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
--                           - University of Nancy 1 - FRANCE
-- Copyright(C) 2003:      INRIA - LORIA (INRIA Lorraine) - I.U.T. Charlemagne
--                           - University of Nancy 2 - FRANCE
--
--                 Dominique COLNET, Suzanne COLLIN, Olivier ZENDRA,
--                           Philippe RIBET, Cyril ADRIAN
--
-- http://SmartEiffel.loria.fr - SmartEiffel@loria.fr
--
class ASSIGNMENT_ATTEMPT
   --
   -- For instructions like :
   --                          foo ?= bar
   --                          foo ?= bar + 1
   --
   
inherit INSTRUCTION
   
creation make

feature

   left_side: EXPRESSION

   right_side: EXPRESSION

   side_effect_free: BOOLEAN is False
      
   end_mark_comment: BOOLEAN is False

   use_current: BOOLEAN is
      do
         if left_side.use_current then
            Result := True
         else
            Result := right_side.use_current
         end
      end

   stupid_switch(run_time_set: RUN_TIME_SET): BOOLEAN is
      do
         if smart_eiffel.stupid_switch(left_side.result_type,
                                       run_time_set) 
          then
            if smart_eiffel.stupid_switch(right_side.result_type,
                                          run_time_set)
             then
               if left_side.stupid_switch(run_time_set) then
                  if right_side.stupid_switch(run_time_set) then
                     Result := True
                  end
               end
            end
         end
      end

   afd_check is
      do
         right_side.afd_check
      end

   safety_check is
      do
         right_side.safety_check
      end

   simplify_2(container: COMPOUND; index: INTEGER) is
      do
         right_side := right_side.simplify_2
      end
   
   collect_c_tmp is
      do
         right_side.collect_c_tmp
      end

   compile_to_c is
      local
         run_time_set, run_time_set2: RUN_TIME_SET; i: INTEGER
      do
         if ace.no_check then
            cpp.put_trace_or_sedb_instruction(start_position)
         end
         cpp.put_string(once "/*AA*/")
         if right_type.run_type.is_expanded then
            error_handler.add_position(start_position)
            fatal_error("Right-hand side expanded Not Yet Implemented.")
         end
         run_time_set := left_type.run_class.run_time_set
         if run_time_set.count = 0 then
            if not right_side.side_effect_free then
               right_side.compile_to_c
               cpp.put_string(fz_00)
            end
            left_side.compile_to_c
            cpp.put_string(fz_30)
         elseif right_side.is_current then
            if run_time_set.has(right_side.result_type.run_class) then
               left_side.compile_to_c
               cpp.put_string(once "=((void*)")
               right_side.compile_to_c
               cpp.put_string(fz_14)
            else
               left_side.compile_to_c
               cpp.put_string(fz_30)
            end
         elseif run_time_set.count = 1 
            and then not run_time_set.first.is_tagged 
          then
            check
               ace.boost 
            end
            left_side.compile_to_c
            cpp.put_character('=')
            run_time_set2 := right_type.run_class.run_time_set
            if run_time_set2.count = 1 
               and then 
               run_time_set2.first = run_time_set.first
             then
               -- Only one and the good one.
            else
               cpp.put_string(fz_null)
               cpp.put_character(';')
            end
            right_side.compile_to_c
            cpp.put_string(fz_00)
         else -- General translation scheme:
            left_side.compile_to_c
            cpp.put_character('=')
            if right_side.is_current then
               cpp.put_string(fz_cast_t0_star)
            end
            right_side.compile_to_c
            cpp.put_string(once ";%Nif(NULL!=(")
            left_side.compile_to_c
            cpp.put_string(once ")){%N")
            if smart_eiffel.scoop
               and then not left_side.result_type.is_separate
               and then right_side.result_type.is_separate
             then
               cpp.put_string(once "se_subsystem_t* self = se_current_subsystem_thread();%N")
               cpp.put_string(once "if (get_subsystem(")
               left_side.compile_to_c
               cpp.put_string(once ", NULL) == self) {%N")
               left_side.compile_to_c
               cpp.put_string(once "=((sT0*)(")
               left_side.compile_to_c
               cpp.put_string(once "))->ref;%N}%N")
            end
            cpp.put_string(once "switch(((T0*)")
            left_side.compile_to_c
            cpp.put_string(once ")->")
            cpp.put_string(once "id){%N")
            from
               i := 1
            until
               i > run_time_set.count
            loop
               check run_time_set.item(i).is_tagged end
               cpp.put_string(once "case ")
               cpp.put_integer(run_time_set.item(i).id)
               cpp.put_character(':')
               i := i + 1
            end
            cpp.put_string(once "%Nbreak;%Ndefault:%N")
            left_side.compile_to_c
            cpp.put_string(once "=NULL;%N}%N}")
         end
      end

   compile_to_jvm is
      local
         run_time_set: RUN_TIME_SET; rc: RUN_CLASS; point1, i: INTEGER
         ca: like code_attribute; branch_index: INTEGER
      do
         ca := code_attribute
         if right_type.run_type.is_expanded then
            error_handler.add_position(start_position)
            fatal_error("Right-hand side expanded Not Yet Implemented.")
         end
         run_time_set := left_type.run_class.run_time_set
         if run_time_set.count = 0 then
            right_side.compile_to_jvm
            ca.opcode_pop
            ca.opcode_aconst_null
            left_side.jvm_assign
         else
            right_side.compile_to_jvm
            ca.opcode_dup
            point1 := ca.opcode_ifnull
            from
               branch_index := ca.get_branch_array_index
               i := run_time_set.count
            until
               i = 0
            loop
               ca.opcode_dup
               rc := run_time_set.item(i)
               rc.opcode_instanceof
               ca.add_branch(ca.opcode_ifne, branch_index)
               i := i - 1
            end
            ca.opcode_pop
            ca.opcode_aconst_null
            ca.resolve_u2_branch(point1)
            ca.resolve_branches( branch_index )
            ca.release_branch_array_index
            left_side.jvm_assign
         end
      end

   once_pre_computable: BOOLEAN is
      do
         if left_side.once_pre_computable then
            Result := right_side.once_pre_computable
         end
      end

   start_position: POSITION is
      do
         Result := left_side.start_position
      end

   to_runnable(ct: E_TYPE): like Current is
      local
         e: EXPRESSION; vjrv_flag, warning_flag: BOOLEAN
      do
         if current_type = Void then
            current_type := ct
            e := left_side.to_runnable(ct)
            if e = Void then
               error_handler.add_position(left_side.start_position)
               error_handler.append(fz_blhsoa)
               error_handler.print_as_fatal_error
            end
            left_side := e
            e := right_side.to_runnable(ct)
            if e = Void then
               error_handler.add_position(right_side.start_position)
               error_handler.append(fz_brhsoa)
               error_handler.print_as_fatal_error
            end
            right_side := e
            if not left_type.run_type.is_reference then
               error_handler.add_type(left_type.run_type,
                                      " is not a reference Type.")
               error_handler.add_position(start_position)
               error_handler.append(" Invalid reverse assignment (VJRV).")
               error_handler.print_as_fatal_error
            end
            if right_side.is_current then
               -- No check yet :-(
            elseif not left_type.run_type.is_a(right_type.run_type) then
               vjrv_flag := True
            elseif right_type.run_type.is_a(left_type.run_type) then
               if not left_type.is_like_current and then
                  not right_type.is_formal_generic and then
                  not left_type.is_formal_generic
                then
                  warning_flag := True
               end
            else
               error_handler.cancel
            end
            if vjrv_flag then
               error_handler.add_position(start_position)
               error_handler.append(
               "Strange assignment attempt. The left-hand side expression should %
               %conform with the right-hand side (VJRV). Note: the previous %
               %constraint is more strict than ETL is, but, the SmartEiffel team %
               %is convinced that this is better for your safety to enforce %
               %this extra constraint. This code will not work in SE 2.x; it is %
               %accepted by SE 1.2 for compatibility with other compilers without %
               %this constraint")
               error_handler.print_as_warning
            end
            if warning_flag then
               error_handler.add_type(right_type," is a ")
               error_handler.add_type(left_type,
               ". Simple assignment is allowed (%"?=%" is not necessary).")
               error_handler.add_position(start_position)
               error_handler.print_as_warning
            end
            assignment_handler.assignment(right_side.start_position,
                                          right_side.result_type,
                                          left_type)
            Result := Current
         else
            create Result.make(left_side,right_side)
            Result := Result.to_runnable(ct)
         end
      end

   right_type: E_TYPE is
      do
         Result := right_side.result_type
      ensure
         Result /= Void
      end

   left_type: E_TYPE is
      do
         Result := left_side.result_type
      ensure
         Result /= Void
      end

   pretty_print is
      do
         pretty_print_assignment(left_side,once "?=",right_side)
      end

feature {ASSIGNMENT_ATTEMPT_VISITOR}

   accept(visitor: ASSIGNMENT_ATTEMPT_VISITOR) is
      do
         visitor.visit_assignment_attempt(Current)
      end

feature {COMPOUND,INSTRUCTION_WITH_COMMENT}

   verify_scoop(allowed: FORMAL_ARG_LIST) is
      local
         dummy: BOOLEAN
      do
         dummy := left_side.verify_scoop(allowed)
         dummy := right_side.verify_scoop(allowed)
      end

feature {NONE}

   current_type: E_TYPE

   make(ls: like left_side; rs: like right_side) is
      require
         ls /= Void
         rs /= Void
      do
         left_side := ls
         right_side := rs
      end

invariant

   left_side.is_writable

   right_side /= Void

end -- ASSIGNMENT_ATTEMPT
