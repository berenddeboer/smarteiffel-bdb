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
class INDEX_CLAUSE

inherit
   GLOBALS
   VISITABLE

creation with_tag, without_tag

feature {INDEX_CLAUSE_VISITOR}

   accept(visitor: INDEX_CLAUSE_VISITOR) is
      do
         visitor.visit_index_clause(Current)
      end

feature {NONE}

   tag: STRING

   list: FIXED_ARRAY[EXPRESSION]

   with_tag(i: like tag) is
      require
         i /= Void
      do
         tag := i
      ensure
         tag = i
      end

   without_tag(index_value: EXPRESSION) is
      do
         add_last(index_value)
      end

feature

   pretty_print is
      local
         i: INTEGER
         tag_column: INTEGER
      do
         if tag /= Void then
            pretty_printer.put_string(tag)
            pretty_printer.put_string(once ": ")
            tag_column := pretty_printer.column
         end
         if list /= Void then
            pretty_printer.indent_level_increment
            from
               i := list.lower
            until
               i > list.upper
            loop
               list.item(i).pretty_print
               i := i + 1
               if i <= list.upper then
                  pretty_printer.put_string(once ",%N")
                  if tag_column > 0 then
                     from
                     until
                        pretty_printer.column >= tag_column
                     loop
                        pretty_printer.put_character(' ')
                     end
                  else
                     pretty_printer.indent
                  end
               end
            end
            pretty_printer.indent_level_decrement
         end
      end

feature {EIFFEL_PARSER}

   add_last(index_value: EXPRESSION) is
      require
         index_value /= Void
      do
         if list = Void then
            !!list.with_capacity(4)
         end
         list.add_last(index_value)
      end

invariant

   tag /= Void or else list /= Void

end -- INDEX_CLAUSE

