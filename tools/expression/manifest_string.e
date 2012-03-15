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
class MANIFEST_STRING
   --
   -- Any kind of manifest strings: classic STRING as well as UNICODE_STRING
   -- writtent using the classic way as well as multi-line verbatim
   -- manifest strings. Also note that the onceness status of the
   -- corresponding manifest string is also part of the MANIFEST_STRING
   -- object knowledge.
   --

inherit
   EXPRESSION redefine is_equal end
   HASHABLE redefine is_equal end
   
creation {PARSER} make

feature

   is_manifest_string,
   once_pre_computable,
   side_effect_free,
   extra_bracket_flag
   : BOOLEAN is True

   is_manifest_array,
   is_writable,
   is_current,
   is_void,
   is_result,
   use_current
   : BOOLEAN is False

   start_position: POSITION
         -- Of the first opening '%"' character or of the "once"  keyword
         -- if any.

   once_flag: BOOLEAN
	 -- Is it a once manifest string?

   unicode_flag: BOOLEAN
	 -- Is it a unicode manifest string?

   to_string: STRING
         -- The content of the Eiffel string from the programmer's point of
         -- view (i.e. what is inside the manifest string at run time).
	 -- (See also `source_view'.)

   unicode_string: UNICODE_STRING
	 -- Non Void when the U"foo" notation is used.

   result_type: E_TYPE
	 -- TYPE_STRING (for STRING) or TYPE_CLASS (for UNICODE_STRING).
   
   is_static: BOOLEAN is
      do
	 Result := once_flag
      end

   is_equal(other: like Current): BOOLEAN is
      do
         if other = Current then
            Result := True
         elseif unicode_flag then
	    if other.unicode_flag then
	       Result := to_string.is_equal(other.to_string)
	    end
	 elseif other.unicode_flag then
	 else
	    Result := to_string.is_equal(other.to_string)
	 end
      end

   hash_code: INTEGER is
      do
	 if hash_code_memory = 0 then
	    hash_code_memory := to_string.hash_code
	 end
	 Result := hash_code_memory
      end
   
   start_lookup_class: BASE_CLASS is do end

   assertion_check(tag: CHARACTER) is do end

   to_integer_or_error: INTEGER is
      do
	 to_integer_error
      end

   isa_dca_inline_argument: INTEGER is do end

   dca_inline_argument(formal_arg_type: E_TYPE) is do end

   compile_to_c is
      do
	 c_code.clear_count
	 if once_flag then
	    once_c_mapping
	 elseif unicode_flag then
	    manifest_string_pool.se_ums_c_call_in(c_code, Current)
	 else
	    manifest_string_pool.se_ms_c_call_in(c_code, Current)
	 end
	 cpp.put_string(c_code)
      end

   mapping_c_target(target_type: E_TYPE) is
      do
	 cpp.put_character('(')
	 result_type.mapping_cast
         compile_to_c
	 cpp.put_character(')')
      end

   mapping_c_arg(formal_arg_type: E_TYPE) is
      do
         compile_to_c
      end

   collect_c_tmp is do end

   c_frame_descriptor(format, locals: STRING) is do end

   afd_check is do end

   safety_check is do end

   count: INTEGER is
      do
         Result := to_string.count
      end

   compile_target_to_jvm, compile_to_jvm is
      local
         idx: INTEGER
      do
	 if once_flag then
	    idx := fieldref_idx
	    code_attribute.opcode_getstatic(idx,1)
	 else
	    code_attribute.opcode_push_manifest_string(to_string)
	 end
      end

   compile_to_jvm_assignment(a: ASSIGNMENT) is do end

   jvm_branch_if_false: INTEGER is do end

   jvm_branch_if_true: INTEGER is do end

   jvm_assign_creation, jvm_assign is do end

   compile_to_jvm_into(dest: E_TYPE): INTEGER is
      do
         Result := 1
         compile_to_jvm
      end

   to_runnable(ct: E_TYPE): MANIFEST_STRING is
      local
	 utf8_parser: UTF8_PARSER; bcn: CLASS_NAME
      do
	 manifest_string_pool.register(Current)
         Result := Current
	 if result_type = Void then
	    type_string_set_at_run_time
	    if once_flag then
	       if once_variable = Void then
		  once_variable :=
		     manifest_string_pool.once_register(Current)
	       end
	    end
	    -- Computing the `result_type': 
	    if unicode_flag then
	       create unicode_string.make(to_string.count * 2)
	       utf8_parser.decode(to_string, unicode_string)
	       if utf8_parser.first_error /= Void then
		  error_handler.append("Invalid unicode string at index ")
		  error_handler.add_position(start_position)
		  error_handler.append_integer(utf8_parser.first_error_index)
		  error_handler.append(" of this Unicode manifest string. ")
		  error_handler.append(utf8_parser.first_error)
		  error_handler.print_as_error
	       else
		  create bcn.make(as_unicode_string, start_position)
		  create {TYPE_CLASS} result_type.make(bcn)
		  set_se_ums_live
	       end
	    else
	       create {TYPE_STRING} result_type.make(start_position)
	       set_se_ms_live
	    end
	 end
      end

   simplify_1_, simplify_2: like Current is
      do
	 Result := Current
      end
   
   stupid_switch(run_time_set: RUN_TIME_SET): BOOLEAN is
      do
         Result := True
      end

   precedence: INTEGER is
      do
         Result := atomic_precedence
      end

   bracketed_pretty_print, pretty_print is
      local
         i: INTEGER
      do
	 if once_flag then
	    if pretty_printer.last_non_blank_character_is('(') then
	       pretty_printer.put_string(fz_once)
	       pretty_printer.put_character(' ')
	    else
	       pretty_printer.keyword(fz_once)
	    end
	 end
	 pretty_printer.set_no_blanks_to_tab_flag(True)
	 if unicode_flag then
	    pretty_printer.put_character('U')
	 end
         from
            i := source_view.lower
         until
            i > source_view.upper
         loop
	    pretty_printer.put_string(source_view.item(i))
            i := i + 1
         end
	 pretty_printer.set_no_blanks_to_tab_flag(False)
      end

   print_as_target is
      do
         pretty_printer.put_character('(')
         pretty_print
         pretty_printer.put_character(')')
         pretty_printer.put_character('.')
      end

   short is
      local
         i, j: INTEGER; line_view: STRING
      do
	 if once_flag then
	    short_print.hook_or(fz_once,once "once ")
	 end
         short_print.hook_or("open_ms","%"")
         from
            i := source_view.lower
         until
            i > source_view.upper
         loop
            line_view := source_view.item(i)
	    from
	       j := 1
	    until
	       j > line_view.count
	    loop
	       if i = source_view.lower and then j = 1 then
		  -- (to skip the opening %")
	       elseif i = source_view.upper and then j = line_view.count then
		  -- (to skip the closing %")
	       else
		  short_print.a_character(line_view.item(j))
	       end
	       j := j + 1
	    end
            i := i + 1
         end
         short_print.hook_or("close_ms","%"")
      end

   short_target is
      do
         bracketed_short
         short_print.a_dot
      end

feature {EIFFEL_PARSER, CST_ATT_STRING, WHEN_ITEM_1, CLASS_CHECKER}

   set_once_flag(flag: BOOLEAN) is
      do
	 once_flag := flag
      ensure
	 once_flag = flag
      end

feature {MANIFEST_STRING}

   set_alias_link(al: like alias_link) is
      require
	 al /= Void
      do
	 alias_link := al
      ensure
	 alias_link = al
      end

feature {EIFFEL_PARSER}

   set_source_view(sv: like source_view) is
      do
	 check
	    (sv /= Void) = (smart_eiffel.short_flag or
			    smart_eiffel.pretty_flag)
	 end
	 source_view := sv
      ensure
	 source_view = sv
      end

feature {MANIFEST_STRING, MANIFEST_STRING_POOL}

   alias_link: like Current
	 -- When runnable, may be non Void to indicate that `alias_link' has 
	 -- exactely the same initial storage information as `Current'. In 
	 -- this situation, both `Current' and `alias_link' have exactely 
	 -- the same `alias_global' mangling.
   
   alias_global: STRING
	 -- Mangling value for the storage information or to alias the 
	 -- initial storage information amongs different objects.


feature {MANIFEST_STRING_POOL}

   once_variable: STRING
         -- When runnable. The name to be used for the corresponding global 
         -- once memory variable in the generated code (C or bytecode as 
         -- well).

   set_alias_global(ag: like alias_global) is
      require
	 ag /= Void
      do
	 alias_global := ag
      ensure
	 alias_global = ag
      end

   storage_alias_of(other: like Current) is
      require
	 alias_link = Void
	 alias_global = Void
	 other.alias_global /= Void
      do
	 alias_link := other
	 alias_global := other.alias_global
	 other.set_alias_link(Current)
      ensure
	 alias_link = other
	 other.alias_link = Current
	 alias_global = other.alias_global
      end
   
   fieldref_idx: INTEGER is
      do
         Result := constant_pool.
	                 idx_fieldref_for_manifest_string(once_variable)
      end

feature {MANIFEST_STRING_VISITOR}

   accept(visitor: MANIFEST_STRING_VISITOR) is
      do
         visitor.visit_manifest_string(Current)
      end

feature {NONE}

   hash_code_memory: INTEGER
	 -- To cache `hash_code' value.
   
   set_se_ms_live is
      local
	 rf: RUN_FEATURE; run_class: RUN_CLASS; fn: FEATURE_NAME
      once
	 run_class := result_type.run_class
	 create fn.simple_feature_name(as_item, start_position)
	 rf := run_class.get_feature(fn)
	 run_class.set_at_run_time
      end
   
   set_se_ums_live is
      local
	 rf: RUN_FEATURE; run_class: RUN_CLASS; fn: FEATURE_NAME
      once
	 run_class := result_type.run_class
	 create fn.simple_feature_name(as_manifest_initialize,
				       start_position)
	 rf := run_class.get_feature(fn)
	 manifest_string_pool.set_se_ums(rf)
	 run_class.set_at_run_time
      end
   
   source_view: FAST_ARRAY[STRING]
	 -- The manifest string as it appear in the Eiffel source file (see
	 -- also `to_string'). This information is only computed for
	 -- formatting tools (`pretty' or `short' for example).

   once_c_mapping is
      require
	 once_flag
      do
	 if smart_eiffel.scoop then
	    c_code.append(once "scoop_once_manifest_string(%"")
	    c_code.append(once_variable)
	    c_code.append(once "%",")
	    count.append_in(c_code)
	    c_code.extend(',')
	    manifest_string_pool.string_to_c_code(to_string, c_code)
	    c_code.extend(')')
	 else
	    c_code.append(once_variable)
	 end
      end

   make(sp: like start_position;
	of: like once_flag uf: like unicode_flag; ts: like to_string) is
      require
         not sp.is_unknown
	 ts /= Void
      do
         start_position := sp
	 once_flag := of
	 unicode_flag := uf
         to_string := ts.twin
      ensure
         start_position = sp
	 once_flag = of
	 unicode_flag = uf
	 to_string /= ts and then to_string.is_equal(ts)
      end

   c_code: STRING is
      once
	 create Result.make(512)
      end

   type_string_set_at_run_time is
      once
	 type_string.set_at_run_time
      end

invariant

   not start_position.is_unknown

   to_string /= Void

end -- MANIFEST_STRING
