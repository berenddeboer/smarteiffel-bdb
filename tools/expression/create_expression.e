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
class CREATE_EXPRESSION
   --
   -- The new style create expression.
   --

inherit CREATE_TOOLS; EXPRESSION

creation make

feature

   is_current: BOOLEAN is False

   side_effect_free: BOOLEAN is False

   is_manifest_string: BOOLEAN is False

   is_static: BOOLEAN is False

   extra_bracket_flag: BOOLEAN is False
   
   is_void: BOOLEAN is False

   is_result: BOOLEAN is False

   isa_dca_inline_argument: INTEGER is 0

   is_writable: BOOLEAN is False

   dca_inline_argument(formal_arg_type: E_TYPE) is do end

   to_runnable(ct: E_TYPE): EXPRESSION is
      local
	 rc: RUN_CLASS
      do
         if current_type = Void then
	    current_type := ct
	    check_explicit_type
            check_created_type(type)
            check_create_clause(type)
	    Result := simplify_1
	    rc := type.run_class
	    if not rc.current_type.is_basic_eiffel_expanded then
	       rc.create_function_register(run_feature)
	    end
         else
            create {like Current} Result.make(start_position,type,call)
            Result := Result.to_runnable(ct)
         end
      end

   simplify_1_, simplify_2: EXPRESSION is
      do
	 if result_type.is_basic_eiffel_expanded then
	    Result := result_type.default_expression(start_position)
	 else
	    Result := Current
	 end
      end
   
   once_pre_computable: BOOLEAN is
      local
	 expression: EXPRESSION
      do
	 expression := simplify_1
	 if expression /= Current then
	    Result := expression.once_pre_computable
	 elseif arguments = Void or else arguments.once_pre_computable then
	    Result := common_once_pre_computable(type)
	 end
      end

   mapping_c_target(formal_type: E_TYPE) is
      local
	 rc: RUN_CLASS; boost: BOOLEAN; args: like arguments
      do
	 check formal_type.run_time_mark = type.run_time_mark end
	 boost := ace.boost
	 rc := type.run_class
	 cpp.put_string(fz_create)
	 cpp.put_integer(rc.id)
	 if run_feature /= Void then
	    cpp.put_string(run_feature.name.to_string)
	 end
	 cpp.put_character('(')
	 if not boost then
	    cpp.put_string(once "&ds")
	 end
	 args := arguments
	 if args /= Void then
	    if not boost then
	       cpp.put_character(',')
	    end
	    args.compile_to_c(run_feature.arguments)
	 end
	 cpp.put_character(')')
      end

   mapping_c_arg(formal_arg_type: E_TYPE) is
      do
         compile_to_c
      end

   c_frame_descriptor(format, locals: STRING) is
      do
      end

   assertion_check(tag: CHARACTER) is
      do
	 if run_feature /= Void then
	    if tag = 'R' then
	       run_feature.vape_check_from(start_position)
	    end
	 end
      end

   result_type: E_TYPE is
      do
	 Result := type
      end

   use_current: BOOLEAN is
      local
	 args: like arguments
      do
	 args := arguments
	 if args /= Void then
	    Result := args.use_current
	 end
      end

   start_lookup_class: BASE_CLASS is
      do
	 Result := type.base_class
      end

   to_integer_or_error: INTEGER is
      do
	 to_integer_error
      end

   collect_c_tmp is
      do
         if arguments /= Void then
            arguments.collect_c_tmp
         end
      end

   compile_to_c is
      do
	 if type.is_reference then
	    cpp.put_string(once "((T0*)")
	 end
	 mapping_c_target(type)
	 if type.is_reference then
	    cpp.put_character(')')
	 end
      end

   stupid_switch(run_time_set: RUN_TIME_SET): BOOLEAN is
      do
	 Result := True
      end

   compile_target_to_jvm, compile_to_jvm is
      do
         compile_to_jvm0(type)
	 if run_feature /= Void then
	    jvm.inside_create_instruction(run_feature,call)
	 end
         type.jvm_check_class_invariant
      end

   compile_to_jvm_into(dest: E_TYPE): INTEGER is
      do
         Result := standard_compile_to_jvm_into(dest)
      end

   jvm_assign_creation, jvm_assign is
      do
      end

   jvm_branch_if_false: INTEGER is
      do
      end

   jvm_branch_if_true: INTEGER is
      do
      end

   bracketed_pretty_print, pretty_print is
      local
	 semi_colon_flag: BOOLEAN
      do
         pretty_printer.keyword(fz_create)
	 pretty_printer.put_character('{')
	 type.pretty_print
	 pretty_printer.put_character('}')
	 if call /= Void then
	    pretty_printer.put_character('.')
	    semi_colon_flag := pretty_printer.semi_colon_flag
	    pretty_printer.set_semi_colon_flag(False)
	    call.pretty_print
	    pretty_printer.set_semi_colon_flag(semi_colon_flag)
	 end
      end

   print_as_target is
      do
         pretty_printer.put_character('(')
         pretty_print
         pretty_printer.put_character(')')
         pretty_printer.put_character('.')
      end

   precedence: INTEGER is
      do
         Result := atomic_precedence
      end

   short is
      do
         short_print.hook_or(once "create_open",once "create {")
	 type.short
         short_print.hook_or(once "create_close",once "}")
	 if call /= Void then
	    call.short
	 end
      end

   short_target is
      do
         bracketed_short
         short_print.a_dot
      end

feature {CREATE_EXPRESSION_VISITOR}

   accept(visitor: CREATE_EXPRESSION_VISITOR) is
      do
         visitor.visit_create_expression(Current)
      end

feature {NONE}

   se_tmp_buffer: STRING is
      once
	 !!Result.make(64)
      end

   make(sp: like start_position; t: like type; c: like call) is
      require
         not sp.is_unknown
         t /= Void
      do
         start_position := sp
         type := t
         call := c
      ensure
         start_position = sp
         type = t
         call = c
      end

invariant

   type /= Void

   writable = Void

end -- CREATE_EXPRESSION
