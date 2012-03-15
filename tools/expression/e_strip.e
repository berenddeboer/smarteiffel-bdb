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
class E_STRIP
   --
   -- To store a strip expression like :
   --                                        strip(foo, bar)
   --

inherit EXPRESSION

creation make

feature

   is_current: BOOLEAN is False

   is_writable: BOOLEAN is False

   is_manifest_string: BOOLEAN is False

   is_result: BOOLEAN is False

   is_void: BOOLEAN is False

   is_static: BOOLEAN is False

   use_current: BOOLEAN is True

   side_effect_free: BOOLEAN is False

   once_pre_computable: BOOLEAN is False

   extra_bracket_flag: BOOLEAN is False
   
   current_type: E_TYPE
         -- Context of this expression.

   start_position: POSITION

   to_integer_or_error: INTEGER is
      do
	 to_integer_error
      end

   start_lookup_class: BASE_CLASS is
      local
	 cn: CLASS_NAME
      once
	 create cn.unknown_position(as_array)
         Result := smart_eiffel.base_class(cn)
      end

   isa_dca_inline_argument: INTEGER is 0

   dca_inline_argument(formal_arg_type: E_TYPE) is do end

   assertion_check(tag: CHARACTER) is do end

   afd_check is
      local
         rf2: RUN_FEATURE_2; i: INTEGER; st: E_TYPE
         fd: DICTIONARY[RUN_FEATURE,FEATURE_NAME]
      do
         fd := current_type.run_class.feature_dictionary
         from
            i := 1
         until
            i > fd.count
         loop
            rf2 ?= fd.item(i)
            if rf2 /= Void then
               if list = Void or else not list.has(rf2.name) then
                  st := rf2.result_type
		  assignment_handler.assignment(start_position,st,type_any)
               end
            end
            i := i + 1
         end
      end

   safety_check is do end

   mapping_c_target(target_type: E_TYPE) is
      do
         compile_to_c
      end

   mapping_c_arg(formal_arg_type: E_TYPE) is
      do
         compile_to_c
      end

   collect_c_tmp is
      do
      end

   compile_to_c is
      local
         wa: ARRAY[RUN_FEATURE_2]
         rf2: RUN_FEATURE_2
         i: INTEGER
         ct, st, dt: E_TYPE
      do
         manifest_array_pool.c_call(result_type)
         cpp.put_character('(')
         ct := current_type
         wa := ct.run_class.writable_attributes
         vwst1_check(wa)
         cpp.put_integer(array_count(wa))
         if wa /= Void then
            from
               i := wa.upper
            until
               i = 0
            loop
               rf2 := wa.item(i)
               if list = Void or else not list.has(rf2.name) then
                  cpp.put_character(',')
                  st := rf2.result_type
                  if st.is_expanded then
                     dt := st.actual_reference(Void)
                     assignment_handler.c_conversion_call(st,dt)
                  end
                  cpp.print_current
                  if current_type.is_expanded then
                     cpp.put_character('.')
                  else
                     cpp.put_string(once "->")
                  end
                  cpp.put_character('_')
                  cpp.put_string(rf2.name.to_string)
                  if st.is_expanded then
                     cpp.put_character(')')
                  end
               end
               i := i - 1
            end
         end
         cpp.put_character(')')
      end

   c_frame_descriptor(format, locals: STRING) is
      do
      end

   compile_to_jvm is
      local
         ca: like code_attribute
         cp: like constant_pool
         count, i, j, idx, idx_array, space: INTEGER
         wa: ARRAY[RUN_FEATURE_2]
         rf2: RUN_FEATURE_2
      do
         ca := code_attribute
         cp := constant_pool
         wa := current_type.run_class.writable_attributes
         count := array_count(wa)
         result_type.run_class.jvm_basic_new
         ca.opcode_dup
         ca.opcode_iconst_1
         idx_array := result_type.run_class.jvm_constant_pool_index
         idx := cp.idx_fieldref4(idx_array,as_lower,fz_i)
         ca.opcode_putfield(idx,-2)
         ca.opcode_dup
         ca.opcode_push_integer(count)
         idx := cp.idx_fieldref4(idx_array,as_upper,fz_i)
         ca.opcode_putfield(idx,-2)
         ca.opcode_dup
         ca.opcode_push_integer(count)
         idx := cp.idx_fieldref4(idx_array,as_capacity,fz_i)
         ca.opcode_putfield(idx,-2)
         if count > 0 then
            -- pile = array
            ca.opcode_push_integer(count)
            type_any.jvm_xnewarray
            -- pile = array storage
            ca.opcode_dup2
            -- pile = array storage array storage
            tmp_string.clear
            tmp_string.extend('[')
            tmp_string.append(jvm_root_descriptor)
            idx := cp.idx_fieldref4(idx_array,as_storage,tmp_string)
            ca.opcode_putfield(idx,-2)
            -- pile = array storage
            from
               i := wa.upper
               j := 0
            until
               i = 0
            loop
               rf2 := wa.item(i)
               if list = Void or else not list.has(rf2.name) then
                  if j < count - 1 then
                     ca.opcode_dup
                  end
                  ca.opcode_push_integer(j)
                  current_type.jvm_push_local(0)
                  idx := cp.idx_fieldref(rf2)
                  ca.opcode_getfield(idx,0)
                  space := rf2.result_type.jvm_convert_to(type_any)
                  result_type.jvm_xastore
                  j := j + 1
               end
               i := i - 1
            end
         end
      end

   compile_target_to_jvm is
      do
      end

   jvm_branch_if_false: INTEGER is
      do
      end

   jvm_branch_if_true: INTEGER is
      do
      end

   compile_to_jvm_into(dest: E_TYPE): INTEGER is
      do
         Result := 1
         compile_to_jvm
      end

   result_type: TYPE_ARRAY is
      do
         if result_type_memory = Void then
            !!result_type_memory.make(start_position,type_any)
            result_type_memory := result_type_memory.to_runnable(type_any)
            result_type_memory.run_class.set_at_run_time
            result_type_memory.load_basic_features
            manifest_array_pool.register(result_type_memory)
         end
         Result := result_type_memory
      end

   to_runnable(ct: E_TYPE): like Current is
      do
         if current_type = Void then
            current_type := ct
            Result := Current
         else
            !!Result.make(start_position,list)
            Result := Result.to_runnable(ct)
         end
      end

   simplify_1_, simplify_2: like Current is
      do
	 Result := Current
      end
   
   stupid_switch(run_time_set: RUN_TIME_SET): BOOLEAN is do end

   pretty_print is
      do
         pretty_printer.keyword(fz_strip)
         pretty_printer.put_character('(')
         pretty_printer.indent_level_increment
         if list /= Void then
            list.pretty_print
         end
         pretty_printer.put_character(')')
         pretty_printer.indent_level_decrement
      end

   print_as_target is
      do
         pretty_print
         pretty_printer.put_character('.')
      end

   bracketed_pretty_print is
      do
         pretty_printer.put_character('(')
         pretty_print
         pretty_printer.put_character(')')
      end

   short is
      do
         short_print.hook_or(once "strip_open",once "strip (")
         if list /= Void then
            list.short
         end
         short_print.hook_or(once "strip_close",once ")")
      end

   short_target is
      do
         short
         short_print.a_dot
      end

   precedence: INTEGER is
      do
         Result := 11
      end

   jvm_assign_creation, jvm_assign is
      do
      end

