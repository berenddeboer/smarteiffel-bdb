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
class TYPE_CLASS

inherit E_TYPE

creation make

feature

   base_class_name: CLASS_NAME

   is_run_type: BOOLEAN is true

   is_bit,
   is_pointer,
   is_generic,
   is_basic_eiffel_expanded,
   is_array,
   is_none,
   is_any,
   is_string,
   is_integer,
   is_real,
   is_double,
   is_character,
   is_boolean,
   is_anchored,
   is_like_current,
   is_like_argument,
   is_like_feature: BOOLEAN is false

   jvm_method_flags: INTEGER is 17

   actual_reference(destination: E_TYPE): E_TYPE is
      local
         sp: POSITION
      do
	 sp := start_position
	 if sp.is_unknown then
	    if destination /= Void then
	       sp := destination.start_position
	    end
	 end
         create {TYPE_REFERENCE} Result.make(sp,run_type)
      end

   actual_separate(destination: E_TYPE): E_TYPE is
      local
         sp: POSITION
      do
         sp := destination.start_position
         Result := separate_tools.create_type_separate(sp,Current)
      end

   start_lookup_name: CLASS_NAME is
      do
         Result := base_class_name
      end

   is_expanded: BOOLEAN is
      do
         Result := base_class.is_expanded
      end

   is_separate: BOOLEAN is
      do
         Result := base_class.is_separate
      end

   is_reference: BOOLEAN is
      do
         Result := not base_class.is_expanded
      end

   is_user_expanded: BOOLEAN is
      do
         Result := is_expanded
      end

   is_dummy_expanded: BOOLEAN is
      do
         if is_expanded then
            Result := run_class.writable_attributes = Void
         end
      end

   generic_list: ARRAY[E_TYPE] is
      do
         fatal_error_generic_list
      end

   local_from_separate: E_TYPE is
      do
	 not_yet_implemented
      end

   stupid_switch(run_time_set: RUN_TIME_SET): BOOLEAN is
      do
         Result := true
      end

   id: INTEGER is
      do
         Result := base_class.id
      end

   c_sizeof: INTEGER is
      do
         if is_reference then
            Result := c_sizeof_pointer
         else
            Result := run_class.c_sizeof
         end
      end

   smallest_ancestor(other: E_TYPE): E_TYPE is
      local
         rto: E_TYPE
         bc, bc2: BASE_CLASS
      do
         rto := other.run_type
         if other.is_none then
            Result := Current
         elseif rto.is_any then
            Result := rto
         else
            bc := base_class
            bc2 := rto.base_class
            if bc2 = bc then
               Result := Current
            elseif bc2.is_subclass_of(bc) then
               Result := Current
            elseif bc.is_subclass_of(bc2) then
               Result := rto
            elseif rto.is_expanded and then not is_expanded then
               Result := rto.smallest_ancestor(Current)
            else
               Result := bc2.smallest_ancestor(rto,Current)
            end
         end
      end

   jvm_descriptor_in(str: STRING) is
      do
         if is_reference then
            str.append(jvm_root_descriptor)
         else
            run_class.jvm_type_descriptor_in(str)
         end
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
         if is_reference then
            code_attribute.opcode_aconst_null
         else
            run_class.jvm_expanded_push_default
         end
      end

   jvm_write_local_creation(offset: INTEGER) is
      do
         code_attribute.opcode_astore(offset)
      end

   jvm_write_local(offset: INTEGER) is
      do
	 if not is_expanded then
	    code_attribute.opcode_astore(offset)
	 else
	    jvm_write_local_expanded(offset)
	 end
      end
   
   jvm_write_local_expanded(offset: INTEGER) is
      local
	 rc: RUN_CLASS; wa: ARRAY[RUN_FEATURE_2]
      do
         rc := run_class
	 wa := rc.writable_attributes
	 code_attribute.opcode_aload(offset)
	 code_attribute.opcode_swap
	 jvm.fields_by_fields_expanded_copy(wa)
	 code_attribute.opcode_pop2
      end
   
   jvm_xnewarray is
      local
         idx: INTEGER
      do
         if is_reference then
            idx := constant_pool.idx_jvm_root_class
         else
            check
               is_user_expanded
            end
            idx := run_class.jvm_constant_pool_index
         end
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
         if is_expanded then
            run_class.jvm_to_reference
         end
      end

   jvm_expanded_from_reference(other: E_TYPE): INTEGER is
      do
         check
            false
         end
      end

   jvm_convert_to(destination: E_TYPE): INTEGER is
      do
         if is_reference then
            if destination.is_reference then
               Result := 1
            else
               Result := destination.jvm_expanded_from_reference(Current)
            end
         elseif destination.is_reference then
            jvm_to_reference
            Result := 1
         else
            Result := 1
         end
      end

   jvm_standard_is_equal is
      local
         rc: RUN_CLASS
         wa: ARRAY[RUN_FEATURE_2]
      do
         rc := run_class
         wa := rc.writable_attributes
         jvm.std_is_equal(rc,wa)
      end

   is_a(other: E_TYPE): BOOLEAN is
      local
         bcn, obcn: CLASS_NAME
      do
         if other.is_separate then
            Result := is_a(other.local_from_separate)
         elseif is_separate then
            error_handler.add_position(start_position)
            error_handler.add_position(other.start_position)
            fatal_error(fz_sc1)
	 end
         if not Result then
            bcn := base_class_name
            obcn := other.base_class_name
            if bcn.to_string = obcn.to_string then
               Result := true
            elseif is_reference and then other.is_expanded then
            elseif bcn.is_subclass_of(obcn) then
               if other.is_generic then
                  Result := bcn.base_class.is_a_vncg(Current,other)
               else
                  Result := true
               end
            end
         end
         if not Result then
            error_handler.type_error(Current,other)
         end
      end

   run_type: E_TYPE is
      do
         Result := Current
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
         if is_expanded then
            if need_c_struct then
               standard_c_struct
            end
         end
      end

   c_header_pass4 is
      do
         if is_reference then
            if need_c_struct then
               standard_c_struct
            end
         end
         standard_c_object_model
         standard_c_print_function
      end

   c_type_for_argument_in(buffer: STRING) is
      do
         if is_reference then
            buffer.append(fz_t0_star)
         elseif is_dummy_expanded then
            buffer.append(fz_int)
         else
            buffer.extend('T')
            id.append_in(buffer)
         end
      end

   c_type_for_target_in(buffer: STRING) is
      do
         if is_dummy_expanded then
            buffer.append(fz_int)
         else
            buffer.extend('T')
            id.append_in(buffer)
            buffer.extend('*')
         end
      end

   c_type_for_result_in(buffer: STRING) is
      do
         if is_reference then
            buffer.append(fz_t0_star)
         elseif is_dummy_expanded then
            buffer.append(fz_int)
         else
            buffer.extend('T')
            id.append_in(buffer)
         end
      end

   need_c_struct: BOOLEAN is
      do
         if is_dummy_expanded then
         elseif is_expanded then
            Result := true
         elseif run_class.is_tagged then
            Result := true
         else
            Result := run_class.writable_attributes /= Void
         end
      end

   start_position: POSITION is
      do
         Result := base_class_name.start_position
      end

   to_runnable(ct: E_TYPE): like Current is
      local
         bc: BASE_CLASS
      do
         bc := base_class
         if bc.is_expanded and then not check_memory.fast_has(bc) then
            check_memory.add_last(bc)
            run_class.set_at_run_time
         end
         if bc.formal_generic_list /= Void then
            error_handler.add_position(bc.formal_generic_list.start_position)
            error_handler.add_type(Current," is generic. Wrong type mark.")
            error_handler.print_as_fatal_error
         end
         Result := Current
      end

   written_mark, run_time_mark: STRING is
      do
         Result := base_class_name.to_string
      end

   c_initialize is
      do
         if is_expanded then
            c_initialize_expanded
         else
            cpp.put_string(fz_null)
         end
      end

   c_initialize_in(str: STRING) is
      do
         if is_expanded then
            if need_c_struct then
               run_class.c_object_model_in(str)
            else
               str.extend('0')
            end
         else
            str.append(fz_null)
         end
      end

