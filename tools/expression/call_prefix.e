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
deferred class CALL_PREFIX
   --
   -- For all sort of prefix operators.
   -- Root of all CALL_PREFIX_*.
   --

inherit
   CALL_0
      redefine print_as_target
      end

feature

   extra_bracket_flag: BOOLEAN is True
   
   operator: STRING is
      deferred
      end

   frozen simplify_2: EXPRESSION is
      do
	 target := target.simplify_2
	 Result := simplify_1_
      end
   
   frozen to_runnable(ct: E_TYPE): EXPRESSION is
      local
         copied: like Current
      do
	 if current_type = Void then
	    current_type := ct
	    runnable_target(ct)
	    run_feature_for(ct)
	    Result := Current.simplify_1
	    debug debug_info_update end
	    run_feature_match
	 else
	    copied := twin
	    copied.with(target, feature_name)
	    Result := copied.to_runnable(ct)
	 end
      end

   compile_to_c is
      do
         call_proc_call_c2c
      end

   frozen bracketed_pretty_print is
      do
         pretty_printer.put_character('(')
         pretty_print
         pretty_printer.put_character(')')
      end

   frozen pretty_print is
      do
         feature_name.pretty_print
         pretty_printer.put_character(' ')
         if target.precedence < precedence then
            pretty_printer.put_character('(')
            target.pretty_print
            pretty_printer.put_character(')')
         else
            target.pretty_print
         end
      end

   frozen print_as_target is
      do
         pretty_printer.put_character('(')
         pretty_print
         pretty_printer.put_character(')')
         pretty_printer.put_character('.')
      end

   frozen short is
      do
         short_print.a_prefix_name(feature_name)
         if target.precedence < precedence then
            target.bracketed_short
         else
            target.short
         end
      end

   frozen short_target is
      do
         bracketed_short
         short_print.a_dot
      end

feature {CALL_PREFIX_VISITOR}

   accept(visitor: CALL_PREFIX_VISITOR) is
      deferred
      end

feature {CALL_PREFIX}

   frozen with(t: like target; fn: like feature_name) is
      require
         t /= Void
         fn /= Void
      do
         run_feature := Void
         current_type := Void
         target := t
         feature_name := fn
      ensure
         target = t
         feature_name = fn
      end

end -- CALL_PREFIX
