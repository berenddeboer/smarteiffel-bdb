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
class PROC_CALL_N
   --
   -- For a procedure call with more than one argument.
   --

inherit PROC_CALL

creation make

feature

   arguments: EFFECTIVE_ARG_LIST

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
            create Result.make(target, feature_name, arguments)
	    Result := Result.to_runnable(ct)
         end
      end

   simplify_2(container: COMPOUND; index: INTEGER) is
      local
	 rf: RUN_FEATURE; run_time_set: RUN_TIME_SET
      do
	 if ace.no_check then
	    -- Do nothing in order to track Void target as well.
	 elseif target.side_effect_free and then arguments.side_effect_free then
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
   
   arg_count: INTEGER is
      do
         Result := arguments.count
      end

   pretty_print is
      do
         target.print_as_target
         pretty_printer.put_string(feature_name.to_string)
         pretty_printer.indent_level_increment
         arguments.pretty_print
         pretty_printer.indent_level_decrement
         if pretty_printer.semi_colon_flag then
            pretty_printer.put_character(';')
         end
      end

   compile_to_jvm is
      do
         call_proc_call_c2jvm
      end

feature {CREATE_TOOLS,PROC_CALL}

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

feature {PROC_CALL_N_VISITOR}

   accept(visitor: PROC_CALL_N_VISITOR) is
      do
         visitor.visit_proc_call_n(Current)
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
         run_feature_has_no_result
	 smart_eiffel.argument_passing_check(feature_name.start_position,
					     arguments,run_feature)
      end

invariant

   arguments.count > 1

end -- PROC_CALL_N

