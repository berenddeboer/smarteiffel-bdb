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
deferred class CALL_INFIX2
   --
   -- Root for CALL_INFIX_EQ and CALL_INFIX_NEQ.
   --

inherit
   CALL_INFIX redefine start_lookup_class, use_current, verify_scoop end

feature

   precedence: INTEGER is 6

   left_brackets: BOOLEAN is False

   start_lookup_class: BASE_CLASS is
      local
	 cn: CLASS_NAME
      once
	 create cn.unknown_position(as_boolean)
         Result := smart_eiffel.base_class(cn)
      end

   frozen result_type: E_TYPE is
      do
         Result := type_boolean
      end

   side_effect_free: BOOLEAN is
      do
	 Result := target.side_effect_free and then arg1.side_effect_free
      end
   
   frozen to_runnable(ct: E_TYPE): EXPRESSION is
      local
         copied: like Current
      do
	 if current_type = Void then
	    current_type := ct
	    runnable_target(ct)
	    arguments := runnable_arguments(ct)
	    Result := simplify_1
	    debug debug_info_update end
	    if nb_errors = 0 then
	       check_comparison(ct)
	    end
	 else
	    copied := twin
	    copied.with(target, feature_name, arguments)
	    Result := copied.to_runnable(ct)
	 end
      end

   frozen simplify_1_: EXPRESSION is
      local
	 ic1, ic2: INTEGER_CONSTANT; rc1, rc2: REAL_CONSTANT
      do
	 Result := simplify_with_boolean_constant
	 if Result = Void then
	    Result := simplify_with_character_constant
	 end
	 if Result /= Void then
	 elseif target.is_void then
	    Result := simplify_cmp_void(arg1)
	 elseif arg1.is_void then
	    Result := simplify_cmp_void(target)
	 else
	    ic1 ?= target
	    if ic1 = Void then
	       rc1 ?= target
	       if rc1 = Void then
		  Result := Current
	       else
		  rc2 ?= arg1
		  if rc2 = Void then
		     Result := Current
		  elseif rc1.to_string.is_equal(rc2.to_string) then
		     Result := e_true_e_false(operator.first = '=')
		  else
		     Result := e_true_e_false(operator.first = '/')
		  end
	       end
	    else
	       ic2 ?= arg1
	       if ic2 = Void then
		  Result := Current
	       elseif ic1.value_memory = ic2.value_memory then
		  Result := e_true_e_false(operator.first = '=')
	       else
		  Result := e_true_e_false(operator.first = '/')
	       end
	    end
	 end
      end
   
   frozen assertion_check(tag: CHARACTER) is
      do
         target.assertion_check(tag)
         arg1.assertion_check(tag)
      end

   frozen use_current: BOOLEAN is
      do
         Result := target.use_current or else arg1.use_current
      end

   frozen isa_dca_inline_argument: INTEGER is
      do
      end

   frozen dca_inline_argument(formal_arg_type: E_TYPE) is
      do
      end

   verify_scoop(allowed: FORMAL_ARG_LIST): BOOLEAN is
      do
         -- "=" and "/=" never can be guards; separate objects are accepted
         -- without being enclosed in a routine, because those features do not
         -- involve calling any message on the object.
         Result := False;
      end

feature {RUN_FEATURE_4}

   frozen dca_inline(formal_arg_type: E_TYPE) is
      do
         cpp.put_character('(')
         cpp.put_target_as_value
         cpp.put_character(')')
         if operator.first = '=' then
            cpp.put_string(fz_c_eq)
         else
            cpp.put_string(fz_c_neq)
         end
         cpp.put_character('(')
         arg1.dca_inline_argument(formal_arg_type)
         cpp.put_character(')')
      end

feature {RUN_FEATURE_3, RUN_FEATURE_4}

   finalize is
      do
      end

