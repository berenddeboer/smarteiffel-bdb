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
class GRAPH_NODE
   --
   -- One node of the whole system assignment graph node.
   --

inherit
   GLOBALS
   VISITABLE
   HASHABLE
      redefine
         is_equal
      end

creation {ASSIGNMENT_HANDLER} make

feature {GRAPH_NODE_VISITOR}

   accept(visitor: GRAPH_NODE_VISITOR) is
      do
         visitor.visit_graph_node(Current)
      end

feature

   source_type: E_TYPE
	 -- The one (source) of the `Current' node in the graph.

   run_class: RUN_CLASS
	 -- An alias for `source_type.run_class'.

   run_time_mark: STRING
	 -- An alias for `source_type.run_time_mark'.

   run_time_set: RUN_TIME_SET
	 -- An alias for `run_class.run_time_set'.

   destination_types: SET[GRAPH_NODE]
	 -- The set of possible destination starting from `source_type'.

   explanation_memory: FIXED_ARRAY[TUPLE[POSITION,E_TYPE]]

   hash_code: INTEGER
	 -- A memory cache for `source_type.run_time_mark.hash_code'.

   is_equal(other: like Current): BOOLEAN is
      do
	 Result := Current = other
      end

feature {ASSIGNMENT_HANDLER}

   assignment(site: POSITION; destination_type: E_TYPE) is
      require
	 smart_eiffel.status.in_range(0,2)
	 source_type.run_time_mark /= destination_type.run_time_mark
      local
	 graph_node: GRAPH_NODE
      do
	 graph_node := assignment_handler.graph_node_for(destination_type)
	 if not destination_types.has(graph_node) then
	    destination_types.add(graph_node)
	    if graph_node.run_time_set.add_set(site, run_time_set) > 0 then
	       graph_node.push_run_time_set(site, run_time_set)
	    end
	 end
	 explanation_memory.add_last([site,destination_type])
      end

feature {ASSIGNMENT_HANDLER, GRAPH_NODE}

   push_run_time_set(site: POSITION; rts: RUN_TIME_SET) is
	 -- Push the content of `rts' in all `destination_types'.
      require
	 run_time_set.add_set(site, rts) = 0
      local
	 i: INTEGER
      do
	 from
	    i := destination_types.lower
	 until
	    i > destination_types.upper
	 loop
	    destination_types.item(i).push_run_time_set_(site, Current, rts)
	    i := i + 1
	 end
      end

feature {GRAPH_NODE}

   push_run_time_set_(site: POSITION; origin: GRAPH_NODE; rts: RUN_TIME_SET) is
      require
	 origin.run_time_set.add_set(site, rts) = 0
      local
	 i: INTEGER
      do
	 if Current /= origin then
	    if run_time_set.add_set(site, rts) > 0 then
	       -- The `Current' `run_time_set' has changed, so we
	       -- have to continue to push the modification:
	       from
		  i := destination_types.lower
	       until
		  i > destination_types.upper
	       loop
		  destination_types.item(i).push_run_time_set_(site,
							       origin,
							       rts)
		  i := i + 1
	       end
	    end
	 end
      end

feature {NONE}

   make(st: like source_type) is
      require
	 not st.is_none
      do
	 source_type := st.run_type
	 check
	    source_type.run_type = source_type
	 end
	 create destination_types.make
	 hash_code := source_type.run_time_mark.hash_code
	 create explanation_memory.with_capacity(512)
	 run_class := source_type.run_class
	 run_time_mark := run_class.run_time_mark
	 run_time_set := run_class.run_time_set
      ensure
	 source_type.run_type = st.run_type
      end

invariant

   destination_types /= Void

end -- GRAPH_NODE
