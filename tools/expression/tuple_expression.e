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
class TUPLE_EXPRESSION
   --
   -- Like:  [ foo , bar ]
   --

inherit EXPRESSION

creation make

feature

   start_position: POSITION
         -- Of opening bracket.

   result_type: TYPE_TUPLE
         -- Computed according to the actual `list'.

   is_void: BOOLEAN is False

   is_current: BOOLEAN is False

   side_effect_free: BOOLEAN is False

   isa_dca_inline_argument: INTEGER is 0

   extra_bracket_flag: BOOLEAN is True
   
   precedence: INTEGER is 2

   is_static: BOOLEAN is False

   is_manifest_string: BOOLEAN is False

   is_result: BOOLEAN is False

   is_writable: BOOLEAN is False

   bracketed_pretty_print is
      do
         pretty_printer.put_character('(')
         pretty_print
         pretty_printer.put_character(')')
      end

   pretty_print is
      local
         i: INTEGER
      do
         pretty_printer.put_character('[')
         pretty_printer.indent_level_increment
         if list /= Void then
            from
               i := list.lower
            until
               i > list.upper
            loop
               list.item(i).pretty_print
               i := i + 1
               if i <= list.upper then
                  pretty_printer.put_character(',')
                  pretty_printer.put_character(' ')
               end
            end
         end
         pretty_printer.put_character(']')
         pretty_printer.indent_level_decrement
      end

   print_as_target is
      do
         pretty_printer.put_character('(')
         pretty_print
         pretty_printer.put_character(')')
         pretty_printer.put_character('.')
      end

   short is
      local
         i: INTEGER
      do
         short_print.hook_or(once "open_sb",once "[")
         if list /= Void then
            from
               i := list.lower
            until
               i > list.upper
            loop
               list.item(i).short
               i := i + 1
               if i <= list.upper then
                  short_print.hook_or(once "ma_sep",once ",")
               end
            end
         end
         short_print.hook_or(once "close_sb",once "]")
      end

   short_target is
      do
         bracketed_short
         short_print.a_dot
      end

   to_integer_or_error: INTEGER is
      do
	 to_integer_error
      end

   start_lookup_class: BASE_CLASS is do end

   stupid_switch(run_time_set: RUN_TIME_SET): BOOLEAN is
      local
         i: INTEGER
      do
         Result := True
         if list /= Void then
            from
               i := list.upper
            until
               not Result or else i < list.lower
            loop
               Result := list.item(i).stupid_switch(run_time_set)
               i := i - 1
            end
         end
      end

   to_runnable(ct: E_TYPE): like Current is
      do
	 Result := to_runnable_(ct)
	 if nb_errors = 0 then
	    Result.result_type.run_class.set_at_run_time
         end
      end

   simplify_1_, simplify_2: like Current is
      do
	 Result := Current
      end
   
   use_current: BOOLEAN is
      local
         i: INTEGER
      do
         if list /= Void then
            from
               i := list.upper
            until
               i < list.lower or else Result
            loop
               Result := list.item(i).use_current
               i := i - 1
            end
         end
      end

   afd_check is
      local
         i: INTEGER
      do
         if list /= Void then
            from
               i := list.upper
            until
               i < list.lower
            loop
               list.item(i).afd_check
               i := i - 1
            end
         end
      end

   safety_check is
      local
         i: INTEGER
      do
         if list /= Void then
            from
               i := list.upper
            until
               i < list.lower
            loop
               list.item(i).safety_check
               i := i - 1
            end
         end
      end

   once_pre_computable: BOOLEAN is
      do
	 -- At time beeing, TUPLE expression are never handled :-(
      end

   assertion_check(tag: CHARACTER) is
      local
         i: INTEGER; e: EXPRESSION
      do
         if list /= Void then
            from
               i := list.upper
            until
               i < list.lower
            loop
               e := list.item(i)
               e.assertion_check(tag)
               i := i - 1
            end
         end
      end

   dca_inline_argument(formal_arg_type: E_TYPE) is
      do
      end

   collect_c_tmp is
      local
         i: INTEGER
      do
	 if list /= Void then
	    from
	       i := list.upper
	    until
	       i < list.lower
	    loop
	       list.item(i).collect_c_tmp
	       i := i - 1
	    end
	 end
      end

   c_frame_descriptor(format, locals: STRING) is
      local
         i: INTEGER
      do
         if list /= Void then
            from
               i := list.upper
            until
               i < list.lower
            loop
               list.item(i).c_frame_descriptor(format,locals)
               i := i - 1
            end
         end
      end

   jvm_assign_creation, jvm_assign is
      do
	 check False end
      end

   jvm_branch_if_false: INTEGER is
      do
	 check False end
      end

   jvm_branch_if_true: INTEGER is
      do
	 check False end
      end

   compile_target_to_jvm, compile_to_jvm is
      local
         i: INTEGER; e: EXPRESSION; idx: INTEGER; cd: STRING; d: STRING
      do
	 result_type.run_class.jvm_basic_new
         create cd.make(32)
         create d.make(32)
         if list /= Void then
            from
               i := list.lower
            until
               i > list.upper
            loop
               code_attribute.opcode_dup
               e := list.item(i)
               e.compile_to_jvm
               cd.wipe_out
               cd.append(result_type.run_class.fully_qualified_name)
               d.wipe_out
               if e.result_type.is_basic_eiffel_expanded then
                  e.result_type.jvm_descriptor_in(d)
               else
                  e.result_type.jvm_descriptor_in(d)
               end
               idx := constant_pool.idx_fieldref3(cd, 
			result_type.item_name(i-list.lower+1),d)
               code_attribute.opcode_putfield(idx,-2)
               i := i + 1
            end
         end
      end
   
   compile_to_jvm_into(dest: E_TYPE): INTEGER is
      do
         Result := 1
         compile_to_jvm
      end
   
   mapping_c_target(target_type: E_TYPE) is
      do
         cpp.put_character('(')
         target_type.mapping_cast
         compile_to_c
         cpp.put_character(')')
      end

   mapping_c_arg(formal_arg_type: E_TYPE) is
      do
         compile_to_c
      end

   compile_to_c is
      local
         i: INTEGER; e: EXPRESSION; t: E_TYPE
      do
         cpp.put_string(once "new_tuple")
	 cpp.put_integer(result_type.id)
         cpp.put_character('(')
         if list /= Void then
            from
               i := list.lower
            until
               i > list.upper
            loop
               e := list.item(i)
	       t := e.result_type
               e.mapping_c_arg(t)
	       if i < list.upper then
		  cpp.put_character(',')
		  cpp.put_character('%N')
	       end
               i := i + 1
            end
         end
         cpp.put_character(')')
      end

feature {FAKE_TUPLE}

   list: FIXED_ARRAY[EXPRESSION]
         -- Void or elements in the manifest array.

   debug_info: STRING

   to_runnable_(ct: E_TYPE): like Current is
      local
         i: INTEGER; e: EXPRESSION; types: ARRAY[E_TYPE]
	 l: like list
      do
         if current_type = Void then
            current_type := ct
            if list /= Void then
               from
		  create types.with_capacity(list.count,1)
                  i := list.lower
               until
                  i > list.upper
               loop
                  e := list.item(i).to_runnable(ct)
                  if e = Void then
                     error_handler.add_position(start_position)
                     error(list.item(i).start_position,
                           "Bad expression inside TUPLE.")
                     i := list.upper + 1
                  else
                     list.put(e,i)
		     types.add_last(e.result_type.run_type)
                     i := i + 1
                  end
               end
            end
            if nb_errors = 0 then
               create result_type.make(start_position,types)
	       result_type := result_type.to_runnable(ct)
               Result := Current
            end
         else
	    l := list
	    if l /= Void then
	       l := l.twin
	    end
            create Result.make(start_position,l)
            Result := Result.to_runnable(ct)
         end
	 debug
	    debug_info := result_type.run_time_mark
	 end
      end

feature {TUPLE_EXPRESSION_VISITOR}

   accept(visitor: TUPLE_EXPRESSION_VISITOR) is
      do
         visitor.visit_tuple_expression(Current)
      end

feature {NONE}

   current_type: E_TYPE

   make(sp: like start_position; l: like list) is
      require
         not sp.is_unknown
         l /= Void implies not l.is_empty
      do
         start_position := sp
         list := l
      ensure
         start_position = sp
         list = l
      end

end

