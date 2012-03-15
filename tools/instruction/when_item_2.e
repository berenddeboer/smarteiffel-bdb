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
class WHEN_ITEM_2
--
-- To store a slice value of a when clause in an inspect instruction.
--
-- Exemple :
--          inspect ...
--              when foo .. bar, then ...
--

inherit WHEN_ITEM

creation {E_WHEN,WHEN_ITEM_2}
   make

feature 

   lower, upper: EXPRESSION

   lower_value, upper_value: INTEGER

feature {E_WHEN}

   simplify_2(index: INTEGER; cc: CHARACTER_CONSTANT; ic: INTEGER_CONSTANT) is
      local
	 cc2a, cc2b: CHARACTER_CONSTANT; ic2a, ic2b: INTEGER_CONSTANT
      do
	 lower := lower.simplify_2
	 upper := upper.simplify_2
	 if cc /= Void then
	    cc2a ?= lower
	    cc2b ?= upper
	    if cc2a /= Void and then cc2b /= Void then
	       if cc.value.in_range(cc2a.value, cc2b.value) then
		  e_when.always_selected(index)
	       end
	    end
	 elseif ic /= Void then
	    ic2a ?= lower
	    ic2b ?= upper
	    if ic2a /= Void and then ic2b /= Void then
	       if ic.value_memory.in_range(ic2a.value_memory, ic2b.value_memory)
		then
		  e_when.always_selected(index)
	       end
	    end
	 end
      end
   
   verify_scoop(allowed: FORMAL_ARG_LIST) is
      local
         dummy: BOOLEAN
      do
         if lower /= Void then
            dummy := lower.verify_scoop(allowed)
         end
         if upper /= Void then
            dummy := upper.verify_scoop(allowed)
         end
      end

feature {NONE}

   make(l, u: EXPRESSION) is
      require
         l /= Void
         u /= Void
      do
         lower := l
         upper := u
      ensure
         lower = l
         upper = u
      end

feature {ANY}

   start_position: POSITION is
      do
         Result := lower.start_position
      end

feature {E_WHEN,WHEN_ITEM_2}

   to_runnable_integer(ew: like e_when): like Current is
      local
         ct: E_TYPE; v: like lower
      do
         if e_when = Void then
            e_when := ew
            ct := smart_eiffel.top_rf.current_type
            v := lower.to_runnable(ct)
            if v /= Void and then v.result_type.is_integer then
               lower := v
               lower_value := lower.to_integer_or_error
            else
               error(lower.start_position,fz_biv)
            end
            v := upper.to_runnable(ct)
            if v /= Void and then v.result_type.is_integer then
               upper := v
               upper_value := upper.to_integer_or_error
            else
               error(upper.start_position,fz_biv)
            end
            e_when.add_when_item_2(Current)
            Result := Current
         else
            !!Result.make(lower,upper)
            Result := Result.to_runnable_integer(ew)
         end
      end

   to_runnable_character(ew: like e_when): like Current is
      local
         ct: E_TYPE; v: like lower
      do
         if e_when = Void then
            e_when := ew
            ct := smart_eiffel.top_rf.current_type
            v := lower.to_runnable(ct)
            if v /= Void and then v.result_type.is_character then
               lower := v
               lower_value := lower.to_integer_or_error
            else
               error(lower.start_position,fz_bcv)
            end
            v := upper.to_runnable(ct)
            if v /= Void and then v.result_type.is_character then
               upper := v
               upper_value := upper.to_integer_or_error
            else
               error(upper.start_position,fz_bcv)
            end
            e_when.add_when_item_2(Current)
            Result := Current
         else
            !!Result.make(lower,upper)
            Result := Result.to_runnable_character(ew)
         end
      end

   to_runnable_string(ew: like e_when): like Current is
      do
         fatal_error("Unexpected runnable slice with string. This message should not appear: please contact the SmartEiffel team.");
      end;

   pretty_print is
      do
         lower.pretty_print
	 if not pretty_printer.zen_mode then
	    pretty_printer.put_character(' ')
	 end
         pretty_printer.put_string(once "..")
	 if not pretty_printer.zen_mode then
	    pretty_printer.put_character(' ')
	 end
         upper.pretty_print
      end

feature {WHEN_ITEM_2_VISITOR}

   accept(visitor: WHEN_ITEM_2_VISITOR) is
      do
         visitor.visit_when_item_2(Current)
      end

feature {E_WHEN}

   eval(exp: INTEGER): BOOLEAN is
      do
         Result := (lower_value <= exp) and (exp <= upper_value)
      end

end -- WHEN_ITEM_2

