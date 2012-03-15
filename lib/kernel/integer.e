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
expanded class INTEGER
--
-- 32 bits signed integer.
--

inherit
   INTEGER_GENERAL
      redefine fit_integer_32, fit_integer, item
      end

feature

   fit_integer_32, fit_integer: BOOLEAN is true

   low_16: INTEGER_16 is
	 -- The 16 low bits of `Current' (i.e. the right-most part).
      external "SmartEiffel"
      end

   high_16: INTEGER_16 is
	 -- The 16 high bits of `Current' (i.e. the left-most part).
      do
	 Result := (item |>> 16).low_16
      end

feature -- For experts only:

   item: INTEGER

   set_item(value: like item) is
      do
	 item := value
      ensure
	 item = value
      end

end -- INTEGER
