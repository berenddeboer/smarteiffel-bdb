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
class CST_ATT_UNIQUE
   --
   -- For "unique" constant attribute.
   --

inherit CST_ATT

creation make

feature {CST_ATT_UNIQUE_VISITOR}

   accept(visitor: CST_ATT_UNIQUE_VISITOR) is
      do
         visitor.visit_cst_att_unique(Current)
      end

feature

   value(i: INTEGER): INTEGER_CONSTANT is
      do
         Result := values.item(i - 1)
      end

feature {NONE}

   values: FIXED_ARRAY[INTEGER_CONSTANT]

   make(n: like names; t: like result_type) is
      require
         n /= Void
         t.is_integer
      local
         i, j: INTEGER; ic: INTEGER_CONSTANT
      do
         make_e_feature(n)
         result_type := t
         i := names.count
         create values.with_capacity(i)
         from
            j := 1
         until
            i = 0
         loop
            counter.increment
            create ic.make(counter.value, names.item(j).start_position)
            values.add_last(ic)
            j := j + 1
            i := i - 1
         end
      end

   pretty_constant_value_ is
      do
         pretty_printer.put_string(once "unique")
      end

   counter: COUNTER is
      once
         create Result
      end

end -- CST_ATT_UNIQUE

