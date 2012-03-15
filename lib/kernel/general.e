-- This  file  is  free software,  which comes along with SmartEiffel.  This
-- software is distributed in the hope that it will be useful,  but  WITHOUT
-- ANY  WARRANTY;  without  even the  implied warranty of MERCHANTABILITY or
-- FITNESS FOR A PARTICULAR PURPOSE. You can modify it as you want, provided
-- this header is kept unaltered, and a notification of the changes is added.
-- You  are  allowed  to  redistribute it and sell it, alone or as a part of
-- another product.
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
class GENERAL
   --
   -- Platform-independent universal properties.
   -- This class is an ancestor to all developer-written classes.
   --

feature -- Access:

   generating_type: STRING is
         -- Name of current object's generating type (type of
         -- which it is a direct instance).
      external "SmartEiffel"
      end

   generator: STRING is
         -- Name of current object's generating class (base class
         -- of the type of which it is a direct instance).
      external "SmartEiffel"
      end

   stripped(other: GENERAL): like other is
 	 -- Newly created object with fields copied from current object,
 	 -- but limited to attributes of type of `other'.
      require
         conformance: conforms_to(other)
      do
         not_yet_implemented
      ensure
         stripped_to_other: Result.same_dynamic_type(other)
      end

feature -- Status report:

   frozen conforms_to(other: GENERAL): BOOLEAN is
         -- Is dynamic type of `Current' a descendant of dynamic type of
         -- `other' ?
         --
         -- Note: because of automatic conversion from expanded to reference
         -- type when passing argument `other', do not expect a correct
         -- behavior with  expanded types.
      require
         not is_expanded_type
         other_not_void: other /= Void
      do
         Result := other.se_assigned_from(Current)
      end

   frozen same_dynamic_type(other: like Current): BOOLEAN is
         -- Is the dynamic type of `Current' identical to the dynamic type 
         -- of `other'?
      external "SmartEiffel"
      end

   frozen same_type(other: GENERAL): BOOLEAN is
         -- Is type of current object identical to type of `other' ?
      obsolete "Now use `same_dynamic_type' instead (14 feb 2003)."
      require
         not is_expanded_type
         other_not_void: other /= Void
      do
         if conforms_to(other) then
            Result := other.conforms_to(Current)
         end
      ensure
         definition: Result = (conforms_to(other)
                               and
                               other.conforms_to(Current))
      end

feature -- Comparison:

   frozen equal(some: ANY; other: like some): BOOLEAN is
         -- Are `some' and `other' both Void or attached to objects 
         -- considered equal ?
      local
--	 some_ref_integer, other_ref_integer: reference INTEGER_64
      do
         if some = other then
            Result := True
         elseif some = Void then
         elseif other = Void then
         else
-- I'm not sure why INTEGER_64s were special cases here. But they shouldn't (dmoisset, July 22nd 2005)
--	    some_ref_integer ?= some
--	    if some_ref_integer /= Void then
--	       other_ref_integer ?= other
--	       if other_ref_integer /= Void then
--		  Result := some_ref_integer.item = other_ref_integer.item
--	       end
--	    else
            Result := some.is_equal(other)
--	    end
         end
      ensure
         symmetric: Result implies equal(other, some)
      end

   is_equal(other: like Current): BOOLEAN is
         -- Is `other' attached to an object considered equal to
         -- current object ?
      require
         other /= Void
      external "SmartEiffel"
      ensure
         generating_type = other.generating_type implies
	    (Result = other.is_equal(Current))
      end

   frozen standard_equal(some: ANY; other: like some): BOOLEAN is
         -- Are `some' and `other' both Void or attached to
         -- field-by-field objects of the same type ?
         -- Always use the default object comparison criterion.
      do
         if some = other then
            Result := True
         elseif some = Void then
         elseif other = Void then
         elseif some.same_dynamic_type(other) then
            Result := some.standard_is_equal(other)
         end
      ensure
         definition: Result = (some = Void and other = Void) or else
                     ((some /= Void and other /= Void) and then
                      some.standard_is_equal(other))
      end

   frozen standard_is_equal(other: like Current): BOOLEAN is
         -- Are Current and `other' field-by-field identical?
      require
         other /= Void
      external "SmartEiffel"
      ensure
         same_dynamic_type(other) implies
	    (Result = other.standard_is_equal(Current))
      end

feature -- Deep Comparison:

   frozen deep_equal(some: ANY; other: like some): BOOLEAN is
         -- Are `some' and `other' either both Void or attached to
         -- recursively isomorphic object structures ?
      do
         if some = other then
            Result := True
         elseif some = Void then
         elseif other = Void then
         else
            Result := some.is_deep_equal(other)
         end
      ensure
         shallow_implies_deep: standard_equal(some,other) implies Result
      end

   is_deep_equal(other: like Current): BOOLEAN is
         -- Is `Current' recursively isomorph with `other' ?
      require
         other_not_void: other /= Void
      external "SmartEiffel"
      end