feature {CALL_INFIX2}

   frozen check_comparison(ct: E_TYPE) is
      local
         t1, t2: E_TYPE; do_warning: BOOLEAN; bcw1, bcw2: BASE_CLASS
      do
	 t1 := target.result_type
	 t2 := arg1.result_type
	 if t1.is_a(t2) then
	 else
	    error_handler.cancel
	    if t2.is_a(t1) then
	    else
	       if smart_eiffel.short_flag then
		  bcw1 := ct.base_class
		  bcw2 := feature_name.start_position.base_class
		  do_warning := bcw1 = bcw2
	       else
		  do_warning := True
	       end
	       error_handler.cancel
	       error_handler.add_position(feature_name.start_position)
	       if t1.is_expanded or else t2.is_expanded then
		  error_handler.append(
		     "Comparison not allowed (more details below).")
		  error_handler.print_as_error
		  error_handler.add_type(t1," cannot be compared with ")
		  error_handler.add_type(t2," (comparison not allowed).")
		  error_handler.print_as_fatal_error
	       elseif do_warning then
		  error_handler.append(
		     "Strange (or invalid ?) comparison of ")
		  error_handler.append(t1.run_time_mark)
		  error_handler.append(" with ")
		  error_handler.append(t2.run_time_mark)
		  error_handler.append(". (This will be always ")
		  if feature_name.to_string = as_eq then
		     error_handler.append("False")
		  else
		     error_handler.append("True")
		  end
		  error_handler.append(
	             ".) Note: the context of types interpretation (i.e. %
		     %the type of Current) is ")
		  error_handler.append(ct.run_time_mark)
		  error_handler.append(".")
		  error_handler.print_as_warning
	       end
	    end
	 end
      end

   afd_check_hook is
      local
	 t1, t2: E_TYPE
      do
	 t1 := target.result_type
	 t2 := arg1.result_type
	 if t1.is_bit then
	    if t2.is_bit then
	       bit_limitation(t1, t2)
	    end
	 end
      end
   
   bit_limitation(t1, t2: E_TYPE) is
      require
         t1.is_bit; t2.is_bit
      local
         b1, b2: TYPE_BIT
      do
         b1 ?= t1.run_type; b2 ?= t2.run_type
         if b1.nb /= b2.nb then
            error_handler.add_position(feature_name.start_position)
            error_handler.append("Comparison between ")
            error_handler.add_type(b1," and ")
            error_handler.add_type(b2,
            " is not yet implemented (you can work arround by %
            %doing an assignment in a local variable).")
            error_handler.print_as_fatal_error
         end
      end

   cmp_bit(equal_test: BOOLEAN; t: E_TYPE) is
      require
         t.is_bit
      local
         tb: TYPE_BIT
      do
	 tb ?= t
	 if tb.is_c_unsigned_ptr then
	    if equal_test then
	       cpp.put_character('!')
	    end
	    cpp.put_string(once "memcmp((")
	    target.mapping_c_target(t)
	    cpp.put_string(fz_20)
	    arg1.mapping_c_target(t)
	    cpp.put_string(fz_84)
	    cpp.put_integer(tb.id)
	    cpp.put_string(fz_13)
	 else
	    cpp.put_character('(')
	    target.compile_to_c
	    cpp.put_character(')')
	    if equal_test then
	       cpp.put_string(fz_c_eq)
	    else
	       cpp.put_string(fz_c_neq)
	    end
	    cpp.put_character('(')
	    arg1.compile_to_c
	    cpp.put_character(')')
	 end
      end

   cmp_user_expanded(equal_test: BOOLEAN; t: E_TYPE) is
      require
         t.is_user_expanded
      local
         mem_id: INTEGER
      do
	 if t.is_dummy_expanded then
            cpp.put_character('(')
            target.compile_to_c
            cpp.put_character(',')
            arg1.compile_to_c
            cpp.put_character(',')
            if equal_test then
               cpp.put_character('1')
            else
               cpp.put_character('0')
            end
            cpp.put_character(')')
         else
            mem_id := t.id
            if equal_test then
               cpp.put_character('!')
            end
            cpp.put_string(fz_se_cmpt)
            cpp.put_integer(mem_id)
            cpp.put_string(fz_17)
            target.compile_to_c
            cpp.put_string(fz_20)
            arg1.compile_to_c
            cpp.put_string(fz_13)
         end
      end

   cmp_basic_eiffel_expanded(equal_test: BOOLEAN; t1, t2: E_TYPE) is
      require
         t1.is_basic_eiffel_expanded
         t2.is_basic_eiffel_expanded
      local
         cast: STRING
      do
	 if t1.is_double or else t2.is_double then
	    cast := fz_43
	 elseif t1.is_real or else t2.is_real then
	    cast := fz_45
	 end
	 if cast /= Void then
	    cpp.put_string(cast)
	 end
	 cpp.put_character('(')
	 target.compile_to_c
	 if cast /= Void then
	    cpp.put_string(fz_13)
	 end
	 cpp.put_character(')')
	 if equal_test then
	    cpp.put_string(fz_c_eq)
	 else
	    cpp.put_string(fz_c_neq)
	 end
	 cpp.put_character('(')
	 if cast /= Void then
	    cpp.put_string(cast)
	 end
	 arg1.compile_to_c
	 cpp.put_character(')')
	 if cast /= Void then
	    cpp.put_string(fz_13)
	 end
      end

   cmp_basic_ref(equal_test: BOOLEAN) is
      do
	 if target.result_type.is_separate or else
	    arg1.result_type.is_separate
	  then
	    if not equal_test then
	       cpp.put_character('!')
	    end
	    cpp.put_string(once "scoop_cmp((T0*)(")
	    target.compile_to_c
	    cpp.put_string(once "),(T0*)(")
	    arg1.compile_to_c
	    cpp.put_string(once "))")
	 else
	    cpp.put_character('(')
	    target.compile_to_c
	    cpp.put_character(')')
	    if equal_test then
	       cpp.put_string(fz_c_eq)
	    else
	       cpp.put_string(fz_c_neq)
	    end
	    cpp.put_string(once "((void*)(")
	    arg1.compile_to_c
	    cpp.put_string(once "))")
	 end
      end

   is_manifest_array(e: EXPRESSION): BOOLEAN is
      local
	 manifest_array: MANIFEST_ARRAY
      do
	 manifest_array ?= e
	 Result := manifest_array /= Void
      end

   frozen make(lp: like target; operator_position: POSITION; rp: like arg1) is
      require
         lp /= Void
         not operator_position.is_unknown
         rp /= Void
      do
         target := lp
         create feature_name.infix_name(operator,operator_position)
         create arguments.make_1(rp)
      ensure
         target = lp
         start_position = operator_position
         arguments.first = rp
      end

   frozen with(t: like target; fn: like feature_name; a: like arguments) is
      require
         t /= Void
         fn /= Void
         a.count = 1
      do
         run_feature := Void
         current_type := Void
         target := t
         feature_name := fn
         arguments := a
      ensure
         target = t
         feature_name = fn
         arguments = a
      end

