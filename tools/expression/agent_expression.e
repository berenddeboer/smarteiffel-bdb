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
class AGENT_EXPRESSION
   --
   -- Some agent is called using the `foo.item([bar])' notation.
   --


inherit
   CALL_PROC_CALL
   EXPRESSION redefine verify_scoop end

creation {CALL_1_C} make

feature

   is_current: BOOLEAN is False

   is_void: BOOLEAN is False

   side_effect_free: BOOLEAN is False

   is_manifest_string: BOOLEAN is False

   is_static: BOOLEAN is False

   once_pre_computable: BOOLEAN is False

   is_result: BOOLEAN is False

   is_writable: BOOLEAN is False

   extra_bracket_flag: BOOLEAN is True
   
   arg_count: INTEGER is 1

   result_type: E_TYPE is
      do
	 Result := run_feature.result_type
      end

   start_lookup_class: BASE_CLASS is do end

   stupid_switch(run_time_set: RUN_TIME_SET): BOOLEAN is
      do
	 check False end
      end

   to_runnable(ct: E_TYPE): EXPRESSION is
      do
	 Result := creator.to_runnable(ct)
      end

   simplify_1_, simplify_2: like Current is
      do
	 Result := Current
      end
   
   compile_to_c is
      do
	 agent_args.c_agent_definition_call(target)
      end

   mapping_c_arg(formal_arg_type: E_TYPE) is
      do
	 compile_to_c
      end

   mapping_c_target(formal_type: E_TYPE) is
      do
	 standard_mapping_c_target(formal_type)
      end

   c_frame_descriptor(format, locals: STRING) is do end

   assertion_check(tag: CHARACTER) is do end

   to_integer_or_error: INTEGER is
      do
	 to_integer_error
      end

   isa_dca_inline_argument: INTEGER is 0

   dca_inline_argument(formal_arg_type: E_TYPE) is
      do
	 check False end
      end

   compile_target_to_jvm, compile_to_jvm is
      local
         idx: INTEGER space: INTEGER fcn: STRING i_argument: INTEGER
         ft: FAKE_TUPLE  tt: TYPE_TUPLE
         tf: TYPE_FUNCTION
         point1: INTEGER
         point2: INTEGER
         point3: INTEGER
         point4: INTEGER
         index_local: INTEGER
         count_local: INTEGER
         target_local: INTEGER
      do
	 -- target                t
	 -- open_arguments        o
	 -- open_arguments_count  c
	 -- open_arguments_index  x
	 -- open_argument_indices d
	 -- arguments             a
	 -- base                  b
	 -- integer               i
	 -- minus_1               m
	 -- object                j
	 -- method                e
	 index_local := code_attribute.extra_local_size1
         count_local := code_attribute.extra_local_size1
         target_local := code_attribute.extra_local_size1
         
	 -- set up target local
	 
         target.compile_to_jvm
         fcn := target.result_type.run_class.fully_qualified_name
         idx := constant_pool.idx_class2(fcn)
         code_attribute.opcode_checkcast(idx)
         code_attribute.opcode_astore( target_local )
	 
         -- put open arguments into open_arguments
	 -- ,
         code_attribute.opcode_aload( target_local )
	 -- ,t         
         idx := constant_pool.idx_fieldref3( fcn, as_open_arguments, fz_c2  )
         space := target.result_type.jvm_stack_space

         ft ?= arguments.expression(1)
         tf ?= target.result_type
         tt := tf.open

         if tt.count > 0 then
            code_attribute.opcode_dup
	    -- ,tt         
            code_attribute.opcode_getfield(idx,space + 1); 
	    -- get open_arguments ,to            
         end
         from
            i_argument := 1
         until
            i_argument > ft.count
         loop
            code_attribute.opcode_dup
	    -- ,too
            code_attribute.opcode_push_integer( i_argument - 1 )
	    -- ,tooi            
            if ft.expression(i_argument).result_type.is_basic_eiffel_expanded then
               push_jvm_expanded_argument_to_object_wrapper( ft.expression(i_argument), tt.type(i_argument) )
            else
               space := ft.expression(i_argument).standard_compile_to_jvm_into( tt.type(i_argument) )
            end
	    -- ,tooij
            code_attribute.opcode_aastore
	    -- ,to
            i_argument := i_argument + 1
         end
         if tt.count > 0 then
            code_attribute.opcode_pop
	    -- ,t            
         end
	 
         -- fill in open arguments in arguments
         -- set up index local
         code_attribute.opcode_push_integer( 0 )
         code_attribute.opcode_istore( index_local )
	 -- ,t

         -- set up count local
         code_attribute.opcode_dup
	 -- ,tt         
         fcn := target.result_type.run_class.fully_qualified_name
         idx := constant_pool.idx_class2(fcn)
         idx := constant_pool.idx_fieldref3( fcn, as_open_argument_indices, fz_d3 )
         space := target.result_type.jvm_stack_space
         code_attribute.opcode_getfield(idx,space + 1); -- get open_arguments_indices
	 -- ,td
         code_attribute.opcode_arraylength; -- get length of open_arguments_indices
	 -- ,tc         
         code_attribute.opcode_istore( count_local )
	 -- ,t         
         code_attribute.opcode_iload( count_local )
	 -- ,tc
         code_attribute.opcode_iconst_0
	 -- ,tc0         
         point1 := code_attribute.opcode_if_icmpeq -- jump if open_argument_count empty
	 -- ,t
         -- if open_argument_count > 0, see if open_argument_indices[0] = -1
         code_attribute.opcode_dup
	 -- ,tt         
         fcn := target.result_type.run_class.fully_qualified_name
         idx := constant_pool.idx_class2(fcn)
         idx := constant_pool.idx_fieldref3( fcn, as_open_argument_indices, fz_d3 )
         space := target.result_type.jvm_stack_space
         code_attribute.opcode_getfield(idx,space + 1); -- get open_arguments_indices
	 -- ,td
         code_attribute.opcode_iconst_0
	 -- ,td0         
         code_attribute.opcode_iaload
	 -- ,ti         
         code_attribute.opcode_iconst_m1
	 -- ,tim         
         point2 := code_attribute.opcode_if_icmpne -- jump if open_argument_indices[0] /= -1
	 -- ,t
         -- get open_arguments[0] and put it in target
         code_attribute.opcode_dup
	 -- ,tt         
         code_attribute.opcode_dup -- to get open_arguments
	 -- ,ttt
         fcn := target.result_type.run_class.fully_qualified_name
         idx := constant_pool.idx_class2(fcn)
         idx := constant_pool.idx_fieldref3( fcn, as_open_arguments, fz_c2 )
         space := target.result_type.jvm_stack_space
         code_attribute.opcode_getfield(idx,space + 1); -- get open_arguments
	 -- ,tto
         code_attribute.opcode_iconst_0 -- index 0 of open_arguments
	 -- ,tto0         
         code_attribute.opcode_aaload -- get open_arguments[0]
	 -- ,ttj         
         fcn := target.result_type.run_class.fully_qualified_name
         idx := constant_pool.idx_class2(fcn)
         idx := constant_pool.idx_fieldref3( fcn, as_target, fz_21  )
         space := target.result_type.jvm_stack_space
	 code_attribute.opcode_putfield(idx,space + 1); -- set target
	 -- ,t
         -- set open_argument_index to 1
         code_attribute.opcode_push_integer( 1 )
         code_attribute.opcode_istore( index_local )
	 -- ,t         
         code_attribute.resolve_u2_branch( point2 ) -- jumped to here if open_argument_indices[0] /= -1
	 -- ,t
         -- test to see if open_argument_index >= open_argument_count
         point4 := code_attribute.program_counter; -- jumped to here from end of "loop" to copy open arguments
	 --
         code_attribute.opcode_iload( index_local )
      -- ,tx         
      -- ,tx 
      code_attribute.opcode_iload( count_local )
      -- ,txc
      point3 := code_attribute.opcode_if_icmpge -- jump if open_argument_index >= open_argument_count
      -- ,t         
      -- put open_argument[open_argument_index] into
      -- arguments[ open_argument_indices[open_argument_index] ]
      code_attribute.opcode_dup
      -- ,tt         
      code_attribute.opcode_dup
      -- ,ttt
      fcn := target.result_type.run_class.fully_qualified_name
      idx := constant_pool.idx_class2(fcn)
      idx := constant_pool.idx_fieldref3( fcn, as_arguments, fz_c2  )
      space := target.result_type.jvm_stack_space
      code_attribute.opcode_getfield(idx,space + 1); -- get arguments
      -- ,tta         
      --target.compile_to_jvm
      code_attribute.opcode_swap
      -- ,tat                  
      fcn := target.result_type.run_class.fully_qualified_name
      idx := constant_pool.idx_class2(fcn)
      idx := constant_pool.idx_fieldref3( fcn, as_open_argument_indices, fz_d3 )
      space := target.result_type.jvm_stack_space
      code_attribute.opcode_getfield(idx,space + 1); -- get open_arguments_indices
      -- ,tad         
      code_attribute.opcode_iload( index_local )
      -- ,tadx
      code_attribute.opcode_iaload -- get open_argument_indices[open_argument_index]
      -- ,tai
      code_attribute.opcode_aload( target_local )
      -- ,tait
      fcn := target.result_type.run_class.fully_qualified_name
      idx := constant_pool.idx_class2(fcn)
      idx := constant_pool.idx_fieldref3( fcn, as_open_arguments, fz_c2 )
      space := target.result_type.jvm_stack_space
      code_attribute.opcode_getfield(idx,space + 1); -- get open_arguments
      -- ,taio
      code_attribute.opcode_iload( index_local )
      -- ,taiox
      code_attribute.opcode_aaload   -- get open_argument[open_argument_index]
      -- ,taij
      code_attribute.opcode_aastore  -- store argument[open_argument_indices[open_argument_index]] = open_argument[open_argument_index]
      -- ,t
      -- increment open_argument_index
      -- ,t
      code_attribute.opcode_iload( index_local )
      -- ,tx         
      code_attribute.opcode_iconst_1
      -- ,tx1
      code_attribute.opcode_iadd
      -- ,ti
      code_attribute.opcode_istore( index_local )
      -- ,t
      code_attribute.opcode_goto_backward(point4); -- jump back to top of loop to iterate through open_arguments
      
      code_attribute.resolve_u2_branch( point3 ) -- jumped to here if open_argument_index >= open_argument_count
      code_attribute.resolve_u2_branch( point1 ) -- jumped to here if open_argument_count empty
      -- ,t
      fcn := target.result_type.run_class.fully_qualified_name
      idx := constant_pool.idx_class2(fcn)
      fcn := target.result_type.run_class.fully_qualified_name
      idx := constant_pool.idx_fieldref3( fcn, as_method, fz_21  )
      space := target.result_type.jvm_stack_space
      code_attribute.opcode_getfield(idx,space + 1); -- get method
-- ,e
         idx := constant_pool.idx_class2(fz_java_lang_reflect_method)
         code_attribute.opcode_checkcast(idx)
-- ,e
         idx := constant_pool.idx_class2(fz_java_lang_reflect_method)
         code_attribute.opcode_aload( target_local )
-- ,et
         fcn := target.result_type.run_class.fully_qualified_name
         idx := constant_pool.idx_class2(fcn)
         idx := constant_pool.idx_fieldref3( fcn, as_target, fz_21  )
         space := target.result_type.jvm_stack_space
         code_attribute.opcode_getfield(idx,space + 1); -- get target
-- ,eb
         code_attribute.opcode_aload( target_local )
-- ,ebt
         fcn := target.result_type.run_class.fully_qualified_name
         idx := constant_pool.idx_class2(fcn)
         idx := constant_pool.idx_fieldref3( fcn, as_arguments, fz_c2  )
         space := target.result_type.jvm_stack_space
         code_attribute.opcode_getfield(idx,space + 1); -- get arguments
-- ,eba
         idx := constant_pool.idx_methodref3( fz_java_lang_reflect_method, fz_c8, fz_c9  ); -- invoke
         code_attribute.opcode_invokevirtual( idx, -1 )
-- ,j
         code_attribute.opcode_dup
-- ,jj         
         code_attribute.opcode_aload( target_local )
-- ,jjt
         code_attribute.opcode_swap
-- ,jtj
         fcn := target.result_type.run_class.fully_qualified_name
         idx := constant_pool.idx_class2(fcn)
         idx := constant_pool.idx_fieldref3( fcn, as_last_result, fz_21 )
         space := target.result_type.jvm_stack_space
         code_attribute.opcode_putfield(idx,space + 1); -- set last_result
-- ,j 
         if result_type.is_basic_eiffel_expanded then
            convert_jvm_expanded_argument_from_object_wrapper( result_type )
         end
-- ,"j"        

      end

   push_jvm_expanded_argument_to_object_wrapper( arg_expression: EXPRESSION; f_type: E_TYPE ) is
      local
         idx: INTEGER
         space: INTEGER
      do
         if f_type.is_boolean then
            idx := constant_pool.idx_class2(fz_java_lang_boolean)
            code_attribute.opcode_new(idx)
            code_attribute.opcode_dup
            space := arg_expression.standard_compile_to_jvm_into( f_type )
            idx := constant_pool.idx_methodref3( fz_java_lang_boolean, fz_35, fz_cb  ); -- <init>
            code_attribute.opcode_invokespecial( idx, -1 )
         elseif f_type.is_character then
            idx := constant_pool.idx_class2(fz_java_lang_byte)
            code_attribute.opcode_new(idx)
            code_attribute.opcode_dup
            space := arg_expression.standard_compile_to_jvm_into( f_type )
            idx := constant_pool.idx_methodref3( fz_java_lang_byte, fz_35, fz_cc1  ); -- <init>
            code_attribute.opcode_invokespecial( idx, -1 )
         elseif f_type.is_integer then
            idx := constant_pool.idx_class2(fz_java_lang_integer)
            code_attribute.opcode_new(idx)
            code_attribute.opcode_dup
            space := arg_expression.standard_compile_to_jvm_into( f_type )
            idx := constant_pool.idx_methodref3( fz_java_lang_integer, fz_35, fz_27  ); -- <init>
            code_attribute.opcode_invokespecial( idx, -1 )
         elseif f_type.is_real then
            idx := constant_pool.idx_class2(fz_java_lang_float)
            code_attribute.opcode_new(idx)
            code_attribute.opcode_dup
            space := arg_expression.standard_compile_to_jvm_into( f_type )
            idx := constant_pool.idx_methodref3( fz_java_lang_float, fz_35, fz_ce  ); -- <init>
            code_attribute.opcode_invokespecial( idx, -1 )
         elseif f_type.is_double then
            idx := constant_pool.idx_class2(fz_java_lang_double)
            code_attribute.opcode_new(idx)
            code_attribute.opcode_dup
            space := arg_expression.standard_compile_to_jvm_into( f_type )
            idx := constant_pool.idx_methodref3( fz_java_lang_double, fz_35, fz_cf  ); -- <init>
            code_attribute.opcode_invokespecial( idx, -1 )
         elseif f_type.is_pointer then
            arg_expression.compile_to_jvm
         end
      end

   convert_jvm_expanded_argument_from_object_wrapper( f_type: E_TYPE ) is
      local
         idx: INTEGER
      do
         if f_type.is_boolean then
            idx := constant_pool.idx_class2(fz_java_lang_boolean)
            code_attribute.opcode_checkcast(idx)
            idx := constant_pool.idx_methodref3( fz_java_lang_boolean, fz_d4, fz_87  ); -- booleanValue
            code_attribute.opcode_invokevirtual( idx, -1 )
         elseif f_type.is_character then
            idx := constant_pool.idx_class2(fz_java_lang_byte)
            code_attribute.opcode_checkcast(idx)
            idx := constant_pool.idx_methodref3( fz_java_lang_byte, fz_d6, fz_d5  ); -- byteValue
            code_attribute.opcode_invokevirtual( idx, -1 )
         elseif f_type.is_integer then
            idx := constant_pool.idx_class2(fz_java_lang_integer)
            code_attribute.opcode_checkcast(idx)
            idx := constant_pool.idx_methodref3( fz_java_lang_integer, fz_d7, fz_71  ); -- intValue
            code_attribute.opcode_invokevirtual( idx, -1 )
         elseif f_type.is_real then
            idx := constant_pool.idx_class2(fz_java_lang_float)
            code_attribute.opcode_checkcast(idx)
            idx := constant_pool.idx_methodref3( fz_java_lang_float, fz_da, fz_97 ); -- floatValue
            code_attribute.opcode_invokevirtual( idx, -1 )
         elseif f_type.is_double then
            idx := constant_pool.idx_class2(fz_java_lang_double)
            code_attribute.opcode_checkcast(idx)
            idx := constant_pool.idx_methodref3( fz_java_lang_double, fz_db, fz_96  ); -- doubleValue
            code_attribute.opcode_invokespecial( idx, -1 )
         elseif f_type.is_pointer then
         end
      end

   compile_to_jvm_into(dest: E_TYPE): INTEGER is
      do
         Result := standard_compile_to_jvm_into(dest)
      end

   jvm_branch_if_true: INTEGER is
      do
	 check False end
      end

   jvm_branch_if_false: INTEGER is
      do
	 check False end
      end

   jvm_assign_creation, jvm_assign is
      do
	 check False end
      end

   precedence: INTEGER is
      do
         Result := atomic_precedence
      end

   short is
      do
	 not_yet_implemented
      end

   short_target is
      do
	 not_yet_implemented
      end

   pretty_print is
      do
	 creator.pretty_print
      end

   bracketed_pretty_print is
      do
	 pretty_printer.put_character('(')
         pretty_print
         pretty_printer.put_character(')')
      end

   print_as_target is
      do
	 pretty_printer.put_character('(')
         pretty_print
         pretty_printer.put_character(')')
         pretty_printer.put_character('.')
      end

feature

   verify_scoop(allowed: FORMAL_ARG_LIST): BOOLEAN is
      do
         Result := target.result_type.is_separate
         Result := target.verify_scoop(allowed) or else Result
         if allowed /= Void then
            if allowed.verify_scoop(target) then
               Result := True
            end
         elseif target.result_type.is_separate and then not target.is_current then
            target.scoop_error
         end
      end

feature {AGENT_EXPRESSION_VISITOR}

   accept(visitor: AGENT_EXPRESSION_VISITOR) is
      do
         visitor.visit_agent_expression(Current)
      end

feature {NONE}

   creator: CALL_1_C
	 -- The `creator' of `Current'.

   arguments: EFFECTIVE_ARG_LIST

   agent_args: AGENT_ARGS
	 -- Computed using `feature_name' and `aguments'.

   make(c: like creator) is
      require
	 c.target /= Void
	 c.feature_name.to_string = as_item
	 c.run_feature.result_type /= Void
      do
	 creator := c
	 target := creator.target
	 feature_name := creator.feature_name
	 arguments := creator.arguments
	 run_feature := creator.run_feature
	 agent_args := agent_pool.register_agent_call(arguments, run_feature)
      ensure
	 creator = c
	 target = creator.target
	 feature_name = creator.feature_name
	 arguments = creator.arguments
	 run_feature = creator.run_feature
      end

   afd_check_hook is
      do
      end

end -- AGENT_EXPRESSION
