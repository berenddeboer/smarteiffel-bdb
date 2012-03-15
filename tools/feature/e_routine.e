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
deferred class E_ROUTINE
   --
   -- Root class for all sort of routines : function, procedure,
   -- external function/procedure, deferred function/procedure and
   -- once function/procedure.
   --
   --

inherit E_FEATURE redefine  set_header_comment end

feature

   arguments: FORMAL_ARG_LIST

   obsolete_mark: MANIFEST_STRING

   require_assertion: E_REQUIRE

   ensure_assertion: E_ENSURE

   end_comment: COMMENT

   pretty_print is
      local
         fn: FEATURE_NAME
      do
         pretty_print_profile
         pretty_printer.keyword(fz_is)
         if obsolete_mark /= Void then
            pretty_printer.set_indent_level(2)
            pretty_printer.indent
            pretty_printer.keyword(fz_obsolete)
            obsolete_mark.pretty_print
         end
         if header_comment /= Void then
	    pretty_printer.set_indent_level(3)
	    pretty_printer.indent
            header_comment.pretty_print
	    pretty_printer.set_indent_level(2)
         end
         pretty_printer.set_indent_level(2)
         pretty_printer.indent
         if require_assertion /= Void then
            require_assertion.pretty_print
         end
         pretty_printer.set_indent_level(2)
         pretty_printer.indent
         pretty_print_routine_body
         if ensure_assertion /= Void then
            pretty_printer.set_indent_level(2)
            ensure_assertion.pretty_print
         end
         pretty_print_rescue
         pretty_printer.set_indent_level(2)
         pretty_printer.indent
         pretty_printer.keyword(fz_end)
         if end_comment /= Void
	    and then not end_comment.is_dummy_feature_end(Current) then
            end_comment.pretty_print
         elseif pretty_printer.print_end_of_feature then
            pretty_printer.put_string(once "-- ")
            fn := first_name
            fn.declaration_pretty_print
         end
         pretty_printer.set_indent_level(1)
         pretty_printer.indent
      end

   set_header_comment(hc: like header_comment) is
	 -- Is the `end_comment' for routines.
      do
         if hc /= Void and then hc.count > 1 then
            end_comment := hc
         end
      end

feature {EIFFEL_PARSER}

   set_sedb_trace_before_exit(end_start_position: POSITION) is
      require
	 ace.sedb ; not end_start_position.is_unknown
      do
	 sedb_trace_before_exit := end_start_position
      ensure
	 sedb_trace_before_exit = end_start_position
      end
   
   set_ensure_assertion(ea: like ensure_assertion) is
      do
         ensure_assertion := ea
      ensure
         ensure_assertion = ea
      end

   set_rescue_compound(c: COMPOUND) is
      deferred
      end

feature {E_ROUTINE_VISITOR}

   accept(visitor: E_ROUTINE_VISITOR) is
      deferred
      end

feature {NONE}

   make_routine(n: like names
                fa: like arguments
                om: like obsolete_mark
                hc: like header_comment
                ra: like require_assertion) is
      do
         make_e_feature(n)
         header_comment := hc
         arguments := fa
         obsolete_mark := om
         require_assertion := ra
      end

   frozen pretty_print_arguments is
      do
         if arguments /= Void then
            arguments.pretty_print
         end
      end

   pretty_print_routine_body is
      require
         pretty_printer.indent_level = 2
      deferred
      end

   pretty_print_rescue is
      deferred
      end

end -- E_ROUTINE

