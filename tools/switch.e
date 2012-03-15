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
expanded class SWITCH
   --
   -- Set of tools (no attributes) to handle one switching site.
   --

inherit
   GLOBALS
   VISITABLE

feature

   c_define(up_rf: RUN_FEATURE) is
         -- Define the switching C function for `up_rf'.
      require
         cpp.on_c
      local
         boost: BOOLEAN; arguments:  FORMAL_ARG_LIST; tag: STRING
         result_type, arg_type: E_TYPE; i: INTEGER; fn: FEATURE_NAME
	 run_time_set: RUN_TIME_SET
      do
         boost := ace.boost
         arguments := up_rf.arguments
         result_type := up_rf.result_type
         c_code.clear
         if result_type = Void then
            c_code.append(fz_void)
         else
            result_type := result_type.run_type
            result_type.c_type_for_result_in(c_code)
         end
         c_code.extend(' ')
         c_code.extend('X')
         up_rf.current_type.id.append_in(c_code)
         up_rf.name.mapping_c_in(c_code)
         if boost then
            c_code.append(once "(T0*C")
         else
            c_code.append(once "(se_dump_stack*caller,se_position position,T0*C")
         end
         if arguments /= Void then
            from
               i := 1
            until
               i > arguments.count
            loop
               c_code.extend(',')
               arg_type := arguments.type(i).run_type
               arg_type.c_type_for_argument_in(c_code)
               c_code.append(once " a")
               i.append_in(c_code)
               i := i + 1
            end
         end
         c_code.extend(')')
         cpp.put_c_heading(c_code)
         cpp.swap_on_c
	 if smart_eiffel.scoop and then up_rf.current_type.is_separate then
	    cpp.put_string(once "se_subsystem_t* self=se_current_subsystem_thread();%N")
	 end
         if result_type /= Void then
            c_code.clear
            result_type.c_type_for_result_in(c_code)
            c_code.extend(' ')
            c_code.extend('R')
            if not boost then
               c_code.extend('=')
               result_type.c_initialize_in(c_code)
            end
            c_code.append(fz_00)
            cpp.put_string(c_code)
         end
         if not boost then
            cpp.put_string(once "static se_frame_descriptor fd={%"<late-binding-wrapper> ")
	    fn := up_rf.name
	    tag := fn.infix_or_prefix
	    if tag /= Void then
	       cpp.put_string(tag)
	       cpp.put_character(' ')
	    end
	    cpp.put_string(fn.to_string)
	    cpp.put_character('%"')
            cpp.put_string(once "[
	       ,0,0,"",1};
               se_dump_stack ds;
               ds.fd=&fd;ds.p=0;
               ds.caller=caller;
               ds.exception_origin=NULL;
               ds.locals=NULL;

	                         ]")
	    end
         cpp.put_string(once "{Tid id=")
         run_time_set := up_rf.run_class.run_time_set
         if boost then
            cpp.put_string(once "((T0*)C)->id;%N")
         else
            cpp.put_string(once "vc(C,position)->id;%N")
         end
         if not boost then
	    up_rf.c_set_dump_stack_top(once "&ds",fz_link)
         end
         if ace.all_check then
            c_switch(up_rf,run_time_set)
         else
            c_dicho(up_rf,run_time_set,1,run_time_set.count)
         end
         cpp.put_string(fz_12)
         if not boost then
	    up_rf.c_set_dump_stack_top(fz_caller,fz_unlink)
         end
         if result_type /= Void then
            cpp.put_string(fz_15)
         else
            cpp.put_string(fz_12)
         end
      ensure
         cpp.on_c
      end

feature {C_PRETTY_PRINTER}

   put_arguments(up_rf: RUN_FEATURE; fal: FORMAL_ARG_LIST) is
         -- Produce C code for arguments of `fal' used inside the switching
         -- C function.
      require
         cpp.on_c
         fal.count = up_rf.arguments.count
      local
         i, up: INTEGER
      do
         from
            i := 1
            up := fal.count
         until
            i > up
         loop
            if i > 1 then
               cpp.put_character(',')
            end
            put_ith_argument(up_rf,fal,i)
            i := i + 1
         end
      ensure
         cpp.on_c
      end

   put_ith_argument(up_rf: RUN_FEATURE; fal: FORMAL_ARG_LIST; i: INTEGER) is
         -- Produce C code for argument at index `i' of `fal' used
         -- inside the switching C function.
      require
         cpp.on_c
         fal.count = up_rf.arguments.count
         1 <= i
         i <= fal.count
      local
         eal: like fal
         at, ft: E_TYPE
	 conversion: BOOLEAN
      do
         eal := up_rf.arguments
         at := eal.type(i).run_type
         ft := fal.type(i).run_type
         if ft.is_separate then
            conversion := not at.is_separate
	 elseif at.is_reference then
	    conversion := ft.is_expanded
	 else
	    conversion := ft.is_reference
	 end
	 if conversion then
	    assignment_handler.c_conversion_call(at,ft)
	 end
	 cpp.put_character('a')
	 cpp.put_integer(i)
	 if conversion then
	    cpp.put_character(')')
	 end
      ensure
         cpp.on_c
      end

