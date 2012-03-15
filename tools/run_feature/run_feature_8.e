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
class RUN_FEATURE_8

inherit RUN_FEATURE redefine base_feature, verify_scoop_expanded end

creation make

feature

   base_feature: EXTERNAL_FUNCTION

   arguments: FORMAL_ARG_LIST

   result_type: E_TYPE

   require_assertion: RUN_REQUIRE

   ensure_assertion: E_ENSURE

   is_deferred: BOOLEAN is False

   once_pre_computable: BOOLEAN is False

   side_effect_free: BOOLEAN is False

   is_once_procedure: BOOLEAN is False

   is_once_function: BOOLEAN is False

   arg_count: INTEGER is
      do
         if arguments /= Void then
            Result := arguments.count
         end
      end

   local_vars: LOCAL_VAR_LIST is do end

   routine_body: COMPOUND is do end

   rescue_compound: COMPOUND is do end

   afd_check is
      local
         i: INTEGER
         t: E_TYPE
         nc: NATIVE_C; ncpp: NATIVE_C_PLUS_PLUS; nj: NATIVE_JAVA
      do
         routine_afd_check
         -- Check for non-portable argument types
         nc ?= base_feature.native
         ncpp ?= base_feature.native
         nj ?= base_feature.native
         if arguments /= Void and (nc /= Void or ncpp /= Void or nj /= Void) then
            from i := arguments.count until i < 1 loop
               t := arguments.type (i)
               if t.is_real and then t.written_mark = as_real then
                  error_handler.add_position (t.start_position)
                  error_handler.append ("You should not use REAL as argument for external %
                                        %routines. The size of REAL will change for SE 2.x to %
                                        %64-bits, producing linking problems. Use REAL_32 instead.")
                  error_handler.print_as_warning
               elseif t.is_double and then t.written_mark = as_double then
                  error_handler.add_position (t.start_position)
                  error_handler.append ("You should not use DOUBLE as argument for external %
                                        %routines. DOUBLE will be deprecated in SE 2.x for %
                                        %REAL. Use REAL_64 instead.")
                  error_handler.print_as_warning
               end
               i := i - 1
            end
         end
      end

   simplify_2 is
      do
      end

   collect_c_tmp is
      do
         if result_type.is_user_expanded then
            if not result_type.is_dummy_expanded then
	       -- This may occurs when feature `twin':
               cpp.se_tmp_register(result_type)
            end
         end
      end

   mapping_c is
      local
         bf: like base_feature; native: NATIVE; bcn: STRING
	 unknown_position: POSITION; se_tmp_idx: INTEGER
      do
	 se_tmp_idx := cpp.se_tmp_open_expanded(result_type)
	 if in_scoop_wrapper then
            default_mapping_function
         else
            bf := base_feature
            native := bf.native
            bcn := bf.base_class.name.to_string
            native.c_mapping_function(Current,bcn,bf.first_name.to_string)
         end
	 if se_tmp_idx >= 0 then
	    cpp.se_tmp_close_expanded(se_tmp_idx)
	 end
      end

   c_define is
      local
         bf: like base_feature; native: NATIVE; bc: BASE_CLASS; bcn: STRING
      do
         bf := base_feature
         native := bf.native
	 bc := bf.base_class
	 if bc /= Void then
	    bcn := bc.name.to_string
	    native.c_define_function(Current,bcn,bf.first_name.to_string)
	 end
      end

   mapping_jvm is
      local
         bf: like base_feature; native: NATIVE; bcn: STRING
      do
         bf := base_feature
         native := bf.native
         bcn := bf.base_class.name.to_string
         native.jvm_mapping_function(Current,bcn,bf.first_name.to_string)
      end

feature {TYPE_BIT_2}

   integer_value(p: POSITION): INTEGER is
	 -- For some special constant only.
      local
         n: STRING
      do
	 n := name.to_string
	 debug
	    if eiffel_parser.case_insensitive then
	       check
		  as_integer_bits.is_equal(as_integer_bits.as_lower)
	       end
	    end
	 end
	 check
	    n = string_aliaser.item(n)
	    as_integer_bits = string_aliaser.item(as_integer_bits)
	 end
	 if as_integer_bits = n then
            Result := Integer_bits
         elseif as_character_bits = n then
            Result := Character_bits
         else
	    error_handler.add_position(p)
            error_handler.add_position(start_position)
            fatal_error(fz_iinaiv)
         end
      end

feature {RUN_CLASS}

   jvm_field_or_method is
      local
         bf: like base_feature; native: NATIVE; n, bcn: STRING
      do
         bf := base_feature
         n := bf.first_name.to_string
	 native := base_feature.native
	 bcn := bf.base_class.name.to_string
	 native.jvm_add_method_for_function(Current,bcn,n)
      end

   verify_scoop_expanded(p: POSITION) is
      do
         --default_verify_scoop_expanded(p)
      end

feature {JVM}

   jvm_define is
      local
         bf: like base_feature; native: NATIVE; n, bcn: STRING
      do
         bf := base_feature
         n := bf.first_name.to_string
	 native := bf.native
	 bcn := bf.base_class.name.to_string
	 native.jvm_define_function(Current,bcn,n)
      end

feature {NATIVE}

   external_c_prototype_from(p: POSITION) is
      do
         external_c_prototype(p,base_feature)
      end

   c_opening is
      do
         define_prototype
         c_define_opening
      end

   c_closing is
      do
         c_define_closing
         cpp.put_string(fz_15)
      end

   jvm_opening is
      do
         method_info_start
         jvm_define_opening
      end

   jvm_closing is
      do
         jvm_define_closing
         result_type.jvm_push_local(jvm_result_offset)
         result_type.run_type.jvm_return_code
         method_info.finish
      end

   jvm_closing_fast is
         -- Skip ensure and assume the result is already pushed.
      do
         result_type.run_type.jvm_return_code
         method_info.finish
      end

feature {ADDRESS_OF_POOL}

   address_of_c_define(caller: ADDRESS_OF) is
      do
      end

feature {ADDRESS_OF}

   address_of_c_mapping is
      do
	 cpp.put_string(base_feature.external_name)
      end

feature {RUN_FEATURE_8_VISITOR}

   accept(visitor: RUN_FEATURE_8_VISITOR) is
      do
         visitor.visit_run_feature_8(Current)
      end

feature {NONE}

   initialize is
      local
         n: STRING; rf: RUN_FEATURE; base_class: BASE_CLASS
      do
	 base_class := current_type.base_class
         n := base_feature.first_name.to_string
         arguments := base_feature.arguments
	 result_type := base_feature.result_type
	 if arguments = Void then
	    result_type := result_type.to_runnable(current_type)
	 elseif result_type.is_like_argument then
	    if not arguments.is_runnable(current_type) then
	       !!arguments.with(arguments,current_type)
	    end
	    result_type := result_type.to_runnable(current_type)
	 else
	    result_type := result_type.to_runnable(current_type)
	    if not arguments.is_runnable(current_type) then
	       !!arguments.with(arguments,current_type)
	    end
         end
         if base_class.require_check then
            require_assertion := base_class.run_require(Current)
         end
         if base_class.ensure_check then
            ensure_assertion := base_class.run_ensure(Current)
         end
         if n.has_prefix(fz_basic_) then
            smart_eiffel.register_sys_runtime_basic_of(n)
         elseif as_twin = n then
            rf := run_class.get_copy
         elseif as_se_argc = n then
            type_string.set_at_run_time
         elseif as_generating_type = n then
            smart_eiffel.set_generator_used
            smart_eiffel.set_generating_type_used
         elseif as_generator = n then
            smart_eiffel.set_generator_used
         elseif as_deep_twin = n then
            run_class.set_deep_twin_flag
         elseif as_is_deep_equal = n then
            run_class.set_is_deep_equal_flag
         elseif as_exception = n then
            exceptions_handler.set_used
         elseif as_signal_number = n then
            exceptions_handler.set_used
         end
	 base_feature.native.notify_external_assignments(arguments,
							 result_type)
      end

   c_define_body is
      local
         bf: like base_feature; native: NATIVE_SMART_EIFFEL; bcn: STRING
      do
         bf := base_feature
         native ?= bf.native
	 if native = Void then
	    not_yet_implemented
	 end
         bcn := bf.base_class.name.to_string
         native.scoop_define_function_body(Current,bcn,bf.first_name.to_string)
      end

   compute_use_current is
      do
         smart_eiffel.push(Current)
         if base_feature.use_current then
            use_current_state := True_state
         else
            std_compute_use_current
         end
         smart_eiffel.pop
      end

   compute_stupid_switch(run_time_set: RUN_TIME_SET) is
      do
         smart_eiffel.push(Current)
         if base_feature.native.stupid_switch_function(run_time_set,
						       name.to_string)
	  then
            stupid_switch_state := True_state
         else
            stupid_switch_state := False_state
         end
         smart_eiffel.pop
      end

   update_tmp_jvm_descriptor is
      do
         routine_update_tmp_jvm_descriptor
      end

   stupid_switch_comment: STRING is "SSERRF8"

end -- RUN_FEATURE_8
