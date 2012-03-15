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
expanded class CHARACTER
--
-- Note: An Eiffel CHARACTER is mapped as a C unsigned char or as a Java Byte.
--

inherit
   HASHABLE
      export {NONE} copy
      end
   COMPARABLE
      export {NONE} copy
      undefine
	 is_equal
      redefine
         out_in_tagged_out_memory, fill_tagged_out_memory,
	 infix ">=", infix "<=", infix ">"
      end

feature

   to_integer: INTEGER_8 is
         -- Sign-extended conversion.
      external "SmartEiffel"
      end

   code: INTEGER_16 is
         -- ASCII code of Current. (No Sign-extended conversion.)
      external "SmartEiffel"
      ensure
         Result.in_range(Minimum_character_code,Maximum_character_code)
      end

   infix "<" (other: CHARACTER): BOOLEAN is
         -- Comparison using `code'.
      do
         Result := code < other.code
      end

   infix "<=" (other: CHARACTER): BOOLEAN is
         -- Comparison using `code'.
      do
         Result := code <= other.code
      end

   infix ">" (other: CHARACTER): BOOLEAN is
         -- Comparison using `code'.
      do
         Result := code > other.code
      end

   infix ">=" (other: CHARACTER): BOOLEAN is
         -- Comparison using `code'.
      do
         Result := code >= other.code
      end

   value, decimal_value: INTEGER_8 is
         -- Gives the value of a decimal digit.
      require
         is_digit
      do
         Result := code.to_integer_8 - 48
      ensure
         Result.in_range(0,9)
      end

   binary_value: INTEGER_8 is
         -- Gives the value of a binary digit.
      require
         is_binary_digit
      do
         Result := code.to_integer_8 - 48
      ensure
         Result.in_range(0,1)
      end

   octal_value: INTEGER_8 is
         -- Gives the value of an octal digit.
      require
         is_octal_digit
      do
         Result := code.to_integer_8 - 48
      ensure
         Result.in_range(0,7)
      end

   hexadecimal_value: INTEGER_8 is
         -- Gives the value of an hexadecimal digit.
      require
         is_hexadecimal_digit
      do
         Result := code.to_integer_8
         if code < ('A').code then
            Result := Result - 48
         elseif code < ('a').code then
            Result := Result - 55
         else
            Result := Result - 87
         end
      ensure
         Result.in_range(0,15)
      end

   same_as(other: CHARACTER): BOOLEAN is
         -- Case insensitive comparison.
         -- No difference between upper/lower case letters.
      do
         if item = other then
            Result := True
         else
            inspect
               code
            when 65 .. 90 then
               Result := code = other.code - 32
            when 97 .. 122 then
               Result := code = other.code + 32
            else
            end
         end
      ensure
         Result implies to_lower = other or to_upper = other
      end 

   to_upper: CHARACTER is
         -- Conversion to the corresponding upper case.
      do
         if code < 97 then
            Result := item
         elseif code > 122 then
            Result := item
         else
            Result := (code - 32).to_character
         end
      end

   to_lower: CHARACTER is
         -- Conversion to the corresponding lower case.
      do
         if code < 65 then
            Result := item
         elseif code > 90 then
            Result := item
         else
            Result := (code + 32).to_character
         end
      end

   is_letter: BOOLEAN is
         -- Is it a letter ('a' .. 'z' or 'A' .. 'Z') ?
      do
         if item >= 'a' then
            Result := item <= 'z'
         elseif item >= 'A' then
            Result := item <= 'Z'
         end
      ensure
         Result = in_range('A','Z') or in_range('a','z')
      end

   is_digit, is_decimal_digit: BOOLEAN is
         -- Belongs to '0'..'9'.
      do
         if item >= '0' then
            Result := item <= '9'
         end
      ensure
        Result = in_range('0','9')
      end

   is_binary_digit: BOOLEAN is
         -- Belongs to '0'..'1'.
      do
         if item >= '0' then
            Result := item <= '1'
         end
      ensure
         Result = in_range('0','1')
      end

   is_octal_digit: BOOLEAN is
         -- Belongs to '0'..'7'.
      do
         if item >= '0' then
            Result := item <= '7'
         end
      ensure
         Result = in_range('0','7')
      end

   is_hexadecimal_digit: BOOLEAN is
         -- Is it one character of "0123456789abcdefABCDEF" ?
      do
         if is_digit then
            Result := True
         elseif item >= 'a' then
            Result := item <= 'f'
         elseif item >= 'A' then
            Result := item <= 'F'
         end
      ensure
         Result =  (once "0123456789abcdefABCDEF").has(Current)
      end

   is_lower: BOOLEAN is
         -- Is it some lowercase letter ('a'..'z')?
      do
         inspect
            item
         when 'a'..'z' then
            Result := True
         else
         end
      end

   is_upper: BOOLEAN is
         -- Is it some uppercase letter ('A'..'Z')?
      do
         inspect
            item
         when 'A'..'Z' then
            Result := True
         else
         end
      end

   is_separator: BOOLEAN is
         -- True when character is a separator.
      do
         inspect
            item
         when ' ','%T','%N','%R','%U', '%F' then
            Result := True
         else
         end
      end

   is_letter_or_digit: BOOLEAN is
	 -- Is it a letter (see `is_letter') or a digit (see `is_digit') ?
      do
         Result := is_letter or else is_digit
      ensure
         definition: Result = (is_letter or is_digit)
      end

   is_ascii: BOOLEAN is
         -- Is character a 8-bit ASCII character?
      do
         inspect
            item
         when '%U'..'%/255/' then
            Result := True
         else
         end
      end

   is_bit: BOOLEAN is
         -- True for `0' and `1'.
      do
         inspect
            item
         when '0','1' then
            Result := True
         else
         end
      end

   next: CHARACTER is
         -- Give the next character (the following `code')
      do
         Result := (code + 1).to_character
      end

   previous: CHARACTER is
         -- Give the previous character (the `code' before)
      require
         code > 0
      do
         Result := (code - 1).to_character
      end

feature -- Conversions:

   to_bit: BIT Character_bits is
      external "SmartEiffel"
      end

   to_hexadecimal: STRING is
         -- Create a new STRING giving the `code' in hexadecimal.
         -- For example :
         --    (255).to_character.to_hexadecimal gives "FF".
         -- Note: see `to_hexadecimal_in' to save memory.
      do
         create Result.make(2)
         to_hexadecimal_in(Result)
      ensure
         Result.count = 2
      end

   to_hexadecimal_in(str: STRING) is
         -- Append the equivalent of `to_hexadecimal' at the end of
         -- `str'. Thus you can save memory because no other
         -- STRING is allocate for the job.
      local
         c: CHARACTER
      do
         c := ((to_bit and 11110000B) |>> 4).to_character
         inspect
            c.code
         when 0 .. 9 then
            str.extend((('0').code + c.code).to_character)
         else
            str.extend(((('A').code - 10) + c.code).to_character)
         end
         c := (to_bit and 00001111B).to_character
         inspect
            c.code
         when 0 .. 9 then
            str.extend((('0').code + c.code).to_character)
         else
            str.extend(((('A').code - 10) + c.code).to_character)
         end
      ensure
         str.count = 2 + old str.count
      end

feature -- Object Printing:

   out_in_tagged_out_memory, fill_tagged_out_memory is
      do
         tagged_out_memory.extend(item)
      end

feature -- Hashing:

   hash_code: INTEGER is
      do
         Result := code
      end

feature -- Miscellaneous:

   is_alpha: BOOLEAN is
	 -- See `is_letter' (yes this is just a call to `is_letter').
	 -- Isn't `is_letter' better English ;-)
      do
	 Result := is_letter
      ensure
	 Result = is_letter
      end

feature -- For compatibility with the obsolete CHARACTER_REF style:
   
   item: CHARACTER
   
   set_item(item_value: like item) is
      do
	 item := item_value
      ensure
	 item = item_value
      end

end -- CHARACTER

