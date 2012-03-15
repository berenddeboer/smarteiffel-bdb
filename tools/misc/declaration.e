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
deferred class DECLARATION
   --
   -- To store the syntax of the user in a declaration list, a single
   -- declaration is a DECLARATION_1 and a group of variables with the
   -- the same type is a DECLARATION_GROUP.
   --

inherit
   GLOBALS
   VISITABLE

feature

   pretty_print_in(buffer: STRING) is
      deferred
      end

   short is
      deferred
      end

feature {DECLARATION_VISITOR}

   accept(visitor: DECLARATION_VISITOR) is
      deferred
      end

feature {DECLARATION_LIST}

   count: INTEGER is
         -- One or more items.
      deferred
      ensure
         Result >= 1
      end

feature {DECLARATION_LIST}

   append_in(dl: DECLARATION_LIST) is
         -- Append current declaration in `dl'.
      require
         dl /= Void
      deferred
      end

end -- DECLARATION

