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
class TYPE_POINTER
   --
   -- Handling the "POINTER" type mark.
   --

inherit TYPE_BASIC_EIFFEL_EXPANDED

creation make

feature

   id: INTEGER is 8

   is_pointer: BOOLEAN is true

   is_integer,
   is_real,
   is_double,
   is_character,
   is_boolean: BOOLEAN is false
   
   smallest_ancestor(other: E_TYPE): E_TYPE is
      local
         rto: E_TYPE
      do
         rto := other.run_type
         if rto.is_pointer then
            Result := Current
         else
	    Result := smallest_ancestor_end_hook(rto)
         end
      end

   is_a(other: E_TYPE): BOOLEAN is
      do
         if other.is_pointer then
            Result := true
         else
	    Result := is_a_end_hook(other.run_type)
         end
         if not Result then
            error_handler.type_error(Current,other)
         end
      end

   c_sizeof: INTEGER is
      do
         Result := c_sizeof_pointer
      end

   to_runnable(rt: E_TYPE): like Current is
      do
         Result := Current
         load_run_class_once
      end

   written_mark, run_time_mark: STRING is
      do
         Result := as_pointer
      end

   c_type_for_argument_in(str: STRING) is
      do
         str.extend('T')
         str.extend('8')
      end

   jvm_descriptor_in(str: STRING) is
      do
         str.append(fz_21)
      end

   jvm_return_code is
      do
         code_attribute.opcode_areturn
      end

   jvm_push_local(offset: INTEGER) is
      do
         code_attribute.opcode_aload(offset)
      end

   jvm_push_default: INTEGER is
      do
         code_attribute.opcode_aconst_null
         Result := 1
      end

   jvm_write_local_creation, jvm_write_local(offset: INTEGER) is
      do
         code_attribute.opcode_astore(offset)
      end

   jvm_xnewarray is
      local
         idx: INTEGER
      do
         idx := constant_pool.idx_java_lang_object
         code_attribute.opcode_anewarray(idx)
      end

   jvm_xastore is
      do
         code_attribute.opcode_aastore
      end

   jvm_xaload is
      do
         code_attribute.opcode_aaload
      end

   jvm_if_x_eq: INTEGER is
      do
         Result := code_attribute.opcode_if_acmpeq
      end

   jvm_if_x_ne: INTEGER is
      do
         Result := code_attribute.opcode_if_acmpne
      end

   jvm_to_reference is
      local
         rc: RUN_CLASS
         idx: INTEGER
         ca: like code_attribute
      do
         ca := code_attribute
         rc := type_pointer_ref.run_class
         rc.jvm_basic_new
         idx := rc.jvm_constant_pool_index
         ca.opcode_dup_x1
         ca.opcode_swap
         idx := constant_pool.idx_fieldref4(idx,as_item,fz_21)
         ca.opcode_putfield(idx,-2)
      end

   jvm_expanded_from_reference(other: E_TYPE): INTEGER is
      local
         rc: RUN_CLASS
         idx: INTEGER
         ca: like code_attribute
      do
         ca := code_attribute
         rc := type_pointer_ref.run_class
         rc.opcode_checkcast
         idx := rc.jvm_constant_pool_index
         idx := constant_pool.idx_fieldref4(idx,as_item,fz_21)
         ca.opcode_getfield(idx,0)
         Result := 1
      end

   jvm_convert_to(destination: E_TYPE): INTEGER is
      do
         if destination.is_reference then
            jvm_to_reference
         end
         Result := 1
      end

feature {TYPE_POINTER_VISITOR}

   accept(visitor: TYPE_POINTER_VISITOR) is
      do
         visitor.visit_type_pointer(Current)
      end

feature {NONE}

   make(sp: like start_position) is
      do
         !!base_class_name.make(as_pointer,sp)
      end

   type_pointer_ref: TYPE_CLASS is
      local
         pointer_ref: CLASS_NAME
      once
         !!pointer_ref.unknown_position(as_pointer_ref)
         !!Result.make(pointer_ref)
      end

   load_run_class_once is
      once
         if base_class /= Void then
	    if run_class = Void then
	       check false end
	    end
	 end
      end

end -- TYPE_POINTER

