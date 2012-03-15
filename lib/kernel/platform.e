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
class PLATFORM
--
-- This class is ancestor for any user class. This class provides information
-- as number of bits for basic types and minimum/maximum values.
--

inherit GENERAL

feature -- Maximum:

   Maximum_character_code : INTEGER_16 is
         -- Largest supported code for CHARACTER values.
      external "SmartEiffel"
      ensure
         meaningful: Result >= 127
      end

   Maximum_integer_8: INTEGER_8 is 127
         -- Largest supported value of type INTEGER_8.

   Maximum_integer_16: INTEGER_16 is 32767
         -- Largest supported value of type INTEGER_16.

   Maximum_integer, Maximum_integer_32: INTEGER is 2147483647
         -- Largest supported value of type INTEGER/INTEGER_32.

   Maximum_integer_64: INTEGER_64 is 9223372036854775807
         -- Largest supported value of type INTEGER_64.

   Maximum_real: REAL is
         -- Largest supported value of type REAL.
      external "SmartEiffel"
      ensure
         meaningful: Result >= 0.0
      end

   Maximum_double: DOUBLE is
         -- Largest supported value of type DOUBLE.
      external "SmartEiffel"
      ensure
         meaningful: Result >= Maximum_real
      end

feature -- Minimum:

   Minimum_character_code: INTEGER_16 is
         -- Smallest supported code for CHARACTER values.
      external "SmartEiffel"
      ensure
         meaningful: Result <= 0
      end

   Minimum_integer_8: INTEGER_8 is -128
         -- Smallest supported value of type INTEGER_8.

   Minimum_integer_16: INTEGER_16 is -32768
         -- Smallest supported value of type INTEGER_16.

   Minimum_integer, Minimum_integer_32: INTEGER is -2147483648
         -- Smallest supported value of type INTEGER/INTEGER_32.

   Minimum_integer_64: INTEGER_64 is -9223372036854775808
         -- Smallest supported value of type INTEGER_64.

   Minimum_double: DOUBLE is
         -- Smallest supported value of type DOUBLE.
      external "SmartEiffel"
      ensure
         meaningful: Result <= 0.0
      end

   Minimum_real: REAL is
         -- Smallest supported value of type REAL.
      external "SmartEiffel"
      ensure
         meaningful: Result <= 0.0
      end

feature -- Bits:

   Boolean_bits: INTEGER is
         -- Number of bits in a value of type BOOLEAN.
      external "SmartEiffel"
      ensure
         meaningful: Result >= 1
      end

   Character_bits: INTEGER is
         -- Number of bits in a value of type CHARACTER.
      external "SmartEiffel"
      ensure
         meaningful: Result >= 1
         large_enough: ((2).to_integer_32^Result) >= Maximum_character_code
      end

   Integer_bits: INTEGER is
         -- Number of bits in a value of type INTEGER.
      external "SmartEiffel"
      ensure
         integer_definition: Result = 32
      end

   Real_bits: INTEGER is
         -- Number of bits in a value of type REAL.
      external "SmartEiffel"
      ensure
         meaningful: Result >= 1
      end

   Double_bits: INTEGER is
         -- Number of bits in a value of type DOUBLE.
      external "SmartEiffel"
      ensure
         meaningful: Result >= 1
         meaningful: Result >= Real_bits
      end

   Pointer_bits: INTEGER is
         -- Number of bits in a value of type POINTER.
      external "SmartEiffel"
      end

end -- PLATFORM

