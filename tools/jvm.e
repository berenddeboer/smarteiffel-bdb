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
class JVM
   --
   -- Handling of Java Virtual Machine byte code generation.
   --

inherit
   CODE_PRINTER

creation make

feature {JVM_VISITOR}

   accept(visitor: JVM_VISITOR) is
      do
         visitor.visit_jvm(Current)
      end

feature {NONE}

   make is
      do
      end

feature

   current_frame: RUN_FEATURE
         -- Current method or current field.

   argument_offset_of(an: ARGUMENT_NAME): INTEGER is
      require
         an /= Void
      do
         Result := current_frame.jvm_argument_offset(an)
      ensure
         Result >= 0
      end

   local_offset_of(ln: LOCAL_NAME): INTEGER is
      require
         ln /= Void
      do
         Result := current_frame.jvm_local_variable_offset(ln)
      ensure
         Result >= 0
      end

   std_is_equal(rc: RUN_CLASS; wa: ARRAY[RUN_FEATURE_2]) is
         -- Produce byte code to compare two operands at top of stack.
         -- Result `1'  (true) or `0' (false) is left at top of stack.
      require
         not rc.current_type.is_basic_eiffel_expanded
      local
         ca: like code_attribute
         rf2: RUN_FEATURE_2
         point, space, i: INTEGER
         branch_index: INTEGER
      do
         ca := code_attribute
         branch_index := ca.get_branch_array_index
         if wa = Void then
            if rc.current_type.is_expanded then
               ca.opcode_pop2
               ca.opcode_iconst_1
            else
               ca.opcode_swap
               ca.opcode_pop
               rc.opcode_instanceof
            end
         else
            if rc.current_type.is_reference then
               ca.opcode_dup
               rc.opcode_instanceof
               ca.add_branch(ca.opcode_ifeq, branch_index)
            end
            from
               i := wa.upper
            until
               i = 0
            loop
               rf2 := wa.item(i)
               space := rf2.result_type.jvm_stack_space - 1
                  ca.opcode_dup2
               space := rc.opcode_getfield(rf2)
               if space = 0 then
                  ca.opcode_swap
               else
                  ca.opcode_dup2_x1
                  ca.opcode_pop2
               end
               space := rc.opcode_getfield(rf2)
               if rf2.result_type.is_user_expanded then
                  std_is_equal_recurse( rf2.result_type.run_class,rf2.result_type.run_class.writable_attributes, branch_index)
               else
                  ca.add_branch(rf2.result_type.jvm_if_x_ne, branch_index)
               end
               i := i - 1
            end
            ca.opcode_pop2
            ca.opcode_iconst_1
            point := ca.opcode_goto
            ca.resolve_branches( branch_index )
            ca.opcode_pop2
            ca.opcode_iconst_0
            ca.resolve_u2_branch(point)
         end
         ca.release_branch_array_index
      end

   std_is_equal_recurse(rc: RUN_CLASS; wa: ARRAY[RUN_FEATURE_2]; calling_branch_index: INTEGER) is
         -- Produce byte code to compare two operands at top of stack.
         -- Called recursively from std_is_equal for user expanded types
         -- if all equal, fall through after taking off two top words on stack
         -- if any not equal, take two top words off stack and jump to std_is_equal last branch point
         -- rc is user expanded
      require
         not rc.current_type.is_basic_eiffel_expanded
      local
         ca: like code_attribute
         rf2: RUN_FEATURE_2
         point, space, i: INTEGER
         branch_index: INTEGER
      do
         ca := code_attribute
         branch_index := ca.get_branch_array_index

         if wa = Void then
            ca.opcode_swap
            ca.opcode_pop
            rc.opcode_instanceof
            ca.add_branch(ca.opcode_ifeq, calling_branch_index)
         else
            from
               i := wa.upper
            until
               i = 0
            loop
               rf2 := wa.item(i)
               space := rf2.result_type.jvm_stack_space - 1
               ca.opcode_dup2
               space := rc.opcode_getfield(rf2)
               if space = 0 then
                  ca.opcode_swap
               else
                  ca.opcode_dup2_x1
                  ca.opcode_pop2
               end
               space := rc.opcode_getfield(rf2)
               if rf2.result_type.is_user_expanded then
                  std_is_equal_recurse( rf2.result_type.run_class,rf2.result_type.run_class.writable_attributes, branch_index)
               else
                  ca.add_branch(rf2.result_type.jvm_if_x_ne, branch_index)
               end
               i := i - 1
            end
            ca.opcode_pop2
            point := ca.opcode_goto
            ca.resolve_branches( branch_index )
            ca.opcode_pop2
            ca.add_branch(ca.opcode_goto, calling_branch_index)
            ca.resolve_u2_branch(point)
         end
         ca.release_branch_array_index
      end

   fields_by_fields_copy(wa: ARRAY[RUN_FEATURE_2]) is
         -- Stack : ..., destination, model => ..., destination
         -- Assume the checkcast is already done.
      local
         ca: like code_attribute
         rf2: RUN_FEATURE_2
         idx, space, i: INTEGER
      do
         ca := code_attribute
         if wa /= Void then
            from
               i := wa.upper
            until
               i = 0
            loop
               ca.opcode_dup2
               rf2 := wa.item(i)
               idx := constant_pool.idx_fieldref(rf2)
               space := rf2.result_type.jvm_stack_space
               ca.opcode_getfield(idx,space - 1)
               ca.opcode_putfield(idx,-(space + 1))
               i := i - 1
            end
         end
         ca.opcode_pop
      end

   fields_by_fields_expanded_copy(wa: ARRAY[RUN_FEATURE_2]) is
         -- Stack : ..., destination, model => ..., destination
         -- Assume the checkcast is already done.
      local
         ca: like code_attribute; rf2: RUN_FEATURE_2
	 idx, idx1, space, i: INTEGER; rc: RUN_CLASS
         wa1: ARRAY[RUN_FEATURE_2]; rt: E_TYPE
      do
         ca := code_attribute
         if wa /= Void then
            from
               i := wa.upper
            until
               i = 0
            loop
               rf2 := wa.item(i)
	       rt := rf2.result_type.run_type
               if rt.is_basic_eiffel_expanded or else rt.is_reference 
		  or else rt.is_native_array
		then
                  ca.opcode_dup2
                  idx := constant_pool.idx_fieldref(rf2)
                  space := rt.jvm_stack_space
                  ca.opcode_getfield(idx,space - 1)
                  ca.opcode_putfield(idx,-(space + 1))
               elseif rt.is_bit then
                  ca.opcode_dup2
                  idx := constant_pool.idx_fieldref(rf2)
                  space := rt.jvm_stack_space
                  ca.opcode_getfield(idx,space - 1)
                  idx1 := constant_pool.idx_methodref3(fz_java_util_bitset,fz_a6,fz_a7)
                  ca.opcode_invokevirtual(idx1,0)
                  idx1 := constant_pool.idx_class2( fz_java_util_bitset )
                  ca.opcode_checkcast( idx1 )
                  ca.opcode_putfield(idx,-(space + 1))
               else -- is_expanded
                  ca.opcode_dup2
                  idx := constant_pool.idx_fieldref(rf2)
                  space := rt.jvm_stack_space
                  ca.opcode_getfield(idx,space - 1)
                  ca.opcode_swap
                  ca.opcode_getfield(idx,space - 1)
                  ca.opcode_swap
                  rc := rt.run_class
                  wa1 := rc.writable_attributes
                  fields_by_fields_expanded_copy(wa1)
                  ca.opcode_pop2
               end
               i := i - 1
            end
         end
      end

