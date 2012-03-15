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
class RUN_CLASS
   --
   -- Only for class with objects at execution time.
   --

inherit
   HASHABLE redefine is_equal end
   GLOBALS redefine is_equal end
   VISITABLE redefine is_equal end
   ASSERTION_LEVEL_NUMBERING redefine is_equal end

creation {SMART_EIFFEL} make

feature

   current_type: E_TYPE
         -- The runnable corresponding one.

   run_time_mark: STRING
	 -- Alias the one of `current_type'.

   base_class: BASE_CLASS
         -- Alias the one of `current_type'.

   base_class_name: CLASS_NAME
         -- Alias the one of `base_class'.

   id: INTEGER
         -- Id of the receiver to produce C code.

   at_run_time: BOOLEAN
         -- True if `current_type' is really created (only when direct
	 -- instances of `current_type' exists at run time).

   run_time_set: RUN_TIME_SET
         -- The set of all possible dynamic types (existing types at
         -- run-time, i.e. with a corresponding `at_run_time' object) which
         -- may be actually returned by an expression of the `Current' type.
         -- This set, which is empty at the beginning of the compilation
         -- process will grow, following the `smart_eiffel.status' evolution.
         -- Thus, if the type of `Current' is a reference type, the
	 -- `run_time_set' has only reference run classes elements. If the
	 -- type of `Current' is an expanded type, the `run_time_set' has 
	 -- only `Current' as a single element. Futhermore, the size of the
	 -- `run_time_set' depends on live assignments (as well as argument
	 -- passing and creation statements) that are found in the live code.

   class_invariant: CLASS_INVARIANT
         -- Collected Runnable invariant if any and only is necessary.

   compile_to_c_done: BOOLEAN
         -- True if `compile_to_c' has already be called.

   hash_code: INTEGER
	 -- Actually, in order to speed up the compiler, this is a cache
	 -- for value `run_time_mark'.

   is_equal(other: like Current): BOOLEAN is
      do
	 Result := Current = other
      end

