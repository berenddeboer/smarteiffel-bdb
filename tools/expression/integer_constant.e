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
class INTEGER_CONSTANT
   --
   -- For Manifest Constant of class INTEGER.
   --

inherit BASE_TYPE_CONSTANT

creation make

creation {EIFFEL_PARSER} with, hexadecimal

feature

   is_static: BOOLEAN is True

   value_memory: INTEGER_64
	 -- We use here a 64 bit INTEGER to be able to store large values.

   size: INTEGER -- is 8, 16, 32 or 64.

   hexadecimal_flag: BOOLEAN
	 -- When the hexadecimal notation is used.

   underscore_flag: BOOLEAN
	 -- When the original notation use underscore characters.

   to_integer_or_error: INTEGER is
      do
	 Result := value_memory.to_integer
      end

   to_runnable(ct: E_TYPE): like Current is
      do
         Result := Current
	 if result_type = Void then
	    set_result_type
	 end
      end
   
   simplify_1_, simplify_2: like Current is
      do
	 Result := Current
      end
   
   compile_to_c is
      do
	 if hexadecimal_flag then
	    -- To view the corresponding hexadecimal value in the
	    -- generated C code:
	    string_buffer.copy(fz_open_c_comment)
	    append_in(string_buffer)
	    string_buffer.append(fz_close_c_comment)
	    cpp.put_string(string_buffer)	       
	 end
	 -- (Note: Unfortunately, it is not possible to use an inspect 
	 -- statement below because the INTEGER_64 tyepe is not 
	 -- supported by the current language definition.) 
	 if value_memory = Minimum_integer_8  then
	    cpp.put_string(once "INT8_MIN")
	 elseif value_memory = Minimum_integer_16 then
	    cpp.put_string(once "INT16_MIN")
	 elseif value_memory = Minimum_integer_32 then
	    cpp.put_string(once "INT32_MIN")
	 elseif value_memory = Minimum_integer_64 then
	    cpp.put_string(once "INT64_MIN")
	 else
	    cpp.put_string(once "INT")
	    cpp.put_integer(size)
	    cpp.put_string(once "_C(")
	    cpp.put_integer(value_memory)
	    cpp.put_character(')')
	 end
      end

   compile_target_to_jvm, compile_to_jvm is
      do
         code_attribute.opcode_push_integer(value_memory.to_integer)
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

   to_string: STRING is
      local
	 buffer: STRING
      do
	 buffer := string_buffer
	 buffer.clear_count
	 append_in(buffer)
         Result := buffer.twin
      end

   append_in(buffer: STRING) is
	 -- Append in `buffer' Eiffel prettifyed view of `Current'.
      local
	 i: INTEGER
      do
	 if hexadecimal_flag then
	    buffer.extend('0')
	    buffer.extend('x')
	    inspect
	       size
	    when 8 then
	       value_memory.to_integer_8.to_hexadecimal_in(buffer)
	    when 16 then
	       value_memory.to_integer_16.to_hexadecimal_in(buffer)
	    when 32 then
	       value_memory.to_integer_32.to_hexadecimal_in(buffer)
	    when 64 then
	       value_memory.to_hexadecimal_in(buffer)
	    end
	 else
	    value_memory.append_in(buffer)
	    if underscore_flag then
	       from
		  i := buffer.count - 2
	       until
		  i <= 1
	       loop
		  buffer.insert_character('_', i)
		  i := i - 3
	       end
	    end
	 end
      end
   
feature {TMP_FEATURE}

   to_real_constant: REAL_CONSTANT is
      do
         create Result.make(start_position, value_memory.to_string)
      end

feature {INTEGER_CONSTANT_VISITOR}

   accept(visitor: INTEGER_CONSTANT_VISITOR) is
      do
         visitor.visit_integer_constant(Current)
      end

feature {NONE}
   
   with(uf: like underscore_flag; negative: BOOLEAN
	negative_value: INTEGER_64; sp: like start_position) is
	 -- The `negative_value' has to be negative because negative range 
	 -- is greater than the positive one.  
      require
	 negative_value <= 0
      do
	 underscore_flag := uf
         start_position := sp
	 if negative then
	    value_memory := negative_value
	    if value_memory >= -128 then
	       size := 8
	    elseif value_memory >= -32768 then
	       size := 16
	    elseif value_memory >= -2147483648 then
	       size := 32
	    else
	       size := 64
	    end
	 else
	    value_memory := -negative_value
	    if value_memory <= 127 then
	       size := 8
	    elseif value_memory <= 32767 then
	       size := 16
	    elseif value_memory <= 2147483647 then
	       size := 32
	    else
	       size := 64
	    end
	 end
      ensure
	 underscore_flag = uf
      end

   hexadecimal(negative: BOOLEAN; digit_count: INTEGER_8;
	       a_value: INTEGER_64; sp: like start_position) is
      do
	 hexadecimal_flag := True
	 value_memory := a_value
	 inspect
	    digit_count
	 when 2 then
	    size := 8
	    if negative then
	       value_memory := a_value.to_integer_8 | 0x80
	    end
	 when 4 then
	    size := 16
	    if negative then
	       value_memory := a_value.to_integer_16 | 0x8000
	    end
	 when 8 then
	    size := 32
	    if negative then
	       value_memory := a_value.to_integer_32 | 0x80000000
	    end 
	 when 16 then
	    size := 64
	    if negative then
	       value_memory := a_value | 0x8000000000000000
	    end 
	 end
      end

   make(v: like value_memory; sp: like start_position) is
      do
	 if v >= 0 then
	    with(False, False, -v, sp)
	 else
	    with(False, True, v, sp)
	 end
	 set_result_type
      end
   
   string_buffer: STRING is
      once
	 create Result.make(32)
      end

   set_result_type is
      require
	 result_type = Void
      do
	 inspect
	    size
	 when 8 then
	    create {TYPE_INTEGER}
	    result_type.integer_8(start_position)
	 when 16 then
	    create {TYPE_INTEGER}
	    result_type.integer_16(start_position)
	 when 32 then
	    create {TYPE_INTEGER}
	    result_type.integer_32(start_position)
	 when 64 then
	    create {TYPE_INTEGER}
	    result_type.integer_64(start_position)
	 end
      ensure
	 result_type /= Void
      end
   
invariant

   size = 8 xor size = 16 xor size = 32 xor size = 64

   underscore_flag implies not hexadecimal_flag
   
   hexadecimal_flag implies not underscore_flag 
   
end -- INTEGER_CONSTANT
