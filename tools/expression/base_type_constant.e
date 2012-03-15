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
deferred class BASE_TYPE_CONSTANT
   --
   -- Common root of : BOOLEAN_CONSTANT, CHARACTER_CONSTANT,
   -- INTEGER_CONSTANT and REAL_CONSTANT.
   --

inherit EXPRESSION

feature

   is_writable,
   is_current,
   is_manifest_string,
   is_result,
   is_void,
   use_current
   : BOOLEAN is False

   side_effect_free,
   extra_bracket_flag
   : BOOLEAN is True

   start_position: POSITION

   result_type: E_TYPE

   frozen start_lookup_class: BASE_CLASS is
      do
	 if result_type /= Void then
	    Result := result_type.base_class
	 end
      end

   frozen afd_check is do end

   frozen safety_check is do end

   once_pre_computable: BOOLEAN is True

   frozen c_frame_descriptor(format, locals: STRING) is do end

   frozen collect_c_tmp is do end

   to_runnable(ct: E_TYPE): like Current is
      deferred
      ensure then
         Result = Current
         result_type = result_type.to_runnable(ct)
      end

   frozen stupid_switch(run_time_set: RUN_TIME_SET): BOOLEAN is
      do
         Result := true
      end

   frozen assertion_check(tag: CHARACTER) is do end

   frozen isa_dca_inline_argument: INTEGER is
      do
         if is_static then
            Result := -1
         end
      end

   frozen dca_inline_argument(formal_arg_type: E_TYPE) is
      do
         mapping_c_arg(formal_arg_type)
      end

   frozen mapping_c_target(target_type: E_TYPE) is
      do
         compile_to_c
      end

   frozen mapping_c_arg(formal_arg_type: E_TYPE) is
      do
         compile_to_c
      end

   frozen bracketed_pretty_print, frozen pretty_print is
      do
         pretty_printer.put_string(to_string)
      end

   frozen print_as_target is
      do
         pretty_printer.put_character('(')
         pretty_print
         pretty_printer.put_character(')')
         pretty_printer.put_character('.')
      end

   frozen short is
      do
         short_print.a_base_type_constant(to_string)
      end

   frozen short_target is
      do
         bracketed_short
         short_print.a_dot
      end

   frozen precedence: INTEGER is
      do
         Result := atomic_precedence
      end

   frozen base_class_name: CLASS_NAME is
      do
         Result := result_type.base_class_name
      end

   frozen jvm_assign_creation, jvm_assign is
      do
	 check false end
      end

feature {BASE_TYPE_CONSTANT_VISITOR}

   accept(visitor: BASE_TYPE_CONSTANT_VISITOR) is
      deferred
      end

feature {NONE}

   to_string: STRING is
      deferred
      end

end -- BASE_TYPE_CONSTANT

