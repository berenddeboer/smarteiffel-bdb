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
class TYPE_GENERIC
   --
   -- Handling of generic type mark excluding ARRAY, NATIVE_ARRAY, 
   -- and all agents types.

inherit  E_TYPE

creation make

creation {TYPE_GENERIC} set

feature

   is_generic: BOOLEAN is True

   is_basic_eiffel_expanded,
   is_array,
   is_none,
   is_any,
   is_like_current,
   is_like_argument,
   is_like_feature,
   is_bit,
   is_string,
   is_integer,
   is_character,
   is_boolean,
   is_real,
   is_double,
   is_anchored,
   is_pointer
   : BOOLEAN is False
   
   jvm_method_flags: INTEGER is 17

   base_class_name: CLASS_NAME

   generic_list: ARRAY[E_TYPE]

   written_mark: STRING is
      local
	 i: INTEGER; gl: like generic_list
      do
	 Result := written_mark_memory
	 if Result = Void then
	    gl := generic_list
	    -- To force first the computation of `generic_list' items:
	    from
	       i := gl.upper
	    until
	       i < 1
	    loop
	       if gl.item(i).written_mark = Void then
		  check False end
	       end
	       i := i - 1
	    end
	    -- Now compute the `Result':
	    Result := once ".....         local unique buffer          ....."
	    from
	       Result.copy(base_class_name.to_string)
	       Result.extend('[')
	       i := 1
	    until
	       i > gl.upper
	    loop
	       Result.append(gl.item(i).written_mark)
	       i := i + 1
	       if i <= gl.upper then
		  Result.extend(',')
	       end
	    end
	    Result.extend(']')
	    Result := string_aliaser.item(Result)
	    written_mark_memory := Result
	 end
      end

   local_from_separate: E_TYPE is
      do
	 check False end
      end

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
         create {TYPE_REFERENCE} Result.make(sp, run_type)
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

   is_run_type: BOOLEAN is
      do
         Result := run_type /= Void
      end

   run_type: like Current
	 -- Non Void indicates `is_run_type'.
         -- (This is always a completely static type mark.)

   to_runnable(ct: E_TYPE): like Current is
      local
         i: INTEGER; rgl: like generic_list; t1, t2: E_TYPE
	 new_rgl_flag: BOOLEAN
      do
         if written_runnable_flag then
	    to_runnable_for_all(ct, generic_list)
	    basic_checks
	    Result := Current
         else
            from
	       if run_type = Void then
		  rgl := generic_list.twin
		  new_rgl_flag := True
	       else
		  rgl := run_type.generic_list
	       end
               i := rgl.upper
            until
               i = 0
            loop
               t1 := generic_list.item(i)
               t2 := t1.to_runnable(ct)
               if t2 = Void or else not t2.is_run_type then
                  error_handler.add_type(t1, fz_is_invalid)
                  error_handler.print_as_error
                  i := 0
               else
		  t2 := t2.run_type
		  if new_rgl_flag then
		     rgl.put(t2, i)
		  elseif t2 = rgl.item(i)
		     or else t2.run_time_mark = rgl.item(i).run_time_mark
		   then
		     -- We are lucky, because this is the same one.
		  else
		     -- We have to actually create a new `rgl':
		     rgl := rgl.twin
		     new_rgl_flag := True
		     rgl.put(t2, i)
		  end
		  if t2.is_expanded then
		     t2.run_class.set_at_run_time
		  end
		  i := i - 1
	       end
            end
	    if new_rgl_flag then
	       if run_type = Void then
		  create run_type.make(base_class_name, rgl)
		  check run_type.written_runnable_flag end
		  run_type.basic_checks
		  Result := Current
	       else
		  create Result.make(base_class_name, rgl)
		  check Result.written_runnable_flag end
		  Result.basic_checks
		  create Result.set(base_class_memory,
				    Result.run_class,
				    base_class_name,
				    generic_list,
				    written_mark_memory,
				    Result)
	       end
	    else
	       -- We are lucky:
	       Result := Current
	    end
         end
      end

   c_sizeof: INTEGER is
      do
         if is_reference then
            Result := c_sizeof_pointer
         else
            Result := run_class.c_sizeof
         end
      end

   stupid_switch(run_time_set: RUN_TIME_SET): BOOLEAN is
      local
         i: INTEGER
      do
         from
            i := generic_list.upper
            Result := True
         until
            not Result or else i = 0
         loop
            Result := generic_list.item(i).stupid_switch(run_time_set)
            i := i - 1
         end
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
         Result := base_class.is_expanded
      end

   is_dummy_expanded: BOOLEAN is
      do
         if is_user_expanded then
            Result := run_class.writable_attributes = Void
         end
      end

   id: INTEGER is
      do
         Result := run_class.id
      end

   run_time_mark: STRING is
      do
         if is_run_type then
            Result := run_type.written_mark
	    if Result.count > 512 then
	       error_handler.add_position(start_position)
	       error_handler.append("Probably infinite or too long generic %
	         %derivation of this type mark (see next warnings to find the %
                 %cause of the problem... and good luck).")
	       error_handler.print_as_warning
	       error_handler.append("The huge generic derivation related to %
	         %the previous warning is: ")
	       error_handler.append(Result)
	       if error_handler.warning_counter > 50 then
		  error_handler.print_as_error
	       else 
		  error_handler.print_as_warning
	       end
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
         if is_expanded then
            run_class.jvm_expanded_push_default
         else
            code_attribute.opcode_aconst_null
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
      end

   jvm_expanded_from_reference(other: E_TYPE): INTEGER is
      do
         check False end
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
         rc: RUN_CLASS; wa: ARRAY[RUN_FEATURE_2]
      do
         rc := run_class
         wa := rc.writable_attributes
         jvm.std_is_equal(rc,wa)
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
            standard_c_object_model
         end
      end

   c_header_pass4 is
      do
         if is_reference then
            if need_c_struct then
               standard_c_struct
               standard_c_object_model
            end
         end
         standard_c_print_function
      end

   c_initialize is
      do
         if run_type.is_expanded then
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

   smallest_ancestor(other: E_TYPE): E_TYPE is
      local
         rto: E_TYPE
      do
         rto := other.run_type
         if other.is_none then
            Result := Current
         elseif rto.is_any then
            Result := rto
         elseif rto.is_a(run_type) then
            Result := run_type
         else
            error_handler.cancel
            if run_type.is_a(rto) then
               Result := rto
            else
               error_handler.cancel
               if rto.is_generic then
                  Result := type_any
                  -- *** NOT CLEVER ENOUGHT... WE SHOULD DO LIKE IN
		  --     TYPE_CLASS.
		  -- ***
               else
                  Result := rto.smallest_ancestor(Current)
               end
            end
         end
      end

   is_a(other: E_TYPE): BOOLEAN is
      local
         i: INTEGER; t1, t2: E_TYPE; gl1, gl2: ARRAY[E_TYPE]
      do
         if other.is_separate then
            Result := base_class = other.base_class
         end
         if is_separate and then not other.is_separate then
            error_handler.add_position(start_position)
            error_handler.add_position(other.start_position)
            fatal_error(fz_sc1)
         elseif not Result then
            if other.is_none then
            elseif run_class = other.run_class then
               Result := True
            elseif other.is_generic then
               if base_class = other.base_class then
                  from
                     Result := True
                     gl1 := run_type.generic_list
                     gl2 := other.run_type.generic_list
                     i := gl1.upper
                  until
                     not Result or else i = 0
                  loop
                     t1 := gl1.item(i).run_type
                     t2 := gl2.item(i).run_type
                     if t1.is_a(t2) then
                        i := i - 1
                     else
                        Result := False
                        error_handler.append(fz_bga)
                        error_handler.extend(' ')
                     end
                  end
               elseif base_class.is_subclass_of(other.base_class) then
                  Result := base_class.is_a_vncg(Current,other)
               end
            else
               check
                  not other.is_generic
               end
               if base_class.is_subclass_of(other.base_class) then
                  Result := True
               end
            end
         end
         if not Result then
            error_handler.type_error(Current,other)
         end
      end

   start_position: POSITION is
      do
         Result := base_class_name.start_position
      end

   need_c_struct: BOOLEAN is
      do
         if is_dummy_expanded then
         elseif is_expanded then
            Result := True
         elseif run_class.is_tagged then
            Result := True
         else
            Result := run_class.writable_attributes /= Void
         end
      end

   c_type_for_argument_in(str: STRING) is
      do
         if is_reference then
            str.append(fz_t0_star)
         elseif is_dummy_expanded then
            str.append(fz_int)
         else
            str.extend('T')
            id.append_in(str)
         end
      end

   c_type_for_target_in(str: STRING) is
      do
         if is_dummy_expanded then
            str.append(fz_int)
         else
            str.extend('T')
            id.append_in(str)
            str.extend('*')
         end
      end

   c_type_for_result_in(str: STRING) is
      do
         if is_reference then
            str.append(fz_t0_star)
         elseif is_dummy_expanded then
            str.append(fz_int)
         else
            str.extend('T')
            id.append_in(str)
         end
      end

feature {RUN_CLASS,E_TYPE}

   need_gc_mark_function: BOOLEAN is
      do
         if is_reference then
            Result := True
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

feature {TYPE_GENERIC}

   written_runnable_flag: BOOLEAN
	 -- True when the corresponding mark is completely static 
	 -- (i.e. written only with static type marks).   
   
   basic_checks is
      local
         bc: BASE_CLASS; fgl: FORMAL_GENERIC_LIST
      do
         bc := base_class
         fgl := bc.formal_generic_list
         if fgl = Void then
            error_handler.add_position(start_position)
            error_handler.append(bc.name.to_string)
            fatal_error(" is not a generic class.")
         elseif fgl.count /= generic_list.count then
            error_handler.add_position(start_position)
            error_handler.add_position(fgl.start_position)
            fatal_error(fz_bnga)
         end
      end
   
feature {E_TYPE}

   frozen short_hook is
      local
         i: INTEGER
      do
         short_print.a_class_name(base_class_name)
         short_print.hook_or("open_sb","[")
         from
            i := 1
         until
            i > generic_list.count
         loop
            generic_list.item(i).short_hook
            if i < generic_list.count then
               short_print.hook_or("tm_sep",",")
            end
            i := i + 1
         end
         short_print.hook_or("close_sb","]")
      end

feature {TYPE_GENERIC_VISITOR}

   accept(visitor: TYPE_GENERIC_VISITOR) is
      do
         visitor.visit_type_generic(Current)
      end

feature {NONE}

   written_mark_memory: STRING
	 -- To cache `written_mark'.
   
   make(bcn: like base_class_name; gl: like generic_list) is
      require
         bcn /= Void
         gl.lower = 1
         not gl.is_empty
      local
	 i: INTEGER; t: E_TYPE
      do
         base_class_name := bcn
         generic_list := gl
	 -- Compute `written_runnable_flag':
	 from
	    written_runnable_flag := True
	    i := generic_list.upper
	 until
	    not written_runnable_flag or else i = 0
	 loop
	    t := gl.item(i)
	    if t.is_run_type then
	       if t.run_type /= t then
		  written_runnable_flag := False
	       end
	    else
	       written_runnable_flag := False
	    end
	    i := i - 1
	 end
	 if written_runnable_flag then
	    run_type := Current
	 end
      ensure
         base_class_name = bcn
         generic_list = gl
      end

   set(bcm: like base_class_memory
       rcm: like run_class_memory
       bcn: like base_class_name
       gl: like generic_list
       wmm: like written_mark_memory; 
       rtm: like run_type) is
      require
	 rcm /= Void
	 bcn /= Void
	 gl /= Void
	 rtm.is_run_type
      do
	 base_class_memory := bcm
	 run_class_memory := rcm
	 base_class_name := bcn
	 generic_list := gl
	 written_mark_memory := wmm
	 run_type := rtm
      ensure
	 base_class_memory = bcm
	 run_class_memory = rcm
	 base_class_name = bcn
	 generic_list = gl
	 written_mark_memory = wmm
	 run_type = rtm
      end

end -- TYPE_GENERIC

