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
class CALL_N
   --
   -- For calls with more than one argument : "bar.foo(...)".
   -- For other calls, use CALL_0 or CALL_1.
   --

inherit CALL

creation make

feature

   side_effect_free: BOOLEAN is False

   extra_bracket_flag: BOOLEAN is False
   
   arguments: EFFECTIVE_ARG_LIST

   to_integer_or_error: INTEGER is
      do
	 to_integer_error
      end

   result_type: E_TYPE is
      local
         tla: TYPE_LIKE_ARGUMENT;  e: EXPRESSION
      do
         Result := run_feature.result_type
	 tla ?= Result
	 if tla /= Void then
	    e := arguments.expression(tla.rank)
	    Result := e.result_type.run_type
         end
      end

   precedence: INTEGER is
      do
         Result := dot_precedence
      end

   compile_to_c is
      do
         call_proc_call_c2c
      end

   isa_dca_inline_argument: INTEGER is
      do
      end

   dca_inline_argument(formal_arg_type: E_TYPE) is
      do
      end

   arg_count: INTEGER is
      do
         Result := arguments.count
      end

   to_runnable(ct: E_TYPE): like Current is
      do
	 if current_type = Void then
	    current_type := ct
	    runnable_target(ct)
	    arguments := runnable_arguments(ct)
	    run_feature_for(ct)
	    Result := Current
	    debug debug_info_update end
	    run_feature_match
	 else
	    create Result.make(target,feature_name,arguments)
	    Result := Result.to_runnable(ct)
	 end
      end

   simplify_1_: like Current is
      do
	 Result := Current
      end
   
   simplify_2: EXPRESSION is
      local
	 rf: RUN_FEATURE; run_time_set: RUN_TIME_SET
      do
	 if target.is_current then
	    if arguments.side_effect_free then
	       Result := current_or_result_of(run_feature)
	    else
	       Result := Current
	    end
	 elseif run_feature.run_class.run_time_set.count = 1 then
	    if target.side_effect_free and then arguments.side_effect_free then
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
   
   bracketed_pretty_print, pretty_print is
      do
         target.print_as_target
         pretty_printer.put_string(feature_name.to_string)
         pretty_printer.indent_level_increment
         arguments.pretty_print
         pretty_printer.indent_level_decrement
      end

   short is
      do
         target.short_target
         run_feature.name.short
         arguments.short
      end

   short_target is
      do
         short
         short_print.a_dot
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

   assertion_check(tag: CHARACTER) is
      do
         if tag = 'R' then
            run_feature.vape_check_from(start_position)
         end
         target.assertion_check(tag)
         arguments.assertion_check(tag)
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

feature {CALL_N_VISITOR}

   accept(visitor: CALL_N_VISITOR) is
      do
         visitor.visit_call_n(Current)
      end

feature {NONE}

   make(t: like target; sn: like feature_name; a: like arguments) is
      require
         t /= Void
         sn /= Void
         a.count > 1
      do
         target := t
         feature_name := sn
         arguments := a
      ensure
         target = t
         feature_name = sn
         arguments = a
      end

   run_feature_match is
      do
         run_feature_has_result
	 smart_eiffel.argument_passing_check(feature_name.start_position,
					     arguments,run_feature)
      end

   afd_check_hook is
      do
      end

invariant

   arguments.count > 1

end -- CALL_N

