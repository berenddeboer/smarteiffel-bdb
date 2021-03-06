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
expanded class INTEGER_16
--
-- 16 bits signed integer.
--

inherit
   INTEGER_GENERAL
      redefine
          fit_integer_16, fit_integer_32, fit_integer, item, to_integer,
          to_integer_32, to_number
      end

feature

   fit_integer_16, fit_integer_32, fit_integer: BOOLEAN is True

   low_8: INTEGER_8 is
	 -- The 8 low bits of `Current' (i.e. the right-most part).
      external "SmartEiffel"
      end

   high_8: INTEGER_8 is
	 -- The 8 high bits of `Current' (i.e. the left-most part).
      do
	 Result := (item |>> 8).low_8
      end

feature

   to_integer_32, to_integer: INTEGER_32 is
      external "SmartEiffel"
      end

   to_number: NUMBER is
      local
         number_tools: NUMBER_TOOLS
      do
         Result := number_tools.from_integer(Current)
      ensure
         Result @= Current
      end

feature -- For experts only:

   item: INTEGER_16

   set_item(value: like item) is
      do
	 item := value
      ensure
	 item = value
      end

end -- INTEGER_16
