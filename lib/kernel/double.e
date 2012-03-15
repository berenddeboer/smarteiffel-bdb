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
expanded class DOUBLE
--
-- DOUBLE is the type for real numbers with more precision than 'REAL' type.
-- The precision is not infinite.
--
-- Note: An Eiffel DOUBLE is mapped as a C double or as a Java double.
--

inherit
   NUMERIC
      export {NONE} copy
      end
   COMPARABLE
      export {NONE} copy
      undefine
	 is_equal, infix "<", infix "<=", infix ">", infix ">="
      redefine
         fill_tagged_out_memory, out_in_tagged_out_memory
      end

feature

   infix "+" (other: like Current): DOUBLE is
      external "SmartEiffel"
      end

   infix "-" (other: like Current): DOUBLE is
      external "SmartEiffel"
      end

   infix "*" (other: like Current): DOUBLE is
      external "SmartEiffel"
      end

   infix "/" (other: like Current): DOUBLE is
      external "SmartEiffel"
      end

   infix "^" (e: INTEGER): DOUBLE is
         -- Raise Current to `e'-th power (see also `pow').
      external "SmartEiffel"
      end

   prefix "+" : like Current is
      do
         Result := Current
      end

   prefix "-": DOUBLE is
      external "SmartEiffel"
      end

   abs: like Current is
      do
         if Current < 0.0 then
            Result := -Current
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

   double_floor: DOUBLE is
         -- Greatest integral value no greater than Current.
      external "SmartEiffel"
      end

   floor: INTEGER is
         -- Greatest integral value no greater than Current.
      do
         Result := truncated_to_integer
      ensure
         result_no_greater: Result <= Current
	 close_enough: Current - Result < one
      end

   double_ceiling: DOUBLE is
         -- Smallest integral value no smaller than Current.
      do
         Result := ceil
      end

   ceiling: INTEGER is
         -- Smallest integral value no smaller than Current.
      local
         d: DOUBLE
      do
         d := double_ceiling
         Result := d.truncated_to_integer
      ensure
	 result_no_smaller: Result >= Current
	 close_enough: Result - Current < one
      end

   rounded: INTEGER is
         -- Rounded integral value.
      do
         if double_floor + 0.5 < Current then
            Result := double_ceiling.truncated_to_integer
         else
            Result := double_floor.truncated_to_integer
         end
      end

   truncated_to_integer: INTEGER is
         -- Integer part (same sign, largest absolute value
         -- no greater than Current).
      external "SmartEiffel"
      ensure
         Result.to_double <= Current
      end

   to_real: REAL is
         -- Note: C conversion from "double" to "float".
         -- Thus, Result can be undefine (ANSI C).
      external "SmartEiffel"
      end

   to_string: STRING is
         -- Convert the DOUBLE into a new allocated STRING.
         -- As ANSI C, the default number of digit for the
         -- fractionnal part is 6.
         -- Note: see `append_in' to save memory.
      do
         create Result.make(16)
         append_in(Result)
      end

   append_in(str: STRING) is
         -- Append the equivalent of `to_string' at the end of
         -- `str'. Thus you can save memory because no other
         -- STRING is allocate for the job.
      require
         str /= Void
      do
         append_in_format(str,6)
      end

   to_string_format(f: INTEGER): STRING is
         -- Convert the DOUBLE into a new allocated STRING including
         -- only `f' digits in fractionnal part.
         -- Note: see `append_in_format' to save memory.
      require
         f >= 0
      do
         basic_sprintf_double(sprintf_buffer,f,Current)
         !!Result.from_external_copy(sprintf_buffer.to_pointer)
      end

   append_in_format(str: STRING; f: INTEGER) is
         -- Same as `append_in' but produce `f' digit of
         -- the fractionnal part.
      require
         str /= Void
         f >= 0
      local
         i: INTEGER
      do
         from
            basic_sprintf_double(sprintf_buffer,f,Current)
            i := 0
         until
            sprintf_buffer.item(i) = '%U'
         loop
            str.extend(sprintf_buffer.item(i))
            i := i + 1
         end
      end

feature -- Maths functions:

   sqrt: DOUBLE is
         -- Square root of `Current' (ANSI C `sqrt').
      require
         Current >= 0
      external "SmartEiffel"
      end

   sin: DOUBLE is
         -- Sine of `Current' (ANSI C `sin').
      external "SmartEiffel"
      end

   cos: DOUBLE is
         -- Cosine of `Current' (ANSI C `cos').
      external "SmartEiffel"
      end

   tan: DOUBLE is
         -- Tangent of `Current' (ANSI C `tan').
      external "SmartEiffel"
      end

   asin: DOUBLE is
         -- Arc Sine of `Current' (ANSI C `asin').
      external "SmartEiffel"
      end

   acos: DOUBLE is
         -- Arc Cosine of `Current' (ANSI C `acos').
      external "SmartEiffel"
      end

   atan: DOUBLE is
         -- Arc Tangent of `Current' (ANSI C `atan').
      external "SmartEiffel"
      end

   atan2(x: DOUBLE): DOUBLE is
         -- Arc Tangent of `Current' / `x'  (ANSI C `atan2').
      external "SmartEiffel"
      end

   sinh: DOUBLE is
         -- Hyperbolic Sine of `Current' (ANSI C `sinh').
      external "SmartEiffel"
      end

   cosh: DOUBLE is
         -- Hyperbolic Cosine of `Current' (ANSI C `cosh').
      external "SmartEiffel"
      end

   tanh: DOUBLE is
	 -- Hyperbolic Tangent of `Current' (ANSI C `tanh').
      external "SmartEiffel"
      end

   exp: DOUBLE is
         -- Exponential of `Current' (ANSI C `exp').
      external "SmartEiffel"
      end

   log: DOUBLE is
         -- Natural Logarithm of `Current' (ANSI C `log').
      external "SmartEiffel"
      end

   log10: DOUBLE is
         -- Base-10 Logarithm of Current (ANSI C `log10').
      external "SmartEiffel"
      end

   pow(e: DOUBLE): DOUBLE is
	 -- `Current' raised to the power of `e' (ANSI C `pow').
      external "SmartEiffel"
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
	 if Current < 0.0 then
	    Result := -1
	 elseif 0.0 < Current then
	    Result := 1
	 else
	    Result := 0
	 end
      end
   
   one: DOUBLE is 1.0
   
   zero: DOUBLE is 0.0
   
   divisible(other: like Current): BOOLEAN is
      do
         Result := (other /= 0.0)
      end

feature -- Hashing:

   hash_code: INTEGER is
      do
         Result := truncated_to_integer
	 if Result < 0 then
	    Result := - (Result + 1)
	 end
      end

feature -- For compatibility with the obsolete DOUBLE_REF style:
   
   item: DOUBLE
   
   set_item(value: like item) is
      do
	 item := value
      ensure
	 item = value
      end

feature {NONE}

   ceil: DOUBLE is
      external "SmartEiffel"
      end

   basic_sprintf_double(buffer: NATIVE_ARRAY[CHARACTER];
			f: INTEGER; d: DOUBLE) is
         -- Put in the `buffer' a viewable version of Current with
         -- `f' digit of the fractionnal part. Assume the `buffer' is
         -- large enougth.
      require
         f >= 0
      external "SmartEiffel"
      end

   sprintf_buffer: NATIVE_ARRAY[CHARACTER] is
      once
         Result := Result.calloc(1024)
      end

end -- DOUBLE

