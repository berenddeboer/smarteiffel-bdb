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
class BIT_STRING
   --
   -- Long and very long bit sequences.
   -- An INTEGER index can be used to access each bit of the sequence.
   -- The leftmost bit has index 1 and the rightmost bit has index `count'.
   --
   -- For short bit sequences (less or equal to 32 or 64), also
   -- consider using the basic INTEGER_N type.
   --

inherit
   ANY
      redefine
	 copy, is_equal, out_in_tagged_out_memory
      end

creation make, from_string

feature {BIT_STRING}

   storage: FAST_ARRAY[INTEGER]
         -- The `storage' area. Bits are stored in the usual way (as
         -- they are printed). Padding of the `last' word is done
         -- using 0 on the left.

feature

   count: INTEGER
	 --  Number of bits in the sequence.

   make(n: INTEGER) is
         -- Make bit sequence of `n' bits.
         -- All bits are set to false.
      require
	 n > 0
      local
	 c: INTEGER
      do
	 c := n // Integer_bits
	 if n \\ Integer_bits > 0 then
	    c := c + 1
	 end
	 count := n
         if storage = Void then
            !!storage.make(c)
         else
            storage.make(c)
         end
      ensure
	 count = n
	 all_default
      end

   from_string(model: STRING) is
	 -- Create or set `Current' using `model' which is supposed
	 -- to be a sequence of mixed `0' or `1' characters.
      require
	 model.is_bit
      do
         make(model.count)
	 set_from_string(model,1)
      end

   valid_index(idx: INTEGER): BOOLEAN is
         -- True when `index' is valid (ie. inside actual
         -- bounds of the bit sequence).
      do
         if idx > 0 then
            Result := idx <= count
         end
      ensure
	 Result = idx.in_range(1,count)
      end

   item(idx: INTEGER): BOOLEAN is
	 --  True if `idx'-th bit is 1, false otherwise.
      require
	 valid_index(idx)
      local
	 stor_slice: INTEGER
      do
	 stor_slice := storage.item ((idx-1) // Integer_bits)
	 Result := stor_slice.bit_test (((idx - 1) \\ Integer_bits).to_integer_8)
      end

   put(value: BOOLEAN; idx: INTEGER) is
	 --  Set bit `idx' to 1 if `value' is true, 0 otherwise.
      require
	 valid_index(idx)
      do
	 if value then
	    put_1(idx)
	 else
	    put_0(idx)
	 end
      ensure
	 value = item(idx)
      end

   put_1(idx: INTEGER) is
	 --  Set bit `idx' to 1.
      require
	 valid_index(idx)
      local
	 stor_slice: INTEGER
      do
	 stor_slice := storage.item((idx-1) // Integer_bits)
	             | (mask_1 |<< ((idx-1) \\ Integer_bits).to_integer_8)
	 storage.put(stor_slice, (idx-1) // Integer_bits)
      ensure
	 item(idx)
      end

   put_0(idx: INTEGER) is
	 --  Set bit `idx' to 0.
      require
	 valid_index(idx)
      local
	 stor_slice: INTEGER
      do
	 stor_slice := storage.item((idx-1) // Integer_bits)
	             & ~(mask_1 |<< ((idx-1) \\ Integer_bits).to_integer_8)
	 storage.put(stor_slice, (idx-1) // Integer_bits)
      ensure
	 not item(idx)
      end

feature --  Rotating and shifting:

   shift_by(n: INTEGER) is
	 -- Shift `n'-bits.
         --  `n' > 0 : shift right,
	 --  `n' < 0 : shift left,
	 --  `n' = 0 : do nothing.
         -- Falling bits are lost and entering bits are 0.
      do
	 if n.abs < count then
	    if n > 0 then
	       shift_right_by(n)
	    elseif n < 0 then
	       shift_left_by(-n)
	    end
	 else
	    clear_all
	 end
      end

   shift_left_by(n:INTEGER) is
	 -- Shift left by `n' bits.
         -- Falling bits are lost and entering bits are 0.
      require
	 n >= 0
      local
	 i: INTEGER
	 prec, oprec: INTEGER
      do
	 if n >= count then
	    clear_all
	 elseif  n >= Integer_bits then
	    shift_left_by(Integer_bits - 1)
	    shift_left_by(n - Integer_bits + 1)
	 else
	    from
	       i := storage.lower
	    until
	       i > storage.upper
	    loop
	       prec := storage.item (i) |>>> (Integer_bits-n).to_integer_8
	       storage.put( (storage.item(i) |<< n.to_integer_8) | oprec  , i)
	       oprec := prec
	       i := i + 1
	    end
	    storage.put (storage.item (storage.upper) &
	        (mask_all |>>> (Integer_bits-n).to_integer_8 ), storage.upper)
	 end
      end

   shift_right_by(n: INTEGER) is
	 -- Shift right by `n' bits.
         -- Falling bits are lost and entering bits are 0.
      require
	 n >= 0
      local
	 i: INTEGER
	 oprec, prec: INTEGER
      do
	 if n >= count then
	    clear_all
	 elseif  n >= Integer_bits then
	    shift_right_by(Integer_bits - 1)
	    shift_right_by(n - Integer_bits + 1)
	 else
	    from
	       i := storage.upper
	    until
               i < storage.lower
	    loop
               prec := storage.item(i) |<< (Integer_bits - n).to_integer_8
	       storage.put((storage.item(i) |>>> n.to_integer_8) | oprec, i)
	       oprec := prec
	       i := i - 1
	    end
	 end
      end

   rotate_by(n: INTEGER) is
         -- Rotate by `n' bits.
	 --  `n' > 0 : Rotate right,
	 --  `n' < 0 : Rotate left,
	 --  `n' = 0 : do nothing.
      do
	 if  n > 0 then
	       rotate_right_by(n)
	 elseif n < 0 then
	       rotate_left_by(- n)
	 end
      end

   rotate_left_by(n: INTEGER) is
	 --  Rotate left by `n' bits.
      require
	 n >= 0
      local
	 prec: BIT_STRING
	 mask: BIT_STRING
	 rn: INTEGER
      do
         rn := n \\ count
	 if rn /= 0 then
	    if rn > (count // 2) then
	       rotate_right_by(count - rn)
	    else
	       !!mask.make(count)
	       mask.set_all
	       mask.shift_left_by(count - rn)
	       prec := Current and mask
	       shift_left_by(rn)
	       prec.shift_right_by(count - rn)
	       or_mask(prec)
	    end
	 end
      end

   rotate_right_by(n: INTEGER) is
	 -- Rotate right by `n' bits.
      require
	 n >= 0
      local
	 prec: BIT_STRING
	 mask: BIT_STRING
	 rn: INTEGER
      do
	 rn := n \\ count
	 if rn /= 0 then
	    if rn > (count // 2) then
	       rotate_left_by(count - rn)
	    else
	       !!mask.make(count)
	       mask.set_all
	       mask.shift_right_by(count - rn)
	       prec := Current and mask
	       shift_right_by(rn)
	       prec.shift_left_by(count - rn)
	       or_mask(prec)
	    end
	 end
      end

    infix "^" (s: INTEGER): like Current is
	 -- Sequence shifted by `s' positions (positive `s' shifts
	 -- right, negative left; bits falling off the sequence's
	 -- bounds are lost).
	 -- See also infix "|>>" and infix "|<<".
      require
	 s.abs < count
      do
	 Result := Current.twin
	 Result.shift_by(s)
      end

   infix "|>>" (s: INTEGER): like Current is
         -- Sequence shifted right by `s' positions.
         -- Same as infix "^" when `s' is positive (may run a little
         -- bit faster).
      require
	 s > 0
      do
	 Result := Current.twin
	 Result.shift_right_by(s)
      end

   infix "@>>" (s: INTEGER): like Current is
      obsolete "Use %"|>>%" instead of %"@>>%" (september 2002)."
      do
         Result := Current |>> s
      end

   infix "|<<" (s: INTEGER): like Current is
         -- Sequence shifted left by `s' positions.
         -- Same as infix "^" when `s' is negative (may run a little
         -- bit faster.
      require
	 s > 0
      do
	 Result := Current.twin
	 Result.shift_left_by(s)
      end

   infix "@<<" (s: INTEGER): like Current is
      obsolete "Use %"|<<%" instead of %"@<<%" (september 2002)."
      do
         Result := Current |<< s
      end

   infix "#" (s: INTEGER): like Current is
         -- Sequence rotated by `s' positions (positive right,
         -- negative left).
      require
	 s.abs < count
      do
	 Result := Current.twin
	 Result.rotate_by(s)
      end

   infix "#>>" (s: INTEGER): like Current is
         -- Sequence rotated by `s' positions right.
      require
         s >= 0
	 s < count
      do
	 Result := Current.twin
	 Result.rotate_right_by(s)
      end

   infix "#<<" (s: INTEGER): like Current is
         -- Sequence rotated by `s' positions left.
      require
         s >= 0
	 s < count
      do
	 Result := Current.twin
	 Result.rotate_left_by(s)
      end

feature --  Bitwise Logical Operators:

   infix "and" (other: like Current): like Current is
         --  Bitwise `and' of Current with `other'
      require
	 count = other.count
      do
	 Result := Current.twin
	 Result.and_mask(other)
      ensure
	 Result.count = Current.count
      end

   infix "implies" (other: like Current): like Current is
         -- Bitwise implication of Current with `other'
      require
	 count = other.count
      do
	 Result := Current.twin
         Result.implies_mask(other)
      end

   prefix "not": like Current is
         -- Bitwise `not' of Current.
      do
	 Result := Current.twin
	 Result.invert
      ensure
	 Result.count = Current.count
      end

   infix "or" (other: like Current): like Current is
	 -- Bitwise `or' of Current with `other'.
      require
	 other /= Void
	 count = other.count
      do
	 Result := Current.twin
	 Result.or_mask(other)
      ensure
         Result.count = Current.count
      end

   infix "xor" (other: like Current): like Current is
         -- Bitwise `xor' of Current with `other'
      require
	 other /= Void
	 count = other.count
      do
	 Result := Current.twin
	 Result.xor_mask(other)
      ensure
	 Result.count = Current.count
      end

   and_mask(other: like Current) is
         -- Apply bitwise `and' mask of `other' onto Current.
      require
	 count = other.count
      local
	 i: INTEGER
      do
	 from
	    i := storage.lower
	 variant
	    storage.upper - i
	 until
	    i > storage.upper
	 loop
	    storage.put((storage.item(i) & other.storage.item(i)), i)
	    i := i + 1
	 end
      end

   implies_mask(other: like Current) is
         -- Aply bitwise implies mask of `other'.
      require
	 count = other.count
      local
	 i: INTEGER
         word, mask: INTEGER
      do
         from
             i := storage.upper
         until
             i < 0
         loop
             word := ~storage.item(i) | other.storage.item(i)
             storage.put(word,i)
             i := i - 1
	 end
	 if (count \\ Integer_bits) /= 0 then
	     mask := (~mask) |>>> (Integer_bits - (count \\ Integer_bits)).to_integer_8
	     i := storage.upper
	     storage.put(storage.item (i) & mask,i)
	 end
      end

   or_mask(other: like Current) is
         -- Apply bitwise `or' mask of `other' onto Current.
      require
	 count = other.count
      local
	 i: INTEGER
      do
	 from
	    i := storage.lower
	 variant
	    storage.upper - i
	 until
	    i > storage.upper
	 loop
	    storage.put((storage.item(i) | other.storage.item(i)), i)
	    i := i + 1
	 end
      end

   xor_mask(other: like Current) is
         -- Apply bitwise `xor' mask of `other' onto Current
      require
	 count = other.count
      local
	 i: INTEGER
      do
	 from
	    i := storage.lower
	 variant
	    storage.upper - i
	 until
	    i > storage.upper
	 loop
	    storage.put((storage.item(i).bit_xor (other.storage.item(i))), i)
	    i := i + 1
	 end
      end

   invert is
         -- Invert Current bit-per-bit.
      local
	 i: INTEGER
	 mask: INTEGER
      do
	 from
	    i := storage.lower
	 variant
	    storage.upper - i
	 until
	    i > storage.upper
	 loop
	    storage.put(~storage.item(i), i)
	    i := i + 1
	 end
	 mask := (~mask) |>>> (Integer_bits - (count \\ Integer_bits)).to_integer_8
	 storage.put(~storage.item(storage.upper) & mask, storage.upper)
      end

feature -- Conversions:

   to_string: STRING is
         -- String representation of bit sequence.
	 -- A zero bit is mapped to '0', a one bit to '1'.
	 -- Leftmost bit is at index 1 in the returned string.
	 --
	 --  Note: see `append_in' to save memory.
      do
	 !!Result.make(count)
	 append_in(Result)
      ensure
	 Result.count = count
      end

   to_integer: INTEGER is
         -- The corresponding INTEGER value when `count' <= `Integer_bits'.
         -- No sign-extension when `count' < `Integer_bits'.
      require
	 count <= Integer_bits
      do
	  Result := storage.last
      end

feature -- Others:

   all_cleared, all_default: BOOLEAN is
	 --  Are all bits set to 0 ?
      do
	 Result := storage.all_default
      end

   clear_all is
         -- Set all bits to 0
      do
	 storage.clear_all
      ensure
	 all_default
      end

   all_set: BOOLEAN is
	 --  Are all bits set to 1 ?
      local
	 i: INTEGER
	 mask: INTEGER
      do
	 from
	    Result := true
	    i := storage.upper - 1
	 until
	    i < 0 or else not Result
	 loop
	    Result := ~storage.item(i) = 0
	    i := i - 1
	 end
	 if Result then
	    if count \\ Integer_bits = 0 then
	       Result := ~storage.last = 0
	    else
	       mask := mask_all |>>> (Integer_bits - (count \\ Integer_bits)).to_integer_8
	       Result := storage.last = mask
	    end
	 end
      end

   set_all is
	 -- Set all bits to 1
      local
	 mask: INTEGER
      do
	 storage.set_all_with(mask_all)
	 if count \\ Integer_bits /= 0 then
	    mask := (~mask) |>>> (Integer_bits - (count \\ Integer_bits)).to_integer_8
	    storage.put(mask, storage.upper)
	 end
      ensure
	 all_set
      end

   is_equal(other: like Current): BOOLEAN is
      do
	 if count = other.count then
            Result := storage.is_equal(other.storage)
	 end
      end

   copy(other: like Current) is
      do
	 count := other.count
         if storage = Void then
            storage := other.storage.twin
         else
            storage.copy(other.storage)
         end
      end

   out_in_tagged_out_memory is
	 --  Append terse printable represention of current object
	 --  in `tagged_out_memory'
      do
	 Current.append_in(tagged_out_memory)
	 tagged_out_memory.extend('B')
      end

   append_in(str: STRING) is
         -- Append in `str' a viewable representation of `Current'.
      local
	 i: INTEGER
      do
	 from
	    i := 1
	 until
	    i > count
	 loop
	    if item(i) then
	       str.extend('1')
	    else
	       str.extend('0')
	    end
	    i := i + 1
	 end
      end

   set_from_string(model: STRING; offset: INTEGER) is
         -- Use the whole contents of `model' to reset range
         -- `offset' .. `offset + model.count - 1' of `Current'.
         -- Assume all characters of `model' are `0' or `1'.
      require
	 model.is_bit
	 valid_index(offset)
         valid_index(offset + model.count - 1)
      local
	 i: INTEGER
      do
	 from
	    i := 1
	 variant
	    model.count - i
	 until
	    i > model.count
	 loop
	    put(model.item(i) = '1',i + offset - 1)
	    i := i + 1
	 end
      ensure
         count = old count
      end

feature {NONE} -- Utility constants

    mask_0: INTEGER is 0
    mask_1: INTEGER is 1
    mask_all: INTEGER is -1

invariant

   count >= 1

   not storage.is_empty

end -- BIT_STRING
