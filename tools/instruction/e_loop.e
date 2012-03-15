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
class E_LOOP
   --
   -- The Eiffel instruction : "from ... until ... loop ... end".
   --

inherit INSTRUCTION

creation make

feature

   start_position: POSITION
         -- Of letter 'f' of "from".

   initialize: COMPOUND

   invariant_clause: LOOP_INVARIANT

   variant_clause: LOOP_VARIANT

   until_expression: EXPRESSION

   loop_body: COMPOUND

   side_effect_free: BOOLEAN is False
      
   once_pre_computable: BOOLEAN is False

   end_mark_comment: BOOLEAN is True

   afd_check is
      do
         if loop_check then
            if variant_clause /= Void then
               variant_clause.afd_check
            end
            if invariant_clause /= Void then
               invariant_clause.afd_check
            end
         end
         if initialize /= Void then
            initialize.afd_check
         end
         until_expression.afd_check
         if loop_body /= Void then
            loop_body.afd_check
         end
      end

   safety_check is
      do
         if initialize /= Void then
            initialize.safety_check
         end
         until_expression.safety_check
         if loop_body /= Void then
            loop_body.safety_check
         end
      end

   simplify_2(container: COMPOUND; index: INTEGER) is
      local
	 bc: BOOLEAN_CONSTANT
      do
         if initialize /= Void then
            initialize := initialize.simplify_2
         end
         until_expression := until_expression.simplify_2
	 bc ?= until_expression
	 if loop_body /= Void then
            loop_body := loop_body.simplify_2
         end
	 if bc /= Void and then bc.value and then initialize = Void then
	    container.remove(index)
	 end
      end

   collect_c_tmp is
      do
      end

   compile_to_c is
      local
         need_se_tmp, variant_flag, invariant_flag: BOOLEAN
      do
         if loop_check and then variant_clause /= Void then
            cpp.put_string(once "{int c=0;int v=0;%N")
            variant_flag := True
         end
         if initialize /= Void then
            initialize.compile_to_c
         end
         if loop_check and then invariant_clause /= Void then
            invariant_clause.compile_to_c
            invariant_flag := True
         end
         until_expression.collect_c_tmp
         need_se_tmp := cpp.se_tmp_open_declaration
         cpp.put_string(once "while (!(")
         if ace.no_check then
            cpp.trace_boolean_expression(until_expression)
         else
            until_expression.compile_to_c
         end
         cpp.put_string(once "))%N{%N")
         if variant_flag then
            cpp.variant_check(variant_clause.expression)
         end
         if loop_body /= Void then
            loop_body.compile_to_c
         end
         if invariant_flag then
            invariant_clause.compile_to_c
         end
         cpp.put_string(once "}%N")
         if need_se_tmp then
            cpp.se_tmp_close_declaration
         end
         if variant_flag then
            cpp.put_string(fz_12)
         end
      end

   compile_to_jvm is
      local
         until_point, exit_point: INTEGER
         ca: like code_attribute
         counter, previous: INTEGER
      do
         ca := code_attribute
         if loop_check then
            counter := ca.extra_local_size1
            ca.opcode_iconst_0
            ca.opcode_istore(counter)
            previous := ca.extra_local_size1
            ca.opcode_iconst_0
            ca.opcode_istore(previous)
         end
         if initialize /= Void then
            initialize.compile_to_jvm
         end
         if loop_check then
            if invariant_clause /= Void then
               invariant_clause.compile_to_jvm(True)
               ca.opcode_pop
            end
         end
         until_point := ca.program_counter
         exit_point := until_expression.jvm_branch_if_true
         if loop_check then
            if variant_clause /= Void then
               ca.opcode_iload(counter)
               ca.opcode_iload(previous)
               ca.runtime_check_loop_variant(variant_clause.expression)
               ca.opcode_istore(previous)
            end
         end
         if loop_body /= Void then
            loop_body.compile_to_jvm
         end
         if loop_check then
            if invariant_clause /= Void then
               invariant_clause.compile_to_jvm(True)
               ca.opcode_pop
            end
         end
         if loop_check then
            ca.opcode_iinc(counter,1)
         end
         ca.opcode_goto_backward(until_point)
         ca.resolve_u2_branch(exit_point)
      end

   use_current: BOOLEAN is
      do
         if loop_check and then variant_clause /= Void then
            Result := Result or else variant_clause.use_current
         end
         if initialize /= Void then
            Result := Result or else initialize.use_current
         end
         Result := Result or else until_expression.use_current
         if loop_check and then invariant_clause /= Void then
            Result := Result or else invariant_clause.use_current
         end
         if loop_body /= Void then
            Result := Result or else loop_body.use_current
         end
      end

   stupid_switch(run_time_set: RUN_TIME_SET): BOOLEAN is
      do
         Result := 
	    (initialize = Void or else initialize.stupid_switch(run_time_set))
	    and then
	    until_expression.stupid_switch(run_time_set)
	    and then
	    (loop_body = Void or else loop_body.stupid_switch(run_time_set))
      end

   to_runnable(ct: E_TYPE): like Current is
      local
         ue: like until_expression
      do
         if current_type = Void then
            current_type := ct
	    loop_check := ct.base_class.loop_check
            if initialize /= Void then
               initialize := initialize.to_runnable(ct)
               if initialize = Void then
                  error(start_position,"Bad initialisation part.")
               end
            end
            if loop_check and then invariant_clause /= Void then
               invariant_clause := invariant_clause.to_runnable(ct)
               if invariant_clause = Void then
                  error(start_position,"Bad invariant.")
               end
            end
            if loop_check and then variant_clause /= Void then
               variant_clause := variant_clause.to_runnable(ct)
               if variant_clause = Void then
                  error(start_position,"Bad variant for this loop.")
               end
            end
            ue := until_expression.to_runnable(ct)
            if ue /= Void then
               if not ue.result_type.is_boolean then
                  error(ue.start_position,
                        "Expression of until must be BOOLEAN.")
                  error_handler.add_type(ue.result_type,fz_is_not_boolean)
                  error_handler.print_as_error
               end
               until_expression := ue
            else
               error(start_position, "This loop has an invalid expression.")
            end
            if loop_body /= Void then
               loop_body := loop_body.to_runnable(ct)
               if loop_body = Void then
                  error(start_position,"Invalid loop body.")
               end
            end
            if nb_errors = 0 then
               Result := Current
            end
         else
            !!Result.make(start_position,initialize,invariant_clause,
                          variant_clause,until_expression,loop_body)
            Result := Result.to_runnable(ct)
         end
      end

   pretty_print is
      local
         semi_colon_flag: BOOLEAN
      do
         pretty_printer.indent
         pretty_printer.keyword(fz_from)
            if initialize /= Void then
               initialize.pretty_print
            end
         if invariant_clause /= Void then
            invariant_clause.pretty_print
         end
         if variant_clause /= Void then
            pretty_printer.indent
            pretty_printer.keyword(fz_variant)
            pretty_printer.indent_level_increment
            semi_colon_flag := pretty_printer.semi_colon_flag
            pretty_printer.set_semi_colon_flag(False)
            variant_clause.pretty_print
            pretty_printer.set_semi_colon_flag(semi_colon_flag)
            pretty_printer.indent_level_decrement
	 end
         pretty_printer.indent
         pretty_printer.keyword(fz_until)
         pretty_printer.indent_level_increment
         pretty_printer.indent
         pretty_printer.set_semi_colon_flag(False)
         until_expression.pretty_print
         pretty_printer.indent_level_decrement
         pretty_printer.indent
         pretty_printer.keyword(fz_loop)
         pretty_printer.indent
         if loop_body /= Void then
            loop_body.pretty_print
         end
         pretty_printer.indent
         pretty_printer.keyword(fz_end)
         if pretty_printer.print_end_of_statement then
            pretty_printer.put_end_of(fz_loop)
         end
      end

