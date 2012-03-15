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
class TAG_NAME

inherit
   GLOBALS
   VISITABLE

creation make

feature {TAG_NAME_VISITOR}

   accept(visitor: TAG_NAME_VISITOR) is
      do
         visitor.visit_tag_name(Current)
      end

feature

   to_string: STRING

   start_position: POSITION

   to_key: STRING is
      do
         Result := to_string
      end

   short is
      local
         i: INTEGER; c: CHARACTER
      do
         short_print.hook("Btag")
         from
            i := 1
         until
            i > to_string.count
         loop
            c := to_string.item(i)
            if c = '_' then
               short_print.hook_or("Utag","_")
            else
               short_print.a_character(c)
            end
            i := i + 1
         end
         short_print.hook("Atag")
      end

feature {NONE}

   make(n: STRING; sp: like start_position) is
      require
         n = string_aliaser.item(n)
      do
         to_string := n
         start_position := sp
      ensure
         to_string = n
         start_position = sp
      end

end -- TAG_NAME

