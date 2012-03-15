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
class SMART_EIFFEL
   --
   -- Singleton object to handle general purpose information about the 
   -- SmartEiffel global compilation process. (This singleton is shared via 
   -- the GLOBALS.`smart_eiffel' once function.)
   --

inherit
   GLOBALS
   VISITABLE

feature

   copyright: STRING is "[
      SmartEiffel The GNU Eiffel Compiler, Eiffel tools and libraries
      Release 1.2r7 transitional Release (Sunday April 2nd 2006)
      This is an unofficial release. Check http://SmartEiffel.loria.fr for
      the official SmartEiffel
      Copyright (C), 1994-2003 - INRIA - LORIA - UHP - Nancy 2 - FRANCE
      D.COLNET, S.COLLIN, O.ZENDRA, P.RIBET, C.ADRIAN 
      Copyright (C) 2005-2006 D.F.MOISSET - smarteiffel@except.com.ar
      http://opensvn.csie.org/traccgi/smarteiffel12

      ]"

   status: INTEGER
	 -- The compilation process reach different `status' which are
	 -- described below. Note: at time being, `status' are simply
	 -- numbered because I don't have yet a precise idea for
	 -- appropriate names.
	 --
	 -- 0 `status': live code gathering has just started but is not yet
	 --   finished. At this time we are not aware of all types which may
	 --   be created at run-time.
	 -- 1 `status': falling-down process has just started. During this
	 --   process, all call sites are considered again in order to know
	 --   more about effective definitions of deferred features or
	 --   redefinitions. At this time, because new code may be
	 --   considered, we are not aware of all types which may be created
	 --   at run-time.
	 -- 2 `status': after-falling-down process has just started. The goal
	 --   of this step is to finish the complete computation of the
	 --   actual set of live types. At the end of this process, all live
	 --   types are known and all source files should be loaded.
	 -- 3 `status': whole system analysis for the final safety check has 
	 --   just  started but is not yet finished.
	 -- 4 `status': the system is _not_ type safe (i.e. some dangerous
	 --   covariant redefinitions are used and the user has got 
	 --   warnings).
	 -- 5 `status': the safety check test has not been performed 
	 --   (because of the compilation mode for example), so, we do not 
	 --   know if the system is safe or not.
	 -- 6 `status': whole system analysis is finished and the system is
	 --   type safe! Great!

   is_ready: BOOLEAN is
	 -- Is all the live code alerady gathered (`status' in 4 .. 6)? 
      do
	 Result := status.in_range(4, 6)
      end

   short_flag: BOOLEAN
         -- True when command `short' is running.

   pretty_flag: BOOLEAN
         -- True when command `pretty' is running.

   no_id: BOOLEAN
         -- True when the ids file has not to be read.

   base_class(class_name: CLASS_NAME): BASE_CLASS is
	 -- Retrieve the good one into the `base_class_dictionary' or launch 
	 -- the `eiffel_parser' if this class is not yet loaded. 
	 -- (See also `loaded_base_class'.)
      require
         class_name /= Void
      do
	 Result := base_class_dictionary.reference_at(class_name)
         if Result = Void then
	    if no_file_for(class_name.to_string) then
	       create Result.face_class(class_name.to_string)
               echo.put_integer(base_class_count)
               echo.put_character('%T')
               echo.put_character('(')
               echo.put_string(class_name.to_string)
               echo.put_character(')')
               echo.put_character('%N')
	    elseif eiffel_parser.is_running then
	       error_handler.append("Internal Error #1 in SMART_EIFFEL.")
	       error_handler.print_as_fatal_error
	    else
	       if ace.parser_buffer_for(class_name.to_string) then
		  Result := eiffel_parser.analyse_class(class_name)
		  check
		     Result /= Void
                     implies
		     base_class_dictionary.has(class_name)
		  end
	       end
	       if Result = Void then
		  error_handler.add_position(class_name.start_position)
		  error_handler.append("Unable to load class %"")
		  error_handler.append(class_name.to_string)
		  error_handler.append("%".")
		  error_handler.print_as_fatal_error
	       end
	    end
	 end
	 check Result /= Void end
	 Result.obsolete_warning(class_name)
      end

   loaded_base_class(cn: CLASS_NAME): BASE_CLASS is
	 -- Retrieve the good one into the `base_class_dictionary'. When the 
	 -- corresponding class `cn' is not yet loaded, the `eiffel_parser' 
	 -- is _not_ launched and the Result is Void. 
	 -- (See also `loaded_base_class'.)
      do
         Result := base_class_dictionary.reference_at(cn)
      end

   same_base_feature(up_rf: RUN_FEATURE; run_time_set: RUN_TIME_SET)
      : BOOLEAN is
         -- True when all `dynamic' features of the `run_time_set' have 
         -- excately the same final name and refer exactely to the same 
         -- `base_feature'.
      require
	 up_rf /= Void
         is_ready and run_time_set.count > 1
      local
         i: INTEGER; f: E_FEATURE; dyn_rf: RUN_FEATURE; rc: RUN_CLASS
      do
         from
            Result := True
            i := run_time_set.count
            f := up_rf.base_feature
         until
            not Result or else i = 0
         loop
            rc := run_time_set.item(i)
            dyn_rf := rc.dynamic(up_rf)
            if f = dyn_rf.base_feature then
               if dyn_rf.name.to_string /= up_rf.name.to_string then
                  Result := False
               end
            else
               Result := False
            end
            i := i - 1
         end
      end

   no_file_for(class_name: STRING): BOOLEAN is
      require
	 class_name = string_aliaser.item(class_name)
      do
	 if as_none = class_name then
	    Result := True
	 elseif as_tuple = class_name then
	    Result := True
	 elseif as_routine = class_name then
	    Result := True
	 elseif as_procedure = class_name then
	    Result := True
	 elseif as_function = class_name then
	    Result := True
	 elseif as_predicate = class_name then
	    Result := True
	 end
      end

   stupid_switch(t: E_TYPE; run_time_set: RUN_TIME_SET): BOOLEAN is
         -- True when `t' drives exactely to the same `t.run_type' for all 
         -- element of the `run_time_set'.
      require
         is_ready
      do
	 if run_time_set.count <= 1 then
            Result := True
         else
            Result := t.stupid_switch(run_time_set)
         end
      end

   generating_type_used: BOOLEAN
         -- When GENERAL `generating_type' is used.

   generator_used: BOOLEAN
         -- When GENERAL `generator' is used.

   deep_twin_used: BOOLEAN
	 -- When `deep_twin' support is necessary.

   scoop: BOOLEAN
         -- When some SCOOP functions are used. See scoop.html for details.

feature {RUN_CLASS, CREATE_TOOLS}

   set_scoop is
      do
         scoop := True
      end

feature {GC_HANDLER,C_PRETTY_PRINTER}

   root_procedure: RUN_FEATURE_3
	 -- The root procedure of the system to compile.

feature {PRETTY}

   re_load_class(bc: BASE_CLASS): BOOLEAN is
	 -- Try to re-parse the `bc' class to check that this newly created
	 -- class is syntactically correct.
      require
         bc /= Void
      local
	 name: CLASS_NAME; new_class: like bc
      do
         name := bc.name
         check
            base_class_dictionary.has(name)
         end
         base_class_dictionary.remove(name)
         if ace.parser_buffer_for(name.to_string) then
            new_class := eiffel_parser.analyse_class(name)
         end
         Result := new_class /= Void
      end

feature {BASE_CLASS}

   add_base_class(bc: BASE_CLASS) is
      require
         bc /= Void
      local
	 name: CLASS_NAME
      do
         name := bc.name
         check
            not base_class_dictionary.has(name)
         end
         base_class_dictionary.put(bc,name)
         magic_count_increment
      ensure
         base_class_dictionary.has(bc.name)
      end

feature {FINDER, SMART_EIFFEL_VISITOR}

   find_path_for(arg: STRING): STRING is
      do
         if ace.parser_buffer_for(arg) then
            Result := parser_buffer.path
	    parser_buffer.release
         end
      end

feature {CLASS_CHECKER, SMART_EIFFEL_VISITOR}

   set_short_flag is
      do
         short_flag := True
         set_no_id
      end

feature {PRETTY, SMART_EIFFEL_VISITOR}

   set_pretty_flag is
      do
         pretty_flag := True
         set_no_id
      end

feature {SMART_EIFFEL_VISITOR}

   set_no_id is
      do
         no_id := True
      end

feature

   bit_n_ref_is_nyi_error(p: POSITION) is
      do
	 error_handler.add_position(p)
	 error_handler.append(
             "Type %"reference BIT_N%" is not yet implemented.")
	 error_handler.print_as_error
      end

   run_class(simple_type: E_TYPE): RUN_CLASS is
      require
         simple_type.run_type = simple_type
      local
         rtm: STRING
      do
         rtm := simple_type.run_time_mark
	 Result := run_class_dictionary.reference_at(rtm)
         if Result = Void then
            create Result.make(simple_type, rtm)
            check
               run_class_dictionary.has(rtm)
            end
         end
      ensure
         Result /= Void
      end

   base_class_count: INTEGER is
         -- Total number of base class actually loaded.
      do
         Result := base_class_dictionary.count
      end

   compile_to_c is
         -- Produce C code for `root_class'/`procedure'.
      local
         root_class, procedure: STRING; rc: RUN_CLASS
	 run_count, i: INTEGER; gc_flag: BOOLEAN
      do
         root_class := ace.root_class_name
         procedure := ace.root_procedure_name
         get_started(root_class, procedure)
         if nb_errors = 0 then
            check
               root_procedure /= Void
            end
            cpp.get_started
            cpp.swap_on_h
            gc_flag := not gc_handler.is_off
            -- ---------------------------------------------------------
	    if ace.boost then
	       cpp.put_string_on_h(once "#define SE_BOOST 1%N")
            end
	    if ace.sedb then
	       cpp.put_string_on_h(once "#define SE_SEDB 1%N")
            end
	    if gc_flag then
	       cpp.put_string_on_h(once "#define SE_GC_LIB 1%N")
            end
	    if exceptions_handler.used then
	       cpp.put_string_on_h(once "#define SE_EXCEPTIONS 1%N")
	    end
	    if scoop then
	       cpp.put_string_on_h(once "#define SE_SCOOP 1%N")
	    end
	    -- ---------------------------------------------------------
            if scoop then
               cpp.sys_runtime_h_and_c(once "scoop")
               cpp.sys_runtime_h_and_c(once "scoop_thread")
               system_tools.add_lib_scoop
            end
            -- ---------------------------------------------------------
            from
               cpp.put_comment_line(once "C Header Pass 1 :")
	       agent_pool.c_header_pass1
	       update_run_class_map
               i := run_class_map.upper
            until
               i < 0
            loop
               rc := run_class_map.item(i)
               if rc.at_run_time then
                  run_count := run_count + 1
               end
               rc.c_header_pass1
               i := i - 1
            end
            -- ---------------------------------------------------------
            from
               cpp.put_comment_line(once "C Header Pass 2 :")
	       update_run_class_map
               i := run_class_map.upper
            until
               i < 0
            loop
               rc := run_class_map.item(i)
               rc.c_header_pass2
               i := i - 1
            end
            -- ---------------------------------------------------------
            from
               cpp.put_comment_line(once "C Header Pass 3 :")
	       update_run_class_map
               i := run_class_map.upper
            until
               i < 0
            loop
               rc := run_class_map.item(i)
               rc.c_header_pass3
               i := i - 1
            end
            -- ---------------------------------------------------------
            from
               cpp.put_comment_line(once "C Header Pass 4 :")
	       update_run_class_map
               i := run_class_map.upper
	    until
               i < 0
            loop
               rc := run_class_map.item(i)
               rc.c_header_pass4
               i := i - 1
            end
            -- Force definition of T9 and T7 :
            if not run_class_dictionary.has(as_native_array_character) then
               cpp.put_string(once "typedef T3* T9;%N")
               if ace.no_check then
                  cpp.put_c_function(once "void se_prinT9(FILE* file, T9*o)",
                      once "fprintf(file, %"NATIVE_ARRAY[STRING]#%%p\n%",(void*)*o);")
               end
            end
            manifest_string_pool.c_define1(string_at_run_time)
            cpp.customize_runtime(sys_runtime_basic)
            -- ---------------------------------------------------------
            if gc_flag then
               gc_handler.define1
            end
            -- ---------------------------------------------------------
            compile_routines
            cpp.cecil_define
            -- ---------------------------------------------------------
	    if ace.sedb then
               prepare_introspection
            end
            -- ---------------------------------------------------------
            cpp.define_main(root_procedure)
            manifest_string_pool.c_define2(string_at_run_time)
            compile_registered_for_c_define
            address_of_pool.c_define
            if gc_flag then
               gc_handler.define2
            end
            manifest_array_pool.c_define
            switch_collection.c_define
	    agent_pool.c_define_missing_agent_launcher
            cpp.define_used_basics
	    if scoop then
	       separate_tools.generate_scoop_functions(run_class_map)
	    end
            debug
               echo.put_string(once "Very Final magic_count : ")
               echo.put_integer(magic_count)
               echo.put_character('%N')
            end
            cpp.write_make_file
	    very_last_information
         else
            error_handler.append("Cannot produce C code.")
            error_handler.print_as_error
         end
      end

   compile_to_jvm is
         -- Produce Java Byte Code for `root_class'/`procedure'.
      local
         root_class, procedure: STRING
         rc: RUN_CLASS
         run_count, i: INTEGER
      do
         root_class := ace.root_class_name
         procedure := ace.root_procedure_name
         get_started(root_class, procedure)
         if scoop then
            not_yet_implemented
         end
         if nb_errors = 0 then
            jvm.prepare_output_directory
            from
	       update_run_class_map
               i := run_class_map.upper
            until
               i < 0
            loop
               rc := run_class_map.item(i)
               if rc.at_run_time then
                  run_count := run_count + 1
                  rc.compile_to_jvm
               end
               i := i - 1
            end
            echo.print_count(once "Used Type",run_count)
	    agent_pool.customize_jvm_runtime
            jvm.write_jvm_root_class
            jvm.write_main_class(root_procedure)
	    very_last_information
         else
            error_handler.append(once "Cannot produce Java Byte Code.")
            error_handler.print_as_error
         end
      end

feature {NONE}

   base_class_dictionary: HASHED_DICTIONARY[BASE_CLASS,CLASS_NAME] is
         -- When looking for a BASE_CLASS using the name of the base class
         -- (ie. FOO[BAR] is stored at key "FOO").
      once
         create Result.with_capacity(1024)
      end

feature

   magic_count: INTEGER
         -- Grow each time a new run class is added, each time a new class is 
         -- loaded, each time a new feature is checked, each time another 
         -- expression is optimized, etc. ...
         -- Thus when `magic_count' stops growing, we are really ready :-).

   magic_count_increment is
      do
         magic_count := magic_count + 1
      end

feature {GC_HANDLER}

   get_run_class_map: FAST_ARRAY[RUN_CLASS] is
      do
	 check
	    run_class_map.count = run_class_dictionary.count
	 end
	 Result := run_class_map
      end

feature {RUN_CLASS}

   run_class_dictionary: HASHED_DICTIONARY[RUN_CLASS,STRING] is
      once
         !!Result.with_capacity(2048)
      end

feature {BASE_CLASS,TYPE_BASIC_EIFFEL_EXPANDED}

   run_class_for(cn: CLASS_NAME): RUN_CLASS is
	 -- Assume `cn' is a simple non generic class.
      require
	 cn /= Void
      local
	 bc: BASE_CLASS; type_class: TYPE_CLASS
      do
         Result := run_class_dictionary.reference_at(cn.to_string)
         if Result = Void then
	    bc := base_class_dictionary.reference_at(cn)
	    if bc /= Void then
	       create type_class.make(bc.name)
	       Result := type_class.run_class
	    else
	       error_handler.append("SMART_EIFFEL Internal error for: ")
	       error_handler.append(cn.to_string)
	       error_handler.print_as_fatal_error
	    end
	 end
      ensure
	 Result /= Void
      end

feature {RUN_CLASS}

   is_tagged(rc: RUN_CLASS): BOOLEAN is
      require
         status >= 4
         rc.at_run_time
         rc.current_type.is_reference
         ace.boost
      local
         i: INTEGER; run_time_set: RUN_TIME_SET
      do
         from
	    update_run_class_map
            i := run_class_map.upper
	 until
            Result or else i < 0
         loop
            run_time_set := run_class_map.item(i).run_time_set
            if run_time_set.count = 0 then
            elseif run_time_set.has(rc) then
               Result := run_time_set.count > 1
            end
            i := i - 1
         end
      end
   
   memory_class_used: BASE_CLASS is
         -- The MEMORY class when used or Void when this class is not
         -- in the live code.
      local
	 cn: CLASS_NAME
      do
	 create cn.unknown_position(as_memory)
	 Result := base_class_dictionary.reference_at(cn)
      end

feature -- To add more Context for some `to_runnable' :

   top_rf: RUN_FEATURE is
      do
	 if not run_feature_stack.is_empty then
	    Result := run_feature_stack.last
	 end
      end

   push(rf: RUN_FEATURE) is
      do
         run_feature_stack.add_last(rf)
      ensure
         run_feature_stack.count = 1 + old (run_feature_stack.count)
      end

   pop is
      do
	 run_feature_stack.remove_last
      ensure
         run_feature_stack.count = old (run_feature_stack.count) - 1
      end

feature {NONE}

   run_feature_stack: FAST_ARRAY[RUN_FEATURE] is
	 -- The top-most one gives the current analysis context.
      once
         !!Result.with_capacity(50)
      end

   run_class_map: FAST_ARRAY[RUN_CLASS] is
      once
	 create Result.with_capacity(2048)
      end

   update_run_class_map is
      do
	 if run_class_map.count /= run_class_dictionary.count then
	    run_class_map.clear
	    run_class_dictionary.item_map_in(run_class_map)
	 end
      end

   falling_down is
      local
         rc: RUN_CLASS; i: INTEGER; n: STRING; root_type: E_TYPE
	 sp: POSITION; type_reference: TYPE_REFERENCE
      do
         if generator_used then
            type_string.set_at_run_time
         end
         address_of_pool.falling_down
	 agent_pool.falling_down
         from
	    update_run_class_map
            i := run_class_map.upper
         until
            i < 0
         loop
            rc := run_class_map.item(i)
	    n := rc.base_class_name.to_string
	    if no_file_for(n) or else n = as_bit_n then
	       -- No `falling_down' for NONE, TUPLE, ROUTINE, ...
	    else
	       type_reference ?= rc.current_type
	       if type_reference = Void then
		  rc.falling_down
	       elseif type_reference.expanded_type.is_integer then
		  rc.falling_down
		  if reference_integer_set = Void then
		     create reference_integer_set.make
		  end
		  reference_integer_set.add(rc)
	       end
	    end
            i := i - 1
         end
	 if reference_integer_set /= Void then
	    assignment_handler.force_compatibility(reference_integer_set)
	 end
	 if smart_eiffel.scoop then
	    root_type := root_procedure.current_type
	    if  not root_type.is_separate then
	       -- SCOOP needs the root object to be separate.
	       sp := root_type.start_position
	       root_type := separate_tools.create_type_separate(sp,
								root_type)
	       root_type := root_type.to_runnable(type_any)
	       root_procedure ?=
	                 root_type.run_class.get_feature(root_procedure.name)
	       check
		  root_procedure /= Void
	       end
	    end
         end
      end

   afd_check is
      local
         rc: RUN_CLASS; i: INTEGER
      do
         from
	    update_run_class_map
            i := run_class_map.upper
         until
            i < 0
         loop
            rc := run_class_map.item(i)
            rc.afd_check
            i := i - 1
         end
	 cecil_pool.afd_check
      end

   very_last_information is
      do
	 assignment_handler.echo_information
	 inspect
	    status
	 when 4 then
	    error_handler.append(
		"The system is not type safe (read previous %
		%warnings carefully.)")
	    error_handler.print_as_warning
	 when 5 then
	    echo.put_string(
		"Type-system safety check not performed in %
		%this mode (use flag -safety_check).%N")
	 when 6 then
	    echo.put_string("The system is type safe.%N")
	 end
	 eiffel_parser.show_nb_warnings
	 eiffel_parser.show_nb_errors
	 echo.put_string(fz_02)
      end

feature {RUN_FEATURE_9}

   afd_check_deferred(rf9: RUN_FEATURE_9) is
      do
         if not rf9_memory.fast_has(rf9) then
            rf9_memory.add_last(rf9)
         end
      end

feature {NONE}

   rf9_memory: FAST_ARRAY[RUN_FEATURE_9] is
      once
         !!Result.with_capacity(1024)
      end

   check_for_deferred is
      local
         i: INTEGER
         rf9: RUN_FEATURE
         rc: RUN_CLASS
      do
         from
            i := rf9_memory.upper
            echo.print_count(once "Deferred Routine",i+1)
         until
            i < 0
         loop
            rf9 := rf9_memory.item(i)
            rc := rf9.current_type.run_class
            if rc.at_run_time then
               error_handler.append(rf9.name.to_string)
               error_handler.append(once " is a deferred feature in ")
               error_handler.append(rf9.current_type.written_mark)
               warning(rf9.start_position,fz_dot_blank)
            end
            i := i - 1
         end
      end

   check_generic_formal_arguments is
      local
         i: INTEGER
      do
         from
            i := 1
         until
            i > base_class_dictionary.count
         loop
            base_class_dictionary.item(i).check_generic_formal_arguments
            i := i + 1
         end
      end

feature {ID_PROVIDER}

   id_extra_information(tfw: TEXT_FILE_WRITE; name: STRING) is
      local
         bc: BASE_CLASS; rc: RUN_CLASS; path: STRING; cn: CLASS_NAME
     do
	if name = as_none then
	else
	   rc := run_class_dictionary.reference_at(name)
	   if rc /= Void then
	      bc := rc.base_class
	   else
	      create cn.unknown_position(name)
	      bc := base_class_dictionary.reference_at(cn)
	   end
        end
	tfw.put_character('%N')
        if bc /= Void then
           tfw.put_string(once "class-path: %"")
           path := bc.path
           tfw.put_string(path)
           tfw.put_character('%"')
           tfw.put_character('%N')
           bc.id_extra_information(tfw)
        end
        if rc /= Void then
           rc.id_extra_information(tfw)
        end
     end

feature {CALL_PROC_CALL}

   covariance_check(call_site: POSITION; up_rf: RUN_FEATURE
		    run_time_set: RUN_TIME_SET) is
      require
	 not call_site.is_unknown
	 up_rf.arguments.count >= 1
	 not run_time_set.is_empty
      local
	 dyn_rf: RUN_FEATURE; up_args, dyn_args: FORMAL_ARG_LIST; 
	 r, a: INTEGER; t1, t2: E_TYPE
      do
	 from
	    r := 1
	    up_args := up_rf.arguments
	 until
	    r > run_time_set.count
	 loop
	    dyn_rf := run_time_set.item(r).dynamic(up_rf)
	    from 
	       a := 1
	       dyn_args := dyn_rf.arguments
	    until 
	       a > up_args.count
	    loop
	       t1 := up_args.type(a)
	       t2 := dyn_args.type(a)
	       if t1.run_time_mark /= t2.run_time_mark then
		  error_handler.add_position(call_site)
		  error_handler.append(
                      "Unsafe covariant redefinition (type %"")
		  error_handler.append(t1.run_time_mark)
		  error_handler.append("%" redefined as %"")
		  error_handler.append(t2.run_time_mark)
		  error_handler.append("%").")
		  error_handler.add_position(t1.start_position)
		  error_handler.add_position(t2.start_position)
		  error_handler.print_as_warning
		  status := 4
	       end
	       a := a + 1
	    end
	    r := r + 1
	 end
      end

feature {CALL_PROC_CALL,PRECURSOR_CALL,CREATE_TOOLS,E_AGENT}

   argument_passing_check(call_site: POSITION
			  arguments: EFFECTIVE_ARG_LIST
			  rf: RUN_FEATURE) is
	 --  Check if argument passing at `call_site' position is valid or 
	 --  not. This verification is here (i.e. not in class 
	 --  EFFECTIVE_ARG_LIST or in class FORMAL_ARG_LIST) because 
	 --  `arguments' or/and `formal_arg_list' may be both Void.
      require
	 not call_site.is_unknown
	 rf /= Void
      local
	 i: INTEGER; formal_arg_list: FORMAL_ARG_LIST
      do
	 formal_arg_list := rf.arguments
         if arguments = Void then
	    if formal_arg_list /= Void then
	       error_handler.add_position(call_site)
	       error_handler.add_position(formal_arg_list.start_position)
	       error_handler.append("The feature called has ")
	       i := formal_arg_list.count
	       error_handler.append_integer(i)
	       error_handler.append(" argument")
	       if i > 1 then
		  error_handler.extend('s')
	       end
	       error_handler.append(". (The actual argument list is empty.)")
	       error_handler.print_as_fatal_error
	    end
	 elseif formal_arg_list = Void then
	    error_handler.add_position(rf.start_position)
	    error_handler.add_position(arguments.start_position)
	    error_handler.append("There ")
	    i := arguments.count
	    if i > 1 then
	       error_handler.append("are ")
	    else
	       error_handler.append("is ")
	    end
	    error_handler.append_integer(i)
	    error_handler.append(" actual argument")
	    if i > 1 then error_handler.extend('s') end
	    error_handler.append(". (The feature found has no argument.)")
	    error_handler.print_as_fatal_error
	 else
	    arguments.match_with(rf)
         end
      end

feature {C_PRETTY_PRINTER}

   define_extern_tables is
      require
         cpp.on_c
      local
         size: INTEGER
      do
         size := id_provider.max_id + 1
         cpp.macro_def(once "SE_MAXID",size)
         if generator_used then
            cpp.put_extern4(once "T7*g", size)
         end
         if generating_type_used then
            cpp.put_extern4(once "T7*t",size)
         end
         if ace.no_check then
            cpp.put_extern4(once "char*p",size)
            c_code.copy(once "void(*se_prinT[")
            size.append_in(c_code)
            c_code.append(once "])(FILE*,void**)")
            cpp.put_extern1(c_code)
            c_code.copy(once "int se_strucT[")
            size.append_in(c_code)
            c_code.extend(']')
            cpp.put_extern1(c_code)
            if ace.sedb then
               c_code.copy(once "void*(*se_introspecT[")
               size.append_in(c_code)
               c_code.append(once "])(void*,char*,int*,int*)")
               cpp.put_extern1(c_code)
               c_code.copy(once "char* se_atT[")
               size.append_in(c_code)
               c_code.append(once "]")
               cpp.put_extern1(c_code)
            end
         end
      end

   initialize_path_table is
      require
         ace.no_check
         cpp.on_c
      local
         i, id: INTEGER; bc: BASE_CLASS; rc: RUN_CLASS
      do
         from
            cpp.put_string(once "p[0]=%"???%";%N")
            i := 1
         until
            i > base_class_dictionary.count
         loop
            bc := base_class_dictionary.item(i)
	    id := bc.id
	    if id > 0 then
	       cpp.put_string(once "p[")
	       cpp.put_integer(id)
	       cpp.put_string(once "]=")
	       cpp.put_string_c(bc.path)
	       cpp.put_string(fz_00)
	    end
            i := i + 1
         end
         from
	    update_run_class_map
            i := run_class_map.upper
         until
            i < 0
         loop
            rc := run_class_map.item(i)
            if rc.at_run_time then
               cpp.put_string(once "se_prinT[")
               cpp.put_integer(rc.id)
               cpp.put_string(once "]=((void(*)(FILE*,void**))se_prinT")
               cpp.put_integer(rc.id)
               cpp.put_string(once ");%N")
               if rc.current_type.is_generic then
                  cpp.put_string(once "p[")
                  cpp.put_integer(rc.id)
                  cpp.put_string(once "]=p[")
                  cpp.put_integer(rc.base_class.id)
                  cpp.put_string(once "];%N")
               end
               cpp.put_string(once "se_strucT[")
               cpp.put_integer(rc.id)
               cpp.put_string(once "]=sizeof(T")
               cpp.put_integer(rc.id)
               cpp.put_string(fz_14)
	       if ace.sedb then
		  cpp.put_string(once "se_introspecT[")
		  cpp.put_integer(rc.id)
		  cpp.put_string(once "]=((void*(*)(void*,char*,int*,int*))se_introspecT")
		  cpp.put_integer(rc.id)
		  cpp.put_string(once ");%N")
                  rc.prepare_introspection2
	       end
            end
            i := i - 1
         end
      ensure
         cpp.on_c
      end

   initialize_generator is
      require
         cpp.on_c
      local
         i, id: INTEGER; bc: BASE_CLASS; rc: RUN_CLASS
      do
         from
            i := 1
         until
            i > base_class_dictionary.count
         loop
            bc := base_class_dictionary.item(i)
	    id := bc.id
	    if id >= 0 then
	       cpp.put_array1('g',id)
	       cpp.put_character('=')
	       cpp.put_se_string(bc.name.to_string)
	       cpp.put_string(fz_00)
	    end
            i := i + 1
         end
         from
	    update_run_class_map
            i := run_class_map.upper
         until
            i < 0
         loop
            rc := run_class_map.item(i)
            if rc.at_run_time then
               bc := rc.base_class
               if bc.name.to_string /= rc.current_type.run_time_mark then
                  cpp.put_array1('g',rc.id)
                  cpp.put_character('=')
                  cpp.put_array1('g',bc.id)
                  cpp.put_string(fz_00)
               end
            end
            i := i - 1
         end
      ensure
         cpp.on_c
      end

   initialize_generating_type is
      require
         cpp.on_c
      local
         i: INTEGER; rc: RUN_CLASS; bc: BASE_CLASS; rtm: STRING
      do
         from
	    update_run_class_map
            i := run_class_map.upper
         until
            i < 0
         loop
            rc := run_class_map.item(i)
            if rc.at_run_time then
               cpp.put_array1('t',rc.id)
               cpp.put_character('=')
               bc := rc.base_class
               rtm := rc.current_type.run_time_mark
               if bc.name.to_string /= rtm then
                  cpp.put_se_string(rtm)
               else
                  cpp.put_array1('g',rc.id)
               end
               cpp.put_string(fz_00)
            end
            i := i - 1
         end
      ensure
         cpp.on_c
      end

feature {RUN_FEATURE_3}

   register_for_c_define(rf: RUN_FEATURE_3) is
      require
         rf /= Void
      do
         registered_for_c_define.add_last(rf)
      end

feature {RUN_FEATURE_7, RUN_FEATURE_8, AGENT_POOL}

   register_sys_runtime_basic_of(name: STRING) is
         -- Add some SmartEiffel/sys/runtime/basic_* package as
         -- an already used one in order to customize the runtime.
      require
         name.has_prefix("basic_")
      local
         package: STRING
      do
         from
            package := once "basic_...................."
            package.copy(name)
         until
            package.occurrences('_') = 1
         loop
            package.remove_last(1)
         end
         if not sys_runtime_basic.has(package) then
            package := package.twin
            sys_runtime_basic.add(package)
         end
      end

feature {RUN_CLASS}

   set_deep_twin_used is
      do
         deep_twin_used := True
      end

   reference_to_separate(source_type: E_TYPE) is
      require
         source_type.is_reference
      local
         i: INTEGER
         rc: RUN_CLASS
         type: E_TYPE
      do
         from
	    update_run_class_map
            i := run_class_map.upper
         until
            i < 0
         loop
            rc := run_class_map.item(i)
            type := rc.current_type
            if type.is_separate then
               if type.is_a(source_type) then
                  type := type.actual_separate(source_type)
                  rc := type.run_class
                  if not rc.at_run_time then
                     rc.set_at_run_time
                     source_type.run_class.falling_down
                  end
               else
                  error_handler.cancel
               end
            end
            i := i - 1
         end
      end

feature {RUN_FEATURE_8}

   set_generating_type_used is
      do
         generating_type_used := True
      end

   set_generator_used is
      do
         generator_used := True
      end

feature {CLUSTER}

   parse_include(include_name: STRING) is
      require
	 include_name /= Void
      local
	 bc: BASE_CLASS
      do
	 check parser_buffer.is_ready end
	 echo.put_string(once "Handling include of %"")
	 echo.put_string(include_name)
	 echo.put_string(once "%" from ACE file. (Parsing %"")
	 echo.put_string(parser_buffer.path)
	 echo.put_string(once "%".)%N")
	 bc := eiffel_parser.analyse_buffer
	 check
	    bc /= Void
	    implies
	    base_class_dictionary.has(bc.name)
	 end
      end

feature {SMART_EIFFEL_VISITOR}

   accept(visitor: SMART_EIFFEL_VISITOR) is
      do
         visitor.visit_smart_eiffel(Current)
      end

feature {NONE}

   sys_runtime_basic: HASHED_SET[STRING] is
         -- Actually used packages of SmartEiffel/sys/runtime.
         -- For example: basic_directory, basic_time, basic_*, etc.
      once
         !!Result.make
      end

   string_at_run_time: BOOLEAN is
      require
         is_ready
      local
         rc: RUN_CLASS
      do
         if run_class_dictionary.has(as_string) then
            rc := run_class_dictionary.at(as_string)
            Result := rc.at_run_time
         end
      end

   get_started(root_class_name, root_procedure_name: STRING) is
         -- Get started to compile using creation procedure `root_procedure_name'
         -- of base class `root_class_name'.
      require
         not root_class_name.is_empty
         not root_procedure_name.is_empty
      local
         sfn: FEATURE_NAME; root: BASE_CLASS; root_proc: E_PROCEDURE
         root_type: E_TYPE; magic: INTEGER; root_name: CLASS_NAME
      do
         if ace.no_check then
            set_generator_used
            set_generating_type_used
         end
	 ace.parse_include
	 create root_name.unknown_position(root_class_name)
         root := base_class(root_name)
         if root = Void then
            error_handler.append("Cannot load root class ")
            error_handler.append(root_class_name)
            error_handler.append(fz_dot_blank)
            error_handler.print_as_error
         elseif root.is_expanded then
	    error_handler.add_position(root.name.start_position)
	    error_handler.append("The root class must not be expanded (sorry,%
		      % but this is a limitation of the compiler).")
	    error_handler.print_as_fatal_error
	 else
	    sfn := root.root_creation_search(root_procedure_name)
            root_proc := root.root_procedure_check(sfn)
         end
         if nb_errors = 0 then
            if root_proc.arguments /= Void then
               error_handler.add_position(root_proc.start_position)
               error_handler.append("Creation procedure must not have arguments.")
               error_handler.print_as_fatal_error
            end
         end
         if nb_errors = 0 then
	    root_type := run_class_for(root.name).current_type
         end
         if nb_errors = 0 then
            root_procedure := root_proc.to_run_feature(root_type,sfn)
         end
         if nb_errors = 0 then
	    cecil_pool.fill_up
	    check status = 0 end
	    status := 1
            echo_magic_count(once "Starting Falling Down")
            if scoop then
               echo.put_string(once "(SCOOP target verification activated)%N")
            end
            from
               falling_down
            until
               magic = magic_count or else nb_errors > 0
            loop
               magic := magic_count
               falling_down
            end
            echo_magic_count(once "End of Falling Down")
         end
         if nb_errors = 0 then
	    check status = 1 end
	    status := 2
            echo_magic_count(once "Starting AFD Check")
            from
               afd_check
            until
               magic = magic_count or else nb_errors > 0
            loop
               magic := magic_count
               afd_check
            end
            check_for_deferred
            check_generic_formal_arguments
            echo_magic_count(once "Before conversion handling")
            assignment_handler.finish_falling_down
            echo_magic_count(once "After conversion handling")
            from
            until
               magic = magic_count or else nb_errors > 0
            loop
	       echo_magic_count(once "Extra falling-down")
               magic := magic_count
               falling_down
	       afd_check
            end
            echo_magic_count(once "End of AFD Check")
         end
         if not error_handler.is_empty then
            error_handler.append(
	       "Internal Warning #1 (Error Handler Not Empty): ")
            error_handler.print_as_warning
         end
         if nb_errors = 0 then
 	    safety_check
            echo.print_count(once "Loaded Classe",
			     base_class_dictionary.count)
         end
	 if nb_errors = 0 and then
	    not pretty_flag and then
	    not short_flag
	  then
	    simplify_2
	 end
      ensure
         nb_errors = 0 implies root_procedure /= Void
      end

   compile_routines is
         -- Try to give the best order to the C output.
      require
         root_procedure.set_is_root
      local
         rc, rc_string: RUN_CLASS; ct: E_TYPE; deep, i: INTEGER
         stop: BOOLEAN; bcn: STRING
      do
         echo.put_string(once "Compiling/Sorting routines for ")
         echo.put_integer(run_class_dictionary.count)
         echo.put_string(once " run classes :%N")
         cpp.swap_on_c
         from
	    update_run_class_map
            i := run_class_map.upper
         until
            i < 0
         loop
            rc := run_class_map.item(i)
            ct := rc.current_type
            if ct.is_basic_eiffel_expanded then
               rc.compile_to_c(0)
            elseif ct.is_string then
               rc_string := rc
            end
            i := i - 1
         end
         from
	    update_run_class_map
            i := run_class_map.upper
         until
            i < 0
         loop
            rc := run_class_map.item(i)
            ct := rc.current_type
            if ct.is_bit then
               rc.compile_to_c(0)
            end
            i := i - 1
         end
         from
	    update_run_class_map
            i := run_class_map.upper
         until
            i < 0
         loop
            rc := run_class_map.item(i)
            bcn := rc.base_class_name.to_string
            if as_native_array = bcn then
               rc.compile_to_c(0)
            end
            i := i - 1
         end
         if rc_string /= Void then
            rc_string.compile_to_c(0)
         end
         from
	    update_run_class_map
            i := run_class_map.upper
         until
            i < 0
         loop
            rc := run_class_map.item(i)
            ct := rc.current_type
            bcn := ct.base_class_name.to_string
            if as_array = bcn or else as_fixed_array = bcn then
               rc.compile_to_c(0)
            end
            i := i - 1
         end
         from
	    update_run_class_map
            i := run_class_map.upper
         until
            i < 0
         loop
            rc := run_class_map.item(i)
            ct := rc.current_type
            if ct.is_generic then
               rc.compile_to_c(0)
            end
            i := i - 1
         end
         from -- General sorting:
            deep := 6
         until
            stop
         loop
            from
               stop := True
	       update_run_class_map
	       i := run_class_map.upper
            until
               i < 0
            loop
               rc := run_class_map.item(i)
               if not rc.compile_to_c_done then
                  stop := False
                  rc.compile_to_c(deep)
               end
               i := i - 1
            end
            deep := deep - 1
         end
      end

   prepare_introspection is
         -- Creates the introspection features
      require
         ace.no_check
      local
         i: INTEGER
      do
         cpp.swap_on_c
         from
            i := run_class_map.upper
         until
            i < 0
         loop
            run_class_map.item(i).prepare_introspection
            i := i - 1
         end
      end

   c_code: STRING is
      once
         !!Result.make(128)
      end

   registered_for_c_define: FAST_ARRAY[RUN_FEATURE_3] is
      once
         !!Result.with_capacity(512)
      end

   compile_registered_for_c_define is
      local
         i: INTEGER
      do
         from
            i := registered_for_c_define.upper
         until
            i < 0
         loop
            registered_for_c_define.item(i).c_define_or_scoop_define
            i := i - 1
         end
      end

   safety_check is
	 -- Start final whole system analysis to decide whether this 
	 -- system is safe or not.
      require
	 status = 2
      local
	 old_magic_count, i: INTEGER; do_it: BOOLEAN; rc: RUN_CLASS
      do
	 debug
	    old_magic_count := magic_count
	 end
	 do_it := ace.safety_check
	 if do_it then
	    status := 6
	    echo_magic_count(once "Starting type safety check")
	    from
	       update_run_class_map
	       i := run_class_map.upper
	    until
	       i < run_class_map.lower
	    loop
	       rc := run_class_map.item(i)
	       if rc.at_run_time then
		  rc.safety_check
	       end
	       i := i - 1
	    end
	 else
	    status := 5
	 end
	 debug
	    check
	       old_magic_count = magic_count
	    end
	 end
      ensure
	 status.in_range(4,6)
      end

   echo_magic_count(msg: STRING) is
      require
	 msg /= Void
      do
	 echo.put_string(msg)
	 echo.put_string(once " (magic_count = ")
	 echo.put_integer(magic_count)
	 echo.put_string(once ").%N")
      end

   simplify_2 is
      require
	 not smart_eiffel.pretty_flag
	 not smart_eiffel.short_flag
	 smart_eiffel.status >= 4
      local
         rc: RUN_CLASS; i: INTEGER; prev_magic_count: INTEGER 
      do
	 echo.put_string(once "[Starting simplify_2 (")
	 echo.put_integer(magic_count)
	 echo.put_string(once "): ")
	 from
	 until
	    prev_magic_count = magic_count
	 loop
	    prev_magic_count := magic_count
	    echo.put_character('.')
	    from
	       update_run_class_map
	       i := run_class_map.upper
	    until
	       i < 0
	    loop
	       rc := run_class_map.item(i)
	       rc.simplify_2
	       i := i - 1
	    end
	 end
	 echo.put_string(once " finished simplify_2 (")
	 echo.put_integer(magic_count)
	 echo.put_string(once ")]%N")
      end

   reference_integer_set: HASHED_SET[RUN_CLASS]

   singleton_memory: SMART_EIFFEL is
      once
         Result := Current
      end

invariant

   status.in_range(0,6)

   is_real_singleton: Current = singleton_memory

end -- SMART_EIFFEL
