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
class TYPE_FORMAL_GENERIC
   -- 
   -- Handling of formal generic arguments type marks.
   --
   
inherit E_TYPE redefine is_formal_generic end
   
creation {EIFFEL_PARSER,FORMAL_GENERIC_ARG} make

creation {TYPE_FORMAL_GENERIC} set

feature

   written_mark: STRING

   run_type: E_TYPE
         -- Not Void when the subtituted concrete one is known.

   run_time_mark: STRING
	 -- The corresponding one of `run_type'.

   is_formal_generic: BOOLEAN is true

   is_anchored,
   is_like_current,
   is_like_argument,
   is_like_feature: BOOLEAN is false

   actual_reference(destination: E_TYPE): E_TYPE is
      do
         Result := run_type.actual_reference(destination)
      end

   actual_separate(destination: E_TYPE): E_TYPE is
      do
         Result := run_type.actual_separate(destination)
      end

   start_lookup_name: CLASS_NAME is
	 -- IL SEMBLERAIT RAISONABLE DE RETOURNER ANY LORSQU'IL N'Y a
	 -- pas de contrainte....
      local
         c: E_TYPE
      do
         c := formal_generic_arg.constraint
         if c /= Void then
            Result := c.start_lookup_name
	 else
	    Result := class_any.name
         end
      end

   c_sizeof: INTEGER is
      do
         Result := run_type.c_sizeof
      end

   is_boolean: BOOLEAN is
      do
         Result := run_type.is_boolean
      end

   is_character: BOOLEAN is
      do
         Result := run_type.is_character
      end

   is_integer: BOOLEAN is
      do
         Result := run_type.is_integer
      end

   is_real: BOOLEAN is
      do
         Result := run_type.is_real
      end

   is_double: BOOLEAN is
      do
         Result := run_type.is_double
      end

   is_string: BOOLEAN is
      do
         Result := run_type.is_string
      end

   is_array: BOOLEAN is
      do
         Result := run_type.is_array
      end

   is_bit: BOOLEAN is
      do
         Result := run_type.is_bit
      end

   is_any: BOOLEAN is
      do
         Result := run_type.is_any
      end

   is_none: BOOLEAN is
      do
         Result := run_type.is_none
      end

   is_pointer: BOOLEAN is
      do
         Result := run_type.is_pointer
      end

   is_reference: BOOLEAN is
      do
         Result := run_type.is_reference
      end

   is_expanded: BOOLEAN is
      do
         Result := run_type.is_expanded
      end

   is_separate: BOOLEAN is
      do
         Result := run_type.is_separate
      end

   is_basic_eiffel_expanded: BOOLEAN is
      do
         Result := run_type.is_basic_eiffel_expanded
      end

   is_dummy_expanded: BOOLEAN is
      do
         Result := run_type.is_dummy_expanded
      end

   is_user_expanded: BOOLEAN is
      do
         Result := run_type.is_user_expanded
      end

   is_generic: BOOLEAN is
      do
         Result := run_type.is_generic
      end

   generic_list: ARRAY[E_TYPE] is
      do
         if is_generic then
            Result := run_type.generic_list
         else
            fatal_error_generic_list
         end
      end

   local_from_separate: E_TYPE is
      do
	 Result := run_type.local_from_separate
      end

   c_header_pass1 is
      do
         run_type.c_header_pass1
      end

   c_header_pass2 is
      do
         run_type.c_header_pass2
      end

   c_header_pass3 is
      do
         run_type.c_header_pass3
      end

   c_header_pass4 is
      do
         run_type.c_header_pass4
      end

   c_initialize is
      do
         run_type.c_initialize
      end

   c_initialize_in(str: STRING) is
      do
         run_type.c_initialize_in(str)
      end

   stupid_switch(run_time_set: RUN_TIME_SET): BOOLEAN is
      do
         Result := standard_stupid_switch(run_time_set)
      end

   id: INTEGER is
      do
         Result := run_class.id
      end

   base_class_name: CLASS_NAME is
      do
         Result := run_type.base_class_name
      end

   start_position: POSITION is
      do
         Result := formal_name.start_position
      end

   c_type_for_argument_in(str: STRING) is
      do
         run_type.c_type_for_argument_in(str)
      end

   c_type_for_target_in(str: STRING) is
      do
         run_type.c_type_for_target_in(str)
      end

   c_type_for_result_in(str: STRING) is
      do
         run_type.c_type_for_result_in(str)
      end

   need_c_struct: BOOLEAN is
      do
         Result := run_type.need_c_struct
      end

   smallest_ancestor(other: E_TYPE): E_TYPE is
      do
         Result := run_type.smallest_ancestor(other)
      end

   is_a(other: E_TYPE): BOOLEAN is
      do
         if other.is_separate then
            Result := base_class = other.base_class
         end
         if is_separate and then not other.is_separate then
            error_handler.add_position(start_position)
            error_handler.add_position(other.start_position)
            fatal_error(fz_sc1)
         elseif not Result then
            Result := run_type.is_a(other)
         end
	 if not Result then
	    error_handler.add_position(start_position)
	 end
      end

   is_run_type: BOOLEAN is
      do
         Result := run_type /= Void
      end

   jvm_method_flags: INTEGER is
      do
         Result := run_type.jvm_method_flags
      end

   jvm_descriptor_in(str: STRING) is
      do
         run_type.jvm_descriptor_in(str)
      end

   jvm_target_descriptor_in(str: STRING) is
      do
         run_type.jvm_target_descriptor_in(str)
      end

   jvm_return_code is
      do
         run_type.jvm_return_code
      end

   jvm_push_local(offset: INTEGER) is
      do
         run_type.jvm_push_local(offset)
      end

   jvm_check_class_invariant is
      do
         run_type.jvm_check_class_invariant
      end

   jvm_push_default: INTEGER is
      do
         Result := run_type.jvm_push_default
      end

   jvm_write_local_creation(offset: INTEGER) is
      do
         run_type.jvm_write_local_creation(offset)
       end

   jvm_write_local(offset: INTEGER) is
      do
         run_type.jvm_write_local(offset)
      end

   jvm_xnewarray is
      do
         run_type.jvm_xnewarray
      end

   jvm_xastore is
      do
         run_type.jvm_xastore
      end

   jvm_xaload is
      do
         run_type.jvm_xaload
      end

   jvm_if_x_eq: INTEGER is
      do
         Result := run_type.jvm_if_x_eq
      end

   jvm_if_x_ne: INTEGER is
      do
         Result := run_type.jvm_if_x_ne
      end

   jvm_to_reference is
      do
         run_type.jvm_to_reference
      end

   jvm_expanded_from_reference(other: E_TYPE): INTEGER is
      do
         Result := run_type.jvm_expanded_from_reference(other)
      end

   jvm_convert_to(destination: E_TYPE): INTEGER is
      do
         Result := run_type.jvm_convert_to(destination)
      end

   jvm_standard_is_equal is
      do
         run_type.jvm_standard_is_equal
      end

   to_runnable(ct: E_TYPE): like Current is
      local
         bc_written, bc_ct: BASE_CLASS; p: PARENT; t: E_TYPE; gl: ARRAY[E_TYPE]
      do
         bc_written := start_position.base_class
         bc_ct := ct.base_class
         if bc_written = bc_ct then
            gl := ct.generic_list
            if gl = Void or else rank > gl.upper then
               error_handler.add_position(ct.start_position)
               error_handler.add_position(start_position)
	       error_handler.append(fz_bnga)
	       error_handler.print_as_fatal_error
            else
               Result := make_runnable(ct, gl.item(rank))
            end
         else
	    check
               bc_ct.is_subclass_of(bc_written)
            end
            from
               p := bc_ct.first_parent_for(bc_written)
            until
               p = Void
            loop
               t := p.type
               t := t.to_runnable(ct).run_type
               if Result = Void then
                  Result := to_runnable(t)
                  p := Void
               else
                  p := bc_ct.next_parent_for(bc_written,p)
               end
            end
            if Result = Void then
               error_handler.add_type(ct," is the context. ")
               error_handler.add_position(start_position)
	       error_handler.append("Unable to compute this type.")
	       error_handler.print_as_warning
            end
         end
      end

feature {BASE_CLASS}

   constraint: E_TYPE is
      require
	 run_type /= Void
      do
         Result := constraint_memory
      ensure
	 formal_generic_arg.constraint /= Void implies Result.is_run_type
      end

feature {RUN_CLASS,E_TYPE}

   need_gc_mark_function: BOOLEAN is
      do
         Result := run_type.need_gc_mark_function
      end

   just_before_gc_mark_in(str: STRING) is
      do
         run_type.just_before_gc_mark_in(str)
      end

   gc_info_in(str: STRING) is
      do
         run_type.gc_info_in(str)
      end

   gc_define1 is
      do
         run_type.gc_define1
      end

   gc_define2 is
      do
         run_type.gc_define2
      end

feature {E_TYPE}

   frozen short_hook is
      do
         short_print.a_magic_class_name(formal_name)
      end

feature {TYPE_FORMAL_GENERIC_VISITOR}

   accept(visitor: TYPE_FORMAL_GENERIC_VISITOR) is
      do
         visitor.visit_type_formal_generic(Current)
      end

feature {PARENT}

   rank: INTEGER
         -- Rank in the corresponding generic list.

feature {NONE}

   formal_name: CLASS_NAME
         -- The one at the corresponding `start_position'.

   formal_generic_arg: FORMAL_GENERIC_ARG
	 -- The corresponding definition.

   constraint_memory: E_TYPE
   	 -- The corresponding runnable one, if any, according to the `run_type'.

   make(fn: like formal_name; fga: like formal_generic_arg; r: INTEGER) is
      require
         fn.to_string = fga.name.to_string
         fga.rank = r
      do
         formal_name := fn
	 formal_generic_arg := fga
         written_mark := fn.to_string
         rank := r
      ensure
         formal_name = fn
	 formal_generic_arg = fga
         rank = r
      end

   make_runnable(ct: E_TYPE; type: like run_type): like Current is
      require
	 ct.run_type = ct
	 type /= Void
      local
         rt: E_TYPE
      do
         rt := type.run_type
         if rt = Void then
            if type /= Void then
               error_handler.add_position(type.start_position)
            end
            error(start_position, fz_bga)
         elseif run_type = Void then
            set_run_type(ct, rt)
            Result := Current
	 elseif rt.written_mark = run_type.written_mark then
	    Result := Current
         else
	    create Result.set(rt.base_class,rt.run_class,
			      formal_name,formal_generic_arg,rank,ct,rt)
         end
      end

   set(bcm: like base_class_memory; rcm: like run_class_memory
       fn: like formal_name; fga: like formal_generic_arg
       r: like rank; ct: E_TYPE; rt: like run_type) is
      require
         bcm = rt.base_class
	 rcm = rt.run_class
	 fn /= Void
	 fga /= Void
	 r > 0
      do
	 base_class_memory := bcm
	 run_class_memory := rcm
	 formal_name := fn
	 formal_generic_arg := fga
         written_mark := fn.to_string
	 rank := r
	 set_run_type(ct, rt)
      ensure
	 base_class_memory = bcm
	 run_class_memory = rcm
	 formal_name = fn
	 formal_generic_arg = fga
	 rank = r
	 run_type = rt
      end

   set_run_type(ct: E_TYPE; rt: like run_type) is
	 -- To be called to make `Current' truly runnable, ie. substitution
	 -- with `rt'. In order to compute the associated `contraint_memory', `ct'
	 -- is passed from `to_runnable'.
	 -- Note: The constraint violation is checked here.
      require
	 ct.run_type = ct
	 rt.run_type = rt
	 run_type = Void
      local
         c: E_TYPE
      do
	 run_type := rt
	 run_time_mark := rt.run_time_mark
	 c := formal_generic_arg.constraint
	 if c /= Void then
	    constraint_memory := c.to_runnable(ct)
	    if constraint_memory = Void then
	       error_handler.add_position(c.start_position)
	       error_handler.append("Unable to handle this constraint.")
	       error_handler.print_as_fatal_error
	    elseif not rt.is_a(constraint_memory) then
	       error_handler.append(" Constraint Generic Violation (VTCG.3).")
	       error_handler.print_as_error
	    end
	 end
      ensure
	 run_type = rt
      end

invariant

   not start_position.is_unknown

   formal_name.to_string = formal_generic_arg.name.to_string

   written_mark = formal_name.to_string

   rank = formal_generic_arg.rank

   run_type /= Void implies run_time_mark = run_type.run_time_mark

end -- TYPE_FORMAL_GENERIC
