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
deferred class CST_ATT
   --
   -- For all ConSTant Attributes.
   --

inherit ATTRIBUTE

feature

   value(i: INTEGER): EXPRESSION is
         -- Result will be redefine as: REAL_CONSTANT, INTEGER_CONSTANT,
         -- CHARACTER_CONSTANT, BOOLEAN_CONSTANT or MANIFEST_STRING.
      require
         1 <= i
         i <= names.count
      deferred
      ensure
         Result /= Void
      end

   to_run_feature(ct: E_TYPE; fn: FEATURE_NAME): RUN_FEATURE_1 is
      local
         rc: RUN_CLASS
      do
         rc := ct.run_class
         Result ?= rc.at(fn)
         if Result = Void then
            !!Result.make(ct,fn,Current)
         end
      end

feature {CST_ATT_VISITOR}

   accept(visitor: CST_ATT_VISITOR) is
      deferred
      end

feature {NONE}

   frozen pretty_constant_value is
      do
         pretty_printer.put_string(once " is ")
	 pretty_constant_value_
      end

   pretty_constant_value_ is
      deferred
      end

end -- CST_ATT

