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
class RUN_FEATURE_6

inherit RUN_FEATURE redefine base_feature end

creation make

feature

   base_feature: ONCE_FUNCTION

   arguments: FORMAL_ARG_LIST

   result_type: E_TYPE

   require_assertion: RUN_REQUIRE

   local_vars: LOCAL_VAR_LIST

   routine_body: COMPOUND

   rescue_compound: COMPOUND

   ensure_assertion: E_ENSURE

   is_deferred: BOOLEAN is False

   is_once_procedure: BOOLEAN is False

   is_once_function: BOOLEAN is True

   afd_check is
      do
         routine_afd_check
      end

   simplify_2 is
      do
	 if routine_body /= Void then
	    routine_body := routine_body.simplify_2
	 end
      end

   once_pre_computable: BOOLEAN is
      do
	 inspect
	    once_pre_computable_memory
	 when 0 then
	    once_pre_computable_memory := 1
	    Result := once_routine_pool.once_pre_computable(base_feature)
	    if Result then
	       require_assertion := Void
	       ensure_assertion := Void
	       rescue_compound := Void
	       once_pre_computable_memory := 2
	    else
	       once_pre_computable_memory := 3
	    end
	 when 1 then
	    once_pre_computable_memory := 3
	 when 2 then
	    Result := True
	 when 3 then
	 end
      end

   side_effect_free: BOOLEAN is
      do
         Result := once_pre_computable
      end

   collect_c_tmp is
       do
         if result_type.is_user_expanded then
            if result_type.is_dummy_expanded then
            elseif once_pre_computable then
            else
               cpp.se_tmp_register(result_type)
            end
         end
       end

   mapping_c is
      local
	 se_tmp_idx: INTEGER
       do
          if once_pre_computable then
             once_routine_pool.c_put_o_result(Current)
          else
	     se_tmp_idx := cpp.se_tmp_open_expanded(result_type)
             default_mapping_function
	     if se_tmp_idx >= 0 then
		cpp.se_tmp_close_expanded(se_tmp_idx)
	     end
          end
       end

   c_define is
      do
	 once_routine_pool.c_define_o_result(Current)
         if not once_pre_computable then
	    once_routine_pool.c_define_o_flag(Current)
            define_prototype
	    c_define_body
         end
      end

   mapping_jvm is
      do
         routine_mapping_jvm
      end

feature {ADDRESS_OF_POOL}

   address_of_c_define(caller: ADDRESS_OF) is
      do
         if ace.boost then
            if use_current then
            else
               address_of_c_define_wrapper(caller)
            end
         else
            address_of_c_define_wrapper(caller)
         end
      end

feature {ADDRESS_OF}

   address_of_c_mapping is
      do
         if ace.boost then
            if use_current then
               mapping_name(False)
            else
               address_of_c_mapping_wrapper
            end
         else
            address_of_c_mapping_wrapper
         end
      end

feature {RUN_CLASS}

   jvm_field_or_method is
      do
         jvm.add_method(Current)
      end

feature {JVM}

   jvm_define is
      local
         branch, idx_flag: INTEGER
         ca: like code_attribute
      do
         ca := code_attribute
         idx_flag := once_routine_pool.idx_fieldref_for_flag(Current)
         method_info_start
         ca.opcode_getstatic(idx_flag,1)
         branch := ca.opcode_ifne
         ca.opcode_iconst_1
         ca.opcode_putstatic(idx_flag,-1)
         jvm_define_opening
         jvm_increment_invariant_flag
         if routine_body /= Void then
            routine_body.compile_to_jvm
         end
         jvm_decrement_invariant_flag
         jvm_define_closing
         ca.resolve_u2_branch(branch)
         once_routine_pool.jvm_result_load(Current)
         result_type.run_type.jvm_return_code
         method_info.finish
      end

feature {RUN_CLASS}

   prepare_introspection is
      require
         cpp.on_c
         ace.no_check
      do
         cpp.push_introspect(Current)
         cpp.put_string(once "if (!strcmp(attr,%"")
	 cpp.put_string(name.to_string)
         cpp.put_string(once "%")) {%N")
         if once_pre_computable then
            result_type.run_class.c_return_introspect(Current)
         else
            once_routine_pool.c_test_o_flag_introspect(Current)
            result_type.run_class.c_return_introspect(Current)
            cpp.put_string(once "} else { *id=0; }%N")
         end
         cpp.put_string(fz_12)
         cpp.pop
      end

feature {RUN_FEATURE_6_VISITOR}

   accept(visitor: RUN_FEATURE_6_VISITOR) is
      do
         visitor.visit_run_feature_6(Current)
      end

feature {NONE}

   c_define_body is
      do
	 once_routine_pool.c_test_o_flag(Current)
	 c_define_opening
	 if routine_body /= Void then
	    routine_body.compile_to_c
	 end
	 c_define_closing
	 once_routine_pool.c_return_o_result(Current)
      end

   initialize is
      local
	 base_class: BASE_CLASS
      do
	 base_class := current_type.base_class
         result_type := base_feature.result_type
         arguments := base_feature.arguments
         if result_type.is_anchored then
            fe_vffd7
         elseif result_type.is_formal_generic then
            error_handler.add_position(result_type.start_position)
            fatal_error("Result type of a once function must %
                        %not be a formal generic argument (VFFD.7).")
         end
         result_type := result_type.to_runnable(current_type)
         if arguments /= Void then
            if not arguments.is_runnable(current_type) then
               !!arguments.with(arguments,current_type)
            end
         end
         local_vars := base_feature.local_vars
         if local_vars /= Void then
            local_vars := local_vars.to_runnable(current_type)
         end
         routine_body := base_feature.routine_body
         if routine_body /= Void then
            routine_body := routine_body.to_runnable(current_type)
         end
         if base_class.require_check then
            require_assertion := base_class.run_require(Current)
         end
         if base_class.ensure_check then
            ensure_assertion := base_class.run_ensure(Current)
         end
         rescue_compound := base_feature.rescue_compound
         if rescue_compound = Void then
	    rescue_compound := default_rescue_compound
	 end
         if rescue_compound /= Void then
            exceptions_handler.set_used
            rescue_compound := rescue_compound.to_runnable(current_type)
         end
         once_routine_pool.register_function(Current)
      end

   compute_use_current is
      do
	 std_compute_use_current
      end

   compute_stupid_switch(run_time_set: RUN_TIME_SET) is
      do
         std_compute_stupid_switch(run_time_set)
      end

   update_tmp_jvm_descriptor is
      do
         routine_update_tmp_jvm_descriptor
      end

   once_pre_computable_memory: INTEGER
	    
   stupid_switch_comment: STRING is "SSORRF6"

end -- RUN_FEATURE_6
