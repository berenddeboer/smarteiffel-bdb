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
deferred class CALL_0
   --
   -- For calls without argument (only Current).
   --

inherit
   CALL
      redefine current_or_result_of
      end
   
feature

   arg_count: INTEGER is 0

   frozen arguments: EFFECTIVE_ARG_LIST is
      do
      end

   frozen result_type: E_TYPE is
      do
         Result := run_feature.result_type
      end

   frozen to_integer_or_error: INTEGER is
      local
         rf1: RUN_FEATURE_1
      do
         rf1 ?= run_feature
         if rf1 = Void then
            to_integer_error
         else
            Result := rf1.value.to_integer_or_error
         end
      end

   frozen assertion_check(tag: CHARACTER) is
      do
         if tag = 'R' then
            run_feature.vape_check_from(start_position)
         end
         target.assertion_check(tag)
      end

   frozen run_feature_match is
      do
         run_feature_has_result
	 smart_eiffel.argument_passing_check(feature_name.start_position,
					     Void,run_feature)
      end

feature {CALL_0_VISITOR}

   accept(visitor: CALL_0_VISITOR) is
      deferred
      end

feature {RUN_FEATURE_3,RUN_FEATURE_4}

   frozen finalize is
      local
         rc: RUN_CLASS; rf: RUN_FEATURE
      do
         rf := run_feature
         rc := rf.run_class
         run_feature := rc.run_time_set.first.dynamic(rf)
      end

feature {NONE}

   current_or_result_of(rf: RUN_FEATURE): EXPRESSION is
      local
	 rf1: RUN_FEATURE_1
      do
	 Result := Precursor(rf)
	 if Result = Current then
	    rf1 ?= rf
	    if rf1 /= Void then
	       Result := rf1.value
	    end
	 end
      end
   
   frozen afd_check_hook is
      do
      end

end -- CALL_0
