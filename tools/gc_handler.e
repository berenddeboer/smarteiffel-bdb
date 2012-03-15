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
class GC_HANDLER
   --
   -- GARBAGE_COLLECTOR_HANDLER
   --

inherit
   GLOBALS
   VISITABLE

creation make

feature {GC_HANDLER_VISITOR}

   accept(visitor: GC_HANDLER_VISITOR) is
      do
         visitor.visit_gc_handler(Current)
      end

feature

   is_off: BOOLEAN
         -- True when the Garbage Collector is not produced.

   info_flag: BOOLEAN
         -- True when Garbage Collector Information need to be printed.

   declare_allocate_n(run_class: RUN_CLASS) is
         -- Declare variable `n' and then allocate `n' with an object of the 
         -- given `run_class'. The appropriate allocation code is 
         -- automatically selected (i.e. a plain C malloc when the GC 
         -- `is_off' or the appropriate newXXX C function call when the GC 
         -- is generated.
	 -- Note: this is only a basic allocation of an empty cleared object 
	 -- of the `run_class' (i.e. no initialisation procedure call).
      require
         run_class.at_run_time
         run_class.current_type.is_reference
         cpp.on_c
      local
	 my_buffer: STRING
      do
         body.clear_count
         body.extend('T')
         run_class.id.append_in(body)
         body.extend('*')
	 allocation_in_(once "n",body,run_class,Void)
	 if run_class.current_type.is_separate then
	    my_buffer := once "                "
	    my_buffer.clear_count
	    my_buffer.append(once "(n->ref)")
	    allocation_in_(my_buffer, body,
		 run_class.current_type.local_from_separate.run_class,
                 once "se_current_subsystem_thread()")
	 end
         cpp.put_string(body)
      end

feature {ACE, COMPILE_TO_C, STRING_COMMAND_LINE}

   no_gc is
      do
         is_off := True
         info_flag := False
      ensure
         is_off
         not info_flag
      end

   set_info_flag is
      do
         is_off := False
         info_flag := True
      ensure
         not is_off
         info_flag
      end

feature {E_TYPE}

   memory_dispose(code: STRING; o: STRING; run_class: RUN_CLASS) is
         -- Append in `code' the extra C code for the MEMORY.dispose
	 -- call if any.
      require
         not run_class.current_type.is_expanded
         not run_class.current_type.is_native_array
      local
         rf3: RUN_FEATURE_3; no_check: BOOLEAN
      do
         rf3 := run_class.get_memory_dispose
         if rf3 /= Void then
            code.append(once "if((")
            code.append(o)
            code.append(once "->header.flag)==FSOH_UNMARKED){%N")
            no_check := ace.no_check
            if no_check then
               code.append(
               once "[
                se_frame_descriptor gcd={"Garbage Collector at work.\n"
                "dispose called (during sweep phase)",0,0,"",1};
                se_dump_stack ds = {NULL,NULL,0,NULL,NULL};
                ds.fd=&gcd;
                ds.caller=se_dst;
                ds.exception_origin=NULL;
                ds.locals=NULL;

                     ]")
	       rf3.c_set_dump_stack_top_in(code, once "&ds", fz_link)
            end
            code.extend('r')
            run_class.id.append_in(code)
            rf3.name.mapping_c_in(code)
            code.extend('(')
            if no_check then
               code.append(once "&ds,")
            end
            if no_check or else rf3.use_current then
               code.extend('(')
               run_class.current_type.c_type_for_target_in(code)
               code.extend(')')
               code.append(o)
            end
            code.append(fz_14)
            if no_check then
	       rf3.c_set_dump_stack_top_in(code, once "ds.caller", fz_unlink)
            end
            code.extend('}')
         end
      end

