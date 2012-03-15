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
deferred class E_TYPE_GROUP_VISITOR
      --
      -- Visitor of all the classes of the `tools/e_type' cluster.
      --
      -- It is just a convenient inheritance for those who implement functions
      -- involving all the classes of the cluster.
      --
inherit
   TYPE_ANCHORED_VISITOR
   TYPE_ANY_VISITOR
   TYPE_ARRAY_VISITOR
   TYPE_BASIC_EIFFEL_EXPANDED_VISITOR
   TYPE_BIT_VISITOR
   TYPE_BIT_1_VISITOR
   TYPE_BIT_2_VISITOR
   TYPE_BOOLEAN_VISITOR
   TYPE_CHARACTER_VISITOR
   TYPE_CLASS_VISITOR
   TYPE_DOUBLE_VISITOR
   TYPE_EXPANDED_VISITOR
   TYPE_FORMAL_GENERIC_VISITOR
   TYPE_FUNCTION_VISITOR
   TYPE_GENERIC_VISITOR
   TYPE_INTEGER_VISITOR
   TYPE_LIKE_ARGUMENT_VISITOR
   TYPE_LIKE_CURRENT_VISITOR
   TYPE_LIKE_FEATURE_VISITOR
   TYPE_NATIVE_ARRAY_VISITOR
   TYPE_NONE_VISITOR
   TYPE_OF_AGENT_VISITOR
   TYPE_POINTER_VISITOR
   TYPE_PROCEDURE_VISITOR
   TYPE_REAL_VISITOR
   TYPE_REFERENCE_VISITOR
   TYPE_SEPARATE_VISITOR
   TYPE_STRING_VISITOR
   TYPE_THREAD_VISITOR
   TYPE_TUPLE_VISITOR

end -- E_TYPE_GROUP_VISITOR
