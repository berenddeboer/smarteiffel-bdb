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
class ASSERTION
   --
   -- To store one assertion.
   --
   
inherit
   GLOBALS
   VISITABLE
   
creation make

feature

   tag: TAG_NAME

   expression: EXPRESSION

   comment: COMMENT

   current_type: E_TYPE

   is_guard: BOOLEAN

feature

   verify_scoop(allowed: FORMAL_ARG_LIST) is
      require
         smart_eiffel.scoop
      do
         is_guard := expression.verify_scoop(allowed)
      end

feature {NONE}

   make(t: like tag; exp: like expression; c: like comment) is
      require
         t /= void or exp /= Void or c /= Void
      do
         tag := t
         expression := exp
         comment := c
      ensure
         tag = t
         expression = exp
         comment = c
      end

feature

   start_position: POSITION is
      do
         if tag /= Void then
            Result := tag.start_position
         elseif expression /= Void then
            Result := expression.start_position
         else
            Result := comment.start_position
         end
      end

   pretty_print is
      require
         pretty_printer.indent_level >= 1
      do
         if tag /= Void then
            pretty_printer.put_string(tag.to_string)
            pretty_printer.put_string(once ": ")
         end
         if expression /= Void then
            expression.pretty_print
            if pretty_printer.semi_colon_flag then
               pretty_printer.put_string(once "; ")
            end
         end
         if comment /= Void then
            comment.pretty_print
         end
      end

   short(h01,r01,h02,r02,h03,r03,h04,r04,h05,r05,h06,r06,h07,r07,
         h08,r08,h09,r09,h10,r10,h11,r11,h12,r12,h13,r13: STRING) is
      do
         short_print.hook_or(h01,r01)
         if tag = Void then
            short_print.hook_or(h02,r02)
         else
            short_print.hook_or(h03,r03)
            tag.short
            short_print.hook_or(h04,r04)
         end
         if expression = Void then
            short_print.hook_or(h05,r05)
         else
            short_print.hook_or(h06,r06)
            expression.short
            short_print.hook_or(h07,r07)
         end
         if comment = Void then
            short_print.hook_or(h08,r08)
         else
            short_print.hook_or(h09,r09)
            comment.short(h10,r10,h11,r11)
            short_print.hook_or(h12,r12)
         end
         short_print.hook_or(h13,r13)
      end

   to_runnable(ct: E_TYPE; assertion_check_tag: CHARACTER): like Current is
      require
         ct.is_run_type
      local
         e: like expression
      do
         if current_type = Void then
            current_type := ct
            Result := Current
            if expression /= Void then
               e := expression.to_runnable(ct)
               if e = Void then
                  error(start_position,fz_bad_assertion)
               else
                  expression := e
                  if not expression.result_type.is_boolean then
                     error_handler.add_type(expression.result_type,fz_is_not_boolean)
                     error(start_position,fz_bad_assertion)
                  end
               end
            end
            if expression /= Void and then nb_errors = 0 then
               if ace.require_check then
                  expression.assertion_check(assertion_check_tag)
               end
            end
         else
            !!Result.make(tag,expression,comment)
            Result := Result.to_runnable(ct,assertion_check_tag)
         end
      ensure
         nb_errors = 0 implies Result.is_checked
      end

   is_checked: BOOLEAN is
      do
         Result := current_type /= Void
      end

   use_current: BOOLEAN is
      do
         if expression /= Void then
            Result := expression.use_current
         end
      end

   afd_check is
      require
         is_checked
      do
         if expression /= Void then
            expression.afd_check
         end
      end

   compile_to_c is
      require
         is_checked
      do
         if expression /= Void then
            if is_guard then
               cpp.put_string(once "se_guard &= (")
               expression.compile_to_c
               cpp.put_string(fz_14)
            else
               cpp.check_assertion(expression,tag)
            end
         end
      end

   is_always_true: BOOLEAN is
      local
	 bc: BOOLEAN_CONSTANT
      do
         if expression = Void then
            Result := True
         else
	    bc ?= expression
	    if bc /= Void then
	       Result := bc.value
	    end
         end
      end

   c_frame_descriptor(format, locals: STRING) is
      require
	 ace.no_check
      do
         if expression /= Void then
            expression.c_frame_descriptor(format, locals)
         end
      end

feature {ASSERTION_LIST}

   compile_to_jvm(last_chance: BOOLEAN) is
         -- The boolean result of the expression is pushed.
         -- When `last_chance' is True, the generated code includes an
         -- error message to be printed when assertion is False.
         --
      require
         is_checked
      local
         point1: INTEGER; ca: like code_attribute
      do
         ca := code_attribute
         if expression = Void then
            ca.opcode_iconst_1
         else
            expression.compile_to_jvm
            if last_chance then
               point1 := code_attribute.opcode_ifne
               ca.runtime_error(expression.start_position,Void,fz_50)
               ca.resolve_u2_branch(point1)
               ca.opcode_iconst_1
            end
         end
      end

feature {ASSERTION_VISITOR}

   accept(visitor: ASSERTION_VISITOR) is
      do
         visitor.visit_assertion(Current)
      end

feature {ASSERTION_LIST}

   collect_c_tmp is
      do
         if expression /= Void then
            expression.collect_c_tmp
         end
      end

feature {NONE}

   tmp_string: STRING is
      once
         !!Result.make(128)
      end

invariant

   tag /= Void or expression /= Void or comment /= Void

end -- ASSERTION

