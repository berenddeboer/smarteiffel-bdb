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
deferred class FEATURE_GROUP_VISITOR
      --
      -- Visitor of all the classes of the `tools/feature' cluster.
      --
      -- It is just a convenient inheritance for those who implement functions
      -- involving all the classes of the cluster.
      --
inherit
   ATTRIBUTE_VISITOR
   CST_ATT_VISITOR
   CST_ATT_BIT_VISITOR
   CST_ATT_BOOLEAN_VISITOR
   CST_ATT_CHARACTER_VISITOR
   CST_ATT_DOUBLE_VISITOR
   CST_ATT_INTEGER_VISITOR
   CST_ATT_REAL_VISITOR
   CST_ATT_STRING_VISITOR
   CST_ATT_UNIQUE_VISITOR
   DEFERRED_FUNCTION_VISITOR
   DEFERRED_PROCEDURE_VISITOR
   DEFERRED_ROUTINE_VISITOR
   E_ENSURE_VISITOR
   E_FEATURE_VISITOR
   E_FUNCTION_VISITOR
   E_PROCEDURE_VISITOR
   E_REQUIRE_VISITOR
   E_ROUTINE_VISITOR
   EFFECTIVE_ROUTINE_VISITOR
   EXTERNAL_FUNCTION_VISITOR
   EXTERNAL_PROCEDURE_VISITOR
   EXTERNAL_ROUTINE_VISITOR
   NATIVE_VISITOR
   NATIVE_C_VISITOR
   NATIVE_C_PLUS_PLUS_VISITOR
   NATIVE_JAVA_VISITOR
   NATIVE_SMART_EIFFEL_VISITOR
   ONCE_FUNCTION_VISITOR
   ONCE_PROCEDURE_VISITOR
   ONCE_ROUTINE_VISITOR
   RUN_REQUIRE_VISITOR
   WRITABLE_ATTRIBUTE_VISITOR

end -- FEATURE_GROUP_VISITOR
