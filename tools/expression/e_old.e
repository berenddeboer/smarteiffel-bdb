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
class E_OLD
   --
   -- To store instruction "old ..." usable in an ensure clause.
   --

inherit EXPRESSION

creation make

feature

   expression: EXPRESSION
	 -- The one after keyword "old".

   is_current: BOOLEAN is False

   is_writable: BOOLEAN is False

   is_static: BOOLEAN is False

   once_pre_computable: BOOLEAN is False

   is_manifest_string: BOOLEAN is False

   is_result: BOOLEAN is False

   is_void: BOOLEAN is False

   side_effect_free: BOOLEAN is False

   isa_dca_inline_argument: INTEGER is 0

   extra_bracket_flag: BOOLEAN is True

   to_integer_or_error: INTEGER is
      do
	 to_integer_error
      end

   start_lookup_class: BASE_CLASS is
      do
         Result := expression.start_lookup_class
      end

   dca_inline_argument(formal_arg_type: E_TYPE) is
      do
      end

   result_type: E_TYPE is
      do
         Result := expression.result_type
      end

   assertion_check(tag: CHARACTER) is
      do
         if vaol_check_memory.item = Void then
            vaol_check_memory.set_item(Current)
         else
            error_handler.add_position(vaol_check_memory.item.start_position)
            error_handler.append("Must not use old inside some old %
                       %expression (VAOL.2).")
            error_handler.print_as_fatal_error
         end
         expression.assertion_check(tag)
         vaol_check_memory.clear
      end

   afd_check is
      do
         expression.afd_check
      end

   safety_check is
      do
         check False end
      end

   to_runnable(ct: E_TYPE): like Current is
      local
         exp: like expression
      do
         if current_type = Void then
            current_type := ct
            exp := expression.to_runnable(ct)
            if exp = Void then
               error(start_position,"Bad old expression.")
            else
               expression := exp
            end
	    smart_eiffel.top_rf.register_old(Current)
	    Result := Current
         else
            !!Result.make(expression)
            Result := Result.to_runnable(ct)
         end
      end

   simplify_1_, simplify_2: like Current is
      do
	 Result := Current
      end
   
   stupid_switch(run_time_set: RUN_TIME_SET): BOOLEAN is
      do
         Result := True
      end

   start_position: POSITION is
      do
         Result := expression.start_position
      end

   bracketed_pretty_print is
      do
         pretty_printer.put_character('(')
         pretty_print
         pretty_printer.put_character(')')
      end

   pretty_print is
      do
         pretty_printer.keyword(fz_old)
         pretty_printer.indent_level_increment
         expression.pretty_print
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
      do
         short_print.hook_or(once "old",once "old ")
         expression.short
      end

   short_target is
      do
         bracketed_short
         short_print.a_dot
      end

   precedence: INTEGER is
      do
         Result := 11
      end

   mapping_c_target(target_type: E_TYPE) is
      do
         compile_to_c
      end

   mapping_c_arg(formal_arg_type: E_TYPE) is
      do
         compile_to_c
      end

   compile_to_c_old is
      local
         t: E_TYPE
      do
         t := result_type.run_type
         tmp_string.copy(local_c_name)
         tmp_string.extend('=')
         cpp.put_string(tmp_string)
         expression.mapping_c_arg(t)
         cpp.put_string(fz_00)
      end

   collect_c_tmp is
      do
      end

   compile_to_c is
      do
         cpp.put_string(local_c_name)
      end

   compile_to_jvm_old is
      local
         e: like expression
         rt: E_TYPE
      do
         e := expression
         rt := e.result_type.run_type
         id := code_attribute.extra_local(rt)
         e.compile_to_jvm
         rt.jvm_write_local_creation(id)
      end

   compile_to_jvm is
      do
         expression.result_type.jvm_push_local(id)
      end

   compile_target_to_jvm is
      do
         standard_compile_target_to_jvm
      end

   jvm_branch_if_false: INTEGER is
      do
         Result := jvm_standard_branch_if_false
      end

   jvm_branch_if_true: INTEGER is
      do
         Result := jvm_standard_branch_if_true
      end

   compile_to_jvm_into(dest: E_TYPE): INTEGER is
      do
         Result := standard_compile_to_jvm_into(dest)
      end

   jvm_assign_creation, jvm_assign is
      do
      end

   use_current: BOOLEAN is
      do
         Result := expression.use_current
      end

feature {E_ENSURE}

   c_frame_descriptor(format, locals: STRING) is
      local
         t: E_TYPE; name: STRING; p: POSITION
      do
         name := local_c_name
         t := result_type.run_type
	 locals.append(once "(void**)&")
	 locals.append(name)
	 locals.extend(',')
	 p := start_position
	 format.append(once "old value")
	 t.c_frame_descriptor_in(format)
      end

feature {RUN_FEATURE}

   c_declare_for_old is
      local
         t: E_TYPE; name: STRING; p: POSITION
      do
         name := local_c_name
         t := result_type.run_type
         tmp_string.clear_count
         t.c_type_for_argument_in(tmp_string)
         tmp_string.extend(' ')
         tmp_string.append(name)
         tmp_string.extend('=')
         t.c_initialize_in(tmp_string)
         tmp_string.append(fz_00)
         cpp.put_string(tmp_string)
      end

feature {E_OLD_VISITOR}

   accept(visitor: E_OLD_VISITOR) is
      do
         visitor.visit_e_old(Current)
      end

feature {NONE}

   current_type: E_TYPE

   local_c_name_memory: STRING
         -- The C name for the local variable.

   id: INTEGER
         -- Used in Java byte code to gives a number to the
         -- the extra local variable.

   make(exp: like expression) is
      require
         exp /= Void
      do
         expression := exp
      ensure
         expression = exp
      end

   special_old_counter: COUNTER is
      -- This counter is only used to provide unique name for old 
      -- expression where column is unknown.
      once
	 create Result
      end

   local_c_name: STRING is
      local
	 suffix: INTEGER
      do
         if local_c_name_memory = Void then
            tmp_string.clear_count
            tmp_string.extend('o')
            start_position.base_class.id.append_in(tmp_string)
            tmp_string.extend('_')
            start_position.line.append_in(tmp_string)
            tmp_string.extend('_')
	    suffix := start_position.column
	    if suffix = 0 then
	       special_old_counter.increment
	       suffix := special_old_counter.value
	       tmp_string.extend('s')
	    end
            suffix.append_in(tmp_string)
            local_c_name_memory := tmp_string.twin
         end
         Result := local_c_name_memory
      end

   tmp_string: STRING is
      once
         !!Result.make(12)
      end

   vaol_check_memory: REFERENCE[E_OLD] is
      once
         !!Result
      end

invariant

   expression /= Void

end -- E_OLD

