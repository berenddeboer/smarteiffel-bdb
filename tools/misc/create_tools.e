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
--                           - University of Nancy 1 - FRANCE
-- Copyright(C) 2003:      INRIA - LORIA (INRIA Lorraine) - I.U.T. Charlemagne
--                           - University of Nancy 2 - FRANCE
--
--                 Dominique COLNET, Suzanne COLLIN, Olivier ZENDRA,
--                           Philippe RIBET, Cyril ADRIAN
--
-- http://SmartEiffel.loria.fr - SmartEiffel@loria.fr
--
deferred class CREATE_TOOLS
--
-- Common root for OLD_CREATION, CREATE_INSTRUCTION and CREATE_EXPRESSION
--

inherit
   GLOBALS
   VISITABLE

feature

   frozen afd_check is
      local
         args: like arguments
      do
         args := arguments
         if args /= Void then
            args.afd_check
         end
      end

   frozen safety_check is
      local
         args: like arguments
      do
         args := arguments
         if args /= Void then
            args.safety_check
         end
      end

feature {CREATE_TOOLS_VISITOR}

   accept(visitor: CREATE_TOOLS_VISITOR) is
      deferred
      end

feature {NONE}

   start_position: POSITION

   type: E_TYPE
         -- Explicit optional generator name if any.

   writable: EXPRESSION
         -- If any, the target of the creation call.

   call: PROC_CALL
         -- Optional initialisation call if any. (The target of `call' is
         -- the `writable' entity.)

   run_feature: RUN_FEATURE
         -- When checked, if any, the only one corresponding creation
         -- procedure.

   current_type: E_TYPE
         -- Not Void when checked in this context.

   check_create_clause(t: E_TYPE) is
         -- Where `t' is the TYPE to create.
      require
         t.is_run_type
      local
         fn: FEATURE_NAME; bottom, top: BASE_CLASS; args: like arguments
         arg_count: INTEGER; w: like writable; rc: RUN_CLASS

         bf: E_FEATURE; -- DEBUG
      do
         rc := t.run_class
         if call = Void then
            run_feature := rc.a_default_create
            if run_feature /= Void then
            elseif t.base_class.has_creation_clause then
               error_handler.append("Creation clause exists for ")
               error_handler.add_type(t,". ")
               error(start_position,"You must use a constructor.")
            end
         else
            fn := call.feature_name
            top := fn.start_position.base_class
            bottom := t.base_class
            if t.is_like_current then
               check
                  bottom = top or else bottom.is_subclass_of(top)
               end
               fn := bottom.new_name_of(top,fn)
               if fn = Void then
                  fn := call.feature_name
                  error_handler.feature_not_found(fn)
                  error_handler.append(" Type to create is %"")
                  error_handler.append(t.run_time_mark)
                  fatal_error(fz_03)
               end
            end
            run_feature := rc.get_feature(fn)
            if run_feature = Void then
               cp_not_found(fn)
            else
               bf := run_feature.base_feature
               run_feature.base_feature.check_obsolete(fn.start_position)
            end
            if smart_eiffel.short_flag then
            elseif not rc.base_class.has_creation(fn) then
               error_handler.add_position(call.feature_name.start_position)
               error_handler.add_position(fn.start_position)
               error_handler.append(fn.to_string)
               error_handler.append(" is not in the creation list of ")
               error_handler.add_type(t,fz_dot_blank)
               error_handler.print_as_fatal_error
            end
            run_feature.run_class.add_client(current_type.run_class)
            if run_feature.result_type /= Void then
               error_handler.add_position(run_feature.start_position)
               error_handler.add_position(fn.start_position)
               fatal_error(fz_ffinap)
            end
            arg_count := arguments_count
            if arg_count > 0 then
               args := arguments.to_runnable(current_type)
               if args = Void then
                  error(call.arguments.start_position,fz_bad_arguments)
               end
            end
            smart_eiffel.argument_passing_check(call.start_position,
                                                args,run_feature)
            w := writable
            if w = Void then
               w := call.target
            end
            call := call.runnable_create(current_type,w,args,run_feature)
         end
      end

   arguments: EFFECTIVE_ARG_LIST is
      do
         if call /= Void then
            Result := call.arguments
         end
      end

   arguments_count: INTEGER is
      do
         if call /= Void then
            Result := call.arg_count
         end
      end

   cp_not_found(fn: FEATURE_NAME) is
      do
         error_handler.add_position(call.feature_name.start_position)
         error_handler.add_position(fn.start_position)
         fatal_error("Creation procedure not found.")
      end

   check_created_type(t: E_TYPE) is
      require
         t.is_run_type
      local
         rt: E_TYPE; bc1, bc2: BASE_CLASS
      do
         rt := t.run_type
         if smart_eiffel.short_flag then
         elseif rt.base_class.is_deferred then
            error_handler.add_type(rt," is deferred. ")
            warning(start_position,"Cannot create object.")
         end
         if t.is_formal_generic then
            -- Because `t' may be inherited:
            bc1 := start_position.base_class
            bc2 := t.written_in.base_class
            if bc1 = bc2 then
               error_handler.add_position(start_position)
               error_handler.append("Creation call on formal generic type (")
               error_handler.add_type(t,").")
               error_handler.print_as_fatal_error
            end
         end
         if t.is_separate then
            smart_eiffel.set_scoop
         end
         rt.run_class.set_at_run_time
      end

   check_explicit_type is
      require
         type /= Void
      local
         t, destination_type: E_TYPE
      do
         t := type.to_runnable(current_type)
         if t = Void or else not t.is_run_type then
            error_handler.add_position(type.start_position)
            fatal_error("Invalid explicit type.")
         else
            type := fix_type(t)
         end
         if writable /= Void then
            destination_type := writable.result_type
            if not type.is_a(destination_type) then
               fatal_error(" Bad explicit type mark.")
            end
            if type.run_time_mark /= destination_type.run_time_mark then
               assignment_handler.assignment(type.start_position,
                                             type,
                                             destination_type)
            end
         end
      end

   compile_to_jvm0(t: E_TYPE) is
         -- Push the new object with default initialization.
      require
         t /= Void
      local
         dummy: INTEGER
      do
         if t.is_reference then
            t.run_class.jvm_basic_new
         else
            dummy := t.jvm_push_default
         end
      end

   common_once_pre_computable(t: like type): BOOLEAN is
         -- Common part for CREATE_INSTRUCTION and CREATE_EXPRESSION.
      require
         t /= Void
      local
         rfct: E_TYPE; rfn, rfctbcn: STRING
      do
         -- Check first that the created type `t' is really static:
         Result := t.is_run_type and then (t.run_type = t)
         if Result and then run_feature /= Void then
            -- Hard coded creation list :-(
            rfct := run_feature.current_type
            rfctbcn := rfct.base_class.name.to_string
            rfn := run_feature.name.to_string
            if as_make= rfn then
               Result := (
                          as_array = rfctbcn  or else
                          as_fixed_array = rfctbcn or else
                          as_string = rfctbcn or else
                          as_dictionary = rfctbcn or else
                          as_text_file_read = rfctbcn or else
                          as_text_file_write = rfctbcn
                          )
            elseif as_blank = rfn then
               Result := (
                          as_string = rfctbcn
                          )
            elseif as_with_capacity = rfn then
               Result := (
                          as_array = rfctbcn or else
                          as_fixed_array = rfctbcn or else
                          as_dictionary = rfctbcn
                          )
            else
               Result := False
            end
         end
      end

   fix_type (t: E_TYPE): E_TYPE is
         -- Correct `t' for hardwired substitutions
         -- Particularly, DICTIONARY/SET -> HASHED_DICTIONARY/HASHED_SET
      require
          t /= Void
          t.is_run_type
      do
         -- Handle DICTIONARY/SET -> HASHED_xxx substitution
         if t.base_class_name.to_string.is_equal ("DICTIONARY") then
             error_handler.add_position (start_position)
             if type = Void then 
                error_handler.add_position (t.start_position)
             end
             error_handler.append ("DICTIONARY will be deferred in SmartEiffel 2. %
                                   %You should use HASHED_DICTIONARY instead. This %
                                   %instruction will actually create a HASHED_DICTIONARY.")
             error_handler.print_as_warning
             Result := fix_dictionary_type (t)
         elseif t.base_class_name.to_string.is_equal ("SET") then
             error_handler.add_position (start_position)
             if type = Void then 
                error_handler.add_position (t.start_position)
             end
             error_handler.append ("SET will be deferred in SmartEiffel 2. %
                                   %You should use HASHED_SET instead. This %
                                   %instruction will actually create a HASHED_SET.")
             error_handler.print_as_warning
             Result := fix_set_type (t)
         else
             Result := t
         end
      end

   fix_dictionary_type (t: E_TYPE): E_TYPE is
      require
         t /= Void
         t.is_run_type
         t.base_class_name.to_string.is_equal ("DICTIONARY")
      local
         g: TYPE_GENERIC
      do
         tmp_name.reset (t.start_position)
         tmp_name.append (once "HASHED_DICTIONARY")
         g ?= t
         create {TYPE_GENERIC}Result.make (tmp_name.to_class_name, g.generic_list)
         Result := Result.to_runnable (current_type)
      end
   
   fix_set_type (t: E_TYPE): E_TYPE is
      require
         t /= Void
         t.is_run_type
         t.base_class_name.to_string.is_equal ("SET")
      local
         g: TYPE_GENERIC
      do
         tmp_name.reset (t.start_position)
         tmp_name.append (once "HASHED_SET")
         g ?= t
         create {TYPE_GENERIC}Result.make (tmp_name.to_class_name, g.generic_list)
         Result := Result.to_runnable (current_type)
      end

   tmp_name: TMP_NAME
   
invariant

   not start_position.is_unknown

end -- CREATE_TOOLS
