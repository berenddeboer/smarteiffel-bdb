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
class EFFECTIVE_ARG_LIST
   --
   -- For an effective arguments list (for a routine call).
   --

inherit
   GLOBALS
   VISITABLE

creation make_1, make_n

creation {EFFECTIVE_ARG_LIST} from_model

feature {EFFECTIVE_ARG_LIST}

   first_one: EXPRESSION

   remainder: FAST_ARRAY[EXPRESSION]
         -- Corresponding list of actual arguments.

feature

   current_type: E_TYPE
         -- Not Void when checked in.

   count: INTEGER is
      do
         if remainder = Void then
            Result := 1
         else
            Result := remainder.upper + 2
         end
      end

   expression(i: INTEGER): EXPRESSION is
      require
         i.in_range(1,count)
      do
         if i = 1 then
            Result := first_one
         else
            Result := remainder.item(i - 2)
         end
      ensure
         Result /= Void
      end

   first: EXPRESSION is
      require
         count >= 1
      do
         Result := first_one
      ensure
         Result /= Void
      end

   run_class: RUN_CLASS is
      do
         Result := current_type.run_class
      end

   start_position: POSITION is
      do
         Result := first.start_position
      end

   to_runnable(ct: E_TYPE): like Current is
      require
         ct.run_type = ct
      local
         i: INTEGER; e1, e2: EXPRESSION
      do
         if current_type = Void then
            current_type := ct
            from
               i := count
            until
               i = 0
            loop
               e1 := expression(i)
               e2 := e1.to_runnable(current_type)
               if e2 = Void then
                  error(e1.start_position,"Bad expression.")
               else
                  put(e2,i)
               end
               i := i - 1
            end
            if nb_errors = 0 then
               Result := Current
            end
         else
            create Result.from_model(Current)
            Result := Result.to_runnable(ct)
         end
      end

   simplify_2 is
      local
         i: INTEGER
      do
         from
            i := count
         until
            i = 0
         loop
            put(expression(i).simplify_2, i)
            i := i - 1
         end
      end
   
   side_effect_free: BOOLEAN is
      local
         i: INTEGER
      do
         from
	    Result := True
            i := count
         until
            not Result or else i = 0
         loop
            Result := expression(i).side_effect_free
            i := i - 1
         end
      end
   
   afd_check is
      require
         current_type /= Void
      local
         i: INTEGER
      do
         from
            i := count
         until
            i = 0
         loop
            expression(i).afd_check
            i := i - 1
         end
      end

   safety_check is
      local
         i: INTEGER
      do
         from
            i := count
         until
            i = 0
         loop
            expression(i).safety_check
            i := i - 1
         end
      end

   compile_to_c(fal: FORMAL_ARG_LIST) is
         -- Produce C code for all expressions of the list.
      require
         cpp.on_c
         count = fal.count
      local
         i, up: INTEGER
      do
         from
            i := 1
            up := count
         until
            i > up
         loop
            compile_to_c_ith(fal,i)
            i := i + 1
            if i <= up then
               cpp.put_character(',')
            end
         end
      ensure
         cpp.on_c
      end

   compile_to_c_ith(fal: FORMAL_ARG_LIST; index: INTEGER) is
         -- Produce C code for expression `index'.
      require
         cpp.on_c
         count = fal.count
         index.in_range(1,count)
      local
         e: EXPRESSION; ft: E_TYPE
      do
         e := expression(index)
         ft := fal.type(index).run_type
	 if ft.is_boolean then
	    cpp.put_string(once "(T6)(")
	 end
         e.mapping_c_arg(ft)
	 if ft.is_boolean then
	    cpp.put_character(')')
	 end
      ensure
         cpp.on_c
      end

   collect_c_tmp is
      local
         i, c: INTEGER
      do
         from
            i := 1
            c := count
         until
            i > c
         loop
            expression(i).collect_c_tmp
            i := i + 1
         end
      end

   c_frame_descriptor(format, locals: STRING) is
      local
         i, c: INTEGER
      do
         from
            i := 1
            c := count
         until
            i > c
         loop
            expression(i).c_frame_descriptor(format,locals)
            i := i + 1
         end
      end

   compile_to_jvm(fal: FORMAL_ARG_LIST): INTEGER is
      require
         count = fal.count
      local
         i, up: INTEGER
      do
         from
            i := 1
            up := count
         until
            i > up
         loop
            Result := Result + compile_to_jvm_ith(fal,i)
            i := i + 1
         end
      end

   compile_to_jvm_ith(fal: FORMAL_ARG_LIST; index: INTEGER): INTEGER is
      require
         count = fal.count
         1 <= index
         index <= count
      local
         e: EXPRESSION
         ft: E_TYPE
      do
         e := expression(index)
         ft := fal.type(index).run_type
         Result :=  e.compile_to_jvm_into(ft)
      end

   use_current: BOOLEAN is
      local
         i: INTEGER
      do
         from
            i := count
         until
            Result or else i = 0
         loop
            Result := expression(i).use_current
            i := i - 1
         end
      end

   stupid_switch(run_time_set: RUN_TIME_SET): BOOLEAN is
      local
         i: INTEGER
      do
         from
            Result := True
            i := count
         until
            not Result or else i = 0
         loop
            Result := expression(i).stupid_switch(run_time_set)
            i := i - 1
         end
      end

   once_pre_computable: BOOLEAN is
      local
         i: INTEGER
      do
         from
            i := count
            Result := True
         until
            not Result or else i = 0
         loop
            Result := expression(i).once_pre_computable
            i := i - 1
         end
      end

   pretty_print is
      local
         i: INTEGER
      do
         pretty_printer.put_character('(')
         from
            i := 1
         until
            i > count
         loop
            expression(i).pretty_print
            i := i + 1
            if i <= count then
               pretty_printer.put_character(',')
	       if not pretty_printer.zen_mode then
		  pretty_printer.put_character(' ')
	       end
            end
         end
         pretty_printer.put_character(')')
      end

   short is
      local
         i: INTEGER
      do
         short_print.hook_or("op_eal","(")
         from
            i := 1
         until
            i > count
         loop
            expression(i).short
            i := i + 1
            if i <= count then
               short_print.hook_or("eal_sep",",")
            end
         end
         short_print.hook_or("cl_eal",")")
      end

   is_static: BOOLEAN is
         -- Is True when only `is_static' expression are used.
      local
         i: INTEGER
      do
         from
            Result := True
            i := count
         until
            not Result or else i = 0
         loop
            Result := expression(i).is_static
            i := i - 1
         end
      end

