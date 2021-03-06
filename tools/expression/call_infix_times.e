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
class CALL_INFIX_TIMES
   --
   --   Infix operator : "*".
   --

inherit CALL_INFIX1

creation make, with

feature

   precedence: INTEGER is 8

   left_brackets: BOOLEAN is False

   frozen operator: STRING is
      do
         Result := as_muls
      end

   isa_dca_inline_argument: INTEGER is
      do
      end

   dca_inline_argument(formal_arg_type: E_TYPE) is
      do
      end

   simplify_1_: EXPRESSION is
      local
	 ic1, ic2: INTEGER_CONSTANT; i1, i2, i3: INTEGER_64
	 rc: REAL_CONSTANT; r1, r2: DOUBLE
      do
	 if result_type.is_integer then
	    ic1 ?= target
	    if ic1 = Void then
	       Result := Current
	    else
	       i1 := ic1.value_memory
	       ic2 ?= arg1
	       if ic2 = Void then
		  Result := Current
	       else
		  i2 := ic2.value_memory
		  i3 := i1 #* i2
		  if i2 /= 0 then
		     if (i3 // i2) /= i1 then
			error_handler.append(integer_constant_overflow)
			error_handler.add_position(feature_name.start_position)
			error_handler.print_as_fatal_error
		     end
		  end
		  create {INTEGER_CONSTANT}
	             Result.make(i3, feature_name.start_position)
	       end
	    end
	 elseif result_type.is_real or else result_type.is_double then
	    rc ?= arg1
	    if rc = Void then
	       Result := Current
	    else
	       r2 := rc.value
	       rc ?= target.simplify_1_
	       if rc = Void then
		  Result := Current
	       else
		  r1 := rc.value
	       end
	    end
	    if Result = Void then
	       create {REAL_CONSTANT}
	          Result.from_double(feature_name.start_position,
				     r1 * r2,
				     result_type)
	    end
	 else
	    Result := Current
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

feature {CALL_INFIX_TIMES_VISITOR}

   accept(visitor: CALL_INFIX_TIMES_VISITOR) is
      do
         visitor.visit_call_infix_times(Current)
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

end -- CALL_INFIX_TIMES

