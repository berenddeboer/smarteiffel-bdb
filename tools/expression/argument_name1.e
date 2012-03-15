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
class ARGUMENT_NAME1
   --
   -- An argument name in some declaration list.
   --

inherit
   LOCAL_ARGUMENT1
   ARGUMENT_NAME

creation make

feature

   to_runnable(ct: E_TYPE): like Current is
      local
         rt: E_TYPE
      do
         rt := result_type.to_runnable(ct)
         if rt = Void then
            error_handler.add_position(result_type.start_position)
            error(start_position,fz_bad_argument)
         end
	 if result_type = rt then
            Result := Current
         else
            Result := twin
            Result.set_result_type(rt)
         end
      end

feature {DECLARATION_LIST}

   name_clash(ct: E_TYPE) is
      do
         name_clash_for(ct,once "Conflict between argument/feature name (VRFA).")
      end

feature {ARGUMENT_NAME1_VISITOR}

   accept(visitor: ARGUMENT_NAME1_VISITOR) is
      do
         visitor.visit_argument_name1(Current)
      end

feature {NONE}

   make(sp: POSITION; n: STRING) is
      require
         not sp.is_unknown
         n = string_aliaser.item(n)
      do
         start_position := sp
         to_string := n
      ensure
         start_position = sp
         to_string = n
      end

end -- ARGUMENT_NAME1
