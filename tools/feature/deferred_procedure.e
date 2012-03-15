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
class DEFERRED_PROCEDURE
   --
   -- For deferred routines.
   --

inherit DEFERRED_ROUTINE

creation make, from_effective

feature {DEFERRED_PROCEDURE_VISITOR}

   accept(visitor: DEFERRED_PROCEDURE_VISITOR) is
      do
         visitor.visit_deferred_procedure(Current)
      end

feature {NONE}

   make(n: like names
        fa: like arguments
        om: like obsolete_mark
        hc: like header_comment
        ra: like require_assertion) is
      do
         make_routine(n,fa,om,hc,ra)
      end

feature

   result_type: E_TYPE is
      do
      end

   from_effective(fn: FEATURE_NAME
        fa: like arguments
        ra: like require_assertion
        ea: like ensure_assertion
        bc: like base_class) is
      do
         !!names.make_1(fn)
         make_routine(names,fa,Void,Void,ra)
         set_ensure_assertion(ea)
         base_class := bc
      end

end -- DEFERRED_PROCEDURE

