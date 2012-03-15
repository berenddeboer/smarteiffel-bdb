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
class TYPE_DOUBLE
   --
   -- Handling of the "DOUBLE" type mark.
   --

inherit TYPE_BASIC_EIFFEL_EXPANDED

creation make

feature {TYPE_DOUBLE_VISITOR}

   accept(visitor: TYPE_DOUBLE_VISITOR) is
      do
         visitor.visit_type_double(Current)
      end

feature

   id: INTEGER is 5

   is_double: BOOLEAN is True

   is_real,
   is_integer,
   is_character,
   is_boolean,
   is_pointer: BOOLEAN is False

   c_sizeof: INTEGER is
      do
         Result := (0.0).to_double.object_size
      end

   is_a(other: E_TYPE): BOOLEAN is
      do
         if other.is_double then
            Result := True
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
            Result := Current
         else
	    Result := smallest_ancestor_end_hook(rto)
         end
      end

   to_runnable(rt: E_TYPE): like Current is
      do
         Result := Current
         load_run_class_once
      end

   written_mark: STRING
   
   run_time_mark: STRING is
      do
         Result := as_double -- must be constant to avoid code duplication, see ticket:40
      end

   c_type_for_argument_in(str: STRING) is
      do
         str.extend('T')
         str.extend('5')
      end

   jvm_descriptor_in(str: STRING) is
      do
         str.extend('D')
      end

   jvm_return_code is
      do
         code_attribute.opcode_dreturn
      end

   jvm_push_local(offset: INTEGER) is
      do
         code_attribute.opcode_dload(offset)
      end

   jvm_push_default: INTEGER is
      do
         code_attribute.opcode_dconst_0
         Result := 2
      end

   jvm_write_local_creation, jvm_write_local(offset: INTEGER) is
      do
         code_attribute.opcode_dstore(offset)
      end

   jvm_xnewarray is
      do
         code_attribute.opcode_newarray(7)
      end

   jvm_xastore is
      do
         code_attribute.opcode_dastore
      end

   jvm_xaload is
      do
         code_attribute.opcode_daload
      end

   jvm_if_x_eq: INTEGER is
      local
         ca: like code_attribute
      do
         ca := code_attribute
         ca.opcode_dcmpg
         Result := ca.opcode_ifeq
      end

   jvm_if_x_ne: INTEGER is
      local
         ca: like code_attribute
      do
         ca := code_attribute
         ca.opcode_dcmpg
         Result := ca.opcode_ifne
      end

   jvm_to_reference is
      local
         rc: RUN_CLASS; idx: INTEGER; ca: like code_attribute
      do
         ca := code_attribute
         rc := actual_reference(Void).run_class
         rc.jvm_basic_new
         ca.opcode_dup_x2
         ca.opcode_dup_x2
         ca.opcode_pop
         idx := rc.jvm_constant_pool_index
         idx := constant_pool.idx_fieldref4(idx,as_item,fz_77)
         ca.opcode_putfield(idx,-3)
      end

   jvm_expanded_from_reference(other: E_TYPE): INTEGER is
      local
         rc: RUN_CLASS; idx: INTEGER; ca: like code_attribute
      do
         ca := code_attribute
         rc := actual_reference(Void).run_class
         rc.opcode_checkcast
         idx := rc.jvm_constant_pool_index
         idx := constant_pool.idx_fieldref4(idx,as_item,fz_77)
         ca.opcode_getfield(idx,1)
         Result := 2
      end

   jvm_convert_to(destination: E_TYPE): INTEGER is
      local
	 type_integer: TYPE_INTEGER
      do
         if destination.is_reference then
            jvm_to_reference
            Result := 1
         elseif destination.is_real then
            code_attribute.opcode_d2f
            Result := 1
         elseif destination.is_integer then
	    type_integer ?= destination.run_type
	    inspect
	       type_integer.c_sizeof
	    when 1 then
	       code_attribute.opcode_d2i
	       code_attribute.opcode_i2b
	       Result := 1
	    when 2 then
	       code_attribute.opcode_d2i
	       code_attribute.opcode_i2s
	       Result := 1
	    when 4 then
	       code_attribute.opcode_d2i
	       Result := 1
	    when 8 then
	       code_attribute.opcode_d2l
	       Result := 2
	    end
         else
            check
               destination.is_double
            end
            Result := 2
         end
      end
   
feature {NONE}
   
   make(sp: like start_position; mark: STRING) is
      require
         mark = as_double or mark = as_real_64 or mark = as_real_general
      do
         written_mark := mark
         create base_class_name.make(mark,sp)
      end

   load_run_class_once is
      once
         if base_class /= Void then
	    if run_class = Void then
	       check False end
	    end
	 end
      end

invariant

   written_mark = as_double or
   written_mark = as_real_64 or
   written_mark = as_real_general

end -- TYPE_DOUBLE
