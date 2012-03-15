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
class CST_ATT_STRING

inherit CST_ATT

creation make

feature {CST_ATT_STRING_VISITOR}

   accept(visitor: CST_ATT_STRING_VISITOR) is
      do
         visitor.visit_cst_att_string(Current)
      end

feature

   value(i: INTEGER): MANIFEST_STRING is
      do
         if i = 1 then
            Result := first_value
         else
            Result := remainder.item(i - 2)
         end
      end

feature {NONE}

   first_value: MANIFEST_STRING

   remainder: FAST_ARRAY[MANIFEST_STRING]

   make(n: like names; t: like result_type; v: like value) is
      require
         n /= Void
         t /= Void
         v /= Void
      local
         i: INTEGER
      do
         make_e_feature(n)
         result_type := t
         first_value := v
         i := names.count
         if i > 1 then
            from
               i := i - 1
               create remainder.make(i)
            until
               i = 0
            loop
               i := i - 1
               remainder.put(v.twin,i)
            end
         end
      ensure
         names = n
         result_type = t
      end

   pretty_constant_value_ is
      local
	 once_flag: BOOLEAN
      do
	 once_flag := first_value.once_flag
	 -- To ensure that the unused once keyword is not printed:
	 first_value.set_once_flag(False)
	 first_value.pretty_print
	 first_value.set_once_flag(once_flag)
      end

end -- CST_ATT_STRING

