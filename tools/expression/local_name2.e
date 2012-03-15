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
class LOCAL_NAME2
   --
   -- A local name used somewhere.
   --

inherit LOCAL_NAME

creation refer_to

feature

   rank: INTEGER
	 -- The `rank' of the corresponding declaration in `local_var_list'.

   assertion_check(tag: CHARACTER) is
      do
         check tag /= 'R' end
         if tag = 'E' then
            error_handler.add_position(start_position)
            fatal_error("Cannot use local variable here (VEEN).")
         end
      end

   to_string: STRING is
      do
         Result := local_var_list.name(rank).to_string
      end

   result_type: E_TYPE is
      do
         Result := local_var_list.type(rank)
      end

   to_runnable(ct: E_TYPE): like Current is
      local
         rf: RUN_FEATURE; lvl: LOCAL_VAR_LIST
      do
         rf := smart_eiffel.top_rf
         lvl := rf.local_vars
         if local_var_list = lvl then
            Result := Current
         else
            create Result.refer_to(start_position,lvl,rank)
         end
         lvl.name(rank).set_is_live
      end

feature {LOCAL_NAME2_VISITOR}

   accept(visitor: LOCAL_NAME2_VISITOR) is
      do
         visitor.visit_local_name2(Current)
      end

feature {NONE}

   local_var_list: LOCAL_VAR_LIST

   refer_to(sp: POSITION; lvl: LOCAL_VAR_LIST; r: like rank) is
         -- Using name `r' of `dcl' at place `sp'.
      require
         not sp.is_unknown
         r.in_range(1,lvl.count)
      do
         start_position := sp
         local_var_list := lvl
         rank := r
	 lvl.name(r).refer_to_increment
      ensure
         start_position = sp
         local_var_list = lvl
         rank = r
      end

end -- LOCAL_NAME2
