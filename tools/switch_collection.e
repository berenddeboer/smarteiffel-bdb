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
expanded class SWITCH_COLLECTION
   --
   -- Unique Global Object in charge of the `switch_collection'.
   --

inherit
   GLOBALS
   VISITABLE

feature {CALL_PROC_CALL, E_AGENT}

   update(target: EXPRESSION; run_feature: RUN_FEATURE) is
	 -- Update the switch_collection such that `run_feature' can be
	 -- applied with `target'.
      require
	 not smart_eiffel.is_ready
         target /= Void
	 run_feature /= Void
      local
         current_type: E_TYPE; type_of_agent: TYPE_OF_AGENT
      do
	 if target.is_current then
         elseif target.is_manifest_string then
         else
	    current_type := run_feature.current_type
	    check current_type = current_type.run_type end
	    type_of_agent ?= current_type
	    if type_of_agent /= Void then
	    elseif current_type.is_reference then
	       update_with(run_feature)
            end
         end
      end
   
feature {SMART_EIFFEL}

   c_define is
         -- Produce C code for switches.
      local
         dictionary2: HASHED_DICTIONARY[RUN_FEATURE,FEATURE_NAME]
         count1, count2, total: INTEGER; switch: SWITCH
      do
	 echo.put_string(
            once "Late binding support (X* switch definition).%N")
         if not dictionary.is_empty then
            cpp.swap_on_c
            from
               count1 := 1
            until
               count1 > dictionary.count
            loop
               dictionary2 := dictionary.item(count1)
               from
                  count2 := 1
               until
                  count2 > dictionary2.count
               loop
		  cpp.next_bunch_size(3)
                  switch.c_define(dictionary2.item(count2))
                  total := total + 1
                  count2 := count2 + 1
               end
               count1 := count1 + 1
            end
         end
         echo.print_count(once "Defined Switche",total)
      end

feature {CECIL_FILE, ADDRESS_OF_POOL, E_AGENT, RUN_CLASS}

   update_with(run_feature: RUN_FEATURE) is
      require
	 not smart_eiffel.is_ready
	 not run_feature.current_type.is_type_of_agent
      local
         current_type: E_TYPE; key1: STRING; key2: FEATURE_NAME
         dictionary2: HASHED_DICTIONARY[RUN_FEATURE,FEATURE_NAME]
         run_time_set: RUN_TIME_SET; dyn_rf: RUN_FEATURE; i: INTEGER
      do
         current_type := run_feature.current_type
         run_time_set := run_feature.run_class.run_time_set
         if run_time_set.count > 1 then
            key1 := current_type.run_time_mark
            key2 := run_feature.name
	    dictionary2 := dictionary.reference_at(key1)
            if dictionary2 /= Void then
               if not dictionary2.has(key2) then
                  dictionary2.add(run_feature, key2)
                  smart_eiffel.magic_count_increment
               end
            else
               create dictionary2.make
               dictionary2.put(run_feature, key2)
               dictionary.put(dictionary2, key1)
               smart_eiffel.magic_count_increment
            end
            check
               dictionary.at(key1).at(key2) = run_feature
            end
	    if smart_eiffel.status >= 2 then
	       -- To make dynamic possibilities live:
	       from
		  i := run_time_set.count
	       until
		  i = 0
	       loop
		  dyn_rf := run_time_set.item(i).dynamic(run_feature)
		  i := i - 1;
	       end
	    end
         end
      end

feature {C_PRETTY_PRINTER}

   remove(run_feature: RUN_FEATURE) is
      require
         run_feature /= Void
      local
         key1: STRING; key2: FEATURE_NAME
         dictionary2: HASHED_DICTIONARY[RUN_FEATURE,FEATURE_NAME]
      do
         key1 := run_feature.run_class.run_time_mark
	 dictionary2 := dictionary.reference_at(key1)
         if dictionary2 /= Void then
            key2 := run_feature.name
            dictionary2.remove(key2)
            check
               not dictionary.at(key1).has(key2)
            end
         end
      end

feature {JVM}

   jvm_define is
         -- Produce Java byte code for switches.
      local
         dictionary2: HASHED_DICTIONARY[RUN_FEATURE,FEATURE_NAME]
         count1, count2, total: INTEGER; switch: SWITCH
         up_rf: RUN_FEATURE
      do
         if not dictionary.is_empty then
            from
               count1 := 1
            until
               count1 > dictionary.count
            loop
               dictionary2 := dictionary.item(count1)
               from
                  count2 := 1
               until
                  count2 > dictionary2.count
               loop
                  up_rf := dictionary2.item(count2)
                  jvm.set_current_frame(up_rf)
                  switch.jvm_define(up_rf)
                  total := total + 1
                  count2 := count2 + 1
               end
               count1 := count1 + 1
            end
         end
         echo.print_count(once "Defined Switche",total)
      end

feature {SWITCH_COLLECTION_VISITOR}

   accept(visitor: SWITCH_COLLECTION_VISITOR) is
      do
         visitor.visit_switch_collection(Current)
      end

feature {NONE}

   dictionary: HASHED_DICTIONARY[HASHED_DICTIONARY[RUN_FEATURE,FEATURE_NAME],STRING] is
         -- First STRING key is the name of a run type corresponding
         -- to a RUN_CLASS. Embedded dictionary gives all switching points.
      once
         create Result.with_capacity(1024)
      end

end -- SWITCH_COLLECTION
