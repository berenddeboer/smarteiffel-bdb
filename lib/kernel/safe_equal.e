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
expanded class SAFE_EQUAL[E]
   --
   -- The goal of this class is to share the definition of feature 
   -- `safe_equal'. Feature `safe_equal' compares two arguments of type E, 
   -- by calling `is_equal' only and only if both arguments have the 
   -- `same_dynamic_type'.
   --

feature {NONE}

   safe_equal(e1, e2: E): BOOLEAN is
         -- In order to avoid run-time type errors, feature `safe_equal' call
         -- `is_equal' only when `e1' and `e2' have exactly the same dynamic 
         -- type. Furthermore, this feature avoid argument passing from some
         -- expanded type to the corresponding reference type (no automatic
         -- allocation of some reference type during the comparison).
      do
	 -- Note: the following implementation may appear complicated, but this 
	 -- is automatically optimized by the compiler.
         if e1 = e2 then
	    Result := True
         elseif e1 = Void then
         elseif e2 = Void then
	 elseif not e1.is_basic_expanded_type then
	    if e1.same_dynamic_type(e2) then
	       Result := e1.is_equal(e2)
	    end
	 end
      end

end
