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
class DECLARATION_GROUP
   --
   -- When a group of variable have the same type mark.
   --
   -- Exemple 1 :
   --         local
   --           foo, bar : ZOO
   --           --------------
   --
   -- Exemple 2 :
   --         bip(foo, bar : ZOO) is
   --             --------------
   --
   -- See Eiffel3 grammar for more details.
   --
   -- Note : it is necessary to have a good pretty pretty_printing to store
   --        the user's original text.
   --

inherit DECLARATION

creation {EIFFEL_PARSER} make

feature {DECLARATION_GROUP_VISITOR}

   accept(visitor: DECLARATION_GROUP_VISITOR) is
      do
         visitor.visit_declaration_group(Current)
      end

feature {NONE}

   name_list: ARRAY[LOCAL_ARGUMENT1]

feature {NONE}

   make(nl: like name_list; type: E_TYPE) is
      require
         nl /= Void
         1 < nl.count
         type /= Void
      local
         i: INTEGER
      do
         name_list := nl
         from
            i := name_list.upper
         until
            i = 0
         loop
            name_list.item(i).set_result_type(type)
            i := i - 1
         end
      ensure
         name_list = nl
      end

feature

   pretty_print_in(buffer: STRING) is
      local
         i: INTEGER
      do
         from
            i := name_list.lower
            buffer.append(name_list.item(i).to_string)
            i := i + 1
         until
            i > name_list.upper
         loop
            buffer.extend(',')
	    if not pretty_printer.zen_mode then
	       buffer.extend(' ')
	    end
            buffer.append(name_list.item(i).to_string)
            i := i + 1
         end
         buffer.append(once ": ")
	 buffer.append(name_list.first.result_type.written_mark)
      end

   short is
      local
         i: INTEGER
      do
         from
            i := name_list.lower
            name_list.item(i).short
            i := i + 1
         until
            i > name_list.upper
         loop
            short_print.hook_or("hook304",", ")
            name_list.item(i).short
            i := i + 1
         end
         short_print.hook_or("hook305",": ")
         name_list.item(1).result_type.short
      end

feature {DECLARATION_LIST}

   count: INTEGER is
      do
         Result := name_list.upper
      end

feature {DECLARATION_LIST}

   append_in(dl: DECLARATION_LIST) is
      local
         i: INTEGER
      do
         from
            i := name_list.lower
         until
            i > name_list.upper
         loop
            dl.add_last(name_list.item(i))
            i := i + 1
         end
      end

invariant

   name_list.lower = 1

   name_list.upper >= 2

end -- DECLARATION_GROUP

