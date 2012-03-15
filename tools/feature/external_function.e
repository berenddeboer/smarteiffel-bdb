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
class EXTERNAL_FUNCTION
   --
   -- Call to a function of a foreign language.
   --

inherit EXTERNAL_ROUTINE

creation make

feature

   result_type: E_TYPE

   to_run_feature(ct: E_TYPE; fn: FEATURE_NAME): RUN_FEATURE_8 is
      do
         create Result.make(ct, fn, Current)
      end

feature {EXTERNAL_FUNCTION_VISITOR}

   accept(visitor: EXTERNAL_FUNCTION_VISITOR) is
      do
         visitor.visit_external_function(Current)
      end

feature {NONE}

   make(n: like names; fa: like arguments; t: like result_type
        om: like obsolete_mark; hc: like header_comment;
	ra: like require_assertion; l: like native; en: STRING) is
      require
         t /= Void; l /= Void
      do
         make_routine(n,fa,om,hc,ra)
         result_type := t
         make_external_routine(l,en)
      end

   try_to_undefine_aux(fn: FEATURE_NAME
                       bc: BASE_CLASS): DEFERRED_ROUTINE is
      do
         create {DEFERRED_FUNCTION}
	    Result.from_effective(fn,arguments,
	                          result_type,
				  require_assertion,
				  ensure_assertion,
				  bc)
      end

end -- EXTERNAL_FUNCTION
