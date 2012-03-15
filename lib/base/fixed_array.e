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
class FIXED_ARRAY[E]
   --
   -- Resizable, fixed lower bound array.
   -- Unlike ARRAY, the `lower' bound of a FIXED_ARRAY is frozen
   -- to 0. Thus, some memory is saved and looping toward `lower'
   -- bound (which is 0) run a little bit faster.
   --
obsolete "The new name of this class is now FAST_ARRAY. Please update your code."

inherit FAST_ARRAY[E]

creation
   make, with_capacity, from_collection

end -- FIXED_ARRAY[E]

