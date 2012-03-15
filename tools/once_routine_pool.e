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
class ONCE_ROUTINE_POOL
   --
   -- Singleton object in charge of runnable once routines.
   -- This singleton is shared via the GLOBALS.`once_routine_pool' once function.
   --

inherit
   GLOBALS
   VISITABLE

feature {ONCE_ROUTINE_POOL_VISITOR}

   accept(visitor: ONCE_ROUTINE_POOL_VISITOR) is
      do
         visitor.visit_once_routine_pool(Current)
      end

feature {RUN_FEATURE} -- For `compile_to_c' as well as `compile_to_jvm':

   register_procedure(rf: RUN_FEATURE) is
      require
         rf.is_once_procedure
      do
         check
            not procedure_list.has(rf)
         end
         procedure_list.add_last(rf)
      end

   register_function(rf: RUN_FEATURE) is
      require
         rf.is_once_function
      local
         rc: RUN_CLASS
      do
         check not function_list.has(rf) end
         function_list.add_last(rf)
	 if rf.name.to_string = as_std_output then
	    if std_output_flush_atexit = Void then
	       if rf.base_feature.base_class.name.to_string = as_general then
		  rc := rf.result_type.run_class
		  std_output_flush_atexit := rc.get_feature_with(as_flush)
	       end
	    end
	 end
      end

