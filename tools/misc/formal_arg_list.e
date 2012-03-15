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
class FORMAL_ARG_LIST
   --
   -- For the formal arguments list of a routine.
   --

inherit DECLARATION_LIST

creation  make

creation {RUN_FEATURE} with

feature

   name(i: INTEGER): ARGUMENT_NAME1 is
      do
         Result := flat_list.item(i)
      end

   pretty_print is
      local
         i, j, column, wrap_limit: INTEGER; buffer: STRING; c: CHARACTER
      do
	 buffer := once "........................"
	 buffer.clear
	 -- Fill the `buffer' first:
         from
	    i := list.lower
	 until
	    i > list.upper
	 loop
	    list.item(i).pretty_print_in(buffer)
	    buffer.extend(';')
	    if not pretty_printer.zen_mode then
	       buffer.extend(' ')
	    end
	    i := i + 1
	 end
	 -- Output of `pretty' now start:
	 pretty_printer.put_character('(')
         pretty_printer.indent_level_increment
	 from
	    wrap_limit := pretty_printer.wrap_limit
	 until
	    buffer.is_empty
	 loop
	    column := pretty_printer.column
	    i := buffer.index_of(';', 1)
	    if column + i <= wrap_limit then
	       from
	       until
		  ((buffer.index_of(';', i + 1) = 0)
		   or else
		   ((column + buffer.index_of(';', i + 1)) > wrap_limit))
	       loop
		  i := buffer.index_of(';', i + 1)
	       end
	    else 
	       i := buffer.index_of(',', 1)
	       if i = 0 then
		  i := buffer.index_of(';', 1)
	       else
		  from
		  until
		     ((buffer.index_of(',', i + 1) = 0)
		      or else
		      ((column + buffer.index_of(',', i + 1)) > wrap_limit))
		  loop
		     i := buffer.index_of(',', i + 1)
		  end
	       end
	    end
	    check i > 1 end
	    -- Output from 1 .. `i' range:
	    from
	       j := 1
	    until
	       j = i
	    loop
	       c := buffer.item(j)
	       if j = i and then c = ';' then
		  if pretty_printer.parano_mode then
		     pretty_printer.put_character(c)
		  end
	       else
		  pretty_printer.put_character(c)
	       end
	       j := j + 1
	    end
	    buffer.remove_first(i)
	    if not buffer.is_empty then
	       if buffer.first = ' ' then
		  buffer.remove_first(1)
	       end
	    end
	    if not buffer.is_empty then
	       pretty_printer.indent
	    end
	 end
	 pretty_printer.indent_level_decrement
         pretty_printer.put_character(')')
      end

   short is
      local
         i: INTEGER
      do
         short_print.hook_or(once "hook302",once " (")
         from
            i := list.lower
         until
            i > list.upper
         loop
            list.item(i).short
            i := i + 1
            if i <= list.upper then
               short_print.hook_or(once "hook303",once "; ")
            end
         end
         short_print.hook_or(once "hook306",once ")")
      end

   is_a_in(other: like Current; rc: RUN_CLASS): BOOLEAN is
         -- True when `Current' interpreted in `rc' is a kind of `other'
         -- interpreted in `rc'.
      require
         other /= Void ; rc /= Void
      local
         i: INTEGER; t1, t2: E_TYPE
      do
         i := count
         if other.count /= i then
            error_handler.add_position(other.start_position)
            error(start_position,"Bad number of arguments.")
         end
         if nb_errors = 0 then
            from
               Result := True
            until
               not Result or else i = 0
            loop
               t1 := type(i)
               t2 := other.type(i)
               if not assignment_handler.redefinition(t2, t1, rc, True) then
                  Result := false
                  error_handler.print_as_error
                  error_handler.add_position(t1.start_position)
                  error_handler.add_position(t2.start_position)
                  error_handler.append("Incompatible types in ")
                  error_handler.append(rc.current_type.run_time_mark)
                  error_handler.append(fz_dot_blank)
                  error_handler.print_as_error
               end
               i := i - 1
            end
         end
      end

   verify_scoop(target: EXPRESSION): BOOLEAN is
         -- Verify if the target is an argument of the expression (only when 
         -- the target is separate)
         -- True if any separate expression is target of a call
      local
         i: INTEGER; arg: ARGUMENT_NAME; found: BOOLEAN
      do
         arg ?= target
         if (arg /= Void
	     and then
	     target.result_type.is_separate
	     and then
	     not target.is_current)
	  then
            from
               i := count
            until
               i < 1
            loop
               found := found or else arg.to_string = name(i).to_string
               if name(i).verify_scoop(Current) then
                  Result := True
               end
               i := i - 1
            end
            if not found then
               target.scoop_error
            end
         else
            from
               i := count
            until
               i < 1
            loop
               if name(i).verify_scoop(Current) then
                  Result := True
               end
               i := i - 1
            end
         end
      end

