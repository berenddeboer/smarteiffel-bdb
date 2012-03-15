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
class INI_PARSER
   --
   -- .INI-like files parser
   --
   -- inifile -> key* [section]*
   --
   -- key -> identifier ':' value '%N'
   --
   -- section -> '[' identifier ']' '%N' key*
   --
   -- Eiffel-like comments are allowed at ends of lines and on empty lines
   --
inherit
   PARSER
      redefine
         skip1, fcp
      end

feature {INI_PARSER_VISITOR}

   accept(visitor: INI_PARSER_VISITOR) is
      do
         visitor.visit_ini_parser(Current)
      end

feature

   file_path: STRING

feature {SYSTEM_TOOLS, INSTALL} -- Parsing:

   a_inifile is
      require
         parser_buffer.is_ready
      do
         debug
            echo.put_string(once "<inifile>%N")
         end

         last_section := Void
         last_key := Void

	 line := 1
	 column := 1
	 current_line := parser_buffer.item(line)
         file_path := parser_buffer.path
	 if current_line.count = 0 then
	    cc := '%N'
	 else
	    cc := current_line.first
	 end
         skip_comments
         if cc /= '[' then
            a_keys
         end
         a_sections
         goto_next_line
         if cc /= end_of_text then
            error_handler.add_position(pos(line, column))
            fcp("Unexpected text continuation")
         elseif default_section = Void and then sections = Void then
            error_handler.add_position(pos(line, column))
            fcp("Invalid empty file")
         end

         debug
            echo.put_string(once "</inifile>%N")
         end

         parser_buffer.release
      ensure
         not parser_buffer.is_ready
      end

feature {SYSTEM_TOOLS, INSTALL}

   is_invalid: BOOLEAN

feature -- Values in the default section:

   has(key: STRING): BOOLEAN is
      do
         Result := default_section /= Void and then default_section.has(key)
      end

   item(key: STRING): STRING is
      require
         has(key)
      do
         Result := default_section.at(key)
      end

   key_iterator: ITERATOR[STRING] is
      do
         if default_section /= Void then
            Result := default_section.get_new_iterator_on_keys
         end
      end

feature -- Values in sections:

   section_has(section, key: STRING): BOOLEAN is
      local
         sec: like default_section
      do
         if sections /= Void then
            sec := sections.reference_at(section)
            Result := sec /= Void and then sec.has(key)
         end
      end

   section_item(section, key: STRING): STRING is
      require
         section_has(section, key)
      do
         Result := sections.at(section).at(key)
      end

   sections_iterator: ITERATOR[STRING] is
      do
         if sections /= Void then
            Result := sections.get_new_iterator_on_keys
         end
      end

   section_key_iterator(section: STRING): ITERATOR[STRING] is
      local
         sec: HASHED_DICTIONARY[STRING, STRING]
      do
         if sections /= Void then
            sec := sections.reference_at(section)
            if sec /= Void then
               Result := sec.get_new_iterator_on_keys
            end
         end
      end

