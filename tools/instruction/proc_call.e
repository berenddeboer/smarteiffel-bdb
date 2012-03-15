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
deferred class PROC_CALL
   --
   -- For all sort of procedure calls.
   -- Does not include function calls (see CALL).
   --
   -- Classification: E_PROC_0 when 0 argument, PROC_CALL_1 when
   -- 1 argument and PROC_CALL_N when N arguments.
   --

inherit CALL_PROC_CALL; INSTRUCTION redefine stupid_switch end

feature

   end_mark_comment: BOOLEAN is False

   frozen once_pre_computable: BOOLEAN is
      do
	 if target.once_pre_computable then
	    if arguments /= Void then
	       Result := arguments.once_pre_computable
	    else
	       Result := True
	    end
	 end
      end

   frozen side_effect_free: BOOLEAN is
      local
	 rf: RUN_FEATURE; run_time_set: RUN_TIME_SET
      do
	 if ace.boost and then smart_eiffel.status >= 4 then
	    run_time_set := run_feature.run_class.run_time_set
	    if run_time_set.count = 1 then
	       if target.side_effect_free then
		  if arguments = Void or else arguments.side_effect_free then
		     rf := run_time_set.first.dynamic(run_feature)
		     Result := rf.side_effect_free
		  end
	       end
	    end
	 end
      end
      
   frozen stupid_switch(run_time_set: RUN_TIME_SET): BOOLEAN is
      do
         Result := call_proc_call_stupid_switch(run_time_set)
      end

   frozen compile_to_c is
      do
	 if ace.no_check then
	    cpp.put_trace_or_sedb_instruction(start_position)
	 end
         call_proc_call_c2c
      end

   frozen short is
      do
         run_feature.name.short
         arguments.short
      end

feature {COMPOUND,INSTRUCTION_WITH_COMMENT}

   verify_scoop(allowed: FORMAL_ARG_LIST) is
      local
         dummy: BOOLEAN
      do
         if not target.is_current and then target.result_type.is_separate then
            if allowed /= Void then
               dummy := allowed.verify_scoop(target)
            else
               target.scoop_error
            end
         end
      end

feature {RUN_FEATURE_3,RUN_FEATURE_4}

   finalize is
      local
         rc: RUN_CLASS; rf: RUN_FEATURE
      do
         rf := run_feature
         rc := rf.current_type.run_class
         run_feature := rc.run_time_set.first.dynamic(rf)
      end

feature {CREATE_TOOLS,PROC_CALL}

   runnable_create(ct: E_TYPE; w: like target; a: like arguments
		   rf: RUN_FEATURE): like Current is
	 -- When the `Current' call is part of some create expression
	 -- or instruction. (The lookup is alreday done and arguments
	 -- are already runnable.)
      require
	 ct /= Void; rf /= Void
      deferred
      ensure
	 Result.current_type = ct
	 Result.target = w
	 Result.arguments = a
	 Result.run_feature = rf
      end

feature {PROC_CALL_VISITOR}

   accept(visitor: PROC_CALL_VISITOR) is
      deferred
      end

feature {NONE}

   frozen afd_check_hook is
      do
      end

   frozen run_feature_has_no_result is
      do
         if run_feature.result_type /= Void then
            error_handler.add_position(run_feature.start_position)
            error_handler.add_position(feature_name.start_position)
            fatal_error("Feature found is not a procedure.")
         end
      end

end -- PROC_CALL

