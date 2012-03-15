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
deferred class EXPRESSION
   --
   -- Any kind of Eiffel expression.
   --

inherit GLOBALS; VISITABLE

feature

   start_position: POSITION is
         -- Of the expression if any.
      deferred
      end

   is_current: BOOLEAN is
         -- Is it a `Current' like expression (really written `Current' or 
         -- some implicit not-written `Current') ?
      deferred
      end

   is_manifest_string: BOOLEAN is
         -- Is it a manifest string (i.e. a basic manifest string or some
         -- verbatim manifest string)?
      deferred
      end

   is_void: BOOLEAN is
         -- Is it the built-in Void?
      deferred
      end

   is_result: BOOLEAN is
         -- Is it the pseudo local variable `Result' ?
      deferred
      end

   is_writable: BOOLEAN is
         -- Is is something that one can find on the left-hand-side
         -- of the := operator ?
      deferred
      end

   is_static: BOOLEAN is
         -- True if the expression has always the same static value 
         -- regardless the context of the code. For example, this is 
         -- True for True, False, Void, 2, "foo", etc.
      require
         smart_eiffel.is_ready
      deferred
      end

   start_lookup_class: BASE_CLASS is
         -- The one where the lookup process must start according to the
         -- `result_type', but also according to its `start_position'. The 
         -- `Result' may be Void when this information is too difficult to 
         -- compute, or when there is no need to compute some renaming. 
         -- Hence the Void `Result', for example in class MANIFEST_STRING 
         -- or when the result type is NONE, TUPLE or some agent type.
      deferred
      end

   result_type: E_TYPE is
         -- The `result_type' is available only when the expression has been
         -- checked (see `to_runnable').
      deferred
      ensure
         Result /= Void
      end

   use_current: BOOLEAN is
         -- True if `Current' is used somewhere inside this expression. As 
         -- for `result_type', this information is available only for 
         -- checked expressions.
      require
         smart_eiffel.is_ready
      deferred
      end

   stupid_switch(run_time_set: RUN_TIME_SET): BOOLEAN is
      require
         smart_eiffel.is_ready
         ace.boost
         run_time_set.count > 1
      deferred
      end

   to_runnable(ct: E_TYPE): EXPRESSION is
         -- Gives the corresponding expression checked in the `ct' context
         -- (i.e. when `ct' is the type of `Current').
      require
         ct.run_type = ct
         ct.run_class /= Void
      deferred
      ensure
         nb_errors = 0 implies Result.result_type.is_run_type
      end

   frozen simplify_1: EXPRESSION is
	 -- If it is possible, this `simplify_1_' function returns a simplified 
	 -- version of `Current' or `Current' itself when no simplification is 
	 -- possible. The simplification performed by the `simplify_1_' function 
	 -- is always straightforward and statically obvious. As an example, 
	 -- this function can simplify 3 + 1 into 4. The simplification 
	 -- performed does not depends on `Current' type. As a consequence, 
	 -- this function can be called at any time of the compilation process. 
	 -- (See also `simplify_2'.)
      do
	 if smart_eiffel.short_flag then
	    Result := Current
	 else
	    check not smart_eiffel.pretty_flag end
	    Result := Current.simplify_1_
	    if Result /= Current then
	       smart_eiffel.magic_count_increment
	    end
	 end
      ensure
	 never_void: Result /= Void
	 Result /= Current implies Result = Result.simplify_1_
      end
   
   simplify_1_: EXPRESSION is
	 -- Implementation of `simplify_1' without the need to check
	 -- `smart_eiffel.pretty_flag' or `smart_eiffel.short_flag'.
      require
	 not smart_eiffel.pretty_flag
	 not smart_eiffel.short_flag
      deferred
      ensure
	 never_void: Result /= Void
	 Result /= Current implies Result = Result.simplify_1_
      end
   
   simplify_2: EXPRESSION is
	 -- If it is possible, this `simplify_2' function returns a simplified
	 -- version of `Current' or `Current' itself when no simplification is 
	 -- possible. The simplification performed by the `simplify_2' function 
	 -- occurs at the very last time of the compilation process to complete 
	 -- the work of `simplify_1_'. As an example, this function may simplify 
	 -- an expression like `Current.foo' where foo is a constant feature. 
	 -- This function can only be called at the end of the compilation 
	 -- process, when all the live code is known. (See also `simplify_2'.)
      require
	 not smart_eiffel.pretty_flag
	 not smart_eiffel.short_flag
	 smart_eiffel.status >= 4
      deferred
      ensure
	 Result /= Void
      end

   to_integer_or_error: INTEGER is
	 -- Gives the corresponding INTEGER value or emit the 
	 -- `to_integer_error' for non constant expression.
      deferred
      end

   isa_dca_inline_argument: INTEGER is
         -- Interpretation of the Result:
         --    -1 : yes and no ARGUMENT_NAME used
         --     0 : not inlinable
         --   > 0 : inlinable and ARGUMENT_NAME rank is used.
      require
         ace.boost and smart_eiffel.is_ready
      deferred
      ensure
         Result >= -1
      end

   dca_inline_argument(formal_arg_type: E_TYPE) is
      require
         formal_arg_type /= Void
         isa_dca_inline_argument /= 0
      deferred
      end

   assertion_check(tag: CHARACTER) is
         -- Assume the current code in inside some assertion (a require
         -- clause or some class invariant for example). The `tag' mangling
         -- is:
         --   'R' when we are inside some require clause.
         --   'E' when we are inside some ensure clause.
         --   '_' for all other assertions.
         -- This flag is used to check VAPE and VEEN as well.
      require
         ace.no_check
         ; (once "RE_").has(tag)
      deferred
      end

   verify_scoop(allowed: FORMAL_ARG_LIST): BOOLEAN is
         -- Verify that any separate entity is within the `allowed' list 
         -- (except Current).
         -- True if any separate entity (except Current) is used as target.
      do
      end

   scoop_error is
      do
         error_handler.add_position(start_position)
         error_handler.append(
	    "A separate target must be an argument of the enclosing routine.")
	 error_handler.print_as_fatal_error
      end

   precedence: INTEGER is
	 -- Handling of precedence (priority of expressions).
      deferred
      ensure
         1 <= Result and Result <= atomic_precedence
      end

   frozen base_class_written: BASE_CLASS is
         -- The base class where this expression is written.
      require
	 not start_position.is_unknown
      do
         Result := start_position.base_class
      end

   frozen written_in: CLASS_NAME is
         -- The name of the base class where this expression is written.
      require
	 not start_position.is_unknown
      do
         Result := start_position.base_class_name
      end

   afd_check is
         -- After Falling Down Check.
      deferred
      end

   safety_check is
      require
	 for_boost_mode_only_or_asked_for: ace.boost or else ace.safety_check
         smart_eiffel.status.in_range(3,6)
      deferred
      end

feature -- To produce C code:

   collect_c_tmp is
         -- Traverse the expression to collect extra mandatory C temporary
	 -- variables (for user expanded) just before `compile_to_c'.
      require
         smart_eiffel.is_ready
      deferred
      end

   mapping_c_target(formal_type: E_TYPE) is
         -- Produce C code in order to pass Current expression as the target
         -- of a feature call. When it is needed, C code to check invariant
         -- is automatically added as well as a C cast according to the
         -- destination `formal_type'.
      require
         smart_eiffel.is_ready
	 formal_type.is_static
         formal_type.run_class.at_run_time
	 ace.no_check implies result_type.is_a(formal_type)
      deferred
      end

   mapping_c_arg(formal_type: E_TYPE) is
         -- Produce C code in order to pass Current expression as an
         -- argument of the feature called. Thus, it is the same jobs as 
         -- `mapping_c_target' without the invariant call.
      require
         smart_eiffel.is_ready
      deferred
      end

   compile_to_c is
         -- Produce C code to access the value of the expression: user's
         -- expanded are no longuer pointer.
      require
         smart_eiffel.is_ready
         cpp.on_c
      deferred
      ensure
         cpp.on_c
      end

   c_frame_descriptor(format, locals: STRING) is
	 -- Prepare information for the C frame descriptor.
      require
	 ace.no_check
      deferred
      end

   side_effect_free: BOOLEAN is
         -- True when the evaluation of `Current' has no side effect at all and 
         -- that the evaluation of of `Current' done more than once or not done 
         -- at all without any problem/penalty.
      deferred
      end

   once_pre_computable: BOOLEAN is
         -- Is it possible to use `Current' inside the body of a pre-computed 
         -- once function? 
         -- (Used to decide if some once function is really pre-computable.)
      deferred
      end

feature -- For `compile_to_jvm':

   compile_to_jvm is
         -- Produce Java byte code in order to push expression value on the
         -- jvm stack.
      require
         smart_eiffel.is_ready
      deferred
      end

   compile_target_to_jvm is
         -- Same as `compile_to_jvm', but add class invariant check when 
         -- needed.
      require
         smart_eiffel.is_ready
      deferred
      end

   compile_to_jvm_into(dest: E_TYPE): INTEGER is
         -- Assume `result_type' conforms to `dest'. Produce Java byte code 
         -- in order to convert the expression into `dest' (comparisons = 
         -- and /=, argument passing and assignment). Result gives the space 
         -- in the jvm stack.
         -- *** SHOULD BE REMOVE AS SOON AS IMPLICIT_CAST WILL BE CORRECT ***
      require
         conversion_check(dest,result_type)
      deferred
      ensure
         Result >= 1
      end

   frozen standard_compile_target_to_jvm is
      do
         compile_to_jvm
         result_type.jvm_check_class_invariant
      end

   frozen standard_compile_to_jvm_into(dest: E_TYPE): INTEGER is
      require
         conversion_check(dest,result_type)
      do
         compile_to_jvm
         Result := result_type.run_type.jvm_convert_to(dest)
      ensure
         Result >= 1
      end

   conversion_check(dest, rt: E_TYPE): BOOLEAN is
      do
         Result := True
         if rt.is_a(dest) then
         else
            error_handler.cancel
            if dest.is_a(rt) then
            else
               warning(start_position,
                ". Impossible conversion (EXPRESSION).")
            end
         end
      end

   jvm_branch_if_false: INTEGER is
         -- Gives the `program_counter' to be resolved.
      require
         result_type.is_boolean
      deferred
      end

   jvm_branch_if_true: INTEGER is
         -- Gives the `program_counter' to be resolved.
      require
         result_type.is_boolean
      deferred
      end

   jvm_assign_creation is
         -- Basic assignment using value on top of stack. (Always writes 
         -- reference.)
      require
         is_writable
      deferred
      end

   jvm_assign is
         -- Basic assignment using value on top of stack. (Copies to 
         -- expanded type, else writes reference.)
      require
         is_writable
      deferred
      end

feature -- For `pretty' and `short':

   extra_bracket_flag: BOOLEAN is
	 -- True when we do have to add an extra pair of brackets if the 
	 -- `Current' expression is the target of a call. As an example, this is 
	 -- True for manifest constants or for infix calls. (This feature is 
	 -- used for `pretty' as well as for `short').
      deferred
      end
      
   pretty_print is
         -- For `pretty'. Start the `pretty_print' of `Current'.
      require
         pretty_printer.indent_level >= 1
      deferred
      ensure
         pretty_printer.indent_level = old pretty_printer.indent_level
      end

   print_as_target is
         -- For `pretty'. Print the expression viewed as a target plus the 
         -- corresponding dot when it is necessary.
      deferred
      end

   bracketed_pretty_print is
         -- For `pretty'. Add a bracket pair around `Current' only when it is 
         -- necessary.
      deferred
      end
   
   short is
	 -- For `short'. Start the job for `Current'.
      deferred
      end

   short_target is
         -- For `short'. A target with the following dot if needed.
      deferred
      end

   frozen bracketed_short is
      do
         short_print.hook_or("open_b","(")
         short
         short_print.hook_or("close_b",")")
      end
   
feature {EXPRESSION_VISITOR}

   accept(visitor: EXPRESSION_VISITOR) is
      deferred
      end

feature {NONE}

   standard_mapping_c_target(formal_type: E_TYPE) is
      local
         flag: BOOLEAN; rt: E_TYPE
      do
         flag := cpp.call_invariant_start(formal_type)
         rt := result_type.run_type
         if rt.is_reference then
            if formal_type.is_reference then
               -- Reference into Reference :
               cpp.put_character('(')
	       formal_type.mapping_cast
               compile_to_c
               cpp.put_character(')')
            else
               -- Reference into Expanded :
               compile_to_c
            end
         elseif formal_type.is_reference then
            -- Expanded into Reference :
            compile_to_c
         else
            -- Expanded into Expanded :
            if rt.need_c_struct then
               cpp.put_character('&')
            end
            compile_to_c
         end
         if flag then
            cpp.call_invariant_end
         end
      end

   frozen jvm_standard_branch_if_false: INTEGER is
         -- Gives the `program_counter' to be resolved.
      require
         result_type.is_boolean
      do
         compile_to_jvm
         Result := code_attribute.opcode_ifeq
      end

   frozen jvm_standard_branch_if_true: INTEGER is
         -- Gives the `program_counter' to be resolved.
      require
         result_type.is_boolean
      do
         compile_to_jvm
         Result := code_attribute.opcode_ifne
      end

   frozen to_integer_error is
	 -- The `to_integer_or_error' message.
      do
	 error_handler.append(fz_iinaiv)
	 error_handler.add_position(start_position)
	 error_handler.print_as_error
      end

end -- EXPRESSION
