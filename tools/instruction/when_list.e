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
class WHEN_LIST

inherit GLOBALS

creation {E_INSPECT} make

creation {E_INSPECT, WHEN_LIST} from_when_list

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
               pretty_printer.put_character('%N')
               pretty_printer.indent
            end
         end
      end

   start_position: POSITION is
         -- The `start_position' of the first keyword "when".
      do
         Result := list.first.start_position
      end

feature {WHEN_LIST, E_WHEN}

   e_inspect: E_INSPECT
         -- Corresponding one when checked.

feature {E_INSPECT, WHEN_LIST}

   from_when_list(wl: like Current) is
      local
         i: INTEGER; e_when: E_WHEN
      do
	 from
	    list := wl.list.twin
	    i := list.lower
	 until
	    i > list.upper
	 loop
	    !!e_when.from_e_when(list.item(i))
	    list.put(e_when,i)
	    i := i + 1
	 end
      end

feature {E_INSPECT}

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

feature {E_INSPECT,WHEN_LIST,MANIFEST_STRING_INSPECTOR}

   includes_integer(v: INTEGER): BOOLEAN is
      local
         i: INTEGER
      do
         from
            i := list.lower
         until
            Result or else i > list.upper
         loop
            Result := list.item(i).includes_integer(v)
            i := i + 1
         end
      end

   includes_integer_between(l,u: INTEGER): BOOLEAN is
      local
         i: INTEGER
      do
         from
            i := list.lower
         until
            Result or else i > list.upper
         loop
            Result := list.item(i).includes_integer_between(l,u)
            i := i + 1
         end
      end

   largest_range_of_values: INTEGER is
      local
         i, range: INTEGER
      do
         from
            i := list.lower
         until
            i > list.upper
         loop
            range := list.item(i).largest_range_of_values
            if range > Result then
               Result := range
            end
            i := i + 1
         end
      end

   to_runnable_integer(ei: E_INSPECT): like Current is
      require
         ei /= Void
      local
         i: INTEGER; e_when: E_WHEN
      do
         if e_inspect = Void then
            e_inspect := ei
            from
               i := list.lower
            until
               i > list.upper or else nb_errors > 0
            loop
               e_when := list.item(i).to_runnable_integer(Current)
               if e_when = Void then
                  error(start_position,em1)
               else
                  list.put(e_when,i)
               end
               i := i + 1
            end
            Result := Current
         else
            !!Result.from_when_list(Current)
            Result := Result.to_runnable_integer(ei)
         end
      ensure
         Result.e_inspect = ei
      end

   to_runnable_character(ei: E_INSPECT): like Current is
      require
         ei /= Void
      local
         i: INTEGER; e_when: E_WHEN
      do
         if e_inspect = Void then
            e_inspect := ei
            from
               i := list.lower
            until
               i > list.upper or else nb_errors > 0
            loop
               e_when := list.item(i).to_runnable_character(Current)
               if e_when = Void then
                  error(start_position,em1)
               else
                  list.put(e_when,i)
               end
               i := i + 1
            end
            Result := Current
         else
            !!Result.from_when_list(Current)
            Result := Result.to_runnable_character(ei)
         end
      ensure
         Result.e_inspect = ei
      end

   to_runnable_string(ei: E_INSPECT): like Current is
      require
         ei /= Void
      local
         i: INTEGER; e_when: E_WHEN
      do
         if e_inspect = Void then
            e_inspect := ei
            from
               i := list.lower
            until
               i > list.upper or else nb_errors > 0
            loop
               e_when := list.item(i).to_runnable_string(Current)
               if e_when = Void then
                  error(start_position,em1)
               else
                  list.put(e_when,i)
               end
               i := i + 1
            end
            Result := Current
         else
            !!Result.from_when_list(Current)
            Result := Result.to_runnable_string(ei)
         end
      ensure
         Result.e_inspect = ei
      end

   compile_to_c(else_position: POSITION) is
      local
         i: INTEGER
         last_compound: COMPOUND
      do
	 from
	    i := list.lower
	 until
	    i = list.upper
	 loop
	    list.item(i).compile_to_c
	    i := i + 1
	    if i < list.upper then
	       cpp.put_string(fz_else_alone)
	    end
	 end
	 if i > list.lower then
	    cpp.put_string(fz_else_alone)
	 end
	 if else_position.is_unknown and then ace.boost then
	    cpp.put_character('{')
	    last_compound := list.item(i).compound
	    if last_compound /= Void then
	       last_compound.compile_to_c
	    end
	    cpp.put_character('}')
	 else
	    list.item(i).compile_to_c
	 end
      end

   compile_to_c_switch(else_position: POSITION) is
      local
         i: INTEGER
         last_compound: COMPOUND
      do
	 from
	    i := list.lower
	 until
	    i = list.upper
	 loop
            list.item(i).compile_to_c_switch
	    i := i + 1
	 end
	 if else_position.is_unknown and then ace.boost then
            cpp.put_string(once "default:;%N")
	    last_compound := list.item(i).compound
	    if last_compound /= Void then
	       last_compound.compile_to_c
	    end
	 else
            list.item(i).compile_to_c_switch
	 end
      end

   compile_to_jvm(else_position: POSITION) is
      local
         remainder, i: INTEGER
      do
	 from
	    remainder := list.count
	    i := list.lower
	 until
	    remainder = 0
	 loop
	    remainder := remainder - 1
	    list.item(i).compile_to_jvm(else_position,remainder)
	    i := i + 1
         end
      end

   compile_to_jvm_resolve_branch is
      local
         i: INTEGER
      do
	 from
	    i := list.upper
	 until
	    i < list.lower
	 loop
	    list.item(i).compile_to_jvm_resolve_branch
	    i := i - 1
         end
      end


   use_current: BOOLEAN is
      local
         i: INTEGER
      do
	 from
	    i := list.upper
	 until
	     Result or else i < list.lower
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
	    Result := True
	    i := list.upper
	 until
	    not Result or else i < list.lower
	 loop
	    Result := list.item(i).stupid_switch(run_time_set)
	    i := i - 1
	 end
      end

feature {E_INSPECT}

   simplify_2(cc: CHARACTER_CONSTANT; ic: INTEGER_CONSTANT) is
      local
	 i: INTEGER
      do
	 from
	    i := list.lower
	 until
	    e_inspect.when_list = Void
	       or else
	    i > list.upper
	 loop
	    list.item(i).simplify_2(cc, ic)
	    i := i + 1
	 end
      end
   
   add_last(ew: E_WHEN) is
      require
         ew /= Void
      do
         list.add_last(ew)
      end

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

feature {WHEN_LIST, MANIFEST_STRING_INSPECTOR}

   list: FAST_ARRAY[E_WHEN]

feature {WHEN_LIST_VISITOR}

   accept(visitor: WHEN_LIST_VISITOR) is
      do
         visitor.visit_when_list(Current)
      end

feature {E_WHEN}

   always_selected(compound: COMPOUND) is
      do
	 e_inspect.always_selected(compound)
      end

feature {NONE}

   make(first: E_WHEN) is
      require
	 first /= Void
      do
         !!list.with_capacity(4)
	 list.add_last(first)
      ensure
         list.first = first
      end

   fz_else_alone: STRING is " else "

   em1: STRING is "Bad when list."

end -- WHEN_LIST
