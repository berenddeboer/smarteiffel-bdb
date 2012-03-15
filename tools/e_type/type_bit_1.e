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
class TYPE_BIT_1
   --
   -- Handling for example of "BIT 32", or "BIT 8", etc. type mark 
   --

inherit TYPE_BIT

creation make

feature

   n: INTEGER_CONSTANT

   is_run_type: BOOLEAN is True

   run_time_mark: STRING is
      do
         Result := written_mark
      end

   run_type: TYPE_BIT is
      do
         Result := Current
      end

   nb: INTEGER is
      do
         Result := n.value_memory.to_integer
      end

   to_runnable(rt: E_TYPE): like Current is
      do
         Result := Current
         to_runnable_1_2
      end

feature {E_TYPE}

   short_hook is
      do
         short_print.a_class_name(base_class_name)
         short_print.hook_or("tm_blank"," ")
         short_print.a_integer(n.value_memory)
      end

feature {TYPE_BIT_1_VISITOR}

   accept(visitor: TYPE_BIT_1_VISITOR) is
      do
         visitor.visit_type_bit_1(Current)
      end

feature {NONE}

   make(sp: like start_position; vn: like n) is
      require
         not sp.is_unknown
         vn.value_memory > 0
      do
         start_position := sp
         n := vn
         tmp_string.copy(as_bit)
	 tmp_string.extend(' ')
         nb.append_in(tmp_string)
         written_mark := string_aliaser.item(tmp_string)
      ensure
         start_position = sp
         n = vn
      end

invariant

   n /= Void

end -- TYPE_BIT_1

