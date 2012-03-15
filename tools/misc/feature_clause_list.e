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
class FEATURE_CLAUSE_LIST

inherit GLOBALS; VISITABLE

creation {BASE_CLASS} make

feature

   pretty_print is
      local
         i: INTEGER
      do
         from
            i := list.lower
         until
            i > list.upper
         loop
            pretty_printer.set_indent_level(0)
            pretty_printer.indent
            if not pretty_printer.zen_mode then
               pretty_printer.skip_one_line
            end
            list.item(i).pretty_print
            i := i + 1
         end
      ensure
         pretty_printer.indent_level = 0
      end

feature {CLASS_CHECKER}

   for_short(bcn: CLASS_NAME; sort: BOOLEAN; short_list: SHORT_LIST
	     rc: RUN_CLASS; client: CLASS_NAME) is
      local
         i: INTEGER; fc: FEATURE_CLAUSE
      do
         from
            i := list.lower
         until
            i > list.upper
         loop
            fc := list.item(i)
            fc.for_short(bcn, sort, short_list, rc, client)
            i := i + 1
         end
      end

feature {BASE_CLASS}

   get_started(fd: DICTIONARY[E_FEATURE,FEATURE_NAME]) is
      local
         i: INTEGER
      do
         from
            i := list.upper
         until
            i < list.lower
         loop
            list.item(i).add_into(fd)
            i := i - 1
         end
      end

   add_last(fc: FEATURE_CLAUSE) is
      require
         fc /= Void
      do
         list.add_last(fc)
      end

feature {FEATURE_CLAUSE_LIST_VISITOR}

   accept(visitor: FEATURE_CLAUSE_LIST_VISITOR) is
      do
         visitor.visit_feature_clause_list(Current)
      end

feature {FEATURE_CLAUSE_LIST_VISITOR}

   list: FIXED_ARRAY[FEATURE_CLAUSE]

feature {NONE}

   make(first: FEATURE_CLAUSE) is
      require
         first /= Void
      do
         !!list.with_capacity(12)
	 list.add_last(first)
      ensure
         list.first = first
      end

invariant

   not list.is_empty

end -- FEATURE_CLAUSE_LIST

