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
class TYPE_THREAD

inherit TYPE_SEPARATE

creation {SEPARATE_TOOLS}
   make

creation {TYPE_THREAD}
   from_other

feature {TYPE_THREAD_VISITOR}

   accept(visitor: TYPE_THREAD_VISITOR) is
      do
         visitor.visit_type_thread(Current)
      end

feature

   is_anchored: BOOLEAN is false
   
   c_header_pass1 is
      do
         standard_c_typedef
      end

   c_header_pass2 is
      do
      end

   c_header_pass3 is
      do
         if run_type = Current then
            thread_c_struct
         else
            run_type.c_header_pass3
         end
	 thread_c_object_model
      end

   c_header_pass4 is
      do
         standard_c_print_function
      end

   c_type_for_argument_in(str: STRING) is
      do
         str.append(fz_t0_star)
      end

   c_type_for_target_in(str: STRING) is
      do
         str.extend('T')
         id.append_in(str)
         str.extend('*')
      end

   c_type_for_result_in(str: STRING) is
      do
         str.append(fz_t0_star)
      end

   need_c_struct: BOOLEAN is true

   c_sizeof: INTEGER is
      do
         Result := (1).object_size + 2 * default_pointer.object_size
      end

   c_initialize is
      do
         cpp.put_string(fz_null)
      end

   c_initialize_in(str: STRING) is
      do
         str.append(fz_null)
      end

feature {RUN_CLASS,E_TYPE}

   need_gc_mark_function: BOOLEAN is true

   just_before_gc_mark_in(str: STRING) is
      do
         standard_just_before_gc_mark_in(str)
      end

   gc_info_in(str: STRING) is
      do
         standard_gc_info_in(str)
      end

   gc_define1 is
      do
         standard_gc_define1
      end

   gc_define2 is
      do
         standard_gc_define2
      end

feature {NONE}

   copy_from_other(other: like Current; m: like mapped): like Current is
      do
         create Result.from_other(other, m)
      end

feature {NONE}

   thread_c_struct is
         -- Modified version of `standard_c_struct'
      require
         run_type = Current
         need_c_struct
         cpp.on_h
      local
         wa: ARRAY[RUN_FEATURE_2]
         mem_id: INTEGER
      do
         mem_id := id
         wa := run_class.writable_attributes
         tmp_string.copy(fz_struct)
         tmp_string.extend(' ')
         tmp_string.extend('S')
         mem_id.append_in(tmp_string)
         tmp_string.extend('{')
         if run_class.is_tagged then
            tmp_string.append(once "Tid id;")
         end
         tmp_string.append(once "se_subsystem_t* subsystem;")
         mapped.c_type_for_target_in(tmp_string)
         tmp_string.append(once " ref;}")
         tmp_string.append(fz_00)
         cpp.put_string(tmp_string)
      ensure
         cpp.on_h
      end

   frozen thread_c_object_model is
         -- Modified version of `standard_c_object_model'
      require
         run_type = Current
         cpp.on_h
      local
         mem_id: INTEGER
         rc: RUN_CLASS
      do
         rc := run_class
         mem_id := rc.id
         tmp_string.clear
         tmp_string.extend('T')
         mem_id.append_in(tmp_string)
         tmp_string.extend(' ')
         tmp_string.extend('M')
         mem_id.append_in(tmp_string)
         cpp.put_extern7(tmp_string)
         cpp.swap_on_c
         tmp_string.clear
         tmp_string.extend('{')
         id.append_in(tmp_string)
         tmp_string.append(once ",NULL,NULL}")
         tmp_string.append(fz_00)
         cpp.put_string(tmp_string)
         cpp.swap_on_h
      ensure
         cpp.on_h
      end

end -- TYPE_THREAD
