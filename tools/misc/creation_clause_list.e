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
class CREATION_CLAUSE_LIST

inherit
   GLOBALS
   VISITABLE

creation {BASE_CLASS} make

feature

   start_position: POSITION is
      do
         Result := list.first.start_position
      end

   pretty_print is
      local
         i: INTEGER
      do
         from
            i := list.lower
         until
            i > list.upper
         loop
            list.item(i).pretty_print
            if not pretty_printer.zen_mode then
               pretty_printer.set_indent_level(0)
               pretty_printer.skip_one_line
            end
            i := i + 1
         end
      end

   short(client: CLASS_NAME): BOOLEAN is
         -- True when at least one creation list is printed for the given `client'.
      local
         i: INTEGER
      do
         from
            i := list.lower
         until
            i > list.upper
         loop
            Result := list.item(i).short(Result,client) or else Result
            i := i + 1
         end
      end

   get_clause(fn: FEATURE_NAME): CREATION_CLAUSE is
      local
         i: INTEGER
      do
         from
            i := list.lower
         until
            i > list.upper or else list.item(i).has(fn)
         loop
            i := i + 1
         end
         if i <= list.upper then
            Result := list.item(i)
         end
      end

feature {BASE_CLASS}

   default_root: STRING is
	 -- Return the default creation procedure name to be used as the root
	 -- procedure (the execution entry point of the system).
      local
         i: INTEGER
      do
         from
            i := list.upper
         until
            Result /= Void or else i < list.lower
         loop
            Result := list.item(i).default_root
	    if Result /= as_make then
	       Result := Void
	    end
            i := i - 1
         end
         from
            i := list.lower
         until
            Result /= Void or else i > list.upper
         loop
            Result := list.item(i).default_root
            i := i + 1
         end
      end

   root_creation_search(a_name: STRING): FEATURE_NAME is
      local
         i: INTEGER
      do
         from
            i := list.upper
         until
            i < list.lower or else Result /= Void
         loop
            Result := list.item(i).root_creation_search(a_name)
            i := i - 1
         end
      end

   add_last(cc: CREATION_CLAUSE) is
      require
         cc /= Void
      do
         list.add_last(cc)
      end

   check_expanded_with(t: E_TYPE) is
      require
         t.is_expanded
      local
	 lower: INTEGER
      do
         if list.count > 1 then
            error_handler.add_type(t,fz_cbe)
	    lower := list.lower
            error_handler.add_position(list.item(lower).start_position)
	    lower := lower + 1
            error_handler.add_position(list.item(lower).start_position)
            fatal_error_vtec_2
         end
         list.first.check_expanded_with(t)
      end

   a_default_create(type: E_TYPE): RUN_FEATURE_3 is
      local
	 i: INTEGER
      do
	 from
	    i := list.upper
	 until
	    Result /= Void or else i < list.lower
	 loop
	    Result := list.item(i).a_default_create(type)
	    i := i - 1
	 end
      end

feature {CREATION_CLAUSE_LIST_VISITOR}

   accept(visitor: CREATION_CLAUSE_LIST_VISITOR) is
      do
         visitor.visit_creation_clause_list(Current)
      end

   list: FIXED_ARRAY[CREATION_CLAUSE]

feature {NONE}

   make(first: CREATION_CLAUSE) is
      require
         first /= Void
      do
         !!list.with_capacity(4)
	 list.add_last(first)
      ensure
         list.first = first
      end

invariant

   not list.is_empty

end -- CREATION_CLAUSE_LIST

