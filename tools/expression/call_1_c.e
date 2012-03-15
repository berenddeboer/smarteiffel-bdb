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
class CALL_1_C
   --
   -- Other kinds of call with only one argument.
   --

inherit CALL_1

creation make

feature

   side_effect_free: BOOLEAN is False

   extra_bracket_flag: BOOLEAN is False

   result_type: E_TYPE is
      local
         tla: TYPE_LIKE_ARGUMENT
      do
         Result := run_feature.result_type
	 tla ?= Result
	 if tla /= Void then
	    Result := arg1.result_type.run_type
         end
      end

   to_runnable(ct: E_TYPE): EXPRESSION is
      local
	 target_type, argument_type: E_TYPE; type_of_agent: TYPE_OF_AGENT
	 rc: RUN_CLASS; fn: STRING
      do
	 if current_type = Void then
	    current_type := ct
	    runnable_target(ct)
	    target_type := target.result_type
	    type_of_agent ?= target_type.run_type
	    if type_of_agent /= Void then
	       rc := type_of_agent.run_class
	       run_feature := rc.agent_feature_for(type_of_agent, feature_name)
	       arguments := arguments.tuple_substitution
	       arguments := runnable_arguments(ct)
	    else
	       arguments := runnable_arguments(ct)
	       argument_type := arg1.result_type
	       target := basic_conversion(target, target_type, argument_type)
	       run_feature_for(ct)
	    end
	    debug debug_info_update end
	    if type_of_agent /= Void then
	       fn := feature_name.to_string
	       if fn /= as_item then
		  error_handler.append(
		     "You must use %"item%" to get the result of the %
		     %execution of an agent.")
		  if fn = as_call then
		     error_handler.append(
		        " (Just replace %"call%" with %"item%".)")
		  end
		  error_handler.add_position(feature_name.start_position)
		  error_handler.print_as_fatal_error
	       end
	       create {AGENT_EXPRESSION} Result.make(Current)
	    else
	       run_feature_match
	       Result := Current
	    end
         else
            create {CALL_1_C} Result.make(target, feature_name, arguments)
	    Result := Result.to_runnable(ct)
         end
      end

   simplify_1_: like Current is
      do
	 Result := Current
      end
   
   simplify_2: EXPRESSION is
      local
	 run_time_set: RUN_TIME_SET; rf: RUN_FEATURE
      do
	 target := target.simplify_2
	 arguments.simplify_2
	 if ace.no_check then
	    -- Do nothing in order to track Void target as well.
	    Result := Current
	 elseif as_same_dynamic_type = feature_name.to_string then
	    if (target.result_type.is_expanded
		and then
		target.side_effect_free
		and then
		arg1.side_effect_free)
	     then
	       create {E_TRUE} Result.make(feature_name.start_position)
	    else
	       run_time_set := run_feature.run_class.run_time_set
	       if (run_time_set.count = 1
		   and then
		   target.side_effect_free
		   and then
		   arg1.side_effect_free
		   and then
		   run_feature.base_feature.base_class_name.to_string = as_general
		   )
		then
		  create {E_TRUE} Result.make(feature_name.start_position)
	       else
		  Result := Current
	       end
	    end
	 elseif target.is_current then
	    if arg1.side_effect_free then
	       Result := current_or_result_of(run_feature)
	    else
	       Result := Current
	    end
	 elseif run_feature.run_class.run_time_set.count = 1 then
	    if target.side_effect_free and then arg1.side_effect_free then
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
   
   assertion_check(tag: CHARACTER) is
      do
         if tag = 'R' then
            run_feature.vape_check_from(start_position)
         end
         target.assertion_check(tag)
         arg1.assertion_check(tag)
      end

   precedence: INTEGER is
      do
         Result := dot_precedence
      end

   compile_to_c is
      do
         call_proc_call_c2c
      end

   short is
      do
         target.short_target
         run_feature.name.short
         arg1.bracketed_short
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
         pretty_printer.put_character('(')
         arg1.pretty_print
         pretty_printer.put_character(')')
      end

   isa_dca_inline_argument: INTEGER is
      do
      end

   dca_inline_argument(formal_arg_type: E_TYPE) is
      do
      end

   compile_to_jvm is
      do
         call_proc_call_c2jvm
      end

   jvm_branch_if_false: INTEGER is
      do
         Result := jvm_standard_branch_if_false
      end

   jvm_branch_if_true: INTEGER is
      do
         Result := jvm_standard_branch_if_true
      end

feature {RUN_FEATURE_3,RUN_FEATURE_4}

   finalize is
      local
         rc: RUN_CLASS; rf: RUN_FEATURE
      do
         rf := run_feature
         rc := rf.run_class
         run_feature := rc.run_time_set.first.dynamic(rf)
      end

feature {CALL_1_C_VISITOR}

   accept(visitor: CALL_1_C_VISITOR) is
      do
         visitor.visit_call_1_c(Current)
      end

feature {NONE}

   make(t: like target; fn: like feature_name; a: like arguments) is
      require
         t /= Void
         fn /= Void
         a.count = 1
      do
         target := t
         feature_name := fn
         arguments := a
      ensure
         target = t
         feature_name = fn
         arguments = a
      end

   afd_check_hook is
      do
      end

end -- CALL_1_C
