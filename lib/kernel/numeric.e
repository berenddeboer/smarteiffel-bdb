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
deferred class  NUMERIC
   --
   -- This class describes a ring.
   --

inherit HASHABLE

feature

   infix "+" (other: like Current): like Current is
         -- Sum with `other' (commutative).
--      require
--        other /= Void
      deferred
      end

   infix "-" (other: like Current): like Current is
         -- Result of substracting `other'.
--      require
--         other /= Void
      deferred
      end

   infix "*" (other: like Current): like Current is
         -- Product by `other'.
--      require
--         other /= Void
      deferred
      end

   infix "/" (other: like Current): NUMERIC is
         -- Division by `other'.
      require
         other /= Void
         divisible (other)
      deferred
      end

   prefix "+" : like Current is
         -- Unary plus of `Current'.
      deferred
      end

   prefix "-" : like Current is
         -- Unary minus of `Current'.
      deferred
      end

   divisible(other: like Current): BOOLEAN is
         -- May `Current' be divided by `other' ?
      require
         other /= Void
      deferred
      end

   one: like Current is
         -- Neutral element for "*" and "/".
      deferred
      end

   zero: like Current is
         -- Neutral element for "+" and "-".
      deferred
      end

   sign: INTEGER_8 is
         -- Sign of Current (0 -1 or 1).
      deferred
      ensure
         -1 <= Result; Result <= 1
      end

end --  NUMERIC
