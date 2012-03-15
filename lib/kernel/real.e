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
expanded class  REAL
--
-- REAL is the type for real numbers. You may consider DOUBLE type if you
-- need more precision.
--
-- Note: An Eiffel REAL is mapped as a C float or as a Java float.
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
	 out_in_tagged_out_memory, fill_tagged_out_memory
      end

feature

   infix "+" (other: like Current): REAL is
      external "SmartEiffel"
      end

   infix "-" (other: like Current): REAL is
      external "SmartEiffel"
      end

   infix "*" (other: like Current): REAL is
      external "SmartEiffel"
      end

   infix "/" (other: like Current): REAL is
      external "SmartEiffel"
      end

   infix "^" (e: INTEGER): DOUBLE is
         -- Raise Current to `e'-th power (see also `pow').
      do
         check
            Current = 0.0 implies e > 0
         end
         Result := to_double ^ e
      end

   prefix "+" : like Current is
      do
         Result := Current
      end

   prefix "-": REAL is
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

   floor: INTEGER is
         -- Greatest integral value no greater than Current.
      do
         Result := to_double.floor
      ensure
	 result_no_greater: Result <= Current
	 close_enough: Current - Result < one
      end

   ceiling: INTEGER is
         -- Smallest integral value no smaller than Current.
      do
         Result := to_double.ceiling
      ensure
	 result_no_smaller: Result >= Current
	 close_enough: Result - Current < one
      end

   rounded: INTEGER is
         -- Rounded integral value.
      do
         Result := to_double.rounded
      end

   truncated_to_integer: INTEGER is
         -- Integer part (same sign, largest absolute value
         -- no greater than Current).
      do
         Result := to_double.truncated_to_integer
      ensure
         Result.to_real <= Current
      end

   to_string: STRING is
         -- Convert the REAL into a new allocated STRING.
         -- Note: see `append_in' to save memory.
      do
         Result := to_double.to_string
      end

   append_in(str: STRING) is
         -- Append the equivalent of `to_string' at the end of
         -- `str'. Thus you can save memory because no other
         -- STRING is allocate for the job.
      require
         str /= Void
      do
         to_double.append_in(str)
      end

   to_string_format(d: INTEGER): STRING is
         -- Convert the REAL into a new allocated STRING including
         -- only `d' digits in fractional part.
         -- Note: see `append_in_format' to save memory.
      do
         Result := to_double.to_string_format(d)
      end

   append_in_format(str: STRING; f: INTEGER) is
         -- Same as `append_in' but produce only `f' digit of
         -- the fractional part.
      require
         str /= Void
         f >= 0
      do
         to_double.append_in_format(str,f)
      end

   to_double: DOUBLE is
      external "SmartEiffel"
      end

feature -- Maths functions:

   sqrt: DOUBLE is
         -- Square root of `Current' (ANSI C `sqrt').
      require
         Current >= 0
      do
         Result := to_double.sqrt
      end

   sin: DOUBLE is
         -- Sine of `Current' (ANSI C `sin').
      do
         Result := to_double.sin
      end

   cos: DOUBLE is
         -- Cosine of `Current' (ANSI C `cos').
      do
         Result := to_double.cos
      end

   tan: DOUBLE is
         -- Tangent of `Current' (ANSI C `tan').
      do
         Result := to_double.tan
      end

   asin: DOUBLE is
         -- Arc Sine of `Current' (ANSI C `asin').
      do
         Result := to_double.asin
      end

   acos: DOUBLE is
         -- Arc Cosine of `Current' (ANSI C `acos').
      do
         Result := to_double.acos
      end

   atan: DOUBLE is
         -- Arc Tangent of `Current' (ANSI C `atan').
      do
         Result := to_double.atan
      end

   atan2(x: DOUBLE): DOUBLE is
         -- Arc Tangent of `Current' / `x'  (ANSI C `atan2').
      do
         Result := to_double.atan2(x)
      end

   sinh: DOUBLE is
         -- Hyperbolic Sine of `Current' (ANSI C `sinh').
      do
         Result := to_double.sinh
      end

   cosh: DOUBLE is
         -- Hyperbolic Cosine of `Current' (ANSI C `cosh').
      do
         Result := to_double.cosh
      end

   tanh: DOUBLE is
	 -- Hyperbolic Tangent of `Current' (ANSI C `tanh').
      do
         Result := to_double.tanh
      end

   exp: DOUBLE is
         -- Exponential of `Current' (ANSI C `exp').
      do
         Result := to_double.exp
      end

   log: DOUBLE is
         -- Natural Logarithm of `Current' (ANSI C `log').
      do
         Result := to_double.log
      end

   log10: DOUBLE is
         -- Base-10 Logarithm of Current (ANSI C `log10').
      do
         Result := to_double.log10
      end

   pow(e: DOUBLE): DOUBLE is
	 -- `Current' raised to the power of `e' (ANSI C `pow').
      do
	 Result := to_double.pow(e)
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
   
   one: REAL is 1.0
   
   zero: REAL is 0.0
   
   divisible(other: like Current): BOOLEAN is
      do
         Result := (other /= 0.0)
      end

feature -- Hashing:

   hash_code: INTEGER is
      do
         Result := to_double.hash_code
      end

feature -- For compatibility with the obsolete REAL_REF style:
   
   item: REAL
   
   set_item(value: like item) is
      do
	 item := value
      ensure
	 item = value
      end

end --  REAL

