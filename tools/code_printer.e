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
deferred class CODE_PRINTER
   --
   -- Common root for C_PRETTY_PRINTER and JVM.
   --

inherit
   GLOBALS
   VISITABLE

feature {CODE_PRINTER_VISITOR}

   accept(visitor: CODE_PRINTER_VISITOR) is
      deferred
      end

feature {NONE}

   inlined_procedure_count: INTEGER

   inlined_function_count: INTEGER

   procedure_count: INTEGER

   function_count: INTEGER

   precursor_routine_count: INTEGER

   real_procedure_count: INTEGER

   real_function_count: INTEGER

   static_expression_count: INTEGER

feature {RUN_FEATURE_3}

   incr_inlined_procedure_count is
      do
         inlined_procedure_count := inlined_procedure_count + 1
      end

   incr_real_procedure_count is
      do
         real_procedure_count := real_procedure_count + 1
      end

   incr_procedure_count is
      do
         procedure_count := procedure_count + 1
      end

feature {RUN_FEATURE_4}

   incr_inlined_function_count is
      do
         inlined_function_count := inlined_function_count + 1
      end

   incr_real_function_count is
      do
         real_function_count := real_function_count + 1
      end

   incr_function_count is
      do
         function_count := function_count + 1
      end

feature {RUN_FEATURE_10, RUN_FEATURE_11}

   incr_precursor_routine_count is
      do
         precursor_routine_count := precursor_routine_count + 1
      end

feature {NONE} -- Context stacks:

   top: INTEGER
         -- Index for top of followings stacks.

   stack_code: FIXED_ARRAY[INTEGER] is
         -- The indicating stack. It contains only one
         -- of the following unique code.
      once
         create Result.make(stack_first_size)
      end

   C_direct_call: INTEGER is unique
         -- Target is sure not to be Void and there is only one possible
         -- type (target is often Current, a manifest string or an expanded).

   C_check_id: INTEGER is unique
         -- Target is a reference type which can be Void but only one type
         -- is the good one.

   C_switch: INTEGER is unique
         -- Target is a reference type with more than one possibility.

   C_create_instruction: INTEGER is unique
         -- Target has been just created with a create instruction and
         -- need to be initialized with some create procedure call.

   C_create_expression: INTEGER is unique
         -- Target has been just created with a create expression and
         -- need to be initialized inside the create function.

   C_expanded_initialize: INTEGER is unique
         -- Target is some expanded to initialize with the default
         -- initialization procedure (ie. without arguments).

   C_inline_dca: INTEGER is unique
         -- Inlining of a direct call applied on attribute of target.
         -- Target is the one given at `top-1' plus the access to
         -- the corresponding attribute stored at level `top'.
         -- Arguments are taken at `top-1' context.

   C_same_target: INTEGER is unique
         -- Target is stored at level top - 1

   C_inline_one_pc: INTEGER is unique
         -- Inlining `one_pc' of RUN_FEATURE_3

   C_inside_twin: INTEGER is unique
         -- In order to call the user's `copy'.

   C_precursor: INTEGER is unique
         -- For Precursor calls.

   C_scoop_unwrapper: INTEGER is unique
         -- For calls into scoop unwrapper.

   C_scoop_wrapper: INTEGER is unique
	 -- For calls into scoop wrapper.

   C_string_inspector: INTEGER is unique
         -- For storage and count string fields generation inside a STRING
         -- inspect.

   C_introspect: INTEGER is unique
         -- For the introspection features

   -- Contents of stacks depends on `stack_code'.
   stack_rf: FIXED_ARRAY[RUN_FEATURE] is
      once
         create Result.make(stack_first_size)
      end

   stack_target: FIXED_ARRAY[EXPRESSION] is
      once
         create Result.make(stack_first_size)
      end

   stack_args: FIXED_ARRAY[EFFECTIVE_ARG_LIST] is
      once
         create Result.make(stack_first_size)
      end

   stack_static_rf: FIXED_ARRAY[RUN_FEATURE] is
      once
         create Result.make(stack_first_size)
      end

   stack_cpc: FIXED_ARRAY[CALL_PROC_CALL] is
      once
         create Result.make(stack_first_size)
      end

   stack_string: FIXED_ARRAY[STRING] is
      once
         create Result.make(stack_first_size)
      end

   stack_first_size: INTEGER is 12

   stack_push(code: INTEGER) is
         -- Push the `code' and resize all stacks if needed.
      local
         new_size: INTEGER
      do
         top := top + 1
         if top > stack_code.upper then
            new_size := stack_code.upper * 2
            stack_code.resize(new_size)
            stack_rf.resize(new_size)
            stack_target.resize(new_size)
            stack_args.resize(new_size)
            stack_static_rf.resize(new_size)
            stack_cpc.resize(new_size)
            stack_string.resize(new_size)
            if new_size > 1024 then
               stack_overflow
            end
         end
         stack_code.put(code,top)
      end

feature {PRECURSOR_CALL}

   push_precursor(rf: RUN_FEATURE; args: EFFECTIVE_ARG_LIST) is
      require
         rf /= Void
      do
         stack_push(C_precursor)
         stack_rf.put(rf,top)
         stack_args.put(args,top)
         direct_call_count := direct_call_count + 1
      end

feature {RUN_FEATURE_3}

   stack_not_full: BOOLEAN is
      do
         Result := top < 50
      end

feature {NONE}

   stack_overflow is
      local
         i: INTEGER
         rf: RUN_FEATURE
         rtm: STRING
         rtma: FIXED_ARRAY[STRING]
      do
         error_handler.append("Infinite inlining loop (bad recursion ??). ")
         from
            i := top - 1
         until
            i < stack_code.lower
         loop
            rf := stack_rf.item(i)
            if rf /= Void then
               error_handler.add_position(rf.start_position)
               rtm := rf.current_type.run_time_mark
               if rtma = Void then
                  create rtma.with_capacity(top)
                  rtma.add_last(rtm)
                  error_handler.append(rtm)
               elseif rtma.fast_has(rtm) then
               else
                  rtma.add_last(rtm)
                  error_handler.append(", ")
                  error_handler.append(rtm)
               end
            end
            i := i - 1
         end
         error_handler.append(",...")
	 error_handler.print_as_fatal_error
      end

feature

   pop is
      do
         check
            stack_code.lower <= top
         end
         top := top - 1
      ensure
         old(top) = top + 1
      end

feature {NONE}

   direct_call_count: INTEGER

   check_id_call_count: INTEGER

   stupid_switch_call_count: INTEGER

   sure_void_count: INTEGER

   switched_call_count: INTEGER

feature {GC_HANDLER}

   incr_direct_call_count is
      do
         direct_call_count := direct_call_count + 1
      end

   incr_switched_call_count is
      do
         switched_call_count := switched_call_count + 1
      end

end -- CODE_PRINTER

