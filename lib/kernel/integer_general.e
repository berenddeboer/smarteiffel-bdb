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
expanded class INTEGER_GENERAL
--
-- General integer abstraction to share feature definition of INTEGER_8,
-- INTEGER_16, INTEGER, INTEGER_32 and INTEGER_64.
--
-- If you need integers with bigger values, use NUMBER (lib/number cluster).
--

inherit
   NUMERIC
      export {NONE} copy
      redefine
	 is_equal
      select
	 is_equal
      end
   COMPARABLE
      export {NONE} copy
      undefine
	 is_equal, infix "<", infix "<=", infix ">",  infix ">="
      redefine
	 fill_tagged_out_memory, out_in_tagged_out_memory
      end

feature

   item: like Current
	 -- Access to the expanded value of `Current'. (The type of 
	 -- `item' is INTEGER_8 or INTEGER_16 or INTEGER_32 or INTEGER_64.)

   infix "+" (other: like Current): like item is
      require
	 no_overflow: ((item>0) = (other.item>0)) implies (((Current#+other)>0) = (item>0))
	 -- this means: if operand are of same sign, it will be sign 
	 -- of the Result.
      do
	 Result := item #+ other
      ensure
	 Result #- other.item = item
      end

   infix "-" (other: like Current): like item is
      require
	 no_overflow: ((item>0) /= (other.item>0)) implies (((Current#-other)>0) = (item>0))
	 -- this means: if operand are of different sign, sign of the 
	 -- Result will be the same sign as item.
      do
	 Result := item #- other
      ensure
	 Result #+ other.item = item
      end

   infix "*" (other: like Current): like item is
      require
	 no_overflow: divisible(other) implies ((item#*other.item) // other.item = item)
      do
	 Result := item #* other
      ensure
	 item /= 0 and other.item /= 0 implies Result /= 0
	 Result /= 0 implies Result // other.item = item
	 Result /= 0 implies Result \\ other.item = 0
      end

   infix "/" (other: like Current): DOUBLE is
      external "SmartEiffel"
      end

   infix "//" (other: like Current): like item is
	 -- Integer division of `Current' by `other'
      external "SmartEiffel"
      end

   infix "\\" (other: like Current): like item is
	 -- Remainder of integer division of `Current' by `other'
      external "SmartEiffel"
      end

   infix "^" (exp: like Current): INTEGER_64 is
	 -- Integer power of `Current' by `other'
      require
	 exp >= 0
      local
	 i: like exp; k: INTEGER_64
      do
	 i := exp
	 if i = 0 then
	    Result := 1
	 else
	    Result := item
	    from
	       k := 1
	    until
	       i <= 1
	    loop
	       if i.odd then
		  k := k * Result
	       end
	       Result := Result * Result
	       i := i // 2
	    end
	    Result := Result * k
	 end
      end

   abs: like Current is
         -- Absolute value of `Current'.
      require
	 not_minimum_value: item = 0 or else (item |<< 1) /= 0
      do
         if item < 0 then
            Result := - item
         else
            Result := Current
         end
      end

   infix "<" (other: like Current): BOOLEAN is
      external "SmartEiffel"
      end

   infix "<=" (other: like Current): BOOLEAN is
      external "SmartEiffel"
      end

   infix ">" (other: like Current): BOOLEAN is
      external "SmartEiffel"
      end

   infix ">=" (other: like Current): BOOLEAN is
      external "SmartEiffel"
      end

   prefix "+": like Current is
      do
         Result := Current
      end

   prefix "-": like item is
      require
	 not_minimum_value: item = 0 or else (item |<< 1) /= 0
      external "SmartEiffel"
      end

   odd: BOOLEAN is
         -- Is odd ?
      do
         Result := (item & 1) /= 0
      end

   even: BOOLEAN is
         -- Is even ?
      obsolete "Use `is_even' instead"
      do
         Result := is_even
      end

   is_even: BOOLEAN is
         -- Is even ?
      do
         Result := (item & 1) = 0
      end

   sqrt: DOUBLE is
         -- Compute the square routine.
      require
         item >= 0
      do
         Result := to_double.sqrt
      end

   log: DOUBLE is
         -- (ANSI C log).
      require
         item > 0
      do
         Result := to_double.log
      end

   log10: DOUBLE is
         -- (ANSI C log10).
      require
         item > 0
      do
         Result := to_double.log10
      end

   gcd(other: like Current): like item is
         -- Great Common Divisor of `Current' and `other'.
      require
         Current >= 0
         other >= 0
      do
         if other.item = 0 then
            Result := item
         else
            Result := other.gcd(item \\ other.item)
         end
      ensure
         Result.is_equal(other.gcd(Current))
      end

feature -- Conversions:

   to_real: REAL is
      do
         Result := item
      end

   to_double: DOUBLE is
      do
         Result := item
      end

   to_string: STRING is
         -- Convert the decimal view of `Current' into a new allocated 
         -- STRING. For example, if `Current' is -1 the new STRING is "-1".
         -- Note: see also `append_in' to save memory.
      do
	 string_buffer.clear_count
         append_in(string_buffer)
         Result := string_buffer.twin
      end

   to_unicode_string: UNICODE_STRING is
         -- Convert the decimal view of `Current' into a new allocated 
         -- UNICODE_STRING. For example, if `Current' is -1 the new 
         -- UNICODE_STRING is U"-1".
         -- Note: see also `append_in_unicode' to save memory.
      do
	 unicode_string_buffer.clear
         append_in_unicode(unicode_string_buffer)
         Result := unicode_string_buffer.twin
      end

   to_boolean: BOOLEAN is
         -- Return false for 0, otherwise true.
      do
         Result := item /= 0
      ensure
         Result = (Current.item /= 0)
      end

   fit_integer_8: BOOLEAN is
	 -- Does `Current' fit on an INTEGER_8 ?
      do
	 if item >= -128 then
	    Result := item <= 127
	 end
      ensure
	 Result = Current.in_range(-128, 127)
      end

   to_integer_8: INTEGER_8 is
	 -- Explicit conversion to INTEGER_8.
      require
	 fit_integer_8
      external "SmartEiffel"
      ensure
	 Current.is_equal(Result)
      end

   fit_integer_16: BOOLEAN is
	 -- Does `Current' fit on an INTEGER_16 ?
      do
	 if item >= -32768 then
	    Result := item <= 32767
	 end
      ensure
	 Result = Current.in_range(-32768, 32767)
      end

   to_integer_16: INTEGER_16 is
	 -- Explicit conversion to INTEGER_16.
      require
	 fit_integer_16
      external "SmartEiffel"
      ensure
	 Current.is_equal(Result)
      end

   fit_integer_32, fit_integer: BOOLEAN is
	 -- Does `Current' fit on an INTEGER_32 ?
      do
	 if item >= -2147483648 then
	    Result := item <= 2147483647
	 end
      ensure
	 Result = Current.in_range(-2147483648, 2147483647)
      end

   to_integer_32, to_integer: INTEGER_32 is
	 -- Explicit conversion to INTEGER_32.
	 obsolete "This feature will not be present in SE2. Please update your code."
      require
	 fit_integer_32
      external "SmartEiffel"
      ensure
	 Current.is_equal(Result)
      end

   to_integer_64: INTEGER_64 is
	 -- Explicit conversion to INTEGER_64.
      do
	 Result := Current
      ensure
	 Current.is_equal(Result)
      end

   to_number: NUMBER is
      obsolete
         "Do not use INTEGER_GENERAL.to_number, use some INTEGER_XX instead."
      local
	 number_tools: NUMBER_TOOLS
      do
	 Result := number_tools.from_integer(Current.to_integer)
      end

   to_bit: BIT Integer_bits is
         -- Portable BIT_N conversion.
      obsolete "BIT types will not be supported in SE2. Use `code' and INTEGER bit %
               %operations instead"
      external "SmartEiffel"
      end

   append_in(buffer: STRING) is
         -- Append in the `buffer' the equivalent of `to_string'. No new 
         -- STRING creation during the process.
      require
         buffer /= Void
      local
         val: like item; i, idx: INTEGER
      do
         if item = 0 then
            buffer.extend('0')
         else
            if item > 0 then
               from
                  i := buffer.count + 1
                  val := item
               until
                  val = 0
               loop
                  buffer.extend((val \\ 10).digit)
                  val := val // 10
               end
            else
               buffer.extend('-')
               from
                  i := buffer.count + 1
                  val := item
               until
                  val = 0
               loop
                  buffer.extend((-(val \\ 10)).digit)
                  val := val // 10
               end
            end
            from
               idx := buffer.count
            until
               i >= idx
            loop
               buffer.swap(i,idx)
               idx := idx - 1
               i := i + 1
            end
         end
      end

   append_in_unicode(buffer: UNICODE_STRING) is
         -- Append in the `buffer' the equivalent of `to_unicode_string'. No 
         -- new UNICODE_STRING creation during the process.
      require
         buffer /= Void
      local
         val: like item; i, idx: INTEGER
      do
         if item = 0 then
            buffer.extend(('0').code)
         else
            if item > 0 then
               from
                  i := buffer.count + 1
                  val := item
               until
                  val = 0
               loop
                  buffer.extend((val \\ 10).digit.code)
                  val := val // 10
               end
            else
               buffer.extend(('-').code)
               from
                  i := buffer.count + 1
                  val := item
               until
                  val = 0
               loop
                  buffer.extend((-(val \\ 10)).digit.code)
                  val := val // 10
               end
            end
            from
               idx := buffer.count
            until
               i >= idx
            loop
               buffer.swap(i,idx)
               idx := idx - 1
               i := i + 1
            end
         end
      end

   to_string_format(s: INTEGER): STRING is
         -- Same as `to_string' but the result is on `s' character and the
         -- number is right aligned.
         -- Note: see `append_in_format' to save memory.
      require
         to_string.count <= s
      local
	 i: INTEGER
      do
	 string_buffer.clear_count
	 append_in(string_buffer)
         from
	    create Result.make(string_buffer.count.max(s))
	    i := s - string_buffer.count
         until
	    i <= 0
         loop
            Result.extend(' ')
	    i := i - 1
	 end
         Result.append(string_buffer)
      ensure
         Result.count = s
      end

   to_unicode_string_format(s: INTEGER): UNICODE_STRING is
         -- Same as `to_unicode_string' but the result is on `s' character and 
         -- the number is right aligned.
         -- Note: see `append_in_unicode_format' to save memory.
      require
         to_string.count <= s
      local
	 i: INTEGER
      do
	 unicode_string_buffer.clear
	 append_in_unicode(unicode_string_buffer)
         from
	    create Result.make(unicode_string_buffer.count.max(s))
	    i := s - unicode_string_buffer.count
         until
	    i <= 0
         loop
            Result.extend((' ').code)
	    i := i - 1
	 end
         Result.append(unicode_string_buffer)
      ensure
         Result.count = s
      end

   append_in_format(str: STRING; s: INTEGER) is
         -- Append the equivalent of `to_string_format' at the end of
         -- `str'. Thus you can save memory because no other
         -- STRING is allocate for the job.
      require
	 to_string.count <= s
      local
	 i: INTEGER
      do
	 string_buffer.clear_count
	 append_in(string_buffer)
         from
	    i := s - string_buffer.count
         until
            i <= 0
         loop
            str.extend(' ')
	    i := i - 1
         end
         str.append(string_buffer)
      ensure
         str.count >= (old str.count) + s
      end

   append_in_unicode_format(str: UNICODE_STRING; s: INTEGER) is
         -- Append the equivalent of `to_unicode_string_format' at the end of
         -- `str'. Thus you can save memory because no other
         -- UNICODE_STRING is allocate for the job.
      require
	 to_string.count <= s
      local
	 i: INTEGER
      do
	 unicode_string_buffer.clear
	 append_in_unicode(unicode_string_buffer)
         from
	    i := s - unicode_string_buffer.count
         until
            i <= 0
         loop
            str.extend((' ').code)
	    i := i - 1
         end
         str.append(unicode_string_buffer)
      ensure
         str.count >= (old str.count) + s
      end

   decimal_digit, digit: CHARACTER is
         -- Gives the corresponding CHARACTER for range 0..9.
      require
         in_range(0, 9)
      do
         Result := (item + ('0').code).to_character
      ensure
         (once "0123456789").has(Result)
         Current.is_equal(Result.value)
      end

   hexadecimal_digit: CHARACTER is
         -- Gives the corresponding CHARACTER for range 0..15.
      require
         in_range(0,15)
      do
         if item <= 9 then
            Result := digit
         else
            Result := (('A').code + (item - 10)).to_character
         end
      ensure
         (once "0123456789ABCDEF").has(Result)
      end

   to_character: CHARACTER is
         -- Return the coresponding ASCII character.
      require
         in_range (0, Maximum_character_code)
      external "SmartEiffel"
      end

   to_octal_in(buffer: STRING) is
         -- Append in `buffer' the octal view of `Current'. No new 
         -- STRING creation during the process.
         -- For example, if `Current' is -1 and if `Current' is a 
         -- 16 bits integer the `Result' is "177777".
         -- Note: see also `to_hexadecimal_in' to save memory.
      local
         index, times: INTEGER; value: like item
      do
	 from
	    value := item
            times := (object_size * 8) // 3 + 1
            index := buffer.count + times
            buffer.extend_multiple(' ',times)
         until
            times = 0
         loop
            buffer.put((value & 0x07).digit, index)
            index := index - 1
            value := value |>>> 3
            times := times - 1
         end
      ensure
         buffer.count = old buffer.count + (object_size * 8) // 3 + 1
      end

   to_octal: INTEGER is
	 -- *** THE RESULT IS OF TYPE INTEGER (not like Current) ...
      obsolete "Use to_octal_in intead (February 2003)."
      do
         if Current = 0 then
         elseif item < 0 then
            Result := -((-Current).to_octal)
         else
            from
               string_buffer.clear_count
               Result := Current.to_integer
            until
               Result = 0
            loop
               string_buffer.extend((Result \\ 8).digit)
               Result := Result // 8
            end
            string_buffer.reverse
            Result := string_buffer.to_integer
         end
      end

   to_hexadecimal: STRING is
         -- Convert the hexadecimal view of `Current' into a new allocated
         -- STRING. For example, if `Current' is -1 and if `Current' is a 
         -- 32 bits integer the `Result' is "FFFFFFFF".
         -- Note: see also `to_hexadecimal_in' to save memory.
      do
         string_buffer.clear_count
         to_hexadecimal_in(string_buffer)
         Result := string_buffer.twin
      ensure
         Result.count = object_size * 2
      end

   to_hexadecimal_in(buffer: STRING) is
         -- Append in `buffer' the equivalent of `to_hexadecimal'. No new 
         -- STRING creation during the process.
      local
	 index, times: INTEGER; value: like item
      do
         from
            value := item
            times := object_size * 2
            index := buffer.count + times
            buffer.extend_multiple(' ',times)
         until
            times = 0
         loop
            buffer.put((value & 0x0F).hexadecimal_digit, index)
            index := index - 1
            value := value |>> 4
            times := times - 1
         end
      ensure
         buffer.count = old buffer.count + object_size * 2
      end

feature -- Hashing:

   hash_code: INTEGER is
      do
	 Result := 0x7FFFFFFF & item
      end

feature -- Bitwise Logical Operators:

   bit_test(idx: INTEGER_8): BOOLEAN is
	 -- The value of the `idx'-ith bit (the right-most bit is at 
	 -- index 0).
      require
	 idx >= 0
      do
	 Result := (item.bit_shift_right(idx) & 1) /= 0
      end

   infix "|>>", bit_shift_right (s: INTEGER_8): like item is
	 -- Shift by `s' positions right (sign bit copied) bits falling 
	 -- off the end are lost.
      require 
	 s >= 0 
      external "SmartEiffel"
      end

   infix "@>>" (s: INTEGER_8): like Current is
      obsolete "Use %"|>>%" instead of %"@>>%" (september 2002)."
      require
         s >= 0
      do
	 Result := Current.bit_shift_right(s)
      end

   infix "|>>>", bit_shift_right_unsigned (s: INTEGER_8): like item is
	 -- Shift by `s' positions right (sign bit not copied) bits
	 -- falling off the end are lost.
      require
	 s >= 0
      external "SmartEiffel"
      end

   infix "|<<", bit_shift_left (s: INTEGER_8): like item is
         -- Shift by `s' positions left bits falling off the end are lost.
      require
         s >= 0
      external "SmartEiffel"
      end

   infix "@<<" (s: INTEGER_8): like Current is
      obsolete "Use %"|<<%" instead of %"@<<%" (september 2002)."
      do
         Result := Current |<< s
      end

   infix "#>>", bit_rotate_right (s: INTEGER_8): like item is
         -- Rotate by `s' positions right.
      require
         s >= 0
      external "SmartEiffel"
      end

   infix "#<<", bit_rotate_left (s: INTEGER_8): like item is
        -- Rotate by `s' positions left.
      require
         s >= 0
      external "SmartEiffel"
      end

   bit_rotate(s: INTEGER_8): like item is
         -- Rotate by `s' positions (positive `s' shifts right, negative left
         -- See also infix "#>>" and infix "#<<".
      external "SmartEiffel"
      end

   prefix "~", bit_not: like item is
        -- One's complement of `Current'.
      external "SmartEiffel"
      end

   infix "&", bit_and (other: like Current): like item is
        -- Bitwise logical and of `Current' with `other'.
       external "SmartEiffel"
       end

   infix "|", bit_or (other: like Current): like item is
        -- Bitwise logical inclusive or of `Current' with `other'.
       external "SmartEiffel"
       end

   bit_xor(other: like Current): like item is
        -- Bitwise logical exclusive or of `Current' with `other'.
       external "SmartEiffel"
       end

   infix "and" (other: like Current): like Current is
      obsolete "Use feature 'bit_and' or infix '&' (Dec. 2002)."
      do
	Result := Current.bit_and(other)
      end

   prefix "not": like Current is
      obsolete "Use feature 'bit_not' (Dec. 2002)."
      do
	Result := Current.bit_not
      end

   infix "or" (other: like Current): like Current is
      obsolete "Use feature 'bit_or' or infix '|' (Dec. 2002)."
      do
         Result := Current.bit_or(other)
      end

   infix "xor" (other : like Current) : like Current is
      obsolete "Use feature 'bit_xor' (Dec. 2002)."
      do
	 Result := Current.bit_xor(other)
      end

   bit_shift(s: INTEGER_8): like item is 
	 -- Shift by `s' positions (positive `s' shifts right (sign bit 
	 -- copied), negative shifts left bits falling off the end are lost).
	 -- See also infix "|>>" and infix "|<<".
      do
	 if s > 0 then
            Result := Current |>> s
         else
	    Result := Current |<< s
	 end
      end

   bit_shift_unsigned(s: INTEGER_8): like item is 
         -- Shift by `s' positions (positive `s' shifts right (sign bit not 
	 -- copied), negative left bits falling off the end are lost).
         -- See also infix "|>>>" and infix "|<<".
      do
         if s > 0 then
            Result := Current |>>> s
         else
	    Result := Current |<< s
	 end
      end

feature -- Object Printing:

   out_in_tagged_out_memory, fill_tagged_out_memory is
      do
         Current.append_in(tagged_out_memory)
      end

feature -- Miscellaneous:

   sign: INTEGER_8 is
         -- Sign of `Current' (0 -1 or 1).
      do
	 if item < 0 then
	    Result := -1
	 elseif 0 < item then
	    Result := 1
	 else
	    Result := 0
	 end
      end

   one: INTEGER_8 is 1

   zero: INTEGER_8 is 0

   divisible(other: like Current): BOOLEAN is
      do
         Result := (other.item /= 0)
      end

   is_equal(other: like Current): BOOLEAN is
      do
	 Result := other.item.to_integer_64 = item.to_integer_64
      end

feature -- For experts only: native operators with potential overflow

   infix "#+" (other: like Current): like item is
      external "SmartEiffel"
      end

   infix "#-" (other: like Current): like item is
      external "SmartEiffel"
      end

   infix "#*" (other: like Current): like item is
      external "SmartEiffel"
      end

feature {NONE}

   string_buffer: STRING is
      once
         create Result.make(128)
      end

   unicode_string_buffer: UNICODE_STRING is
      once
         create Result.make(128)
      end

end -- INTEGER_GENERAL
