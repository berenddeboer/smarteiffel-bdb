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
class RENAME_PAIR
   --
   -- To store a rename pair of Eiffel construct :
   --    "inherit ... rename ... as ... end"
   --

inherit
   GLOBALS
   VISITABLE

creation make

feature {RENAME_PAIR_VISITOR}

   accept(visitor: RENAME_PAIR_VISITOR) is
      do
         visitor.visit_rename_pair(Current)
      end

feature

   old_name, new_name: FEATURE_NAME

   make(on, nn: like old_name) is
      require
         on /= Void
         nn /= Void
      do
         if on.to_string = nn.to_string then
            error_handler.add_position(on.start_position)
            error_handler.add_position(nn.start_position)
            error_handler.append("New name and old name must be different.")
	    error_handler.print_as_fatal_error
         end
         old_name := on
         new_name := nn
      ensure
         old_name = on
         new_name = nn
      end

   pretty_print is
      do
         old_name.declaration_pretty_print
         pretty_printer.keyword(once "as")
         new_name.declaration_pretty_print
      end

end -- RENAME_PAIR

