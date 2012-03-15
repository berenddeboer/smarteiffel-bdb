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
class CALL_INFIX_PLUS
   --
   --   Infix operator : "+".
   --

inherit CALL_INFIX1

creation make, with

feature

   precedence: INTEGER is 7

   left_brackets: BOOLEAN is False

   operator: STRING is
      do
         Result := as_plus
      end

   isa_dca_inline_argument: INTEGER is
      do
         if result_type.is_integer then
            Result := target.isa_dca_inline_argument
            if Result = -1 then
               Result := arg1.isa_dca_inline_argument
            elseif Result > 0 then
               if arg1.isa_dca_inline_argument >= 0 then
                  Result := 0
               end
            end
         end
      end

   dca_inline_argument(formal_arg_type: E_TYPE) is
      do
         cpp.put_character('(')
         target.dca_inline_argument(formal_arg_type)
         cpp.put_character(')')
         cpp.put_character('+')
         cpp.put_character('(')
         arg1.dca_inline_argument(formal_arg_type)
         cpp.put_character(')')
      end

   simplify_1_: EXPRESSION is
      local
	 ic1, ic2: INTEGER_CONSTANT; v1, v2, r: INTEGER_64; overflow: BOOLEAN
      do
	 ic1 ?= target
	 if ic1 = Void then
	    Result := Current
	 else
	    ic2 ?= arg1
	    if ic2 = Void then
	       Result := Current
	    else
	       v1 := ic1.value_memory
	       v2 := ic2.value_memory
	       r := v1 #+ v2
	       if v1 >= 0 then
		  if v2 >= 0 then
		     overflow := r < 0
		  end
	       elseif v2 < 0 then
		  overflow := r > 0
	       end
	       if overflow then
		  error_handler.append(integer_constant_overflow)
		  error_handler.add_position(feature_name.start_position)
		  error_handler.print_as_fatal_error
	       end
	       create {INTEGER_CONSTANT}
	          Result.make(r, feature_name.start_position)
	    end
	 end
      end

   compile_to_c is
      do
         call_proc_call_c2c
      end

   compile_to_jvm is
      do
         call_proc_call_c2jvm
      end

   jvm_branch_if_false: INTEGER is
      do
         Result := jvm_standard_branch_if_false
      end

   jvm_branch_if_true: INTEGER is
      do
         Result := jvm_standard_branch_if_true
      end

feature {CALL_INFIX_PLUS_VISITOR}

   accept(visitor: CALL_INFIX_PLUS_VISITOR) is
      do
         visitor.visit_call_infix_plus(Current)
      end

feature {NONE}

   make(lp: like target; operator_position: POSITION; rp: like arg1) is
      require
         lp /= Void
         not operator_position.is_unknown
         rp /= Void
      do
         target := lp
         create feature_name.infix_name(operator, operator_position)
         create arguments.make_1(rp)
      ensure
         target = lp
         start_position = operator_position
         arguments.first = rp
      end

end -- CALL_INFIX_PLUS

