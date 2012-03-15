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
class E_AGENT
   --
   -- An agent definition as for example: agent foo("bar",?)
   --

inherit
   EXPRESSION;
   HASHABLE
      redefine is_equal end

creation make

feature

   start_position: POSITION
         -- Of the "agent" keyword.

   is_current: BOOLEAN is False

   extra_bracket_flag: BOOLEAN is False
   
   isa_dca_inline_argument: INTEGER is 0

   dca_inline_argument(formal_arg_type: E_TYPE) is do end

   start_lookup_class: BASE_CLASS is do end

   once_pre_computable: BOOLEAN is False

   creation_mold_id: INTEGER
	 -- Identify the creation form (which feature is called and 
	 -- where are placed base/open arguments).

   is_equal(other: like Current): BOOLEAN is
	 -- (Because we want to store `Current' in DICTIONARY and/or SET)
	 -- True only if both have to share the same `creation_mold_id'.
      local
	 i: INTEGER; e1, e2: EXPRESSION; oo1, oo2: OPEN_OPERAND
      do
	 check
	    run_feature /= Void and other.run_feature /= Void
	 end
	 Result := run_feature = other.run_feature
	 if Result then
	    if base /= Void then
	       if other.base /= Void then
		  Result := mold_equal(base, other.base)
	       else
		  Result := false
	       end
	    elseif other.base /= Void then
	       Result := false
	    end
	 end
	 if Result and then arguments /= Void then
	    from
	       Result := True
	       i := arguments.count
	    until
	       not Result or else i = 0
	    loop
	       e1 := arguments.expression(i); oo1 ?= e1
	       e2 := other.arguments.expression(i) ; oo2 ?= e2
	       -- Check first that both are open or both are closed:
	       if oo1 /= Void then
		  if oo2 = Void then
		     Result := False
		  else
		     Result := mold_equal(oo1.result_type, oo2.result_type)
		  end
	       elseif oo2 /= Void then
		  Result := False
	       else
		  Result := mold_equal(e1.result_type, e2.result_type)
	       end
	       i := i - 1
	    end
	 end
      end
   
   hash_code: INTEGER is
	 -- (Because we want to store `Current' in DICTIONARY and/or SET)
      do
	 Result := run_feature.name.hash_code
      end
   
   to_integer_or_error: INTEGER is
      do
	 to_integer_error
      end

   to_runnable(ct: E_TYPE): like Current is
      local
         rc: RUN_CLASS; rt, rfrt: E_TYPE; bc: BASE_CLASS
	 types: ARRAY[E_TYPE]; i: INTEGER; fal: FORMAL_ARG_LIST
      do
	 if current_type = Void then
	    current_type := ct
	    feature_name := call.feature_name
	    if base /= Void then
	       rt := base.to_runnable(ct)
	       if rt = Void then
		  error_handler.add_position(base.start_position)
		  error_handler.append("Bad BASE type for agent.")
		  error_handler.print_as_fatal_error
	       end
	       create {FAKE_TARGET} target.make(rt)
	    else
	       check target = Void end
	       target := call.target.to_runnable(ct)
	       if target = Void then
		  error_handler.add_position(call.target.start_position)
		  error_handler.append("Bad target for agent definition.")
		  error_handler.print_as_fatal_error
	       end
	    end
	    check target /= Void end
	    rt := target.result_type
	    rc := rt.run_class
	    if rc /= Void then
	       rt := rc.current_type
	       bc := rc.base_class
	       run_feature := bc.run_feature_for(rc,target,
						 call.feature_name,ct)
	    end
	    arguments := call.arguments
	    fal := run_feature.arguments
	    if fal /= Void then
	       if arguments = Void then
		  -- Creating the ommited open argument list:
		  arguments := fal.open_args(feature_name.start_position)
	       end
	    end
	    if arguments /= Void then
	       arguments := arguments.open_operands_notify(Current,
							   run_feature)
	       arguments := arguments.to_runnable(ct)
	       if arguments = Void then
		  error_handler.add_position(call.arguments.start_position)
		  error_handler.append("Bad arguments for agent definition.")
		  error_handler.print_as_fatal_error
	       end
	    end
	    --
	    smart_eiffel.argument_passing_check(call.start_position,
						arguments,run_feature)
	    -- Computing `result_type':
	    if base /= Void then
	       create types.with_capacity(4,1)
	       types.add_last(base.run_type)
	    end
	    if open_args /= Void then
	       if types = Void then
		  create types.with_capacity(4,1)
	       end
	       from
		  i := open_args.lower
	       until
		  i > open_args.upper
	       loop
		  types.add_last(open_args.item(i).result_type.run_type)
		  i := i + 1
	       end
	    end
	    create open_tuple.make(start_position, types)
	    check open_tuple.written_runnable_flag end
	    rfrt := run_feature.result_type
	    if rfrt = Void then
	       create {TYPE_PROCEDURE}
	              result_type.procedure(start_position, rt, open_tuple)
	    else
	       rfrt := rfrt.run_type
	       create {TYPE_FUNCTION}
                      result_type.make(start_position, rt, open_tuple, rfrt)
	    end
	    check result_type.written_runnable_flag end
	    result_type.load_builtin_features
	    creation_mold_id := agent_pool.register(Current)
	    -- Computing `definition_function_name':
	    create definition_function_name.make(16)
	    definition_function_name.append(as_agent)
	    creation_mold_id.append_in(definition_function_name)
	    -- Computing `execution_function_name':
	    create execution_function_name.make(16)
	    execution_function_name.extend('_')
	    execution_function_name.append(definition_function_name)
	    -- Finally:
	    result_type.run_class.set_at_run_time
	    Result := Current
	 else
	    create Result.make(start_position,base,call)
	    Result := Result.to_runnable(ct)
	 end
      end

   simplify_1_, simplify_2: like Current is
      do
	 Result := Current
      end
   
   result_type: TYPE_OF_AGENT

   is_void: BOOLEAN is False

   is_writable: BOOLEAN is False

   side_effect_free: BOOLEAN is False

   is_manifest_string: BOOLEAN is False

   is_static: BOOLEAN is False

   is_result: BOOLEAN is False

   stupid_switch(run_time_set: RUN_TIME_SET): BOOLEAN is do end

   afd_check is
      local
         rc: RUN_CLASS; run_time_set: RUN_TIME_SET
      do
	 rc := target.result_type.run_class
	 run_time_set := rc.run_time_set
	 if run_time_set.count = 0 then
	 elseif run_time_set.count > 1 then
	    switch_collection.update(target,run_feature)
	 end
         target.afd_check
         if arguments /= Void then
            arguments.afd_check
         end
      end

   safety_check is
      do
         target.safety_check
         if arguments /= Void then
            arguments.safety_check
         end
      end

   collect_c_tmp is
      do
	 run_feature.collect_c_tmp
         target.collect_c_tmp
         if arguments /= Void then
            arguments.collect_c_tmp
         end
      end

   compile_to_c is
      local
	 i: INTEGER; boost, need_comma: BOOLEAN; e: EXPRESSION
      do
	 cpp.put_string(definition_function_name)
	 cpp.put_character('(')
	 boost := ace.boost
	 if not boost then
	    cpp.put_string(once "&ds")
	    need_comma := True
	 end
	 if base = Void then
	    if need_comma then cpp.put_character(',') end
	    target.mapping_c_arg(target.result_type)
	    need_comma := True
	 end
	 if arguments /= Void then
	    from i := 1 until i > arguments.count
	    loop
	       if is_closed_argument(i) then
		  if need_comma then
		     cpp.put_character(',')
		  end
		  e := arguments.expression(i)
		  e.mapping_c_arg(e.result_type)
		  need_comma := True
	       end
	       i := i + 1
	    end
	 end
	 cpp.put_character(')')
      end

   mapping_c_target(formal_type: E_TYPE) is
      do
	 compile_to_c
      end

   mapping_c_arg(formal_arg_type: E_TYPE) is
      do
	 compile_to_c
      end

   use_current: BOOLEAN is
      do
	 if arguments /= Void then
	    Result := arguments.use_current
	 end
	 if not Result then
	    Result := target.use_current
	 end
      end

   c_frame_descriptor(format, locals: STRING) is
      do
	 check False end
      end

   assertion_check(tag: CHARACTER) is
      do
	 not_yet_implemented
      end

   bracketed_pretty_print, pretty_print is
      do
	 pretty_printer.keyword(once "agent")
	 if base /= void then
	    pretty_printer.put_character('{')
	    base.pretty_print
	    pretty_printer.put_character('}')
	    pretty_printer.put_character('.')
	 end
	 call.pretty_print
      end

   print_as_target is
      do
         pretty_printer.put_character('(')
         pretty_print
         pretty_printer.put_character(')')
         pretty_printer.put_character('.')
      end

   short, short_target is
      do
	 not_yet_implemented
      end

   precedence: INTEGER is
      do
         Result := atomic_precedence
      end

   jvm_assign_creation, jvm_assign is
      do
	 check False end
      end

   compile_to_jvm_into(dest: E_TYPE): INTEGER is
      do
	 Result := 1
         compile_to_jvm
      end

   compile_target_to_jvm, compile_to_jvm is
      local
         is_switched: BOOLEAN
      do
         if base = void then
	    if target.result_type.run_class.run_time_set.count > 1 then
	       is_switched := True
	    end
	 elseif base.run_class.run_time_set.count > 1 then
	    is_switched := True
         end
         if not is_switched then
            compile_to_jvm_no_switch
         else
            compile_to_jvm_switch
         end
      end

   compile_to_jvm_no_switch is 
      local
         idx: INTEGER
         space: INTEGER
         fcn: STRING
         i_argument: INTEGER
         i_open_argument: INTEGER
         open_argument_count: INTEGER
         switch: SWITCH
         arguments_count: INTEGER
         sfn: FEATURE_NAME
         rfc: RUN_FEATURE
         rfi: RUN_FEATURE
         sp: POSITION
      do

         create fcn.make(64)
         
         if arguments /= void then
            arguments_count := arguments.count
         else
            arguments_count := 0
         end
         
         sp.set_in(result_type.run_class.base_class)
         create sfn.simple_feature_name(as_call,sp)
         rfc := result_type.run_class.at(sfn)
         create sfn.simple_feature_name(as_item,sp)
         rfi := result_type.run_class.at(sfn)

         if rfc /= void or rfi /= void then

            -- new agent object (FUNCTION, PROCEDURE, or PREDICATE)
            result_type.run_class.jvm_basic_new
            -- store target into agent object
            code_attribute.opcode_dup
            target.compile_to_jvm
            fcn := result_type.run_class.fully_qualified_name
            idx := constant_pool.idx_fieldref3(fcn,as_target,fz_21)
            space := result_type.jvm_stack_space
            code_attribute.opcode_putfield(idx,space + 1); -- store target
            
            -- arguments
            code_attribute.opcode_dup
            code_attribute.opcode_push_integer(arguments_count)
            idx := constant_pool.idx_class2(fz_21)
            code_attribute.opcode_anewarray(idx)
            idx := constant_pool.idx_fieldref3(fcn,as_arguments,fz_c2)
            space := result_type.jvm_stack_space
            code_attribute.opcode_putfield(idx,space + 1)
            
            fcn := result_type.run_class.fully_qualified_name
            idx := constant_pool.idx_fieldref3(fcn,as_arguments,fz_c2)
            code_attribute.opcode_dup
            space := result_type.jvm_stack_space
            code_attribute.opcode_getfield(idx,space+1); -- get arguments
   
            from
               i_argument := 1
            until
               i_argument > arguments_count
            loop
               if is_closed_argument(i_argument) then
                  
                  code_attribute.opcode_dup
                  code_attribute.opcode_push_integer(i_argument - 1)
               
                  if arguments.expression(i_argument).result_type.is_basic_eiffel_expanded then
                     push_jvm_expanded_argument_to_object_wrapper(arguments.expression(i_argument),run_feature.arguments.type(i_argument))
                  else
                     space := arguments.expression(i_argument).standard_compile_to_jvm_into(run_feature.arguments.type(i_argument))
                  end
                  
                  code_attribute.opcode_aastore
               else
                  open_argument_count := open_argument_count + 1
               end
               i_argument := i_argument + 1
            end
            
            code_attribute.opcode_pop
            
            -- method
            code_attribute.opcode_dup
            
            create fcn.make(64)
            if base = void then
               target.compile_to_jvm -- target object
               fcn.clear
               fcn.append(target.result_type.run_class.fully_qualified_name)
               idx := constant_pool.idx_methodref3(fcn,fz_c3,fz_c4); -- getClass
               code_attribute.opcode_invokevirtual(idx,-1)
            else
               fcn.clear
   
               fcn.append(base.run_class.fully_qualified_name)
               fcn.replace_all('/','.')
   
               idx := constant_pool.idx_string2(fcn)
               code_attribute.opcode_ldc(idx)
               idx := constant_pool.idx_methodref3(fz_java_lang_class,fz_d1,fz_d2); -- forName
               code_attribute.opcode_invokestatic(idx,-1)
            end      
   
            idx := constant_pool.idx_string(run_feature.name.to_string) -- the method name
            code_attribute.opcode_ldc(idx)
   
            code_attribute.opcode_push_integer(arguments_count)
            idx := constant_pool.idx_class2(fz_java_lang_class); -- array of java/lang/Class
            code_attribute.opcode_anewarray(idx)
            
            create fcn.make(64)
            from
               i_argument := 1
            until
               i_argument > arguments_count
            loop
               code_attribute.opcode_dup
               code_attribute.opcode_push_integer(i_argument - 1)
               
               if arguments.expression(i_argument).result_type.is_basic_eiffel_expanded then
                  push_jvm_expanded_argument_object_wrapper_type(run_feature.arguments.type(i_argument))
               else
                  fcn.clear
                  fcn.append(ace.executable_name)
                  fcn.extend('.')
                  fcn.append(fz_jvm_root)
                  idx := constant_pool.idx_string2(fcn)
                  code_attribute.opcode_ldc(idx)
                  idx := constant_pool.idx_methodref3(fz_java_lang_class,fz_d1,fz_d2); -- forName
                  code_attribute.opcode_invokestatic(idx,-1)
               end   
               
               code_attribute.opcode_aastore
               i_argument := i_argument + 1
            end
            
            idx := constant_pool.idx_methodref3(fz_java_lang_class,fz_c6,fz_c7); -- getMethod
            code_attribute.opcode_invokevirtual(idx,-1)
            fcn := result_type.run_class.fully_qualified_name
            idx := constant_pool.idx_fieldref3(fcn,as_method,fz_21)
            space := result_type.jvm_stack_space
            code_attribute.opcode_putfield(idx,space + 1)
   
            -- get open_argument_count
            if base /= void then
               open_argument_count := open_argument_count + 1
            end            
      
            -- open_arguments
            code_attribute.opcode_dup
            code_attribute.opcode_push_integer(open_argument_count)
            idx := constant_pool.idx_class2(fz_21)
            code_attribute.opcode_anewarray(idx)
            idx := constant_pool.idx_fieldref3(fcn,as_open_arguments,fz_c2)
            space := result_type.jvm_stack_space
            code_attribute.opcode_putfield(idx,space + 1)
   
            -- open_argument_indices
            code_attribute.opcode_dup
   
            code_attribute.opcode_push_integer(open_argument_count)
            code_attribute.opcode_newarray(10) -- array of int
            
            fcn := result_type.run_class.fully_qualified_name
            idx := constant_pool.idx_fieldref3(fcn,as_open_argument_indices,fz_d3)
            space := result_type.jvm_stack_space
            code_attribute.opcode_putfield(idx,space + 1); -- store open_argument_indices
   
            -- open_argument_indices contents
            code_attribute.opcode_dup
            fcn := result_type.run_class.fully_qualified_name
            idx := constant_pool.idx_fieldref3(fcn,as_open_argument_indices,fz_d3)
            space := result_type.jvm_stack_space
            code_attribute.opcode_getfield(idx,space + 1); -- get open_argument_indices
            
            i_open_argument := 0
            if base /= void then
               code_attribute.opcode_dup
               code_attribute.opcode_push_integer(i_open_argument)
               code_attribute.opcode_push_integer(-1)
               code_attribute.opcode_iastore
               i_open_argument := 1
            end
   
            from
               i_argument := 1
            until
               i_argument > arguments_count
            loop
               if not is_closed_argument(i_argument) then
                  code_attribute.opcode_dup
                  code_attribute.opcode_push_integer(i_open_argument)
                  code_attribute.opcode_push_integer(i_argument - 1)
                  code_attribute.opcode_iastore
                  i_open_argument := i_open_argument + 1
               end
               i_argument := i_argument + 1
            end
   
            code_attribute.opcode_pop

         else   
            code_attribute.opcode_aconst_null
         end
               
	  end

   compile_to_jvm_switch is 
      local
         idx: INTEGER
         space: INTEGER
         fcn: STRING
         i_argument: INTEGER
         i_open_argument: INTEGER
         open_argument_count: INTEGER
         switch: SWITCH
         arguments_count: INTEGER
         sfn: FEATURE_NAME
         rfc: RUN_FEATURE
         rfi: RUN_FEATURE
         sp: POSITION
      do

         create fcn.make(64)
         
         if arguments /= void then
            arguments_count := arguments.count
         else
            arguments_count := 0
         end
         

         sp.set_in(result_type.run_class.base_class)
         create sfn.simple_feature_name(as_call,sp)
         rfc := result_type.run_class.at(sfn)
         create sfn.simple_feature_name(as_item,sp)
         rfi := result_type.run_class.at(sfn)

         if rfc /= void or rfi /= void then

            -- new agent object (FUNCTION, PROCEDURE, or PREDICATE)
            result_type.run_class.jvm_basic_new
            -- store target into agent object
            code_attribute.opcode_dup
            target.compile_to_jvm
            fcn := result_type.run_class.fully_qualified_name
            idx := constant_pool.idx_fieldref3(fcn,as_target,fz_21)
            space := result_type.jvm_stack_space
            code_attribute.opcode_putfield(idx,space + 1); -- store target
            
            -- arguments
            code_attribute.opcode_dup
            code_attribute.opcode_push_integer(arguments_count + 1)
            idx := constant_pool.idx_class2(fz_21)
            code_attribute.opcode_anewarray(idx)
            idx := constant_pool.idx_fieldref3(fcn,as_arguments,fz_c2)
            space := result_type.jvm_stack_space
            code_attribute.opcode_putfield(idx,space + 1)
            
            fcn := result_type.run_class.fully_qualified_name
            idx := constant_pool.idx_fieldref3(fcn,as_arguments,fz_c2)
            code_attribute.opcode_dup
            space := result_type.jvm_stack_space
            code_attribute.opcode_getfield(idx,space+1); -- get arguments
   
            if base = void then
               code_attribute.opcode_dup
               code_attribute.opcode_push_integer(0)
               target.compile_to_jvm -- target object is argument 0 for switch call
               code_attribute.opcode_aastore
            end
   
            from
               i_argument := 1
            until
               i_argument > arguments_count
            loop
               if is_closed_argument(i_argument) then
                  
                  code_attribute.opcode_dup
                  code_attribute.opcode_push_integer(i_argument)
               
                  if arguments.expression(i_argument).result_type.is_basic_eiffel_expanded then
                     push_jvm_expanded_argument_to_object_wrapper(arguments.expression(i_argument),run_feature.arguments.type(i_argument))
                  else
                     space := arguments.expression(i_argument).standard_compile_to_jvm_into(run_feature.arguments.type(i_argument))
                  end
                  
                  code_attribute.opcode_aastore
               else
                  open_argument_count := open_argument_count + 1
               end
               i_argument := i_argument + 1
            end
            
            code_attribute.opcode_pop
            
            -- method
            code_attribute.opcode_dup
            
            create fcn.make(64)
            fcn.clear
            fcn.append(ace.executable_name)
            fcn.extend('.')
            fcn.append(fz_jvm_root)
   
            idx := constant_pool.idx_string2(fcn)
            code_attribute.opcode_ldc(idx)
            idx := constant_pool.idx_methodref3(fz_java_lang_class,fz_d1,fz_d2); -- forName
            code_attribute.opcode_invokestatic(idx,-1)
   
            idx := constant_pool.idx_string2(switch.name(run_feature)); -- the switch method name
            code_attribute.opcode_ldc(idx)
   
            code_attribute.opcode_push_integer(arguments_count + 1)
            idx := constant_pool.idx_class2(fz_java_lang_class); -- array of java/lang/Class
            code_attribute.opcode_anewarray(idx)
            
            create fcn.make(64)
   
            code_attribute.opcode_dup
            code_attribute.opcode_push_integer(0)
            fcn.clear
            fcn.append(ace.executable_name)
            fcn.extend('.')
            fcn.append(fz_jvm_root)
            idx := constant_pool.idx_string2(fcn)
            code_attribute.opcode_ldc(idx)
            idx := constant_pool.idx_methodref3(fz_java_lang_class,fz_d1,fz_d2); -- forName
            code_attribute.opcode_invokestatic(idx,-1)
            code_attribute.opcode_aastore
   
            from
               i_argument := 1
            until
               i_argument > arguments_count
            loop
               code_attribute.opcode_dup
               code_attribute.opcode_push_integer(i_argument)
               
               if arguments.expression(i_argument).result_type.is_basic_eiffel_expanded then
                  push_jvm_expanded_argument_object_wrapper_type(run_feature.arguments.type(i_argument))
               else
                  fcn.clear
                  fcn.append(ace.executable_name)
                  fcn.extend('.')
                  fcn.append(fz_jvm_root)
                  idx := constant_pool.idx_string2(fcn)
                  code_attribute.opcode_ldc(idx)
                  idx := constant_pool.idx_methodref3(fz_java_lang_class,fz_d1,fz_d2); -- forName
                  code_attribute.opcode_invokestatic(idx,-1)
               end   
               
               code_attribute.opcode_aastore
               i_argument := i_argument + 1
            end
            
            idx := constant_pool.idx_methodref3(fz_java_lang_class,fz_c6,fz_c7); -- getMethod
            code_attribute.opcode_invokevirtual(idx,-1)
            fcn := result_type.run_class.fully_qualified_name
            idx := constant_pool.idx_fieldref3(fcn,as_method,fz_21)
            space := result_type.jvm_stack_space
            code_attribute.opcode_putfield(idx,space + 1)
   
            -- open_argument_count
            if base /= void then
               open_argument_count := open_argument_count + 1
            end            
      
            -- open_arguments
            code_attribute.opcode_dup
            code_attribute.opcode_push_integer(open_argument_count)
            idx := constant_pool.idx_class2(fz_21)
            code_attribute.opcode_anewarray(idx)
            idx := constant_pool.idx_fieldref3(fcn,as_open_arguments,fz_c2)
            space := result_type.jvm_stack_space
            code_attribute.opcode_putfield(idx,space + 1)
   
            -- open_argument_indices
            code_attribute.opcode_dup
   
            code_attribute.opcode_push_integer(open_argument_count)
            code_attribute.opcode_newarray(10) -- array of int
            
            fcn := result_type.run_class.fully_qualified_name
            idx := constant_pool.idx_fieldref3(fcn,as_open_argument_indices,fz_d3)
            space := result_type.jvm_stack_space
            code_attribute.opcode_putfield(idx,space + 1); -- store open_argument_indices
   
            -- open_argument_indices contents
            code_attribute.opcode_dup
            fcn := result_type.run_class.fully_qualified_name
            idx := constant_pool.idx_fieldref3(fcn,as_open_argument_indices,fz_d3)
            space := result_type.jvm_stack_space
            code_attribute.opcode_getfield(idx,space + 1); -- get open_argument_indices
            
            i_open_argument := 0
            if base /= void then
               code_attribute.opcode_dup
               code_attribute.opcode_push_integer(i_open_argument)
               code_attribute.opcode_push_integer(0)
               code_attribute.opcode_iastore
               i_open_argument := 1
            end
   
            from
               i_argument := 1
            until
               i_argument > arguments_count
            loop
               if not is_closed_argument(i_argument) then
                  code_attribute.opcode_dup
                  code_attribute.opcode_push_integer(i_open_argument)
                  code_attribute.opcode_push_integer(i_argument)
                  code_attribute.opcode_iastore
                  i_open_argument := i_open_argument + 1
               end
               i_argument := i_argument + 1
            end
   
            code_attribute.opcode_pop

         end
                  
       end

   push_jvm_expanded_argument_to_object_wrapper(arg_expression: EXPRESSION; f_type: E_TYPE) is
      local
         idx: INTEGER
         space: INTEGER
      do
         if f_type.is_boolean then
            idx := constant_pool.idx_class2(fz_java_lang_boolean)
            code_attribute.opcode_new(idx)
            code_attribute.opcode_dup
            space := arg_expression.standard_compile_to_jvm_into(f_type)
            idx := constant_pool.idx_methodref3(fz_java_lang_boolean,fz_35,fz_cb); -- <init>
            code_attribute.opcode_invokespecial(idx,-1)
         elseif f_type.is_character then
            idx := constant_pool.idx_class2(fz_java_lang_byte)
            code_attribute.opcode_new(idx)
            code_attribute.opcode_dup
            space := arg_expression.standard_compile_to_jvm_into(f_type)
            idx := constant_pool.idx_methodref3(fz_java_lang_byte,fz_35,fz_cc1); -- <init>
            code_attribute.opcode_invokespecial(idx,-1)
         elseif f_type.is_integer then
            idx := constant_pool.idx_class2(fz_java_lang_integer)
            code_attribute.opcode_new(idx)
            code_attribute.opcode_dup
            space := arg_expression.standard_compile_to_jvm_into(f_type)
            idx := constant_pool.idx_methodref3(fz_java_lang_integer,fz_35,fz_27); -- <init>
            code_attribute.opcode_invokespecial(idx,-1)
         elseif f_type.is_real then
            idx := constant_pool.idx_class2(fz_java_lang_float)
            code_attribute.opcode_new(idx)
            code_attribute.opcode_dup
            space := arg_expression.standard_compile_to_jvm_into(f_type)
            idx := constant_pool.idx_methodref3(fz_java_lang_float,fz_35,fz_ce); -- <init>
            code_attribute.opcode_invokespecial(idx,-1)
         elseif f_type.is_double then
            idx := constant_pool.idx_class2(fz_java_lang_double)
            code_attribute.opcode_new(idx)
            code_attribute.opcode_dup
            space := arg_expression.standard_compile_to_jvm_into(f_type)
            idx := constant_pool.idx_methodref3(fz_java_lang_double,fz_35,fz_cf); -- <init>
            code_attribute.opcode_invokespecial(idx,-1)
         elseif f_type.is_pointer then
            arg_expression.compile_to_jvm
         end
      end

   push_jvm_expanded_argument_object_wrapper_type(f_type: E_TYPE) is
      local
         idx: INTEGER; fcn: STRING
      do
         if f_type.is_boolean then
            idx := constant_pool.idx_fieldref3(fz_java_lang_boolean,as_type,fz_ca)
            code_attribute.opcode_getstatic(idx,2); -- get java.lang.Boolean.TYPE
         elseif f_type.is_character then
            idx := constant_pool.idx_fieldref3(fz_java_lang_byte,as_type,fz_ca)
            code_attribute.opcode_getstatic(idx,2); -- get java.lang.Byte.TYPE
         elseif f_type.is_integer then
            idx := constant_pool.idx_fieldref3(fz_java_lang_integer,as_type,fz_ca)
            code_attribute.opcode_getstatic(idx,2); -- get java.lang.Integer.TYPE
         elseif f_type.is_real then
            idx := constant_pool.idx_fieldref3(fz_java_lang_float,as_type,fz_ca)
            code_attribute.opcode_getstatic(idx,2); -- get java.lang.Float.TYPE
         elseif f_type.is_double then
            idx := constant_pool.idx_fieldref3(fz_java_lang_double,as_type,fz_ca)
            code_attribute.opcode_getstatic(idx,2); -- get java.lang.Double.TYPE
         elseif f_type.is_pointer then
            create fcn.make(64)
            fcn.copy(fz_java_lang_object)
            fcn.replace_all('/','.')
            idx := constant_pool.idx_string2(fcn)
            code_attribute.opcode_ldc(idx)
            idx := constant_pool.idx_methodref3(fz_java_lang_class,fz_d1,fz_d2); -- forName
            code_attribute.opcode_invokestatic(idx,-1)
         end
      end

   jvm_branch_if_false: INTEGER is
      do
	 not_yet_implemented
      end

   jvm_branch_if_true: INTEGER is
      do
	 not_yet_implemented
      end

feature {AGENT_POOL}

   falling_down is
      do
	 switch_collection.update_with(run_feature)
      end

   c_define_type_1(boost: BOOLEAN) is
      require
	 cpp.on_h; boost = ace.boost
      local
	 i, id: INTEGER; t: E_TYPE
      do
	 id := creation_mold_id
	 buffer.clear
	 buffer.append(once "typedef struct _se_agent")
	 id.append_in(buffer)
	 buffer.append(once " se_agent")
	 id.append_in(buffer)
	 buffer.append(once ";%Nstruct _se_agent")
	 id.append_in(buffer)
	 buffer.append(once "{Tid id;%Nint creation_mold_id;%N")
	 t := run_feature.result_type
	 if t = void then
	    buffer.append(fz_void)
	 else
	    t.c_type_for_result_in(buffer)
	 end
	 buffer.append(once "(*afp)(")
	 if not boost then buffer.append(once "se_dump_stack*,") end
	 buffer.append(once "se_agent")
	 id.append_in(buffer)
	 buffer.extend('*')
	 if base /= Void then
	    buffer.extend(',')
	    t := run_feature.current_type
	    t.c_type_for_result_in(buffer)
	 end
	 if open_args /= Void then
	    from i := 1; until i > arguments.count
	    loop
	       if not is_closed_argument(i) then
		  buffer.extend(',')
		  t := arguments.expression(i).result_type
		  t.c_type_for_result_in(buffer)
	       end
	       i := i + 1
	    end
	 end
	 buffer.append(once ");")
	 if base = Void then
	    t := run_feature.current_type
	    t.c_type_for_argument_in(buffer)
	    buffer.append(once " C;")
	 end
	 if arguments /= Void then
	    from
	       i := 1
	    until
	       i > arguments.count
	    loop
	       if is_closed_argument(i) then
		  t := arguments.expression(i).result_type
		  t.c_type_for_argument_in(buffer)
		  buffer.append(once " a")
		  i.append_in(buffer)
		  buffer.extend(';')
	       end
	       i := i + 1
	    end
	 end
	 t := run_feature.result_type
	 if t /= Void then
	    t.c_type_for_argument_in(buffer)
	    buffer.append(once " R;")
	 end
	 buffer.append(once "};%N")
	 cpp.put_string(buffer)
      ensure
	 cpp.on_h
      end

   c_define_type_2 is
      require
	 cpp.on_h
      local
	 id: INTEGER
      do
	 id := creation_mold_id
	 cpp.put_string(once "se_agent")
	 cpp.put_integer(id)
	 cpp.put_character(' ')
	 cpp.put_character('u')
	 cpp.put_integer(id)
	 cpp.put_character(';')
      ensure
	 cpp.on_h
      end

   c_define_function(boost: BOOLEAN) is
      require
	 cpp.on_c; boost = ace.boost
      local
	 t, rt: E_TYPE; i, id: INTEGER
      do
	 id := creation_mold_id
	 -- The local execution function:
	 buffer.clear
	 buffer.append(once "%Nstatic ")
	 t := run_feature.result_type
	 if t /= Void then
	    t.c_type_for_result_in(buffer)
	 else
	    buffer.append(fz_void)
	 end
	 buffer.extend(' ')
	 buffer.append(execution_function_name)
	 buffer.extend('(')
	 if not boost then
	    buffer.append(once "se_dump_stack*caller,")
	 end
	 buffer.append(once "se_agent")
	 id.append_in(buffer)
	 buffer.extend('*')
	 buffer.extend('u')
	 if base /= Void then
	    buffer.extend(',')
	    t := run_feature.current_type
	    t.c_type_for_result_in(buffer)
	    buffer.extend(' ')
	    buffer.extend('C')
	 end
	 if open_args /= Void then
	    from i := 1; until i > arguments.count
	    loop
	       if not is_closed_argument(i) then
		  buffer.extend(',')
		  t := arguments.expression(i).result_type
		  t.c_type_for_result_in(buffer)
		  buffer.extend(' ')
		  buffer.extend('a')
		  i.append_in(buffer)
	       end
	       i := i + 1
	    end
	 end
	 buffer.append(once "){%N")
	 if base = Void then
	    t := target.result_type
	    if t.is_user_expanded then
	       t.c_type_for_target_in(buffer)
	       buffer.append(once " C=&(u->C);%N")
	    else 
	       t.c_type_for_argument_in(buffer)
	       buffer.append(once " C=u->C;%N")
	    end
	 end
	 if arguments /= Void then
	    from
	       i := 1; until i > arguments.count
	    loop
	       if is_closed_argument(i) then
		  t := arguments.expression(i).result_type
		  t.c_type_for_argument_in(buffer)
		  buffer.extend(' ')
		  buffer.extend('a')
		  i.append_in(buffer)
		  buffer.append(once "=u->a")
		  i.append_in(buffer)
		  buffer.extend(';')
		  buffer.extend('%N')
	       end
	       i := i + 1
	    end
	 end
	 cpp.put_string(buffer)
         if not boost then
            cpp.put_string(
             once "[
                 se_frame_descriptor fd={"<agent-call-wrapper-2>",0,0,"",1};
                 se_dump_stack ds;
                 ds.fd=&fd;
                 ds.p=0;
                 ds.caller=caller;
                 ds.exception_origin=NULL;
                 ds.locals=NULL;

                  ]")
         end
	 -- Calling the actual one:
	 create e_agent_call.make(Current,run_feature)
	 rt := run_feature.result_type
	 if rt /= Void then
	    cpp.put_string(once "u->R=")
	 end
	 cpp.put_cpc(e_agent_call)
	 if rt /= Void then
	    cpp.put_string(once ";%Nreturn u->R;%N")
	 end
	 cpp.put_character('}')
	 -- The definition function:
	 buffer.clear
	 buffer.append(once "/*agent*/T0*")
	 buffer.append(definition_function_name)
	 buffer.extend('(')
	 if not boost then
	    buffer.append(once "se_dump_stack*caller")
	 end
	 if base = Void then
	    if buffer.last /= '(' then buffer.extend(',') end
	    t := target.result_type
	    t.c_type_for_argument_in(buffer)
	    buffer.extend(' ')
	    buffer.extend('C')
	 end
	 if arguments /= Void then
	    from
	       i := 1; until i > arguments.count
	    loop
	       if is_closed_argument(i) then
		  if buffer.last /= '(' then buffer.extend(',') end
		  t := arguments.expression(i).result_type
		  t.c_type_for_argument_in(buffer)
		  buffer.extend(' ')
		  buffer.extend('a')
		  i.append_in(buffer)
	       end
	       i := i + 1
	    end
	 end
	 if buffer.last = '(' then buffer.append(fz_void) end
	 buffer.extend(')')
	 cpp.put_c_heading(buffer)
	 cpp.put_string(once "se_agent")
	 cpp.put_integer(id)
	 cpp.put_string(once "*u=(void*)new_agent(")
	 cpp.put_integer(result_type.id)
	 cpp.put_string(once ");%Nu->creation_mold_id=")
	 cpp.put_integer(creation_mold_id)
	 cpp.put_string(once ";%Nu->afp=")
	 cpp.put_string(execution_function_name)
	 cpp.put_string(once ";%N")
	 if base = Void then
	    if ace.no_check
	       and then not target.result_type.is_expanded
	       and then not target.is_current
	     then
	       cpp.put_string(once "u->C=vc(C,")
               cpp.put_position(target.start_position)
	       cpp.put_string(once ");%N")
            else
	       cpp.put_string(once "u->C=C;%N")
            end
	 end
	 if arguments /= Void then
	    from
	       i := 1
	    until
	       i > arguments.count
	    loop
	       if is_closed_argument(i) then
		  cpp.put_string(once "u->a")
		  cpp.put_integer(i)
		  cpp.put_string(once "=a")
		  cpp.put_integer(i)
		  cpp.put_string(once ";%N")
	       end
	       i := i + 1
	    end
	 end
	 cpp.put_string(once "return((T0*)u);%N}%N")
      ensure
	 cpp.on_c
      end

feature {OPEN_OPERAND}

   register(open_operand: OPEN_OPERAND) is
      require
	 open_operand /= Void
      do
	 if open_args = Void then
	    create open_args.with_capacity(4)
	 end
	 open_args.add_last(open_operand)
      end

feature {JVM, E_AGENT}

   base: E_TYPE
	 -- When the target itself is an open operand.

   call: CALL
	 -- The one provided by the eiffel_parser.

   current_type: E_TYPE
	 -- Not Void when checked in this context.

   target: EXPRESSION
	 -- Computed one using `base' and `call'.

   run_feature: RUN_FEATURE
	 -- Computed one using `target' and `call'.

   feature_name: FEATURE_NAME
	 -- Computed one using `call'.

   arguments: EFFECTIVE_ARG_LIST
	 -- Computed one using the `call'.

   open_args: FIXED_ARRAY[OPEN_OPERAND]
	 -- Computed using `arguments' to store, if any, the list of open
	 -- arguments. -- (The `target' is never part of this list, see 
	 -- `base'.)

   open_tuple: TYPE_TUPLE

   definition_function_name: STRING
	 -- The name of the definition function.

   execution_function_name: STRING
	 -- The name of the execution function.

   e_agent_call: E_AGENT_CALL
	 -- The fake CALL_PROC_CALL.

   is_closed_argument(i: INTEGER): BOOLEAN is
	 -- Is the `i'th argument a closed argument?
      require
	 i.in_range(1,arguments.count)
      local
	 e: EXPRESSION; open_operand: OPEN_OPERAND
      do
	 e := arguments.expression(i)
	 open_operand ?= e
	 Result := open_operand = Void
      end

feature {E_AGENT_VISITOR}

   accept(visitor: E_AGENT_VISITOR) is
      do
         visitor.visit_e_agent(Current)
      end

feature {NONE}

   make(sp: like start_position; b: like base; c: like call) is
      require
	 not sp.is_unknown
	 c /= Void
      do
	 start_position := sp
	 base := b
	 call := c
	 debug
	    debug_info := "line " + sp.line.to_string + " " + sp.path
	 end
      ensure
	 start_position = sp
	 base = b
	 call = c
      end

   mold_equal(t1, t2: E_TYPE): BOOLEAN is
	 -- Checking if type are similar from `creation_mold_id' point of view.
      require
	 t1.is_static
	 t2.is_static
      do
	 if t1.is_reference then
	    Result := t2.is_reference
	 else
	    Result := t1.run_time_mark = t2.run_time_mark
	 end
      end
   
   debug_info: STRING
   
   buffer: STRING is
      once
	 create Result.make(512)
      end

invariant

   call /= Void

end -- E_AGENT
