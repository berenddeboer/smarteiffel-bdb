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
class MANIFEST_STRING_INSPECTOR

inherit
   GLOBALS

creation
   make

feature {MANIFEST_STRING_INSPECTOR_VISITOR}

   accept(visitor: MANIFEST_STRING_INSPECTOR_VISITOR) is
      do
         visitor.visit_manifest_string_inspector(Current)
      end

feature {NONE}

   string_pool: TUPLE_STRING_POOL

   headers: FAST_ARRAY[STRING] is
      once
         create Result.with_capacity(4)
      end

   make(ei: E_INSPECT) is
      require
         ei /= Void
      local
         wl: WHEN_LIST; lw: FAST_ARRAY[E_WHEN]
         val: ARRAY[WHEN_ITEM]; i, j, n: INTEGER
         wi1: WHEN_ITEM_1; s: STRING
         ms: MANIFEST_STRING
      do
         headers.clear
         wl := ei.when_list
         lw := wl.list

         from
            n := lw.count - 1
            i := 0
         until
            i > n
         loop
            val := lw.item(i).list
            from
               j := val.lower
            until
               j > val.upper
            loop
               wi1 ?= val.item(j)
               if wi1 = Void then
                  error_handler.add_position(ei.start_position)
                  error_handler.add_position(val.item(j).start_position)
                  error_handler.append("Unexpected range for inspect strings.")
                  error_handler.print_as_fatal_error
               else
                  ms ?= wi1.expression
                  if ms = Void then
                     error_handler.add_position(ei.start_position)
                     error_handler.add_position(wi1.start_position)
                     error_handler.append("Only manifest strings are accepted in inspect.")
                     error_handler.print_as_fatal_error
                  else
                     s := ms.to_string
                     if headers.has(s) then
                        error_handler.add_position(ei.start_position)
                        error_handler.add_position(ms.start_position)
                        error_handler.append("Second occurrence of this value (%"")
                        error_handler.append(s)
                        error_handler.append("%") in the same inspect.")
                        error_handler.print_as_fatal_error
                     elseif s.is_empty then
                        empty_position := ms.start_position
                     end
                     wi1.set_expression_value(headers.count)
                     headers.add_last(s)
                  end
               end
               j := j + 1
            end
            i := i + 1
         end

         create string_pool.from_collection(headers)
         count_headers := headers.count

         debug
            from
               i := headers.lower
            until
               i > headers.upper
            loop
               echo.put_string(once "checking header#")
               echo.put_integer(i)
               echo.put_string(once ": %"")
               echo.put_string(headers.item(i))
               echo.put_string(once "%"%N")
               check
                  string_pool.index_of(headers.item(i)) = i
               end
               i := i + 1
            end
         end

         check has_empty = string_pool.has_empty end
      end

   count_headers: INTEGER

   has_empty: BOOLEAN is
      local
         unknown_position: POSITION
      do
         Result := empty_position /= unknown_position
      end

   empty_position: POSITION

feature {NONE} -- Generation helpers:

   var_storage: STRING is "storage"
   var_count:   STRING is "count"
   var_state:   STRING is "state"
   var_i:       STRING is "i"

   put_var(var: STRING) is
      require
         var.count > 0
      do
         cpp.put_string(var)
         cpp.put_character('_')
         cpp.put_inspect
      end

feature

   c_compile(e_inspect: E_INSPECT) is
      local
         i, cur_state, new_state, ext_state: INTEGER
         cur_char: CHARACTER; octal: STRING
         no_check, all_check: BOOLEAN
         transition: LINKED_LIST[TUPLE[CHARACTER, INTEGER]]
      do
         no_check := ace.no_check
         all_check := ace.all_check
         cpp.inspect_incr
         cpp.put_string(once "/*[manifest INSPECT*/%N{T7* ")
         cpp.put_inspect
         cpp.put_string(once "=(T7*)")
         if all_check then
            cpp.put_character('(')
            cpp.put_trace_or_sedb_expression(e_inspect.expression.start_position)
            cpp.put_character(',')
         end
         e_inspect.expression.compile_to_c
         if all_check then
            cpp.put_character(')')
         end
         cpp.put_string(once ";%NT3* ")
         put_var(var_storage)
         cpp.put_string(once "=(NULL==")
         cpp.put_inspect
         cpp.put_string(once ")?NULL:")
         cpp.put_string_inspector(as_storage)
         cpp.put_string(fz_00)
         cpp.put_string(once "int ")
         put_var(var_count)
         cpp.put_string(once "=(NULL==")
         cpp.put_inspect
         cpp.put_string(once ")?0:")
         cpp.put_string_inspector(as_count)
         cpp.put_string(fz_00)

         -- walk through the string to have the final state:

         cpp.put_string(once "int ")
         put_var(var_state)
         cpp.put_character('=')
         cpp.put_integer(string_pool.unknown_state)
         cpp.put_string(once ";%Nint ")
         put_var(var_i)
         cpp.put_string(once "=0;%Nif (")
         cpp.put_inspect
         cpp.put_string(once "!=NULL)")
         if has_empty then
            cpp.put_string(once " /* has_empty */ if (")
            put_var(var_count)
            cpp.put_string(once "==0) ")
            put_var(var_state)
            cpp.put_string(once "=")
            cpp.put_integer(string_pool.external_state(string_pool.state_empty))
            cpp.put_string(once ";%Nelse")
         end
         cpp.put_string(once " while (")
         put_var(var_i)
         cpp.put_string(once " < ")
         put_var(var_count)
         cpp.put_string(once " && (")
         put_var(var_i)
         cpp.put_string(once "==0 || ")
         put_var(var_state)
         cpp.put_string(once "!=")
         cpp.put_integer(string_pool.unknown_state)
         cpp.put_string(once ")) {%Nswitch(")
         put_var(var_state)
         cpp.put_string(once ") {%N")

         from
            cur_state := string_pool.unknown_state
         until
            cur_state > string_pool.maxstate
         loop
            cpp.put_string(once "case ")
            cpp.put_integer(cur_state)
            cpp.put_string(once ": switch(*(")
            put_var(var_storage)
            cpp.put_character('+')
            put_var(var_i)
            cpp.put_string(once ")) {%N")
            transition := string_pool.transition(cur_state)
            from
               i := transition.lower
            until
               i > transition.upper
            loop
               cur_char := transition.item(i).first
               new_state := transition.item(i).second
               cpp.put_string(once "case '")
               inspect cur_char.code
               when 9 then
                  cpp.put_string(once "\t")
               when 10 then
                  cpp.put_string(once "\r")
               when 13 then
                  cpp.put_string(once "\n")
               when 0..8, 11, 12, 14..31 then
                  octal := once ""
                  octal.clear_count
                  cur_char.code.to_integer_8.to_octal_in(octal)
                  cpp.put_character('\')
                  cpp.put_string(octal)
               else
                  cpp.put_character(cur_char)
               end
               cpp.put_string(once "': ")
               put_var(var_state)
               cpp.put_character('=')
               if new_state < count_headers and then new_state /= string_pool.unknown_state then
                  ext_state := string_pool.external_state(new_state)
                  if ext_state /= new_state then
                     cpp.put_string(once "(*(")
                     put_var(var_storage)
                     cpp.put_character('+')
                     put_var(var_i)
                     cpp.put_string(once "+1))?")
                     cpp.put_integer(new_state)
                     cpp.put_character(':')
                  end
                  cpp.put_integer(ext_state)
               else
                  cpp.put_integer(new_state)
               end
               cpp.put_string(once ";break;%N")
               i := i + 1
            end
            cpp.put_string(once "default: ")
            put_var(var_state)
            cpp.put_character('=')
            cpp.put_integer(string_pool.unknown_state)
            cpp.put_string(once ";%Nbreak;%N}%Nbreak;%N")
            cur_state := cur_state + 1
         end
         cpp.put_string(once "default: ")
         put_var(var_state)
         cpp.put_character('=')
         cpp.put_integer(string_pool.unknown_state)
         cpp.put_string(once ";%Nbreak;%N}%N")
         put_var(var_i)
         cpp.put_string(once "++;%N}%N")

         -- now compile the compounds:

         cpp.put_string(once "switch(")
         put_var(var_state)
         cpp.put_string(once "){%N")
         e_inspect.when_list.compile_to_c_switch(e_inspect.else_position)
         if e_inspect.else_compound /= Void then
            if e_inspect.else_position.is_unknown then
               if no_check then
                  cpp.put_string(once "default:;%N")
                  exceptions_handler.bad_inspect_value(e_inspect.start_position)
               end
            else
               cpp.put_string(once "default:;%N")
               e_inspect.else_compound.compile_to_c
            end
         end
         cpp.put_string(once "}%N")

         cpp.put_string(once "}/*manifest INSPECT]*/%N")
         cpp.inspect_decr
      end

   jvm_compile(e_inspect: E_INSPECT) is
      local
         ca: like code_attribute
         loop_point, default_state_point, default_char_point, empty_point, not_empty_point, state_found_point: INTEGER
         counter, state: INTEGER
         i, cur_state, new_state, cur_char: INTEGER
         transition: LINKED_LIST[TUPLE[CHARACTER, INTEGER]]
         loop_points, inspect_points: INTEGER
         pc_tableswitch, pc_lookupswitch: INTEGER
      do
         ca := code_attribute

         loop_points := ca.get_branch_array_index
         inspect_points := ca.get_branch_array_index

         e_inspect.expression.compile_to_jvm

         ca.opcode_checkcast(constant_pool.idx_eiffel_string_class)
         ca.opcode_dup
         ca.opcode_getfield(constant_pool.idx_eiffel_string_storage_fieldref, -2)
         ca.opcode_swap
         ca.opcode_getfield(constant_pool.idx_eiffel_string_count_fieldref, -2)
         counter := ca.extra_local_size1
         ca.opcode_iconst_0
         ca.opcode_istore(counter)
         state := ca.extra_local_size1
         ca.opcode_push_integer(string_pool.unknown_state)
         ca.opcode_istore(state)

         -- Walk through the string to have the final state:

         -- State of the stack at this point:
         -- 2 storage
         -- 1 count
         if has_empty then
            -- Here we test if the count is 0. In that case, we have an empty
            -- string, we must take that into account.
            ca.opcode_dup
            empty_point := ca.opcode_ifeq
            not_empty_point := ca.opcode_goto
            ca.resolve_u2_branch(empty_point)
            ca.opcode_push_integer(string_pool.state_empty)
            ca.opcode_istore(state)
            state_found_point := ca.opcode_goto
         end

         ca.resolve_u2_branch(not_empty_point)

         -- State of the stack at this point:
         -- 2 storage
         -- 1 count
         loop_point := ca.program_counter

         -- End-loop condition: if the counter is equal or greater than the
         -- count, then go to the "inspect" part.
         ca.opcode_dup
         ca.opcode_iload(counter)
         ca.add_branch(ca.opcode_if_icmpge, inspect_points)

         -- Switch on all states: since the whole complete sequence of states
         -- is generated, a table switch will be used. Maybe someday we will
         -- use a lookup if the algorithm is complexified (still more) to
         -- remove the "holes".
         ca.opcode_iload(state)

         pc_tableswitch := ca.program_counter
         default_state_point := ca.opcode_tableswitch(string_pool.unknown_state, string_pool.maxstate, jvm_state_points)
         from
            cur_state := string_pool.unknown_state
         until
            cur_state > string_pool.maxstate
         loop
            -- Resolve the current switch case position
            ca.resolve_tableswitch_branch(pc_tableswitch, jvm_state_points, cur_state - string_pool.unknown_state)

            -- We now prepare the array of available characters...
            transition := string_pool.transition(cur_state)
            jvm_char_values.clear
            from
               i := transition.lower
            until
               i > transition.upper
            loop
               cur_char := transition.item(i).first.code
               jvm_char_values.add_last(cur_char)
               i := i + 1
            end
            if jvm_char_values.count = 0 then
               -- ... and either it is empty, in that case there is no need to
               -- go further: the string will not be found here...
               ca.opcode_push_integer(string_pool.unknown_state)
               ca.opcode_istore(state)
               ca.add_branch(ca.opcode_goto, inspect_points)
            else
               -- ... or it's not empty; in that case, we will use a
               -- lookupswitch because obviously all the possible characters
               -- won't match. Be aware that `opcode_lookupswitch' sorts the
               -- values, so after the opcode we will have to find them again.
               jvm_char_points.clear

               -- Just before the lookup switch, we push the current
               -- character, from the storage (stack#2) and the counter
               ca.opcode_swap
               ca.opcode_dup_x1
               ca.opcode_iload(counter)
               ca.opcode_baload

               pc_lookupswitch := ca.program_counter
               default_char_point := ca.opcode_lookupswitch(jvm_char_values, jvm_char_points)

               from
                  cur_char := jvm_char_values.lower
               until
                  cur_char > jvm_char_values.upper
               loop
                  -- As said above, `opcode_lookupswitch' may have changed the
                  -- ordering of jvm_char_values, so we must look for the
                  -- "good" `new_state'; hence the loop.
                  from
                     i := transition.lower
                  until
                     jvm_char_values.item(cur_char) = transition.item(i).first.code or else i > transition.upper
                  loop
                     i := i + 1
                  end

                  new_state := transition.item(i).second

                  -- Resolve the current switch case position
                  ca.resolve_lookupswitch_branch(pc_lookupswitch, jvm_char_points, cur_char)

                  if new_state = string_pool.unknown_state then
                     -- Either the new_state is unknown, in that case we exit
                     -- the loop...
                     ca.opcode_push_integer(new_state)
                     ca.opcode_istore(state)
                     ca.add_branch(ca.opcode_goto, inspect_points)
                  else
                     -- Either it is a valid state, in that case we store it
                     -- and continue to the next character
                     if new_state <= count_headers then
                        ca.opcode_push_integer(string_pool.external_state(new_state))
                     else
                        ca.opcode_push_integer(new_state)
                     end
                     ca.opcode_istore(state)
                     ca.add_branch(ca.opcode_goto, loop_points)
                  end

                  cur_char := cur_char + 1
               end

               -- Default when no character match: unknown state, exit the
               -- loop
               ca.resolve_lookupswitch_default_branch(pc_lookupswitch, default_char_point)
               ca.opcode_push_integer(string_pool.unknown_state)
               ca.opcode_istore(state)
               ca.add_branch(ca.opcode_goto, inspect_points)
            end

            cur_state := cur_state + 1
         end

         -- Default when no state match (which shouldn't happen)
         ca.resolve_tableswitch_default_branch(pc_tableswitch, default_state_point)
         ca.opcode_push_integer(string_pool.unknown_state)
         ca.opcode_istore(state)
         ca.add_branch(ca.opcode_goto, inspect_points)

         -- Here is the "continue" part of the loop. We increment the counter
         -- and go back at the beginning.
         ca.resolve_branches(loop_points)
         ca.opcode_iinc(counter, 1)
         ca.opcode_goto_backward(loop_point)

         -- Now compile the compounds:

         -- Here we have exitted the loop.
         ca.resolve_branches(inspect_points)
         -- This point is also reached from the is_empty case.
         ca.resolve_u2_branch(state_found_point)

         -- We may safely remove the two stack elements, they were useful for
         -- the loop and are not anymore.
         ca.opcode_pop2

         -- Now we push the final state we reckoned above; the rest is like a
         -- "normal" inspect.
         ca.opcode_iload(state)

         if e_inspect.when_list /= Void then
            e_inspect.when_list.compile_to_jvm(e_inspect.else_position)
         end
         if e_inspect.else_compound /= Void then
            e_inspect.else_compound.compile_to_jvm
         elseif e_inspect.else_position.is_unknown then
            if ace.no_check then
               code_attribute.runtime_error_inspect(e_inspect.expression)
            end
         end
         if e_inspect.when_list /= Void then
            e_inspect.when_list.compile_to_jvm_resolve_branch
         end

         ca.opcode_pop

         ca.release_branch_array_index
         ca.release_branch_array_index
      end

feature {NONE}

   jvm_state_points: FAST_ARRAY[INTEGER] is
      once
         create Result.with_capacity(4)
      end

   jvm_char_points: FAST_ARRAY[INTEGER] is
      once
         create Result.with_capacity(4)
      end

   jvm_char_values: FAST_ARRAY[INTEGER] is
      once
         create Result.with_capacity(4)
      end

end
