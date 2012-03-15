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
class RUN_TIME_SET
   --
   -- The set of all possible `at_run_time' RUN_CLASSes which are associated 
   -- with some `owner' RUN_CLASS. There is exactely one RUN_TIME_SET object
   -- for each RUN_CLASS. The RUN_TIME_SET of a RUN_CLASS is the set of 
   -- possible `at_run_time' RUN_CLASSes which are conform to this RUN_CLASS 
   -- and which may be actually held by an expression of the type of `owner'.
   --

inherit GLOBALS; VISITABLE

creation {RUN_CLASS} make

feature -- Basic accessing:

   count: INTEGER is
      do
	 Result := sorted.count
      ensure
	 Result >= 0
      end

   item(index: INTEGER): RUN_CLASS is
      require
	 index.in_range(1,count)
      do
	 Result := sorted.item(index - 1)
      ensure
	 Result /= Void
      end

   is_empty: BOOLEAN is
      do
	 Result := count = 0
      ensure 
	 Result = (count = 0)
      end
   
   has(run_class: RUN_CLASS): BOOLEAN is
      do
	 Result := set.has(run_class)
      end
   
   owner: RUN_CLASS
	 -- The `owner' of the `Current' set.
   
   first: RUN_CLASS is
      require
	 count = 1
      do
	 Result := sorted.first
      ensure
	 Result = item(1)
      end

feature {RUN_CLASS}

   id_extra_information(tfw: TEXT_FILE_WRITE) is
      local
         c, i: INTEGER; rc: RUN_CLASS
      do
	 c := sorted.count
	 tfw.put_string(once "run-time-set-count: ")
	 tfw.put_integer(c)
	 tfw.put_character('%N')
	 if c > 0 then
	    from
	       tfw.put_string(once "run-time-set:%N")
	       i := sorted.lower
	    until
	       i = c
	    loop
	       rc := sorted.item(i)
	       tfw.put_character('%T')
	       tfw.put_string(rc.run_time_mark)
	       tfw.put_character(' ')
	       tfw.put_character('(')
	       tfw.put_integer(rc.id)
	       tfw.put_character(')')
	       tfw.put_character('%N')
	       i := i + 1
	    end
	 end
      end

feature {RUN_TIME_SET}

   set: HASHED_SET[RUN_CLASS]
	 -- The set of possible RUN_CLASSes which are all `at_run_time' and 
	 -- that can be held by a variable of the `owner' type.

   sorted: FAST_ARRAY[RUN_CLASS]
	 -- Same `set' of RUN_CLASSes, but sorted by increasing id. 

feature {ASSIGNMENT_HANDLER, GRAPH_NODE}

   add_set(site: POSITION; other: like Current): INTEGER is
	 -- Add elements of `other' into `Current' and return the number of 
	 -- actually added elements.
      require
	 not smart_eiffel.is_ready
	 other /= Void
      local
	 i: INTEGER; other_sorted: like sorted; rc: RUN_CLASS
      do
	 from
	    other_sorted := other.sorted
	    i := other_sorted.upper
	 until
	    i < other_sorted.lower
	 loop
	    rc := other_sorted.item(i)
	    if not set.has(rc) then
	       if rc.current_type.is_a(owner.current_type) then
		  add(site, rc)
		  Result := Result + 1
	       else
		  error_handler.cancel
	       end
	    end
	    i := i - 1
	 end
      ensure
	 Result = count - old count
      end

feature {ASSIGNMENT_HANDLER}

   add(site: POSITION; run_class: RUN_CLASS) is
	 -- Actual unique modifier.
      require
	 not smart_eiffel.is_ready
	 run_class.at_run_time
	 not has(run_class)
	 run_class.current_type = owner.current_type
            or else
	 run_class.current_type.is_a(owner.current_type)
      local
	 i: INTEGER; t1, t2: E_TYPE; dummy: BOOLEAN; gl1, gl2: ARRAY[E_TYPE]
      do
	 check
	    run_class.is_expanded implies owner = run_class
	 end
	 smart_eiffel.magic_count_increment
	 force(run_class)
	 -- The update of the GRAPH_NODEs must also follow generic 
	 -- arguments (for example, if ARRAY[PEACH] is assigned into 
	 -- ARRAY[FRUIT], this implies that PEACH is assigned into FRUIT). 
	 -- Thus we must also follow the VNCG rules as for generic type 
	 -- conformance:
	 if run_class /= owner then
	    t1 := run_class.current_type
	    t2 := owner.current_type
	    if t1.is_generic then
	       if t2.is_generic then
		  if t1.base_class = t2.base_class then
		     -- (Note: may be TUPLE too.)
		     from
			gl1 := t1.generic_list
			gl2 := t2.generic_list
			check
			   gl1.count > 0
			   gl1.lower = gl2.lower
			   gl1.count >= gl2.count
			end
			i := gl2.upper
		     until
			i < gl2.lower
		     loop
			assignment_handler.vncg(site,
						gl1.item(i),
						gl2.item(i))
			i := i - 1
		     end
		  else
		     dummy := t1.base_class.graph_node_vncg_update(site,
								   t1,t2)
		  end
	       end
	    elseif t2.is_generic then
	       check
		  t1.base_class.is_subclass_of(t2.base_class)
	       end
	       dummy := t1.base_class.graph_node_vncg_update(site,t1,t2)
	    end
	 end
      ensure
	 sorted.fast_has(run_class)
	 has(run_class)
	 count = 1 + old count
      end

feature {SMART_EIFFEL}

   force(run_class: RUN_CLASS) is
      require
	 run_class.current_type.is_expanded implies run_class = owner
      local
	 i: INTEGER
      do
	 set.add(run_class)
	 debug
	    debug_info.extend(' ')
	    debug_info.append(run_class.run_time_mark)
	 end
	 from
	    i := sorted.upper
	    sorted.add_last(run_class)
	 until
	    i < sorted.lower
	       or else
	    sorted.item(i).id < run_class.id
	 loop
	    sorted.swap(i, i + 1)
	    i := i - 1
	 end
      end
   
feature {RUN_TIME_SET_VISITOR}

   accept(visitor: RUN_TIME_SET_VISITOR) is
      do
         visitor.visit_run_time_set(Current)
      end

feature {NONE}

   debug_info: STRING
   
   make(o: like owner) is
      require
	 o /= Void
      do
	 owner := o
	 create sorted.with_capacity(64)
	 create set.make
	 debug
	    debug_info := owner.run_time_mark.twin
	    debug_info.append(once ": ")
	 end
      ensure
	 owner = o
      end

invariant

   owner.run_time_set = Current or else  owner.run_time_set = Void

   sorted.count = set.count

end -- RUN_TIME_SET
