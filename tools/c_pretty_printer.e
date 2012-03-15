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
class C_PRETTY_PRINTER
   --
   -- Singleton in charge of handling C code pretty printing.
   -- This singleton is shared via the GLOBALS.`cpp' once function.
   --

inherit
   CODE_PRINTER

feature {C_PRETTY_PRINTER_VISITOR}

   accept(visitor: C_PRETTY_PRINTER_VISITOR) is
      do
         visitor.visit_c_pretty_printer(Current)
      end

feature {COMMAND_LINE_TOOLS, ACE}

   compact: BOOLEAN

   set_compact(c: like compact) is
      do
         compact := c
      ensure
         compact = c
      end

feature

   on_h: BOOLEAN is
      require
	 smart_eiffel.is_ready
      do
	 Result := current_out = out_h
      end

   on_c: BOOLEAN is
      require
	 smart_eiffel.is_ready
      do
	 Result := current_out = out_c
      end

   swap_on_c is
      do
	 current_out := out_c
      ensure
	 on_c
      end

   swap_on_h is
      do
	 current_out := out_h
      ensure
	 on_h
      end

   put_string_on_h(string: STRING) is
      do
	 out_h.put_string(string)
      end

   put_extern1(type_variable: STRING) is
      do
	 out_h.put_string(fz_extern)
	 out_h.put_string(type_variable)
	 out_h.put_string(fz_00)
	 --
	 out_c.put_string(type_variable)
	 out_c.put_string(fz_00)
      end

   put_extern2(type_variable: STRING; initializer: CHARACTER) is
      do
	 out_h.put_string(fz_extern)
	 out_h.put_string(type_variable)
	 out_h.put_string(fz_00)
	 --
	 out_c.put_string(type_variable)
	 out_c.put_character('=')
	 out_c.put_character(initializer)
	 out_c.put_string(fz_00)
      end

   put_extern3(type_variable: STRING; array_size: INTEGER) is
      do
	 out_h.put_string(fz_extern)
	 out_h.put_string(type_variable)
	 out_h.put_string(once "[];%N")
	 --
	 out_c.put_string(type_variable)
	 out_c.put_character('[')
	 out_c.put_integer(array_size)
	 out_c.put_string(once "]={")
      end

   put_extern4(type_variable: STRING; array_size: INTEGER) is
      do
	 out_h.put_string(fz_extern)
	 out_h.put_string(type_variable)
	 out_h.put_string(once "[];%N")
	 --
	 out_c.put_string(type_variable)
	 out_c.put_character('[')
	 out_c.put_integer(array_size)
	 out_c.put_string(once "];%N")
      end

   put_extern5(type_variable: STRING; initializer: STRING) is
      do
	 out_h.put_string(fz_extern)
	 out_h.put_string(type_variable)
	 out_h.put_string(fz_00)
	 --
	 out_c.put_string(type_variable)
	 out_c.put_character('=')
	 out_c.put_string(initializer)
	 out_c.put_string(fz_00)
      end

   put_extern6(type_variable: STRING; initializer: INTEGER) is
      do
	 out_h.put_string(fz_extern)
	 out_h.put_string(type_variable)
	 out_h.put_string(fz_00)
	 --
	 out_c.put_string(type_variable)
	 out_c.put_character('=')
	 out_c.put_integer(initializer)
	 out_c.put_string(fz_00)
      end

   put_extern7(type_variable: STRING) is
      do
	 out_h.put_string(fz_extern)
	 out_h.put_string(type_variable)
	 out_h.put_string(fz_00)
	 out_c.put_string(type_variable)
	 out_c.put_character('=')
      end

   put_c_heading(heading: STRING) is
      do
	 out_h.put_string(heading)
	 out_h.put_string(fz_00)
	 out_c.put_character('%N')
	 out_c.put_string(heading)
	 out_c.put_string(fz_11)
      end

   put_c_function(heading, body:STRING) is
      require
	 not heading.is_empty
	 body /= Void
      do
	 put_c_heading(heading)
	 out_c.put_string(body)
	 out_c.put_string(fz_12)
      end

   put_string(c: STRING) is
      require
	 smart_eiffel.is_ready
      do
	 current_out.put_string(c)
      end

   put_string_c(s: STRING) is
      require
	 on_c
      do
	 tmp_string.clear_count
	 manifest_string_pool.string_to_c_code(s, tmp_string)
	 out_c.put_string(tmp_string)
      end

   put_character(c: CHARACTER) is
      require
	 smart_eiffel.is_ready
      do
	 current_out.put_character(c)
      end

   put_integer(i: INTEGER_64) is
      require
	 smart_eiffel.is_ready
      do
	 current_out.put_integer(i)
      end

   put_real(r: REAL) is
      require
	 smart_eiffel.is_ready
      do
	 current_out.put_real(r)
      end

   put_double(d: DOUBLE) is
      require
	 smart_eiffel.is_ready
      do
	 current_out.put_double(d)
      end

   put_array1(array_name: CHARACTER; value: INTEGER) is
      do
	 current_out.put_character(array_name)
	 current_out.put_character('[')
	 current_out.put_integer(value)
	 current_out.put_character(']')
      end

   put_se_string(c_string: STRING) is
      do
	 current_out.put_string(once "(T7*)se_string(")
	 put_string_c(c_string)
	 current_out.put_character(')')
      end

   put_position(p: POSITION) is
      require
	 on_c
      local
         hex: STRING
      do
         hex := once "0x        "
         hex.copy(once "0x")
         p.mangling.to_hexadecimal_in(hex)
	 out_c.put_string(hex)
	 put_position_comment_on(out_c, p)
      end

   put_position_in_ds(p: POSITION) is
      require
	 on_c
      do
	 out_c.put_string(once "ds.p=")
	 put_position(p)
	 out_c.put_string(fz_00)
      end

   current_target: EXPRESSION is
      local
         code: INTEGER
      do
         code := stack_code.item(top)
	 inspect
	    code
         when C_same_target then
            top := top - 1
            Result := current_target
            top := top + 1
         else
            Result := stack_target.item(top)
         end
      end

   target_type: E_TYPE is
      do
         Result := current_target.result_type
      end

   put_target_as_target is
	 -- Produce C code to pass the current stacked target as
	 -- a target of a new call : user expanded are passed with
	 -- a pointer and class invariant code is produced.
      require
	 smart_eiffel.is_ready
      local
	 code: INTEGER; rf: RUN_FEATURE; target: EXPRESSION
	 args: EFFECTIVE_ARG_LIST; ct: E_TYPE; ivt_flag: BOOLEAN
      do
	 code := stack_code.item(top)
	 inspect
	    code
	 when C_direct_call then
	    target := stack_target.item(top)
	    rf := stack_rf.item(top)
	    ct := rf.current_type
	    target.mapping_c_target(ct)
	 when C_check_id then
	    target := stack_target.item(top)
	    rf := stack_rf.item(top)
	    ct := rf.current_type
	    check
	       ct.is_reference
	    end
	    if ace.boost then
	       target.mapping_c_target(ct)
	    else
	       ivt_flag := call_invariant_start(ct)
	       check_id(target, rf.id)
	       if ivt_flag then
		  call_invariant_end
	       end
	    end
	 when C_inline_dca then
	    ct := stack_rf.item(top).current_type
	    ct := ct.run_class.run_time_set.first.current_type
	    check
	       ct.run_class.run_time_set.count = 1
	    end
	    put_character('(')
	    ct.mapping_cast
	    put_character('(')
	    put_target_as_value
	    put_string(fz_13)
	 when C_same_target then
	    rf := stack_rf.item(top)
	    args := stack_args.item(top)
	    top := top - 1
	    put_target_as_target
	    top := top + 1
	    stack_code.put(code, top)
	    stack_rf.put(rf, top)
	    stack_args.put(args, top)
	 else
	    common_put_target
	 end
      end

   put_target_as_value is
	 -- Produce C code for a simple access to the stacked target.
	 -- User's expanded values are not given using a pointer.
	 -- There is no C code to check the class invariant.
      require
	 smart_eiffel.is_ready
      local
	 code: INTEGER
	 rf, static_rf: RUN_FEATURE
	 target: EXPRESSION
	 args: EFFECTIVE_ARG_LIST
	 c0c: CALL_0_C
	 direct_rf: RUN_FEATURE
      do
	 code := stack_code.item(top)
	 inspect
	    code
	 when C_direct_call then
	    stack_target.item(top).compile_to_c
	 when C_check_id then
	    stack_rf.item(top).current_type.mapping_cast
	    stack_target.item(top).compile_to_c
	 when C_inline_dca then
	    rf := stack_rf.item(top)
	    target := stack_target.item(top)
	    args := stack_args.item(top)
	    static_rf := stack_static_rf.item(top)
	    top := top - 1
	    c0c ?= target
	    direct_rf := c0c.run_feature
	    direct_rf.mapping_c
	    top := top + 1
	    stack_code.put(code, top)
	    stack_rf.put(rf, top)
	    stack_target.put(target, top)
	    stack_args.put(args, top)
	    stack_static_rf.put(static_rf, top)
	 when C_same_target then
	    rf := stack_rf.item(top)
	    args := stack_args.item(top)
	    top := top - 1
	    put_target_as_value
	    top := top + 1
	    stack_code.put(code, top)
	    stack_rf.put(rf, top)
	    stack_args.put(args, top)
	 else
	    common_put_target
	 end
      end

   put_error0(msg: STRING) is
	 -- Print `msg' and then stop execution.
	 -- Also print stack when not -boost.
      do
	 if ace.boost then
	    put_comment(msg)
	    put_string(
               "%Nse_signal_handler(14/*System_level_type_error*/);%N")
	 else
	    put_string(once "error0(")
	    put_string_c(msg)
	    put_string(once ",NULL);%N")
	 end
      end

   put_position_comment(p: POSITION) is
      do
	 put_position_comment_on(current_out, p)
      end

   put_comment(str: STRING) is
      do
	 put_string(fz_open_c_comment)
	 put_string(str)
	 put_string(fz_close_c_comment)
      end

   put_comment_line(str: STRING) is
      do
	 put_character('%N')
	 put_comment(str)
	 put_character('%N')
      end

   define_main(rf3: RUN_FEATURE_3) is
      do
	 swap_on_c
	 -- Declare eiffel_root_object :
	 tmp_string.clear_count
	 tmp_string.extend('T')
	 rf3.run_class.id.append_in(tmp_string)
	 tmp_string.append(once "*eiffel_root_object")
	 put_extern5(tmp_string, fz_null)
	 -- Save argv argc :
	 put_extern1(once "int se_argc")
	 put_extern1(once "char**se_argv")
	 define_initialize_eiffel_runtime(rf3)
	 if not ace.no_main then
	    next_bunch_size(1)
	    really_define_c_main(rf3)
	 end
      end

   trace_boolean_expression(e: EXPRESSION) is
	 -- Produce a C boolean expression including trace code.
      require
	 e.result_type.is_boolean ; ace.no_check
      do
	 put_character('(')
	 put_trace_or_sedb_expression(e.start_position)
	 put_character(',')
	 e.compile_to_c
	 put_character(')')
      end

   next_bunch_size(size: INTEGER) is
      do
	 if not ace.no_split then
	    if bunch_counter = 1 and then bunch_size >= 200 then
	       split_c_file_now(size)
	    elseif size >= 200 then
	       split_c_file_now(size)
	    elseif bunch_size >= 400 then
	       split_c_file_now(size)
	    else
	       bunch_counter := bunch_counter + 1
	       bunch_size := bunch_size + size
	    end
	 end
      end

