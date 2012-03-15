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
class ITERATOR_ON_TWO_WAY_LINKED_LIST[E]
   -- Please do not use this class directly. Look at `ITERATOR'.

inherit ITERATOR[E]

creation make

feature {NONE}

   linked_list: TWO_WAY_LINKED_LIST[E]
	 -- The one to be traversed.

   item_link: LINK2[E]
	 --  Memorize the current position.

feature

   make(twll: TWO_WAY_LINKED_LIST[E]) is
      require
	 twll /= Void
      do
	 linked_list := twll
	 item_link := linked_list.first_link
      ensure
	 linked_list = twll
      end

   start is
      do
	 item_link := linked_list.first_link
      end

   is_off: BOOLEAN is
      do
	 Result := item_link = Void
      end

   item: E is
      do
	 Result := item_link.item
      end

   next is
      do
	 item_link := item_link.next
      end

end
