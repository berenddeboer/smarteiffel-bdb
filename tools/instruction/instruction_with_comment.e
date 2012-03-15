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
class INSTRUCTION_WITH_COMMENT
   --
   -- To wrap an instruction with a following comment.
   --

inherit INSTRUCTION

creation make

feature

   instruction : INSTRUCTION

   comment : COMMENT

   end_mark_comment: BOOLEAN is false

   side_effect_free: BOOLEAN is
      do
	 Result := instruction.side_effect_free
      end
      
   use_current: BOOLEAN is
      do
         Result := instruction.use_current
      end

   stupid_switch(run_time_set: RUN_TIME_SET): BOOLEAN is
      do
         Result := instruction.stupid_switch(run_time_set)
      end

   afd_check is
      do
         instruction.afd_check
      end

   simplify_2(container: COMPOUND; index: INTEGER) is
      do
	 container.remove(index)
	 container.insert_instruction(instruction, index)
	 instruction.simplify_2(container, index)
      end

   safety_check is
      do
         instruction.safety_check
      end

   collect_c_tmp is
      do
         instruction.collect_c_tmp
      end

   compile_to_c is
      do
         instruction.compile_to_c
      end

   compile_to_jvm is
      do
         instruction.compile_to_jvm
      end

   once_pre_computable: BOOLEAN is
      do
         Result := instruction.once_pre_computable
      end

   start_position: POSITION is
      do
         Result := instruction.start_position
      end

   to_runnable(ct: E_TYPE): like Current is
      local
         ri: like instruction
      do
         ri := instruction.to_runnable(ct)
         if ri = Void then
            error(instruction.start_position,"Bad instruction.")
            Result := Current
         elseif ri = instruction then
            Result := Current
         else
            create Result.make(ri,comment)
         end
      end

   pretty_print is
      do
         if comment.is_dummy_end_of_statement then
            instruction.pretty_print
         else
            instruction.pretty_print
            pretty_printer.indent
            comment.pretty_print
         end
      end

feature {INSTRUCTION_WITH_COMMENT_VISITOR}

   accept(visitor: INSTRUCTION_WITH_COMMENT_VISITOR) is
      do
         visitor.visit_instruction_with_comment(Current)
      end

feature {COMPOUND,INSTRUCTION_WITH_COMMENT}

   verify_scoop(allowed: FORMAL_ARG_LIST) is
      do
         instruction.verify_scoop(allowed)
      end

feature {NONE}

   make(i: like instruction; c: like comment) is
      require
         i /= void
         really_a_comment: c.count > 0
      do
         instruction := i
         comment := c
      end

invariant

   instruction /= Void

   comment /= Void

end -- INSTRUCTION_WITH_COMMENT

