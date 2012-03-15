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
class SHORT_LIST
   --
   -- This singleton is used to memorize the already printed list of features
   -- in order to avoid dupplicates in the `short' output. This singleton is
   -- used as well to print the sorted list of features when the "-sort" flag is
   -- used.
   --

inherit GLOBALS

creation make

feature

   has(run_feature: RUN_FEATURE): BOOLEAN is
      require
	 run_feature /= Void
      do
	 Result := memory.has(run_feature.name)
      end

   add_last(run_feature: RUN_FEATURE) is
      require
	 not has(run_feature)
      do
	 memory.add(run_feature, run_feature.name)
      ensure
	 has(run_feature)
      end

feature {FEATURE_NAME_LIST}

   do_print_of(run_feature: RUN_FEATURE) is
      require
	 has(run_feature)
      do
	 short_print.a_run_feature(run_feature)
      end

feature {CLASS_CHECKER}

   is_empty: BOOLEAN is
      do
	 Result := memory.is_empty
      end

   do_sorted_print is
      local
	 i: INTEGER; key_map: FAST_ARRAY[FEATURE_NAME]
	 sorter: COLLECTION_SORTER[FEATURE_NAME]; run_feature: RUN_FEATURE
      do
	 create key_map.with_capacity(memory.count)
	 memory.key_map_in(key_map)
	 sorter.sort(key_map)
	 from
	    i := key_map.lower
	 until
	    i > key_map.upper
	 loop
	    run_feature := memory.at(key_map.item(i))
	    short_print.a_run_feature(run_feature)
	    i := i + 1
	 end
      end

feature {NONE}

   memory: HASHED_DICTIONARY[RUN_FEATURE, FEATURE_NAME]
	 -- Already memorized RUN_FEATURE to be printed if the `short' "-sort"
	 -- flag is used.

   make is
      do
	 create memory.make
      end

   singleton_memory: SHORT_LIST is
      once
	 Result := Current
      end

invariant

   is_real_singleton: Current = singleton_memory

end
