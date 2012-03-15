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
class E_TRUE
   --
   -- When using explicit constant `true'.
   --

inherit BOOLEAN_CONSTANT

creation make

feature

   value, is_static: BOOLEAN is True

   to_integer_or_error: INTEGER is 1

   to_string: STRING is
      do
         Result := fz_true
      end

   compile_to_c is
      do
         cpp.put_character('1')
      end

   compile_target_to_jvm, compile_to_jvm is
      do
         code_attribute.opcode_iconst_1
      end

   jvm_branch_if_false: INTEGER is
      do
         code_attribute.opcode_iconst_1
         Result := code_attribute.opcode_ifeq
      end

   jvm_branch_if_true: INTEGER is
      do
         Result := code_attribute.opcode_goto
      end

feature {E_TRUE_VISITOR}

   accept(visitor: E_TRUE_VISITOR) is
      do
         visitor.visit_e_true(Current)
      end

end -- E_TRUE
