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
deferred class GEN_RAND
   --
   -- Here is the common way to use a random number generator.
   -- Current implementations are MIN_STAND, STD_RAND.
   --

feature -- Creation procedures:

   make is
         -- Create the generator with an automatic hazardous setting of
         -- the `seed_value'.
         -- Because automatic setting may be done using internal address
         -- of Current for example, it may produces platform dependent
         -- behavior or compilation-mode dependant behavior.
         -- Also consider `with_seed' to chose the most appropriate.
      deferred
      end

   with_seed(seed_value: INTEGER) is
         -- Create the generator with an explicit `seed_value'.
      deferred
      end

feature

   next is
         -- Compute next random number in sequence.
      deferred
      end

feature -- No modifications:

   last_double: DOUBLE is
         -- Look at the last computed number.
         -- Range 0 to 1
      do
         Result := last_real.to_double
      ensure
         Result > 0 and Result <= 1
      end

   last_real: REAL is
         -- Look at the last computed number.
         -- Range 0 to 1
      deferred
      ensure
         Result > 0 and Result <= 1
      end

   last_integer(n:INTEGER):INTEGER is
         -- Look the last computed number.
         -- Range 1 to `n'.
      require
         n >= 1
      deferred
      ensure
         1 <= Result and Result <= n
      end

end -- GEN_RAND


