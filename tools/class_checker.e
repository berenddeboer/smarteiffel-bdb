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
deferred class CLASS_CHECKER
      --
      -- Common parent of SHORT and CLASS_CHECK
      --
inherit
   COMMAND_LINE_TOOLS

feature {CLASS_CHECKER_VISITOR}

   make_for_visitor is
         -- An empty creator used by `CLASS_CHECKER_VISITOR'
      do
      end

   parents: FIXED_ARRAY[BASE_CLASS] is
         -- From `ace..root_class' up to ANY included.
      once
         create Result.with_capacity(4)
      end

   run_class: RUN_CLASS
	 -- The corresponding one of the class to class_check.

   short_list: SHORT_LIST is
	 -- To be printed by the short command.
      once
         create Result.make
      end

   client: CLASS_NAME
         -- The client for whom the class is class_check'ed (-client flag).
         -- If no client is provided on the command line, the default is ANY.

   format: STRING
	 -- The selected format directory to find hooks files.

   sort: BOOLEAN
	 -- True if the -sort flag is used.

   obsolete_type_string: MANIFEST_STRING
	 -- Non Void when the class to short is itself obsolete.

   output: OUTPUT_STREAM

   root_class_names: FIXED_ARRAY[STRING] is
      once
         create Result.with_capacity(1)
      end

   short: BOOLEAN

   start is
         -- Should be called by the make procedure of short or class_check
      require
         output /= Void
      local
         bc: BASE_CLASS; cn: CLASS_NAME; i: INTEGER
      do
         smart_eiffel.set_short_flag
         parse_arguments

         -- Force client class lookup:
         bc := smart_eiffel.base_class(client)

         -- Set the output stream:
         short_print.set_out_stream(output)

         from
            i := root_class_names.lower
         until
            i > root_class_names.upper
         loop
	    create cn.unknown_position(root_class_names.item(i))
	    bc := smart_eiffel.base_class(cn)
	    obsolete_type_string := bc.obsolete_type_string
            if not smart_eiffel.no_file_for(bc.name.to_string) then
               class_check(bc)
            end
            i := i + 1
         end
      end

   parse_arguments is
      deferred
      ensure
         client /= Void
         format /= Void
         not root_class_names.is_empty
      end

   class_check(bc: BASE_CLASS) is
	 -- Actually check the class `bc'
      local
	 ccl: CREATION_CLAUSE_LIST; name: STRING
         obsolete_flag, file_exist_flag: BOOLEAN
      do
         file_exist_flag := not smart_eiffel.no_file_for(bc.name.to_string)
	 if file_exist_flag then
	    parents.clear
	    parents.add_last(bc)
	    if not short then
	       bc.up_to_any_in(parents)
	    end
	 else
	    name := bc.name.to_string
	    if as_none = name then
	       none_documentation(bc)
	    elseif as_tuple = name then
	       tuple_documentation(bc)
	    elseif as_routine = name then
	       routine_documentation(bc)
	    elseif as_procedure = name then
	       procedure_documentation(bc)
	    elseif as_function = name then
	       function_documentation(bc)
	    elseif as_predicate = name then
	       predicate_documentation(bc)
	    else
	       check -- Forgot this one ?
		  False
	       end
	    end
	 end
	 -- Prepare data:
	 compute_run_class(bc)
	 run_class.runnable_class_invariant
	 -- Print the class interface:
	 short_print.start(format, bc, run_class)
	 if obsolete_type_string /= Void then
      	    obsolete_flag := True
	    obsolete_type_string.set_once_flag(False)
	    obsolete_type_string.short
            short_print.a_character('%N')
	 else
	    ccl := bc.creation_clause_list
	    if ccl = Void or else not ccl.short(client) then
	       short_print.hook(once "hook102")
	    end
	    compute_short_list_for(client)
            if sort then
               if not short_list.is_empty then
                  short_print.hook_or(once "hook200",once "feature(s)%N")
               end
	       short_list.do_sorted_print
	    else
	       -- Nothing to do because features are actually already printed 
	       -- using the order of feature clauses in various source files.
	    end
            short_print.hook(once "hook201")
	 end
	 short_print.finish(obsolete_flag)
      end

   set_format(a_format: like format) is
      do
         format := a_format
      end

   set_client(a_client: STRING) is
      require
         string_aliaser.item(a_client) = a_client
      do
         create client.unknown_position(a_client)
      end

   compute_run_class(bc: BASE_CLASS) is
      local
         ct, t: E_TYPE; constraints: DICTIONARY[E_TYPE, STRING]
	 i: INTEGER; fgl: FORMAL_GENERIC_LIST; sp: POSITION
	 fga: FORMAL_GENERIC_ARG
      do
	 -- Creates the `constraints' substitution dictionary first:
	 fgl := bc.formal_generic_list
	 if fgl /= Void then
	    from
	       sp := bc.name.start_position
	       i := 1
	       create constraints.make
	    until
	       i > fgl.count
	    loop
	       fga := fgl.item(i)
	       t := fga.constraint
	       if t = Void then
		  constraints.put(create {TYPE_ANY}.make(sp),
				  fga.name.to_string)
	       elseif t.base_class.formal_generic_list = Void then
		  constraints.put(t, fga.name.to_string)
	       end
	       i := i + 1
	    end
	 end
         ct := run_type_for(bc, sp, constraints)
         run_class := ct.run_class
      end

   compute_short_list_for(cn: CLASS_NAME) is
      local
         i: INTEGER; bc: BASE_CLASS; rc: RUN_CLASS; fcl: FEATURE_CLAUSE_LIST
      do
         from
            i := parents.upper
            rc := run_class
         until
            i < 0
         loop
            bc := parents.item(i)
            fcl := bc.feature_clause_list
            if fcl /= Void then
               fcl.for_short(bc.name, False, short_list, rc, cn)
            end
            i := i - 1
         end
      end

   fatal_bad_usage is
      do
         system_tools.bad_use_exit(Current)
      end