feature {C_PRETTY_PRINTER}

   customize_c_runtime is
      do
	 if not is_off then
	    cpp.macro_def(once "FSOC_SIZE",fsoc_size)
	    cpp.macro_def(once "RSOC_SIZE",rsoc_size)
	    cpp.sys_runtime_h_and_c(fz_gc_lib)
	 end
      end

   initialize_runtime is
      do
         if not is_off then
            cpp.put_string(
               once "gcmt=((mch**)se_malloc((gcmt_max+1)*sizeof(void*)));%N%
               %if (!stack_bottom) stack_bottom=((void**)(&argc));%N")
         end
      end

   gc_info_before_exit is
      require
         cpp.on_c
      do
         if is_off then
         elseif info_flag then
            cpp.put_string(
            once "fprintf(SE_GCINFO,%"==== Last GC before exit ====\n%");%N%
	    %gc_start();%N")
         end
         if not is_off and then dispose_flag then
            cpp.put_string(once "gc_dispose_before_exit();%N")
         end
      end

feature {SMART_EIFFEL}

   define1 is
      require
         not is_off
      do
         if smart_eiffel.scoop then
            fatal_error(
	       "The Garbage Collector cannot currently be used with SCOOP.")
         end

         echo.put_string(once "Adding Garbage Collector.%N")
         --
         compute_ceils
         cpp.swap_on_h
      end

   define2 is
      require
         not is_off
      local
         i: INTEGER; rc: RUN_CLASS; run_class_map: FAST_ARRAY[RUN_CLASS]
         root_type: E_TYPE
      do
         run_class_map := smart_eiffel.get_run_class_map
         root_type := smart_eiffel.root_procedure.current_type
         manifest_string_pool.define_manifest_string_mark
         body.clear_count
         once_routine_pool.gc_mark_in(body)
         cpp.put_c_function(once "void once_function_mark(void)",body)
         define_gc_start(root_type,run_class_map)
	 echo.put_string(once "GC support (gc_define1 step).%N")
         cpp.swap_on_h
         from
            i := run_class_map.upper
         until
            i < 0
         loop
            rc := run_class_map.item(i)
            rc.gc_define1
            i := i - 1
         end
	 echo.put_string(once "GC support (gc_define2 step).%N")
         cpp.swap_on_c
         from
            i := run_class_map.upper
         until
            i < 0
         loop
            rc := run_class_map.item(i)
            rc.gc_define2
            i := i - 1
         end
         from
            i := switch_list.upper
         until
            i < 0
         loop
            switch_for(switch_list.item(i))
            i := i - 1
         end
         if info_flag then
            define_gc_info(run_class_map)
         end
      ensure
         smart_eiffel.magic_count = old smart_eiffel.magic_count
      end

feature {RUN_CLASS}

   falling_down(run_class: RUN_CLASS) is
      local
         rf3: RUN_FEATURE_3
      do
         if not is_off then
            rf3 := run_class.get_memory_dispose
            if rf3 /= Void then
               dispose_flag := True
            end
         end
      end

feature {RUN_CLASS,C_PRETTY_PRINTER,ASSIGNMENT_HANDLER,CREATE_EXPRESSION}

   allocation_of(var: STRING; rc: RUN_CLASS) is
         -- Basic allocation in the already declared C variable `var' of
         -- an object of `rc'. (This is only a basic allocation, without
         -- the creation procedure call.)
      require
         var /= Void
         rc.at_run_time
         rc.current_type.is_reference
         cpp.on_c
      do
	 body.clear_count
	 allocation_in_(var,body,rc,Void)
         cpp.put_string(body)
      end

   allocation_of_ref(var: STRING; rc: RUN_CLASS; source_type: E_TYPE) is
         -- Basic allocation in the already declared C variable `var' of
         -- an object of `rc'. (This is only a basic allocation, without
         -- the creation procedure call.)
         -- There is no creation of a separate processor.
      require
         var /= Void
         rc.at_run_time
         cpp.on_c
      do
	 body.clear
	 allocation_in_(var,body,rc, once "se_current_subsystem_thread()")
         check
	    rc.current_type.is_separate
	 end
	 body.append(once "destination->ref=(")
	 source_type.c_type_for_target_in(body)
	 body.append(once ")source;%N")
         cpp.put_string(body)
      end

