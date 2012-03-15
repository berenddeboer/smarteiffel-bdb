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
class E_ENSURE
   --
   -- To store a `ensure' clause.
   --

inherit ASSERTION_LIST

creation with, make_runnable

feature

   is_require: BOOLEAN is false

   is_ensure_then: BOOLEAN

   name: STRING is
      do
         if is_ensure_then then
            Result := once "ensure then"
         else
            Result := once "ensure"
         end
      end

   side_effect_free: BOOLEAN is
      do
	 -- *** TO DO ***
      end
   
   short is
      local
         i: INTEGER
      do
         short_print.hook_or(once "hook511","      ensure%N")
         if header_comment = Void then
            short_print.hook_or(once "hook512",once "")
         else
            short_print.hook_or(once "hook513",once "")
            header_comment.short(once "hook514",once "         --",once "hook515",once "%N")
            short_print.hook_or(once "hook516",once "")
         end
         if list = Void then
            short_print.hook_or(once "hook517",once "")
         else
            short_print.hook_or(once "hook518",once "")
            from
               i := list.lower
            until
               i = list.upper
            loop
               list.item(i).short(once "hook519",once "         ", -- before each assertion
                                  once "hook520",once "", -- no tag
                                  once "hook521",once "", -- before tag
                                  once "hook522",once ": ", -- after tag
                                  once "hook523",once "", -- no expression
                                  once "hook524",once "", -- before expression
                                  once "hook525",once ";", -- after expression except last
                                  once "hook526",once "%N", -- no comment
                                  once "hook527",once "", -- before comment
                                  once "hook528",once " --", -- comment begin line
                                  once "hook529",once "%N", -- comment end of line
                                  once "hook530",once "", -- after comment
                                  once "hook531",once ""); -- end of each assertion

               i := i + 1
            end
            list.item(i).short(once "hook519",once "         ", -- before each assertion
                               once "hook520",once "", -- no tag
                               once "hook521",once "", -- before tag
                               once "hook522",once ": ", -- after tag
                               once "hook523",once "", -- no expression
                               once "hook524",once "", -- before expression
                               once "hook532",once "", -- after expression except last
                               once "hook526",once "%N", -- no comment
                               once "hook527",once "", -- before comment
                               once "hook528",once " --", -- comment begin line
                               once "hook529",once "%N", -- comment end of line
                               once "hook530",once "", -- after comment
                               once "hook531",once "")
            short_print.hook_or(once "hook533",once "")
         end
         short_print.hook_or(once "hook534",once "")
      end

feature {E_ENSURE_VISITOR}

   accept(visitor: E_ENSURE_VISITOR) is
      do
         visitor.visit_e_ensure(Current)
      end

feature {RUN_FEATURE}

   c_frame_descriptor(format, locals: STRING) is
      local
         i: INTEGER
      do
         if list /= Void then
            from
               i := list.lower
            until
               i > list.upper
            loop
               list.item(i).c_frame_descriptor(format,locals)
               i := i + 1
            end
         end
      end

feature {NONE}

   with(sp: like start_position; then_flag: BOOLEAN
	hc: like header_comment; l: like list) is
      do
	 make(sp, hc, l)
	 is_ensure_then := then_flag
      ensure
	 is_ensure_then = then_flag
      end
   
   check_assertion_mode: STRING is "ens"

end -- E_ENSURE

