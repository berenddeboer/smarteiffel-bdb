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
class CREATE_INSTRUCTION
   --
   -- The new style create instruction.
   --

inherit CREATE_TOOLS; INSTRUCTION

creation {EIFFEL_PARSER,CREATE_INSTRUCTION} make

feature

   side_effect_free: BOOLEAN is False
      
   frozen to_runnable(ct: E_TYPE): like Current is
      local
         t: E_TYPE
      do
         if current_type = Void then
            current_type := ct
            check_writable(ct)
            if type /= Void then
               check_explicit_type
               t := type
            else
               t := writable.result_type
               type := fix_type (t)
               if t /= type then
                  -- Special case. fix_type changed, store result in `type'
                  -- We're actually converting an implicit to explicit creation here.
                  t := type
               else
                  -- Type was not fixed. Stay with implicit style
                  type := Void
               end
            end
            check_created_type(t)
            check_create_clause(t)
            Result := Current
         else
            !!Result.make(start_position,type,writable,call)
            Result := Result.to_runnable(ct)
         end
      end

   frozen once_pre_computable: BOOLEAN is
      local
	 t: like type
      do
         if writable.once_pre_computable then
	    if arguments = Void or else arguments.once_pre_computable then
	       t := type
	       if t = Void then
		  t := writable.result_type
	       end
	       Result := common_once_pre_computable(t)
	    end
	 end
      end

   frozen use_current: BOOLEAN is
      local
	 args: like arguments
      do
	 if writable.use_current then
	    Result := True
	 elseif run_feature /= Void then
	    args := arguments
	    if args /= Void then
	       Result := args.use_current
	    end
	 end
      end

   frozen collect_c_tmp is
      local
         args: like arguments
      do
	 args := arguments
	 if args /= Void then
	    args.collect_c_tmp
	 end
      end

   frozen stupid_switch(run_time_set: RUN_TIME_SET): BOOLEAN is
      local
         t: E_TYPE
      do
         if type /= Void then
            t := type
         else
            t := writable.result_type
         end
         if t.is_anchored then
         elseif t.is_generic then
         else
            if call = Void then
               Result := writable.stupid_switch(run_time_set)
            else
               Result := call.stupid_switch(run_time_set)
            end
         end
      end

   simplify_2(container: COMPOUND; index: INTEGER) is
      do
      end
   
   pretty_print is
      do
         pretty_printer.keyword(fz_create)
	 if type /= Void then
	    pretty_printer.put_character('{')
	    type.pretty_print
	    pretty_printer.put_character('}')
	    pretty_printer.put_character(' ')
	 end
	 if call /= Void then
	    call.pretty_print
	 else
	    writable.pretty_print
	    if pretty_printer.semi_colon_flag then
	       pretty_printer.put_character(';')
	    end
	 end
      end

   frozen compile_to_c is
         -- @TODO: lock till the end of the procedure call
      local
	 t: E_TYPE; rf3: RUN_FEATURE_3; need_se_tmp: BOOLEAN
      do
	 t := type
	 if t = Void then
	    t := writable.result_type.run_type
	 end
         if t.is_reference then
            c2c_opening(t)
	    if run_feature /= Void then
	       cpp.push_create_instruction(run_feature, arguments)
	       -- *** IS IT NECESSARY ***
               -- run_feature.collect_c_tmp
               -- need_se_tmp := cpp.se_tmp_open_declaration
	       -- ***
	       run_feature.mapping_c
               if need_se_tmp then
                  cpp.se_tmp_close_declaration
               end
	       cpp.pop
	    end
            --if smart_eiffel.scoop and then t.is_separate then
            --	 cpp.put_string(once "se_join_subsystem(n->subsystem);%N")
            --end
            c2c_closing(t)
         else
	    writable.compile_to_c
	    cpp.put_character('=')
	    cpp.put_character('M')
	    cpp.put_integer(t.id)
	    cpp.put_string(fz_00)
	    if run_feature /= Void then
	       check
		  run_feature = t.run_class.a_default_create
	       end
	       rf3 ?= run_feature
	       cpp.put_proc_call_0(rf3, writable, Void)
	    end
         end
      end

   frozen compile_to_jvm is
      local
         w: EXPRESSION; t: E_TYPE
      do
         w := writable
	 if type /= Void then
	    t := type
	 else
	    t := writable.result_type
	 end
         compile_to_jvm0(t)
	 if run_feature /= Void then
	    jvm.inside_create_instruction(run_feature,call)
	 end
         t.jvm_check_class_invariant
         w.jvm_assign_creation
      end

   end_mark_comment: BOOLEAN is False

feature {COMPOUND,INSTRUCTION_WITH_COMMENT}

   verify_scoop(allowed: FORMAL_ARG_LIST) is
      do
      end

feature {CREATE_INSTRUCTION_VISITOR}

   accept(visitor: CREATE_INSTRUCTION_VISITOR) is
      do
         visitor.visit_create_instruction(Current)
      end

feature {NONE}

   check_writable(ct: E_TYPE) is
      require
         ct /= Void
      local
         w: like writable
      do
         w := writable.to_runnable(ct)
         if w = Void then
            error_handler.add_position(writable.start_position)
            fatal_error("Bad writable target for creation.")
         else
            writable := w
         end
      ensure
         writable.result_type.is_run_type
      end

   c2c_opening(t: E_TYPE) is
      require
         t.is_reference
      local
         rc: RUN_CLASS; e_result: E_RESULT
      do
         rc := t.run_class
	 if ace.no_check then
	    cpp.put_trace_or_sedb_instruction(start_position)
	 end
         cpp.put_character('{')
         gc_handler.declare_allocate_n(rc)
         cpp.expanded_attributes(t)
         e_result ?= writable
         if e_result /= Void and then e_result.is_once_result then
            cpp.put_string(e_result.c_variable_name)
            cpp.put_string(once "=((T0*)n);%N")
         end
      end

   c2c_closing(t: E_TYPE) is
      require
         t.is_reference
      local
         e_result: E_RESULT
      do
         e_result ?= writable
         if e_result = Void or else not e_result.is_once_result then
            writable.compile_to_c
            cpp.put_string(once "=((T0*)n);%N")
         end
         if cpp.call_invariant_start(t) then
            cpp.put_character('n')
            cpp.call_invariant_end
            cpp.put_character(';')
         end
         cpp.put_character('}')
         cpp.put_character('%N')
      end

   make(sp: like start_position
	t: like type; w: like writable; c: like call) is
      require
         not sp.is_unknown
         w /= Void
      do
         start_position := sp
         type := t
         writable := w
         call := c
      ensure
         start_position = sp
         type = t
         writable = w
         call = c
      end

invariant

   not start_position.is_unknown

   writable.is_writable

end -- CREATE_INSTRUCTION
