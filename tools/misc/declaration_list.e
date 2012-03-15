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
deferred class DECLARATION_LIST
   --
   -- For a formal arguments list (FORMAL_ARG_LIST) or for a local
   -- variable list (LOCAL_VAR_LIST).
   --
   -- Exemple :
   --
   --   foo, bar : ZOO; x : INTEGER
   --

inherit
   GLOBALS
   VISITABLE

feature {DECLARATION_LIST_VISITOR}

   accept(visitor: DECLARATION_LIST_VISITOR) is
      deferred
      end

feature {DECLARATION_LIST}

   list: ARRAY[DECLARATION]
         -- Really written list including declaration groups.

   flat_list: ARRAY[like name]
         -- The same contents as `list' but flat.

feature {NONE}

   declaration_list_make(l: like list) is
         -- Common part of creation.
      require
         l.lower = 1
         not l.is_empty
      local
         il, actual_count: INTEGER
      do
         list := l
         from
            il := list.upper
         until
            il < list.lower
         loop
            actual_count := actual_count + list.item(il).count
            il := il - 1
         end
         from
            !!flat_list.make(1,actual_count)
            il := list.lower
         until
            il > list.upper
         loop
            list.item(il).append_in(Current)
            il := il + 1
         end
      ensure
         list = l
         flat_list /= Void
      end

feature

   start_position: POSITION is
      do
         Result := flat_list.first.start_position
      end

   pretty_print is
      require
         pretty_printer.indent_level >= 2
      deferred
      ensure
         pretty_printer.indent_level = old pretty_printer.indent_level
      end

   count: INTEGER is
      do
         Result := flat_list.count
      end

   rank_of(n: STRING): INTEGER is
         -- Result is greater than 0 when `n' is in the list.
      require
         string_aliaser.item(n) = n
      do
         from
            Result := count
         until
            Result = 0 or else n = name(Result).to_string
         loop
            Result := Result - 1
         end
      ensure
         0 <= Result
         Result <= count
      end

   name(i: INTEGER): LOCAL_ARGUMENT1 is
      require
         1 <= i
         i <= count
      deferred
      ensure
         Result /= Void
      end

   type(i: INTEGER): E_TYPE is
      require
         1 <= i
         i <= count
      do
         Result := name(i).result_type
      ensure
         Result /= Void
      end

feature {RUN_FEATURE}

   c_scoop_struct_in(buf: STRING) is
      local
         i, c: INTEGER
      do
         from
            i := 1
	    c := count
         until
            i > c
         loop
            name(i).c_scoop_struct_in(buf)
            i := i + 1
         end
      end

feature {DECLARATION}

   add_last(n: like name) is
      local
         i: INTEGER; n2: like name
      do
         from
            i := flat_list.lower
         until
            flat_list.item(i) = Void
         loop
            n2 := flat_list.item(i)
            if n2.to_string = n.to_string then
               error_handler.add_position(n.start_position)
               error_handler.add_position(n2.start_position)
               error_handler.append("Same name appears twice.")
	       error_handler.print_as_fatal_error
            end
            i := i + 1
         end
         flat_list.put(n,i)
         n.set_rank(i)
      end

feature {RUN_FEATURE}

   frozen jvm_stack_space: INTEGER is
         -- Number of needed words in the JVM stack.
      local
         i: INTEGER
      do
         from
            i := count
         until
            i = 0
         loop
            Result := Result + type(i).run_type.jvm_stack_space
            i := i - 1
         end
      end

feature {RUN_FEATURE}

   frozen jvm_offset_of(la: LOCAL_ARGUMENT): INTEGER is
      local
         i, rank: INTEGER
      do
         from
            rank := la.rank
            i := 1
         variant
            count - i
         until
            i = rank
         loop
            Result := Result + type(i).run_type.jvm_stack_space
            i := i + 1
         end
      end

feature

   frozen is_runnable(ct: E_TYPE): BOOLEAN is
      local
         i: INTEGER; n1, n2: like name; t: E_TYPE
      do
	 -- Try first to see if all type are statically determined:
         from
            Result := True
            i := count
         until
            not Result or else i = 0
         loop
            t := type(i)
            if t.is_run_type then
               if t.run_type /= t then
                  Result := False
	       elseif t.to_runnable(ct) /= t then
		  Result := False
               end
            else
               Result := False
            end
            i := i - 1
         end
         if Result then
	    -- Make it ready for use:
            from
               i := count
            until
               i = 0
            loop
               n1 := flat_list.item(i)
	       n2 := n1.to_runnable(ct)
               if n2 = Void then
                  error(n1.start_position, em1)
                  i := 0
               else
		  check n1 = n2 end
                  i := i - 1
               end
            end
            check_name_clash(ct)
         end
      end

feature {DECLARATION_LIST}

   frozen check_name_clash(ct: E_TYPE) is
      local
         i: INTEGER
      do
         from
            i := count
         until
            i = 0
         loop
            name(i).name_clash(ct)
            i := i - 1
         end
      end

   frozen dynamic_runnable(ct: E_TYPE) is
      local
         i: INTEGER; n1, n2: like name
      do
         flat_list := flat_list.twin
         from
            i := flat_list.upper
         until
            i < flat_list.lower
         loop
            n1 := flat_list.item(i)
            n2 := n1.to_runnable(ct)
            if n2 = Void then
               error(n1.start_position, em1)
            else
               flat_list.put(n2,i)
            end
            i := i - 1
         end
      end

feature {NONE}

   em1: STRING is "Bad declaration."

invariant

   count > 0

   count = flat_list.count

   list.count <= count

end -- DECLARATION_LIST

