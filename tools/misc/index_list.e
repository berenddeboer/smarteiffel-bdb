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
class INDEX_LIST
   --
   -- For the indexing clause in the heading part of a class.
   --

inherit
   GLOBALS
   VISITABLE

creation {BASE_CLASS} make

feature {INDEX_LIST_VISITOR}

   accept(visitor: INDEX_LIST_VISITOR) is
      do
         visitor.visit_index_list(Current)
      end

feature {NONE}

   list: ARRAY[INDEX_CLAUSE]

   make(first: INDEX_CLAUSE) is
      require
         first /= Void
      do
         !!list.with_capacity(4,1)
	 list.add_last(first)
      ensure
         list.first = first
      end

feature

   pretty_print is
      require
         pretty_printer.indent_level = 0
      local
         i: INTEGER
      do
         pretty_printer.put_string(once "indexing")
         pretty_printer.indent_level_increment
         pretty_printer.indent
         from
            i := 1
         until
            i > list.upper
         loop
            list.item(i).pretty_print
            i := i + 1
            if i <= list.upper then
               pretty_printer.put_string(fz_00)
               pretty_printer.indent
            end
         end
         pretty_printer.put_string(once ";%N%N")
         pretty_printer.indent_level_decrement
         pretty_printer.indent
      ensure
         pretty_printer.indent_level = old pretty_printer.indent_level
      end

feature {BASE_CLASS}

   add_last(ic: INDEX_CLAUSE) is
      require
         ic /= Void
      do
         list.add_last(ic)
      end

invariant

   list.lower = 1

   not list.is_empty

end -- INDEX_LIST

