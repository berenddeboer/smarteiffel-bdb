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
class TYPE_ARRAY
   --
   -- Handling of the "ARRAY[FOO]" type mark.
   --
   -- Note: can be implicit when used for the type of manifest arrays.
   --

inherit E_TYPE

creation make

creation {TYPE_ARRAY} with

feature

   is_array,
   is_generic,
   is_reference: BOOLEAN is true

   is_none,
   is_any,
   is_expanded,
   is_separate,
   is_basic_eiffel_expanded,
   is_dummy_expanded,
   is_user_expanded,
   is_anchored,
   is_like_current,
   is_like_argument,
   is_like_feature,
   is_string,
   is_integer,
   is_real,
   is_double,
   is_character,
   is_pointer,
   is_bit,
   is_boolean: BOOLEAN is false

   jvm_method_flags: INTEGER is 17

   need_c_struct: BOOLEAN is true

   base_class_name: CLASS_NAME
         -- Is always "ARRAY" but with the good `start_position'.

   generic_list: ARRAY[E_TYPE]
         -- With exactely one element.

   written_runnable_flag: BOOLEAN
	 -- True when the corresponding mark is completely static 
	 -- (i.e. written only with static type marks).   

   is_run_type: BOOLEAN is
      do
         Result := run_type /= Void
      end

   run_type: like Current
	 -- Non Void indicates `is_run_type'.
         -- (This is always a completely static type mark.)

   written_mark: STRING is
      local
	 etwm: STRING
      do
	 Result := written_mark_memory
	 if Result = Void then
	    -- To force computation of `array_of' first:
	    etwm := array_of.written_mark;
	    -- Now compute the `Result':
	    Result := once ".....         local unique buffer          ....."
	    Result.copy(as_array)
	    Result.extend('[')
	    Result.append(etwm)
	    Result.extend(']')
	    Result := string_aliaser.item(Result)
	    written_mark_memory := Result
	 end
      end

   local_from_separate: E_TYPE is
      do
	 check false end
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
         Result := base_class_name
      end

   c_sizeof: INTEGER is
      do
         Result := c_sizeof_pointer
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

   array_of: E_TYPE is
      do
         Result := generic_list.first
      end

   stupid_switch(run_time_set: RUN_TIME_SET): BOOLEAN is
      do
         Result := generic_list.first.stupid_switch(run_time_set)
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
            false
         end
      end

   jvm_convert_to(destination: E_TYPE): INTEGER is
      do
         Result := 1
      end

   jvm_standard_is_equal is
      local
         rc: RUN_CLASS; wa: ARRAY[RUN_FEATURE_2]
      do
         rc := run_class
         wa := rc.writable_attributes
         jvm.std_is_equal(rc,wa)
      end

   start_position: POSITION is
      do
         Result := base_class_name.start_position
      end

   run_time_mark: STRING is
      do
	 Result := run_type.written_mark
      end

   smallest_ancestor(other: E_TYPE): E_TYPE is
      local
         rto, array_of1, array_of2, array_of3: E_TYPE
         unknown_position: POSITION
      do
         rto := other.run_type
         if rto.is_array then
            array_of1 := array_of.run_type
            array_of2 := rto.generic_list.first
            array_of3 := array_of1.smallest_ancestor(array_of2)
            if array_of3 = array_of1 then
               Result := Current
            elseif array_of3 = array_of2 then
               Result := other
            else
               !TYPE_ARRAY!Result.make(unknown_position,array_of3)
            end
         else
            Result := rto.smallest_ancestor(Current)
         end
      end

   is_a(other: E_TYPE): BOOLEAN is
      local
	 t1, t2: E_TYPE
      do
         if other.is_separate then
            Result := base_class = other.base_class
         end
         if is_separate and then not other.is_separate then
            error_handler.add_position(start_position)
            error_handler.add_position(other.start_position)
            fatal_error(fz_sc1)
         elseif not Result then
            if other.is_array then
               t1 := run_type.generic_list.first
               t2 := other.run_type.generic_list.first
               Result := t1.is_a(t2)
               if not Result then error_handler.extend(' ') end
            elseif base_class.is_subclass_of(other.base_class) then
               if other.is_generic then
                  Result := base_class.is_a_vncg(Current,other)
               else
                  Result := true
               end
            end
         end
         if not Result then
            error_handler.type_error(Current,other)
         end
      end

   to_runnable(ct: E_TYPE): like Current is
      local
         et1, et2, et3, et: E_TYPE
      do
	 if written_runnable_flag then
	    to_runnable_for_all(ct, generic_list)
	    Result := Current
	 else
	    et1 := generic_list.first
	    et2 := et1.to_runnable(ct)
	    if et2 = Void or else not et2.is_run_type then
	       error_handler.add_position(et1.start_position)
	       error_handler.append(fz_bga)
	       error_handler.print_as_fatal_error
	    end
	    et3 := et2.run_type
	    check et3.is_static end
	    if run_type = Void then
	       create run_type.make(start_position, et3)
	       check run_type.written_runnable_flag end
	       Result := Current
	    else
	       et := run_type.generic_list.first
	       check et.is_static end
	       if et = et3 or else et.written_mark = et3.written_mark then
		  -- We are lucky, because this is the same one.
		  Result :=  Current
	       else
		  -- We have to actually create a new one:
		  create Result.make(start_position, et3)
		  check Result.written_runnable_flag end
		  create Result.with(base_class_name, et2, Result)
	       end
	    end
	 end
      end

   id: INTEGER is
      do
         Result := run_class.id
      end