feature {RUN_CLASS, MANIFEST_STRING_POOL}

   allocation_in(var, buffer: STRING; rc: RUN_CLASS) is
         -- Same as `allocation_of' but in the provided C code `buffer'.
      require
         var /= Void
         rc.at_run_time
         rc.current_type.is_reference
      do
         allocation_in_(var, buffer, rc, Void)
      end

feature {SEPARATE_TOOLS}

   new_separate(rc: RUN_CLASS; subsystem: STRING) is
      do
	 body.clear_count
	 allocation_in_(once "n", body, rc, subsystem)
	 cpp.put_string(body)
      end

feature {NONE}

   allocation_in_(var, buffer: STRING; rc: RUN_CLASS; subsystem: STRING) is
	 -- `subsystem' may be Void (if we must start a new separate processor)
	 -- otherwise, the given `subsystem' is assigned to the object.
      require
         var /= Void
         rc.at_run_time
         rc.current_type.is_reference
      local
         ct: E_TYPE; id: INTEGER
      do
         ct := rc.current_type
         id := rc.id
         buffer.append(var)
         buffer.extend('=')
         if is_off then
	    buffer.append(fz_b7)
	    id.append_in(buffer)
            if ct.need_c_struct then
               buffer.append(once "*)se_malloc(sizeof(*")
               buffer.append(var)
               buffer.append(once "))/*")
               rc.c_sizeof.append_in(buffer)
	       buffer.append(once "*/);%N*")
               buffer.append(var)
               buffer.append(once "=M")
               id.append_in(buffer)
            else
               -- Object has no attributes :
               buffer.append(once "*)se_malloc(1))")
            end
         else
            buffer.append(fz_new)
            id.append_in(buffer)
            buffer.append(fz_c_no_args_function)
         end
	 buffer.extend(';')
	 buffer.extend('%N')

         if rc.current_type.is_separate then
            if subsystem = Void then
               -- Create a new subsystem (and start its processor):
               buffer.append(var)
               buffer.append(
                  once "->subsystem=se_new_subsystem(SE_SCOOP_THREAD_TYPE,%"")
               buffer.append(rc.run_time_mark)
               buffer.append(once "%");%N")
            else
               -- Attach the current subsystem reference:
               buffer.append(var)
               buffer.append(once "->subsystem=")
	       buffer.append(subsystem)
	       buffer.append(once ";%N")
            end
         end
      end

feature {MANIFEST_STRING_POOL}

   new_manifest_string_in(c_code: STRING; string_at_run_time: BOOLEAN) is
	 -- Code to create a new Manifest STRING in the "s" local C variable.
      do
         if is_off or else not string_at_run_time then
            c_code.append(once "s=((T7*)se_malloc(sizeof(T7)));%N")
	    if string_at_run_time and then type_string.run_class.is_tagged then
	       c_code.append(once "s->id=7;%N")
	    end
         else
            c_code.append(once "s=new7();%N")
         end
      end

   new_native9_in(c_code: STRING; string_at_run_time: BOOLEAN) is
      do
         if is_off or else not string_at_run_time then
            c_code.append(once "se_malloc")
         else
            c_code.append(fz_new)
            c_code.extend('9')
         end
      end

feature

   mark_for(c_code: STRING; entity: STRING; rc: RUN_CLASS) is
         -- Add `c_code' to mark `entity' of class `rc'.
      require
         not is_off
         rc.current_type.need_gc_mark_function
      local
         ct: E_TYPE; run_time_set: RUN_TIME_SET
      do
         run_time_set := rc.run_time_set
         if run_time_set.count >= 1 then
            ct := rc.current_type
            if ct.is_reference or else ct.is_native_array then
               c_code.append(once "if(NULL!=")
               c_code.append(entity)
               c_code.extend(')')
            end
            if run_time_set.count > 1 and not ct.is_expanded then
	       --                      **********************
	       -- Note: I don't understand why this fix (provided by Alain
	       -- Le_Guennec) can be useful because, as far as I know, an
	       -- expanded class must not have more than one runnable.
	       -- *** Fri Aug 15 2000, DC
               cpp.incr_switched_call_count
               if not switch_list.fast_has(rc) then
                  switch_list.add_last(rc)
               end
               c_code.extend('X')
               ct.gc_mark_in(c_code)
            else
               cpp.incr_direct_call_count
	       ct := run_time_set.first.current_type
	       ct.gc_mark_in(c_code)
            end
            c_code.extend('(')
	    if ct.is_reference then
	       c_code.extend('(')
	       if run_time_set.count > 1 then
		  c_code.append(once "T0*")
	       else
		  ct.c_type_for_target_in(c_code)
	       end
	       c_code.extend(')')
	    elseif ct.is_user_expanded then
	       c_code.extend('&')
            end
            c_code.extend('(')
            c_code.append(entity)
            c_code.append(fz_16)
         end
      end

