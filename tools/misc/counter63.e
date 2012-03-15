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
class COUNTER63
   --
   -- A base-63 counter
   --
inherit
   GLOBALS
   VISITABLE

creation
   make

feature

   make is
      do
         value := "0"
      end

   next is
      do
         increment_at(1)
      end

   append_in(s: STRING) is
      do
         s.append(value)
      end

feature {NONE}

   value: STRING

   increment_at(i: INTEGER) is
      require
         value.valid_index(i)
      local
         c: CHARACTER
      do
         c := value.item(i)
         inspect
            c
         when '0'..'8', 'a'..'y', 'A'..'Y' then
            value.put((c.code+1).to_character, i)
         when '9' then
            value.put('a', i)
         when 'z' then
            value.put('A', i)
         when 'Z' then
            value.put('_', i)
         when '_' then
            value.put('0', i)
            if i = value.count then
               value.extend('1')
            else
               increment_at(i+1)
            end
         end
      ensure
         value.count >= old value.count
         value.item(i) /= old value.item(i)
      end

feature {COUNTER63_VISITOR}

   accept(visitor: COUNTER63_VISITOR) is
      do
         visitor.visit_counter63(Current)
      end

end
