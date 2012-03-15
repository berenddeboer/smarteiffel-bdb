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
deferred class EXPRESSION_GROUP_VISITOR
      --
      -- Visitor of all the classes of the `tools/expression' cluster.
      --
      -- It is just a convenient inheritance for those who implement functions
      -- involving all the classes of the cluster.
      --
inherit
   ABSTRACT_CURRENT_VISITOR
   ADDRESS_OF_VISITOR
   AGENT_EXPRESSION_VISITOR
   ARGUMENT_NAME_VISITOR
   ARGUMENT_NAME1_VISITOR
   ARGUMENT_NAME2_VISITOR
   BASE_TYPE_CONSTANT_VISITOR
   BIT_CONSTANT_VISITOR
   BOOLEAN_CONSTANT_VISITOR
   CALL_VISITOR
   CALL_0_VISITOR
   CALL_0_C_VISITOR
   CALL_1_VISITOR
   CALL_1_C_VISITOR
   CALL_INFIX_VISITOR
   CALL_INFIX1_VISITOR
   CALL_INFIX2_VISITOR
   CALL_INFIX_AND_VISITOR
   CALL_INFIX_AND_THEN_VISITOR
   CALL_INFIX_DIV_VISITOR
   CALL_INFIX_EQ_VISITOR
   CALL_INFIX_FREEOP_VISITOR
   CALL_INFIX_GE_VISITOR
   CALL_INFIX_GT_VISITOR
   CALL_INFIX_IMPLIES_VISITOR
   CALL_INFIX_INT_DIV_VISITOR
   CALL_INFIX_INT_REM_VISITOR
   CALL_INFIX_LE_VISITOR
   CALL_INFIX_LT_VISITOR
   CALL_INFIX_MINUS_VISITOR
   CALL_INFIX_NEQ_VISITOR
   CALL_INFIX_OR_VISITOR
   CALL_INFIX_OR_ELSE_VISITOR
   CALL_INFIX_PLUS_VISITOR
   CALL_INFIX_POWER_VISITOR
   CALL_INFIX_TIMES_VISITOR
   CALL_INFIX_XOR_VISITOR
   CALL_N_VISITOR
   CALL_PREFIX_VISITOR
   CALL_PREFIX_FREEOP_VISITOR
   CALL_PREFIX_MINUS_VISITOR
   CALL_PREFIX_NOT_VISITOR
   CALL_PREFIX_PLUS_VISITOR
   CALL_PROC_CALL_VISITOR
   CHARACTER_CONSTANT_VISITOR
   CREATE_EXPRESSION_VISITOR
   E_AGENT_VISITOR
   E_FALSE_VISITOR
   E_OLD_VISITOR
   E_RESULT_VISITOR
   E_STRIP_VISITOR
   E_TRUE_VISITOR
   E_VOID_VISITOR
   EXPRESSION_WITH_COMMENT_VISITOR
   FAKE_ARGUMENT_VISITOR
   FAKE_TARGET_VISITOR
   FAKE_TUPLE_VISITOR
   FEATURE_NAME_VISITOR
   IMPLICIT_CAST_VISITOR
   IMPLICIT_CURRENT_VISITOR
   INTEGER_CONSTANT_VISITOR
   LOCAL_ARGUMENT_VISITOR
   LOCAL_ARGUMENT1_VISITOR
   LOCAL_NAME_VISITOR
   LOCAL_NAME1_VISITOR
   LOCAL_NAME2_VISITOR
   MANIFEST_ARRAY_VISITOR
   MANIFEST_STRING_VISITOR
   OPEN_OPERAND_VISITOR
   PRECURSOR_EXPRESSION_VISITOR
   REAL_CONSTANT_VISITOR
   TUPLE_EXPRESSION_VISITOR
   WRITTEN_CURRENT_VISITOR

end -- EXPRESSION_GROUP_VISITOR