feature {NONE} -- Parser:

   last_section: STRING
   last_key: STRING

   a_sections is
      local
         stop: BOOLEAN
      do
         debug
            echo.put_string(once "<sections>%N")
         end

         from
            goto_next_line
         until
            stop
         loop
            stop := not a_section
         end

         debug
            echo.put_string(once "</sections>%N")
         end
      end

   a_section: BOOLEAN is
      do
         debug
            echo.put_string(once "<section>%N")
         end

         if skip_spaces and then skip1('[') and then skip_spaces then
            Result := a_identifier and then skip_spaces and then skip1(']') and then skip_spaces
            if Result then
               goto_next_line
               last_section := tmp_name.case_sensitive_aliased_string
               if sections = Void then
                  create sections.make
               end
               if not sections.has(last_section) then
                  sections.add(create {ORDERED_DICTIONARY[STRING, STRING]}.make, last_section)
               end
               a_keys
            end
         end

         debug
            echo.put_string(once "</section result='")
            echo.put_string(Result.out)
            echo.put_string(once "'>%N")
         end
      end

   a_keys is
      local
         stop: BOOLEAN
      do
         debug
            echo.put_string(once "<keys>%N")
         end

         from
            goto_next_line
         until
            stop
         loop
            stop := not a_key
         end

         debug
            echo.put_string(once "</keys>%N")
         end
      end

   a_key: BOOLEAN is
      local
         dummy: BOOLEAN
      do
         debug
            echo.put_string(once "<key>%N")
         end

         if a_identifier and then skip_spaces then
            if not skip1(':') then
               error_handler.add_position(pos(line, column))
               error_handler.append(once "Inserted ':'")
               error_handler.print_as_warning
            end
            dummy := skip_spaces
            last_key := tmp_name.aliased_string

            if last_value /= Void then
               echo.w_put_string(once "The key '")
               echo.w_put_string(last_key)
               echo.w_put_string(once "' is defined more than once")
               if last_section /= Void then
                  echo.w_put_string(once " in the section [")
                  echo.w_put_string(last_section)
                  echo.w_put_character(']')
               end
               echo.w_put_string(once ".%NIts retained value will be the last read.%N")
            end

            if cc = '%N' or else cc = end_of_text then
               Result := True
               set_value(once "")
            elseif cc = '"' and then a_manifest_string then
               Result := True
               set_value(last_manifest_string.to_string)
            elseif a_string then
               Result := True
               set_value(tmp_name.aliased_string)
            end
            if Result then
               goto_next_line
            end
         end

         debug
            echo.put_string(once "</key result='")
            echo.put_string(Result.out)
            echo.put_string(once "'>%N")
         end
      end

   goto_next_line is
      do
         from
         until
            not skip1('%N')
         loop
            skip_comments
         end
      end

   set_value(value: STRING) is
      do
         if last_section = Void then
            if default_section = Void then
               create default_section.make
            end
            default_section.add(value, last_key)
         else
            sections.at(last_section).add(value, last_key)
         end
      end

   last_value: STRING is
      do
         if last_section = Void then
            if default_section /= Void then
               Result := default_section.reference_at(last_key)
            end
         elseif sections.has(last_section) then
            Result := sections.at(last_section).reference_at(last_key)
         end
      end

