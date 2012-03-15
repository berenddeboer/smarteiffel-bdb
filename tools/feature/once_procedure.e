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
class ONCE_PROCEDURE

inherit
   ONCE_ROUTINE
      rename make_effective_routine as make
      export {ANY} make
      end

creation make

feature {ONCE_PROCEDURE_VISITOR}

   accept(visitor: ONCE_PROCEDURE_VISITOR) is
      do
         visitor.visit_once_procedure(Current)
      end

feature

   result_type: E_TYPE is
      do
      end

   to_run_feature(t: E_TYPE; fn: FEATURE_NAME): RUN_FEATURE_5 is
      do
         !!Result.make(t,fn,Current)
      end

feature {NONE}

   try_to_undefine_aux(fn: FEATURE_NAME
                       bc: BASE_CLASS): DEFERRED_ROUTINE is
      do
         !DEFERRED_PROCEDURE!Result.from_effective(fn,arguments,
                                                   require_assertion,
                                                   ensure_assertion,
                                                   bc)
      end

end -- ONCE_PROCEDURE

