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
deferred class EFFECTIVE_ROUTINE
   --
   -- Such a routine can have local variables.
   --

inherit E_ROUTINE

feature {EFFECTIVE_ROUTINE_VISITOR}

   accept(visitor: EFFECTIVE_ROUTINE_VISITOR) is
      deferred
      end

feature

   is_deferred: BOOLEAN is False

   local_vars: LOCAL_VAR_LIST

   routine_body: COMPOUND

   rescue_compound: COMPOUND

   frozen set_rescue_compound(c: like rescue_compound) is
      do
         rescue_compound := c
      ensure
         rescue_compound = c
      end

feature {NONE}

   use_current_state: INTEGER

   computed_true: INTEGER is unique

   computed_false: INTEGER is unique

   not_computed: INTEGER is unique

   in_computation: INTEGER is unique

   pretty_print_routine_body is
      do
         if local_vars /= Void then
            local_vars.pretty_print
         end
         pretty_printer.indent
         pretty_print_once_or_do
         pretty_printer.put_character(' ')
	 pretty_printer.indent
         if routine_body /= Void then
            routine_body.pretty_print
         end
      end

   pretty_print_once_or_do is
      deferred
      end

   pretty_print_rescue is
      do
         if rescue_compound /= Void then
            pretty_printer.set_indent_level(2)
            pretty_printer.indent
            pretty_printer.keyword(fz_rescue)
            rescue_compound.pretty_print
         end
      end

   make_effective_routine(n: like names
                          fa: like arguments
                          om: like obsolete_mark
                          hc: like header_comment
                          ra: like require_assertion
                          lv: like local_vars
                          rb: like routine_body) is
      do
         make_routine(n,fa,om,hc,ra)
         local_vars := lv
         routine_body := rb
         use_current_state := not_computed
      ensure
         local_vars = lv
         routine_body = rb
      end

end -- EFFECTIVE_ROUTINE
