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
class E_RESULT
   --
   -- Handling of the pseudo variable `Result' (keep in mind that the 
   -- `Result' variable can be inside a once function or inside an ordinary 
   -- non-once function).
   --

inherit EXPRESSION

creation make
   
feature

   start_position: POSITION

   is_result: BOOLEAN is True

   is_writable: BOOLEAN is True

   is_current: BOOLEAN is False

   is_manifest_string: BOOLEAN is False

   is_void: BOOLEAN is False

   is_static: BOOLEAN is False

   once_pre_computable: BOOLEAN is True

   isa_dca_inline_argument: INTEGER is 0

   side_effect_free: BOOLEAN is True

   use_current: BOOLEAN is False

   extra_bracket_flag: BOOLEAN is False
   
   precedence: INTEGER is
      do
         Result := atomic_precedence
      end

   is_once_result: BOOLEAN is
      do
	 Result := run_feature.is_once_function
      end
   
   to_integer_or_error: INTEGER is
      do
	 to_integer_error
      end

   result_type: E_TYPE is
      do
         Result := run_feature.result_type
      end

   to_string, frozen to_key: STRING is
      do
         Result := as_result
      end

   start_lookup_class: BASE_CLASS is
      local
         rf: RUN_FEATURE; e_feature: E_FEATURE; rt: E_TYPE
      do
         rf := smart_eiffel.top_rf
         e_feature := rf.base_feature
         rt := e_feature.result_type
	 Result := rt.start_lookup_class
      end

   to_runnable(ct: E_TYPE): like Current is
      local
         rf: RUN_FEATURE; rt: E_TYPE
      do
         rf := smart_eiffel.top_rf
         rt := rf.result_type
         if run_feature = Void then
            run_feature := rf
	    if run_feature.is_once_function and then rt.is_anchored then
	       run_feature.fe_vffd7
	    end
            Result := Current
         else
            create Result.make(start_position)
            Result := Result.to_runnable(ct)
         end
      end

   compile_to_c is
      do
         if run_feature.is_once_function then
            once_routine_pool.c_put_o_result(run_feature)
         else
            cpp.put_character('R')
         end
      end

   stupid_switch(run_time_set: RUN_TIME_SET): BOOLEAN is
      do
         if smart_eiffel.stupid_switch(result_type,run_time_set) then
            Result := True
         end
      end

   assertion_check(tag: CHARACTER) is
      do
      end

   afd_check is
      do
      end

   safety_check is
      do
      end

   dca_inline_argument(formal_arg_type: E_TYPE) is
      do
      end

   bracketed_pretty_print, frozen pretty_print is
      do
         pretty_printer.put_string(as_result)
      end

   print_as_target is
      do
         pretty_printer.put_string(as_result)
         pretty_printer.put_character('.')
      end

   short is
      do
         short_print.hook_or(as_result,as_result)
      end

   short_target is
      do
         short
         short_print.a_dot
      end

   mapping_c_target(formal_type: E_TYPE) is
      do
	 standard_mapping_c_target(formal_type)
      end

   simplify_1_, frozen simplify_2: like Current is
      do
	 Result := Current
      end
   
   mapping_c_arg(formal_arg_type: E_TYPE) is
      do
	 compile_to_c
      end

   collect_c_tmp is
      do
      end

   c_frame_descriptor(format, locals: STRING) is
      do
      end

   compile_to_jvm is
      local
         jvm_offset: INTEGER
      do
	 if run_feature.is_once_routine then
	    once_routine_pool.jvm_result_load(run_feature)
	 else
	    jvm_offset := run_feature.jvm_result_offset
	    result_type.run_type.jvm_push_local(jvm_offset)
	 end
      end

   compile_target_to_jvm is
      do
         standard_compile_target_to_jvm
      end

   jvm_branch_if_false: INTEGER is
      do
         compile_to_jvm
         Result := code_attribute.opcode_ifeq
      end

   jvm_branch_if_true: INTEGER is
      do
         compile_to_jvm
         Result := code_attribute.opcode_ifne
      end

   compile_to_jvm_into(dest: E_TYPE): INTEGER is
      do
         Result := standard_compile_to_jvm_into(dest)
      end

   jvm_assign_creation is
      local
         jvm_offset: INTEGER
      do
	 if run_feature.is_once_routine then
	    once_routine_pool.jvm_result_store(run_feature)
	 else
	    jvm_offset := run_feature.jvm_result_offset
	    result_type.run_type.jvm_write_local_creation(jvm_offset)
	 end
      end

   jvm_assign is
      local
         jvm_offset: INTEGER
      do
	 if run_feature.is_once_routine then
	    once_routine_pool.jvm_result_store(run_feature)
	 else
	    jvm_offset := run_feature.jvm_result_offset
	    result_type.run_type.jvm_write_local(jvm_offset)
	 end
      end

feature {CREATE_TOOLS}

   c_variable_name: STRING is
      require
	 is_once_result
      local
	 bf: E_FEATURE
      do
	 bf := run_feature.base_feature
         Result := once_routine_pool.o_result(bf)
      end

feature {E_RESULT_VISITOR}

   accept(visitor: E_RESULT_VISITOR) is
      do
         visitor.visit_e_result(Current)
      end

feature {NONE}

   run_feature: RUN_FEATURE
	 -- The corresponding one which contains this `Result' expression.

   make(sp: like start_position) is
      require
         not sp.is_unknown
      do
         start_position := sp
      ensure
         start_position = sp
      end

invariant

   not start_position.is_unknown

end -- E_RESULT

