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
class IFTHENLIST

inherit IF_GLOBALS

creation make

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
            list.item(i).pretty_print
            i := i + 1
            if i <= list.upper then
               pretty_printer.indent
               pretty_printer.keyword(fz_elseif)
            end
         end
      end

   afd_check is
      local
         i: INTEGER
      do
         from
            i := list.upper
         until
            i < list.lower
         loop
            list.item(i).afd_check
            i := i - 1
         end
      end

   safety_check is
      local
         i: INTEGER
      do
         from
            i := list.upper
         until
            i < list.lower
         loop
            list.item(i).safety_check
            i := i - 1
         end
      end

   collect_c_tmp is
      local
         i: INTEGER
      do
         from
            i := list.upper
         until
            i < list.lower
         loop
            list.item(i).collect_c_tmp
            i := i - 1
         end
      end

   compile_to_c: INTEGER is
         -- state 0: no printing done.
         -- state 1: already print `Always_here'.
         -- state 2: end of list or previous `Always_true'.
      local
         state, previous, i: INTEGER
      do
         from
            i := list.lower
         until
            state = 2
         loop
            inspect
               state
            when 0 then
               if i > list.upper then
                  state := 2
                  Result := previous
               else
                  previous := list.item(i).compile_to_c(false)
                  inspect
                     previous
                  when Always_here then
                     state := 1
                  when Always_false then
                  when Always_true then
                     Result := Always_true
                     state := 2
                  end
               end
            else -- 1
               if i > list.upper then
                  state := 2
                  inspect
                     previous
                  when Always_true then
                     Result := Always_true
                  else
                     Result := Always_here
                  end
               else
                  previous := list.item(i).compile_to_c(true)
                  inspect
                     previous
                  when Always_here then
                  when Always_false then
                  when Always_true then
                     state := 2
                     Result := Always_true
                  end
               end
            end
            i := i + 1
         end
      ensure
         (<<Always_true,Always_false,Always_here>>).fast_has(Result)
      end

   compile_to_jvm: INTEGER is
      local
         i: INTEGER
      do
         from
            Result := list.first.compile_to_jvm
            i := list.lower + 1
         until
            Result = Always_true or else i > list.upper
         loop
            inspect
               list.item(i).compile_to_jvm
            when Always_true then
               Result := Always_true
            when Always_false then
               if Result = Always_false then
               else
                  Result := Always_here
               end
            else -- Always_here :
               Result := Always_here
            end
            i := i + 1
         end
      ensure
         (<<Always_true,Always_false,Always_here>>).fast_has(Result)
      end

   use_current: BOOLEAN is
      local
         i: INTEGER
      do
         from
            i := list.upper
         until
            i < list.lower or else Result
         loop
            Result := list.item(i).use_current
            i := i - 1
         end
      end

   stupid_switch(run_time_set: RUN_TIME_SET): BOOLEAN is
      local
         i: INTEGER
      do
         from
            Result := true
            i := list.upper
         until
            not Result or else i < list.lower
         loop
            Result := list.item(i).stupid_switch(run_time_set)
            i := i - 1
         end
      end

   count: INTEGER is
      do
         Result := list.count
      end

   to_runnable(ct: E_TYPE): like Current is
      require
         ct /= Void
      local
         i: INTEGER
      do
         if current_type /= Void then
	    from
	       !!Result.make(list.first)
	       i := list.lower + 1
	    until
	       i > list.upper
	    loop
	       Result.add_last(list.item(i))
	       i := i + 1
	    end
            Result := Result.to_runnable(ct)
         else
            current_type := ct
            from
               i := list.lower
            until
               i > list.upper or else nb_errors > 0
            loop
               list.put(list.item(i).to_runnable(ct),i)
               debug
                  if nb_errors = 0 then
                     check
                        list.item(i) /= Void
                     end
                  end
               end
               i := i + 1
            end
            Result := Current
         end
      end

feature {IFTHENELSE}

   verify_scoop(allowed: FORMAL_ARG_LIST) is
      local
         i: INTEGER
      do
         from
            i := list.upper
         until
            i < list.lower
         loop
            list.item(i).verify_scoop(allowed)
            i := i - 1
         end
      end

feature {IFTHENELSE, IFTHENLIST}

   add_last(it: IFTHEN) is
      require
         it /= Void
      do
         list.add_last(it)
      ensure
         count = old count + 1
      end

feature {IFTHENELSE}

   simplify_2(container: IFTHENELSE) is
      require
	 container /= Void
      local
         i: INTEGER
      do
         from
            i := list.lower
         until
            i > list.upper
         loop
            inspect
	       list.item(i).simplify_2
	    when Always_true then
	       -- Removing the remainder:
	       from
	       until
		  i = list.upper
	       loop
		  list.remove_last
	       end
	       -- Overwrite the else compound of the if-then-else:
	       container.set_else_compound(list.item(i).then_compound)
	       list.remove_last
	       check i > list.upper end
	    when Always_false then
	       list.remove(i)
	    when Always_here then
	       i := i + 1
	    end
         end
      end
   
   compile_to_jvm_resolve_branch is
      local
         i, static: INTEGER
      do
         from
            i := list.lower
            static := Always_here
         until
            static = Always_true or else i > list.upper
         loop
            static := list.item(i).compile_to_jvm_resolve_branch
            i := i + 1
         end
      end

feature {IFTHENLIST_VISITOR}

   accept(visitor: IFTHENLIST_VISITOR) is
      do
         visitor.visit_ifthenlist(Current)
      end

feature {NONE}

   list: FIXED_ARRAY[IFTHEN]

   current_type: E_TYPE

   make(first: IFTHEN) is
      require
         first /= Void
      do
         !!list.with_capacity(4)
	 list.add_last(first)
      ensure
         list.first = first
      end

invariant

   list /= Void

end -- IFTHENLIST
