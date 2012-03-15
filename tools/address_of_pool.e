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
class ADDRESS_OF_POOL
   --
   -- Unique global object in charge of $ operator calls.
   --

inherit
   GLOBALS
   VISITABLE

feature {ADDRESS_OF_POOL_VISITOR}

   accept(visitor: ADDRESS_OF_POOL_VISITOR) is
      do
         visitor.visit_address_of_pool(Current)
      end

feature {NONE}

   registered: FAST_ARRAY[RUN_FEATURE] is
      once
         !!Result.with_capacity(64)
      end

   caller_memory: FAST_ARRAY[ADDRESS_OF] is
      once
         !!Result.with_capacity(64)
      end

feature {ADDRESS_OF}

   register_for(address_of: ADDRESS_OF) is
      require
         address_of /= Void
      local
         rf: RUN_FEATURE
      do
         rf := address_of.run_feature
         if not registered.fast_has(rf) then
            registered.add_last(rf)
            caller_memory.add_last(address_of)
         end
      ensure
         registered.fast_has(address_of.run_feature)
      end

feature {SMART_EIFFEL}

   falling_down is
      local
         i: INTEGER
      do
         from
            i := registered.upper
         until
            i < 0
         loop
            switch_collection.update_with(registered.item(i))
            i := i - 1
         end
      end

   c_define is
      local
         i: INTEGER
      do
         i := registered.upper
         if i >= 0 then
            from
            until
               i < 0
            loop
               registered.item(i).address_of_c_define(caller_memory.item(i))
               i := i - 1
            end
         end
      end

end -- ADDRESS_OF_POOL
