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
deferred class CALL_INFIX
   --
   -- For all sort of infix operators (root of all CALL_INFIX_*).
   --

inherit CALL_1 redefine print_as_target end

feature

   extra_bracket_flag: BOOLEAN is True

   left_brackets: BOOLEAN is
      deferred
      end

   right_brackets: BOOLEAN is
      do
         Result := not left_brackets
      end

   operator: STRING is
      deferred
      ensure
         Result.count >= 1
      end

   frozen simplify_2: EXPRESSION is
      do
	 target := target.simplify_2
	 arguments.simplify_2
	 Result := simplify_1_
      end
   
   frozen short is
      do
         if target.precedence = atomic_precedence then
            target.short
         elseif precedence > target.precedence then
            target.bracketed_short
         elseif precedence < target.precedence then
            target.short
         elseif left_brackets then
            target.bracketed_short
         else
            target.short
         end
         short_print_feature_name
         if arg1.precedence = atomic_precedence then
            arg1.short
         elseif precedence > arg1.precedence then
            arg1.bracketed_short
         elseif precedence < arg1.precedence then
            arg1.short
         elseif right_brackets then
            arg1.bracketed_short
         else
            arg1.short
         end
      end

   frozen short_target is
      do
         bracketed_short
         short_print.a_dot
      end

   frozen print_as_target is
      do
         pretty_printer.put_character('(')
         pretty_print
         pretty_printer.put_character(')')
         pretty_printer.put_character('.')
      end

   frozen bracketed_pretty_print is
      do
         pretty_printer.put_character('(')
         pretty_print
         pretty_printer.put_character(')')
      end
   
   frozen pretty_print is
      do
	 -- The `target' first:
         if target.precedence = atomic_precedence then
            target.pretty_print
         elseif precedence > target.precedence then
            target.bracketed_pretty_print
         elseif precedence < target.precedence then
            target.pretty_print
         elseif left_brackets then
            target.bracketed_pretty_print
         else
            target.pretty_print
         end
	 -- The operator:
	 pretty_printer.put_character(' ')
         feature_name.pretty_print
	 pretty_printer.put_character(' ')
	 -- The argument, `arg1':
         if arg1.precedence = atomic_precedence then
            arg1.pretty_print
         elseif precedence > arg1.precedence then
            arg1.bracketed_pretty_print
         elseif precedence < arg1.precedence then
            arg1.pretty_print
         elseif right_brackets then
            arg1.bracketed_pretty_print
         else
            arg1.pretty_print
         end
      end

feature {CALL_INFIX_VISITOR}

   accept(visitor: CALL_INFIX_VISITOR) is
      deferred
      end

feature {NONE}

   frozen short_print_feature_name is
      do
         short_print.a_infix_name("Binfix"," ","Ainfix"," ",feature_name)
      end

   frozen c2c_cast_op(cast, op: STRING) is
      do
         cpp.put_character('(')
         cpp.put_character('(')
         cpp.put_character('(')
         cpp.put_string(cast)
         cpp.put_character(')')
         cpp.put_character('(')
         target.compile_to_c
         cpp.put_character(')')
         cpp.put_character(')')
         cpp.put_string(op)
         cpp.put_character('(')
         cpp.put_character('(')
         cpp.put_string(cast)
         cpp.put_character(')')
         cpp.put_character('(')
         arg1.compile_to_c
         cpp.put_character(')')
         cpp.put_character(')')
         cpp.put_character(')')
      end

invariant

   feature_name.is_infix_name

end -- CALL_INFIX

