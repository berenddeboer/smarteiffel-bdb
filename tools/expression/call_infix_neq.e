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
class CALL_INFIX_NEQ
   --
   --   Infix operator : "/=".
   --

inherit CALL_INFIX2

creation make, with

feature

   operator: STRING is
      do
         Result := as_neq
      end

   compile_to_c is
      local
         tt, at: E_TYPE
      do
         tt := target.result_type.run_type
         at := arg1.result_type.run_type
         if tt.is_expanded then
            if at.is_expanded then -- ------------- Expanded/Expanded :
               if tt.is_user_expanded then
                  cmp_user_expanded(False, tt)
               elseif tt.is_basic_eiffel_expanded then
                  cmp_basic_eiffel_expanded(False, at, tt)
               elseif tt.is_bit then
                  cmp_bit(False, tt)
               else -- NATIVE_ARRAY
                  cmp_basic_ref(False)
               end
            else -- ------------------------------- Expanded/Reference :
               c2c_exp_ref(target, arg1, False)
            end
         elseif at.is_expanded then -- ----------- Reference/Expanded :
            c2c_exp_ref(arg1, target, False)
         else -- ---------------------------- Reference/Reference :
            cmp_basic_ref(False)
         end
      end

   compile_to_jvm is
      local
         space, point1, point2: INTEGER; rt: E_TYPE; rc: RUN_CLASS
         ca: like code_attribute
      do
         if target.is_void then
            jvm_void_cmp(arg1)
         elseif arg1.is_void then
            jvm_void_cmp(target)
         else
            ca := code_attribute
            rt := target.result_type.smallest_ancestor(arg1.result_type)
            space := target.compile_to_jvm_into(rt)
            space := arg1.compile_to_jvm_into(rt)
            if rt.is_user_expanded then
               rc := rt.run_class
               jvm.std_is_equal(rc,rc.writable_attributes)
               ca.opcode_iconst_1
               ca.opcode_ixor
            else
               point1 := rt.jvm_if_x_eq
               ca.opcode_iconst_1
               point2 := ca.opcode_goto
               ca.resolve_u2_branch(point1)
               ca.opcode_iconst_0
               ca.resolve_u2_branch(point2)
            end
         end
      end

   jvm_branch_if_false: INTEGER is
      do
         Result := jvm_standard_branch_if_false
      end

   jvm_branch_if_true: INTEGER is
      do
         Result := jvm_standard_branch_if_true
      end

feature {CALL_INFIX_NEQ_VISITOR}

   accept(visitor: CALL_INFIX_NEQ_VISITOR) is
      do
         visitor.visit_call_infix_neq(Current)
      end

feature {NONE}

   jvm_void_cmp(e: EXPRESSION) is
      local
         rt: E_TYPE; point1, point2: INTEGER; ca: like code_attribute
      do
         ca := code_attribute
         rt := e.result_type.run_type
         if rt.is_expanded then
            ca.opcode_iconst_1
         else
            e.compile_to_jvm
            point1 := ca.opcode_ifnonnull
            ca.opcode_iconst_0
            point2 := ca.opcode_goto
            ca.resolve_u2_branch(point1)
            ca.opcode_iconst_1
            ca.resolve_u2_branch(point2)
         end
      end

invariant

   run_feature = Void

end -- CALL_INFIX_NEQ

