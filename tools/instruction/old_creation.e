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
class OLD_CREATION
   --
   -- The good old style (bang bang !!) creation instruction.
   --

inherit
   CREATE_INSTRUCTION
      redefine
         pretty_print, accept
      end

creation {EIFFEL_PARSER,CREATE_INSTRUCTION} make

feature {OLD_CREATION_VISITOR}

   accept(visitor: OLD_CREATION_VISITOR) is
      do
         visitor.visit_old_creation(Current)
      end

feature

   pretty_print is
      do
         pretty_printer.put_character('!')
	 if type /= Void then
	    type.pretty_print
	 end
         pretty_printer.put_character('!')
	 if call /= Void then
	    call.pretty_print
	 else
	    writable.pretty_print
	    if pretty_printer.semi_colon_flag then
	       pretty_printer.put_character(';')
	    end
	 end
      end

end -- OLD_CREATION

