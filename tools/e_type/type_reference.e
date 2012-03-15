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
class TYPE_REFERENCE
   --
   -- Handling of the "reference FOO" type mark.
   --

inherit E_TYPE
   
creation make
   
creation {TYPE_REFERENCE} set
   
feature
   
   is_reference,
   need_gc_mark_function
   : BOOLEAN is True

   is_expanded,
   is_bit,
   is_separate,
   is_none,
   is_pointer,
   is_real,
   is_anchored,
   is_integer,
   is_character,
   is_double,
   is_boolean,
   is_string,
   is_any,
   is_array,
   is_basic_eiffel_expanded,
   is_user_expanded,
   is_dummy_expanded,
   is_like_current,
   is_like_argument,
   is_like_feature
   : BOOLEAN is False

   jvm_method_flags: INTEGER is 17

   start_position: POSITION
	 -- Of the first letter of the reference keyword.
   
   expanded_type: E_TYPE
         -- The corresponding usually expanded one.

   is_run_type: BOOLEAN is
      do
	 if run_type_memory /= Void then
	    Result := True
	 elseif expanded_type.is_run_type then
	    run_type_memory := Current
	    Result := True
	 end
      end
   
   written_mark: STRING is
      local
	 expanded_wm: STRING
      do
	 Result := written_mark_memory
	 if Result = Void then
	    expanded_wm := expanded_type.written_mark
	    Result := once ".....         local unique buffer          ....."
	    Result.copy(fz_reference)
	    Result.extend(' ')
	    Result.append(expanded_wm)
	    Result := string_aliaser.item(Result)
	    written_mark_memory := Result
	 end
      end

   actual_reference(destination: E_TYPE): E_TYPE is
      do
	 check False end
      end

   actual_separate(destination: E_TYPE): E_TYPE is
      local
         sp: POSITION
      do
         sp := destination.start_position
         Result := separate_tools.create_type_separate(sp, Current)
      end

   start_lookup_name: CLASS_NAME is
      do
         Result := expanded_type.start_lookup_name
      end

   id: INTEGER is
      do
         Result := run_class.id
      end

   is_generic: BOOLEAN is
      do
         Result := expanded_type.is_generic
      end

   run_type: E_TYPE is
      do
	 if is_run_type then
	    Result := run_type_memory
	 end
      end

   generic_list: ARRAY[E_TYPE] is
      do
         Result := expanded_type.generic_list
      end

   local_from_separate: E_TYPE is
      do
	 check False end
      end

   run_time_mark: STRING is
      do
	 Result := run_type.written_mark
      end

   base_class_name: CLASS_NAME is
      do
         Result := expanded_type.base_class_name
      end

   to_runnable(ct: E_TYPE): like Current is
      local
	 et: E_TYPE; rt: like Current; rtm: STRING
	 type_integer: TYPE_INTEGER;
      do
	 et := expanded_type.to_runnable(ct)
	 rtm := et.run_time_mark
	 if rtm = as_integer_64 then
	    type_integer ?= et.run_type
	    if type_integer.is_integer_general then
	       error_handler.add_position(start_position)
	       error_handler.append(
	          "Type %"reference INTEGER_GENERAL%" is not valid (CTCR).")
	       error_handler.print_as_fatal_error
	    end
	 end
	 if rtm = as_real_general then
	    error_handler.add_position(start_position)
	    error_handler.append(
	       "Type reference %"REAL_GENERAL%" is not valid (CTCR).")
	    error_handler.print_as_fatal_error
	 end
	 if et.is_bit then
	    smart_eiffel.bit_n_ref_is_nyi_error(et.start_position)
	 end
	 if et = expanded_type then
	    if run_type_memory = Void then
	       if et.is_expanded then
		  run_type_memory := Current
	       else -- This is not common but possible because of genericity:
		  run_type_memory := et
	       end
	       Result := Current
	    elseif run_type_memory = Current then
	       if et.is_expanded then
		  Result := Current
	       else -- This is not common but possible because of genericity:
		  create Result.make(start_position, et)
		  Result := Result.to_runnable(ct)
	       end
	    else
	       create rt.make(start_position, et.run_type)
	       check rt.run_type = rt end
	       create Result.set(start_position,
				 et,
				 written_mark_memory,
				 rt)
	    end
	 else
	    create rt.make(start_position, et.run_type)
	    check rt.run_type = rt end
	    create Result.set(start_position,
			      et,
			      written_mark_memory,
			      rt)
	 end
      end

   is_a(other: E_TYPE): BOOLEAN is
      do
         if run_time_mark = other.run_time_mark then
	    Result := True
	 else
	    Result := expanded_type.is_a(other)
         end
	 if not Result then
	    error_handler.type_error(Current,other)
	 end
      end

   smallest_ancestor(other: E_TYPE): E_TYPE is
      do
         if run_time_mark = other.run_time_mark then
	    Result := Current
	 else
	    Result := expanded_type.smallest_ancestor(other)
	 end
      end

   just_before_gc_mark_in(str: STRING) is
      do
         standard_just_before_gc_mark_in(str)
      end

   gc_info_in(str: STRING) is
      do
         standard_gc_info_in(str)
      end

   gc_define1 is
      do
         standard_gc_define1
      end

   gc_define2 is
      do
         standard_gc_define2
      end

   c_sizeof: INTEGER is
      do
         Result := c_sizeof_pointer
      end

   stupid_switch(run_time_set: RUN_TIME_SET): BOOLEAN is
      do
         Result := expanded_type.stupid_switch(run_time_set)
      end

   c_type_for_argument_in(str: STRING) is
      do
         str.append(fz_t0_star)
      end

   c_type_for_target_in(str: STRING) is
      do
         str.extend('T')
         id.append_in(str)
         str.extend('*')
      end

   c_type_for_result_in(str: STRING) is
      do
         str.append(fz_t0_star)
      end

   need_c_struct: BOOLEAN is
      do
	 if run_class.is_tagged then
            Result := true
         else
            Result := run_class.writable_attributes /= Void
         end
      end

   c_header_pass1 is
      do
         standard_c_typedef
      end

   c_header_pass2 is
      do
      end

   c_header_pass3 is
      do
      end

   c_header_pass4 is
      do
	 if need_c_struct then
	    standard_c_struct
	 end
         standard_c_object_model
         standard_c_print_function
      end

   c_initialize is
      do
         cpp.put_string(fz_null)
      end

   c_initialize_in(str: STRING) is
      do
         str.append(fz_null)
      end

   jvm_descriptor_in(str: STRING) is
      do
         str.append(jvm_root_descriptor)
      end

   jvm_target_descriptor_in(str: STRING) is
      do
      end

   jvm_return_code is
      do
         code_attribute.opcode_areturn
      end

   jvm_check_class_invariant is
      do
         standard_jvm_check_class_invariant
      end

   jvm_push_local(offset: INTEGER) is
      do
         code_attribute.opcode_aload(offset)
      end

   jvm_push_default: INTEGER is
      do
         Result := 1
         code_attribute.opcode_aconst_null
      end

   jvm_write_local_creation, jvm_write_local(offset: INTEGER) is
      do
         code_attribute.opcode_astore(offset)
      end

   jvm_xnewarray is
      local
         idx: INTEGER
      do
         idx := constant_pool.idx_jvm_root_class
         code_attribute.opcode_anewarray(idx)
      end

   jvm_xastore is
      do
         code_attribute.opcode_aastore
      end

   jvm_xaload is
      do
         code_attribute.opcode_aaload
      end

   jvm_if_x_eq: INTEGER is
      do
         Result := code_attribute.opcode_if_acmpeq
      end

   jvm_if_x_ne: INTEGER is
      do
         Result := code_attribute.opcode_if_acmpne
      end

   jvm_to_reference is
      do
      end

   jvm_expanded_from_reference(other: E_TYPE): INTEGER is
      do
         check False end
      end

   jvm_convert_to(destination: E_TYPE): INTEGER is
      do
         check
            destination.is_reference
         end
         Result := 1
      end

   jvm_standard_is_equal is
      local
         ca: like code_attribute; cp: like constant_pool; idx: INTEGER
      do
         ca := code_attribute
         cp := constant_pool
         idx := jvm_item_field_idx
         run_class.opcode_checkcast
         ca.opcode_getfield(idx,0)
         ca.opcode_swap
         run_class.opcode_checkcast
         ca.opcode_getfield(idx,0)
         expanded_type.jvm_standard_is_equal
      end

   short_hook is
      do
         expanded_type.short_hook
      end

