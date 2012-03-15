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
class EXPRESSION_WITH_COMMENT
   --
   -- To wrap an expression with a following comment.
   --

inherit EXPRESSION

creation make

feature {EXPRESSION_WITH_COMMENT_VISITOR}

   accept(visitor: EXPRESSION_WITH_COMMENT_VISITOR) is
      do
         visitor.visit_expression_with_comment(Current)
      end

feature

   expression: EXPRESSION

   comment: COMMENT
	 -- the associated one.

   to_integer_or_error: INTEGER is
      do
	 Result := expression.to_integer_or_error
      end

   start_lookup_class: BASE_CLASS is
      do
         Result := expression.start_lookup_class
      end

   is_writable: BOOLEAN is
      do
         Result := expression.is_writable
      end

   is_manifest_string: BOOLEAN is
      do
         Result := expression.is_manifest_string
      end

   is_void: BOOLEAN is
      do
         Result := expression.is_void
      end

   is_result: BOOLEAN is
      do
         Result := expression.is_result
      end

   is_current: BOOLEAN is
      do
         Result := expression.is_current
      end

   assertion_check(tag: CHARACTER) is
      do
         expression.assertion_check(tag)
      end

   is_static: BOOLEAN is
      do
         Result := expression.is_static
      end

   once_pre_computable: BOOLEAN is
      do
         Result := expression.once_pre_computable
      end

   isa_dca_inline_argument: INTEGER is
      do
         Result := expression.isa_dca_inline_argument
      end

   dca_inline_argument(formal_arg_type: E_TYPE) is
      do
         expression.dca_inline_argument(formal_arg_type)
      end

   mapping_c_target(target_type: E_TYPE) is
      do
         expression.mapping_c_target(target_type)
      end

   mapping_c_arg(formal_arg_type: E_TYPE) is
      do
         expression.mapping_c_arg(formal_arg_type)
      end

   afd_check is
      do
         expression.afd_check
      end

   safety_check is
      do
         expression.safety_check
      end

   collect_c_tmp is
      do
          expression.collect_c_tmp
      end

   compile_to_c is
      do
         expression.compile_to_c
      end

   c_frame_descriptor(format, locals: STRING) is
      do
	 expression.c_frame_descriptor(format,locals)
      end

   compile_to_jvm is
      do
         expression.compile_to_jvm
      end

   compile_target_to_jvm is
      do
         expression.compile_target_to_jvm
      end

   jvm_branch_if_false: INTEGER is
      do
         Result := expression.jvm_branch_if_false
      end

   jvm_branch_if_true: INTEGER is
      do
         Result := expression.jvm_branch_if_true
      end

   compile_to_jvm_into(dest: E_TYPE): INTEGER is
      do
         Result := expression.compile_to_jvm_into(dest)
      end

   use_current: BOOLEAN is
      do
         Result := expression.use_current
      end

   stupid_switch(run_time_set: RUN_TIME_SET): BOOLEAN is
      do
         Result := expression.stupid_switch(run_time_set)
      end

   side_effect_free: BOOLEAN is
      do
         Result := expression.side_effect_free
      end

   to_runnable(ct: E_TYPE): like Current is
      local
         e: EXPRESSION
      do
         e := expression.to_runnable(ct)
         if expression = e then
            Result := Current
         else
            !!Result.make(e,comment)
         end
      end

   simplify_1_, simplify_2: like Current is
      do
	 check
	    -- No creation of COMMENT while producing code:
	    smart_eiffel.pretty_flag or else smart_eiffel.short_flag
	 end
	 Result := Current
      end
   
   start_position: POSITION is
      do
         Result := expression.start_position
      end

   extra_bracket_flag: BOOLEAN is
      do
	 Result := expression.extra_bracket_flag
      end

   pretty_print is
      do
         expression.pretty_print
         comment.pretty_print
      end

   bracketed_pretty_print is
      do
         expression.bracketed_pretty_print
         comment.pretty_print
      end

   print_as_target is
      do
         expression.print_as_target
      end

   short is
      do
         expression.short
      end

   short_target is
      do
         expression.short_target
      end

   result_type: E_TYPE is
      do
         Result := expression.result_type
      end

   precedence: INTEGER is
      do
         Result := expression.precedence
      end

   jvm_assign_creation is
      do
         expression.jvm_assign_creation
      end

   jvm_assign is
      do
         expression.jvm_assign
      end

feature {NONE}

   make(e: like expression; c: like comment) is
      require
         e /= Void
         really_a_comment: c.count > 0
      do
         expression := e
         comment := c
      ensure
         expression = e
         comment = c
      end

invariant

   comment /= Void

end -- EXPRESSION_WITH_COMMENT

