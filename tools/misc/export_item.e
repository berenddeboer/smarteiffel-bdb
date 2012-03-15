-- This file is part of SmartEiffel The GNU Eiffel Compiler Tools and Libraries
--
-- SmartEiffel is  free software;  you can redistribute it and/or  modify it
-- under  the terms of the  GNU General Public License, as published by  the
-- Free Software Foundation; either version 2, or (at your option) any later
-- version.
-- SmartEiffel is distributed in the hope that it will be useful but WITHOUT 
-- ANY WARRANTY;  without  even the implied warranty  of MERCHANTABILITY  or
-- FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
-- more details.  You should have received a copy of  the GNU General Public
-- License along with SmartEiffel;  see the file COPYING.  If not,  write to
-- the Free Software Foundation,  Inc., 59 Temple Place - Suite 330,  Boston, 
-- MA 02111-1307, USA.
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
class EXPORT_ITEM
   --
   -- To store one item of the option "inherit ... export ... end".
   --

inherit
   GLOBALS
   VISITABLE

creation make_all, make

feature {EXPORT_ITEM_VISITOR}

   accept(visitor: EXPORT_ITEM_VISITOR) is
      do
         visitor.visit_export_item(Current)
      end

feature

   clients: CLIENT_LIST

   list: FEATURE_NAME_LIST

feature {NONE}

   make_all(c: like clients) is
      require
         c /= Void
      do
         clients := c
         list := Void
      end

   make(c: like clients; l: like list) is
      require
         c /= Void
      do
         clients := c
         list := l
      ensure
         clients = c
         list = l
      end

feature

   for_all: BOOLEAN is
         -- True when "all" primitives affected
      do
         Result := list = Void
      end

   affect(fn: FEATURE_NAME): BOOLEAN is
      do
         if for_all then
            Result := True
         else
            Result := list.has(fn)
         end
      end

   pretty_print is
      do
         clients.pretty_print
         if for_all then
            pretty_printer.keyword(once "all")
         else
            list.pretty_print
         end
      end

invariant

   clients /= Void

end -- EXPORT_ITEM