feature {NONE}

   run_type_for(bc: BASE_CLASS; sp: POSITION
		constraints: DICTIONARY[E_TYPE, STRING]): E_TYPE is
	 -- Create a valid runnable one. The `constraints' dictionary
	 -- is used to substitute nested generic formal arguments.
      local
	 bcn: STRING; fgl: FORMAL_GENERIC_LIST
         t: E_TYPE; gl: ARRAY[E_TYPE]; i: INTEGER; fga: FORMAL_GENERIC_ARG
      do
	 bcn := bc.name.to_string
	 fgl := bc.formal_generic_list
	 if as_any = bcn then
            create {TYPE_ANY} Result.make(sp)
         elseif as_native_array = bcn then
            create {TYPE_CHARACTER} t.make(sp)
            create {TYPE_NATIVE_ARRAY} Result.make(sp, t)
         elseif as_array = bcn then
            create {TYPE_ANY} t.make(sp)
            create {TYPE_ARRAY} Result.make(sp, t)
         elseif as_integer_8 = bcn then
            create {TYPE_INTEGER} Result.integer_8(sp)
         elseif as_integer_16 = bcn then
            create {TYPE_INTEGER} Result.integer_16(sp)
         elseif as_integer_32 = bcn then
            create {TYPE_INTEGER} Result.integer_32(sp)
         elseif as_integer = bcn then
            create {TYPE_INTEGER} Result.integer(sp)
         elseif as_integer_64 = bcn then
            create {TYPE_INTEGER} Result.integer_64(sp)
         elseif as_integer_general = bcn then
            create {TYPE_INTEGER} Result.integer_general(sp)
         elseif as_real = bcn then
            create {TYPE_REAL} Result.make(sp)
         elseif as_double = bcn then
            create {TYPE_DOUBLE} Result.make(sp)
         elseif as_character = bcn then
            create {TYPE_CHARACTER} Result.make(sp)
         elseif as_boolean = bcn then
            create {TYPE_BOOLEAN} Result.make(sp)
         elseif as_pointer = bcn then
            create {TYPE_POINTER} Result.make(sp)
         elseif as_string = bcn then
            create {TYPE_STRING} Result.make(sp)
         elseif as_none = bcn then
            create {TYPE_NONE} Result.make(sp)
         elseif fgl /= Void then
            from
               i := 1
               create gl.with_capacity(fgl.count, 1)
            until
               i > fgl.count
            loop
               fga := fgl.item(i)
	       t := constraints.reference_at(fga.name.to_string)
	       if t = Void then
		  t := fga.constraint
		  t := run_type_for(t.base_class, sp, constraints)
               end
               gl.add_last(t)
               i := i + 1
            end
            create {TYPE_GENERIC} Result.make(bc.name, gl)
         else
            create {TYPE_CLASS} Result.make(bc.name)
         end
	 Result := Result.to_runnable(create {TYPE_ANY}.make(sp))
      ensure
	 Result.is_run_type
      end

   none_documentation(bc: BASE_CLASS) is
      require
	 bc.name.to_string = as_none
      local
	 comment: COMMENT
      do
	 create comment.fake_comment(bc,
         "[

          Note: actually, the NONE class is an artefact of the Eiffel language
          definition. The NONE class is supposed to inherit of all existing
          classes of the entire system.
          Actually, the NONE class cannot be written (i.e. there is no file for
          this class and this class is magically written by the compiler).

          ]")
	 bc.set_heading_comment2(comment)
       end

   tuple_documentation(bc: BASE_CLASS) is
      require
	 bc.name.to_string = as_tuple
      local
	 comment: COMMENT
      do
	 create comment.fake_comment(bc,
         "[

          The main purpose of the TUPLE class is allow you to manipulate Eiffel
          agents and to avoid in some cases to write simple record-like classes.
          For a good start with TUPLE class, you might consider to have a look
          in directory SmartEiffel/tutorial/tuple.
          For more details about agents, see also ROUTINE, PROCEDURE, FUNCTION
          and PREDICATE as well as examples from SmartEiffel/tutorial/agent.

          ]")
	 bc.set_heading_comment2(comment)
       end

   routine_documentation(bc: BASE_CLASS) is
      require
	 bc.name.to_string = as_routine
      local
	 comment: COMMENT
      do
	 create comment.fake_comment(bc,
         "[

          The main purpose of the ROUTINE class is allow you to manipulate Eiffel
          code parts, also known as agents using the Eiffel terminology.
          The only thing you can do on a ROUTINE object is to run the corresponding
          Eiffel code by using the `call' procedure.
          For more details about agents, you might consider first to have a look
          at examples from SmartEiffel/tutorial/agent directory.

          Note: there is no file for this class (this class is magically provided
          by the compiler).

          ]")
	 bc.set_heading_comment2(comment)
       end

   procedure_documentation(bc: BASE_CLASS) is
      require
	 bc.name.to_string = as_procedure
      local
	 comment: COMMENT
      do
	 create comment.fake_comment(bc,
         "[

          The main purpose of the PROCEDURE class is allow you to manipulate Eiffel
          code parts, also known as agents using the Eiffel terminology.
          The only thing you can do on a PROCEDURE object is to run the corresponding
          Eiffel code by using the `call' procedure.
          For more details about agents, you might consider first to have a look
          at examples from SmartEiffel/tutorial/agent directory.

          Note: there is no file for this class (this class is magically provided
          by the compiler).

          ]")
	 bc.set_heading_comment2(comment)
       end

   function_documentation(bc: BASE_CLASS) is
      require
	 bc.name.to_string = as_function
      local
	 comment: COMMENT
      do
	 create comment.fake_comment(bc,
         "[

          The main purpose of the FUCNTION class is allow you to manipulate Eiffel
          code parts, also known as agents using the Eiffel terminology.
          The only thing you can do on a FUCNTION object is to run the corresponding
          Eiffel code by using the `item' procedure.
          For more details about agents, you might consider first to have a look
          at examples from SmartEiffel/tutorial/agent directory.

          Note: there is no file for this class (this class is magically provided
          by the compiler).

          ]")
	 bc.set_heading_comment2(comment)
       end

   predicate_documentation(bc: BASE_CLASS) is
      require
	 bc.name.to_string = as_predicate
      local
	 comment: COMMENT
      do
	 create comment.fake_comment(bc,
         "[

          The main purpose of the PREDICATE class is allow you to manipulate Eiffel
          code parts, also known as agents using the Eiffel terminology.
          The only thing you can do on a PREDICATE object is to run the corresponding
          Eiffel code by using the `call' procedure.
          For more details about agents, you might consider first to have a look
          at examples from SmartEiffel/tutorial/agent directory.

          Note: there is no file for this class (this class is magically provided
          by the compiler).

          ]")
	 bc.set_heading_comment2(comment)
       end

invariant

   out /= Void

end
