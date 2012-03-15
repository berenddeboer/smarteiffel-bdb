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
deferred class INSTRUCTION_GROUP_VISITOR
      --
      -- Visitor of all the classes of the `tools/instruction' cluster.
      --
      -- It is just a convenient inheritance for those who implement functions
      -- involving all the classes of the cluster.
      --
inherit
   AGENT_INSTRUCTION_VISITOR
   ASSIGNMENT_VISITOR
   ASSIGNMENT_ATTEMPT_VISITOR
   CHECK_INVARIANT_VISITOR
   CREATE_INSTRUCTION_VISITOR
   E_CHECK_VISITOR
   E_DEBUG_VISITOR
   E_INSPECT_VISITOR
   E_LOOP_VISITOR
   E_RETRY_VISITOR
   E_WHEN_VISITOR
   IFTHEN_VISITOR
   IFTHENELSE_VISITOR
   IFTHENLIST_VISITOR
   INSTRUCTION_WITH_COMMENT_VISITOR
   LOOP_INVARIANT_VISITOR
   LOOP_VARIANT_VISITOR
   OLD_CREATION_VISITOR
   PRECURSOR_INSTRUCTION_VISITOR
   PROC_CALL_VISITOR
   PROC_CALL_0_VISITOR
   PROC_CALL_1_VISITOR
   PROC_CALL_N_VISITOR
   WHEN_ITEM_VISITOR
   WHEN_ITEM_1_VISITOR
   WHEN_ITEM_2_VISITOR
   WHEN_LIST_VISITOR

end -- INSTRUCTION_GROUP_VISITOR
