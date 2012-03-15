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
class AGENT_POOL
   --
   -- Singleton object in charge of agents.
   -- This singleton is shared via the GLOBALS.`agent_pool' once function.
   --

inherit
   GLOBALS
   VISITABLE

feature {E_AGENT}

   register(e_agent: E_AGENT): INTEGER is
	 -- Registration of an "agent ..." creation call. The registered one
	 -- gets it's `creation_mold_id' as the `Result' of this function.
      local
	 model: E_AGENT
      do
	 if agent_set = Void then
	    create agent_set.make
	 end
	 model := agent_set.reference_at(e_agent)
	 if model = Void then
	    agent_set.add(e_agent)
	    Result := agent_set.count
	 else
	    Result := model.creation_mold_id
	 end
      end

feature {SMART_EIFFEL}

   falling_down is
      local
         i: INTEGER
      do
	 if agent_set /= Void then
	    from
	       i := agent_set.lower
	    until
	       i > agent_set.upper
	    loop
	       agent_set.item(i).falling_down
	       i := i + 1
	    end
	 end
      end

   c_header_pass1 is
      require
         cpp.on_h
      do
         if agent_set /= Void then
	    cpp.put_string(once "[
               typedef union _se_agent se_agent;
               typedef struct _se_agent0 se_agent0;

                                 ]")
	 end
      ensure
         cpp.on_h
      end

   c_define_missing_agent_launcher is
      local
	 i: INTEGER; agent_args: AGENT_ARGS
      do
	 from
	    i := 1
	 until
	    i > missing_call_set.count
	 loop
	    agent_args := missing_call_set.item(i)
	    agent_args.c_define_missing_agent_launcher
	    i := i + 1
	 end
      end

   customize_jvm_runtime is
      do
	 -- *** ???? ***
      end

feature {JVM}

   jvm_define_deferred_methods is
      local
	 i: INTEGER
      do
	 method_info.add_init(fz_java_lang_object)
	 from
	    i := 1
	 until
	    i > agent_call_set.count
	 loop
	    agent_call_set.item(i).jvm_define(False)
	    i := i + 1
	 end
	 method_info.finish
      end

   ajout_call_full(i:INTEGER) is
	 -- *** NOM MOCHE ***
      do
	 method_info.add_init(fz_java_lang_object)
	 agent_call_set.item(i).jvm_define(True)
	 method_info.finish
      end

feature {AGENT_INSTRUCTION, AGENT_EXPRESSION}

   register_agent_call(args: EFFECTIVE_ARG_LIST
		       rf: RUN_FEATURE): AGENT_ARGS is
	 -- Where `rf' is the `call' or the `item' feature.
      require
	 args.count = 1
      local
	 toa: TYPE_OF_AGENT
      do
	 check
	    rf.name.to_string = as_item or rf.name.to_string = as_call
	 end
	 toa ?= rf.current_type
	 create Result.make(toa, args, rf.result_type)
	 agent_call_set.add(Result)
      ensure
	 Result /= Void
      end

