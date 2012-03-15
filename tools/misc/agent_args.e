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
class AGENT_ARGS

inherit
   GLOBALS
   VISITABLE
   HASHABLE redefine is_equal end

creation {AGENT_POOL} make

feature

   hash_code: INTEGER is
      do
	 Result := signature.hash_code
      end

   is_equal(other: like Current): BOOLEAN is
      do
	 Result := signature.is_equal(other.signature)
      end

   signature: STRING
	 -- Computed using `arguments' and `result_type'.

feature {AGENT_POOL}

   result_type: E_TYPE

   c_define_agent_launcher is
      require
	 cpp.on_c
      local
	 boost: BOOLEAN
      do
	 boost := c_define_agent_launcher_heading(once "(live)")
	 buffer.clear
         if not boost then
            buffer.append(
            once "[
                se_frame_descriptor fd={"<agent-call-wrapper-1>",0,0,"",1};
                se_dump_stack ds;
                ds.fd=&fd;
                ds.p=0;
                ds.caller=caller;
                ds.exception_origin=NULL;
                ds.locals=NULL;

              ]")
         end
	 buffer.append(once "switch(((se_agent0*)a)->creation_mold_id){%N")
	 agent_pool.c_switch_in(buffer, type_of_agent, result_type)
	 if not boost then
	    buffer.append(once "[
               default:
               error0("Internal error in agent launcher.",NULL);
                                ]")
	 end
	 buffer.append(once "}%N}%N")
	 cpp.put_string(buffer)
      ensure
	 cpp.on_c
      end

   c_define_missing_agent_launcher is
      local
	 boost: BOOLEAN
      do
	 boost := c_define_agent_launcher_heading(once "(missing)")
	 buffer.clear
	 if not boost then
	    buffer.append("error0(%"Missing agent.%",NULL);%N")
	 end
	 buffer.append("}%N")
	 cpp.put_string(buffer)
      end
   
   jvm_define(actual: BOOLEAN) is
	 -- Define both the deferred wrapper or the `actual' definition.
      local
	 flags, i: INTEGER; descripteur: STRING
	 ca: CODE_ATTRIBUTE; cp: CONSTANT_POOL
      do
	 ca := code_attribute
	 cp := constant_pool
	 flags := 9
	 descripteur := once "...................."
	 descripteur.clear
	 descripteur.extend('(')
	 if types /= Void then
	    from 
	       i := 1
	    until
	       i > types.count
	    loop
	       types.item(i).jvm_descriptor_in(descripteur)
	       i := i + 1
	    end
	 end
	 descripteur.append(")V")
	 method_info.start(flags,signature,descripteur)
	 if actual then
	    ca.opcode_return
	 else
	    ca.opcode_return
	 end
	 method_info.finish
      end

feature {AGENT_INSTRUCTION, AGENT_EXPRESSION}

   c_agent_definition_call(agent_target: EXPRESSION) is
	 -- Generate the C code to launch the execution of the `agent_target'.
      require
	 agent_target /= Void
      local
	 boost: BOOLEAN; position: POSITION
      do
	 position := agent_target.start_position
	 agent_pool.check_for_callee(Current,position)
	 if result_type = Void then
	    if ace.no_check then
	       cpp.put_trace_or_sedb_instruction(position)
	    end
         else
	    -- *** Dominique -> Cyril (5/6/2003)
	    -- I do not think we have to cast here, but, may be 
	    -- actually the type of the call_* wrapper is wrong ??
            -- result_type.mapping_cast
	 end
	 cpp.put_string(signature)
	 cpp.put_character('(')
	 boost := ace.boost
	 if not boost then
	    cpp.put_string(once "&ds,vc(")
	 end
	 agent_target.compile_to_c
	 if not boost then
	    cpp.put_character(',')
	    cpp.put_position(agent_target.start_position)
	    cpp.put_character(')')
	 end
	 if fake_tuple.count > 0 then
	    cpp.put_character(',')
	    fake_tuple.compile_to_c
	 end
	 cpp.put_character(')')
      end

   jvm_agent_definition_call(agent_target: EXPRESSION) is
      require
	 agent_target /= Void
      local
	i, count, idx:INTEGER; cp: CONSTANT_POOL; ca: CODE_ATTRIBUTE
	class_name, descripteur: STRING; place:INTEGER
      do
	ca:=code_attribute
	cp:=constant_pool
	place:=0
	agent_target.compile_to_jvm
	fake_tuple.compile_to_jvm
	descripteur:="("
	if types /= Void then
	  count := types.count
	  from i := 1 until i > count
	  loop
	    types.item(i).jvm_descriptor_in(descripteur)
            descripteur.remove_last(1)
	    place:=place+types.item(i).jvm_stack_space
	    i := i + 1
	  end
	descripteur:=descripteur+")"
	end
	if (result_type /= Void) then
	  result_type.jvm_descriptor_in(descripteur)
	else
          descripteur:=descripteur+"V"
	end
	class_name:="_agent"
	idx:=cp.idx_methodref3(class_name,signature,descripteur)
	ca.opcode_invokevirtual(idx,place)
      end

