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
class IMPLICIT_CAST
   --
   -- To memorize an implicit legal cast from one type to another.
   -- This invisible expression is used for all kinds of implicit
   -- conversions:
   --   from INTEGER to REAL
   --   from INTEGER to DOUBLE,
   --   from REAL to DOUBLE,
   --   from INTEGER to reference INTEGER,
   --   from INTEGER_8 to reference INTEGER_8,
   --   ...
   --   from FOO to reference FOO,
   --   ...

inherit EXPRESSION

creation {ASSIGNMENT_HANDLER} make

feature

   is_manifest_string: BOOLEAN is
      do
         Result := expression.is_manifest_string
      end

   extra_bracket_flag: BOOLEAN is
      do
	 Result := expression.extra_bracket_flag
      end
   
   to_integer_or_error: INTEGER is
      do
	 to_integer_error
      end

   result_type: E_TYPE is
      do
         Result := destination_type
      end

   is_void: BOOLEAN is
      do
         Result := expression.is_void
      end

   start_lookup_class: BASE_CLASS is
      do
         Result := result_type.base_class
      end

   is_writable: BOOLEAN is
      do
         Result := expression.is_writable
      end

   is_result: BOOLEAN is
      do
         Result := expression.is_result
      end

   is_current: BOOLEAN is
      do
         Result := expression.is_current
      end

   assertion_check(tag: CHARACTER) is
      do
         expression.assertion_check(tag)
      end

   is_static: BOOLEAN is
      do
         Result := expression.is_static
      end

   once_pre_computable: BOOLEAN is
      do
         Result := expression.once_pre_computable
      end

   isa_dca_inline_argument: INTEGER is
      do
         Result := expression.isa_dca_inline_argument
      end

   dca_inline_argument(formal_arg_type: E_TYPE) is
      do
         expression.dca_inline_argument(formal_arg_type)
      end

   compile_to_c is
      local
	 i: INTEGER
      do
         c_wrapper_opening
	 if source_type.is_reference then
	    -- To promote automatically reference INTEGER_* type:
	    cpp.put_character('(')
	    from
	       i := 1
	    until
	       conversion.item(i) = 't'
	    loop
	       cpp.put_character(conversion.item(i))
	       i := i + 1
	    end
	    cpp.put_string(fz_70)
	    expression.compile_to_c
	    cpp.put_character(')')
	 else
	    expression.mapping_c_target(source_type)
	 end
         c_wrapper_closing
      end

   mapping_c_target(target_type: E_TYPE) is
      do
	 compile_to_c
      end

   mapping_c_arg(formal_arg_type: E_TYPE) is
      do
	 compile_to_c
      end

   afd_check is
      do
         expression.afd_check
      end

   safety_check is
      do
         expression.safety_check
      end

   collect_c_tmp is
      do
          expression.collect_c_tmp
      end

   c_frame_descriptor(format, locals: STRING) is
      do
	 expression.c_frame_descriptor(format,locals)
      end

   compile_to_jvm is
      local
         space: INTEGER
      do
         expression.compile_to_jvm
         space := source_type.jvm_convert_to(destination_type)
      end

   compile_target_to_jvm is
      local
         space: INTEGER
      do
         expression.compile_target_to_jvm
         space := source_type.jvm_convert_to(destination_type)
      end

   compile_to_jvm_into(dest: E_TYPE): INTEGER is
      do
         compile_to_jvm
         Result := destination_type.jvm_convert_to(dest)
      end

   jvm_branch_if_false: INTEGER is
      do
         Result := expression.jvm_branch_if_false
      end

   jvm_branch_if_true: INTEGER is
      do
         Result := expression.jvm_branch_if_true
      end

   use_current: BOOLEAN is
      do
         Result := expression.use_current
      end

   stupid_switch(run_time_set: RUN_TIME_SET): BOOLEAN is
      do
         Result := expression.stupid_switch(run_time_set)
      end

   side_effect_free: BOOLEAN is
      do
         Result := expression.side_effect_free
      end

   to_runnable(ct: E_TYPE): EXPRESSION is
      do
         Result := expression.to_runnable(ct)
      end

   simplify_1_: EXPRESSION is
      do
	 Result := simplify(expression.simplify_1_)
      end
   
   simplify_2: EXPRESSION is
      do
	 Result := simplify(expression.simplify_2)
      end
   
   start_position: POSITION is
      do
         Result := expression.start_position
      end

   bracketed_pretty_print, pretty_print is
      do
         expression.pretty_print
      end

   print_as_target is
      do
         expression.print_as_target
      end

   short is
      do
         expression.short
      end

   short_target is
      do
         expression.short_target
      end

   precedence: INTEGER is
      do
         Result := expression.precedence
      end

   jvm_assign_creation, jvm_assign is
      do
         expression.jvm_assign
      end

feature {C_PRETTY_PRINTER}

   original_expression: EXPRESSION is
      do
         Result := expression
      end

feature {IMPLICIT_CAST_VISITOR}

   accept(visitor: IMPLICIT_CAST_VISITOR) is
      do
         visitor.visit_implicit_cast(Current)
      end

feature {NONE}

   expression : EXPRESSION
         -- The wrapped `expression' with it's `source_type'.

   source_type, destination_type: E_TYPE

   conversion: STRING
	 -- If mandatory, the name of the C conversion function (to 
	 -- avoid too many C code generation).
   
   make(e: like expression; dt: like destination_type) is
      require
         e.result_type.run_time_mark /= dt.run_time_mark
	 e.result_type.is_a(dt)
      do
         expression := e
         source_type := e.result_type.run_type
         destination_type := dt.run_type
	 if source_type.is_expanded and then destination_type.is_expanded
	  then
	    -- May be two INTEGERs of different size or some REAL 
	    -- value converted into DOUBLE for example.
	 else
	    conversion := assignment_handler.register(source_type,
						      destination_type)
	 end
	 if source_type.is_bit and then destination_type.is_reference then
	    smart_eiffel.bit_n_ref_is_nyi_error(e.start_position)
	 end
      ensure
         expression = e
         source_type = e.result_type.run_type
         destination_type = dt.run_type
      end

   simplify(e: like expression): EXPRESSION is
      local
	 ic: INTEGER_CONSTANT; rc: REAL_CONSTANT; rt: E_TYPE
      do
	 rt := result_type
	 if rt.is_double or else rt.is_real then
	    ic ?= e
	    if ic /= Void then
	       create {REAL_CONSTANT}
	          Result.from_double(start_position, ic.value_memory.to_double, rt)
	    else
	       rc ?= e
	       if rc /= Void then
		  rc.set_result_type(rt)
	          Result := rc
	       else
		  Result := Current
	       end
	    end
	 elseif rt.is_integer then
	    ic ?= e
	    if ic /= Void then
	       Result := ic
	    else
	       Result := Current
	    end
	 else
	    Result := Current
	 end
      end
   
   c_wrapper_opening is
      do
	 if conversion = Void then
	    cpp.put_string(once "/*IC*/")
	    destination_type.mapping_cast
	 else
	    cpp.put_string(conversion)
	 end
	 cpp.put_character('(')
      end

   c_wrapper_closing is
      do
	 cpp.put_character(')')
      end

invariant

   source_type.run_type = source_type
   
   destination_type.run_type = destination_type
   
end -- IMPLICIT_CAST