feature {SMART_EIFFEL}

   get_started is
      require
	 smart_eiffel.is_ready
      do
	 echo.file_removing(path_make)
	 top := -1
	 if ace.no_split then
	    c_connect(path_c)
	 else
	    backup_tfw_connect(path_c)
	 end
	 current_out := out_c
	 begin_c_linkage (out_c)
	 add_first_include(path_h)
	 h_connect(path_h)
	 current_out := out_h
	 begin_c_linkage (out_h)
	 put_banner(out_h)
	 out_h.put_character('%N')
	 sys_runtime_h_and_c(fz_base)
	 current_out := out_c
      ensure
	 on_c
      end

   cecil_define is
      local
	 save_out_h: like out_h
      do
	 save_out_h := out_h
	 cecil_pool.c_define_users
	 out_h := save_out_h
      end

   define_used_basics is
	 -- Produce C code only when used.
      do
	 echo.put_string(once "Define used basics.%N")
	 assignment_handler.c_definitions
	 bit_constant_definition
	 if sure_void_count > 0 then
	    echo.put_string(once "Calls with a Void target : ")
	    echo.put_integer(sure_void_count)
	    echo.put_string(once " (yes it is dangerous).%N")
	 end
	 echo.print_count(once "Direct Call", direct_call_count)
	 echo.print_count(once "Direct (Stupid-Switch) Call",
			  stupid_switch_call_count)
	 echo.print_count(once "Check Id Call", check_id_call_count)
	 echo.print_count(once "Switched Call", switched_call_count)
	 echo.print_count(once "Inlined Procedure", inlined_procedure_count)
	 echo.print_count(once "Inlined Function", inlined_function_count)
	 echo.print_count(once "Procedure", procedure_count)
	 echo.print_count(once "Function", function_count)
	 echo.print_count(once "Procedure without Current", real_procedure_count)
	 echo.print_count(once "Function without Current", real_function_count)
	 echo.print_count(once "Precursor routine", precursor_routine_count)
	 echo.put_string(once "Internal stacks size used : ")
	 echo.put_integer(stack_code.count)
	 echo.put_character('%N')
	 end

   customize_runtime(sys_runtime_basic: HASHED_SET[STRING]) is
      require
	 sys_runtime_basic /= Void
      local
	 i: INTEGER; item: STRING
      do
	 if ace.no_check then
	    sys_runtime_h_and_c(fz_no_check)
	    if ace.sedb then
	       put_extern2(once "int se_general_trace_switch", '0')
	       sys_runtime_h_and_c(fz_sedb)
	    end
	 else
	    sys_runtime_h_and_c(fz_boost)
	 end
	 exceptions_handler.customize_c_runtime
	 gc_handler.customize_c_runtime
	 agent_pool.customize_c_runtime
	 if smart_eiffel.deep_twin_used then
	    sys_runtime_h_and_c(as_deep_twin)
	 end
	 from
	    i := sys_runtime_basic.lower
	 until
	    i > sys_runtime_basic.upper
	 loop
	    item := sys_runtime_basic.item(i)
	    if item.has_prefix(once "basic_vision") then
	       system_tools.add_lib_basic_vision
	    end
	    sys_runtime_h_and_c(item)
	    i := i + 1
	 end
      end

feature {RUN_FEATURE, NATIVE}

   target_cannot_be_dropped: BOOLEAN is
	 -- True when top target cannot be dropped because we are not sure that 
	 -- target is non Void or that target has no side effects. When Result is True, 
	 -- printed C code is : "(((void)(<target>))"
      require
	 smart_eiffel.is_ready
      local
	 recursivity_flag: BOOLEAN target: EXPRESSION; type_of_target: E_TYPE
	 rf: RUN_FEATURE; args: EFFECTIVE_ARG_LIST
      do
	 inspect
	    stack_code.item(top)
	 when C_direct_call, C_check_id then
	    target := stack_target.item(top)
	    type_of_target := target.result_type
	    Result := not target.side_effect_free
	 when C_inline_dca then
	    Result := True
	 when C_same_target then
	    -- Saving value first:
	    rf := stack_rf.item(top)
	    args := stack_args.item(top)
	    top := top - 1
	    recursivity_flag := target_cannot_be_dropped
	    top := top + 1
	    stack_code.put(C_same_target, top)
	    stack_rf.put(rf, top)
	    stack_args.put(args, top)
	 else
	 end
	 if Result then
	    put_string(once "((/*UT*/(void)(")
	    if type_of_target = Void then
	       put_target_as_target
	    elseif type_of_target.is_user_expanded then
	       put_target_as_value
	    else
	       put_target_as_target
	    end
	    put_string(fz_13)
	 elseif recursivity_flag then
	    Result := True
	 end
      end

   arguments_cannot_be_dropped: BOOLEAN is
	 -- True when arguments cannot be dropped.
	 -- Printed C code is like :
	 --  "(((void)<exp1>), ((void)<exp2>), ...((void)<expN>)"
      do
	 if not no_args_to_eval then
	    Result := True
	    put_string(once "((/*UA*/(void)(")
	    put_arguments
	    put_string(fz_13)
	 end
      end

   cannot_drop_all: BOOLEAN is
	 -- Result is True when something (target or one argument)
	 -- cannot be dropped. Thus when something cannot be dropped,
	 -- Result is True and C code is printed :
	 --  "(((void)<exp1>), ((void)<exp2>), ...((void)<expN>)"
      do
	 if target_cannot_be_dropped then
	    Result := True
	    put_character(',')
	    if arguments_cannot_be_dropped then
	       put_character(')')
	    else
	       put_character('0')
	    end
	 else
	    Result := arguments_cannot_be_dropped
	 end
      end

