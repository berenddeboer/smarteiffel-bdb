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
class E_VOID
   --
   -- Handling of the Eiffel `Void'.
   --

inherit EXPRESSION

creation make

feature

   start_position: POSITION

   is_void: BOOLEAN is True

   is_writable: BOOLEAN is False

   is_current: BOOLEAN is False

   is_result: BOOLEAN is False

   is_static: BOOLEAN is True

   extra_bracket_flag: BOOLEAN is False
   
   to_integer_or_error: INTEGER is 0

   once_pre_computable: BOOLEAN is True

   is_manifest_string: BOOLEAN is False

   use_current: BOOLEAN is False

   side_effect_free: BOOLEAN is True

   start_lookup_class: BASE_CLASS is do end

   bracketed_pretty_print, pretty_print is
      do
         pretty_printer.put_string(as_void)
      end

   to_string, to_key: STRING is
      do
         Result := as_void
      end

   isa_dca_inline_argument: INTEGER is -1

   dca_inline_argument(formal_arg_type: E_TYPE) is
      do
         mapping_c_arg(formal_arg_type)
      end

   assertion_check(tag: CHARACTER) is do end

   afd_check is do end

   safety_check is do end

   mapping_c_target(target_type: E_TYPE) is
      do
	 check False end
      end

   mapping_c_arg(formal_arg_type: E_TYPE) is
      do
         compile_to_c
      end

   short is
      do
         short_print.hook_or(as_void,as_void)
      end

   short_target is
      do
         short
         short_print.a_dot
      end

   collect_c_tmp is do end

   compile_to_c is
      do
         cpp.put_string(fz_null)
      end

   c_frame_descriptor(format, locals: STRING) is do end

   compile_target_to_jvm, compile_to_jvm is
      do
         code_attribute.opcode_aconst_null
      end

   jvm_branch_if_false: INTEGER is
      do
	 check False end
      end

   jvm_branch_if_true: INTEGER is
      do
	 check False end
      end

   compile_to_jvm_into(dest: E_TYPE): INTEGER is
      do
         Result := 1
         compile_to_jvm
      end

   result_type: TYPE_NONE is
      local
         unknown_position: POSITION
      once
         create Result.make(unknown_position)
      end

   to_runnable(ct: E_TYPE): like Current is
      do
         Result := Current
      end

   simplify_1_, simplify_2: like Current is
      do
	 Result := Current
      end
   
   stupid_switch(run_time_set: RUN_TIME_SET): BOOLEAN is
      do
         Result := True
      end

   print_as_target is
      do
	 check False end
      end

   precedence: INTEGER is
      do
         Result := atomic_precedence
      end

   jvm_assign_creation, jvm_assign is
      do
	 check False end
      end

feature {E_VOID_VISITOR}

   accept(visitor: E_VOID_VISITOR) is
      do
         visitor.visit_e_void(Current)
      end

feature {NONE}

   make(sp: like start_position) is
      require
         not sp.is_unknown
      do
         start_position := sp
      ensure
         sp = start_position
      end

end -- E_VOID
