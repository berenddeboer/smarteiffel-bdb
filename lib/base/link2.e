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
class LINK2[E]
   --
   -- To implement TWO_WAY_LINKED_LIST[E].
   --

creation {TWO_WAY_LINKED_LIST} make

feature {ITERATOR_ON_TWO_WAY_LINKED_LIST,TWO_WAY_LINKED_LIST,LINK2}

   item: E

   previous, next: like Current

feature {TWO_WAY_LINKED_LIST}

   make(i: like item; p: like previous; n: like next) is
      do
         item := i
         previous := p
         next := n
      ensure
         item = i
         previous = p
         next = n
      end

feature {TWO_WAY_LINKED_LIST,LINK2}

   set_item(i: like item) is
      do
         item := i
      ensure
         item = i
      end

   set_next(n: like next) is
      do
         next := n
      ensure
         next = n
      end

   set_all_with(v: like item) is
      local
         lnk: like Current
      do
         from
            lnk := Current
         until
            lnk = Void
         loop
            lnk.set_item(v)
            lnk := lnk.next
         end
      end

   set_previous(p: like previous) is
      do
         previous := p
      ensure
         previous = p
      end

end -- LINK2[E]