feature {RUN_FEATURE,NATIVE_SMART_EIFFEL}

   add_field(rf: RUN_FEATURE) is
      require
         rf /= Void
      do
         check
            not fields.fast_has(rf)
         end
         fields.add_last(rf)
      ensure
         fields.fast_has(rf)
      end

feature {SMART_EIFFEL}

   prepare_output_directory is
         -- A new output directory is created or the content of the old
         -- existing one is cleared.
      require
         smart_eiffel.is_ready
      local
         executable_name: STRING
         basic_directory: BASIC_DIRECTORY
      do
         executable_name := ace.executable_name
         if executable_name = Void then
            executable_name := ace.root_class_name.twin
            executable_name.to_lower
         elseif executable_name.has_suffix(class_suffix) then
            executable_name.remove_suffix(class_suffix)
         end
         echo.put_string("Trying to prepare directory %"")
         echo.put_string(executable_name)
         echo.put_string("%" to store Java byte code.%N")
         basic_directory.connect_to(executable_name)
         if basic_directory.is_connected then
            basic_directory.disconnect
            basic_directory.remove_files_of(executable_name)
	    -- *******
            -- Because a bug of BASIC_DIRECTORY.remove_files_of under
	    -- WINDOWS, we may need to recreate the directory itself :
            basic_directory.connect_to(executable_name)
            if not basic_directory.is_connected then
               if basic_directory.create_new_directory(executable_name) then
               end
            end
	    -- *******
         elseif basic_directory.create_new_directory(executable_name) then
         end
      ensure
         ace.executable_name /= Void
      end

   write_jvm_root_class is
      local
         idx: INTEGER
         cp: like constant_pool
         ca: like code_attribute
         executable_name: STRING
      do
         cp := constant_pool
         ca := code_attribute
         executable_name := ace.executable_name
	 out_file_path.copy(executable_name)
	 system_tools.file_path(out_file_path,fz_jvm_root)
	 out_file_path.append(class_suffix)
         bfw_connect(out_file,out_file_path)
         start_basic
         this_class_idx := cp.idx_class2(jvm_root_class)
         super_class_idx := cp.idx_java_lang_object
         -- Fields :
         args_field
         manifest_string_pool.jvm_define_fields
         once_routine_pool.jvm_define_fields
         if ace.no_check then
            field_info.add(9,cp.idx_utf8(fz_58),cp.idx_utf8(fz_41))
         end
         -- Methods :
         method_info.add_init(fz_java_lang_object)
         -- The _initialize_eiffel_runtime static method :
         current_frame := Void
         method_info.start(9,fz_28,fz_23)
         -- Set `args' field to store command line arguments.
         ca.opcode_aload_0
         ca.opcode_putstatic(args_field_idx,-1)
         manifest_string_pool.jvm_initialize_fields
         once_routine_pool.jvm_initialize_fields
         if ace.no_check then
            idx := cp.idx_fieldref3(jvm_root_class,fz_58,fz_41)
            ca.opcode_iconst_0
            ca.opcode_putstatic(idx,-1)
         end
         ca.opcode_return
         method_info.finish
         -- For switches :
         switch_collection.jvm_define
         
         idx := cp.idx_class2( "java/io/Serializable" )
         interface_info.add( idx )
         
         finish_class
      end

   write_main_class(rf3: RUN_FEATURE_3) is
         -- Write Java Byte Code for main class to call `rf3'.
      require
         rf3 /= Void
         smart_eiffel.is_ready
      local
         idx: INTEGER
         cp: like constant_pool
         ca: like code_attribute
      do
         cp := constant_pool
         ca := code_attribute
         out_file_path.copy(ace.executable_name)
         out_file_path.append(class_suffix)
         bfw_connect(out_file,out_file_path)
         start_basic
         this_class_idx := cp.idx_class2(ace.executable_name)
         super_class_idx := cp.idx_java_lang_object
         -- Methods :
         --    The main method :
         current_frame := Void
         method_info.add_init(fz_java_lang_object)
         method_info.start(9,fz_main,fz_23)
         ca.opcode_aload_0
         idx := cp.idx_methodref3(jvm_root_class,fz_28,fz_23)
         ca.opcode_invokestatic(idx,0)
         rf3.run_class.jvm_basic_new
         idx := cp.idx_methodref(rf3)
         ca.opcode_invokevirtual(idx,-1)
         ca.opcode_return
         method_info.finish
         finish_class
      end

feature {AGENT_POOL}

   write_super_agent_class is
	 -- The deferred one, without attribute and only deferred
	 -- wrappers.
      local
         cp: like constant_pool; ca: like code_attribute
         executable_name, class_name: STRING
      do
         cp := constant_pool
         ca := code_attribute
         executable_name := ace.executable_name
         out_file_path.copy(executable_name)
	 system_tools.file_path(out_file_path,once "_agent")
	 out_file_path.append(class_suffix)
         bfw_connect(out_file,out_file_path)
         start_basic
	 class_name := executable_name.twin
	 class_name.extend('/')
	 class_name.append("_agent")
         this_class_idx := cp.idx_class2(class_name)
	 agent_pool.jvm_define_deferred_methods
         finish_class
      end

   write_agent_class(e_agent:E_AGENT) is
	 -- *** THIS IS DEAD CODE TO BE REMOVED ????
	 --     D. Colnet (june 7 2003)
	 -- ***
-- ***      local
-- ***         cp: like constant_pool
-- ***         ca: like code_attribute
-- ***         executable_name: STRING
-- ***         class_name,descripteur:STRING
-- ***	 i,place:INTEGER
-- ***	 arg_courant:EXPRESSION
      do
-- ***        cp := constant_pool
-- ***        ca := code_attribute
-- ***        executable_name:=ace.executable_name
-- ***        out_file_path.copy(executable_name)
-- ***	system_tools.file_path(out_file_path,("_agent" + e_agent.launcher_id.to_string))
-- ***	out_file_path.append(class_suffix)
-- ***        bfw_connect(out_file,out_file_path)
-- ***        start_basic
-- ***        this_class_idx := cp.idx_class2("_agent"+e_agent.launcher_id.to_string)
-- ***	super_class_idx := cp.idx_class2("_agent")
-- ***        class_name:="_agent/_agent"+e_agent.launcher_id.to_string
-- ***	descripteur:=""
-- ***        from
-- ***	  i := 1
-- ***	until
-- ***	  i>e_agent.arguments.count
-- ***	loop
-- ***	  if (e_agent.is_closed_argument(i)) then
-- ***	    arg_courant:=e_agent.arguments.expression(i)
-- ***	    arg_courant.result_type.jvm_descriptor_in(descripteur)
-- ***	    place:=arg_courant.result_type.jvm_stack_space
-- ***	    field_info.add(9,cp.idx_utf8(("a"+i.to_string)),cp.idx_utf8(descripteur))
-- ***	    ca.opcode_dup
-- ***	  end;--if
-- ***	  i:=i+1
-- ***        end;--loop
-- ***	agent_pool.ajout_call_full(e_agent.launcher_id)
-- ***        finish_class
      end

feature {CODE_ATTRIBUTE}

   max_locals: INTEGER is
      do
         if current_frame /= Void then
            Result := current_frame.jvm_max_locals
         else
            Result := 4
         end
      end

feature {RUN_CLASS,SWITCH_COLLECTION}

   set_current_frame(cf: like current_frame) is
      do
         current_frame := cf
      end

feature {CP_INFO}

   b_put_u1(byte: CHARACTER) is
      require
         byte.code <= 255
      do
         out_file.put_byte(byte.code)
      end

feature {CONSTANT_POOL,FIELD_INFO,METHOD_INFO,INTERFACE_INFO,CLASSFILE_ATTRIBUTE}

   b_put_u2(u2: INTEGER) is
      do
         b_put_u1((u2 // 256).to_character)
         b_put_u1((u2 \\ 256).to_character)
      end

feature {CP_INFO,FIELD_INFO,METHOD_INFO,INTERFACE_INFO}

   b_put_byte_string(str: STRING) is
      require
         str /= Void
      local
         i: INTEGER
      do
         from
            i := 1
         until
            i > str.count
         loop
            b_put_u1(str.item(i))
            i := i + 1
         end
      end

feature {NATIVE_SMART_EIFFEL}

   push_se_argc is
      local
         ca: like code_attribute
      do
         ca := code_attribute
         ca.opcode_getstatic(args_field_idx,1)
         ca.opcode_arraylength
         ca.opcode_iconst_1
         ca.opcode_iadd
      end

   push_se_argv is
      local
         point1, point2, i: INTEGER
         ca: like code_attribute
      do
         ca := code_attribute
         ca.opcode_getstatic(args_field_idx,1)
         i := push_ith_argument(1)
         ca.opcode_dup
         point1 := ca.opcode_ifeq
         ca.opcode_iconst_1
         ca.opcode_isub
         ca.opcode_aaload
         point2 := ca.opcode_goto
         ca.resolve_u2_branch(point1)
         ca.opcode_pop2
         i := constant_pool.idx_string(ace.executable_name)
         ca.opcode_ldc(i)
         ca.resolve_u2_branch(point2)
         ca.opcode_java_string2eiffel_string
      end

feature {CALL_PROC_CALL}

   call_proc_call_mapping(cpc: CALL_PROC_CALL) is
      local
         target: EXPRESSION; target_type: E_TYPE; rc: RUN_CLASS
         run_time_set: RUN_TIME_SET; switch: SWITCH; rf: RUN_FEATURE
         result_type: E_TYPE
      do
         target := cpc.target
         target_type := target.result_type.run_type
         rf := cpc.run_feature
         if target.is_current then
            push_direct(cpc)
            rf.mapping_jvm
            pop
         elseif target.is_manifest_string then
            push_direct(cpc)
            rf.mapping_jvm
            pop
         elseif target_type.is_expanded then
            push_direct(cpc)
            rf.mapping_jvm
            pop
         else
            run_time_set := target_type.run_class.run_time_set
            check
               run_time_set.count > 0
            end
            if run_time_set.count = 1 then
               push_check(cpc)
               rf := run_time_set.first.dynamic(rf)
               rf.mapping_jvm
               pop
            else
               switched_call_count := switched_call_count + 1
               switch.jvm_mapping(cpc)
            end
         end
         result_type := rf.result_type
         -- Optional checkcast for result :
         if result_type /= Void then
            if not result_type.is_none then
               rc := result_type.run_class
               if rc /= Void then
                  run_time_set := rc.run_time_set
                  if run_time_set.count = 1 then
                     run_time_set.first.opcode_checkcast
                  end
               end
            end
         end
      end

feature {NATIVE_SMART_EIFFEL}

   has_method_name( n: STRING ): BOOLEAN is
      local
         i: INTEGER
         rf: RUN_FEATURE
      do
         from
            i := methods.upper
         until
            i < 0 or Result
         loop
            rf := methods.item(i)
            if n = rf.name.to_string then
               Result := True
            end
            i := i - 1
         end
      end

feature {RUN_CLASS}

   prepare_fields is
      local
         i: INTEGER
         rf: RUN_FEATURE
      do
         from
            i := fields.upper
         until
            i < 0
         loop
            rf := fields.item(i)
            rf.jvm_define
            i := i - 1
         end
      end

   prepare_methods is
      local
         i: INTEGER
      do
         from
            i := methods.upper
         until
            i < 0
         loop
            set_current_frame(methods.item(i))
            current_frame.jvm_define
            i := i - 1
         end
      end

   start_new_class(rc: RUN_CLASS) is
      require
         ace.executable_name /= Void
      local
         name_idx, type_idx: INTEGER
         cp: like constant_pool
         executable_name: STRING
      do
         classfile_attribute.clear
         cp := constant_pool
         start_basic
         tmp_string.copy(rc.unqualified_name)
         executable_name := ace.executable_name
	 out_file_path.copy(executable_name)
	 system_tools.file_path(out_file_path,tmp_string)
	 out_file_path.append(class_suffix)
         bfw_connect(out_file,out_file_path)
         this_class_idx := rc.jvm_constant_pool_index
         super_class_idx := cp.idx_jvm_root_class
         method_info.add_init(jvm_root_class)
         -- <clinit> :
         method_info.start(9,fz_76,fz_29)
         if smart_eiffel.generating_type_used then
            name_idx := cp.idx_utf8(as_generating_type)
            type_idx := cp.idx_eiffel_string_descriptor
            field_info.add(9,name_idx,type_idx)
            name_idx := cp.idx_fieldref5(this_class_idx,name_idx,type_idx)
            code_attribute.opcode_aconst_null
            code_attribute.opcode_putstatic(name_idx,-1)
         end
         if smart_eiffel.generating_type_used then
            name_idx := cp.idx_utf8(as_generator)
            field_info.add(9,name_idx,type_idx)
            name_idx := cp.idx_fieldref5(this_class_idx,name_idx,type_idx)
            code_attribute.opcode_aconst_null
            code_attribute.opcode_putstatic(name_idx,-1)
         end
         code_attribute.opcode_return
         method_info.finish
         rc.jvm_define_class_invariant
         classfile_attribute.set( rc.run_time_mark )
      end

   finish_class is
         -- Really print the class file.
      do
         put_magic
         put_minor_version
         put_major_version
         constant_pool.write_bytes
         b_put_u2(access_flags)
         b_put_u2(this_class_idx)
         b_put_u2(super_class_idx)
         -- interfaces_count :
			interface_info.write_bytes
         field_info.write_bytes
         method_info.write_bytes
         -- attributes_count :
         classfile_attribute.write_bytes
         out_file.disconnect
         classfile_attribute.clear
      end

   push_expanded_initialize(rf: RUN_FEATURE) is
      do
         stack_push(C_expanded_initialize)
         stack_rf.put(rf,top)
      end

   define_class_invariant_method(ci: CLASS_INVARIANT) is
      require
         ci /= Void
      local
         ca: like code_attribute
         cp: like constant_pool
      do
         ca := code_attribute
         cp := constant_pool
         method_info.start(1,fz_invariant,fz_29)
         stack_push(C_switch)
         ci.compile_to_jvm(True)
         pop
         ca.opcode_return
         method_info.finish
      end

feature {NATIVE}

   inside_twin(cpy: RUN_FEATURE) is
      do
         stack_push(C_inside_twin)
         stack_rf.put(cpy,top)
         cpy.mapping_jvm
         pop
      end

feature {CREATE_TOOLS}

   inside_create_instruction(rf: RUN_FEATURE; cpc: CALL_PROC_CALL) is
      require
         rf /= Void
         cpc /= Void
      do
         stack_push(C_create_instruction)
         stack_rf.put(rf,top)
         stack_cpc.put(cpc,top)
         rf.mapping_jvm
         pop
      end

feature {RUN_FEATURE,NATIVE}

   add_method(rf: RUN_FEATURE) is
      require
         rf /= Void
      do
         check
            not methods.fast_has(rf)
         end
         methods.add_last(rf)
      ensure
         methods.fast_has(rf)
      end

   target_position: POSITION is
      local
         code: INTEGER
      do
         code := stack_code.item(top)
         inspect
            code
         when C_direct_call, C_check_id then
            Result := stack_cpc.item(top).start_position
         when C_inside_twin then
         when C_switch then
         when C_expanded_initialize then
         when C_create_instruction then
            Result := stack_cpc.item(top).start_position
         else
         end
      end

   push_target is
         -- Produce java byte code in order to push target on the
         -- jvm stack.
      local
         code: INTEGER
      do
         code := stack_code.item(top)
         inspect
            code
         when C_direct_call then
            stack_cpc.item(top).target.compile_to_jvm
         when C_check_id then
            opcode_check_id_for(stack_cpc.item(top).target)
         when C_switch then
            code_attribute.opcode_aload_0
         when C_expanded_initialize then
            code_attribute.opcode_dup
         when C_create_instruction then
            code_attribute.opcode_dup
         when C_inside_twin then
            code_attribute.opcode_aload_1
         end
      end

   push_target_as_target is
         -- Same as `push_target' but with class invariant check
         -- and the checkcast opcode.
      local
         target: EXPRESSION
         rc: RUN_CLASS
         code: INTEGER
      do
         code := stack_code.item(top)
         inspect
            code
         when C_direct_call then
            target := stack_cpc.item(top).target
            target.compile_target_to_jvm
         when C_check_id then
            target := stack_cpc.item(top).target
            opcode_check_id_for(target)
         when C_switch then
            code_attribute.opcode_aload_0
            rc := stack_rf.item(top).run_class
            rc.opcode_checkcast
         when C_expanded_initialize then
            code_attribute.opcode_dup
         when C_create_instruction then
            code_attribute.opcode_dup
         when C_inside_twin then
            code_attribute.opcode_aload_1
         when C_precursor then
            stack_rf.item(top).current_type.jvm_push_local(0)
         end
      end

   drop_target is
      local
         code: INTEGER; cpc: CALL_PROC_CALL; call: CALL
      do
         code := stack_code.item(top)
         inspect
            code
         when C_direct_call, C_check_id then
            cpc := stack_cpc.item(top)
            call ?= cpc
            -- if call = Void or else not call.side_effect_free then
            --*** CAD 14 Apr 2003: The line above is very strange! I changed
            -- it with:
            if call /= Void and then not call.side_effect_free then
               call.target.compile_to_jvm
               if call.run_feature.current_type.jvm_stack_space = 1 then
                  code_attribute.opcode_pop
               else
                  code_attribute.opcode_pop2
               end
            end
         when C_switch then
         when C_expanded_initialize then
         when C_create_instruction then
         when C_inside_twin then
         end
      end

   drop_ith_argument(i: INTEGER) is
      local
         space: INTEGER
      do
         from
            space := push_ith_argument(i)
         until
            space = 0
         loop
            code_attribute.opcode_pop
            space := space - 1
         end
      end

   push_arguments: INTEGER is
      local
         code: INTEGER; cpc: CALL_PROC_CALL; eal: EFFECTIVE_ARG_LIST
	 rf, dyn_rf: RUN_FEATURE; fal: FORMAL_ARG_LIST
      do
         code := stack_code.item(top)
         inspect
            code
         when C_direct_call, C_check_id then
            cpc := stack_cpc.item(top)
            eal := cpc.arguments
            if eal /= Void then
               rf := cpc.run_feature
               fal := rf.arguments
               Result := eal.compile_to_jvm(fal)
            end
         when C_switch then
            rf := stack_static_rf.item(top)
            dyn_rf := stack_rf.item(top)
            fal := rf.arguments
            if fal /= Void then
               Result := fal.jvm_switch_push(dyn_rf.arguments)
            end
         when C_expanded_initialize then
            check
               stack_rf.item(top).arguments = Void
            end
         when C_create_instruction then
            cpc := stack_cpc.item(top)
            eal := cpc.arguments
            if eal /= Void then
               rf := stack_rf.item(top)
               fal := rf.arguments
               Result := eal.compile_to_jvm(fal)
            end
         when C_inside_twin then
            Result := push_ith_argument(1)
         when C_precursor then
            eal := stack_args.item(top)
            if eal /= Void then
               rf := stack_rf.item(top)
               fal := rf.arguments
               Result := eal.compile_to_jvm(fal)
            end
         end
      end

   arg_count: INTEGER is
      local
         code: INTEGER; cpc: CALL_PROC_CALL; eal: EFFECTIVE_ARG_LIST
	 rf, dyn_rf: RUN_FEATURE; fal: FORMAL_ARG_LIST;
      do
         code := stack_code.item(top);
         inspect
            code
         when C_direct_call, C_check_id then
            cpc := stack_cpc.item(top);
            eal := cpc.arguments;
            if eal /= Void then
               Result := eal.count;
            end;
         when C_switch then
            rf := stack_static_rf.item(top);
            dyn_rf := stack_rf.item(top);
            fal := rf.arguments;
            if fal /= Void then
               Result := fal.count;
            end;
         when C_expanded_initialize then
         when C_create_instruction then
            cpc := stack_cpc.item(top);
            eal := cpc.arguments;
            if eal /= Void then
               Result := eal.count;
            end;
         when C_inside_twin then
            Result := 1;
         when C_precursor then
            eal := stack_args.item(top);
            if eal /= Void then
               Result := eal.count;
            end;
         end;
      end;

   push_ith_argument(i: INTEGER): INTEGER is
      local
         code: INTEGER
         cpc: CALL_PROC_CALL
         eal: EFFECTIVE_ARG_LIST
         rf, dyn_rf: RUN_FEATURE
         fal: FORMAL_ARG_LIST
      do
         code := stack_code.item(top)
         inspect
            code
         when C_direct_call, C_check_id then
            cpc := stack_cpc.item(top)
            eal := cpc.arguments
            rf := cpc.run_feature
            fal := rf.arguments
            Result := eal.compile_to_jvm_ith(fal,i)
         when C_switch then
            rf := stack_static_rf.item(top)
            dyn_rf := stack_rf.item(top)
            fal := rf.arguments
            Result := fal.jvm_switch_push_ith(dyn_rf.arguments,i)
         when C_expanded_initialize then
            check
               False
            end
         when C_create_instruction then
            cpc := stack_cpc.item(top)
            eal := cpc.arguments
            rf := stack_rf.item(top)
            fal := rf.arguments
            Result := eal.compile_to_jvm_ith(fal,i)
         when C_inside_twin then
            code_attribute.opcode_aload_0
            Result := 1
         end
      end

   assign_target is
      local
         code: INTEGER
         cpc: CALL_PROC_CALL
      do
         code := stack_code.item(top)
         inspect
            code
         when C_direct_call, C_check_id then
            cpc := stack_cpc.item(top)
            cpc.target.jvm_assign
         when C_switch then
            cpc := stack_cpc.item(top)
            cpc.target.jvm_assign
         when C_expanded_initialize then
            check
               False
            end
         when C_create_instruction then
            check
               False
            end
         when C_inside_twin then
            check
               False
            end
         end
      end

   ith_argument_as_manifest_string( i: INTEGER ): STRING is
      local
         code: INTEGER
         cpc: CALL_PROC_CALL
         eal: EFFECTIVE_ARG_LIST
         ms: MANIFEST_STRING
      do
         code := stack_code.item(top)
         inspect
            code
         when C_direct_call, C_check_id then
            cpc := stack_cpc.item(top)
            eal := cpc.arguments
            ms ?= eal.expression( i )
            if ms /= Void then
               Result := ms.to_string
            end
         when C_switch then
            cpc := stack_cpc.item(top)
            eal := cpc.arguments
            ms ?= eal.expression( i )
            if ms /= Void then
               Result := ms.to_string
            end
         when C_expanded_initialize then
            check
               False
            end
         when C_create_instruction then
            check
               False
            end
         when C_inside_twin then
            check
               False
            end
         end
      end

feature {SWITCH}

   push_switch(rf, static_rf: RUN_FEATURE) is
      require
         rf /= Void
         static_rf /= Void
         rf.run_class.dynamic(static_rf) = rf
      do
         stack_push(C_switch)
         stack_rf.put(rf,top)
         stack_static_rf.put(static_rf,top)
      end

feature {NONE}

   fields: FAST_ARRAY[RUN_FEATURE] is
      once
         !!Result.with_capacity(4)
      end

   methods: FAST_ARRAY[RUN_FEATURE] is
      once
         !!Result.with_capacity(64)
      end

   access_flags: INTEGER is 33
         -- To allow any external access.

   this_class_idx: INTEGER

   super_class_idx: INTEGER

   start_basic is
      do
         fields.clear
         methods.clear
         constant_pool.clear
         interface_info.clear
         field_info.clear
         method_info.clear
      end

   put_magic is
         -- The Magic CAFEBABE ;-)
      do
         b_put_byte_string("%/0xCAFEBABE/")
      end

   put_minor_version is
      do
         b_put_u2(3)
      end

   put_major_version is
      do
         b_put_byte_string("%/0/%/45/")
      end

   args_field is
         -- Define `args' field to store command line arguments.
      local
         args_idx, jaos_idx: INTEGER
         cp: like constant_pool
      do
         cp := constant_pool
         args_idx := cp.idx_utf8(fz_74)
         jaos_idx := cp.idx_utf8(fz_75)
         field_info.add(9,args_idx,jaos_idx)
      end

   args_field_idx: INTEGER is
      local
         cp: like constant_pool
      do
         cp := constant_pool
         Result := cp.idx_fieldref3(jvm_root_class,fz_74,fz_75)
      end

   out_file: BINARY_FILE_WRITE is
         -- Current output class file.
      once
         !!Result.make
      end

   out_file_path: STRING is
      once
         !!Result.make(32)
      end

   tmp_string: STRING is
      once
         !!Result.make(16)
      end

   push_direct(cpc: CALL_PROC_CALL) is
      require
         cpc /= Void
      do
         stack_push(C_direct_call)
         stack_cpc.put(cpc,top)
         direct_call_count := direct_call_count + 1
      end

   push_check(cpc: CALL_PROC_CALL) is
      require
         cpc /= Void
      do
         stack_push(C_check_id)
         stack_cpc.put(cpc,top)
      end

   opcode_check_id_for(e: EXPRESSION) is
         -- Produce byte-code for `e' with non-void check and id
         -- check.
         -- Finally, also add a `checkcast' opcode.
      require
         e.result_type.run_class.run_time_set.count = 1
      local
         point1, point2: INTEGER; rc: RUN_CLASS
         ct: E_TYPE; ca: like code_attribute
      do
         e.compile_to_jvm
         rc := e.result_type.run_class.run_time_set.first
         ct := rc.current_type
         if ace.no_check then
            ca := code_attribute
            ca.opcode_dup
            point1 := ca.opcode_ifnull
            ca.opcode_dup
            rc.opcode_instanceof
            point2 := ca.opcode_ifne
            ca.resolve_u2_branch(point1)
            ca.opcode_dup
            ca.runtime_error_bad_target(e.start_position,ct,Void)
            ca.resolve_u2_branch(point2)
            rc.jvm_check_class_invariant
         end
         rc.opcode_checkcast
      end

   bfw_connect(bfw: BINARY_FILE_WRITE; path: STRING) is
      require
         not bfw.is_connected
         path /= Void
      do
         bfw.connect_to(path)
         if bfw.is_connected then
            echo.put_string("Writing %"")
            echo.put_string(path)
            echo.put_string("%" file.%N")
         else
            echo.w_put_string("Cannot write file %"")
            echo.w_put_string(path)
            echo.w_put_string(fz_b0)
            die_with_code(exit_failure_code)
         end
      ensure
         bfw.is_connected
      end

end -- JVM

