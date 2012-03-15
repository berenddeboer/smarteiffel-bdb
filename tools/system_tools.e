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
class SYSTEM_TOOLS
   --
   -- Singleton object to handle system dependant information.
   -- This singleton is shared via the GLOBALS.`system_tools' once function.
   --
   -- Only this object is supposed to handle contents of the `SmartEiffel'
   -- system environment variable.
   --
   -- You may also want to customize this class in order to support a
   -- new operating system (please let us know).
   --

inherit
   GLOBALS
   VISITABLE

creation make, install

feature {SYSTEM_TOOLS_VISITOR}

   accept(visitor: SYSTEM_TOOLS_VISITOR) is
      do
         visitor.visit_system_tools(Current)
      end

feature {INSTALL}

   -- Currently handled system list:
   unix_system:        STRING is "UNIX"
   windows_system:     STRING is "Windows"
   cygwin_system:      STRING is "Cygwin"
   beos_system:        STRING is "BeOS"
   macintosh_system:   STRING is "Macintosh"
   amiga_system:       STRING is "Amiga"
   dos_system:         STRING is "DOS"
   os2_system:         STRING is "OS2"
   open_vms_system:    STRING is "OpenVMS"
   elate_system:       STRING is "Elate"

   -- Currently handled C/C++ compiler list:
   gcc:                STRING is "gcc"
   gpp:                STRING is "g++"
   lcc_win32:          STRING is "lcc-win32"
   cc:                 STRING is "cc"
   wcl386:             STRING is "wcl386"
   bcc32:              STRING is "bcc32"
   cl:                 STRING is "cl"
   sas_c:              STRING is "sc"
   dice:               STRING is "dice"
   vbcc:               STRING is "vbcc"
   ccc:                STRING is "ccc"
   vpcc:               STRING is "vpcc"
   open_vms_cc:        STRING is "OpenVMS_CC"
   tcc:                STRING is "tcc"

