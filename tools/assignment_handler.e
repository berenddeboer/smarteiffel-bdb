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
class ASSIGNMENT_HANDLER
   --
   -- Singleton object used to register all kinds of assignments from one
   -- type to another. First, one have to note that assignments not only
   -- occurs in the assignment statement itself but also, for example, while
   -- passing some argument to a routine or for creation statements, or,
   -- as another example, for the assignment attempt. The `assignment_handler'
   -- singleton has two main goals. The most basic goal (historically
   -- speaking) is to provide IMPLICIT_CAST wrappers when they are necessary.
   -- The brand new usage of `assignment_handler' (since the 1.0 SmartEiffel
   -- release) is to build the assignments type graph in order to compute
   -- more accurately the possible dynamic types of an expression (i.e. the
   -- corresponding RUN_TIME_SET). This information is important to
   -- implement dynamic dispatch and to perform the whole system covariance
   -- check (`safety_check').
   -- This singleton is shared via the GLOBALS.`assignment_handler' 
   -- once function.
   --

inherit
   GLOBALS
   VISITABLE

feature

   assignment(site: POSITION source_type, destination_type: E_TYPE) is
         -- Register a possible assignment (not always legal because of 
         -- possible covariance) occurring in some `site' from the 
         -- `source_type' into some `destination_type' in order to compute 
         -- the whole assignment graph.
      require
	 source_type.is_run_type ; destination_type.is_run_type
      local
	 key, source_rtm: STRING; graph_node: GRAPH_NODE
	 source, destination, ref_type: E_TYPE
      do
	 source := source_type.run_type
	 destination := destination_type.run_type
	 if source_type.is_bit and then destination_type.is_reference then
	    smart_eiffel.bit_n_ref_is_nyi_error(site)
	 end
	 source_rtm := source.run_time_mark
	 if source_rtm = as_none then
	 elseif source_rtm /= destination.run_time_mark then
	    if source.is_expanded then
	       if destination.is_reference then
		  ref_type := source.actual_reference(destination)
		  key := register(source,ref_type)
		  assignment(site, ref_type, destination)
	       end
	    elseif destination.is_expanded then
	       check
		  source = destination.actual_reference(source)
	       end
	    else
	       graph_node := graph_node_for(source)
	       graph_node.assignment(site,destination)
	    end
	 end
      end

feature {ASSIGNMENT, EFFECTIVE_ARG_LIST, MANIFEST_ARRAY, CALL, AGENT_ARGS}

   implicit_cast(expression: EXPRESSION; destination: E_TYPE)
      : EXPRESSION is
         -- If necessary, wrap the source `expression' inside an IMPLICIT_CAST 
         -- invisible wrapper object, hence the name of the function.
	 -- Note: most calls to this `implicit_cast' feature should be 
	 -- followed by an ordinary `assignment' call too.
      require
	 expression.result_type.is_a(destination)
      local
	 source: E_TYPE
         source_bit, destination_bit: TYPE_BIT
	 source_rtm, destination_rtm: STRING
      do
         source := expression.result_type
	 check
	    source.run_type.is_a(destination.run_type)
	 end
	 source_rtm := source.run_time_mark
	 destination_rtm := destination.run_time_mark
         if source_rtm = destination_rtm then
            Result := expression
         elseif source.is_reference then
            if destination.is_reference then -- Reference to Reference:
               Result := expression
            else -- Reference to Expanded:
               create {IMPLICIT_CAST}
	          Result.make(expression,destination)
            end
         elseif destination.is_reference then -- Expanded to Reference:
            create {IMPLICIT_CAST}
	       Result.make(expression,source.actual_reference(destination))
         elseif destination.is_integer and then source.is_integer then
	    -- INTEGER_* to INTEGER_*:
	    check source.is_a(destination) end
	    create {IMPLICIT_CAST}
	       Result.make(expression,destination)
	 elseif destination.is_real and then source.is_integer then
	    -- INTEGER to REAL:
	    create {IMPLICIT_CAST}
	       Result.make(expression,destination)
	 elseif destination.is_double then
	    if source.is_integer or else source.is_real then
	       -- INTEGER to DOUBLE or REAL to DOUBLE:
	       create {IMPLICIT_CAST}
	          Result.make(expression,destination)
	    else
	       Result := expression
	    end
	 elseif destination.is_bit then
	    source_bit ?= source.run_type
	    destination_bit ?= destination.run_type
	    if source_bit.nb /= destination_bit.nb then
	       -- BIT_* to BIT_*:
	       create {IMPLICIT_CAST}
	          Result.make(expression,destination)
	    else
	       Result := expression
	    end
	 else
	    Result := expression
         end
      ensure
         Result /= Void
      end

feature {RUN_CLASS}

   at_run_time(run_class: RUN_CLASS; rts: RUN_TIME_SET) is
      require
	 run_class = rts.owner
      local
	 graph_node: GRAPH_NODE; unknown_position: POSITION
      do
	 rts.add(unknown_position, run_class)
	 graph_node := graph_node_for(run_class.current_type)
	 graph_node.push_run_time_set(unknown_position, rts)
      end

feature {IMPLICIT_CAST}

   register(source_type, destination_type: E_TYPE): STRING is
         -- Register for code generation some needed IMPLICIT_CAST from
         -- `source_type' to `destination_type'. The `Result' is the 
         -- name of the C conversion function.
      require
         source_type.run_time_mark /= destination_type.run_time_mark
      local
	 source, destination: E_TYPE; key: STRING
      do
	 source := source_type.run_type
	 destination := destination_type.run_type
	 if source.is_expanded then
	    if destination.is_reference then
	       destination := source. actual_reference(destination)
	    end
	 elseif destination.is_expanded then
	    if source.is_reference then
	       if destination.is_integer then
		  source := destination. actual_reference(Void)
	       else
		  source := destination. actual_reference(source)
	       end
	    end
	 end
	 key := once "... unique buffer ..."
	 key.clear_count
	 key.extend('T')
	 source.id.append_in(key)
	 key.append(once "toT")
	 destination.id.append_in(key)
	 key := string_aliaser.item(key)
	 if not conversions.has(key) then
	    conversions.put([source, destination], key)
	    reference_type_special(source)
	    reference_type_special(destination)
	 end
	 Result := key
      ensure
	 Result = string_aliaser.item(Result)
      end

feature {C_PRETTY_PRINTER, E_STRIP, SWITCH}

   c_conversion_call(source, destination: E_TYPE) is
      require
	 source.run_time_mark /= destination.run_time_mark
      local
	 key: STRING; i: INTEGER
      do
	 if destination.is_separate then
	    cpp.put_string(once "(T0*)as_separate(self,")
	 else
	    key := register(source,destination)
	    cpp.put_string(key)
	    cpp.put_character('(')
	    if source.is_reference then
	       cpp.put_character('(')
	       from
		  i := 1
	       until
		  key.item(i) = 't'
	       loop
		  cpp.put_character(key.item(i))
		  i := i + 1
	       end
	       cpp.put_character('*')
	       cpp.put_character(')')
	    end
	 end
      end

feature {C_PRETTY_PRINTER}

   c_definitions is
      local
         i: INTEGER; conversion: TUPLE[E_TYPE, E_TYPE]
	 key: STRING; source, destination: E_TYPE
      do
         from
            i := 1
         until
            i > conversions.count
         loop
	    key := conversions.key(i)
	    conversion := conversions.item(i)
            source := conversion.first
            destination := conversion.second
            if source.is_bit then
               c_bit_bit_conversion(key, source, destination)
            elseif source.is_expanded and then destination.is_expanded then
               -- Because it is worthless or because this is already 
               -- done by some macro definition (#define) in
	       -- the "SmartEiffel/sys/runtime/base.h".
            else
               c_refexp_expref_conversion(key, source, destination)
            end
            i := i + 1
         end
      end

feature {SMART_EIFFEL}

   force_compatibility(reference_integer_set: HASHED_SET[RUN_CLASS]) is
      require
	 reference_integer_set /= Void
      local
	 i, j: INTEGER; t1, t2: E_TYPE; unknown_position: POSITION
      do
	 from
	    i := 1
	 until
	    i > reference_integer_set.count
	 loop
	    t1 := reference_integer_set.item(i).current_type
	    from
	       j := 1
	    until
	       j > reference_integer_set.count
	    loop
	       t2 := reference_integer_set.item(j).current_type
	       if t1 /= t2 then
		  if t1.is_a(t2) then
		     assignment(unknown_position, t1, t2)
		  else
		     error_handler.cancel
		  end
	       end
	       j := j + 1
	    end
	    i := i + 1
	 end
      end
   
   echo_information is
      local
	 i, n: INTEGER; graph_node: GRAPH_NODE; rc: RUN_CLASS
	 rts: RUN_TIME_SET
      do
	 echo.put_string(once "Assignment graph: ")
	 echo.put_integer(graph_nodes.count)
	 from
	    i := graph_nodes.lower
	 until
	    i > graph_nodes.upper
	 loop
	    graph_node := graph_nodes.item(i)
	    rc := graph_node.run_class
	    rts := rc.run_time_set
	    n := n + graph_node.destination_types.count
	    i := i + 1
	 end
	 echo.put_string(once " nodes and ")
	 echo.put_integer(n)
	 echo.put_string(once " transitions.%N")
      end

   finish_falling_down is
      local
         i: INTEGER; source, destination: E_TYPE
         rc1, rc2: RUN_CLASS; conversion: TUPLE[E_TYPE, E_TYPE]
      do
         from
            i := 1
         until
            i > conversions.count
         loop
	    conversion := conversions.item(i)
            source := conversion.first
            destination := conversion.second
            if source.is_user_expanded then
               if destination.is_reference then
                  rc1 := source.run_class
                  rc2 := destination.run_class
               end
            elseif destination.is_user_expanded then
               if source.is_reference then
                  rc1 := source.run_class
                  rc2 := destination.run_class
               end
            end
            if rc1 /= Void then
               rc1.shared_attributes(rc2)
               rc2.shared_attributes(rc1)
               rc1 := Void
            end
            i := i + 1
         end
      end

feature {RUN_FEATURE}

   falling_down(sta_rf, dyn_rf: RUN_FEATURE) is
      require
	 sta_rf /= Void ; dyn_rf /= Void ; sta_rf /= dyn_rf
      local
	 sta_type, dyn_type: E_TYPE; unknown_position: POSITION
	 sta_args, dyn_args: FORMAL_ARG_LIST; i: INTEGER; key: STRING
      do
	 sta_type := sta_rf.result_type
	 if sta_type /= Void then
	    dyn_type := dyn_rf.result_type.run_type
	    if dyn_type.is_a(sta_type) then
	       assignment(unknown_position,dyn_type,sta_type)
	    else
	       check dyn_type.is_native_array end
	       error_handler.cancel
	    end
	 end
	 sta_args := sta_rf.arguments
	 if sta_args /= Void then
	    from
	       dyn_args := dyn_rf.arguments
	       i := sta_args.count
	    until
	       i = 0
	    loop
	       sta_type := sta_args.type(i).run_type
	       dyn_type := dyn_args.type(i).run_type
	       if sta_type.is_reference and then dyn_type.is_expanded then
		  key := register(sta_type,dyn_type)
	       else
		  assignment(unknown_position,dyn_type,sta_type)
		  assignment(unknown_position,sta_type,dyn_type)
	       end
	       i := i - 1
	    end
	 end
      end

feature {PARENT, RUN_TIME_SET}

   vncg(site: POSITION; source, destination: E_TYPE) is
      do
	 if source.is_expanded then
	    if destination.is_expanded then
	    else
	       assignment(site,source,destination)
	    end
	 else
	    check
	       not destination.is_expanded
	    end
	    assignment(site,source,destination)
	 end
      end

feature {GRAPH_NODE}

   graph_node_for(type: E_TYPE): GRAPH_NODE is
      require
	 type.is_run_type
      local
	 key: STRING
      do
	 key := type.run_time_mark
	 Result := graph_nodes.reference_at(key)
	 if Result = Void then
	    create Result.make(type)
	    graph_nodes.put(Result,key)
	 end
      end

feature {FORMAL_ARG_LIST, E_FEATURE}

   redefinition(t1, t2: E_TYPE; rc: RUN_CLASS; arg_flag: BOOLEAN): BOOLEAN is
         -- Is the the `t2' type mark an allowed redefinition of the 
         -- original `t1' type mark in the new `rc' context? The `arg_flag' 
         -- flag is used to indicate that the redefinition is in argument 
         -- position (Result position otherwise) hence to compute the 
         -- assignment graph accordingly.
      require
         t1.start_position /= t2.start_position
         rc /= Void
      local
         ct, rt1, rt2: E_TYPE; bc1, bc2: BASE_CLASS
      do
         if t1.written_mark = t2.written_mark then
            Result := True
         else
            ct := rc.current_type
	    rt1 := t1.to_runnable(ct).run_type
	    rt2 := t2.to_runnable(ct).run_type
	    if rt2.run_time_mark = rt1.run_time_mark then
	       Result := True
	    else
	       Result := rt2.is_a(rt1)
	       if Result then
		  assignment_arg_or_result(arg_flag, rt1, rt2)
	       elseif t1.is_like_current then
		  error_handler.cancel
		  check not t2.is_like_current end
		  if rt1.is_a(rt2) then
		     bc1 := t1.start_position.base_class
		     bc2 := t2.base_class
		     Result := (bc2 = bc1) or else bc2.is_subclass_of(bc1)
		     if not Result then
			check error_handler.is_empty end
			error_handler.add_position(t1.start_position)
			error_handler.add_type(t2, " does not conforms %
			   %to %"like Current%" written in class ")
			error_handler.append(bc1.name.to_string)
			error_handler.extend('.')
		     end
		  end
		  if Result then
		     assignment_arg_or_result(arg_flag, rt1, rt2)
		  end
	       end
	    end
         end
      ensure
         Result xor not error_handler.is_empty
      end

feature {NATIVE, CECIL_FILE}

   from_external(site: POSITION; args: FORMAL_ARG_LIST; rt: E_TYPE) is
      local
	 i: INTEGER 
      do
	 if args /= Void then
	    from
	       i := args.count
	    until
	       i <= 0
	    loop
	       from_external_(site, args.type(i).run_type)
	       i := i - 1
	    end
	 end
	 if rt /= Void then
	    from_external_(site, rt.run_type)
	 end
      end
   
feature {ASSIGNMENT_HANDLER_VISITOR}

   accept(visitor: ASSIGNMENT_HANDLER_VISITOR) is
      do
         visitor.visit_assignment_handler(Current)
      end

feature {NONE}

   conversions: HASHED_DICTIONARY[TUPLE[E_TYPE,E_TYPE], STRING] is
         -- All needed conversions functions. The key is the corresponding 
         -- name for the C function (e.g. T56toT78).
      once
         create Result.make
      end

   c_header_for(key: STRING; source, destination: E_TYPE) is
	 -- Compute the C header in the `buffer'
      do
         buffer.clear_count
         destination.c_type_for_result_in(buffer)
         buffer.extend(' ')
         buffer.append(key)
         buffer.extend('(')
         source.c_type_for_target_in(buffer)
         buffer.append(once " source)")
         echo.put_string(once "Conversion from %"")
         echo.put_string(source.run_time_mark)
         echo.put_string(once "%" to %"")
         echo.put_string(destination.run_time_mark)
         echo.put_string(once "%" is%Ndone by C function %"")
         echo.put_string(buffer)
	 echo.put_character('%"')
	 echo.put_character('%N')
      end
   
   c_refexp_expref_conversion(key: STRING; source, destination: E_TYPE) is
      require
         source.run_time_mark /= destination.run_time_mark
	 source.run_class.at_run_time
	 destination.run_class.at_run_time
	 not (source.is_expanded and then destination.is_expanded)
      local
	 source_rc, destination_rc: RUN_CLASS; wa: ARRAY[RUN_FEATURE_2]
	 i, id: INTEGER; field: STRING
      do
	 source_rc := source.run_class
	 destination_rc := destination.run_class
	 c_header_for(key, source, destination)
	 cpp.put_c_heading(buffer)
	 if destination.is_expanded then
	    -- reference FOO to expanded FOO:
	    check
	       source.run_time_mark.has_prefix(fz_reference)
	       xor
	       destination.run_time_mark.has_prefix(fz_expanded)
	    end
	    if destination.is_basic_eiffel_expanded then
	       if ace.no_check then
		  cpp.put_string(once "vc((T0*)source,0);%N")
	       end
	       i := source_rc.run_time_set.count
	       if i > 1 then
		  cpp.put_string(once "switch(source->id){%N")
		  from until i = 0
		  loop
		     id := source_rc.run_time_set.item(i).id
		     cpp.put_string(once "case ")
		     cpp.put_integer(id)
		     cpp.put_string(once ": return")
		     destination.mapping_cast
		     cpp.put_string(once "(((T")
		     cpp.put_integer(id)
		     cpp.put_string(once "*)source)->_item);%N")
		     i := i - 1
		  end
		  if ace.no_check then
		     cpp.put_string(once "error0(%"")
		     cpp.put_string(source_rc.run_time_mark)
		     cpp.put_string(
                        once " expected (type error).%",NULL);%N")
		  end
		  cpp.put_string(once "}%N")
	       else
		  cpp.put_string(once "return((T")
		  cpp.put_integer(source_rc.id)
		  cpp.put_string(once "*)source)->_item;")
	       end
	    else
	       cpp.put_character('T')
	       cpp.put_integer(destination_rc.id)
	       cpp.put_string(once " destination;%N")
	       if ace.no_check then
		  cpp.put_string(once "ci(")
		  cpp.put_integer(source_rc.id)
		  cpp.put_string(once ",(T0*)source,0);%N")
	       end
	       wa := destination_rc.writable_attributes
	       if wa /= Void then
		  from
		     i := wa.lower
		  until
		     i > wa.upper
		  loop
		     field := wa.item(i).name.to_string
		     cpp.put_string(once "destination._")
		     cpp.put_string(field)
		     cpp.put_string(once "=((T")
		     cpp.put_integer(source_rc.id)
		     cpp.put_string(once "*)source)->_")
		     cpp.put_string(field)
		     cpp.put_string(once ";%N")
		     i := i + 1
		  end
	       end
	       cpp.put_string(once "return destination;")
	    end
         else
	    -- expanded FOO to reference FOO :
	    check source.is_expanded end
            cpp.put_character('T')
            cpp.put_integer(destination_rc.id)
            cpp.put_character('*')
            gc_handler.allocation_of(once "destination",destination_rc)
	    if source.is_basic_eiffel_expanded then
	       cpp.put_string(once "destination->_item=source;%N")
	    else
	       wa := destination_rc.writable_attributes
	       if wa /= Void then
		  from
		     i := wa.lower
		  until
		     i > wa.upper
		  loop
		     field := wa.item(i).name.to_string
		     cpp.put_string(once "destination->_")
		     cpp.put_string(field)
		     cpp.put_string(once "=source->_")
		     cpp.put_string(field)
		     cpp.put_string(once ";%N")
		     i := i + 1
		  end
	       end
	    end
            cpp.put_string(once "return (T0*)destination;")
         end
	 cpp.put_string(once "%N}%N")
      end

   c_bit_bit_conversion(key: STRING; source, destination: E_TYPE) is
      require
         source.run_time_mark /= destination.run_time_mark
      local
	 rc: RUN_CLASS
      do
	 c_header_for(key, source, destination)
         if destination.is_expanded then
            if source.is_expanded then
	       -- expanded to expanded:
               buffer.copy(once "#define T")
               source.id.append_in(buffer)
               buffer.append(fz_to_t)
               destination.id.append_in(buffer)
               buffer.append(once "(x) (x)%N")
               cpp.put_string_on_h(buffer)
	    else
	       -- *_REF to expanded:
	       cpp.put_c_heading(buffer)
	       buffer.copy(once "return (((")
	       source.c_type_for_target_in(buffer)
	       buffer.append(once ")source)->_item);%N}%N")
	       cpp.put_string(buffer)
	    end
         else
	    -- expanded to reference :
            cpp.put_c_heading(buffer)
            cpp.put_character('T')
            cpp.put_integer(destination.id)
            cpp.put_character('*')
	    rc := destination.run_class
            gc_handler.allocation_of(once "destination",rc)
	    if source.is_basic_eiffel_expanded then
	       cpp.put_string(once "destination->_item=source;%N")
	    else
	       cpp.put_string(once "memcpy((((Tid*)destination)")
	       if rc.is_tagged then
		  cpp.put_string(once "+1")
	       end
	       cpp.put_string(once "),&source,sizeof(source));%N")
	    end
            cpp.put_string(once "return ((T0*)destination);%N}%N")
         end
      end

   assignment_arg_or_result(arg_flag: BOOLEAN; t1, t2: E_TYPE) is
      local
	  unknown_position: POSITION
      do
	 if arg_flag then -- Argument of routine:
	    assignment(unknown_position, t1, t2)
	 else -- Result of function:
	    assignment(unknown_position, t2, t1)
	 end
      end
   
   buffer: STRING is
      once
         create Result.make(128)
      end

   graph_nodes: HASHED_DICTIONARY[GRAPH_NODE, STRING] is
	 -- The key STRING is the run time mark of the corresponding
	 -- graph node.
      once
	 create Result.with_capacity(512)
      end

   external_types: HASHED_DICTIONARY[E_TYPE, STRING] is
      once
	 create Result.make
      end
   
   from_external_(site: POSITION; type: E_TYPE) is
      require
	 not site.is_unknown ; type = type.run_type
      local
	 rtm: STRING; i: INTEGER; type2: E_TYPE
      do
	 if not type.is_expanded then
	    rtm := type.run_type.run_time_mark
	    if not external_types.has(rtm) then
	       from
		  i := 1
	       until
		  i > external_types.count
	       loop
		  type2 := external_types.item(i)
		  assignment(site, type, type2)
		  assignment(site, type2, type)
		  i := i + 1
	       end
	       external_types.add(type,rtm)
	    end
	 end
      end

   reference_type_special(type: E_TYPE) is
      require
	 type.run_type = type
      local
	 ref_type: TYPE_REFERENCE; exp_type: E_TYPE; rc: RUN_CLASS
      do
	 ref_type ?= type
	 if ref_type /= Void then
	    rc := ref_type.run_class
	    rc.set_at_run_time
	    exp_type := ref_type.expanded_type
	    if exp_type.is_basic_eiffel_expanded or else exp_type.is_bit then
	       if rc.get_feature_with(as_item) = Void then
		  check False end
	       end
            end
	 end
      end
   
   singleton_memory: ASSIGNMENT_HANDLER is
      once
         Result := Current
      end

invariant

   is_real_singleton: Current = singleton_memory

end -- ASSIGNMENT_HANDLER
