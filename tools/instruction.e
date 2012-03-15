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
deferred class INSTRUCTION
   --
   -- For all differents kinds of Eiffel instruction.
   --

inherit
   GLOBALS
   VISITABLE

feature

   start_position: POSITION is
         -- Of the first character of the instruction.
      deferred
      ensure
         not Result.is_unknown
      end

   pretty_print is
      require
         pretty_printer.indent_level >= 3
      deferred
      ensure
         pretty_printer.indent_level = old pretty_printer.indent_level
      end

   side_effect_free: BOOLEAN is
         -- True when the execution of `Current' has no side effect at all.
      deferred
      end

   use_current: BOOLEAN is
         -- Does instruction use Current ?
      require
         smart_eiffel.is_ready
      deferred
      end

   stupid_switch(run_time_set: RUN_TIME_SET): BOOLEAN is
      require
         smart_eiffel.is_ready
         ace.boost
         run_time_set.count > 1
      deferred
      end

   to_runnable(ct: E_TYPE): INSTRUCTION is
         -- Gives a checked instruction runnable in `ct'.
      require
         ct.run_type = ct
         ct.run_class /= Void
      deferred
      ensure
         nb_errors = 0 implies Result /= Void
      end

   end_mark_comment: BOOLEAN is
         -- True for instructions with a possible end mark comment
         -- like instruction "loop" "debug" or "check" for example.
      deferred
      end

   afd_check is
         -- After Falling Down Check.
      deferred
      end

   safety_check is
      require
	 for_boost_mode_only_or_asked_for: ace.boost or else ace.safety_check
         smart_eiffel.status.in_range(3,6)
      deferred
      end

   simplify_2(container: COMPOUND; index: INTEGER) is
	 -- If it is possible, this `simplify_2' try to simplify `Current'.
	 -- The simplification performed by the `simplify_2' function occurs at 
	 -- the very last time of the compilation process. It is up to `Current' 
	 -- to notify its `container' if, for example, when the instruction 
	 -- itself must be suppressed. 
      require
	 container.item(index) = Current
	 not smart_eiffel.pretty_flag
	 not smart_eiffel.short_flag
	 smart_eiffel.status >= 4
      deferred
      end
   
   collect_c_tmp is
         -- Traverse the instruction to collect extra mandatory C tmp
	 -- variables (for user expanded) just before `compile_to_c'.
      require
         smart_eiffel.is_ready
      deferred
      end

   compile_to_c is
      require
         smart_eiffel.is_ready
         cpp.on_c
      deferred
      ensure
         cpp.on_c
      end

   compile_to_jvm is
      require
         smart_eiffel.is_ready
      deferred
      end

   once_pre_computable: BOOLEAN is
         -- Is it possible to use `Current' inside the body of a pre-computed 
         -- once function? 
         -- (Used to decide if some once function is really pre-computable.)
      require
         smart_eiffel.is_ready
      deferred
      end

feature {COMPOUND,INSTRUCTION_WITH_COMMENT}

   verify_scoop(allowed: FORMAL_ARG_LIST) is
      deferred
      end

feature {EIFFEL_PARSER}

   frozen add_comment(c: COMMENT): INSTRUCTION is
         -- Attach `c' to the instruction.
      require
         eiffel_parser.is_running
	 c.count > 0
      do
	 if end_mark_comment then
            if c.count = 1 then
               Result := Current
            else
               !INSTRUCTION_WITH_COMMENT!Result.make(Current,c)
            end
         else
            !INSTRUCTION_WITH_COMMENT!Result.make(Current,c)
         end
      end

feature {INSTRUCTION_VISITOR}

   accept(visitor: INSTRUCTION_VISITOR) is
      deferred
      end

feature {NONE}

   pretty_print_assignment(rhs: EXPRESSION; op: STRING; lhs: EXPRESSION) is
      local
         semi_colon_flag: BOOLEAN
      do
         rhs.pretty_print
         pretty_printer.put_character(' ')
         pretty_printer.put_string(op)
         pretty_printer.put_character(' ')
         semi_colon_flag := pretty_printer.semi_colon_flag
         pretty_printer.indent_level_increment
         pretty_printer.set_semi_colon_flag(False)
         lhs.pretty_print
         pretty_printer.set_semi_colon_flag(semi_colon_flag)
         if semi_colon_flag then
            pretty_printer.put_character(';')
         end
         pretty_printer.indent_level_decrement
      end

end -- INSTRUCTION
