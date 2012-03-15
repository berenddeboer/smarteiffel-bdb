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
deferred class LOCAL_NAME
   --
   -- Handling of local variables.
   --

inherit LOCAL_ARGUMENT

feature

   is_writable: BOOLEAN is True

   once_pre_computable: BOOLEAN is True

   isa_dca_inline_argument: INTEGER is 0

   frozen dca_inline_argument(formal_arg_type: E_TYPE) is
      do
      end

   frozen mapping_c_target(formal_type: E_TYPE) is
      do
	 standard_mapping_c_target(formal_type)
      end

   frozen mapping_c_arg(formal_arg_type: E_TYPE) is
      do
         compile_to_c
      end

   frozen compile_to_c is
      do
         cpp.print_local(to_string)
      end

   frozen compile_to_jvm is
      local
         jvm_offset: INTEGER
      do
         jvm_offset := jvm.local_offset_of(Current)
         result_type.run_type.jvm_push_local(jvm_offset)
      end

   frozen jvm_branch_if_false: INTEGER is
      do
         compile_to_jvm
         Result := code_attribute.opcode_ifeq
      end

   frozen jvm_branch_if_true: INTEGER is
      do
         compile_to_jvm
         Result := code_attribute.opcode_ifne
      end

   frozen compile_to_jvm_into(dest: E_TYPE): INTEGER is
      do
         Result := standard_compile_to_jvm_into(dest)
      end

   frozen jvm_assign_creation is
      local
         jvm_offset: INTEGER
      do
         jvm_offset := jvm.local_offset_of(Current)
         result_type.run_type.jvm_write_local(jvm_offset)
      end

   frozen jvm_assign is
      local
         jvm_offset: INTEGER
      do
         jvm_offset := jvm.local_offset_of(Current)
         result_type.run_type.jvm_write_local(jvm_offset)
      end

   frozen pretty_print is
      do
         pretty_printer.put_string(to_string)
      end

feature {LOCAL_NAME_VISITOR}

   accept(visitor: LOCAL_NAME_VISITOR) is
      deferred
      end

feature {NONE}

   tmp_string: STRING is
      once
         !!Result.make(256)
      end

end -- LOCAL_NAME