feature

   put_arguments is
	 -- Produce code to access to the whole effective arguments list.
      require
	 smart_eiffel.is_ready
      local
	 i, c: INTEGER; fal: FORMAL_ARG_LIST; rf: RUN_FEATURE
      do
	 -- Compute arguments count in `c':
	 rf := stack_rf.item(top)
	 fal := rf.arguments
	 c := fal.count
	 -- Put all arguments:
	 from
	    i := 1
	 until
	    i > c
	 loop
	    put_ith_argument(i)
	    if i < c then put_character(',') end
	    i := i + 1
	 end
      end

   put_ith_argument(index: INTEGER) is
	 -- Produce code to access to the ith argument.
      require
	 smart_eiffel.is_ready ; index >= 1
      local
	 code: INTEGER; rf, static_rf: RUN_FEATURE; target: EXPRESSION
	 args: EFFECTIVE_ARG_LIST; fal: FORMAL_ARG_LIST; switch: SWITCH
	 unwrap_buffer: STRING
      do
	 code := stack_code.item(top)
	 inspect
	    code
	 when C_switch then
	    fal := stack_rf.item(top).arguments
	    static_rf := stack_static_rf.item(top)
	    switch.put_ith_argument(static_rf, fal, index)
	 when C_create_expression, C_scoop_wrapper then
	    put_character('a')
	    put_integer(index)
	 when C_inline_dca then
	    rf := stack_rf.item(top)
	    target := stack_target.item(top)
	    args := stack_args.item(top)
	    static_rf := stack_static_rf.item(top)
	    top := top - 1
	    if rf /= Void then
	       args.dca_inline_ith(rf.arguments, index)
	    else
	       -- No rf for "=" and "/=".
	       args.dca_inline_ith(static_rf.arguments, index)
	    end
	    top := top + 1
	    stack_code.put(code, top)
	    stack_rf.put(rf, top)
	    stack_target.put(target, top)
	    stack_args.put(args, top)
	    stack_static_rf.put(static_rf, top)
	 when C_inline_one_pc then
	    print_argument(index)
	 when C_inside_twin then
	    check index = 1 end
	    if stack_rf.item(top).current_type.is_reference then
	       put_string(once "((T0*)C)")
	    else
	       put_string(once "*C")
	    end
	 when
	    C_create_instruction,
	    C_direct_call,
	    C_check_id,
	    C_same_target,
	    C_precursor
	  then
	    fal := stack_rf.item(top).arguments
	    stack_args.item(top).compile_to_c_ith(fal, index)
	 when C_scoop_unwrapper then
	    unwrap_buffer := once "                "
	    unwrap_buffer.clear_count
	    unwrap_buffer.append(once "((Tw")
	    stack_rf.item(top).id.append_in(unwrap_buffer)
	    stack_rf.item(top).name.mapping_c_in(unwrap_buffer)
	    unwrap_buffer.append(once "*)data)->_")
	    unwrap_buffer.append(stack_rf.item(top).arguments.name(index).to_string)
	    out_c.put_string(unwrap_buffer)
	 end
     end

feature {NATIVE_SMART_EIFFEL}

   put_c_inline_h is
      local
	 c_code: STRING
      do
	 c_code := get_inline_ms.to_string
	 if not c_inline_h_mem.fast_has(c_code) then
	    c_inline_h_mem.add_last(c_code)
	    out_h.put_string(c_code)
	    out_h.put_character('%N')
	 end
      end

   put_c_inline_c is
      local
	 c_code: MANIFEST_STRING
      do
	 c_code := get_inline_ms
	 out_c.put_string(c_code.to_string)
      end

   put_trace_switch is
	 -- The GENERAL.trace_switch feature
      do
	 if ace.sedb then
	    put_string(once "se_general_trace_switch=(")
	    put_ith_argument(1)
	    put_string(fz_14)
	 end
      end

   put_sedb_breakpoint is
      require
	 on_c
      local
	 e: EXPRESSION; p: POSITION
      do
	 if ace.sedb then
	    out_c.put_string(once "sedb_breakpoint(&ds,")
	    e := stack_target.item(top)
	    if e /= Void then
	       p := e.start_position
	    end
	    put_position(p)
	    put_string(once ");%N")
	 end
      end

   put_generating_type(t: E_TYPE) is
      local
	 rc: RUN_CLASS
      do
	 put_string(fz_cast_t0_star)
	 put_character('(')
	 put_character('t')
	 put_character('[')
	 if t.is_reference then
	    rc := t.run_class
	    if rc.is_tagged then
	       put_character('(')
	       put_target_as_value
	       put_character(')')
	       put_string(fz_arrow_id)
	    else
	       put_integer(rc.id)
	    end
	 else
	    put_integer(t.id)
	 end
	 put_character(']')
	 put_character(')')
      end

   put_generator(t: E_TYPE) is
      require
	 t.is_run_type
      local
	 rc: RUN_CLASS
      do
	 put_string(fz_cast_t0_star)
	 put_character('(')
	 put_character('g')
	 put_character('[')
	 if t.is_reference then
	    rc := t.run_class
	    if rc.is_tagged then
	       put_character('(')
	       put_target_as_value
	       put_character(')')
	       put_string(fz_arrow_id)
	    else
	       put_integer(rc.id)
	    end
	 else
	    put_integer(t.id)
	 end
	 put_character(']')
	 put_character(')')
      end

   target_position_in_error_handler is
	 -- Add the target position into the `error_handler'.
      local
	 target: EXPRESSION
      do
	 target := stack_target.item(top)
	 if target /= Void then
	    error_handler.add_position(target.start_position)
	 end
      end

   put_object_size(t: E_TYPE) is
      require
	 t.is_run_type
      local
	 tcbd: BOOLEAN
      do
	 tcbd := target_cannot_be_dropped
	 if tcbd then
	    out_c.put_character(',')
	 end
	 out_c.put_string(once "sizeof(T")
	 out_c.put_integer(t.id)
	 out_c.put_character(')')
	 if tcbd then
	    out_c.put_character(')')
	 end
      end

