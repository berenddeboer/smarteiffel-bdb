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
class SEPARATE_TOOLS
   -- Some day this class will be able to deal with CCF files both at
   -- compile- and execution-time.

   -- *** What is a CCF file ?? ***

   -- *** CAD: it is a file that allows the customization of resources
   -- *** allocation; how each new processor is to be treaded (new local
   -- *** thread, new thread on this or that machine... See OOSC2)

inherit
   GLOBALS
   VISITABLE

creation
   make

feature {SEPARATE_TOOLS_VISITOR}

   accept(visitor: SEPARATE_TOOLS_VISITOR) is
      do
         visitor.visit_separate_tools(Current)
      end

feature {NONE}

   make is
      do
      end

   singleton_memory: SEPARATE_TOOLS is
      once
         Result := Current
      end

feature

   create_type_separate(sp: POSITION; m: E_TYPE): TYPE_SEPARATE is
         -- Will be more complex when a CFF is used
      require
	 m /= Void
	 not sp.is_unknown
      do
         create {TYPE_THREAD} Result.make(sp, m)
      ensure
	 Result.is_separate
      end

feature {SMART_EIFFEL}

   generate_scoop_functions(run_class_map: FAST_ARRAY[RUN_CLASS]) is
      require
	 cpp.on_c
      do
	 generate_as_separate(run_class_map)
	 generate_get_subsystem(run_class_map)
      end

feature {NONE}

   generate_as_separate(run_class_map: FAST_ARRAY[RUN_CLASS]) is
         -- Generate the "as_separate()" C function, used to SCOOP'ify an
         -- object, to pass it to another thread.
      local
	 i: INTEGER; t: E_TYPE; rc: RUN_CLASS
      do
	 cpp.put_c_heading(once "sT0* as_separate(se_subsystem_t* subsystem, T0* object)")
	 cpp.put_string(once "[
	    if (object==NULL) return NULL;
	    switch(object->id) {
			      ]")
	 from
	    i := run_class_map.upper
	 until
	    i < 0
	 loop
	    rc := run_class_map.item(i)
	    if rc.current_type.is_separate then
	       put_case(rc.current_type)
	    end
	    i := i - 1
	 end
	 cpp.put_string(once "return (sT0*)object;%N")
	 from
	    i := run_class_map.upper
	 until
	    i < 0
	 loop
	    rc := run_class_map.item(i)
	    if rc.current_type.is_separate then
	       t := rc.current_type
	       put_case(t.local_from_separate)
	       cpp.put_string(once "{%NT")
	       cpp.put_integer(rc.id)
	       cpp.put_string(once "*n;%N")
	       gc_handler.new_separate(rc, once "subsystem")
	       cpp.put_string(once "n->ref=(T")
	       cpp.put_integer(t.local_from_separate.id)
	       cpp.put_string(once "*)object;%Nreturn (sT0*)n;%N}%N")
	    end
	    i := i - 1
	 end
	 cpp.put_string(once "%N}%N")
	 if not ace.boost then
	    cpp.put_string(once "error0(%"as_separate() internal error\n%", NULL);%N")
	 end
	 cpp.put_string(once "}%N")
      end

   generate_get_subsystem(run_class_map: FAST_ARRAY[RUN_CLASS]) is
         -- Generates the "get_subsystem()" C function, used to return the
         -- subsystem of an object. If the object type is not separate, that
         -- function will return NULL.
      local
	 i: INTEGER; rc: RUN_CLASS
      do
	 cpp.put_c_heading(once "se_subsystem_t* get_subsystem(T0* object, se_subsystem_t* subsystem)")
	 cpp.put_string(once "[
	    sT0* n;
	    if (object==NULL) return NULL;
	    switch(object->id) {
			      ]")
	 from
	    i := run_class_map.upper
	 until
	    i < 0
	 loop
	    rc := run_class_map.item(i)
	    if rc.current_type.is_separate then
	       put_case(rc.current_type)
	    end
	    i := i - 1
	 end
	 cpp.put_string(once "[
			      return ((sT0*)object)->subsystem;
			      }
			      return subsystem;
			      }

			      ]")
      end

   put_case(t: E_TYPE) is
      do
	 cpp.put_string(once "case ")
	 cpp.put_integer(t.id)
	 cpp.put_comment(t.run_time_mark)
	 cpp.put_string(once ":%N")
      end

invariant

   is_singleton: singleton_memory = Current

end -- SEPARATE_TOOLS