feature {C_PRETTY_PRINTER,SWITCH,E_AGENT}

   name(up_rf: RUN_FEATURE): STRING is
      do
         c_code.clear
         c_code.extend('X')
         up_rf.run_class.id.append_in(c_code)
         c_code.append(up_rf.name.to_key)
         Result := c_code
      end

feature

   jvm_descriptor(up_rf: RUN_FEATURE): STRING is
      local
         arguments:  FORMAL_ARG_LIST
         rt: E_TYPE
      do
         arguments := up_rf.arguments
         tmp_jvmd.clear
         tmp_jvmd.extend('(')
         tmp_jvmd.append(jvm_root_descriptor)
         if arguments /= Void then
            arguments.jvm_descriptor_in(tmp_jvmd)
         end
         rt := up_rf.result_type
         if rt = Void then
            tmp_jvmd.append(fz_19)
         else
            rt := rt.run_type
            tmp_jvmd.extend(')')
            if rt.is_reference then
               tmp_jvmd.append(jvm_root_descriptor)
            else
               rt.jvm_descriptor_in(tmp_jvmd)
            end
         end
         Result := tmp_jvmd
      end

feature

   idx_methodref(up_rf: RUN_FEATURE): INTEGER is
      require
         up_rf /= Void
      do
         Result := constant_pool.idx_methodref3(jvm_root_class,
                                                name(up_rf),
                                                jvm_descriptor(up_rf))
      end

feature {JVM}

   jvm_mapping(cpc: CALL_PROC_CALL) is
      require
         cpc /= Void
      local
         idx, stack_level: INTEGER
         up_rf: RUN_FEATURE
         target: EXPRESSION
         eal: EFFECTIVE_ARG_LIST
         fal: FORMAL_ARG_LIST
         switch: SWITCH
      do
         target := cpc.target
         up_rf := cpc.run_feature
         eal := cpc.arguments
         target.compile_to_jvm
         stack_level := 1
         if eal /= Void then
            fal := up_rf.arguments
            stack_level := stack_level + eal.compile_to_jvm(fal)
         end
         if up_rf.result_type /= Void then
            stack_level := stack_level - up_rf.result_type.jvm_stack_space
         end
         idx := switch.idx_methodref(up_rf)
         code_attribute.opcode_invokestatic(idx,-stack_level)
      end

feature {SWITCH_VISITOR}

   accept(visitor: SWITCH_VISITOR) is
      do
         visitor.visit_switch(Current)
      end