feature {GC_HANDLER}

   gc_mark_in(c_code: STRING) is
	 -- To mark results of once functions because they are part of the root.
      local
         i: INTEGER; rf: RUN_FEATURE; of: ONCE_FUNCTION
         mem: FAST_ARRAY[ONCE_FUNCTION]; rt: E_TYPE; oresult: STRING
      do
         if function_list.count > 0 then
            from
               i := function_list.upper
               create mem.with_capacity(i // 2)
            until
               i < 0
            loop
               rf := function_list.item(i)
               of ?= rf.base_feature
	       check
		  of /= Void
	       end
               if not mem.fast_has(of) then
                  if rf.current_type.run_class.at_run_time then
                     mem.add_last(of)
                     rt := rf.result_type
                     if rt.need_gc_mark_function then
                        oresult := o_result(of)
			gc_handler.mark_for(c_code,oresult,rt.run_class)
                     end
                  end
               end
               i := i - 1
            end
         end
      end

feature {JVM}

   fields_count: INTEGER

   jvm_define_fields is
      local
         byte_idx, idx_flag, i: INTEGER; rf: RUN_FEATURE
         bf: E_FEATURE; name_list: FAST_ARRAY[INTEGER]
      do
         create name_list.with_capacity(fields_count)
         if function_list.count > 0 then
            from
               i := function_list.upper
               byte_idx := constant_pool.idx_utf8(fz_41)
            until
               i < 0
            loop
               rf := function_list.item(i)
               bf := rf.base_feature
               idx_flag := idx_name_for_flag(bf)
               if name_list.fast_has(idx_flag) then
               else
                  name_list.add_last(idx_flag)
                  -- ---------- Static field for flag:
                  field_info.add(9,idx_flag,byte_idx)
                  -- ---------- Static field for result:
                  field_info.add(9,
                                 idx_name_for_result(bf),
                                 idx_descriptor(rf.result_type.run_type))
               end
               i := i - 1
            end
         end
         if procedure_list.count > 0 then
            from
               i := procedure_list.upper
               byte_idx := constant_pool.idx_utf8(fz_41)
            until
               i < 0
            loop
               rf := procedure_list.item(i)
               bf := rf.base_feature
               idx_flag := idx_name_for_flag(bf)
               if name_list.fast_has(idx_flag) then
               else
                  name_list.add_last(idx_flag)
                  -- ---------- Static field for flag:
                  field_info.add(9,idx_flag,byte_idx)
               end
               i := i - 1
            end
         end
      end

   jvm_initialize_fields is
      local
         i: INTEGER
      do
         if jvm_flag_list.count > 0 then
            from
               i := jvm_flag_list.upper
            until
               i < 0
            loop
               -- Set once flag :
               code_attribute.opcode_iconst_0
               code_attribute.opcode_putstatic(jvm_flag_list.item(i),-1)
               i := i - 1
            end
         end
      end

feature {RUN_FEATURE} -- For `compile_to_jvm' only:

   idx_fieldref_for_flag(rf: RUN_FEATURE): INTEGER is
      require
         rf.is_once_routine
      local
	 cp: CONSTANT_POOL
      do
	 cp := constant_pool
         Result := cp.idx_fieldref3(jvm_root_class,
				    o_flag(rf.base_feature),
				    fz_41)
      end

feature {NONE} -- For `compile_to_c' as well as `compile_to_jvm':

   idx_fieldref_for_result(rf: RUN_FEATURE): INTEGER is
      require
         rf.is_once_function
      local
	 cp: CONSTANT_POOL
	 rt: E_TYPE
      do
	 cp := constant_pool
         rt := rf.result_type.run_type
         Result := cp.idx_fieldref3(jvm_root_class,
				    o_result(rf.base_feature),
				    jvm_descriptor(rt))
      end

   procedure_list: FAST_ARRAY[RUN_FEATURE] is
	 -- Live set of once procedures.
      once
         create Result.with_capacity(32)
      end

   function_list: FAST_ARRAY[RUN_FEATURE] is
	 -- Live set of once functions.
      once
         create Result.with_capacity(32)
      end

   o_flag(bf: E_FEATURE): STRING is
	 -- Compute the only one corresponding `flag': fBCxxKey used
	 -- to check that execution is done.
      require
	 bf /= Void
      do
	 Result := o_flag_buffer
         Result.clear_count
         Result.append(once "fBC")
         bf.base_class.id.append_in(Result)
         Result.append(bf.first_name.to_key)
	 Result := string_aliaser.item(Result)
      ensure
	 Result = string_aliaser.item(Result)
      end

   buffer: STRING is
      once
	 create Result.make(64)
      end

   c_define_o_result_buffer: STRING is
      once
	 create Result.make(64)
      end

   o_flag_buffer: STRING is
      once
	 create Result.make(32)
      end

   o_result_buffer: STRING is
      once
	 create Result.make(32)
      end

   jvm_descriptor_buffer: STRING is
      once
	 create Result.make(32)
      end

feature {E_RESULT, RUN_FEATURE, RUN_CLASS}

   o_result(bf: E_FEATURE): STRING is
      require
	 bf /= Void
      do
	 Result := o_result_buffer
         Result.clear_count
         Result.append(once "oBC")
         bf.base_class.id.append_in(Result)
         Result.append(bf.first_name.to_key)
	 Result := string_aliaser.item(Result)
      ensure
	 Result = string_aliaser.item(Result)
      end

   c_put_o_result(rf: RUN_FEATURE) is
      require
	 rf.is_once_function
      do
	 cpp.put_string(o_result(rf.base_feature))
      end

   jvm_result_load(rf: RUN_FEATURE) is
      require
	 rf.is_once_function
      local
         result_space, idx_result: INTEGER
      do
         result_space := rf.result_type.jvm_stack_space
         idx_result := idx_fieldref_for_result(rf)
         code_attribute.opcode_getstatic(idx_result,result_space)
      end

   jvm_result_store(rf: RUN_FEATURE) is
      require
	 rf.is_once_function
      local
         result_space, idx_result: INTEGER
      do
         result_space := rf.result_type.jvm_stack_space
         idx_result := idx_fieldref_for_result(rf)
         code_attribute.opcode_putstatic(idx_result,- result_space)
      end

feature {C_PRETTY_PRINTER} -- For `compile_to_c':

   c_pre_compute is
	 -- Generate C code to pre_compute some functions.
      local
	 i: INTEGER; memory: FAST_ARRAY[E_FEATURE]
	 rf: RUN_FEATURE; bf: E_FEATURE
      do
	 echo.put_string(fz_04)
	 echo.put_string(fz_05)
	 cpp.put_string(fz_pco_comment)
	 from
	    i := function_list.upper
	    create memory.with_capacity(64)
	 until
	    i < 0
	 loop
	    rf := function_list.item(i)
	    if rf.run_class.at_run_time then
	       if rf.once_pre_computable then
		  bf := rf.base_feature
		  if not memory.fast_has(bf) then
		     memory.add_last(bf)
		     echo.put_character('%T')
		     echo.put_string(bf.base_class.name.to_string)
		     echo.put_character('.')
		     echo.put_string(rf.name.to_string)
		     echo.put_character('%N')
		     c_pre_compute_of(rf,bf)
		     cpp.put_string(fz_pco_comment)
		  end
	       end
	    end
	    i := i - 1
	 end
	 echo.print_count(fz_04,memory.count)
      end

   std_output_flush_atexit: RUN_FEATURE
	 -- To be called by the atexit() function if any.

   rf_frozen_general(rf_name: STRING): RUN_FEATURE is
         -- One one the registered functions corresponding to the "std_output"
         -- GENERAL feature. All are equivalent, returning the first is well
         -- enough.
      require
         frozen_general.fast_has(rf_name)
      local
         i: INTEGER
         rf: RUN_FEATURE
      do
         from
            i := function_list.lower
         until
            Result /= Void or else i > function_list.upper
         loop
            rf := function_list.item(i)
            if rf.name.to_string = rf_name and then rf.base_feature.base_class.name.to_string = as_general then
               Result := rf
            end
            i := i + 1
         end
      end

   frozen_general: ARRAY[STRING] is
      once
         Result := <<as_std_error, as_std_input, as_io, as_std_output>>
      end

feature {RUN_FEATURE} -- For `compile_to_c':

   c_define_o_flag(rf: RUN_FEATURE) is
	 -- Add the definition/initialization of the corresponding
	 -- `o_flag' if not yet done.
      require
	 rf.is_once_routine
      local
	 bf: E_FEATURE
	 bcbf: BASE_CLASS
	 flag: STRING
      do
         if not smart_eiffel.scoop or else rf.result_type.is_separate then
            bf := rf.base_feature
            bcbf := bf.base_class
            flag := o_flag(bf)
            if not bcbf.once_flag(flag) then
               buffer.copy(once "int ")
               buffer.append(flag)
               cpp.put_extern2(buffer,'0')
            end
         end
      end

   c_define_o_result(rf: RUN_FEATURE) is
      require
	 rf.is_once_function
      local
	 bf: E_FEATURE; bcbf: BASE_CLASS; oresult: STRING; rt: E_TYPE
      do
         if not smart_eiffel.scoop or else rf.result_type.is_separate then
            bf := rf.base_feature
            bcbf := bf.base_class
            oresult := o_result(bf)
            if not bcbf.once_flag(oresult) then
               buffer.clear_count
               rt := rf.result_type
               if rt.is_separate then
                  buffer.extend('s')
               end
               buffer.extend('T')
               if rt.is_expanded then
                  rt.id.append_in(buffer)
                  buffer.extend(' ')
               else
                  buffer.extend('0')
                  buffer.extend('*')
               end
               buffer.append(oresult)
               c_define_o_result_buffer.clear_count
               rt.c_initialize_in(c_define_o_result_buffer)
               cpp.put_extern5(buffer,c_define_o_result_buffer)
            end
         end
     end

   c_test_o_flag(rf: RUN_FEATURE) is
      require
	 rf.is_once_routine
      local
	 flag: STRING; rt: E_TYPE
      do
         if not smart_eiffel.scoop or else rf.result_type.is_separate then
            flag := o_flag(rf.base_feature)
            cpp.put_string(once "if(")
            cpp.put_string(flag)
            cpp.put_string(once "==0){")
            cpp.put_string(flag)
            cpp.put_string(once "=1;{%N")
         else
            rt := rf.result_type
            buffer.clear_count
            buffer.extend('T')
            if rt.is_expanded then
               rt.id.append_in(buffer)
            else
               buffer.extend('0')
               buffer.extend('*')
            end
            flag := o_result(rf.base_feature)
            cpp.put_string(buffer)
            cpp.put_character(' ')
            cpp.put_string(flag)
            if not rt.is_expanded then
               cpp.put_string(once "=NULL")
            end
            cpp.put_string(fz_00)
            cpp.put_string(once "[
                se_subsystem_t* self=se_current_subsystem_thread();
                if(!self->vft.is_set_once(self,"
                                ]") --"
            cpp.put_string(flag)
            cpp.put_string(once "%")){{%N")
         end
      end

   c_test_o_flag_introspect(rf: RUN_FEATURE) is
      require
	 rf.is_once_routine
      local
	 flag: STRING; rt: E_TYPE
      do
         if not smart_eiffel.scoop or else rf.result_type.is_separate then
            flag := o_flag(rf.base_feature)
            cpp.put_string(once "if(")
            cpp.put_string(flag)
            cpp.put_string(once "!=0){%N")
         else
            rt := rf.result_type
            buffer.clear_count
            buffer.extend('T')
            if rt.is_expanded then
               rt.id.append_in(buffer)
            else
               buffer.extend('0')
               buffer.extend('*')
            end
            flag := o_result(rf.base_feature)
            cpp.put_string(buffer)
            cpp.put_character(' ')
            cpp.put_string(flag)
            if not rt.is_expanded then
               cpp.put_string(once "=NULL")
            end
            cpp.put_string(fz_00)
            cpp.put_string(once "[
                se_subsystem_t* self=se_current_subsystem_thread();
                if(self->vft.is_set_once(self,"
                                ]") --"
            cpp.put_string(flag)
            cpp.put_string(once "%")){%N")
         end
      end

   c_return_o_result(rf: RUN_FEATURE) is
      require
	 rf.is_once_function
      local
         oresult: STRING; rt: E_TYPE
      do
         oresult := o_result(rf.base_feature)
         if smart_eiffel.scoop and then not rf.result_type.is_separate then
            rt := rf.result_type
            if rt.is_expanded then
               cpp.put_string(fz_11)
               cpp.put_string(buffer)
               cpp.put_character('*')
               cpp.put_string(once "p_")
               cpp.put_string(oresult)
               cpp.put_string(once "=memcpy(malloc(sizeof(")
               cpp.put_string(buffer)
               cpp.put_string(once ")),")
               cpp.put_string(oresult)
               cpp.put_string(once ",sizeof(")
               cpp.put_string(buffer)
               cpp.put_string(once "));%N");
            end
            cpp.put_string(once "self->vft.set_once(self,%"")
            cpp.put_string(oresult)
            cpp.put_string(once "%", ")
            if rt.is_expanded then
               cpp.put_string(once "p_")
            end
            cpp.put_string(oresult)
            cpp.put_string(once ");%N}%N")
            if rt.is_expanded then
               cpp.put_string(fz_12)
            end
            cpp.put_string(once "else {%N")
            cpp.put_string(oresult)
            cpp.put_character('=')
            if rt.is_expanded then
               cpp.put_character('*')
            end
            cpp.put_character('(')
            cpp.put_string(buffer)
            if rt.is_expanded then
               cpp.put_character('*')
            end
            cpp.put_string(once ")(self->vft.get_once(self,%"")
            cpp.put_string(oresult)
            cpp.put_string(once "%"));%N}%N")
         else
            cpp.put_string(once "}}%N")
         end
         cpp.put_string(once "return ")
         cpp.put_string(oresult)
         cpp.put_string(once ";%N}%N")
      end

feature {NONE} -- For `compile_to_jvm':

   jvm_flag_list: FAST_ARRAY[INTEGER] is
      once
         create Result.with_capacity(32)
      end

   idx_descriptor(rt: E_TYPE): INTEGER is
      require
         rt /= Void
      do
         Result := constant_pool.idx_utf8(jvm_descriptor(rt))
      end

   idx_name_for_result(bf: E_FEATURE): INTEGER is
      require
         bf /= Void
      do
         Result := constant_pool.idx_utf8(o_result(bf))
      end

   idx_name_for_flag(bf: E_FEATURE): INTEGER is
      require
         bf /= Void
      do
         Result := constant_pool.idx_utf8(o_flag(bf))
      end

   jvm_descriptor(rt: E_TYPE): STRING is
      do
	 Result := jvm_descriptor_buffer
         Result.clear_count
         if rt.is_reference then
            Result.append(jvm_root_descriptor)
         else
            rt.jvm_descriptor_in(Result)
         end
      end

feature {RUN_FEATURE_6, RUN_FEATURE_11}

   once_pre_computable(once_function: ONCE_FUNCTION): BOOLEAN is
	 -- Actually, only once function may be pre-computed and it seems to be 
	 -- the right choice.
      require
         smart_eiffel.is_ready
	 once_function /= Void
      do
         if not smart_eiffel.scoop then
            if frozen_general.fast_has(once_function.first_name.to_string) then
               Result := True
	    elseif once_function.once_pre_computable then
	       Result := True
	    end
	 end
      end

feature {NONE}

   c_pre_compute_of(rf: RUN_FEATURE; bf: E_FEATURE) is
      require
	 rf.is_once_function
         rf.once_pre_computable
         cpp.on_c
      local
	 result_type: E_TYPE; local_vars: LOCAL_VAR_LIST; rf3: RUN_FEATURE_3
      do
	 if rf.require_assertion /= Void then
	    rf.require_assertion.compile_to_c
	 end
	 result_type := rf.result_type
	 if result_type.is_user_expanded then
	    rf3 := result_type.run_class.a_default_create
	    if rf3 /= Void then
	       cpp.put_proc_call_0(rf3,Void,o_result(rf.base_feature))
	    end
	 end
	 --
	 local_vars := rf.local_vars
         if local_vars /= Void then
            cpp.put_character('{')
            local_vars.c_declare(False)
         end
	 --
         if rf.routine_body /= Void then
            rf.routine_body.compile_to_c
         end
	 --
	 if rf.ensure_assertion /= Void then
	    rf.ensure_assertion.compile_to_c
         end
	 --
         if local_vars /= Void then
            cpp.put_character('}')
         end
      end

   fz_pco_comment: STRING is "/*PCO*/%N"

   singleton_memory: ONCE_ROUTINE_POOL is
      once
	 Result := Current
      end

invariant

   is_real_singleton: Current = singleton_memory

end -- ONCE_ROUTINE_POOL

