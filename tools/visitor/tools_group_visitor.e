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
deferred class TOOLS_GROUP_VISITOR
      --
      -- Visitor of all the classes of the `tools' cluster, except
      -- ORDERED_DICTIONARY_VISITOR.
      --
      -- It is just a convenient inheritance for those who implement functions
      -- involving all the classes of the cluster.
      --
inherit
   ACE_VISITOR
   ACE_CHECK_VISITOR
   ADDRESS_OF_POOL_VISITOR
   AGENT_POOL_VISITOR
   ASSIGNMENT_HANDLER_VISITOR
   BASE_CLASS_VISITOR
   C_PRETTY_PRINTER_VISITOR
   CECIL_FILE_VISITOR
   CECIL_POOL_VISITOR
   CLASS_NAME_VISITOR
   CLEAN_VISITOR
   CLUSTER_VISITOR
   CODE_ATTRIBUTE_VISITOR
   CODE_PRINTER_VISITOR
   COMMAND_LINE_TOOLS_VISITOR
   COMMENT_VISITOR
   COMPILE_VISITOR
   COMPILE_TO_C_VISITOR
   COMPILE_TO_JVM_VISITOR
   CONSTANT_POOL_VISITOR
   E_TYPE_VISITOR
   ECHO_VISITOR
   EIFFEL_PARSER_VISITOR
   ERROR_HANDLER_VISITOR
   EXPRESSION_VISITOR
   FINDER_VISITOR
   GC_HANDLER_VISITOR
   ID_PROVIDER_VISITOR
   INI_PARSER_VISITOR
   INSTRUCTION_VISITOR
   JVM_VISITOR
   MANIFEST_ARRAY_POOL_VISITOR
   MANIFEST_STRING_POOL_VISITOR
   METHOD_INFO_VISITOR
   ONCE_ROUTINE_POOL_VISITOR
   PARSER_VISITOR
   PARSER_BUFFER_VISITOR
   POSITION_VISITOR
   PRETTY_VISITOR
   PRETTY_PRINTER_VISITOR
   PRINT_JVM_CLASS_VISITOR
   RUN_CLASS_VISITOR
   RUN_FEATURE_VISITOR
   RUN_TIME_SET_VISITOR
   SAME_EXECUTABLES_VISITOR
   SHORT_VISITOR
   SHORT_PRINT_VISITOR
   SMART_EIFFEL_VISITOR
   STRING_ALIASER_VISITOR
   STRING_COMMAND_LINE_VISITOR
   SWITCH_VISITOR
   SWITCH_COLLECTION_VISITOR
   SYSTEM_TOOLS_VISITOR

end -- TOOLS_GROUP_VISITOR
