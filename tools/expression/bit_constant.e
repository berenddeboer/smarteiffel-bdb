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
class BIT_CONSTANT
   --
   -- For Manifest Constant BIT_N.
   --

inherit EXPRESSION

creation make

feature

   start_position: POSITION
         -- Of the first bit.

   value: STRING
         -- Only '0' and '1'.

   result_type: TYPE_BIT_1

   is_writable: BOOLEAN is False

   is_current: BOOLEAN is False

   is_manifest_string: BOOLEAN is False

   is_result: BOOLEAN is False

   is_void: BOOLEAN is False

   extra_bracket_flag: BOOLEAN is True
   
   use_current: BOOLEAN is False

   once_pre_computable: BOOLEAN is False

   side_effect_free: BOOLEAN is True

   start_lookup_class: BASE_CLASS is do end

   assertion_check(tag: CHARACTER) is do end

   to_integer_or_error: INTEGER is
      do
	 to_integer_error
      end

   is_static: BOOLEAN is False

   isa_dca_inline_argument: INTEGER is 0

   dca_inline_argument(formal_arg_type: E_TYPE) is
      do
	 check False end
      end

   afd_check is do end

   safety_check is do end

   mapping_c_target(target_type: E_TYPE) is
      do
         mapping_c_arg(target_type)
      end

   mapping_c_arg(formal_arg_type: E_TYPE) is
      do
         compile_to_c
      end

   collect_c_tmp is do end

   compile_to_c is
      do
         if result_type.is_c_unsigned_ptr then
            cpp.register_bit_constant(Current)
         else
            cpp.put_string(fz_0x)
            cpp.put_string(hexa)
         end
      end

   c_frame_descriptor(format, locals: STRING) is do end

   compile_target_to_jvm, compile_to_jvm is
      local
         i, idx: INTEGER
         ca: like code_attribute
         cp: like constant_pool
      do
         ca := code_attribute
         cp := constant_pool
         idx := cp.idx_class2(fz_java_util_bitset)
         ca.opcode_new(idx)
         ca.opcode_dup
         ca.opcode_push_integer(value.count)
         idx := cp.idx_methodref3(fz_java_util_bitset,fz_35,fz_27)
         ca.opcode_invokespecial(idx,0)
         from
            i := value.count
         until
            i = 0
         loop
            if value.item(i) = '1' then
               ca.opcode_dup
               ca.opcode_push_integer(i - 1)
               idx := cp.idx_methodref3(fz_java_util_bitset,fz_set,fz_27)
               ca.opcode_invokevirtual(idx,-2)
            end
            i := i - 1
         end
      end

   jvm_branch_if_false: INTEGER is
      do
      end

   jvm_branch_if_true: INTEGER is
      do
      end

   compile_to_jvm_into(dest: E_TYPE): INTEGER is
      do
         Result := standard_compile_to_jvm_into(dest)
      end

   jvm_assign_creation, jvm_assign is
      do
      end

   to_runnable(ct: E_TYPE): like Current is
      local
         ic: INTEGER_CONSTANT
      do
         if result_type = Void then
            create ic.make(value.count, start_position)
            create result_type.make(start_position,ic)
            result_type := result_type.to_runnable(ct)
            result_type.run_class.set_at_run_time
            hexa := value.twin
            hexa.to_hexadecimal
         end
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

   precedence: INTEGER is
      do
         Result := atomic_precedence
      end

   bracketed_pretty_print, pretty_print is
      do
         pretty_printer.put_string(value)
         pretty_printer.put_character('B')
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
         from
            i := 1
         until
            i > value.count
         loop
            short_print.a_character(value.item(i))
            i := i + 1
         end
         short_print.a_character('B')
      end

   short_target is
      do
         bracketed_short
         short_print.a_dot
      end

feature {C_PRETTY_PRINTER}

   c_define is
      local
         i, k, digit_nb: INTEGER
      do
         digit_nb := digit_nb.object_size * 2
         k := hexa.count \\ digit_nb
         i := 1
         if k > 0 then
            from
               cpp.put_string(fz_0x)
            until
               k = 0
            loop
               cpp.put_character(hexa.item(i))
               i := i + 1
               k := k - 1
            end
            cpp.put_character(',')
         end
         from
         until
            i > hexa.count
         loop
            cpp.put_string(fz_0x)
            from
               k := digit_nb
            until
               k = 0
            loop
               cpp.put_character(hexa.item(i))
               i := i + 1
               k := k - 1
            end
            if i <= hexa.count then
               cpp.put_character(',')
            end
         end
      end

feature {BIT_CONSTANT_VISITOR}

   accept(visitor: BIT_CONSTANT_VISITOR) is
      do
         visitor.visit_bit_constant(Current)
      end

feature {NONE}

   id: INTEGER

   hexa: STRING

   make(sp: like start_position; s: STRING) is
      require
         s /= Void
         -- `s' contains only '0' and '1'.
      do
         start_position := sp
         value := s
      ensure
         value.count = s.count
      end

end -- BIT_CONSTANT