feature {AGENT_ARGS_VISITOR}

   accept(visitor: AGENT_ARGS_VISITOR) is
      do
         visitor.visit_agent_args(Current)
      end

feature {NONE}

   type_of_agent: TYPE_OF_AGENT
   
   types: ARRAY[E_TYPE]

   fake_tuple: FAKE_TUPLE

   debug_info: STRING

   make(toa: like type_of_agent;
	args: EFFECTIVE_ARG_LIST; rt: like result_type) is
	 -- Also check type conformance of `args' with `open'.
      require
	 toa /= Void
	 args.count = 1
      local
	 i, count: INTEGER; e, implicit_cast: EXPRESSION; t, ft: E_TYPE
	 open: TYPE_TUPLE
      do
	 type_of_agent := toa
	 open := toa.open
	 result_type := rt
	 create signature.make(32)
	 signature.append(as_call)
	 signature.extend('_')
	 debug
	    debug_info := ("agent_args:").twin
	 end
	 fake_tuple ?= args.expression(1)
	 if fake_tuple = Void then
	    error_handler.add_position(args.expression(1).start_position)
	    error_handler.append(
               "Only the explicit manifest TUPLE notation (i.e. the square %
	       %bracketed notation) is allowed here. If you cannot work %
	       %around, please contact us on our mailing list %
	       %(SmartEiffel@loria.fr).")
	    error_handler.print_as_fatal_error
	 else
	    from
	       count := fake_tuple.count
	       if count > 0 then
		  create types.make(1, count)
	       end
	       if count /= open.count then
		  error_handler.add_position(open.start_position)
		  error_handler.add_position(args.start_position)
		  error_handler.append(
		     "Bad number of open arguments for agent call.")
		  error_handler.print_as_fatal_error
	       end
	       i := 1
	    until
	       i > count
	    loop
	       e := fake_tuple.expression(i)
	       ft := open.type(i)
	       t := e.result_type.run_type
	       if t.is_a(ft) then
		  implicit_cast := assignment_handler.implicit_cast(e, ft)
		  if e /= implicit_cast then
		     e := implicit_cast
		     t := e.result_type
		     fake_tuple.set_expression(e, i)
		  end
		  assignment_handler.assignment(e.start_position,
						e.result_type,
						ft)
	       else
		  error_handler.add_position(ft.start_position)
		  error_handler.add_position(e.start_position)
		  error_handler.append(
		  "Incompatible open arguments for agent call.")
		  error_handler.print_as_fatal_error
	       end
	       extend_signature(t)
	       types.put(t, i)
	       i := i + 1
	    end
	 end
	 if rt = Void then
	    signature.extend('v')
	 else
	    extend_signature(rt)
	 end
      ensure
	 type_of_agent = toa
	 result_type = rt
      end

   c_define_agent_launcher_heading(tag: STRING): BOOLEAN is
      local
	 boost: BOOLEAN; i, count: INTEGER
      do
	 echo.put_string(once "Defining ")
	 echo.put_string(tag)
	 echo.put_string(once " agent wrapper: ")
	 echo.put_string(signature)
	 echo.put_string(once "%N")
	 boost := ace.boost
	 buffer.clear
	 if result_type = Void then
	    buffer.append(fz_void)
	 else
	    result_type.c_type_for_result_in(buffer)
	 end
	 buffer.extend(' ')
	 buffer.append(signature)
	 buffer.extend('(')
	 if not boost then 
	    buffer.append(once "se_dump_stack*caller,")
	 end
	 buffer.append(once "/*agent*/T0*a")
	 if types /= Void then
	    count := types.count
	    from i := 1 until i > count
	    loop
	       buffer.extend(',')
	       types.item(i).c_type_for_argument_in(buffer)
	       buffer.extend(' ')
	       buffer.extend('a')
	       i.append_in(buffer)
	       i := i + 1
	    end
	 end
	 buffer.extend(')')
	 cpp.put_c_heading(buffer)
	 Result := boost
      end
   
   extend_signature(t: E_TYPE) is
      do
	 debug
	    debug_info.append(t.run_time_mark)
	    debug_info.extend(' ')
	 end
	 if t.is_reference then
	    signature.extend('r')
	    signature.extend('0')
	 else
	    signature.extend('e')
	    t.id.append_in(signature)
	 end
      end

   buffer: STRING is
      once
	 create Result.make(256)
      end

invariant

   not signature.is_empty

   fake_tuple /= Void

end -- AGENT_ARGS