feature {COMPOUND,INSTRUCTION_WITH_COMMENT}

   verify_scoop(allowed: FORMAL_ARG_LIST) is
      local
         dummy: BOOLEAN
      do
         if initialize /= Void then
            initialize.verify_scoop(allowed)
         end
         if invariant_clause /= Void then
            invariant_clause.verify_scoop(allowed)
         end
         if variant_clause /= Void then
            variant_clause.verify_scoop(allowed)
         end
         dummy := until_expression.verify_scoop(allowed)
         if loop_body /= Void then
            loop_body.verify_scoop(allowed)
         end
      end

feature {E_LOOP_VISITOR}

   accept(visitor: E_LOOP_VISITOR) is
      do
         visitor.visit_e_loop(Current)
      end

feature {NONE}

   current_type: E_TYPE

   loop_check: BOOLEAN

   make(sp: like start_position
        i: like initialize
        ic : like invariant_clause
        vc: like variant_clause
        ue : like until_expression
        lb : like loop_body) is
      require
         not sp.is_unknown
         ue /= Void
      do
         start_position := sp
         initialize := i
         invariant_clause := ic
         variant_clause := vc
         until_expression := ue
         loop_body := lb
      ensure
         start_position = sp
         initialize = i
         invariant_clause = ic
         variant_clause = vc
         until_expression = ue
         loop_body = lb
      end

invariant

   not start_position.is_unknown

   until_expression /= Void

end -- E_LOOP

