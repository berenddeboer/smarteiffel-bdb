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
class NATIVE_SMART_EIFFEL

inherit NATIVE

creation make, default_create

feature

   need_prototype: BOOLEAN is False

   stupid_switch_function(run_time_set: RUN_TIME_SET; name: STRING)
      : BOOLEAN is
      do
	 if name.has_prefix(fz_basic_) then
	    Result := True
	 elseif as_character_bits = name or else
            as_generating_type = name or else
            as_generator = name or else
            as_to_pointer = name or else
	    as_item = name
          then
            Result := True
         end
      end

   stupid_switch_procedure(run_time_set: RUN_TIME_SET; name: STRING)
      : BOOLEAN is
      do
	 if name.has_prefix(fz_basic_) then
	    Result := True
	 elseif as_call = name then
	    Result := True
         end
      end

   notify_external_assignments(args: FORMAL_ARG_LIST; rt: E_TYPE) is
      do
      end

   c_define_procedure(rf7: RUN_FEATURE_7; bcn, name: STRING) is
      local
	 ct: E_TYPE
      do
         if as_bit_n = bcn then
            c_define_procedure_bit(rf7,name)
	 elseif as_copy = name or else as_standard_copy = name then
	    ct := rf7.current_type
	    if ct.is_reference and then ace.no_check then
	       rf7.c_define_with_body(once "memcpy(C,a1,sizeof(*C));%N")
	    elseif ct.is_user_expanded then
	       if ct.is_dummy_expanded then
		  rf7.c_define_with_body(once "/*No fields.*/%N")
	       else
		  rf7.c_define_with_body(once "memcpy(C,&a1,sizeof(*C));%N")
	       end
	    end
	 end
      end

   c_mapping_procedure(rf7: RUN_FEATURE_7; bcn, name: STRING) is
      local
         ct: E_TYPE; cbd: BOOLEAN
      do
	 ct := rf7.current_type
	 if name.has_prefix(fz_basic_) then
            cbd := cpp.target_cannot_be_dropped
            if cbd then cpp.put_character(',') end
            cpp.put_string(name)
	    if rf7.arguments /= Void then
	       cpp.put_character('(')
	       cpp.put_arguments
	       cpp.put_character(')')
	    end
	    if cbd then cpp.put_character(')') end
	    cpp.put_string(fz_00)
	 elseif as_copy = name or else as_standard_copy = name then
	    if ct.is_reference then
	       if ace.boost then
		  cpp.put_string(once "*((T"); cpp.put_integer(ct.id)
		  cpp.put_string(once "*)(")
		  cpp.put_target_as_value
		  cpp.put_string(once "))=*((T"); cpp.put_integer(ct.id)
		  cpp.put_string(once "*)(")
		  cpp.put_ith_argument(1)
		  cpp.put_string(once "));%N")
	       else
		  rf7.default_mapping_procedure
	       end
	    elseif ct.is_basic_eiffel_expanded then
	       cpp.put_target_as_value
	       cpp.put_string(fz_00)
	       cpp.put_ith_argument(1)
	       cpp.put_string(fz_00)
	    else
	       rf7.default_mapping_procedure
            end
         elseif as_print_run_time_stack = name then
            if smart_eiffel.scoop then
               cpp.put_string(once "se_current_subsystem_thread()->vft.print_run_time_stack(se_current_subsystem_thread());%N")
            else
               cpp.put_string(once "se_print_run_time_stack();%N")
            end
         elseif as_print_all_run_time_stacks = name then
            cpp.put_string(once "se_print_run_time_stack();%N")
         elseif as_die_with_code = name then
            if cpp.target_cannot_be_dropped then
               cpp.put_string(fz_14)
            end
            cpp.put_string(once "exit(")
            cpp.put_ith_argument(1)
            cpp.put_string(fz_14)
         elseif as_native_array = bcn then
            c_mapping_native_array_procedure(rf7,name)
         elseif as_bit_n = bcn then
            c_mapping_bit_procedure(rf7,name)
         elseif is_integer(ct) then
            c_mapping_integer_procedure(rf7,name)
         elseif as_raise_exception = name then
            cpp.put_string(once "internal_exception_handler(")
            cpp.put_ith_argument(1)
            cpp.put_string(fz_14)
	 elseif as_full_collect = name then
	    if not gc_handler.is_off then
	       cpp.put_string(once "gc_start();%N")
	    end
         elseif as_c_inline_c = name then
            cpp.put_c_inline_c
         elseif as_c_inline_h = name then
            cpp.put_c_inline_h
         elseif as_trace_switch = name then
            cpp.put_trace_switch
         elseif as_sedb_breakpoint = name then
            cpp.put_sedb_breakpoint
	 elseif as_collection_off = name then
	    if not gc_handler.is_off then
	       cpp.put_string(once "gc_is_off=1;%N")
	    end
	 elseif as_collection_on = name then
	    if not gc_handler.is_off then
	       cpp.put_string(fz_48)
	    end
	 elseif as_put_16_be = name or else 
	    as_put_16_le = name or else 
	    as_put_16_ne = name then
	    cpp.put_string(once "*((int16_t*)(")
            cpp.put_ith_argument(1)
	    cpp.put_string(once "+")
            cpp.put_ith_argument(3)
	    cpp.put_string(once "))=")
	    if as_put_16_ne /= name then
	       if as_put_16_be = name then
		  cpp.put_string(once "%N#if BYTE_ORDER == LITTLE_ENDIAN%N")
	       else
		  cpp.put_string(once "%N#if BYTE_ORDER == BIG_ENDIAN%N")
	       end
	       cpp.put_character('(')
	       cpp.put_ith_argument(2)
	       cpp.put_string(once "<<8)|((uint16_t)")
	       cpp.put_ith_argument(2)
	       cpp.put_string(once ">>8);%N")
	       cpp.put_string(once "#else%N")
	    end
            cpp.put_ith_argument(2)
	    cpp.put_string(once ";%N")
	    if as_put_16_ne /= name then
	       cpp.put_string(once "#endif%N")
	    end
	 else
	    check False end
         end
      end

   scoop_define_function_body(rf8: RUN_FEATURE_8; bcn, name: STRING) is
         -- Produce C code to define the corresponding `rf8' body.
	 -- (Or nothing when the code is inlined.)
      require
         rf8.base_feature.first_name.to_string = name
         rf8.base_feature.base_class.name.to_string = bcn
	 rf8.arguments.has_like_current
	 rf8.current_type.is_separate
      do
	 if as_is_equal = name or else as_standard_is_equal = name then
	    cpp.put_string(
               once "[
                  R=((C->id==a1->id)?
                  !memcmp(C->ref,((sT0*)a1)->ref,sizeof(*(C->ref)))
                  :0);
                     ]")
	 elseif as_is_deep_equal = name then
	    body.clear
	    rf8.run_class.is_deep_equal_in(body)
	    cpp.put_string(body)
	 end
      end

   scoop_define_procedure_body(rf7: RUN_FEATURE_7; bcn, name: STRING) is
         -- Produce C code to define the corresponding `rf7' body.
	 -- (Or nothing when the code is inlined.)
      require
         rf7.base_feature.first_name.to_string = name
         rf7.base_feature.base_class.name.to_string = bcn
	 rf7.arguments.has_like_current
	 rf7.current_type.is_separate
      local
         t: E_TYPE
      do
	 if as_copy = name or else as_standard_copy = name then
	    cpp.put_string(once "*(C->ref)=*((T")
	    cpp.put_integer(t.id)
	    cpp.put_string(fz_70)
	    cpp.put_ith_argument(1)
	    cpp.put_string(once ")->ref);%N")
	 end
      end

   c_define_function(rf8: RUN_FEATURE_8; bcn, name: STRING) is
      local
         elt_type: E_TYPE; ct: E_TYPE; rc: RUN_CLASS
         rf: RUN_FEATURE; rf7: RUN_FEATURE_7; ref_type: TYPE_REFERENCE
      do
	 ct := rf8.current_type
	 ref_type ?= ct
	 rc := rf8.run_class
         if as_bit_n = bcn then
            c_define_function_bit(rf8,name)
	 elseif as_is_equal = name or else as_standard_is_equal = name then
	    rc := rf8.run_class
	    if ct.is_basic_eiffel_expanded then
	    elseif ct.is_native_array then
	    elseif ct.is_bit then
	    elseif ref_type /= Void and then
	       ref_type.expanded_type.is_basic_eiffel_expanded
	     then
	       body.copy(once "R=(T6)((C->_item)==(((T")
	       ref_type.id.append_in(body)
	       body.append(once "*)a1)->_item));")
	       rf8.c_define_with_body(body)
	    elseif rc.is_tagged then
	       rf8.c_define_with_body(
                  once "R=(T6)((C->id==a1->id)?!memcmp(C,a1,sizeof(*C)):0);")
	    elseif rc.writable_attributes = Void then
	       if ace.boost then
	       else
		  rf8.c_define_with_body(fz_92)
	       end
	    elseif ace.boost then
	    else
	       rf8.c_define_with_body(once "R=(T6)!memcmp(C,&a1,sizeof(*C));")
	    end
	 elseif as_standard_twin = name then
	    c_define_standard_twin(rf8,rf8.current_type)
	 elseif as_twin = name then
	    rf := rc.get_copy
	    rf7 ?= rf
	    if rf7 /= Void then
	       c_define_standard_twin(rf8,ct)
	    else
	       c_define_twin(rf8,ct,rc,rf)
	    end
	 elseif as_deep_twin = name then
	    if ct.is_basic_eiffel_expanded or else ct.is_dummy_expanded then
	       rf8.c_define_with_body(once "R=C;%N")
	    elseif ct.is_native_array then
	       error_handler.add_type(ct,fz_dtideena)
	       error_handler.print_as_warning
	       if ace.boost then
		  rf8.c_define_with_body(once "R=NULL")
	       else
		  rf8.c_define_with_body(
                     once "error0(%"Invalid deep_twin.%",NULL);")
	       end
	    else
	       body.clear
	       rf8.run_class.deep_twin_in(body)
	       rf8.c_define_with_body(body)
	    end
	 elseif as_is_deep_equal = name then
	    if ct.is_basic_eiffel_expanded then
	       rf8.c_define_with_body(once "R=(T6)(C==a1);%N")
	    elseif ct.is_dummy_expanded then
	       rf8.c_define_with_body(once "R=1;%N")
	    elseif ct.is_native_array then
	       error_handler.add_type(ct,fz_dtideena)
	       error_handler.print_as_warning
	       if ace.boost then
		  rf8.c_define_with_body(once "R=0")
	       else
		  rf8.c_define_with_body(
                     once "error0(%"Invalid is_deep_equal.%",NULL);")
	       end
	    else
	       body.clear
	       rf8.run_class.is_deep_equal_in(body)
	       rf8.c_define_with_body(body)
            end
         elseif as_native_array = bcn then
            if as_calloc = name then
               elt_type := ct.generic_list.item(1).run_type
               if expanded_initializer(elt_type) then
                  body.clear
                  body.append(once "R=")
                  if gc_handler.is_off then
                     body.append(once "se_malloc(sizeof(T")
                     elt_type.id.append_in(body)
                     body.append(once ")*")
                  else
                     body.append(once "(void*)new")
                     ct.id.append_in(body)
                     body.extend('(')
                  end
                  body.append(once "a1);%Nr")
                  ct.id.append_in(body)
                  body.append(once "clear_all(")
                  if ace.no_check then
                     body.append(fz_85)
                  end
                  body.append(once "R,a1-1);%N")
                  rf8.c_define_with_body(body)
               end
            end
         elseif is_integer(ct) then
	    if as_to_integer_8 = name then
	       c_define_integer_to_integer(8, rf8)
	    elseif as_to_integer_16 = name then
	       c_define_integer_to_integer(16, rf8)
	    elseif as_to_integer_32 = name then
	       c_define_integer_to_integer(32, rf8)
	    end
         end
      end

   c_mapping_function(rf8: RUN_FEATURE_8; bcn, name: STRING) is
      local
         cbd, cda: BOOLEAN; ct: E_TYPE; rc: RUN_CLASS; rf: RUN_FEATURE
	 rf7: RUN_FEATURE_7; basic_eq: BOOLEAN; type_bit: TYPE_BIT
      do
	 ct := rf8.current_type
	 if name.has_prefix(fz_basic_) then
            cbd := cpp.target_cannot_be_dropped
            if cbd then cpp.put_character(',') end
            cpp.put_string(name)
            if rf8.arguments /= Void then
	       cpp.put_character('(')
               cpp.put_arguments
	       cpp.put_character(')')
            end
            if cbd then cpp.put_character(')') end
         elseif as_platform = bcn then
            cbd := cpp.target_cannot_be_dropped
            if cbd then cpp.put_character(',') end
            tmp_string.copy(once "EIF_")
            tmp_string.append(name)
            tmp_string.to_upper
            cpp.put_string(tmp_string)
	    if cbd then cpp.put_character(')') end
	 elseif as_generating_type = name then
	    cpp.put_generating_type(ct)
	 elseif as_generator = name then
	    cpp.put_generator(ct)
	 elseif as_same_dynamic_type = name then
	    cpp.put_comment(as_same_dynamic_type)
	    if ct.is_reference and then ct.run_class.is_tagged then
	       cpp.put_string(once "((")
	       if ace.no_check then cpp.put_string(once "(vc(") end
	       cpp.put_string(once "((T0*)(")
	       cpp.put_target_as_value
	       cpp.put_string(once "))")
	       if ace.no_check then cpp.put_string(once ",0))") end
	       cpp.put_string(once "->id)==(")
	       if ace.no_check then cpp.put_string(once "(vc(") end
	       cpp.put_string(once "((T0*)(")
	       cpp.put_ith_argument(1)
	       cpp.put_string(once "))")
	       if ace.no_check then cpp.put_string(once ",0))") end
	       cpp.put_string(once "->id))")
	    else -- Statically known:
	       cda := cpp.cannot_drop_all
	       if cda then cpp.put_character(',') end
	       cpp.put_character('1')
	       if cda then cpp.put_character(')') end
	    end
	 elseif as_to_pointer = name then
	    cpp.put_string(once "((void*)(")
	    cpp.put_target_as_value
	    if ct.is_expanded and then not ct.is_native_array then
	       error_handler.add_position(rf8.start_position)
	       error_handler.append(once "Bad usage of GENERAL.to_pointer.")
	       cpp.target_position_in_error_handler
	       error_handler.print_as_warning
	       cpp.put_string(once ",NULL")
	    end
	    cpp.put_string(fz_13)
	 elseif as_object_size = name then
	    cpp.put_object_size(ct)
	 elseif as_is_equal = name or else as_standard_is_equal = name then
	    rc := rf8.run_class
	    if ct.is_basic_eiffel_expanded then
	       basic_eq := True
	    elseif ct.is_native_array then
	       basic_eq := True
	    elseif ct.is_bit then
	       type_bit ?= ct
	       basic_eq := not type_bit.is_c_unsigned_ptr
	    end
	    if basic_eq then
	       cpp.put_character('(')
	       exp_or_ref(ct, 0)
	       cpp.put_character(')')
	       cpp.put_string(fz_c_eq)
	       cpp.put_character('(')
	       exp_or_ref(ct, 1)
	       cpp.put_character(')')
	    elseif rc.is_tagged then
	       rf8.default_mapping_function
	    elseif rc.writable_attributes = Void then
	       if ace.boost then
		  cbd := cpp.cannot_drop_all
		  if cbd then
		     cpp.put_character(',')
		  end
		  cpp.put_character('1')
		  if cbd then
		     cpp.put_character(')')
		  end
	       else
		  rf8.default_mapping_function
	       end
	    elseif ace.boost then
	       cpp.put_string(once "!memcmp(")
	       cpp.put_target_as_target
	       cpp.put_character(',')
               if ct.is_user_expanded then
		  cpp.put_character('&')
	       end
	       cpp.put_character('(')
	       cpp.put_ith_argument(1)
	       cpp.put_string(fz_84)
	       cpp.put_integer(rc.id)
	       cpp.put_string(fz_13)
	    else
	       rf8.default_mapping_function
	    end
	 elseif as_standard_twin = name then
	    c_mapping_standard_twin(rf8, ct)
	 elseif as_twin = name then
	    rc := rf8.run_class
	    rf := rc.get_copy
	    rf7 ?= rf
	    if rf7 /= Void then
	       c_mapping_standard_twin(rf8,ct)
	    else
	       rf8.default_mapping_function
	    end
	 elseif as_deep_twin = name then
	    if ct.is_basic_eiffel_expanded then
	       cpp.put_target_as_target
	    elseif ct.is_user_expanded then
	       rf8.default_mapping_function
	    else
	       cpp.put_string(
                  once "(se_deep_twin_start(),se_deep_twin_trats(")
	       rf8.default_mapping_function
	       cpp.put_string(fz_13)
	    end
	 elseif as_is_deep_equal = name then
	    rf8.default_mapping_function
	 elseif as_is_basic_expanded_type = name then
	    cbd := cpp.cannot_drop_all
	    if cbd then
	       cpp.put_character(',')
	    end
	    if ct.is_basic_eiffel_expanded then
	       cpp.put_character('1')
	    else
	       cpp.put_character('0')
	    end
	    if cbd then
	       cpp.put_character(')')
	    end
	 elseif as_is_expanded_type = name then
	    cbd := cpp.cannot_drop_all
	    if cbd then
	       cpp.put_character(',')
	    end
	    if ct.is_expanded then
	       cpp.put_character('1')
	    else
	       cpp.put_character('0')
	    end
	    if cbd then
	       cpp.put_character(')')
	    end
	 elseif as_se_argc = name then
	    cpp.put_string(as_se_argc)
	 elseif as_se_argv = name then
	    cpp.put_string(once "((T0*)se_string(se_argv[_i]))")
	 elseif as_native_array = bcn then
	    c_mapping_native_array_function(rf8,name)
	 elseif as_real = bcn or else as_double = bcn then
	    c_mapping_real_double(ct, name, rf8.arg_count)
	 elseif as_boolean = bcn then
	    if as_implies = name then
	       cpp.put_string(once "(T6)((!(")
	       exp_or_ref(ct, 0)
	       cpp.put_string(once "))||(")
	       exp_or_ref(ct, 1)
	       cpp.put_string(once "))")
	    else
	       check rf8.arg_count = 1 end
	       cpp.put_string(once "(T6)((")
	       exp_or_ref(ct, 0)
	       if as_or_else = name then
		  cpp.put_string(once ")||(")
	       else
		  check as_and_then = name end
		  cpp.put_string(fz_39)
	       end
	       exp_or_ref(ct, 1)
	       cpp.put_string(once "))")
	    end
	 elseif as_character = bcn then
	    cpp.put_string(once "T3")
	    cpp.put_string(name)
	    cpp.put_character('(')
	    exp_or_ref(ct, 0)
	    cpp.put_character(')')
	 elseif as_pointer = bcn then
	    check as_is_not_null = name end
	    cpp.put_string(once "(NULL!=")
	    exp_or_ref(ct, 0)
	    cpp.put_character(')')
	 elseif as_bit_n = bcn then
	    c_mapping_bit_function(rf8,name)
	 elseif as_pointer_size = name then
	    cpp.put_string(fz_sizeof)
	    cpp.put_character('(')
	    cpp.put_string(fz_t0_star)
	    cpp.put_character(')')
	 elseif as_exception = name then
	    cpp.put_string(once "internal_exception_number")
	 elseif as_signal_number = name then
	    cpp.put_string(once "signal_exception_number")
	 elseif as_collecting = name then
	    if gc_handler.is_off then
	       cpp.put_character('0')
	    else
	       cpp.put_string(once "!gc_is_off")
	    end
	 elseif as_collector_counter = name then
	    if gc_handler.is_off then
	       cpp.put_string(once "(-1)")
	    else
	       cpp.put_string(as_collector_counter)
	    end
	 elseif is_integer(ct) then
	    c_mapping_integer_function(rf8,name)
	 elseif as_as_16_ne = name then
	    cpp.put_string(once "%N#if BYTE_ORDER == LITTLE_ENDIAN%N(")
	    cpp.put_ith_argument(2)
	    cpp.put_string(once "<<8)|((uint16_t)")
	    cpp.put_ith_argument(1)
	    cpp.put_string(once ")%N#else%N(")
	    cpp.put_ith_argument(1)
	    cpp.put_string(once "<<8)|((uint16_t)")
	    cpp.put_ith_argument(2)
	    cpp.put_string(once ")%N#endif%N")
	 else
	    check False end
	 end
      end

   jvm_add_method_for_function(rf8: RUN_FEATURE_8; bcn, name: STRING) is
      local
         ct: E_TYPE; rc: RUN_CLASS; rf: RUN_FEATURE; rf7: RUN_FEATURE_7
         writable_attribute: WRITABLE_ATTRIBUTE; rf2: RUN_FEATURE_2
         feature_name: FEATURE_NAME; feature_name_list: FEATURE_NAME_LIST
         t_pointer: TYPE_POINTER; t_integer: TYPE_INTEGER
         t_native_array: TYPE_NATIVE_ARRAY
      do
	 if as_twin = name then
	    ct := rf8.current_type
	    rc := rf8.run_class
	    rf := rc.get_copy
	    rf7 ?= rf
	    if rf7 = Void then
	       jvm.add_method(rf8)
	    end
	 elseif as_generating_type = name then
	    jvm.add_method(rf8)
	 elseif as_generator = name then
	    jvm.add_method(rf8)
	 elseif bcn = as_native_array then
	 elseif as_item = name then
	    -- creation of agent class, including attribute definitions
	    if not jvm.has_method_name( as_item ) then
	       jvm.add_method(rf8)
	       create feature_name.simple_feature_name( as_target, rf8.start_position )
	       create feature_name_list.make_1( feature_name )
	       create t_pointer.make( rf8.start_position)
	       create writable_attribute.make( feature_name_list, t_pointer )
	       rf2 := writable_attribute.to_run_feature( t_pointer, feature_name )
	       jvm.add_field( rf2 )
	       create feature_name.simple_feature_name( as_arguments, rf8.start_position )
	       create feature_name_list.make_1( feature_name )
	       create t_native_array.make( rf8.start_position, t_pointer)
	       create writable_attribute.make( feature_name_list, t_native_array )
	       rf2 := writable_attribute.to_run_feature( t_pointer, feature_name )
	       jvm.add_field( rf2 )
	       create feature_name.simple_feature_name( as_open_arguments, rf8.start_position )
	       create feature_name_list.make_1( feature_name )
	       create t_native_array.make( rf8.start_position, t_pointer)
	       create writable_attribute.make( feature_name_list, t_native_array )
	       rf2 := writable_attribute.to_run_feature( t_pointer, feature_name )
	       jvm.add_field( rf2 )
	       create feature_name.simple_feature_name( as_open_argument_indices, rf8.start_position )
	       create feature_name_list.make_1( feature_name )
	       create t_integer.integer( rf8.start_position )
	       create t_native_array.make( rf8.start_position, t_integer)
	       create writable_attribute.make( feature_name_list, t_native_array )
	       rf2 := writable_attribute.to_run_feature( t_pointer, feature_name )
	       jvm.add_field( rf2 )
	       create feature_name.simple_feature_name( as_last_result, rf8.start_position )
	       create feature_name_list.make_1( feature_name )
	       create writable_attribute.make( feature_name_list, t_pointer )
	       rf2 := writable_attribute.to_run_feature( t_pointer, feature_name )
	       jvm.add_field( rf2 )
	       create feature_name.simple_feature_name( as_method, rf8.start_position )
	       create feature_name_list.make_1( feature_name )
	       create writable_attribute.make( feature_name_list, t_pointer )
	       rf2 := writable_attribute.to_run_feature( t_pointer, feature_name )
	       jvm.add_field( rf2 )
	    end
         end
      end

   jvm_define_function(rf8: RUN_FEATURE_8; bcn, name: STRING) is
      local
         ct: E_TYPE; rc: RUN_CLASS; rf: RUN_FEATURE; rf7: RUN_FEATURE_7
         rc_idx, field_idx, point1: INTEGER; cp: like constant_pool
         ca: like code_attribute; index_args: INTEGER
         t_pointer: TYPE_POINTER
      do
         cp := constant_pool
         ca := code_attribute
	 if as_twin = name then
	    ct := rf8.current_type
	    rc := rf8.run_class
	    rf := rc.get_copy
	    rf7 ?= rf
	    if rf7 /= Void then
	    else
	       jvm_define_twin(rf8,rc,rf)
	    end
	 elseif as_generating_type = name then
	    rf8.jvm_opening
	    ct := rf8.current_type
	    rc := rf8.run_class
	    rc_idx := rc.jvm_constant_pool_index
	    field_idx := cp.idx_fieldref_generating_type(rc_idx)
	    ca.opcode_getstatic(field_idx,1)
	    ca.opcode_dup
	    point1 := ca.opcode_ifnonnull
	    ca.opcode_pop
	    ca.opcode_push_manifest_string(ct.run_time_mark)
	    ca.opcode_dup
	    ca.opcode_putstatic(field_idx,-1)
	    ca.resolve_u2_branch(point1)
	    rf8.jvm_closing_fast
	 elseif as_generator = name then
	    rf8.jvm_opening
	    ct := rf8.current_type
	    rc := rf8.run_class
	    rc_idx := rc.jvm_constant_pool_index
	    field_idx := cp.idx_fieldref_generator(rc_idx)
	    ca.opcode_getstatic(field_idx,1)
	    ca.opcode_dup
	    point1 := ca.opcode_ifnonnull
	    ca.opcode_pop
	    ca.opcode_push_manifest_string(ct.base_class_name.to_string)
	    ca.opcode_dup
	    ca.opcode_putstatic(field_idx,-1)
	    ca.resolve_u2_branch(point1)
	    rf8.jvm_closing_fast
	 elseif as_function = bcn then
            if as_call = name then
               create t_pointer.make( rf8.start_position)
               rf8.jvm_opening
               index_args := code_attribute.extra_local( t_pointer )
               code_attribute.opcode_iconst_1
               code_attribute.opcode_pop
               rf8.jvm_closing
            end
         end
      end

   jvm_mapping_function(rf8: RUN_FEATURE_8; bcn, name: STRING) is
      local
         ct: E_TYPE; rc: RUN_CLASS; rf: RUN_FEATURE; rf7: RUN_FEATURE_7
         point1, point2, space, idx: INTEGER; cp: like constant_pool
         ca: like code_attribute
      do
	 ct := rf8.current_type
         ca := code_attribute
         cp := constant_pool
	 if name.has_prefix(fz_basic_) then
	    jvm.drop_target
            jvm_smart_eiffel_runtime(name,rf8)
         elseif as_to_pointer = name then
            jvm.push_target
         elseif is_integer(ct) then
            jvm_mapping_integer_function(rf8,name)
         elseif as_real = bcn then
            jvm_mapping_real_function(rf8,name)
         elseif as_double = bcn then
            jvm_mapping_double_function(rf8,name)
         elseif as_native_array = bcn then
            jvm_mapping_native_array_function(rf8,name)
         elseif as_character = bcn then
            if as_code = name then
               jvm.push_target
               ca.opcode_dup
               point1 := ca.opcode_ifge
               ca.opcode_sipush(255)
               ca.opcode_iand
               ca.resolve_u2_branch(point1)
            elseif as_to_integer = name then
               jvm.push_target
            else
               check
                  as_to_bit = name
               end
               jvm_int_to_bit(rf8.result_type,8)
            end
         elseif as_is_not_null = name then
            jvm.push_target
            point1 := ca.opcode_ifnonnull
            ca.opcode_iconst_0
            point2 := ca.opcode_goto
            ca.resolve_u2_branch(point1)
            ca.opcode_iconst_1
            ca.resolve_u2_branch(point2)
         elseif as_implies = name then
            jvm.push_target
            point1 := ca.opcode_ifeq
            space := jvm.push_ith_argument(1)
            point2 := ca.opcode_goto
            ca.resolve_u2_branch(point1)
            ca.opcode_iconst_1
            ca.resolve_u2_branch(point2)
         elseif as_generating_type = name then
	    rf8.routine_mapping_jvm
	 elseif as_generator = name then
	    rf8.routine_mapping_jvm
	 elseif as_to_pointer = name then
	    fe_nyi(rf8)
	 elseif as_object_size = name then
	    jvm.drop_target
	    jvm_object_size(ct)
	 elseif as_is_equal = name or else as_standard_is_equal = name then
	    jvm.push_target
	    space := jvm.push_ith_argument(1)
	    rf8.current_type.jvm_standard_is_equal
	 elseif as_standard_twin = name then
	    jvm_standard_twin(rf8.current_type)
	 elseif as_twin = name then
	    rc := rf8.run_class
	    rf := rc.get_copy
	    rf7 ?= rf
	    if rf7 /= Void then
	       jvm_standard_twin(ct)
	    else
	       rf8.routine_mapping_jvm
	    end
	 elseif as_is_basic_expanded_type = name then
	    jvm.drop_target
	    if rf8.current_type.is_basic_eiffel_expanded then
	       ca.opcode_iconst_1
	    else
	       ca.opcode_iconst_0
	    end
	 elseif as_is_expanded_type = name then
	    jvm.drop_target
	    if rf8.current_type.is_expanded then
	       ca.opcode_iconst_1
	    else
	       ca.opcode_iconst_0
	    end
	 elseif as_se_argc = name then
	    jvm.push_se_argc
	 elseif as_se_argv = name then
	    jvm.push_se_argv
	 elseif as_platform = bcn then
            jvm.drop_target
            if as_character_bits = name then
               ca.opcode_bipush(8)
            elseif as_integer_bits = name then
               ca.opcode_bipush(32)
            elseif as_boolean_bits = name then
               ca.opcode_bipush(32)
            elseif as_real_bits = name then
               ca.opcode_bipush(32)
            elseif as_double_bits = name then
               ca.opcode_bipush(64)
            elseif as_pointer_bits = name then
               ca.opcode_bipush(32)
            elseif as_minimum_character_code = name then
               ca.opcode_iconst_i(0)
            elseif as_minimum_double = name then
               idx := cp.idx_fieldref3(fz_java_lang_double,
				       fz_max_value,fz_77)
               ca.opcode_getstatic(idx,2)
               ca.opcode_dneg
            elseif as_minimum_real = name then
               idx := cp.idx_fieldref3(fz_java_lang_float,fz_max_value,fz_78)
               ca.opcode_getstatic(idx,1)
               ca.opcode_fneg
            elseif as_maximum_character_code = name then
               ca.opcode_sipush(255)
            elseif as_maximum_double = name then
               idx := cp.idx_fieldref3(fz_java_lang_double,fz_max_value,fz_77)
               ca.opcode_getstatic(idx,2)
	    end
         elseif as_pointer_size = name then
            ca.opcode_bipush(32)
         elseif as_bit_n = bcn then
            jvm_mapping_bit_function(rf8,name)
         elseif as_item = name then
            jvm.push_target
            rc := rf8.run_class
            idx := rc.jvm_constant_pool_index
            idx := cp.idx_fieldref4(idx,as_item,fz_a9)
            ca.opcode_getfield(idx,0)
         elseif as_exception = name then
            ca.runtime_internal_exception_number
         elseif as_signal_number = name then
	 else
            fe_nyi(rf8)
	 end
      end

   jvm_add_method_for_procedure(rf7: RUN_FEATURE_7; bcn, name: STRING) is
      local
         writable_attribute: WRITABLE_ATTRIBUTE
         rf2: RUN_FEATURE_2
         feature_name: FEATURE_NAME
         feature_name_list: FEATURE_NAME_LIST
         t_pointer: TYPE_POINTER
         t_integer: TYPE_INTEGER
         t_native_array: TYPE_NATIVE_ARRAY
      do

         if as_procedure = bcn or as_routine = bcn then
            if as_call = name then -- creation of agent class, including attribute definitions

               if jvm.has_method_name( as_call ) = False then
                  jvm.add_method(rf7)
                  create feature_name.simple_feature_name( as_target, rf7.start_position )
                  create feature_name_list.make_1( feature_name )
                  create t_pointer.make( rf7.start_position)
                  create writable_attribute.make( feature_name_list, t_pointer )
                  rf2 := writable_attribute.to_run_feature( t_pointer, feature_name )
                  jvm.add_field( rf2 )
                  create feature_name.simple_feature_name( as_arguments, rf7.start_position )
                  create feature_name_list.make_1( feature_name )
                  create t_native_array.make( rf7.start_position, t_pointer)
                  create writable_attribute.make( feature_name_list, t_native_array )
                  rf2 := writable_attribute.to_run_feature( t_pointer, feature_name )
                  jvm.add_field( rf2 )
                  create feature_name.simple_feature_name( as_open_arguments, rf7.start_position )
                  create feature_name_list.make_1( feature_name )
                  create t_native_array.make( rf7.start_position, t_pointer)
                  create writable_attribute.make( feature_name_list, t_native_array )
                  rf2 := writable_attribute.to_run_feature( t_pointer, feature_name )
                  jvm.add_field( rf2 )
                  create feature_name.simple_feature_name( as_open_argument_indices, rf7.start_position )
                  create feature_name_list.make_1( feature_name )
                  create t_integer.integer( rf7.start_position)
                  create t_native_array.make( rf7.start_position, t_integer)
                  create writable_attribute.make( feature_name_list, t_native_array )
                  rf2 := writable_attribute.to_run_feature( t_pointer, feature_name )
                  jvm.add_field( rf2 )
                  create feature_name.simple_feature_name( as_last_result, rf7.start_position )
                  create feature_name_list.make_1( feature_name )
                  create writable_attribute.make( feature_name_list, t_pointer )
                  rf2 := writable_attribute.to_run_feature( t_pointer, feature_name )
                  jvm.add_field( rf2 )
                  create feature_name.simple_feature_name( as_method, rf7.start_position )
                  create feature_name_list.make_1( feature_name )
                  create writable_attribute.make( feature_name_list, t_pointer )
                  rf2 := writable_attribute.to_run_feature( t_pointer, feature_name )
                  jvm.add_field( rf2 )
               end
            end
         end
      end

   jvm_define_procedure(rf7: RUN_FEATURE_7; bcn, name: STRING) is
      local
         t_pointer: TYPE_POINTER; index_args: INTEGER
      do
         if as_procedure = bcn then
            if as_call = name then
               create t_pointer.make( rf7.start_position)
               rf7.jvm_opening
               index_args := code_attribute.extra_local( t_pointer )
               code_attribute.opcode_iconst_0
               code_attribute.opcode_pop
               rf7.jvm_closing
            end
         end
      end

   jvm_mapping_procedure(rf7: RUN_FEATURE_7; bcn, name: STRING) is
      local
	 ct: E_TYPE; ca: like code_attribute; cp: like constant_pool
         space: INTEGER;
      do
	 ct := rf7.current_type
         ca := code_attribute
         cp := constant_pool
	 if name.has_prefix(fz_basic_) then
	    jvm.drop_target
            jvm_smart_eiffel_runtime(name,rf7)
	 elseif as_copy = name or else as_standard_copy = name then
            if ct.is_basic_eiffel_expanded then
               jvm.drop_target
               jvm.drop_ith_argument(1)
            else
               jvm_copy(rf7.current_type)
            end
         elseif as_die_with_code = name then
            jvm.drop_target
            space := jvm.push_ith_argument(1)
            ca.runtime_die_with_code
         elseif as_print_run_time_stack = name then
            jvm_smart_eiffel_runtime(name,rf7)
         elseif as_print_all_run_time_stacks = name then
            jvm_smart_eiffel_runtime(name,rf7)
         elseif as_sedb_breakpoint = name then
         elseif as_native_array = bcn then
            jvm_mapping_native_array_procedure(rf7,name)
         elseif as_raise_exception = name then
            fe_nyi(rf7)
         elseif as_bit_n = bcn then
            jvm_mapping_bit_procedure(rf7,name)
         elseif is_integer(ct) then
            jvm_mapping_integer_procedure(rf7,name)
         else
            fe_nyi(rf7)
         end
      end

