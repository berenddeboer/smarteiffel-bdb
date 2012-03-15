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
deferred class ABSTRACT_INTEGER
--
-- To implement NUMBER (do not use this class, see NUMBER).
--

inherit NUMBER

feature

   append_in(buffer: STRING) is
      deferred
      end

   append_decimal_in(buffer: STRING; digits: INTEGER; all_digits: BOOLEAN) is
      do
	 append_in(buffer)
      end

feature {NUMBER}

   is_integer_value: BOOLEAN is
      deferred
      end

   integer_divide_small_integer(other: SMALL_INTEGER): ABSTRACT_INTEGER is
      require
	 other /= Void
      deferred
      ensure
	 Result /= Void
      end

   remainder_of_divide_small_integer(other: SMALL_INTEGER): ABSTRACT_INTEGER is
      require
	 other /= Void
      deferred
      ensure
	 Result /= Void
      end


   integer_divide_large_positive_integer(other: LARGE_POSITIVE_INTEGER): ABSTRACT_INTEGER is
      require
	 other /= Void
      deferred
      ensure
	 Result /= Void
      end

   remainder_of_divide_large_positive_integer(other: LARGE_POSITIVE_INTEGER): ABSTRACT_INTEGER is
      require
	 other /= Void
      deferred
      ensure
	 Result /= Void
      end


   integer_divide_large_negative_integer(other: LARGE_NEGATIVE_INTEGER): ABSTRACT_INTEGER is
      require
	 other /= Void
      deferred
      ensure
	 Result /= Void
      end

   remainder_of_divide_large_negative_integer(other: LARGE_NEGATIVE_INTEGER): ABSTRACT_INTEGER is
      require
	 other /= Void
      deferred
      ensure
	 Result /= Void
      end


feature{NONE}

   mult_2_integer(a, b: INTEGER) is
	 -- multiply a and b and store the result in temp_2_digints
      require
	 a >= 0
	 b >= 0
      local
	 left_a, left_b, right_a, right_b: INTEGER
	 upper_half_base: INTEGER
	 temp1, temp2: INTEGER
      do
	 upper_half_base := 2*Half_base
	 left_a := a // upper_half_base
	 right_a := a \\ upper_half_base
	 left_b := b // Half_base
	 right_b := b \\ Half_base

	 temp_2_digints.put(left_a * left_b, 1)
	 temp_2_digints.put(right_a * right_b, 0)

	 temp1 := left_a * right_b
	 temp_2_digints.put((temp_2_digints @ 1) + (temp1 // Half_base), 1)
	 temp2 := (temp1 \\ Half_base)*upper_half_base + (temp_2_digints @ 0)
	 if (temp2 < 0) then
	    temp_2_digints.put(temp2 - Base, 0)
	    temp_2_digints.put((temp_2_digints @ 1) + 1, 1)
	 else
	    temp_2_digints.put(temp2 , 0)
	 end

	 temp1 := left_b * right_a
	 if (temp1 < 0) then
	    temp1 := temp1 - Base
	    temp_2_digints.put((temp_2_digints @ 1) + Half_base, 1)
	 end
	 temp_2_digints.put((temp_2_digints @ 1)+(temp1 // upper_half_base), 1)
	 temp2 := (temp1 \\ upper_half_base)*Half_base + (temp_2_digints @ 0)
	 if (temp2 < 0) then
	    temp_2_digints.put(temp2 - Base, 0)
	    temp_2_digints.put((temp_2_digints @ 1) + 1, 1)
	 else
	    temp_2_digints.put(temp2, 0)
	 end
      end

end -- ABSTRACT_INTEGER









