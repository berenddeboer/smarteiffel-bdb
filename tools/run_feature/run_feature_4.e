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
class RUN_FEATURE_4

inherit RUN_FEATURE redefine base_feature, verify_scoop_expanded end

creation make

feature

   base_feature: E_FUNCTION

   arguments: FORMAL_ARG_LIST

   result_type: E_TYPE

   require_assertion: RUN_REQUIRE

   local_vars: LOCAL_VAR_LIST

   routine_body: COMPOUND

   rescue_compound: COMPOUND

   ensure_assertion: E_ENSURE

   is_deferred: BOOLEAN is False

   is_once_procedure: BOOLEAN is False

   is_once_function: BOOLEAN is False

   once_pre_computable: BOOLEAN is False

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

   side_effect_free: BOOLEAN is
      do
	 if side_effect_free_flag then
	    Result := False
	 else
	    side_effect_free_flag := True
	    Result :=
	    (
	     ((routine_body = Void) or else routine_body.side_effect_free)
	     and then
	     ((local_vars = Void) or else local_vars.side_effect_free)
	     and then
	     ((rescue_compound = Void) or else rescue_compound.side_effect_free)
	     and then
	     ((require_assertion = Void) or else require_assertion.side_effect_free)
	     and then
	     ((ensure_assertion = Void) or else ensure_assertion.side_effect_free)
	     )
	    side_effect_free_flag := False
	 end
      end

   collect_c_tmp is
      local
         a: ASSIGNMENT; c: CALL
      do
         if result_type.is_user_expanded then
            if result_type.is_dummy_expanded then
            elseif isa_in_line then
               inspect
                  in_line_status
               when C_dca then
                  a ?= routine_body.first
                  c ?= a.right_side
                  c.run_feature.collect_c_tmp
               else
               end
            else
               cpp.se_tmp_register(result_type)
            end
         end
      end

   mapping_c is
      local
         se_tmp_idx: INTEGER
      do
         if isa_in_line then
            in_line
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
         if isa_in_line then
            cpp.incr_inlined_function_count
         else
            if use_current then
               cpp.incr_function_count
            else
               cpp.incr_real_function_count
            end
            define_prototype
	    c_define_body
            cpp.put_string(fz_15)
         end
      end

feature {CALL}

   value: EXPRESSION is
	 -- If non Void, for simple function, the constant value of this 
	 -- call.
      local
	 assignment: ASSIGNMENT; expression: EXPRESSION; e_void: E_VOID
	 base_type_constant: BASE_TYPE_CONSTANT
	 manifest_string: MANIFEST_STRING
      do
	 if side_effect_free then
	    Result := result_type.default_expression(start_position)
	 elseif (routine_body /= Void and then routine_body.count = 1
		 and then
		 ((local_vars = Void) or else local_vars.side_effect_free)
		 and then
		 rescue_compound = Void
		 and then
		 require_assertion = Void
		 and then
		 ensure_assertion = Void)
	  then
            assignment ?= routine_body.first
            if assignment /= Void then
               if assignment.left_side.is_result then
		  expression := assignment.right_side
		  base_type_constant ?= expression
		  if base_type_constant /= Void then
		     Result := base_type_constant
		  else
		     e_void ?= expression
		     if e_void /= Void then
			Result := e_void
		     else
			manifest_string ?= expression
			if manifest_string /= Void then
			   Result := manifest_string
			end
		     end
		  end
               end
            end
	 end
      end
   
feature {ADDRESS_OF_POOL}

   address_of_c_define(caller: ADDRESS_OF) is
      do
         if ace.boost then
            if isa_in_line then
               address_of_c_define_wrapper(caller)
            elseif use_current then
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
            if isa_in_line then
               address_of_c_mapping_wrapper
            elseif use_current then
               mapping_name(False)
            else
               address_of_c_mapping_wrapper
            end
         else
            address_of_c_mapping_wrapper
         end
      end

feature {FUNCTION}

   is_empty_or_null_body: BOOLEAN is
      do
         if isa_in_line then
            Result := in_line_status = C_empty_or_null_body
         end
      end

   is_direct_call_on_attribute: CALL is
         -- Gives Void or the corresponding call.
      do
         if isa_in_line then
            inspect
               in_line_status
            when C_dca then
               Result ?= body_one_result
            else
            end
         end
      end

