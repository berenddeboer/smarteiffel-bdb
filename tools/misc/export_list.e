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
class EXPORT_LIST

inherit
   GLOBALS
   VISITABLE

creation make

feature

   start_position: POSITION
         -- Of keyword "export".

   clients_for(fn: FEATURE_NAME): CLIENT_LIST is
      local
         i: INTEGER; ei: EXPORT_ITEM
      do
         from
            i := items.upper
         until
            i = 0
         loop
            ei := items.item(i)
            if ei.affect(fn) then
               if Result = Void then
                  Result := ei.clients
               else
                  Result := Result.merge_with(ei.clients)
               end
            end
            i := i - 1
         end
      end

   pretty_print is
      local
         i: INTEGER
      do
         pretty_printer.set_indent_level(2)
         pretty_printer.indent
         pretty_printer.keyword(once "export")
         from
            i := 1
         until
            i > items.upper
         loop
            pretty_printer.set_indent_level(3)
            items.item(i).pretty_print
            i := i + 1
            if i <= items.upper then
               pretty_printer.put_character(';')
               pretty_printer.set_indent_level(3)
               pretty_printer.indent
            end
         end
      end

feature {EXPORT_LIST_VISITOR}

   accept(visitor: EXPORT_LIST_VISITOR) is
      do
         visitor.visit_export_list(Current)
      end

feature {NONE}

   items: ARRAY [EXPORT_ITEM]

   make(sp: like start_position; i: like items) is
      require
         not sp.is_unknown
         i.lower = 1
         not i.is_empty
      do
         start_position := sp
         items := i
         -- *** ADD some validity checking...
      ensure
         start_position = sp
         items = i
      end

invariant

   items.lower = 1

   not items.is_empty

end -- EXPORT_LIST

