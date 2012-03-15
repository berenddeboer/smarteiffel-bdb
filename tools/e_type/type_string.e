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
class TYPE_STRING
   --
   -- Handling of the "STRING" type mark.
   --
   
inherit E_TYPE

creation make

feature

   id: INTEGER is 7

   is_string,
   is_reference,
   need_c_struct,
   is_run_type: BOOLEAN is True

   is_none,
   is_bit,
   is_pointer,
   is_integer,
   is_character,
   is_boolean,
   is_real,
   is_double,
   is_expanded,
   is_separate,
   is_basic_eiffel_expanded,
   is_dummy_expanded,
   is_user_expanded,
   is_generic,
   is_array,
   is_any,
   is_anchored,
   is_like_current,
   is_like_argument,
   is_like_feature: BOOLEAN is False

   jvm_method_flags: INTEGER is 17

   base_class_name: CLASS_NAME

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
         Result := base_class_name
      end

   c_sizeof: INTEGER is
      do
         Result := c_sizeof_pointer
      end

   generic_list: ARRAY[E_TYPE] is
      do
         fatal_error_generic_list
      end

   local_from_separate: E_TYPE is
      do
	 check False end
      end

   set_at_run_time is
      local
         bc: BASE_CLASS
         rc: RUN_CLASS
         rf: RUN_FEATURE
      once
         bc := type_string.base_class
         rc := type_string.run_class
         rc.set_at_run_time
         rf := rc.get_feature_with(as_capacity)
         rf := rc.get_feature_with(as_count)
         rf := rc.get_feature_with(as_storage)
         rf.result_type.run_class.set_at_run_time
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
         standard_c_struct
         standard_c_object_model
      end

   c_initialize is
      do
         cpp.put_string(fz_null)
      end

   c_initialize_in(str: STRING) is
      do
         str.append(fz_null)
      end

   run_type: E_TYPE is
      do
         Result := Current
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
         code_attribute.opcode_aconst_null
         Result := 1
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
         check
            False
         end
      end

   jvm_convert_to(destination: E_TYPE): INTEGER is
      do
         Result := 1
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
      do
         if other.is_separate then
            Result := base_class = other.base_class
         end
         if is_separate and then not other.is_separate then
            error_handler.add_position(start_position)
            error_handler.add_position(other.start_position)
            fatal_error(fz_sc1)
         elseif not Result then
            if other.is_string then
               Result := True
            else
               Result := base_class.is_subclass_of(other.base_class)
            end
         end
         if not Result then
            error_handler.type_error(Current,other)
         end
      end

   smallest_ancestor(other: E_TYPE): E_TYPE is
      local
         rto: E_TYPE
         bc, bc2: BASE_CLASS
      do
         rto := other.run_type
         if rto.is_string then
            Result := Current
         elseif rto.is_none then
            Result := Current
         elseif rto.is_any then
            Result := rto
         elseif rto.is_expanded then
            Result := rto.smallest_ancestor(Current)
         else
            bc := base_class
            bc2 := rto.base_class
            if bc2.is_subclass_of(bc) then
               Result := Current
            elseif bc.is_subclass_of(bc2) then
               Result := rto
            else
               Result := type_any
            end
         end
      end

   start_position: POSITION is
      do
         Result := base_class_name.start_position
      end

   to_runnable(rt: E_TYPE): like Current is
      do
         Result := Current
      end

   written_mark, run_time_mark: STRING is
      do
         Result := as_string
      end

   c_type_for_argument_in(str: STRING) is
      do
         str.append(fz_t0_star)
      end

   c_type_for_target_in(str: STRING) is
      do
         str.append(once "T7*")
      end

   c_type_for_result_in(str: STRING) is
      do
         str.append(fz_t0_star)
      end

   stupid_switch(run_time_set: RUN_TIME_SET): BOOLEAN is
      do
         Result := True
      end

feature {RUN_CLASS,E_TYPE}

   need_gc_mark_function: BOOLEAN is True

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

feature {E_TYPE}

   frozen short_hook is
      do
         short_print.a_class_name(base_class_name)
      end

feature {TYPE_STRING_VISITOR}

   accept(visitor: TYPE_STRING_VISITOR) is
      do
         visitor.visit_type_string(Current)
      end

feature {NONE}

   make(sp: like start_position) is
      do
         !!base_class_name.make(as_string,sp)
      end

invariant

   written_mark = as_string

end -- TYPE_STRING

