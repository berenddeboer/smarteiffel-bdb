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
deferred class ARGUMENT_NAME
   --
   -- Handling of arguments.
   --

inherit LOCAL_ARGUMENT

feature

   is_writable: BOOLEAN is False

   once_pre_computable: BOOLEAN is False

   frozen assertion_check(tag: CHARACTER) is
      do
      end

   frozen isa_dca_inline_argument: INTEGER is
      do
         Result := rank
      end

   frozen dca_inline_argument(formal_arg_type: E_TYPE) is
      do
         cpp.put_ith_argument(rank)
      end

   frozen pretty_print is
      do
         pretty_printer.put_string(to_string)
      end

   frozen mapping_c_target(formal_type: E_TYPE) is
      local
         flag: BOOLEAN; rt: E_TYPE
      do
         flag := cpp.call_invariant_start(formal_type)
         rt := result_type.run_type
         if rt.is_reference then
            if formal_type.is_reference then
               -- Reference into Reference :
               cpp.put_character('(')
	       formal_type.mapping_cast
               cpp.print_argument(rank)
               cpp.put_character(')')
            else
               -- Reference into Expanded :
               cpp.print_argument(rank)
            end
         elseif formal_type.is_reference then
            -- Expanded into Reference :
            cpp.print_argument(rank)
         elseif rt.is_user_expanded then
            -- User Expanded into User Expanded :
            if not rt.is_dummy_expanded then
               cpp.put_character('&')
            end
            cpp.print_argument(rank)
         else
            -- Kernel Expanded into Kernel Expanded :
            cpp.print_argument(rank)
         end
         if flag then
            cpp.call_invariant_end
         end
      end

   frozen mapping_c_arg(formal_arg_type: E_TYPE) is
      do
         cpp.print_argument(rank)
      end

   frozen compile_to_c is
      do
         cpp.print_argument(rank)
      end

   frozen compile_to_jvm is
      local
         jvm_offset: INTEGER
      do
         jvm_offset := jvm.argument_offset_of(Current)
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

   frozen jvm_assign_creation, jvm_assign is
      do
         check False end
      end

feature {ARGUMENT_NAME_VISITOR}

   accept(visitor: ARGUMENT_NAME_VISITOR) is
      deferred
      end

end -- ARGUMENT_NAME