feature {RUN_CLASS,E_TYPE}

   need_gc_mark_function: BOOLEAN is
      do
         if is_reference then
            Result := true
         else
            Result := run_class.gc_mark_to_follow
         end
      end

   just_before_gc_mark_in(str: STRING) is
      do
         if is_reference then
            standard_just_before_gc_mark_in(str)
         end
      end

   gc_info_in(str: STRING) is
      do
         if is_reference then
            standard_gc_info_in(str)
         end
      end

   gc_define1 is
      do
         if is_reference then
            standard_gc_define1
         end
      end

   gc_define2 is
      do
         if is_reference then
            standard_gc_define2
         else
            standard_gc_define2_for_expanded
         end
      end

feature {E_TYPE}

   frozen short_hook is
      do
         short_print.a_class_name(base_class_name)
      end

feature {TYPE_CLASS_VISITOR}

   accept(visitor: TYPE_CLASS_VISITOR) is
      do
         visitor.visit_type_class(Current)
      end

feature {NONE}

   make(bcn: like base_class_name) is
      require
         not bcn.predefined
      do
         base_class_name := bcn
	 debug
	    debug_info := bcn.to_string
	 end
      ensure
         base_class_name = bcn
      end

   debug_info: STRING; -- To view more under sedb.

   check_memory: FIXED_ARRAY[BASE_CLASS] is
      once
         !!Result.with_capacity(16)
      end

end -- TYPE_CLASS