feature {NONE}

   last_manifest_string: MANIFEST_STRING

   a_identifier: BOOLEAN is
	 -- Case-sensitive identifiers, used for section names and key
	 -- names. The dot is not eiffel-like, but useful in many cases.
      local
	 stop: BOOLEAN
      do
         debug
            echo.put_string(once "<a_identifier>%N")
         end

	 if cc.is_letter then
	    from
	       tmp_name.reset(pos(line,column))
	       tmp_name.extend(cc)
	    until
	       stop
	    loop
	       next_char
	       inspect
		  cc
	       when 'a'..'z' then
		  tmp_name.extend(cc)
	       when 'A'..'Z' then
		  tmp_name.extend(cc)
	       when '0'..'9','_','.' then
		  tmp_name.extend(cc)
	       else
		  stop := True
	       end
	    end
            Result := True
	 end

         debug
            echo.put_string(once "</a_identifier result='")
            echo.put_string(Result.out)
            if Result then
               echo.put_string(once "' identifier='")
               echo.put_string(tmp_name.aliased_string)
            end
            echo.put_string(once "'>%N")
         end
      end

   a_string: BOOLEAN is
	 -- Some string
      local
         state, l, c: INTEGER
      do
         debug
            echo.put_string(once "<a_string>%N")
         end

         from
            tmp_name.reset(pos(line,column))
            state := 0
         until
            cc = '%N' or else cc = end_of_text
         loop
            Result := True
            inspect
               state
            when 0 then
               -- reading "normal" characters
               inspect
                  cc
               when ' ', '%T' then
                  buffer.extend(cc)
                  state := 1
               when '-' then
                  l := line
                  c := column
                  state := 2
               else
                  tmp_name.extend(cc)
               end
            when 1 then
               -- reading spaces. They will be appended if some normal
               -- characters are still to be found after
               inspect
                  cc
               when ' ', '%T' then
                  buffer.extend(cc)
               when '-' then
                  l := line
                  c := column
                  state := 2
               else
                  tmp_name.append(buffer)
                  buffer.clear_count
                  tmp_name.extend(cc)
                  state := 0
               end
            when 2 then
               -- just read a '-'. If a second is read, then it is a comment;
               -- the string is finished
               inspect cc
               when '-'then
                  state := 3
               when ' ', '%T' then
                  tmp_name.append(buffer)
                  tmp_name.extend('-')
                  buffer.clear_count
                  buffer.extend(cc)
                  state := 1
               else
                  tmp_name.append(buffer)
                  tmp_name.extend('-')
                  tmp_name.extend(cc)
                  buffer.clear_count
                  state := 0
               end
            when 3 then
               -- reading a comment
            end
            next_char
         end

         debug
            echo.put_string(once "</a_string result='")
            echo.put_string(Result.out)
            if Result then
               echo.put_string(once "' string='")
               echo.put_string(tmp_name.aliased_string)
            end
            echo.put_string(once "'>%N")
         end
      end

   skip_spaces: BOOLEAN is
         -- returns always True
      local
         stop: BOOLEAN
      do
         from
         until
            stop
         loop
            inspect cc
            when ' ', '%T' then
               next_char
            else
               stop := True
            end
         end
         Result := True
      ensure
         Result
      end

   skip1(char: CHARACTER): BOOLEAN is
         -- Redefined to not skip comments
      do
	 if char = cc then
	    start_line := line
	    start_column := column
	    Result := True
	    next_char
	 end
      end

   skip2(c1, c2: CHARACTER): BOOLEAN is
      do
	 if c1 = cc then
	    start_line := line
	    start_column := column
	    next_char
	    if c2 = cc then
	       Result := True
	       next_char
	       skip_comments
	    else
	       cc := c1
	       column := start_column
	    end
	 end
      end

   a_manifest_string: BOOLEAN is
      local
	 state, l, c: INTEGER; once_flag, unicode_flag, stop: BOOLEAN
	 ascii_code, unicode, digit_count: INTEGER
	 line_view: STRING
	 multi_line_end: STRING; left_alignment, current_alignment: INTEGER
      do
         debug
            echo.put_string(once "<a_manifest_string>%N")
         end

	 l := line; c := column
	 if a_keyword(fz_once) then once_flag := True end
	 if cc = 'U' then
	    unicode_flag := True; next_char
	 end
	 if cc = '%"' then
	    Result := True
	    if smart_eiffel.short_flag or else smart_eiffel.pretty_flag then
	       create line_view.make(32)
	    end
	    from buffer.clear_count until
	       state > 9
	    loop
	       next_char
	       inspect
		  state
	       when 0 then -- Somewhere inside the manifest string.
		  inspect
		     cc
		  when '%N' then
		     from until	multi_line_end /= Void
		     loop
			if buffer.is_empty then
			   fcp(em8)
			else
			   inspect
			      buffer.last
			   when ' ', '%T' then
			      buffer.remove_last(1)
			      wcp(em42)
			   when '{', '[' then
			      multi_line_end := once "]foo%""
			      multi_line_end.clear_count
			      if buffer.last = '{' then
				 multi_line_end.extend('}')
				 left_alignment := 1
				 state := 8
			      else
				 multi_line_end.extend(']')
				 state := 7
			      end
			      multi_line_end.append(buffer)
			      current_alignment := 1
			      multi_line_end.remove_last(1)
			      multi_line_end.extend('%"')
			      buffer.clear_count
			   else
			      fcp(em8)
			   end
			end
		     end
		  when '%"' then
		     state := 11
		  when '%%' then
		     state := 1
		  else
		     buffer.extend(cc)
		  end
	       when 1 then -- Just after a '%%'.
		  state := 0
		  inspect
		     cc
		  when '%N' then
		     state := 3
		  when 'A' then buffer.extend('%A')
		  when 'B' then buffer.extend('%B')
		  when 'C' then buffer.extend('%C')
		  when 'D' then buffer.extend('%D')
		  when 'F' then buffer.extend('%F')
		  when 'H' then buffer.extend('%H')
		  when 'L' then buffer.extend('%L')
		  when 'N' then buffer.extend('%N')
		  when 'Q' then buffer.extend('%Q')
		  when 'R' then buffer.extend('%R')
		  when 'S' then buffer.extend('%S')
		  when 'T' then buffer.extend('%T')
		  when 'U' then buffer.extend('%U')
		  when 'V' then buffer.extend('%V')
		  when '%%' then buffer.extend('%%')
		  when '%'' then buffer.extend('%'')
		  when '%"' then buffer.extend('%"')
		  when '(' then buffer.extend('%(')
		  when ')' then buffer.extend('%)')
		  when '<' then buffer.extend('%<')
		  when '>' then buffer.extend('%>')
		  when '/' then
		     ascii_code := 0
		     digit_count := 0
		     state := 4
		  when ' ','%T' then
		     state := 2
		  else
		     fcp(em37)
		     state := 0
		  end
	       when 2 then -- Extended form. At end of line.
		  inspect
		     cc
		  when '%N' then
		     state := 3
		  when ' ','%T' then
		     wcp(em42)
		  else
		     fcp("In extended form of manifest string.%
			 %Bad character after '%%'.")
		  end
	       when 3 then  -- Extended form. At beginning of line.
		  inspect
		     cc
		  when ' ','%T' then
		  when '%%' then
		     state := 0
		  when '%N' then
		     fcp(em8)
		  else
		     fcp("In extended form of manifest string.%
			 % Bad character before '%%'.")
		  end
	       when 4 then  -- Inside ascii code. After opening '/'.
		  inspect
		     cc
		  when '0' .. '9' then
		     digit_count := digit_count + 1
		     ascii_code := ascii_code * 10 + cc.decimal_value
		  when 'x' then
		     if digit_count = 1 and ascii_code = 0 then
			digit_count := 0
			state := 5
		     else
			fcp(em38)
		     end
		  when 'U' then
		     if digit_count = 0 then
			next_char
			if cc = 'x' then
			   state := 6
			   unicode := 0
			   digit_count := 0
			else fcp(em38) end
		     else
			fcp(em38)
		     end
		  when '/' then
		     buffer.extend(ascii_code.to_character)
		     state := 0
		     if digit_count = 0 then
			ecp(em39)
		     elseif ascii_code > Maximum_character_code then
			ascii_code := 0
			ecp(em40)
		     end
		  else
		     fcp(em38)
		  end
	       when 5 then  -- Inside ascii code. After /0x
		  if cc.is_hexadecimal_digit then
		     ascii_code := ascii_code * 16 + cc.hexadecimal_value
		     digit_count := digit_count + 1
		     if digit_count.is_even then
			buffer.extend(ascii_code.to_character)
			ascii_code := 0
		     end
		  elseif cc = '/' then
		     state := 0
		     if digit_count = 0 then
			ecp(em45)
		     elseif digit_count.odd then
			ecp("You must use an even number of hexadecimal %
                            %digits to denote a sequence of CHARACTERs.")
		     end
		  else
		     fcp(em45)
		  end
	       when 6 then  -- Inside unicode code. After /Ux
		  if cc.is_hexadecimal_digit then
		     unicode := unicode * 16 + cc.hexadecimal_value
		     digit_count := digit_count + 1
		  elseif cc = '/' then
		     state := 0
		     if digit_count = 0 then
			ecp(em46)
		     elseif digit_count > 8 then
			ecp("Too long hexadecimal sequence %
                            %for a single unicode value.")
		     else
			unicode_string_buffer.clear
			if unicode_string_buffer.valid_unicode(unicode) then
			   unicode_string_buffer.add_last(unicode)
			   unicode_string_buffer.utf8_encode_in(buffer)
			else
			   ecp("Invalid unicode notation (see also http://%
			       %www.unicode.org as well as feature %
			       %{UNICODE_STRING}.valid_unicode).")
			end
		     end
		  else
		     fcp(em46)
		  end
	       when 7 then -- Just after the multi-line opener, in left
		  -- alignment mode.
		  check left_alignment = 0 end
		  inspect
		     cc
		  when ' ', '%T' then
		     current_alignment := current_alignment + 1
		  when '%N' then
		     buffer.extend('%N'); current_alignment := 1
		  when end_of_text then
		     error_handler.add_position(pos(l,c))
		     fcp(em41)
		  else
		     buffer.extend(cc)
		     if left_alignment = 0 then
			left_alignment := current_alignment
		     end
		     state := 8
		  end
	       when 8 then -- Inside multi-line manifest string.
		  current_alignment := current_alignment + 1
		  inspect
		     cc
		  when ' ', '%T' then
		     if current_alignment >= left_alignment then
			buffer.extend(cc)
		     end
		  when '%N' then
		     buffer.extend(cc); current_alignment := 0
		  when end_of_text then
		     error_handler.add_position(pos(l,c))
		     fcp(em41)
		  when '%"' then
		     buffer.extend(cc)
		     if buffer.has_suffix(multi_line_end) then
			state := 10
		     end
		  else
		     if current_alignment < left_alignment then
			if cc = multi_line_end.first then
			   buffer.extend(cc)
			   state := 9
			else
			   error_handler.add_position(pos(l,c))
			   fcp(em41)
			end
		     else
			buffer.extend(cc)
		     end
		  end
	       when 9 then -- Inside multi-line closer.
		  inspect
		     cc
		  when end_of_text then
		     error_handler.add_position(pos(l,c))
		     fcp(em41)
		  when '%"' then
		     buffer.extend(cc)
		     if buffer.has_suffix(multi_line_end) then
			state := 10
		     end
		  else
		     buffer.extend(cc)
		  end
	       end
	    end
	    if state = 10 then -- Good verbatim string.
	       buffer.remove_suffix(multi_line_end)
	       from
	       until stop
	       loop
		  if buffer.is_empty then
		     stop := True
		  else
		     stop := buffer.last = '%N'
		     buffer.remove_last(1)
		  end
	       end
	    end
	    create last_manifest_string.make(pos(l,c),
	                                     once_flag, unicode_flag, buffer)
	    next_char
	    skip_comments
	 end

         debug
            echo.put_string(once "</a_manifest_string result='")
            echo.put_string(Result.out)
            if Result then
               echo.put_string(once "' string='")
               echo.put_string(last_manifest_string.to_string)
            end
            echo.put_string(once "'>%N")
         end
      end

   buffer: STRING is
      once
	 create Result.make(80)
      end

   unicode_string_buffer: UNICODE_STRING is
      once
	 create Result.make_empty
      end

   ecp(msg: STRING) is
	 -- Error at current position.
      do
	 error(current_position, msg)
      end

   fcp(msg: STRING) is
      do
         if is_install.item then
            is_invalid := True
         else
            Precursor(msg)
         end
      end

   pos(l, c: INTEGER): POSITION is
      do
	 Result.ini_file(l,c)
      end

feature {NONE} -- Sections:

   default_section: ORDERED_DICTIONARY[STRING, STRING]
   sections: ORDERED_DICTIONARY[ORDERED_DICTIONARY[STRING, STRING], STRING]

invariant

   is_invalid implies is_install.item

end
