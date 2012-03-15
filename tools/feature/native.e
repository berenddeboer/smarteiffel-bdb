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
deferred class NATIVE
   --
   -- An external language clause definition (external "SmartEiffel", 
   -- external "C ...", external "C++ ...", external "dll ...".
   --

inherit GLOBALS

feature {NATIVE_VISITOR}

   accept(visitor: NATIVE_VISITOR) is
      deferred
      end

feature

   external_tag: MANIFEST_STRING
         -- The external language call description.

   start_position: POSITION is
	 -- Of the `external_tag'.
      do
	 Result := external_tag.start_position
      end

   frozen pretty_print is
      do
	 external_tag.pretty_print
      end

   use_current(er: EXTERNAL_ROUTINE): BOOLEAN is
	 -- Is `Current' used by such a call?
      require
         er /= Void
      deferred
      end

   stupid_switch_function(run_time_set: RUN_TIME_SET; name: STRING)
      : BOOLEAN is
      require
         run_time_set.count > 1
      deferred
      end

   stupid_switch_procedure(run_time_set: RUN_TIME_SET; name: STRING)
      : BOOLEAN is
      require
         run_time_set.count > 1
      deferred
      end

   c_define_function(rf8: RUN_FEATURE_8; bcn, name: STRING) is
         -- Produce C code to define the corresponding `rf8' function.
	 -- (Or nothing when the code is inlined.)
      require
         rf8.base_feature.first_name.to_string = name
         rf8.base_feature.base_class.name.to_string = bcn
      deferred
      end

   c_mapping_function(rf8: RUN_FEATURE_8; bcn, name: STRING) is
         -- Produce C code to call the corresponding `rf8' function.
      require
         rf8.base_feature.first_name.to_string = name
         rf8.base_feature.base_class.name.to_string = bcn
      deferred
      end

   c_define_procedure(rf7: RUN_FEATURE_7; bcn, name: STRING) is
         -- Produce C code to define the corresponding `rf7' procedure.
	 -- (Or nothing when the code is inlined.)
      require
         rf7.base_feature.first_name.to_string = name
         rf7.base_feature.base_class.name.to_string = bcn
      deferred
      end

   c_mapping_procedure(rf7: RUN_FEATURE_7; bcn, name: STRING) is
         -- Produce C code to call the corresponding `rf7' procedure.
      require
         rf7.base_feature.first_name.to_string = name
         rf7.base_feature.base_class.name.to_string = bcn
      deferred
      end

   jvm_add_method_for_function(rf8: RUN_FEATURE_8; bcn, name: STRING) is
      require
         rf8.base_feature.first_name.to_string = name
         rf8.base_feature.base_class.name.to_string = bcn
      deferred
      end

   jvm_define_function(rf8: RUN_FEATURE_8; bcn, name: STRING) is
         -- Produce Java byte code to define `rf8'.
      require
         rf8.base_feature.first_name.to_string = name
         rf8.base_feature.base_class.name.to_string = bcn
      deferred
      end

   jvm_mapping_function(rf8: RUN_FEATURE_8; bcn, name: STRING) is
         -- Produce Java byte code to use `rf8'.
      require
         rf8.base_feature.first_name.to_string = name
         rf8.base_feature.base_class.name.to_string = bcn
      deferred
      end

   jvm_add_method_for_procedure(rf7: RUN_FEATURE_7; bcn, name: STRING) is
      require
         rf7.base_feature.first_name.to_string = name
         rf7.base_feature.base_class.name.to_string = bcn
      deferred
      end

   jvm_define_procedure(rf7: RUN_FEATURE_7; bcn, name: STRING) is
         -- Produce Java byte code to define `rf7'.
      require
         rf7.base_feature.first_name.to_string = name
         rf7.base_feature.base_class.name.to_string = bcn
      deferred
      end

   jvm_mapping_procedure(rf7: RUN_FEATURE_7; bcn, name: STRING) is
         -- Produce Java byte code to use `rf7'.
      require
         rf7.base_feature.first_name.to_string = name
         rf7.base_feature.base_class.name.to_string = bcn
      deferred
      end

   notify_external_assignments(args: FORMAL_ARG_LIST; rt: E_TYPE) is
	 -- Notify to the `assignment_handler' the possible assignments 
	 -- which may be done outside of the Eiffel code.
      deferred
      end
   
feature {NONE}

   fe_c2jvm(rf: RUN_FEATURE) is
      do
         error_handler.add_position(jvm.target_position)
         error_handler.add_position(rf.start_position)
         fatal_error("Command 'compile_to_jvm' cannot compile this code.")
      end

   fe_c2c(rf: RUN_FEATURE) is
      do
         error_handler.add_position(rf.start_position)
         fatal_error("Command 'compile_to_c' cannot compile this code.")
      end

   make(et: like external_tag) is
      require
         et /= Void
      do
         external_tag := et
      ensure
         external_tag = et
      end

   body: STRING is
      once
         create Result.make(1024)
      end

   buffer: STRING is
      once
	 create Result.make(32)
      end

invariant

   external_tag /= Void implies not external_tag.once_flag

end -- NATIVE
