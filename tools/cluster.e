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
class CLUSTER
   --
   -- A CLUSTER description. Such an object is created for each cluster
   -- entry of the ACE file in ACE file mode, but also for each directory of
   -- the loading path for the ordinary command line mode.
   --

inherit
   GLOBALS
   VISITABLE
   ASSERTION_LEVEL_NUMBERING

creation {ACE} compute_directory_path_using

feature {CLUSTER_VISITOR}

   accept(visitor: CLUSTER_VISITOR) is
      do
         visitor.visit_cluster(Current)
      end

feature {ACE}

   parser_buffer_for(class_name: STRING): BOOLEAN is
	 -- Try to prepare the `parser_buffer' assuming `class_name' is the
	 -- classic Eiffel notation for a class name (actually the aliased
	 -- one using only upper case letters).
      require
	 class_name = string_aliaser.item(class_name)
      local
	 i, count: INTEGER; excluded: BOOLEAN
      do
	 -- Update the `file_name_buffer':
	 from
	    file_name_buffer.clear
	    i := 1
	    count := class_name.count
	 until
	    i > count
	 loop
	    file_name_buffer.extend(class_name.item(i).to_lower)
	    i := i + 1
	 end
	 file_name_buffer.extend('.')
	 file_name_buffer.extend('e')
	 if exclude_list /= Void then
	    excluded := exclude_list.has(file_name_buffer)
	 end
	 if excluded then
	 elseif parser_buffer_load then
	    -- Try the most common case first. (The name of the file uses
	    -- lower case letters only.)
	    Result := True
	 else
	    -- All in upper cases (strange but not so uncommon):
	    file_name_buffer.to_upper
	    if parser_buffer_load then
	       Result := True
	    else
	       -- May happens:
	       file_name_buffer.to_upper
	       file_name_buffer.put('e',file_name_buffer.count)
	       Result := parser_buffer_load
	    end
	 end
      end

   rename_se_parser_buffer_for(class_name: STRING): BOOLEAN is
	 -- To handle old "rename.se" files.
      require
	 class_name = string_aliaser.item(class_name)
      local
	 i, count: INTEGER
      do
	 -- Update the `file_name_buffer':
	 from
	    file_name_buffer.clear
	    i := 1
	    count := class_name.count
	 until
	    i > count
	 loop
	    file_name_buffer.extend(class_name.item(i).to_lower)
	    i := i + 1
	 end
	 file_name_buffer.extend('.')
	 file_name_buffer.extend('e')
	 if rename_se /= Void then
	    -- To handle old "rename.se" files.
	    if rename_se.has(file_name_buffer) then
	       file_name_buffer.copy(rename_se.at(file_name_buffer))
	       Result := parser_buffer_load
	    end
	 end
      end

   pretty_in(txt: STRING) is
	 -- Performs the `ace_check' and also prepare in `txt' a pretty version
	 -- of the Ace file as it is memorized (can be also used to pretty
	 -- one's ACE file).
      require
	 ace.file_path /= Void
      local
	 i, l: INTEGER; basic_directory: BASIC_DIRECTORY
	 cn: CLASS_NAME
      do
	 txt.append("   ")
	 if name /= Void then
	    txt.append(name)
	    txt.append(": ")
	 end
	 txt.extend('%"')
	 txt.append(directory_path)
	 txt.extend('%"')
	 basic_directory.connect_to(directory_path)
	 txt.extend('%N')
	 if basic_directory.is_connected then
	    basic_directory.disconnect
	 else
	    txt.append(" -- *** ERROR: directory %"")
	    txt.append(directory_path)
	    txt.append("%" not found or not readable ***%N")
	 end
	 if include_list /= Void then
	    txt.append("      include ")
	    from
	       i := include_list.lower
	    until
	       i > include_list.upper
	    loop
	       txt.extend('%"')
	       txt.append(include_list.item(i))
	       txt.extend('%"')
	       i := i + 1
	       if i <= include_list.upper then
		  txt.extend(';')
	       end
	    end
	    txt.extend('%N')
	 end
	 if exclude_list /= Void then
	    txt.append("      exclude ")
	    from
	       i := exclude_list.lower
	    until
	       i > exclude_list.upper
	    loop
	       txt.extend('%"')
	       txt.append(exclude_list.item(i))
	       txt.extend('%"')
	       i := i + 1
	       if i <= exclude_list.upper then
		  txt.extend(';')
	       end
	    end
	    txt.extend('%N')
	 end
	 txt.append("      default%N")
	 txt.append("         assertion (")
	 txt.append(level_name(default_assertion_level))
	 txt.append(")%N")
	 if default_trace /= '%U' then
	    txt.append("         trace (")
	    inspect
	       default_trace
	    when 'n' then
	       txt.append("no")
	    when 'y' then
	       txt.append("yes")
	    end
	    txt.append(")%N")
	 end
	 if option_assertion_level /= Void then
	    txt.append("      option%N")
	 end
	 if option_assertion_level /= Void then
	    from
	       i := option_assertion_level.lower
	    until
	       i > option_assertion_level.upper
	    loop
	       l := option_assertion_level.item(i)
	       cn := option_assertion_level.key(i)
	       txt.append("         assertion (")
	       txt.append(level_name(l))
	       txt.append("): ")
	       txt.append(cn.to_string)
	       txt.append("%N")
	       if not parser_buffer_for(cn.to_string) then
		  error_handler.add_position(cn.start_position)
		  error_handler.append("No such class in this cluster.")
		  error_handler.print_as_error
	       else
		  parser_buffer.release
	       end
	       i := i + 1
	    end
	 end
	 txt.append("      end")
	 if name /= Void then
	    txt.append(" -- ")
	    txt.append(name)
	 end
	 txt.extend('%N')
      end

   view_in(no: INTEGER; msg: STRING) is
      local
	 i: INTEGER
      do
	 msg.append("cluster ")
	 no.append_in(msg)
	 msg.append(":%N   ")
	 if name /= Void then
	    msg.append(name)
	    msg.extend(':')
	 end
	 msg.extend('%"')
	 msg.append(directory_path)
	 msg.extend('%"')
	 msg.extend('%N')
	 if ace.file_path /= Void then
	    if include_list /= Void then
	       msg.append("   include ")
	       from
		  i := include_list.lower
	       until
		  i > include_list.upper
	       loop
		  msg.extend('%"')
		  msg.append(include_list.item(i))
		  msg.extend('%"')
		  msg.extend(';')
		  i := i + 1
	       end
	       msg.extend('%N')
	    end
	    if exclude_list /= Void then
	       msg.append("   exclude ")
	       from
		  i := exclude_list.lower
	       until
		  i > exclude_list.upper
	       loop
		  msg.extend('%"')
		  msg.append(exclude_list.item(i))
		  msg.extend('%"')
		  msg.extend(';')
		  i := i + 1
	       end
	       msg.extend('%N')
	    end
	    msg.append("   default assertion (")
	    msg.append(level_name(default_assertion_level))
	    msg.extend(')')
	 end
	 msg.extend('%N')
      end

   set_name(n: like name) is
      require
	 string_aliaser.item(n) = n
      do
	 name := n
      ensure
	 name = n
      end

   set_default_trace(flag: BOOLEAN) is
      do
	 if flag then
	    default_trace := 'y'
	 else
	    default_trace := 'n'
	 end
      end

   set_default_assertion_level(level: INTEGER) is
      require
	 level.in_range(level_boost,level_debug)
      do
	 default_assertion_level := level
      ensure
	 default_assertion_level = level
      end

   add_default_debug_key(key: STRING) is
      require
	 key /= Void
      do
	 if default_debug_keys = Void then
	    !!default_debug_keys.make(4)
	 end
	 default_debug_keys.add_last(key)
      ensure
	 default_debug_keys.has(key)
      end

   get_started is
	 -- Should be called to set some default values at the end of
	 -- command line parsing or at the end of the ACE file parsing.
      do
	 if default_assertion_level = level_unknown then
	    default_assertion_level := ace.default_assertion_level
	 elseif default_assertion_level = level_boost then
	    if ace.highest_level > level_boost then
	       default_assertion_level := level_no
	    end
	 end
      end

   include_parsing is
      local
	 i: INTEGER; fn: STRING
      do
	 if include_list /= Void then
	    from
	       i := include_list.lower
	    until
	       i > include_list.upper
	    loop
	       fn := include_list.item(i)
	       file_name_buffer.copy(fn)
	       if not parser_buffer_load then
		  error_handler.append("Cannot find include %"")
		  error_handler.append(fn)
		  error_handler.append("%" in cluster %"")
		  error_handler.append(directory_path)
		  error_handler.append("%" (check your ACE file).")
		  error_handler.print_as_fatal_error
	       end
	       smart_eiffel.parse_include(fn)
	       i := i + 1
	    end
	 end
      end

   set_option_assertion_level(class_name: CLASS_NAME; level: INTEGER) is
      require
	 class_name /= Void
	 level.in_range(level_boost,level_debug)
      local
	 cn: CLASS_NAME
      do
	 if option_assertion_level = Void then
	    !!option_assertion_level.make
	 end
	 if option_assertion_level.has(class_name) then
	    error_handler.add_position(class_name.start_position)
	    cn := option_assertion_level.internal_key(class_name)
	    error_handler.add_position(cn.start_position)
	    error_handler.append("Same class name appears twice.")
	    error_handler.print_as_fatal_error
	 end
	 option_assertion_level.put(level,class_name)
      end

   assertion_level_of(class_name: CLASS_NAME): INTEGER is
      require
	 class_name /= Void
      do
	 check Result = level_unknown end
	 if option_assertion_level /= Void then
	    if option_assertion_level.has(class_name) then
	       Result := option_assertion_level.at(class_name)
	    else
	       check
		  Result = level_unknown
	       end
	    end
	 end
	 if Result = level_unknown then
	    Result := default_assertion_level
	    check Result /= level_unknown end
	 end
      ensure
	 Result.in_range(level_boost,level_debug)
      end

   add_option_debug_key(class_name: CLASS_NAME; key: STRING) is
      require
	 class_name /= Void
	 not key.is_empty
      local
	 fas: FIXED_ARRAY[STRING]
      do
	 if option_debug_keys = Void then
	    create option_debug_keys.make
	 end
	 fas := option_debug_keys.reference_at(class_name)
	 if fas = Void then
	    create fas.make(4)
	    option_debug_keys.add(fas,class_name)
	 end
	 fas.add_last(key)
      end

   debug_check(class_name: CLASS_NAME; e_debug: E_DEBUG): BOOLEAN is
      local
	 fas: FIXED_ARRAY[STRING]
      do
	 if option_debug_keys = Void then
	    if default_debug_keys = Void then
	       Result := ace.default_debug(e_debug)
	    else
	       Result := match_debug_keys(e_debug,default_debug_keys)
	    end
	 else
	    fas := option_debug_keys.reference_at(class_name)
	    if fas /= Void then
	       Result := match_debug_keys(e_debug,fas)
	    elseif default_debug_keys = Void then
	       Result := ace.default_debug(e_debug)
	    else
	       Result := match_debug_keys(e_debug,default_debug_keys)
	    end
	 end
      end

   add_option_trace(class_name: CLASS_NAME) is
      require
	 class_name /= Void
      do
	 if option_trace = Void then
	    !!option_trace.make
	 end
	 option_trace.add(class_name)
      end

   trace(class_name: CLASS_NAME): BOOLEAN is
      do
	 if option_trace = Void then
	    Result := default_trace_or_ace_default_trace
	 elseif option_trace.has(class_name) then
	    Result := True
	 else
	    Result := default_trace_or_ace_default_trace
	 end
      end

   include_add_last(file_name: STRING) is
      require
	 file_name /= Void
      do
	 if include_list = Void then
	    !!include_list.with_capacity(16)
	 end
	 include_list.add_last(file_name)
      end

   exclude_add_last(file_name: STRING) is
      require
	 file_name /= Void
      do
	 if exclude_list = Void then
	    !!exclude_list.with_capacity(16)
	 end
	 exclude_list.add_last(file_name)
      end

   rename_se_clash(full_name: STRING): STRING is
	 -- To handle old "rename.se" files.
      require
	 ace.file_path = Void
      do
	 if rename_se /= Void then
	    if rename_se.has(full_name) then
	       create Result.make(256)
	       Result.append(directory_path)
	       system_tools.file_path(Result,rename_se.at(full_name))
	    end
	 end
      end

   rename_se_read is
         -- Load the "rename.se" file.
      require
	 ace.file_path = Void
      local
         full_name, short_name, clash, rename_extension: STRING
      do
	 tmp_path.copy(directory_path)
	 rename_extension := once "rename.se"
	 if tmp_path.is_empty then
	    tmp_path.append(rename_extension)
	 else
	    system_tools.file_path(tmp_path,rename_extension)
	 end
	 echo.tfr_connect(tmp_file_read,tmp_path)
	 if tmp_file_read.is_connected then
	    error_handler.append("Old style %"rename.se%" file used (%"")
	    error_handler.append(tmp_file_read.path)
	    error_handler.append("%"). The %"rename.se%" mechanism may become obsolete %
	              %in the near futur. You should consider to use an ACE %
	              %file right now.")
	    error_handler.print_as_warning
	    from
	       !!rename_se.make
	    until
	       tmp_file_read.end_of_input
	    loop
	       tmp_file_read.read_word
	       full_name := tmp_file_read.last_string.twin
	       tmp_file_read.read_word
	       short_name := tmp_file_read.last_string.twin
	       if short_name.is_empty then
		  echo.w_put_string("Each line in %"rename.se%" files %
				     %need exactly two names.%N")
		  die_with_code(exit_failure_code)
	       end
	       clash := ace.rename_se_clash(full_name)
	       if clash /= Void  then
		  echo.w_put_string("Multiple entry for %"")
		  echo.w_put_string(full_name)
		  echo.w_put_string("%" in %"rename.se%" files.%N%
				    %Clash for %N%"")
		  echo.w_put_string(short_name)
		  echo.w_put_string("%" and %N%"")
		  echo.w_put_string(clash)
		  echo.w_put_string(".%N")
		  die_with_code(exit_failure_code)
	       end
	       rename_se.put(short_name,full_name)
	       tmp_file_read.skip_separators
	    end
	    tmp_file_read.disconnect
	 end
      end

feature {CLUSTER_VISITOR}

   name: STRING

   directory_path: STRING

   is_from_config: BOOLEAN

feature {NONE}

   rename_se: DICTIONARY[STRING,STRING]
	 -- To handle the old "rename.se" files style.

   default_assertion_level: INTEGER
	 -- The default one for this cluster.

   default_trace: CHARACTER
	 -- The default trace selection for this cluster ('%U'|'y'|'n').

   default_trace_or_ace_default_trace: BOOLEAN is
	 -- If any, gives the default trace of this `Current' cluster
	 -- otherwise the `default_trace' of `ace'.
      do
	 inspect
	    default_trace
	 when '%U' then
	    Result := ace.default_trace
	 when 'y' then
	    Result := True
	 when 'n' then
	 end
      end

   default_debug_keys: FIXED_ARRAY[STRING]
	 -- The default(s) one for this cluster.

   option_assertion_level: DICTIONARY[INTEGER,CLASS_NAME]

   option_debug_keys: DICTIONARY[FIXED_ARRAY[STRING],CLASS_NAME]

   option_trace: SET[CLASS_NAME]

   compute_directory_path_using(path: STRING; from_config: BOOLEAN) is
      require
	 path /= Void
      local
	 buffer: STRING
      do
	 --check -- To save the `string_aliaser' memory:
	 --   path /= string_aliaser.item(path)
	 --end
	 buffer := path_buffer
	 buffer.copy(path)
	 system_tools.cluster_path(buffer)
	 directory_path := string_aliaser.item(buffer)
         is_from_config := from_config
      ensure
	 directory_path = string_aliaser.item(directory_path)
      end

   parser_buffer_load: BOOLEAN is
      do
	 if directory_path.is_empty then
	    path_buffer.copy(file_name_buffer)
	 else
	    path_buffer.copy(directory_path)
	    system_tools.file_path(path_buffer,file_name_buffer)
	 end
	 parser_buffer.load_file(path_buffer)
	 Result := parser_buffer.is_ready
	 if Result then
	    parser_buffer.set_cluster(Current)
	 end
      end

   match_debug_keys(e_debug: E_DEBUG; list: FIXED_ARRAY[STRING]): BOOLEAN is
      local
	 key: STRING; i: INTEGER
      do
	 from
	    i := list.upper
	 until
	    Result or else i < list.lower
	 loop
	    key := list.item(i)
	    if key = fz_yes then
	       Result := True
	    elseif key = fz_no then
	       i := list.lower
	    else
	       Result := e_debug.match_debug_key(key)
	    end
	    i := i - 1
	 end
      end

   file_name_buffer: STRING is
	 -- Temporary buffer to store some file name like eg. "array.e".
      once
	 !!Result.make(64)
      end

   path_buffer: STRING is
	 -- Temporary buffer to store some file path like eg.
	 -- "../lib/kernel/array.e".
      once
         !!Result.make(256)
      end

   include_list: FIXED_ARRAY[STRING]

   exclude_list: FIXED_ARRAY[STRING]

end -- CLUSTER
