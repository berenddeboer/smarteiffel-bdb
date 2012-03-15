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
class CECIL_FILE
   --
   -- Handle the content of one -cecil file.
   --

inherit GLOBALS; VISITABLE
   
creation make

feature {CECIL_POOL}

   parse is
	 -- Parse the corresponding `path' file.
      local
	 tuple: TUPLE[STRING, RUN_FEATURE]; rt: E_TYPE; type_tuple: TYPE_TUPLE
	 aux: FIXED_ARRAY[TUPLE[E_TYPE, FEATURE_NAME]]
         fn: FEATURE_NAME; void_rf, rf: RUN_FEATURE; i: INTEGER; rc: RUN_CLASS
      do
	 create entries.with_capacity(4)
	 path_h := eiffel_parser.connect_to_cecil(path)
	 from
	    create aux.with_capacity(4)
	 until
	    eiffel_parser.end_of_input
	 loop
	    tuple := [eiffel_parser.parse_c_name, void_rf]
	    -- Note: `void_rf' is mandatory here to force the type of 
	    -- this TUPLE field.
	    entries.add_last(tuple)
	    rt := eiffel_parser.parse_run_type
	    if not rt.is_static then
	       error_handler.append("All type marks used in a cecil %
                  %file have to be static (no anchors).")
	       error_handler.add_position(rt.start_position)
	       error_handler.print_as_fatal_error
	    end
	    type_tuple ?= rt
	    if rt.is_type_of_agent or else type_tuple /= Void then
	       error_handler.append("Cannot use agents type marks or TUPLE type %
	          %marks inside cecil files (SmartEiffel limitation, sorry). To %
		  %work around, just use an extra Eiffel routine/object to %
                  %perform agent or TUPLE manipulation in pure Eiffel.")
	       error_handler.add_position(rt.start_position)
	       error_handler.print_as_fatal_error
	    end
	    fn := eiffel_parser.parse_feature_name
	    aux.add_last([rt, fn])
	 end
	 eiffel_parser.disconnect
	 echo.put_string(once "Loading cecil features:%N")
	 from
	    i := aux.lower
	 until
	    i > aux.upper
	 loop
	    rt := aux.item(i).first
	    fn := aux.item(i).second
	    rt := rt.to_runnable(type_any)
	    check
	       rt.is_static
	    end
	    rc := rt.run_class
	    rf := rc.get_feature(fn)
	    if rf = Void then
	       error_handler.add_position(fn.start_position)
	       error_handler.append(
                  "Error while loading feature of cecil file.")
	       error_handler.print_as_fatal_error
	    end
	    assignment_handler.from_external(rf.start_position,
					     rf.arguments,
					     rf.result_type)
	    if rf.is_deferred then
	    elseif rc.run_time_set.count = 0 then
	       rc.set_at_run_time
	    end
	    cecil_pool.echo_for(rf)
	    entries.item(i).set_second(rf)
	    i := i + 1
	 end
      end

   c_define_users is
      local
         i: INTEGER; tuple: TUPLE[STRING, RUN_FEATURE]
      do
         if entries /= Void then
            echo.put_string(once "Cecil (C function for external code) :%N")
            cpp.connect_cecil_out_h(path_h)
	    from
	       i := entries.upper
	    until
	       i < entries.lower
	    loop
	       tuple := entries.item(i)
	       cecil_pool.c_define_for(tuple.first, tuple.second)
	       i := i - 1
	    end
            cpp.disconnect_cecil_out_h
         end
      end

   afd_check is
      local
	 i: INTEGER; rf: RUN_FEATURE
      do
	 if entries /= Void then
	    from
	       i := entries.upper
	    until
	       i < entries.lower
	    loop
	       rf := entries.item(i).second
	       switch_collection.update_with(rf)
	       i := i - 1
	    end
	 end
      end

feature {CECIL_FILE_VISITOR}

   accept(visitor: CECIL_FILE_VISITOR) is
      do
         visitor.visit_cecil_file(Current)
      end

feature {NONE}

   path: STRING
	 -- The `path' given after the -cecil flag.

   path_h: STRING
	 -- The name of the include file to be generated (ie. first
	 -- information inside file `path'.

   entries: FIXED_ARRAY[TUPLE[STRING, RUN_FEATURE]]
	 -- List of user's `entries'. For each TUPLE entry `first' is the C 
	 -- user's name and `second' the corresponding Eiffel feature.

   make(p: like path) is
      require
	 p /= Void
      do
	 path := p
      ensure
	 path = p
      end

end
