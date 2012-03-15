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
class PROC_CALL_1
   --
   -- For a procedure call with only one argument.
   --

inherit PROC_CALL redefine use_current end

creation make

feature

   arguments: EFFECTIVE_ARG_LIST

   arg_count: INTEGER is 1

   arg1: EXPRESSION is
      do
         Result := arguments.first
      end

   to_runnable(ct: E_TYPE): INSTRUCTION is
      local
	 type_of_agent: TYPE_OF_AGENT; rc: RUN_CLASS
      do
	 if current_type = Void then
	    current_type := ct
	    runnable_target(ct)
	    type_of_agent ?= target.result_type.run_type
	    if type_of_agent /= Void then
	       rc := type_of_agent.run_class
	       run_feature := rc.agent_feature_for(type_of_agent, feature_name)
	       arguments := arguments.tuple_substitution
	    else
	       run_feature_for(ct)
	    end
	    arguments := runnable_arguments(ct)
	    debug debug_info_update end
	    if type_of_agent /= Void then
	       create {AGENT_INSTRUCTION} Result.make(Current)
	    else
	       run_feature_match
	       Result := set_item_special
	    end
	 else
	    create {PROC_CALL_1} Result.make(target,feature_name,arguments)
	    Result := Result.to_runnable(ct)
	 end
      end

   simplify_2(container: COMPOUND; index: INTEGER) is
      local
	 rf: RUN_FEATURE; run_time_set: RUN_TIME_SET
      do
	 if ace.no_check then
	    -- Do nothing in order to track Void target as well.
	 elseif target.side_effect_free and then arg1.side_effect_free then
	    if smart_eiffel.status >= 4 then
	       rf := run_feature
	       run_time_set := rf.run_class.run_time_set
	       if run_time_set.count = 1 then
		  rf := run_time_set.first.dynamic(rf)
		  if rf.side_effect_free then
		     container.remove(index)
		  end
	       end
	    end
	 end
      end
   
   compile_to_jvm is
      do
         if as_c_inline_c = feature_name.to_string then
            error_handler.add_position(start_position)
            fatal_error(
               "Cannot use %"c_inline_c%" to produce Java byte code.")
         else
            call_proc_call_c2jvm
         end
      end

   use_current: BOOLEAN is
      local
         ms: MANIFEST_STRING
         s: STRING
      do
         if as_c_inline_c = feature_name.to_string then
            ms ?= arg1
            if ms /= Void then
               s := ms.to_string
               Result := s.has('C')
            end
         else
            Result := standard_use_current
         end
      end

   pretty_print is
      do
         target.print_as_target
         pretty_printer.put_string(feature_name.to_string)
         pretty_printer.put_character('(')
         arg1.pretty_print
         pretty_printer.put_character(')')
         if pretty_printer.semi_colon_flag then
            pretty_printer.put_character(';')
         end
      end

feature {CREATE_TOOLS, PROC_CALL}

   runnable_create(ct: E_TYPE; w: like target; a: like arguments
		   rf: RUN_FEATURE): like Current is
      do
	 if current_type = Void then
	    current_type := ct
            target := w
            arguments := a
            run_feature := rf
            Result := Current
	    debug debug_info_update end
         else
            create Result.make(target,feature_name,arguments)
            Result := Result.runnable_create(ct,w,a,rf)
         end
      end

feature {PROC_CALL_1_VISITOR}

   accept(visitor: PROC_CALL_1_VISITOR) is
      do
         visitor.visit_proc_call_1(Current)
      end

feature {NONE}

   make(t: like target; fn: like feature_name; a: like arguments) is
      require
         t /= Void
         fn /= Void
         a /= Void
      do
         target := t
         feature_name := fn
         arguments := a
      ensure
         target = t
         feature_name = fn
         arguments = a
      end

   run_feature_match is
      do
         run_feature_has_no_result
	 smart_eiffel.argument_passing_check(feature_name.start_position,
					     arguments,run_feature)
      end

   set_item_special: INSTRUCTION is
	 -- Replace `set_item' valid calls by a simple assignment.
      local
	 rf: RUN_FEATURE; rf3: RUN_FEATURE_3
      do
	 rf := run_feature
	 if rf.current_type.is_basic_eiffel_expanded and then
	    rf.name.to_string = as_set_item
	  then -- The special case of `set_item' on basic expanded.
	    if not target.is_writable then
	       error_handler.add_position(target.start_position)
	       error_handler.append("Cannot apply `set_item' on this %
                                    %non-writable entity.")
	       error_handler.print_as_fatal_error
	    end
	    -- `Current' is magically replaced with an assignment:
	    create {ASSIGNMENT} Result.make(target, arg1)
	    -- To avoid wrong code generation:
	    rf3 ?= rf
	    rf3.no_definition
	 else
	    Result := Current
	 end
      end
   
invariant

   arguments.count = 1

end -- PROC_CALL_1

