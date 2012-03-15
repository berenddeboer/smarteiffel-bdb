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
class ITERATOR_ON_UNICODE_STRING
   -- Please do not use this class directly. Look at `ITERATOR'.

inherit ITERATOR[INTEGER];

create make

feature {NONE}

   string: UNICODE_STRING;
	 -- The one to be traversed.

   item_index: INTEGER;
	 --  Memorize the current position.
feature

   make(s: UNICODE_STRING) is
      require
	 s /= Void
      do
	 string := s;
	 item_index := 1;
      ensure
	 string = s
      end;

   start is
      do
	 item_index := 1;
      end;

   is_off: BOOLEAN is
      do
	 Result :=  item_index > string.count;
      end;

   item: INTEGER is
      do
	 Result := string.item(item_index);
      end;

   next is
      do
	 item_index := item_index + 1;
      end;

end
