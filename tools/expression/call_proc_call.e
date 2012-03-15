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
deferred class CALL_PROC_CALL
   --
   -- Common root for CALL and PROC_CALL.
   --

inherit GLOBALS

feature

   target: EXPRESSION
	 -- Target of the call.

   feature_name: FEATURE_NAME
	 -- Written selector name of the call.

   run_feature: RUN_FEATURE
	 -- Non void when runnable and if any `run_feature' exists.

   arguments: EFFECTIVE_ARG_LIST is
	 -- Arguments of the call if any.
      deferred
      ensure
	 Result = Void or else Result.count > 0
      end

   arg_count: INTEGER is
	 -- The `arguments' count or 0.
      deferred
      ensure
	 Result >= 0
      end

   frozen collect_c_tmp is
      do
	 if run_feature /= Void then
	    run_feature.collect_c_tmp
	 end
	 target.collect_c_tmp
	 if arguments /= Void then
	    arguments.collect_c_tmp
	 end
      end

   frozen start_position: POSITION is
      do
	 Result := feature_name.start_position
      end

   use_current, frozen standard_use_current: BOOLEAN is
      do
	 if arg_count > 0 then
	    Result := arguments.use_current
	 end
	 if Result then
	 elseif target.is_current then
	    if smart_eiffel.top_rf /= run_feature then
	       Result := run_feature.use_current
	    end
	 else
	    Result := target.use_current
	 end
      end

   frozen afd_check is
      local
	 trt: E_TYPE; rc: RUN_CLASS; run_time_set: RUN_TIME_SET
      do
	 if run_feature /= Void then
	    trt := target.result_type
	    rc := trt.run_class
	    run_time_set := rc.run_time_set
	    if run_time_set.count > 1 then
	       switch_collection.update(target,run_feature)
	    end
	 end
	 target.afd_check
	 if arg_count > 0 then
	    arguments.afd_check
	 end
	 afd_check_hook
      end

   frozen safety_check is
      local
	 run_time_set: RUN_TIME_SET
      do
	 if run_feature /= Void then
	    if arguments /= Void then
	       run_time_set := run_feature.run_class.run_time_set
	       if run_time_set.count >= 1 then
		  smart_eiffel.covariance_check(start_position,
						run_feature,
						run_time_set)
	       end
	    end
	 end
	 target.safety_check
	 if arguments /= Void then
	    arguments.safety_check
	 end
      end

feature {CALL_PROC_CALL}

   current_type: E_TYPE
	 -- Non Void when runnable and checked in `ct' context.

   debug_info: STRING
	 -- For debug only.

   debug_info_update is
      local
	 i: INTEGER; e: EXPRESSION; t: E_TYPE; sp: POSITION
      do
	 check debug_info = Void end
	 create debug_info.make(32)
	 sp := start_position
	 if not sp.is_unknown then
	    sp.line.append_in(debug_info)
	    debug_info.extend('/')
	    sp.column.append_in(debug_info)
	    debug_info.extend('/')
	    debug_info.append(sp.path)
	 end
	 debug_info.append(" ct:")
	 current_type.debug_info_in(debug_info)
	 debug_info.extend(' ')
	 debug_info.extend('{')
	 target.result_type.debug_info_in(debug_info)
	 debug_info.extend('}')
	 debug_info.extend('.')
	 debug_info.append(feature_name.to_string)
	 if arguments /= Void then
	    debug_info.extend('(')
	    from
	       i := 1
	    until
	       i > arguments.count
	    loop
	       e := arguments.expression(i)
	       t := e.result_type
	       t.debug_info_in(debug_info)
	       i := i + 1
	       if i <= arguments.count then debug_info.extend(',') end
	    end
	    debug_info.extend(')')
	 end
	 if run_feature /= Void then
	    debug_info.append(" rf: ")
	    run_feature.debug_info_in(debug_info)
	 end
      end

feature {RUN_FEATURE_3, RUN_FEATURE_4}

   finalize is
	 -- For inlining of direct calls on an attribute.
      require
	 ace.boost
	 smart_eiffel.is_ready
	 run_feature.run_class.run_time_set.count = 1
      deferred
      ensure
	 run_feature.run_class.at_run_time
      end

feature {CALL_PROC_CALL_VISITOR}

   accept(visitor: CALL_PROC_CALL_VISITOR) is
      deferred
      end

feature {NONE}

   afd_check_hook is
      deferred
      end
   
   frozen call_proc_call_c2c is
      do
	 cpp.put_cpc(Current)
      end

   frozen call_proc_call_c2jvm is
      do
	 jvm.call_proc_call_mapping(Current)
      end

   frozen runnable_target(ct: E_TYPE) is
      require
	 ct.run_type = ct
      local
	 t: like target
      do
	 t := target.to_runnable(ct)
	 if t = Void then
	    error_handler.add_position(target.start_position)
	    error_handler.append("Bad target.")
	    error_handler.add_context_info(ct)
	    error_handler.print_as_fatal_error
	 end
	 target := t
      end

   frozen runnable_arguments(ct: E_TYPE): like arguments is
      require
	 ct.run_type = ct
      do
	 Result := arguments.to_runnable(ct)
	 if Result = Void then
	    error_handler.add_position(arguments.start_position)
	    error_handler.append(fz_bad_argument)
	    error_handler.add_context_info(ct)
	    error_handler.print_as_fatal_error
	 end
      end

   frozen run_feature_for(ct: E_TYPE) is
      require
	 ct.run_type = ct
      local
	 rf: RUN_FEATURE; rc: RUN_CLASS; rt: E_TYPE; bc: BASE_CLASS
      do
	 rt := target.result_type
	 if rt /= Void then
	    rc := rt.run_class
	    if rc /= Void then
	       bc := rc.base_class
	       rf := bc.run_feature_for(rc, target, feature_name, ct)
	    end
	 end
	 if rf = Void then
	    error_handler.add_position(feature_name.start_position)
	    error_handler.append("Bad target for this call.")
	    error_handler.add_context_info(ct)
	    error_handler.print_as_fatal_error
	 end
	 run_feature := rf
      end

   frozen call_proc_call_stupid_switch(run_time_set: RUN_TIME_SET): BOOLEAN is
      local
	 tr: RUN_TIME_SET
      do
	 if arguments = Void then
	    Result := True
	 else
	    Result := arguments.stupid_switch(run_time_set)
	 end
	 if Result then
	    if run_feature = Void then
	       check -- CALL_INFIX2:
		  feature_name.to_string = as_eq
		     or else
		  feature_name.to_string = as_neq
	       end
	    elseif target.is_current then
	       if smart_eiffel.same_base_feature(run_feature,run_time_set) then
		  Result := run_feature.stupid_switch(run_time_set) /= Void
	       else
		  Result := False
	       end
	    else
	       Result := target.stupid_switch(run_time_set)
	       if Result then
		  if run_feature /= Void then
		     tr := run_feature.current_type.run_class.run_time_set
		     if tr.count > 1 then
			Result := smart_eiffel.same_base_feature(run_feature,
								 tr)
		     end
		  end
	       end
	    end
	 end
      end

invariant

   target /= Void

   feature_name /= Void

end -- CALL_PROC_CALL
