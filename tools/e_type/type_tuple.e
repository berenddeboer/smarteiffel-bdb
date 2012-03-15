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
class TYPE_TUPLE
   --
   -- For the TUPLE type.
   --

inherit E_TYPE

creation make

creation {TYPE_TUPLE} set

feature

   is_reference,
   need_c_struct
   : BOOLEAN is True
   

   is_any,
   is_none,
   is_expanded,
   is_separate,
   is_user_expanded,
   is_basic_eiffel_expanded,
   is_anchored,
   is_like_argument,
   is_like_current,
   is_like_feature,
   is_array,
   is_dummy_expanded,
   is_string,
   is_bit,
   is_integer,
   is_character,
   is_real,
   is_double,
   is_boolean,
   is_pointer
   : BOOLEAN is False

   start_position: POSITION

   base_class_name: CLASS_NAME

   is_generic: BOOLEAN is
      do
	 Result := generic_list /= Void
      end

   generic_list: ARRAY[E_TYPE]
	 -- Of the TUPLE.
   
   written_runnable_flag: BOOLEAN
	 -- True when the corresponding mark is completely static 
	 -- (i.e. written only with static type marks).

   written_mark: STRING is
      local
	 i: INTEGER
      do
	 Result := written_mark_memory
	 if Result = Void then
	    if generic_list = Void then
	       Result := as_tuple
	    else
	       -- To force computation of `generic_list' items:
	       from
		  i := generic_list.upper
	       until
		  i = 0
	       loop
		  if generic_list.item(i).written_mark = Void then
		     check False end
		  end
		  i := i - 1
	       end
	       -- Then compute the `Result':
	       Result := once ".....         local unique buffer          ....."
	       Result.copy(as_tuple)
	       Result.extend('[')
	       from
		  i := generic_list.lower
	       until
		  i > generic_list.upper
	       loop
		  Result.append(generic_list.item(i).written_mark)
		  if i < generic_list.upper then
		     Result.extend(',')
		  end
		  i := i + 1
	       end
	       Result.extend(']')
	       Result := string_aliaser.item(Result)
	    end
	    written_mark_memory := Result
	 end
      end

   run_time_mark: STRING is
      do
	 Result := run_type.written_mark
      end

   type(i: INTEGER): E_TYPE is
      require
	 is_run_type
	 i.in_range(1, count)
      do
	 if run_type = Current then
	    Result := generic_list.item(i)
	 else
	    Result := run_type.type(i)
	 end
      ensure
	 Result /= Void
      end

   count: INTEGER is
      do
	 if generic_list /= Void then
	    Result := generic_list.count
	 end
      end

   is_run_type: BOOLEAN is
      do
	 Result := run_type /= Void
      end

   run_type: like Current
	 -- Non Void indicates `is_run_type'.
         -- (This is always a completely static type mark.)


   stupid_switch(run_time_set: RUN_TIME_SET): BOOLEAN is
      do
         Result := written_mark = run_time_mark
      end

   id: INTEGER is
      do
         Result := run_class.id
      end

   c_sizeof: INTEGER is
      do
	 Result := c_sizeof_pointer
      end

   is_a(other: E_TYPE): BOOLEAN is
      local
	 other_tuple: like Current; other_run_types: ARRAY[E_TYPE]
         i: INTEGER; t1, t2: E_TYPE
      do
	 Result := True
	 other_tuple ?= other.run_type
         if other_tuple /= Void then
	    if other_tuple.count > count then
	       Result := False
	    else
	       from
		  other_run_types := other_tuple.generic_list
		  if other_run_types /= Void then
		     i := other_run_types.upper
		  end
	       until
		  not Result or else i <= 0
	       loop
		  t1 := run_type.generic_list.item(i)
		  t2 := other_run_types.item(i)
		  if t1.is_a(t2) then
		     i := i - 1
		  else
		     Result := False
		     error_handler.add_position(t1.start_position)
		     error_handler.add_position(t2.start_position)
		  end
	       end
	    end
	 elseif other.is_any then
	 else
	    Result := False
         end
         if not Result then
            error_handler.type_error(Current, other)
         end
      end

   smallest_ancestor(other: E_TYPE): E_TYPE is
      local
         rto: E_TYPE; unknown_position: POSITION; i, c: INTEGER
	 t1, t2: E_TYPE; other_tuple: like Current
         common, run_types, other_run_types: ARRAY[E_TYPE]
      do
	 run_types := run_type.generic_list
         rto := other.run_type
         other_tuple ?= rto
         if other_tuple /= Void then
            if other_tuple.count = 0 then
               Result := other
            elseif count = 0 then
               Result := Current
            else
               other_run_types := other_tuple.generic_list
               c := count.min(other_tuple.count)
               create common.make(1,c)
               from
                  i := common.lower
               until
                  i > common.upper
               loop
                  t1 := run_types.item(i)
                  t2 := other_run_types.item(i)
                  common.put(t1.smallest_ancestor(t2),i)
                  i := i + 1
               end
               create {TYPE_TUPLE} Result.make(unknown_position,common)
            end
         else
            Result := rto.smallest_ancestor(Current)
         end
      end

   to_runnable(ct: E_TYPE): like Current is
      local
	 i: INTEGER; rgl: like generic_list; t1, t2: E_TYPE
	 new_rgl_flag: BOOLEAN
      do
	 if written_runnable_flag then
	    if generic_list /= Void then
	       to_runnable_for_all(ct, generic_list)
	    end
	    load_basic_features
	    Result := Current
	 else
            from
	       if run_type = Void then
		  rgl := generic_list.twin
		  new_rgl_flag := True
	       else
		  rgl := run_type.generic_list
	       end
               i := rgl.upper
            until
               i = 0
            loop
               t1 := generic_list.item(i)
               t2 := t1.to_runnable(ct)
               if t2 = Void or else not t2.is_run_type then
                  error_handler.add_type(t1, fz_is_invalid)
                  error_handler.print_as_error
                  i := 0
               else
		  t2 := t2.run_type
		  if new_rgl_flag then
		     rgl.put(t2, i)
		  elseif t2 = rgl.item(i)
		     or else t2.run_time_mark = rgl.item(i).run_time_mark
		   then
		     -- We are lucky, because this is the same one.
		  else
		     -- We have to actually create a new `rgl':
		     rgl := rgl.twin
		     new_rgl_flag := True
		     rgl.put(t2, i)
		  end
		  if t2.is_expanded then
		     t2.run_class.set_at_run_time
		  end
		  i := i - 1
	       end
            end
	    if new_rgl_flag then
	       if run_type = Void then
		  create run_type.make(start_position, rgl)
		  check run_type.written_runnable_flag end
		  run_type.load_basic_features
		  Result := Current
	       else
		  create Result.make(start_position, rgl)
		  check Result.written_runnable_flag end
		  Result.load_basic_features
		  create Result.set(start_position,
				    generic_list,
				    Result)
	       end
	    else
	       -- We are lucky:
	       Result := Current
	    end
	 end
      end
   
   local_from_separate: E_TYPE is
      do
	 check False end
      end

   actual_reference(destination: E_TYPE): E_TYPE is
      do
	 check False end
      end

   actual_separate(destination: E_TYPE): E_TYPE is
      do
	 check False end
      end

   start_lookup_name: CLASS_NAME is
      do
         Result := base_class_name
      end

   c_type_for_argument_in(str: STRING) is
      do
         str.append(fz_t0_star)
      end

   c_type_for_target_in(str: STRING) is
      do
         str.extend('T')
         id.append_in(str)
         str.extend('*')
      end

   c_type_for_result_in(str: STRING) is
      do
         str.append(fz_t0_star)
      end

   c_header_pass1 is
      do
         standard_c_typedef
      end

   c_header_pass2 is
      do
      end

   c_header_pass3 is
      do
      end

   c_header_pass4 is
      local
	 i: INTEGER; t: E_TYPE; run_types: like generic_list
      do
	 run_types := run_type.generic_list
	 if need_c_struct then
	    standard_c_struct
	    standard_c_object_model
	 end
	 -- Definition of new_tupleXXX:
         standard_c_print_function
	 header.copy(once "T0*new_tuple")
	 id.append_in(header)
	 header.extend('(')
	 if run_types /= Void then
	    from
	       i := run_types.lower
	    until
	       i > run_types.upper
	    loop
	       t := run_types.item(i)
	       t.c_type_for_argument_in(header)
	       header.append(once " i")
	       i.append_in(header)
	       if i < run_types.upper then
		  header.extend(',')
	       end
	       i := i + 1
	    end
	 end
	 header.extend(')')
	 cpp.put_c_heading(header)
	 cpp.swap_on_c
	 gc_handler.declare_allocate_n(run_class)
	 if run_types /= Void then
	    cpp.put_string(once "n->_first=i1;%N")
	    if run_types.count >= 2 then
	       cpp.put_string(once "n->_second=i2;%N")
	    end
	    if run_types.count >= 3 then
	       cpp.put_string(once "n->_third=i3;%N")
	    end
	    if run_types.count >= 4 then
	       cpp.put_string(once "n->_fourth=i4;%N")
	    end
	    if run_types.count >= 5 then
	       cpp.put_string(once "n->_fifth=i5;%N")
	    end
	    from
	       i := 6
	    until
	       i > run_types.upper
	    loop
	       cpp.put_string(once "n->_item_")
	       cpp.put_integer(i)
	       cpp.put_string(once "=i")
	       cpp.put_integer(i)
	       cpp.put_string(once "%N;")
	       i := i + 1
	    end
	 end
	 cpp.put_string(once "return (T0*)n;}%N")
	 cpp.swap_on_h
      end

   c_initialize is
      do
	 cpp.put_string(fz_null)
      end

   c_initialize_in(str: STRING) is
      do
	 str.append(fz_null)
      end

   jvm_method_flags: INTEGER is 17

   jvm_descriptor_in(str: STRING) is
      do
	 str.append(jvm_root_descriptor)
      end

   jvm_target_descriptor_in(str: STRING) is
      do
      end

   jvm_return_code is
      do
         code_attribute.opcode_areturn
      end

   jvm_check_class_invariant is
      do
         standard_jvm_check_class_invariant
      end

   jvm_push_local(offset: INTEGER) is
      do
         code_attribute.opcode_aload(offset)
      end

   jvm_push_default: INTEGER is
      do
         Result := 1
	 code_attribute.opcode_aconst_null
      end

   jvm_write_local_creation(offset: INTEGER) is
      do
         code_attribute.opcode_astore(offset)
      end

   jvm_write_local(offset: INTEGER) is
      do
         code_attribute.opcode_astore(offset)
      end

   jvm_xnewarray is
      local
         idx: INTEGER
      do
	 idx := constant_pool.idx_jvm_root_class
         code_attribute.opcode_anewarray(idx)
      end

   jvm_xastore is
      do
         code_attribute.opcode_aastore
      end

   jvm_xaload is
      do
         code_attribute.opcode_aaload
      end

   jvm_if_x_eq: INTEGER is
      do
         Result := code_attribute.opcode_if_acmpeq
      end

   jvm_if_x_ne: INTEGER is
      do
         Result := code_attribute.opcode_if_acmpne
      end

   jvm_to_reference is
      do
      end

   jvm_expanded_from_reference(other: E_TYPE): INTEGER is
      do
         check
            False
         end
      end

   jvm_convert_to(destination: E_TYPE): INTEGER is
      do
	 Result := 1
      end

   jvm_standard_is_equal is
      local
         rc: RUN_CLASS; wa: ARRAY[RUN_FEATURE_2]
      do
         rc := run_class
         wa := rc.writable_attributes
         jvm.std_is_equal(rc,wa)
      end

