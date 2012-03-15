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
deferred class TYPE_OF_AGENT
   --
   -- Common for all TYPEs of agents: TYPE_ROUTINE, TYPE_PROCEDURE,
   -- and TYPE_FUNCTION.
   --

inherit E_TYPE

feature

   is_reference: BOOLEAN is True

   is_generic: BOOLEAN is False

   is_any,
   is_none,
   is_expanded,
   is_separate,
   is_anchored,
   is_like_current,
   is_array,
   is_basic_eiffel_expanded,
   is_integer,
   is_real,
   is_double,
   is_character,
   is_boolean,
   is_pointer,
   is_bit,
   is_string
   : BOOLEAN is False
   
   start_position: POSITION

   base_class_name: CLASS_NAME
	 -- Either ROUTINE, PROCEDURE or FUNCTION.
   
   base: E_TYPE
	 -- Type to which the feature belongs.

   open: TYPE_TUPLE
	 -- Tuple of the types of open operands, if any.
	 -- (See also `static_open'.)

   static_open: E_TYPE
	 -- Because one may use anchored type to denote `open', 
	 -- `static_open' is the written type mark for `open'.

   res: E_TYPE
	 -- If any, the type of the `Result'.

   written_runnable_flag: BOOLEAN
	 -- True when the corresponding mark is completely static 
	 -- (i.e. written only with static type marks).   

   frozen is_run_type: BOOLEAN is
      do
         Result := run_type /= Void
      end

   run_type: like Current
	 -- Non Void indicates `is_run_type'.
         -- (This is always a completely static type mark.)   
   
   frozen run_time_mark: STRING is
      do
	 Result := run_type.written_mark
      end

   frozen to_runnable(ct: E_TYPE): like Current is
      do
	 if written_runnable_flag then
	    if open = Void then
	       set_open_using(static_open)
	    else
	       run_type.load_builtin_features
	    end
	    Result := Current
	 else
	    Result := to_runnable_(ct)
	 end
      ensure then
	 no_errors implies open /= Void
      end

   to_runnable_(ct: E_TYPE): like Current is
      require
	 not written_runnable_flag
      deferred
      end
   
   c_sizeof: INTEGER is
      do
         Result := c_sizeof_pointer
      end

   frozen c_type_for_target_in(buffer: STRING) is
      do
	 buffer.extend('T')
	 id.append_in(buffer)
	 buffer.extend('*')
      end

   frozen c_type_for_argument_in,
   frozen c_type_for_result_in(buffer: STRING) is
      do
	 buffer.append(fz_t0_star)
      end

   frozen start_lookup_name: CLASS_NAME is
      do
	 Result := base_class_name
      end

   is_like_feature: BOOLEAN is False

   frozen is_a(other: E_TYPE): BOOLEAN is
      local
	 type_of_agent: TYPE_OF_AGENT
      do
	 type_of_agent ?= other.run_type
	 if type_of_agent /= Void then
	    Result := is_a_(type_of_agent)
	 elseif other.is_any then
	    error_handler.append("SmartEiffel limitation (sorry); ")	    
	 end
         if not Result then
            error_handler.type_error(Current, other)
         end
      end

   frozen generic_list: ARRAY[E_TYPE] is
      do
	 check False end
      end

   frozen local_from_separate: E_TYPE is
      do
	 check False end
      end

   c_initialize_in(str: STRING) is
      do
	 str.append(fz_null)
      end

   c_initialize is
      do
	 cpp.put_string(fz_null)
      end

   frozen c_header_pass1 is
      do
	 cpp.put_string(once "typedef T0 T")
	 cpp.put_integer(id)
	 cpp.put_character(';')
	 cpp.put_character('%N')
      end

   frozen c_header_pass2 is
      do
      end

   frozen c_header_pass3 is
      do
      end

   frozen c_header_pass4 is
      do
         standard_c_print_function
      end

   just_before_gc_mark_in(str: STRING) is do end

   frozen gc_define1 is
      do
	 cpp.put_string("#define gc_mark")
	 cpp.put_integer(id)
	 cpp.put_string("(x) gc_mark_agent((x))%N")
      end

   frozen gc_define2 is do end

   is_user_expanded: BOOLEAN is False

   need_gc_mark_function: BOOLEAN is True

   stupid_switch(run_time_set: RUN_TIME_SET): BOOLEAN is do end

   gc_info_in(str: STRING) is do end

   is_dummy_expanded: BOOLEAN is False

   need_c_struct: BOOLEAN is False

   actual_reference(destination: E_TYPE): E_TYPE is
      do
	 check False end
      end

   actual_separate(destination: E_TYPE): E_TYPE is
      do
	 check False end
      end

   is_like_argument: BOOLEAN is False

   smallest_ancestor(other: E_TYPE): E_TYPE is
      do
	 not_yet_implemented
      end

   frozen id: INTEGER is
      do
	 Result := run_class.id
      end

   frozen jvm_xnewarray is
      local
         idx: INTEGER
      do
         idx := constant_pool.idx_jvm_root_class
         code_attribute.opcode_anewarray(idx)
      end

   frozen jvm_check_class_invariant is
      do
         standard_jvm_check_class_invariant
      end

   frozen jvm_if_x_ne: INTEGER is
      do
         Result := code_attribute.opcode_if_acmpne
      end

   frozen jvm_return_code is
      do
         code_attribute.opcode_areturn
      end

   frozen jvm_convert_to(destination: E_TYPE): INTEGER is
      do
         Result := 1
      end

   frozen jvm_target_descriptor_in(str: STRING) is
      do
      end

   frozen jvm_push_local(offset: INTEGER) is
      do
         code_attribute.opcode_aload(offset)
      end

   frozen jvm_xaload is
      do
         code_attribute.opcode_aaload
      end

   frozen jvm_write_local_creation, jvm_write_local(offset: INTEGER) is
      do
         code_attribute.opcode_astore(offset)
      end

   frozen jvm_expanded_from_reference(other: E_TYPE): INTEGER is
      do
	 check False end
      end

   frozen jvm_push_default: INTEGER is
      do
         code_attribute.opcode_aconst_null
         Result := 1
      end

   frozen jvm_descriptor_in(str: STRING) is
      do
	      str.append(jvm_root_descriptor)
      end

   frozen jvm_method_flags: INTEGER is 17

   frozen jvm_standard_is_equal is
       local
         rc: RUN_CLASS; wa: ARRAY[RUN_FEATURE_2]
      do
         rc := run_class
         wa := rc.writable_attributes
         jvm.std_is_equal(rc,wa)
      end

   frozen jvm_xastore is
      do
         code_attribute.opcode_aastore
      end

   frozen jvm_if_x_eq: INTEGER is
      do
         Result := code_attribute.opcode_if_acmpeq
      end

feature {E_AGENT, RUN_CLASS, TYPE_OF_AGENT}

   load_builtin_features is
	 -- Load the built-in predefined appropriate features (`call' 
	 -- for PROCEDURE  `item' and `call' for FUNCTION, etc.). 
      require
	 is_run_type
      deferred
      end

feature {TYPE_OF_AGENT}

   set_open_using(st: like static_open) is
	 -- Check that `st.run_type' is a valid `open' TUPLE type mark and call 
	 -- the `load_builtin_features'.
  
      require
	 st.is_run_type
      do
	 open ?= st.run_type
	 if open = Void then
	    error_handler.add_position(st.start_position)
	    error_handler.append("TUPLE type mark expected for open argument %
				 %part of agent type (see also next error %
				 %message).")
	    error_handler.print_as_warning
	    error_handler.add_type(st.run_type, " is not a TUPLE type mark.")
	    error_handler.print_as_fatal_error
	 end
	 load_builtin_features
      end
      
feature {TYPE_OF_AGENT_VISITOR}

   accept(visitor: TYPE_OF_AGENT_VISITOR) is
      deferred
      end

feature {NONE}

   written_mark_memory: STRING

   is_a_(other: TYPE_OF_AGENT): BOOLEAN is
      deferred
      end

invariant

   base /= Void

   static_open /= Void

end -- TYPE_OF_AGENT