feature {SWITCH_COLLECTION}

   jvm_define(up_rf: RUN_FEATURE) is
      local
         rt: E_TYPE; run_time_set: RUN_TIME_SET
      do
         -- Define the Java switching static method for `up_rf'.
         method_info.start(9,name(up_rf),jvm_descriptor(up_rf))
         rt := up_rf.result_type
         if rt /= Void then
            rt := rt.run_type
         end
	 run_time_set := up_rf.run_class.run_time_set
         jvm_switch(up_rf,run_time_set,rt)
         method_info.finish
      end

feature {NONE}

   c_code: STRING is
      once
         !!Result.make(256)
      end

   jvm_switch(up_rf: RUN_FEATURE; run_time_set: RUN_TIME_SET; rt: E_TYPE) is
         -- Produce Java sequential switch code.
      require
         rt /= Void implies rt.run_type = rt
      local
         space, point, i: INTEGER
         dyn_rc: RUN_CLASS
         dyn_rf: RUN_FEATURE
         boost: BOOLEAN
         ca: like code_attribute
         static_na, dynamic_na: TYPE_NATIVE_ARRAY
      do
         ca := code_attribute
         from
            boost := ace.boost
            i := run_time_set.count
         until
            i = 0
         loop
            dyn_rc := run_time_set.item(i)
            dyn_rf := dyn_rc.dynamic(up_rf)
            if i = 1 and then boost then
            else
               ca.opcode_aload_0
               dyn_rf.run_class.opcode_instanceof
               point := ca.opcode_ifeq
            end
            jvm.push_switch(dyn_rf,up_rf)
            dyn_rf.mapping_jvm
            jvm.pop
            if rt = Void then
               ca.opcode_return
            elseif rt.is_native_array then
               static_na ?= rt.run_type
               dynamic_na ?= dyn_rf.result_type.run_type
               if static_na.run_time_mark = dynamic_na.run_time_mark then
                  static_na.jvm_return_code
               elseif static_na.of_references and then dynamic_na.of_references then
                  static_na.jvm_return_code
               else
                  if ace.no_check then
                     ca.runtime_error(up_rf.start_position,up_rf.current_type,
                     once "System-level Validity error detected inside virtual %
                     %switching code.%N%
                     %Bad NATIVE_ARRAY type return type.")
                  end
                  ca.opcode_pop
                  space := rt.jvm_push_default
                  rt.jvm_return_code
               end
            else
               space := dyn_rf.result_type.jvm_convert_to(rt)
               rt.jvm_return_code
            end
            if i = 1 and then boost then
            else
               ca.resolve_u2_branch(point)
            end
            i := i - 1
         end
         if not boost then
            ca.opcode_aload_0
            ca.runtime_error_bad_target(up_rf.start_position,up_rf.current_type,
               once "System-level Validity error detected inside virtual %
               %switching code.%N%
               %Bad target type for dynamic dispatch.")
            if rt = Void then
               ca.opcode_return
            else
               space := rt.jvm_push_default
               rt.jvm_return_code
            end
         end
      end

   tmp_jvmd: STRING is
      once
         !!Result.make(32)
      end

   c_dicho(up_rf: RUN_FEATURE; run_time_set: RUN_TIME_SET; bi, bs: INTEGER) is
         -- Produce dichotomic inspection code for Current id.
      require
         bi <= bs
      local
         m: INTEGER; dyn_rc: RUN_CLASS; dyn_rf: RUN_FEATURE
      do
         if bi = bs then
            dyn_rc := run_time_set.item(bi)
            dyn_rf := dyn_rc.dynamic(up_rf)
            cpp.inside_switch_call(dyn_rf,up_rf)
         else
            m := (bi + bs) // 2
            dyn_rc := run_time_set.item(m)
            cpp.put_string(once "if(id<=")
            cpp.put_integer(dyn_rc.id)
            cpp.put_string(fz_62)
            c_dicho(up_rf,run_time_set,bi,m)
            cpp.put_string(once "}%Nelse{%N")
            c_dicho(up_rf,run_time_set,m + 1,bs)
            cpp.put_character('}')
         end
      end

   c_switch(up_rf: RUN_FEATURE; run_time_set: RUN_TIME_SET) is
         -- Produce C switch inspection code for Current id.
      require
	 run_time_set.count > 1
	 run_time_set = up_rf.run_class.run_time_set
      local
         i: INTEGER; dyn_rc: RUN_CLASS; dyn_rf: RUN_FEATURE
      do
         cpp.put_string(once "switch(id){%N")
         from
            i := 1
         until
            i > run_time_set.count
         loop
            dyn_rc := run_time_set.item(i)
            dyn_rf := dyn_rc.dynamic(up_rf)
            cpp.put_string(once "case ")
            cpp.put_integer(dyn_rc.id)
            cpp.put_character(':')
            cpp.inside_switch_call(dyn_rf,up_rf)
            cpp.put_string(once "%Nbreak;%N")
            i := i + 1
         end
         if ace.no_check then
            cpp.put_string(once "default: error2(C,position);%N")
         end
         cpp.put_string(fz_12)
      end

end