feature {SMART_EIFFEL}

   match_with(rf: RUN_FEATURE) is
         -- Check the good match for actual/formal arguments with `rf'.
      require
         rf.arguments /= Void
      local
         fal: FORMAL_ARG_LIST; i: INTEGER; e: EXPRESSION; at, ft: E_TYPE
         sep: BOOLEAN
      do
         from
	    if smart_eiffel.scoop then
	       e := cpp.current_target
	       sep := (rf.current_type.is_separate and then
		       e /= Void and then
		       not e.is_current)
	    end
	    fal := rf.arguments
	    i := fal.count
	    if fal.count /= count then
	       error_handler.add_position(start_position)
	       error_handler.add_position(fal.start_position)
	       error_handler.append("The feature called has ")
	       error_handler.append_integer(i)
	       error_handler.append(" argument")
	       if i > 1 then error_handler.extend('s') end
	       error_handler.append(". (The actual argument list has ")
	       error_handler.append_integer(count)
	       error_handler.append(" item")
	       if count > 1 then error_handler.extend('s') end
	       error_handler.append(".)")
	       error_handler.print_as_fatal_error
	    end
         until
            i = 0 or else nb_errors > 0
         loop
            e := expression(i)
            at := e.result_type
            ft := fal.type(i)
            if e.is_void then
               if ft.is_expanded then
                  error_handler.add_position(e.start_position)
                  error(ft.start_position,
                        "Cannot pass Void for expanded argument.")
               end
            elseif sep then
               if at.is_expanded then
                  at.run_class.verify_scoop_expanded(at.start_position)
               elseif not at.is_separate and then not ft.is_separate then
                  error_handler.add_position(e.start_position)
                  error_handler.add_position(ft.start_position)
                  fatal_error(fz_sc2)
               end
            elseif ft.is_like_current then
               if at.run_type.is_a(ft.run_type) then
                  if at.run_type.is_expanded then
                  elseif at.run_type.is_a(ft.run_type) then
                  else
                     error_handler.add_position(e.start_position)
                     error(ft.start_position,em1)
                  end
               else
                  error_handler.add_position(e.start_position)
                  error(ft.start_position,em1)
               end
            elseif ft.is_like_feature then
               if at.run_type.is_a(ft.run_type) then
               else
                  error_handler.add_position(e.start_position)
                  error(ft.start_position," It is not Like <feature>.")
               end
            elseif is_like_argument(e,at,ft) then
            elseif at.is_a(ft) then
            else
	       error_handler.print_as_error
	       error_handler.add_position(ft.start_position)
               error_handler.add_position(e.start_position)
	       error_handler.append(
                  "Actual-argument/Formal-argument mismatch.")
	       error_handler.print_as_fatal_error
            end
            e := assignment_handler.implicit_cast(e, ft)
            assignment_handler.assignment(e.start_position,
					  e.result_type,
					  ft)
            put(e,i)
            i := i - 1
         end
      end

feature {PROC_CALL_1,CALL_1_C}

   tuple_substitution: like Current is
      local
	 tuple_expression: TUPLE_EXPRESSION; fake_tuple: FAKE_TUPLE
      do
	 tuple_expression ?= first_one
	 if tuple_expression /= Void then
	    create fake_tuple.make(tuple_expression)
	    if remainder /= Void then
	       create Result.make_n(fake_tuple,remainder)
	    else
	       create Result.make_1(fake_tuple)
	    end
	 else
	    Result := Current
	 end
      end

feature {E_AGENT,EFFECTIVE_ARG_LIST}

   open_operands_notify(e_agent: E_AGENT; rf: RUN_FEATURE): like Current is
	 -- Before the traditional `to_runnable', we have to notify open 
	 -- operands.
      local
	 open_operand: OPEN_OPERAND; i, c: INTEGER
      do
         if current_type = Void then
            from
	       c := count
               i := 1
            until
               i > c
            loop
               open_operand ?= expression(i)
	       if open_operand /= Void then
		  put(open_operand.notify(e_agent,rf,i),i)
	       end
               i := i + 1
            end
	    Result := Current
         else
            create Result.from_model(Current)
            Result := Result.open_operands_notify(e_agent,rf)
         end
      ensure
	 Result.current_type = Void
      end

