-- This  file  is  free software,  which comes along with SmartEiffel.  This
-- software is distributed in the hope that it will be useful,  but  WITHOUT
-- ANY  WARRANTY;  without  even the  implied warranty of MERCHANTABILITY or
-- FITNESS FOR A PARTICULAR PURPOSE. You can modify it as you want, provided
-- this header is kept unaltered, and a notification of the changes is added.
-- You  are  allowed  to  redistribute it and sell it, alone or as a part of
-- another product.
--
-- Copyright(C) 1994-2002: INRIA - LORIA (INRIA Lorraine) - ESIAL U.H.P.
--			   - University of Nancy 1 - FRANCE
-- Copyright(C) 2003:      INRIA - LORIA (INRIA Lorraine) - I.U.T. Charlemagne
--			   - University of Nancy 2 - FRANCE
--
--		 Dominique COLNET, Suzanne COLLIN, Olivier ZENDRA,
--			   Philippe RIBET, Cyril ADRIAN
--
-- http://SmartEiffel.loria.fr - SmartEiffel@loria.fr
--
class MUTABLE_BIG_INTEGER
   --
   -- WARNING: THIS CLASS IS NOT YET FINISHED. DO NOT USE.
   --
   -- A class used to represent multiprecision integers that makes efficient
   -- use of allocated space by allowing a number to occupy only part of
   -- an array so that the arrays do not have to be reallocated as often.
   -- When performing an operation with many iterations the array used to
   -- hold a number is only reallocated when necessary and does not have to
   -- be the same size as the number it represents. A mutable number allows
   -- calculations to occur on the same number without having to create
   -- a new number for every step of the calculation as occurs with NUMBERs.
   --
   
inherit
   COMPARABLE
      redefine
	 is_equal
      end
   HASHABLE
      redefine
	 is_equal, copy, fill_tagged_out_memory, out_in_tagged_out_memory
      end
   
creation from_integer, from_integer_64, copy

