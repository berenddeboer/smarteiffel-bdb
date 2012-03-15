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
class CALL_INFIX_LE
   --
   --   Infix operator : "<=".
   --

inherit CALL_INFIX1

creation make, with

feature

   precedence: INTEGER is 6

   left_brackets: BOOLEAN is False

   operator: STRING is
      do
         Result := as_le
      end

   isa_dca_inline_argument: INTEGER is
      do
      end

   dca_inline_argument(formal_arg_type: E_TYPE) is
      do
      end

   simplify_1_: EXPRESSION is
      local
	 ic1, ic2: INTEGER_CONSTANT
      do
	 ic1 ?= target
	 if ic1 = Void then
	    Result := Current
	 else
	    ic2 ?= arg1
	    if ic2 = Void then
	       Result := Current
	    else
	       if ic1.value_memory <= ic2.value_memory then
		  create {E_TRUE} Result.make(feature_name.start_position)
	       else
		  create {E_FALSE} Result.make(feature_name.start_position)
	       end
	    end
	 end
      end

   compile_to_c is
      do
         if ace.boost and then
            target.result_type.run_type.is_character
          then
            c2c_cast_op(fz_unsigned,as_le)
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
         if result_type.is_integer then
            target.compile_to_jvm
            arg1.compile_to_jvm
            Result := code_attribute.opcode_if_icmpgt
         else
            Result := jvm_standard_branch_if_false
         end
      end

   jvm_branch_if_true: INTEGER is
      do
         if result_type.is_integer then
            target.compile_to_jvm
            arg1.compile_to_jvm
            Result := code_attribute.opcode_if_icmple
         else
            Result := jvm_standard_branch_if_true
         end
      end

feature {CALL_INFIX_LE_VISITOR}

   accept(visitor: CALL_INFIX_LE_VISITOR) is
      do
         visitor.visit_call_infix_le(Current)
      end

feature {NONE}

   make(lp: like target; operator_position: POSITION; rp: like arg1) is
      require
         lp /= Void
         not operator_position.is_unknown
         rp /= Void
      do
         target := lp
         create feature_name.infix_name(operator,operator_position)
         create arguments.make_1(rp)
      ensure
         target = lp
         start_position = operator_position
         arguments.first = rp
      end

end -- CALL_INFIX_LE
