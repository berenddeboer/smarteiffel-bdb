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
class FIELD_MODIFIER
   --
   -- Holds JVM field modifiers.
   --
inherit
   GLOBALS
   VISITABLE

feature {FIELD_MODIFIER_VISITOR}

   accept(visitor: FIELD_MODIFIER_VISITOR) is
      do
         visitor.visit_field_modifier(Current)
      end

feature

   is_transient: BOOLEAN
   
   set_transient is
      do
         is_transient := True
      end
      
   clear_transient is
      do
         is_transient := False
      end

feature
      
   is_volatile: BOOLEAN
   
   set_volatile is
      do
         is_volatile := True
      end
      
   clear_volatile is
      do
         is_volatile := False
      end      

feature

   access_flags: INTEGER is
      do
         Result := 1
         if is_transient then
            Result := Result + 128
         end
         if is_volatile then
            Result := Result + 64
         end         
      end

end -- FIELD_MODIFIER

