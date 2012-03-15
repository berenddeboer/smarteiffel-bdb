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
class FAKE_TUPLE
   --
   -- Pseudo expression used to avoid creation of TUPLEs at run-time.
   -- Very important for an efficient agents implementation.
   --

inherit EXPRESSION

creation make

feature

   is_void: BOOLEAN is False

   is_current: BOOLEAN is False

   side_effect_free: BOOLEAN is False

   once_pre_computable: BOOLEAN is False

   precedence: INTEGER is 2

   is_static: BOOLEAN is False

   is_manifest_string: BOOLEAN is False

   is_result: BOOLEAN is False

   is_writable: BOOLEAN is False

   extra_bracket_flag: BOOLEAN is False
   
   start_position: POSITION is
      do
	 Result := tuple_expression.start_position
      end

   debug_info: STRING

   to_runnable(ct: E_TYPE): like Current is
      do
	 if current_type = Void then
	    current_type := ct
	    tuple_expression := tuple_expression.to_runnable_(ct)
	    Result := Current
	    debug
	       create debug_info.make(32)
	       debug_info.append("ct:")
	       debug_info.append(ct.run_time_mark)
	       debug_info.append(" result_type:")
	       debug_info.append(tuple_expression.result_type.run_time_mark)
	    end
	 else
	    create Result.make(tuple_expression)
	    Result := Result.to_runnable(ct)
	 end
      end

   simplify_1_, simplify_2: like Current is
      do
	 Result := Current
      end
   
   compile_to_c is
      local
	 i: INTEGER; list: FAST_ARRAY[EXPRESSION]; e: EXPRESSION
      do
	 list := tuple_expression.list
	 if list /= Void then
	    from until i > list.upper
	    loop
	       e := list.item(i)
	       e.mapping_c_arg(e.result_type)
	       if i < list.upper then
		  cpp.put_character(',')
	       end
	       i := i + 1
	    end
	 end
      end

   mapping_c_target(formal_type: E_TYPE) is
      do
	 check False end
      end

   mapping_c_arg(formal_arg_type: E_TYPE) is
      do
	 check False end
      end

   c_frame_descriptor(format, locals: STRING) is
      do
	 check False end
      end

   result_type: E_TYPE is
      do
	 Result := tuple_expression.result_type
      end

   afd_check is
      do
	 tuple_expression.afd_check
      end

   safety_check is
      do
	 tuple_expression.safety_check
      end

   collect_c_tmp is
      do
	 tuple_expression.collect_c_tmp
      end

   to_integer_or_error: INTEGER is
      do
	 to_integer_error
      end

   stupid_switch(run_time_set: RUN_TIME_SET): BOOLEAN is
      do
	 check False end
      end

   isa_dca_inline_argument: INTEGER is 0

   dca_inline_argument(formal_arg_type: E_TYPE) is
      do
	 check False end
      end

   assertion_check(tag: CHARACTER) is
      do
	 tuple_expression.assertion_check(tag)
      end

   use_current: BOOLEAN is
      do
	 Result := tuple_expression.use_current
      end

   start_lookup_class: BASE_CLASS is
      do
	 Result := tuple_expression.start_lookup_class
      end

   pretty_print is
      do
	 tuple_expression.pretty_print
      end

   print_as_target is
      do
	 tuple_expression.print_as_target
      end

   bracketed_pretty_print is
      do
	 tuple_expression.bracketed_pretty_print
      end

   short is
      do
	 tuple_expression.short
      end

   short_target is
      do
	 tuple_expression.short_target
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

   compile_to_jvm is
      local
	 i: INTEGER; list: FAST_ARRAY[EXPRESSION]
      do
	 list := tuple_expression.list
	 if list /= Void then
	    from
	       i := list.lower
	    until
	       i > list.upper
	    loop
	       list.item(i).compile_to_jvm
	       i := i + 1
	    end
	 end
      end

   compile_to_jvm_into(dest: E_TYPE): INTEGER is
      do
	 check False end
      end

   compile_target_to_jvm is
      do
	 check False end
      end

feature {AGENT_ARGS,AGENT_INSTRUCTION,AGENT_EXPRESSION}

   count: INTEGER is
      local
	 list: FAST_ARRAY[EXPRESSION]
      do
	 list := tuple_expression.list
	 if list /= Void then
	    Result := list.count
	 end
      end

   expression(i: INTEGER): EXPRESSION is
      require
	 i.in_range(1, count)
      local
	 list: FAST_ARRAY[EXPRESSION]
      do
	 list := tuple_expression.list
	 Result := list.item(i - 1)
      end

feature {AGENT_ARGS}

   set_expression(e: EXPRESSION; i: INTEGER) is
      require
	 e /= Void
	 e /= expression(i)
      local
	 list: FAST_ARRAY[EXPRESSION]
      do
	 list := tuple_expression.list
	 list.put(e, i - 1)
      end
   
feature {FAKE_TUPLE_VISITOR}

   accept(visitor: FAKE_TUPLE_VISITOR) is
      do
         visitor.visit_fake_tuple(Current)
      end

feature {NONE}

   current_type: E_TYPE

   tuple_expression: TUPLE_EXPRESSION
	 -- The hidded one.

   make(te: like tuple_expression) is
      require
	 te /= Void
      do
	 tuple_expression := te
      ensure
	 tuple_expression = te
      end

invariant

   tuple_expression /= Void

end --  FAKE_TUPLE

