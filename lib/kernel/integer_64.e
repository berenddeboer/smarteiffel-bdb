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
expanded class INTEGER_64
--
-- 64 bits signed integer.
--

inherit INTEGER_GENERAL redefine item, hash_code end

feature

   low_32: INTEGER_32 is
	 -- The 32 low bits of `Current' (i.e. the right-most part).
      external "SmartEiffel"
      end

   high_32: INTEGER_32 is
	 -- The 32 high bits of `Current' (i.e. the left-most part).
      do
	 Result := (item |>> 32).low_32
      end

   hash_code: INTEGER is
      do
	 Result := item.low_32 & 0x7FFFFFFF
      end

feature -- For experts only:

   item: INTEGER_64

   set_item(value: like item) is
      do
	 item := value
      ensure
	 item = value
      end

end -- INTEGER_64
