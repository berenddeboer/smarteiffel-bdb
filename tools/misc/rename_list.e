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
class RENAME_LIST

inherit
   GLOBALS
   VISITABLE

creation make

feature {RENAME_LIST_VISITOR}

   accept(visitor: RENAME_LIST_VISITOR) is
      do
         visitor.visit_rename_list(Current)
      end

feature

   pretty_print is
      local
         icount, i: INTEGER
      do
         pretty_printer.set_indent_level(2)
         pretty_printer.indent
         pretty_printer.keyword(once "rename")
         from
            i := list.lower
         until
            i > list.upper
         loop
            list.item(i).pretty_print
            i := i + 1
            icount := icount + 1
            if i <= list.upper then
               pretty_printer.put_string(once ", ")
               if icount > 3 then
                  icount := 0
                  pretty_printer.set_indent_level(3)
                  pretty_printer.indent
               end
            end
         end
      end

feature {PARENT}

   name_in_child(fn: FEATURE_NAME): FEATURE_NAME is
         -- Gives Void or the name of `fn' after renaming.
      require
         fn /= Void
      local
         i: INTEGER
         rp: RENAME_PAIR
         fn_to_key: STRING
         no_longer_exists: BOOLEAN
      do
         fn_to_key := fn.to_key
         Result := fn
         from
            i := list.upper
         until
            i < list.lower
         loop
            rp := list.item(i)
            if rp.old_name.to_key = fn_to_key then
               Result := rp.new_name
            elseif rp.new_name.to_key = fn_to_key then
               no_longer_exists := True
            end
            i := i - 1
         end
         if no_longer_exists and then Result = fn then
            Result := Void
         end
      end

   name_in_parent(fn: FEATURE_NAME): FEATURE_NAME is
         -- Gives Void or the name of `fn' before renaming.
      require
         fn /= Void
      local
         i: INTEGER; rp: RENAME_PAIR; fn_to_key: STRING
         no_longer_exists: BOOLEAN
      do
         fn_to_key := fn.to_key
         Result := fn
         from
            i := list.upper
         until
            i < list.lower
         loop
            rp := list.item(i)
            if rp.new_name.to_key = fn_to_key then
               Result := rp.old_name
	       i := list.lower - 1
            elseif rp.old_name.to_key = fn_to_key then
               no_longer_exists := True
            end
            i := i - 1
         end
         if no_longer_exists and then Result = fn then
            Result := Void
         end
      end

   new_name_for_step2(fn: FEATURE_NAME): FEATURE_NAME is
      require
         fn /= Void
      local
         i: INTEGER
         rp: RENAME_PAIR
         fn_to_key: STRING
      do
         fn_to_key := fn.to_key
         from
            i := list.upper
         until
            i < list.lower
         loop
            rp := list.item(i)
            if rp.old_name.to_key = fn_to_key then
               if Result = Void then
                  Result := rp.new_name
               end
            end
            i := i - 1
         end
      end

   add_last(rp: RENAME_PAIR) is
      require
         rp /= Void
      do
         list.add_last(rp)
      end

   get_started(pbc: BASE_CLASS) is
      require
         ace.all_check
      local
         i, j: INTEGER
         rp1, rp2: RENAME_PAIR
      do
         from
            i := list.upper
         until
            i < list.lower
         loop
            rp1 := list.item(i)
            if not pbc.has(rp1.old_name) then
               error_handler.add_position(rp1.old_name.start_position)
               error_handler.append(
                  "Cannot rename inexistant feature (VHRC.1).")
	       error_handler.print_as_fatal_error
            end
            i := i - 1
            from
               j := i
            until
               j < list.lower
            loop
               rp2 := list.item(j)
               if rp2.old_name.to_key = rp1.old_name.to_key then
                  error_handler.add_position(rp1.old_name.start_position)
                  error_handler.add_position(rp2.old_name.start_position)
                  error_handler.append(
                     "Multiple rename for the same feature (VHRC.2).")
		  error_handler.print_as_fatal_error
               end
               j := j - 1
            end
         end
      end

feature {NONE}

   list: FAST_ARRAY[RENAME_PAIR]

   make(first: RENAME_PAIR) is
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

end -- RENAME_LIST

