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
expanded class MATH_CONSTANTS
   --
   -- Platform-independent, universal, mathematical constants.
   -- Intended to be used as ancestor for classes that need these constants.
   --

inherit
   ANY
      redefine Pi, Evalue, Deg, Phi
      end

feature -- Maths constants:

   Pi    : DOUBLE is  3.1415926535897932384626

   Evalue: DOUBLE is  2.7182818284590452353602

   Deg   : DOUBLE is 57.2957795130823208767981; -- Degrees/Radian

   Phi   : DOUBLE is  1.6180339887498948482045; -- Golden Ratio
	
	
end -- MATH_CONSTANTS

