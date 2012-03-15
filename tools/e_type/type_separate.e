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
deferred class TYPE_SEPARATE
   --
   -- Handling of the "separate FOO" type mark.
   --
   -- The subclasses of TYPE_SEPARATE are the different kinds of processors:
   --  - TYPE_THREAD         processors implemented as Threads
   --  - TYPE_PROXY          processors implemented as Proxies
   --  - TYPE_SERVER         processors implemented as Servers
   --
   -- (see scoop.html)
   --
   -- The compilation either compiles all the types in (with the CCF read at 
   -- runtime, acting as factory parameter), or only the relevant types if 
   -- the CCF is used at compile-time.

inherit E_TYPE

feature

   start_position: POSITION
         -- Of first letter of keyword `separate'.

   written_mark: STRING

   mapped: E_TYPE
         -- Corresponding mapped type (usualy the reference type).

   run_time_mark: STRING

   run_type: E_TYPE
         -- When runnable only.

   is_expanded: BOOLEAN is False

   is_reference: BOOLEAN is True

   is_separate: BOOLEAN is True

   local_from_separate: E_TYPE is
      do
	 Result := mapped
      end

   is_array: BOOLEAN is
      do
         Result := mapped.is_array
      end

   is_none: BOOLEAN is
      do
         Result := mapped.is_none
      end

   is_any: BOOLEAN is
      do
         Result := mapped.is_any
      end

   is_like_current: BOOLEAN is False

   is_like_argument: BOOLEAN is False

   is_like_feature: BOOLEAN is False

   jvm_method_flags: INTEGER is 17

   actual_reference(destination: E_TYPE): E_TYPE is
      do
         Result := mapped
      end

   actual_separate(destination: E_TYPE): E_TYPE is
      do
         Result := destination
      end

   start_lookup_name: CLASS_NAME is
      do
         Result := base_class_name
      end

   is_basic_eiffel_expanded: BOOLEAN is False

   stupid_switch(run_time_set: RUN_TIME_SET): BOOLEAN is
      do
         Result := mapped.stupid_switch(run_time_set)
      end

   is_generic: BOOLEAN is
      do
         Result := mapped.is_generic
      end

   generic_list: ARRAY[E_TYPE] is
      do
         Result := mapped.generic_list
      end

   is_user_expanded: BOOLEAN is False

   is_dummy_expanded: BOOLEAN is False

   id: INTEGER is
      do
         Result := run_class.id
      end

   smallest_ancestor(other: E_TYPE): E_TYPE is
      do
         if run_time_mark = other.run_time_mark then
            Result := run_type
         else
            Result := mapped.smallest_ancestor(other).run_type
         end
      end

   is_a(other: E_TYPE): BOOLEAN is
      do
         if other.is_separate then
            Result := mapped = other or else mapped.is_a(other)
         end
         if not Result then
            error_handler.type_error(Current,other)
         end
      end

   is_run_type: BOOLEAN is
      do
         Result := run_type /= Void
      end

   base_class_name: CLASS_NAME is
      do
         Result := mapped.base_class_name
      end

   to_runnable(rt: E_TYPE): like Current is
      local
         m: like mapped
      do
         if mapped.base_class.is_deferred then
            error(start_position, once "A deferred class cannot be separate.")
         elseif mapped.is_expanded then
            error(start_position, once "An expanded class cannot be separate.")
         end

         mapped.base_class.set_maybe_separate

         if run_type = Current then
            -- Context change nothing :
            Result := Current
         elseif run_type = mapped then
            -- Mapped is already separate :
            Result := Current
         else
            m := mapped.to_runnable(rt)
            if m = Void then
               error_handler.add_position(start_position)
               fatal_error("Bad outside separate type.")
            end
            if run_type /= Void then
               Result := copy_from_other(Current,m.run_type)
            elseif m.is_separate then
               run_type := m
               run_time_mark := m.run_time_mark
               Result := Current
            elseif mapped = m.run_type then
               run_time_mark := compute_mark(m.run_time_mark)
               run_type := Current
               Result := Current
            else
               run_time_mark := compute_mark(m.run_time_mark)
               run_type := copy_from_other(Current,m.run_type)
               Result := Current
            end
            mapped.run_class.set_at_run_time
            Result.run_type.run_class.set_at_run_time
         end
      end

feature -- JVM: not implemented!

   jvm_descriptor_in(str: STRING) is
      do
         not_yet_implemented
      end

   jvm_target_descriptor_in(str: STRING) is
      do
         not_yet_implemented
      end

   jvm_return_code is
      do
         not_yet_implemented
      end

   jvm_push_local(offset: INTEGER) is
      do
         not_yet_implemented
      end

   jvm_check_class_invariant is
      do
         not_yet_implemented
      end

   jvm_push_default: INTEGER is
      do
         not_yet_implemented
      end

   jvm_write_local_creation(offset: INTEGER) is
      do
         not_yet_implemented
      end

   jvm_write_local(offset: INTEGER) is
      do
         not_yet_implemented
      end

   jvm_write_local_expanded(offset: INTEGER) is
      do
         not_yet_implemented
      end

   jvm_xnewarray is
      do
         not_yet_implemented
      end

   jvm_xastore is
      do
         not_yet_implemented
      end

   jvm_xaload is
      do
         not_yet_implemented
      end

   jvm_if_x_eq: INTEGER is
      do
         not_yet_implemented
      end

   jvm_if_x_ne: INTEGER is
      do
         not_yet_implemented
      end

   jvm_to_reference is
      do
         not_yet_implemented
      end

   jvm_expanded_from_reference(other: E_TYPE): INTEGER is
      do
         not_yet_implemented
      end

   jvm_convert_to(destination: E_TYPE): INTEGER is
      do
         not_yet_implemented
      end

   jvm_standard_is_equal is
      do
         not_yet_implemented
      end

feature

   is_boolean: BOOLEAN is
      do
         Result := mapped.is_boolean
      end

   is_character: BOOLEAN is
      do
         Result := mapped.is_character
      end

   is_integer: BOOLEAN is
      do
         Result := mapped.is_integer
      end

   is_real: BOOLEAN is
      do
         Result := mapped.is_real
      end

   is_double: BOOLEAN is
      do
         Result := mapped.is_double
      end

   is_bit: BOOLEAN is
      do
         Result := mapped.is_bit
      end

   is_pointer: BOOLEAN is
      do
         Result := mapped.is_pointer
      end

   is_string: BOOLEAN is
      do
         Result := mapped.is_string
      end

feature {TYPE_SEPARATE_VISITOR}

   accept(visitor: TYPE_SEPARATE_VISITOR) is
      deferred
      end

feature {E_TYPE}

   frozen short_hook is
      do
         short_print.hook_or(fz_separate,"separate ")
         mapped.short_hook
      end

feature {NONE}

   compute_mark(str: STRING): STRING is
      do
         tmp_string.copy(fz_separate)
         tmp_string.extend(' ')
         tmp_string.append(str)
         Result := string_aliaser.item(tmp_string)
      end

   make(sp: like start_position; m: like mapped) is
      require
         not sp.is_unknown
         m /= Void
      do
         start_position := sp
         mapped := m
         written_mark := compute_mark(mapped.written_mark)
      ensure
         start_position = sp
         mapped = m
      end

   from_other(other: like Current; m: like mapped) is
      require
         other /= Void
         m.run_type = m
      do
         start_position := other.start_position
         written_mark := other.written_mark
         mapped := m
         if mapped.is_separate then
            run_time_mark := mapped.run_time_mark
            run_type := mapped
         else
            run_time_mark := compute_mark(mapped.run_time_mark)
            run_type := Current
         end
      ensure
         run_type /= Void
      end

   copy_from_other(other: like Current; m: like mapped): like Current is
         -- Factory method, used to duplicate the current object.
      deferred
      end

end -- TYPE_SEPARATE