feature -- Creation/initialization from INTEGER_32 or INTEGER_64:

   from_integer(value: INTEGER) is
	 -- Create or set `Current' using `value' as an initializer.
	 -- directly allocate a storage of 4 INTEGER cause it's non-sense to use
	 -- mutable_big_integer to perform calculation that could fit in an 
	 -- INTEGER_64
      do
	 debug_info := value
	 if capacity = 0 then
	    storage := storage.calloc(4)
	    capacity := 4
	 end
	 offset := 0
	 if value > 0 then
	    negative := False
	    put(value, 0)
	    integer_length := 1
	 elseif value < 0 then
	    negative := True
	    -- attention à la valeur limite (minimum_integer)
            -- put(0 #- value, 0) -- a remplacer par le moins unaire natif
            if value = Minimum_integer then
               put(value, 0)
            else
               put(-value, 0)
	    end
	    integer_length := 1
	 else
	    check value = 0 end
	    integer_length := 0
	 end
      ensure
	 to_integer = value
      end

   is_integer: BOOLEAN is
	 -- Do `Current' fit on an INTEGER_32?
      do
	 if integer_length = 0 then
	    Result := True
	 elseif integer_length = 1 then
	    if item(offset) > 0 then
	       Result := True
	    elseif negative then
	       Result := item(offset) = 0x80000000
	    end
	 end
      ensure
	 Result implies is_integer_64
      end
   
   to_integer: INTEGER is
	 -- Convert `Current' as a 32 bit INTEGER.
      require
	 is_integer
      do
	 if integer_length > 0 then
	    Result := item(offset)
	    if negative then
	       Result := - Result
	    end
	 end
      end
   
   from_integer_64(value: INTEGER_64) is
	 -- Create or set `Current' using `value' as an initializer.
	 -- directly allocate a storage of 4 INTEGER cause it's non-sense to use
	 -- mutable_big_integer to perform calculation that could fit in an INTEGER_64
      local
	 v32: INTEGER_32
      do
	 debug_info := value
	 if capacity = 0 then
	    storage := storage.calloc(4)
	    capacity := 4
	 end
	 offset := 0; integer_length := 2
	 if value > 0 then
	    negative := False
	    put(value.low_32, 1)
	    v32 := value.bit_shift_right(32).low_32
	    if v32 = 0 then
	       offset := 1; integer_length := 1
	    else
	       put(v32, 0)
	    end
	 elseif value < 0 then
	    negative := True
	    put((- value).low_32, 1)
	    v32 := (- value).bit_shift_right(32).low_32
	    if v32 = 0 then
	       offset := 1; integer_length := 1
	    else
	       put(v32, 0)
	    end
	 else
	    check value = 0 end
	    integer_length := 0
	 end
      ensure
	 to_integer_64 = value
      end

   is_integer_64: BOOLEAN is
	 -- Do `Current' fit on an INTEGER_64?
      do
	 if integer_length <= 1 then
	    Result := True
	 elseif integer_length = 2 then
	    if negative then
	       if item(offset) > 0 then
		  Result := True
	       elseif item(offset + 1) = 0 then
		  Result := item(offset) = 0x80000000
	       end
	    else
	       Result := item(offset) > 0
	    end
	 end
      ensure
	 (not Result) implies (not is_integer)
      end
   
   to_integer_64: INTEGER_64 is
	 -- Convert `Current' as a INTEGER_64.
      require
	 is_integer_64
      local
	 v: INTEGER_64
      do
	 inspect
	    integer_length
	 when 0 then
	 when 1 then
	    Result := item(offset)
	    Result := Result & 0x00000000FFFFFFFF
	    if negative then Result := - Result end
	 when 2 then
	    Result := item(offset + 1)
	    Result := Result & 0x00000000FFFFFFFF
	    v := item(offset)
	    v := v.bit_shift_left(32)
	    Result := Result.bit_xor(v) 
	    if negative then Result := - Result end
	 end
      end

feature -- Addition:
   
   add(other: like Current) is
	 -- Add `other' into `Current'.
      require
         other /= Void
      local
         tmp: like Current
      do
	 -- Choose the appropriate absolute operator depending on current and 
	 -- other sign.
         if other.integer_length = 0 then
            -- Nothing to do, `Current' remains unchanged
         elseif integer_length = 0 then
            -- `Current' is null so simply copy the value of other
            Current.copy(other)
	 elseif not negative then
	    if not other.negative then
	       Current.add_magnitude(other)
	    else
	       if (abs_compare(other)=1) then
		  subtract_magnitude(other)
		  -- CSC:DEBUG (not necessary) negative := False
	       elseif (abs_compare(other)=(-1)) then
		  create tmp.copy(other)
		  tmp.subtract_magnitude(Current)
		  tmp.swap_with(Current)
		  negative := True
	       else
		  set_with_zero
	       end
	    end
         elseif negative then
	    if not other.negative then
	       if (abs_compare(other)=1) then
		  subtract_magnitude(other)
		  -- CSC:DEBUG (not necessary) negative := True
	       elseif  (abs_compare(other)=(-1)) then
		  create tmp.copy(other)
		  tmp.subtract_magnitude(Current)
		  tmp.swap_with(Current)
		  negative := False
	       else
		  set_with_zero
	       end
	    else 
	       Current.add_magnitude(other)
	       -- CSC:DEBUG (not necessary) negative := True
	    end
	 end
      end

   add_integer(other: INTEGER_32) is
	 -- Add `other' into `Current'.
      local
         x, z, c: INTEGER_32; sum, diff: INTEGER_64
         new_capacity: like capacity
         new_storage: like storage
      do
         if other = 0 then
            --not_yet_implemented -- CSC:DEBUG code VISITED
            -- Nothing to do, `Current' remains unchanged
         elseif integer_length = 0 then
            --not_yet_implemented -- CSC:DEBUG code VISITED
            -- `Current' is null so simply copy the value of other
            Current.from_integer(other)
	 elseif ((not negative) and (other > 0)) or (negative and (other < 0)) then
            --not_yet_implemented -- CSC:DEBUG code VISITED
            from
               --not_yet_implemented -- CSC:DEBUG code VISITED
               x := offset + integer_length - 1
               z := capacity - 1
               c := integer_length
               sum := (Long_mask & item(x))
               sum := sum + other.abs
               put(sum.low_32, z)
               offset := z
               x := x - 1; z := z - 1; c := c - 1
            until
               c = 0
            loop
               --not_yet_implemented -- CSC:DEBUG code VISITED
               -- must perform slice_copy fully even when carried is 0
               -- in order to set the result correctly margin left
               sum := sum |>>> 32
               sum := sum + (Long_mask & item(x))
               put(sum.low_32, z)
               offset := z
               x := x - 1; z := z - 1; c := c - 1
            end
            sum := sum |>>> 32
            if sum /= 0 then
               -- not_yet_implemented -- CSC:DEBUG code  NOT visited
               if z < 0 then
                  not_yet_implemented -- CSC:DEBUG code  NOT visited
                  -- in case of overflow
                  new_capacity := capacity * 2
                  new_storage := new_storage.calloc(new_capacity)
                  new_storage.copy_slice(capacity, storage, 0, capacity - 1)
                  z := capacity - 1
                  storage := new_storage
                  capacity := new_capacity
               else
                  -- not_yet_implemented -- CSC:DEBUG code  NOT visited
                  put(sum.low_32, z)
                  offset := z
               end
            end
            integer_length := capacity - offset
         elseif ((not negative) and (other < 0)) or (negative and (other > 0)) then
            --not_yet_implemented -- CSC:DEBUG code VISITED
            if integer_length = 1 then
               -- not_yet_implemented -- CSC:DEBUG code  NOT visited
               if (item(offset) < other.abs) then
                  -- not_yet_implemented -- CSC:DEBUG code  NOT visited
                  --special case when |current| < |other|
                  --so current holds in less than 32 bits -> ,
		  --no need for Long_mask
                  diff := other.abs
                  diff := diff - item(x)
                  negative := (other < 0)
               else
                  -- not_yet_implemented -- CSC:DEBUG code  NOT visited
                  diff := (Long_mask & item(x))
                  diff := diff - other.abs
               end
               offset := capacity - 1
               put(diff.low_32, offset)
            else
               -- not_yet_implemented -- CSC:DEBUG code  NOT visited
               -- |`Current'| is formely greater than |`other'|.
               from
                  x := offset + integer_length - 1
                  z := capacity - 1
                  c := integer_length
                  diff := (Long_mask & item(x))
                  diff := diff - other.abs
                  put(diff.low_32, z)
                  x := x - 1; z := z - 1; c := c - 1
               until
                  c = 0
               loop
                  --not_yet_implemented -- CSC:DEBUG code  NOT visited
                  diff := (diff |>> 32).to_integer_32
                  diff := diff + (Long_mask & item(x))
                  put(diff.low_32, z)
                  x := x - 1; z := z - 1; c := c - 1
               end

               -- Setting `offset' and `integer_length' as well:
               from
                  offset := z + 1
               until
                  (offset = capacity - 1) or else (item(offset) /= 0)
               loop
                  offset := offset + 1
               end

               if item(offset) = 0 then
                  integer_length := 0
               else
                  integer_length := capacity - offset
               end
            end
         end
      end

   add_integer_64(other: INTEGER_64) is
	 -- Add `other' into `Current'.
      local
         x, z, c, new_capacity: INTEGER; sum, diff: INTEGER_64
	 new_storage: like storage
      do
         if other = 0 then
            -- Nothing to do, `Current' remains unchanged
         elseif integer_length = 0 then
            -- `Current' is null so simply copy the value of other
            Current.from_integer_64(other)
	 elseif ((not negative) and (other > 0)) or (negative and (other < 0)) then
            from
               x := offset + integer_length - 1
               z := capacity - 1
               c := integer_length

               sum := (Long_mask & item(x))
               sum := sum + other.low_32.abs
               put(sum.low_32, z)
               offset := z

               x := x - 1;
               z := z - 1; c := c - 1

               sum := sum |>>> 32

               if x > 0 then
                  -- if Current.integer_length > 1, add Current high_32 with other.high_32
                  sum := sum + (Long_mask & item(x))
                  offset := z
               end
               
               -- as other is negative, be carefull not to take the bit sign
               sum := sum + (Long_mask & other |>>> 32)
               if sum > 0 then
                  put(sum.low_32, z)
                  offset := z
               end
               x := x - 1; z := z - 1; c := c - 1
            until
               c <= 0
            loop
              -- must perform slice_copy fully even when carried is 0
               sum := sum |>>> 32
               sum := sum + (Long_mask & item(x))
               put(sum.low_32, z)
               offset := z
               x := x - 1; z := z - 1; c := c - 1
            end
            if sum.high_32 /= 0 then
               if z < 0 then
                  -- for debordement
                  new_capacity := capacity * 2
                  new_storage := new_storage.calloc(new_capacity)
                  new_storage.copy_slice(capacity, storage, 0, capacity - 1)
                  z := capacity - 1
                  storage := new_storage
                  capacity := new_capacity
               else
                  put(sum.high_32, z)
                  offset := z
               end
            end
            integer_length := capacity - offset
         elseif ((not negative) and (other < 0)) or (negative and (other > 0)) then
            if integer_length = 1 then
               if (item(offset) < other.abs) then
                  --special case when |current| < |other|
                  --so current holds in less than 32 bits -> , 
		  --no need for Long_mask
                  diff := other.abs
                  diff := diff - item(x)
                  negative := (other < 0)
               else
                  diff := (Long_mask & item(x))
                  diff := diff - other.abs
               end
               offset := capacity - 1
               put(diff.low_32, offset)
            else
               -- |current| is formely greater than |other|
               from
                  x := offset + integer_length - 1
                  z := capacity - 1
                  c := integer_length

                  diff := (Long_mask & item(x))
                  diff := diff - other.abs
                  put(diff.low_32, z)
                  x := x - 1; z := z - 1; c := c - 1
               until
                  c = 0
               loop
                  diff := (diff |>> 32).to_integer_32
                  diff := diff + (Long_mask & item(x))
                  put(diff.low_32, z)
                  x := x - 1; z := z - 1; c := c - 1
               end

               -- Setting `offset' and `integer_length' as well:
               from
                  offset := z + 1
               until
                  (offset = capacity - 1) or else (item(offset) /= 0)
               loop
                  offset := offset + 1
               end

               if item(offset) = 0 then
                  integer_length := 0
               else
                  integer_length := capacity - offset
               end
            end
         end
      end

   add_natural(other: like Current) is
	 -- Same behavior as `add', but this one works only when `Current' 
	 -- and `other' are both positive numbers and are both greater than 
	 -- zero. The only one advantage of using `add_natural' instead of the 
	 -- general `add' is the gain of efficiency.
      require
         not is_zero and not is_negative
         not other.is_zero and not other.is_negative
      do
	 Current.add_magnitude(other)
      end

feature -- Subtract:

   subtract(other: like Current) is
	 -- Subtract `other' from `Current'.
      require
	 other /= Void
      local
	 tmp: like Current
      do
	 if other.integer_length = 0 then
	    -- nothing to do, `Current' remains unchanged
	 elseif integer_length = 0 then
	    -- current is null so simply copy the value of other, the sign is also fixed
	    copy(other)
	    negative := not other.negative
	 elseif not negative then
	    if not other.negative then
	       if (abs_compare(other) = 1) then
		  subtract_magnitude(other)
		  negative := False
	       elseif (abs_compare(other) = (-1)) then
		  create tmp.copy(other)
		  tmp.subtract_magnitude(Current)
		  tmp.swap_with(Current)
		  negative := True
	       else
		  set_with_zero
	       end
	    else  	       
	       add_magnitude(other)
	       negative := False
	    end
	 elseif negative then
	    if other.negative then
	       if (abs_compare(other) = 1 ) then
	          subtract_magnitude(other)
		  negative := True
	       elseif (abs_compare(other) = (-1) ) then
	          create tmp.copy(other)
		  tmp.subtract_magnitude(Current)
		  tmp.swap_with(Current)
		  negative := False
	       else
		  set_with_zero
	       end
	    else
	       add_magnitude(other)
	       negative := True
	    end
	 end
      end

   subtract_integer(other: INTEGER_32) is
      do
         Current.add_integer(-other)
      end
   
feature -- To divide:

   divide(other, quotient, remainder: like Current) is
	 -- Calculates the `quotient' and `remainder' of `Current' 
	 -- divided by `other'. (The contents of `Current' and `other' are 
	 -- not changed.)
	 --
	 -- Note: Uses Algorithm D in Knuth section 4.3.1. Many 
	 -- optimizations to that algorithm have been adapted from the Colin
	 -- Plumb C library. It special cases one word divisors for speed.
      require
	 not other.is_zero
      local
	 cmp, nlen, limit, shift, dh, dl, j, qhat, qrem, nh, nh2, nm,
	 borrow, i: INTEGER;
	 d: like Current q, qword: NATIVE_ARRAY[INTEGER]
	 dhlong, nchunk, nl, rs, est_product: INTEGER_64
	 skip_correction: BOOLEAN
      do
	 cmp := Current.compare(other)
	 if integer_length = 0 then -- Dividend is zero:
            quotient.set_with_zero; remainder.set_with_zero
	 elseif cmp < 0 then -- Dividend less than divisor:
            quotient.set_with_zero; remainder.copy(Current)
	 elseif cmp = 0 then -- Dividend equal to divisor:
	    quotient.from_integer(1)
	    remainder.set_with_zero
	 elseif other.integer_length = 1 then
	    -- Special case one word divisor:
	    quotient.clear
	    remainder.copy(Current)
	    remainder.divide_one_word(other.item(other.offset),quotient)
	 else
	    quotient.clear
	    -- Copy divisor storage to protect divisor:
            create d.copy(other)
            -- Remainder starts as dividend with space for a leading zero:
	    remainder.ensure_capacity(integer_length + 1)
	    from i := 0 until i > integer_length
	    loop
	       remainder.put(item(i + offset), i + 1)
	       i := i + 1
	    end
	    remainder.set_ilo(integer_length, 1)
	    nlen := remainder.integer_length
	    -- Set the quotient size:
	    limit := nlen - d.integer_length + 1
	    quotient.ensure_capacity(limit)
            quotient.set_ilo(limit, 0)
	    q := quotient.storage
	    -- D1 normalize the divisor:
	    shift := 32 - left_most_bit_set_index(d.item(0))
	    if shift > 0 then
	       -- First shift will not grow array:
	       d.primitive_left_shift(shift.to_integer_8)
	       -- But this one might:
	       remainder.left_shift(shift)
	    end
	    -- Must insert leading 0 in remainder if its length did not change
	    if remainder.integer_length = nlen then
	       remainder.set_offset(0)
	       remainder.put(0, 0)
	       remainder.set_integer_length(integer_length + 1)
	    end
	    dh := d.item(0)
	    dhlong := Long_mask & dh
	    dl := d.item(1)
	    qword := qword.calloc(2)
	    -- D2 Initialize j:
	    from
	       j := 0
	    until
	       j >= limit
	    loop
	       -- D3 Calculate qhat - estimate qhat
	       qhat := 0; qrem := 0; skip_correction := False
	       nh := remainder.item(j + remainder.offset)
	       nh2 := nh + 0x80000000
	       nm := remainder.item(j + 1 + remainder.offset)
	       if nh = dh then
		  qhat := ~0; qrem := nh + nm
		  skip_correction := qrem + 0x80000000 < nh2
	       else
		  nchunk := (nh.to_integer_64.bit_shift_left(32)) | (Long_mask & nm)
		  if nchunk >= 0 then
		     qhat := (nchunk // dhlong).low_32
                     qrem := (nchunk - (qhat * dhlong)).low_32
		  else
		     not_yet_implemented
		     -- div_word(qword, nchunk, dh)
		     qhat := qword.item(0)
		     qrem := qword.item(1)
		  end
	       end
	       if qhat = 0 then
	       elseif not skip_correction then -- Correct qhat:
		  nl := remainder.item(j + 2 + remainder.offset) & Long_mask
		  rs := (qrem & Long_mask).bit_shift_left(32) | nl
		  est_product := (dl & Long_mask) * (qhat & Long_mask)
		  if unsigned_long_compare(est_product, rs) then
		     qhat := qhat - 1
		     qrem := ((qrem & Long_mask) + dhlong).low_32
                     if ((qrem & Long_mask) >=  dhlong) then
                        est_product := (dl & Long_mask) * (qhat & Long_mask)
                        rs := ((qrem & Long_mask).bit_shift_left(32)) | nl
			if unsigned_long_compare(est_product, rs) then
			   qhat := qhat - 1
			end
		     end
		  end
		  -- D4 Multiply and subtract:
		  remainder.put(0, j + remainder.offset)
		  not_yet_implemented
		  -- borrow := mulsub(remainder.storage, d, qhat, dlen, j + remainder.offset)
		  -- D5 Test remainder:
		  if borrow + 0x80000000 > nh2 then -- D6 Add back:
		     not_yet_implemented
		     -- divadd(d, remainder.storage, j + 1 + remainder.offset)
		     qhat := qhat - 1
		  end
		  -- Store the quotient digit:
		  q.put(qhat, j)
	       end
	    j := j + 1
            end -- D7 loop on j
            -- D8 Unnormalize:
            if (shift > 0) then remainder.right_shift(shift) end
            remainder.normalize
	    quotient.normalize
         end						      
      end

  left_shift(n: INTEGER_32) is
	 -- If there is enough storage space in `storage' already
	 -- the available space will be used. Space to the right of the used
	 -- ints in the storage array is faster to utilize, so the extra
	 -- space will be taken from the right if possible.
      local
	 left, right: INTEGER_8
	 new_storage: like storage
	 stop, nb_ints, old_length: INTEGER
	 writing, reading: INTEGER
	 last, tmp: INTEGER_32
      do
	 if n = 31 and item(offset) = 3 then sedb_breakpoint end
	 -- TODO: bug (ex: offset n'est pas ajusté dans un des cas pour left_shift).
        -- TODO: faire une classe de test qui produit ce cas d'erreur
	 if integer_length > 0 then
	    old_length := integer_length
	    nb_ints := n |>>> 5
	    left := (n & 0x0000001F).to_integer_8
	    right := 32 - left
	    if left = 0 then
	       integer_length := integer_length + nb_ints
	       if integer_length > capacity then
		  new_storage := new_storage.calloc(integer_length)
		  new_storage.copy_slice(0, storage, offset, offset + old_length - 1)
		  storage := new_storage
		  capacity := integer_length
		  offset := 0
	       elseif integer_length + offset > capacity then
	          storage.move(offset, offset + old_length - 1, -offset)
		  storage.clear(old_length, integer_length - 1)
		  offset := 0
	       else
	          storage.clear(offset + old_length, offset + integer_length - 1)
	       end
	    else
	       from
	          if item(offset) |>>> right /= 0 then
		     -- ???last := item(offset)
		     reading := offset - 1
		     integer_length := integer_length + nb_ints + 1
		     stop := old_length - 1
		  else
		     reading := offset
		     last := item(offset)
		     integer_length := integer_length + nb_ints
		     stop := old_length
		  end
		  offset := 0
		  if integer_length <= capacity then
		     new_storage := storage
		  else
		     new_storage := new_storage.calloc(integer_length)
		  end
	       until
	          writing >= stop
	       loop
	          tmp := last |<< left
		  reading := reading + 1
		  last := item(reading)
		  new_storage.put(tmp | (last |>>> right), writing)
		  writing := writing + 1
	       end
	       new_storage.put(last |<< left, writing)
	       writing := writing + 1
	       if new_storage /= storage then
	          storage := new_storage
		  capacity := integer_length
	       elseif nb_ints > 0 then
		  storage.clear(writing, integer_length - 1)
	       end
	    end
	 end
      end

   right_shift(n: INTEGER_32) is
	 -- Right shift `Current' n bits. (`Current' is left in normal form.)
      require
	 --current.integer_length > 0
	 n > 0
      local
	 n_ints, n_bits, bits_in_high_word: INTEGER
      do
	 if integer_length > 0 then
	    n_ints := n |>>> 5
	    n_bits := n & 0x0000001F
	    integer_length := integer_length - n_ints
	    if n_bits /= 0 then
	       bits_in_high_word := left_most_bit_set_index(item(offset))
	       if n_bits >= bits_in_high_word then
		  primitive_left_shift(32 - n_bits.to_integer_8)
		  integer_length := integer_length - 1
	       else
		  primitive_right_shift(n_bits.to_integer_8)
	       end
	    end
	 end
      end
   
feature -- To multiply:

   multiply(other, res: like Current) is
	 -- Multiply the contents of `Current' and `other' and place the 
	 -- result  in `res'. (`Current' and other are not modified.)
      require
	 other /= Void
         res /= Void
      local
	 xlen, ylen, new_length, i, j, k : INTEGER
	 new_storage : like storage
	 mult, carry : INTEGER_64
      do
	if (is_zero or other.is_zero) then
	   res.set_with_zero
	elseif (Current.is_one)then
	   res.copy(other)
	elseif (other.is_one) then
	   res.copy(Current)
	elseif (Current.is_one_negative) then
	    res.copy(other)
	    res.set_negative(not res.negative)
	elseif (other.is_one_negative) then
	     res.copy(Current)
	     res.set_negative(not negative)
	else
	-- calcul of dimension
		xlen := integer_length
		ylen := other.integer_length
		new_length := xlen + ylen
   
	 -- Put res into an appropriate state to receive product
		if (res.capacity < new_length) then
			new_storage := res.storage.calloc(new_length)
			res.set_storage(new_storage)
		end

	-- The first iteration is hosted out of the loop to avoid extra add
		from
			j:= ylen-1
			k := res.capacity -1
		until
			j<0
		loop
			mult := other.item(j+other.offset) & Long_mask
			mult := mult * item(xlen-1+offset) & Long_mask
			mult := mult + carry 
			res.put(mult.low_32, k)
			carry := (mult |>>> 32).to_integer_32
			res.set_offset(k)
			j:=j-1
			k:=k-1
		end
		if carry /= 0 then
			res.put(carry.to_integer_32,k)
			res.set_offset(k)
		end
		res.set_integer_length(res.capacity - res.offset)

	 -- Perform the multiplication word by word
		from
			i:=xlen-2
			carry:=0
		until
			i<0
		loop	
			from
				 j := ylen - 1
				 k := ylen +i
			until
				j <0
			loop		  
				  mult := other.item(j+other.offset) & Long_mask
				    mult := mult * item(i+offset) & Long_mask
				    mult := mult + res.item(k) & Long_mask +carry
				    res.put(mult.low_32, k)
				    carry := (mult |>>> 32).to_integer_32
				    j := j-1
				    k := k-1
			end
			res.put(carry.to_integer_32,i)
			i:=i-1
		end
            -- Remove leading zeros from product
           res.normalize
	   if not(res.negative = (Current.is_negative xor other.is_negative)) then
		res.set_negative((Current.is_negative xor other.is_negative))
	   end
	end
      end

   
   multiply_integer(other: INTEGER; res: like Current) is
	 -- Multiply the contents of `Current' and `other' and place the 
	 -- result  in `res'. (`Current' is not modified.)
      require
	 other /= Void
	 res /= Void
      do
	 not_yet_implemented
      end
   
feature -- Comparison:

   is_zero: BOOLEAN is
         -- Is it 0?
      do
	 Result := integer_length = 0
      ensure
	 Result implies not is_negative
      end

   is_one: BOOLEAN is
         -- Is it 1?
      do
	 if integer_length = 1 then
	    if not negative then
	       Result := item(offset) = 1
	    end
	 end
      ensure
	 Result implies not is_negative
      end

     is_one_negative: BOOLEAN is
         -- Is it -1?
      do
	 if integer_length = 1 then
	    if negative then
	       Result := item(offset) = 1
	    end
	 end
      ensure
	 Result implies is_negative
      end

   is_negative: BOOLEAN is
	 -- Is `Current' negative integer?
      do
	 Result := negative
      end

   is_even: BOOLEAN is
      -- Is `Current' even?
      do
	 if integer_length = 0 then
	    Result := True
	 else
	    Result := item(offset + integer_length - 1).even
	 end
      ensure
	 Result = not Current.is_odd
      end
   
   is_odd: BOOLEAN is
      -- Is `Current' odd?
      do
	 if integer_length > 0 then
	    Result := item(offset + integer_length - 1).odd
	 end
      ensure
	 Result = not Current.is_even
      end
   
   is_equal(other: like Current): BOOLEAN is
      local
	 a, b, c: INTEGER
      do
	 if Current = other then
	    Result := True
	 elseif negative then
	    if other.negative then
	       negative := False; other.set_negative(False)
	       Result := Current.is_equal(other)
	       negative := True; other.set_negative(True)
	    end
	 elseif other.negative then
	 elseif integer_length < other.integer_length then
	 elseif other.integer_length < integer_length then
	 else
	    check other.integer_length = integer_length end
	    from
	       c := integer_length
	       a := offset
	       b := other.offset
	       Result := True
	    until
	       c = 0
	    loop
	       if item(a) /= other.item(b) then
		  Result := False
		  c := 0
	       else
		  c := c - 1
	       end
	       a := a + 1; b := b + 1
	    end
	 end
      end

   infix "<" (other: like Current): BOOLEAN is
      local
	 a, b, c: INTEGER va, vb: INTEGER_64
      do
	 if Current = other then
	 elseif negative then
	    if other.negative then
	       negative := False; other.set_negative(False)
	       Result := other < Current
	       negative := True; other.set_negative(True)
	    else
	       Result := True
	    end
	 elseif other.negative then
	 elseif integer_length < other.integer_length then
	    Result := True
	 elseif other.integer_length < integer_length then
	 else
	    check other.integer_length = integer_length end
	    from
	       c := integer_length; a := offset; b := other.offset
	    until
	       c = 0
	    loop
	       va := Long_mask & item(a)
	       vb := Long_mask & other.item(b)
	       if va < vb then
		  Result := True
		  c := 0
	       elseif vb < va then
		  c := 0
	       else
		  c := c - 1
	       end
	       a := a + 1; b := b + 1
	    end
	 end
      end

   abs_compare(other : like Current) : INTEGER is
	 -- Compare the magnitude of `Current' and `other'. Returns -1, 0 or 1
	 -- as this MutableBigInteger is numerically less than, equal to, or
	 -- greater than other. 
      do
	 if not negative and other.negative then
	    -- `Current'>0 and `other'<0
	    other.set_negative(false)
	    if(current>other) then
	       result:=1
	    elseif(current<other) then
	       result:= -1
	    else
	       result:=0
	    end
	    other.set_negative(true)
	 elseif negative and not other.negative then
	    --`Current'<0 and `other'>0
	    set_negative(false)
	    if(current>other) then
	       result:=1
	    elseif(current<other) then
	       result:= -1
	    else
	       result:=0
	    end
	    set_negative(true)
	 elseif negative and other.negative then
	    --`Current'<0 and `other'<0
	    set_negative(false)
	    other.set_negative(false)
	    if(current>other) then
	       result:=1
	    elseif(current<other) then
	       result:= -1
	    else
	       result:=0
	    end
	    set_negative(true)
	    other.set_negative(true)
	 elseif not negative and not other.negative then
	     --`Current'>0 and `other'>0
	    if(current>other) then
	       result:=1
	    elseif(current<other) then
	       result:= -1
	    else
	       result:=0
	    end
	 end
      end
   
feature -- Printing:
   
   to_string: STRING is
	 -- Create a decimal view of the `Current' big integer.
         -- Note: see also `append_in' to save memory.
      do
	 string_buffer.clear
	 --io.put_string("on passe ici")
	 append_in(string_buffer)
	 Result := string_buffer.twin
      end

   append_in(buffer: STRING) is
         -- Append in the `buffer' the equivalent of `to_string'. No new 
         -- STRING creation during the process.
      local
	 max_num_digit_groups, num_groups, i, num_leading_zeros: INTEGER
	 digit_group: FIXED_ARRAY[STRING]; q, r, a, b: like Current
      do
	 if integer_length = 0 then
	    buffer.extend('0')
	 else
	    if negative then buffer.extend('-') end
	    -- Compute upper bound on number of digit groups and allocate 
	    -- space:
	    max_num_digit_groups := (4 * integer_length + 6) // 7
	    create digit_group.make(max_num_digit_groups)
	    -- Translate number to string, a digit group at a time:
	    from
	       a := Current.twin
	       create b.from_integer_64(0x0DE0B6B3A7640000)
	       create q.from_integer(0)
	       create r.from_integer(0)
	       if a.negative then a.set_negative(False) end
	       num_groups := 0
	    until
	       a.integer_length = 0
	    loop
	       q.from_integer(0)
	       r.from_integer(0)
	       a.divide(b, q, r)
	       digit_group.put(r.to_integer_64.to_string, num_groups)
	       num_groups := num_groups + 1
	       a.copy(q)
	    end
	    -- Put first digit group into result buffer:
	    buffer.append(digit_group.item(num_groups - 1))
	    -- Append remaining digit groups padded with leading zeros:
	    from
	       i := num_groups - 2
	    until
	       i < 0
	    loop
	       -- Prepend (any) leading zeros for this digit group:
	       from
		  num_leading_zeros := 18 - digit_group.item(i).count
	       until
		  num_leading_zeros = 0
	       loop
		  buffer.extend('0')
		  num_leading_zeros := num_leading_zeros - 1
	       end
	       buffer.append(digit_group.item(i))
	       i := i - 1
	    end
	 end
      end
   
   out_in_tagged_out_memory, fill_tagged_out_memory is
      do
	 append_in(tagged_out_memory)
      end

feature -- Miscellaneous:

   negate is
	 -- Negate the sign of `Current'.
      do
	 if integer_length /= 0 then
	    negative := not negative
	 end
      ensure
	 is_zero implies not is_negative
      end
   
   set_with_zero is
      do
         integer_length := 0
         negative := False
      ensure
         is_zero
      end

   hash_code: INTEGER is
      local
	 i, c: INTEGER hash: INTEGER_64
      do
	 from
	    c := integer_length
	    i := offset
	 until
	    c = 0
	 loop
	    hash := hash + (Long_mask & item(i))
	    c := c - 1; i := i + 1
	 end
	 Result := hash.hash_code
      end

   copy(other: like Current) is
      do
	 if capacity < other.capacity then
	    capacity := other.capacity
	    storage := storage.calloc(capacity)
	 end
	 integer_length := other.integer_length
	 offset := other.offset
	 negative := other.negative
	 storage.copy_slice(offset, other.storage,
			    offset, offset + integer_length - 1)
	 debug
	    if ( Current.is_integer_64) then
		debug_info := Current.to_integer_64
	    end
	 end
      end

   swap_with(other: like Current) is
	 -- Swap the value of `Current' with the value of `other'.
      local
	 s: like storage; c: like capacity; il: like integer_length
	 o: like offset; n: like negative
      do
	 s := other.storage
	 c := other.capacity
	 il := other.integer_length
	 o := other.offset
	 n := other.negative
	 --
	 other.standard_copy(Current)
         --
	 storage := s
	 capacity := c
	 integer_length := il
	 offset := o
	 negative := n
      ensure
	 -- *** other.to_string.is_equal(old to_string)
	 -- *** Current.to_string.is_equal(old other.to_string)
      end
   
feature {MUTABLE_BIG_INTEGER} -- Implementation:
   
   storage: NATIVE_ARRAY[INTEGER_32]
	 -- Holds the magnitude of `Current' in big endian order.
	 -- The magnitude may start at an `offset' into the value array, 
	 -- and it may end before the length of the allocated `storage' 
	 -- array.

   capacity: INTEGER
	 -- Of the allocated `storage' area.
   
   integer_length: INTEGER
	 -- The number of INTEGER of the `storage' array that are currently 
	 -- used to hold the magnitude of this MutableBigInteger. The 
	 -- magnitude starts at an offset and offset + integer_length may be 
	 -- less than capacity. 

   offset: INTEGER
	 -- The `offset' into the `storage' array where the magnitude of 
	 -- `Current' begins.

   negative: BOOLEAN
	 -- True when `Current' is negative.

   item(index: INTEGER): INTEGER_32 is
      require
	 index.in_range(0, capacity - 1)
      do
	 Result := storage.item(index)
      end
   
   put(value: INTEGER_32; index: INTEGER) is
      require
	 index.in_range(0, capacity - 1)
      do
	 storage.put(value, index)
      end
   
   set_negative(n: like negative) is
      require
         n /= negative
      do
	 negative := n
      ensure
	 negative = n
      end

   set_integer_length(il: like integer_length) is
      require
	 il >= 0
      do
	 integer_length := il
      ensure
	 integer_length = il
      end

   set_offset(o: like offset) is
      require
	 o.in_range(0, capacity - 1)
      do
	 offset := o
      ensure
	 offset = o
      end

   set_ilo(il: like integer_length; o: like offset) is
      do
	 integer_length := il
	 offset := o
      ensure
	 integer_length = il
	 offset = o
      end

   set_storage(new_storage: like storage) is
      do
         storage := new_storage
      end

   ensure_capacity(needed_capacity: INTEGER) is
	 -- *** A VIRER ***
      local
	 
      do
	 if capacity < needed_capacity then
	    not_yet_implemented
	 end
	 integer_length := 0
      ensure
	 is_zero
	 capacity >= needed_capacity
      end
   
   primitive_left_shift(n: INTEGER_8) is
	 -- Left shift `Current' with no need to extend the `storage'.
      require
	 integer_length > 0
	 n.in_range(1, 31)
	 left_most_bit_set_index(item(offset)) + n <= 32
      local
	 n2: INTEGER_8; i, up, b, c: INTEGER
      do
	 n2 := 32 - n
	 from
	    i := offset; c := item(i); up := i + integer_length - 1
	 until
	    i >= up
	 loop
	    b := c
	    c := item(i + 1)
	    put(b.bit_shift_left(n) | (c |>>> n2), i)
	    i := i + 1
	 end
	 check i = (offset + integer_length - 1) end
	 put(item(i).bit_shift_left(n), i)
      end
	 
   primitive_right_shift(n: INTEGER_8) is
	 -- Right shift `Current' of `n' bits.
      require
	 integer_length > 0
	 n.in_range(1, 31)
	 -- right_most_bit_set_index(item(offset + integer_length - 1)) - n >= 0 
      local
	 n2: INTEGER_8; i, b, c: INTEGER
      do
	 n2 := 32 - n
	 from
	    i := offset + integer_length - 1
	    c := item(i)
	 until
	    i <= offset
	 loop
            b := c
            c := item(i - 1)
            put(c.bit_shift_left(n2) | (b |>>> n), i)
	    i := i - 1
	 end
	 storage.put(storage.item(offset) |>>> n, offset)
      end

   divide_one_word(divisor: INTEGER; quotient: like Current) is
	 -- This method is used by `divide'. The `quotient' is placed into 
	 -- `quotient'. The one word divisor is specified by `divisor'. The 
	 -- `storage' of `Current' is the dividend at invocation but is 
	 -- replaced by the remainder.
	 -- Note: The `storage' of `Current' is modified by this method.
      local
	 div_long, rem_long, rem_storage, dividend_estimate: INTEGER_64
	 shift: INTEGER_8; rem, xlen: INTEGER_32
	 q_word: NATIVE_ARRAY[INTEGER_32]
      do
	 div_long := Long_mask & divisor
	 -- Special case of one word dividend
	 if integer_length = 1 then
            rem_storage := Long_mask & item(offset)
            quotient.put((rem_storage // div_long).low_32, 0)
	    if quotient.item(0) = 0 then
	       quotient.set_integer_length(0)
	    else
	       quotient.set_integer_length(1)
	    end
            quotient.set_offset(0)
            put((rem_storage - (quotient.item(0) * div_long)).low_32, 0)
            offset := 0
	    if item(0) = 0 then
	       integer_length := 0
	    else
	       integer_length := 1
	    end
	 else
	    quotient.ensure_capacity(integer_length)
	    quotient.set_offset(0)
	    quotient.set_integer_length(integer_length)
	    -- Normalize the divisor:
	    shift := 32 - left_most_bit_set_index(divisor)
	    rem := item(offset)
	    rem_long := Long_mask & rem
	    if rem_long < div_long then
	       quotient.put(0, 0)
	    else
               quotient.put((rem_long // div_long).low_32, 0)
               rem := (rem_long - (quotient.item(0) * div_long)).low_32
               rem_long := Long_mask & rem
	    end
	    xlen := integer_length - 1
	    q_word := q_word.calloc(2)
	    from until xlen <= 0
	    loop
	       dividend_estimate :=
		  (rem_long.bit_shift_left(32) |
		   (Long_mask & item(offset + integer_length - xlen)))
	       if dividend_estimate >= 0 then
		  q_word.put((dividend_estimate // div_long).low_32, 0)
		  q_word.put((dividend_estimate -
			      (q_word.item(0) * div_long)).low_32, 1)
	       else
		  div_word(q_word, dividend_estimate, divisor)
	       end
	       quotient.put(q_word.item(0), integer_length - xlen)
	       rem := q_word.item(1)
	       rem_long := Long_mask & rem
	    end
	    -- Unnormalize;
	    if shift > 0 then
	       put(rem \\ divisor, 0)
	    else
	       put(rem, 0)
	    end
	    if item(0) = 0 then
	       integer_length := 0
	    else
	       integer_length := 1
	    end
	    quotient.normalize
	 end
      end

   normalize is
	 -- Ensure that `Current' is in normal form, specifically making 
	 -- sure that there are no leading zeros, and that if the magnitude 
	 -- is zero, then `integer_length' is zero.
      local
	 index, index_bound, num_zeros: INTEGER
      do
	 if integer_length = 0 then
            offset := 0
	 elseif item(offset) /= 0 then
	 else
	    from
	       index := offset
	       index_bound := index + integer_length
	    until
	       index >= index_bound or else item(index) /= 0
	    loop
	       index := index + 1
	    end
	    num_zeros := index - offset
	    integer_length := integer_length - num_zeros
	    if integer_length = 0 then
	       offset := 0
	    else
	       offset := offset + num_zeros
	    end
	 end
      ensure
	 integer_length = 0 xor item(offset) /= 0
      end

   clear is
      -- Clear out `Current' for reuse.
      do
         offset := 0
         integer_length := 0
         storage.clear_all(capacity - 1)
      end   
   
feature {NONE} -- Implementation:

   add_magnitude(other: Like Current) is
	 -- Add the magnitude of `Current' and `other' regardless of signs.
      require
         not is_zero
         not other.is_zero
      local
         x, y, z, c, new_capacity: INTEGER_32; sum: INTEGER_64
	 new_storage: like storage
      do	 
	 x := offset + integer_length - 1 
	 y := other.offset + other.integer_length - 1
	 z := capacity - 1
	 -- Add common parts of both numbers:
	 from
	    c := integer_length.min(other.integer_length)
	 until
	    c = 0
	 loop
	    sum := sum |>>> 32
	    sum := sum + (Long_mask & item(x))
	    sum := sum + (Long_mask & other.item(y))
	    put(sum.low_32, z)
	    x := x - 1; y := y - 1; z := z - 1; c := c - 1
	 end
	 -- Add remainder of the longer number:
	 if offset <= x then
	    from until x < offset
	    loop
	       sum := sum |>>> 32
	       sum := sum + (Long_mask & item(x))
	       put(sum.low_32, z)
	       x := x - 1; z := z - 1
	    end
	 elseif other.offset <= y then 
	    from
	       if capacity < other.integer_length then
		  new_capacity := other.integer_length + 1
		  new_storage := new_storage.calloc(new_capacity)
		  z := capacity - 1 - x
		  new_storage.copy_slice(z, storage, x + 1, capacity - 1)
		  z := z - 1
		  storage := new_storage
		  capacity := new_capacity 
	       end
	    until y < other.offset
	    loop
	       sum := sum |>>> 32
	       sum := sum + (Long_mask & other.item(y))
	       put(sum.low_32, z)
	       y := y - 1; z := z - 1
	    end
	 end
	 sum := sum |>>> 32
	 if sum /= 0 then
	    if z < 0 then
	       new_capacity := capacity * 2
	       new_storage := new_storage.calloc(new_capacity)
	       new_storage.copy_slice(capacity, storage, 0, capacity - 1)
	       z := capacity - 1
	       storage := new_storage
	       capacity := new_capacity 
	    end
	    put(sum.low_32, z)
	    z := z - 1
	 end
	 offset := z + 1
	 integer_length := capacity - offset
      ensure
	 integer_length >= other.integer_length.max(old integer_length)
      end

feature {MUTABLE_BIG_INTEGER} -- Implementation:

   subtract_magnitude(other: like Current) is
   -- Subtract `other' from `Current'. (The result is placed  in `Current')
   local
      x, y, z, c: INTEGER_32; diff: INTEGER_64
   do
   sedb_breakpoint -- to do again ....

   x := offset + integer_length - 1 
   y := other.offset + other.integer_length - 1
   z := capacity - 1
   -- Subtract common parts of both numbers:
   from
      c := integer_length.min(other.integer_length)
   until
      c = 0
   loop
      --diff := ((Long_mask & item(x)) - (Long_mask & other.item(y)) - (- (diff |>> 32).to_integer_32))
      diff := (diff |>> 32).to_integer_32
      diff := diff + (Long_mask & item(x))
      diff := diff - (Long_mask & other.item(y))
      put(diff.low_32, z)
      x := x - 1; y := y - 1; z := z - 1; c := c - 1
   end

   -- Subtract remainder of the longer number:
   if offset <= x then
      from until x < offset
      loop
         --diff := ((Long_mask & item(x)) - (- (diff |>> 32).to_integer_32))
	 diff := (diff |>> 32).to_integer_32
	 diff := diff + (Long_mask & item(x))
         put(diff.low_32, z)
         x := x - 1; z := z - 1
      end
   elseif other.offset <= y then 
      negative := False
      from until y < other.offset
      loop
	diff := (diff |>> 32).to_integer_32
	diff := diff - (Long_mask & item(y))
         put(diff.low_32, z)
         y := y - 1; z := z - 1
      end
   else
      diff := - (diff |>> 32)
      inspect
      diff
      when 0 then
      when 1 then
         negative := True
      end
   end

   -- Setting `offset' and `integer_length' as well:
   from
      offset := z + 1
   until
      (offset = capacity - 1) or else (item(offset) /= 0)
   loop
      offset := offset + 1
   end

   if item(offset) = 0 then
      integer_length := 0
   else
      integer_length := capacity - offset
   end
end

   left_most_bit_set_index(n: INTEGER_32): INTEGER_8 is
	 -- *** TROUVER UN BON NOM !!! ***
	 -- The index of the first non-zero bit in `n' looking from left to right.
	 -- 32 means that the left-most bit is set.
	 --  1 means that the right-most bit is set.
	 --  0 means that there is no bit set in `n'.
      local
	 i: INTEGER
      do
	-- c'est pas optimal, on peut faire mieux).
	-- Pour l'instant ce n'est pas une priorité et même le nom devra être repensé.
	-- Sinon, pour éviter l'itération, procéder dichotomiquement.
        --from
        --   i := n
        --until
        --   i = 0
        --loop
        --   i := i |>>> 1
        --   Result := Result + 1
        --end
        -- à tester plus tard
         from
	    i := n
	    Result := 32
	 until
	    Result = 0 or else i < 0
	 loop
	    i := i.bit_shift_left(1)
	    Result := Result - 1
	 end
      ensure
	 Result.in_range(0, 32)
      end
   
feature {NONE} -- Implementation:
   
   Long_mask: INTEGER_64 is 0x00000000FFFFFFFF
	 -- This mask is used to obtain the value of an INTEGER as if it 
	 -- were unsigned.

   string_buffer: STRING is
      once
	 create Result.make(4096)
      end

   debug_info: INTEGER_64
	 -- *** A VIRER PLUS TARD ***

   divadd(a, res: FIXED_ARRAY[INTEGER]; o: INTEGER) is
	 -- A primitive used for division. This method adds in one multiple of the
	 -- divisor a back to the dividend result at a specified offset. It is used
	 -- when qhat was estimated too large, and must be adjusted.
      do
	 not_yet_implemented
      end

   div_word(res: NATIVE_ARRAY[INTEGER_32]; n: INTEGER_64; d: INTEGER) is
      do
	 not_yet_implemented
      end

   unsigned_long_compare(one, two: INTEGER_64): BOOLEAN is
	 -- Compare two longs as if they were unsigned.
	 -- Returns true iff one is bigger than two.
      do
	 Result := (one + Minimum_integer_64) > (two + Minimum_integer_64)
      end
   
feature {NONE} --  GARBAGE CODE : A virer quand tout marchera

   left_shift_old(n: INTEGER_32) is
	 -- If there is enough storage space in `storage' already
	 -- the available space will be used. Space to the right of the used
	 -- ints in the storage array is faster to utilize, so the extra 
	 -- space will be taken from the right if possible.
      require
	 not is_zero; n > 0 
      local
	 n_ints, new_len: INTEGER; bits_in_high_word, n_bits: INTEGER_8
	 new_storage: like storage
      do
	 if integer_length > 0 then
	    n_ints := n |>>> 5
	    n_bits := (n & 0x0000001F).to_integer_8
	    bits_in_high_word := left_most_bit_set_index(item(offset))
	    -- If shift can be done without moving words, do so:
	    if n <= (32 - bits_in_high_word) then
	       primitive_left_shift(n_bits)
	    else
	       new_len := integer_length + n_ints + 1
	       if n_bits <= (32 - bits_in_high_word) then
		  new_len := new_len - 1
	       end
	       if capacity < new_len then
		  -- The array must grow:
		  new_storage := new_storage.calloc(new_len)
		  new_storage.copy_slice(0, storage, offset,
					 offset + integer_length - 1) 
		  storage := new_storage
		  capacity := new_len
	       elseif capacity - offset >= new_len then
		  -- Use space on right:
		  storage.clear(offset+integer_length, offset+new_len-1)
	       else -- Must use space on left:
		  storage.move(offset, offset + integer_length - 1, -offset)
		  storage.clear(integer_length, new_len - 1)
		  offset := 0
	       end
	       integer_length := new_len
	       if n_bits = 0 then
	       elseif n_bits <= (32 - bits_in_high_word) then
		  primitive_left_shift(n_bits)
	       else
		  primitive_right_shift(32 -n_bits)
	       end
	    end
	 end
      end

invariant

   (capacity > 0) = storage.is_not_null
   
   integer_length.in_range(0, capacity)

   integer_length /= 0 implies offset.in_range(0, capacity - 1)

   integer_length /= 0 implies item(offset) /= 0

   integer_length = 0 implies not negative
   
end --  MUTABLE_BIG_INTEGER