feature {RUN_FEATURE}

   c_frame_descriptor(format, locals: STRING) is
      require
	 ace.no_check
      local
         i: INTEGER; t: E_TYPE
      do
         from
            i := 1
         until
            i > count
         loop
            t := type(i).run_type
	    format.append(name(i).to_string)
	    t.c_frame_descriptor_in(format)
	    locals.append(once "(void**)&a")
	    i.append_in(locals)
	    locals.extend(',')
            i := i + 1
         end
      end

   c_lock_scoop_count: INTEGER

   c_lock_scoop_init is
      require
         smart_eiffel.scoop
      local
         t: E_TYPE
         i, n: INTEGER
      do
         tmp_string.clear
         cpp.put_character('{')
         from
            i := 1
         until
            i > count
         loop
            t := type(i).run_type
            if t.is_separate then
               cpp.put_string(once "NULL,")
               tmp_string.append(once "scoop_sub[")
               n.append_in(tmp_string)
               tmp_string.append(once "]=get_subsystem(a")
               i.append_in(tmp_string)
               tmp_string.append(once ",self);%N")
               n := n + 1
            end
            i := i + 1
         end
         cpp.put_string(once "};%N")
         cpp.put_string(tmp_string)

         c_lock_scoop_count := n
      end

   c_lock_scoop is
      do
         cpp.put_string(once "self->vft.wait_for_providers(self,scoop_sub,")
         cpp.put_integer(c_lock_scoop_count)
         cpp.put_string(once ");%N")
      end

   c_unlock_scoop is
      require
         smart_eiffel.scoop
      do
         cpp.put_string(once "self->vft.unqueue_providers(self, scoop_sub,")
         cpp.put_integer(c_lock_scoop_count)
         cpp.put_string(once ");%N")
      end

feature {RUN_CLASS,RUN_FEATURE}

   compile_to_c_in(c_code_buffer: STRING) is
      local
         i: INTEGER; t: E_TYPE
      do
         from i := 1; until i > count
         loop
            t := type(i).run_type
            t.c_type_for_argument_in(c_code_buffer)
            c_code_buffer.extend(' ')
            c_code_buffer.extend('a')
            i.append_in(c_code_buffer)
            i := i + 1
            if i <= count then
               c_code_buffer.extend(',')
            end
         end
      end

feature {JVM}

   jvm_switch_push(dyn_fal: like Current): INTEGER is
         -- Push inside switching method.
      require
         count = dyn_fal.count
      local
         i: INTEGER
      do
         from i := 1; until i > count
         loop
            Result := Result + jvm_switch_push_ith(dyn_fal,i)
            i := i + 1
         end
      end

feature {JVM}

   jvm_switch_push_ith(dyn_fal: like Current; i: INTEGER): INTEGER is
      local
         ft, at: E_TYPE; offset: INTEGER
      do
         offset := jvm.argument_offset_of(name(i))
         ft := type(i).run_type
         at := dyn_fal.type(i).run_type
         ft.jvm_push_local(offset)
         Result := ft.jvm_convert_to(at)
      end

feature {RUN_FEATURE,SWITCH,NATIVE_SMART_EIFFEL}

   jvm_descriptor_in(buffer: STRING) is
      local
         i: INTEGER; at: E_TYPE
      do
         from
            i := 1
         until
            i > count
         loop
            at := type(i).run_type
            if at.is_reference then
               buffer.append(jvm_root_descriptor)
            else
               at.jvm_descriptor_in(buffer)
            end
            i := i + 1
         end
      end