feature -- Duplication:

   frozen clone(other: ANY): like other is
         -- When argument `other' is Void, return Void otherwise 
         -- return `other.twin'.
      do
         if other /= Void then
            Result := other.twin
         end
      ensure
         equal: equal(Result,other)
      end

   frozen twin: like Current is
         -- Return a new object with the dynamic type of Current.
         -- Before being returned, the new object is initialized using
         -- feature `copy' (Current is passed as the argument).
         -- Thus, when feature `copy' of GENERAL is not redefined,
         -- `twin' has exactly the same behaviour as `standard_twin'.
      external "SmartEiffel"
      ensure
         equal: Result.is_equal(Current)
      end

   copy(other: like Current) is
         -- Update current object using fields of object attached
         -- to `other', so as to yield equal objects.
	 -- Note: you can't copy object from a different dynamic type.
      require
	 same_dynamic_type(other)
      external "SmartEiffel"
      ensure
         is_equal(other)
      end

   frozen standard_clone(other: ANY): like other is
         -- Void if `other' is Void; otherwise new object
         -- field-by-field identical to `other'.
         -- Always use the default copying semantics.
      do
         if other /= Void then
            Result := other.standard_twin
         end
      ensure
         equal: standard_equal(Result,other)
      end

   frozen standard_twin: like Current is
         -- Return a new object with the dynamic type of Current.
         -- Before being returned, the new object is initialized using
         -- feature `standard_copy' (Current is passed as the argument).
      external "SmartEiffel"
      end

   frozen standard_copy(other: like Current) is
         -- Copy every field of `other' onto corresponding field of
         -- current object.
      require
         other_not_void: other /= Void
      external "SmartEiffel"
      ensure
         standard_is_equal(other)
      end

   frozen box: REFERENCE [like Current] is
          -- Create a REFERENCe object referring to Current 
      do
          create Result
          Result.set_item (Current)
      end

feature -- Deep Duplication:

   frozen deep_clone(other: ANY): like other is
         -- When argument `other' is Void, return Void
         -- otherwise return `other.deep_twin'.
      do
	 if other /= Void then
	    Result := other.deep_twin
	 end
      ensure
	 deep_equal(other,Result)
      end

   deep_twin: like Current is
         -- Return a new object with the dynamic type of Current.
         -- The new object structure is recursively duplicated from the one
         -- attached to `Current'.
      external "SmartEiffel"
      end

