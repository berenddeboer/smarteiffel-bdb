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
deferred class HASHABLE
   --
   -- Ancestor class for all hashable objects.
   -- For example, the `hash_code' is needed for DICTIONARY and for SET.
   -- Thus, most standard objects are HASHABLE (STRING, DOUBLE, REAL, 
   -- INTEGER_8, INTEGER_16, INTEGER_32, INTEGER_64, POINTER, NUMBER,
   -- MUTABLE_BIG_INTEGER, etc.). 
   --

feature

   hash_code: INTEGER is
         -- The hash-code value of `Current'.
      deferred
      ensure
         good_hash_value: Result >= 0
      end

end -- HASHABLE

