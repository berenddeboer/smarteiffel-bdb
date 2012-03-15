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
class NUMBER_FRACTION
   --
   -- To implement NUMBER (do not use this class, see NUMBER).
   --

inherit ABSTRACT_FRACTION

creation make, make_simply

feature {NUMBER}

   is_negative: BOOLEAN

   numerator: ABSTRACT_INTEGER

   denominator: ABSTRACT_INTEGER

   make(n, d: ABSTRACT_INTEGER; s: BOOLEAN) is
	 -- Create a simplified large_fraction
      require
	 n.is_positive
	 d.is_positive
	 not ((n \\ d) @= 0)
      local
	 gcd_frac,num,den: ABSTRACT_INTEGER
      do
	 gcd_frac := n.gcd(d)
 	 num ?= n // gcd_frac
	 den ?= d // gcd_frac
	 numerator := num
	 denominator := den
	 is_negative := s
      end

   make_simply (n, d: ABSTRACT_INTEGER; s: BOOLEAN)  is
	 -- create a large_fraction without simplify it
      require
	 n.is_positive
	 d.is_positive
	 not ((n \\ d) @= 0)
      do
	 numerator := n
	 denominator := d
	 is_negative := s
      end

feature

   is_positive: BOOLEAN is
      do
	 Result := not is_negative
      end

   append_in(string: STRING) is
      do
	 if is_negative then
	    string.extend('-')
	 end
	 numerator.append_in(string)
	 string.extend('/')
	 denominator.append_in(string)
      end

   append_decimal_in(buffer: STRING; digits: INTEGER; all_digits: BOOLEAN) is
      do
	 decimal_in(buffer,numerator,denominator,
		    is_negative,digits, all_digits)
      end

   is_equal(other: NUMBER): BOOLEAN is
      local
	 n2: like Current
      do
	 n2 ?= other
	 if n2 /= Void then
	    if is_negative then
	       if n2.is_negative then
		  Result := (denominator.is_equal(n2.denominator)
			     and then
			     numerator.is_equal(n2.numerator))
	       end
	    elseif n2.is_positive then
	       Result := (denominator.is_equal(n2.denominator)
			  and then
			  numerator.is_equal(n2.numerator))
	    end
	 end
      end
   
