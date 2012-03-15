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
deferred class NAME
   --
   -- Handling of all sort of names you can find in an Eiffel
   -- source file :
   --
   --   CLASS_NAME : a base class name.
   --   FEATURE_NAME: a feature name.
   --   LOCAL_ARGUMENT (deferred)
   --      LOCAL_NAME (deferred)
   --         LOCAL_NAME1: in a declaration list.
   --         LOCAL_NAME2: used in an expression.
   --      ARGUMENT_NAME (deferred)
   --         ARGUMENT_NAME1: in a declaration list.
   --         ARGUMENT_NAME2: used in an expression.
   --

inherit
   GLOBALS
   VISITABLE

feature

   extra_bracket_flag: BOOLEAN is False

   frozen bracketed_pretty_print is
      do
	 pretty_print
      end
   
   start_position: POSITION is
         -- The position of the first character of `to_string' in the text source.
      deferred
      end

   to_string: STRING is
         -- The corresponding name (alone in a STRING).
      deferred
      ensure
         not Result.is_empty
         Result = string_aliaser.item(Result)
      end

   pretty_print is
      deferred
      end

   frozen line: INTEGER is
      require
         start_position /= Void
      do
         Result := start_position.line
      end

   frozen column: INTEGER is
      require
         start_position /= Void
      do
         Result := start_position.column
      end

feature {NAME_VISITOR}

   accept(visitor: NAME_VISITOR) is
      deferred
      end

end -- NAME