feature {E_STRIP_VISITOR}

   accept(visitor: E_STRIP_VISITOR) is
      do
         visitor.visit_e_strip(Current)
      end

feature {NONE}

   list: FEATURE_NAME_LIST

   make(sp: like start_position; l: like list) is
      require
         not sp.is_unknown
      do
         start_position := sp
         list := l
      ensure
         start_position = sp
         list = l
      end

   vwst1: STRING is "This is not an attribute of Current (VWST.1)."

   vwst1_check(wa: ARRAY[RUN_FEATURE_2]) is
      local
         i, j: INTEGER
         fn: FEATURE_NAME
         rf2: RUN_FEATURE_2
      do
         if wa = Void then
            if list = Void then
            else
               error_handler.add_position(list.item(1).start_position)
               error_handler.append(vwst1)
               error_handler.print_as_error
            end
         elseif list /= Void then
            from
               i := list.count
            until
               i = 0
            loop
               fn := list.item(i)
               from
                  j := wa.upper
                  rf2 := Void
               until
                  j <= 0
               loop
                  rf2 := wa.item(j)
                  if rf2.name.to_string = fn.to_string then
                     j := -1
                  else
                     j := j - 1
                  end
               end
               if j = 0 then
                  error_handler.add_position(fn.start_position)
                  error_handler.append(vwst1)
                  error_handler.print_as_error
               end
               i := i - 1
            end
         end
      end

   result_type_memory: like result_type

   array_count(wa: ARRAY[RUN_FEATURE_2]): INTEGER is
      do
         if wa /= Void then
            Result := wa.count
         end
         if list /= Void then
            Result := Result - list.count
         end
      ensure
         Result >= 0
      end

   tmp_string: STRING is
      once
         !!Result.make(32)
      end

end -- E_STRIP
