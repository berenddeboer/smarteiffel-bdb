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
class E_REQUIRE
   --
   -- To store a `require' clause.
   --

inherit ASSERTION_LIST

creation with, make_runnable

feature {E_REQUIRE_VISITOR}

   accept(visitor: E_REQUIRE_VISITOR) is
      do
         visitor.visit_e_require(Current)
      end

feature

   is_require: BOOLEAN is True

   is_require_else: BOOLEAN

   name: STRING is
      do
         if is_require_else then
            Result := once "require else"
         else
            Result := once "require"
         end
      end

   short(h1,r1: STRING) is
      local
         i: INTEGER
      do
         short_print.hook_or(h1,r1)
         if header_comment = Void then
            short_print.hook_or("hook412","")
         else
            short_print.hook_or("hook413","")
            header_comment.short("hook414","         --","hook415","%N")
            short_print.hook_or("hook416","")
         end
         if list = Void then
            short_print.hook_or("hook417","")
         else
            short_print.hook_or("hook418","")
            from
               i := list.lower
            until
               i = list.upper
            loop
               list.item(i).short("hook419","         ", -- before each assertion
                                  "hook420","", -- no tag
                                  "hook421","", -- before tag
                                  "hook422",": ", -- after tag
                                  "hook423","", -- no expression
                                  "hook424","", -- before expression
                                  "hook425",";", -- after expression except last
                                  "hook426","%N", -- no comment
                                  "hook427","", -- before comment
                                  "hook428"," --", -- comment begin line
                                  "hook429","%N", -- comment end of line
                                  "hook430","", -- after comment
                                  "hook431",""); -- end of each assertion

               i := i + 1
            end
            list.item(i).short("hook419","         ", -- before each assertion
                               "hook420","", -- no tag
                               "hook421","", -- before tag
                               "hook422",": ", -- after tag
                               "hook423","", -- no expression
                               "hook424","", -- before expression
                               "hook432","", -- after expression except last
                               "hook426","%N", -- no comment
                               "hook427","", -- before comment
                               "hook428"," --", -- comment begin line
                               "hook429","%N", -- comment end of line
                               "hook430","", -- after comment
                               "hook431","")
            short_print.hook_or("hook433","")
         end
         short_print.hook_or("hook434","")
      end

feature {NONE}

   with(sp: like start_position; else_flag: BOOLEAN
	hc: like header_comment; l: like list) is
      do
	 make(sp, hc, l)
	 is_require_else := else_flag
      ensure
	 is_require_else = else_flag
      end
   
   check_assertion_mode: STRING is "req"

end -- E_REQUIRE
