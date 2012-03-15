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
deferred class CALL_INFIX1
   --
   -- Root for of all infix call but CALL_INFIX_EQ and CALL_INFIX_NEQ.
   --

inherit CALL_INFIX

feature

   side_effect_free: BOOLEAN is False
   
   frozen to_runnable(ct: E_TYPE): EXPRESSION is
      local
         argument_type, target_type: E_TYPE
         copied: like Current
      do
	 if current_type = Void then
	    current_type := ct
	    runnable_target(ct)
	    arguments := runnable_arguments(ct)
	    target_type := target.result_type
	    argument_type := arg1.result_type
	    target := basic_conversion(target, target_type, argument_type)
	    run_feature_for(ct)
	    Result := Current.simplify_1
	    debug debug_info_update end
	    run_feature_match
	 else
	    copied := twin
	    copied.with (target,feature_name,arguments)
	    Result := copied.to_runnable(ct)
	 end
      end

   frozen result_type: E_TYPE is
      local
         tla: TYPE_LIKE_ARGUMENT
      do
         Result := run_feature.result_type
	 tla ?= Result
	 if tla /= Void then
	    Result := arg1.result_type.run_type
	 end
      end

   frozen assertion_check(tag: CHARACTER) is
      do
         if tag = 'R' then
            run_feature.vape_check_from(start_position)
         end
         target.assertion_check(tag)
         arg1.assertion_check(tag)
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

feature {CALL_INFIX1_VISITOR}

   accept(visitor: CALL_INFIX1_VISITOR) is
      deferred
      end

feature {CALL_INFIX1}

   frozen with(t: like target; fn: like feature_name; a: like arguments) is
      require
         t /= Void
         fn /= Void
         a.count = 1
      do
         run_feature := Void
         current_type := Void
         target := t
         feature_name := fn
         arguments := a
      ensure
         target = t
         feature_name = fn
         arguments = a
      end

   frozen afd_check_hook is
      do
      end

end -- CALL_INFIX1

