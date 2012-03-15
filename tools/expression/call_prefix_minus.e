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
class CALL_PREFIX_MINUS
   --
   --   Prefix operator : "-".
   --

inherit CALL_PREFIX redefine compile_to_c end

creation make, with

feature

   precedence: INTEGER is 11

   side_effect_free: BOOLEAN is False

   operator: STRING is
      do
         Result := as_minus
      end

   isa_dca_inline_argument: INTEGER is
      do
         if result_type.is_integer then
            Result := target.isa_dca_inline_argument
         end
      end

   dca_inline_argument(formal_arg_type: E_TYPE) is
      do
         cpp.put_character('-')
         cpp.put_character('(')
         target.dca_inline_argument(formal_arg_type)
         cpp.put_character(')')
      end

   simplify_1_: EXPRESSION is
      local
	 ic: INTEGER_CONSTANT; v, r: INTEGER_64
      do
	 ic ?= target
	 if ic = Void then
	    Result := Current
	 else
	    v := ic.value_memory
	    r := -v
	    if v < 0 and then r < 0 then
	       error_handler.append(integer_constant_overflow)
	       error_handler.add_position(feature_name.start_position)
	       error_handler.print_as_fatal_error
	    end
	    create {INTEGER_CONSTANT}
	       Result.make(r, feature_name.start_position)
	 end
      end

   compile_to_c is
      do
         if ace.boost and then
            run_feature.current_type.is_basic_eiffel_expanded then
            cpp.put_character('-')
            cpp.put_character('(')
            target.compile_to_c
            cpp.put_character(')')
         else
            call_proc_call_c2c
         end
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

feature {CALL_PREFIX_MINUS_VISITOR}

   accept(visitor: CALL_PREFIX_MINUS_VISITOR) is
      do
         visitor.visit_call_prefix_minus(Current)
      end

feature {NONE}

   make(operator_position: POSITION; rp: like target) is
      require
         not operator_position.is_unknown
         rp /= Void
      do
         create feature_name.prefix_name(operator,operator_position)
         target := rp
      ensure
         start_position = operator_position
         target = rp
      end

end -- CALL_PREFIX_MINUS
