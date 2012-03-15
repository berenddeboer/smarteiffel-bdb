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
class AGENT_INSTRUCTION
   --
   -- Some agent is called using the `foo.call([bar]);' notation.
   --

inherit CALL_PROC_CALL; INSTRUCTION

creation {PROC_CALL_1} make

feature

   arg_count: INTEGER is 1

   side_effect_free: BOOLEAN is False
      
   end_mark_comment: BOOLEAN is False

   once_pre_computable: BOOLEAN is False

   pretty_print is
      do
	 creator.pretty_print
      end

   to_runnable(ct: E_TYPE): INSTRUCTION is
      do
	 Result := creator.to_runnable(ct)
      end

   compile_to_c is
      do
	 agent_args.c_agent_definition_call(target)
	 cpp.put_character(';')
	 cpp.put_character('%N')
      end

   simplify_2(container: COMPOUND; index: INTEGER) is
      do
      end

   stupid_switch(run_time_set: RUN_TIME_SET): BOOLEAN is
      do
	 check False end
      end

   compile_to_jvm is
      local
         idx: INTEGER; space: INTEGER; fcn: STRING; i_argument: INTEGER
         ft: FAKE_TUPLE; tt: TYPE_TUPLE; tp: TYPE_OF_AGENT; point1: INTEGER
         point2: INTEGER; point3: INTEGER; point4: INTEGER
         index_local: INTEGER; count_local: INTEGER; target_local: INTEGER
      do
         index_local := code_attribute.extra_local_size1
         count_local := code_attribute.extra_local_size1
         target_local := code_attribute.extra_local_size1
         
         target.compile_to_jvm
         fcn := target.result_type.run_class.fully_qualified_name
         idx := constant_pool.idx_class2(fcn)
         code_attribute.opcode_checkcast(idx)
         code_attribute.opcode_astore( target_local )

         -- put open arguments into open_arguments
         code_attribute.opcode_aload( target_local )
         idx := constant_pool.idx_fieldref3( fcn, as_open_arguments, fz_c2  )
         space := target.result_type.jvm_stack_space

         ft ?= arguments.expression(1)
         tp ?= target.result_type
         tt := tp.open

         if tt.count > 0 then
            code_attribute.opcode_dup
            code_attribute.opcode_getfield(idx,space + 1); -- get open_arguments
         end

         from
            i_argument := 1
         until
            i_argument > ft.count
         loop
            code_attribute.opcode_dup
            code_attribute.opcode_push_integer( i_argument - 1 )
            if ft.expression(i_argument).result_type.is_basic_eiffel_expanded then
               push_jvm_expanded_argument_to_object_wrapper( ft.expression(i_argument), tt.type(i_argument) )
            else
               space := ft.expression(i_argument).standard_compile_to_jvm_into( tt.type(i_argument) )
            end
            code_attribute.opcode_aastore
            i_argument := i_argument + 1
         end

         if tt.count > 0 then
            code_attribute.opcode_pop
         end

         -- fill in open arguments in arguments
         -- set up index local
         code_attribute.opcode_push_integer( 0 )
         code_attribute.opcode_istore( index_local )
         -- set up count local
         code_attribute.opcode_dup
         fcn := target.result_type.run_class.fully_qualified_name
         idx := constant_pool.idx_class2(fcn)
         idx := constant_pool.idx_fieldref3( fcn, as_open_argument_indices, fz_d3 )
         space := target.result_type.jvm_stack_space
         code_attribute.opcode_getfield(idx,space + 1); -- get open_arguments_indices
         code_attribute.opcode_arraylength; -- get length of open_arguments_indices
         code_attribute.opcode_istore( count_local )
         code_attribute.opcode_iload( count_local )
         code_attribute.opcode_iconst_0
         point1 := code_attribute.opcode_if_icmpeq -- jump if open_argument_count empty
         -- if open_argument_count > 0, see if open_argument_indices[0] = -1
         code_attribute.opcode_dup
         fcn := target.result_type.run_class.fully_qualified_name
         idx := constant_pool.idx_class2(fcn)
         idx := constant_pool.idx_fieldref3( fcn, as_open_argument_indices, fz_d3 )
         space := target.result_type.jvm_stack_space
         code_attribute.opcode_getfield(idx,space + 1); -- get open_arguments_indices
         code_attribute.opcode_iconst_0
         code_attribute.opcode_iaload
         code_attribute.opcode_iconst_m1
         point2 := code_attribute.opcode_if_icmpne -- jump if open_argument_indices[0] /= -1
         -- get open_arguments[0] and put it in target
         code_attribute.opcode_dup
         code_attribute.opcode_dup -- to get open_arguments
         fcn := target.result_type.run_class.fully_qualified_name
         idx := constant_pool.idx_class2(fcn)
         idx := constant_pool.idx_fieldref3( fcn, as_open_arguments, fz_c2 )
         space := target.result_type.jvm_stack_space
         code_attribute.opcode_getfield(idx,space + 1); -- get open_arguments
         code_attribute.opcode_iconst_0 -- index 0 of open_arguments
         code_attribute.opcode_aaload -- get open_arguments[0]
         fcn := target.result_type.run_class.fully_qualified_name
         idx := constant_pool.idx_class2(fcn)
         idx := constant_pool.idx_fieldref3( fcn, as_target, fz_21  )
         space := target.result_type.jvm_stack_space
         code_attribute.opcode_putfield(idx,space + 1); -- set target
         -- set open_argument_index to 1
         code_attribute.opcode_push_integer( 1 )
         code_attribute.opcode_istore( index_local )
         code_attribute.resolve_u2_branch( point2 ) -- jumped to here if open_argument_indices[0] /= -1
         -- test to see if open_argument_index >= open_argument_count
         point4 := code_attribute.program_counter; -- jumped to here from end of "loop" to copy open arguments
--
         code_attribute.opcode_iload( index_local )
         code_attribute.opcode_iload( count_local )
         point3 := code_attribute.opcode_if_icmpge -- jump if open_argument_index >= open_argument_count
         -- put open_argument[open_argument_index] into
         -- arguments[ open_argument_indices[open_argument_index] ]
         code_attribute.opcode_dup
         code_attribute.opcode_dup
         fcn := target.result_type.run_class.fully_qualified_name
         idx := constant_pool.idx_class2(fcn)
         idx := constant_pool.idx_fieldref3( fcn, as_arguments, fz_c2  )
         space := target.result_type.jvm_stack_space
         code_attribute.opcode_getfield(idx,space + 1); -- get arguments
         --target.compile_to_jvm
         code_attribute.opcode_swap
         fcn := target.result_type.run_class.fully_qualified_name
         idx := constant_pool.idx_class2(fcn)
         idx := constant_pool.idx_fieldref3( fcn, as_open_argument_indices, fz_d3 )
         space := target.result_type.jvm_stack_space
         code_attribute.opcode_getfield(idx,space + 1); -- get open_arguments_indices
         code_attribute.opcode_iload( index_local )
         code_attribute.opcode_iaload -- get open_argument_indices[open_argument_index]
         code_attribute.opcode_aload( target_local )
         fcn := target.result_type.run_class.fully_qualified_name
         idx := constant_pool.idx_class2(fcn)
         idx := constant_pool.idx_fieldref3( fcn, as_open_arguments, fz_c2 )
         space := target.result_type.jvm_stack_space
         code_attribute.opcode_getfield(idx,space + 1); -- get open_arguments
         code_attribute.opcode_iload( index_local )
         code_attribute.opcode_aaload   -- get open_argument[open_argument_index]
         code_attribute.opcode_aastore  -- store argument[open_argument_indices[open_argument_index]] = open_argument[open_argument_index]
         -- increment open_argument_index
         code_attribute.opcode_iload( index_local )
         code_attribute.opcode_iconst_1
         code_attribute.opcode_iadd
         code_attribute.opcode_istore( index_local )
         code_attribute.opcode_goto_backward(point4); -- jump back to top of loop to iterate through open_arguments

         code_attribute.resolve_u2_branch( point3 ) -- jumped to here if open_argument_index >= open_argument_count
         code_attribute.resolve_u2_branch( point1 ) -- jumped to here if open_argument_count empty
         fcn := target.result_type.run_class.fully_qualified_name
         idx := constant_pool.idx_class2(fcn)
         fcn := target.result_type.run_class.fully_qualified_name
         idx := constant_pool.idx_fieldref3( fcn, as_method, fz_21  )
         space := target.result_type.jvm_stack_space
         code_attribute.opcode_getfield(idx,space + 1); -- get method
         idx := constant_pool.idx_class2(fz_java_lang_reflect_method)
         code_attribute.opcode_checkcast(idx)
         idx := constant_pool.idx_class2(fz_java_lang_reflect_method)
         code_attribute.opcode_aload( target_local )
         fcn := target.result_type.run_class.fully_qualified_name
         idx := constant_pool.idx_class2(fcn)
         idx := constant_pool.idx_fieldref3( fcn, as_target, fz_21  )
         space := target.result_type.jvm_stack_space
         code_attribute.opcode_getfield(idx,space + 1); -- get target
         code_attribute.opcode_aload( target_local )
         fcn := target.result_type.run_class.fully_qualified_name
         idx := constant_pool.idx_class2(fcn)
         idx := constant_pool.idx_fieldref3( fcn, as_arguments, fz_c2  )
         space := target.result_type.jvm_stack_space
         code_attribute.opcode_getfield(idx,space + 1); -- get arguments
         idx := constant_pool.idx_methodref3( fz_java_lang_reflect_method, fz_c8, fz_c9  ); -- invoke
         code_attribute.opcode_invokevirtual( idx, -1 )
         code_attribute.opcode_aload( target_local )
         code_attribute.opcode_swap
         fcn := target.result_type.run_class.fully_qualified_name
         idx := constant_pool.idx_class2(fcn)
         idx := constant_pool.idx_fieldref3( fcn, as_last_result, fz_21 )
         space := target.result_type.jvm_stack_space
         code_attribute.opcode_putfield(idx,space + 1); -- set last_result
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

feature {COMPOUND,INSTRUCTION_WITH_COMMENT}

   verify_scoop(allowed: FORMAL_ARG_LIST) is
      local
         dummy: BOOLEAN
      do
         if not target.is_current and then target.result_type.is_separate then
            if allowed /= Void then
               dummy := allowed.verify_scoop(creator.target)
            else
               target.scoop_error
            end
         end
      end

feature {AGENT_INSTRUCTION_VISITOR}

   accept(visitor: AGENT_INSTRUCTION_VISITOR) is
      do
         visitor.visit_agent_instruction(Current)
      end

feature {NONE}

   creator: PROC_CALL
	 -- The `creator' of `Current'.

   arguments: EFFECTIVE_ARG_LIST

   agent_args: AGENT_ARGS
	 -- Computed using `feature_name' and `aguments'.

   make(c: like creator) is
      require
	 c.target /= Void
	 c.feature_name.to_string = as_call
	 c.run_feature.result_type = Void
      do
	 creator := c
	 target := creator.target
	 feature_name := creator.feature_name
	 arguments := creator.arguments
	 run_feature := creator.run_feature
	 agent_args := agent_pool.register_agent_call(arguments,run_feature)
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

invariant

   target /= Void

   feature_name /= Void

   run_feature /= Void

end -- AGENT_INSTRUCTION
