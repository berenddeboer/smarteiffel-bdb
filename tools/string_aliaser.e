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
class STRING_ALIASER
   --
   -- Singleton object used to share constant immutable strings.
   -- This singleton is shared via the GLOBALS.`string_aliaser' once 
   -- function .
   -- The goal is to optimize immutable strings comparisons. Thus, any
   -- immutable name must be registered here to get the corresponding
   -- unique reference.
   --

inherit
   GLOBALS
   VISITABLE

creation make

feature

   item(model: STRING): STRING is
      require
         model /= Void
      do
	 Result := memory.reference_at(model)
         if Result = Void then
            Result := model.twin
            memory_add(Result)
         end
      ensure
         Result.is_equal(model)
      end

feature {FEATURE_NAME}

   for_prefix(to_string: STRING): STRING is
      do
         Result := key_for_prefix_infix(once "_px_",to_string)
      end

   for_infix(to_string: STRING): STRING is
      do
         Result := key_for_prefix_infix(once "_ix_",to_string)
      end

feature {COMPILE_TO_C,COMPILE_TO_JVM}

   echo_information is
      do
         echo.put_string(once "Aliased Strings: ")
         echo.put_integer(memory.count)
         echo.put_string(fz_dot_new_line)
      end

feature {EIFFEL_PARSER}

   case_insensitive_notify is
      require
         eiffel_parser.case_insensitive
      do
         case_insensitive_for(as_boolean_bits)
         case_insensitive_for(as_character_bits)
	 case_insensitive_for(as_double_bits)
	 case_insensitive_for(as_integer_bits)
	 case_insensitive_for(as_minimum_character_code)
	 case_insensitive_for(as_minimum_double)
	 case_insensitive_for(as_minimum_real)
	 case_insensitive_for(as_maximum_character_code)
	 case_insensitive_for(as_maximum_double)
	 case_insensitive_for(as_maximum_real)
	 case_insensitive_for(as_pointer_bits)
	 case_insensitive_for(as_real_bits)
      end

feature {STRING_ALIASER_VISITOR}

   accept(visitor: STRING_ALIASER_VISITOR) is
      do
         visitor.visit_string_aliaser(Current)
      end

feature {NONE}

   make is
      do
         -- Hard-coded class names:
         memory_add(as_any)
         memory_add(as_array)
         memory_add(as_arguments)
         memory_add(as_bit)
         memory_add(as_bit_n)
         memory_add(as_boolean)
         memory_add(as_boolean_ref)
         memory_add(as_character)
         memory_add(as_character_ref)
         memory_add(as_dictionary)
         memory_add(as_double)
         memory_add(as_double_ref)
         memory_add(as_exceptions)
         memory_add(as_fixed_array)
         memory_add(as_function)
         memory_add(as_general)
         memory_add(as_integer_general)
         memory_add(as_integer_8)
         memory_add(as_integer_16)
         memory_add(as_integer_32)
         memory_add(as_integer)
         memory_add(as_integer_64)
         memory_add(as_integer_ref)
         memory_add(as_memory)
         memory_add(as_native_array)
         memory_add(as_none)
         memory_add(as_platform)
         memory_add(as_pointer)
         memory_add(as_pointer_ref)
         memory_add(as_predicate)
         memory_add(as_procedure)
         memory_add(as_real_general)
         memory_add(as_real_32)
         memory_add(as_real)
         memory_add(as_real_64)
         memory_add(as_real_ref)
         memory_add(as_routine)
         memory_add(as_string)
         memory_add(as_text_file_read)
         memory_add(as_text_file_write)
         memory_add(as_tuple)
         memory_add(as_type)
	 memory_add(as_unicode_string)
	 
         -- Operator/Infix/Prefix list:
         memory_add(as_and)
         memory_add(as_and_then)
         memory_add(as_at)
         memory_add(as_backslash_backslash)
         memory_add(as_bit_and)
         memory_add(as_bit_clear)
         memory_add(as_bit_not)
         memory_add(as_bit_or)
         memory_add(as_bit_put)
         memory_add(as_bit_rotate)
         memory_add(as_bit_rotate_left)
         memory_add(as_bit_rotate_right)
         memory_add(as_bit_set)
         memory_add(as_bit_shift_right_unsigned)
         memory_add(as_bit_xor)
         memory_add(as_eq)
         memory_add(as_ge)
         memory_add(as_gt)
         memory_add(as_implies)
         memory_add(as_le)
         memory_add(as_lt)
         memory_add(as_minus)
         memory_add(as_minus_native)
         memory_add(as_muls)
         memory_add(as_muls_native)
         memory_add(as_neq)
         memory_add(as_not)
         memory_add(as_or)
         memory_add(as_or_else)
         memory_add(as_plus)
         memory_add(as_plus_native)
         memory_add(as_pow)
         memory_add(as_shift_left)
         memory_add(as_shift_right)
         memory_add(as_slash)
         memory_add(as_slash_slash)
         memory_add(as_xor)
	 
	 -- Hard coded feature names:
         memory_add(as_a1)
         memory_add(as_add_last)
         memory_add(as_agent)
	 memory_add(as_as_16_ne)
         memory_add(as_atan2)
         memory_add(as_blank)
         memory_add(as_boolean_bits)
         memory_add(as_call)
         memory_add(as_calloc)
         memory_add(as_capacity)
         memory_add(as_character_bits)
         memory_add(as_clear_all)
         memory_add(as_count)
         memory_add(as_code)
         memory_add(as_collecting)
         memory_add(as_collection_off)
         memory_add(as_collection_on)
         memory_add(as_collector_counter)
         memory_add(as_conforms_to)
         memory_add(as_copy)
         memory_add(as_c_inline_c)
         memory_add(as_c_inline_h)
         memory_add(as_default_create)
         memory_add(as_default_rescue)
         memory_add(as_deep_memcmp)
         memory_add(as_deep_twin)
         memory_add(as_deep_twin_from)
         memory_add(as_dispose)
         memory_add(as_double_bits)
         memory_add(as_double_floor)
         memory_add(as_die_with_code)
         memory_add(as_element_sizeof)
         memory_add(as_exception)
         memory_add(as_fifth)
         memory_add(as_first)
         memory_add(as_floor)
         memory_add(as_flush)
         memory_add(as_fourth)
         memory_add(as_from_pointer)
         memory_add(as_full_collect)
         memory_add(as_generating_type)
         memory_add(as_generator)
         memory_add(as_io)
         memory_add(as_integer_bits)
         memory_add(as_is_basic_expanded_type)
         memory_add(as_is_deep_equal)
         memory_add(as_is_default)
         memory_add(as_is_expanded_type)
         memory_add(as_is_equal)
         memory_add(as_is_not_null)
         memory_add(as_item)
         memory_add(as_last)
         memory_add(as_lower)
         memory_add(as_low_8)
         memory_add(as_low_16)
         memory_add(as_low_32)
         memory_add(as_make)
         memory_add(as_minimum_character_code)
         memory_add(as_minimum_double)
         memory_add(as_minimum_real)
	 memory_add(as_manifest_initialize)
         memory_add(as_maximum_character_code)
         memory_add(as_maximum_double)
         memory_add(as_maximum_real)
         memory_add(as_object_size)
         memory_add(as_pointer_bits)
         memory_add(as_pointer_size)
         memory_add(as_pow_postfix)
         memory_add(as_print)
         memory_add(as_print_on)
         memory_add(as_print_run_time_stack)
         memory_add(as_print_all_run_time_stacks)
         memory_add(as_put)
         memory_add(as_put_0)
         memory_add(as_put_1)
         memory_add(as_put_16_be)
         memory_add(as_put_16_le)
         memory_add(as_put_16_ne)
         memory_add(as_raise_exception)
         memory_add(as_real_bits)
         memory_add(as_realloc)
         memory_add(as_second)
         memory_add(as_set_item)
         memory_add(as_same_dynamic_type)
         memory_add(as_se_argc)
         memory_add(as_se_argv)
         memory_add(as_sedb_breakpoint)
         memory_add(as_signal_number)
         memory_add(as_standard_copy)
         memory_add(as_standard_is_equal)
         memory_add(as_standard_twin)
         memory_add(as_std_error)
         memory_add(as_std_input)
         memory_add(as_std_output)
         memory_add(as_storage)
         memory_add(as_third)
         memory_add(as_to_bit)
         memory_add(as_to_character)
         memory_add(as_to_double)
         memory_add(as_to_integer_8)
         memory_add(as_to_integer_16)
         memory_add(as_to_integer)
         memory_add(as_to_integer_32)
         memory_add(as_to_pointer)
         memory_add(as_to_real)
         memory_add(as_trace_switch)
         memory_add(as_truncated_to_integer)

         memory_add(as_twin)
         memory_add(as_upper)
         memory_add(as_with_capacity)

         -- Other names:
	 memory_add(as_arguments)
	 memory_add(as_current)
         memory_add(as_native_array_character)
	 memory_add(as_last_result)
         memory_add(as_like_current)
	 memory_add(as_method)
	 memory_add(as_open_arguments)
	 memory_add(as_open_argument_indices)
	 memory_add(as_open_argument_index)
	 memory_add(as_open_argument_count)
         memory_add(as_precursor)
         memory_add(as_result)
	 memory_add(as_target)
         memory_add(as_void)
      end

   buffer: STRING is
      once
	 create Result.make(128)
      end

   key_for_prefix_infix(tag_prefix_or_infix, to_string: STRING): STRING is
      local
         i: INTEGER; c: CHARACTER
      do
         buffer.copy(tag_prefix_or_infix)
         from
            i := 1
         until
            i > to_string.count
         loop
            c := to_string.item(i)
            if c.is_letter then
               buffer.extend(c)
            else
               c.code.append_in(buffer)
            end
            i := i + 1
         end
         Result := item(buffer)
      end

   memory_add(str: STRING) is
      require
	 not memory.has(str)
      do
	 memory.add(str, str)
      end
   
   case_insensitive_for(str: STRING) is
      require
	 str = memory.reference_at(str)
      do
	 memory.remove(str)
	 str.to_lower
	 memory.add(str, str)
      end

   memory: HASHED_DICTIONARY[STRING,STRING] is
      once
         create Result.with_capacity(16384)
      end

   singleton_memory: STRING_ALIASER is
      once
         Result := Current
      end

invariant

   is_real_singleton: Current = singleton_memory

end -- STRING_ALIASER
