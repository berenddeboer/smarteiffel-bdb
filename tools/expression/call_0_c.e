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
class CALL_0_C
   --
   -- Other calls without argument.
   --

inherit CALL_0

creation make

feature

   extra_bracket_flag: BOOLEAN is False

   side_effect_free: BOOLEAN is
      local
	 rf: RUN_FEATURE; run_time_set: RUN_TIME_SET
      do
	 if target.side_effect_free then
	    if smart_eiffel.status >= 4 then
	       rf := run_feature
	       run_time_set := rf.run_class.run_time_set
	       if run_time_set.count = 1 then
		  rf := run_time_set.first.dynamic(rf)
		  Result := rf.side_effect_free
	       end
	    end
	 end
      end

   precedence: INTEGER is
      do
         Result := dot_precedence
      end

   to_runnable(ct: E_TYPE): like Current is
      do
	 if current_type = Void then
	    current_type := ct
	    runnable_target(ct)
	    run_feature_for(ct)
	    Result := Current
	    debug debug_info_update end
	    run_feature_match
	 else
	    create {CALL_0_C} Result.make(target,feature_name)
	    Result := Result.to_runnable(ct)
	 end
      end

   simplify_1_: like Current is
      do
	 Result := Current
      end
   
   simplify_2: EXPRESSION is
      local
         name: STRING; type_bit: TYPE_BIT run_time_set: RUN_TIME_SET
	 ic: INTEGER_CONSTANT; target_type: E_TYPE; sp: POSITION
	 rf: RUN_FEATURE
      do
	 target := target.simplify_2
	 target_type := target.result_type.run_type
	 name := run_feature.name.to_string
	 if as_is_expanded_type = name then
	    if target_type.is_expanded then
	       create {E_TRUE} Result.make(feature_name.start_position)
	    else
	       create {E_FALSE} Result.make(feature_name.start_position)
	    end
	    if not target.side_effect_free then
	       error_handler.append("Must use {GENERAL}.is_expanded_type %
                 %with such a target expression (keep in mind that %
		 %the target is not evaluated).")
	       error_handler.add_position(target.start_position)
	       error_handler.print_as_fatal_error
	    end
	 elseif as_is_basic_expanded_type = name then
	    if target_type.is_basic_eiffel_expanded then
	       create {E_TRUE} Result.make(feature_name.start_position)
	    else
	       create {E_FALSE} Result.make(feature_name.start_position)
	    end
	    if not target.side_effect_free then
	       error_handler.append("Must use {GENERAL}.is_basic_expanded_type %
                 %with such a target expression (keep in mind that %
		 %the target is not evaluated).")
	       error_handler.add_position(target.start_position)
	       error_handler.print_as_fatal_error
	    end
	 elseif as_is_default = name then
	    sp := feature_name.start_position
	    if target_type.is_integer then
	       create ic.make(0, sp)
	       create {CALL_INFIX_EQ} Result.make(target, sp, ic)
	       Result := Result.simplify_2
	    elseif target_type.is_real or else target_type.is_double then
	       create {REAL_CONSTANT} Result.make(sp, once "0.0")
	       create {CALL_INFIX_EQ} Result.make(target, sp, Result)
	       Result := Result.simplify_2
	    elseif target_type.is_boolean then
	       create {E_FALSE} Result.make(sp)
	       create {CALL_INFIX_EQ} Result.make(target, sp, Result)
	       Result := Result.simplify_2
	    elseif target_type.is_character then
	       create {CHARACTER_CONSTANT} Result.with(sp, '%U')
	       create {CALL_INFIX_EQ} Result.make(target, sp, Result)
	       Result := Result.simplify_2
	    elseif target_type.is_dummy_expanded then
	       create {E_TRUE} Result.make(sp)
	    elseif target_type.is_type_of_agent then
	       create {E_TRUE} Result.make(sp)
	    else
	       Result := Current
	    end
	 elseif as_count = name and then target_type.is_bit then
	    type_bit ?= target_type
	    sp := feature_name.start_position
	    create {INTEGER_CONSTANT} Result.make(type_bit.nb, sp)
	 end
	 if Result /= Void then
	 elseif ace.no_check then
	    -- Do nothing in order to track Void target as well.
	    Result := Current
	 elseif target.is_current then
	    Result := current_or_result_of(run_feature)
	 elseif target.is_manifest_string then
	    Result := current_or_result_of(run_feature)
	 elseif run_feature.run_class.run_time_set.count = 1 then
	    if target.side_effect_free then
	       run_time_set := run_feature.run_class.run_time_set
	       rf := run_time_set.first.dynamic(run_feature)
	       Result := current_or_result_of(rf)
	    else
	       Result := Current
	    end
	 else
	    Result := Current
	 end
      end

   short is
      do
         target.short_target
         run_feature.name.short
      end

   short_target is
      do
         short
         short_print.a_dot
      end

   bracketed_pretty_print, pretty_print is
      do
         target.print_as_target
         pretty_printer.put_string(feature_name.to_string)
      end

   compile_to_c is
      local
         n: STRING
      do
         n := feature_name.to_string
         if as_is_expanded_type = n then
            if target.result_type.run_type.is_expanded then
               cpp.put_character('1')
            else
               cpp.put_character('0')
            end
         elseif as_is_basic_expanded_type = n then
            if target.result_type.is_basic_eiffel_expanded then
               cpp.put_character('1')
            else
               cpp.put_character('0')
            end
         else
            call_proc_call_c2c
         end
      end

   isa_dca_inline_argument: INTEGER is
      do
      end

   dca_inline_argument(formal_arg_type: E_TYPE) is
      do
      end

   compile_to_jvm is
      local
         n: STRING
      do
         n := feature_name.to_string
         if as_is_expanded_type = n then
            if target.result_type.is_expanded then
               code_attribute.opcode_iconst_1
            else
               code_attribute.opcode_iconst_0
            end
         elseif as_is_basic_expanded_type = n then
            if target.result_type.is_basic_eiffel_expanded then
               code_attribute.opcode_iconst_1
            else
               code_attribute.opcode_iconst_0
            end
         else
            call_proc_call_c2jvm
         end
      end

   jvm_branch_if_false: INTEGER is
      do
         Result := jvm_standard_branch_if_false
      end

   jvm_branch_if_true: INTEGER is
      do
         Result := jvm_standard_branch_if_true
      end

feature {CALL_0_C_VISITOR}

   accept(visitor: CALL_0_C_VISITOR) is
      do
         visitor.visit_call_0_c(Current)
      end

feature {NONE}

   make(t: like target; fn: like feature_name) is
      require
         t /= Void
         fn /= Void
      do
         target := t
         feature_name := fn
      ensure
         target = t
         feature_name = fn
      end

end -- CALL_0_C