feature {NUMBER}

   to_double: DOUBLE is
      do
	 Result := numerator.to_double / denominator.to_double
	 if is_negative then
	    Result := - Result
	 end
      end

   prefix "-": NUMBER is
      do
	 create {NUMBER_FRACTION}
	    Result.make_simply(numerator,denominator,not is_negative)
      end


   infix "+"(other: NUMBER): NUMBER is
      do
	 Result := other.add_with_large_fraction(Current)
      end


   add_with_large_positive_integer(other: LARGE_POSITIVE_INTEGER): NUMBER is
      local
	 num : ABSTRACT_INTEGER
      do
	 if is_negative then
	    num ?= (other * denominator) + (-numerator)
	    check
	       num /= Void
	    end
	 else
	    num ?= (other * denominator) + numerator
	    check
	       num /= Void
	    end
	 end
	 Result := from_two_abstract_integer(num,denominator)
      end

   add_with_large_negative_integer(other: LARGE_NEGATIVE_INTEGER): NUMBER is
      local
	 num: ABSTRACT_INTEGER
      do
	 if is_negative then
	    num ?= (other * denominator) + (-numerator)
	    check
	       num /= Void
	    end
	 else
	    num ?= (other * denominator) + numerator
	    check
	       num /= Void
	    end
	 end
	 Result := from_two_abstract_integer(num,denominator)
      end

   add_with_small_fraction(other: INTEGER_FRACTION): NUMBER is
      do
	 Result := other.add_with_large_fraction(Current)
      end


   add_with_large_fraction(other: NUMBER_FRACTION): NUMBER is
      local
	 new_num, new_den: ABSTRACT_INTEGER
      do
	 new_den ?= denominator * other.denominator
	 if is_negative then
	    if other.is_negative then
	       new_num ?= (-(numerator) * other.denominator) + (-(other.numerator) * denominator)
	    else
	       new_num ?= (-(numerator) * other.denominator) + (other.numerator * denominator);	       
	    end
	 else
	    if other.is_negative then
	       new_num ?= (numerator * other.denominator) + (-(other.numerator) * denominator)
	    else
	       new_num ?= (numerator * other.denominator) + (other.numerator * denominator)
	    end
	 end
	 check
	    new_num /= Void
	    new_den /= Void
	 end
	 Result := from_two_abstract_integer(new_num,new_den)
      end

   infix "@+"(other: INTEGER): NUMBER is
      -- Sum of 'Current' and 'other'.
      local
	 tmp: SMALL_INTEGER
      do
	 !SMALL_INTEGER!tmp.make(other)
	 Result := add_with_small_integer(tmp)
      end


   infix "*" (other: NUMBER): NUMBER is
      do
	 Result := other.multiply_with_large_fraction(Current)
      end

   multiply_with_large_positive_integer(other: LARGE_POSITIVE_INTEGER): NUMBER is
      local
	 num: ABSTRACT_INTEGER
      do
	 num ?= numerator.multiply_with_large_positive_integer(other)
	 check
	    num /= Void
	 end
	 if is_negative then
	    num ?= -num
	    Result := from_two_abstract_integer(num,denominator)
	 else
	    Result := from_two_abstract_integer(num,denominator)
	 end
      end

   multiply_with_large_negative_integer(other: LARGE_NEGATIVE_INTEGER): NUMBER is
      local
	 num: ABSTRACT_INTEGER
      do
	 num ?= numerator.multiply_with_large_negative_integer(other)
	 check
	    num /= Void
	 end
	 if is_negative then
	    num ?= -num
	    Result := from_two_abstract_integer(num, denominator)
	 else
	    Result := from_two_abstract_integer(num, denominator)
	 end
      end

   multiply_with_small_fraction(other: INTEGER_FRACTION): NUMBER is
      do
	Result := other.multiply_with_large_fraction(Current)
      end

   multiply_with_large_fraction (other: NUMBER_FRACTION) : NUMBER is
      local
	 prod1, prod2: ABSTRACT_INTEGER
      do
	 if is_negative xor other.is_negative then
	    prod1 ?= -numerator * other.numerator
	 else
	    prod1 ?= numerator * other.numerator
	 end
	 prod2 ?= denominator * other.denominator
	 check
	    prod1 /= Void
	    prod2 /= Void
	 end
	 Result := from_two_abstract_integer(prod1,prod2)
      end

   infix "@*"(other: INTEGER): NUMBER is
      local
	 tmp: SMALL_INTEGER
      do
	 if numerator.is_one then
	    if is_negative then
	       Result := from_integer_and_abstract_integer(-other,denominator)
	    else
	       Result := from_integer_and_abstract_integer(other,denominator)
	    end
	 else
	    !SMALL_INTEGER!tmp.make(other)
	    Result := multiply_with_small_integer(tmp)
	 end
      end

   infix "@/"(other: INTEGER): NUMBER is
      do
	 if other = 1 then
	    Result := Current
	 else
	    Result := Current * from_two_integer(1,other)
	 end
      end

   inverse: NUMBER is
      do
	 if numerator.is_one then
	    Result := denominator
	 elseif (-numerator).is_one then
	    Result := -denominator
	 else
	    !NUMBER_FRACTION!Result.make_simply(denominator, numerator, is_negative)
	 end
      end


