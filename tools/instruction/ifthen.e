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
class IFTHEN
   --
   -- Note : it is not really a complete Eiffel INSTRUCTION.
   -- It is just a small part of an IFTHENELSE.
   --

inherit IF_GLOBALS

creation make
   
feature
   
   expression: EXPRESSION
   
   then_compound: COMPOUND
     -- Not Void if any.

feature {IFTHENLIST}

   verify_scoop(allowed: FORMAL_ARG_LIST) is
      local
         dummy: BOOLEAN
      do
         dummy := expression.verify_scoop(allowed)
         if then_compound /= Void then
            then_compound.verify_scoop(allowed)
         end
      end

   afd_check is
      do
         expression.afd_check
         if then_compound /= Void then
            then_compound.afd_check
         end
      end

   safety_check is
      do
         expression.safety_check
         if then_compound /= Void then
            then_compound.safety_check
         end
      end

   collect_c_tmp is
      do
         expression.collect_c_tmp
      end

feature

   compile_to_c(need_else: BOOLEAN): INTEGER is
      local
         trace: BOOLEAN; bc: BOOLEAN_CONSTANT
      do
	 bc ?= expression
         if bc /= Void then
            if bc.value then
               print_else(need_else)
               cpp.put_string(once "{/*AT*/")
               if then_compound /= Void then
                  then_compound.compile_to_c
               end
               cpp.put_string(fz_12)
               Result := Always_true
            else
               cpp.put_string(once "/*AF*/")
	       Result := Always_false
            end
         else
            Result := Always_here
            trace := not expression.side_effect_free and then ace.no_check
            print_else(need_else)
            cpp.put_string(fz_if)
            cpp.put_character('(')
            if trace then
               cpp.trace_boolean_expression(expression)
            else
               expression.compile_to_c
            end
            cpp.put_character(')')
            cpp.put_string(fz_11)
            if then_compound /= Void then
               then_compound.compile_to_c
            end
            cpp.put_string(fz_12)
         end
      end

   compile_to_jvm: INTEGER is
      local
         point1: INTEGER; bc: BOOLEAN_CONSTANT
      do
	 bc ?= expression
         if bc /= Void then
            if bc.value then
               if then_compound /= Void then
                  then_compound.compile_to_jvm
               end
               Result := Always_true
            else
               Result := Always_false
            end
         else
            Result := Always_here
            point1 := expression.jvm_branch_if_false
            if then_compound /= Void then
               then_compound.compile_to_jvm
            end
            point2 := code_attribute.opcode_goto
            code_attribute.resolve_u2_branch(point1)
         end
      ensure
         (<<Always_true,Always_false,Always_here>>).fast_has(Result)
      end

   compile_to_jvm_resolve_branch: INTEGER is
      local
	 bc: BOOLEAN_CONSTANT
      do
	 bc ?= expression
         if bc /= Void then
            if bc.value then
               Result := Always_true
            else
               Result := Always_false
            end
         else
            Result := Always_here
            if point2 > 0 then
               code_attribute.resolve_u2_branch(point2)
            end
         end
      ensure
         (<<Always_true,Always_false,Always_here>>).fast_has(Result)
      end

   use_current: BOOLEAN is
      do
         Result := expression.use_current
         if not Result and then then_compound /= Void then
            Result := then_compound.use_current
         end
      end

   stupid_switch(run_time_set: RUN_TIME_SET): BOOLEAN is
      do
         Result := expression.stupid_switch(run_time_set) 
	    and then
	    (then_compound = Void 
	     or else 
	     then_compound.stupid_switch(run_time_set))
      end

   start_position: POSITION is
      do
         Result := expression.start_position
      end

   pretty_print is
      do
         pretty_printer.indent_level_increment
         pretty_printer.set_semi_colon_flag(False)
         expression.pretty_print
         pretty_printer.indent_level_decrement
         pretty_printer.keyword(fz_then)
         pretty_printer.indent
         if then_compound /= Void then
            then_compound.pretty_print
         end
      end

   to_runnable(ct: E_TYPE): like Current is
      local
         e: like expression; tc: like then_compound; t: E_TYPE
      do
         if current_type = Void then
            current_type := ct
            e := expression.to_runnable(ct)
            if e = Void then
               error(expression.start_position,
                     "Bad BOOLEAN expression.")
            else
               expression := e
               t := expression.result_type
               if not t.is_boolean then
                  error_handler.append("Expression of if/elseif must be BOOLEAN. ")
                  error_handler.add_type(expression.result_type,fz_is_not_boolean)
                  error_handler.add_position(expression.start_position)
                  error_handler.print_as_error
               end
            end
            if then_compound /= Void then
               tc := then_compound.to_runnable(ct)
               if tc /= Void then
                  then_compound := tc
               end
            end
            if nb_errors = 0 then
               Result := Current
            end
         else
            create Result.make(expression,then_compound)
            Result := Result.to_runnable(ct)
         end
      end

   simplify_2: INTEGER is
      local
	 bc: BOOLEAN_CONSTANT
      do
	 expression := expression.simplify_2
	 bc ?= expression
	 if bc /= Void then
	    if bc.value then
	       if then_compound /= Void then
		  then_compound := then_compound.simplify_2
	       end
	       Result := Always_true
	    else
	       then_compound := Void
	       Result := Always_false
	    end
	 else
	    if then_compound /= Void then
	       then_compound := then_compound.simplify_2
	    end
	    Result := Always_here
	 end
      ensure
	 (Result = Always_false) or (Result = Always_true) or (Result = Always_here)
      end
   
feature {IFTHEN_VISITOR}

   accept(visitor: IFTHEN_VISITOR) is
      do
         visitor.visit_ifthen(Current)
      end

feature {NONE}

   current_type: E_TYPE
         -- Not Void when instruction is checked for.

   point2: INTEGER
         -- To reach the end of IFTHENELSE.

   make(exp: like expression; tc: like then_compound) is
      require
         exp /= void
      do
         expression := exp
         then_compound := tc
      ensure
         expression = exp
         then_compound = tc
      end

   print_else(need_else: BOOLEAN) is
      do
         if need_else then
            cpp.put_string(once " else ")
         end
      end

invariant

   expression /= Void

end -- IFTHEN
