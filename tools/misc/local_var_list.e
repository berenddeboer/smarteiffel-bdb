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
class LOCAL_VAR_LIST
   --
   -- To store local variables declaration list.
   --

inherit DECLARATION_LIST

creation {EIFFEL_PARSER} make

feature

   name(i: INTEGER): LOCAL_NAME1 is
      do
         Result := flat_list.item(i)
      end

   to_runnable(ct: E_TYPE): like Current is
      require
         ct.run_type = ct
      do
         if is_runnable(ct) then
            Result := Current
         else
            Result := twin
            Result.dynamic_runnable(ct)
            Result.check_name_clash(ct)
         end
      end

   side_effect_free: BOOLEAN is
      local
         i: INTEGER; lt: E_TYPE; rf3: RUN_FEATURE_3
      do
         from
	    Result := True
            i := count
         until
            not Result or else i = 0
         loop
	    lt := type(i)
	    if lt.is_user_expanded then
	       rf3 := lt.run_class.a_default_create
	       if rf3 /= Void then
		  Result := rf3.side_effect_free
	       end
	    end
            i := i - 1
         end
      end
   
   pretty_print is
      local
         i, j, column, wrap_limit: INTEGER; buffer: STRING; c: CHARACTER
      do
	 buffer := once "........................"
	 buffer.clear_count
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
	 pretty_printer.set_indent_level(2)
         pretty_printer.indent
         pretty_printer.keyword(fz_local)
	 if pretty_printer.zen_mode and list.count = 1 then
	    buffer.remove_last(1)
	    pretty_printer.put_string(buffer)
	 else
	    wrap_limit := pretty_printer.wrap_limit
            from
	       pretty_printer.set_indent_level(3)
	       pretty_printer.indent
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
	       pretty_printer.indent
	       buffer.remove_first(i)
	       if not buffer.is_empty then
		  if buffer.first = ' ' then
		     buffer.remove_first(1)
		  end
	       end
            end
         end
         pretty_printer.set_indent_level(2)
         pretty_printer.indent
      end

   produce_c: BOOLEAN is
	 -- See {LOCAL_NAME1}.produce_c comment.
      local
         i: INTEGER
      do
         from
            i := count
         until
            Result or else i = 0
         loop
            Result := name(i).produce_c
            i := i - 1
         end
      end

feature {RUN_FEATURE}

   c_frame_descriptor(format, locals: STRING) is
      require
	 ace.no_check
      local
         i, c: INTEGER; n: LOCAL_NAME1; to_string: STRING
      do
         from
            i := 1
	    c := count
         until
            i > c
         loop
	    n := name(i)
	    if n.produce_c then
	       to_string := n.to_string
	       format.append(to_string)
	       locals.append(once "(void**)&_l_")
	       locals.append(to_string)
	       locals.extend(',')
	       type(i).c_frame_descriptor_in(format)
	    end
            i := i + 1
         end
      end

feature {ONCE_ROUTINE_POOL, RUN_FEATURE}

   c_declare(volatile_flag: BOOLEAN) is
	 -- Generate the C code for the declaration part. The 
	 -- `volatile_flag' indicate that an extra volatile C keyword 
	 -- must be generated because we are in the case of a routine 
	 -- with a rescue clause.
      local
         i, c: INTEGER
      do
         from
            i := 1
	    c := count
         until
            i > c
         loop
            name(i).c_declare(volatile_flag)
            i := i + 1
         end
      end

   initialize_expanded is
      local
         i: INTEGER; t: E_TYPE; rf3: RUN_FEATURE_3
      do
         from
            i := count
         until
            i = 0
         loop
            t := type(i).run_type
            if t.is_expanded then
               if not t.is_basic_eiffel_expanded then
                  rf3 := t.run_class.a_default_create
                  if rf3 /= Void then
                     cpp.put_proc_call_0(rf3,name(i),Void)
                  end
               end
            end
            i := i - 1
         end
      end

   jvm_initialize is
         -- Produce code in order to initialize variables.
      local
         jvm_offset, i, dummy: INTEGER
         t: E_TYPE
      do
         from
            i := count
         until
            i = 0
         loop
            jvm_offset := jvm.local_offset_of(name(i))
            t := type(i).run_type
            dummy := t.jvm_push_default
            t.jvm_write_local_creation(jvm_offset)
            i := i - 1
         end
      end

feature {RUN_FEATURE_3}

   inline_one_pc is
      local
         i: INTEGER
      do
         from
            i := count
         until
            i = 0
         loop
            cpp.inline_level_incr
            name(i).c_declare(False)
            cpp.inline_level_decr
            i := i - 1
         end
      end

feature {LOCAL_VAR_LIST_VISITOR}

   accept(visitor: LOCAL_VAR_LIST_VISITOR) is
      do
         visitor.visit_local_var_list(Current)
      end

feature {NONE}

   make(l: like list) is
      do
         declaration_list_make(l)
      end

end -- LOCAL_VAR_LIST