feature {CECIL_FILE}

   connect_cecil_out_h(user_path_h: STRING) is
      do
	 !!out_h.make
	 echo.tfw_connect(out_h, user_path_h)
	 system_tools.mandatory_sys_runtime(fz_base, 'h')
	 put_file(tmp_file_read, out_h)
	 out_h.put_string(
			  once "extern void*eiffel_root_object;%N%N%
			  %typedef unsigned char* T9;%N%
			  %/* Available Eiffel routines via -cecil:%N*/%N")
      end

   disconnect_cecil_out_h is
      do
	 out_h.disconnect
      end

feature {CECIL_POOL, RUN_FEATURE}

   push_scoop_unwrapper(rf: RUN_FEATURE) is
      require
	 rf /= Void
      do
	 stack_push(C_scoop_unwrapper)
	 stack_rf.put(rf, top)
      end

   push_scoop_wrapper(rf: RUN_FEATURE) is
      require
	 rf /= Void
      do
	 stack_push(C_scoop_wrapper)
	 stack_rf.put(rf, top)
      end

feature {RUN_FEATURE}

   push_introspect(rf: RUN_FEATURE) is
      do
         stack_push(C_introspect)
         stack_rf.put(rf, top)
      end

feature {CECIL_POOL, RUN_FEATURE}

   push_direct(rf: RUN_FEATURE; t: EXPRESSION; args: EFFECTIVE_ARG_LIST) is
      require
	 rf /= Void
	 t /= Void
	 (args /= Void) implies rf.arguments.count = args.count 
      do
	 stack_push(C_direct_call)
	 stack_rf.put(rf, top)
	 stack_target.put(t, top)
	 stack_args.put(args, top)
	 direct_call_count := direct_call_count + 1
      end

feature {MANIFEST_STRING_INSPECTOR}

   put_string_inspector(a_feature: STRING) is
      local
         rc: RUN_CLASS; rf: RUN_FEATURE
      do
         check
            a_feature = as_storage or else a_feature = as_count
         end
         rc := smart_eiffel.run_class(type_string)
         rf := rc.get_feature_with(a_feature)
         stack_push(C_string_inspector)
         stack_rf.put(rf, top)
         rf.mapping_c
         pop
      end

feature {RUN_FEATURE_3}

   push_inline_one_pc(rf: RUN_FEATURE) is
      do
	 stack_push(C_inline_one_pc)
	 stack_rf.put(rf, top)
      end

feature {RUN_FEATURE_3, RUN_FEATURE_4}

   push_inline_dca(relay_rf: RUN_FEATURE; dpca: CALL_PROC_CALL) is
	 -- Where `dpca' is inside `relay_rf'.
      require
	 relay_rf /= Void
	 dpca /= Void
      do
	 stack_push(C_inline_dca)
	 stack_rf.put(dpca.run_feature, top)
	 stack_static_rf.put(relay_rf, top)
	 stack_target.put(dpca.target, top)
	 stack_args.put(dpca.arguments, top)
	 direct_call_count := direct_call_count + 1
      end

   push_same_target(rf: RUN_FEATURE; args: EFFECTIVE_ARG_LIST) is
      require
	 rf.arguments /= Void implies args.count = rf.arguments.count
	 args /= Void implies args.count = rf.arguments.count
      do
	 stack_push(C_same_target)
	 stack_rf.put(rf, top)
	 stack_args.put(args, top)
      end

feature {CECIL_POOL}

   push_cpc(up_rf: RUN_FEATURE; run_time_set: RUN_TIME_SET
	    t: EXPRESSION; args: EFFECTIVE_ARG_LIST) is
      require
	 run_time_set = up_rf.run_class.run_time_set
      local
	 dyn_rf: RUN_FEATURE
      do
	 check
	    not up_rf.current_type.is_type_of_agent
	    -- Because agent execution handled in class 
	    -- AGENT_INSTRUCTION and AGENT_EXPRESSION.
	 end
	 if run_time_set.count = 0 then
	    se_evobt(up_rf, t)
	 elseif run_time_set.count = 1 then
	    dyn_rf := run_time_set.first.dynamic(up_rf)
	    push_check(dyn_rf, t, args)
	    dyn_rf.mapping_c
	    pop
	 else
	    use_switch(up_rf, run_time_set, t, args)
	 end
      end

feature {SWITCH}

   inside_switch_call(dyn_rf, static_rf: RUN_FEATURE) is
	 -- Call the `dyn_rf' inside switching function for `static_rf'.
      require
	 dyn_rf /= Void
	 static_rf /= Void
	 dyn_rf.run_class.dynamic(static_rf) = dyn_rf
      local
	 dyn_result, static_result: E_TYPE; msg: STRING
	 cast, no_code, need_se_tmp, assign_call: BOOLEAN
      do
	 -- Extra comment to debug C code:
	 -- put_comment(dyn_rf.current_type.run_time_mark)
	 --
	 static_result := static_rf.result_type
	 if static_result /= Void then
	    static_result := static_result.run_type
	    dyn_result := dyn_rf.result_type
	    if static_result.is_user_expanded then
	       if dyn_result.is_user_expanded then
		  if dyn_result.run_class /= static_result.run_class then
		     no_code := True
		  end
	       end
	    end
	 end
	 if no_code then
	    msg := "Conversion from: "
	    msg.append(dyn_result.run_time_mark)
	    msg.append(once " to: ")
	    msg.append(static_result.run_time_mark)
	    msg.append(once " not yet implemented (sorry). %
			    %Please report on SmartEiffel@loria.fr.)")
	    put_error0(msg)
	 else
	    dyn_rf.collect_c_tmp
	    need_se_tmp := se_tmp_open_declaration
	    -- Opening section for Result:
	    if static_result /= Void then
	       if static_result.is_boolean then
		  out_c.put_string(once "R=(T6)(")
	       else
	          out_c.put_string(fz_26)
	       end
	       if (static_result.is_native_array
		  or else
	          (dyn_result.is_none and then
		   static_result.is_expanded))
		then
		  cast := True
		  out_c.put_string(fz_b7)
		  out_c.put_integer(static_result.id)
		  out_c.put_character(')')
		  out_c.put_character('(')
	       end
	       if dyn_result.is_expanded then
		  if static_result.is_reference then
		     assignment_handler.c_conversion_call(dyn_result,
                                                          static_result)
                     assign_call := True
		  end
               elseif static_result.is_separate then
                  assignment_handler.c_conversion_call(dyn_result,
		                                       static_result)
                  assign_call := True
	       end
	    end
	    stack_push(C_switch)
	    stack_rf.put(dyn_rf, top)
	    stack_static_rf.put(static_rf, top)
	    dyn_rf.mapping_c
	    pop
	    -- Closing section for Result:
	    if static_result /= Void then
	       if assign_call then
		  out_c.put_character(')')
	       end
	       if cast then
		  out_c.put_character(')')
		  out_c.put_character(')')
	       end
	       out_c.put_string(fz_14)
	    end
	    if need_se_tmp then
	       se_tmp_close_declaration
	    end
	 end
      end

feature

   put_proc_call_0(rf3: RUN_FEATURE_3; writable: EXPRESSION; c_name: STRING) is
	 -- To call the expanded initializer `rf3' (ie. a procedure without
	 -- arguments) using `writable' or `c_name' as target.
      require
	 rf3.current_type.is_expanded
	 rf3.arguments = Void
	 (writable /= Void) xor (c_name /= Void)
      do
	 stack_push(C_expanded_initialize)
	 stack_target.put(writable, top)
	 stack_string.put(c_name, top)
	 stack_rf.put(Void, top)
	 direct_call_count := direct_call_count + 1
	 rf3.mapping_c
	 pop
	 if call_invariant_start(rf3.current_type) then
	    put_character('&')
	    writable.compile_to_c
	    call_invariant_end
	    put_string(fz_00)
	 end
      end

feature {RUN_CLASS}

   push_create_expression(rf: RUN_FEATURE) is
      require
	 rf /= Void
      do
	 stack_push(C_create_expression)
	 stack_rf.put(rf, top)
	 direct_call_count := direct_call_count + 1
      end

feature {CREATE_TOOLS}

   push_create_instruction(rf: RUN_FEATURE; args: EFFECTIVE_ARG_LIST) is
      require
	 rf /= Void
      do
	 stack_push(C_create_instruction)
	 stack_rf.put(rf, top)
	 stack_args.put(args, top)
	 direct_call_count := direct_call_count + 1
      end

   expanded_attributes(rt: E_TYPE) is
	 -- Produce C code to initialize expanded attribute
	 -- of the new object juste created in variable "n".
      require
	 smart_eiffel.is_ready
	 rt.is_run_type
      local
	 wa: ARRAY[RUN_FEATURE]; a: RUN_FEATURE; at: E_TYPE
	 i: INTEGER; rf3: RUN_FEATURE_3
      do
	 wa := rt.run_class.writable_attributes
	 if wa /= Void then
	    from
	       i := wa.upper
	    until
	       i = 0
	    loop
	       a := wa.item(i)
	       at := a.result_type.run_type
	       if at.is_user_expanded then
		  rf3 := at.run_class.a_default_create
		  if rf3 /= Void then
		     stack_push(C_expanded_initialize)
		     stack_string.put(Void, top)
		     stack_target.put(Void, top)
		     stack_rf.put(a, top)
		     direct_call_count := direct_call_count + 1
		     rf3.mapping_c
		     pop
		  end
	       end
	       i := i - 1
	    end
	 end
      end

feature {NATIVE}

   inside_twin(cpy: RUN_FEATURE) is
      do
	 stack_push(C_inside_twin)
	 stack_rf.put(cpy, top)
	 cpy.mapping_c
	 pop
      end

feature {ASSERTION}

   check_assertion(e: EXPRESSION; tag_name: TAG_NAME) is
	 -- Produce a C boolean expression including trace code
	 -- and assertion check.
      require
	 e.result_type.is_boolean
      do
	 put_trace_or_sedb_instruction(e.start_position)
	 put_string(once "ac_")
	 put_string(check_assertion_mode)
	 put_character('(')
	 e.compile_to_c
	 put_character(',')
	 if tag_name /= Void then
	    put_string_c(tag_name.to_string)
	 else
	    put_string(fz_null)
	 end
	 put_string(fz_14)
      end

feature {ASSERTION_LIST}

   set_check_assertion_mode(s: STRING) is
      require
	 s /= Void
      do
	 check_assertion_mode := s
      ensure
	 check_assertion_mode = s
      end

feature

   put_trace_or_sedb_expression(position: POSITION) is
	 -- Writes on `out_c' an `sedb(...)' call or some `ds.p' 
	 -- update according to the ACE mode of the given `position'. 
      require
	 not ace.boost ; not position.is_unknown
      do
	 if position.sedb_trace then
	    out_c.put_string(once "sedb(&ds,")
	 else
	    out_c.put_string(once "(ds.p=")
	 end
	 put_position(position)
	 out_c.put_character(')')
      end
   
   put_trace_or_sedb_instruction(position: POSITION) is
      require
	 not ace.boost ; not position.is_unknown
      do
	 put_trace_or_sedb_expression(position)
	 out_c.put_string(fz_00)
      end
   
feature -- Numbering of inspect variables :

   inspect_incr is
      do
	 inspect_level := inspect_level + 1
      end

   inspect_decr is
      do
	 inspect_level := inspect_level - 1
      end

   put_inspect is
      do
	 put_character('z')
	 put_integer(inspect_level)
      end

feature -- Printing Current, local or argument :

   inline_level_incr is
      do
	 inline_level := inline_level + 1
      end

   inline_level_decr is
      do
	 inline_level := inline_level - 1
      end

   print_current is
      require
	 on_c
      local
	 level: INTEGER
      do
	 out_c.put_character('C')
	 level := inline_level
	 if level > 0 then
	    out_c.put_integer(level)
	 end
      end

   print_argument(rank: INTEGER) is
      require
	 on_c
      local
	 code: INTEGER
      do
	 code := ('a').code + inline_level
	 out_c.put_character(code.to_character)
	 out_c.put_integer(rank)
      end

   print_local(name: STRING) is
      require
	 on_c
      local
	 level: INTEGER
      do
	 out_c.put_character('_')
	 out_c.put_character('l')
	 out_c.put_character('_')
	 from
	    level := inline_level
	 until
	    level = 0
	 loop
	    out_c.put_character('_')
	    level := level - 1
	 end
	 out_c.put_string(name)
      end

feature {E_LOOP}

   variant_check(e: EXPRESSION) is
      require
	 e /= Void
      do
	 put_trace_or_sedb_instruction(e.start_position)
	 put_string(once "v=ac_lvc(c++,v,")
	 e.compile_to_c
	 put_string(fz_14)
      end

feature {RUN_FEATURE}

   current_class_invariant(current_type: E_TYPE) is
	 -- Add some C code to check class invariant with Current
	 -- at the end of a routine for `Current'.
      require
	 current_type.is_run_type
      local
	 rc: RUN_CLASS
      do
	 rc := need_invariant(current_type)
	 if rc /= Void then
	    if rc.current_type.is_reference then
	       out_c.put_string(once "if(se_rci(caller,C))")
	    end
	    out_c.put_string(fz_se_i)
	    out_c.put_integer(rc.id)
	    out_c.put_string(once "(&ds,C);%N")
	 end
      end

feature

   call_invariant_start(type_of_target: E_TYPE): BOOLEAN is
	 -- Start printing call of invariant only when it is needed
	 -- (`type_of_target' really has an invariant and when mode is
	 -- `-invariant_check').
	 -- When Result is True, `call_invariant_end' must be called to
	 -- finish the job.
      require
	 type_of_target.is_run_type
      local
	 rc: RUN_CLASS
      do
	 rc := need_invariant(type_of_target)
	 if rc /= Void then
	    out_c.put_string(fz_se_i)
	    out_c.put_integer(rc.id)
	    out_c.put_string(once "(&ds,")
	    Result := True
	 end
      end

   call_invariant_end is
      do
	 out_c.put_character(')')
      end

feature

   macro_def(str: STRING; id: INTEGER) is
      do
	 tmp_string.clear_count
	 tmp_string.extend('#')
	 tmp_string.append(fz_define)
	 tmp_string.extend(' ')
	 tmp_string.append(str)
	 tmp_string.extend(' ')
	 id.append_in(tmp_string)
	 tmp_string.extend('%N')
	 out_h.put_string(tmp_string)
      end

feature

   write_make_file is
      local
	 score: DOUBLE
         cc: C_COMPACTOR
	 cmd: STRING
      do
	 --
	 out_h.put_character('%N')
	 end_c_linkage(out_h)
	 out_h.disconnect
	 out_c.put_character('%N')
	 end_c_linkage(out_c)
	 out_c.disconnect
         --
         if compact then
            cc ?= out_h
            check cc /= Void end
            echo.tfw_connect(out_make, path_symbols)
            cc.write_symbols(out_make)
            create in_h.make
            echo.tfr_connect(in_h, path_h)
            from
               in_h.read_line
            until
               in_h.end_of_input
            loop
               out_make.put_string(in_h.last_string)
               out_make.put_new_line
               in_h.read_line
            end
            in_h.disconnect
            out_make.disconnect
            echo.file_renaming(path_symbols, path_h)
            cc.show_gain
         end
	 --
	 c_plus_plus_definitions
         --
         system_tools.default_c_compiler_options(False)
         --
         echo.tfw_connect(out_make, path_make)
	 if ace.no_split then
	    write_make_file_no_split
	 else
	    write_make_file_split
	 end
	 if not executable_is_up_to_date then
	    cmd := system_tools.strip_executable
	    if cmd /= Void then
	       echo_make(cmd)
	    end
	 end
	 out_make.disconnect
	 if nb_errors > 0 then
	    echo.file_removing(path_make)
	 else
	    echo.put_string(once "Type inference score : ")
	    score := direct_call_count + check_id_call_count
	    score := (score / (score + switched_call_count)) * 100.0
	    echo.put_double_format(score, 2)
	    echo.put_character('%%')
	    echo.put_character('%N')
	 end
      end

feature {CALL_PROC_CALL, E_AGENT}

   put_cpc(cpc: CALL_PROC_CALL) is
      local
	 target: EXPRESSION; type_of_target: E_TYPE; run_feature: RUN_FEATURE
      do
	 target := cpc.target
	 type_of_target := target.result_type.run_type
	 run_feature := cpc.run_feature
         if type_of_target.is_expanded or else
            target.is_current or else
            target.is_manifest_string
	  then
	    push_direct(run_feature, target, cpc.arguments)
	    run_feature.mapping_c
	    pop
	 else
	    push_cpc(run_feature,
		     type_of_target.run_class.run_time_set,
		     target,
		     cpc.arguments)
	 end
      end

feature

   sys_runtime_h_and_c(name: STRING) is
	 -- Inline corresponding SmartEiffel/sys/runtime/`name'.[hc]
	 -- file. (At least, one file should be found.)
      local
	 ok: BOOLEAN
      do
	 system_tools.sys_runtime(name, 'h')
	 if tmp_file_read.is_connected then
	    ok := True
	    put_file(tmp_file_read, out_h)
	 end
	 system_tools.sys_runtime(name, 'c')
	 if tmp_file_read.is_connected then
	    ok := True
	    put_file(tmp_file_read, out_c)
	 end
	 if not ok then
	    error_handler.append("No support found in directory sys/runtime for %"")
	    error_handler.append(name)
	    error_handler.append("%" (i.e. file(s) %"")
	    tmp_path.remove_last(1)
	    error_handler.append(tmp_path)
	    error_handler.append("[hc]%" not found).")
	    error_handler.print_as_fatal_error
	 end
      end

feature {SYSTEM_TOOLS}

   put_c_file(tfr: TEXT_FILE_READ) is
      require
	 not tfr.end_of_input
      do
	 put_file(tfr, out_c)
      ensure
	 not tfr.is_connected
      end

feature

   put_recompilation_comment(key: INTEGER) is
      do
	 out_c.put_string(fz_open_c_comment)
	 out_c.put_integer(key)
	 out_c.put_string(fz_close_c_comment)
      end

   put_recompilation_comment_in(buffer: STRING; key: INTEGER) is
      do
	 buffer.append(fz_open_c_comment)
	 key.append_in(buffer)
	 buffer.append(fz_close_c_comment)
      end

feature {COMPOUND, ASSERTION_LIST, E_LOOP, RUN_CLASS, CREATE_TOOLS}

   se_tmp_open_declaration: BOOLEAN is
	 -- True if some `se_tmpXX' temporay is needed.
      local
	 i: INTEGER; t: E_TYPE
      do
	 from
	    tmp_string.clear_count
	    tmp_string.extend('{')
	    i := se_tmp_list.upper
	 until
	    i < 0
	 loop
	    t := se_tmp_list.item(i)
	    if t /= Void then
	       Result := True
	       if t.is_expanded then
		  t.c_type_for_result_in(tmp_string)
	       else
		  t.c_type_for_target_in(tmp_string)
	       end
	       tmp_string.append(once " se_tmp")
	       i.append_in(tmp_string)
	       tmp_string.append(fz_00)
	    end
	    i := i - 1
	 end
	 if Result then
	    se_tmp_level := se_tmp_level + 1
	    out_c.put_string(tmp_string)
	 end
      end

   se_tmp_close_declaration is
      do
	 check
	    se_tmp_level > 0
	 end
	 se_tmp_level := se_tmp_level - 1
	 out_c.put_string(fz_12)
	 if se_tmp_level = 0 then
	    se_tmp_list.clear
	 end
      end

feature {RUN_FEATURE}

   se_tmp_register(t: E_TYPE) is
      require
	 (t.is_expanded and not t.is_dummy_expanded)
	 or else
	  t.is_separate
      do
	 se_tmp_list.add_last(t)
      end

   se_tmp_open_expanded(t: E_TYPE): INTEGER is
	 -- The `Result' is the index of the `se_tmp' variable, because this
	 -- variable may be used more than once. Result >= 0 implies that
	 -- a temporary variable is used and thus that 
	 -- `se_tmp_close_expanded' must be called. Result < 0 indicate that 
	 -- `t' is not registered.
      local
	 stop: BOOLEAN; t2: E_TYPE; rtm1: STRING
      do
	 from
	    Result := se_tmp_list.upper
	    rtm1 := t.run_time_mark
	 until
	    stop
	 loop
	    if Result < 0 then
	       stop := True
	    else
	       t2 := se_tmp_list.item(Result)
	       if t2 /= Void and then rtm1 = t2.run_time_mark then
		  stop := True
		  se_tmp_list.put(Void, Result)
		  out_c.put_string(once "(*(/*expanded*/se_tmp")
		  out_c.put_integer(Result)
		  out_c.put_character('=')
	       else
		  Result := Result - 1
	       end
	    end
	 end
      end

   se_tmp_close_expanded(se_tmp_idx: INTEGER) is
	 -- Assume `se_tmp_idx' is the value obtained with 
	 -- `se_tmp_open_expanded'.
      require
	 se_tmp_idx >= 0
      do
	 check -- Obtained with `se_tmp_open_expanded':
	    se_tmp_list.item(se_tmp_idx) = Void
	 end
	 out_c.put_character(',')
	 out_c.put_character('&')
	 out_c.put_string(once "se_tmp")
	 out_c.put_integer(se_tmp_idx)
	 out_c.put_character(')')
	 out_c.put_character(')')
      end

   se_tmp_open_separate(t: E_TYPE): INTEGER is
	 -- The `Result' is the index of the `se_tmp' variable, because this
	 -- variable may be used more than once. Result >= 0 implies that
	 -- a temporary variable is used and thus that 
	 -- `se_tmp_close_separate' must be called. Result < 0 indicate that 
	 -- `t' is not registered.
      require
	 t.is_separate
      local
	 stop: BOOLEAN
      do
	 from
	    Result := se_tmp_list.upper
	 until
	    stop
	 loop
	    if Result < 0 then
	       stop := True
	    elseif t = se_tmp_list.item(Result) then
	       stop := True
	       se_tmp_list.put(Void, Result)
	       out_c.put_string(once "(((void)(/*separate*/se_tmp")
	       out_c.put_integer(Result)
	       out_c.put_character('=')
	       put_target_as_target
	       out_c.put_string(once ")),")
	    else
	       Result := Result - 1
	    end
	 end
      end

   se_tmp_close_separate(se_tmp_idx: INTEGER) is
	 -- Assume `se_tmp_idx' is the value obtained with 
	 -- `se_tmp_open_separate'.
      require
	 se_tmp_idx >= 0
      do
	 check -- Obtained with `se_tmp_open_separate':
	    se_tmp_list.item(se_tmp_idx) = Void
	 end
	 out_c.put_character(')')
      end

feature {BIT_CONSTANT}

   register_bit_constant(bc: BIT_CONSTANT) is
      require
	 bc.result_type.is_c_unsigned_ptr
      do
	 if bit_constant_pool = void then
	    !!bit_constant_pool.with_capacity(4)
	 end
	 bit_constant_pool.add_last(bc)
	 out_c.put_string(fz_se_bit_constant)
	 out_c.put_integer(bit_constant_pool.upper)
      end

   bit_constant_definition is
      local
	 i: INTEGER
	 bc: BIT_CONSTANT
	 type_bit: TYPE_BIT
      do
	 if bit_constant_pool /= Void then
	    from
	       i := bit_constant_pool.upper
	    until
	       i < 0
	    loop
	       tmp_string.clear_count
	       bc := bit_constant_pool.item(i)
	       type_bit := bc.result_type
	       tmp_string.clear_count
	       type_bit.c_type_for_argument_in(tmp_string)
	       tmp_string.extend(' ')
	       tmp_string.append(fz_se_bit_constant)
	       i.append_in(tmp_string)
	       put_extern7(tmp_string)
	       out_c.put_character('{')
	       bc.c_define
	       out_c.put_character('}')
	       out_c.put_character(';')
	       out_c.put_character('%N')
	       i := i - 1
	    end
	 end
      end

feature {NATIVE}

   include_register(origin: POSITION; include_name: STRING) is
      do
	 if include_memory = Void then
	    create include_memory.make
	 end
	 if not include_memory.has(include_name) then
	    include_memory.add(include_name)
	    put_position_comment_on(out_h, origin)
	    add_include_on(out_h, include_name)
	    put_position_comment_on(out_h, origin)
	 end
      end

feature {NATIVE_C_PLUS_PLUS}

   c_plus_plus_register(native: NATIVE_C_PLUS_PLUS) is
      do
	 if c_plus_plus = Void then
	    !!c_plus_plus.with_capacity(64)
	 end
	 c_plus_plus.add_last(native)
      end

   add_include(include: STRING) is
      do
	 add_include_on(out_h, include)
      end

   add_include_on(output: TEXT_FILE_WRITE; include: STRING) is
      do
	 end_c_linkage (output)
	 output.put_string(once "#include ")
	 inspect
	    include.first
	 when '%"', '<' then
	 else
	    output.put_character('%"')
	 end
	 output.put_string(include)
	 inspect
	    include.last
	 when '%"', '>' then
	 else
	    output.put_character('%"')
	 end
	 output.put_character('%N')
	 begin_c_linkage (output)
      end

feature {RUN_FEATURE_2}

   attribute_read_removal(up_rf: RUN_FEATURE
			  run_time_set: RUN_TIME_SET): BOOLEAN is
      require
	 smart_eiffel.is_ready
	 run_time_set.count > 1
      local
	 rf2a, rf2b: RUN_FEATURE_2; offseta, offsetb: INTEGER
	 rta, rtb: E_TYPE; i: INTEGER; rc: RUN_CLASS
      do
	 from
	    Result := True
	    i := run_time_set.count
	 until
	    not Result or else i = 0
	 loop
	    rc := run_time_set.item(i)
	    rf2b ?= rc.dynamic(up_rf)
	    if rf2b /= Void then
	       offsetb := rc.offset_of(rf2b)
	    end
	    if rf2a = Void then
	       rf2a := rf2b
	       offseta := offsetb
	    end
	    if rf2b = Void then
	       Result := False
	    else
	       Result := offseta = offsetb
	       if Result then
		  rta := rf2a.result_type.run_type
		  rtb := rf2b.result_type.run_type
		  if rta.is_reference then
		     Result := rtb.is_reference
		  elseif rta.run_time_mark = rtb.run_time_mark then
		  elseif rta.is_native_array then
		     if rta.generic_list.first.is_reference then
			Result := rtb.generic_list.first.is_reference
		     end
		  else
		     Result := False
		  end
	       end
	    end
	    i := i - 1
	 end
      end

feature {NONE}

   ftools: FILE_TOOLS

   stupid_switch(up_rf: RUN_FEATURE): BOOLEAN is
      require
	 smart_eiffel.is_ready
	 up_rf.run_class.run_time_set.count >= 1
      local
	 run_time_set: RUN_TIME_SET
      do
	 run_time_set := up_rf.run_class.run_time_set
	 if run_time_set.count > 1 then
	    smart_eiffel.push(up_rf)
	    Result := stupid_switch_n(up_rf, run_time_set)
	    smart_eiffel.pop
	 else
	    Result := True
	 end
      end

   stupid_switch_n(up_rf: RUN_FEATURE; run_time_set: RUN_TIME_SET): BOOLEAN is
      require
	 smart_eiffel.is_ready
	 smart_eiffel.top_rf = up_rf
	 run_time_set.count > 1
      local
	 stupid: STRING
      do
	 if smart_eiffel.same_base_feature(up_rf, run_time_set) then
	    stupid := up_rf.stupid_switch(run_time_set)
	    if stupid /= Void then
	       put_comment(stupid)
	       Result := True
	    end
	 else
	    Result := attribute_read_removal(up_rf, run_time_set)
	    if Result then
	       put_comment(once "SSWA2")
	    end
	 end
      end

   c_plus_plus: FAST_ARRAY[NATIVE_C_PLUS_PLUS]

   begin_c_linkage (output: TEXT_FILE_WRITE) is
		 -- Begin wrap for C linkage
      do
	 output.put_string (once "#ifdef __cplusplus%Nextern %"C%" {%N#endif%N")
      end

   end_c_linkage (output: TEXT_FILE_WRITE) is
		 -- End wrap for C linkage
      do
	 output.put_string (once "#ifdef __cplusplus%N}%N#endif%N")
      end

   c_plus_plus_definitions is
      local
	 cpp_path_h, cpp_path_c: STRING
	 i: INTEGER
	 no_split_save: BOOLEAN
      do
	 if c_plus_plus /= Void then
	    no_split_save := ace.no_split
	    ace.set_no_split(True)
	    echo.put_string(once "C++ external definitions.%N")
	    cpp_path_h := system_tools.path_h.twin
	    cpp_path_h.remove_last(2)
	    cpp_path_h.append(once "_external_cpp")
	    cpp_path_c := cpp_path_h.twin
	    cpp_path_h.append(h_suffix)
	    cpp_path_c.append(c_plus_plus_suffix)
	    echo.tfw_connect(out_h, cpp_path_h)
	    echo.tfw_connect(out_c, cpp_path_c)
	    begin_c_linkage (out_c)
	    begin_c_linkage (out_h)
	    add_first_include(cpp_path_h)
	    system_tools.add_c_plus_plus_file(cpp_path_c)
	    sys_runtime_h_and_c(once "c_plus_plus")
	    if c_plus_plus /= Void then
	       from
		  i := c_plus_plus.upper
	       until
		  i < 0
	       loop
		  c_plus_plus.item(i).c_plus_plus_definition
		  i := i - 1
	       end
	    end
	    end_c_linkage (out_c)
	    end_c_linkage (out_h)
	    out_h.disconnect
	    out_c.disconnect
	    ace.set_no_split(no_split_save)
	 end
      end

   echo_make(cmd: STRING) is
      do
	 out_make.put_string(cmd)
	 out_make.put_character('%N')
      end

   out_c: TEXT_FILE_WRITE
	 -- The current *.c output file.

   out_h: TEXT_FILE_WRITE
	 -- The *.h output file.

   in_h: TEXT_FILE_READ
         -- The *.h, when copied in the symbols file

   current_out: TEXT_FILE_WRITE
	 -- Is `out_c' or `out_h'.

   out_make: TEXT_FILE_WRITE is
	 -- The *.make output file.
      once
	 !!Result.make
      end

   no_args_to_eval: BOOLEAN is
	 -- True if there is no C code to produce to eval arguments.
	 -- For example because there are  no arguments or because
	 -- we are inside a switching function for example.
      require
	 smart_eiffel.is_ready
      local
	 code: INTEGER; args: EFFECTIVE_ARG_LIST
      do
	 code := stack_code.item(top)
	 inspect
	    code
	 when C_direct_call, C_check_id, C_create_instruction, C_same_target
	  then
	    args := stack_args.item(top)
	    if args = Void then
	       Result := True
	    else
	       Result := args.side_effect_free
	    end
	 when C_inline_dca then
	    top := top - 1
	    Result := no_args_to_eval
	    top := top + 1
	 else
	    Result := True
	 end
      end

   c_inline_h_mem: FAST_ARRAY[STRING] is
      once
	 !!Result.with_capacity(4)
      end

   se_evobt(rf: RUN_FEATURE; target: EXPRESSION) is
      require
	 rf /= Void
	 target /= Void
	 on_c
      local
	 rt: E_TYPE; p: POSITION
      do
	 sure_void_count := sure_void_count + 1
	 rt := rf.result_type
	 if rt /= Void then
	    if rt.is_reference then
	       -- Because of a Borland C compiler bug we have to add
	       -- this extra cast:
	       out_c.put_string(once "(T0*)")
	    end
	    out_c.put_character('(')
	 end
	 if ace.no_check then
	    out_c.put_string(once "se_evobt")
	    out_c.put_character('(')
	    target.compile_to_c
	    out_c.put_character(',')
	    put_position(target.start_position)
	    out_c.put_character(')')
	 else
	    out_c.put_string(once "/*se_evobt*/")
	    p := target.start_position
	    put_position_comment_on(out_c, p)
	    target.compile_to_c
	    out_c.put_character(',')
	    exceptions_handler.se_evobt
	 end
	 if rt /= Void then
	    out_c.put_character(',')
	    if rt.is_reference then
	       rt.c_initialize
	    else
	       out_c.put_character('M')
	       out_c.put_integer(rt.id)
	    end
	    out_c.put_character(')')
	 end
	 if rt = Void then
	    out_c.put_character(';')
	    out_c.put_character('%N')
	 end
      end

   push_check(rf: RUN_FEATURE; t: EXPRESSION; args: EFFECTIVE_ARG_LIST) is
      require
	 rf /= Void; t /= Void
      do
	 stack_push(C_check_id)
	 stack_rf.put(rf, top)
	 stack_target.put(t, top)
	 stack_args.put(args, top)
      end

   use_switch(up_rf: RUN_FEATURE; run_time_set: RUN_TIME_SET
	      t: EXPRESSION; args: EFFECTIVE_ARG_LIST) is
      require
	 up_rf.run_class.run_time_set = run_time_set
	 run_time_set.count > 1
	 t /= Void
	 on_c
      local
	 rt: E_TYPE; rc: RUN_CLASS; rf: RUN_FEATURE
	 switch: SWITCH; se_tmp_idx: INTEGER; cast: BOOLEAN
      do
	 rt := up_rf.result_type
	 if ace.boost and then stupid_switch(up_rf) then
	    stupid_switch_call_count := stupid_switch_call_count + 1
	    switch_collection.remove(up_rf)
	    out_c.put_string(fz_open_c_comment)
	    out_c.put_character('X')
	    out_c.put_integer(up_rf.current_type.id)
	    out_c.put_string(up_rf.name.to_string)
	    out_c.put_string(fz_close_c_comment)
	    if rt /= Void and then rt.run_type.is_native_array then
	       cast := True
	       out_c.put_string(fz_b7)
	       out_c.put_integer(rt.id)
	       out_c.put_character(')')
	       out_c.put_character('(')
	    end
	    rc := run_time_set.item(1)
	    rf := rc.dynamic(up_rf)
	    push_direct(rf, t, args)
	    rf.mapping_c
	    pop
	    if cast then
	       out_c.put_character(')')
	       out_c.put_character(')')
	    end
	 else
	    switched_call_count := switched_call_count + 1
	    if rt /= Void then
	       se_tmp_idx := se_tmp_open_expanded(rt)
	       -- Because the result of the dispatch function may be 
	       -- a complex expanded.
	    end
	    out_c.put_string(switch.name(up_rf))
	    out_c.put_character('(')
	    if ace.no_check then
	       out_c.put_string(fz_85)
	       put_position(t.start_position)
	       out_c.put_character(',')
	    end
	    t.compile_to_c
	    if args /= Void then
	       out_c.put_character(',')
	       args.compile_to_c(up_rf.arguments)
	    end
	    put_character(')')
	    if rt = Void then
	       out_c.put_string(fz_00)
	    elseif se_tmp_idx >= 0 then
	       se_tmp_close_expanded(se_tmp_idx)
	    end
	 end
      end

   define_initialize_eiffel_runtime(rf3: RUN_FEATURE_3) is
      require
	 on_c
	 rf3.is_root
      local
	 no_check: BOOLEAN; rc: RUN_CLASS; ct: E_TYPE; rf_stdout_flush: RUN_FEATURE
         rf_std_output: RUN_FEATURE
         do_atexit: BOOLEAN
      do
	 no_check := ace.no_check
	 ct := rf3.current_type
	 rc := rf3.run_class
	 echo.put_string(once "Define initialize stuff.%N")
	 smart_eiffel.define_extern_tables

         -- Define atexit() function, if useful (i.e. stdout is used, or
         -- SCOOP, which defines its own atexit methods)

	 rf_stdout_flush := once_routine_pool.std_output_flush_atexit
         do_atexit := rf_stdout_flush /= Void or else smart_eiffel.scoop
	 if do_atexit then
	    put_c_heading(once "void se_atexit(void)")
	    if no_check then
	       out_c.put_string(
		   "[
                 se_frame_descriptor fd={"<atexit wrapper>",0,0,"",1};
                 se_dump_stack ds;
                 ds.fd=&fd;
                 ds.p=0;
                 ds.caller=NULL;
                 ds.exception_origin=NULL;
                 ds.locals=NULL;

                    ]")
	    end
            if rf_stdout_flush /= Void then
	       -- Initialize C with `std_output' first:
               rf_std_output := once_routine_pool.rf_frozen_general(as_std_output)
               out_c.put_string(once "{%NT0*C=")
	       stack_push(C_inside_twin)
	       stack_rf.put(rf_std_output, top)
               rf_std_output.mapping_c
	       pop
               out_c.put_string(fz_00)
	       -- Calling `rf_stdout_flush':
               stack_push(C_switch)
               stack_rf.put(rf_stdout_flush, top)
	       if ace.sedb then
                  -- calling eiffel function flush would result in running
                  -- sedb again whereas the user said s/he wanted to exit.
                  out_c.put_string("if (sedb_status != SEDB_EXIT_MODE) ")
               end
               rf_stdout_flush.mapping_c
               pop
               out_c.put_string(fz_12)
            end
            if smart_eiffel.scoop then
               out_c.put_string(once "scoop_atexit();%N");
            end
	    out_c.put_string(once "}%N")
	 end

         -- Define the SmartEiffel runtime initialization function

	 put_c_heading(once
	        "void initialize_eiffel_runtime(int argc,char*argv[])")
	 if smart_eiffel.scoop then
            out_c.put_string(once "init_scoop_thread();%N")
            out_c.put_string(once
	     "se_init_separate_root(SE_SCOOP_THREAD_TYPE, %"<root>%");%N{%N")
         end
         if no_check then
            if smart_eiffel.scoop then
               out_c.put_string(once
	        "se_subsystem_t* self = se_current_subsystem_thread();%N")
            end
	    out_c.put_string(
               once "[
                se_frame_descriptor irfd={"<runtime init>",0,0,"",1};
                se_dump_stack ds = {NULL,NULL,0,NULL,NULL};
                ds.fd=&irfd;

                     ]")
	    rf3.c_set_dump_stack_top(once "&ds", fz_link)
	 end
	 out_c.put_string(once "se_argc=argc;%Nse_argv=argv;%N")
	 if do_atexit then
	    out_c.put_string(once "atexit(se_atexit);%N")
	 end
	 gc_handler.initialize_runtime
	 exceptions_handler.initialize_runtime
	 if no_check then
	    smart_eiffel.initialize_path_table
	 end
	 if smart_eiffel.generator_used then
	    smart_eiffel.initialize_generator
	 end
	 if smart_eiffel.generating_type_used then
	    smart_eiffel.initialize_generating_type
	 end
	 if not exceptions_handler.used then
            if ace.no_check then
	    out_c.put_string(once "[
               #ifdef SIGINT
               signal(SIGINT,se_signal_handler);
               #endif
               #ifdef SIGTERM
               signal(SIGTERM,se_signal_handler);
               #endif

                                    ]")
            end
	    out_c.put_string(once "[
               #ifdef SIGQUIT
               signal(SIGQUIT,se_signal_handler);
               #endif
               #ifdef SIGILL
               signal(SIGILL,se_signal_handler);
               #endif
               #ifdef SIGABRT
               signal(SIGABRT,se_signal_handler);
               #endif
               #ifdef SIGFPE
               signal(SIGFPE,se_signal_handler);
               #endif
               #ifdef SIGSEGV
               signal(SIGSEGV,se_signal_handler);
               #endif
               #ifdef SIGBUS
               signal(SIGBUS,se_signal_handler);
               #endif
               #ifdef SIGSYS
               signal(SIGSYS,se_signal_handler);
               #endif
               #ifdef SIGTRAP
               signal(SIGTRAP,se_signal_handler);
               #endif
               #ifdef SIGXCPU
               signal(SIGXCPU,se_signal_handler);
               #endif
               #ifdef SIGXFSZ
               signal(SIGXFSZ,se_signal_handler);
               #endif

                                    ]")
	 end
	 manifest_string_pool.c_call_initialize
	 once_routine_pool.c_pre_compute
	 if ace.sedb then
	    out_c.put_string(once "se_general_trace_switch=1;%N")
	 end
	 if not gc_handler.is_off then
	    out_c.put_string(fz_48)
	 end
	 out_c.put_string(once "{%N")
	 gc_handler.declare_allocate_n(rc)
	 out_c.put_string(once "eiffel_root_object=n;%N}%N")
	 if ace.no_check then
	    rf3.c_set_dump_stack_top(fz_null, fz_unlink)
	 end
	 out_c.put_string(fz_12)
         if smart_eiffel.scoop then
            out_c.put_string(fz_12)
         end
      ensure
	 on_c
      end

   check_assertion_mode: STRING

   inspect_level: INTEGER

   inline_level: INTEGER

   check_id(e: EXPRESSION; id: INTEGER) is
	 -- Produce a C expression checking that `e' is not void and
	 -- that `e' is really of type `id'.
	 -- The result of the C expression is the pointer to the
	 -- corresponding Object.
      require
	 e.result_type.run_type.is_reference
	 id > 0
      do
	 if ace.no_check then
	    put_string(once "((T")
	    put_integer(id)
	    put_string(once "*)ci(")
	    put_integer(id)
	    put_character(',')
	    e.compile_to_c
	    put_character(',')
	    put_position(e.start_position)
	    put_string(fz_13)
	    check_id_call_count := check_id_call_count + 1
	 else
	    e.compile_to_c
	    direct_call_count := direct_call_count + 1
	 end
      end

   tmp_string: STRING is
      once
	 !!Result.make(256)
      end

   need_invariant(type_of_target: E_TYPE): RUN_CLASS is
	 -- Give the good RUN_CLASS when `type_of_target' need some
	 -- class invariant checking.
      require
	 type_of_target.is_run_type
      do
	 Result := type_of_target.run_type.run_class
	 if Result.at_run_time and then
	    Result.class_invariant /= Void then
	 else
	    Result := Void
	 end
      end

   split_count: INTEGER
	 -- Number of *.c files.

   path_h: STRING is
      once
	 Result := system_tools.path_h
      ensure
	 Result.has_suffix(h_suffix)
      end

   path_c: STRING is
      once
	 if ace.no_split then
	    Result := path_h.twin
	    Result.remove_last(1)
	    Result.extend('c')
	 else
	    split_count := 1
	    !!Result.make(path_h.count + 4)
	    path_c_in(Result, split_count)
	 end
      ensure
	 Result.has_suffix(c_suffix)
      end

   path_symbols: STRING is
      once
	 Result := path_h.twin
	 Result.remove_last(2)
	 Result.append(system_tools.symb_suffix)
      ensure
         Result.has_suffix(system_tools.symb_suffix)
      end

   path_make: STRING is
      once
	 Result := path_h.twin
	 Result.remove_last(2)
	 Result.append(system_tools.make_suffix)
      ensure
	 Result.has_suffix(system_tools.make_suffix)
      end

   add_first_include(the_first_include: STRING) is
      do
	 put_banner(out_c)
	 add_include_on(out_c, the_first_include)
      end

   put_banner(output: TEXT_FILE_WRITE) is
      require
	 output.is_connected
      do
	 output.put_string(once "/*%NANSI C code generated by ")
	 output.put_string(smart_eiffel.copyright)
	 output.put_string(once "C Compiler options used: ")
	 output.put_string(system_tools.c_compiler_options)
	 output.put_string(once "%N*/%N")
      end

   c_code_saved: BOOLEAN

   get_inline_ms: MANIFEST_STRING is
      local
	 e, o: EXPRESSION; i: IMPLICIT_CAST
      do
	 e := stack_args.item(top).expression(1)
         if e.is_manifest_string then
            Result ?= e
            if Result = Void then
               i ?= e
               if i /= Void then
                  o := i.original_expression
                  Result ?= o
               end
            end
         end
         if Result = Void then
            error_handler.add_position(e.start_position)
            fatal_error("Bad usage of C inlining (argument%
                        % is not a manifest string).")
	 end
      end

   h_connect(h_path: STRING) is
      local
         cc: C_COMPACTOR
      do
         if out_h = Void then
            if compact then
               create cc.make
               if ace.no_check then
                  cc.register_symbol(once "se_frame_descriptor")
                  cc.register_symbol(once "se_dump_stack")
                  cc.register_symbol(once "se_evobt")
                  cc.register_symbol(once "se_print_one_frame")
                  cc.register_symbol(once "se_print_one_frame_in")
                  cc.register_symbol(once "se_print_run_time_stack")
                  cc.register_symbol(once "se_rspf")
                  cc.register_symbol(once "se_require_uppermost_flag")
                  cc.register_symbol(once "se_require_last_result")
                  cc.register_symbol(once "se_error0")
                  cc.register_symbol(once "se_error1")
                  cc.register_symbol(once "se_error2")
                  cc.register_symbol(once "ac_req")
                  cc.register_symbol(once "ac_ens")
                  cc.register_symbol(once "ac_inv")
                  cc.register_symbol(once "ac_insp")
                  cc.register_symbol(once "ac_lvc")
                  cc.register_symbol(once "ac_civ")
                  cc.register_symbol(once "se_signal_handler")
                  cc.register_symbol(once "se_gc_check_id")
                  cc.register_symbol(once "se_stack_size")
                  cc.register_symbol(once "se_position2line")
                  cc.register_symbol(once "se_position2column")
                  cc.register_symbol(once "se_position2path_id")
                  cc.register_symbol(once "se_position")
               end
               out_h := cc
            else
               create {TEXT_FILE_WRITE} out_h.make
            end
         end
         out_h.connect_to(h_path)
      end

   c_connect(c_path: STRING) is
      do
         if out_c = Void then
            if compact then
               create {C_COMPACTOR} out_c.make
            else
               create {TEXT_FILE_WRITE} out_c.make
            end
         end
         out_c.connect_to(c_path)
         if out_c.is_connected then
            echo.put_string(once "Writing %"")
            echo.put_string(c_path)
            echo.put_string(once "%" file.%N")
         else
            echo.w_put_string(once "Cannot write file %"")
            echo.w_put_string(c_path)
            echo.w_put_string(fz_b0)
            die_with_code(exit_failure_code)
         end
      ensure
         out_c.is_connected
      end

   backup_tfw_connect(c_path: STRING) is
      require
	 not ace.no_split
      do
	 tmp_path.copy(c_path)
	 tmp_path.remove_last(2)
	 tmp_path.append(system_tools.object_suffix)
	 if ftools.is_readable(tmp_path) then
	    if ftools.is_readable(c_path) then
	       c_path.put('d', c_path.count)
	    else
	       echo.file_removing(tmp_path)
	    end
	 end
	 c_connect(c_path)
      end

   path_c_in(str: STRING; number: INTEGER) is
      do
	 str.clear_count
	 str.append(path_h)
	 str.remove_last(2)
	 number.append_in(str)
	 str.extend('.')
	 str.extend('c')
      end

   write_make_file_split is
      require
	 not ace.no_split
      local
	 i: INTEGER
	 no_change, recompile: BOOLEAN
	 executable_name, c_name: STRING
      do
	 from
	    no_change := True
	    i := split_count
	 until
	    i = 0
	 loop
	    recompile := True
	    path_c_in(tmp_path, i)
	    tmp_string.copy(tmp_path)
	    tmp_string.put('d', tmp_string.count)
	    if ftools.is_readable(tmp_string) then
	       if ftools.same_files(tmp_path, tmp_string) then
		  echo.put_string(fz_01)
		  echo.put_string(tmp_path)
		  echo.put_string(once "%" not changed.%N")
		  echo.file_removing(tmp_string)
		  recompile := False
	       else
		  echo.file_renaming(tmp_string, tmp_path)
		  tmp_path.remove_last(2)
		  tmp_path.append(system_tools.object_suffix)
		  echo.file_removing(tmp_path)
	       end
	    end
	    if recompile then
	       c_name := once "...This is a local once buffer..."
	       c_name.copy(path_h)
	       c_name.remove_last(2)
	       i.append_in(c_name)
	       c_name.extend('.')
	       c_name.extend('c')
	       echo_make(system_tools.split_mode_c_compiler_command(c_name))
	       no_change := False
	    end
	    i := i - 1
	 end
	 executable_name := ace.executable_name
	 if no_change and then executable_name /= Void then
	    no_change := ftools.is_readable(executable_name)
	 else
	    no_change := False
	 end
	 if no_change and then not system_tools.is_linking_mandatory then
	    executable_is_up_to_date := True
	    echo.put_string(once "Executable is up-to-date %
			    %(no C compilation, no linking done).%N")
	 else
	    tmp_string.copy(path_h)
	    tmp_string.remove_last(2)
	    echo_make(system_tools.split_mode_linker_command(tmp_string,
							     split_count))
	 end
      end

   executable_is_up_to_date: BOOLEAN
	 -- When the executable seems to be already correct (no C
	 -- compilation and no linking is to be done).

   write_make_file_no_split is
      require
	 ace.no_split
      do
	 echo_make(system_tools.no_split_mode_command(path_c))
      end

   common_put_target is
      local
	 rf: RUN_FEATURE; flag: BOOLEAN; e: EXPRESSION; ct: E_TYPE
	 c_name: STRING; unwrap_buffer: STRING; mem_id: INTEGER
      do
	 inspect
	    stack_code.item(top)
	 when C_inside_twin then
	    rf := stack_rf.item(top)
	    ct := rf.current_type
	    if ct.is_reference then
	       out_c.put_character('(')
	       ct.mapping_cast
	       out_c.put_character('R')
	       out_c.put_character(')')
	    else
	       out_c.put_character('&')
	       out_c.put_character('R')
	    end
	 when C_create_instruction, C_create_expression then
	    rf := stack_rf.item(top)
	    if rf.current_type.is_expanded then
	       out_c.put_character('&')
	    end
	    out_c.put_character('n')
	 when C_switch then
	    rf := stack_rf.item(top)
	    flag := call_invariant_start(rf.current_type)
	    out_c.put_string(once "((T")
	    out_c.put_integer(rf.id)
	    out_c.put_string(once "*)C)")
	    if flag then
	       call_invariant_end
	    end
	 when C_expanded_initialize then
	    out_c.put_character('&')
	    e := stack_target.item(top)
	    if e /= Void then
	       e.compile_to_c
	    else
	       c_name := stack_string.item(top)
	       if c_name /= Void then
		  out_c.put_string(c_name)
	       else
		  out_c.put_string(once "n->_")
		  out_c.put_string(stack_rf.item(top).name.to_string)
	       end
	    end
	 when C_inline_one_pc then
	    print_current
	 when C_precursor then
	    out_c.put_character('C')
	 when C_scoop_wrapper then
	    out_c.put_string(once "C->ref")
	 when C_scoop_unwrapper then
	    mem_id := stack_rf.item(top).id
	    unwrap_buffer := once "                "
	    unwrap_buffer.clear_count
            unwrap_buffer.append(once "((T")
            mem_id.append_in(unwrap_buffer)
            unwrap_buffer.append(once "*)((Tw")
            mem_id.append_in(unwrap_buffer)
            stack_rf.item(top).name.mapping_c_in(unwrap_buffer)
            unwrap_buffer.append(once "*)data)->C)")
	    out_c.put_string(unwrap_buffer)
         when C_string_inspector then
            put_inspect
         when C_introspect then
            out_c.put_string(once "*C")
	 end
      end

   put_file(tfr: TEXT_FILE_READ; output: TEXT_FILE_WRITE) is
      require
	 not tfr.end_of_input
      do
	 from
	    tfr.read_character
	 until
	    tfr.end_of_input
	 loop
	    output.put_character(tfr.last_character)
	    tfr.read_character
	 end
	 tfr.disconnect
      ensure
	 not tfr.is_connected
      end

   really_define_c_main(rf3: RUN_FEATURE_3) is
      require
	 not ace.no_main
      local
	 id: INTEGER; rc: RUN_CLASS; ct: E_TYPE; od: BOOLEAN
      do
	 echo.put_string(once "Define C main function.%N")
	 ct := rf3.current_type
	 rc := rf3.run_class
	 id := rc.id
	 system_tools.put_c_main_function_type(out_c)
	 out_c.put_string(once " main(int argc,char*argv[]){%N")
	 if not gc_handler.is_off then
	    out_c.put_string(once "stack_bottom=((void**)(&argc));%N")
	 end
	 out_c.put_string(once "initialize_eiffel_runtime(argc,argv);%N")
	 out_c.put_string(once "{T")
	 out_c.put_integer(id)
	 out_c.put_string(once "*n=eiffel_root_object;%N")
         if smart_eiffel.scoop then
	    out_c.put_string(once "se_subsystem_t* self = n->subsystem;%N")
         end
	 if ace.no_check then
	    out_c.put_string(once "se_frame_descriptor root={%"<system root>%",1,0,%"")
	    tmp_string.clear_count
	    ct.c_frame_descriptor_in(tmp_string)
	    out_c.put_string(tmp_string)
	    out_c.put_string(once "%",1};%N%
			       %se_dump_stack ds;%N%
			       %ds.fd=&root;%N%
			       %ds.current=((void**)(&n));%N")
	    put_position_in_ds(rf3.start_position)
	    out_c.put_string(once "ds.caller=NULL;%Nds.exception_origin=NULL;%Nds.locals=NULL;%N")
            rf3.c_set_dump_stack_top(once "&ds", fz_link);
	 end
	 expanded_attributes(ct)
	 push_create_instruction(rf3, Void)
         od := se_tmp_open_declaration
         if od then
            out_c.put_string(once "se_subsystem_t* self=se_current_subsystem_thread();%N")
         end
	 rf3.mapping_c_root
         if od then
            se_tmp_close_declaration
         end
	 pop
	 if rc.class_invariant /= Void then
	    out_c.put_string(fz_se_i)
	    out_c.put_integer(id)
	    out_c.put_string(once "(&ds,n);%N")
	 end
	 gc_handler.gc_info_before_exit
         if ace.no_check then
            rf3.c_set_dump_stack_top(once "NULL", fz_unlink);
         end
	 system_tools.put_c_main_function_exit(out_c)
      end

   bit_constant_pool: FAST_ARRAY[BIT_CONSTANT]

   fz_se_bit_constant: STRING is "se_bit_constant"

   se_tmp_level: INTEGER

   se_tmp_list: FAST_ARRAY[E_TYPE] is
      once
	 create Result.with_capacity(4)
      end

   fz_base: STRING is "base"

   bunch_counter, bunch_size: INTEGER

   split_c_file_now(new_bunch_size: INTEGER) is
      do
	 split_count := split_count + 1
	 out_c.put_character('%N')
	 end_c_linkage(out_c)
	 out_c.disconnect
	 path_c_in(path_c, split_count)
	 backup_tfw_connect(path_c)
	 begin_c_linkage(out_c)
	 add_first_include(path_h)
	 if current_out /= out_h then
	    current_out := out_c
	 end
	 bunch_counter := 1
	 bunch_size := new_bunch_size
      end

   include_memory: HASHED_SET[STRING]

   put_position_comment_on(output: TEXT_FILE_WRITE; p: POSITION) is
      local
	 i: INTEGER; path: STRING; stop: BOOLEAN
      do
	 if p.is_unknown then
	    output.put_string(once "/*unknown position*/")
	 else
	    output.put_string(fz_open_c_comment)
	    output.put_character('l')
	    output.put_integer(p.line)
	    output.put_character('c')
	    output.put_integer(p.column)
	    path := p.path
	    from
	       i := path.count
	    until
	       stop
	    loop
	       if i <= 1 then
		  output.put_character(' ')
		  stop := True
	       else
		  inspect
		     path.item(i)
		  when '/', '\' then
		     stop := True
		  else
		     i := i - 1
		  end
	       end
	    end
	    from until
	       i > path.count
	    loop
	       output.put_character(path.item(i))
	       i := i + 1
	    end
	    output.put_string(fz_close_c_comment)
	 end
      end
   
end -- C_PRETTY_PRINTER