feature {RUN_CLASS}

   jvm_prepare_item_field is
      local
         name_idx, descriptor: INTEGER
         cp: like constant_pool
      do
         cp := constant_pool
         name_idx := cp.idx_utf8(as_item)
         tmp_string.clear
         expanded_type.jvm_descriptor_in(tmp_string)
         descriptor := cp.idx_utf8(tmp_string)
         field_info.add(1,name_idx,descriptor)
      end

feature {TYPE_REFERENCE_VISITOR}

   accept(visitor: TYPE_REFERENCE_VISITOR) is
      do
         visitor.visit_type_reference(Current)
      end

feature {NONE}

   written_mark_memory: STRING
	 -- To cache `written_mark' value.
   
   run_type_memory: E_TYPE
	 -- To cache `run_type' value.
   
   make(sp: like start_position; et: like expanded_type) is
      require
	 not sp.is_unknown
         et /= Void
      do
         start_position := sp
         expanded_type := et
	 if et.is_bit then
	    smart_eiffel.bit_n_ref_is_nyi_error(et.start_position)
	 end
	 debug
	    check written_mark /= Void end
	 end
      end

   set(sp: like start_position;
       et: like expanded_type;
       wmm: like written_mark_memory;
       rtm: like run_type_memory) is
      require
	 not sp.is_unknown
	 et.is_expanded
	 rtm.is_reference
	 rtm.run_type = rtm
      do
	 start_position := sp
	 expanded_type := et
	 written_mark_memory := wmm
	 run_type_memory := rtm
      ensure
	 start_position = sp
	 expanded_type = et
	 written_mark_memory = wmm
	 run_type_memory = rtm
      end
   
   jvm_item_field_idx: INTEGER is
      local
         c, n, t: INTEGER; cp: like constant_pool
      do
         cp := constant_pool
         c := run_class.jvm_constant_pool_index
         n := cp.idx_utf8(as_item)
         tmp_string.clear
         expanded_type.jvm_descriptor_in(tmp_string)
         t := cp.idx_utf8(tmp_string)
         Result := cp.idx_fieldref5(c,n,t)
      end

end -- TYPE_REFERENCE