feature {INSTALL,C_MODE}

   system_list: ARRAY[STRING] is
      once
         Result := <<
                     unix_system,
                     windows_system,
                     cygwin_system,
                     beos_system,
                     macintosh_system,
                     amiga_system,
                     dos_system,
                     os2_system,
                     open_vms_system,
                     elate_system
                     >>
      end

   compiler_list: ARRAY[STRING] is
      once
         Result := <<
                     gcc,
                     gpp,
                     lcc_win32,
                     cc,
                     wcl386,
                     bcc32,
                     cl,
                     sas_c,
                     dice,
                     vbcc,
                     ccc,
                     vpcc,
                     open_vms_cc,
		     tcc
                     >>
      end

   c_plus_plus_compiler_list: ARRAY[STRING] is
         -- Compilers (among `compiler_list') which can handle C++
      once
         Result := <<
                     gpp,
                     cl,
                     bcc32,
                     wcl386,
                     vpcc,
                     fz_none -- special no-C++ compiler
                   >>
      end

   set_system_name(name: STRING) is
      require
         system_list.fast_has(name)
      do
         system_name := name
         is_win_like := Void
         is_unix_like := Void
      end

   add_x_suffix(cmd: STRING) is
      local
         suffix: STRING
      do
         suffix := x_suffix
         if not cmd.has_suffix(suffix) then
            cmd.append(suffix)
         end
      end

   make is
      local
         serc: STRING
         paths: FIXED_ARRAY[STRING]
         i: INTEGER
         found, msg: BOOLEAN
      do
         cluster_directory.scan_current_working_directory
         if cluster_directory.last_scan_status then
            current_loadpath_path.copy(cluster_directory.path)
         end

         c_compiler_mode := c_compiler_none

         paths := all_configfile_paths -- sets seconf to the contents of the environment variable
         from
            i := paths.lower
         until
            found or else i > paths.upper or else paths.item(i).is_empty
         loop
            serc := paths.item(i)
            if file_tools.is_readable(serc) then
               seconf := serc
               new_config
               found := True
            end
            i := i + 1
         end

         if not found or else ini_parser.is_invalid then
            if seconf_env /= Void then
               seconf := seconf_env
            else
               seconf := fz_conf_undefined
            end
            if is_install.item then
               set_automatic_system_name
            else
               if seconf_env /= Void then
                  echo.w_put_string(once "The environment variable %"")
                  echo.w_put_string(fz_seconf)
                  echo.w_put_string(once"%" does not contain name of a valid file.%N")
                  msg := True
                  i := 1
               else
                  i := 0
               end
               if i <= paths.upper then
                  echo.w_put_string(once "A valid configuration file was not found in %
                                         %all its default locations:%N")
                  from
                  until
                     i > paths.upper or else paths.item(i).is_empty
                  loop
                     echo.w_put_string(once "  - ")
                     echo.w_put_string(paths.item(i))
                     echo.w_put_character('%N')
                     i := i + 1
                  end
                  msg := True
               end
               if not msg then
                  echo.w_put_string(once "No default configuration file was found.%
                                         % Please set the %"")
                  echo.w_put_string(fz_seconf)
                  echo.w_put_string(once "%" environment variable to a valid %
                                         %SmartEiffel configuration file.%N")
               end
               if not is_install.item then
                  die_with_code(exit_failure_code)
               end
            end
         end

         debug
            io.put_string("seconf=")
            io.put_string(seconf)
            io.put_string(" (seconf_env=")
            if seconf_env = Void then
               io.put_string(once "Void")
            else
               io.put_string(seconf_env)
            end
            io.put_string(")%N")
         end

         echo.put_string(once "Using the configuration file: ")
         echo.put_string(seconf)
         echo.put_new_line
      end

   system_name: STRING

feature {NONE}

   set_automatic_system_name is
         -- Sets a "not very smart" default `system_name' value
      require
         basic_directory.system_notation_detected
      do
         if system_name = Void then
            if basic_directory.system_notation_detected then
               if basic_directory.unix_notation then
                  set_system_name(unix_system)
               elseif basic_directory.cygwin_notation then
                  set_system_name(cygwin_system)
               elseif basic_directory.windows_notation then
                  set_system_name(windows_system)
               elseif basic_directory.macintosh_notation then
                  set_system_name(macintosh_system)
               elseif basic_directory.amiga_notation then
                  set_system_name(amiga_system)
               elseif basic_directory.openvms_notation then
                  set_system_name(open_vms_system)
               end
            end
         end
         io.put_string(once "%NThe type of your operating system was %
                            %automatically  computed. Please verify.%N")
      ensure
         system_name /= Void
      end

   all_configfile_paths_buffer: FIXED_ARRAY[STRING] is
      once
         create Result.with_capacity(4)
      end

feature {INSTALL}

   add_lib_math_do_it_again is
      do
         if beos_system = system_name then
         elseif c_compiler = gcc or else c_compiler = gpp then
            add_external_lib(libm)
         elseif c_compiler = bcc32 then
            -- add_external_lib(libm)
         elseif c_compiler = cl then
         elseif c_compiler = sas_c then
            -- math library is included automatically if
            -- "Math=..." was specified (as it is in
            -- default `sas_c_compiler_options')
         elseif c_compiler = dice then
            add_external_lib(libm)
         elseif c_compiler = vbcc then
            if amiga_system = system_name then
               add_external_lib(once "mieee")
            else
               add_external_lib(libm)
            end
         elseif c_compiler = ccc then
            add_external_lib(libcpml)
         elseif c_compiler = vpcc then
         elseif c_compiler = open_vms_cc then
         elseif c_compiler = tcc then
            add_external_lib(libm)
         elseif c_compiler = cc then
            add_external_lib(libm)
         elseif c_compiler = lcc_win32 then
         elseif c_compiler = wcl386 then
         end
      end

   seconf_env: STRING is
         -- The value of the SmartEiffel environment variable, if defined.
      local
         s: SYSTEM
      once
         Result := s.get_environment_variable(fz_seconf)
      end

   home_env: STRING is
         -- Unix variable: the home directory of the user
      local
         s: SYSTEM
      once
         Result := s.get_environment_variable(once "HOME")
      end

   user_env: STRING is
         -- Unix variable: the name of the user
      local
         s: SYSTEM
      once
         Result := s.get_environment_variable(once "USER")
      end

   userprofile_env: STRING is
         -- This variable is always set on Windows NT, 2000 and XP
      local
         s: SYSTEM
      once
         Result := s.get_environment_variable(once "USERPROFILE")
      end

   all_configfile_paths: FIXED_ARRAY[STRING] is
      local
         i: INTEGER
         s, home: STRING
      do
         seconf := seconf_env
         Result := all_configfile_paths_buffer
         i := Result.lower
         if seconf /= Void then
            if Result.count = 0 then
               Result.add_last(seconf.twin)
            else
               Result.first.copy(seconf)
            end
            i := i + 1
         end

         basic_directory.connect_to_current_working_directory
         basic_directory.set_notation_using(basic_directory.last_entry)
         basic_directory.disconnect

         if basic_directory.system_notation_detected then
            if basic_directory.unix_notation or else basic_directory.cygwin_notation then
               home := home_env
               if home /= Void then
                  if Result.upper >= i then
                     Result.item(i).copy(home)
                     Result.item(i).append(once "/.serc")
                  else
                     create s.copy(home)
                     s.append(once "/.serc")
                     Result.add_last(s)
                  end
                  i := i + 1
               end
               if file_exists(once "/sys/rc") then
                  set_system_name(elate_system)
                  s := once "/lang/eiffel/.serc"
                  if Result.upper >= i then
                     Result.item(i).copy(s)
                  else
                     Result.add_last(s.twin)
                  end
                  i := i + 1
               end
               s := once "/etc/serc"
               if Result.upper >= i then
                  Result.item(i).copy(s)
               else
                  Result.add_last(s.twin)
               end
               i := i + 1
            elseif basic_directory.windows_notation then
               home := userprofile_env
               if home /= Void then
                  if Result.upper >= i then
                     Result.item(i).copy(home)
                     Result.item(i).append(once "\SE.CFG")
                  else
                     create s.copy(home)
                     s.append(once "\SE.CFG")
                     Result.add_last(s)
                  end
                  i := i + 1
               end
               s := once "C:\SE.CFG"
               if Result.upper >= i then
                  Result.item(i).copy(s)
               else
                  Result.add_last(s.twin)
               end
               i := i + 1
            elseif basic_directory.macintosh_notation then
            elseif basic_directory.amiga_notation then
            elseif basic_directory.openvms_notation then
            end
         end

         if sys_directory /= Void then
            basic_directory.compute_subdirectory_with(sys_directory, once "system.se")
            if not basic_directory.last_entry.is_empty then
               if Result.upper >= i then
                  Result.item(i).copy(basic_directory.last_entry)
               else
                  Result.add_last(basic_directory.last_entry.twin)
               end
               i := i + 1
            end
         end

         from
         until
            i > Result.upper
         loop
            Result.item(i).clear
            i := i + 1
         end
      end

feature {NONE}

   verify_system_name is
      local
         i: INTEGER
      do
         i := system_list.index_of(system_name)
         if i > system_list.upper then
            echo.w_put_string(once "Unknown system name in file%N%"")
            echo.w_put_string(tmp_file_read.path)
            echo.w_put_string(once "%".%NCurrently handled system names:%N")
            from
               i := 1
            until
               i > system_list.upper
            loop
               echo.w_put_string(system_list.item(i))
               echo.w_put_character('%N')
               i := i + 1
            end
            die_with_code(exit_failure_code)
         else
            set_system_name(system_list.item(i))
            echo.put_string(once "System is %"")
            echo.put_string(system_name)
            echo.put_string(fz_b0)
         end
      end

feature {INSTALL}

   seconf: STRING
         -- Path to the configuration file. Non Void if the new environment
         -- variable is used; in that case, the informations for accessing
         -- data are retrieved from the `ini_file'.

feature {NONE}

   new_config is
      local
         s: STRING
      do
         parser_buffer.load_file(seconf)
         if parser_buffer.is_ready then
            ini_parser.a_inifile
            if not is_install.item then
               if not ini_parser.section_has(fz_conf_general, fz_conf_bin) then
                  error_handler.append("%"[General] bin%" key is missing.")
                  error_handler.print_as_error
               else
                  bin_directory := ini_parser.section_item(fz_conf_general, fz_conf_bin)
                  environment_variable_substitution(Void, bin_directory)
               end
               if not ini_parser.section_has(fz_conf_general, fz_conf_sys) then
                  error_handler.append("%"[General] sys%" key is missing.")
                  error_handler.print_as_error
               else
                  sys_directory := ini_parser.section_item(fz_conf_general, fz_conf_sys)
                  environment_variable_substitution(Void, sys_directory)
               end
               if not ini_parser.section_has(fz_conf_general, fz_conf_short) then
                  error_handler.append("%"[General] short%" key is missing.")
                  error_handler.print_as_error
               else
                  short_directory := ini_parser.section_item(fz_conf_general, fz_conf_short)
                  environment_variable_substitution(Void, short_directory)
               end
               if not ini_parser.section_has(fz_conf_general, fz_conf_os) then
                  error_handler.append("%"[General] os%" key is missing.")
                  error_handler.print_as_error
               else
                  s := ini_parser.section_item(fz_conf_general, fz_conf_os)
                  if not system_list.has(s) then
                     error_handler.append(once "Unknown os %"")
                     error_handler.append(s)
                     error_handler.append(once "%S: config file corrupted!")
                     error_handler.print_as_fatal_error
                  end
                  s := system_list.item(system_list.index_of(s))
                  set_system_name(s)
               end
               if nb_errors /= 0 then
                  error_handler.append("The configuration file seems invalid. %
                                       %Correct the above errors first.")
                  error_handler.print_as_fatal_error
               end
               verify_system_name
            end
         end
         include_config_loadpaths
      end

feature {SYSTEM_TOOLS_VISITOR}

   include_config_loadpaths is
      local
         i: ITERATOR[STRING]
      do
         i := ini_parser.section_key_iterator(fz_conf_loadpath)
         if i /= Void then
            from
            until
               i.is_off
            loop
               add_config_loadpath_file(ini_parser.section_item(fz_conf_loadpath, i.item))
               i.next
            end
         end
      end

feature {NONE}

   sys_directory: STRING
         -- The SmartEiffel/sys directory computed with the value of
         -- the environment variable `SmartEiffel'.
         -- For example, under UNIX: "/usr/lib/SmartEiffel/sys/"

   bin_directory: STRING
         -- For example, under UNIX: "/usr/lib/SmartEiffel/bin/"

   short_directory: STRING
         -- For example, under UNIX: "/usr/lib/SmartEiffel/short/"

   install is
      do
      end

feature {COMPILE,INSTALL}

   set_sys_directory(sysdir: STRING) is
      do
         sys_directory := sysdir
      end

   set_bin_directory(bindir: STRING) is
      do
         bin_directory := bindir
      end

   set_short_directory(shortdir: STRING) is
      do
         short_directory := shortdir
      end

   command_path_in(command, command_name: STRING) is
         -- Append in `command' the correct path for `command_name'.
      do
         if system_name = open_vms_system then
            command.append(once "mcr ")
         end
         command.append(bin_directory)
         command.append(command_name)
         command.append(x_suffix)
      end

   remove_other_extra_files(name: STRING) is
         -- Remove some other extra file which may be created while
         -- compiling `name' root class in split mode.
      local
         n: STRING
      do
         if c_compiler = lcc_win32 or else c_compiler = sas_c then
            n := name + lnk_suffix
            echo.file_removing(n)
         end
      end

feature {COMPILE}

   remove_make_script_and_other_extra_files is
         -- Remove the *.make file script and some other extra files.
      local
         name: STRING
      do
         name := new_make_script
         name.remove_suffix(make_suffix)
         remove_other_extra_files(name)
      end

   cygnus_bug(make_file: TEXT_FILE_READ; make_script_name: STRING) is
         -- Because of a bug in cygnus on windows 95/NT.
      local
         time_out: INTEGER
      do
         make_file.connect_to(make_script_name)
         from
            time_out := 2000
         until
            time_out = 0 or else make_file.is_connected
         loop
            make_file.connect_to(make_script_name)
            time_out := time_out - 1
         end
      end

feature {COMPILE,CLEAN}

   new_make_script: STRING is
         -- Compute the corresponding make file script name and remove
         -- the old existing one if any.
      do
         Result := path_h
         Result.remove_last(2)
         Result.append(make_suffix)
         echo.file_removing(Result)
      end

feature {SHORT_PRINT}

   format_directory(format: STRING): STRING is
      require
         format /= Void
      do
         !!Result.make(short_directory.count)
         Result.copy(short_directory)
         subdirectory(Result,format)
      end

feature

   is_c_plus_plus_file_path(path: STRING): BOOLEAN is
         -- True when there `path' has one of the following
         -- suffix: ".cpp", ".cc", or ".C".
      do
         if path.has_suffix(c_plus_plus_suffix) then
            Result := true
         elseif path.has_suffix(once ".cc") then
            Result := true
         elseif path.has_suffix(once ".C") then
            Result := true
         end
      end

feature {CLUSTER,JVM,ACE}

   file_path(parent_path, file_name: STRING) is
         -- Use the `system_name' knowledge to call feature `compute_file_path_with'
         -- of BASIC_DIRECTORY. The `parent_path' is modified accordingly.
      do
         set_basic_directory_notation
         basic_directory.compute_file_path_with(parent_path,file_name)
         parent_path.copy(basic_directory.last_entry)
      end

feature

   make_suffix: STRING is
      -- Suffix for make file produced by `compile_to_c'.
      once
         if dos_system = system_name then
            Result := once ".BAT"
         elseif windows_system = system_name then
            Result := once ".bat"
         elseif open_vms_system = system_name then
            Result := once ".com"
         elseif os2_system = system_name then
            Result := once ".CMD"
         elseif elate_system = system_name then
            Result := once ".scf"
         else
            Result := once ".make"
         end
      end

   x_suffix: STRING is
         -- Executable files suffix.
      once
         if dos_system = system_name then
            Result := exe_suffix
            Result.to_upper
         elseif open_vms_system = system_name then
            Result := exe_suffix
            Result.to_upper
         elseif os2_system = system_name then
            Result := exe_suffix
         elseif windows_system = system_name then
            Result := exe_suffix
         elseif cygwin_system = system_name then
            Result := exe_suffix
         elseif elate_system = system_name then
            Result := once ".00"
         else
            create Result.make(4)
         end
      ensure
         Result /= Void
      end

   object_suffix: STRING is
         -- Of object File produced by the C Compiler.
      once
         if c_compiler = gcc or else c_compiler = gpp then
            Result := o_suffix
         elseif c_compiler = lcc_win32 then
            Result := obj_suffix
         elseif c_compiler = cc then
            Result := o_suffix
         elseif c_compiler = wcl386 then
            Result := obj_suffix
         elseif c_compiler = bcc32 then
            Result := obj_suffix
         elseif c_compiler = cl then
            Result := obj_suffix
         elseif c_compiler = sas_c then
            Result := o_suffix
         elseif c_compiler = dice then
            Result := o_suffix
         elseif c_compiler = vbcc then
            Result := o_suffix
         elseif c_compiler = ccc then
            Result := o_suffix
         elseif c_compiler = vpcc then
            Result := o_suffix
         elseif c_compiler = open_vms_cc then
            Result := obj_suffix
            Result.to_upper
         elseif c_compiler = tcc then
            Result := o_suffix
         end
      end

   symb_suffix: STRING is
      -- Suffix for the symbols file produced by `compile_to_c'.
      once
         if dos_system = system_name then
            Result := once ".SYM"
         elseif windows_system = system_name then
            Result := once ".sym"
         elseif open_vms_system = system_name then
            Result := once ".sym"
         elseif os2_system = system_name then
            Result := once ".SYM"
         elseif elate_system = system_name then
            Result := once ".sym"
         else
            Result := once ".sym"
         end
      end

feature {NATIVE_SMART_EIFFEL}

   add_lib_math is
      once
	 add_lib_math_do_it_again
      end

feature {COMPILE,COMPILE_TO_C}

   extra_arg(arg: STRING; argi: INTEGER; next_arg: STRING): INTEGER is
      require
         arg /= Void
         argi >= 1
      do
         check
            c_compiler /= Void
         end
         if arg.item(1) /= '-' then
            if arg.has_suffix(object_suffix) then
               append_token(external_object_files,arg)
               Result := argi + 1
            elseif arg.has_suffix(c_suffix) then
               append_token(external_c_files,arg)
               Result := argi + 1
            elseif is_c_plus_plus_file_path(arg) then
               append_token(external_c_plus_plus_files,arg)
               Result := argi + 1
            elseif arg.has_suffix(once ".a") then
               add_external_lib(arg)
               Result := argi + 1
            elseif arg.has_suffix(once ".lib") then
               add_external_lib(arg)
               Result := argi + 1
            elseif arg.has_suffix(once ".res") then
               -- For lcc-win32 resource files:
               add_external_lib(arg)
               Result := argi + 1
            elseif ace.root_class_name = Void then
               ace.set_root_class_name_using(arg)
               Result := argi + 1
               if next_arg /= Void then
                  if next_arg.item(1) /= '-' then
                     if next_arg.has_suffix(object_suffix) then
                     elseif next_arg.has_suffix(c_suffix) then
                     elseif is_c_plus_plus_file_path(next_arg) then
                     else
                        ace.set_root_procedure_name(next_arg)
                        Result := argi + 2
                     end
                  end
               end
            else
               append_token(c_compiler_options,arg)
               Result := argi + 1
            end
         elseif arg.has_prefix(once "-l") then
            append_if_not_already(external_lib, arg)
            Result := argi + 1
         elseif arg.has_prefix(l_flag) then
            if not (l_flag).is_equal(arg) then
	       add_external_lib_path(arg)
               Result := argi + 1
	    elseif next_arg /= Void then
	       add_external_lib_path(next_arg)
	       Result := argi + 2
            end
         elseif (once "-subsystem").is_equal(arg) then
            append_token(c_linker_options,arg)
            if next_arg /= Void then
               append_token(c_linker_options,next_arg)
               Result := argi + 2
            else
               Result := argi + 1
            end
         elseif (once "-include").is_equal(arg) then
            if next_arg /= Void then
               append_token(c_compiler_options,arg)
               append_token(c_compiler_options,next_arg)
               Result := argi + 2
            else
               Result := argi + 1
            end
         else
            append_token(c_compiler_options,arg)
            Result := argi + 1
         end
      ensure
         Result > old argi
      end

feature {INSTALL}

   set_install_compiler(comptype, comppath, linkpath: STRING) is
      require
         compiler_list.has(comptype)
      local
         i: INTEGER
      do
         seconf := Void
         i := compiler_list.index_of(comptype)
         c_compiler := compiler_list.item(i)
         if comppath = Void then
            c_compiler_path := c_compiler
         else
            c_compiler_path := comppath
         end
         if linkpath = Void then
            c_linker_path := c_compiler
         else
            c_linker_path := linkpath
         end
         c_compiler_mode := c_compiler_cc
      end

   environment_variable_substitution(path, line: STRING) is
         -- If any, substitute some environment variable by it's value.
         -- The only one accepted notation is :
         --                                        ${...}
      local
         i, state, mem1, mem2: INTEGER
         c: CHARACTER
         value, variable: STRING
      do
         from
            i := 1
         until
            i > line.count
         loop
            c := line.item(i)
            inspect
               state
            when 0 then -- Initial state.
               if c = '$' then
                  state := 1
                  mem1 := i
               end
            when 1 then -- "$" read.
               if c = '{' then
                  state := 2
                  create variable.make(8) --*** memory leak
               else
                  state := 0
               end
            when 2 then -- "${" read.
               if c = '}' then
                  state := 3
                  mem2 := i
               else
                  variable.extend(c)
               end
            else -- First correct variable found.
            end
            i := i + 1
         end
         if state = 3 then
            value := echo.getenv(variable,path) --*** memory leak
            if value /= Void then
               variable.copy(line)
               line.keep_head(mem1 - 1)
               line.append(value)
               variable.remove_first(mem2)
               line.append(variable)
               environment_variable_substitution(path,line)
            end
         end
      end

feature {ACE, COMMAND_LINE_TOOLS}

   bad_use_exit(command: COMMAND_LINE_TOOLS) is
         -- Print the traditional `command_line_help_summary' as well as some extra
         -- information to find more help.
      require
         command /= Void
      local
         command_name: STRING
      do
         echo.w_put_string("Bad use of command `")
         command_name := command.command_name
         echo.w_put_string(command_name)
         echo.w_put_string("'.%N")
         echo.w_put_string(command.command_line_help_summary)
         tmp_path.copy(sys_directory)
         parent_directory(tmp_path)
         subdirectory(tmp_path,"man")
         tmp_path.append(command_name)
         tmp_path.append(".txt")
         echo.w_put_string(
            "If SmartEiffel is correctly installed, you should find%N%
            %more information in file: %"")
         echo.w_put_string(tmp_path)
         echo.w_put_string(
            "%".%NYou can also have a look at http://SmartEiffel.loria.fr%N")
         die_with_code(exit_failure_code)
      end

   set_c_compiler(cc_arg: STRING) is
         -- If `cc_arg' is not Void, this `cc_arg' is used as the C compiler.
         -- Otherwise, when `cc_arg' is Void, do nothing (the C compiler will
         -- be set later).
      local
         i: INTEGER;
      do
         if cc_arg /= Void then
            if c_compiler_mode = c_compiler_cmode then
               error_handler.append("You must choose either -cc or -c_mode, but %
                                    %you cannot use them both.")
               error_handler.print_as_fatal_error
            elseif c_compiler_mode = c_compiler_cc then
               echo.w_put_string(once "-cc specified more than once; last is used.%N")
            end

            i := compiler_list.index_of(cc_arg)
            if i > compiler_list.upper then
               echo.w_put_string(once "compile_to_c: %"")
               echo.w_put_string(cc_arg)
               echo.w_put_string(
               once "%": unknown C compiler name after -cc flag or in the ACE file.%N")
               show_compiler_list_then_exit(compiler_list)
            end
            c_compiler := compiler_list.item(i)

            c_compiler_path := compiler_path_of(c_compiler)
            c_linker_path := linker_path_of(c_compiler)

            -- Try to also set the C++ compiler:
            i := c_plus_plus_compiler_list.index_of(cc_arg)
            if i <= c_plus_plus_compiler_list.upper then
               cpp_compiler := c_plus_plus_compiler_list.item(i)
               cpp_compiler_path := compiler_path_of(cpp_compiler)
               cpp_linker_path := linker_path_of(cpp_compiler)
            end

            c_compiler_mode := c_compiler_cc
         else
            -- Do nothing: the compiler will be selected later.
            check
               c_compiler_mode = c_compiler_none
            end
         end
      ensure
         c_compiler_mode = c_compiler_cc implies compiler_list.fast_has(c_compiler)
      end

feature {NONE}

   add_libraries_from_compiler_options is
         -- Extract additionnal libs from c_compiler_options
      local
         i, j: INTEGER; lib_name: STRING;
      do
         if c_compiler = lcc_win32 or else c_compiler = cl
               or else c_compiler = bcc32 then
            -- detect ".lib"
            from
               i := c_compiler_options.substring_index(once ".lib", 1)
            until
               i = 0
            loop
               if (i + 4 > c_compiler_options.count)
                     or else c_compiler_options.item(i + 4).is_separator then
                  from
                     j := i
                  until
                     j = 1 or else c_compiler_options.item(j-1).is_separator
                  loop
                     j := j - 1
                  end
                  lib_name := c_compiler_options.twin
                  lib_name.shrink(j, i + 3)
                  add_external_lib(lib_name)
                  c_compiler_options.remove_between(j, i + 3)
                  i := j
               else
                  i := i + 4
               end
               i := c_compiler_options.substring_index(once ".lib", i)
            end
         else
            -- detect "-l"
            from
               i := c_compiler_options.substring_index(once "-l", 1)
            until
               i = 0
            loop
               if (i = 1) or else
                  c_compiler_options.item(i - 1).is_separator then
                  from
                     j := i
                  until
                     j = c_compiler_options.count or else
                     c_compiler_options.item(j + 1).is_separator
                  loop
                     j := j + 1
                  end
                  lib_name := c_compiler_options.twin
                  lib_name.shrink(i, j)
                  add_external_lib(lib_name)
                  c_compiler_options.remove_between(i, j)
               else
                  i := i + 2
               end
               i := c_compiler_options.substring_index(once ".lib", i)
            end
         end
      end

feature {ACE, COMPILE_TO_C, STRING_COMMAND_LINE}

   set_no_strip is
      do
         no_strip := true
      end

feature {ACE,C_PRETTY_PRINTER,INSTALL}

   c_compiler_options: STRING is ""
         -- C compiler options including extra include path,
         -- optimization flags, etc.

   c_linker_options: STRING is ""
         -- Those options are only to be passed to the linker.

feature {C_PRETTY_PRINTER}

   put_c_main_function_type(out_c: TEXT_FILE_WRITE) is
      do
         if open_vms_system = system_name then
            out_c.put_string(fz_void)
         else
            out_c.put_string(fz_int)
         end
      end

   put_c_main_function_exit(out_c: TEXT_FILE_WRITE) is
      do
         out_c.put_string(once "}%Nexit(0);%N")
         if open_vms_system = system_name then
            out_c.put_string(once "return;}%N")
         else
            out_c.put_string(once "return 0;}%N")
         end
      end

   sys_runtime(name: STRING; suffix: CHARACTER) is
         -- Prepare `tmp_file_read' to access the corresponding file of the
         -- SmartEiffel sys/runtime directory. The complete path is
         -- always available in `tmp_path' to the caller in order to emit an
         -- error message when the corresponding file is not found. (This
         -- routine does not emit errors message itself just because this
         -- may be normal. See also `mandatory_sys_runtime'.)
      require
         name /= Void
         suffix = 'c' or suffix = 'h'
      do
         sys_runtime_(name,suffix)
         echo.tfr_connect(tmp_file_read,tmp_path)
      end

   mandatory_sys_runtime(name: STRING; suffix: CHARACTER) is
         -- Same as `sys_runtime', but emit an error message when the
         -- corresponding file does not exists.
      do
         sys_runtime_(name,suffix)
         echo.tfr_connect_or_exit(tmp_file_read,tmp_path)
      ensure
         tmp_file_read.is_connected
      end

   path_h: STRING is
         -- Create a new STRING which is the name of the main *.h file.
      do
         Result := ace.root_class_name.twin
         Result.to_lower
         if dos_system = system_name then
            from
            until
               Result.count <= 4
            loop
               Result.remove_last(1)
            end
         end
         Result.append(h_suffix)
      end

   strip_executable: STRING is
      local
         executable_name: STRING
      do
         if not no_strip then
            executable_name := ace.executable_name
            if unix_system = system_name then
	       Result := once "...This is a local once buffer..."
	       Result.copy(once "strip ")
               if executable_name = Void then
                  Result.append(once "a.out")
               else
                  Result.append(executable_name)
               end
            elseif os2_system = system_name then
	       Result := once "...This is a local once buffer..."
	       Result.copy(once "emxbind -qs ")
               if executable_name = Void then
                  Result.append(once "a.exe")
               else
                  Result.append(executable_name)
               end
            end
         end
      end

   add_c_plus_plus_file(f: STRING) is
      require
         is_c_plus_plus_file_path(f)
      do
         append_token(external_c_plus_plus_files,f)
      end

   is_linking_mandatory: BOOLEAN is
         -- Is it mandatory to link again this executable even when
         -- nothing has changed in the generated C code ?
      do
         Result := not external_object_files.is_empty
         if not Result then
            Result := not external_c_files.is_empty
         end
         if not Result then
            Result := not external_c_plus_plus_files.is_empty
         end
      end

   add_lib_basic_vision is
      once
         if system_name = unix_system then
            add_external_lib_path("/usr/X11R6/lib")
            add_external_lib_path("/usr/X/lib")
            add_external_lib("X11")
	 elseif system_name = windows_system then
	    if c_compiler = bcc32 then
	       add_external_lib("import32.lib")
	    end
            add_external_lib("user32.lib")
            add_external_lib("gdi32.lib")
            add_external_lib("wsock32.lib")
            add_external_lib("winmm.lib")
	 elseif system_name = cygwin_system and then (c_compiler = gcc or else c_compiler = gpp) then
	    add_external_lib_path("/usr/w32api")
	    add_external_lib("user32")
	    add_external_lib("gdi32")
	    add_external_lib("wsock32")
	    add_external_lib("winmm")
         end
      end

feature {SMART_EIFFEL}

   add_lib_scoop is
      once
         add_external_lib(once "pthread")
      end

feature {C_PRETTY_PRINTER,INSTALL}

   split_mode_c_compiler_command(c_file_name: STRING): STRING is
         -- Where c_file_name is the name of one slice.
      do
	 Result := once "...This is a local once buffer..."
         Result.clear
         check_c_plus_plus
         if c_compiler = gcc or else c_compiler = gpp then
            Result.append(c_compiler_path)
            append_token(Result,c_compiler_options)
            append_token(Result,external_header_path)
            append_token(Result,c_flag)
	    append_token(Result,once "-ansi -x c")
            append_token(Result,c_file_name)
         elseif c_compiler = lcc_win32 then
            Result.append(c_compiler_path)
            append_token(Result,c_compiler_options)
            append_token(Result,external_header_path)
            append_token(Result,c_file_name)
         elseif c_compiler = cc then
            Result.append(c_compiler_path)
            append_token(Result,c_compiler_options)
            append_token(Result,external_header_path)
            append_token(Result,c_flag)
            append_token(Result,c_file_name)
         elseif c_compiler = wcl386 then
            Result.append(c_compiler_path)
            append_token(Result,c_compiler_options)
            append_token(Result,external_header_path)
            append_token(Result,once "/c")
            append_token(Result,c_file_name)
         elseif c_compiler = bcc32 then
            Result.append(c_compiler_path)
            append_token(Result,c_compiler_options)
            append_token(Result,external_header_path)
            append_token(Result,c_flag)
            append_token(Result,c_file_name)
         elseif c_compiler = cl then
            Result.append(c_compiler_path)
            append_token(Result,c_compiler_options)
            append_token(Result,external_header_path)
            append_token(Result,c_flag)
            append_token(Result,c_file_name)
         elseif c_compiler = sas_c then
            Result.append(c_compiler_path)
            append_token(Result,sas_c_compiler_options(true))
            append_token(Result,c_compiler_options)
            append_token(Result,external_header_path)
            append_token(Result,c_file_name)
         elseif c_compiler = dice then
            Result.append(c_compiler_path)
            append_token(Result,c_compiler_options)
            append_token(Result,external_header_path)
            append_token(Result,c_flag)
            append_token(Result,c_file_name)
         elseif c_compiler = vbcc then
            Result.append(c_compiler_path)
            append_token(Result,c_compiler_options)
            append_token(Result,external_header_path)
            append_token(Result,c_flag)
            append_token(Result,c_file_name)
         elseif c_compiler = ccc then
            Result.append(c_compiler_path)
            append_token(Result,c_compiler_options)
            append_token(Result,external_header_path)
            append_token(Result,c_flag)
            append_token(Result,c_file_name)
         elseif c_compiler = vpcc then
            Result.append(c_compiler_path)
            append_token(Result,c_compiler_options)
            append_token(Result,external_header_path)
            append_token(Result,c_flag)
            append_token(Result,c_file_name)
         elseif c_compiler = open_vms_cc then
            -- BdB: external_header_path to be added here somehow
            Result.append(once "cc/warning=disable=(embedcomment,longextern) ")
            Result.append(c_file_name)
            Result.append(c_compiler_path)
            Result.remove_last(2)
         elseif c_compiler = tcc then
            Result.append(c_compiler_path)
            append_token(Result,c_compiler_options)
            append_token(Result,external_header_path)
            append_token(Result,c_flag)
	    append_token(Result,o_flag)
	    append_token(Result,c_file_name)
	    Result.remove_last(2) -- *** BAD STYLE
	    Result.append(object_suffix)
            append_token(Result,c_file_name)
         end
      end

   split_mode_linker_command(c_name: STRING; max: INTEGER): STRING is
         -- Where `c_name' is only the prefix name (i.e. "compile_to_c").
      local
         script, lst: TEXT_FILE_WRITE; i: INTEGER; name: STRING
      do
	 Result := once "...This is a local once buffer..."
         Result.clear
         check_c_plus_plus
         if c_compiler = gcc or else c_compiler = gpp then
            Result.append(c_linker_path)
            append_token(Result,c_linker_options)
            add_executable_name(Result)
            add_objects(Result,c_name,max)
	    if not external_c_files.is_empty then
	       append_token(Result,once "-x c")
	       append_token(Result,external_c_files)
	    end
	    if not external_c_plus_plus_files.is_empty then
	       append_token(Result,once "-x 'c++'")
	       append_token(Result,external_c_plus_plus_files)
	    end
            append_token(Result, once "-x none")
            append_token(Result,external_object_files)
            append_token(Result,external_lib)
            append_token(Result,external_header_path)
            append_token(Result,external_lib_path)
         elseif c_compiler = lcc_win32 then
            external_c_files_for_lcc_win32(Result)
           Result.append(c_linker_path)
            if not no_strip then
               append_token(Result,s_flag)
            end
            append_token(Result,c_linker_options)
            add_executable_name(Result)
            if max < 4 then
               -- Object files are passed in the command line:
               add_objects(Result,c_name,max)
            else
               -- Object files are listed in a *.lnk file:
               name := c_name
               name.append(lnk_suffix)
               append_token(Result, "@" + name)
               create lst.make
               echo.tfw_connect(lst,name)
               from
                  name.remove_last(4)
                  i := 1
               until
                  i > max
               loop
                  lst.put_string(name)
                  lst.put_integer(i)
                  lst.put_string(obj_suffix)
                  lst.put_new_line
                  i := i + 1
               end
               lst.disconnect
            end
            append_token(Result,external_object_files)
            append_token(Result,external_lib)
         elseif c_compiler = cc then
            Result.append(c_linker_path)
            append_token(Result,external_header_path)
            append_token(Result,c_linker_options)
            append_token(Result,external_lib_path)
            add_executable_name(Result)
            add_objects(Result,c_name,max)
            append_token(Result,external_c_files)
            append_token(Result,external_c_plus_plus_files)
            append_token(Result,external_object_files)
            append_token(Result,external_lib)
         elseif c_compiler = wcl386 then
            Result.append(c_linker_path)
            append_token(Result,external_header_path)
            append_token(Result,c_linker_options)
            append_token(Result,external_lib_path)
            add_executable_name(Result)
            add_objects(Result,c_name,max)
            append_token(Result,external_c_files)
            append_token(Result,external_c_plus_plus_files)
            append_token(Result,external_object_files)
            append_token(Result,external_lib)
         elseif c_compiler = bcc32 then
            Result.append(c_linker_path)
            append_token(Result,external_header_path)
            append_token(Result,c_linker_options)
            append_token(Result,external_lib_path)
            add_executable_name(Result)
            add_objects(Result,c_name,max)
            append_token(Result,external_c_files)
            append_token(Result,external_c_plus_plus_files)
            append_token(Result,external_object_files)
            append_token(Result,external_lib)
            add_lib_math
         elseif c_compiler = cl then
            Result.append(c_linker_path)
            append_token(Result,external_header_path)
            add_executable_name(Result)
            add_objects(Result,c_name,max)
            append_token(Result,external_c_files)
            append_token(Result,external_c_plus_plus_files)
            append_token(Result,external_object_files)
            append_token(Result,once " /link")
            append_token(Result,c_linker_options)
            append_token(Result,external_lib_path)
            append_token(Result,external_lib)
            add_lib_math
         elseif c_compiler = sas_c then
            Result.append(c_linker_path)
            --*** CAD: ?? append_token(Result,sas_c_compiler_options(true))
            --*** CAD: ?? append_token(Result,c_compiler_options)
            append_token(Result,external_header_path)
            append_token(Result,c_linker_options)
            append_token(Result,c_name)
            Result.append(once "#1#2#3#4#5#6#7#8#9#?.o")
            append_token(Result,external_c_files)
            append_token(Result,external_c_plus_plus_files)
            append_token(Result,external_object_files)
            append_token(Result,external_lib)
            add_executable_name(Result)
            if not no_strip then
               Result.append(once " StripDebug")
            end
         elseif c_compiler = dice then
            Result.append(c_linker_path)
            append_token(Result,external_header_path)
            append_token(Result,c_linker_options)
            append_token(Result,external_lib_path)
            add_executable_name(Result)
            add_objects(Result,c_name,max)
            append_token(Result,external_c_files)
            append_token(Result,external_c_plus_plus_files)
            append_token(Result,external_object_files)
            append_token(Result,external_lib)
            if no_strip then
               -- no typo; "-s" means "include symbol table",
               -- not "strip debug information"
               append_token(Result,once "-s -d1")
            end
            add_lib_math
         elseif c_compiler = vbcc then
            Result.append(c_linker_path)
            append_token(Result,external_header_path)
            append_token(Result,c_linker_options)
            append_token(Result,external_lib_path)
            add_executable_name(Result)
            add_lib_math
            add_objects(Result,c_name,max)
            append_token(Result,external_c_files)
            append_token(Result,external_c_plus_plus_files)
            append_token(Result,external_object_files)
            append_token(Result,external_lib)
         elseif c_compiler = ccc then
            Result.append(c_linker_path)
            append_token(Result,external_header_path)
            append_token(Result,c_linker_options)
            append_token(Result,external_lib_path)
            add_executable_name(Result)
            add_objects(Result,c_name,max)
            append_token(Result,external_c_files)
            append_token(Result,external_c_plus_plus_files)
            append_token(Result,external_object_files)
            append_token(Result,external_lib)
         elseif c_compiler = vpcc then
            Result.append(c_linker_path)
            append_token(Result,external_header_path)
            append_token(Result,c_linker_options)
            append_token(Result,external_lib_path)
            add_executable_name(Result)
            add_objects(Result,c_name,max)
            append_token(Result,external_c_files)
            append_token(Result,external_c_plus_plus_files)
            append_token(Result,external_object_files)
            append_token(Result,external_lib)
         elseif c_compiler = open_vms_cc then
            -- *** CAD: DON'T UNDERSTAND!! SHOULD USE c_linker_path
            create script.make
            echo.tfw_connect(script,once "linkit.com")
            script.put_string(once "$ link/exe=")
            Result.clear
            add_executable_name(Result)
            script.put_string(Result)
            script.put_character(' ')
            from
               i := 1
            until
               i >= max
            loop
               script.put_string(c_name)
               script.put_integer(i)
               script.put_string(once ",-%N")
               i := i + 1
            end
            script.put_string(c_name)
            script.put_integer(i)
            script.put_character('%N')
            script.disconnect
            Result.clear
            Result.append(once "@linkit.com%Ndelete linkit.com;")
         elseif c_compiler = tcc then
            Result.append(c_linker_path)
            append_token(Result,external_header_path)
            append_token(Result,c_linker_options)
            append_token(Result,external_lib_path)
            add_executable_name(Result)
            append_token(Result,external_lib)
            add_objects(Result,c_name,max)
            append_token(Result,external_c_files)
            append_token(Result,external_object_files)
         end
      end

   no_split_mode_command(c_file_name: STRING): STRING is
      require
         c_file_name.has_suffix(once ".c")
      do
	 Result := "...This is a local once buffer..."
         Result.clear
         check_c_plus_plus
         if c_compiler = gcc or else c_compiler = gpp then
            Result.append(c_compiler_path)
            append_token(Result,c_compiler_options)
            add_executable_name(Result)
            append_token(Result,once "-x c")
	    append_token(Result,c_file_name)
	    append_token(Result,external_c_files)
	    if not external_c_plus_plus_files.is_empty then
	       append_token(Result,once "-x 'c++'")
	       append_token(Result,external_c_plus_plus_files)
	    end
            append_token(Result, once "-x none")
            append_token(Result,external_object_files)
            append_token(Result,external_lib)
            append_token(Result,external_header_path)
            append_token(Result,external_lib_path)
         elseif c_compiler = lcc_win32 then
            Result.append(c_compiler_path)
            append_token(Result,c_compiler_options)
            append_token(Result,external_header_path)
            append_token(Result,c_file_name)
            Result.extend('%N')
            external_c_files_for_lcc_win32(Result)
            Result.append(lcclnk)
            if not no_strip then
               append_token(Result,s_flag)
            end
            add_executable_name(Result)
            c_file_name.remove_suffix(c_suffix)
            c_file_name.append(object_suffix)
            append_token(Result,c_file_name)
            append_token(Result,external_object_files)
            append_token(Result,external_lib)
         elseif c_compiler = cc then
            Result.append(c_compiler_path)
            append_token(Result,c_compiler_options)
            append_token(Result,external_header_path)
            append_token(Result,external_lib_path)
            add_executable_name(Result)
            append_token(Result,c_file_name)
            append_token(Result,external_c_files)
            append_token(Result,external_c_plus_plus_files)
            append_token(Result,external_object_files)
            append_token(Result,external_lib)
         elseif c_compiler = wcl386 then
            Result.append(c_compiler_path)
            append_token(Result,c_compiler_options)
            append_token(Result,external_header_path)
            append_token(Result,external_lib_path)
            add_executable_name(Result)
            append_token(Result,c_file_name)
            append_token(Result,external_c_files)
            append_token(Result,external_c_plus_plus_files)
            append_token(Result,external_object_files)
            append_token(Result,external_lib)
         elseif c_compiler = bcc32 then
            Result.append(c_compiler_path)
            append_token(Result,c_compiler_options)
            append_token(Result,external_header_path)
            append_token(Result,external_lib_path)
            add_executable_name(Result)
            append_token(Result,c_file_name)
            append_token(Result,external_c_files)
            append_token(Result,external_c_plus_plus_files)
            append_token(Result,external_object_files)
            append_token(Result,external_lib)
            add_lib_math
         elseif c_compiler = cl then
            Result.append(c_compiler_path)
            append_token(Result,c_compiler_options)
            append_token(Result,external_header_path)
            add_executable_name(Result)
            append_token(Result,c_file_name)
            append_token(Result,external_c_files)
            append_token(Result,external_c_plus_plus_files)
            append_token(Result,external_object_files)
            append_token(Result,once " /link")
            append_token(Result,external_lib_path)
            append_token(Result,external_lib)
            add_lib_math
         elseif c_compiler = sas_c then
            Result.append(c_compiler_path)
            append_token(Result,sas_c_compiler_options(false))
            append_token(Result,c_compiler_options)
            append_token(Result,external_header_path)
            append_token(Result,external_lib_path)
            append_token(Result,c_file_name)
            append_token(Result,external_c_files)
            append_token(Result,external_c_plus_plus_files)
            append_token(Result,external_object_files)
            append_token(Result,external_lib)
            add_lib_math
            add_executable_name(Result)
         elseif c_compiler = dice then
            Result.append(c_compiler_path)
            append_token(Result,c_compiler_options)
            append_token(Result,external_header_path)
            append_token(Result,external_lib_path)
            add_executable_name(Result)
            append_token(Result,c_file_name)
            append_token(Result,external_c_files)
            append_token(Result,external_c_plus_plus_files)
            append_token(Result,external_object_files)
            append_token(Result,external_lib)
            add_lib_math
            if no_strip then
               append_token(Result,once "-s")
            end
         elseif c_compiler = vbcc then
            Result.append(c_compiler_path)
            append_token(Result,c_compiler_options)
            append_token(Result,external_header_path)
            append_token(Result,external_lib_path)
            add_executable_name(Result)
            add_lib_math
            append_token(Result,c_file_name)
            append_token(Result,external_c_files)
            append_token(Result,external_c_plus_plus_files)
            append_token(Result,external_object_files)
            append_token(Result,external_lib)
         elseif c_compiler = ccc then
            Result.append(c_compiler_path)
            append_token(Result,c_compiler_options)
            append_token(Result,external_header_path)
            append_token(Result,external_lib_path)
            add_executable_name(Result)
            append_token(Result,c_file_name)
            append_token(Result,external_c_files)
            append_token(Result,external_c_plus_plus_files)
            append_token(Result,external_object_files)
            append_token(Result,external_lib)
         elseif c_compiler = vpcc then
            Result.append(c_compiler_path)
            append_token(Result,c_compiler_options)
            append_token(Result,external_header_path)
            append_token(Result,external_lib_path)
            add_executable_name(Result)
            append_token(Result,c_file_name)
            append_token(Result,external_c_files)
            append_token(Result,external_c_plus_plus_files)
            append_token(Result,external_object_files)
            append_token(Result,external_lib)
         elseif c_compiler = open_vms_cc then
            Result.append(once "cc/warning=disable=(embedcomment,longextern) ")
            Result.append(c_file_name)
            Result.append(c_compiler_path)
            Result.remove_last(2)
            Result.append(once "%Nlink/exe=")
            add_executable_name(Result)
            Result.extend(' ')
            Result.append(c_file_name)
            Result.remove_last(2)
         elseif c_compiler = tcc then
            Result.append(c_compiler_path)
            append_token(Result,c_compiler_options)
            append_token(Result,external_header_path)
            append_token(Result,external_lib_path)
            add_executable_name(Result)
            append_token(Result,external_lib)
            append_token(Result,c_file_name)
            append_token(Result,external_c_files)
            append_token(Result,external_object_files)
         end
      end

feature {NONE} -- SAS/c support functions:

   Scoptions_exists: BOOLEAN is
         -- Is there a file "SCOPTIONS" in the current directory?
      once
         Result := file_tools.is_readable(once "SCOPTIONS")
      end

   sas_c_compiler_options(split: BOOLEAN): STRING is
         -- C compiler options or "" if no SCOPTIONS exists.
         -- If `split' is True, "Data=Far" is used, otherwise
         -- "Data=Auto".
      do
         if Scoptions_exists then
            Result := once ""
         else
            !!Result.make(0)
            Result.append(once "Math=IEEE Parameters=Both Code=Far")
            -- cause bloat, but avoid linker errors
            if split then
               Result.append(once " Data=Far")
            else
               Result.append(once " Data=Auto")
            end
            Result.append(once " Ignore=93,194,304")
            -- ignore the following warnings:
            --  93: no reference to identifier X
            -- 194: too much local data for NEAR reference,
            --      some changed to FAR (only with Data=Auto)
            -- 304: dead assignment eliminated
            Result.append(once " NoVersion NoIcons")
            -- avoid cluttering the display with messages and
            -- the current directory with icon files
         end
      end

feature {ACE, SYSTEM_TOOLS_VISITOR}

   read_loadpath_files is
         -- For command line mode only (no ACE file used). Read the good
         -- old "loadpath.se" file as well as the "loadpath.<system>" file
         -- to drive class file searching while in plain command line mode.
      require
         ace.file_path = Void
      local
         i: INTEGER
         dummy: BOOLEAN
         buffer: STRING
      do
         buffer := once ""

         -- read the loadpaths, if any, given on the command line
         if extra_loadpath_files /= Void then
            from
               i := extra_loadpath_files.lower
            until
               i > extra_loadpath_files.upper
            loop
               buffer.copy(extra_loadpath_files.item(i))
               environment_variable_substitution(Void,buffer)
               cluster_directory.scan_with(buffer)
               if cluster_directory.last_scan_status then
                  current_loadpath_path.copy(buffer)
                  dummy := loadpath_read(current_loadpath_path, 1, False)
               end
               i := i + 1
            end
         end

         if not loadpath_read(fz_loadpath_se, 1, False) then
            -- the loadpath.se does not exist in the current directory:
            basic_directory.connect_to_current_working_directory
            if basic_directory.is_connected then
               ace.cluster_add_last(basic_directory.last_entry, once "cwd", False)
               basic_directory.disconnect
            end
         end

         -- read the configuration loadpaths
         if config_loadpath_files /= Void then
            from
               i := config_loadpath_files.lower
            until
               i > config_loadpath_files.upper
            loop
               buffer.copy(config_loadpath_files.item(i))
               environment_variable_substitution(Void,buffer)
               cluster_directory.scan_with(buffer)
               if cluster_directory.last_scan_status then
                  current_loadpath_path.copy(buffer)
                  dummy := loadpath_read(current_loadpath_path, 1, True)
               end
               i := i + 1
            end
         end
      end

   system_name_in(msg: STRING) is
         -- Append in `msg' the current `system_name'.
      do
         if system_name /= Void then
            msg.append(once "The selected system name is %"")
            msg.append(system_name)
            msg.append(fz_b0)
         else
            msg.append(once "No information available about the system used %
                       %(check your%NSmartEiffel installation).%N")
         end
      end

   set_external_header_path(a_paths: STRING) is
         -- Set `external_header_path' to `a_paths', but format it according to rules
         -- for current C compiler.
      local
         paths: ARRAY[STRING]; i: INTEGER
      do
         paths := a_paths.split
         from
            i := paths.lower
         until
            i > paths.upper
         loop
            add_external_header_path(paths.item(i))
            i := i + 1
         end
      end

   set_external_lib_path(a_paths: STRING) is
         -- Set `external_lib_path' to `a_paths', but format it according to rules for
         -- current C compiler and linker.
      local
         lib_paths: ARRAY[STRING]; i: INTEGER
      do
         lib_paths := a_paths.split
         from
            i := lib_paths.lower
         until
            i > lib_paths.upper
         loop
            add_external_lib_path(lib_paths.item(i))
            i := i + 1
         end
      end

   set_external_lib(a_libs: STRING) is
         -- Set `external_lib' to `a_libs', but format it according to rules for
         -- current C compiler and linker.
      local
         lib_files: ARRAY[STRING]; i: INTEGER
      do
         lib_files := a_libs.split
         from
            i := lib_files.lower
         until
            i > lib_files.upper
         loop
            add_external_lib(lib_files.item(i))
            i := i + 1
         end
      end

   external_object_files: STRING is ""
         -- External object files.

   external_c_files: STRING is ""
         -- External C files.

   external_c_plus_plus_files: STRING is ""
         -- External C++ files.

   no_strip: BOOLEAN

feature {ECHO}

   parent_directory(some_path: STRING) is
         -- Use the `system_name' knowledge to call feature `compute_parent_directory_of'
         -- of BASIC_DIRECTORY. The `some_path' is modified accordingly.
      require
         some_path.count > 0
      do
         set_basic_directory_notation
         basic_directory.compute_parent_directory_of(some_path)
         some_path.copy(basic_directory.last_entry)
      end

feature {CLUSTER}

   cluster_path(directory_path: STRING) is
         -- Transforms the path to be compatible with the OS.  If the path is
         -- relative, it is made absolute.
         -- On non-unix systems, the unix notation is supported for relative
         -- directories.
         -- `directory_path' contents is changed accordingly.
      require
         directory_path /= Void
      local
         ok: BOOLEAN
      do
         ok := is_directory_resolve(directory_path)
         debug
            io.put_string("resolve_path=")
            io.put_string(resolve_path)
            io.put_new_line
         end
         check ok end
         directory_path.copy(resolve_path)
      end

feature {NONE}

   is_absolute(path: STRING): BOOLEAN is
         -- Always False on non-winlike and non-unixlike systems
      require
         set_likes_called: is_win_like /= Void
      local
         c: CHARACTER; s: STRING
      do
	 if path.is_empty then
	 else
	    s := system_name
	    if is_win_like.item then
	       c := path.first.to_lower
	       if  path.item(2) = ':' and then c >= 'a' and then c <= 'z' then
		  c := path.item(3)
		  Result := c = '\' or else c = '/'
	       else
		  c := path.first
		  Result := c = '\' or else c = '/'
		  if Result then
		     c := path.item(2)
		     Result := c = '\' or else c = '/'
		  end
	       end
	    elseif is_unix_like.item then
	       Result := path.first = '/'
	    end
	 end
      end

   is_relative(path: STRING): BOOLEAN is
         -- Always True on non-winlike and non-unixlike systems
      require
         set_likes_called: is_win_like /= Void
      do
         Result := not is_absolute(path)
      end

   is_win_like: reference BOOLEAN
   is_unix_like: reference BOOLEAN

   set_likes is
         -- Just speed up repeated tests on system by setting `is_win_like'
         -- and `is_unix_like'
      local
         s: STRING
      do
         if is_win_like = Void then
            s := system_name
            is_win_like := (s = windows_system or else s = dos_system or else s = os2_system)
            is_unix_like := (s = unix_system or else s = cygwin_system or else s = elate_system or else s = beos_system)
         end
      end

feature {SYSTEM_TOOLS_VISITOR}

   resolve_path: STRING is
      once
         create Result.make(16)
      end

   current_loadpath_path: STRING is
      once
         create Result.make(16)
      end

   is_directory_resolve(path: STRING): BOOLEAN is
         -- Fills `resolve_path' with the local version of the path.
         -- Returns True if the path is a directory, False otherwise.
      require
         path /= Void
      local
         s, p: STRING; low, up: INTEGER
         ok, again, scanned, err, winlike, uxlike: BOOLEAN
         bd: BASIC_DIRECTORY
      do
         s := system_name
         check
            s /= Void
         end

         set_likes
         winlike := is_win_like.item
         uxlike := is_unix_like.item

         p := once "                                " -- a local buffer

         if current_loadpath_path.count > 0 then
            if not is_relative(path) and then winlike then
               -- On Windoze we want to recognize paths with mixed slashes and
               -- backslashes. We first try replacing '/' by '\', maybe then
               -- we have a valid path...

               -- We use `p' instead of `path', because the next test needs
               -- path not having been tampered with.

               p.copy(path)
               p.replace_all('/', '\')
               resolve_directory.scan(p)
               if resolve_directory.last_scan_status then
                  resolve_path.copy(resolve_directory.path)
                  ok := True
                  Result := True
               end
            end

            if not ok
               and then (path.has('/')
                         or else (winlike
                                  and then path.has('\')))
               and then is_relative(path) then
               -- Simulate subdirectory look-up using '/' on non-unix systems.

               p.copy(path)
               if winlike then
                  -- A special case for Winblows again: mixed '/' and '\'
                  p.replace_all('\', '/')
               end
               from
                  low := 1
                  up := p.index_of('/', low)
                  again := up /= 0
                  if up = 1 then
                     if uxlike then
                        resolve_directory.scan(once "/")
                        if resolve_directory.last_scan_status then
                           low := 2
                           up := p.index_of('/', low)
                        end
                     else
                        error_handler.append(once "On non-unix systems, please either use %
                                                  %relative unix-like directories in loadpath.se, %
                                                  %or the native directory notation.")
                        error_handler.append(once "The path %"")
                        error_handler.append(path)
                        error_handler.append(once "%" is ignored.")
                        error_handler.print_as_warning
                        again := False
                        err := True
                     end
                  else
                     resolve_directory.scan_with(current_loadpath_path)
                     if not resolve_directory.last_scan_status then
                        resolve_directory.scan_current_working_directory
                     end
                  end
               until
                  not again
               loop
                  -- Simulate substring with no string creation
                  resolve_path.copy(p)
                  resolve_path.shrink(low, up - 1)
                  -- Scan the subdirectory
                  if resolve_path.is_empty then
                     -- Doubled slash: ignore
                     scanned := True
                  elseif resolve_path.is_equal(once ".") then
                     -- Current directory
                     scanned := True
                  elseif resolve_path.is_equal(once "..") then
                     -- Parent directory
                     resolve_directory.scan_parent_directory
                     scanned := resolve_directory.last_scan_status
                  elseif not resolve_directory.has(resolve_path) then
                     scanned := False
                     again := False
                     err := True
                     debug
                        io.put_string(resolve_directory.path)
                        io.put_string(" does not have ")
                        io.put_string(resolve_path)
                        io.put_new_line
                     end
                  else
                     -- Subdirectory
                     resolve_directory.scan_subdirectory(resolve_path)
                     scanned := resolve_directory.last_scan_status
                  end
                  if not scanned then
                     again := False
                  else
                     -- And try again
                     low := up + 1
                     if low <= p.count then
                        up := p.index_of('/', low)
                     else
                        up := 0
                     end
                     if up = 0 then
                        -- Special final case: test if it is a directory
                        -- or a normal file
                        if low > p.count then
                           -- it is a directory
                           ok := True
                           Result := True
                        else
                           p.copy(resolve_directory.path)
                           resolve_path.copy(p)
                           resolve_path.shrink(low, path.count)
                           if resolve_directory.has(resolve_path) then
                              resolve_directory.scan_subdirectory(resolve_path)
                              if resolve_directory.last_scan_status then
                                 ok := True
                                 Result := True
                              else
                                 basic_directory.compute_file_path_with(p, resolve_path)
                                 if not basic_directory.last_entry.is_empty and then file_tools.is_readable(basic_directory.last_entry) then
                                    ok := True
                                 else
                                    err := True
                                    debug
                                       io.put_string("unknown file ")
                                       io.put_string(basic_directory.last_entry)
                                       io.put_new_line
                                    end
                                 end
                              end
                           end
                        end
                        again := False
                     end
                  end
               end
               if ok then
                  if Result then
                     resolve_path.copy(resolve_directory.path)
                  else
                     resolve_path.copy(basic_directory.last_entry)
                  end
               end
            end

            if not ok and then not err then
               p.copy(path)
               if p.is_empty then
                  if current_loadpath_path.is_empty then
                     resolve_directory.scan_current_working_directory
                  else
                     resolve_directory.scan(current_loadpath_path)
                  end
               else
                  if winlike then
                     p.replace_all('/', '\')
                  end
                  resolve_directory.scan(p)
               end
               if resolve_directory.last_scan_status then
                  resolve_path.copy(resolve_directory.path)
                  ok := True
                  Result := True
               else
                  resolve_directory.scan_with(current_loadpath_path)
                  if not resolve_directory.last_scan_status then
                     err := True
                     debug
                        io.put_string("cannot connect with ")
                        io.put_string(current_loadpath_path)
                        io.put_new_line
                     end
                  elseif p.is_empty then
                     resolve_path.copy(resolve_directory.path)
                     Result := True
                  else
                     basic_directory.compute_file_path_with(resolve_directory.path, p)
                     if file_tools.is_readable(basic_directory.last_entry) then
                        resolve_path.copy(basic_directory.last_entry)
                     else
                        basic_directory.compute_subdirectory_with(resolve_directory.path, p)
                        p.copy(basic_directory.last_entry)
                        resolve_directory.scan(p)
                        if resolve_directory.last_scan_status then
                           resolve_path.copy(resolve_directory.path)
                           Result := True
                        else
                           err := True
                           debug
                              io.put_string("unknown file or directory ")
                              io.put_string(basic_directory.last_entry)
                              io.put_new_line
                           end
                        end
                     end
                  end
               end
            end
         end

         if err then
            error_handler.append(once "Unknown path: %"")
            error_handler.append(path)
            error_handler.append(once "%" in ")
            error_handler.append(current_loadpath_path)
            error_handler.extend('.')
            error_handler.print_as_warning
            resolve_path.clear
         end

         debug
            io.put_string(  "Resolve: ")
            io.put_string(path)
            io.put_string("%N      in ")
            io.put_string(current_loadpath_path)
            io.put_string("%N      -> ")
            io.put_string(resolve_path)
            io.put_string("%N        (")
            io.put_boolean(Result)
            io.put_string(")%N")
         end
      end

   basic_directory: BASIC_DIRECTORY

   set_basic_directory_notation is
      local
         s: STRING; letter_code: CHARACTER
      once
         s := system_name
         if s = Void then
         elseif s = unix_system then
            letter_code := 'U'
         elseif s = windows_system or else s = dos_system or else s = os2_system then
            letter_code := 'W'
         elseif s = beos_system then
            letter_code := 'U'
         elseif s = macintosh_system then
            letter_code := 'M'
         elseif s = amiga_system then
            letter_code := 'A'
         elseif s = open_vms_system then
            letter_code := 'V'
         elseif s = cygwin_system then
            letter_code := 'C'
         elseif s = elate_system then
            letter_code := 'U'
         else
            check false end
         end
         if s /= Void then
            basic_directory.notation.put(letter_code,1)
         end
      end

   subdirectory(parent_path, entry_name: STRING) is
         -- Use the `system_name' knowledge to call feature `compute_subdirectory_with'
         -- of BASIC_DIRECTORY. The `parent_path' is modified accordingly.
      require
         not parent_path.is_empty
         not entry_name.is_empty
      do
         set_basic_directory_notation
         basic_directory.compute_subdirectory_with(parent_path,entry_name)
         parent_path.copy(basic_directory.last_entry)
      end

   append_token(line, token: STRING) is
      do
         if not token.is_empty then
            if token.first /= ' ' then
               if not line.is_empty then
                  line.extend_unless(' ')
               end
            end
            line.append(token)
         end
      end

   loadpath_read(path: STRING; level: INTEGER; is_config_loadpath: BOOLEAN): BOOLEAN is
         -- Returns `true' if the file was effectively read
      local
         file: TEXT_FILE_READ
         buffer, b: STRING
      do
         buffer := once ""
         debug
            io.put_string("loadpath_read(")
            io.put_string(path)
            io.put_string(", ")
            io.put_integer(level)
            io.put_string(")%N")
         end
         if level > 5 or else ace.cluster_count > 1024 then
            echo.w_put_string(
               "Eiffel source loading path too long or infinite %
               %loadpath.se includes.%N")
            create buffer.make(5000)
            ace.view_in(buffer)
            echo.w_put_string(buffer)
            die_with_code(exit_failure_code)
         end
         save_loadpath_read_file
         file := loadpath_read_file
         check not file.is_connected end
         echo.tfr_connect(file,path)
         Result := file.is_connected
         if Result then
            save_current_loadpath_path
            from
               echo.put_string(once "Append contents of %"")
               echo.put_string(path)
               echo.put_string(once "%" to loading path.%N")
            until
               file.end_of_input
            loop
               current_loadpath_path.copy(path)
               file.read_line
               buffer.copy(file.last_string)
               environment_variable_substitution(path, buffer)
               if buffer.is_empty then
                  if not file.end_of_input then
                     ace.cluster_add_last(buffer, Void, is_config_loadpath)
                  end
               else
                  if is_directory_resolve(buffer) and then not resolve_path.is_empty then
                     b := once ""
                     b.copy(buffer)
                     b.replace_all('/', '.')
                     if b.last = '.' then
                        b.remove_last(1)
                     end
                     ace.cluster_add_last(buffer, b, is_config_loadpath)
                  else
                     Result := loadpath_read(resolve_path.twin, level+1, is_config_loadpath) -- *** memory leak
                  end
               end
            end
            file.disconnect
            restore_current_loadpath_path
         end
         restore_loadpath_read_file
      end

   external_c_files_for_lcc_win32(cmd: STRING) is
         -- Because lcc_win32 does not accept *.c file while linking as
         -- other C compiler do :-(
      local
         c_files: ARRAY[STRING]; c_file: STRING; i: INTEGER
      do
         if not external_c_files.is_empty then
            c_files := external_c_files.split
            external_c_files.clear
            if c_files /= Void then
               from
                  i := c_files.lower
               until
                  i > c_files.upper
               loop
                  c_file := c_files.item(i)
                  cmd.append(lcc)
                  append_token(cmd,c_compiler_options)
                  append_token(cmd,c_file)
                  cmd.extend('%N')
                  c_file.remove_suffix(c_suffix)
                  c_file.append(object_suffix)
                  append_token(external_object_files,c_file)
                  i := i + 1
               end
            end
         end
      end

feature {ID_PROVIDER}

   id_file_path: STRING is
      once
         Result := path_h
         Result.remove_suffix(h_suffix)
         Result.append(once ".id")
      end

feature {C_PRETTY_PRINTER, INSTALL}

   default_c_compiler_options(running_install:  BOOLEAN) is
	 -- Setting of the default `c_compiler_options'.
	 -- The  `running_install' flag means that we are C compiling
	 -- tools of SmartEiffel (compile, compile_to_c, etc).
      do
         check
            c_compiler /= Void
         end
	 if gcc = c_compiler then
	    if running_install then
	       append_token(c_compiler_options, o2)
	    end
	 elseif gpp = c_compiler then
	    if running_install then
	       append_token(c_compiler_options, o2)
	    end
	 elseif lcc_win32 = c_compiler then
	    if c_compiler_options.is_empty then
	       append_token(c_compiler_options, once "-O")
	    end
	 elseif cc = c_compiler then
	 elseif wcl386 = c_compiler then
	 elseif bcc32 = c_compiler then
	    if c_compiler_options.is_empty then
	       c_compiler_options.copy(
                  once "-5 -w-aus -w-par -w-rvl -O2 -O-v")
	    end
	 elseif cl = c_compiler then
	    if c_compiler_options.is_empty then
	       c_compiler_options.copy(once "-O2 -nologo")
	    end
	 elseif sas_c = c_compiler then
	    if running_install then
	       if not Scoptions_exists then
		  append_token(c_compiler_options,
                               once "Optimize OptimizerTime")
	       end
	    else
	       c_compiler_options.clear
	       c_linker_options.copy(once "Link")
	       if not Scoptions_exists then
		  append_token(c_linker_options, once "SmallCode SmallData")
	       end
	    end
	 elseif dice = c_compiler then
	    if c_compiler_options.is_empty then
	       c_compiler_options.copy(once "-mD -mC")
	    end
	 elseif vbcc = c_compiler then
	    if c_compiler_options.is_empty then
	       if amiga_system = system_name then
		  c_compiler_options.copy(once "-DAMIGA")
	       end
	    end
	 elseif ccc = c_compiler then
	    if c_compiler_options.is_empty then
	       c_compiler_options.copy(o2)
	    end
	 elseif vpcc = c_compiler then
	 elseif open_vms_cc = c_compiler then
	 elseif tcc = c_compiler then
	 else
	    check false end
	 end
      end

feature {NONE}

   check_c_plus_plus is
         -- Check if we must use the C++ compiler; in that case, we switch to
         -- it if it is available
      once
         if not external_c_plus_plus_files.is_empty then
            -- There are C++ files; so we must switch
            if cpp_compiler /= Void then
               echo.put_string(once "Selecting C++ compiler: ")
               echo.put_string(cpp_compiler)
               c_compiler := cpp_compiler
               c_compiler_path := cpp_compiler_path
               c_linker_path := cpp_linker_path
               if ace_compiler_options /= Void then
                  c_compiler_options.copy(ace_compiler_options)
               elseif not cpp_mode_compiler_options.is_empty then
                  c_compiler_options.copy(cpp_mode_compiler_options)
               end
               if ace_linker_options /= Void then
                  c_linker_options.copy(ace_linker_options)
               elseif not cpp_mode_linker_options.is_empty then
                  c_linker_options.copy(cpp_mode_linker_options)
               end
               echo.put_string(once ".%N")
            else
               error_handler.append(c_compiler)
               error_handler.append(once " is not supported as a C++ compiler. %
                                         %I will continue, but expect some problems.%N")
               error_handler.print_as_warning
            end
         end
      end

feature {NONE}

   add_config_loadpath_file(loadpath_file: STRING) is
      -- This file will also be read by `read_loadpath_files'
      do
         if config_loadpath_files = Void then
            create config_loadpath_files.with_capacity(4)
         end
         config_loadpath_files.add_last(loadpath_file)
      end

feature {COMMAND_LINE_TOOLS, SYSTEM_TOOLS_VISITOR}

   add_loadpath_file(loadpath_file: STRING) is
      -- This file will also be read by `read_loadpath_files'
      do
         if extra_loadpath_files = Void then
            create extra_loadpath_files.with_capacity(2)
         end
         extra_loadpath_files.add_last(loadpath_file)
      end

   add_smarteiffel_c_mode_options is
         -- Adds the SmartEiffel options for the chosen C mode; then add the
         -- libraries for the C compiler
      local
         string_command_line: STRING_COMMAND_LINE
      do
         if smarteiffel_options /= Void then
            string_command_line.parse(smarteiffel_options)
         end
         if ace_compiler_options /= Void then
            c_compiler_options.copy(ace_compiler_options)
         elseif not c_mode_compiler_options.is_empty then
            c_compiler_options.copy(c_mode_compiler_options)
         end
         if ace_linker_options /= Void then
            c_linker_options.copy(ace_linker_options)
         elseif not c_mode_linker_options.is_empty then
            c_linker_options.copy(c_mode_linker_options)
         end
         add_libraries_from_compiler_options
      end

feature {ACE, COMMAND_LINE_TOOLS}

   is_alternate_c_mode: BOOLEAN
         -- If false, then the C mode associated with the SmartEiffel level
         -- will be selected; otherwise, the user has explicitely used the
         -- -c_mode option; this one will be used.

   set_default_c_mode(c_mode: STRING) is
         -- Sets the C mode to use. If an alternate C mode has been set, this
         -- feature does nothing.
      do
         if c_compiler_mode /= c_compiler_cc and then not is_alternate_c_mode then
            set_c_mode(c_mode)
         end
      end

   set_alternate_c_mode(c_mode: STRING) is
         -- Sets an alternate C mode (the user explicitely used the -c_mode
         -- flag)
      do
         if c_compiler_mode = c_compiler_cc then
            error_handler.append("You must choose either -cc or -c_mode, but %
                                 %you cannot use them both.")
            error_handler.print_as_fatal_error
         end
         c_compiler_mode := c_compiler_cmode
         is_alternate_c_mode := True
         set_c_mode(c_mode)
      end

feature {NONE}

   c_compiler_mode: INTEGER

   c_compiler_none: INTEGER is unique
         -- Value of `c_compiler_none' indicating that neither -cc nor -c_mode
         -- were used (yet).

   c_compiler_cc: INTEGER is unique
         -- Value of `c_compiler_mode' indicating that `set_c_compiler' was
         -- used with a non-Void value

   c_compiler_cmode: INTEGER is unique
         -- Value of `c_compiler_mode' indicating that `set_alternate_c_mode'
         -- was used.

   compiler_path_of(compiler: STRING): STRING is
      do
         if compiler = gcc then
            Result := gcc
         elseif compiler = gpp then
            Result := gpp
         elseif compiler = lcc_win32 then
            Result := lcc
         elseif compiler = cc then
            Result := cc
         elseif compiler = wcl386 then
            Result := once "wcc386"
         elseif compiler = bcc32 then
            Result := bcc32
         elseif compiler = cl then
            Result := cl
         elseif compiler = sas_c then
            Result := sas_c
         elseif compiler = dice then
            Result := dcc
         elseif compiler = vbcc then
            Result := vc
         elseif compiler = ccc then
            Result := ccc
         elseif compiler = vpcc then
            Result := vpcc
         elseif compiler = open_vms_cc then
            Result := open_vms_cc
         elseif compiler = tcc then
            Result := tcc
         end
      end

   linker_path_of(compiler: STRING): STRING is
      do
         if compiler = gcc then
            Result := gcc
         elseif compiler = gpp then
            Result := gpp
         elseif compiler = lcc_win32 then
            Result := lcclnk
         elseif compiler = cc then
            Result := cc
         elseif compiler = wcl386 then
            Result := once "wlink"
         elseif compiler = bcc32 then
            Result := bcc32
         elseif compiler = cl then
            Result := cl
         elseif compiler = sas_c then
            Result := sas_c
         elseif compiler = dice then
            Result := dcc
         elseif compiler = vbcc then
            Result := vc
         elseif compiler = ccc then
            Result := ccc
         elseif compiler = vpcc then
            Result := vpcc
         elseif compiler = open_vms_cc then
            Result := open_vms_cc
         elseif compiler = tcc then
            Result := tcc
         end
      end

   set_c_mode(c_mode: STRING) is
      local
         string_command_line: STRING_COMMAND_LINE
         i: INTEGER
      do
         if not c_mode_memory.is_equal(c_mode) then
            c_mode_memory.copy(c_mode)
            echo.put_string(once "C mode %"")
            echo.put_string(c_mode)
            if is_alternate_c_mode then
               echo.put_string(once "%" (alternate mode) selected.%N")
            else
               echo.put_string(once "%" (default mode) selected.%N")
            end

            -- Now gather info from the config file and populate the variables

            if ini_parser.section_has(c_mode, fz_conf_compiler_type) then
               c_compiler := ini_parser.section_item(c_mode, fz_conf_compiler_type)

               i := compiler_list.index_of(c_compiler)
               if i > compiler_list.upper then
                  echo.w_put_string(once "Unknown compiler type %"")
                  echo.w_put_string(c_compiler)
                  echo.w_put_string(once "%"%N")
                  show_compiler_list_then_exit(compiler_list)
               end
               c_compiler := compiler_list.item(i)
            else
               error_handler.append("Unable to find the compiler type of %"")
               error_handler.append(c_mode)
               error_handler.append("%". Please fix your configuration file or %
                                    %choose another C mode.")
               error_handler.print_as_fatal_error
            end

            if ini_parser.section_has(c_mode, fz_conf_compiler_path) then
               c_compiler_path := ini_parser.section_item(c_mode, fz_conf_compiler_path)
            else
               c_compiler_path := compiler_path_of(c_compiler)
            end

            if ini_parser.section_has(c_mode, fz_conf_linker_path) then
               c_linker_path := ini_parser.section_item(c_mode, fz_conf_linker_path)
               c_mode_has_explicit_linker_path_or_option := True
            else
               c_linker_path := linker_path_of(c_compiler)
            end

            if ini_parser.section_has(c_mode, fz_conf_compiler_options) then
               c_mode_compiler_options.copy(ini_parser.section_item(c_mode, fz_conf_compiler_options))
            else
               c_mode_compiler_options.clear
            end

            if ini_parser.section_has(c_mode, fz_conf_linker_options) then
               c_mode_linker_options.copy(ini_parser.section_item(c_mode, fz_conf_linker_options))
               c_mode_has_explicit_linker_path_or_option := True
            else
               c_mode_linker_options.copy(c_mode_compiler_options)
            end

            if ini_parser.section_has(c_mode, fz_conf_cpp_compiler_type) then
               cpp_compiler := ini_parser.section_item(c_mode, fz_conf_cpp_compiler_type)

               i := c_plus_plus_compiler_list.index_of(cpp_compiler)
               if i > c_plus_plus_compiler_list.upper then
                  echo.w_put_string(once "Unknown C++ compiler type %"")
                  echo.w_put_string(cpp_compiler)
                  echo.w_put_string(once "%"%N")
                  show_compiler_list_then_exit(c_plus_plus_compiler_list)
               end
               cpp_compiler := c_plus_plus_compiler_list.item(i)

               if ini_parser.section_has(c_mode, fz_conf_cpp_compiler_path) then
                  cpp_compiler_path := ini_parser.section_item(c_mode, fz_conf_cpp_compiler_path)
               else
                  cpp_compiler_path := compiler_path_of(cpp_compiler)
               end

               if ini_parser.section_has(c_mode, fz_conf_cpp_linker_path) then
                  cpp_linker_path := ini_parser.section_item(c_mode, fz_conf_cpp_linker_path)
                  c_mode_has_explicit_linker_path_or_option := True
               else
                  cpp_linker_path := linker_path_of(cpp_compiler)
               end

               if ini_parser.section_has(c_mode, fz_conf_cpp_compiler_options) then
                  cpp_mode_compiler_options.copy(ini_parser.section_item(c_mode, fz_conf_cpp_compiler_options))
               elseif cpp_compiler /= Void then
                  cpp_mode_compiler_options.copy(c_mode_compiler_options)
               end

               if ini_parser.section_has(c_mode, fz_conf_cpp_linker_options) then
                  cpp_mode_linker_options.copy(ini_parser.section_item(c_mode, fz_conf_cpp_linker_options))
                  c_mode_has_explicit_linker_path_or_option := True
               else
                  cpp_mode_linker_options.copy(cpp_mode_compiler_options)
               end
            end

            if ini_parser.section_has(c_mode, fz_conf_smarteiffel_options) then
               if smarteiffel_options = Void then
                  create smarteiffel_options.copy(ini_parser.section_item(c_mode, fz_conf_smarteiffel_options))
               else
                  smarteiffel_options.copy(ini_parser.section_item(c_mode, fz_conf_smarteiffel_options))
               end
            end
         end
      ensure
         compiler_list.fast_has(c_compiler)
      end

   c_compiler: STRING
         -- One item of `compiler_list' or `c_plus_plus_compiler_list'

   c_compiler_path: STRING
         -- The path to the real C compiler

   c_linker_path: STRING
         -- The path to the real C linker

   c_mode_compiler_options: STRING is ""
         -- The compiler options set by the C mode

   c_mode_linker_options: STRING is ""
         -- The linker options set by the C mode

   cpp_compiler: STRING
         -- One item of `c_plus_plus_compiler_list'.

   cpp_compiler_path: STRING
         -- The path to the real C++ compiler

   cpp_linker_path: STRING
         -- The path to the real C++ linker

   cpp_mode_compiler_options: STRING is ""
         -- The C++ compiler options set by the C mode

   cpp_mode_linker_options: STRING is ""
         -- The C++ linker options set by the C mode

   ace_compiler_options: STRING
         -- The options ACE can set

   ace_linker_options: STRING
         -- The options ACE can set

   smarteiffel_options: STRING
         -- The SmartEiffel options set by the chosen C mode

   c_mode_has_explicit_linker_path_or_option: BOOLEAN
         -- True if either c_linker_path or c_linker_options are set for the
         -- chosen C mode. Useful to emit warnings (e.g. when using no_split)

feature {ACE}

   set_ace_compiler_options(options: STRING) is
      do
         ace_compiler_options := options
      end

   set_ace_linker_options(options: STRING) is
      do
         ace_linker_options := options
      end

   set_ace_external_lib_path(extlibpath: STRING) is
      do
         external_lib_paths.add_last(extlibpath)
      end

   set_ace_external_lib(extlib: STRING) is
      do
         external_libs.add_last(extlib)
      end

   external_libs: FIXED_ARRAY[STRING] is
         -- The external libs before being added to the `external_lib' (before
         -- the compiler is known, no such addition can take place)
      once
         create Result.with_capacity(2)
      end

   external_lib_paths: FIXED_ARRAY[STRING] is
         -- The external lib paths before being added to the
         -- `external_lib_path' (before the compiler is known, no such
         -- addition can take place)
      once
         create Result.with_capacity(2)
      end

   get_started is
      local
         i: INTEGER
      do
	 check 
	    c_compiler /= Void
	 end
         from
            i := external_libs.upper
         until
            i < external_libs.lower
         loop
            add_external_lib(external_libs.item(i))
            i := i - 1
         end
         external_libs.clear
         from
            i := external_lib_paths.upper
         until
            i < external_lib_paths.lower
         loop
            add_external_lib(external_lib_paths.item(i))
            i := i - 1
         end
         external_lib_paths.clear
      end

feature {NONE}

   external_header_path: STRING is ""
         -- Additional paths where .h files can be found.

   external_lib_path: STRING is ""
         -- External libraries path to be added at link time.

   external_lib: STRING is ""
         -- External libraries to be added at link time.

   sys_runtime_(name: STRING; suffix: CHARACTER) is
         -- Common part to implement `sys_runtime' and `mandatory_sys_runtime'.
      require
         name /= Void
         suffix = 'c' or suffix = 'h'
      do
         tmp_path.copy(sys_directory)
         subdirectory(tmp_path, fz_runtime)
         subdirectory(tmp_path, once "c")
         tmp_path.append(name)
         tmp_path.extend('.')
         tmp_path.extend(suffix)
      end

   show_compiler_list_then_exit(list: like compiler_list) is
      local
         i: INTEGER
      do
         echo.w_put_string(once "Currently handled compiler names:%N")
         from
            i := 1
         until
            i > list.upper
         loop
            echo.w_put_string(list.item(i))
            echo.w_put_character('%N')
            i := i + 1
         end
         die_with_code(exit_failure_code)
      end

   add_executable_name(cmd: STRING) is
      local
         executable_name: STRING
      do
         executable_name := once ""
         if ace.executable_name = Void then
            executable_name.copy(ace.root_class_name.twin)
            executable_name.to_lower
            if c_compiler = lcc_win32 then
               append_token(cmd,o_flag)
               append_token(cmd,executable_name)
               add_x_suffix(cmd)
            elseif c_compiler = bcc32 then
               append_token(cmd,e_flag)
               cmd.append(executable_name)
               add_x_suffix(cmd)
            elseif c_compiler = wcl386 then
               append_token(cmd,once "/fe=")
               cmd.append(executable_name)
               add_x_suffix(cmd)
            elseif c_compiler = sas_c then
               executable_name := ace.root_class_name.twin
               executable_name.to_lower
               cmd.append(fz_to_)
               append_token(cmd,executable_name)
            elseif c_compiler = dice then
               append_token(cmd,o_flag)
               append_token(cmd,executable_name)
            elseif c_compiler = vbcc then
               append_token(cmd,o_flag)
               append_token(cmd,executable_name)
            elseif c_compiler = vpcc then
               append_token(cmd,o_flag)
               append_token(cmd,executable_name)
            elseif c_compiler = open_vms_cc then
               append_token(cmd,executable_name)
            elseif c_compiler = tcc then
	       if system_name = unix_system then
		  append_token(cmd,o_flag)
		  append_token(cmd,once "a.out")
	       else
		  append_token(cmd,o_flag)
		  append_token(cmd,executable_name)
		  add_x_suffix(cmd)
	       end
            end
         else
            executable_name.copy(ace.executable_name)
            if c_compiler = gcc or else c_compiler = gpp then
               append_token(cmd,o_flag)
               append_token(cmd,executable_name)
               add_x_suffix(cmd)
            elseif c_compiler = lcc_win32 then
               append_token(cmd,o_flag)
               append_token(cmd,executable_name)
               add_x_suffix(cmd)
            elseif c_compiler = cc then
               append_token(cmd,o_flag)
               append_token(cmd,executable_name)
               add_x_suffix(cmd)
            elseif c_compiler = wcl386 then
               append_token(cmd,once "/fe=")
               cmd.append(executable_name)
               add_x_suffix(cmd)
            elseif c_compiler = bcc32 then
               append_token(cmd,e_flag)
               cmd.append(executable_name)
               add_x_suffix(cmd)
            elseif c_compiler = cl then
               append_token(cmd,o_flag)
               cmd.append(executable_name)
               add_x_suffix(cmd)
            elseif c_compiler = sas_c then
               cmd.append(fz_to_)
               append_token(cmd,executable_name)
            elseif c_compiler = dice then
               append_token(cmd,o_flag)
               append_token(cmd,executable_name)
               add_x_suffix(cmd)
            elseif c_compiler = vbcc then
               append_token(cmd,o_flag)
               append_token(cmd,executable_name)
               add_x_suffix(cmd)
            elseif c_compiler = ccc then
               append_token(cmd,o_flag)
               append_token(cmd,executable_name)
               add_x_suffix(cmd)
            elseif c_compiler = vpcc then
               append_token(cmd,o_flag)
               append_token(cmd,executable_name)
               add_x_suffix(cmd)
            elseif c_compiler = open_vms_cc then
               cmd.append(executable_name)
	    elseif c_compiler = tcc then
	       append_token(cmd,o_flag)
	       append_token(cmd,executable_name)
	       add_x_suffix(cmd)
            end
         end
      end

   add_objects(cmd, c_name: STRING; max: INTEGER) is
         -- Add objects files numbered from 1 to `max' included.
      local
         i: INTEGER; short_command: BOOLEAN
      do
         if max.in_range(3,99) then
            if unix_system = system_name then
               short_command := true
            elseif cygwin_system = system_name then
               short_command := true
            end
         end
         if short_command then
            add_objects_(cmd,c_name,1,max)
         else
            from
               i := 1 until i > max
            loop
               append_token(cmd,c_name)
               i.append_in(cmd)
               cmd.append(object_suffix)
               i := i + 1
            end
         end
      end

   add_objects_(cmd, c_name: STRING; min, max: INTEGER) is
         -- This is a good recursive example ;-)
      require
         max.in_range(1,99)
         min.in_range(1,max + 1)
      local
         c, i1, i2, new_min: INTEGER
      do
         if min > max then
            check min = max + 1 end
         elseif min < 9 then
            append_token(cmd,c_name)
            cmd.append(once "[1-")
            i1 := (9).min(max)
            i1.append_in(cmd)
            cmd.extend(']')
            cmd.append(object_suffix)
            add_objects_(cmd,c_name,i1 + 1,max)
         elseif min = max then
            append_token(cmd,c_name)
            min.append_in(cmd)
            cmd.append(object_suffix)
         else
            check (min \\ 10) = 0 end
            c := max - min + 1
            check c >= 2 end
            if c <= 10 then
               i1 := min // 10
               i2 := max \\ 10
               append_token(cmd,c_name)
               i1.append_in(cmd)
               cmd.extend('[')
               cmd.extend('0')
               cmd.extend('-')
               i2.append_in(cmd)
               cmd.extend(']')
               cmd.append(object_suffix)
            elseif c < 20 then
               add_objects_(cmd,c_name,min,min + 9)
               add_objects_(cmd,c_name,min + 10,max)
            else
               i1 := min // 10
               i2 := (max - 9) // 10
               check (i2 * 10) + 9 <= max end
               append_token(cmd,c_name)
               cmd.extend('[')
               i1.append_in(cmd)
               cmd.extend('-')
               i2.append_in(cmd)
               cmd.append(once "][0-9]")
               cmd.append(object_suffix)
               new_min := (i2 * 10) + 10
               add_objects_(cmd,c_name,new_min,max)
            end
         end
      ensure
         (min < max) implies (cmd.count > old cmd.count)
         c_name.is_equal(old c_name.twin)
         max = old max
      end

   add_external_header_path(path: STRING) is
         -- Append `path' to `external_header_path' taking into account
         -- how the current linker likes it to get this path.
         -- If `path' appears to be already formatted, no formatting is
         -- added by this routine.
      require
         not path.is_empty
      do
         token_buffer.clear
         -- everybody likes the Unix way
         if path.item (1) /= '-' then
            token_buffer.copy(once "-I")
         end
         token_buffer.append_string(path)
         append_if_not_already(external_header_path, token_buffer)
      end

   add_external_lib(lib: STRING) is
         -- Append `lib' to `external_lib' taking into account
         -- how the current linker likes it to get an additional library.
         -- If `lib' appears to be already formatted, no formatting is
         -- added by this routine.
      require
         not lib.is_empty
      do
         token_buffer.clear
         check compiler_list.fast_has(c_compiler) or else c_plus_plus_compiler_list.fast_has(c_compiler) end
         if c_compiler = lcc_win32 or else c_compiler = cl
	    or else c_compiler = bcc32 then
            -- they don't need an option
         else
            -- the Unix way
            if lib.item (1) /= '-' then
	       if not lib.has('/') and then not lib.has('\') then
		  token_buffer.copy(once "-l")
	       end
	    end
         end
         token_buffer.append_string(lib)
         token_buffer.extend_unless(' ')
         append_if_not_already(external_lib, token_buffer)
      end

   add_external_lib_path(path: STRING) is
         -- Append `path' to `external_lib_path' taking into account
         -- how the current linker likes it to get this path.
         -- If `path' appears to be already formatted, no formatting is
         -- added by this routine.
      require
         not path.is_empty
      do
	 -- lcc_win32 doesn't support paths, do nothing in that case
         if c_compiler /= lcc_win32 then
	    token_buffer.clear
	    if c_compiler = cl then
	       if path.has_prefix(l_flag) then
		  path.remove_prefix(l_flag)
	       end
	       -- Microsoft's own way of library searching
	       if path.item (1) /= '/' then
		  token_buffer.copy(once "/LIBPATH:")
	       end
	    else
	       -- the Unix way
	       if path.item (1) /= '-' then
		  token_buffer.copy(l_flag)
	       end
	    end
	    token_buffer.append_string(path)
            append_if_not_already(external_lib_path, token_buffer)
	 end
      end

feature {NONE}

   append_if_not_already(command_buffer, token: STRING) is
         -- Append the `token' to the `command_buffer' if it is not already in
         -- the buffer.
         -- Patch proposed by Tim Wilson-Brown <twilsonb@mac.com>, enhanced by
         -- Cyril Adrian
      local
         test_buffer: STRING
      do
         -- assumptions:
         -- ' ' is the character between tokens path will never contain ' '
         -- (anyone who tries this is insane anyway)

         -- this code uses test_buffer for memory management reasons
         test_buffer := once "                "

         -- check that " " + token_buffer does not appear at the end of the
         -- string, " " + token_buffer + " " appears nowhere in the string,
         -- and token_buffer + " " does not appear at the beginning of the
         -- string

         -- construct " " + token_buffer (test at the end of the buffer)
         test_buffer.make_filled(' ',1)
         test_buffer.append(token)

         if not command_buffer.has_suffix(test_buffer) then
            -- construct " " + token_buffer + " " (test at the middle of the buffer)
            test_buffer.extend(' ')
            if not external_lib_path.has_substring(test_buffer) then
               -- construct token_buffer + " " (test at the beginning of the buffer)
               test_buffer.remove_first(1)
               if not external_lib_path.has_prefix(test_buffer) then
                  append_token(command_buffer, token)
               end
            end
         end
      end

feature {NONE} -- Strings:

   exe_suffix: STRING is ".exe"

   o_suffix: STRING is ".o"

   obj_suffix: STRING is ".obj"

   c_flag: STRING is "-c"

   o_flag: STRING is "-o"

   e_flag: STRING is "-e"

   s_flag: STRING is "-s"

   lcc: STRING is "lcc"

   vc: STRING is "vc"

   dcc: STRING is "dcc"

   lcclnk: STRING is "lcclnk"

   lnk_suffix: STRING is ".lnk"

   libm: STRING is "m"

   l_flag: STRING is "-L"

   o2: STRING is "-O2"

   libcpml: STRING is "cpml"

   fz_to_: STRING is " To "

   fz_loadpath_se: STRING is "loadpath.se"

feature {SYSTEM_TOOLS_VISITOR}

   extra_loadpath_files: FIXED_ARRAY[STRING]

   config_loadpath_files: FIXED_ARRAY[STRING]

feature {NONE} -- Buffers:

   token_buffer: STRING is
      once
         create Result.make(128)
      end

   loadpath_read_file: TEXT_FILE_READ is
      do
         Result := lrf_save_buffer.item(lrf_save_counter.item)
      end

   cluster_directory: DIRECTORY is
      once
         create Result.make
      end

   resolve_directory: DIRECTORY is
      once
         create Result.make
      end

   c_mode_memory: STRING is
      once
         create Result.make(16)
      end

   clp_save_buffer: FIXED_ARRAY[STRING] is
      once
         create Result.with_capacity(5)
         Result.add_last("")
         Result.add_last("")
         Result.add_last("")
         Result.add_last("")
         Result.add_last("")
      end

   clp_save_counter: MEMO[INTEGER] is
      once
         create Result
      end

   save_current_loadpath_path is
      local
         counter: INTEGER
      do
         counter := clp_save_counter.item
         clp_save_buffer.item(counter).copy(current_loadpath_path)
         counter := counter + 1
         clp_save_counter.set_item(counter)
      end

   restore_current_loadpath_path is
      local
         counter: INTEGER
      do
         counter := clp_save_counter.item - 1
         current_loadpath_path.copy(clp_save_buffer.item(counter))
         clp_save_counter.set_item(counter)
      end

   lrf_save_buffer: FIXED_ARRAY[TEXT_FILE_READ] is
      once
         create Result.with_capacity(5)
         Result.add_last(create {TEXT_FILE_READ}.make)
         Result.add_last(create {TEXT_FILE_READ}.make)
         Result.add_last(create {TEXT_FILE_READ}.make)
         Result.add_last(create {TEXT_FILE_READ}.make)
         Result.add_last(create {TEXT_FILE_READ}.make)
      end

   lrf_save_counter: MEMO[INTEGER] is
      once
         create Result
         Result.set_item(-1)
      end

   save_loadpath_read_file is
      local
         counter: INTEGER
      do
         counter := lrf_save_counter.item + 1
         lrf_save_counter.set_item(counter)
      end

   restore_loadpath_read_file is
      local
         counter: INTEGER
      do
         counter := lrf_save_counter.item - 1
         lrf_save_counter.set_item(counter)
      end

feature {NONE} -- Singleton:

   singleton_memory: SYSTEM_TOOLS is
      once
         Result := Current
      end

invariant

   is_real_singleton: Current = singleton_memory

end -- SYSTEM_TOOLS
