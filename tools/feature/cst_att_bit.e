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
class CST_ATT_BIT

inherit CST_ATT

creation make

feature {CST_ATT_BIT_VISITOR}

   accept(visitor: CST_ATT_BIT_VISITOR) is
      do
         visitor.visit_cst_att_bit(Current)
      end

feature

   value(i: INTEGER): BIT_CONSTANT is
      do
         Result := value_mem
      end

feature {NONE}

   value_mem: BIT_CONSTANT

   make(n: like names; t: like result_type; v: like value) is
      require
         n /= Void
         v /= Void
         t /= Void
      do
         make_e_feature(n)
         result_type := t
         value_mem := v
      ensure
         names = n
         result_type = t
         value_mem = v
      end

   pretty_constant_value_ is
      do
	 value_mem.pretty_print
      end

end -- CST_ATT_BIT

