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
expanded class BOOLEAN
--
-- Note: An Eiffel BOOLEAN is mapped as a C char or as a Java int.
--

inherit
   ANY
      export {NONE} copy
      redefine out_in_tagged_out_memory, fill_tagged_out_memory
      end

feature

   infix "and" (other: BOOLEAN): BOOLEAN is
         -- `and' of Current with `other'.
         --
         -- Note: when evaluation of `other' has no side effects, it
         -- may be better to use "and then" to avoid execution-time
         -- overhead.
      do
         Result := Current and then other
      end

   infix "and then" (other: BOOLEAN): BOOLEAN is
         -- Semi-strict `and' of Current with `other'.
      external "SmartEiffel"
      end

   infix "implies"(other: BOOLEAN): BOOLEAN is
         -- Does Current imply `other'.
      external "SmartEiffel"
      end

   infix "or" (other: BOOLEAN): BOOLEAN is
         -- `or' of Current with `other'
         --
         -- Note: when evaluation of `other' has no side effects, it
         -- may be better to use "or else" to avoid execution-time
         -- overhead.
      do
         Result := Current or else other
      end

   infix "or else" (other: BOOLEAN): BOOLEAN is
         -- Semi-strict `or' of Current with `other'
      external "SmartEiffel"
      end

   infix "xor" (other: BOOLEAN): BOOLEAN is
         -- `xor' of Current with `other'
      do
	 Result := Current /= other
      end

   prefix "not": BOOLEAN is
         -- `not' of Current.
      do
	 Result := Current = False
      end

   to_string: STRING is
      do
         if item then
            Result := once "True"
         else
            Result := once "False"
         end
      ensure
         (once "True").is_equal(Result) implies Current
         (once "False").is_equal(Result) implies not Current
      end

   to_integer: INTEGER is
      do
         if item then
            Result := 1
         else
            Result := 0
         end
      ensure
         Result = 1 implies Current
         Result = 0 implies not Current
      end

   to_character: CHARACTER is
      do
         if item then
            Result := '1'
         else
            Result := '0'
         end
      ensure
         Result = '1' implies Current
         Result = '0' implies not Current
      end

   append_in(str: STRING) is
      do
         str.append(to_string)
      end

feature -- Object Printing:

   out_in_tagged_out_memory, fill_tagged_out_memory is
      do
         tagged_out_memory.append(to_string)
      end

feature -- For compatibility with the obsolete BOOLEAN_REF style:
   
   item: BOOLEAN
   
   set_item(value: like item) is
      do
	 item := value
      ensure
	 item = value
      end

end -- BOOLEAN
