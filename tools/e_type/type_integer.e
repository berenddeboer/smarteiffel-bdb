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
class TYPE_INTEGER
   --
   -- Handling of the "INTEGER" type mark. This class handles all
   -- variants of the "INTEGER" type mark: "INTEGER_8", "INTEGER_16",
   -- "INTEGER_32", "INTEGER_64" and "INTEGER_GENERAL"
   --

inherit
   TYPE_BASIC_EIFFEL_EXPANDED
      redefine pretty_print
      end

creation integer_8, integer_16, integer_32, integer_64, integer,
   integer_general

feature {TYPE_INTEGER_VISITOR}

   accept(visitor: TYPE_INTEGER_VISITOR) is
      do
         visitor.visit_type_integer(Current)
      end

feature

   is_integer: BOOLEAN is True

   is_boolean,
   is_character,
   is_real,
   is_double,
   is_pointer: BOOLEAN is False

   is_integer_general: BOOLEAN is
      do
	 Result := format_code = Code_integer_general
      end

   id: INTEGER is
      do
	 inspect
	    format_code
	 when Code_integer_8 then
	    Result := 1
	 when Code_integer_16 then
	    Result := 10
	 when Code_integer, Code_integer_32 then
	    Result := 2
	 when Code_integer_64, Code_integer_general then
	    Result := 11
	 end
      end

   c_sizeof: INTEGER is
      do
	 inspect
	    format_code
	 when Code_integer_8 then
	    Result := 1
	 when Code_integer_16 then
	    Result := 2
	 when Code_integer, Code_integer_32 then
	    Result := 4
	 when Code_integer_64, Code_integer_general then
	    Result := 8
	 end
      end

   smallest_ancestor(other: E_TYPE): E_TYPE is
      local
         other_rt: E_TYPE
      do
         other_rt := other.run_type
         if other_rt.is_integer then
	    if Current.is_a(other_rt) then
	       Result := other_rt
	    else
	       error_handler.cancel
	       Result := Current
	    end
	 elseif other_rt.is_real then
            Result := other
         elseif other_rt.is_double then
            Result := other
         else
	    Result := smallest_ancestor_end_hook(other_rt)
         end
      end

   is_a(other: E_TYPE): BOOLEAN is
      local
	 other_type_integer: TYPE_INTEGER
      do
         if other.is_integer then
	    other_type_integer ?= other.run_type
            Result := c_sizeof <= other_type_integer.c_sizeof
         elseif other.is_double or else other.is_real then
            Result := True
         else
	    Result := is_a_end_hook(other.run_type)
	 end
	 if not Result then
	    error_handler.type_error(Current, other)
	 end
      end

   to_runnable(ct: E_TYPE): like Current is
      do
         Result := Current
         if base_class /= Void then
	    if run_class = Void then
	       check False end
	    end
	 end
      end

   written_mark, run_time_mark: STRING is
      do
	 inspect
	    format_code
	 when Code_integer_8 then
	    Result := as_integer_8
	 when Code_integer_16 then
	    Result := as_integer_16
	 when Code_integer, Code_integer_32 then
	    Result := as_integer
	 when Code_integer_64, Code_integer_general then
	    Result := as_integer_64
	 end
      end

   pretty_print is
      local
	 actual_written_mark: STRING
      do
	 inspect
	    format_code
	 when Code_integer_8 then
	    actual_written_mark := as_integer_8
	 when Code_integer_16 then
	    actual_written_mark := as_integer_16
	 when Code_integer then
	    actual_written_mark := as_integer
	 when Code_integer_32 then
	    actual_written_mark := as_integer_32
	 when Code_integer_64 then
	    actual_written_mark := as_integer_64
	 when Code_integer_general then
	    actual_written_mark := as_integer_general
	 end
	 pretty_printer.put_string(actual_written_mark)
      end

   c_type_for_argument_in(str: STRING) is
      do
	 str.extend('T')
	 inspect
	    format_code
	 when Code_integer_8 then
	    str.extend('1')
	 when Code_integer, Code_integer_32 then
	    str.extend('2')
	 when Code_integer_16 then
	    str.extend('1')
	    str.extend('0')
	 when Code_integer_64, Code_integer_general then
	    str.extend('1')
	    str.extend('1')
	 end
      end

   jvm_descriptor_in(str: STRING) is
      do
	 inspect
	    format_code
	 when Code_integer_8 then
	    str.extend('B')
	 when Code_integer_16 then
	    str.extend('S')
	 when Code_integer, Code_integer_32 then
	    str.extend('I')
	 when Code_integer_64, Code_integer_general then
	    str.extend('J')
	 end
      end

   jvm_return_code is
      do
	 inspect
	    format_code
	 when Code_integer_8 then
             code_attribute.opcode_ireturn
	 when Code_integer_16 then
             code_attribute.opcode_ireturn
	 when Code_integer, Code_integer_32 then
            code_attribute.opcode_ireturn
	 when Code_integer_64, Code_integer_general then
             code_attribute.opcode_lreturn
	 end
      end

   jvm_push_local(offset: INTEGER) is
      do
	 inspect
	    format_code
	 when Code_integer_8 then
            code_attribute.opcode_iload(offset)
	 when Code_integer_16 then
            code_attribute.opcode_iload(offset)
	 when Code_integer, Code_integer_32 then
            code_attribute.opcode_iload(offset)
	 when Code_integer_64, Code_integer_general then
            code_attribute.opcode_lload(offset)
	 end
      end

   jvm_push_default: INTEGER is
      do
	 inspect
	    format_code
	 when Code_integer_8 then
            code_attribute.opcode_iconst_0
	 when Code_integer_16 then
            code_attribute.opcode_iconst_0
	 when Code_integer, Code_integer_32 then
            code_attribute.opcode_iconst_0
	 when Code_integer_64, Code_integer_general then
            code_attribute.opcode_iconst_0
	 end
         Result := 1
      end

   jvm_write_local_creation, jvm_write_local(offset: INTEGER) is
      do
	 inspect
	    format_code
	 when Code_integer_8 then
            code_attribute.opcode_istore(offset)
	 when Code_integer_16 then
            code_attribute.opcode_istore(offset)
	 when Code_integer, Code_integer_32 then
            code_attribute.opcode_istore(offset)
	 when Code_integer_64, Code_integer_general then
            code_attribute.opcode_lstore(offset)
	 end
      end

   jvm_xnewarray is
      do
	 inspect
	    format_code
	 when Code_integer_8 then
            code_attribute.opcode_newarray(8)
	 when Code_integer_16 then
            code_attribute.opcode_newarray(9)
	 when Code_integer, Code_integer_32 then
            code_attribute.opcode_newarray(10)
	 when Code_integer_64, Code_integer_general then
            code_attribute.opcode_newarray(11)
	 end
      end

   jvm_xastore is
      do
	 inspect
	    format_code
	 when Code_integer_8 then
            code_attribute.opcode_bastore
	 when Code_integer_16 then
            code_attribute.opcode_sastore
	 when Code_integer, Code_integer_32 then
            code_attribute.opcode_iastore
	 when Code_integer_64, Code_integer_general then
            code_attribute.opcode_lastore
	 end
      end

   jvm_xaload is
      do
	 inspect
	    format_code
	 when Code_integer_8 then
            code_attribute.opcode_baload
	 when Code_integer_16 then
            code_attribute.opcode_saload
	 when Code_integer, Code_integer_32 then
            code_attribute.opcode_iaload
	 when Code_integer_64, Code_integer_general then
            code_attribute.opcode_laload
	 end
      end

   jvm_if_x_eq: INTEGER is
      do
	 inspect
	    format_code
	 when Code_integer_8 then
            Result := code_attribute.opcode_if_icmpeq
	 when Code_integer_16 then
            Result := code_attribute.opcode_if_icmpeq
	 when Code_integer, Code_integer_32 then
            Result := code_attribute.opcode_if_icmpeq
	 when Code_integer_64, Code_integer_general then
            code_attribute.opcode_lsub
            Result := code_attribute.opcode_ifeq
	 end
      end

   jvm_if_x_ne: INTEGER is
      do
	 inspect
	    format_code
	 when Code_integer_8 then
            Result := code_attribute.opcode_if_icmpne
	 when Code_integer_16 then
            Result := code_attribute.opcode_if_icmpne
	 when Code_integer, Code_integer_32 then
            Result := code_attribute.opcode_if_icmpne
	 when Code_integer_64, Code_integer_general then
            code_attribute.opcode_lsub
            Result := code_attribute.opcode_ifne
	 end
      end

   jvm_to_reference is
      local
         rc: RUN_CLASS; idx: INTEGER; ca: like code_attribute
      do
         ca := code_attribute
	 rc := actual_reference(Void).run_class
         rc.jvm_basic_new
         ca.opcode_dup_x1
         ca.opcode_swap
         idx := rc.jvm_constant_pool_index
         idx := constant_pool.idx_fieldref4(idx,as_item,fz_i)
         ca.opcode_putfield(idx,-2)
      end

   jvm_expanded_from_reference(other: E_TYPE): INTEGER is
      local
         rc: RUN_CLASS; idx: INTEGER; ca: like code_attribute
      do
         ca := code_attribute
         rc := actual_reference(Void).run_class
         rc.opcode_checkcast
         idx := rc.jvm_constant_pool_index
         idx := constant_pool.idx_fieldref4(idx,as_item,fz_i)
         ca.opcode_getfield(idx,0)
         Result := 1
      end

   jvm_convert_to(destination: E_TYPE): INTEGER is
      local
	 type_integer: TYPE_INTEGER
      do
         if destination.is_reference then
            jvm_to_reference
            Result := 1
         elseif destination.is_real then
            code_attribute.opcode_i2f
            Result := 1
         elseif destination.is_double then
            code_attribute.opcode_i2d
            Result := 2
         else
	    type_integer ?= destination.run_type
	    inspect
	       type_integer.c_sizeof
	    when 1 then
	       code_attribute.opcode_i2b
	       Result := 1
	    when 2 then
	       code_attribute.opcode_i2s
	       Result := 1
	    when 4 then
	       Result := 1
	    when 8 then
	       code_attribute.opcode_i2l
	       Result := 2
	    end
         end
      end