feature {NONE}

   make is do end

   min_kb_count: INTEGER is 256
         -- Minimum kb to allocate for fsoc and for rsoc

   compute_ceils is
      local
         fsoc_count_ceil, rsoc_count_ceil, i: INTEGER
         run_class_map: FAST_ARRAY[RUN_CLASS]
         rc: RUN_CLASS
         kb_count: INTEGER
      do
         run_class_map := smart_eiffel.get_run_class_map
         from
            i := run_class_map.upper
         until
            i < 0
         loop
            rc := run_class_map.item(i)
            if rc.at_run_time then
               if rc.current_type.is_native_array then
                  rsoc_count_ceil := rsoc_count_ceil + 1
               else
                  fsoc_count_ceil := fsoc_count_ceil + 1
               end
            end
            i := i - 1
         end
         fsoc_count_ceil := 4 * fsoc_count_ceil
         kb_count := fsoc_count_ceil * (fsoc_size // 1024)
         if kb_count < min_kb_count then
            fsoc_count_ceil := min_kb_count // (fsoc_size // 1024)
         end
         rsoc_count_ceil := 3 * rsoc_count_ceil
         kb_count := rsoc_count_ceil * (rsoc_size // 1024)
         if kb_count < min_kb_count then
            rsoc_count_ceil := min_kb_count // (rsoc_size // 1024)
         end
         cpp.put_extern6(once "unsigned int fsoc_count_ceil",fsoc_count_ceil)
         cpp.put_extern6(once "unsigned int rsoc_count_ceil",rsoc_count_ceil)
      end

   switch_list: FAST_ARRAY[RUN_CLASS] is
	 -- For which there is a switching function.
      once
         create Result.with_capacity(128)
      end

   switch_for(rc: RUN_CLASS) is
      local
         ct: E_TYPE; run_time_set: RUN_TIME_SET
      do
         header.clear_count
         header.append(fz_void)
         header.extend(' ')
         header.extend('X')
         ct := rc.current_type
         ct.gc_mark_in(header)
         header.extend('(')
         header.append(fz_t0_star)
         header.extend('o')
         header.extend(')')
         body.clear_count
         run_time_set := rc.run_time_set
         body.append(once "{int i=o->id;%N")
         c_dicho(run_time_set,1,run_time_set.count)
         body.extend('}')
         cpp.put_c_function(header,body)
      end

   c_dicho(run_time_set: RUN_TIME_SET; bi, bs: INTEGER) is
         -- Produce dichotomic inspection code for Current id.
      require
         bi <= bs
      local
         m: INTEGER; rc: RUN_CLASS
      do
         if bi = bs then
            rc := run_time_set.item(bi)
            rc.current_type.gc_mark_in(body)
            body.extend('(')
            body.extend('(')
            body.extend('T')
            rc.id.append_in(body)
            body.extend('*')
            body.extend(')')
            body.extend('o')
            body.extend(')')
            body.append(fz_00)
         else
            m := (bi + bs) // 2
            rc := run_time_set.item(m)
            body.append(once "if (i <= ")
            rc.id.append_in(body)
            body.append(once ") {%N")
            c_dicho(run_time_set,bi,m)
            body.append(fz_67)
            c_dicho(run_time_set,m + 1,bs)
            body.extend('}')
         end
      end

  just_before_mark(run_class_map: FAST_ARRAY[RUN_CLASS]) is
      require
         not is_off
      local
         i: INTEGER
         rc: RUN_CLASS
      do
         from
            i := run_class_map.upper
         until
            i < 0
         loop
            rc := run_class_map.item(i)
            rc.just_before_gc_mark_in(body)
            i := i - 1
         end
      end

   define_gc_info(run_class_map: FAST_ARRAY[RUN_CLASS]) is
      require
         info_flag
      local
         i: INTEGER; rc: RUN_CLASS
      do
         header.copy(once "void  gc_info(void)")
         body.clear_count
         body.append(once "fprintf(SE_GCINFO,%"--------------------\n%");%N")
         from
            i := run_class_map.upper
         until
            i < 0
         loop
            rc := run_class_map.item(i)
            rc.gc_info_in(body)
            i := i - 1
         end
	 agent_pool.gc_info_in(body)
         body.append(
           once "fprintf(SE_GCINFO,%"C-stack=%%d %",gc_stack_size());%N%
           %fprintf(SE_GCINFO,%"main-table=%%d/%%d %",gcmt_used,gcmt_max);%N%
           %fprintf(SE_GCINFO,%"fsoc:%%d(%",fsoc_count);%N%
           %fprintf(SE_GCINFO,%"free=%%d %",fsocfl_count());%N%
	   %fprintf(SE_GCINFO,%"ceil=%%d) %",fsoc_count_ceil);%N%
           %fprintf(SE_GCINFO,%"rsoc:%%d(%",rsoc_count);%N%
           %fprintf(SE_GCINFO,%"ceil=%%d)\n%",rsoc_count_ceil);%N%
           %fprintf(SE_GCINFO,%"GC called %%d time(s)\n%",collector_counter);%N%
           %fprintf(SE_GCINFO,%"--------------------\n%");%N")
         cpp.put_c_function(header,body)
      end

   define_gc_start(root_type: E_TYPE; run_class_map: FAST_ARRAY[RUN_CLASS]) is
      do
         body.clear_count
         body.append(once "if(gc_is_off)return;%N%
                   %if(garbage_delayed())return;%N")
         body.append(
            once "gcmt_tail_addr=(((char*)(gcmt[gcmt_used-1]))+%
            %(gcmt[gcmt_used-1])->size);%N%
            %((gc")
         root_type.id.append_in(body)
         body.append(once "*)eiffel_root_object)->header.flag=FSOH_UNMARKED;%N")
         just_before_mark(run_class_map)
         body.append(fz_gc_mark)
         root_type.id.append_in(body)
         body.append(once "(eiffel_root_object);%N%
                     %manifest_string_mark1();%N%
                     %once_function_mark();%N")
         if smart_eiffel.generator_used then
            body.append(once "{int i=SE_MAXID-1;%N%
                        %while(i>=0){%N%
                        %if(g[i]!=NULL)gc_mark7(g[i]);%N%
                        %i--;}%N}%N")
         end
         if smart_eiffel.generating_type_used then
            body.append(once "{int i=SE_MAXID-1;%N%
                        %while(i>=0){%N%
                        %if(t[i]!=NULL)gc_mark7(t[i]);%N%
                        %i--;}%N}%N")
         end
         body.append(once "mark_stack_and_registers();%N%
                     %gc_sweep();%N%
                     %collector_counter++;%N")
         if info_flag then
            body.append(once "gc_info();")
         end
         cpp.put_c_function(once "void gc_start(void)",body)
      end

   header: STRING is
      once
         !!Result.make(64)
      end

   body: STRING is
      once
         !!Result.make(512)
      end

   fsoc_size: INTEGER is 8192; -- Fixed Size Objects Chunks Size.

   rsoc_size: INTEGER is 32768; -- ReSizable Objects Chunks Size.

   dispose_flag: BOOLEAN

invariant

   info_flag implies not is_off

end -- GC_HANDLER