feature -- Comparisons with INTEGER

   infix "@<" (other: INTEGER): BOOLEAN is
      require
	 other /= Minimum_integer
      do
	 if is_negative then
	    if other < 0 then
	       Result := numerator > (denominator @* -other)
	    else
	       Result := true
	    end
	 elseif other >= 0 then
	    Result := numerator < (denominator @* other)
	 end
      end

   infix "@>"(other: INTEGER): BOOLEAN is
      require
	 other /= Minimum_integer
      do
	 if is_negative then
	    if other < 0 then
	       Result := numerator < (denominator @* -other)
	    end
	 else
	    if other < 0 then
	       Result := True
	    else
	       Result := numerator > (denominator @* other)
	    end
	 end
      end

    infix "@<="(other: INTEGER): BOOLEAN is
      require
	 other /= Minimum_integer
      do
	 if is_negative then
	    if other < 0 then
	       Result := numerator >= (denominator @* -other)
	    else
	       Result := true
	    end
	 elseif other >= 0 then
	    Result := numerator <= (denominator @* other)
	 end
      end

    infix "@>="(other: INTEGER): BOOLEAN is
      require
	 other /= Minimum_integer
      do
	 if is_negative then
	    if other < 0 then
	       Result := numerator <= (denominator @* -other)
	    end
	 else
	    if other < 0 then
	       Result := True
	    else
	       Result := numerator >= (denominator @* other)
	    end
	 end
      end

   infix "<"(other: NUMBER): BOOLEAN is
      do
	 Result := other.greater_with_large_fraction(Current)
      end

   infix "#=" (other: DOUBLE): BOOLEAN is
      do
	 if (Current <= max_double) and then (min_double <= Current) then
	    Result := to_double = other
	 end
      end

   infix "#<" (other: DOUBLE): BOOLEAN is
      do
-- 	 if (min_double <= Current) and then (Current <= max_double) then
-- 	    Result := to_double < other
-- 	 else
-- 	    Result := max_double > Current
-- 	 end
	 if min_double > Current then
	    Result := True
	 elseif Current < max_double then
	    Result := to_double < other
	 end
      end

   infix "#<=" (other: DOUBLE): BOOLEAN is
      do
	 if min_double >= Current then
	    Result := True
	 elseif Current <= max_double then
	    Result := to_double <= other
	 end
      end


   infix "#>=" (other: DOUBLE): BOOLEAN is
      do
	 if max_double <= Current then
	    Result := True
	 elseif Current >= min_double then
	    Result := to_double >= other
	 end
      end

   infix "#>" (other: DOUBLE): BOOLEAN is
      do
	 if max_double < Current then
	    Result := True
	 elseif Current > min_double then
	    Result := to_double > other
	 end
      end


feature{NUMBER}

  greater_with_large_positive_integer(other: LARGE_POSITIVE_INTEGER): BOOLEAN is
      do
	 if is_negative then
	    Result := denominator.multiply_with_large_positive_integer(other) < -numerator
	 else
	    Result := denominator.multiply_with_large_positive_integer(other) < numerator
	 end
      end

   greater_with_large_negative_integer(other: LARGE_NEGATIVE_INTEGER): BOOLEAN is
      do
	 if is_negative then
	    Result := denominator.multiply_with_large_negative_integer(other) < -numerator
	 else
	    Result := denominator.multiply_with_large_negative_integer(other) < numerator
	 end
      end

   greater_with_small_fraction(other: INTEGER_FRACTION): BOOLEAN is
      do
	 if is_negative then
	    Result := other.small_numerator * denominator < -numerator * other.small_denominator
	 else
	    Result := other.small_numerator * denominator < numerator * other.small_denominator
	 end
      end

   greater_with_large_fraction(other: NUMBER_FRACTION): BOOLEAN is
      do
	 if is_negative and then other.is_negative then
	    Result := numerator * other.denominator < other.numerator * denominator
	 elseif is_negative then
	    Result := other.numerator * denominator < -numerator * other.denominator
	 elseif other.is_negative then
	    Result := -other.numerator * denominator < numerator * other.denominator
	 else
	    Result := other.numerator * denominator < numerator * other.denominator
	 end
      end

invariant

   not (numerator.is_small_integer and denominator.is_small_integer)

end -- NUMBER_FRACTION


