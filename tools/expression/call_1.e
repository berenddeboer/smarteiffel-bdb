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
deferred class CALL_1
   --
   -- For calls with only one argument.
   --

inherit CALL

feature

   arg_count: INTEGER is 1

   arguments: EFFECTIVE_ARG_LIST

   frozen arg1: EXPRESSION is
      do
         Result := arguments.first
      end

   frozen to_integer_or_error: INTEGER is
      do
	 to_integer_error
      end

feature {CALL_1_VISITOR}

   accept(visitor: CALL_1_VISITOR) is
      deferred
      end

feature {NONE}

   frozen run_feature_match is
      do
         run_feature_has_result
         smart_eiffel.argument_passing_check(feature_name.start_position,
					     arguments,run_feature)
      end

invariant

   arguments.count = 1

end -- CALL_1

