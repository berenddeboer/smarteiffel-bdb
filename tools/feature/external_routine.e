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
deferred class EXTERNAL_ROUTINE
   --
   -- For routines implemented with a call to a foreign language.
   -- Root of EXTERNAL_PROCEDURE and EXTERNAL_FUNCTION.
   --

inherit E_ROUTINE

feature

   native: NATIVE

   alias_string: STRING

   is_deferred: BOOLEAN is false

   frozen set_rescue_compound(c: COMPOUND) is
      do
         if c /= Void then
            error_handler.add_position(c.start_position)
         else
            error_handler.add_position(start_position)
         end
         error_handler.append("External feature must not have rescue compound.")
         error_handler.print_as_fatal_error
      end

   frozen use_current: BOOLEAN is
      do
         Result := native.use_current(Current)
      end

   external_name: STRING is
      local
	 native_c_plus_plus: NATIVE_C_PLUS_PLUS; tmp: STRING
      do
	 native_c_plus_plus ?= native
	 if native_c_plus_plus = Void then
	    Result := c_plus_plus_name
	 else
	    -- For C++, there is always a wrapping function :
	    tmp := first_name.to_string
	    !!Result.make(tmp.count + 8)
	    Result.append(once "cpp")
	    base_class.id.append_in(Result)
	    Result.append(tmp)
	 end
      end

feature {NATIVE_C}

   argument_rank_of(arg_name: STRING): INTEGER is
	 -- Gives 0 or the index of `arg_name'.
      require
	 arg_name = string_aliaser.item(arg_name)
      do
	 if arguments /= Void then
	    Result := arguments.rank_of(arg_name)
	 end
      ensure
	 arguments /= Void implies Result.in_range(0,arguments.count)
	 arguments = Void implies Result = 0
      end

feature {NATIVE_C_PLUS_PLUS}

   c_plus_plus_name: STRING is
	 -- The name of the corresponding member in C++ is the
	 -- `alias_string' if any or the `first_name' itself.
      do
         if alias_string = Void then
            Result := first_name.to_string
         else
            Result := alias_string
         end
      end

feature {EXTERNAL_ROUTINE_VISITOR}

   accept(visitor: EXTERNAL_ROUTINE_VISITOR) is
      deferred
      end

feature {NONE}

   pretty_print_routine_body is
      do
         pretty_printer.keyword(once "external")
         native.pretty_print
         if not external_name.is_equal(first_name.to_string) or else
            names.count > 1 then
            pretty_printer.indent
            pretty_printer.keyword(once "alias")
            pretty_printer.put_character('%"')
            pretty_printer.put_string(external_name)
            pretty_printer.put_character('%"')
         end
      end

   pretty_print_rescue is
      do
      end

   make_external_routine(n: like native; desc: STRING) is
      require
         n /= void
      do
         native := n
         alias_string := desc
      end

end -- EXTERNAL_ROUTINE