feature {RUN_FEATURE_3}

   inline_one_pc is
      local
         i: INTEGER; t: E_TYPE
      do
         from
            i := 1
         until
            i > count
         loop
            t := type(i).run_type
            tmp_string.clear
            t.c_type_for_argument_in(tmp_string)
            tmp_string.extend(' ')
            cpp.put_string(tmp_string)
            cpp.inline_level_incr
            cpp.print_argument(i)
            cpp.inline_level_decr
            cpp.put_character('=')
            cpp.put_ith_argument(i)
            cpp.put_string(fz_00)
            i := i + 1
         end
      end

feature {RUN_FEATURE,CECIL_POOL}

   external_prototype_in(str: STRING) is
      local
         i: INTEGER
         t: E_TYPE
      do
         from
            i := 1
         until
            i > count
         loop
            t := type(i).run_type
            t.c_type_for_external_in(str)
            str.extend(' ')
            str.extend('a')
            i.append_in(str)
            i := i + 1
            if i <= count then
               str.extend(',')
            end
         end
      end

feature {E_AGENT}

   open_args(sp: POSITION): EFFECTIVE_ARG_LIST is
	 -- Create the corresponding ommited open arguments list.
      local
	 i, c: INTEGER
      do
	 create Result.make_1(create {OPEN_OPERAND}.make(sp))
         from
	    i := 2
            c := count
         until
            i > c
         loop
            Result.add_last(create {OPEN_OPERAND}.make(sp))
            i := i + 1
         end
      ensure
	 Result.count = count
      end

feature

   has_like_current: BOOLEAN is
      local
	 i: INTEGER
      do
	 from
	    i := flat_list.upper
	 until
	    Result or else i < flat_list.lower
	 loop
	    Result :=  flat_list.item(i).result_type.is_like_current
	    i := i - 1
	 end
      end

feature {FORMAL_ARG_LIST_VISITOR}

   accept(visitor: FORMAL_ARG_LIST_VISITOR) is
      do
         visitor.visit_formal_arg_list(Current)
      end

feature {NONE}

   make(l: like list) is
	 -- Parsing creation procedure.
      require
         l.lower = 1
         not l.is_empty
      local
         an: like name; tlf: TYPE_LIKE_FEATURE; an2: ARGUMENT_NAME2
	 tla, tla2: TYPE_LIKE_ARGUMENT; i, rank: INTEGER
      do
         declaration_list_make(l)
         -- Substitution TYPE_LIKE_FEATURE/TYPE_LIKE_ARGUMENT:
         from
            i := count
         until
            i = 0
         loop
            an := name(i)
            tlf ?= an.result_type
            if tlf /= Void then
               rank := rank_of(tlf.like_what.to_string)
               if rank = i then
                  error_handler.add_position(tlf.start_position)
                  error_handler.append(fz_cad)
		  error_handler.print_as_fatal_error
               elseif rank > 0 then
                  !!an2.refer_to(tlf.like_what.start_position,Current,rank)
                  !!tla.make(tlf.start_position,an2)
                  an.set_result_type(tla)
               end
            end
            i := i - 1
         end
         if ace.all_check then
            from
               i := count
            until
               i = 0
            loop
               tla ?= name(i).result_type
               if tla /= Void then
                  rank := rank_of(tla.like_what.to_string)
                  tla2 ?= name(rank).result_type
                  if tla2 /= Void then
                     error_handler.add_position(tla.start_position)
                     error_handler.add_position(tla2.start_position)
                     error_handler.append(fz_cad)
		     error_handler.print_as_fatal_error
                  end
               end
               i := i - 1
            end
         end
      ensure
         list = list
         flat_list /= Void
      end

   with(model: like Current; ct: E_TYPE) is
	 -- Runnable creation procedure.
      require
         not model.is_runnable(ct)
      do
         standard_copy(model)
         dynamic_runnable(ct)
         check_name_clash(ct)
      end

   tmp_string: STRING is
      once
         !!Result.make(32)
      end

end -- FORMAL_ARG_LIST