feature

   use_current(er: EXTERNAL_ROUTINE): BOOLEAN is
      local
         name: STRING
      do
         name := er.first_name.to_string
	 if name.has_prefix(fz_basic_) then
	 elseif as_se_argc = name then
         elseif as_se_argv = name then
         else
            Result := True
         end
      end

feature {NONE}

   jvm_smart_eiffel_runtime(name: STRING; rf: RUN_FEATURE) is
         -- Call the corresponding sys/SmartEiffelRutime.java static
         -- definition of some external "SmartEiffel" feature.
      local
         idx, space: INTEGER; fal: FORMAL_ARG_LIST; rt: E_TYPE
         prototype: STRING
      do
         fal := rf.arguments
         rt := rf.result_type
         jvm.drop_target
         if fal /= Void then
            space := - jvm.push_arguments
         end
         prototype := once "(....)."
         prototype.clear
         prototype.extend('(')
         if fal /= Void then
            fal.jvm_descriptor_in(prototype)
         end
         prototype.extend(')')
         if rt = Void then
            prototype.extend('V')
         else
            rt.jvm_descriptor_in(prototype)
            space := space + rt.jvm_stack_space
         end
         idx := constant_pool.idx_methodref3(basic_java_class(name), name, prototype)
         code_attribute.opcode_invokestatic(idx,space)
      end

   jvm_object_size(ct: E_TYPE) is
      local
         t: E_TYPE
         space, i: INTEGER
         wa: ARRAY[RUN_FEATURE_2]
      do
         if ct.is_basic_eiffel_expanded then
            space := ct.jvm_stack_space
         else
            wa := ct.run_class.writable_attributes
            if wa /= Void then
               from
                  i := wa.upper
               until
                  i = 0
               loop
                  t := wa.item(i).result_type
                  space := space + t.jvm_stack_space
                  i := i - 1
               end
            end
         end
         code_attribute.opcode_push_integer(space)
      end

   basic_java_class(name: STRING): STRING is
         -- Examples:
         -- basic_pointer_to_any => SmartEiffelBasicPointer
         -- basic_time_mktime    => SmartEiffelBasicTime
      local
         i, n: INTEGER
         capitalize: BOOLEAN
         c: CHARACTER
      do
         Result := tmp_string
         Result.copy(once "fr/loria/smarteiffel/")
         if name.has_prefix(fz_basic_) then
            n := name.index_of('_', fz_basic_.count+1) - 1
            if n = 0 then
               n := name.count
            end
            Result.append(once "SmartEiffel")
            from
               i := 1
               capitalize := true
            until
               i > n
            loop
               c := name.item(i)
               if c = '_' then
                  capitalize := true
               elseif capitalize then
                  Result.extend(c.to_upper)
                  capitalize := false
               else
                  Result.extend(c)
               end
               i := i + 1
            end
         else
            Result.append(fz_se_runtime)
         end
      end

   c_mapping_standard_twin(rf8: RUN_FEATURE_8; ct: E_TYPE) is
      do
         if ct.is_basic_eiffel_expanded then
            cpp.put_target_as_value
         elseif ct.is_expanded then
            if ct.is_dummy_expanded then
               cpp.put_target_as_target
            elseif ct.is_native_array then
               cpp.put_target_as_target
            else
               rf8.default_mapping_function
            end
         else
            rf8.default_mapping_function
         end
      end

   c_define_standard_twin(rf8: RUN_FEATURE_8; ct: E_TYPE) is
      do
         if ct.is_basic_eiffel_expanded then
         elseif ct.is_expanded then
            if ct.is_dummy_expanded then
            elseif ct.is_native_array then
            else
               rf8.c_define_with_body(once "memcpy(&R,C,sizeof(R));")
            end
         else
            if gc_handler.is_off then
               body.copy(once "R=se_malloc(sizeof(*C));%N")
            else
               body.copy(once "R=(")
               body.append(fz_cast_void_star)
               ct.gc_call_new_in(body)
               body.append(fz_14)
            end
            body.append(fz_69)
            ct.id.append_in(body)
            body.append(once "*)R)=*C;%N")
            rf8.c_define_with_body(body)
         end
      end

   c_define_twin(rf8: RUN_FEATURE_8; ct: E_TYPE; rc: RUN_CLASS
                 cpy: RUN_FEATURE) is
      require
         rf8 /= Void
         ct.is_reference or ct.is_user_expanded
         rc = ct.run_class
         cpy /= Void
      local
         id: INTEGER
      do
         rf8.c_opening
         if ct.is_reference then
            if gc_handler.is_off then
               id := rc.id
               cpp.put_string(once "R=se_malloc(sizeof(*C));%N")
               cpp.put_string(fz_69)
               cpp.put_integer(id)
               cpp.put_string(once "*)R)=M")
               cpp.put_integer(id)
               cpp.put_string(fz_00)
            else
               body.copy(once "R=((void*)")
               ct.gc_call_new_in(body)
               body.append(fz_14)
               cpp.put_string(body)
            end
         end
         cpp.inside_twin(cpy)
         rf8.c_closing
      end

   jvm_mapping_native_array_function(rf8: RUN_FEATURE_8; name: STRING) is
      local
         elt_type: E_TYPE
         space: INTEGER
         rc: RUN_CLASS
         loc1, point1, point2: INTEGER
         ca: like code_attribute
      do
         elt_type := rf8.current_type.generic_list.item(1).run_type
         if as_element_sizeof = name then
            jvm.drop_target
            space := elt_type.jvm_stack_space
            code_attribute.opcode_push_integer(space)
         elseif as_item = name then
            jvm.push_target
            space := jvm.push_ith_argument(1)
            elt_type.jvm_xaload
         elseif as_calloc = name then
            jvm.drop_target
            space := jvm.push_ith_argument(1)
            elt_type.jvm_xnewarray
            if elt_type.is_user_expanded and then
               not elt_type.is_dummy_expanded
             then
               ca := code_attribute
               rc := elt_type.run_class
               loc1 := ca.extra_local_size1
               ca.opcode_dup
               ca.opcode_arraylength
               ca.opcode_istore(loc1)
               point1 := ca.program_counter
               ca.opcode_iload(loc1)
               point2 := ca.opcode_ifle
               ca.opcode_iinc(loc1,255)
               ca.opcode_dup
               ca.opcode_iload(loc1)
               rc.jvm_expanded_push_default
               ca.opcode_aastore
               ca.opcode_goto_backward(point1)
               ca.resolve_u2_branch(point2)
            end
         elseif name = as_from_pointer then
            jvm.drop_target
            space := jvm.push_ith_argument(1)
            rf8.run_class.opcode_checkcast
         else
            fe_nyi(rf8)
         end
      end

   jvm_mapping_native_array_procedure(rf7: RUN_FEATURE_7; name: STRING) is
      local
         elt_type: E_TYPE
         space: INTEGER
         rc: RUN_CLASS
         flag: BOOLEAN
         wa: ARRAY[RUN_FEATURE_2]
      do
         elt_type := rf7.current_type.generic_list.item(1).run_type
         check
	    as_put = name
	 end
         rc := elt_type.run_class
         flag := rc.run_time_mark.has_substring("NATIVE_ARRAY")
         if elt_type.is_basic_eiffel_expanded or elt_type.is_reference or flag then
	 jvm.push_target
	 space := jvm.push_ith_argument(2)
	 space := jvm.push_ith_argument(1)
	 elt_type.jvm_xastore
         else
            jvm.push_target
            space := jvm.push_ith_argument(2)
            elt_type.jvm_xaload
            space := jvm.push_ith_argument(1)
            wa := rc.writable_attributes
            jvm.fields_by_fields_expanded_copy(wa)
            code_attribute.opcode_pop2
         end
      end

   c_mapping_native_array_function(rf8: RUN_FEATURE_8; name: STRING) is
      local
         ct, elt_type: E_TYPE; tcbd: BOOLEAN
      do
	 ct := rf8.current_type
         elt_type := ct.generic_list.item(1).run_type
         if as_element_sizeof = name then
            tcbd := cpp.target_cannot_be_dropped
            if tcbd then
               cpp.put_character(',')
            end
            tmp_string.copy(fz_sizeof)
            tmp_string.extend('(')
            elt_type.c_type_for_argument_in(tmp_string)
            tmp_string.extend(')')
            cpp.put_string(tmp_string)
            if tcbd then
               cpp.put_character(')')
            end
         elseif as_calloc = name then
            if expanded_initializer(elt_type) then
               rf8.default_mapping_function
	    else
               tcbd := cpp.target_cannot_be_dropped
               if tcbd then
                  cpp.put_character(',')
               end
               if gc_handler.is_off then
                  cpp.put_string(fz_b7)
		  cpp.put_integer(ct.id)
                  cpp.put_string(once ")(se_calloc(")
                  cpp.put_ith_argument(1)
                  tmp_string.copy(once ",sizeof(")
                  elt_type.c_type_for_result_in(tmp_string)
                  tmp_string.append(once "))))")
                  cpp.put_string(tmp_string)
               else
                  cpp.put_string(fz_new)
                  cpp.put_integer(rf8.current_type.id)
                  cpp.put_character('(')
                  cpp.put_ith_argument(1)
                  cpp.put_character(')')
               end
               if tcbd then
                  cpp.put_character(')')
               end
            end
         elseif as_from_pointer = name then
            tcbd := cpp.target_cannot_be_dropped
            if tcbd then
               cpp.put_character(',')
            end
            cpp.put_ith_argument(1)
            if tcbd then
               cpp.put_character(')')
            end
         elseif as_item = name then
            cpp.put_character('(')
            cpp.put_target_as_value
            cpp.put_string(fz_46)
            cpp.put_ith_argument(1)
            cpp.put_character(']')
         else
            error_handler.append(once "Class NATIVE_ARRAY has been tampered with.%
                                      % Unknown function: ")
            error_handler.append(name)
            error_handler.add_position(rf8.start_position)
            error_handler.print_as_fatal_error
         end
      end

   c_mapping_native_array_procedure(rf7: RUN_FEATURE_7; name: STRING) is
      local
         elt_type: E_TYPE
      do
         elt_type := rf7.current_type.generic_list.item(1).run_type
         if name = as_put then
            if elt_type.is_user_expanded then
               if elt_type.is_dummy_expanded then
                  if cpp.cannot_drop_all then
                     cpp.put_string(fz_14)
                  end
               else
		  cpp.put_string(once "{%NT")
		  cpp.put_integer(elt_type.id)
		  cpp.put_string(once " tmp_src=")
		  cpp.put_ith_argument(1)
		  cpp.put_string(once ";%Nmemcpy((")
                  cpp.put_target_as_value
                  cpp.put_string(once ")+(")
                  cpp.put_ith_argument(2)
                  cpp.put_string(once "),&(tmp_src),sizeof(T")
                  cpp.put_integer(elt_type.id)
                  cpp.put_string(once "));%N}%N")
               end
            else
               cpp.put_character('(')
               cpp.put_target_as_value
               cpp.put_string(fz_46)
               cpp.put_ith_argument(2)
               cpp.put_string(once "]=(")
               cpp.put_ith_argument(1)
               cpp.put_string(fz_14)
            end
         else
            error_handler.append(once "Class NATIVE_ARRAY has been tampered with.%
                                      % Unknown procedure: ")
            error_handler.append(name)
            error_handler.add_position(rf7.start_position)
            error_handler.print_as_fatal_error
         end
      end

   jvm_copy(t: E_TYPE) is
      require
         not t.is_basic_eiffel_expanded
      local
         rc: RUN_CLASS
         wa: ARRAY[RUN_FEATURE_2]
         space: INTEGER
      do
         rc := t.run_class
         wa := rc.writable_attributes
         jvm.push_target
         space := jvm.push_ith_argument(1)
         rc.opcode_checkcast
         jvm.fields_by_fields_copy(wa)
         code_attribute.opcode_pop
      end

   jvm_define_twin(rf8: RUN_FEATURE_8; rc: RUN_CLASS; cpy: RUN_FEATURE) is
      require
         rc = rf8.run_class
         cpy /= Void
      local
         idx, space, i: INTEGER
         wa: ARRAY[RUN_FEATURE_2]
         rf2: RUN_FEATURE_2
      do
         rf8.jvm_opening
         wa := rc.writable_attributes
         rc.jvm_basic_new
         code_attribute.opcode_astore_1
         if wa /= Void then
            from
               i := wa.upper
            until
               i = 0
            loop
               rf2 := wa.item(i)
               code_attribute.opcode_aload_1
               idx := constant_pool.idx_fieldref(rf2)
               space := rf2.result_type.jvm_push_default
               code_attribute.opcode_putfield(idx,-(space + 1))
               i := i - 1
            end
         end
         jvm.inside_twin(cpy)
         rf8.jvm_closing
      end

feature {NONE}

   jvm_standard_twin(t: E_TYPE) is
      require
         t /= Void
      local
         rc: RUN_CLASS
         wa: ARRAY[RUN_FEATURE_2]
      do
         if t.is_basic_eiffel_expanded or else t.is_native_array then
            jvm.push_target
         else
            rc := t.run_class
            wa := rc.writable_attributes
            if t.is_expanded then
               if wa = Void then
                  jvm.push_target
               else
                  jvm_standard_twin_aux(rc,wa)
               end
            else
               jvm_standard_twin_aux(rc,wa)
            end
         end
      end

   jvm_standard_twin_aux(rc: RUN_CLASS; wa: ARRAY[RUN_FEATURE_2]) is
      require
         rc /= Void
      local
         ca: like code_attribute
         rf2: RUN_FEATURE_2
         idx, space, i: INTEGER
      do
         ca := code_attribute
         rc.jvm_basic_new
         if wa = Void then
            jvm.drop_target
         else
            jvm.push_target
            rc.opcode_checkcast
            from
               i := wa.upper
            until
               i = 0
            loop
               rf2 := wa.item(i)
               ca.opcode_dup2
               idx := constant_pool.idx_fieldref(rf2)
               space := rf2.result_type.jvm_stack_space
               ca.opcode_getfield(idx,space - 1)
               ca.opcode_putfield(idx,space + 1)
               i := i - 1
            end
            ca.opcode_pop
         end
      end

   jvm_mapping_integer_function(rf8: RUN_FEATURE_8; name: STRING) is
      local
         point1, point2, space: INTEGER; ca: like code_attribute
      do
         ca := code_attribute
         if as_slash = name then
            jvm.push_target
            ca.opcode_i2d
            space := jvm.push_ith_argument(1)
            ca.opcode_i2d
            ca.opcode_ddiv
         elseif as_bit_rotate = name then
            space := jvm.push_ith_argument(1)
            point1 := ca.opcode_iflt
            jvm.push_target
            space := jvm.push_ith_argument(1)
            ca.opcode_iushr
            jvm.push_target
            ca.opcode_bipush(32)
            space := jvm.push_ith_argument(1)
            ca.opcode_isub
            ca.opcode_ishl
            ca.opcode_ior
            point2 := ca.opcode_goto
            ca.resolve_u2_branch(point1)
            jvm.push_target
            space := jvm.push_ith_argument(1)
            ca.opcode_ineg
            ca.opcode_ishl
            jvm.push_target
            ca.opcode_bipush(32)
            space := jvm.push_ith_argument(1)
            ca.opcode_iadd
            ca.opcode_iushr
            ca.opcode_ior
            ca.resolve_u2_branch(point2)
         elseif rf8.arg_count = 1 then
            jvm.push_target
            space := jvm.push_ith_argument(1)
            if as_plus_native = name then
               ca.opcode_iadd
            elseif as_minus_native = name then
               ca.opcode_isub
            elseif as_muls_native = name then
               ca.opcode_imul
            elseif as_slash_slash = name then
               ca.opcode_idiv
            elseif as_backslash_backslash = name then
               ca.opcode_irem
            elseif as_shift_right = name then
               ca.opcode_ishr
            elseif as_bit_shift_right_unsigned = name then
               ca.opcode_iushr
            elseif as_shift_left = name then
               ca.opcode_ishl
            elseif as_bit_rotate_right = name then
               ca.opcode_iushr
               jvm.push_target
               ca.opcode_bipush(32)
               space := jvm.push_ith_argument(1)
               ca.opcode_isub
               ca.opcode_ishl
               ca.opcode_ior
            elseif as_bit_rotate_left = name then
               ca.opcode_ishl
               jvm.push_target
               ca.opcode_bipush(32)
               space := jvm.push_ith_argument(1)
               ca.opcode_isub
               ca.opcode_iushr
               ca.opcode_ior
            elseif as_bit_and = name then
               ca.opcode_iand
            elseif as_bit_or = name then
               ca.opcode_ior
            elseif as_bit_xor = name then
               ca.opcode_ixor
            else -- < > <= >= only
               if as_gt = name then
                  point1 := ca.opcode_if_icmpgt
               elseif as_lt = name then
                  point1 := ca.opcode_if_icmplt
               elseif as_le = name then
                  point1 := ca.opcode_if_icmple
               else
                  point1 := ca.opcode_if_icmpge
               end
               ca.opcode_iconst_0
               point2 := ca.opcode_goto
               ca.resolve_u2_branch(point1)
               ca.opcode_iconst_1
               ca.resolve_u2_branch(point2)
            end
         elseif as_to_character = name then
            jvm.push_target
            code_attribute.opcode_i2b
         elseif as_to_bit = name then
            jvm_int_to_bit(rf8.result_type,32)
         elseif as_minus = name then
            jvm.push_target
            code_attribute.opcode_ineg
         elseif as_bit_not = name then
            jvm.push_target
            ca.opcode_iconst_m1
            ca.opcode_ixor
	 elseif as_low_8 = name then
            jvm.push_target
	    ca.opcode_sipush(255)
	    ca.opcode_iand
	 elseif as_low_16 = name then
            jvm.push_target
	    ca.opcode_i2s
	 elseif as_low_32 = name then
            jvm.push_target
	    ca.opcode_l2i
         else
            jvm.push_target
         end
      end

   jvm_mapping_integer_procedure(rf7: RUN_FEATURE_7; name: STRING) is
      local
         point1, point2, space: INTEGER
         ca: like code_attribute
      do
         ca := code_attribute
         if as_bit_put = name then
            space := jvm.push_ith_argument(1)
            point1 := ca.opcode_ifeq
            ca.opcode_iconst_1
            space := jvm.push_ith_argument(2)
            ca.opcode_ishl
            jvm.push_target
            ca.opcode_ior;
            point2 := ca.opcode_goto
            ca.resolve_u2_branch(point1)
            ca.opcode_iconst_1
            space := jvm.push_ith_argument(2)
            ca.opcode_ishl
            ca.opcode_iconst_m1
            ca.opcode_ixor
            jvm.push_target
            ca.opcode_iand;
            ca.resolve_u2_branch(point2)
            jvm.assign_target
         elseif as_bit_set = name then
            ca.opcode_iconst_1
            space := jvm.push_ith_argument(1)
            ca.opcode_ishl
            jvm.push_target
            ca.opcode_ior;
            jvm.assign_target
         elseif as_bit_clear = name then
            ca.opcode_iconst_1
            space := jvm.push_ith_argument(1)
            ca.opcode_ishl
            ca.opcode_iconst_m1
            ca.opcode_ixor
            jvm.push_target
            ca.opcode_iand;
            jvm.assign_target
         end
      end

   jvm_mapping_real_function(rf8: RUN_FEATURE_8; name: STRING) is
      local
         point1, point2, space: INTEGER
         ca: like code_attribute
      do
         ca := code_attribute
         if rf8.arg_count = 1 then
            jvm.push_target
            space := jvm.push_ith_argument(1)
            if as_plus = name then
               ca.opcode_fadd
            elseif as_minus = name then
               ca.opcode_fsub
            elseif as_muls = name then
               ca.opcode_fmul
            elseif as_slash = name then
               ca.opcode_fdiv
            else
               ca.opcode_fcmpg
               if as_gt = name then     -- gt
                  point1 := ca.opcode_ifgt
               elseif as_lt = name then -- lt
                  point1 := ca.opcode_iflt
               elseif as_le = name then -- le
                  point1 := ca.opcode_ifle
               elseif as_ge = name then -- ge
                  point1 := ca.opcode_ifge
               end
               ca.opcode_iconst_0
               point2 := ca.opcode_goto
               ca.resolve_u2_branch(point1)
               ca.opcode_iconst_1
               ca.resolve_u2_branch(point2)
            end
         elseif as_minus = name then
            jvm.push_target
            ca.opcode_fneg
         elseif as_to_double = name then
            jvm.push_target
            ca.opcode_f2d
         end
      end

   jvm_mapping_double_function(rf8: RUN_FEATURE_8; name: STRING) is
      local
         point1, point2, space, idx: INTEGER
         ca: like code_attribute
      do
         ca := code_attribute
         if rf8.arg_count = 1 then
            jvm.push_target
            space := jvm.push_ith_argument(1)
            if as_plus = name then
               ca.opcode_dadd
            elseif as_minus = name then
               ca.opcode_dsub
            elseif as_muls = name then
               ca.opcode_dmul
            elseif as_slash = name then
               ca.opcode_ddiv
            elseif as_pow = name then
               idx := constant_pool.idx_methodref3(fz_java_lang_math,
						   as_pow_postfix,fz_99)
				   ca.opcode_i2d
               ca.opcode_invokestatic(idx,-2)
            elseif as_pow_postfix = name then
               idx := constant_pool.idx_methodref3(fz_java_lang_math,
						   as_pow_postfix,fz_99)
               ca.opcode_invokestatic(idx,-2)
            elseif as_atan2 = name then
               idx := constant_pool.idx_methodref3(fz_java_lang_math,
						   as_atan2,fz_99)
               ca.opcode_invokestatic(idx,-2)
            else
               ca.opcode_dcmpg
               if as_gt = name then     -- gt
                  point1 := ca.opcode_ifgt
               elseif as_lt = name then -- lt
                  point1 := ca.opcode_iflt
               elseif as_le = name then -- le
                  point1 := ca.opcode_ifle
               elseif as_ge = name then -- ge
                  point1 := ca.opcode_ifge
               end
               ca.opcode_iconst_0
               point2 := ca.opcode_goto
               ca.resolve_u2_branch(point1)
               ca.opcode_iconst_1
               ca.resolve_u2_branch(point2)
            end
         elseif as_minus = name then
            jvm.push_target
            ca.opcode_dneg
         elseif as_to_real = name then
            jvm.push_target
            ca.opcode_d2f
         elseif as_double_floor = name then
            jvm.push_target
            idx := constant_pool.idx_methodref3(fz_java_lang_math,
						as_floor, fz_94)
            ca.opcode_invokestatic(idx,0)
         elseif as_truncated_to_integer = name then
            jvm.push_target
            idx := constant_pool.idx_methodref3(fz_java_lang_math,
						as_floor, fz_94)
            ca.opcode_invokestatic(idx,0)
            ca.opcode_d2i
         else -- Same name in java/lang/Math :
            jvm.push_target
            idx := constant_pool.idx_methodref3(fz_java_lang_math,name,fz_94)
            ca.opcode_invokestatic(idx,0)
         end
      end

feature {NATIVE_SMART_EIFFEL_VISITOR}

   accept(visitor: NATIVE_SMART_EIFFEL_VISITOR) is
      do
         visitor.visit_native_smart_eiffel(Current)
      end

feature {NONE}

   to_integer(size: INTEGER; no_check: BOOLEAN) is
      do
	 if no_check then
	    cpp.put_character('R')
	    cpp.put_character('=')
	 end
	 cpp.put_string(once "((EIF_INTEGER_")
	 cpp.put_integer(size)
	 cpp.put_character(')')
	 if no_check then
	    cpp.put_character('C')
	 else
	    cpp.put_character('(')
	    cpp.put_target_as_value
	    cpp.put_character(')')
	 end
	 cpp.put_character(')')
	 if no_check then cpp.put_string(fz_00) end
      end

   c_define_integer_to_integer(size: INTEGER; rf8: RUN_FEATURE_8) is
      do
	 if ace.no_check then
	    rf8.c_opening
	    to_integer(size, True)
	    rf8.c_closing
	 end
      end

   c_mapping_integer_to_integer(size: INTEGER; rf8: RUN_FEATURE_8) is
      do
	 if ace.no_check then
	    rf8.default_mapping_function
	 else
	    to_integer(size, False)
	 end
      end

   exp_or_ref(ct: E_TYPE; rank: INTEGER) is
      require
	 rank = 0 or rank = 1
      local
	 ref_type: TYPE_REFERENCE; id: INTEGER
      do
	 ref_type ?= ct
	 if ref_type /= Void then
	    id := ref_type.id
	    cpp.put_string(once "((T")
	    cpp.put_integer(id)
	    cpp.put_string(once "*)(")
	    if ace.no_check then
	       cpp.put_string(once "vc((T0*)(")
	    end
	 end
	 inspect
	    rank
	 when 0 then
	    cpp.put_target_as_value
	 when 1 then
	    cpp.put_ith_argument(1)
	 end
	 if ref_type /= Void then
	    if ace.no_check then
	       cpp.put_string(once "),0)")
	    end
	    cpp.put_string(once "))->_item")
	 end
      end

   c_mapping_integer_function(rf8: RUN_FEATURE_8; name: STRING) is
      local
	 ct: E_TYPE;
      do
	 ct := rf8.current_type
	 if as_to_integer_8 = name then
	    c_mapping_integer_to_integer(8, rf8)
	 elseif as_to_integer_16 = name then
	    c_mapping_integer_to_integer(16, rf8)
	 elseif as_to_integer_32 = name then
	    c_mapping_integer_to_integer(32, rf8)
         elseif as_shift_right = name then
            cpp.put_string("((")
            exp_or_ref(ct, 0)
            cpp.put_string(once ")>>(")
	    cpp.put_ith_argument(1)
            cpp.put_string(once "))")
         elseif as_bit_shift_right_unsigned = name then
            cpp.put_string(once "((uint")
	    cpp.put_integer(integer_size(ct))
            cpp.put_string(once "_t)(")
            exp_or_ref(ct, 0)
            cpp.put_string(once ")>>(")
	    cpp.put_ith_argument(1)
            cpp.put_string(once "))")
         elseif as_shift_left = name then
            cpp.put_string(once "((")
            exp_or_ref(ct, 0)
            cpp.put_string(once ")<<(")
            cpp.put_ith_argument(1)
            cpp.put_string(once "))")
         elseif as_bit_rotate = name then
            cpp.put_string(once "((")
            cpp.put_ith_argument(1)
            cpp.put_string(once ">=0)?((T2)(((unsigned int)")
            exp_or_ref(ct, 0)
            cpp.put_string(once ">>")
            cpp.put_ith_argument(1)
            cpp.put_string(once "))|(")
            exp_or_ref(ct, 0)
            cpp.put_string(once "<<(")
            cpp.put_integer(Integer_bits)
            cpp.put_string(once "-")
            cpp.put_ith_argument(1)
            cpp.put_string(once "))):((T2)(((unsigned int)")
            exp_or_ref(ct, 0)
            cpp.put_string(once ">>(")
            cpp.put_integer(Integer_bits)
            cpp.put_string(once "+")
            cpp.put_ith_argument(1)
            cpp.put_string(once ")))|(")
            exp_or_ref(ct, 0)
            cpp.put_string(once "<<-")
            cpp.put_ith_argument(1)
            cpp.put_string(once ")))")
         elseif as_bit_rotate_right = name then
            cpp.put_string(once "((T2)(((unsigned int)")
            exp_or_ref(ct, 0)
            cpp.put_string(once ">>")
            cpp.put_ith_argument(1)
            cpp.put_string(once "))|(")
            exp_or_ref(ct, 0)
            cpp.put_string(once "<<(")
            cpp.put_integer(Integer_bits)
            cpp.put_character('-')
            cpp.put_ith_argument(1)
            cpp.put_string(once ")))")
         elseif as_bit_rotate_left = name then
            cpp.put_string(once "((T2)(((unsigned int)")
            exp_or_ref(ct, 0)
            cpp.put_string(once ">>(")
            cpp.put_integer(Integer_bits)
            cpp.put_character('-')
            cpp.put_ith_argument(1)
            cpp.put_string(once ")))|(")
            exp_or_ref(ct, 0)
            cpp.put_string(once "<<")
            cpp.put_ith_argument(1)
            cpp.put_string(once "))")
         elseif as_bit_and = name then
            cpp.put_character('(')
            exp_or_ref(ct, 0)
            cpp.put_character('&')
            exp_or_ref(ct, 1)
            cpp.put_character(')')
         elseif as_bit_or = name then
            cpp.put_character('(')
            exp_or_ref(ct, 0)
            cpp.put_character('|')
            exp_or_ref(ct, 1)
            cpp.put_character(')')
         elseif as_bit_xor = name then
            cpp.put_character('(')
            exp_or_ref(ct, 0)
            cpp.put_character('^')
            exp_or_ref(ct, 1)
            cpp.put_character(')')
         elseif as_bit_not = name then
            cpp.put_string(once "~(")
            exp_or_ref(ct, 0)
            cpp.put_character(')')
	 elseif as_low_8 = name then
	    cpp.put_string(once "(EIF_INTEGER_8)(")
            exp_or_ref(ct, 0)
            cpp.put_character(')')
	 elseif as_low_16 = name then
	    cpp.put_string(once "(EIF_INTEGER_16)(")
            exp_or_ref(ct, 0)
            cpp.put_character(')')
	 elseif as_low_32 = name then
	    cpp.put_string(once "(EIF_INTEGER_32)(")
            exp_or_ref(ct, 0)
            cpp.put_character(')')
         elseif rf8.arg_count = 1 then
            if as_slash = name then
               cpp.put_string(once "((T5)")
	    else
               cpp.put_string(once "(int")
	       cpp.put_integer(integer_size(ct))
	       cpp.put_string(once "_t)(")
            end
            cpp.put_character('(')
            exp_or_ref(ct, 0)
            if as_slash = name then
               cpp.put_character(')')
            end
            cpp.put_character(')')
            if as_slash_slash = name then
               cpp.put_character('/')
            elseif as_backslash_backslash = name then
               cpp.put_character('%%')
            elseif as_plus_native = name then
               cpp.put_character('+')
            elseif as_minus_native = name then
               cpp.put_character('-')
            elseif as_muls_native = name then
               cpp.put_character('*')
            else
               cpp.put_string(name)
            end
            cpp.put_character('(')
            exp_or_ref(ct, 1)
            cpp.put_character(')')
            if as_slash /= name then
               cpp.put_character(')')
            end
         elseif as_to_character = name then
            cpp.put_string(once "((T3)(")
            exp_or_ref(ct, 0)
            cpp.put_string(fz_13)
         elseif as_to_bit = name then
            exp_or_ref(ct, 0)
         else
	    cpp.put_string(name)
            cpp.put_character('(')
            exp_or_ref(ct, 0)
            cpp.put_character(')')
         end
      end

   c_mapping_integer_procedure(rf7: RUN_FEATURE_7; name: STRING) is
      do
         if as_bit_put = name then
            cpp.put_string(once "if(")
            cpp.put_ith_argument(1)
            cpp.put_string(once "){%N")
            cpp.put_target_as_value
            cpp.put_character('=')
            cpp.put_target_as_value
            cpp.put_string(once "|(1<<")
            cpp.put_ith_argument(2)
            cpp.put_string(once ");%N}%Nelse{%N")
            cpp.put_target_as_value
            cpp.put_character('=')
            cpp.put_target_as_value
            cpp.put_string(once "&(~(1<<")
            cpp.put_ith_argument(2)
            cpp.put_string(once "));%N}")
         elseif as_bit_set = name then
            cpp.put_target_as_value
            cpp.put_character('=')
            cpp.put_target_as_value
            cpp.put_string(once "|(1<<")
            cpp.put_ith_argument(1)
            cpp.put_string(once ");%N")
         elseif as_bit_clear = name then
            cpp.put_target_as_value
            cpp.put_character('=')
            cpp.put_target_as_value
            cpp.put_string(once "&(~(1<<")
            cpp.put_ith_argument(1)
            cpp.put_string(once "));%N")
         end
      end

   c_mapping_real_double(ct: E_TYPE; name: STRING; arg_count: INTEGER) is
      require
         arg_count = 0 or arg_count = 1
      do
         if as_pow = name then
            system_tools.add_lib_math
            cpp.put_string(once "pow((")
	    exp_or_ref(ct, 0)
            cpp.put_string(once "),(double)(")
            cpp.put_arguments
            cpp.put_string(fz_13)
         elseif as_double_floor = name then
            system_tools.add_lib_math
            cpp.put_string(as_floor)
            cpp.put_character('(')
	    exp_or_ref(ct, 0)
            cpp.put_character(')')
         elseif as_truncated_to_integer = name then
            system_tools.add_lib_math
            cpp.put_string(once "((int)floor(")
	    exp_or_ref(ct, 0)
            cpp.put_string(fz_13)
         elseif as_to_double = name then
            cpp.put_string(fz_43)
            exp_or_ref(ct, 0)
            cpp.put_string(fz_13)
         elseif as_to_real = name then
            cpp.put_string(fz_45)
	    exp_or_ref(ct, 0)
            cpp.put_string(fz_13)
         elseif name.count <= 2 and then arg_count = 1 then
            cpp.put_character('(')
	    exp_or_ref(ct, 0)
            cpp.put_character(')')
            cpp.put_string(name)
            cpp.put_character('(')
	    exp_or_ref(ct, 1)
            cpp.put_character(')')
         else
            system_tools.add_lib_math
            cpp.put_string(name)
            cpp.put_character('(')
	    exp_or_ref(ct, 0)
	    if arg_count = 1 then
	       cpp.put_character(',')
	       exp_or_ref(ct, 1)
	    end
            cpp.put_character(')')
         end
      end

   c_define_procedure_bit(rf7: RUN_FEATURE_7; n: STRING) is
      local
         type_bit: TYPE_BIT
      do
         type_bit ?= rf7.current_type
         if as_put_0 = n then
            if type_bit.is_c_unsigned_ptr then
               body.clear
               body_long_bit_put01(type_bit,'&','~','1')
               rf7.c_define_with_body(body)
            end
         elseif as_put_1 = n then
            if type_bit.is_c_unsigned_ptr then
               body.clear
               body_long_bit_put01(type_bit,'|',' ','1')
               rf7.c_define_with_body(body)
            end
         elseif as_put = n then
            if type_bit.is_c_unsigned_ptr then
               body.clear
               body.append(once "if(a1)%N")
               body_long_bit_put01(type_bit,'|',' ','2')
               body.append(fz_else)
               body_long_bit_put01(type_bit,'&','~','2')
               rf7.c_define_with_body(body)
            end
         end
      end

   tmp_string: STRING is
      once
         !!Result.make(32)
      end

   fe_long_bit(rf: RUN_FEATURE) is
      do
         error_handler.add_position(rf.start_position)
         error_handler.append("Sorry, this feature cannot be implemented for ")
         error_handler.add_type(rf.current_type,
          " (bit string too long). You should probably consider using %
          %the BIT_STRING class to work around.")
         error_handler.print_as_fatal_error
      end

   fe_nyi(rf: RUN_FEATURE) is
      do
         error_handler.add_position(rf.start_position)
         error_handler.append("Sorry, but this feature is not yet implemented for %
                   %Current type ")
         error_handler.append(rf.current_type.run_time_mark)
         fatal_error(" (if you cannot work around mail %"colnet@loria.fr%").")
      end

   jvm_bit_to_int(size: INTEGER) is
      local
         idx: INTEGER
         point1, point2: INTEGER
         loc1, loc2: INTEGER
         ca: like code_attribute
         cp: like constant_pool
      do
         ca := code_attribute
         cp := constant_pool
         jvm.push_target
         loc1 := ca.extra_local_size1
         ca.opcode_iconst_0
         ca.opcode_istore(loc1)
         loc2 := ca.extra_local_size1
         ca.opcode_iconst_0
         ca.opcode_istore(loc2)
         ca.opcode_iconst_1
         point1 := ca.program_counter
         point2 := ca.opcode_ifeq
         ca.opcode_iload(loc2)
         ca.opcode_iconst_1
         ca.opcode_ishl
         ca.opcode_istore(loc2)
         ca.opcode_dup
         ca.opcode_iload(loc1)
         idx := cp.idx_methodref3(fz_java_util_bitset,fz_get,fz_a3)
         ca.opcode_invokevirtual(idx,-1)
         ca.opcode_iload(loc2)
         ca.opcode_ior
         ca.opcode_istore(loc2)
         ca.opcode_iinc(loc1,1)
-- ***
-- ca.opcode_dup
--	 idx := cp.idx_methodref3(fz_java_util_bitset,once "size",fz_71)
--	 ca.opcode_invokevirtual(idx,0)
         ca.opcode_push_integer(size)
-- ***
         ca.opcode_iload(loc1)
         ca.opcode_isub
         ca.opcode_goto_backward(point1)
         ca.resolve_u2_branch(point2)
         ca.opcode_pop
         ca.opcode_iload(loc2)
      end

   jvm_int_to_bit(type_bit: E_TYPE; nb_bit: INTEGER) is
      local
         idx: INTEGER
         point1, point2, point3: INTEGER
         loc1, loc2: INTEGER
         ca: like code_attribute
         cp: like constant_pool
      do
         ca := code_attribute
         cp := constant_pool
         jvm.push_target
         loc1 := ca.extra_local_size1
         ca.opcode_push_integer(nb_bit)
         ca.opcode_istore(loc1)
         loc2 := ca.extra_local_size1
         idx := type_bit.jvm_push_default
         ca.opcode_astore(loc2)
         ca.opcode_iconst_1
         point1 := ca.program_counter
         point2 := ca.opcode_ifeq
         ca.opcode_iinc(loc1,255)
         ca.opcode_dup
         ca.opcode_iconst_1
         ca.opcode_iand
         point3 := ca.opcode_ifeq
         ca.opcode_aload(loc2)
         ca.opcode_iload(loc1)
         idx := cp.idx_methodref3(fz_java_util_bitset,fz_set,fz_27)
         ca.opcode_invokevirtual(idx,-2)
         ca.resolve_u2_branch(point3)
         ca.opcode_iconst_1
         ca.opcode_iushr
         ca.opcode_iload(loc1)
         ca.opcode_goto_backward(point1)
         ca.resolve_u2_branch(point2)
         ca.opcode_pop
         ca.opcode_aload(loc2)
      end

   jvm_mapping_bit_function(rf8: RUN_FEATURE_8; name: STRING) is
      local
         type_bit: TYPE_BIT
         space, idx: INTEGER
         point1, point2, point3: INTEGER
         loc1, loc2: INTEGER
         ca: like code_attribute
         cp: like constant_pool
      do
         ca := code_attribute
         cp := constant_pool
         type_bit ?= rf8.current_type
         if as_count = name then
            jvm.drop_target
            ca.opcode_push_integer(type_bit.nb)
         elseif as_item = name then
            jvm.push_target
            space := jvm.push_ith_argument(1)
            ca.opcode_iconst_1
            ca.opcode_isub
            idx := cp.idx_methodref3(fz_java_util_bitset,fz_get,fz_a3)
            ca.opcode_invokevirtual(idx,-1)
         elseif as_shift_right = name then
            jvm.push_target
            space := jvm.push_ith_argument(1)
            loc1 := ca.extra_local_size1
            loc2 := ca.extra_local_size1
            ca.opcode_istore(loc2)
            space := type_bit.jvm_push_default
            ca.opcode_swap
            ca.opcode_push_integer(type_bit.nb)
            ca.opcode_istore(loc1)
            ca.opcode_iload(loc1)
            ca.opcode_iload(loc2)
            ca.opcode_isub
            ca.opcode_istore(loc2)
            ca.opcode_iload(loc2)
            point1 := ca.program_counter
            point2 := ca.opcode_ifeq
            ca.opcode_iinc(loc1,255)
            ca.opcode_iinc(loc2,255)
            ca.opcode_dup2
            ca.opcode_iload(loc2)
            idx := cp.idx_methodref3(fz_java_util_bitset,fz_get,fz_a3)
            ca.opcode_invokevirtual(idx,-1)
            point3 := ca.opcode_ifne
            ca.opcode_pop
            ca.opcode_iload(loc2)
            ca.opcode_goto_backward(point1)
            ca.resolve_u2_branch(point3)
            ca.opcode_iload(loc1)
            idx := cp.idx_methodref3(fz_java_util_bitset,fz_set,fz_27)
            ca.opcode_invokevirtual(idx,-2)
            ca.opcode_iload(loc2)
            ca.opcode_goto_backward(point1)
            ca.resolve_u2_branch(point2)
            ca.opcode_pop
         elseif as_shift_left = name then
            jvm.push_target
            space := jvm.push_ith_argument(1)
            loc1 := ca.extra_local_size1
            loc2 := ca.extra_local_size1
            ca.opcode_istore(loc1)
            space := type_bit.jvm_push_default
            ca.opcode_swap
            ca.opcode_push_integer(type_bit.nb)
            ca.opcode_istore(loc2)
            ca.opcode_iload(loc2)
            ca.opcode_iload(loc1)
            ca.opcode_isub
            ca.opcode_istore(loc1)
            ca.opcode_iload(loc1)
            point1 := ca.program_counter
            point2 := ca.opcode_ifeq
            ca.opcode_iinc(loc1,255)
            ca.opcode_iinc(loc2,255)
            ca.opcode_dup2
            ca.opcode_iload(loc2)
            idx := cp.idx_methodref3(fz_java_util_bitset,fz_get,fz_a3)
            ca.opcode_invokevirtual(idx,-1)
            point3 := ca.opcode_ifne
            ca.opcode_pop
            ca.opcode_iload(loc1)
            ca.opcode_goto_backward(point1)
            ca.resolve_u2_branch(point3)
            ca.opcode_iload(loc1)
            idx := cp.idx_methodref3(fz_java_util_bitset,fz_set,fz_27)
            ca.opcode_invokevirtual(idx,-2)
            ca.opcode_iload(loc1)
            ca.opcode_goto_backward(point1)
            ca.resolve_u2_branch(point2)
            ca.opcode_pop
         elseif as_xor = name then
            jvm.push_target
            ca.opcode_dup
            space := jvm.push_ith_argument(1)
            idx := cp.idx_methodref3(fz_java_util_bitset,as_xor,fz_b1)
            ca.opcode_invokevirtual(idx,0)
         elseif as_or = name then
            jvm.push_target
            ca.opcode_dup
            space := jvm.push_ith_argument(1)
            idx := cp.idx_methodref3(fz_java_util_bitset,as_or,fz_b1)
            ca.opcode_invokevirtual(idx,0)
         elseif as_not = name then
            jvm.push_target
            loc1 := ca.extra_local_size1
            ca.opcode_push_integer(type_bit.nb)
            ca.opcode_istore(loc1)
            ca.opcode_iload(loc1)
            point1 := ca.program_counter
            point2 := ca.opcode_ifeq
            ca.opcode_iinc(loc1,255)
            ca.opcode_dup
            ca.opcode_iload(loc1)
            idx := cp.idx_methodref3(fz_java_util_bitset,fz_get,fz_a3)
            ca.opcode_invokevirtual(idx,-1)
            point3 := ca.opcode_ifne
            ca.opcode_dup
            ca.opcode_iload(loc1)
            idx := cp.idx_methodref3(fz_java_util_bitset,fz_set,fz_27)
            ca.opcode_invokevirtual(idx,-2)
            ca.opcode_iload(loc1)
            ca.opcode_goto_backward(point1)
            ca.resolve_u2_branch(point3)
            ca.opcode_dup
            ca.opcode_iload(loc1)
            idx := cp.idx_methodref3(fz_java_util_bitset,fz_a5,fz_27)
            ca.opcode_invokevirtual(idx,-2)
            ca.opcode_iload(loc1)
            ca.opcode_goto_backward(point1)
            ca.resolve_u2_branch(point2)
         elseif as_and = name then
            jvm.push_target
            ca.opcode_dup
            space := jvm.push_ith_argument(1)
            idx := cp.idx_methodref3(fz_java_util_bitset,as_and,fz_b1)
            ca.opcode_invokevirtual(idx,0)
         elseif as_last = name then
            jvm.push_target
            ca.opcode_push_integer(type_bit.nb)
            ca.opcode_iconst_1
            ca.opcode_isub
            idx := cp.idx_methodref3(fz_java_util_bitset,fz_a2,fz_a3)
            ca.opcode_invokevirtual(idx,-1)
         elseif as_to_character = name then
            jvm_bit_to_int(8)
         elseif as_to_integer = name then
            jvm_bit_to_int(32)
         end
      end

   jvm_mapping_bit_procedure(rf7: RUN_FEATURE_7; name: STRING) is
      local
         type_bit: TYPE_BIT
         space, idx, point1, point2: INTEGER
         ca: like code_attribute
         cp: like constant_pool
      do
         ca := code_attribute
         cp := constant_pool
         type_bit ?= rf7.current_type
         if name = as_put_0 then
            jvm.push_target
            space := jvm.push_ith_argument(1)
            ca.opcode_iconst_1
            ca.opcode_isub
            idx := cp.idx_methodref3(fz_java_util_bitset,fz_a5,fz_27)
            ca.opcode_invokevirtual(idx,-2)
         elseif name = as_put_1 then
            jvm.push_target
            space := jvm.push_ith_argument(1)
            ca.opcode_iconst_1
            ca.opcode_isub
            idx := cp.idx_methodref3(fz_java_util_bitset,fz_set,fz_27)
            ca.opcode_invokevirtual(idx,-2)
         else
            check
               name = as_put
            end
            jvm.push_target
            space := jvm.push_ith_argument(1)
            space := jvm.push_ith_argument(2)
            ca.opcode_iconst_1
            ca.opcode_isub
            ca.opcode_swap
            point1 := ca.opcode_ifne
            idx := cp.idx_methodref3(fz_java_util_bitset,fz_a5,fz_27)
            ca.opcode_invokevirtual(idx,-2)
            point2 := ca.opcode_goto
            ca.resolve_u2_branch(point1)
            idx := cp.idx_methodref3(fz_java_util_bitset,fz_set,fz_27)
            ca.opcode_invokevirtual(idx,-2)
            ca.resolve_u2_branch(point2)
         end
      end

   c_mapping_bit_procedure(rf7: RUN_FEATURE_7; name: STRING) is
      local
         type_bit: TYPE_BIT
      do
         type_bit ?= rf7.current_type
         if name = as_put_0 then
            if type_bit.is_c_unsigned_ptr then
               rf7.default_mapping_procedure
            else
               mapping_small_bit_put_0(type_bit,1)
            end
         elseif name = as_put_1 then
            if type_bit.is_c_unsigned_ptr then
               rf7.default_mapping_procedure
            else
               mapping_small_bit_put_1(type_bit,1)
            end
         else
            check
               name = as_put
            end
            if type_bit.is_c_unsigned_ptr then
               rf7.default_mapping_procedure
            else
               cpp.put_string(fz_53)
               cpp.put_ith_argument(1)
               cpp.put_string(fz_62)
               mapping_small_bit_put_1(type_bit,2)
               cpp.put_string(fz_67)
               mapping_small_bit_put_0(type_bit,2)
               cpp.put_string(fz_12)
            end
         end
      end

   body_long_bit_put01(type_bit: TYPE_BIT; op1, op2, arg: CHARACTER) is
      require
         type_bit.is_c_unsigned_ptr
      do
         body.append(once "{%N%
                     %unsigned int*ptr=((void*)C);%N%
                     %int ib=(CHAR_BIT*sizeof(int));%N%
                     %int widx=((")
         type_bit.unsigned_padding.append_in(body)
         body.append(once "+a")
         body.extend(arg)
         body.append(once "-1)/ib);%N%
                     %int bidx=((a")
         body.extend(arg)
         body.append(once "-1+")
         type_bit.unsigned_padding.append_in(body)
         body.append(once ")%%ib)+1;%N%
                     %int shift=ib-bidx;%N%
                     %(*(ptr+widx))")
         body.extend(op1)
         body.append(fz_47)
         body.extend(op2)
         body.append(once "(((unsigned int)1)<<shift));%N}")
      end

   mapping_small_bit_put01(type_bit: TYPE_BIT; op1, op2: CHARACTER; arg: INTEGER) is
      require
         not type_bit.is_c_unsigned_ptr
      do
         cpp.put_target_as_value
         cpp.put_character(op1)
         cpp.put_string(fz_47)
         cpp.put_character(op2)
         cpp.put_string(once "(((unsigned ")
         if type_bit.is_c_char then
            cpp.put_string(fz_char)
         else
            cpp.put_string(fz_int)
         end
         cpp.put_string(once ")1)<<(")
         cpp.put_integer(type_bit.nb)
         cpp.put_string(fz_37)
         cpp.put_ith_argument(arg)
         cpp.put_string(once "))));%N")
      end

   mapping_small_bit_put_1(type_bit: TYPE_BIT; arg: INTEGER) is
      require
         not type_bit.is_c_unsigned_ptr
      do
         mapping_small_bit_put01(type_bit,'|',' ',arg)
      end

   mapping_small_bit_put_0(type_bit: TYPE_BIT; arg: INTEGER) is
      require
         not type_bit.is_c_unsigned_ptr
      do
         mapping_small_bit_put01(type_bit,'&','~',arg)
      end

   c_mapping_bit_function(rf8: RUN_FEATURE_8; name: STRING) is
      local
         type_bit: TYPE_BIT
         boost: BOOLEAN
      do
         type_bit ?= rf8.current_type
         boost := ace.boost
         if as_count = name then
            cpp.put_integer(type_bit.nb)
         elseif as_item = name then
            if type_bit.is_c_unsigned_ptr then
               rf8.default_mapping_function
            elseif boost then
	       cpp.put_string(fz_32)
               cpp.put_target_as_target
               cpp.put_string(fz_36)
               cpp.put_integer(type_bit.nb)
               cpp.put_string(fz_37)
               cpp.put_arguments
               cpp.put_string(once ")))&1)")
            else
               rf8.default_mapping_function
            end
         elseif as_shift_right = name then
            if type_bit.is_c_unsigned_ptr then
               fe_long_bit(rf8)
            elseif boost then
               cpp.put_string(fz_17)
               cpp.put_target_as_target
               cpp.put_string(fz_36)
               cpp.put_ith_argument(1)
               cpp.put_string(fz_13)
            else
               rf8.default_mapping_function
            end
         elseif as_shift_left = name then
            if type_bit.is_c_unsigned_ptr then
               fe_long_bit(rf8)
            elseif boost then
               cpp.put_string(fz_17)
               cpp.put_target_as_target
               cpp.put_string(once ")<<(")
               cpp.put_ith_argument(1)
               cpp.put_string(fz_13)
            else
               rf8.default_mapping_function
            end
         elseif as_xor = name then
            if type_bit.is_c_unsigned_ptr then
               fe_long_bit(rf8)
            else
               cpp.put_character('(')
               cpp.put_target_as_target
               cpp.put_string(once ")^(")
               cpp.put_ith_argument(1)
               cpp.put_character(')')
            end
         elseif as_or = name then
            if type_bit.is_c_unsigned_ptr then
               fe_long_bit(rf8)
            else
               cpp.put_character('(')
               cpp.put_target_as_target
               cpp.put_character(')')
               cpp.put_character('|')
               cpp.put_character('(')
               cpp.put_ith_argument(1)
               cpp.put_character(')')
            end
         elseif as_not = name then
            if type_bit.is_c_unsigned_ptr then
               fe_long_bit(rf8)
            else
               type_bit.mapping_cast
               cpp.put_character('~')
               cpp.put_character('(')
               cpp.put_target_as_target
               cpp.put_character(')')
            end
         elseif as_and = name then
            if type_bit.is_c_unsigned_ptr then
               fe_long_bit(rf8)
            else
               cpp.put_character('(')
               cpp.put_target_as_target
               cpp.put_character(')')
               cpp.put_character('&')
               cpp.put_character('(')
               cpp.put_ith_argument(1)
               cpp.put_character(')')
            end
         elseif as_last = name then
            if type_bit.is_c_unsigned_ptr then
               rf8.default_mapping_function
            elseif boost then
               cpp.put_string(fz_32)
               cpp.put_target_as_target
               cpp.put_string(once "))&1)")
            else
               rf8.default_mapping_function
            end
         elseif as_to_character = name then
            cpp.put_target_as_value
         elseif as_to_integer = name then
            cpp.put_target_as_value
         end
      end

   c_define_function_bit(rf8: RUN_FEATURE_8; name: STRING) is
      local
         type_bit: TYPE_BIT; no_check: BOOLEAN
      do
         type_bit ?= rf8.current_type
         no_check := ace.no_check
         if as_count = name then
         elseif as_item = name then
            if type_bit.is_c_unsigned_ptr then
               body.copy(once "{int ib=(CHAR_BIT*sizeof(int));%N%
                         %int widx=((")
               type_bit.unsigned_padding.append_in(body)
               body.append(once "+a1-1)/ib);%N%
                           %unsigned int word=*(((unsigned int*)C)+widx);%N%
                           %int bidx=((a1-1+")
               type_bit.unsigned_padding.append_in(body)
               body.append(once ")%%ib)+1;%N%
                           %int shift=ib-bidx;%N%
                           %R=(T6)((word>>shift)&1);%N}%N")
               rf8.c_define_with_body(body)
            elseif no_check then
               body.copy(once "R=(T6)(((unsigned int)C>>(")
               type_bit.nb.append_in(body)
               body.append(once "-a1))&1);%N")
               rf8.c_define_with_body(body)
            end
         elseif as_shift_left = name then
            if type_bit.is_c_unsigned_ptr then
               fe_long_bit(rf8)
            else
               rf8.c_define_with_body(once "R=(C<<a1);")
            end
         elseif as_shift_right = name then
            if type_bit.is_c_unsigned_ptr then
               fe_long_bit(rf8)
            else
               rf8.c_define_with_body(once "R=(C>>a1);")
            end
         elseif as_last = name then
            if type_bit.is_c_unsigned_ptr then
               body.copy(once "{int ib=(CHAR_BIT*sizeof(int));%N%
                         %int widx=((")
               type_bit.unsigned_padding.append_in(body)
               body.extend('+')
               ; (type_bit.nb - 1).append_in(body)
               body.append(once ")/ib);%N%
                           %unsigned int word=*(((unsigned int*)C)+widx);%N%
                           %int bidx=((")
               ; (type_bit.nb - 1).append_in(body)
               body.extend('+')
               type_bit.unsigned_padding.append_in(body)
               body.append(once ")%%ib)+1;%N%
                           %int shift=ib-bidx;%N%
                           %R=(T6)((word>>shift)&1);%N}%N")
               rf8.c_define_with_body(body)
            elseif no_check then
               body.copy(once "R=(T6)(((unsigned int)C)&1);%N")
               rf8.c_define_with_body(body)
            end
         end
      end

   expanded_initializer(rt: E_TYPE): BOOLEAN is
      do
	 if rt.is_user_expanded then
	    Result := rt.run_class.a_default_create /= Void
	 end
      end

   default_create is
      do
      end

   is_integer(ct: E_TYPE): BOOLEAN is
      local
	 tr: TYPE_REFERENCE
      do
	 if ct.is_integer then
	    Result := True
	 else
	    tr ?= ct
	    if tr /= Void then
	       Result := tr.expanded_type.is_integer
	    end
	 end
      end

   integer_size(ct: E_TYPE): INTEGER_8 is
      require
	 is_integer(ct)
      local
	 type_integer: TYPE_INTEGER; type_reference: TYPE_REFERENCE
      do
	 type_integer ?= ct
	 if type_integer = void then
	    type_reference ?= ct
	    type_integer ?= type_reference.expanded_type
	 end
	 Result := (type_integer.c_sizeof * 8).to_integer_8
      ensure
	 (<<8, 16, 32, 64>>).fast_has(Result)
      end

end -- NATIVE_SMART_EIFFEL
