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
class ASSIGNMENT
   --
   -- For instruction like :
   --                          foo := bar
   --                          foo := bar + 1
   --
   --

inherit INSTRUCTION

creation make

feature

   left_side: EXPRESSION

   right_side: EXPRESSION

   end_mark_comment: BOOLEAN is False

   side_effect_free: BOOLEAN is False
      
   once_pre_computable: BOOLEAN is
      do
	 if left_side.once_pre_computable then
	    Result := right_side.once_pre_computable
	 end
      end

   afd_check is
      do
         right_side.afd_check
      end

   safety_check is
      do
         right_side.safety_check
      end

   simplify_2(container: COMPOUND; index: INTEGER) is
      do
	 right_side := right_side.simplify_2
      end
   
   collect_c_tmp is
      do
         right_side.collect_c_tmp
      end

   compile_to_c is
      local
         cast_t0: BOOLEAN
      do
	 if ace.no_check then
	    cpp.put_trace_or_sedb_instruction(start_position)
	 end
	 if right_side.is_current then
            if left_type.is_reference then
               cast_t0 := right_type.is_reference
            end
         end
         left_side.compile_to_c
         cpp.put_character('=')
         if cast_t0 then
            cpp.put_string(once "((T0*)(")
	 elseif right_side.result_type.is_boolean then
	    cpp.put_string(once "((T6)(")
         end
         right_side.compile_to_c
         if cast_t0 or else right_side.result_type.is_boolean then
            cpp.put_string(once "))")
         end
         cpp.put_string(fz_00)
      end

   compile_to_jvm is
      do
         right_side.compile_to_jvm
         left_side.jvm_assign
      end

   use_current: BOOLEAN is
      do
         Result := left_side.use_current
         Result := Result or else right_side.use_current
      end

   stupid_switch(run_time_set: RUN_TIME_SET): BOOLEAN is
      do
         if left_side.stupid_switch(run_time_set) then
            if right_side.stupid_switch(run_time_set) then
               Result := True
            end
         end
      end

   right_type: E_TYPE is
      do
         Result := right_side.result_type
      ensure
         Result /= Void
      end

   left_type: E_TYPE is
      do
         Result := left_side.result_type
      ensure
         Result /= Void
      end

   start_position: POSITION is
      do
         Result := left_side.start_position
      end

   to_runnable(ct: E_TYPE): like Current is
      local
         l, r: EXPRESSION; view_r, view_l: E_TYPE
      do
	 l := left_side.to_runnable(ct)
	 if l = Void then
	    error_handler.add_position(left_side.start_position)
	    error_handler.append(fz_blhsoa)
	    error_handler.print_as_fatal_error
	 end
	 r := right_side.to_runnable(ct)
	 if r = Void then
	    error_handler.add_position(right_side.start_position)
	    error_handler.append(fz_brhsoa)
	    error_handler.print_as_fatal_error
	 end
	 view_r := r.result_type
	 view_l := l.result_type
	 if not r.result_type.is_a(l.result_type) then
	    error_handler.add_position(l.start_position)
	    error_handler.append(" Bad assignment (VJAR).")
	    error_handler.print_as_fatal_error
         elseif r.result_type.is_reference then
	    separateness_consistency_rule_3_check(l, r)
	 end
	 if l = left_side and then r = right_side then
	    Result := implicit_conversion
	 else
	    create Result.make(l, r)
	    Result := Result.implicit_conversion
	 end
      end

   pretty_print is
      do
         pretty_print_assignment(left_side, once ":=", right_side)
      end

feature {COMPOUND,INSTRUCTION_WITH_COMMENT}

   verify_scoop(allowed: FORMAL_ARG_LIST) is
      local
         dummy: BOOLEAN
      do
         dummy := left_side.verify_scoop(allowed)
         dummy := right_side.verify_scoop(allowed)
      end

feature {ASSIGNMENT}

   implicit_conversion: like Current is
      local
         left_run_type, right_run_type: E_TYPE; rhs: EXPRESSION
      do
         left_run_type := left_type.run_type
         right_run_type := right_type.run_type
         if right_side.is_void and then left_run_type.is_expanded then
            error_handler.add_position(right_side.start_position)
            error_handler.append("Void may not be assigned to an %
				 %expanded entity. Left hand side is ")
            error_handler.add_type(left_type,".")
            error_handler.print_as_error
         end
         rhs := assignment_handler.implicit_cast(right_side,left_run_type)
         assignment_handler.assignment(rhs.start_position,
				       rhs.result_type,
				       left_run_type)
         if rhs = right_side then
            Result := Current
         else
            create Result.make(left_side, rhs)
         end
      end

feature {ASSIGNMENT_VISITOR}

   accept(visitor: ASSIGNMENT_VISITOR) is
      do
         visitor.visit_assignment(Current)
      end

feature {NONE}

   separateness_consistency_rule_3_check(l, r: EXPRESSION) is
      local
	 c: CALL
      do
	 c ?= r
	 if c /= Void then
	    if c.target.result_type.is_separate
	       and then not c.target.is_current
	       and then not l.result_type.is_separate
	     then
	       error_handler.add_position(l.start_position)
	       error_handler.append(
	          "Separateness Consistency Rule violated%N(OOSC2 p. %
		  %1025): invalid assignment. (See the 2 following %
		  %messages for more details.)")
	       error_handler.print_as_error

	       error_handler.add_position(c.start_position)
	       error_handler.append("This call is separate (%
				    %because the target is separate).")
	       error_handler.print_as_error

	       error_handler.add_position(l.start_position)
	       error_handler.append("In this situation, the type %
				    %of the left-hand-side must be %
				    %separate too.")
	       error_handler.print_as_fatal_error
	    end
	 end
      end

   debug_info: STRING
   
   make(ls: like left_side; rs: like right_side) is
      require
         ls.is_writable
         not ls.start_position.is_unknown
         rs /= Void
      do
         left_side := ls
         right_side := rs
	 debug
	    create debug_info.make(64)
	    left_side.start_position.append_in(debug_info)
	 end
      ensure
         left_side = ls
         right_side = rs
      end

invariant

   left_side.is_writable

   right_side /= Void

end -- ASSIGNMENT

