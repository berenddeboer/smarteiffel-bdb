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
class ADDRESS_OF
   --
   -- For the special address form notation : $ feature_name
   --

inherit EXPRESSION

creation make

feature

   feature_name: FEATURE_NAME

   is_writable: BOOLEAN is False

   is_current: BOOLEAN is False

   once_pre_computable: BOOLEAN is False

   is_static: BOOLEAN is False

   is_result: BOOLEAN is False

   is_void: BOOLEAN is False

   is_manifest_string: BOOLEAN is False

   use_current: BOOLEAN is True

   side_effect_free: BOOLEAN is True

   extra_bracket_flag: BOOLEAN is False
   
   to_integer_or_error: INTEGER is
      do
	 to_integer_error
      end

   start_lookup_class: BASE_CLASS is
      local
	 cn: CLASS_NAME
      once
	 create cn.unknown_position(as_pointer)
         Result := smart_eiffel.base_class(cn)
      end

   isa_dca_inline_argument: INTEGER is 0

   dca_inline_argument(formal_arg_type: E_TYPE) is
      do
	 check False end
      end

   result_type: TYPE_POINTER is
      do
         Result := type_pointer
      end

   assertion_check(tag: CHARACTER) is
      do
      end

   afd_check is
      do
      end

   safety_check is
      do
      end

   compile_target_to_jvm, compile_to_jvm is
      do
         error_handler.add_position(start_position)
         fatal_error(fz_jvm_error)
      end

   jvm_branch_if_false: INTEGER is
      do
      end

   jvm_branch_if_true: INTEGER is
      do
      end

   compile_to_jvm_into(dest: E_TYPE): INTEGER is
      do
      end

   collect_c_tmp is
      do
      end

   compile_to_c is
      do
         cpp.put_string(once "/*$*/((void*)")
         run_feature.address_of_c_mapping
         cpp.put_character(')')
      end

   frozen mapping_c_target(target_type: E_TYPE) is
      do
         compile_to_c
      end

   frozen mapping_c_arg(formal_arg_type: E_TYPE) is
      do
         compile_to_c
      end

   c_frame_descriptor(format, locals: STRING) is
      do
      end

   to_runnable(ct: E_TYPE): like Current is
      local
         rc: RUN_CLASS
         bc: BASE_CLASS
      do
         if current_type = Void then
            current_type := ct
            rc := ct.run_class
            bc := ct.base_class
            if bc.has(feature_name) then
               run_feature := rc.get_rf_with(feature_name)
               address_of_pool.register_for(Current)
            else
               error_handler.add_position(feature_name.start_position)
               error_handler.append(fz_vuar4)
               error_handler.print_as_fatal_error
            end
            Result := Current
         else
            !!Result.make(feature_name)
            Result := Result.to_runnable(ct)
         end
      end

   simplify_1_, simplify_2: like Current is
      do
	 Result := Current
      end
   
   stupid_switch(run_time_set: RUN_TIME_SET): BOOLEAN is do end

   precedence: INTEGER is
      do
         Result := atomic_precedence
      end

   start_position: POSITION is
      do
         Result := feature_name.start_position
      end

   pretty_print is
      do
         pretty_printer.put_character('%D')
         feature_name.pretty_print
      end

   print_as_target is
      do
         check False end
      end

   bracketed_pretty_print is
      do
         pretty_printer.put_character('(')
         pretty_print
         pretty_printer.put_character(')')
      end

   short is
      do
         short_print.a_character('%D')
         feature_name.short
      end

   short_target is
      do
         bracketed_short
         short_print.a_dot
      end

   jvm_assign_creation, jvm_assign is
      do
      end

feature {ADDRESS_OF_POOL}

   run_feature: RUN_FEATURE
         -- Corresponding one when runnable.

feature {ADDRESS_OF_VISITOR}

   accept(visitor: ADDRESS_OF_VISITOR) is
      do
         visitor.visit_address_of(Current)
      end

feature {NONE}

   make(fn: like feature_name) is
      require
         fn /= Void
      do
         feature_name := fn
      ensure
         feature_name = fn
      end

   current_type: E_TYPE

invariant

   feature_name /= Void

end --  ADDRESS_OF
