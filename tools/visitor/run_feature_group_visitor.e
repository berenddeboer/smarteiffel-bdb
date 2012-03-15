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
deferred class RUN_FEATURE_GROUP_VISITOR
      --
      -- Visitor of all the classes of the `tools/run_feature' cluster.
      --
      -- It is just a convenient inheritance for those who implement functions
      -- involving all the classes of the cluster.
      --
inherit
   RUN_FEATURE_1_VISITOR
   RUN_FEATURE_10_VISITOR
   RUN_FEATURE_11_VISITOR
   RUN_FEATURE_2_VISITOR
   RUN_FEATURE_3_VISITOR
   RUN_FEATURE_4_VISITOR
   RUN_FEATURE_5_VISITOR
   RUN_FEATURE_6_VISITOR
   RUN_FEATURE_7_VISITOR
   RUN_FEATURE_8_VISITOR
   RUN_FEATURE_9_VISITOR

end -- RUN_FEATURE_GROUP_VISITOR
