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
deferred class CALL
   --
   -- For all sort of feature calls with result value.
   -- So it does not include procedure calls (see PROC_CALL).
   --
   -- Classification: CALL_0 when 0 argument, CALL_1 when
   -- 1 argument and CALL_N when N arguments.
   --

inherit
   CALL_PROC_CALL
   EXPRESSION redefine verify_scoop end

feature

   is_writable: BOOLEAN is False

   is_current: BOOLEAN is False

   is_manifest_string: BOOLEAN is False

   is_result: BOOLEAN is False

   is_void: BOOLEAN is False

   is_static: BOOLEAN is False

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


   start_lookup_class: BASE_CLASS is
      local
         bc: BASE_CLASS; e_feature: E_FEATURE; rt: E_TYPE
      do
         bc := target.start_lookup_class
         if bc /= Void then
            e_feature := bc.e_feature(feature_name)
            if e_feature /= Void then
               rt := e_feature.result_type
               if rt /= Void then
		  Result := rt.start_lookup_class
               end
            end
         end
      end

   frozen mapping_c_target(formal_type: E_TYPE) is
      local
         flag: BOOLEAN; actual_type: like result_type
      do
         flag := cpp.call_invariant_start(formal_type)
         actual_type := result_type.run_type
         if actual_type.is_reference then
            if formal_type.is_reference then
               -- Reference into Reference:
               formal_type.mapping_cast
               cpp.put_character('(')
               compile_to_c
               cpp.put_character(')')
            else
               -- Reference into Expanded:
               compile_to_c
            end
         else
            if formal_type.is_reference then
               -- Expanded into Reference:
               compile_to_c
            else
               -- Expanded into Expanded:
               if formal_type.need_c_struct then
                  cpp.put_character('&')
                  cpp.put_character('(')
                  compile_to_c
                  cpp.put_character(')')
               else
                  compile_to_c
               end
            end
         end
         if flag then
            cpp.call_invariant_end
         end
      end

   frozen mapping_c_arg(formal_arg_type: E_TYPE) is
      do
         compile_to_c
      end

   frozen c_frame_descriptor(format, locals: STRING) is
      do
         target.c_frame_descriptor(format, locals)
         if arg_count > 0 then
            arguments.c_frame_descriptor(format, locals)
         end
      end

   print_as_target is
      do
         pretty_print
         pretty_printer.put_character('.')
      end

   frozen compile_target_to_jvm is
      do
         standard_compile_target_to_jvm
      end

   frozen compile_to_jvm_into(dest: E_TYPE): INTEGER is
      do
         Result := standard_compile_to_jvm_into(dest)
      end

   frozen jvm_assign_creation, jvm_assign is
      do
      end

   frozen stupid_switch(run_time_set: RUN_TIME_SET): BOOLEAN is
      do
         Result := call_proc_call_stupid_switch(run_time_set)
         if Result then
            Result := not result_type.run_type.is_native_array
         end
      end

   verify_scoop(allowed: FORMAL_ARG_LIST): BOOLEAN is
      do
         Result := target.result_type.is_separate
         Result := target.verify_scoop(allowed) or else Result
         if allowed /= Void then
            if allowed.verify_scoop(target) then
               Result := true
            end
         elseif target.result_type.is_separate and then
	    not target.is_current
	  then
            target.scoop_error
         end
      end

feature {CALL_VISITOR}

   accept(visitor: CALL_VISITOR) is
      deferred
      end

feature {NONE}

   integer_constant_overflow: STRING is
      "Integer constant overflow (out of INTEGER_64 range)."
   
   frozen run_feature_has_result is
      do
         if run_feature.result_type = Void then
            error_handler.add_position(run_feature.start_position)
            error_handler.add_position(feature_name.start_position)
            fatal_error("Feature found is a procedure.")
         end
      end

   basic_conversion(t: like target;
		    target_type, argument_type: E_TYPE): EXPRESSION is
	 -- Automatic conversion for binary features.
      require
	 t.result_type = target_type
	 argument_type /= Void
      local
	 target_type_rtm, argument_type_rtm: STRING
      do
	 Result := t
	 if target_type.is_basic_eiffel_expanded then
	    if argument_type.is_basic_eiffel_expanded then
	       argument_type_rtm := argument_type.run_time_mark
	       target_type_rtm := target_type.run_time_mark
	       if argument_type_rtm /= target_type_rtm then
		  if target_type.is_a(argument_type) then
		     Result :=
			assignment_handler.implicit_cast(t, argument_type)
		  else
		     error_handler.cancel
		  end
	       end
	    end
	 end
      ensure
	 Result /= Void
      end
   
   current_or_result_of(rf: RUN_FEATURE): EXPRESSION is
      require
	 rf /= Void
      local
	 rf4: RUN_FEATURE_4
      do
	 rf4 ?= rf
	 if rf4 /= Void then
	    Result := rf4.value
	 end
	 if Result = Void then
	    Result := Current
	 end
      ensure
	 Result /= Void
      end
   
end -- CALL