feature {C_PRETTY_PRINTER}

   customize_c_runtime is
      require
	 cpp.on_h
      local
	 i: INTEGER; boost: BOOLEAN; agent_args: AGENT_ARGS
      do
	 boost := ace.boost
	 if agent_set /= Void then
	    cpp.put_string(once "[
               /*The generic se_agent0 definition:*/
               struct _se_agent0{
               Tid id;
               Tid creation_mold_id;
               void*(*afp)(
				 ]")
	    if not boost then
	       cpp.put_string(once "se_dump_stack*,")
	    end
	    cpp.put_string(once "se_agent*);};%N")
	    from
	       i := agent_set.lower
	    until
	       i > agent_set.upper
	    loop
	       agent_set.item(i).c_define_type_1(boost)
	       i := i + 1
	    end
	    cpp.put_string(once "union _se_agent{T0 s0;se_agent0 u0;")
	    from
	       i := agent_set.lower
	    until
	       i > agent_set.upper
	    loop
	       agent_set.item(i).c_define_type_2
	       i := i + 1
	    end
	    cpp.put_string(once "};%N")
            cpp.sys_runtime_h_and_c(once "agents")
	    cpp.swap_on_c
	    echo.print_count(once "Agent definition wrapper", agent_set.count)
	    from
	       i := agent_set.lower
	    until
	       i > agent_set.upper
	    loop
	       agent_set.item(i).c_define_function(boost)
	       i := i + 1
	    end
	    echo.print_count(once "Agent call wrapper", agent_call_set.count)
	    from
	       i := 1
	    until
	       i > agent_call_set.count
	    loop
	       agent_args := agent_call_set.item(i)
	       agent_definition_set.add(agent_args.signature)
	       agent_args.c_define_agent_launcher
	       i := i + 1
	    end
	    cpp.swap_on_h
	 end
      ensure
	 cpp.on_h
      end

feature {GC_HANDLER}

   gc_info_in(body: STRING) is
         -- Produce C code to print GC information.
      do
         if agent_set /= Void then
	    body.append(once "[
               if(gc_info_nb_agent)
                  fprintf(SE_GCINFO,
                  "%d\tagent(s) created. (store_left=%d).\n",
                  gc_info_nb_agent,store_left_agent);

                              ]")
	 end
      end

feature {AGENT_ARGS}

   c_switch_in(buffer: STRING; type_of_agent: TYPE_OF_AGENT; rt: E_TYPE) is
      local
	 i, argi, open1_count, open2_count, id: INTEGER; e_agent: E_AGENT
	 toa: TYPE_OF_AGENT; base1, oat1, oat2: E_TYPE;
	 open1, open2: TYPE_TUPLE; match: BOOLEAN
      do
	 if agent_set /= Void then
	    from
	       i := agent_set.lower
	       base1 := type_of_agent.base
	       open1 := type_of_agent.open
	       open1_count := open1.count
	       buffer.extend('%N')
	    until
	       i > agent_set.upper
	    loop
	       e_agent := agent_set.item(i)
	       toa := e_agent.result_type
	       id := e_agent.creation_mold_id
	       -- Does this `e_agent' `match' the prototype:
	       match := False
	       open2 := toa.open; open2_count := open2.count
	       if open1_count >= open2_count then
		  -- (Because we allow to drop some effective args.)
		  from
		     match := True
		     argi := open2_count
		  until
		     not match or else argi <= 0
		  loop
		     oat1 := open1.type(argi)
		     oat2 := open2.type(argi)
		     if oat1.is_reference then
			match := oat2.is_reference
		     elseif oat1.is_a(oat2) then
		        -- expanded types only match when they are the same...
		        -- Note that this means that INTEGER does not match ANY
		        -- This is based on SE 2.x behaviour (dmoisset, August 21 2005)
		        match := oat1.run_time_mark = oat2.run_time_mark
		     else
			error_handler.cancel
			match := False
		     end
		     argi := argi - 1
		  end
	       end
	       if match and then rt /= Void then
		  match := toa.res /= Void
	       end
	       -- (End of `match' computation.)
	       if match then
		  buffer.append(once "case ")
		  id.append_in(buffer)
		  comment_in(buffer, toa.run_time_mark)
		  buffer.append(once ":{%N")
		  if rt /= Void then
		     buffer.append(once "return(")
		     rt.c_type_for_result_in(buffer)
		     buffer.append(fz_22)
		  end
		  buffer.append(once "((se_agent")
		  id.append_in(buffer)
		  buffer.append(once "*)a)->afp(")
		  if not ace.boost then buffer.append(once "&ds,") end
		  buffer.append(once "((/*agent*/void*)a)")
		  from
		     argi := 1
		  until
		     argi > open2_count
		  loop
		     buffer.extend(',')
		     buffer.extend('a')
		     argi.append_in(buffer)
		     argi := argi + 1
		  end
		  buffer.extend(')')
		  if rt /= Void then
		     buffer.extend(')')
                  else
                     buffer.append(once ";%Nbreak")
		  end
		  buffer.append(once ";%N}%N")
	       else
		  comment_in(buffer, toa.run_time_mark)
		  buffer.extend('%N')
	       end
	       i := i + 1
	    end
	 end
      end

   check_for_callee(agent_args: AGENT_ARGS; caller: POSITION) is
      do
	 if not agent_definition_set.has(agent_args.signature) then
	    error_handler.add_position(caller)
	    error_handler.append(
	       "There is no such agent ever defined in the live code.")
	    error_handler.print_as_warning
	    missing_call_set.add(agent_args)
	 end
      end

feature {AGENT_POOL_VISITOR}

   accept(visitor: AGENT_POOL_VISITOR) is
      do
         visitor.visit_agent_pool(Current)
      end

feature {NONE}

   agent_set: HASHED_SET[E_AGENT]
	 -- The collection of already encountered agent (see `register'). 
   
   agent_call_set: HASHED_SET[AGENT_ARGS] is
      once
	 create Result.make
      end

   missing_call_set: HASHED_SET[AGENT_ARGS] is
      once
	 create Result.make
      end

   agent_definition_set: HASHED_SET[STRING] is
      once
	 create Result.make
      end

   comment_in(buffer, type: STRING) is
      do
	 buffer.append(once "/* ")
	 buffer.append(type)
	 buffer.append(once "*/")
      end

   singleton_memory: AGENT_POOL is
      once
	 Result := Current
      end

invariant

   is_real_singleton: Current = singleton_memory

end -- AGENT_POOL
