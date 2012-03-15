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
deferred class RUN_FEATURE
   --
   -- A feature at run time : assertions collected and only run types.
   --
   --   RUN_FEATURE_1  : constant attribute.
   --   RUN_FEATURE_2  : attribute.
   --   RUN_FEATURE_3  : procedure.
   --   RUN_FEATURE_4  : function.
   --   RUN_FEATURE_5  : once procedure.
   --   RUN_FEATURE_6  : once function.
   --   RUN_FEATURE_7  : external procedure.
   --   RUN_FEATURE_8  : external function.
   --   RUN_FEATURE_9  : deferred routine.
   --   RUN_FEATURE_10 : Precursor procedure.
   --   RUN_FEATURE_11 : Precursor function.
   --

inherit
   GLOBALS
   VISITABLE
   ASSERTION_LEVEL_NUMBERING

feature {NONE}

   clients_memory: CLIENT_LIST

feature

   current_type: E_TYPE
         -- The type of Current in this feature.

   run_class: RUN_CLASS
	 -- Alias the one of `current_type'.

   name: FEATURE_NAME
         -- Final name (the only one really used) of the feature.

   base_feature: E_FEATURE
         -- Original base feature definition.

   arguments: FORMAL_ARG_LIST is
         -- Runnable arguments list if any.
      deferred
      end

   result_type: E_TYPE is
         -- Runnable Result type if any.
      deferred
      end

   require_assertion: RUN_REQUIRE is
         -- Runnable collected require assertion if any.
      deferred
      end

   local_vars: LOCAL_VAR_LIST is
         -- Runnable local var list if any.
      deferred
      end

   routine_body: COMPOUND is
         -- Runnable routine body if any.
      deferred
      end

   ensure_assertion: E_ENSURE is
         -- Runnable collected ensure assertion if any.
      deferred
      end

   rescue_compound: COMPOUND is
         -- Runnable rescue compound if any.
      deferred
      end

   is_once_procedure: BOOLEAN is
	 -- This is not only True for RUN_FEATURE_5, but it may be also
	 -- True when some once procedure is wrapped (RUN_FEATURE_10).
      deferred
      ensure
	 Result implies result_type = Void
      end

   is_once_function: BOOLEAN is
	 -- This is not only True for RUN_FEATURE_6, but it may be also
	 -- True when some once function is wrapped (RUN_FEATURE_11).
      deferred
      ensure
	 Result implies result_type /= Void
      end

   is_deferred: BOOLEAN is
      deferred
      end

   is_root: BOOLEAN
         -- True if `Current' is the root creation feature. Can only be set 
         -- once in RUN_FEATURE_3. This function is called via a require 
         -- assertion. (This way, no extra memory is used for a production 
         -- compiler because this is dead code.)

   frozen is_once_routine: BOOLEAN is
	 -- Is it a once routine?
      do
	 Result := is_once_function or else is_once_procedure
      end

   once_pre_computable: BOOLEAN is
	 -- Is it some pre-computable once routine?
      require
         smart_eiffel.is_ready
	 is_once_routine
      deferred
      end

   side_effect_free: BOOLEAN is
	 -- If calling `Current' has no side effect at all.
      require
         smart_eiffel.status >= 4
      deferred
      end

   frozen use_current: BOOLEAN is
      require
         smart_eiffel.is_ready
      do
         inspect
            use_current_state
         when True_state then
            Result := True
         when False_state then
         when Unknown_state then
            use_current_state := Computing_state
	    if smart_eiffel.scoop then
	       if current_type.is_separate then
		  use_current_state := True_state
	       else
		  compute_use_current
	       end
	    else
	       compute_use_current
	    end
            Result := use_current_state = True_state
         when Computing_state then
            use_current_state := True_state
            Result := True
         end
      end

   frozen stupid_switch(run_time_set: RUN_TIME_SET): STRING is
         -- Non-Void `Result' indicates a `stupid_switch' as well as the very
         -- nature of the stupid call site in order to print the
         -- associated comment in the generated C code.
      require
         ace.boost
	 smart_eiffel.status >= 3
         smart_eiffel.same_base_feature(Current,run_time_set)
      do
         check
            -- Must always be called with the same array of run classes.
            run_time_set = run_class.run_time_set
         end
         inspect
            stupid_switch_state
         when True_state then
            Result := stupid_switch_comment
         when False_state then
         when Unknown_state then
            stupid_switch_state := Computing_state
            compute_stupid_switch(run_time_set)
            if stupid_switch_state = True_state then
               Result := stupid_switch_comment
            end
         when Computing_state then
            stupid_switch_state := False_state
         end
      end

   frozen debug_info_in(buffer: STRING) is
	 -- For debugging only.
      local
	 i: INTEGER
      do
	 buffer.extend('{')
	 current_type.debug_info_in(buffer)
	 buffer.extend('}')
	 buffer.extend('.')
	 buffer.append(name.to_string)
	 if arguments /= Void then
	    buffer.extend('(')
	    from
	       i := 1
	    until
	       i > arguments.count
	    loop
	       arguments.type(i).debug_info_in(buffer)
	       i := i + 1
	       if i <= arguments.count then buffer.extend(',') end
	    end
	    buffer.extend(')')
	 end
	 if result_type /= Void then
	    buffer.extend(':')
	    result_type.debug_info_in(buffer)
	 end
      end

   fall_down is
      local
         run_time_set: RUN_TIME_SET; i: INTEGER; dyn_rc: RUN_CLASS
	 dyn_rf: RUN_FEATURE
      do
         if smart_eiffel.scoop then
	    if routine_body /= Void then
	       routine_body.verify_scoop(arguments)
	    end
	    if require_assertion /= Void then
	       require_assertion.verify_scoop(arguments)
	    end
	 end
	 from
	    run_time_set := run_class.run_time_set
	    i := run_time_set.count
	 until
	    i = 0
	 loop
	    dyn_rc := run_time_set.item(i)
	    if dyn_rc /= run_class then
	       dyn_rf := dyn_rc.dynamic(Current)
	       assignment_handler.falling_down(Current,dyn_rf)
	    end
	    i := i - 1
         end
      end

   afd_check is
      deferred
      end

   simplify_2 is
	 -- See also `{EXPRESSION}.simplify_2' and `{INSTRUCTION}.simplify_2'.
      require
	 not smart_eiffel.pretty_flag
	 not smart_eiffel.short_flag
	 smart_eiffel.status >= 4
      deferred
      end
   
   clients: like clients_memory is
         -- Effective client list for the receiver (inherited "export"
         -- clauses are also considered)..
      local
         bc, bfbc: BASE_CLASS
      do
         if clients_memory = Void then
            bc := current_type.base_class
            bfbc := base_feature.base_class
            if bc = bfbc then
               Result := base_feature.clients
            else
               check
                  bc.is_subclass_of(bfbc)
               end
               Result := bc.clients_for(name)
            end
            clients_memory := Result
         else
            Result := clients_memory
         end
      ensure
         Result /= Void
      end

   frozen start_position: POSITION is
      do
         Result := base_feature.start_position
      end

   c_define_or_scoop_define is
      local
	 hlc: BOOLEAN
      do
         debug
            echo.put_character('%T')
            echo.put_character('%T')
            echo.put_string(name.to_string)
            echo.put_character('%N')
         end
	 if smart_eiffel.scoop and then 
	    current_type.is_separate
	  then
            in_scoop_wrapper := True
	    if arguments /= Void then
	       hlc := arguments.has_like_current
	    end
            define_prototype
            c_scoop_define_wrapper(hlc)
            if result_type = Void then
               cpp.put_string(fz_12)
            else
               cpp.put_string(fz_15)
            end
            -- UNWRAP
            define_unwrap_prototype
            c_scoop_define_unwrap(hlc)
            cpp.put_string(fz_12)
            in_scoop_wrapper := False
	 else
	    c_define
	 end
      end

   c_define is
         -- Produce C code for definition.
      require
         cpp.on_c
      deferred
      ensure
         cpp.on_c
      end

   collect_c_tmp is
	 -- Collect needed temporary variables for C code generation.
      deferred
      end

   mapping_c is
         -- Produce C code when current is called and when the concrete type 
         -- of target is unique (`cpp' is in charge of the context). The 
      require
         cpp.on_c
      deferred
      ensure
         cpp.on_c
      end

   mapping_jvm is
      deferred
      end

   frozen id: INTEGER is
      do
         Result := current_type.id
      end

   mapping_name(local_current: BOOLEAN) is
      do
         c_code.clear_count
         if smart_eiffel.scoop and then not local_current and then (current_type.is_separate or else is_root) then
            c_code.append(once "Sw")
         else
            c_code.extend('r')
         end
         id.append_in(c_code)
         name.mapping_c_in(c_code)
         cpp.put_string(c_code)
      end

   frozen jvm_max_locals: INTEGER is
      do
         Result := current_type.jvm_stack_space
         if arguments /= Void then
            Result := Result + arguments.jvm_stack_space
         end
         if local_vars /= Void then
            Result := Result + local_vars.jvm_stack_space
         end
         if result_type /= Void then
            Result := Result + result_type.jvm_stack_space
         end
         if rescue_compound /= Void then
            Result := Result + 1
         end
      end

feature {CALL,CREATE_EXPRESSION}

   frozen vape_check_from(call_site: POSITION) is
         -- Check VAPE rule for this `call_site'.
      require
         not call_site.is_unknown
      local
	 enclosing: RUN_FEATURE
      do
	 enclosing := smart_eiffel.top_rf
	 enclosing.clients.vape_check(enclosing,call_site,clients)
      end

feature {ADDRESS_OF_POOL}

   address_of_c_define(caller: ADDRESS_OF) is
         -- Corresponding `caller' is used for error messages.
      require
         caller /= Void
      deferred
      end

feature {ADDRESS_OF}

   address_of_c_mapping is
         -- Produce C code for operator $<feature_name>
      require
         run_class.at_run_time
         cpp.on_c
      deferred
      ensure
         cpp.on_c
      end

feature {NATIVE}

   frozen default_mapping_procedure is
         -- Default mapping for procedure calls with target.
      do
         default_mapping_function
         cpp.put_string(fz_00)
      end

   frozen default_mapping_function is
         -- Default mapping for function calls with target.
      local
         no_check, uc, tcbd: BOOLEAN
      do
         no_check := ace.no_check
         uc := use_current
	 if not uc then
	    tcbd := cpp.target_cannot_be_dropped
	    if tcbd then
	       cpp.put_character(',')
	    end
	 end
	 mapping_name(True)
	 default_mapping_arg(no_check, uc, tcbd)
      end

   frozen default_mapping_arg(no_check, uc, tcbd: BOOLEAN) is
      do
         cpp.put_character('(')
         if no_check then
            cpp.put_string(once "&ds")
         end
         if uc then
            if no_check then
               cpp.put_character(',')
            end
	    if current_type.is_boolean then
	       cpp.put_string(once "(T6)(")
	    end
	    cpp.put_target_as_target
 	    if current_type.is_boolean then
              cpp.put_character(')')
	    end
         end
         if arguments /= Void then
            if uc or else no_check then
               cpp.put_character(',')
            end
            cpp.put_arguments
         end
         cpp.put_character(')')
         if not uc and then tcbd then
            cpp.put_character(')')
         end
      end

   routine_mapping_jvm is
      local
         rt, ct: E_TYPE
         idx, stack_level: INTEGER
      do
         ct := current_type
         jvm.push_target_as_target
         stack_level := -(1 + jvm.push_arguments)
         rt := result_type
         if rt /= Void then
            stack_level := stack_level + rt.jvm_stack_space
         end
         idx := constant_pool.idx_methodref(Current)
         ct.run_class.jvm_invoke(idx,stack_level)
      end

   frozen c_define_with_body(body: STRING) is
      require
         body /= Void
      do
         define_prototype
         c_define_opening
         cpp.put_string(body)
         c_define_closing
         if result_type = Void then
            cpp.put_string(fz_12)
         else
            cpp.put_string(fz_15)
         end
      end

feature {RUN_CLASS}

   jvm_field_or_method is
         -- Update jvm's `fields' or `methods' if needed.
      deferred
      end

   scoop_expanded_verified: BOOLEAN
         -- Anti-recursion flag used by `verify_scoop_expanded'

   verify_scoop_expanded(p: POSITION) is
         -- default does nothing. Redefined in the query-type run_features
         -- (those having a non-void result type) to call
         -- `default_verify_scoop_expanded'
      do
         scoop_expanded_verified := True
      ensure
         scoop_expanded_verified
      end

feature {NONE}

   default_verify_scoop_expanded(p: POSITION) is
      require
         result_type /= Void
      local
         t: E_TYPE
      do
         t := result_type
         if not t.is_expanded then
            error_handler.add_position(start_position)
            error_handler.add_position(p)
            fatal_error(fz_sc4)
         elseif not t.run_class.scoop_expanded_verified then
            t.run_class.verify_scoop_expanded(p)
         end
         scoop_expanded_verified := True
      ensure
         scoop_expanded_verified
      end

feature {CONSTANT_POOL,SWITCH_COLLECTION}

   frozen jvm_descriptor: STRING is
      do
         tmp_jvm_descriptor.clear_count
         update_tmp_jvm_descriptor
         Result := tmp_jvm_descriptor
      end

feature {SWITCH, C_PRETTY_PRINTER, GC_HANDLER, CECIL_POOL}

   c_set_dump_stack_top_in(code_buffer, ds, comment: STRING) is
      do
	 code_buffer.append(once "set_dump_stack_top(")
         if smart_eiffel.scoop then
	    put_current_thread_in(code_buffer)
	    code_buffer.extend(',')
	 end
	 code_buffer.append(ds)
	 code_buffer.append(once ");/*")
	 code_buffer.append(comment)
	 code_buffer.append(once "*/%N")
      end

   c_set_dump_stack_top(ds, comment: STRING) is
      require
	 cpp.on_c
      do
	 c_code.clear_count
	 c_set_dump_stack_top_in(c_code, ds, comment)
	 cpp.put_string(c_code)
      ensure
	 cpp.on_c
      end

feature {JVM, E_RESULT}

   frozen jvm_result_offset: INTEGER is
         -- Offset of the Result local variable if any.
      require
         result_type /= Void
      do
         Result := current_type.jvm_stack_space
         if arguments /= Void then
            Result := Result + arguments.jvm_stack_space
         end
         if local_vars /= Void then
            Result := Result + local_vars.jvm_stack_space
         end
      end

feature {JVM}

   jvm_define is
         -- To compute the constant pool, the number of fields,
         -- the number of methods, etc.
      require
         smart_eiffel.is_ready
      deferred
      end

   frozen jvm_argument_offset(a: ARGUMENT_NAME): INTEGER is
      require
         arguments /= Void
      do
         Result := current_type.jvm_stack_space
         Result := Result + arguments.jvm_offset_of(a)
      ensure
         Result >= a.rank - 1
      end

   frozen jvm_local_variable_offset(ln: LOCAL_NAME): INTEGER is
      require
         local_vars /= Void
      do
         Result := current_type.jvm_stack_space
         if arguments /= Void then
            Result := Result + arguments.jvm_stack_space
         end
         Result := Result + local_vars.jvm_offset_of(ln)
      ensure
         Result >= ln.rank - 1
      end

feature {E_RESULT}

   frozen fe_vffd7 is
      do
         error_handler.add_position(result_type.start_position)
	 error_handler.append("Result type of a once function must %
			      %not be anchored (VFFD.7).")
	 error_handler.print_as_fatal_error
      end

feature {RUN_FEATURE}

   is_in_computation: BOOLEAN is
      do
         Result := use_current_state = Computing_state
      end

feature {NATIVE_C_PLUS_PLUS}

   c_plus_plus_prototype(er: EXTERNAL_ROUTINE) is
      local
	 comment: STRING
      do
	 comment := c_plus_plus_prototype_buffer
	 comment.copy(once "%N// C++ wrapper for ")
	 comment.append(er.base_class.name.to_string)
	 comment.extend('.')
	 comment.append(name.to_string)
	 comment.append(once "%N")
         external_c_prototype_for(comment,er)
-- ????
--	 cpp.put_string_on_h(once "%Nextern %"C%" {")
         cpp.put_c_heading(c_code)
--	 cpp.put_string_on_h(once "}%N")
      end

feature {E_OLD}

   register_old(e_old: E_OLD) is
      require
	 e_old /= Void
      do
	 if old_list = Void then
	    create old_list.with_capacity(4)
	 end
	 old_list.add_last(e_old)
      end

feature {RUN_FEATURE,E_RETRY}

   jvm_try_begin: INTEGER
   jvm_try_end: INTEGER
   jvm_handler: INTEGER

feature {NONE}

   old_list: FAST_ARRAY[E_OLD]

   c_plus_plus_prototype_buffer: STRING is
      once
	 create Result.make(128)
      end

   compute_stupid_switch(run_time_set: RUN_TIME_SET) is
      require
         stupid_switch_state = Computing_state
      deferred
      ensure
         stupid_switch_state = True_state
	    or else
	 stupid_switch_state = False_state
      end

   frozen external_c_prototype_for(tag: STRING; er: EXTERNAL_ROUTINE) is
      local
         t: E_TYPE
      do
         c_code.clear_count
         c_code.append(tag)
         -- Define heading of corresponding C function.
         t := result_type
         if t = Void then
            c_code.append(fz_void)
         else
            t.c_type_for_external_in(c_code)
         end
         c_code.extend(' ')
         c_code.append(er.external_name)
         c_code.extend('(')
         if er.use_current then
            current_type.c_type_for_external_in(c_code)
            c_code.extend(' ')
            c_code.extend('C')
            if arguments /= Void then
               c_code.extend(',')
            end
         end
         if arguments = Void then
            if not er.use_current then
               c_code.append(fz_void)
            end
         else
            arguments.external_prototype_in(c_code)
         end
         c_code.extend(')')
      end

   frozen put_c_name_tag is
      require
         ace.no_check
      local
         fn: FEATURE_NAME
	 tag: STRING
      do
         cpp.put_character('%"')
         fn := base_feature.first_name
         if fn.to_key /= name.to_key then
	    tag := name.infix_or_prefix
	    if tag /= Void then
	       cpp.put_string(tag)
	       cpp.put_character(' ')
	    end
            cpp.put_string(name.to_string)
            cpp.put_character(' ')
            cpp.put_character('(')
         end
	 tag := fn.infix_or_prefix
	 if tag /= Void then
	    cpp.put_string(tag)
	    cpp.put_character(' ')
	 end
         cpp.put_string(fn.to_string)
         cpp.put_character(' ')
         cpp.put_string(base_feature.base_class_name.to_string)
         if fn.to_key /= name.to_key then
            cpp.put_character(')')
         end
         cpp.put_character('%"')
      end

   address_of_wrapper_name_in(str: STRING) is
      do
         str.extend('W')
         id.append_in(str)
         name.mapping_c_in(str)
      end

   address_of_c_define_wrapper(caller: ADDRESS_OF) is
      require
         cpp.on_c
      do
         c_code.clear_count
         if result_type = Void then
            c_code.append(fz_void)
         else
            result_type.c_type_for_external_in(c_code)
         end
         c_code.extend(' ')
         address_of_wrapper_name_in(c_code)
         c_code.extend('(')
         current_type.c_type_for_external_in(c_code)
         c_code.extend(' ')
         c_code.extend('C')
         if arguments /= Void then
            c_code.extend(',')
            arguments.external_prototype_in(c_code)
         end
         c_code.extend(')')
         cpp.put_c_heading(c_code)
	 cecil_pool.define_body_of(Current)
      end

   address_of_c_mapping_wrapper is
      do
         c_code.clear_count
         address_of_wrapper_name_in(c_code)
         cpp.put_string(c_code)
      end

   c_frame_descriptor_format: STRING is
         -- The format to print `Current' and other locals.
      once
         create Result.make(512)
      end

   c_frame_descriptor_locals: STRING is
         -- To initialize field `locals' of `se_dump_stack'.
      once
         create Result.make(512)
      end

   c_frame_descriptor is
	 -- Initialize all `c_frame_descriptor' variables accordingly.
      require
	 ace.no_check
      local
	 oresult: STRING; t: E_TYPE
      do
	 c_frame_descriptor_format.clear_count
	 c_frame_descriptor_locals.clear_count
	 if use_current then
            current_type.c_frame_descriptor_in(c_frame_descriptor_format)
	 end
	 if arguments /= Void then
	    arguments.c_frame_descriptor(c_frame_descriptor_format,
					 c_frame_descriptor_locals)
	 end
	 if is_once_function then
	    oresult := once_routine_pool.o_result(base_feature)
	    t := result_type.run_type
	    c_frame_descriptor_locals.append(once "(void**)&")
	    c_frame_descriptor_locals.append(oresult)
	    c_frame_descriptor_locals.extend(',')
	    c_frame_descriptor_format.append(as_result)
	    t.c_frame_descriptor_in(c_frame_descriptor_format)
	 elseif result_type /= Void then
            t := result_type.run_type
	    c_frame_descriptor_locals.append(once "(void**)&R,")
	    c_frame_descriptor_format.append(as_result)
	    t.c_frame_descriptor_in(c_frame_descriptor_format)
	 end
         if local_vars /= Void then
            local_vars.c_frame_descriptor(c_frame_descriptor_format,
					  c_frame_descriptor_locals)
         end
	 if ensure_assertion /= Void then
	    ensure_assertion.c_frame_descriptor(c_frame_descriptor_format,
						c_frame_descriptor_locals)
	 end
      end

   define_prototype is
      require
         run_class.at_run_time
         cpp.on_c
      local
         mem_id: INTEGER; no_check: BOOLEAN
      do
         no_check := ace.no_check
         mem_id := id
         -- Define heading of corresponding C function.
         c_code.clear_count
	 -- Extra comment to debug C code :
	 c_code.append(once "/*")
	 c_code.append(current_type.run_time_mark)
	 c_code.append(once "*/%N")
	 --
         if result_type = Void then
            c_code.append(fz_void)
         else
            result_type.run_type.c_type_for_result_in(c_code)
         end
         c_code.extend(' ')
         c_code.extend('r')
         mem_id.append_in(c_code)
         name.mapping_c_in(c_code)
         c_code.extend('(')
         if no_check then
            c_code.append(once "se_dump_stack*caller")
            if use_current or else arguments /= Void then
               c_code.extend(',')
            end
         end
         if use_current then
            current_type.c_type_for_target_in(c_code)
            c_code.extend(' ')
            c_code.extend('C')
            if arguments /= Void then
               c_code.extend(',')
            end
         end
         if arguments = Void then
            if no_check then
            elseif not use_current then
               c_code.append(fz_void)
            end
         else
            arguments.compile_to_c_in(c_code)
         end
         c_code.extend(')')
         cpp.put_c_heading(c_code)
         cpp.swap_on_c
      ensure
         cpp.on_c
      end

   define_unwrap_prototype is
      require
         run_class.at_run_time
         cpp.on_c
      local
         mem_id: INTEGER
         no_check: BOOLEAN
      do
         no_check := ace.no_check
         mem_id := id
         -- Define heading of corresponding C function.
         c_code.clear_count
	 -- Extra comment to debug C code :
	 c_code.append(once "/*")
	 c_code.append(current_type.run_time_mark)
	 c_code.append(once "*/%N")
	 --
         c_code.append(fz_void)
         c_code.extend(' ')
         c_code.append(once "Su")
         mem_id.append_in(c_code)
         name.mapping_c_in(c_code)
         c_code.append(once "(void* data, int data_length, void* result_ref)")
         cpp.put_c_heading(c_code)
         cpp.swap_on_c
      ensure
         cpp.on_c
      end

   c_define_opening is
         -- Define opening section in C function.
      require
         --not current_type.is_separate or else current_type.base_class.is_separate
      local
         t: E_TYPE; no_check: BOOLEAN; oresult: STRING
	 rf3: RUN_FEATURE_3; clc, i: INTEGER
      do
         no_check := ace.no_check
	 if no_check then
	    c_frame_descriptor
	 end
         -- (0) --------------------------- Exception handling :
         if rescue_compound /= Void then
            if smart_eiffel.scoop then
               error_handler.add_position(rescue_compound.start_position)
               fatal_error("Exceptions cannot currently be used with SCOOP.")
            end
            cpp.put_string(once "struct rescue_context rc;%N")
         end
         -- (0') ---------------------------- Current subsystem:
         if current_type.is_separate then
            cpp.put_string(
               once "se_subsystem_t* self=se_current_subsystem_thread();%N")
         end
         -- (1) -------------------- Local variable for Result :
         if is_once_function then
	    oresult := once_routine_pool.o_result(base_feature)
         elseif result_type /= Void then
            t := result_type.run_type
            c_code.clear_count
            t.c_type_for_result_in(c_code)
            c_code.append(once " R=")
            t.c_initialize_in(c_code)
            c_code.append(fz_00)
            cpp.put_string(c_code)
         end
         -- (2) ----------------------- User's local variables :
         if local_vars /= Void then
            local_vars.c_declare(rescue_compound /= Void)
         end
         -- (3) ----------- Local variables for old expressions:
	 if old_list /= Void then
	    from
	       i := old_list.upper
	    until
	       i < old_list.lower
	    loop
	       old_list.item(i).c_declare_for_old
	       i := i - 1
	    end
	 end
         if no_check then
         -- (4) ------------------------------- Prepare locals:
	    clc := c_frame_descriptor_format.occurrences('%%')
	    if clc > 0 then
	       clc := clc // 2
	       if use_current then
		  clc := clc - 1
	       end
	    end
            if clc > 0 then
               cpp.put_string(once "void**locals[")
               cpp.put_integer(clc)
               cpp.put_string(once "];%N")
            end
         -- (5) ----------------------------------- Prepare ds:
            c_initialize_frame_information(clc)
         -- (6) ------------------------ Initialise Dump Stack:
	    c_set_dump_stack_top(once "&ds", fz_link)
         end
         -- (7) ---------------------- Execute old expressions:
	 if old_list /= Void then
	    from
	       i := old_list.upper
	    until
	       i < old_list.lower
	    loop
	       old_list.item(i).compile_to_c_old
	       i := i - 1
	    end
	 end
         -- (8) --------------------------- Exception handling :
         if rescue_compound /= Void then
            cpp.put_string(once "if(SETJMP(rc.jb)!=0){/*rescue*/%N")
            rescue_compound.compile_to_c
            cpp.put_string(
               once "internal_exception_handler(Routine_failure);%N}%N")
         end
         -- (9) -------------------- Initialize Result/local expanded :
	 if result_type /= Void then
	    if result_type.is_user_expanded then
	       rf3 := result_type.run_class.a_default_create
	       if rf3 /= Void then
		  if oresult /= Void then
		     cpp.put_proc_call_0(rf3,Void,oresult)
		  else
		     cpp.put_proc_call_0(rf3,Void,once "R")
		  end
	       end
	    end
	 end
         if local_vars /= Void then
            local_vars.initialize_expanded
         end
         -- (10) --------------------------- Retry start label :
         if rescue_compound /= Void then
            cpp.put_string(once "retry_tag:%N")
         end
         -- (11) ---------------------- Require assertion code :
         if current_type.base_class.require_check and then require_assertion /= Void then
            require_assertion.compile_to_c
         end
         -- (12) ------------------------- Save rescue context :
         if rescue_compound /= Void then
            cpp.put_string(once "rc.next = rescue_context_top;%N%
                           %rescue_context_top = &rc;%N")
            if no_check then
	       cpp.put_string(once "rc.top_of_ds=&ds;%N")
	       c_set_dump_stack_top(once "&ds", fz_link)
            end
         end
         -- (13) ------------------------------ SCOOP handling :
         if smart_eiffel.scoop and then arguments /= Void then
            cpp.put_string(once "[
               {/*<SCOOP>*/
                se_subsystem_t* self=se_current_subsystem_thread();
                static se_subsystem_t* scoop_sub[]=
                                 ]")
            arguments.c_lock_scoop_init
            if require_assertion = Void then
               arguments.c_lock_scoop
            else
               require_assertion.c_scoop_while
               arguments.c_lock_scoop
               require_assertion.c_scoop_if_not_guard
               arguments.c_unlock_scoop
               require_assertion.c_scoop_guard
            end
            cpp.put_string(once "{%N")
         end
      end

   c_define_closing is
         -- Define closing section in the corresponding C function (code 
         -- for ensure checking, free memory of expanded, run stack 
         -- pop, etc.).
      local
	 stbe: POSITION
      do
         -- (1) --------------------------- Ensure Check Code:
	 if ensure_assertion /= Void then
	    ensure_assertion.compile_to_c
	 end
         -- (2) ----------------------------- Class Invariant:
         if use_current then
	    if name.to_string /= as_dispose then
	       cpp.current_class_invariant(current_type)
	    end
         end
         -- (3) ---------------------------------- For rescue:
         if rescue_compound /= Void then
            cpp.put_string(once "rescue_context_top = rc.next;%N")
         end
         -- (4) ------------------------------- Run Stack Pop:
         if ace.no_check then
	    stbe := base_feature.sedb_trace_before_exit
	    if not stbe.is_unknown then
	       cpp.put_trace_or_sedb_instruction(stbe)
	    end
	    c_set_dump_stack_top(fz_caller, fz_unlink)
         end
         -- (5) ------------------------------- SCOOP handling:
         if smart_eiffel.scoop and then arguments /= Void then
            cpp.put_string(once "}%N")
            arguments.c_unlock_scoop
            cpp.put_string(once "/*</SCOOP>*/}%N")
         end
      end

   external_c_prototype(p: POSITION; er: EXTERNAL_ROUTINE) is
         -- Define a C prototype for the `er' external routine.
      require
	 not p.is_unknown
	 er = base_feature
      local
	 comment: STRING
      do
	 comment := once "... mini local unique buffer ..."
	 comment.clear_count
	 comment.append(once "/* Extra external prototype for line ")
	 p.line.append_in(comment)
	 comment.append(fz_81)
	 comment.append(p.path)
	 comment.append(once ":*/%N")
         external_c_prototype_for(comment,er)
         c_code.append(fz_00)
         cpp.swap_on_h
         cpp.put_string(c_code)
         cpp.swap_on_c
      ensure
         cpp.on_c
      end

   use_current_state: INTEGER
	 -- Memory cache for `use_current' (see below *_state constants).

   stupid_switch_state: INTEGER
	 -- Memory cache for `stupid_switch' (see below *_state constants).


   False_state,     -- already computed and False.
   True_state,      -- already computed and True.
   Unknown_state,   -- not yet computed.
   Computing_state: -- during computation.
   INTEGER is unique

   frozen std_compute_use_current is
      require
         is_in_computation
      do
         smart_eiffel.push(Current)
         if use_current_state = Computing_state then
            if require_assertion /= Void then
               if require_assertion.use_current then
                  use_current_state := True_state
               end
            end
         end
         if use_current_state = Computing_state then
            if routine_body /= Void then
               if routine_body.use_current then
                  use_current_state := True_state
               end
            end
         end
         if use_current_state = Computing_state then
            if rescue_compound /= Void then
               if rescue_compound.use_current then
                  use_current_state := True_state
               end
            end
         end
         if use_current_state = Computing_state then
            if ensure_assertion /= Void then
               if ensure_assertion.use_current then
                  use_current_state := True_state
               end
            end
         end
         if use_current_state = Computing_state then
            use_current_state := False_state
         end
         smart_eiffel.pop
      ensure
         use_current_state = False_state or else
         use_current_state = True_state
      end

   compute_use_current is
      require
         is_in_computation
      deferred
      ensure
         use_current_state = True_state or else
         use_current_state = False_state
      end

   frozen std_compute_stupid_switch(run_time_set: RUN_TIME_SET) is
      require
         stupid_switch_state = Computing_state
      local
         rt: E_TYPE
      do
         smart_eiffel.push(Current)
         check
            smart_eiffel.same_base_feature(Current,run_time_set)
         end
         rt := result_type
         if rt /= Void and then rt.is_user_expanded then
            stupid_switch_state := False_state
         end
         if stupid_switch_state = Computing_state then
            if routine_body /= Void then
               if not routine_body.stupid_switch(run_time_set) then
                  stupid_switch_state := False_state
               end
            end
         end
         if stupid_switch_state = Computing_state then
            if rescue_compound /= Void then
               if not rescue_compound.stupid_switch(run_time_set) then
                  stupid_switch_state := False_state
               end
            end
         end
         if stupid_switch_state = Computing_state then
            stupid_switch_state := True_state
         end
         smart_eiffel.pop
      ensure
         stupid_switch_state = True_state
	    or else
	 stupid_switch_state = False_state
      end

   c_code: STRING is
      once
	 create Result.make(512)
      end

   update_tmp_jvm_descriptor is
      deferred
      end

   tmp_jvm_descriptor: STRING is
      once
         create Result.make(128)
      end

   routine_update_tmp_jvm_descriptor is
         -- For RUN_FEATURE_3/4/5/6/7/8/9/10/11 :
      local
         ct, rt: E_TYPE
      do
         tmp_jvm_descriptor.extend('(')
         ct := current_type
         ct.jvm_target_descriptor_in(tmp_jvm_descriptor)
         if arguments /= Void then
            arguments.jvm_descriptor_in(tmp_jvm_descriptor)
         end
         rt := result_type
         if rt = Void then
            tmp_jvm_descriptor.append(fz_19)
         else
            rt := rt.run_type
            tmp_jvm_descriptor.extend(')')
            rt.jvm_descriptor_in(tmp_jvm_descriptor)
         end
      end

   method_info_start is
      local
         flags: INTEGER
      do
         flags := current_type.jvm_method_flags
         method_info.start(flags,name.to_key,jvm_descriptor)
      end

   jvm_increment_invariant_flag is
      local
         name_idx: INTEGER; descriptor_idx: INTEGER; idx: INTEGER
      do
         if not method_info.is_static and run_class.base_class.assertion_level >= level_invariant and not run_class.invariant_flag then
            name_idx := constant_pool.idx_utf8("invariant_flag")
            descriptor_idx := constant_pool.idx_utf8(fz_i)
            field_info.add(1,name_idx,descriptor_idx)
            run_class.set_invariant_flag
         end
         if not method_info.is_static and run_class.base_class.assertion_level >= level_invariant then
            code_attribute.opcode_aload_0
            run_class.opcode_checkcast_1
            idx := constant_pool.idx_fieldref3(run_class.fully_qualified_name,"invariant_flag",fz_i)
            code_attribute.opcode_getfield( idx, -1 )
            code_attribute.opcode_iconst_1
            code_attribute.opcode_iadd
            code_attribute.opcode_aload_0
            run_class.opcode_checkcast_1
            code_attribute.opcode_swap
            code_attribute.opcode_putfield( idx, 1 )
         end
      end

   jvm_decrement_invariant_flag is
      local
         idx: INTEGER
      do
         if not method_info.is_static and run_class.base_class.assertion_level >= level_invariant then
            code_attribute.opcode_aload_0
            run_class.opcode_checkcast_1
            idx := constant_pool.idx_fieldref3(run_class.fully_qualified_name,"invariant_flag",fz_i)
            code_attribute.opcode_getfield( idx, -1 )
            code_attribute.opcode_iconst_1
            code_attribute.opcode_isub
            code_attribute.opcode_aload_0
            run_class.opcode_checkcast_1
            code_attribute.opcode_swap
            code_attribute.opcode_putfield( idx, 1 )
         end
      end

   jvm_define_opening is
      require
         jvm.current_frame = Current
      local
         space, i: INTEGER
      do
         -- (1) -------------------- Local variable for Result :
         if result_type /= Void then
            space := result_type.jvm_push_default
	    if is_once_function then
	       once_routine_pool.jvm_result_store(Current)
	    else
	       result_type.jvm_write_local_creation(jvm_result_offset)
	    end
         end
         -- (2) ----------------------- User's local variables :
         if local_vars /= Void then
            local_vars.jvm_initialize
         end
         -- (3) ------------------------ Execute old epressions:
	 if old_list /= Void then
	    from
	       i := old_list.upper
	    until
	       i < old_list.lower
	    loop
	       old_list.item(i).compile_to_jvm_old
	       i := i - 1
	    end
	 end
         jvm_try_begin := code_attribute.program_counter
         -- (4) ----------------------- Require assertion code :
         if current_type.base_class.require_check and then require_assertion /= Void then
            require_assertion.compile_to_jvm
         end
      end

   jvm_define_closing is
      require
         jvm.current_frame = Current
      local
         idx: INTEGER
      do
         -- (0) ----------------------------- Class Invariant :
         -- (1) --------------------------- Ensure Check Code :
         if run_class.base_class.assertion_level >= level_ensure then
	 if ensure_assertion /= Void then
	    ensure_assertion.compile_to_jvm(True)
	    code_attribute.opcode_pop
         end
         end
         jvm_try_end := code_attribute.program_counter
         -- (0) ----------------------------- Class Invariant :
         run_class.jvm_check_class_invariant_1
         -- (2) --------------------- Free for local expanded :
         -- (3) --------------------- Rescue :
         jvm_handler := code_attribute.program_counter + 1
         if rescue_compound /= Void then
-- save exception
            code_attribute.opcode_return
            code_attribute.opcode_astore( jvm_max_locals - 1 )
-- rescue clause
            rescue_compound.compile_to_jvm
-- rethrow exception
            code_attribute.opcode_aload( jvm_max_locals - 1 )
            code_attribute.opcode_athrow
            idx := constant_pool.idx_class2( "java/lang/Exception" )
            code_attribute.add_exception( jvm_try_begin, jvm_try_end, jvm_handler, idx )
         end
      end

   routine_afd_check is
      do
         if current_type.base_class.require_check and then require_assertion /= Void then
            require_assertion.afd_check
         end
         if routine_body /= Void then
            routine_body.afd_check
         end
         if rescue_compound /= Void then
            rescue_compound.afd_check
         end
         if ensure_assertion /= Void then
            ensure_assertion.afd_check
         end
      end

   c_initialize_frame_information(c_locals_count: INTEGER) is
      require
         ace.no_check
      local
         i, j: INTEGER; c: CHARACTER
      do
	 cpp.put_string(once "static se_frame_descriptor fd={")
	 put_c_name_tag
	 c_code.clear_count
	 c_code.extend(',')
	 if use_current then
	    c_code.extend('1')
	 else
	    c_code.extend('0')
	 end
	 c_code.extend(',')
	 c_locals_count.append_in(c_code)
	 c_code.append(once ",%"")
	 c_code.append(c_frame_descriptor_format)
	 c_code.append(once "%",1};%Nse_dump_stack ds;%Nds.fd=&fd;%N%
			    %ds.current=")
         if use_current then
	    if current_type.is_expanded then
	       if current_type.is_user_expanded then
		  c_code.append(once "(void**)")
               --elseif smart_eiffel.run_class(current_type).run_time_mark = as_native_array_character then
               --   -- NATIVE_ARRAY[CHARACTER]
               --   c_code.append(once "(void*)")
	       else
		  c_code.append(once "(void**)&")
	       end
	    else
	       c_code.append(once "(void**)&")
	    end
	    c_code.extend('C')
         else
            c_code.append(fz_null)
         end
	 c_code.extend(';')
	 c_code.extend('%N')
         cpp.put_string(c_code)
         cpp.put_position_in_ds(start_position)
         cpp.put_string(once "ds.caller=caller;%N")
         if c_locals_count <= 0 then
            cpp.put_string(once "ds.locals=NULL;%N")
	 else
            cpp.put_string(once "ds.locals=locals;%N")
         end
         cpp.put_string(once "ds.exception_origin=NULL;%N");
         from
            j := 1
         until
            i = c_locals_count
         loop
            cpp.put_string(once "locals[")
            cpp.put_integer(i)
            cpp.put_string(once "]=")
            from
               c := c_frame_descriptor_locals.item(j)
            until
               c = ','
            loop
               cpp.put_character(c)
               j := j + 1
               c := c_frame_descriptor_locals.item(j)
            end
            j := j + 1
            cpp.put_string(fz_00)
            i := i + 1
         end
      end

   c_scoop_initialize_frame_descriptor(n: STRING) is
      require
         ace.no_check
      do
	 cpp.put_string(once "static se_frame_descriptor fd={")
	 cpp.put_string(n)
	 put_c_name_tag
	 cpp.put_string(once "[
	    ,0,0,"",1};
	    se_dump_stack ds = {NULL,NULL,0,NULL,NULL};
	    ds.fd=&fd;

		   ]")
         cpp.put_position_in_ds(start_position)
	 -- *** MUST NOT BE NULL FOR SEPARATE DEBUGGING

	 c_set_dump_stack_top(once "&ds", fz_link)
      end

   c_scoop_define_wrapper(has_like_current: BOOLEAN) is
         -- Define the SCOOP function wrapper. (The C prototype is the same as 
         -- an ordinary function.)
      require
         cpp.on_c
         smart_eiffel.scoop
      local
         i, c, mem_id, local_id: INTEGER; t, local_type: E_TYPE
	 local_run_feature: RUN_FEATURE
      do
         mem_id := id
	 if has_like_current then
	    local_type := current_type
	    local_id := mem_id
	    local_run_feature := Current
	 else
	    local_type := current_type.local_from_separate
	    local_id := local_type.id
	    local_run_feature := local_type.run_class.at(name)
	 end
	 check
	    local_run_feature /= Void
	 end
         -- Struct for the local variables to wrap:
         c_code.clear_count
         c_code.append(once "typedef struct {")
	 local_type.c_type_for_target_in(c_code)
         c_code.append(once " C;")
         if arguments /= Void then
            arguments.c_scoop_struct_in(c_code)
         end
         c_code.append(once "} Tw")
	 local_id.append_in(c_code)
         name.mapping_c_in(c_code)
         c_code.append(fz_00)
         cpp.put_string_on_h(c_code)
         -- (0) ------------------------ Local SCOOP variables:
         cpp.put_string(once "[
	    se_subsystem_t* self = se_current_subsystem_thread();
	    se_subsystem_t* client = C->subsystem;

			      ]")
         -- (1) -------------------- Local variable for Result :
         if result_type /= Void then
            t := result_type.run_type
            c_code.clear_count
            t.c_type_for_result_in(c_code)
            c_code.append(once " R=")
            t.c_initialize_in(c_code)
            c_code.append(fz_00)
            cpp.put_string(c_code)
         end
         -- (2) ----------------------------------- Prepare ds:
         if ace.no_check then
            c_scoop_initialize_frame_descriptor(
               once "%"<separate wrapper> %"")
         end
         -- (3) --------------------- False separate detection:
	 cpp.put_string(once "if (self == client) {%N")
	 if has_like_current then
	    c_define_body
	 else
	    if result_type /= Void then
	       cpp.put_string(fz_26)
	    end
	    cpp.push_scoop_wrapper(local_run_feature)
	    local_run_feature.mapping_c
	    cpp.pop
	    if result_type /= Void then
	       cpp.put_string(fz_14)
	    end
	 end
	 cpp.put_string(once "}%Nelse {%N")
         c_code.clear_count
         c_code.append(once "Tw")
	 local_id.append_in(c_code)
         name.mapping_c_in(c_code)
         c_code.append(once "* data = (Tw")
         local_id.append_in(c_code)
         name.mapping_c_in(c_code)
         c_code.append(once "*)malloc(sizeof(Tw")
         local_id.append_in(c_code)
         name.mapping_c_in(c_code)
         c_code.append(once "));%N")
         cpp.put_string(c_code)
         -- (4) -------------------------------- Function wrap:
         if use_current then
            c_code.clear_count
	    if has_like_current then
	       c_code.append(once "data->C=C;%N")
	    else
	       c_code.append(once "data->C=C->ref;%N") --*** TO BE CHECKED for TYPE_CLASS
	    end
            cpp.put_string(c_code)
         end
         if arguments /= Void then
            from
               i := 1
               c := arguments.count
            until
               i > c
            loop
               c_code.clear_count
               c_code.append(once "data->_")
               c_code.append(arguments.name(i).to_string)
	       if arguments.type(i).is_expanded then
		  c_code.append(once "=(a")
		  i.append_in(c_code)
	       else
		  c_code.append(once "=(T0*)as_separate(self,a")
		  i.append_in(c_code)
	       end
               c_code.append(fz_14)
               cpp.put_string(c_code)
               i := i + 1
            end
         end
         -- (5) -------------------------------- Function call:
         c_code.clear_count
         if result_type /= Void then
            c_code.append(once "client->vft.query")
         else
            c_code.append(once "client->vft.command")
         end
         c_code.append(once "(client,&Su")
         mem_id.append_in(c_code)
         name.mapping_c_in(c_code)
         c_code.append(once ",data,sizeof(Tw")
         local_id.append_in(c_code)
         name.mapping_c_in(c_code)
         c_code.extend(')')
         if result_type /= Void then
            c_code.append(once ",&R")
         end
         c_code.append(fz_14)
         cpp.put_string(c_code)
	 cpp.put_string(fz_12)
         -- (5) ------------------------------------ Unlink ds:
         if ace.no_check then
	    c_set_dump_stack_top(fz_caller, fz_unlink)
         end
      end

   c_scoop_define_unwrap(has_like_current: BOOLEAN) is
         -- Define function unwrapper
         -- C prototype: void unwrap(void* data, int length, void* result)
      require
         cpp.on_c
         smart_eiffel.scoop
      local
	 mem_id: INTEGER; local_type: E_TYPE
	 local_run_feature: RUN_FEATURE
      do
         mem_id := id
         -- (0) ------------------------ Local SCOOP variables:
         cpp.put_string(
            once "se_subsystem_t* self = se_current_subsystem_thread();%N")
         -- (2) ----------------------------------- Prepare ds:
         if ace.no_check then
            c_scoop_initialize_frame_descriptor(
               once "%"<separate unwrapper> %"")
         end
         -- (3) -------------------------------- Function call:
         if result_type /= Void then
	    c_code.clear_count
            c_code.append(once "*((")
	    result_type.c_type_for_result_in(c_code)
	    c_code.append(once "*)result_ref)=")
	    cpp.put_string(c_code)
         end
	 if has_like_current then
	    cpp.push_scoop_unwrapper(Current)
	    mapping_c
	    cpp.pop
	 else
	    local_type := current_type.local_from_separate
	    local_run_feature := local_type.run_class.at(name)
	    check local_type.run_class.run_time_set.count = 1 end
	    cpp.push_scoop_unwrapper(local_run_feature)
	    local_run_feature.mapping_c
	    cpp.pop
	 end

	 if result_type /= Void then
	    cpp.put_string(fz_00)
	    if result_type.is_reference then
	       cpp.put_string(once "*((sT0**)result_ref)=as_separate(self,%
				   %*(T0**)result_ref);%N")
	    end
	 end
         cpp.put_string(once "free(data);%N")
         -- (4) ------------------------------------ Unlink ds:
         if ace.no_check then
	    c_set_dump_stack_top(fz_null, fz_unlink)
         end
      end

   initialize is
         -- Perform carefully the initialization (must not trigger
         -- another `initialize').
      deferred
      end

   frozen default_rescue_compound: COMPOUND is
         -- If necessary, builds and returns an "artificial" compound that 
         -- simply calls `default_rescue'. If the `default_rescue' routine is 
         -- from GENERAL or is an empty routine, then no compound is built and 
         -- Void is returned, so as to avoid generation of costly 
         -- SETJMP/LONGJMPs. 
      do
         Result := run_class.get_default_rescue(name)
      end

   frozen make(ct: like current_type; n: like name; bf: like base_feature) is
      require
         not smart_eiffel.is_ready
         ct.is_static
	 ct.run_class.at(n) = Void
         bf /= Void
      local
	 local_run_feature: RUN_FEATURE
	 local_type: E_TYPE
      do
         smart_eiffel.push(Current)
	 run_class := ct.run_class
	 debug
	    debug_info := "{"
	    debug_info.append(ct.run_time_mark)
	    debug_info.extend('}')
	    debug_info.extend('.')
	    debug_info.append(n.to_string)
	 end
         current_type := ct
         name := n
         base_feature := bf
         run_class.add_run_feature(Current,n)
         smart_eiffel.magic_count_increment
         use_current_state := Unknown_state
         stupid_switch_state := Unknown_state
         initialize
	 debug
	    debug_info.clear_count
	    debug_info_in(debug_info)
	 end
         smart_eiffel.pop
	 if current_type.is_separate then
	    -- "enlive" the non-separate version of the feature
	    local_type := current_type.local_from_separate
	    local_run_feature := local_type.run_class.get_feature(name)
	 end
      ensure
         run_class.at(name) = Current
      end

   debug_info: STRING; -- To view more under sedb.

   stupid_switch_comment: STRING is
      deferred
      end

feature {NONE}

   put_current_thread is
      require
         smart_eiffel.scoop
      local
         my_buffer: STRING
      do
	 my_buffer := once "..............."
	 my_buffer.clear_count
	 put_current_thread_in(my_buffer)
	 cpp.put_string(my_buffer)
      end

   put_current_thread_in(buffer: STRING) is
      require
         smart_eiffel.scoop
      do
	 if current_type.is_separate then
            buffer.append(once "self")
         else
            buffer.append(once "se_current_subsystem_thread()")
         end
      end

feature {BASE_CLASS}

   set_clients_with_any is
      do
	 check
	    clients_memory = Void
	 end
	 create clients_memory.omitted
      end
   
feature {RUN_FEATURE_VISITOR}

   accept(visitor: RUN_FEATURE_VISITOR) is
      deferred
      end

feature {NONE} -- Some SCOOP helpers:

   c_define_body is
         -- Produce C code for the body definition.
      require
         cpp.on_c
      deferred
      ensure
         cpp.on_c
      end

   in_scoop_wrapper: BOOLEAN
         -- True when defining SCOOP wrap() and unwrap() functions

invariant

   current_type /= Void

   name /= Void

   base_feature /= Void

end -- RUN_FEATURE
