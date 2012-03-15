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
class RUN_FEATURE_11
   --
   -- Wrapped some function called via the Precursor construct.
   --
inherit RUN_FEATURE redefine base_feature, fall_down, verify_scoop_expanded end

creation {PRECURSOR_EXPRESSION} make

feature

   base_feature: EFFECTIVE_ROUTINE

   arguments: FORMAL_ARG_LIST

   result_type: E_TYPE

   require_assertion: RUN_REQUIRE

   local_vars: LOCAL_VAR_LIST

   routine_body: COMPOUND

   rescue_compound: COMPOUND

   ensure_assertion: E_ENSURE

   once_function: ONCE_FUNCTION
	 -- May not be Void when some once function is wrapped.
		  
   is_deferred: BOOLEAN is False

   side_effect_free: BOOLEAN is False

   is_once_procedure: BOOLEAN is False

   is_once_function: BOOLEAN is
	 -- True when some once function is wrapped.
      do
	 Result := once_function /= Void
      end

   once_pre_computable: BOOLEAN is
      do
	 if is_once_function then
	    inspect
	       once_pre_computable_memory
	    when 0 then
	       once_pre_computable_memory := 1
	       Result := once_routine_pool.once_pre_computable(once_function)
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
      end

   fall_down is do end

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

   collect_c_tmp is
      do
         if result_type.is_user_expanded then
            if result_type.is_dummy_expanded then
            else
               cpp.se_tmp_register(result_type)
            end
         end
      end

   mapping_c is
      local
         se_tmp_idx: INTEGER
      do
	 if is_once_routine and then once_pre_computable then
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
	 cpp.incr_precursor_routine_count
	 if is_once_function then
	    once_routine_pool.c_define_o_result(Current)
	 end
	 if (not is_once_function) or else (not once_pre_computable) then
	    if is_once_function then
	       once_routine_pool.c_define_o_flag(Current)
	    end
	    define_prototype
	    if is_once_function then
	       once_routine_pool.c_test_o_flag(Current)
	    end
	    c_define_opening
	    if routine_body /= Void then
	       routine_body.compile_to_c
	    end
	    c_define_closing
	    if is_once_function then
	       once_routine_pool.c_return_o_result(Current)
	    else
	       cpp.put_string(fz_15)
	    end
	 end
      end

feature {RUN_CLASS}

   jvm_field_or_method is
      do
         jvm.add_method(Current)
      end

   verify_scoop_expanded(p: POSITION) is
      do
         --default_verify_scoop_expanded(p)
      end

feature

   mapping_jvm is
      do
         routine_mapping_jvm
      end

feature {JVM}

   jvm_define is
      do
         method_info_start
         jvm_define_opening
         if routine_body /= Void then
            routine_body.compile_to_jvm
         end
         jvm_define_closing
         result_type.jvm_push_local(jvm_result_offset)
         result_type.run_type.jvm_return_code
         method_info.finish
      end

feature {NONE}

   update_tmp_jvm_descriptor is
      do
         routine_update_tmp_jvm_descriptor
      end

feature {ADDRESS_OF_POOL}

   address_of_c_define(caller: ADDRESS_OF) is
      do
      end

feature {ADDRESS_OF}

   address_of_c_mapping is
      do
      end

feature {RUN_FEATURE_11_VISITOR}

   accept(visitor: RUN_FEATURE_11_VISITOR) is
      do
         visitor.visit_run_feature_11(Current)
      end

feature {NONE}

   compute_use_current is
      do
         std_compute_use_current
      end

   initialize is
      local
	 base_class: BASE_CLASS
      do
	 once_function ?= base_feature
	 base_class := current_type.base_class
         arguments := base_feature.arguments
         if arguments /= Void then
            if not arguments.is_runnable(current_type) then
               !!arguments.with(arguments,current_type)
            end
         end
         result_type := base_feature.result_type.to_runnable(current_type)
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
         if rescue_compound /= Void then
            exceptions_handler.set_used
            rescue_compound := rescue_compound.to_runnable(current_type)
         end
	 if is_once_function then
	    once_routine_pool.register_function(Current)
	 end
      end

   c_define_body is
      do
	 not_yet_implemented
      end

   compute_stupid_switch(run_time_set: RUN_TIME_SET) is
      do
         std_compute_stupid_switch(run_time_set)
      end

   once_pre_computable_memory: INTEGER
	    
   stupid_switch_comment: STRING is "SSPRF11"

end -- RUN_FEATURE_11
