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
class TYPE_REAL
   --
   -- Handling of the "REAL" type mark.
   --

inherit TYPE_BASIC_EIFFEL_EXPANDED

creation make

feature

   id: INTEGER is 4

   is_real: BOOLEAN is true

   is_double,
   is_integer,
   is_pointer,
   is_character,
   is_boolean: BOOLEAN is false

   is_a(other: E_TYPE): BOOLEAN is
      do
         if other.is_real or else other.is_double then
            Result := true
         else
	    Result := is_a_end_hook(other.run_type)
         end
         if not Result then
            error_handler.type_error(Current,other)
         end
      end

   smallest_ancestor(other: E_TYPE): E_TYPE is
      local
         rto: E_TYPE
      do
         rto := other.run_type
         if rto.is_integer then
            Result := Current
         elseif rto.is_real then
            Result := Current
         elseif rto.is_double then
            Result := other
         else
	    Result := smallest_ancestor_end_hook(rto)
         end
      end

   c_sizeof: INTEGER is
      do
         Result := (0.0).object_size
      end

   to_runnable(rt: E_TYPE): like Current is
      do
         Result := Current
         load_run_class_once
      end

   written_mark, run_time_mark: STRING is
      do
         Result := as_real
      end

   c_type_for_argument_in(str: STRING) is
      do
         str.extend('T')
         str.extend('4')
      end

   jvm_descriptor_in(str: STRING) is
      do
         str.extend('F')
      end

   jvm_return_code is
      do
         code_attribute.opcode_freturn
      end

   jvm_push_local(offset: INTEGER) is
      do
         code_attribute.opcode_fload(offset)
      end

   jvm_push_default: INTEGER is
      do
         code_attribute.opcode_fconst_0
         Result := 1
      end

   jvm_write_local_creation, jvm_write_local(offset: INTEGER) is
      do
         code_attribute.opcode_fstore(offset)
      end

   jvm_xnewarray is
      do
         code_attribute.opcode_newarray(6)
      end

   jvm_xastore is
      do
         code_attribute.opcode_fastore
      end

   jvm_xaload is
      do
         code_attribute.opcode_faload
      end

   jvm_if_x_eq: INTEGER is
      do
         code_attribute.opcode_fcmpg
         Result := code_attribute.opcode_ifeq
      end

   jvm_if_x_ne: INTEGER is
      do
         code_attribute.opcode_fcmpg
         Result := code_attribute.opcode_ifne
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
         idx := constant_pool.idx_fieldref4(idx,as_item,fz_78)
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
         idx := constant_pool.idx_fieldref4(idx,as_item,fz_78)
         ca.opcode_getfield(idx,0)
         Result := 1
      end

   jvm_convert_to(destination: E_TYPE): INTEGER is
      local
	 type_integer: TYPE_INTEGER
      do
         Result := 1
         if destination.is_reference then
            jvm_to_reference
         elseif destination.is_double then
            code_attribute.opcode_f2d
            Result := 2
         elseif destination.is_real then
         else
	    type_integer ?= destination.run_type
	    inspect
	       type_integer.c_sizeof
	    when 1 then
	       code_attribute.opcode_f2i
	       code_attribute.opcode_i2b
	       Result := 1
	    when 2 then
	       code_attribute.opcode_f2i
	       code_attribute.opcode_i2s
	       Result := 1
	    when 4 then
	       code_attribute.opcode_f2i
	       Result := 1
	    when 8 then
	       code_attribute.opcode_f2l
	       Result := 2
	    end
         end
      end

feature {TYPE_REAL_VISITOR}

   accept(visitor: TYPE_REAL_VISITOR) is
      do
         visitor.visit_type_real(Current)
      end

feature {NONE}

   make(sp: like start_position) is
      do
         !!base_class_name.make(as_real,sp)
      end

   load_run_class_once is
      once
         if base_class /= Void then
	    if run_class = Void then
	       check false end
	    end
	 end
      end

invariant

   written_mark = as_real

end -- TYPE_REAL
