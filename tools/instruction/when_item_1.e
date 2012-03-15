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
class WHEN_ITEM_1
--
-- To store a single value of a when clause in an inspect instruction.
--
-- Exemple :
--          inspect ...
--              when foo, bar, then ...
--

inherit WHEN_ITEM

creation {E_WHEN, WHEN_ITEM_1} make

feature

   expression: EXPRESSION

   expression_value: INTEGER

   start_position: POSITION is
      do
         Result := expression.start_position
      end

feature {E_WHEN}

   simplify_2(index: INTEGER; cc: CHARACTER_CONSTANT; ic: INTEGER_CONSTANT) is
      local
	 cc2: CHARACTER_CONSTANT; ic2: INTEGER_CONSTANT
      do
	 expression := expression.simplify_2
	 if cc /= Void then
	    cc2 ?= expression
	    if cc2 /= Void then
	       if cc.value = cc2.value then
		  e_when.always_selected(index)
	       end
	    end
	 elseif ic /= Void then
	    ic2 ?= expression
	    if ic2 /= Void then
	       if ic.value_memory = ic2.value_memory then
		  e_when.always_selected(index)
	       end
	    end
	 end
      end
   
   verify_scoop(allowed: FORMAL_ARG_LIST) is
      local
         dummy: BOOLEAN
      do
         if expression /= Void then
            dummy := expression.verify_scoop(allowed)
         end
      end

feature {E_WHEN, WHEN_ITEM_1}

   to_runnable_integer(ew: like e_when): like Current is
      local
         ct: E_TYPE; e: like expression
      do
         if e_when = Void then
            e_when := ew
            ct := smart_eiffel.top_rf.current_type
            e := expression.to_runnable(ct)
            if e /= Void and then e.result_type.is_integer then
               expression := e
               expression_value := expression.to_integer_or_error
               e_when.add_when_item_1(Current)
            else
               error(expression.start_position,fz_biv)
            end
            Result := Current
         else
            !!Result.make(expression)
            Result := Result.to_runnable_integer(ew)
         end
      end

   to_runnable_character(ew: like e_when): like Current is
      local
         ct: E_TYPE; e: like expression
      do
         if e_when = Void then
            e_when := ew
            ct := smart_eiffel.top_rf.current_type
            e := expression.to_runnable(ct)
            if e /= Void and then e.result_type.is_character then
               expression := e
               expression_value := expression.to_integer_or_error
               e_when.add_when_item_1(Current)
            else
               error(expression.start_position,fz_bcv)
            end
            Result := Current
         else
            !!Result.make(expression)
            Result := Result.to_runnable_character(ew)
         end
      end

   to_runnable_string(ew: like e_when): like Current is
      local
         ct: E_TYPE; e: like expression;
      do
         if e_when = Void then
            e_when := ew;
            ct := smart_eiffel.top_rf.current_type;
            e := expression.to_runnable(ct);
            if e /= Void and then e.is_manifest_string then
               expression := e;
               e_when.add_when_item_1(Current);
               -- `expression_value' was computed before by
               -- MANIFEST_STRING_INSPECTOR calling `set_expression_value'
            else
               error(expression.start_position,fz_biv);
            end;
            Result := Current;
         else
            !!Result.make(expression);
            Result := Result.to_runnable_string(ew);
         end;
      end;

   pretty_print is
      do
         expression.pretty_print
      end

feature {MANIFEST_STRING_INSPECTOR}

   set_expression_value(ev: INTEGER) is
      do
         expression_value := ev;
      end;

feature {WHEN_ITEM_1_VISITOR}

   accept(visitor: WHEN_ITEM_1_VISITOR) is
      do
         visitor.visit_when_item_1(Current)
      end

feature {NONE}

   make(v: like expression) is
      require
         v /= Void
      do
         expression := v
      ensure
         expression = v
      end

end -- WHEN_ITEM_1