feature {RUN_FEATURE_3,RUN_FEATURE_4}

   isa_dca_inline(relay_rf, rf: RUN_FEATURE): BOOLEAN is
         -- Assume `rf' is inside `relay_rf'.
      require
         relay_rf /= Void
         rf /= Void
      local
         relay_args, args: FORMAL_ARG_LIST
         e: EXPRESSION
         i, r: INTEGER
      do
         relay_args := relay_rf.arguments
         args := rf.arguments
         from
            Result := True
            i := count
            isa_dca_inline_memory.force(False,i)
            isa_dca_inline_memory.clear_all
         until
            not Result or else i = 0
         loop
            e := expression(i)
            r := e.isa_dca_inline_argument
            inspect
               r
            when 0 then
               Result := False
            when -1 then
               if args.type(i).is_expanded then
                  Result := e.result_type.is_expanded
               else
                  Result := e.result_type.is_reference
               end
            else
               check
                  r > 0
               end
               isa_dca_inline_memory.put(True,r)
               if relay_args.type(r).is_reference then
                  if args.type(i).is_reference then
                     Result := e.result_type.is_reference
                  else
                     Result := False
                  end
               elseif args.type(i).is_expanded then
                  Result := e.result_type.is_expanded
               else
                  Result := False
               end
            end
            i := i - 1
         end
         if Result then
            -- No arguments are lost :
            from
               if relay_rf.arguments /= Void then
                  i := relay_rf.arguments.count
               else
                  i := 0
               end
            until
               not Result or else i = 0
            loop
               Result := isa_dca_inline_memory.item(i)
               i := i - 1
            end
         end
      end