feature {NONE}

   format_code: INTEGER
   	 -- Used to memorize the format of the original written notation.
   	 -- See following Code_* constant definition to know more about
   	 -- codification used to distinguished INTEGER_8, INTEGER_16,
   	 -- INTEGER_32, INTEGER_64, INTEGER and INTEGER_GENERAL.

   Code_integer_8      : INTEGER is 8
   Code_integer_16     : INTEGER is 16
   Code_integer_32     : INTEGER is 32
   Code_integer        : INTEGER is 0
   Code_integer_64     : INTEGER is 64
   Code_integer_general: INTEGER is 65

   integer_8(sp: like start_position) is
      do
	 format_code := Code_integer_8
         create base_class_name.make(as_integer_8,sp)
      end

   integer_16(sp: like start_position) is
      do
	 format_code := Code_integer_16
         create base_class_name.make(as_integer_16,sp)
      end

   integer_32(sp: like start_position) is
      do
	 format_code := Code_integer_32
         create base_class_name.make(as_integer_32,sp)
      end

   integer_64(sp: like start_position) is
      do
	 format_code := Code_integer_64
         create base_class_name.make(as_integer_64,sp)
      end

   integer(sp: like start_position) is
      do
	 format_code := Code_integer
         create base_class_name.make(as_integer,sp)
      end

   integer_general(sp: like start_position) is
      do
	 format_code := Code_integer_general
         create base_class_name.make(as_integer_general,sp)
      end

   valid_format_code: BOOLEAN is
      do
	 inspect
	    format_code
	 when Code_integer_8, Code_integer_16, Code_integer_32,
	    Code_integer, Code_integer_64, Code_integer_general
	  then
	    Result := True
	 else
	 end
      end

invariant

   valid_format_code

end -- TYPE_INTEGER