feature -- Basic operations:

   frozen default: like Current is
         -- Default value of entities declared with the `Current' type.
	 -- Hence, the `Result' is Void for all reference types and, as another 
	 -- example, the `Result' is 0 for an INTEGER expression.
      do
      end

   is_default: BOOLEAN is
	 -- Is the `Current' object in the `default' state?
	 -- For example, when this feature is applied on an INTEGER, the 
	 -- `Result' is True only when the INTEGER is 0.  If not redefined, the 
	 -- `Result' is always False for a reference expression. Actually, this 
	 -- `is_default' predicate may be useful for user-defined expanded 
	 -- objects stored in collection (see `all_default' of class 
	 -- COLLECTION).
      do
	 Result := Current = default
      end
   
   frozen default_pointer: POINTER is
         -- Default value of type POINTER (avoid the need to write p.default 
         -- for some `p' of type POINTER).
      do
      ensure
         Result = Result.default
      end

   default_rescue is
         -- Handle exception if no Rescue clause. (Default: do nothing.)
      do
      end

   frozen do_nothing is
         -- Execute a null action.
      do
      end

feature -- Input and Output:

   io: STD_INPUT_OUTPUT is
         -- Handle to standard file setup.
         -- To use the standard input/output file.
         -- Has type STD_FILES in ELKS 95.
      once
         create Result.make
      ensure
         Result /= Void
      end

   std_input: STD_INPUT is
         -- To use the standard input file.
      once
         create Result.make
      end

   std_output: STD_OUTPUT is
         -- To use the standard output file.
      once
         create Result.make
      end

   std_error: STD_ERROR is
         -- To use the standard error file.
      once
         create Result.make
      end

feature -- Object Printing:

   frozen print(some: GENERAL) is
         -- Write terse external representation of `some' on
         -- `standard_output'.
         -- To customize printing, one may redefine
         -- `fill_tagged_out_memory' or `out_in_tagged_out_memory' (see
         -- for example how it works in class COLLECTION).
 	 -- Not frozen in ELKS 95.
      do
         if some = Void then
            std_output.put_string(once "Void")
         else
            some.print_on(std_output)
         end
      end

   print_on(file: OUTPUT_STREAM) is
         -- Default printing of current object on a `file'.
         -- One may redefine `fill_tagged_out_memory' or
         -- `out_in_tagged_out_memory' to adapt the behavior of
         -- `print_on'.
         --
      do
         tagged_out_memory.clear_count
         out_in_tagged_out_memory
         file.put_string(tagged_out_memory)
      end

   frozen tagged_out: STRING is
         -- New string containing printable representation of current
         -- object, each field preceded by its attribute name, a
         -- colon and a space.
      do
         tagged_out_memory.clear_count
         fill_tagged_out_memory
         Result := tagged_out_memory.twin
      end

   out: STRING is
         -- Create a new string containing terse printable
         -- representation of current object.
      do
         tagged_out_memory.clear_count
         out_in_tagged_out_memory
         Result := tagged_out_memory.twin
      end

   out_in_tagged_out_memory is
         -- Append terse printable represention of current object
         -- in `tagged_out_memory'.
      do
         tagged_out_memory.append(generating_type)
         if not is_expanded_type then
            tagged_out_memory.extend('#')
            Current.to_pointer.append_in(tagged_out_memory)
         end
         tagged_out_memory.extend('[')
         fill_tagged_out_memory
         tagged_out_memory.extend(']')
      ensure
         not_cleared: tagged_out_memory.count >= old tagged_out_memory.count
         append_only: (old (tagged_out_memory.twin)).is_equal(tagged_out_memory.substring(1, old tagged_out_memory.count))
      end

   frozen tagged_out_memory: STRING is
      once
         create Result.make(1024)
      end

   fill_tagged_out_memory is
         -- Append a viewable information in `tagged_out_memory' in
         -- order to affect the behavior of `out', `tagged_out', etc.
      do
         -- Should be an external "SmartEiffel" to provide a default
         -- view of Current contents (not yet implemented).
      end

feature -- Basic named file handling:

   frozen file_tools: FILE_TOOLS is
      obsolete "This feature will be removed, use a local `file_tools' feature."
      once
      end

   file_exists(path: STRING): BOOLEAN is
         -- True if `path' is an existing readable file.
      obsolete
         "This feature will be removed, use a local `file_tools'.is_readable feature."
      require
         not path.is_empty
      local
         ftools: FILE_TOOLS
      do
         Result := ftools.is_readable(path)
      end

   remove_file(path: STRING) is
      obsolete
         "This feature will be removed, use a local `file_tools'.delete feature."
      require
         path /= Void
      local
         ftools: FILE_TOOLS
      do
         ftools.delete(path)
      end

   rename_file(old_path, new_path: STRING) is
      obsolete
         "This feature will be removed, use a local `file_tools'.rename_to feature."
      require
         old_path /= Void
         new_path /= Void
      local
         ftools: FILE_TOOLS
      do
         ftools.rename_to(old_path,new_path)
      end

feature -- Access to command-line arguments:

   argument_count: INTEGER is
         -- Number of arguments given to command that started
         -- system execution (command name does not count).
      do
         Result := command_arguments.upper
      ensure
         Result >= 0
      end

   argument(i: INTEGER): STRING is
         -- `i' th argument of command that started system execution
         -- Gives the command name if `i' is 0.
      require
         i >= 0
         i <= argument_count
      do
         Result := command_arguments.item(i)
      ensure
         Result /= Void
      end

   frozen command_arguments: FAST_ARRAY[STRING] is
         -- Give acces to arguments command line including the
         -- command name at index 0.
      local
         i: INTEGER
         arg: STRING
      once
         from
            i := se_argc
            create Result.make(i)
         until
            i = 0
         loop
            i := i - 1
            arg := se_argv(i)
            Result.put(arg,i)
         end
      ensure
         not Result.is_empty
      end

   get_environment_variable(name: STRING): STRING is
      obsolete "Since release -0.74 you have to use feature `get_environment_variable' %
               %of class SYSTEM."
      local
         s: SYSTEM
      do
         Result := s.get_environment_variable(name)
      end

feature -- SCOOP:

   available: BOOLEAN is
         -- Wait the result (By Necessity [TM])
         -- Always return True
         -- (Meaningless in a non-SCOOP world)
      do
         Result := True
      end

feature -- System calls and crashs:

   frozen crash is
         -- Print Run Time Stack and then exit with `exit_failure_code'.
      do
         print_all_run_time_stacks
	 sedb_breakpoint
         die_with_code(exit_failure_code)
      end

   frozen trace_switch(flag: BOOLEAN) is
         -- May be used in combination with option "-sedb" of command
         -- `compile_to_c' (see compile_to_c documentation for details).
      external "SmartEiffel"
      end

   frozen sedb_breakpoint is
         -- May be used in combination with option "-sedb" of command
         -- `compile_to_c' to set a breakpoint for sedb, the SmartEiffel debugger.
      external "SmartEiffel"
      end

   frozen system(system_command_line: STRING) is
         -- To execute a `system_command_line' as for example, "ls -l" on UNIX.
      obsolete "Since release -0.74 you have to use feature `execute' %
               %of class SYSTEM."
      local
         s: SYSTEM
      do
         s.execute_command_line(system_command_line)
      end

   frozen die_with_code(code:INTEGER) is
         -- Terminate execution with exit status code `code'.
         -- Do not print any message.
         -- Note: you can use predefined `exit_success_code' or
         -- `exit_failure_code' as well as another code you need.
      external "SmartEiffel"
      end

   exit_success_code: INTEGER is 0

   exit_failure_code: INTEGER is 1

feature -- Maths constants:

   Pi    : DOUBLE is
      obsolete "Use same feature in class MATH_CONSTANTS (Nov. 2002)."
      do
	 Result := 3.1415926535897932384626
      end

   Evalue: DOUBLE is
      obsolete "Use same feature in class MATH_CONSTANTS (Nov. 2002)."
      do
	 Result :=   2.7182818284590452353602
      end

   Deg   : DOUBLE is 
      obsolete "Use same feature in class MATH_CONSTANTS (Nov. 2002)."
      do
	 Result := 57.2957795130823208767981; -- Degrees/Radian
      end
   
   Phi   : DOUBLE is  
      obsolete "Use same feature in class MATH_CONSTANTS (Nov. 2002)."
      do
	 Result := 1.6180339887498948482045; -- Golden Ratio
      end
   
feature -- Character names:
   
   Ctrl_a: CHARACTER is 
      obsolete "Use same feature in class CHARACTER_CONSTANT (Nov. 2002)."
      do
	 Result := '%/1/'
      end
   Ctrl_b: CHARACTER is 
      obsolete "Use same feature in class CHARACTER_CONSTANT (Nov. 2002)."
      do
	 Result := '%/2/'
      end
   Ctrl_c: CHARACTER is 
      obsolete "Use same feature in class CHARACTER_CONSTANT (Nov. 2002)."
      do
	 Result := '%/3/'
      end
   Ctrl_d: CHARACTER is  
      obsolete "Use same feature in class CHARACTER_CONSTANT (Nov. 2002)."
      do
	 Result := '%/4/'
      end
   Ctrl_e: CHARACTER is  
      obsolete "Use same feature in class CHARACTER_CONSTANT (Nov. 2002)."
      do
	 Result :='%/5/'
      end
   Ctrl_f: CHARACTER is 
      obsolete "Use same feature in class CHARACTER_CONSTANT (Nov. 2002)."
      do
	 Result := '%/6/'
      end
   Ctrl_g: CHARACTER is 
      obsolete "Use same feature in class CHARACTER_CONSTANT (Nov. 2002)."
      do
	 Result := '%/7/'
      end
   Ch_bs : CHARACTER is 
      obsolete "Use same feature in class CHARACTER_CONSTANT (Nov. 2002)."
      do
	 Result := '%/8/'
      end
   Ch_tab: CHARACTER is 
      obsolete "Use same feature in class CHARACTER_CONSTANT (Nov. 2002)."
      do
	 Result := '%/9/'
      end
   Ctrl_j: CHARACTER is 
      obsolete "Use same feature in class CHARACTER_CONSTANT (Nov. 2002)."
      do
	 Result := '%/10/'
      end
   Ctrl_k: CHARACTER is 
      obsolete "Use same feature in class CHARACTER_CONSTANT (Nov. 2002)."
      do
	 Result := '%/11/'
      end
   Ctrl_l: CHARACTER is 
      obsolete "Use same feature in class CHARACTER_CONSTANT (Nov. 2002)."
      do
	 Result := '%/12/'
      end
   Ctrl_m: CHARACTER is 
      obsolete "Use same feature in class CHARACTER_CONSTANT (Nov. 2002)."
      do
	 Result := '%/13/'
      end
   Ctrl_n: CHARACTER is 
      obsolete "Use same feature in class CHARACTER_CONSTANT (Nov. 2002)."
      do
	 Result := '%/14/'
      end
   Ctrl_o: CHARACTER is 
      obsolete "Use same feature in class CHARACTER_CONSTANT (Nov. 2002)."
      do
	 Result := '%/15/'
      end
   Ctrl_p: CHARACTER is 
      obsolete "Use same feature in class CHARACTER_CONSTANT (Nov. 2002)."
      do
	 Result := '%/16/'
      end
   Ctrl_q: CHARACTER is 
      obsolete "Use same feature in class CHARACTER_CONSTANT (Nov. 2002)."
      do
	 Result := '%/17/'
      end
   Ctrl_r: CHARACTER is 
      obsolete "Use same feature in class CHARACTER_CONSTANT (Nov. 2002)."
      do
	 Result := '%/18/'
      end
   Ctrl_s: CHARACTER is 
      obsolete "Use same feature in class CHARACTER_CONSTANT (Nov. 2002)."
      do
	 Result := '%/19/'
      end
   Ctrl_t: CHARACTER is 
      obsolete "Use same feature in class CHARACTER_CONSTANT (Nov. 2002)."
      do
	 Result := '%/20/'
      end
   Ctrl_u: CHARACTER is 
      obsolete "Use same feature in class CHARACTER_CONSTANT (Nov. 2002)."
      do
	 Result := '%/21/'
      end
   Ctrl_v: CHARACTER is 
      obsolete "Use same feature in class CHARACTER_CONSTANT (Nov. 2002)."
      do
	 Result := '%/22/'
      end
   Ctrl_w: CHARACTER is
      obsolete "Use same feature in class CHARACTER_CONSTANT (Nov. 2002)."
      do
	 Result := '%/23/'
      end
   Ctrl_x: CHARACTER is
      obsolete "Use same feature in class CHARACTER_CONSTANT (Nov. 2002)."
      do
	 Result := '%/24/'
      end
   Ctrl_y: CHARACTER is
      obsolete "Use same feature in class CHARACTER_CONSTANT (Nov. 2002)."
      do
	 Result := '%/25/'
      end
   Ctrl_z: CHARACTER is
      obsolete "Use same feature in class CHARACTER_CONSTANT (Nov. 2002)."
      do
	 Result := '%/26/'
      end
   Ch_del: CHARACTER is
      obsolete "Use same feature in class CHARACTER_CONSTANT (Nov. 2002)."
      do
	 Result := '%/63/'
      end

feature -- Should not exist:

   not_yet_implemented is
      do
	 sedb_breakpoint
         std_error.put_string("[
            Sorry, some feature is not yet implemented (i.e. feature
            `not_yet_implemented' of class GENERAL has been called somewhere). If
            this is not the case, just run this code under the debugger to
            know the `not_yet_implemented' caller. If this is a feature of the
            SmartEiffel library, you may consider to post your
            implementation on the SmartEiffel mailing list.
                                           e-mail: smarteiffel@except.com.ar
                                          Happy debug and thanks in advance.
                               http://opensvn.csie.org/traccgi/smarteiffel12
                                                            Daniel F Moisset

            ]")
         crash
       end

feature -- For ELS Compatibility:

   id_object(id: INTEGER): ANY is
         -- Object for which `object_id' has returned `id'
         -- Void if none.
      require
         id /= 0
      do
         Result := object_id_memory.item(id)
      end

   object_id: INTEGER is
         -- Value identifying current reference object.
      require
         not is_expanded_type
      do
         Result := object_id_memory.fast_index_of(Current)
         if Result > object_id_memory.upper then
            object_id_memory.add_last(Current)
         end
      end

feature -- The Guru section:

   to_pointer: POINTER is
	 -- This routine can be used only if the value of `Current' is really
	 -- a memory address. (This is the case for all reference types and
	 -- for the NATIVE_ARRAY type only.) Actually, this routine do
	 -- nothing: the value of `Current' which is an address is returned
	 -- unchanged. The compiler will emit a warning if you try to use
	 -- `to_pointer' on some invalid type.
      external "SmartEiffel"
      end

   frozen is_expanded_type: BOOLEAN is
         -- Target is not evaluated (Statically computed).
         -- Result is True if target static type is an expanded type.
         -- Useful for formal generic type.
      external "SmartEiffel"
      end

   frozen is_basic_expanded_type: BOOLEAN is
         -- Target is not evaluated (Statically computed).
         -- Result is True if target static type is one of the
         -- following types: BOOLEAN, CHARACTER, INTEGER, REAL,
         -- DOUBLE or POINTER.
      external "SmartEiffel"
      ensure
         Result implies is_expanded_type
      end

   frozen object_size: INTEGER is
         -- Gives the size of the current object at first level
         -- only (pointed-to sub-object are not concerned).
         -- The result is given in number of CHARACTER.
      external "SmartEiffel"
      end

feature {NONE} -- The Guru section:

   c_inline_h(c_code: STRING) is
         -- Target must be Current and `c_code' must be a manifest
         -- string. Write `c_code' in the heading C file.
      external "SmartEiffel"
      end

   c_inline_c(c_code: STRING) is
         -- Target must be Current and `c_code' must be a manifest
         -- string. Write `c_code' in the stream at current position.
      external "SmartEiffel"
      end

feature {NONE} -- Implementation of GENERAL (do not use directly):

   object_id_memory: ARRAY[ANY] is
         -- For a portable implementation of `id_object'/`object_id'.
         -- Note: I think that the pair `id_object'/`object_id' is
         -- a stupid one. It should be removed.
      once
         create Result.with_capacity(256,1)
      end

   print_run_time_stack is
         -- Prints the run time stack.
         -- The result depends both on compilation mode and
         -- target langage used (C or Java byte code).
         -- Usually, in mode -boost, no information is printed.
      external "SmartEiffel"
      end

   print_all_run_time_stacks is
         -- Prints all the run time stacks.
         -- The result depends both on compilation mode and
         -- target langage used (C or Java byte code).
         -- Usually, in mode -boost, no information is printed.
      external "SmartEiffel"
      end

   se_argc: INTEGER is
         -- To implement `command_arguments'
      external "SmartEiffel"
      end

   se_argv(i: INTEGER): STRING is
         -- To implement `command_arguments'
      external "SmartEiffel"
      end

feature -- Implementation of GENERAL (do not use directly):

   frozen se_assigned_from(other: GENERAL): BOOLEAN is
         -- To implement `conforms_to' (must only be called inside
         -- `conforms_to' because of VJRV rule).
      require
         not is_expanded_type
      local
         x: like Current
      do
         x ?= other
         Result := x /= Void
      end

end -- GENERAL