feature {EFFECTIVE_ARG_LIST, RUN_CLASS, RUN_FEATURE}

   scoop_expanded_verified: BOOLEAN
         -- Anti-recursion flag used by `verify_scoop_expanded'

   verify_scoop_expanded(p: POSITION) is
      local
         i: INTEGER; rf: RUN_FEATURE
      do
         scoop_expanded_verified := True
         from
            i := feature_dictionary.upper
         until
            i < feature_dictionary.lower
         loop
            rf := feature_dictionary.item(i)
            if not rf.scoop_expanded_verified then
               rf.verify_scoop_expanded(p)
            end
            i := i - 1
         end
         scoop_expanded_verified := False
      ensure
         scoop_expanded_verified
      end

feature {RUN_CLASS,E_STRIP}

   feature_dictionary: HASHED_DICTIONARY[RUN_FEATURE,FEATURE_NAME]
         -- Access to the runnable version of a feature.

feature {NONE}

   tagged_memory: INTEGER
         -- 0 when not computed, 1 when tagged or -1

   make(t: like current_type; rtm: STRING) is
      require
	 smart_eiffel.status < 3
	 rtm = t.run_time_mark
         t.run_type = t
      local
	 i: INTEGER; gl: ARRAY[E_TYPE]
      do
	 run_time_mark := rtm
	 hash_code := rtm.hash_code
         create feature_dictionary.make
         smart_eiffel.run_class_dictionary.add(Current,rtm)
         compile_to_c_done := True
         current_type := t
         create actual_clients.with_capacity(16)
         base_class := t.base_class
         base_class_name := t.base_class_name
         id := id_provider.item(rtm)
         smart_eiffel.magic_count_increment
	 create run_time_set.make(Current)
         if t.is_expanded then
            set_at_run_time
            base_class.check_expanded_with(t)
         end
	 if t.is_generic then
	    from
	       gl := t.generic_list
	       i := gl.lower
	    until
	       i > gl.upper
	    loop
	       -- To force the creation of the corresponding RUN_CLASS:
	       if gl.item(i).run_class /= Void then end
	       i := i + 1
	    end
	 end
      ensure
         current_type = t
      end

feature

   is_tagged: BOOLEAN is
	 -- Is it a tagged one? In other words, is the `id' field part of the
	 -- object at run time?
      require
         smart_eiffel.is_ready
      do
         if tagged_memory = 0 then
            if current_type.is_expanded then
               tagged_memory := -1
	    elseif current_type.is_separate then
	       tagged_memory := 1
            elseif at_run_time then
               if ace.boost then
                  if smart_eiffel.is_tagged(Current) then
                     tagged_memory := 1
                  else
                     tagged_memory := -1
                  end
               else
                  tagged_memory := 1
               end
            end
         end
         Result := tagged_memory = 1
      ensure
         tagged_memory /= 0
	 Result implies at_run_time
	 Result implies not current_type.is_expanded
      end

   is_expanded: BOOLEAN is
      do
         Result := current_type.is_expanded
      end

   writable_attributes: ARRAY[RUN_FEATURE_2] is
         -- Computed and ordered array of writable attributes. Storage in C
         -- struct is to be done in reverse order (from `upper' to `lower').
         -- Order is done according to the level of attribute definition in
         -- the inheritance graph to allow more stupid switch to be removed.
      require
         smart_eiffel.status.in_range(4,6)
         at_run_time
      local
         rf2: RUN_FEATURE_2; i: INTEGER
      do
         if writable_attributes_mem = Void then
            from
               i := 1
            until
               i > feature_dictionary.count
            loop
               rf2 ?= feature_dictionary.item(i)
               if rf2 /= Void then
                  if writable_attributes_mem = Void then
                     create writable_attributes_mem.with_capacity(4,1)
		  end
		  writable_attributes_mem.add_last(rf2)
               end
               i := i + 1
            end
            if writable_attributes_mem /= Void then
               sort_wam(writable_attributes_mem)
            end
         end
         Result := writable_attributes_mem
      ensure
         Result /= Void implies Result.lower = 1
      end

   c_sizeof: INTEGER is
         -- The C sizeof for an object of this RUN_CLASS on the
         -- current architecture.
      require
         at_run_time
      local
         wa: ARRAY[RUN_FEATURE_2]; a: RUN_FEATURE_2; i: INTEGER
      do
         if is_tagged then
            Result := (i).object_size
         end
         wa := writable_attributes
         if wa /= Void then
            from
               i := wa.upper
            until
               i = 0
            loop
               a := wa.item(i)
               Result := Result + a.result_type.c_sizeof
               i := i - 1
            end
         end
         if Result = 0 then
            Result := 1
         end
      end

feature {TYPE_TUPLE, SMART_EIFFEL}

   definitions_for_tuple(type_tuple: TYPE_TUPLE; types: ARRAY[E_TYPE]) is
	 -- Add extra Eiffel code to handle the TUPLE type.
      require
	 type_tuple = type_tuple.run_type
	 type_tuple.run_time_mark = type_tuple.written_mark
	 types = type_tuple.generic_list
      local
	 count, i: INTEGER; name: STRING; sp: POSITION
	 sfn: FEATURE_NAME; cai: CST_ATT_INTEGER; rf: RUN_FEATURE
      do
	 if not feature_dictionary.has(count_fn) then
	    if types /= Void then
	       count := types.count
	    end
	    -- Adding `count':
	    sp.set_in(type_tuple.base_class)
	    create sfn.simple_feature_name(as_count, sp)
	    !!cai.implicit(type_tuple.base_class, sfn, count)
	    rf := cai.to_run_feature(type_tuple, sfn)
	    -- Adding attributes (read/write):
	    if count >= 1 then
	       tuple_field(type_tuple, as_first, types.item(1), 1)
	    end
	    if count >= 2 then
	       tuple_field(type_tuple, as_second, types.item(2), 2)
	    end
	    if count >= 3 then
	       tuple_field(type_tuple, as_third, types.item(3), 3)
	    end
	    if count >= 4 then
	       tuple_field(type_tuple, as_fourth, types.item(4), 4)
	    end
	    if count >= 5 then
	       tuple_field(type_tuple, as_fifth, types.item(5), 5)
	    end
	    from
	       i := 6
	    until
	       i > count
	    loop
	       create name.make(8)
	       name.copy(once "item_")
	       i.append_in(name)
	       name := string_aliaser.item(name)
	       tuple_field(type_tuple, name, types.item(i), i)
	       i := i + 1
	    end
	 end
      end

feature {NONE}

   tuple_field(type_tuple: E_TYPE; name: STRING; type: E_TYPE; order: INTEGER) is
	 -- Add a new writable attribute supposed to be written in
	 -- `type_tuple'.
      require
	 type_tuple /= Void
	 string_aliaser.item(name) = name
	 type /= Void
      local
	 sp: POSITION; bc: BASE_CLASS; wa: WRITABLE_ATTRIBUTE
	 sfn, set_sfn: FEATURE_NAME; rf2: RUN_FEATURE_2; rf: RUN_FEATURE
	 set_name: STRING; aw: E_PROCEDURE
      do
	 bc := type_tuple.base_class
	 sp.set_in(bc)
	 -- The attribute:
	 create sfn.simple_feature_name(name,sp)
	 check
	    not feature_dictionary.has(sfn)
	 end
	 create wa.implicit(bc,sfn,type)
	 rf2 := wa.to_run_feature(type_tuple,sfn)
         rf2.set_order(order)
	 sfn.set_run_feature_2(rf2)
	 -- The procedure to write the attribute:
	 set_name := once "set_" + name
	 set_name := string_aliaser.item(set_name)
	 create set_sfn.simple_feature_name(set_name,sp)
	 check
	    not feature_dictionary.has(set_sfn)
	 end
	 create aw.attribute_writer(bc,set_sfn,sfn)
	 rf := aw.to_run_feature(type_tuple,set_sfn)
	 check
	    feature_dictionary.has(sfn)
	    feature_dictionary.has(set_sfn)
	 end
      end

feature {E_TYPE}

   jvm_to_reference is
         -- Produce code to convert the pushed expanded into the
         -- corresponding TYPE_REFERENCE type.
      require
         current_type.is_expanded
      local
         ref_type: E_TYPE
      do
         ref_type := current_type.actual_reference(Void)
         ref_type.run_class.jvm_reference_from(current_type)
      end

feature {RUN_CLASS}

   jvm_reference_from(exp_type: E_TYPE) is
      require
         current_type.is_reference and exp_type.is_expanded
      local
         idx: INTEGER; ca: like code_attribute; cp: like constant_pool
      do
         ca := code_attribute
         cp := constant_pool
         idx := jvm_constant_pool_index
         ca.opcode_new(idx)
         ca.opcode_dup
         idx := cp.idx_methodref1(idx,fz_35,fz_29)
         ca.opcode_invokespecial(idx,-1)
         ca.opcode_dup_x1
         ca.opcode_swap
         tmp_string.clear_count
         exp_type.jvm_descriptor_in(tmp_string)
         idx := cp.idx_fieldref3(fully_qualified_name,as_item,tmp_string)
         ca.opcode_putfield(idx,-2)
      end

feature {TYPE_LIKE_FEATURE}

   get_result_type(fn: FEATURE_NAME; ct: E_TYPE): E_TYPE is
         -- Computes only the result type of `fn' when this feature
         -- is not yet runnable.
         -- Possible rename is also done using the `start_position' of
         -- `fn'. No return when an error occurs because `fatal_error'
         -- is called.
      require
         fn /= Void
      local
         fn2: FEATURE_NAME; wbc: BASE_CLASS; rf: RUN_FEATURE
         f: E_FEATURE; bc: BASE_CLASS
      do
         wbc := fn.start_position.base_class
         fn2 := base_class.new_name_of(wbc,fn)
	 rf := feature_dictionary.reference_at(fn2)
         if rf /= Void then
            Result := rf.result_type
            if Result.is_run_type then
               Result := Result.run_type
            else
               Result := Result.to_runnable(current_type)
               Result := Result.run_type
            end
         else
            bc := base_class
            f := bc.look_up_for(Current,fn2)
            if f = Void then
               efnf(bc,fn2)
               error_handler.add_position(fn.start_position)
               error_handler.add_position(fn2.start_position)
               fatal_error(" Anchor not found.")
            else
               Result := f.result_type
               if Result = Void  then
                  error_handler.add_position(f.start_position)
                  error_handler.add_position(fn.start_position)
                  error_handler.add_position(fn2.start_position)
                  fatal_error(" Anchor found is a procedure.")
               else
                  Result := Result.to_runnable(current_type)
                  Result := Result.run_type
               end
            end
         end
      ensure
         Result = Result.run_type
      end

feature

   get_rf_with(fn: FEATURE_NAME): RUN_FEATURE is
         -- Compute or simply fetch the corresponding RUN_FEATURE.
         -- Possible rename are also done using `start_position' of
         -- `fn'. No return when an error occurs because `fatal_error'
         -- is called.
      require
         base_class = fn.start_position.base_class or else
         base_class.is_subclass_of(fn.start_position.base_class)
      local
         fn2: FEATURE_NAME; wbc: BASE_CLASS
      do
         wbc := fn.start_position.base_class
         fn2 := base_class.new_name_of(wbc,fn)
         if fn2 /= fn then
            error_handler.add_position(fn.start_position)
            Result := get_or_fatal_error(fn2)
            error_handler.cancel
         else
            Result := get_or_fatal_error(fn2)
         end
      ensure
         Result /= Void
      end

   dynamic(up_rf: RUN_FEATURE): RUN_FEATURE is
         -- Assume the current type  is a kind of of `up_rf'. 
         -- The result is the concrete one according to dynamic dispatch 
         -- rules.
      require
         up_rf.run_class.run_time_set.has(Current)
      local
         fn: FEATURE_NAME; up_type: E_TYPE; ref_type: TYPE_REFERENCE
      do
         up_type := up_rf.current_type
         if Current = up_type.run_class then
            Result := up_rf
         else
	    ref_type ?= current_type
	    if ref_type /= Void then
	       fn := up_rf.name
	    else
	       fn := base_class.new_name_of(up_type.base_class, up_rf.name)
	    end
            Result := get_or_fatal_error(fn)
         end
      ensure
         Result /= Void
         Result.run_class = Current
      end

feature

   a_default_create: RUN_FEATURE_3 is
	 -- When the corresponding `base_class' has a `default_create' or to 
	 -- get the creation procedure of and expanded class.
      local
	 bc: BASE_CLASS
      do
	 bc := base_class
	 Result := base_class.a_default_create(current_type)
      end

   set_at_run_time is
         -- Set Current `at_run_time' and do needed update of other
         -- instances of RUN_CLASS.
      require
	 not at_run_time implies smart_eiffel.status < 3
      do
         if not at_run_time  then
	    check smart_eiffel.status < 3 end
            at_run_time := True
            if base_class.is_separate then
               smart_eiffel.set_scoop
            end
            compile_to_c_done := False
	    assignment_handler.at_run_time(Current,run_time_set)
            smart_eiffel.magic_count_increment
         end
      ensure
         at_run_time
         run_time_set.has(Current)
      end

feature {E_TYPE}

   gc_mark_to_follow: BOOLEAN is
	 -- *** TO REMOVE ***
      local
         i: INTEGER; rc: like Current
      do
	 from
	    i := run_time_set.count
	 until
	    Result or else i = 0
	 loop
	    rc := run_time_set.item(i)
	    if rc = Current then
	       Result := need_gc_mark
	    else
	       Result := rc.current_type.need_gc_mark_function
	    end
	    i := i - 1
         end
      end

feature {E_TYPE}

   c_print_function is
      require
         ace.no_check
      local
         body: STRING; ct, t: E_TYPE; i: INTEGER
	 wa: like writable_attributes; rf2: RUN_FEATURE_2
      do
         body := c_code_buffer
         body.clear_count
         ct := current_type
         tmp_string.copy(once "void se_prinT")
         id.append_in(tmp_string)
         tmp_string.append(once "(FILE* file,T")
         id.append_in(tmp_string)
         if ct.is_reference then
            tmp_string.extend('*')
         end
         tmp_string.append(once "*o)")
         if ct.is_reference then
            body.append(once "[
               if(*o==NULL){
                  fprintf(file,"Void");
                  return;}

                              ]")
	 end
         body.append(once "fprintf(file,%"")
         body.append(run_time_mark)
         body.append(once "%");%N")
         if ct.is_reference or else ct.is_native_array then
            body.append(once "fprintf(file,%"#%%p%",(void*)*o);%N")
         end
         wa := writable_attributes
         if wa /= Void then
            body.append(once "fprintf(file,%"\n\t[ %");%N")
            from
               i := wa.upper
            until
               i = 0
            loop
               rf2 := wa.item(i)
               t := rf2.result_type
               body.append(once "fprintf(file,%"")
               body.append(rf2.name.to_string)
               body.append(once " = %");%Nse_prinT")
               if t.is_expanded then
                  t.id.append_in(body)
		  body.append(once "(file,")
              elseif t.is_string then
		  body.append(once "7(file,(EIF_STRING*)")
               else
		  body.append(once "0(file,(T0**)")
               end
               body.append(once "(&((*o)")
               if ct.is_separate and then not ct.base_class.is_separate then
                  body.append(once "->ref->")
               elseif ct.is_reference then
                  body.append(once "->")
               else
                  body.extend('.')
               end
               body.extend('_')
               body.append(rf2.name.to_string)
               body.append(once ")));%N")
               i := i - 1
               if i > 0 then
                  body.append(once "fprintf(file,%"\n\t  %");%N")
               end
            end
            body.append(once "fprintf(file,%"\n\t]%");%N")
         end
         cpp.put_c_function(tmp_string,body)
      end

   c_object_model_in(str: STRING) is
      local
         wa: like writable_attributes; i: INTEGER; rf2: RUN_FEATURE_2
         t: E_TYPE; sep: BOOLEAN
      do
         wa := writable_attributes
         sep := smart_eiffel.scoop and then base_class.is_separate
         if wa = Void then
            if is_tagged then
               str.extend('{')
               id.append_in(str)
               if sep then
                  str.extend(',')
                  str.append(fz_null)
               end
               str.extend('}')
            elseif sep then
               str.extend('{')
               str.append(fz_null)
               str.extend('}')
            else
               current_type.c_initialize_in(str)
            end
         else
            str.extend('{')
            if is_tagged then
               id.append_in(str)
               str.extend(',')
            end
            if sep then
               str.append(fz_null)
               str.extend(',')
            end
            from
               i := wa.upper
            until
               i = 0
            loop
               rf2 := wa.item(i)
               t := rf2.result_type
               t.c_initialize_in(str)
               i := i - 1
               if i > 0 then
                  str.extend(',')
               end
            end
            str.extend('}')
         end
      end

feature {SMART_EIFFEL}

   falling_down is
         -- Falling down of Current `feature_dictionary' in `run_time_set'.
      local
         rf: RUN_FEATURE; i: INTEGER; rf2: RUN_FEATURE_2; rc: RUN_CLASS
      do
         from
            i := 1
         until
            i > feature_dictionary.count
         loop
            rf := feature_dictionary.item(i)
            rf.fall_down
	    rf2 ?= rf
	    if rf2 /= Void then
	       rc := rf2.result_type.run_class
	       if deep_twin_flag then
		  rc.set_deep_twin_flag
	       end
	       if is_deep_equal_flag then
		  rc.set_is_deep_equal_flag
	       end
	    end
            i := i + 1
         end
         gc_handler.falling_down(Current)
         runnable_class_invariant
	 if deep_twin_flag then
	    if current_type.is_native_array then
	       rf := get_feature_with(as_deep_twin_from)
	    else
	       rf := get_feature_with(as_deep_twin)
	       switch_collection.update_with(rf)
	    end
	 end
	 if is_deep_equal_flag then
	    if current_type.is_native_array then
	       rf := get_feature_with(as_deep_memcmp)
	    else
	       rf := get_feature_with(as_is_deep_equal)
	       switch_collection.update_with(rf)
	    end
	 end
      end

   afd_check is
         -- After Falling Down Check.
      local
         rf: RUN_FEATURE; i: INTEGER; rc: like Current; rt: E_TYPE
      do
         from
            i := 1
         until
            i > feature_dictionary.count
         loop
            rf := feature_dictionary.item(i)
            rf.afd_check
            rt := rf.result_type
            if rt /= Void then
               if rt.is_none then
               else
                  rc := rt.run_class
               end
            end
            i := i + 1
         end
         if class_invariant /= Void then
            class_invariant.afd_check
         end
      end

   safety_check is
      require
	 for_boost_mode_only_or_asked_for: ace.boost or else ace.safety_check
      local
         rf: RUN_FEATURE; i: INTEGER; c: COMPOUND
      do
         from
            i := 1
         until
            i > feature_dictionary.count
         loop
            rf := feature_dictionary.item(i)
            c := rf.routine_body
	    if c /= Void then
	       c.safety_check
	    end
            i := i + 1
         end
      end

   simplify_2 is
      require
	 not smart_eiffel.pretty_flag
	 not smart_eiffel.short_flag
	 smart_eiffel.status >= 4
      local
         rf: RUN_FEATURE; i: INTEGER
      do
         from
            i := 1
         until
            i > feature_dictionary.count
         loop
            rf := feature_dictionary.item(i)
	    rf.simplify_2
            i := i + 1
         end
      end

feature {CLASS_CHECKER}

   runnable_class_invariant is
      local
	 ct: like current_type
      do
         if not runnable_class_invariant_done then
            runnable_class_invariant_done := True
	    ct := current_type
            if ((ct.base_class.invariant_check and then at_run_time)
		or else
		smart_eiffel.short_flag)
	     then
	       assertion_collector.invariant_start
	       base_class.collect_invariant(Current)
	       class_invariant := assertion_collector.invariant_end(ct)
	    end
         end
      end

feature

   c_header_pass1 is
      require
         cpp.on_h
      do
         if at_run_time then
            if c_header_pass_level_done < 1 then
               current_type.c_header_pass1
               c_header_pass_level_done := 1
            end
         end
      ensure
         cpp.on_h
      end

   c_header_pass2 is
      require
         cpp.on_h
      do
         if at_run_time then
            if c_header_pass_level_done < 2 then
               current_type.c_header_pass2
               c_header_pass_level_done := 2
            end
         end
      ensure
         cpp.on_h
      end

   c_header_pass3 is
      require
         cpp.on_h
      local
         i: INTEGER
         attribute_type: E_TYPE
      do
         if at_run_time then
            if c_header_pass_level_done < 3 then
               if current_type.is_user_expanded and then
                  writable_attributes /= Void
                then
                  from
                     i := writable_attributes.upper
                  until
                     i = 0
                  loop
                     attribute_type := writable_attributes.item(i).result_type
                     if attribute_type.is_expanded then
                        attribute_type.run_class.c_header_pass3
                     end
                     i := i - 1
                  end
               end
               current_type.c_header_pass3
               c_header_pass_level_done := 3
            end
         end
      ensure
         cpp.on_h
      end

   c_header_pass4 is
      require
         cpp.on_h
      do
         if at_run_time then
            if c_header_pass_level_done < 4 then
               current_type.c_header_pass4
               c_header_pass_level_done := 4
            end
         end
      ensure
         cpp.on_h
      end

feature {GC_HANDLER}

   get_memory_dispose: RUN_FEATURE_3 is
      local
         memory, bc: BASE_CLASS
      do
         memory := smart_eiffel.memory_class_used
         if memory /= Void then
            bc := base_class
            if memory /= bc and then bc.is_subclass_of(memory) then
               if bc.has_simple_feature_name(as_dispose) then
                  Result ?= get_feature_with(as_dispose)
                  if Result /= Void then
                     Result := Result.memory_dispose
                 end
               end
            end
         end
      end

   gc_define1 is
      require
         not gc_handler.is_off
      do
         if at_run_time then
	    cpp.next_bunch_size(1)
            current_type.gc_define1
         end
      end

   gc_define2 is
      require
         not gc_handler.is_off
      do
         if at_run_time then
	    cpp.next_bunch_size(4)
            current_type.gc_define2
         end
      end

   gc_info_in(str: STRING) is
         -- Produce C code to print GC information.
      require
         not gc_handler.is_off
         gc_handler.info_flag
      do
         if at_run_time then
            current_type.gc_info_in(str)
         end
      end

   just_before_gc_mark_in(body: STRING) is
      require
         not gc_handler.is_off
      do
         if at_run_time then
            current_type.just_before_gc_mark_in(body)
         end
      end

feature {E_TYPE}

   gc_mark_fixed_size(is_unmarked: BOOLEAN; body: STRING) is
         -- The main purpose is to compute for example the best body for
         -- the corresponding gc_markXXX function (as well as
         -- gc_align_markXXX). In fact, this feature can be called to
         -- produce C code when C variable `o' is not NULL and when `o' is of
         -- some concrete type (Tid*) where `id' is the one of the current
         -- RUN_CLASS. -- Finally, when `is_unmarked' is True, object `o' is
         -- unmarked.
      require
         not gc_handler.is_off
         not current_type.is_native_array
         at_run_time
      local
         rf2: RUN_FEATURE_2; t: E_TYPE; rc: RUN_CLASS; i: INTEGER
      do
         wa_buf.clear
         wa_cyclic_buf.clear
         if writable_attributes /= Void then
            from
               i := writable_attributes.upper
            until
               i = 0
            loop
               rf2 := writable_attributes.item(i)
               t := rf2.result_type
               if t.need_gc_mark_function then
                  rc :=  t.run_class
                  wa_cycle.clear
                  wa_cycle.add_last(rf2)
                  if rc.is_wa_cycle(Current) then
                     wa_cyclic_buf.add_last(rf2)
                  else
                     wa_buf.add_last(rf2)
                  end
               end
               i := i - 1
            end
         end
         if wa_buf.is_empty and then wa_cyclic_buf.is_empty then
            gc_set_fsoh_marked_in(body)
         else
            if wa_cyclic_buf.upper >= 0 then
               body.append(once "begin:%N")
            end
            if not is_unmarked then
               body.append(
                  once "if(((gc")
               id.append_in(body)
               body.append(
                  once "*)o)->header.flag==FSOH_UNMARKED){%N")
            end
            gc_set_fsoh_marked_in(body)
            from -- Ordinary attributes :
               i := wa_buf.upper
            until
               i < 0
            loop
               rf2 := wa_buf.item(i)
               mark_attribute(body,rf2)
               i := i - 1
            end
            from -- Cyclic attributes :
               i := wa_cyclic_buf.upper
            until
               i < 0
            loop
               rf2 := wa_cyclic_buf.item(i)
               t := rf2.result_type
               rc :=  t.run_class
               wa_cycle.clear
               wa_cycle.add_last(rf2)
               if rc.is_wa_cycle(Current) then
               end
               if i = 0 and then
                  wa_cycle.count = 1 and then
                  rc.run_time_set.count = 1 and then
                  rc.run_time_set.item(1) = Current
                then
                  body.append(once "o=(void*)o->_")
                  body.append(rf2.name.to_string)
                  body.append(once ";%Nif((o!=NULL)")
                  if is_unmarked then
                     body.append(once "&&(((gc")
                     id.append_in(body)
                     body.append(
                        once "*)o)->header.flag==FSOH_UNMARKED))")
                  else
                     body.extend(')')
                  end
                  body.append(once "goto begin;%N")
               else
                  mark_attribute(body,rf2)
               end
               i := i - 1
            end
            if not is_unmarked then
               body.extend('}')
            end
         end
      end

feature {E_TYPE}

   gc_align_mark_fixed_size(body: STRING) is
         -- Compute the best body for gc_align_markXXX of
         -- a fixed_size object.
      require
         not gc_handler.is_off
         not current_type.is_native_array
         at_run_time
      do
         body.append(fz_gc)
         id.append_in(body)
         body.append(once "*b=((gc")
         id.append_in(body)
	 body.append(
            once "*)(&(c->first_object)));%N%
            %if((c->header.state_type==FSO_STORE_CHUNK)%
            %&&(((char*)p)>=((char*)store")
         id.append_in(body)
         body.append(
            once ")))return;%N%
            %if(((char*)p)>((char*)(b+(c->count_minus_one))))return;%N%
            %if(((char*)p)<((char*)b))return;%N%
            %if(((((char*)p)-((char*)b))%%sizeof(*p))==0){%N%
            %if(p->header.flag==FSOH_UNMARKED){%N%
            %T")
         id.append_in(body)
         body.append(once "*o=(&(p->object));%N")
         gc_mark_fixed_size(True,body)
         body.append(once "}%N}%N")
      end

feature

   has_feature(n: STRING): BOOLEAN is
      require
	 exists:  n /= Void and then (not n.is_empty)
	 aliased: n = string_aliaser.item(n)
      local
	 sfn: FEATURE_NAME
      do
	 create sfn.unknown_position(n) -- leaky...
	 Result := feature_dictionary.has(sfn)
      end
   
   at(fn: FEATURE_NAME): RUN_FEATURE is
         -- Simple read acces into the `feature_dictionary' using `fn' as 
         -- the final name to know if this one is already computed.
      require
         fn /= Void
      do
	 Result := feature_dictionary.reference_at(fn)
      end

   get_feature_with(n: STRING): RUN_FEATURE is
         -- Assume that `n' is really the final name in current RUN_CLASS.
	 -- Retrieve or compute the corresponding one.
      require
         exists:  n /= Void and then (not n.is_empty)
	 aliased: n = string_aliaser.item(n)
      local
	 sfn: FEATURE_NAME
      do
	 create sfn.unknown_position(n)
	 Result := feature_dictionary.reference_at(sfn)
         if Result = Void then
            Result := get_feature(sfn)
         end
      end

   get_copy: RUN_FEATURE is
      do
         Result := get_rf_with(class_general.get_copy.first_name)
      end

   get_feature(fn: FEATURE_NAME): RUN_FEATURE is
         -- Assume that `fn' is really the final name in current
         -- RUN_CLASS. Don't look for rename.
      require
         fn /= Void
      local
         f: E_FEATURE; bc: BASE_CLASS
      do
	 Result := feature_dictionary.reference_at(fn)
         if Result = Void then
            check
               smart_eiffel.status < 3
            end
            bc := base_class
            f := bc.look_up_for(Current,fn)
            if f = Void then
               efnf(bc,fn)
            else
	       Result := feature_dictionary.reference_at(fn)
	       if Result = Void then
		  Result := f.to_run_feature(current_type,fn)
		  if Result = Void  then
		     efnf(bc,fn)
		  else
		     check
			feature_dictionary.has(Result.name)
		     end
		  end
	       end
            end
         end
      end

   fully_qualified_name: STRING is
	 -- For the corresponding Java class file.
      do
         if fully_qualified_name_memory = Void then
            fully_qualified_name_memory2.copy(ace.executable_name)
            fully_qualified_name_memory2.extend('/')
            fully_qualified_name_memory2.append(unqualified_name)
            !!fully_qualified_name_memory.copy(fully_qualified_name_memory2)
         end
         Result := fully_qualified_name_memory
      end

feature {JVM}

   jvm_define_class_invariant is
         -- If needed, call the invariant for the pushed value.
      local
         ci: like class_invariant
      do
	 ci := class_invariant
	 if ci /= Void then
	    jvm.define_class_invariant_method(ci)
         end
      end

feature {JVM,E_TYPE,RUN_FEATURE}

   jvm_check_class_invariant is
         -- If needed, call the invariant for the stack-top object.
         -- If invariant is correct, the same stack-top object is left
         -- on the stack.
      local
         ci: like class_invariant
         idx: INTEGER
         ca: like code_attribute
         cp: like constant_pool
      do
	 ci := class_invariant
	 if ci /= Void then
	    ca := code_attribute
	    cp := constant_pool
	    ca.opcode_dup
	    opcode_checkcast
	    idx := cp.idx_methodref3(fully_qualified_name,fz_invariant,
				     fz_29)
	    ca.opcode_invokevirtual(idx,-1)
	 end
      end

feature {JVM,RUN_FEATURE}

   jvm_check_class_invariant_1 is
      -- Call the invariant for the stack-top object.
      local
         ia: like class_invariant
         idx: INTEGER
         ca: like code_attribute
         cp: like constant_pool
         skip_invariant: INTEGER
      do
         if base_class.assertion_level >= level_invariant then
            ia := class_invariant
            if ia /= Void then
               ca := code_attribute
               cp := constant_pool
               ca.opcode_aload_0
               idx := cp.idx_fieldref3(fully_qualified_name,
				       once "invariant_flag",
				       fz_i)
               ca.opcode_getfield( idx, -1 )
               skip_invariant := ca.opcode_ifne
               ca.opcode_aload_0
               opcode_checkcast
               idx := cp.idx_methodref3(fully_qualified_name,fz_invariant,
					fz_29)
               ca.opcode_invokevirtual(idx,-1)
               ca.resolve_u2_branch(skip_invariant)
            end
         end
      end

   invariant_flag: BOOLEAN

   set_invariant_flag is
      do
         invariant_flag := True
      end

feature {SMART_EIFFEL}

   compile_to_jvm is
      require
         at_run_time
      local
         i: INTEGER; rf: RUN_FEATURE; type_reference: TYPE_REFERENCE
      do
         echo.put_character('%T')
         echo.put_string(run_time_mark)
         echo.put_character('%N')
         jvm.start_new_class(Current)
         from
            i := 1
         until
            i > feature_dictionary.count
         loop
            rf := feature_dictionary.item(i)
            jvm.set_current_frame(rf)
            rf.jvm_field_or_method
            i := i + 1
         end
         type_reference ?= current_type
         if type_reference = Void then
            jvm.prepare_fields
         else
            type_reference.jvm_prepare_item_field
         end
         jvm.prepare_methods
         jvm.finish_class
      end

feature {E_TYPE}

   jvm_type_descriptor_in(str: STRING) is
         -- Append in `str' the appropriate JVM type descriptor.
      require
         at_run_time
         run_time_set.has(Current)
      do
         check
            current_type.is_user_expanded
         end
         str.extend('L')
         str.append(fully_qualified_name)
         str.extend(';')
      end

feature {RUN_FEATURE}

   jvm_invoke(idx, stack_level: INTEGER) is
      local
         ct: like current_type
      do
         ct := current_type
         inspect
            ct.jvm_method_flags
         when 17 then
            code_attribute.opcode_invokevirtual(idx,stack_level)
         when 9 then
            code_attribute.opcode_invokestatic(idx,stack_level)
         end
      end

feature

   jvm_basic_new is
         -- Poduce bytecode to push a new created object with the
         -- basic default value (the corresponding creation procedure
         -- if any is not called).
      local
         i, idx: INTEGER; wa: ARRAY[RUN_FEATURE_2]; rf2: RUN_FEATURE_2
         t2: E_TYPE; ca: like code_attribute; cp: like constant_pool
      do
         ca := code_attribute
         cp := constant_pool
         idx := jvm_constant_pool_index
         ca.opcode_new(idx)
         ca.opcode_dup
      	 idx := cp.idx_methodref1(idx,fz_35,fz_29)
         ca.opcode_invokespecial(idx,-1)
         wa := writable_attributes
         if wa /= Void then
            from
               i := wa.upper
            until
               i = 0
            loop
               rf2 := wa.item(i)
               t2 := rf2.result_type.run_type
               if t2.is_user_expanded then
                  ca.opcode_dup
                  t2.run_class.jvm_expanded_push_default
                  idx := cp.idx_fieldref(rf2)
                  ca.opcode_putfield(idx,-2)
               elseif t2.is_bit then
                  ca.opcode_dup
                  idx := t2.jvm_push_default
                  idx := cp.idx_fieldref(rf2)
                  ca.opcode_putfield(idx,-2)
               end
               i := i - 1
            end
         end
      end

feature {E_TYPE, RUN_CLASS, NATIVE_SMART_EIFFEL}

   jvm_expanded_push_default is
         -- Push the corresponding new user's expanded (either dummy
         -- or not, initializer is automatically applied).
      require
         current_type.is_user_expanded
      local
         rf: RUN_FEATURE
      do
         jvm_basic_new
         rf := a_default_create
         if rf /= Void then
            jvm.push_expanded_initialize(rf)
            rf.mapping_jvm
            jvm.pop
         end
      end

feature {NATIVE_SMART_EIFFEL}

   deep_twin_in(body: STRING) is
      require
	 at_run_time
      local
	 i: INTEGER; wa: ARRAY[RUN_FEATURE_2]; rf2: RUN_FEATURE_2
	 t: E_TYPE; name: STRING; rts: RUN_TIME_SET
      do
	 if current_type.is_reference then
	    body.append(once "R=se_deep_twin_search((void*)C);%N%
			%if(R == NULL){%N")
	    current_type.c_type_for_target_in(body)
	    body.extend(' ')
	    gc_handler.allocation_in(once "new",body,Current)
	    body.append(once "R=((T0*)new);%N%
			%*new=*C;%N%
			%se_deep_twin_register(((T0*)C),((T0*)new));%N")
         else
	    body.append(once "se_deep_twin_start();%N%
			%R=*C;%N{")
	    current_type.c_type_for_target_in(body)
	    body.append(once " new=&(R);%N")
	 end
         wa := writable_attributes
         if wa /= Void then
            from
               i := wa.upper
            until
               i = 0
            loop
               rf2 := wa.item(i)
	       name := rf2.name.to_string
               t := rf2.result_type.run_type
	       if t.is_reference then
		  rts := t.run_class.run_time_set
		  if rts.count > 0 then
		     body.append(once "if(new->_")
		     body.append(name)
		     body.append(once "!=NULL){%N%
				      %new->_")
		     body.append(name)
		     body.extend('=')
		     rts := t.run_class.run_time_set
		     if rts.count > 1 then
			body.extend('X')
			rts.owner.id.append_in(body)
		     else
			body.extend('r')
			rts.first.id.append_in(body)
		     end
		     body.append(once "deep_twin(")
		     if ace.no_check then
			body.append(fz_85)
			if rts.count > 1 then
			   body.append(fz_98)
			end
		     end
		     if rts.count = 1 then
			body.extend('(')
			rts.first.current_type.c_type_for_target_in(body)
			body.extend(')')
		     end
		     body.append(once "(new->_")
		     body.append(name)
		     body.append(once "));%N}%N")
		  end
	       elseif t.is_native_array then
		  if get_feature_with(as_capacity) = Void then
		     error_handler.add_type(t,fz_dtideena)
		     error_handler.print_as_error
		     error_handler.add_position(rf2.start_position)
		     error_handler.append(em1)
		     error_handler.print_as_fatal_error
		  end
		  body.append(once "new->_")
		  body.append(name)
		  body.append(once "=r")
		  t.id.append_in(body)
		  body.append(once "deep_twin_from(")
		  if ace.no_check then
		     body.append(fz_85)
		  end
		  body.append(once "new->_")
		  body.append(name)
		  body.append(once ",new->_capacity);%N")
	       elseif t.is_dummy_expanded then
	       elseif t.is_user_expanded then
		  body.append(once "new->_")
		  body.append(name)
		  body.append(once "=r")
		  t.id.append_in(body)
		  body.append(once "deep_twin(")
		  if ace.no_check then
		     body.append(fz_85)
		  end
		  body.append(once "&(new->_")
		  body.append(name)
		  body.append(fz_16)
	       else
		  check t.is_basic_eiffel_expanded end
	       end
               i := i - 1
            end
         end
	 if current_type.is_user_expanded then
	    body.append(once "se_deep_twin_trats(NULL);%N")
	 end
	 body.extend('}')
	 body.extend('%N')
      end

   is_deep_equal_in(body: STRING) is
      local
	 i: INTEGER; wa: ARRAY[RUN_FEATURE_2]; rf2: RUN_FEATURE_2
	 ct, t: E_TYPE; name: STRING; check_type: BOOLEAN
	 rts: RUN_TIME_SET
      do
	 ct := current_type
	 body.append(once "se_deep_equal_start();%N")
	 if ct.is_reference then
	    check_type := ct.run_class.is_tagged
	    if check_type then
	       body.append(once "R=(C->id==a1->id);%N%
			   %if(R){%N")
	    end
	    body.append(once "R=se_deep_equal_search(C,a1);%N")
	 end
	 body.append(once "if(!R){%N")
	 ct.c_type_for_target_in(body)
	 body.append(once "a1ptr=")
	 if ct.is_reference then
	    body.append(once "((void*)a1);%N")
	 else
	    body.append(once "((void*)(&a1));%N")
	 end
	 body.append(fz_92)
         wa := writable_attributes
         if wa /= Void then
            from
               i := wa.upper
            until
               i = 0
            loop
               rf2 := wa.item(i)
	       name := rf2.name.to_string
               t := rf2.result_type.run_type
	       if t.is_basic_eiffel_expanded then
		  body.append(once "if(R)R=((C->_")
		  body.append(name)
		  body.append(once ")==(a1ptr->_")
		  body.append(name)
		  body.append(fz_16)
               end
               i := i - 1
            end
            from
               i := wa.upper
            until
               i = 0
            loop
               rf2 := wa.item(i)
	       name := rf2.name.to_string
               t := rf2.result_type.run_type
	       if t.is_reference then
		  rts := t.run_class.run_time_set
		  if rts.count > 0 then
		     body.append(once "if(R){%NT0*o1=C->_")
		     body.append(name)
		     body.append(once ";%NT0*o2=a1ptr->_")
		     body.append(name)
		     body.append(once ";%Nif(o1==o2){}%N%
				   %else if(o1==NULL){R=0;}%N%
				   %else if(o2==NULL){R=0;}%N%
				   %else {R=")
		     if rts.count = 1 then
			t := rts.first.current_type
			body.extend('r')
		     else
			body.extend('X')
		     end
		     t.id.append_in(body)
		     body.append(once "is_deep_equal(")
		     if ace.no_check then
			body.append(fz_85)
			if rts.count > 1 then body.append(fz_98) end
		     end
		     if rts.count = 1 then
			body.extend('(')
			t.c_type_for_target_in(body)
			body.extend(')')
		     end
		     body.append(once "o1,o2);}%N}%N")
	          end
	       elseif t.is_native_array then
		  if get_feature_with(as_capacity) = Void then
		     error_handler.add_type(t,fz_dtideena)
		     error_handler.print_as_error
		     error_handler.add_position(rf2.start_position)
		     error_handler.append(em1)
		     error_handler.print_as_fatal_error
	          end
		  body.append(fz_93)
		  t.id.append_in(body)
		  body.append(once "deep_memcmp(")
		  if ace.no_check then
		     body.append(fz_85)
		  end
		  body.append(fz_95)
		  body.append(name)
		  body.append(once ",a1ptr->_")
		  body.append(name)
		  body.append(once ",C->_capacity);%N")
	       elseif t.is_dummy_expanded then
	       elseif t.is_user_expanded then
		  body.append(fz_93)
		  t.id.append_in(body)
		  body.append(once "is_deep_equal(")
		  if ace.no_check then
		     body.append(fz_85)
		  end
		  body.append(once "&(C->_")
		  body.append(name)
		  body.append(once "),a1ptr->_")
		  body.append(name)
		  body.append(fz_14)
               else
               end
               i := i - 1
            end
         end
	 if check_type then body.append(fz_12) end
	 body.append(once "}%Nse_deep_equal_trats();%N")
      end

feature {JVM}

   unqualified_name: STRING is
         -- Also used for the corresponding file name.
      do
         unqualified_name_memory.copy(run_time_mark)
         unqualified_name_memory.to_lower
         unqualified_name_memory.replace_all('[','O')
         unqualified_name_memory.replace_all(']','F')
         unqualified_name_memory.replace_all(' ','_')
         unqualified_name_memory.replace_all(',','_')
         Result := unqualified_name_memory
      end

feature

   jvm_constant_pool_index: INTEGER is
         -- The fully qualified index in the constant pool.
      do
         Result := constant_pool.idx_class2(fully_qualified_name)
      end

feature {SMART_EIFFEL}

   id_extra_information(tfw: TEXT_FILE_WRITE) is
      local
         ct: E_TYPE
      do
         ct := current_type
         tfw.put_string(once "c-type: T")
         tfw.put_integer(id)
         tfw.put_character(' ')
         ct.id_extra_information(tfw)
	 if ct.is_reference then
            tfw.put_string(once "ref-status: ")
	    if at_run_time then
               tfw.put_string(once "live id-field: ")
	       if ct.is_reference and then not is_tagged then
                  tfw.put_string(once "no ")
               else
                  tfw.put_string(once "yes ")
               end
            else
               tfw.put_string(once "dead ")
	    end
	    tfw.put_character('%N')
	    run_time_set.id_extra_information(tfw)
         end
      end

   prepare_introspection is
      require
         ace.no_check
         cpp.on_c
      local
         i: INTEGER; code: STRING; again: BOOLEAN
         rf: RUN_FEATURE; ct, t: E_TYPE
         rf2: RUN_FEATURE_2; rf6: RUN_FEATURE_6
         s: STRING
      do
         if at_run_time then
            ct := current_type
            cpp.next_bunch_size(1)
            code := once "                "
            code.copy(once "void* se_introspecT")
            id.append_in(code)
            code.append(once "(T")
            ct.id.append_in(code)
	    if ct.is_reference then
	       code.extend('*')
	    end
            code.append(once "*C,char*attr,int*id,int*exp)")
            cpp.put_c_heading(code)
            cpp.put_string(once "void*R=NULL;%N")

            if ct.is_native_array then
               -- NATIVE_ARRAY: support access to an element
               check
                  ct.is_generic
                  ct.generic_list.count = 1
               end
               t := ct.generic_list.first
               s := "                "
               s.clear_count
               t.c_type_for_result_in(s)
               cpp.put_string(once "*id=")
               cpp.put_integer(t.id)
               if t.is_expanded then
                  cpp.put_string(once ";%N*exp=1;%N")
               else
                  cpp.put_string(once ";%N*exp=0;%N")
               end
               cpp.put_string(once "R=(*((")
               cpp.put_string(s)
               cpp.put_string(once "**)C)+atoi(attr));%N")
            else
               -- General case: support access to attributes
               cpp.put_string(once "*id=-1;%N")
               from
                  again := False
                  i := 1
               until
                  i > feature_dictionary.count
               loop
                  rf := feature_dictionary.item(i)
                  rf2 ?= rf
                  if rf2 /= Void then
                     if again then
                        cpp.put_string(once "else ")
                     else
                        again := True
                     end
                     rf2.prepare_introspection
                  else
                     rf6 ?= rf
                     if rf6 /= Void then
                        if again then
                           cpp.put_string(once "else ")
                        else
                           again := True
                        end
                        rf6.prepare_introspection
                     end
                  end
                  i := i + 1
               end
            end
            cpp.put_string(once "return R;%N}%N")
         end
      end

   prepare_introspection2 is
      require
         ace.no_check
         cpp.on_c
      local
         i: INTEGER; again: BOOLEAN
         rf: RUN_FEATURE; ct: E_TYPE
         rf2: RUN_FEATURE_2; rf6: RUN_FEATURE_6
      do
         if at_run_time then
            ct := current_type
            cpp.put_string(once "se_atT[")
            cpp.put_integer(ct.id)
            cpp.put_string(once "]=")
            from
               again := False
               i := 1
            until
               i > feature_dictionary.count
            loop
               rf := feature_dictionary.item(i)
               rf2 ?= rf
               rf6 ?= rf
               if rf2 /= Void or else rf6 /= Void then
                  if again then
                     cpp.put_string(once ", ")
                  else
                     cpp.put_character('"')
                     again := True
                  end
                  cpp.put_string(rf.name.to_string)
               end
               i := i + 1
            end
            if not again then
               cpp.put_string(once "NULL")
            else
               cpp.put_character('"')
            end
            cpp.put_string(once ";%N")
         end
      end

feature {RUN_FEATURE_2, RUN_FEATURE_6}

   c_return_introspect(rf: RUN_FEATURE) is
      require
         ace.no_check
         rf /= Void
      local
         i, t: INTEGER; rts: like run_time_set; type: E_TYPE; s: STRING
         rf2: RUN_FEATURE_2; rf6: RUN_FEATURE_6
      do
         rf2 ?= rf
         rf6 ?= rf
         check
            (rf2 /= Void) /= (rf6 /= Void)
         end
         rts := run_time_set
         inspect rts.count
         when 0 then
            -- nothing
         when 1 then
            type := rts.first.current_type
            s := c_pointer_to_type(type)
            t := type.id
            if type.is_expanded then
               cpp.put_string(once "*exp=1;%N")
            else
               cpp.put_string(once "*exp=0;%N")
            end
            cpp.put_string(once "*id=")
            cpp.put_integer(t)
            cpp.put_string(once ";%N{%Nstatic ")
            cpp.put_string(s)
            cpp.put_string(once " _r=")
            type.c_initialize
            cpp.put_string(once ";%N_r=(")
            cpp.put_string(s)
            cpp.put_string(once ")(")
            if rf2 /= Void then
               rf2.mapping_c
            else
               once_routine_pool.c_put_o_result(rf6)
            end
            cpp.put_string(once ");%NR=&_r;%N}%N")
         else
            check is_tagged end
            cpp.put_string(once "{%Nstatic T0*_r=NULL;%N_r=")
            if rf2 /= Void then
               rf2.mapping_c
            else
               once_routine_pool.c_put_o_result(rf6)
            end
            cpp.put_string(once ";%Nswitch(_r->id) {%N")
            from
               i := 1
            until
               i > rts.count
            loop
               t := rts.item(i).current_type.id
               cpp.put_string(once "case ")
               cpp.put_integer(t)
               cpp.put_string(once ":%N")
               i := i + 1
            end
            cpp.put_string(once "*id=_r->id;R=&_r;break;%Ndefault:break;%N}%N}%N")
         end
      end

feature {NONE}

   c_pointer_to_type(t: E_TYPE): STRING is
      do
         Result := once "                "
         Result.copy(once "T")
         t.id.append_in(Result)
         if t.is_reference then
            Result.extend('*')
         end
      end

feature {SMART_EIFFEL,RUN_CLASS}

   compile_to_c(deep: INTEGER) is
         -- Produce C code for features of Current. The `deep'
         -- indicator is used to sort the C output in the best order
         -- (more C  inlinings are possible when basic functions are
         -- produced first). As there is not always a total order
         -- between clients, the `deep' avoid infinite track.
         -- When `deep' is greater than 0, C code writting
         -- is produced whatever the real client relation is.
      require
         cpp.on_c
         deep >= 0
      local
         i: INTEGER; rc1, rc2: like Current; cc1, cc2: INTEGER
      do
         if compile_to_c_done then
         elseif not at_run_time then
            compile_to_c_done := True
         elseif deep = 0 then
            really_compile_to_c
         else
            i := actual_clients.upper
            if i >= 0 then
               from
                  rc1 := Current
                  cc1 := i + 1
               until
                  i = 0
               loop
                  rc2 := actual_clients.item(i)
                  if not rc2.compile_to_c_done then
                     cc2 := rc2.actual_clients.count
                     if cc2 > cc1 then
                        rc1 := rc2
                        cc1 := cc2
                     end
                  end
                  i := i - 1
               end
               if rc1 = Current then
                  really_compile_to_c
               else
                  rc1.compile_to_c(deep - 1)
               end
            end
         end
      ensure
         cpp.on_c
      end

feature {RUN_CLASS}

   actual_clients: FAST_ARRAY[RUN_CLASS]

feature {CREATE_TOOLS,RUN_FEATURE}

   add_client(rc: RUN_CLASS) is
      require
         rc /= Void
      local
         i: INTEGER
      do
         i := actual_clients.fast_index_of(rc)
         if i > actual_clients.upper then
            actual_clients.add_last(rc)
         end
      end

feature

   offset_of(rf2: RUN_FEATURE_2): INTEGER is
         -- Compute the displacement to access `rf2' in the corresponding
         -- C struct to remove a possible stupid switch.
         -- Result is in number of bytes.
      require
         at_run_time
         writable_attributes.fast_has(rf2)
         smart_eiffel.is_ready
      local
         wa: like writable_attributes; t: E_TYPE; i: INTEGER
      do
         if is_tagged then
            Result := (1).object_size
         end
         from
            wa := writable_attributes
            i := wa.upper
         invariant
            i > 0
         until
            wa.item(i) = rf2
         loop
            t := wa.item(i).result_type
            Result := Result + t.c_sizeof
            i := i - 1
         end
      end

feature

   wa_buf: FAST_ARRAY[RUN_FEATURE_2] is
      once
         !!Result.with_capacity(24)
      end

   wa_cyclic_buf: FAST_ARRAY[RUN_FEATURE_2] is
      once
         !!Result.with_capacity(24)
      end

feature {RUN_CLASS, RUN_FEATURE_8}

   set_deep_twin_flag is
      local
	 i: INTEGER; rc: RUN_CLASS
      do
	 if not deep_twin_flag then
	    smart_eiffel.magic_count_increment
	    deep_twin_flag := True
	    smart_eiffel.set_deep_twin_used
	 end
	 from
	    i := run_time_set.count
	 until
	    i = 0
	 loop
	    rc := run_time_set.item(i)
	    if not rc.deep_twin_flag then
	       rc.set_deep_twin_flag
	    end
	    i := i - 1
	 end
      end

   set_is_deep_equal_flag is
      local
	 i: INTEGER; rc: RUN_CLASS
      do
	 if not is_deep_equal_flag then
	    smart_eiffel.magic_count_increment
	    is_deep_equal_flag := True
	    smart_eiffel.set_deep_twin_used
	 end
	 from
	    i := run_time_set.count
	 until
	    i = 0
	 loop
	    rc := run_time_set.item(i)
	    if not rc.is_deep_equal_flag then
	       rc.set_is_deep_equal_flag
	    end
	    i := i - 1
	 end
      end

feature {RUN_CLASS}

   deep_twin_flag: BOOLEAN
	 -- True if the `deep_twin' support is necessary.

   is_deep_equal_flag: BOOLEAN
	 -- True if the `is_deep_equal' support is necessary.

   is_wa_cycle(origin: like Current): BOOLEAN is
      do
         if Current = origin then
            Result := True
         end
      end

feature -- Some useful JVM opcode:


   opcode_checkcast_1 is
         -- Produces a `checkcast' opcode
      local
         ct: E_TYPE
         idx: INTEGER
      do
         ct := current_type
         idx := jvm_constant_pool_index
         code_attribute.opcode_checkcast(idx)
      end

   opcode_checkcast is
         -- May produce a `checkcast' opcode depending on
         -- `current_type' Java byte-code mapping.
      local
         ct: E_TYPE
         idx: INTEGER
      do
         ct := current_type
         if ct.is_basic_eiffel_expanded then
         elseif ct.is_native_array then
            tmp_string.clear_count
            ct.jvm_target_descriptor_in(tmp_string)
            idx := constant_pool.idx_class2(tmp_string)
            code_attribute.opcode_checkcast(idx)
         elseif ct.is_bit then
         else
            idx := jvm_constant_pool_index
            code_attribute.opcode_checkcast(idx)
         end
      end

   opcode_instanceof is
      require
         not current_type.is_basic_eiffel_expanded
      local
         idx: INTEGER
      do
         idx := jvm_constant_pool_index
         code_attribute.opcode_instanceof(idx)
      end

   opcode_getfield(rf2: RUN_FEATURE_2): INTEGER is
         -- Produce a `checkcast'/`getfield' for the given
         -- attribute of the top object of the stack.
         -- stack: ... object => ... value
      local
         idx: INTEGER
      do
         opcode_checkcast
         idx := constant_pool.idx_fieldref(rf2)
         Result := rf2.result_type.jvm_stack_space - 1
         code_attribute.opcode_getfield(idx,Result)
      end

feature {RUN_FEATURE}

   get_default_rescue(n: FEATURE_NAME): COMPOUND is
      local
         a_rescue: RUN_FEATURE_3; target: IMPLICIT_CURRENT
         call_to_default_rescue: PROC_CALL_0
      do
         a_rescue := base_class.get_default_rescue(Current, n)
         if a_rescue /= Void then
            !!target.make(n.start_position)
            !!call_to_default_rescue.make(target,a_rescue.name)
            !!Result.make(Void,call_to_default_rescue,Void)
         end
      end

   add_run_feature(rf: RUN_FEATURE; fn: FEATURE_NAME) is
      require
	 rf.run_class = Current; rf.name = fn
      do
         check
            not feature_dictionary.has(fn)
         end
         feature_dictionary.add(rf,fn)
      end

feature {ASSIGNMENT_HANDLER}

   shared_attributes(other: RUN_CLASS) is
      local
         rf2: RUN_FEATURE_2; i: INTEGER
      do
         from
            i := 1
         until
            i > feature_dictionary.count
         loop
            rf2 ?= feature_dictionary.item(i)
            if rf2 /= Void then
               rf2 ?= other.get_feature(rf2.name)
            end
            i := i + 1
         end
      end

feature {CREATE_EXPRESSION}

   create_function_register(rf: RUN_FEATURE) is
	 -- Register that there is a live create expression using `rf'
	 -- as the creation procedure.
      do
	 if create_function_list = Void then
	    create create_function_list.with_capacity(4)
	 end
	 if rf /= Void then
	    if not create_function_list.fast_has(rf) then
	       create_function_list.add_last(rf)
	    end
	 end
      end

feature {RUN_CLASS_VISITOR}

   accept(visitor: RUN_CLASS_VISITOR) is
      do
         visitor.visit_run_class(Current)
      end

feature {PROC_CALL_1, CALL_1_C}

   agent_feature_for(toa: TYPE_OF_AGENT; fn: FEATURE_NAME): RUN_FEATURE is
      require
	 toa.run_class = Current
      do
	 Result := feature_dictionary.reference_at(fn)
	 if Result = Void then
	    toa.load_builtin_features
	    Result := feature_dictionary.reference_at(fn)
	 end
	 if Result = Void then
	    error_handler.add_position(fn.start_position)
	    error_handler.append("There is no such feature in class ")
	    error_handler.append(toa.base_class.name.to_string)
	    error_handler.append(". (Feature %"call%" is available for all %
				 %agents and feature %"item%" is available %
				 %only for FUNCTION or PREDICATE.)")
	    error_handler.print_as_fatal_error
	 end
      ensure
	 Result /= Void
      end
   
feature {NONE}

   create_function_list: FAST_ARRAY[RUN_FEATURE]

   create_function_define(rf: RUN_FEATURE) is
      require
	 cpp.on_c
      local
	 boost: BOOLEAN; header, body: STRING; args: FORMAL_ARG_LIST
         need_se_tmp: BOOLEAN
      do
	 boost := ace.boost
	 header := c_code_buffer
	 header.clear_count
	 if current_type.is_reference then
	    current_type.c_type_for_target_in(header)
	 else
	    current_type.c_type_for_result_in(header)
	    header.extend(' ')
	 end
	 header.append(fz_create)
	 id.append_in(header)
	 if rf /= Void then
	    header.append(rf.name.to_string)
	 end
	 header.extend('(')
	 if rf /= Void then
	    args := rf.arguments
	 end
	 if boost then
	    if args /= Void then
	       args.compile_to_c_in(header)
	    else
	       header.append(once "void")
	    end
	 else
	    header.append(once "se_dump_stack*caller")
	    if args /= Void then
	       header.extend(',')
	       args.compile_to_c_in(header)
	    end
	 end
	 header.extend(')')
	 cpp.put_c_heading(header)
	 --
	 body := c_code_buffer
	 body.clear_count
	 if current_type.is_reference then
	    current_type.c_type_for_target_in(body)
	 else
	    current_type.c_type_for_argument_in(header)
	 end
	 body.append(once " n;%N")
	 cpp.put_string(body)
         if not boost then
            cpp.put_string(once "se_frame_descriptor fd=%
			   %{%"create expression wrapper%",0,0,%"%",1};%N%
		           %se_dump_stack ds;%N%
			   %ds.fd=&fd;%Nds.p=0;%N%
                           %ds.caller=caller;%N%
                           %ds.exception_origin=NULL;%N%
                           %ds.locals=NULL;%N")
         end
	 if current_type.is_reference then
	    gc_handler.allocation_of(once "n",Current)
	 else
	    cpp.put_string(once "n=M")
	    cpp.put_integer(id)
	    cpp.put_string(once ";%N")
	 end
	 if rf /= Void then
	    cpp.push_create_expression(rf)
            rf.collect_c_tmp
            need_se_tmp := cpp.se_tmp_open_declaration
	    rf.mapping_c
            if need_se_tmp then
               cpp.se_tmp_close_declaration
            end
	    cpp.pop
	 end
	 cpp.put_string(once "return n;%N}%N")
      end

   mark_attribute(body: STRING; rf2: RUN_FEATURE_2) is
      do
         tmp_string.copy(once "o->_")
         tmp_string.append(rf2.name.to_string)
         tmp_string.append(fz_open_c_comment)
         offset_of(rf2).append_in(tmp_string)
         tmp_string.append(fz_close_c_comment)
         gc_handler.mark_for(body,tmp_string,rf2.result_type.run_class)
      end

   gc_set_fsoh_marked_in(body: STRING) is
      do
         if current_type.is_reference then
            body.append(once "((gc")
            id.append_in(body)
            body.append(once "*)o)->header.flag=FSOH_MARKED;%N")
         end
      end

   need_gc_mark: BOOLEAN is
      require
         at_run_time
      local
         i: INTEGER; wa: like writable_attributes; rf2: RUN_FEATURE_2; t: E_TYPE
      do
         wa := writable_attributes
         if wa /= Void then
            from
               i := wa.upper
            until
               Result or else i = 0
            loop
               rf2 := wa.item(i)
               t := rf2.result_type
               Result := t.need_gc_mark_function
               i := i - 1
            end
         end
      end

   wa_cycle: FAST_ARRAY[RUN_FEATURE_2] is
      once
         create Result.with_capacity(24)
      end

   tmp_string: STRING is
      once
         create Result.make(32)
      end

   c_code_buffer: STRING is
      once
         create Result.make(256)
      end

   efnf(bc: BASE_CLASS; fn: FEATURE_NAME) is
      require
         bc /= Void
         fn /= Void
      do
         error_handler.append(once "Current type is ")
         error_handler.append(run_time_mark)
         error_handler.append(once ". There is no feature ")
	 error_handler.add_feature_name(fn)
         error_handler.append(once " in class ")
         error_handler.append(bc.name.to_string)
         error(fn.start_position,fz_dot_blank)
      end

   sort_wam(wam: like writable_attributes) is
         -- Sort `wam' to common attribute at the end.
      require
         wam.lower = 1
      local
         min, max, buble: INTEGER
         moved: BOOLEAN
      do
         from
            max := wam.upper
            min := 1
            moved := True
         until
            not moved
         loop
            moved := False
            if max - min > 0 then
               from
                  buble := min + 1
               until
                  buble > max
               loop
                  if gt(wam.item(buble - 1),wam.item(buble)) then
                     wam.swap(buble - 1,buble)
                     moved := True
                  end
                  buble := buble + 1
               end
               max := max - 1
            end
            if moved and then max - min > 0 then
               from
                  moved := False
                  buble := max - 1
               until
                  buble < min
               loop
                  if gt(wam.item(buble),wam.item(buble + 1)) then
                     wam.swap(buble,buble + 1)
                     moved := True
                  end
                  buble := buble - 1
               end
               min := min + 1
            end
         end
      end

   gt(rf1, rf2: RUN_FEATURE_2): BOOLEAN is
         -- True if it is better to set attribute `rf1' before attribute 
         -- `rf2'.
      local
         bc1, bc2: BASE_CLASS; bf1, bf2: E_FEATURE; bcn1, bcn2: CLASS_NAME
      do
         if rf1.order /= rf2.order then
            Result := rf1.order < rf2.order
         else
            bf1 := rf1.base_feature
            bf2 := rf2.base_feature
            bc1 := bf1.base_class
            bc2 := bf2.base_class
            bcn1 := bc1.name
            bcn2 := bc2.name
            if bcn1.to_string = bcn2.to_string then
               Result := bf1.start_position.before(bf2.start_position)
            elseif bcn2.is_subclass_of(bcn1) then
               Result := True
            elseif bcn1.is_subclass_of(bcn2) then
            elseif bc1.parent_list = Void then
               if bc2.parent_list = Void then
                  Result := bcn1.to_string < bcn2.to_string
               else
                  Result := True
               end
            elseif bc2.parent_list = Void then
            else
               Result := bc2.parent_list.count < bc1.parent_list.count
            end
         end
      end

   writable_attributes_mem: like writable_attributes

   really_compile_to_c is
      require
         at_run_time
	 current_type.is_separate implies smart_eiffel.scoop
      local
         bunch_size, assertion_level, i: INTEGER; rf: RUN_FEATURE
      do
         compile_to_c_done := True
	 bunch_size := feature_dictionary.count
	 assertion_level := base_class.assertion_level
	 if assertion_level < level_require then
	 elseif assertion_level < level_ensure then
	    bunch_size := bunch_size + bunch_size // 4
	 elseif assertion_level = level_ensure then
	    bunch_size := bunch_size + bunch_size // 3
	 end
	 if assertion_level >= level_invariant then
	    if class_invariant /= Void then
	       bunch_size := bunch_size + 2
	    end
	 end
	 cpp.next_bunch_size(bunch_size)
	 if create_function_list /= Void then
	    if create_function_list.is_empty then
	       create_function_define(Void)
	    else
	       from
		  i := create_function_list.upper
	       until
		  i < 0
	       loop
		  rf := create_function_list.item(i)
		  create_function_define(rf)
		  i := i - 1
	       end
	    end
	 end
         echo.put_character('%T')
         echo.put_string(run_time_mark)
         echo.put_string(once " (")
	 echo.put_integer(feature_dictionary.count)
         echo.put_string(once " features).%N")
         from
            i := 1
         until
            i > feature_dictionary.count
         loop
            rf := feature_dictionary.item(i)
            rf.c_define_or_scoop_define
            i := i + 1
         end
	 if class_invariant /= Void then
	    class_invariant.c_define
         end
      ensure
         compile_to_c_done
      end

   unqualified_name_memory: STRING is
      once
         create Result.make(32)
      end

   fully_qualified_name_memory: STRING

   fully_qualified_name_memory2: STRING is
      once
         create Result.make(256)
      end

   get_or_fatal_error(fn: FEATURE_NAME): RUN_FEATURE is
      do
         Result := get_feature(fn)
         if Result = Void then
            error_handler.add_position(fn.start_position)
            error_handler.append(once "Feature ")
            error_handler.append(fn.to_string)
            error_handler.append(
                once " not found when starting look up from ")
            error_handler.add_type(current_type,fz_dot_blank)
            error_handler.print_as_fatal_error
         end
      end

   runnable_class_invariant_done: BOOLEAN

   count_fn: FEATURE_NAME is
      once
	 create Result.unknown_position(as_count)
      end

   c_header_pass_level_done: INTEGER

   em1: STRING is
      "The `deep_twin'/`is_deep_equal' problem comes from this attribute."

invariant

   current_type.run_type = current_type

   base_class = current_type.base_class

   base_class_name = current_type.base_class_name

end -- RUN_CLASS
