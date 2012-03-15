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
class COMPOUND
   --
   -- An ordered sequence of Eiffel instructions (natural indexing from 1 to 
   -- `count').
   --

inherit GLOBALS; VISITABLE

creation {EIFFEL_PARSER,E_PROCEDURE} make_0, make_1

creation {COMPOUND,RUN_CLASS} make

feature

   header_comment: COMMENT
	 -- The one which may be placed at the beginning of the
	 -- compound.

   count: INTEGER is
      do
         if first_one = Void then
         elseif remainder /= Void then
            Result := remainder.count + 1
         else
            Result := 1
         end
      end

   first: INSTRUCTION is
      require
         count >= 1
      do
         Result := first_one
      ensure
         Result /= Void
      end

   item(i: INTEGER): INSTRUCTION is
      require
         i.in_range(1, count)
      do
         if i = 1 then
            Result := first_one
         else
            Result := remainder.item(i - 2)
         end
      end

   start_position: POSITION is
      do
         if first_one /= Void then
            Result := first_one.start_position
         end
      end

   run_class: RUN_CLASS is
      do
         Result := current_type.run_class
      end

   afd_check is
      local
         i: INTEGER
      do
         from
            i := count
         until
            i = 0
         loop
            item(i).afd_check
            i := i - 1
         end
      end

   safety_check is
      local
         i: INTEGER
      do
         from
            i := count
         until
            i = 0
         loop
            item(i).safety_check
            i := i - 1
         end
      end

   simplify_2: like Current is
      local
         i, old_count: INTEGER; instruction: INSTRUCTION; again: BOOLEAN
      do
	 old_count := count
         from
            i := 1
         until
            i > count
         loop
	    instruction := item(i)
	    instruction.simplify_2(Current, i)
	    if not again then
	       if i <= count then
		  if item(i) /= instruction then
		     again := True
		  end
	       end
	    end
	    i := i + 1
         end
	 if first_one /= Void then
	    if old_count = count then
	       if again then
		  smart_eiffel.magic_count_increment
		  Result := Current.simplify_2
	       else
		  Result := Current
	       end
	    else
	       Result := Current.simplify_2
	    end
	 end
      end
   
   compile_to_c is
      local
         i, c: INTEGER; instruction: INSTRUCTION; need_se_tmp: BOOLEAN
      do
	 from
	    i := 1
	    c := count
	 until
	    i > c
	 loop
	    instruction := item(i)
	    -- The following next instruction is only useful to debug:
	    if ace.boost then
	       cpp.put_position_comment(instruction.start_position)
	       cpp.put_character('%N')
	    end
	    --
	    instruction.collect_c_tmp
	    need_se_tmp := cpp.se_tmp_open_declaration
	    instruction.compile_to_c
	    if need_se_tmp then
	       cpp.se_tmp_close_declaration
	    end
	    i := i + 1
	 end
      end

   compile_to_jvm is
      local
         i, c: INTEGER; instruction: INSTRUCTION; trace: BOOLEAN
         ca: like code_attribute
      do
         from
            c := count
            ca := code_attribute
            trace := start_position.sedb_trace
            i := 1
         until
            i > c
         loop
            instruction := item(i)
            line_number_table.add(ca.program_counter,
				  instruction.start_position)
            if trace then
               ca.se_trace(current_type,instruction.start_position)
            end
            instruction.compile_to_jvm
            i := i + 1
         end
      end

   use_current: BOOLEAN is
      local
         i: INTEGER
      do
         from
            i := count
         until
            Result or else i = 0
         loop
            Result := item(i).use_current
            i := i - 1
         end
      end

   stupid_switch(run_time_set: RUN_TIME_SET): BOOLEAN is
      local
         i: INTEGER
      do
         from
            Result := True
            i := count
         until
            not Result or else i = 0
         loop
            Result := item(i).stupid_switch(run_time_set)
            i := i - 1
         end
      end

   verify_scoop(allowed: FORMAL_ARG_LIST) is
      local
         i: INTEGER
      do
         from
            i := count
         until
            i = 0
         loop
            item(i).verify_scoop(allowed)
            i := i - 1
         end
      end

   once_pre_computable: BOOLEAN is
      require
	 smart_eiffel.is_ready
      local
         i: INTEGER
      do
         from
            i := count
            Result := True
         until
            not Result or else i = 0
         loop
            Result := item(i).once_pre_computable
            i := i - 1
         end
      end

   to_runnable(ct: E_TYPE): like Current is
      require
         ct.run_type = ct
         nb_errors = 0
      local
         i: INTEGER; i1, i2: INSTRUCTION; r: like remainder
      do
         if first_one = Void then
            Result := Current
         elseif current_type = Void then
            current_type := ct
            from
               i := count
            until
               i = 0
            loop
               i1 := item(i)
               i2 := i1.to_runnable(ct)
               if nb_errors > 0 then
                  error_handler.append(
				   "Bad instruction (when interpreted in ")
                  error_handler.append(current_type.written_mark)
                  error_handler.add_position(i1.start_position)
                  error_handler.append(").")
		  error_handler.print_as_fatal_error
               else
                  put(i2, i)
               end
               i := i - 1
            end
            Result := Current
         else
	    r := remainder
	    if r /= Void then
	       r := r.twin
	    end
            create Result.make(header_comment, first_one, r)
            Result := Result.to_runnable(ct)
         end
      ensure
         Result /= Void
      end

   pretty_print is
      require
         pretty_printer.indent_level >= 2
      local
         i, c: INTEGER; instruction, previous_instruction: INSTRUCTION
	 extra_semicolon_flag: BOOLEAN
	 
	 proc_call: PROC_CALL; call: CALL; expression: EXPRESSION
      do
         c := count
         pretty_printer.indent_level_increment
         pretty_printer.indent
         if header_comment /= Void then
            header_comment.pretty_print
         end
         from
            i := 1
         until
            i > c
         loop
            pretty_printer.set_semi_colon_flag(True)
            if pretty_printer.zen_mode and then i = c then
               pretty_printer.set_semi_colon_flag(False)
            end
            pretty_printer.indent
	    previous_instruction := instruction
	    instruction := item(i)
	    -- Computing `extra_semicolon_flag' first:
	    extra_semicolon_flag := False
	    if not pretty_printer.last_non_blank_character_is(';') then
	       proc_call ?= instruction
	       if proc_call /= Void then
		  from
		     expression := proc_call.target
		  until
		     extra_semicolon_flag or else expression = Void
		  loop
		     extra_semicolon_flag := expression.extra_bracket_flag
		     call ?= expression
		     if call = Void then
			expression := Void
		     else
			expression := call.target
		     end
		  end
	       end
	    end
	    if extra_semicolon_flag then
	       if previous_instruction = Void then
	       elseif previous_instruction.end_mark_comment then
		  if pretty_printer.parano_mode then
		     extra_semicolon_flag := False
		  end
	       end
	    end
	    -- Now using the `extra_semicolon_flag':
	    if extra_semicolon_flag then
	       pretty_printer.put_character(';')
	    end
            instruction.pretty_print
            i := i + 1
         end
         pretty_printer.indent_level_decrement
      ensure
         pretty_printer.indent_level = old pretty_printer.indent_level
      end

   side_effect_free: BOOLEAN is
      local
         i: INTEGER
      do
	 from
	    i := count
	    Result := True
	 until
	    not Result or else i <= 0
	 loop
	    Result := item(i).side_effect_free
	    i := i - 1
         end
      end

feature {EIFFEL_PARSER}

   add_last(instruction: INSTRUCTION) is
      require
	 instruction /= Void
      local
	 e_debug: E_DEBUG; e_check: E_CHECK; base_class: BASE_CLASS
      do
	 if smart_eiffel.pretty_flag then
	    perform_add_last(instruction)
	 else
	    e_debug ?= instruction
	    if e_debug /= Void then
	       if ace.debug_check(e_debug) then
		  perform_add_last(e_debug)
	       end
	    else
	       e_check ?= instruction
	       if e_check /= Void then
		  base_class := e_check.start_position.base_class
		  if base_class.all_check then
		     perform_add_last(e_check)
		  end
	       else
		  perform_add_last(instruction)
	       end
	    end
	 end
      ensure
	 count.in_range(old count,1 + old count)
      end

feature {INSTRUCTION}

   remove(i: INTEGER) is
      require
         i.in_range(1, count)
      do
	 smart_eiffel.magic_count_increment
         if i = 1 then
	    if remainder /= Void and then not remainder.is_empty then
	       first_one := remainder.first
	       remainder.remove_first
	    else
	       first_one := Void
	    end
         else
            remainder.remove(i - 2)
         end
      ensure
	 count = (old count) - 1
      end

   insert_compound(compound: like Current; index: INTEGER) is
      require
	 compound /= Void
	 index.in_range(1, count + 1)
      local
	 i: INTEGER
      do
	 from
	    i := compound.count
	 until
	    i < 1
	 loop
	    Current.insert_instruction(compound.item(i), index)
	    i := i - 1
	 end
      ensure
	 count = compound.count + old count
      end

   replace_instruction(instruction: INSTRUCTION; index: INTEGER) is
	 -- Replace the existing one at `index' with the new `instruction'.
      require
	 instruction /= Void
	 index.in_range(1, count)
      do
	 put(instruction, index)
      ensure
	 count = old count
	 item(index) = instruction
      end
   
   insert_instruction(instruction: INSTRUCTION; index: INTEGER) is
	 -- Insert `instruction' at `index' (instruction in range 
	 -- [`index' .. `count'] before this call are shifted right).
      require
	 instruction /= Void
	 index.in_range(1, count + 1)
      do
	 smart_eiffel.magic_count_increment
	 if index = 1 then
	    if first_one = Void then
	       first_one := instruction
	    else
	       if remainder = Void then
		  create remainder.with_capacity(8)
	       end
	       remainder.add_first(first_one)
	       first_one := instruction
	    end
	 elseif remainder = Void then
	    create remainder.with_capacity(8)
	    remainder.add_last(instruction)
	 else
	    remainder.add(instruction, index - 2)
	 end
      ensure
	 item(index) = instruction
	 count = 1 + old count
      end
      
feature {COMPOUND}

   first_one: INSTRUCTION
         -- The `first_one' if any.

   remainder: FIXED_ARRAY[INSTRUCTION]
         -- Non Void when the list has more than one element.

feature {COMPOUND_VISITOR}

   accept(visitor: COMPOUND_VISITOR) is
      do
         visitor.visit_compound(Current)
      end

feature {NONE}

   current_type: E_TYPE
         -- Not Void when checked in.

   make_0(hc: like header_comment) is
      require
         hc /= Void
      do
         header_comment := hc
      ensure
         header_comment = hc
      end

   make_1(hc: like header_comment; fo: like first_one) is
      require
         fo /= Void
      do
         header_comment := hc
	 add_last(fo)
      ensure
         header_comment = hc
      end

   make(hc: like header_comment; fo: like first_one; r: like remainder) is
      require
         hc /= Void or else fo /= Void
         r /= Void implies fo /= Void
      do
         header_comment := hc
         first_one := fo
         remainder := r
      ensure
         header_comment = hc
         first_one = fo
         remainder = r
      end

   put(i: INSTRUCTION; idx: INTEGER) is
      require
         i /= Void
         idx.in_range(1, count)
      do
         if idx = 1 then
            first_one := i
         else
            remainder.put(i, idx - 2)
         end
      end

   perform_add_last(instruction: INSTRUCTION) is
	 -- Really perform the `add_last'.
      require
	 instruction /= Void
      do
	 if first_one = Void then
	    first_one := instruction
	 else
	    if remainder = Void then
	       create remainder.with_capacity(8)
	    end
	    remainder.add_last(instruction)
	 end
      ensure
	 count = 1 + old count
      end

end -- COMPOUND
