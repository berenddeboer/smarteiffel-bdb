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
deferred class ABSTRACT_FRACTION
--
-- To implement NUMBER (do not use this class, see NUMBER).
--

inherit NUMBER

feature

   is_zero: BOOLEAN is false

   is_one: BOOLEAN is false

   frozen to_integer: INTEGER is
      do
	 check false end
      end

   infix "@=" (other: INTEGER): BOOLEAN is do end

   infix "//"(other: NUMBER): NUMBER is
      do
	 check false end
      end

   infix "@//"(other: INTEGER): NUMBER is
      do
	 check false end
      end

   infix "\\"(other: NUMBER): NUMBER is
      do
	 check false end
      end

   infix "@\\"(other: INTEGER): NUMBER is
      do
	 check false end
      end

feature {NUMBER}

   from_two_integer(n, d: INTEGER): NUMBER is
      local
	 num, den, g: INTEGER
      do
	 g := n.abs.gcd(d.abs)
	 num := n.abs // g
	 den := d.abs // g
	 if (den = 1) then
	    if (n < 0) xor (d < 0) then
	       !SMALL_INTEGER!Result.make(-num)
	    else
	       !SMALL_INTEGER!Result.make(num)
	    end
	 else
	    if (n < 0) xor (d < 0) then
	       !INTEGER_FRACTION!Result.make(-num,den)
	    else
	       !INTEGER_FRACTION!Result.make(num,den)
	    end
	 end
      end

   from_two_abstract_integer(n, d: ABSTRACT_INTEGER): NUMBER is
      local
	 num, den : ABSTRACT_INTEGER
	 n_abs, g: ABSTRACT_INTEGER
      do
	 n_abs ?= n.abs
	 g := n_abs.gcd(d.abs)
	 if (g @= 1) then
	    num := n
	    den := d
	 else
	    num ?= n // g
	    den ?= d // g
	 end
	 if (den.is_one) then
	    Result := num
	 else
	    num ?= num.abs
	    den ?= den.abs
	    if num.is_small_integer and then den.is_small_integer and then (n.is_negative xor d.is_negative) then
	       !INTEGER_FRACTION!Result.make(-num.to_integer,den.to_integer)
	    elseif (num.is_small_integer and then den.is_small_integer) then
	       !INTEGER_FRACTION!Result.make(num.to_integer,den.to_integer)
	    else
	       !NUMBER_FRACTION!Result.make_simply(num,den,(n.is_negative xor d.is_negative))
	    end
	 end
      end

   from_integer_and_abstract_integer(n: INTEGER; d: ABSTRACT_INTEGER): NUMBER is
      require
	 d /= Void
      local
	 num: ABSTRACT_INTEGER
      do
	 if n >= Base then
	    !LARGE_POSITIVE_INTEGER!num.make_smaller(n)
	 elseif n <= -Base then
	    !LARGE_NEGATIVE_INTEGER!num.make_smaller(n)
	 else
	    !SMALL_INTEGER!num.make(n)
	 end
	 Result := from_two_abstract_integer(num,d)
      end

   from_abstract_integer_and_integer(n: ABSTRACT_INTEGER; d: INTEGER): NUMBER is
      require
	 n /= Void
      local
	 den: ABSTRACT_INTEGER
      do
	 if d >= Base then
	    !LARGE_POSITIVE_INTEGER!den.make_smaller(d)
	 elseif d <= -Base then
	    !LARGE_NEGATIVE_INTEGER!den.make_smaller(d)
	 else
	    !SMALL_INTEGER!den.make(d)
	 end
	 Result := from_two_abstract_integer(n,den)
      end

feature {NONE}

   decimal_in(buffer: STRING; numerator, denominator: NUMBER; negative: BOOLEAN
		  digits: INTEGER; all_digits: BOOLEAN) is
      local
	 n, div, remainder: NUMBER; counter: INTEGER
      do
	 n := numerator
	 if negative then
	    buffer.extend('-')
	 end
	 div := (n // denominator)
	 div.append_in(buffer)
	 remainder := n \\ denominator
	 if digits > 0 then
	    if all_digits or else not (remainder @= 0) then
	       buffer.extend('.')
	       from
		  counter := 1
	       until
		  (counter > digits) or else (remainder @= 0)
	       loop
		  n := remainder @* 10
		  ; (n // denominator).append_in(buffer)
		  remainder := n \\ denominator
		  counter := counter + 1
	       end
	       if all_digits then
		  from
		  until
		     counter > digits
		  loop
		     buffer.extend('0')
		     counter := counter + 1
		  end
	       end
	    end
	 end
      end

end -- class ABSTRACT_FRACTION