feature {CALL_INFIX2_VISITOR}

   accept(visitor: CALL_INFIX2_VISITOR) is
      deferred
      end

feature {NONE}

   e_true_e_false(boolean: BOOLEAN): EXPRESSION is
      do
	 if boolean then
	    create {E_TRUE} Result.make(feature_name.start_position)
	 else
	    create {E_FALSE} Result.make(feature_name.start_position)
	 end
      end
   
   c2c_exp_ref(exp: EXPRESSION; ref: EXPRESSION; eq_flag: BOOLEAN) is
	 -- Generic (= /=) implementation of `compile_to_c' for an expanded
	 -- expression compared with some reference expression.
      require
	 exp.result_type.is_expanded
	 ref.result_type.is_reference
      local
	 type_reference: TYPE_REFERENCE; exp_type: E_TYPE; skip_tag: BOOLEAN
      do
	 if ref.is_void then
	    cpp.put_character('(')
	    cpp.put_string(once "/*exp-void-cmp*/")
	    if not exp.side_effect_free then
	       exp.compile_to_c
	       cpp.put_character(',')
	    end
	    if eq_flag then
	       cpp.put_character('0')
	    else
	       cpp.put_character('1')
	    end
	    cpp.put_character(')')
	 else
	    type_reference ?= ref.result_type.run_type
	    if type_reference = Void then
	       cpp.put_character('(')
	       ref.compile_to_c
	       cpp.put_character(',')
	       exp.compile_to_c
	       cpp.put_character(',')
	       if eq_flag then
		  cpp.put_character('0')
	       else
		  cpp.put_character('1')
	       end
	       cpp.put_character(')')
	    else
	       exp_type := exp.result_type.run_type
	       if exp_type.is_basic_eiffel_expanded then
		  cpp.put_character('(')
		  exp.compile_to_c
		  cpp.put_character(')')
		  if eq_flag then
		     cpp.put_string(fz_c_eq)
		  else
		     cpp.put_string(fz_c_neq)
		  end
		  cpp.put_string(once "((")
		  ref.mapping_c_target(type_reference)
		  cpp.put_string(once ")->_item)")
	       else
		  if eq_flag then
		     cpp.put_character('!')
		  end
		  cpp.put_string(once "memcmp(&(")
		  exp.compile_to_c
		  cpp.put_string(once "),")
		  if type_reference.run_class.is_tagged then
		     skip_tag := True
		     cpp.put_string(once "((Tid*)(")
		  end
		  ref.compile_to_c
		  if skip_tag then
		     cpp.put_string(once "))+1")
		  end
		  cpp.put_string(once ",sizeof(T")
		  cpp.put_integer(exp_type.id)
		  cpp.put_string(once "))")
	       end
	    end
	 end
      end

   simplify_with_boolean_constant: EXPRESSION is
	 -- To simplify comparison with True / False.
      local
	 bc1, bc2: BOOLEAN_CONSTANT
      do
	 bc1 ?= target
	 if bc1 /= Void then
	    bc2 ?= arg1
	    if operator.first = '=' then
	       if bc1.value then
		  Result := arg1
	       end
	    end
	 else
	    bc1 ?= arg1
	    if bc1 /= Void then
	       bc2 ?= target
	       if operator.first = '=' then
		  if bc1.value then
		     Result := target
		  end
	       end
	    end
	 end
	 if Result = Void and then bc1 /= Void and then bc2 /= Void then
	    if operator.first = '=' then
	       Result := e_true_e_false(bc1.value = bc2.value)
	    else
	       Result := e_true_e_false(bc1.value /= bc2.value)
	    end
	 end
      end

   simplify_with_character_constant: EXPRESSION is
      local
	 cc1, cc2: CHARACTER_CONSTANT
      do
	 cc1 ?= target
	 if cc1 /= Void then
	    cc2 ?= arg1
	    if cc2 /= Void then
	       if operator.first = '=' then
		  Result := e_true_e_false(cc1.value = cc2.value)
	       else
		  Result := e_true_e_false(cc1.value /= cc2.value)
	       end
	    end
	 end
      end
   
   simplify_cmp_void(expression: EXPRESSION): EXPRESSION is
      do
	 if expression.is_void then
	    if operator.first = '=' then
	       create {E_TRUE} Result.make(feature_name.start_position)
	    else
	       create {E_FALSE} Result.make(feature_name.start_position)
	    end	    
	 elseif ((smart_eiffel.status > 3
		  and then
		  expression.result_type.is_expanded
		  and then
		  expression.side_effect_free)
		 or else
		 expression.is_current
		 or else
		 expression.is_manifest_string
		 or else
		 is_manifest_array(expression))
	  then
	    if operator.first = '=' then
	       create {E_FALSE} Result.make(feature_name.start_position)
	    else
	       create {E_TRUE} Result.make(feature_name.start_position)
	    end
	 else
	    Result := Current
	 end
      end

invariant

   run_feature = Void

end -- CALL_INFIX2