feature {RUN_CLASS,E_TYPE}

   need_gc_mark_function: BOOLEAN is true

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

feature {MANIFEST_ARRAY, E_STRIP}

   load_basic_features is
         -- Force some basic feature to be loaded.
      require
         run_type = Current
      local
         et: E_TYPE; rf: RUN_FEATURE; rc: RUN_CLASS
      do
         et := array_of
         if et.is_expanded then
            et.run_class.set_at_run_time
         end
         rc := run_class
         rf := rc.get_feature_with(as_capacity)
         rf := rc.get_feature_with(as_lower)
         rf := rc.get_feature_with(as_upper)
         rf := rc.get_feature_with(as_storage)
      end

feature {E_TYPE}

   frozen short_hook is
      do
         short_print.a_class_name(base_class_name)
         short_print.hook_or(once "open_sb", once "[")
         generic_list.first.short_hook
         short_print.hook_or(once "close_sb", once "]")
      end

feature {TYPE_ARRAY_VISITOR}

   accept(visitor: TYPE_ARRAY_VISITOR) is
      do
         visitor.visit_type_array(Current)
      end

feature {NONE}

   written_mark_memory: STRING
	 -- To cache `written_mark'.

   make(sp: like start_position; of_what: E_TYPE) is
      require
         not sp.is_unknown
         of_what /= Void
      do
         create base_class_name.make(as_array, sp)
         set_generic_list_with(of_what)
	 -- Compute `written_runnable_flag':
	 if of_what.is_static then
	    written_runnable_flag := True
	    run_type := Current
	 end
      ensure
         start_position = sp
         base_class_name.to_string = as_array
         array_of = of_what
      end

   with(bcn: like base_class_name; of_what: E_TYPE; rt: like run_type) is
      require
	 bcn /= Void
	 not of_what.is_static
	 rt.is_static
      do
	 base_class_name := bcn
	 set_generic_list_with(of_what)
	 run_type := rt
      ensure
	 base_class_name = bcn
	 generic_list.first = of_what
	 run_type = rt
      end

   set_generic_list_with(t: E_TYPE) is
      do
	 create generic_list.make(1, 1)
	 generic_list.put(t, 1)
      end

invariant

   generic_list.count = 1

   generic_list.lower = 1

end -- TYPE_ARRAY