feature {NONE}

   initialize is
      local
	 base_class: BASE_CLASS
      do
	 base_class := current_type.base_class
         arguments := base_feature.arguments
         result_type := base_feature.result_type
         if result_type.is_like_argument then
            if not arguments.is_runnable(current_type) then
               create arguments.with(arguments, current_type)
            end
            result_type := result_type.to_runnable(current_type)
         else
            result_type := result_type.to_runnable(current_type)
            if arguments /= Void then
               if not arguments.is_runnable(current_type) then
                  create arguments.with(arguments, current_type)
               end
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
      end

   in_line_status: INTEGER
         -- Value 0 means not computed.
         -- Value -1 means not `isa_in_line' and value -2 is used
         -- during compuation to avoid infinite recursion.

   isa_in_line: BOOLEAN is
      do
         if ace.boost then
            inspect
               in_line_status
            when -2 then
	       in_line_status := -1
            when -1 then
            when 0 then
               Result := True
	       in_line_status := -2
	       if smart_eiffel.scoop and then current_type.is_separate then
                  in_line_status := -1
		  Result := False
               elseif rescue_compound /= Void then
                  in_line_status := -1
                  Result := False
               elseif empty_or_null_body then
                  in_line_status := C_empty_or_null_body
               elseif value_reader then
                  in_line_status := C_value_reader
               elseif attribute_reader then
                  in_line_status := C_attribute_reader
               elseif result_is_current then
                  in_line_status := C_result_is_current
               elseif direct_call then
                  in_line_status := C_direct_call
               elseif dca then
                  in_line_status := C_dca
               elseif a_eq_neq then
                  in_line_status := C_a_eq_neq
               elseif dc_pco1 then
                  in_line_status := C_dc_pco1
               elseif dc_pco2 then
                  in_line_status := C_dc_pco2
               elseif direct_cse_call then
                  in_line_status := C_direct_cse_call
               else
                  in_line_status := -1
                  Result := False
               end
            else
               Result := True
            end
         end
      end

   empty_or_null_body: BOOLEAN is
         -- The body is empty or has only unreacheable code.
      local
         rb: COMPOUND; rt: E_TYPE
      do
         rb := routine_body
         if rb = Void or else rb.side_effect_free then
	    if local_vars = Void then
	       rt := result_type
	       if rt.is_reference then
		  Result := True
	       end
	    end
         end
      end

   value_reader: BOOLEAN is
         -- True when the function body has only one instruction
         -- of the form :
         --      Result := <expression>
         -- Where <expression> is statically computable.
      local
         e: EXPRESSION; c0: CALL_0
      do
         e := body_one_result
         if e /= Void and then local_vars = Void then
            c0 ?= e
            if c0 /= Void and then
               c0.target.is_current and then
               c0.run_feature = Current
             then
               error_handler.add_position(e.start_position)
               fatal_error("Infinite recursive call.")
            elseif e.is_static then
               Result := True
            end
         end
      end

   attribute_reader: BOOLEAN is
         -- True when the function has no arguments, no locals, and
         -- when the body has only one instruction of the form :
         --      Result := attribute
         -- Where `attribute' is a RUN_FEATURE_2.
      local
         e: EXPRESSION; c0: CALL_0; rf2: RUN_FEATURE_2
      do
         e := body_one_result
         if e /= Void and then local_vars = Void then
            c0 ?= e
            if c0 /= Void then
               if c0.target.is_current then
                  rf2 ?= c0.run_feature
                  if rf2 /= Void then
                     Result := not rf2.result_type.is_user_expanded
                  end
               end
            end
         end
      end

   result_is_current: BOOLEAN is
      local
         e: EXPRESSION
      do
	 if current_type.is_reference then
	    e := body_one_result
	    if e /= Void and then local_vars = Void then
	       Result := e.is_current
	    end
	 end
      end

   direct_call: BOOLEAN is
         -- True when the function has no arguments, no locals, and
         -- when the body has only one instruction of the form :
         --    Result := foo(<args>)
         -- Where <args> can be an empty list or a statically
         -- computable one.
         -- Where `foo' is a RUN_FEATURE_4.
      local
	 c: CALL; args: EFFECTIVE_ARG_LIST; rf4: RUN_FEATURE_4
      do
         c ?= body_one_result
         if c /= Void and then arguments = Void and then local_vars = Void then
	    if c.target.is_current then
	       rf4 ?= c.run_feature
	       if rf4 /= Void then
		  args := c.arguments
		  if args = Void then
		     Result := True
		  else
		     Result := args.is_static
		  end
               end
            end
         end
      end

   dca: BOOLEAN is
         -- Direct Call on Attribute.
      local
         c: CALL; rf: RUN_FEATURE; args: EFFECTIVE_ARG_LIST
      do
         c := body_one_result_dca
         if c /= Void and then local_vars = Void then
            rf := c.run_feature
            if rf /= Void then
               if rf /= Current then
		  if rf.current_type.is_user_expanded then
                     -- Not yet inlined :-(
		  elseif rf.result_type.is_user_expanded then
                     -- Not inlined too...
                  else
                     args := c.arguments
                     if args = Void then
                        Result := arguments = Void
                     else
                        Result := args.isa_dca_inline(Current, rf)
                     end
                  end
               end
            end
         end
      end

   a_eq_neq: BOOLEAN is
         -- Attribute "=" or "/=".
      local
         c: CALL; rf: RUN_FEATURE; e: EXPRESSION
      do
         c := body_one_result_dca
         if c /= Void and then local_vars = Void then
            rf := c.run_feature
            if rf = Void and then c.arg_count = 1 then
               -- For "=" and "/=" :
               e := c.arguments.expression(1)
               inspect
                  e.isa_dca_inline_argument
               when 0 then
               when -1 then
                  Result := arguments = Void
               else
                  if arguments /= Void then
                     Result := arguments.count = 1
                  end
               end
            end
         end
      end

   dc_pco1: BOOLEAN is
      local
         c: CALL
         rf6: RUN_FEATURE_6
      do
         c := body_one_dc_pco
         if c /= Void and then c.target.is_current then
            rf6 ?= c.run_feature
            if rf6 /= Void then
               Result := not rf6.use_current
            end
         end
      end

   dc_pco2: BOOLEAN is
      local
         c1, c2: CALL; rf6: RUN_FEATURE_6
      do
         c1 := body_one_dc_pco
         if c1 /= Void then
            c2 ?= c1.target
            if c2 /= Void then
               rf6 ?= c2.run_feature
               if rf6 /= Void and then
                  not rf6.use_current and then
                  c2.target.is_current
                then
                  Result := True
               end
            end
         end
      end

   direct_cse_call: BOOLEAN is
      local
         c: CALL
         rf8: RUN_FEATURE_8
      do
         if arguments = Void and then local_vars = Void then
            c ?= body_one_result
            if c /= Void and then c.arguments = Void then
               c ?= c.target
               if c /= Void and then c.target.is_current then
                  if c.arguments = Void then
                     rf8 ?= c.run_feature
                     if rf8 /= Void then
                        Result := rf8.name.to_string = as_to_pointer
                     end
                  end
               end
            end
         end
      end

   in_line is
      local
         a: ASSIGNMENT; e: EXPRESSION; flag: BOOLEAN; c: CALL
         rf: RUN_FEATURE; rf4: RUN_FEATURE_4; cien: CALL_INFIX2; rt: E_TYPE
      do
         cpp.put_string(once "/*(IRF4.")
         cpp.put_integer(in_line_status)
         cpp.put_string(name.to_string)
         cpp.put_string(fz_close_c_comment)
         inspect
            in_line_status
         when C_empty_or_null_body then
            flag := cpp.cannot_drop_all
            if flag then
               cpp.put_character(',')
            end
            rt := result_type.run_type
            if rt.is_user_expanded then
               cpp.put_character('M')
               cpp.put_integer(rt.id)
            else
               rt.c_initialize
            end
            if flag then
               cpp.put_character(')')
            end
         when C_value_reader then
            flag := cpp.cannot_drop_all
            if flag then
               cpp.put_character(',')
            end
            a ?= routine_body.first
            e := a.right_side
            cpp.put_character('(')
            e.compile_to_c
            cpp.put_character(')')
            if flag then
               cpp.put_character(')')
            end
         when C_attribute_reader then
            flag := cpp.arguments_cannot_be_dropped
            if flag then
               cpp.put_character(',')
            end
            a ?= routine_body.first
            c ?= a.right_side
            rf := c.run_feature
            rf.mapping_c
            if flag then
               cpp.put_character(')')
            end
         when C_result_is_current then
            flag := cpp.arguments_cannot_be_dropped
            if flag then
               cpp.put_character(',')
            end
	    rt := result_type.run_type
	    if rt.is_basic_eiffel_expanded then
	       cpp.put_character('(')
	       cpp.put_target_as_value
	       cpp.put_character(')')
	    else
	       tmp_string.copy(fz_17)
	       rt.c_type_for_result_in(tmp_string)
	       tmp_string.append(fz_22)
	       cpp.put_string(tmp_string)
	       cpp.put_target_as_value
	       cpp.put_string(fz_13)
	    end
            if flag then
               cpp.put_character(')')
            end
         when C_direct_call then
            c ?= body_one_result
            rf4 ?= c.run_feature
            cpp.push_same_target(rf4, c.arguments)
            rf4.mapping_c
            cpp.pop
         when C_dca then
            a ?= routine_body.first
            c ?= a.right_side
	    c.finalize
            cpp.push_inline_dca(Current, c)
            c.run_feature.mapping_c
            cpp.pop
         when C_a_eq_neq then
            a ?= routine_body.first
            cien ?= a.right_side
            cpp.push_inline_dca(Current, cien)
            cien.dca_inline(cien.arg1.result_type)
            cpp.pop
         when C_dc_pco1 then
            flag := cpp.target_cannot_be_dropped
            if flag then
               cpp.put_character(',')
            end
            a ?= routine_body.first
            c ?= a.right_side
            rf := c.run_feature
            cpp.push_direct(rf, c.target, c.arguments)
            rf.mapping_c
            cpp.pop
            if flag then
               cpp.put_character(')')
            end
         when C_dc_pco2 then
            flag := cpp.target_cannot_be_dropped
            if flag then
               cpp.put_character(',')
            end
            a ?= routine_body.first
            c ?= a.right_side
            c.compile_to_c
            if flag then
               cpp.put_character(')')
            end
         when C_direct_cse_call then
            a ?= routine_body.first
            c ?= a.right_side
            rf := c.run_feature
            cpp.push_same_target(rf, c.arguments)
            rf.mapping_c
            cpp.pop
         end
         cpp.put_string(once "/*)*/")
      end

   compute_use_current is
      local
         ct: like current_type
      do
         ct := current_type
         if ct.is_reference then
            if ace.no_check then
               use_current_state := True_state
            else
               std_compute_use_current
            end
         else
            std_compute_use_current
         end
      end

   body_one_result: EXPRESSION is
         -- Gives the RHS expression if the body has only one
         -- instruction of the form :
         --        Result := <RHS>
      local
         rb: like routine_body; a: ASSIGNMENT
      do
         rb := routine_body
         if rb /= Void and then rb.count = 1 then
            a ?= rb.first
            if a /= Void then
               if a.left_side.is_result then
                  Result := a.right_side
               end
            end
         end
      end

   body_one_result_dca: CALL is
      local
         c: CALL; c0c: CALL_0_C; writable_attribute: RUN_FEATURE_2
         rf: RUN_FEATURE; run_time_set: RUN_TIME_SET; bf: WRITABLE_ATTRIBUTE
      do
         c ?= body_one_result
         if c /= Void then
            c0c ?= c.target
            if c0c /= Void then
               if c0c.target.is_current then
                  writable_attribute ?= c0c.run_feature
                  if writable_attribute /= Void then
                     run_time_set := writable_attribute.run_class.run_time_set
                     rf := c.run_feature
                     if rf = Void then -- Basic "=" and "/=" :
                        Result := c
                     elseif run_time_set.count = 1 then
                        run_time_set := rf.run_class.run_time_set
                        if run_time_set.count = 1 then
                           bf := writable_attribute.base_feature
                           Result := c
                        end
                     end
                  end
               end
            end
         end
      end

   body_one_dc_pco: CALL is
      local
         c: CALL
         args: EFFECTIVE_ARG_LIST
      do
         c ?= body_one_result
         if c /= Void and then
            local_vars = Void and then
            arguments = Void
          then
            args := c.arguments
            if args = Void or else args.is_static then
               Result := c
            end
         end
      end

feature {NONE}

   C_empty_or_null_body  : INTEGER is 1
   C_value_reader        : INTEGER is 2
   C_attribute_reader    : INTEGER is 3
   C_result_is_current   : INTEGER is 4
   C_direct_call         : INTEGER is 5
   C_dca                 : INTEGER is 6
   C_a_eq_neq            : INTEGER is 7
   C_dc_pco1             : INTEGER is 8
   C_dc_pco2             : INTEGER is 9
   C_direct_cse_call     : INTEGER is 10

feature {NONE}

   tmp_string: STRING is
      once
         !!Result.make(8)
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
         jvm_increment_invariant_flag
         if routine_body /= Void then
            routine_body.compile_to_jvm
         end
         jvm_decrement_invariant_flag
         jvm_define_closing
         result_type.jvm_push_local(jvm_result_offset)
         result_type.run_type.jvm_return_code
         method_info.finish
      end

feature {RUN_FEATURE_4_VISITOR}

   accept(visitor: RUN_FEATURE_4_VISITOR) is
      do
         visitor.visit_run_feature_4(Current)
      end

feature {NONE}

   c_define_body is
      do
	 c_define_opening
	 if routine_body /= Void then
	    routine_body.compile_to_c
	 end
	 c_define_closing
      end

   compute_stupid_switch(run_time_set: RUN_TIME_SET) is
      do
         std_compute_stupid_switch(run_time_set)
      end

   update_tmp_jvm_descriptor is
      do
         routine_update_tmp_jvm_descriptor
      end

   side_effect_free_flag: BOOLEAN

   stupid_switch_comment: STRING is "SSFRF4"

end -- RUN_FEATURE_4


