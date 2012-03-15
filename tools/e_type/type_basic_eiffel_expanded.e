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
deferred class TYPE_BASIC_EIFFEL_EXPANDED
--
-- Root of TYPE_BOOLEAN, TYPE_CHARACTER, TYPE_INTEGER, TYPE_REAL, 
-- TYPE_DOUBLE and TYPE_POINTER.
--
inherit E_TYPE

feature

   is_basic_eiffel_expanded, is_expanded, is_run_type: BOOLEAN is true

   is_none,
   is_array,
   is_separate,
   is_reference,
   is_dummy_expanded,
   is_user_expanded,
   is_generic,
   is_any,
   is_string,
   is_anchored,
   is_like_current,
   is_like_argument,
   is_like_feature,
   need_c_struct,
   is_bit : BOOLEAN is false

   base_class_name: CLASS_NAME

   jvm_method_flags: INTEGER is 9

   frozen actual_reference(destination: E_TYPE): TYPE_REFERENCE is
      local
         type_reference: TYPE_REFERENCE; sp: POSITION
      do
	 if destination /= Void then
	    type_reference ?= destination.run_type
	 end
         if type_reference /= Void and then
            type_reference.expanded_type.run_time_mark = run_time_mark
	  then
	    Result := type_reference
         else
	    sp := start_position
	    if sp.is_unknown then
	       if destination /= Void then
		  sp := destination.start_position
	       end
	    end
	    create Result.make(sp, Current)
         end
      end
   
   frozen actual_separate(destination: E_TYPE): E_TYPE is
      do
      end
   
   frozen start_lookup_name: CLASS_NAME is
      do
         Result := base_class_name
      end

   frozen jvm_target_descriptor_in(str: STRING) is
      do
         jvm_descriptor_in(str)
      end

   frozen jvm_check_class_invariant is
      do
      end

   frozen jvm_standard_is_equal is
      local
         ca: like code_attribute
         point1, point2: INTEGER
      do
         ca := code_attribute
         point1 := jvm_if_x_eq
         ca.opcode_iconst_0
         point2 := ca.opcode_goto
         ca.resolve_u2_branch(point1)
         ca.opcode_iconst_1
         ca.resolve_u2_branch(point2)
      end

   frozen start_position: POSITION is
      do
         Result := base_class_name.start_position
      end

   frozen generic_list: ARRAY[E_TYPE] is
      do
         fatal_error_generic_list
      end

   frozen local_from_separate: E_TYPE is
      do
	 check false end
      end

   frozen stupid_switch(run_time_set: RUN_TIME_SET): BOOLEAN is
      do
         Result := true
      end

   frozen run_type: E_TYPE is
      do
         Result := Current
      end

   frozen c_header_pass1 is
      do
      end

   frozen c_header_pass2 is
      do
      end

   frozen c_header_pass3 is
      do
      end

   frozen c_header_pass4 is
      do
      end

   frozen c_initialize is
      do
         if is_pointer then
            cpp.put_string(fz_null)
         else
            cpp.put_character('0')
         end
      end

   frozen c_initialize_in(str: STRING) is
      do
         if is_pointer then
            str.append(fz_null)
         else
            str.extend('0')
         end
      end

   frozen c_type_for_target_in(str: STRING) is
      do
         c_type_for_argument_in(str)
      end

   frozen c_type_for_result_in(str: STRING) is
      do
         c_type_for_argument_in(str)
      end

feature {RUN_CLASS,E_TYPE}

   need_gc_mark_function: BOOLEAN is false

   frozen just_before_gc_mark_in(str: STRING) is
      do
      end

   frozen gc_info_in(str: STRING) is
      do
      end

   frozen gc_define1 is
      do
      end

   frozen gc_define2 is
      do
      end

feature {E_TYPE}

   frozen short_hook is
      do
         short_print.a_class_name(base_class_name)
      end

feature {TYPE_BASIC_EIFFEL_EXPANDED_VISITOR}

   accept(visitor: TYPE_BASIC_EIFFEL_EXPANDED_VISITOR) is
      deferred
      end

feature {NONE}

   is_a_end_hook(other: E_TYPE): BOOLEAN is
      require
	 other.run_type = other
      local
	 ref_type: TYPE_REFERENCE
      do
	 ref_type ?= other
	 if ref_type /= Void then
	    if Current.is_a(ref_type.expanded_type) then
	       Result := true
	    else
	       error_handler.cancel
	    end
	 else
	    Result := base_class.is_subclass_of(other.base_class)
	 end
      end
   
   smallest_ancestor_end_hook(other: E_TYPE): E_TYPE is
      require
	 other.run_type = other
      local
	 ref_type: TYPE_REFERENCE
      do
	 ref_type ?= other
	 if ref_type /= Void then
	    if ref_type.expanded_type.is_a(Current) then
	       Result := other
	    else
	       error_handler.cancel
	       Result := type_any
	    end
	 else
	    Result := type_any
	 end
      end
   
end -- TYPE_BASIC_EIFFEL_EXPANDED
