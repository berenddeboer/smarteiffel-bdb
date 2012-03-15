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
deferred class ATTRIBUTE
   --
   -- For all sorts of attributes : constants (CST_ATT), unique
   --   (CST_ATT_UNIQUE) and instance variables (WRITABLE_ATTRIBUTE).
   --

inherit E_FEATURE

feature

   result_type: E_TYPE

   is_deferred: BOOLEAN is false

   obsolete_mark: MANIFEST_STRING is
      do
      end

   require_assertion: E_REQUIRE is
      do
      end

   ensure_assertion: E_ENSURE is
      do
      end

   pretty_print is
      do
         pretty_print_profile
         pretty_constant_value
	 if pretty_printer.print_end_of_feature then
	    pretty_printer.put_character(';')
	 end
         if header_comment /= Void then
            pretty_printer.set_indent_level(3)
            pretty_printer.indent
            header_comment.pretty_print
         end
	 pretty_printer.set_indent_level(1)
	 pretty_printer.indent
      end

   pretty_print_arguments is do end

   arguments: FORMAL_ARG_LIST is do end

feature {ATTRIBUTE_VISITOR}

   accept(visitor: ATTRIBUTE_VISITOR) is
      deferred
      end

feature {NONE}

   pretty_constant_value is
      deferred
      end

   try_to_undefine_aux(fn: FEATURE_NAME
                       bc: BASE_CLASS): DEFERRED_ROUTINE is
      do
         error_handler.add_position(start_position)
         error(fn.start_position,
               "An attribute must not be undefined (VDUS).")
         bc.fatal_undefine(fn)
      end

invariant

   no_arguments: arguments = Void

end -- ATTRIBUTE