feature {C_PRETTY_PRINTER}

   dca_inline(fal: FORMAL_ARG_LIST) is
      require
         fal /= Void
      local
         i, up: INTEGER
      do
         from
            up := count
            i := 1
         until
            i > up
         loop
            dca_inline_ith(fal,i)
            i := i + 1
            if i <= up then
               cpp.put_character(',')
            end
         end
      end

   dca_inline_ith(fal: FORMAL_ARG_LIST; index: INTEGER) is
      require
         fal /= Void
         index <= count
      local
         e: EXPRESSION
         ft: E_TYPE
      do
         e := expression(index)
         ft := fal.type(index).run_type
         e.dca_inline_argument(ft)
      end

feature {EFFECTIVE_ARG_LIST}

   put(e: EXPRESSION; i: INTEGER) is
      require
         i.in_range(1,count)
      do
         if i = 1 then
            first_one := e
         else
            remainder.put(e,i - 2)
         end
      end

feature {CALL_N}

   assertion_check(tag: CHARACTER) is
      local
         i: INTEGER
      do
         from
            i := count
         until
            i = 0
         loop
            expression(i).assertion_check(tag)
            i := i - 1
         end
      end

feature {E_AGENT_CALL,FORMAL_ARG_LIST}

   add_last(e: EXPRESSION) is
	 -- Usually, `e' may be a FAKE_ARGUMENT or an OPEN_OPERAND.
      require
         e /= Void
      do
	 if remainder = Void then
	    create remainder.with_capacity(4)
	 end
	 remainder.add_last(e)
      ensure
         count = 1 + old count
      end

feature {EFFECTIVE_ARG_LIST_VISITOR}

   accept(visitor: EFFECTIVE_ARG_LIST_VISITOR) is
      do
         visitor.visit_effective_arg_list(Current)
      end

feature {NONE}

   make_1(e: EXPRESSION) is
      require
         e /= Void
      do
         first_one := e
      ensure
         count = 1
         first = e
      end

   make_n(fo: like first_one; r: like remainder) is
      require
         fo /= Void
      do
         first_one := fo
         remainder := r
      ensure
         first_one = fo
         remainder = r
      end

   from_model(model: like Current) is
      require
         model /= Void
      do
         first_one := model.first_one
         remainder := model.remainder
         if remainder /= Void then
            remainder := remainder.twin
         end
      ensure
         count = model.count
      end

   isa_dca_inline_memory: ARRAY[BOOLEAN] is
      once
         !!Result.make(1,2)
      end

   is_like_argument(e: EXPRESSION; at, ft: E_TYPE): BOOLEAN is
      local
         tla: TYPE_LIKE_ARGUMENT; at_rt, ot_rt, ot: E_TYPE
      do
         tla ?= ft
         if tla /= Void then
            Result := True
            ot := expression(tla.rank).result_type
	    at_rt := at.run_type
	    ot_rt := ot.run_type
            if not at_rt.is_a(ot_rt) then
	       if at_rt.is_integer and then ot_rt.is_integer then
		  error_handler.cancel
	       else
		  error_handler.add_position(e.start_position)
		  error(ft.start_position," It is not Like <argument>.")
	       end
	    end
         end
      end

   em1: STRING is " It is not Like Current."
   em2: STRING is "Bad number of arguments."

invariant

   first_one /= Void

   remainder /= Void implies count = remainder.count + 1

end -- EFFECTIVE_ARG_LIST

