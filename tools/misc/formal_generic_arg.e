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
class FORMAL_GENERIC_ARG
   --
   -- To store one formal generic argument.
   --

inherit
   GLOBALS
   VISITABLE

creation make

feature {FORMAL_GENERIC_ARG_VISITOR}

   accept(visitor: FORMAL_GENERIC_ARG_VISITOR) is
      do
         visitor.visit_formal_generic_arg(Current)
      end

feature

   name: CLASS_NAME
         -- Name of the formal generic argument.

   constraint: E_TYPE
	 -- Non Void if any.

   rank: INTEGER
         -- In the corresponding declation list.

   constrained: BOOLEAN is
      do
         Result := (constraint /= void)
      end

   start_position: POSITION is
      do
         Result := name.start_position
      end

   pretty_print is
      do
         name.pretty_print
         if constrained then
            pretty_printer.indent_level_increment
            pretty_printer.put_string(once "->")
            constraint.pretty_print
            pretty_printer.indent_level_decrement
         end
      end

   short is
      do
         short_print.a_magic_class_name(name)
         if constrained then
            short_print.hook_or("arrow","->")
            constraint.short
         end
      end

feature {FORMAL_GENERIC_LIST}

   check_generic_formal_arguments is
      do
         if smart_eiffel.loaded_base_class(name) /= Void then
            error_handler.add_position(name.start_position)
            error_handler.append(
               "A formal generic argument must not be the %
	       %name of an existing class (VCFG.1).")
	    error_handler.print_as_fatal_error
         end
      end

   set_rank(r: like rank) is
      require
	 r > 0
      do
	 rank := r
      ensure
	 rank = r
      end

   constraint_substitution(fga: like Current; r: INTEGER) is
	 -- Substitute in the previously read `Current' `constraint'
	 -- all occurrences of `fga' which will be added at rank `r'.
      local
	 fgan: STRING; cn: CLASS_NAME
      do
	 if constraint /= Void then
	    fgan := fga.name.to_string
	    if constraint.is_generic then
	       substitute(constraint.generic_list,fga,r,fgan)
	    else
	       cn := constraint.base_class_name
	       if fgan = cn.to_string then
		  create {TYPE_FORMAL_GENERIC} constraint.make(cn, fga, r)
	       end
	    end
	 end
      end

feature {NONE}

   substitute(gl: ARRAY[E_TYPE]; fga: like Current; r: INTEGER; fgan: STRING) is
	 -- Substitute recursively all occurrences of `fgan' in `gl'.
      require
	 gl /= Void
	 fgan = fga.name.to_string
      local
	 i: INTEGER
	 tfg: TYPE_FORMAL_GENERIC
	 t: E_TYPE
	 cn: CLASS_NAME
      do
	 from
	    i := gl.upper
	 until
	    i < gl.lower
	 loop
	    t := gl.item(i)
	    if t.is_generic then
	       substitute(t.generic_list,fga,r,fgan)
	    else
	       cn := t.base_class_name
	       if fgan = cn.to_string then
		  !!tfg.make(cn,fga,r)
		  gl.put(tfg,i)
	       end
	    end
	    i := i - 1
	 end
      end

   make(n: like name; c: like constraint) is
      require
         n /= Void
      do
         name := n
         constraint := c
      ensure
         name = n
         constraint = c
      end

invariant

   name /= Void

end -- FORMAL_GENERIC_ARG

