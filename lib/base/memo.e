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
class MEMO[E]
   -- This strange tiny class is useful to share a common volatile
   -- expanded value between different objects or as the result of 
   -- a once function.
   -- So in most cases the E type is expanded and the reference to the
   -- MEMO[E] container object is shared.
   -- Other name for `MEMO' is sometimes `CELL'

feature

   item: E

   set_item(i: like item) is
      do
         item := i
      ensure
         item = i
      end

   clear is
         -- Reset `item' with the default value.
      local
         default_item: like item
      do
         item := default_item
      end

end -- MEMO[E]