feature {E_TYPE}

   frozen short_hook is
      local
         i: INTEGER
      do
         short_print.a_magic_class_name(base_class_name)
	 if generic_list /= Void then
	    short_print.hook_or(once "open_sb",once "[")
	    from
	       i := 1
	    until
	       i > generic_list.count
	    loop
	       generic_list.item(i).short_hook
	       if i < generic_list.count then
		  short_print.hook_or(once "tm_sep",once ",")
	       end
	       i := i + 1
	    end
	    short_print.hook_or(once "close_sb",once "]")
	 end
      end

feature {RUN_CLASS,E_TYPE}

   need_gc_mark_function: BOOLEAN is True

   just_before_gc_mark_in(str: STRING) is
      do
	 standard_just_before_gc_mark_in(str)
      end

   gc_info_in(str: STRING) is
      do
	 standard_gc_info_in(str)
      end

   gc_define1 is
      do
	 standard_gc_define1
      end

   gc_define2 is
      do
	 standard_gc_define2
      end

feature {RUN_CLASS, TYPE_TUPLE}

   load_basic_features is
      require
	 run_type = Current
      do
	 if not load_basic_features_flag then
	    load_basic_features_flag := True
	    run_class.definitions_for_tuple(run_type, run_type.generic_list)
	 end
      end

