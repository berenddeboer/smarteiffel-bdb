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
class MANIFEST_ARRAY
   --
   -- Like:  << foo , bar >>
   --

inherit EXPRESSION

creation make

feature

   start_position: POSITION
         -- Of first character '<'.

   result_type: TYPE_ARRAY
         -- Computed according to the actual `list'.

   is_current: BOOLEAN is False

   is_writable: BOOLEAN is False

   is_manifest_string: BOOLEAN is False

   is_result: BOOLEAN is False

   is_void: BOOLEAN is False

   extra_bracket_flag: BOOLEAN is True
   
   precedence: INTEGER is 2

   side_effect_free: BOOLEAN is False

   to_integer_or_error: INTEGER is
      do
	 to_integer_error
      end

   start_lookup_class: BASE_CLASS is do end

   is_static: BOOLEAN is False

   isa_dca_inline_argument: INTEGER is 0

   dca_inline_argument(formal_arg_type: E_TYPE) is
      do
	 check False end
      end

   once_pre_computable: BOOLEAN is
      local
         i: INTEGER
         e: EXPRESSION
      do
         if list = Void then
            Result := True
         elseif result_type.generic_list.first.is_string then
            from
               Result := True
               i := list.upper
            until
               not Result or else i < list.lower
            loop
               e := list.item(i)
               Result := e.once_pre_computable
               i := i - 1
            end
         end
      end

   assertion_check(tag: CHARACTER) is
      local
         i: INTEGER
         e: EXPRESSION
      do
         if list /= Void then
            from
               i := list.upper
            until
               i < list.lower
            loop
               e := list.item(i)
               e.assertion_check(tag)
               i := i - 1
            end
         end
      end

   afd_check is
      local
         i: INTEGER
      do
         if list /= Void then
            from
               i := list.upper
            until
               i < list.lower
            loop
               list.item(i).afd_check
               i := i - 1
            end
         end
      end

   safety_check is
      local
         i: INTEGER
      do
         if list /= Void then
            from
               i := list.upper
            until
               i < list.lower
            loop
               list.item(i).safety_check
               i := i - 1
            end
         end
      end

   mapping_c_target(target_type: E_TYPE) is
      do
         cpp.put_character('(')
         target_type.mapping_cast
         compile_to_c
         cpp.put_character(')')
      end

   mapping_c_arg(formal_arg_type: E_TYPE) is
      do
         compile_to_c
      end

   collect_c_tmp is
      local
         i: INTEGER
      do
	 if list /= Void then
	    from
	       i := list.upper
	    until
	       i < list.lower
	    loop
	       list.item(i).collect_c_tmp
	       i := i - 1
	    end
	 end
      end

   compile_to_c is
      local
         i: INTEGER
         formal_type, actual_type: E_TYPE
         adr: BOOLEAN
         e: EXPRESSION
      do
         manifest_array_pool.c_call(result_type)
         formal_type := result_type.generic_list.item(1).run_type
         cpp.put_character('(')
         if list = Void then
            cpp.put_character('0')
         else
            adr := formal_type.is_user_expanded
            cpp.put_integer(list.count)
            from
               i := list.lower
            until
               i > list.upper
            loop
               cpp.put_character(',')
               cpp.put_character('%N')
               if adr then
                  cpp.put_character('&')
               end
               e := list.item(i)
               actual_type := e.result_type.run_type
               e.compile_to_c
               i := i + 1
            end
         end
         cpp.put_character(')')
      end

   c_frame_descriptor(format, locals: STRING) is
      local
         i: INTEGER
      do
         if list /= Void then
            from
               i := list.upper
            until
               i < list.lower
            loop
               list.item(i).c_frame_descriptor(format,locals)
               i := i - 1
            end
         end
      end

   compile_target_to_jvm, compile_to_jvm is
      local
         rt, elt_type: E_TYPE
         i, idx, space: INTEGER
         rc: RUN_CLASS
         idx_rc: INTEGER
         cp: like constant_pool
         ca: like code_attribute
      do
         cp := constant_pool
         ca := code_attribute
         rt := result_type.run_type
         rc := rt.run_class
         elt_type := rt.generic_list.first.run_type
         idx_rc := rc.jvm_constant_pool_index
         rc.jvm_basic_new
         -- Set lower:
         idx := cp.idx_fieldref4(idx_rc,as_lower,fz_i)
         ca.opcode_dup
         ca.opcode_iconst_1
         ca.opcode_putfield(idx,-2)
         -- Set upper:
         idx := cp.idx_fieldref4(idx_rc,as_upper,fz_i)
         ca.opcode_dup
         if list = Void then
            ca.opcode_iconst_0
         else
            ca.opcode_push_integer(list.count)
         end
         ca.opcode_putfield(idx,-2)
         -- Set capacity:
         idx := cp.idx_fieldref4(idx_rc,as_capacity,fz_i)
         ca.opcode_dup
         if list = Void then
            ca.opcode_iconst_0
         else
            ca.opcode_push_integer(list.count)
         end
         ca.opcode_putfield(idx,-2)
         -- Set storage:
         idx := cp.idx_fieldref4(idx_rc,as_storage,sd(elt_type))
         ca.opcode_dup
         if list = Void then
            ca.opcode_aconst_null
         else
            ca.opcode_push_integer(list.count)
            elt_type.jvm_xnewarray
            from
               i := list.lower
            until
               i > list.upper
            loop
               ca.opcode_dup
               ca.opcode_push_integer(i)
               space := list.item(i).compile_to_jvm_into(elt_type)
               elt_type.jvm_xastore
               i := i + 1
            end
         end
         ca.opcode_putfield(idx,-2)
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

   use_current: BOOLEAN is
      local
         i: INTEGER
      do
         if list /= Void then
            from
               i := list.upper
            until
               i < list.lower or else Result
            loop
               Result := list.item(i).use_current
               i := i - 1
            end
         end
      end

   stupid_switch(run_time_set: RUN_TIME_SET): BOOLEAN is
      local
         i: INTEGER
      do
         Result := True
         if list /= Void then
            from
               i := list.upper
            until
               not Result or else i < list.lower
            loop
               Result := list.item(i).stupid_switch(run_time_set)
               i := i - 1
            end
         end
      end

   to_runnable(ct: E_TYPE): like Current is
      local
         i: INTEGER; e: EXPRESSION; elt: E_TYPE
      do
         if current_type = Void then
            current_type := ct
            if list = Void then
               elt := type_any
            else
               from
                  i := list.upper
               until
                  i < list.lower
               loop
                  e := list.item(i).to_runnable(ct)
                  if e = Void then
                     error_handler.add_position(start_position)
                     error(list.item(i).start_position,
                           "Bad expression in manifest array.")
                     i := list.lower - 1
                  else
                     list.put(e,i)
                     if elt = Void then
                        elt := e.result_type
                     else
                        elt := elt.smallest_ancestor(e.result_type)
                     end
                     i := i - 1
                  end
               end
            end
            if nb_errors = 0 then
               elt := elt.run_type
               create result_type.make(start_position,elt)
               result_type.run_class.set_at_run_time
               result_type.load_basic_features
               Result := Current
               if list /= Void then
                  from
                     i := list.upper
                  until
                     i < list.lower
                  loop
                     e := list.item(i)
                     e := assignment_handler.implicit_cast(e, elt)
                     assignment_handler.assignment(e.start_position,
						   e.result_type,
						   elt)
                     list.put(e,i)
                     i := i - 1
                  end
               end
               manifest_array_pool.register(result_type)
            end
         elseif list = Void then
            Result := Current
         else
            create Result.make(start_position,list.twin)
            Result := Result.to_runnable(ct)
         end
      end

   simplify_1_, simplify_2: like Current is
      do
	 Result := Current
      end
   
   bracketed_pretty_print is
      do
         pretty_printer.put_character('(')
         pretty_print
         pretty_printer.put_character(')')
      end

   pretty_print is
      local
         i: INTEGER
      do
         pretty_printer.put_string(fz_c_shift_left)
         pretty_printer.indent_level_increment
         if list /= Void then
            from
               i := list.lower
            until
               i > list.upper
            loop
               list.item(i).pretty_print
               i := i + 1
               if i <= list.upper then
                  pretty_printer.put_character(',')
               end
            end
         end
         pretty_printer.put_string(fz_c_shift_right)
         pretty_printer.indent_level_decrement
      end

   print_as_target is
      do
         pretty_printer.put_character('(')
         pretty_print
         pretty_printer.put_character(')')
         pretty_printer.put_character('.')
      end

   short is
      local
         i: INTEGER
      do
         short_print.hook_or("op_ma",fz_c_shift_left)
         if list /= Void then
            from
               i := list.lower
            until
               i > list.upper
            loop
               list.item(i).short
               i := i + 1
               if i <= list.upper then
                  short_print.hook_or("ma_sep",",")
               end
            end
         end
         short_print.hook_or("cl_ma",fz_c_shift_right)
      end

   short_target is
      do
         bracketed_short
         short_print.a_dot
      end

   jvm_assign_creation, jvm_assign is
      do
      end

feature {MANIFEST_ARRAY_VISITOR}

   accept(visitor: MANIFEST_ARRAY_VISITOR) is
      do
         visitor.visit_manifest_array(Current)
      end

feature {NONE}

   list: FIXED_ARRAY[EXPRESSION]
         -- Void or elements in the manifest array.

   current_type: E_TYPE

   make(sp: like start_position; l: like list) is
      require
         not sp.is_unknown
         l /= Void implies not l.is_empty
      do
         start_position := sp
         list := l
      ensure
         start_position = sp
         list = l
      end

   sd(elt_type: E_TYPE): STRING is
         -- The JVM descriptor for `storage'.
      do
         sd_buffer.clear
         sd_buffer.extend('[')
         elt_type.jvm_descriptor_in(sd_buffer)
         Result := sd_buffer
      end

   sd_buffer: STRING is
      once
         !!Result.make(16)
      end

invariant

   not start_position.is_unknown

   list /= Void implies not list.is_empty

end -- MANIFEST_ARRAY
