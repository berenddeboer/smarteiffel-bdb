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
class RUN_REQUIRE
   --
   -- A RUN_REQUIRE is composed with all inherited E_REQUIRE.
   --

inherit GLOBALS

creation {ASSERTION_COLLECTOR} make

feature

   side_effect_free: BOOLEAN is
      do
	 -- *** TO DO ***
      end
   
   short is
      local
         i: INTEGER
      do
         from
            list.item(1).short(once "hook401",once "      require%N")
            i := 2
         until
            i > list.upper
         loop
            list.item(i).short(once "hook402",once "      require else %N")
            i := i + 1
         end
         short_print.hook(once "hook403")
      end

   use_current: BOOLEAN is
      local
         i: INTEGER
      do
         from
            i := 1
         until
            Result or else i > list.upper
         loop
            Result := list.item(i).use_current
            i := i + 1
         end
      end

   afd_check is
      local
         i: INTEGER
      do
         from
            i := list.upper
         until
            i = 0
         loop
            list.item(i).afd_check
            i := i - 1
         end
      end

   compile_to_c is
      local
         i: INTEGER
      do
         if list.upper = 1 then
            cpp.put_string(once "se_require_uppermost_flag=1;%N")
            list.first.compile_to_c
         else
            cpp.put_string(once "se_require_uppermost_flag=0;%N%
                           %se_require_last_result=1;%N")
            list.first.compile_to_c
            from
               i := 2
            until
               i > list.upper
            loop
               if i = list.upper then
                  cpp.put_string(once "se_require_uppermost_flag=1;%N")
               end
               cpp.put_string(once "if(!se_require_last_result){%N%
                              %se_require_last_result=1;%N")
               list.item(i).compile_to_c
               cpp.put_string(fz_12)
               i := i + 1
            end
         end
      end

   compile_to_jvm is
      local
         i: INTEGER
         ca: like code_attribute
      do
	 ca := code_attribute
	 if list.upper = 1 then
	    list.first.compile_to_jvm(True)
	    ca.opcode_pop
	 else
	    sucess.clear
	    from
	       i := 1
	    until
	       i > (list.upper - 1)
	    loop
	       list.item(i).compile_to_jvm(False)
	       sucess.add_last(ca.opcode_ifne)
	       i := i + 1
	    end
	    list.item(i).compile_to_jvm(True)
	    ca.opcode_pop
	    ca.resolve_with(sucess)
         end
      end

feature {RUN_FEATURE}

   verify_scoop(allowed: FORMAL_ARG_LIST) is
      local
         i: INTEGER
      do
         list.first.verify_scoop(allowed)
         from
            i := 2
         until
            i > list.upper
         loop
            list.item(i).verify_scoop(allowed)
            i := i + 1
         end
      end

   c_scoop_while is
         -- Compile the first part of the "do...while" loop (just before 
         -- trying to lock the arguments' processors
      do
         cpp.put_string(once "{int se_guard;%Ndo {%Nse_guard=1;%N")
      end

   c_scoop_if_not_guard is
         -- Compile and test the guards
      local
         i: INTEGER
      do
         list.first.c_scoop
         from
            i := 2
         until
            i > list.upper
         loop
            list.item(i).c_scoop
            cpp.put_string(fz_12)
            i := i + 1
         end
         cpp.put_string(once "if (!se_guard) {%N")
      end

   c_scoop_guard is
         -- Close the guard section (last part of the "do...while" loop)
      do
         cpp.put_string(once "}%N} while(!se_guard);%N}%N")
      end

feature {ASSERTION_COLLECTOR}

   add(r: E_REQUIRE) is
      require
         r /= Void
      local
         i: INTEGER
         r2: E_REQUIRE
         bc, bc2: BASE_CLASS
      do
         list.add_last(r)
         from
            bc := r.start_position.base_class
            i := list.upper
         until
            i = 1
         loop
            r2 := list.item(i - 1)
            bc2 := r2.start_position.base_class
            if bc.is_subclass_of(bc2) then
               list.swap(i,i-1)
               i := i - 1
            else
               i := 1
            end
         end
      end

feature {ONCE_ROUTINE_POOL}

   clear_run_feature is
      local
         i: INTEGER
      do
         from
            i := list.upper
         until
            i = 0
         loop
            list.item(i).clear_run_feature
            i := i - 1
         end
      end

feature {RUN_REQUIRE_VISITOR}

   accept(visitor: RUN_REQUIRE_VISITOR) is
      do
         visitor.visit_run_require(Current)
      end

feature {NONE}

   list: ARRAY[E_REQUIRE]
         -- From bottom to the top of the inheritance graph.
         -- Order is important because one at least must be true
         -- following bottom up order.

   make(first: E_REQUIRE) is
      do
         !!list.with_capacity(4,1)
         list.add_last(first)
      end

   sucess: FAST_ARRAY[INTEGER] is
         -- To reach the sucessful code.
      once
         !!Result.with_capacity(4)
      end

invariant

   list.lower = 1

   not list.is_empty

end -- RUN_REQUIRE