feature {TUPLE_EXPRESSION}

   item_name(index: INTEGER): STRING is
	 -- item names for a TUPLE.
      require
	 index_ok: index > 0
      do
         if index = 1 then
            Result := as_first
         elseif index = 2 then
            Result := as_second
         elseif index = 3 then
            Result := as_third
         elseif index = 4 then
            Result := as_fourth
         elseif index = 5 then
            Result := as_fifth
         elseif index > 5 then
            create Result.make(8)
            Result.append(once "item_")
            index.append_in(Result)
	    Result := string_aliaser.item(Result)
         end
      ensure
	 Result = string_aliaser.item(Result)
      end

feature {TYPE_TUPLE_VISITOR}

   accept(visitor: TYPE_TUPLE_VISITOR) is
      do
         visitor.visit_type_tuple(Current)
      end

feature {NONE}

   make(sp: like start_position; gl: like generic_list) is
      require
	 gl /= Void implies (gl.lower = 1 and gl.count > 0)
      local
	 i: INTEGER; t: E_TYPE
      do
	 start_position := sp
	 generic_list := gl
	 base_class_memory := unique_base_class_memory
         create base_class_name.make(as_tuple, start_position)
	 -- Compute `written_runnable_flag':
	 if gl /= Void then
	    from
	       i := gl.upper
	       written_runnable_flag := True
	    until
	       not written_runnable_flag or else i = 0
	    loop
	       t := gl.item(i)
	       if t.is_run_type then
		  if t.run_type /= t then
		     written_runnable_flag := False
		  end
	       else
		  written_runnable_flag := False
	       end
	       i := i - 1
	    end
	 else
	    written_runnable_flag := True
	 end
	 if written_runnable_flag then
	    run_type := Current
	 end
      ensure
	 generic_list = gl
      end

   set(sp: like start_position; gl: like generic_list; rt: like run_type) is
      require
	 gl.lower = 1
	 gl.count > 0
	 rt.written_runnable_flag
      do
	 make(sp, gl)
	 check not written_runnable_flag end
	 run_type := rt
      ensure
	 start_position = sp
	 generic_list = gl
	 run_type = rt
      end
   
   unique_base_class_memory: BASE_CLASS is
      once
         create Result.face_class(as_tuple)
      end

   written_mark_memory: STRING

   load_basic_features_flag: BOOLEAN

end
