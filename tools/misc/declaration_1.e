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
class DECLARATION_1
   --
   -- For a single declaration like :
   --             foo : BAR
   --

inherit DECLARATION

creation make

feature

   start_position: POSITION is
      do
         Result := name.start_position
      end

   pretty_print_in(buffer: STRING) is
      do
         buffer.append(name.to_string)
	 buffer.append(once ": ")
         buffer.append(name.result_type.written_mark)
      end

   short is
      do
         name.short
         short_print.hook_or("hook35",": ")
         name.result_type.short
      end

feature {DECLARATION_1_VISITOR}

   accept(visitor: DECLARATION_1_VISITOR) is
      do
         visitor.visit_declaration_1(Current)
      end

feature {DECLARATION_LIST}

   count: INTEGER is 1

feature {DECLARATION_LIST}

   append_in(dl: DECLARATION_LIST) is
      do
         dl.add_last(name)
      end

feature {NONE}

   name: LOCAL_ARGUMENT1
         -- Of the declared variable.

   make(n: like name; type: E_TYPE) is
      require
         n /= Void
      do
         name := n
         name.set_result_type(type)
      ensure
         name = n
      end

end -- DECLARATION_1
