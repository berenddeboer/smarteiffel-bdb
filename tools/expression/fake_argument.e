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
class FAKE_ARGUMENT
   --
   -- This pseudo expression is used to simulate some argument.
   --

inherit EXPRESSION

creation make

feature

   is_current: BOOLEAN is False

   is_writable: BOOLEAN is False

   is_static: BOOLEAN is False

   once_pre_computable: BOOLEAN is False

   is_manifest_string: BOOLEAN is False

   is_result: BOOLEAN is False

   is_void: BOOLEAN is False

   use_current: BOOLEAN is False

   side_effect_free: BOOLEAN is True

   precedence: INTEGER is
      do
         Result := atomic_precedence
      end

   to_integer_or_error: INTEGER is
      do
	 to_integer_error
      end

   start_lookup_class: BASE_CLASS is
      do
         Result := result_type.base_class
      end

   result_type: E_TYPE

   start_position: POSITION is
      do
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

   to_runnable(ct: E_TYPE): like Current is
      do
         Result := Current
      end

   simplify_1_, simplify_2: like Current is
      do
	 Result := Current
      end
   
   stupid_switch(run_time_set: RUN_TIME_SET): BOOLEAN is do end

   isa_dca_inline_argument: INTEGER is 0

   dca_inline_argument(formal_arg_type: E_TYPE) is
      do
	 check False end
      end

   compile_to_c is
      do
         cpp.put_character('a')
	 cpp.put_integer(rank)
      end

   mapping_c_target(target_type: E_TYPE) is
      do
	 target_type.mapping_cast
	 compile_to_c
      end

   mapping_c_arg(formal_arg_type: E_TYPE) is
      do
	 compile_to_c
      end

   c_frame_descriptor(format, locals: STRING) is
      do
      end

   collect_c_tmp is do end

   compile_to_jvm is
      local
         -- jvm_offset: INTEGER
      do
	 not_yet_implemented
         -- jvm_offset := jvm.argument_offset_of(Current)
         -- result_type.run_type.jvm_push_local(jvm_offset)
      end

   jvm_branch_if_false: INTEGER is
      do
         compile_to_jvm
         Result := code_attribute.opcode_ifeq
      end

   jvm_branch_if_true: INTEGER is
      do
         compile_to_jvm
         Result := code_attribute.opcode_ifne
      end

   compile_to_jvm_into(dest: E_TYPE): INTEGER is
      do
         Result := standard_compile_to_jvm_into(dest)
      end

   jvm_assign, jvm_assign_creation is
      do
         check False end
      end

   compile_target_to_jvm is
      do
         compile_to_jvm
      end

   extra_bracket_flag: BOOLEAN is
      do
	 check False end
      end

   pretty_print is
      do
	 check False end
      end

   print_as_target is
      do
	 check False end
      end

   bracketed_pretty_print is
      do
	 check False end
      end

   short is
      do
	 check False end
      end

   short_target is
      do
	 check False end
      end

feature {FAKE_ARGUMENT_VISITOR}

   accept(visitor: FAKE_ARGUMENT_VISITOR) is
      do
         visitor.visit_fake_argument(Current)
      end

feature {NONE}

   rank: INTEGER

   make(rt: like result_type; r: like rank) is
      require
         rt /= Void
	 r > 0
      do
         result_type := rt
	 rank := r
      ensure
         result_type = rt
	 rank = r
      end

invariant

   rank > 0

   result_type /= Void

end -- FAKE_ARGUMENT
