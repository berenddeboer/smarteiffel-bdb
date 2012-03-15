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
deferred class ABSTRACT_CURRENT
   --
   -- Handling of the pseudo variable "Current".
   --

inherit EXPRESSION

feature

   start_position: POSITION

   result_type: E_TYPE
         -- Non Void when checked

   is_current: BOOLEAN is True

   is_writable: BOOLEAN is False

   is_manifest_string: BOOLEAN is False

   is_static: BOOLEAN is False

   once_pre_computable: BOOLEAN is False

   is_result: BOOLEAN is False

   is_void: BOOLEAN is False

   side_effect_free: BOOLEAN is True

   use_current: BOOLEAN is True

   extra_bracket_flag: BOOLEAN is False

   isa_dca_inline_argument: INTEGER is 0

   frozen start_lookup_class: BASE_CLASS is
      do
         Result := start_position.base_class
      end

   to_string, to_key: STRING is
      do
         Result := as_current
      end

   frozen to_integer_or_error: INTEGER is
      do
	 to_integer_error
      end

   frozen assertion_check(tag: CHARACTER) is
      do
      end

   frozen afd_check is
      do
      end

   frozen safety_check is
      do
      end

   frozen dca_inline_argument(formal_arg_type: E_TYPE) is
      do
      end

   frozen mapping_c_target(target_type: E_TYPE) is
      local
         flag: BOOLEAN
      do
         if is_written then
            flag := cpp.call_invariant_start(target_type)
         end
         cpp.print_current
         if flag then
            cpp.call_invariant_end
         end
      end

   frozen mapping_c_arg(formal_arg_type: E_TYPE) is
      local
         rt: like result_type
      do
         rt := result_type.run_type
         if rt.is_reference then
            if formal_arg_type.is_reference then
               -- Reference into Reference :
               cpp.put_string(fz_cast_t0_star)
               cpp.print_current
            else
               -- Reference into Expanded :
               cpp.print_current
            end
         elseif formal_arg_type.is_reference then
            -- Expanded into Reference :
            cpp.print_current
         elseif rt.is_user_expanded then
            -- User Expanded into User Expanded :
            if not rt.is_dummy_expanded then
               cpp.put_character('*')
            end
            cpp.print_current
         else
            -- Kernel Expanded into Kernel Expanded :
            cpp.print_current
         end
      end

   frozen c_frame_descriptor(format, locals: STRING) is
      do
      end

   frozen collect_c_tmp is
      do
      end

   frozen compile_to_c is
      do
         if result_type.is_user_expanded
	    and then
	    not result_type.is_dummy_expanded
	  then
	    cpp.put_character('*')
         end
         cpp.print_current
      end

   frozen compile_to_jvm is
      do
         result_type.jvm_push_local(0)
      end

   frozen compile_target_to_jvm is
      do
         if is_written then
            standard_compile_target_to_jvm
         else
            compile_to_jvm
         end
      end

   frozen jvm_branch_if_false: INTEGER is
      do
         compile_to_jvm
         Result := code_attribute.opcode_ifeq
      end

   frozen jvm_branch_if_true: INTEGER is
      do
         compile_to_jvm
         Result := code_attribute.opcode_ifne
      end

   frozen compile_to_jvm_into(dest: E_TYPE): INTEGER is
      do
         Result := standard_compile_to_jvm_into(dest)
      end

   frozen to_runnable(ct: E_TYPE): like Current is
      do
         if result_type = Void then
            result_type := ct
            Result := Current
         else
            !!Result.make(start_position)
            Result := Result.to_runnable(ct)
         end
      end

   frozen simplify_1_, frozen simplify_2: like Current is
      do
	 Result := Current
      end
   
   frozen stupid_switch(run_time_set: RUN_TIME_SET): BOOLEAN is do end

   frozen precedence: INTEGER is
      do
         Result := atomic_precedence
      end

   frozen bracketed_pretty_print, frozen pretty_print is
      do
         pretty_printer.put_string(as_current)
      end

   frozen print_as_target is
      do
         if is_written then
            pretty_printer.put_string(as_current)
            pretty_printer.put_character('.')
         end
      end

   frozen short is
      do
         short_print.hook_or(as_current,as_current)
      end

   frozen short_target is
      do
         if is_written then
            short
            short_print.a_dot
         end
      end

   frozen jvm_assign_creation, jvm_assign is
      do
      end

feature {ABSTRACT_CURRENT_VISITOR}

   accept(visitor: ABSTRACT_CURRENT_VISITOR) is
      deferred
      end

feature {NONE}

   is_written: BOOLEAN is
         -- True when it is a really written Current.
      deferred
      end

   make(sp: like start_position) is
      require
         not sp.is_unknown
      do
         start_position := sp
      ensure
         start_position = sp
      end

end -- ABSTRACT_CURRENT

