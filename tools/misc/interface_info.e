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
class INTERFACE_INFO
   --
   -- Unique Global Object to delay field info writing.
   -- Obviously, the same object is recycled.
   --
inherit
   GLOBALS
   VISITABLE

feature {INTERFACE_INFO_VISITOR}

   accept(visitor: INTERFACE_INFO_VISITOR) is
      do
         visitor.visit_interface_info(Current)
      end

feature {NONE}

   count: INTEGER
         -- Number of fields.

   storage: STRING is
         -- To store the final JVM `method_info'.
      once
         !!Result.make(512)
      end

feature {JVM}

   clear is
      do
         count := 0
         storage.clear_count
      end

   write_bytes is
      do
         echo.print_count("interface",count)
         jvm.b_put_u2(count)
         jvm.b_put_byte_string(storage)
      end

feature

   add( name_idx: INTEGER) is
      do
         count := count + 1
         append_u2(storage,name_idx)
         -- attributes_count :
-- include this?         append_u2(storage,0)
      end

end -- INTERFACE_INFO

