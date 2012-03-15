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
class INSTALL
   --
   -- The SmartEiffel installer (the `install' command).
   --
   -- The first goal of this installer is to be simple: a no-brainer
   -- installation can be summed up as "keep your finger on the <Enter> key".
   --
inherit
   COMMAND_LINE_TOOLS
      rename
         system_tools as unused_system_tools
      end
   INSTALL_GLOBALS
      select
         system_tools
      end

creation
   make

feature

   install_tag: STRING is "1"
         -- Some version tag used to validate the format of the config file.
         -- If not existant, it is presumed to be "0".

   make is
      do
         -- That introduction text must fit on exactly 25 lines.
         io.put_string(once "{

Hello!

Thank you for choosing SmartEiffel.

I'm here to help you install your software. Many default options have been set
for you; the simplest way to install SmartEiffel is to keep pressing the
<Enter> key as long as I ask anything.

Of course you can change the options I set; it's just a matter of chosing items
in the menus, and you'll see you can greatly customize your SmartEiffel
installation. A golden rule is, just pressing <Enter> always works, and
inexorably leads towards the actual SmartEiffel installation. When no default is
provided (between brackets), the <Enter> key will just leave everything
unchanged and get you back to the previous menu.

As training, you'll be asked to press the <Enter> key to gain access to the
main menu ;-)

If you have problems, please contact the SmartEiffel team:
  - either by mail:  SmartEiffel@loria.fr
  - either by using the bugs database: http://SmartZilla.loria.fr


Press the <Enter> key: 
         }")
         read_line

         io.put_string(once "{

Don't forget that rule: the <Enter> key ensures that SmartEiffel will eventually
get installed.

         }")

         init
         main_menu
         exit
      end

feature {NONE} -- Initialization:

   init is
         -- Initializes the installer
      local
         config_detected: BOOLEAN
      do
         create default_c_compiler_options.make(16)
         create default_cpp_compiler_options.make(16)

         is_install.set_item(True)

         basic_directory.connect_to_current_working_directory
         cwd := basic_directory.last_entry.twin
         basic_directory.disconnect

         detect_os

         set_compiler_lists

         config_detected := seconf /= fz_conf_undefined
            and then file_tools.is_readable(seconf)
            and then not ini_parser.is_invalid
            and then use_existing_config

         set_default_variables
         if not config_detected then
            set_directories
         end
         if create_default_c_modes then
            if config_detected then
               -- Some default C modes were missing in the provided
               -- configuration file
               default_main_action := main_action_display_config
            else
               -- Since there was no valid config, try and get at least some
               -- default values from the compiler template.
               read_compiler_template(True)
               check
                  default_main_action > 0
               end
            end
         else
            check
               config_detected
            end
            default_main_action := main_action_install
         end

         noenv_bin_directory := once ""
         noenv_bin_directory.copy(bin_directory)
         system_tools.environment_variable_substitution(Void, noenv_bin_directory)

         noenv_sys_directory := once ""
         noenv_sys_directory.copy(sys_directory)
         system_tools.environment_variable_substitution(Void, noenv_sys_directory)

         noenv_short_directory := once ""
         noenv_short_directory.copy(short_directory)
         system_tools.environment_variable_substitution(Void, noenv_short_directory)

         system_tools.set_bin_directory(noenv_bin_directory)
         system_tools.set_sys_directory(noenv_sys_directory)
         system_tools.set_short_directory(noenv_short_directory)

         create install_c_mode.copy(fz_boost)
      end

   set_compiler_lists is
      local
         i: INTEGER
         rcfile, c, key: STRING
         inifile: INI_PARSER
      do
         directory.scan_with(install_path)
         if directory.last_scan_status then
            from
               i := directory.lower
            until
               i > directory.upper
            loop
               rcfile := once ""
               key := once ""
               rcfile.copy(directory.item(i))
               rcfile.to_lower
               key.copy(rcfile)
               if rcfile.has_suffix(once ".rc") then
                  key.remove_last(3)
                  basic_directory.compute_file_path_with(directory.path, rcfile)
                  rcfile.copy(basic_directory.last_entry)
                  inifile := rc_template(key, rcfile)
                  if inifile /= Void then
                     key := key.twin
                     if inifile.has(fz_conf_compiler_type) then
                        c := inifile.item(fz_conf_compiler_type)
                        if c /= Void and then not c.is_equal(fz_none) and then system_tools.compiler_list.has(c) then
                           c := system_tools.compiler_list.item(system_tools.compiler_list.index_of(c));
                           c_compiler_rc_map.add(c, key)
                           debug
                              io.put_string(once "C: ")
                              io.put_string(key)
                              io.put_string(once " -> ")
                              io.put_string(c)
                              io.put_new_line
                           end
                        else
                           fatal_problem_description_start
                           std_error.put_string(once "%NThe RC file ")
                           std_error.put_string(rcfile)
                           std_error.put_string(once" contains an invalid ")
                           std_error.put_string(fz_conf_compiler_type)
                           std_error.put_string(once" key.%N%N")
                           fatal_problem_description_end
                        end
                     else
                        fatal_problem_description_start
                        std_error.put_string(once "%NThe RC file ")
                        std_error.put_string(rcfile)
                        std_error.put_string(once" does not contain the ")
                        std_error.put_string(fz_conf_compiler_type)
                        std_error.put_string(once" key.%N%N")
                        fatal_problem_description_end
                     end
                     if inifile.has(fz_conf_cpp_compiler_type) then
                        c := inifile.item(fz_conf_cpp_compiler_type)
                        if c /= Void and then not c.is_equal(fz_none) then
                           if system_tools.c_plus_plus_compiler_list.has(c) then
                              c := system_tools.c_plus_plus_compiler_list.item(system_tools.c_plus_plus_compiler_list.index_of(c));
                              cpp_compiler_rc_map.add(c, key)
                              debug
                                 io.put_string(once "C++: ")
                                 io.put_string(key)
                                 io.put_string(once " -> ")
                                 io.put_string(c)
                                 io.put_new_line
                              end
                           else
                              fatal_problem_description_start
                              std_error.put_string(once "%NThe RC file ")
                              std_error.put_string(rcfile)
                              std_error.put_string(once" contains an invalid valid ")
                              std_error.put_string(fz_conf_cpp_compiler_type)
                              std_error.put_string(once" key.%N%N")
                              fatal_problem_description_end
                           end
                        end
                     end
                  end
               end
               i := i + 1
            end
         end
      end

   unix_seconf is
      do
         if system_tools.home_env = Void or else system_tools.user_env = Void or else system_tools.user_env.is_equal(once "root") then
            seconf := once "/etc/serc"
         else
            seconf := seconf_buffer
            seconf.copy(system_tools.home_env)
            if seconf.last /= '/' then
               seconf.extend('/')
            end
            seconf.append(once ".serc")
         end
      end

   windows_seconf is
      local
         i: INTEGER; found: BOOLEAN
      do
         if system_tools.userprofile_env = Void then
            seconf := once "C:\SE.CFG"
            from
               i := windows_standard_directories.lower
            until
               found or else i > windows_standard_directories.upper
            loop
               basic_directory.connect_to(windows_standard_directories.item(i))
               found := basic_directory.is_connected
               i := i + 1
            end
            if not found then
               set_system_name(system_tools.dos_system)
            else
               basic_directory.disconnect
            end
         else
            seconf := seconf_buffer
            seconf.copy(system_tools.userprofile_env)
            if seconf.last /= '\' then
               seconf.extend('\')
            end
            seconf.append(once "SE.CFG")
         end
      end

   detect_os is
         -- Auto-detection of the os; set the default variables accordingly
      local
         s: SYSTEM
         is_better_default_than_system_tools: BOOLEAN
      do
         if file_exists(once "/sys/rc") then
            -- We're looking for a file unique to the new Amiga Digital
            -- Environment running on Taos.
            set_system_name(system_tools.elate_system)
            seconf := once "/lang/eiffel/.serc" -- contributed by Joseph R. Kiniry
            is_better_default_than_system_tools := True
         elseif file_exists(once "s:startup-sequence") then
            -- This check has to be performed BEFORE the Unix check
            -- ("/bin/ls"), because the latter might be true if the user
            -- installed GeekGadgets and one of those perverted patches
            -- to handle Unix-style paths!
            set_system_name(system_tools.amiga_system)
            -- seconf not yet contributed
         elseif file_exists(once "/boot/beos/system/Tracker") then
            set_system_name(system_tools.beos_system)
            -- seconf not yet contributed
         elseif file_exists(once "/bin/ls.exe") then
            set_system_name(system_tools.cygwin_system)
            unix_seconf
         elseif file_exists(once "/bin/ls") then
            set_system_name(system_tools.unix_system)
            unix_seconf
         else
            if basic_directory.system_notation_detected then
               if basic_directory.unix_notation then
                  set_system_name(system_tools.unix_system)
                  unix_seconf
               elseif basic_directory.windows_notation then
                  set_system_name(system_tools.windows_system)
                  windows_seconf
               elseif basic_directory.cygwin_notation then
                  set_system_name(system_tools.cygwin_system)
                  unix_seconf
               elseif basic_directory.amiga_notation then
                  set_system_name(system_tools.amiga_system)
               elseif basic_directory.macintosh_notation then
                  set_system_name(system_tools.macintosh_system)
               elseif basic_directory.openvms_notation then
                  set_system_name(system_tools.open_vms_system)
               end
            end
            if system_name = Void then
               basic_directory.connect_to(once "C:\")
               if basic_directory.is_connected then
                  set_system_name(system_tools.windows_system)
                  basic_directory.disconnect
               end
            end
         end

         system_tools.make

         if system_tools.seconf_env /= Void then
            -- The "SmartEiffel" environment variable was set, we must use it
            seconf := system_tools.seconf_env
         elseif seconf = Void then
            -- No conf file is set: use the SYSTEM_TOOLS computed default
            seconf := system_tools.seconf
         elseif not is_better_default_than_system_tools and then system_tools.seconf /= fz_conf_undefined then
            -- A conf file is set, but SYSTEM_TOOLS is deemed more pertinent
            seconf := system_tools.seconf
         else
            -- No known conf file, the user will have to set it
            seconf := fz_conf_undefined
         end

         check
            seconf /= Void
            fz_conf_undefined.is_equal(seconf) implies fz_conf_undefined = seconf
         end
      ensure
         system_name /= Void
         seconf /= Void
      end

   use_existing_config: BOOLEAN is
         -- Read the data from the config file.
         -- True if some valid data could be read.
      require
         seconf /= Void
         file_tools.is_readable(seconf)
      local
         sections, loadpaths: ITERATOR[STRING]
         section, cstr, cppstr, tmp: STRING
         c_mode: C_MODE
         tag: STRING
      do
         if ini_parser.section_has(fz_conf_general, fz_conf_tag) then
            tag := ini_parser.section_item(fz_conf_general, fz_conf_tag)
         else
            tag := once "0" -- unknown version (prior to 1.1b4)
         end
         if not tag.is_equal(install_tag) then
            io.put_string("*** Your installation file has an old format. It %
                          %will not be used.%N")
         else
            if not ini_parser.section_has(fz_conf_general, fz_conf_bin)
               or else not ini_parser.section_has(fz_conf_general, fz_conf_sys)
               or else not ini_parser.section_has(fz_conf_general, fz_conf_short)
               or else not ini_parser.section_has(fz_conf_general, fz_conf_os)
             then
               io.put_string(once "The configuration file is invalid; it will be ignored.%N")
            else
               bin_directory := ini_parser.section_item(fz_conf_general, fz_conf_bin)
               sys_directory := ini_parser.section_item(fz_conf_general, fz_conf_sys)
               short_directory := ini_parser.section_item(fz_conf_general, fz_conf_short)
               set_system_name(ini_parser.section_item(fz_conf_general, fz_conf_os))
               loadpaths := ini_parser.section_key_iterator(fz_conf_loadpath)
               if loadpaths /= Void then
                  from
                     create extra_loadpath_keys.with_capacity(4)
                     create extra_loadpath_items.with_capacity(4)
                  until
                     loadpaths.is_off
                  loop
                     extra_loadpath_keys.add_last(loadpaths.item)
                     extra_loadpath_items.add_last(ini_parser.section_item(fz_conf_loadpath, loadpaths.item))
                     loadpaths.next
                  end
               end
               sections := ini_parser.sections_iterator
               if sections /= Void then
                  from
                     sections.start
                     create c_modes.with_capacity(8)
                     create unused_c_modes.with_capacity(8)
                  until
                     sections.is_off
                  loop
                     section := sections.item
                     if not section.is_equal(fz_conf_general)
                        and then not section.is_equal(fz_conf_loadpath)
                        and then ini_parser.section_has(section, fz_conf_compiler_type)
                      then
                        cstr := ini_parser.section_item(section, fz_conf_compiler_type)
                        if ini_parser.section_has(section, fz_conf_cpp_compiler_type) then
                           cppstr := ini_parser.section_item(section, fz_conf_cpp_compiler_type)
                        else
                           cppstr := Void
                        end
                        create c_mode.make(section, template(cstr), cstr, template(cppstr), cppstr)
                        if ini_parser.section_has(section, fz_conf_compiler_path) then
                           tmp := ini_parser.section_item(section, fz_conf_compiler_path)
                           c_mode.set_c_compiler_path(tmp)
                        end
                        if ini_parser.section_has(section, fz_conf_compiler_options) then
                           tmp := ini_parser.section_item(section, fz_conf_compiler_options)
                           c_mode.set_c_compiler_options(tmp)
                        end
                        if ini_parser.section_has(section, fz_conf_linker_path) then
                           tmp := ini_parser.section_item(section, fz_conf_linker_path)
                           c_mode.set_c_linker_path(tmp)
                        end
                        if ini_parser.section_has(section, fz_conf_linker_options) then
                           tmp := ini_parser.section_item(section, fz_conf_linker_options)
                           c_mode.set_c_linker_options(tmp)
                        end
                        if ini_parser.section_has(section, fz_conf_smarteiffel_options) then
                           tmp := ini_parser.section_item(section, fz_conf_smarteiffel_options)
                           c_mode.set_smarteiffel_options(tmp)
                        end
                        if fz_conf_cpp_compiler_type /= Void then
                           if ini_parser.section_has(section, fz_conf_cpp_compiler_path) then
                              tmp := ini_parser.section_item(section, fz_conf_cpp_compiler_path)
                              c_mode.set_cpp_compiler_path(tmp)
                           end
                           if ini_parser.section_has(section, fz_conf_cpp_compiler_options) then
                              tmp := ini_parser.section_item(section, fz_conf_cpp_compiler_options)
                              c_mode.set_cpp_compiler_options(tmp)
                           end
                           if ini_parser.section_has(section, fz_conf_cpp_linker_path) then
                              tmp := ini_parser.section_item(section, fz_conf_cpp_linker_path)
                              c_mode.set_cpp_linker_path(tmp)
                           end
                           if ini_parser.section_has(section, fz_conf_cpp_linker_options) then
                              tmp := ini_parser.section_item(section, fz_conf_cpp_linker_options)
                              c_mode.set_cpp_linker_options(tmp)
                           end
                        end
                        c_modes.add_last(c_mode)
                     end
                     sections.next
                  end
               end
               Result := True
            end
         end
      end

   set_default_variables is
      do
         inspect
            system_name

         when "UNIX" then
            default_c_compiler := system_tools.gcc
            default_c_compiler_options.copy(once "-pipe")
            default_cpp_compiler := system_tools.gpp
            default_cpp_compiler_options.copy(once "-pipe")

         when "Windows" then

         when "Cygwin" then
            default_c_compiler := system_tools.gcc
            default_c_compiler_options.copy(once "-pipe -O2")
            default_cpp_compiler := system_tools.gpp
            default_cpp_compiler_options.copy(once "-pipe -O2")

         when "BeOS" then

         when "Macintosh" then

         when "Amiga" then

         when "DOS" then

         when "OS2" then

         when "OpenVMS" then
            default_c_compiler := system_tools.open_vms_cc

         when "Elate" then
            default_c_compiler := system_tools.vpcc
            default_cpp_compiler := system_tools.vpcc

         else
            system_name := fz_conf_undefined

         end

         if extra_loadpath_keys = Void then
            create extra_loadpath_keys.with_capacity(4)
            create extra_loadpath_items.with_capacity(4)

            add_default_loadpath(once "lib")
            add_default_loadpath(once "tools")
            add_default_loadpath(once "tutorial")
         end

         check seconf /= Void end
         if seconf = fz_conf_undefined then
            default_main_action := main_action_define_variables
         elseif default_c_compiler = Void then
            default_main_action := main_action_choose_c_compiler
         else
            default_main_action := main_action_display_config
         end
      end

   add_default_loadpath(key: STRING) is
      local
         loadpath: STRING
      do
         basic_directory.connect_to_current_working_directory
         loadpath := basic_directory.last_entry.twin
         basic_directory.disconnect
         if not loadpath.is_empty then
            basic_directory.compute_subdirectory_with(loadpath, key)
            loadpath.copy(basic_directory.last_entry)
            if not loadpath.is_empty then
               basic_directory.compute_file_path_with(loadpath, once "loadpath.se")
               loadpath.copy(basic_directory.last_entry)
            end
         end

         if loadpath.is_empty then
            fatal_problem_description_start
            std_error.put_string(once "%NCould not compute the path to the ")
            std_error.put_string(key)
            std_error.put_string(once" loadpath.se%N%N")
            fatal_problem_description_end
         else
            extra_loadpath_keys.add_last(key)
            extra_loadpath_items.add_last(loadpath)
         end
      end

   set_directories is
      do
         directory.scan_current_working_directory
         if not directory.last_scan_status then
            fatal_problem_description_start
            std_error.put_string("Cannot connect to the current directory!%N")
            fatal_problem_description_end
         end

         directory.scan_subdirectory(once "bin")
         if directory.last_scan_status then
            create bin_directory.copy(directory.path)
            directory.scan_parent_directory
         else
            directory.scan_current_working_directory
            create bin_directory.copy(directory.path)
         end

         directory.scan_subdirectory(once "sys")
         if directory.last_scan_status then
            create sys_directory.copy(directory.path)
            directory.scan_parent_directory
         else
            directory.scan_current_working_directory
            create sys_directory.copy(directory.path)
         end

         directory.scan_subdirectory(once "short")
         if directory.last_scan_status then
            create short_directory.copy(directory.path)
            directory.scan_parent_directory
         else
            directory.scan_current_working_directory
            create short_directory.copy(directory.path)
         end
      end

   create_default_c_modes: BOOLEAN is
         -- Create the default C modes; or only the missing ones.
         -- Returns True if at least one mode was created.
      local
         level: INTEGER
         levelname: STRING
         c_mode: C_MODE
         read_template: BOOLEAN
         c_mode_parser, cpp_mode_parser: INI_PARSER
      do
         levelname := tmp_buffer
         if c_modes = Void then
            Result := True
            create c_modes.with_capacity(8)
         end
         if unused_c_modes = Void then
            create unused_c_modes.with_capacity(8)
         end
         if default_c_compiler /= Void then
            c_mode_parser := template(default_c_compiler)
         end
         from
            level := levels.level_boost
            read_template := True
         until
            level > levels.level_debug
         loop
            tmp_buffer.copy(levels.level_name(level))
            if level /= levels.level_boost then
               tmp_buffer.append(once "_check")
            end
            if not has_c_mode(tmp_buffer) then
               if unused_c_modes.is_empty then
                  if default_c_compiler = Void then
                     create c_mode.make(tmp_buffer, Void, fz_conf_undefined, Void, fz_conf_undefined)
                  else
                     create c_mode.make(tmp_buffer, c_mode_parser, default_c_compiler, cpp_mode_parser, default_cpp_compiler)
                  end
               else
                  c_mode := unused_c_modes.first
                  unused_c_modes.remove_first
                  if default_c_compiler = Void then
                     c_mode.reset(tmp_buffer, Void, fz_conf_undefined, Void, Void)
                  else
                     c_mode.reset(tmp_buffer, c_mode_parser, default_c_compiler, cpp_mode_parser, default_cpp_compiler)
                  end
               end
               if not c_mode.could_read_template then
                  read_template := False
                  if level = levels.level_debug then
                     c_mode.set_smarteiffel_options(once "-sedb -no_strip")
                  end
               end
               c_modes.add_last(c_mode)
               Result := True
            end
            level := level + 1
         end
         if read_template then
            default_main_action := main_action_display_config
         end
      ensure
         old c_modes = Void implies (c_modes /= Void and then Result)
         c_modes.count >= 8 -- there are 8 compilation levels
      end

   has_c_mode(c_mode: STRING): BOOLEAN is
      local
         i: INTEGER
      do
         from
            i := c_modes.lower
         until
            Result or else i > c_modes.upper
         loop
            Result := c_modes.item(i).name.is_equal(c_mode)
            i := i + 1
         end
      end


feature {NONE} -- Variables:

   main_action_define_variables:  INTEGER is  1
         -- The menu proposes to define the [General] and [Loadpath] sections

   main_action_choose_c_compiler: INTEGER is  2
         -- The menu proposes to manage the C mode sections (including
         -- choosing the default C compiler)

   main_action_display_config:    INTEGER is  3
         -- The menu proposes to display the configuration items (in order to
         -- verify them before writing the configuration file)

   main_action_create_config:     INTEGER is  4
         -- The menu proposes to write the configuration file

   main_action_install:           INTEGER is  5
         -- The menu proposes to install SmartEiffel

   main_action_exit:              INTEGER is  6
         -- The menu proposes to exit the installer

   main_action_redisplay:         INTEGER is -1
         -- The menu is asked to redisplay itself (without any action
         -- performed)


   basic_directory: BASIC_DIRECTORY
         -- Used to compute some directory paths

   cwd: STRING
         -- Used to save the initial current working directory (it
         -- must be restored before exit using `restore_current_working_directory'
         -- because we are not always under UNIX.

   stop: BOOLEAN
         -- Tells the main menu to exit

   default_main_action: INTEGER
         -- Next action to be performed by the main menu: one of the
         -- `main_action_*' variables

   seconf: STRING
         -- The path to the configuration file

   bin_directory: STRING
         -- The directory where the binaries are to be put

   sys_directory: STRING
         -- The directory containing the `runtime' directory

   short_directory: STRING
         -- The directory containing the `short' modes

   germ_directory: STRING
         -- The directory when the germ install is to be found

   noenv_bin_directory: STRING
   noenv_sys_directory: STRING
   noenv_short_directory: STRING

   default_c_compiler: STRING
         -- The default C compiler used to create initial C modes

   default_cpp_compiler: STRING
         -- The default C++ compiler used to create initial C modes

   c_compiler_name: STRING
         -- One element of SYSTEM_TOOLS `compiler_list'

   install_c_mode: STRING
         -- The chosen install mode; default is "boost"

   default_c_compiler_options: STRING
         -- Default options for the C compiler

   default_cpp_compiler_options: STRING
         -- Default options for the C compiler

   system_name: STRING
         -- One element of SYSTEM_TOOLS `system_list'

   c_modes: FIXED_ARRAY[C_MODE]
         -- Currently configured C modes (those will be written in the
         -- configuration file)

   unused_c_modes: FIXED_ARRAY[C_MODE]
         -- `Trop-plein' of C modes (unused created ones; to avoid too many
         -- memory leaks)

   extra_loadpath_keys: FIXED_ARRAY[STRING]
         -- The keys of the loadpaths in the configuration file

   extra_loadpath_items: FIXED_ARRAY[STRING]
         -- The loadpaths in the configuration file

feature {NONE} -- Internally handled menu:

   main_menu is
         -- Displays the main menu
      local
         action: INTEGER
      do
         from
         until
            stop
         loop
            action := display_menu
            inspect
               action

            when main_action_define_variables then
               define_variables
               default_main_action := main_action_choose_c_compiler

            when main_action_choose_c_compiler then
               choose_c_compiler
               default_main_action := main_action_display_config

            when main_action_display_config then
               display_config
               default_main_action := main_action_create_config

            when main_action_create_config then
               write_config
               default_main_action := main_action_install

            when main_action_install then
               install
               default_main_action := main_action_exit

            when main_action_exit then
               confirm_exit

            when main_action_redisplay then
               -- Nothing: redisplay the menu

            end
         end
      end

   display_menu: INTEGER is
         -- Displays the menu, and lets the user choose one item
      local
         ok: BOOLEAN
      do
         from until ok
         loop
            io.put_string(once "{
---------------------------------------------------------------------------

   Operating system: 
}")
            if system_name = Void then
               io.put_string(fz_conf_undefined)
            else
               io.put_string(system_name)
            end
            io.put_string(once "{

   Configuration file name: 
}")
            if seconf = Void then
               io.put_string(fz_conf_undefined)
            else
               io.put_string(seconf)
            end
            io.put_string(once "{


1. Define the OS, the configuration file, the default directories and loadpaths
2. Choose the C compilers and options for each C mode
3. Display the configuration information
4. Write the configuration file to disk
5. Install SmartEiffel
6. Exit

h. Help

Your choice [
            }")
            io.put_integer(default_main_action)
            io.put_string(once "]: ")
            read_line
            entry_buffer.to_lower

            if entry_buffer.is_empty then
               Result := default_main_action
               ok := True
            elseif entry_buffer.first = 'h' or else entry_buffer.first = 'H' then
               show_help
               Result := main_action_redisplay
               ok := True
            elseif entry_buffer.is_integer then
               Result := entry_buffer.to_integer
               ok := ((Result > 0) and then (Result <= main_action_exit))
            end
            if not ok then
               io.put_string(once "%NYou typed %"")
               io.put_string(entry_buffer)
               io.put_string(once "%".%NPlease enter a valid number between 1 and 6.%N")
            end
         end
      end

feature {NONE} -- Some help

   show_help is
      do
         page_line := 1
         page_string(smart_eiffel.copyright)
         page_string(once "{

This is the SmartEiffel installer.

This installer is here to help you. The options of the main menu are the six
steps that can be performed to install SmartEiffel. Once an action was perform-
ed, the menu proposes the next one.

You may have seen that, even starting the program, the menu already proposes
some option other than the first! Don't worry! It just means that the first
steps were automatically performed by the installer. You may always choose to
change them, by not choosing the default menu action.

The six steps are:

- First, tell the installer which system SmartEiffel is to be installed upon;
  also choose the directories SmartEiffel will be installed in, and the path
  to the configuration file to be created. At last, you may add default
  "loadpath" entries, meaning the files which describe where to find classes,
  by default (this facility is here to help you insert third-party libraries).

  Note that this step may be automatically performed. In that case, the OS was
  automatically performed, the configuration file is given a default location,
  the directories too, and the default loadpath files are those provided by
  SmartEiffel.


- Second, you may want to tell SmartEiffel which "C modes" are to be recognized.
  SmartEiffel uses a C compiler as back-end; it means that you need a C compiler
  installed on your machine.

  The C modes are ways to tailor how the C compiler must behave; each C modes is
  a C compiler, its path, and its options, and extra options for SmartEiffel to
  use.

  Let me explain in more details:

  SmartEiffel disposes of many options to tailor how instrumented your execut-
  able will be; wich assertions to check, should SmartEiffel add a debugger,
  should SmartEiffel generate the "debug" statements, and so on.

  Each "assertion level": boost, require_check, and so on, is associated with
  a default C mode, named after the level. A typical configuration would associ-
  ate the "boost" level with a highly optimizing C compiler (such as "gcc -O3");
  it would, on the other hand, tell SmartEiffel to no strip the executable in
  debug mode (and why not adding the SmartEiffel Debugger) while asking the C
  compiler to generate the symbol tables.


- Third, you can verify what you entered in the two previous sections. If all is
  ok, then you are ready to install SmartEiffel.


- Fourth, the configuration file is to be written at its chosen location.


- Fifth, the SmartEiffel tools are installed! They use the configuration file to
  generate themselves; just before compiling the tools, you will be asked which
  C mode should be used for that very task; the default mode is "boost".


- Sixth, last but not least: you can now leave the installer; you are now ready
  to enjoy SmartEiffel!


        Happy SmartEiffelling :o)


Type <Enter> to go back to the menu: 
         }")
         read_line
      end

feature {NONE} -- Define the main variables and the [General] section:

   define_variables is
      local
         done, first: BOOLEAN; entry: INTEGER
         sys: SYSTEM
      do
         installed := False
         first := True
         from until done
         loop
            io.put_string(once "%N---------------------------------------------------------------------------%N%N")
            show_valued_menu(once "1. Set the configuration file name", seconf)
            show_valued_menu(once "2. Set the operating system", system_name)
            show_valued_menu(once "3. Set the Bin directory", bin_directory)
            show_valued_menu(once "4. Set the Sys directory", sys_directory)
            show_valued_menu(once "5. Set the Short directory", short_directory)
            io.put_string(once "{
6. Manage the [Loadpath] section
7. Return to the main menu

Your choice [
                           }")
            if first then
               io.put_string(once "2]: ")
            else
               io.put_string(once "7]: ")
            end
            read_line
            if entry_buffer.is_empty then
               if first then
                  (2).append_in(entry_buffer)
               else
                  (7).append_in(entry_buffer)
               end
            end
            if entry_buffer.is_number then
               entry := entry_buffer.to_integer
               if entry < 1 or else entry > 7 then
                  io.put_string(once "Please enter a number between 1 and 7.%N")
               else

                  inspect
                     entry

                  when 1 then
                     ask(once "configuration file name")
                     if not entry_buffer.is_empty then
                        seconf_buffer.copy(entry_buffer)
                        if seconf = fz_conf_undefined then
                           io.put_string(once "*** Don't forget to set the %"SmartEiffel%" environment variable to%N*** ")
                           io.put_string(seconf_buffer)
                        end
                        seconf := seconf_buffer
                        sys.set_environment_variable(once "SmartEiffel", seconf)
                     end

                  when 2 then
                     set_system_name(choice_in(once "%NPlease enter the new value of the operating system",
                                               system_tools.system_list,
                                               system_name))

                  when 3 then
                     ask_directory(once "Bin directory", bin_directory, noenv_bin_directory, True)
                     system_tools.set_bin_directory(noenv_bin_directory)

                  when 4 then
                     ask_directory(once "Sys directory", sys_directory, noenv_sys_directory, False)
                     system_tools.set_sys_directory(noenv_sys_directory)

                  when 5 then
                     ask_directory(once "Short directory", short_directory, noenv_short_directory, False)
                     system_tools.set_short_directory(noenv_short_directory)

                  when 6 then
                     manage_extra_loadpaths

                  when 7 then
                     done := True

                  end
                  first := False
               end
            else
               io.put_string(once "Please enter a number between 1 and 7.%N")
            end
         end
      ensure
         not installed
      end

   ask_directory(prompt, dir, noenv_dir: STRING; ask_create: BOOLEAN) is
      require
         prompt /= Void
         dir /= Void
         noenv_dir /= Void
      local
         noenv_buffer: STRING
      do
         noenv_buffer := once ""
         ask(prompt)
         noenv_buffer.copy(entry_buffer)
         system_tools.environment_variable_substitution(Void, noenv_buffer)
         directory.scan(noenv_buffer)
         if not entry_buffer.is_empty then
            if not directory.last_scan_status then
               directory.scan_current_working_directory
               if directory.has(noenv_buffer) then
                  directory.scan_subdirectory(noenv_buffer)
               else
                  directory.scan(noenv_buffer)
               end
            end
            if directory.last_scan_status then
               dir.copy(entry_buffer)
               noenv_dir.copy(noenv_buffer)
            elseif ask_create then
               io.put_string(once "This directory does not exist; should I %
                                  %create it? [Y|n] ")
               read_line
               if entry_buffer.first.to_lower = 'y' then
                  dir.copy(entry_buffer)
                  noenv_dir.copy(noenv_buffer)
               end
            else
               bad_directory(entry_buffer)
            end
         end
      end

   show_valued_menu(menu, value: STRING) is
      do
         show_default_valued_menu(menu, value, Void)
      end

   ask(what: STRING) is
      do
         io.put_string(once "%NPlease enter the new value of the ")
         io.put_string(what)
         io.put_string(once ":%N")
         read_line
      end

   choice_in(title: STRING; names: COLLECTION[STRING]; default_choice: STRING): STRING is
         -- Force some item to be selected interactively.
         -- A Void `default_choice' means that an explicit chice must be made.
      require
         default_choice = Void or else names.fast_has(default_choice)
      local
         i: INTEGER; multiple: BOOLEAN
         w, n: STRING
      do
         from
         until
            Result /= Void
         loop
            io.put_string(title)
            io.put_string(once ":%N  ")
            from
               i := 1
            until
               i > names.upper
            loop
               n := names.item(i)
               if n = default_choice then
                  io.put_character('<')
                  io.put_string(n)
                  io.put_character('>')
               else
                  io.put_string(n)
               end
               i := i + 1
               if i <= names.upper then
                  io.put_string(once ", ")
               end
            end
            io.put_string(once "%N? ")
            read_line
            if entry_buffer.is_empty then
               Result := default_choice
            else
               from
                  n := once "                "
                  multiple := False
                  i := names.lower
                  w := entry_buffer
                  w.to_lower
               until
                  i > names.upper
               loop
                  n.copy(names.item(i))
                  n.to_lower
                  if w.same_as(n) then
                     Result := names.item(i)
                     i := names.upper
                  elseif n.has_prefix(w) then
                     if Result /= Void then
                        Result := Void
                        multiple := True
                     else
                        Result := names.item(i)
                     end
                  end
                  i := i + 1
               end
               if Result = Void then
                  io.put_string(once "%"")
                  io.put_string(w)
                  if multiple then
                     io.put_string("%" is ambiguous.%N")
                  else
                     io.put_string(once "%" is not a valid choice.%N")
                  end
               end
            end
         end
      ensure
         Result /= Void
         names.fast_has(Result)
      end

   bad_directory(path: STRING) is
      do
         io.put_string(once "%N*** ")
         io.put_string(path)
         io.put_string(once " does not exist or is not a directory:%N%
                            %    this value is ignored.%N")
      end

   manage_extra_loadpaths is
      local
         i, entry: INTEGER
         ok, done, first: BOOLEAN
      do
         first := True
         from
         until
            done
         loop
            io.put_string(once "%N%N---------------------------------------------------------------------------%N%N")
            if extra_loadpath_keys /= Void then
               from
                  i := extra_loadpath_keys.lower
               until
                  i > extra_loadpath_keys.upper or else extra_loadpath_keys.item(i).is_empty
               loop
                  io.put_integer(i+1)
                  io.put_string(once ". ")
                  io.put_string(extra_loadpath_keys.item(i))
                  io.put_string(once ": ")
                  io.put_string(extra_loadpath_items.item(i))
                  io.put_new_line
                  i := i + 1
               end
            end
            io.put_new_line
            io.put_integer(i+1)
            io.put_string(once ". Add an extra loadpath%N")
            io.put_integer(i+2)
            io.put_string(once ". Remove an extra loadpath%N%N")
            io.put_integer(i+3)
            io.put_string(once ". Return to the previous menu%N%NYour choice [")
            if first then
               io.put_integer(i+1)
            else
               io.put_integer(i+3)
            end
            io.put_string(once "]: ")
            read_line
            ok := False
            if entry_buffer.is_empty then
               if first then
                  (i+1).append_in(entry_buffer)
               else
                  (i+3).append_in(entry_buffer)
               end
            end
            if entry_buffer.is_integer then
               entry := entry_buffer.to_integer
            if entry >= 1 and then entry <= i+3 then
               ok := True
               inspect
                  entry - i

               when 3 then
                  done := True

               when 2 then
                  remove_extra_loadpath(i)

               when 1 then
                  add_extra_loadpath(i)

               else
                  modify_extra_loadpath(entry-1)

               end
            end
            end
            if not ok then
               io.put_string(once "%N*** Please enter a nember between 1 and ")
               io.put_integer(i+3)
               io.put_string(once ".%N")
            end
         end
      end

   add_extra_loadpath(pos: INTEGER) is
      do
         ask(once "loadpath key")
         if not entry_buffer.is_empty then
            if extra_loadpath_keys = Void then
               create extra_loadpath_keys.with_capacity(4)
            end
            if extra_loadpath_items = Void then
               create extra_loadpath_items.with_capacity(4)
            end
            if pos > extra_loadpath_keys.upper then
               check pos = extra_loadpath_keys.upper+1 end
               extra_loadpath_keys.add_last(entry_buffer.twin)
               extra_loadpath_items.add_last("")
            else
               extra_loadpath_keys.item(pos).copy(entry_buffer)
            end
         end
         ask(once "loadpath value")
         extra_loadpath_items.item(pos).copy(entry_buffer)
      end

   remove_extra_loadpath(max: INTEGER) is
      local
         ok: BOOLEAN
         entry: INTEGER
         lost_loadpath_key, lost_loadpath_item: STRING
      do
         from
         until
            ok
         loop
            ask(once "loadpath number")
            if entry_buffer.is_empty then
               ok := True
            else
               if entry_buffer.is_integer then
                  entry := entry_buffer.to_integer
                  if entry >= 1 and then entry <= max then
                     ok := True
                     lost_loadpath_key := extra_loadpath_keys.item(entry-1)
                     lost_loadpath_item := extra_loadpath_items.item(entry-1)
                     extra_loadpath_keys.remove(entry-1)
                     extra_loadpath_items.remove(entry-1)
                     lost_loadpath_key.clear
                     lost_loadpath_item.clear
                     extra_loadpath_keys.add_last(lost_loadpath_key) -- memory conservation
                     extra_loadpath_items.add_last(lost_loadpath_item) -- memory conservation
                  end
               end
               if not ok then
                  io.put_string(once "%N*** Please enter a n integer between 1 and ")
                  io.put_integer(max)
                  io.put_string(once ".%N")
               end
            end
         end
      end

   modify_extra_loadpath(i: INTEGER) is
      do
         io.put_string(once "This extra loadpath (")
         io.put_string(extra_loadpath_keys.item(i))
         io.put_string(once ") is: ")
         io.put_string(extra_loadpath_items.item(i))
         io.put_character('.')
         ask(once "loadpath")
         if not entry_buffer.is_empty then
            extra_loadpath_items.item(i).copy(entry_buffer)
         end
      end

feature {NONE} -- Define the C modes:

   choose_c_compiler is
      local
         done, first: BOOLEAN; def: STRING
         i, entry: INTEGER
      do
         installed := False
         first := True

         from
         until
            done
         loop
            io.put_string(once "%N---------------------------------------------------------------------------%NDefault compiler is ")
            if default_c_compiler = Void then
               io.put_string(fz_conf_undefined)
            else
               io.put_string(default_c_compiler)
            end
            io.put_new_line
            io.put_new_line
            from
               i := c_modes.lower
            until
               i > c_modes.upper
            loop
               io.put_integer(i+1)
               io.put_string(once ". Modify the %"")
               io.put_string(c_modes.item(i).name)
               io.put_string(once "%" C mode%N")
               i := i + 1
            end
            i := i + 1
            io.put_new_line
            io.put_integer(i)
            io.put_string(once ". Create a new C mode%N%N")
            io.put_integer(i+1)
            show_valued_menu(once ". Set the default compilers", default_c_compiler)
            io.put_integer(i+2)
            show_valued_menu(once ". Set the default compilers options", default_c_compiler_options)
            io.put_new_line

            io.put_integer(i+3)
            io.put_string("{
. Return to the main menu

Your choice [
            }")
            if first then
               io.put_integer(i+1)
            else
               io.put_integer(i+3)
            end
            io.put_string(once "]: ")
            read_line
            if entry_buffer.is_empty then
               if first then
                  -- Default action the first time you enter this menu, is to
                  -- choose the default compiler. It delays the "enter to
                  -- install" action, but just a bit.
                  (i+1).append_in(entry_buffer)
               else
                  (i+3).append_in(entry_buffer)
               end
            end
            if entry_buffer.is_integer then
               entry := entry_buffer.to_integer
               if entry < 1 or else entry > i+3 then
                  io.put_string(once "Please enter a valid number between 1 and ")
                  io.put_integer(i+3)
                  io.put_string(once ".%N")
               else
                  inspect
                     entry - i

                  when 3 then
                     done := True

                  when 2 then
                     ask(once "default C compiler options")
                     default_c_compiler_options.copy(entry_buffer)
                     from
                        i := c_modes.lower
                     until
                        i > c_modes.upper
                     loop
                        if c_modes.item(i).c_linker_path /= Void and then c_modes.item(i).c_linker_path.count > 0 then
                           c_modes.item(i).set_c_linker_options(default_c_compiler_options)
                        else
                           c_modes.item(i).set_c_linker_options(Void)
                        end
                        c_modes.item(i).set_c_compiler_options(default_c_compiler_options)
                        i := i + 1
                     end
                     default_cpp_compiler_options.copy(default_c_compiler_options)
                     if default_cpp_compiler /= Void and then default_cpp_compiler /= fz_none then
                        ask(once "default C++ compiler options")
                        default_cpp_compiler_options.copy(entry_buffer)
                        from
                           i := c_modes.lower
                        until
                           i > c_modes.upper
                        loop
                           if c_modes.item(i).cpp_linker_path /= Void and then c_modes.item(i).cpp_linker_path.count > 0 then
                              c_modes.item(i).set_cpp_linker_options(default_cpp_compiler_options)
                           else
                              c_modes.item(i).set_cpp_linker_options(Void)
                           end
                           c_modes.item(i).set_cpp_compiler_options(default_cpp_compiler_options)
                           i := i + 1
                        end
                     end

                  when 1 then
                     def := default_c_compiler
                     check def /= Void end
                     default_c_compiler := choice_in(once "%NPlease enter the new value of the default C compiler",
                                                     c_compiler_list,
                                                     def)
                     check default_c_compiler /= Void end
                     default_c_compiler_options.clear
                     if system_tools.c_plus_plus_compiler_list.has(default_c_compiler) then
                        default_cpp_compiler := default_c_compiler
                        default_cpp_compiler_options.copy(default_c_compiler_options)
                     else
                        io.put_string(once "%NThis compiler has no known C++ capabilities.%N%
                                           % In order to compile C++ programs,%
                                           % please also pick a C++ compiler.%N%N%
                                           %Type <Enter> if you don't know what%
                                           % this is all about.%N")
                        def := default_cpp_compiler
                        if def = Void or else def = fz_conf_undefined then
                           def := fz_none
                        end
                        default_cpp_compiler := choice_in(once "%NPlease enter the new value of the default C++ compiler",
                                                          cpp_compiler_list,
                                                          def)
                        if default_cpp_compiler = fz_none then
                           default_cpp_compiler := fz_conf_undefined
                        end
                        check default_cpp_compiler /= Void end
                        default_cpp_compiler_options.clear
                     end
                     read_compiler_template(True)

                  when 0 then
                     new_c_mode

                  else
                     modify_c_mode(entry - 1)
                  end
               end
               first := False
            else
               io.put_string(once "Please enter a valid number between 1 and")
               io.put_integer(i+3)
               io.put_string(once ".%N")
            end
         end
      ensure
         not installed
      end

   read_compiler_template(clean: BOOLEAN) is
         -- if `clean' is True, then the known C_modes are removed first.
      local
         i: INTEGER; dummy: BOOLEAN
         c_mode_parser, cpp_mode_parser: INI_PARSER
         c_mode: C_MODE; cmode: STRING
         sections: ITERATOR[STRING]
      do
         if clean then
            from
               i := c_modes.lower
            until
               i > c_modes.upper
            loop
               unused_c_modes.add_last(c_modes.item(i))
               i := i + 1
            end
            c_modes.clear
         end

         c_mode_parser := template(default_c_compiler)
         cpp_mode_parser := template(default_cpp_compiler)
         if c_mode_parser = Void then
            dummy := create_default_c_modes
         else
            from
               sections := c_mode_parser.sections_iterator
            until
               sections.is_off
            loop
               cmode := sections.item
               c_mode := Void
               if not clean then
                  from
                     i := c_modes.lower
                  until
                     c_mode /= Void or else i > c_modes.upper
                  loop
                     c_mode := c_modes.item(i)
                     if not c_mode.name.is_equal(cmode) then
                        c_mode := Void
                     end
                     i := i + 1
                  end
               end
               if c_mode = Void then
                  if unused_c_modes.is_empty then
                     create c_mode.make(cmode, c_mode_parser, default_c_compiler, cpp_mode_parser, default_cpp_compiler)
                  else
                     c_mode := unused_c_modes.first
                     unused_c_modes.remove_first
                     c_mode.reset(cmode, c_mode_parser, default_c_compiler, cpp_mode_parser, default_cpp_compiler)
                  end
                  c_modes.add_last(c_mode)
               end

               check c_mode /= Void end

               sections.next
            end
         end
      end

   new_c_mode is
      local
         i: INTEGER
         ok: BOOLEAN
      do
         ask(once "new C mode name")
         if entry_buffer.is_equal(fz_conf_general) or else entry_buffer.is_equal(fz_conf_loadpath) then
            io.put_string(once "%N*** This section name is reserved. Please choose another.%N")
         else
            from
               i := c_modes.lower
               ok := True
            until
               not ok or else i > c_modes.upper
            loop
               if c_modes.item(i).name.is_equal(entry_buffer) then
                  ok := False
                  io.put_string(once "%N*** This C mode already exists. Please choose another.%N")
               end
               i := i + 1
            end
            if ok then
               c_modes.add_last(create {C_MODE}.make(entry_buffer,
                                                     template(default_c_compiler),
                                                     default_c_compiler,
                                                     template(default_cpp_compiler),
                                                     default_cpp_compiler))
               modify_c_mode(c_modes.upper)
            end
         end
      end

   modify_c_mode(index: INTEGER) is
      require
         c_modes.valid_index(index)
      local
         c_mode: C_MODE
         default_c_linker, default_cpp_linker: STRING
         done, first, has_cpp: BOOLEAN
         max, i, entry: INTEGER
      do
         first := True
         from
         until
            done
         loop
            c_mode := c_modes.item(index)
            has_cpp := c_mode.cpp_compiler_type /= Void
            if has_cpp then
               max := 12
            else
               max := 8
            end
            io.put_string(once "%N---------------------------------------------------------------------------%N%NC mode: ")
            io.put_string(c_mode.name)
            io.put_new_line
            io.put_new_line

            if c_mode.c_linker_path = Void then
               default_c_linker := c_mode.c_compiler_path
               if default_c_linker = Void then
                  default_c_linker := c_mode.c_compiler_type
               end
            end
            if c_mode.cpp_linker_path = Void then
               default_cpp_linker := c_mode.cpp_compiler_path
               if default_cpp_linker = Void then
                  default_cpp_linker := c_mode.cpp_compiler_type
               end
            end

            show_default_valued_menu(once "1.  Change the C compiler type",           c_mode.c_compiler_type,     Void)
            show_default_valued_menu(once "2.  Change the C compiler path",           c_mode.c_compiler_path,     c_mode.c_compiler_type)
            show_default_valued_menu(once "3.  Change the C compiler options",        c_mode.c_compiler_options,  Void)
            show_default_valued_menu(once "4.  Change the C linker path",             c_mode.c_linker_path,       default_c_linker)
            show_default_valued_menu(once "5.  Change the C linker options",          c_mode.c_linker_options,    Void)
            show_default_valued_menu(once "6.  Change the C++ compiler type",         c_mode.cpp_compiler_type,     Void)
            if has_cpp then
               show_default_valued_menu(once "7.  Change the C++ compiler path",         c_mode.cpp_compiler_path,     c_mode.cpp_compiler_type)
               show_default_valued_menu(once "8.  Change the C++ compiler options",      c_mode.cpp_compiler_options,  Void)
               show_default_valued_menu(once "9.  Change the C++ linker path",           c_mode.cpp_linker_path,       default_cpp_linker)
               show_default_valued_menu(once "10. Change the C++ linker options",        c_mode.cpp_linker_options,    Void)
               show_default_valued_menu(once "11. Change the SmartEiffel extra options", c_mode.smarteiffel_options, Void)
               io.put_string(once "{

12.  Return to the previous menu

Your choice [
            }")
            else
               show_default_valued_menu(once "7. Change the SmartEiffel extra options", c_mode.smarteiffel_options, Void)
               io.put_string(once "{

8.  Return to the previous menu

Your choice [
            }")
            end
            if first then
               io.put_string(once "1]: ")
            elseif has_cpp then
               io.put_string(once "12]: ")
            else
               io.put_string(once "8]: ")
            end
            read_line

            if entry_buffer.is_empty then
               if first then
                  (1).append_in(entry_buffer)
               elseif has_cpp then
                  (12).append_in(entry_buffer)
               else
                  (8).append_in(entry_buffer)
               end
            end
            if entry_buffer.is_number then
               entry := entry_buffer.to_integer
               if entry >= 1 and then entry <= max then
                  inspect
                     entry

                  when 1 then
                     io.put_string(once "Known C compilers: ")
                     from
                        i := c_compiler_list.lower
                     until
                        i > c_compiler_list.upper
                     loop
                        if i > c_compiler_list.lower then
                           io.put_string(once ", ")
                        end
                        io.put_string(c_compiler_list.item(i))
                        i := i + 1
                     end
                     io.put_new_line
                     ask(once "C compiler type")
                     if not entry_buffer.is_empty then
                        if c_compiler_list.has(entry_buffer) then
                           c_mode.reset(c_mode.name, rc_template(entry_buffer, Void),
                                        system_tools.compiler_list.item(system_tools.compiler_list.index_of(c_compiler_rc_map.at(entry_buffer))),
                                        c_mode.cpp_file, c_mode.cpp_compiler_type)
                        else
                           io.put_string(once "%N*** Unknown C compiler.%N")
                        end
                     end

                  when 2 then
                     ask(once "C compiler path")
                     if not entry_buffer.is_empty then
                        if file_tools.is_readable(entry_buffer) then
                           c_mode.set_c_compiler_path(entry_buffer)
                        else
                           io.put_string(once "*** This file does not exist or is not readable.%N")
                        end
                     end

                  when 3 then
                     ask(once "C compiler options")
                     c_mode.set_c_compiler_options(entry_buffer)

                  when 4 then
                     ask(once "C linker path")
                     if not entry_buffer.is_empty then
                        if file_tools.is_readable(entry_buffer) then
                           c_mode.set_c_linker_path(entry_buffer)
                           c_mode.set_c_linker_options(Void)
                        else
                           io.put_string(once "*** This file does not exist or is not readable.%N")
                        end
                     end

                  when 5 then
                     ask(once "C linker options")
                     c_mode.set_c_linker_options(entry_buffer)

                  when 6 then
                     io.put_string(once "Known C++ compilers: ")
                     from
                        i := cpp_compiler_list.lower
                     until
                        i > cpp_compiler_list.upper
                     loop
                        if i > cpp_compiler_list.lower then
                           io.put_string(once ", ")
                        end
                        io.put_string(cpp_compiler_list.item(i))
                        i := i + 1
                     end
                     io.put_new_line
                     ask(once "C++ compiler type")
                     if not entry_buffer.is_empty then
                        if entry_buffer.is_equal(fz_none) then
                           c_mode.reset(c_mode.name,
                                        c_mode.c_file, c_mode.c_compiler_type,
                                        Void, Void)
                        elseif cpp_compiler_list.has(entry_buffer) then
                           c_mode.reset(c_mode.name,
                                        c_mode.c_file, c_mode.c_compiler_type,
                                        rc_template(entry_buffer, Void),
                                        system_tools.c_plus_plus_compiler_list.item(system_tools.c_plus_plus_compiler_list.index_of(cpp_compiler_rc_map.at(entry_buffer))))
                        else
                           io.put_string(once "%N*** Unknown C++ compiler.%N")
                        end
                     end

                  when 7 then
                     if has_cpp then
                        ask(once "C++ compiler path")
                        if not entry_buffer.is_empty then
                           if file_tools.is_readable(entry_buffer) then
                              c_mode.set_cpp_compiler_path(entry_buffer)
                           else
                              io.put_string(once "*** This file does not exist or is not readable.%N")
                           end
                        end
                     else
                        ask(once "SmartEiffel options")
                        c_mode.set_smarteiffel_options(entry_buffer)
                     end

                  when 8 then
                     if has_cpp then
                        ask(once "C++ compiler options")
                        c_mode.set_cpp_compiler_options(entry_buffer)
                     else
                        done := True
                     end

                  when 9 then
                     ask(once "C++ linker path")
                     if not entry_buffer.is_empty then
                        if file_tools.is_readable(entry_buffer) then
                           c_mode.set_cpp_linker_path(entry_buffer)
                           c_mode.set_cpp_linker_options(Void)
                        else
                           io.put_string(once "*** This file does not exist or is not readable.%N")
                        end
                     end

                  when 10 then
                     ask(once "C++ linker options")
                     c_mode.set_cpp_linker_options(entry_buffer)

                  when 11 then
                     ask(once "SmartEiffel options")
                     c_mode.set_smarteiffel_options(entry_buffer)

                  when 12 then
                     done := True

                  end
                  first := False
               else
                  io.put_string(once "%N*** Please enter a number between 1 and ")
                  io.put_integer(max)
                  io.put_string(once ".%N")
               end
            else
               io.put_string(once "%N*** Please enter a number between 1 and ")
               io.put_integer(max)
               io.put_string(once ".%N")
            end
         end
      end

   show_default_valued_menu(menu, value, default_value: STRING) is
      do
         io.put_string(menu)
         io.put_string(once " (")
         if value = Void or else value.is_empty then
            if default_value = Void then
               io.put_string(once "undefined")
            else
               io.put_string(once "default: ")
               io.put_string(default_value)
            end
         else
            io.put_string(value)
         end
         io.put_string(once ")%N")
      end

feature {NONE} -- The installation itself:

   installed: BOOLEAN

   install is
      local
         do_install: BOOLEAN
      do
         do_install := not installed
         if installed then
            io.put_string(once "%NSmartEiffel is already installed with the current options. Do you want to%N%
                               %install SmartEiffel again? [no] ");
            read_line
            if not entry_buffer.is_empty then
               entry_buffer.to_lower
               do_install := entry_buffer.first = 'y'
            else
               io.put_string(once "OK, aborting.%N");
            end
         end

         if do_install then
            io.put_new_line
            installed := True
            set_seconf
            compile_all
            io.put_string(once "Done.%N")
         end
      ensure
         installed
      end

   display_config is
         -- Displays a short summary of the current installer state and
         -- options
      local
         i: INTEGER
         c_mode: C_MODE
      do
         page_line := 1

         page_string(once "%N---------------------------------------------------------------------------%N   Configuration file name: ")
         page_string(seconf)
         page_string(once "%N%N   Operating system: ")
         page_string(system_name)
         page_string(once "%N   Bin directory:    ")
         page_string(bin_directory)
         page_string(once "%N   Sys directory:    ")
         page_string(sys_directory)
         page_string(once "%N   Short directory:  ")
         page_string(short_directory)
         page_char('%N')
         from
            i := c_modes.lower
         until
            i > c_modes.upper
         loop
            c_mode := c_modes.item(i)
            if i > c_modes.lower then
               page_char('%N')
            end
            page_string(once "%N   C mode: ")
            page_string(c_mode.name)
            page_string(once "%N      C compiler type: ")
            page_string(c_mode.c_compiler_type)
            if c_mode.c_compiler_path /= Void then
               page_string(once "%N      C compiler path: ")
               page_string(c_mode.c_compiler_path)
            end
            if c_mode.c_compiler_options /= Void then
               page_string(once "%N      C compiler options: ")
               page_string(c_mode.c_compiler_options)
            end
            if c_mode.c_linker_path /= Void then
               page_string(once "%N      C linker path: ")
               page_string(c_mode.c_linker_path)
            end
            if c_mode.c_linker_options /= Void then
               page_string(once "%N      C linker options: ")
               page_string(c_mode.c_linker_options)
            end
            if c_mode.cpp_compiler_type /= Void and then c_mode.cpp_compiler_type /= fz_none then
               page_string(once "%N      C++ compiler type: ")
               page_string(c_mode.cpp_compiler_type)
               if c_mode.cpp_compiler_path /= Void then
                  page_string(once "%N      C++ compiler path: ")
                  page_string(c_mode.cpp_compiler_path)
               end
               if c_mode.cpp_compiler_options /= Void then
                  page_string(once "%N      C++ compiler options: ")
                  page_string(c_mode.cpp_compiler_options)
               end
               if c_mode.cpp_linker_path /= Void then
                  page_string(once "%N      C++ linker path: ")
                  page_string(c_mode.cpp_linker_path)
               end
               if c_mode.cpp_linker_options /= Void then
                  page_string(once "%N      C++ linker options: ")
                  page_string(c_mode.cpp_linker_options)
               end
            end
            if c_mode.smarteiffel_options /= Void then
               page_string(once "%N      SmartEiffel options: ")
               page_string(c_mode.smarteiffel_options)
            end
            i := i + 1
         end
         if extra_loadpath_keys /= Void then
            page_char('%N')
            from
               i := extra_loadpath_keys.lower
            until
               i > extra_loadpath_keys.upper or else extra_loadpath_keys.item(i).is_empty
            loop
               page_string(once "%N   ")
               page_string(extra_loadpath_keys.item(i))
               page_string(once ": ")
               page_string(extra_loadpath_items.item(i))
               i := i + 1
            end
         end
         if default_c_compiler /= Void then
            page_string(once "%N   Default C compiler: ")
            page_string(default_c_compiler)
         else
            page_string(once "%N   The default C compiler could not be determined.")
         end
         page_char('%N')
         io.put_string(once "Type <Enter> to go back to the menu: ")
         read_line
      end

   page_line: INTEGER

   page_string(s: STRING) is
      local
         i: INTEGER; s0: STRING
      do
         if s = Void then
            s0 := fz_conf_undefined
         else
            s0 := s
         end
         from
            i := 1
         until
            i > s0.count
         loop
            page_char(s0.item(i))
            i := i + 1
         end
      end

   page_char(c: CHARACTER) is
      do
         io.put_character(c)
         if c = '%N' then
            page_line := page_line + 1
            if page_line = 25 then
               io.put_string(once "--press <Enter> for more--")
               read_line
               page_line := 1
            end
         end
      end

   write_config is
      local
         i: INTEGER
         c_mode: C_MODE
      do
         if file_tools.is_readable(seconf) then
            tmp_buffer.copy(seconf)
            tmp_buffer.extend('~')
            io.put_string(once "Renaming ")
            io.put_string(seconf)
            io.put_string(once " to ")
            io.put_string(tmp_buffer)
            io.put_new_line
            file_tools.rename_to(seconf, tmp_buffer)
         end
         open_seconf
         if not tfw.is_connected then
            io.put_string(once "%N*** There was an error while trying to %
                               %write the configuration file. Please verify %
                               %its name.%N%N")
            default_main_action := main_action_define_variables
         else
            tfw.put_string(once "{
-- This is the configuration file of SmartEiffel, generated by the
-- SmartEiffel installer.
-- If you have any problems or questions, please:
--   - either look at the SmartEiffel site (http://SmartEiffel.loria.fr)
--   - or contact the SmartEiffel team (SmartEiffel@loria.fr)
-- ======================================================================= --

            }")

            tfw.put_string(once "[General]%N")
            tfw.put_string(once "{

-- This section contains some general-purpose keys. They describe how is the
-- SmartEiffel distribution arranged, and on which operating system it was
-- installed.

-- The 'bin' key is the path to the directory that contains the SmartEiffel
-- directory. It is used by 'compile' to find 'compile_to_c'.

-- The 'sys' directory is used to find the C and Java files used by the
-- compilers.

-- The 'short' directory is used by the 'short' utility to fotmat the output.

-- The 'os' key tells on which system SmartEiffel is installed on.

-- At last, 'tag' gives the version of install configuration (used only by the
-- installer)


            }")
            tfw.put_string(once "bin: ")
            tfw.put_string(bin_directory)
            tfw.put_new_line
            tfw.put_string(once "sys: ")
            tfw.put_string(sys_directory)
            tfw.put_new_line
            tfw.put_string(once "short: ")
            tfw.put_string(short_directory)
            tfw.put_new_line
            tfw.put_string(once "os: ")
            tfw.put_string(system_name)
            tfw.put_new_line
            tfw.put_string(once "tag: ")
            tfw.put_string(install_tag)
            tfw.put_new_line
            if extra_loadpath_keys /= Void then
               tfw.put_new_line
               tfw.put_string(once "[Loadpath]%N")
               tfw.put_string(once "{

-- This section contains the default loadpaths used by this SmartEiffel
-- installation.

-- The key is a mere description and serves no other purpose,

-- The value of the key is the path to a loadpath file.

-- Note that the loadpath files ar read in the order given below.


               }")
               from
                  i := extra_loadpath_keys.lower
               until
                  i > extra_loadpath_keys.upper or else extra_loadpath_keys.item(i).is_empty
               loop
                  tfw.put_string(extra_loadpath_keys.item(i))
                  tfw.put_string(once ": ")
                  tfw.put_string(extra_loadpath_items.item(i))
                  tfw.put_new_line
                  i := i + 1
               end
            end
            tfw.put_string(once "{


-- ======================================================================= --

-- Below are the "C mode" sections. Each C mode describes which C compiler must
-- be called, with which options, which linker, and so on. The keys are
-- described below.

-- The first sections (boost, ..., debug_check) are by default used in
-- conjunction with the corresponding SmartEiffel check level. This behaviour
-- may be changed by using the -c_mode flag.

-- The recognized keys in each section are:

-- 'compiler_type', which tells which is the compiler type to use

-- 'compiler_path', which gives the path to the compiler executable

-- 'compiler_options', which gives some options to the compiler

-- 'linker_path', which gives the path to the linker executable (not used in
--  -no_split mode)

-- 'linker_options', which gives some options for the linker (not used in
--  -no_split mode)

-- 'smarteiffel_options', which gives some extra SmartEiffel options to take
--  into account


            }")
            from
               i := c_modes.lower
            until
               i > c_modes.upper
            loop
               c_mode := c_modes.item(i)
               tfw.put_new_line
               tfw.put_character('[')
               tfw.put_string(c_mode.name)
               tfw.put_string(once "]%N")
               write_optional_key(fz_conf_compiler_type,        c_mode.c_compiler_type)
               write_optional_key(fz_conf_compiler_path,        c_mode.c_compiler_path)
               write_optional_key(fz_conf_compiler_options,     c_mode.c_compiler_options)
               write_optional_key(fz_conf_linker_path,          c_mode.c_linker_path)
               write_optional_key(fz_conf_linker_options,       c_mode.c_linker_options)
               write_optional_key(fz_conf_cpp_compiler_type,    c_mode.cpp_compiler_type)
               write_optional_key(fz_conf_cpp_compiler_path,    c_mode.cpp_compiler_path)
               write_optional_key(fz_conf_cpp_compiler_options, c_mode.cpp_compiler_options)
               write_optional_key(fz_conf_cpp_linker_path,      c_mode.cpp_linker_path)
               write_optional_key(fz_conf_cpp_linker_options,   c_mode.cpp_linker_options)
               write_optional_key(fz_conf_smarteiffel_options,  c_mode.smarteiffel_options)
               i := i + 1
            end
            tfw.disconnect
         end
      end

   write_optional_key(key, value: STRING) is
      do
         if value /= Void then
            tfw.put_string(key)
            tfw.put_string(once ": ")
            tfw.put_string(value)
            tfw.put_new_line
         end
      end

   open_seconf is
         -- Opens tfw on the seconf file. Creates all the necessary directories.
      do
         if seconf /= fz_conf_undefined then
            basic_directory.compute_parent_directory_of(seconf)
            if not basic_directory.last_entry.is_empty then
               create_parent_directories_of(basic_directory.last_entry)
            end
            tfw.connect_to(seconf)
            if not tfw.is_connected then
               fatal_problem_description_start
               std_error.put_string(once "Could not open ")
               std_error.put_string(seconf)
               std_error.put_string(".%N")
               fatal_problem_description_end
            end
         end
      end

   create_parent_directories_of(path: STRING) is
      require
         not path.is_empty
      local
         p: STRING
      do
         create p.copy(path) -- *** memory leak
         directory.scan(p)
         if not directory.last_scan_status then
            basic_directory.compute_parent_directory_of(path)
            if basic_directory.last_entry.count > 0 then
               create_parent_directories_of(basic_directory.last_entry)
            else
               -- could not compute the parent directory
               fatal_problem_description_start
               std_error.put_string(once "Could not compute the parent directory of ")
               std_error.put_string(path)
               std_error.put_string(once ".%N")
               fatal_problem_description_end
            end
         end
         directory.scan(p)
         check
            directory.last_scan_status
         end
      end

   set_seconf is
         -- Set the environment variable SECONF
      local
         s: SYSTEM
      do
         s.set_environment_variable(fz_seconf, seconf)
      end

   compile_all is
         -- Put the program in the same conditions as with the old installer,
         -- in order to use its features.
      local
         install_dir, germ_dir, install_compiler, compiler_options, linker_options, compile_to_c, obj, s: STRING
         i: INTEGER
         has_germ_dir, found, ok_bin_dir: BOOLEAN
      do
         install_dir := once "install"
         germ_dir := once "germ"
         has_germ_dir := True
         directory.scan_current_working_directory
         if not directory.has(install_dir) then
            has_germ_dir := False
         else
            directory.scan_subdirectory(install_dir)
            if not directory.has(germ_dir) then
               has_germ_dir := False
            else
               directory.scan_subdirectory(germ_dir)
            end
         end
         if not has_germ_dir then
            fatal_problem_description_start
            std_error.put_string(once "The install/germ directory does not exist!%N%
                                      %Did you use a SmartEiffel archive from Loria?%N%
                                      %If not, you can download it at http://SmartEiffel.loria.fr%N%
                                      %and start the installation again.")
            fatal_problem_description_end
         end
         tmp_buffer.copy(directory.path)
         create germ_directory.copy(tmp_buffer)
         if basic_directory.is_connected then
            basic_directory.disconnect
         end

         io.put_string(once "%N%N---------------------------------------------------------------------------%N%N")
         io.put_string(once "You are about to start the SmartEiffel installation.%N%
                            %Just one last thing, though...%N")

         from
         until
            found
         loop
            io.put_string(once "%NThe default installation C mode is ")
            io.put_string(install_c_mode)
            io.put_string(once ".%NPlease either type <Enter> to go on, or choose a new C mode now.%N")
            read_line
            if entry_buffer.is_empty then
               found := True
               from
                  i := c_modes.lower
                  found := False
               variant
                  c_modes.upper - i
               until
                  found
               loop
                  if c_modes.item(i).name.is_equal(install_c_mode) then
                     install_compiler := c_modes.item(i).c_compiler_type
                     found := True
                  else
                     i := i + 1
                  end
               end
            else
               from
                  i := c_modes.lower
                  found := False
               until
                  found or else i > c_modes.upper
               loop
                  found := c_modes.item(i).name.is_equal(entry_buffer)
                  if found then
                     install_c_mode.copy(entry_buffer)
                     install_compiler := c_modes.item(i).c_compiler_type
                  else
                     i := i + 1
                  end
               end
               if not found then
                  io.put_string(once "%N*** Please choose an existant C mode.%N")
               end
            end
         end

         c_compiler_name := install_compiler
         compiler_options := c_modes.item(i).c_compiler_options
         if compiler_options = Void then
            compiler_options := once ""
         end
         linker_options := c_modes.item(i).c_linker_options
         if linker_options = Void then
            linker_options := once ""
         end

         -- Verify the bin directory...
         ok_bin_dir := True
         basic_directory.change_current_working_directory(noenv_bin_directory)
         if basic_directory.last_entry.is_empty then
            -- The `bin' directory does not exist; let's create it.
            if not basic_directory.create_new_directory(noenv_bin_directory) then
               std_error.put_string(once "*** Could not create the bin directory: aborting.%N")
               ok_bin_dir := False
            else
               basic_directory.change_current_working_directory(noenv_bin_directory)
            end
         end

         if ok_bin_dir then
            io.put_string(once "%NSummary of gathered options:%
                               %%N  - C mode:     ")
            io.put_string(install_c_mode)
            io.put_string(once "%N  - C compiler: ")
            io.put_string(install_compiler)
            io.put_string(once "%N  - C options:  (compiler) ")
            io.put_string(compiler_options)
            io.put_string(once "%N                (linker)   ")
            io.put_string(linker_options)
            io.put_string(once "%N%NHere we go!%N%N")

            -- Prepare system_tools to install SmartEiffel
            system_tools.set_install_compiler(install_compiler,
                                              c_modes.item(i).c_compiler_path,
                                              c_modes.item(i).c_linker_path)
            system_tools.c_compiler_options.copy(compiler_options)
            system_tools.c_linker_options.copy(linker_options)

            -- Now we will install SmartEiffel. The process has been
            -- rightfully described by Philippe on SmartZilla, BUG106.
            -- Here it is:

            -- Compile compile_to_c given with the distrib...
            basic_directory.change_current_working_directory(germ_directory)
            compile_to_c := once "compile_to_c"
	    system_tools.add_lib_math_do_it_again
            split_mode_c_compile(compile_to_c)
            move_executable_for(compile_to_c)
            basic_directory.connect_to(germ_directory)
            if basic_directory.is_connected then
               from
                  obj := system_tools.object_suffix
                  basic_directory.read_entry
               until
                  basic_directory.end_of_input
               loop
                  s := once "                                "
                  s.copy(basic_directory.last_entry)
                  if s.has_suffix(obj) then
                     basic_directory.compute_file_path_with(germ_directory, s)
                     if not basic_directory.last_entry.is_empty then
                        s.copy(basic_directory.last_entry)
                        remove_file(s)
                     end
                  end
                  basic_directory.read_entry
               end
            end
            basic_directory.disconnect

            -- Now go to the bin directory...
            basic_directory.change_current_working_directory(noenv_bin_directory)

            -- Compile compile_to_c again (this one is for us developpers),
            -- then "compile" and "clean" in order to compile all the tools,
            -- and clean "compile" and "clean"...
            first_pass_compile

            -- And compile all the remaining tools.
            second_pass_compile
         end

         restore_current_working_directory
      end

   split_mode_c_compile(name: STRING) is
         -- Assume the current working directory is `germ_directory',
         -- compile some command `name' produced without the "-no_split" flag.
         -- BEWARE, it dose not mean that -no_split is not set; it's just not
         -- *given* (it can be implied by the chosen C mode)
      local
         entry, cmd: STRING; i, max: INTEGER
      do
         ace.set_executable_name(name)
         entry := once ""
         entry.copy(name)
         entry.append(once ".c")
         directory.scan_current_working_directory
         if directory.has(entry) then
            -- A not split file is preferred to the split ones
            no_split_mode_c_compile(name)
         else
            from
               i := directory.lower
            until
               i > directory.upper
            loop
               entry := directory.item(i).twin
               open_vms_entry_patch(entry)
               if not entry.has_prefix(name) then
               elseif not entry.has_suffix(once ".c") then
               else
                  max := max + 1
                  cmd := system_tools.split_mode_c_compiler_command(entry)
                  io.put_string(cmd)
                  io.put_new_line
                  echo.system_call(cmd)
               end
               i := i + 1
            end
            if max > 0 then
               cmd := system_tools.split_mode_linker_command(name,max)
               io.put_string(cmd)
               io.put_new_line
               echo.system_call(cmd)
               system_tools.remove_other_extra_files(name)
            end
         end
      end

   no_split_mode_c_compile(name: STRING) is
         -- Assume the current working directory is `germ_directory', compile some
         -- command `name' produced with the "-no_split" flag.
      local
         c_name, cmd: STRING
      do
         ace.set_executable_name(name)
         io.put_string(once "C compiling no-split ")
         io.put_string(name)
         io.put_new_line
         c_name := name.twin
         c_name.append(once ".c")
         ace.set_executable_name(name)
         cmd := system_tools.no_split_mode_command(c_name)
         io.put_string(cmd)
         io.put_new_line
         echo.system_call(cmd)
      end

   compile_arguments(extra_args: STRING): STRING is
      do
         Result := once "                        "
         if (system_tools.lcc_win32).same_as(c_compiler_name) then
            Result.copy(once "-boost") -- See (*).
         else
            Result.copy(once "-boost -no_gc")
         end
         if not install_c_mode.is_equal(fz_boost) then
            Result.append(once " -c_mode ")
            Result.append(install_c_mode)
         end
         if extra_args /= Void then
            Result.extend(' ')
            Result.append(extra_args)
         end

         -- (*): because the bad/slow Microsoft malloc is used, we
         -- get better results when the GC is on (thus the -no_gc
         -- flag is not used).
      end

   first_pass_compile is
      local
         i: INTEGER
         args, item: STRING
      do
         from
            i := 1
         until
            i > first_pass_command_list.count
         loop
            item := first_pass_command_list.item(i)
            if no_split_command_list.has(item) then
               args := compile_arguments(once "-no_split")
               call_compile_to_c(args, item)
               no_split_mode_c_compile(item)
            else
               check splitted_command_list.has(item) end
               args := compile_arguments(Void)
               call_compile_to_c(args, item)
               split_mode_c_compile(item)
            end
            i := i + 1
         end
         from
            i := 1
         until
            i > first_pass_command_list.count
         loop
            item := first_pass_command_list.item(i)
            call_clean(item)
            i := i + 1
         end
      end

   second_pass_compile is
      local
         i: INTEGER
         args, item: STRING
      do
         args := compile_arguments(once "-clean -no_split")
         from
            i := 1
         until
            i > no_split_command_list.count
         loop
            item := no_split_command_list.item(i)
            if not first_pass_command_list.has(item) then
               call_compile(args, item)
            end
            i := i + 1
         end

         args := compile_arguments(once "-clean")
         from
            i := 1
         until
            i > splitted_command_list.count
         loop
            item := splitted_command_list.item(i)
            if not first_pass_command_list.has(item) then
               call_compile(args, item)
            end
            i := i + 1
         end
      end

   open_vms_entry_patch(entry: STRING) is
         -- Remove the strange ;123 version suffix of the OpenVMS system.
      require
         not entry.is_empty
      local
         done: BOOLEAN; s: STRING
      do
         if (once "OpenVMS").same_as(system_name) then
            from
               -- Because the system uses uppercase only:
               entry.to_lower
               s := entry.twin
            until
               done
            loop
               if s.count = 0 then
                  done := true
               elseif s.last = ';' then
                  s.remove_last(1)
                  entry.copy(s)
                  done := true
               elseif s.last.is_decimal_digit then
                  s.remove_last(1)
               else
                  done := true
               end
            end
         end
      end

   move_executable_for(name: STRING) is
         -- Move the executable for command `name' from `germ_directory'
         -- to in `bin_directory'.
      local
         executable, old_path, new_path: STRING
      do
         executable := tmp_buffer
         executable.copy(name)
         system_tools.add_x_suffix(executable)
         basic_directory.compute_file_path_with(germ_directory,executable)
         old_path := once ""
         old_path.copy(basic_directory.last_entry)
         basic_directory.compute_file_path_with(noenv_bin_directory,executable)
         new_path := once ""
         new_path.copy(basic_directory.last_entry)
         if not file_exists(old_path) then
            fatal_problem_description_start
            std_error.put_string(once "Unable to find executable %"")
            std_error.put_string(old_path)
            std_error.put_string(once "%".%N")
            fatal_problem_description_end
         end
         if not (system_tools.elate_system).same_as(system_name) then
            echo.file_renaming(old_path, new_path)
         else
            -- Use the `cpt' command to copy the command from the old to the
            -- new location.  we can't copy tools in Elate with a normal copy
            -- in the filesystem:
            command.copy(once "cpt ")
            command.append(old_path)
            command.extend(' ')
            command.append(new_path)
            echo.system_call(command)
         end
      end

   call_compile(options, name: STRING) is
      local
         x_name: STRING
      do
         x_name := once ""
         x_name.copy(name)
         system_tools.add_x_suffix(x_name)

         command.clear
         system_tools.command_path_in(command, once "compile")
         command.extend(' ')
         command.append(options)
         command.append(once " -o ")
         command.append(x_name)
         command.extend(' ')
         command.append(name)
         io.put_string(command)
         io.put_new_line
         echo.system_call(command)
      end

   call_compile_to_c(options, name: STRING) is
      local
         x_name: STRING
      do
         x_name := once ""
         x_name.copy(name)
         system_tools.add_x_suffix(x_name)

         command.clear
         system_tools.command_path_in(command, once "compile_to_c")
         command.extend(' ')
         command.append(options)
         command.append(once " -o ")
         command.append(x_name)
         command.extend(' ')
         command.append(name)
         io.put_string(command)
         io.put_new_line
         echo.system_call(command)
      end

   call_clean(name: STRING) is
      do
         command.clear
         system_tools.command_path_in(command, once "clean")
         command.extend(' ')
         command.append(name)
         io.put_string(command)
         io.put_new_line
         echo.system_call(command)
      end

   fatal_problem_description_start is
      do
         std_error.put_string(once
         "%N*** Fatal problem during installation of SmartEiffel.%N%
           %    Read carefully the following information before starting%N%
           %    again the installation.%N%
           %***************************************************************%N")
      end

   fatal_problem_description_end is
      do
         std_error.put_string(once
         "***************************************************************%N%
         %Fix the previously described problem and launch again the,%N%
         %installation, or contact the SmartEiffel team:%N%
         %SmartEiffel@loria.fr%N")
         restore_current_working_directory
         install_exit(exit_failure_code)
      end

   install_exit(exit_code: INTEGER) is
         -- To exit properly from the `install' program.
      do
         if system_name = Void or else (once "Windows").same_as(system_name) then
            -- To avoid the terminal window closing before the user has read
            -- the last messages.
            io.put_string(once "Type <Enter> to continue.%N")
            io.read_character
         end
         die_with_code(exit_code)
      end

feature {NONE} -- Exit:

   confirm_exit is
      do
         if installed then
            stop := True
         else
            io.put_string(once "%N---------------------------------------------------------------------------%N%N%
                               %You did not install SmartEiffel. Are you sure you want to exit? [y|N] ")
            read_line
            entry_buffer.to_lower
            stop := entry_buffer.count > 0 and then entry_buffer.first = 'y'
         end
      end

   exit is
      do
         io.put_string(once "%N---------------------------------------------------------------------------%N%N")
         if installed then
            io.put_string(once "Thank you for installing SmartEiffel. Enjoy!%N%N")
         else
            io.put_string(once "SmartEiffel was not properly installed.%N%
                               %Please run the installer again to fix the installation.%N%N")
         end
      end

feature {NONE} -- Misc:

   restore_current_working_directory is
      do
         if cwd /= Void then
            basic_directory.change_current_working_directory(cwd)
         end
      end

   read_line is
      do
         entry_buffer.clear
         io.read_line_in(entry_buffer)
         entry_buffer.left_adjust
         entry_buffer.right_adjust
      end

   set_system_name(name: STRING) is
      local
         sysname: STRING
         i: INTEGER
      do
         sysname := name
         if not system_tools.system_list.fast_has(sysname) then
            i := system_tools.system_list.index_of(name)
            if system_tools.system_list.valid_index(i) then
               sysname := system_tools.system_list.item(i)
            else
               sysname := fz_conf_undefined
            end
         end
         if sysname /= fz_conf_undefined then
            system_name := sysname
            system_tools.set_system_name(sysname)
         end
      end

   rc_template(rcfile, rcpath: STRING): INI_PARSER is
         -- An ini parser to parse the compiler templates. The "good" parser
         -- is selected, or created, from the `rcpath'.
         -- Returns Void if the file is not found.
      do
         if templates.has(rcfile) then
            Result := templates.at(rcfile)
         elseif rcpath /= Void then
            parser_buffer.load_file(rcpath)
            if parser_buffer.is_ready then
               create Result
               Result.a_inifile
            end
            templates.put(Result, rcfile.twin)
         end
      end

   template(compiler: STRING): INI_PARSER is
         -- An ini parser to parse the compiler templates. The "good" parser
         -- is selected, or created, depending on `compiler'.
         -- Returns Void if `compiler' is Void.
      local
         path: STRING
      do
         path := rc_compiler(compiler)
         if path /= Void then
            Result := rc_template(path, Void)
         end
      end

   rc_compiler(compiler: STRING): STRING is
         -- The name of the rc file (without the ".rc" suffix), if unique;
         -- Void otherwise.
      do
         if compiler /= Void then
            if c_compiler_rc_map.occurrences(compiler) = 1 then
               Result := c_compiler_rc_map.key_at(compiler)
            elseif cpp_compiler_rc_map.occurrences(compiler) = 1 then
               Result := cpp_compiler_rc_map.key_at(compiler)
            end
         end
      end

   install_path: STRING is
      -- The path to the "install" subdirectories, which contains the
      -- templates for the compilers.
      once
         basic_directory.connect_to_current_working_directory
         if basic_directory.is_connected then
            create Result.copy(basic_directory.last_entry)
            basic_directory.disconnect
            basic_directory.compute_subdirectory_with(Result, fz_install)
            Result.copy(basic_directory.last_entry)
         end
      end

feature {NONE} -- Buffers:

   tmp_buffer: STRING is
      once
         create Result.make(16)
      end

   entry_buffer: STRING is
      once
         create Result.make(16)
      end

   seconf_buffer: STRING is
      once
         create Result.make(16)
      end

   directory: DIRECTORY is
      once
         create Result.make
      end

   levels: ASSERTION_LEVEL_NUMBERING is
      do
         create Result
      end

   command: STRING is
      once
         !!Result.make(512)
      end

   tfw: TEXT_FILE_WRITE is
      once
         !!Result.make
      end

   tfr: TEXT_FILE_READ is
      once
         !!Result.make
      end

   templates: DICTIONARY[INI_PARSER, STRING] is
      once
         create Result.make
      end

   first_pass_command_list: ARRAY[STRING] is
      once
         Result := <<
                     "compile_to_c"
                     "compile"
                     "clean"
                   >>
      end

   no_split_command_list: ARRAY[STRING] is
         -- Small commands which can be compiled with the -no_split flag.
      once
         Result := <<
                     "compile"
                     "clean"
                     "finder"
                     "ace_check"
                     "print_jvm_class"
                   >>
      end

   splitted_command_list: ARRAY[STRING] is
         -- Small commands which can be compiled with the -no_split flag.
      once
         Result := <<
                     "compile_to_c"
                     "short"
                     "class_check"
                     "pretty"
                     "compile_to_jvm"
                   >>
      end

   windows_standard_directories: ARRAY[STRING] is
         -- De-facto standard places where Windows is installed. I am too
         -- imaginative?
      once
         Result := <<
                     "C:\WINDOWS"
                     "C:\WINNT"
                     "C:\WIN95"
                     "C:\WIN98"
                     "C:\WINME"
                     "C:\WIN2K"
                     "C:\WIN2000"
                     "C:\WINXP"
                   >>
      end

   c_compiler_rc_map: DICTIONARY[STRING, STRING] is
         -- Keys: "reduced" RC file names
         -- Values: compilers
      once
         create Result.make
      end

   cpp_compiler_rc_map: DICTIONARY[STRING, STRING] is
         -- Keys: "reduced" RC file names
         -- Values: compilers
      once
         create Result.make
      end

   c_compiler_list: ARRAY[STRING] is
      once
         create Result.make(1, 0)
         c_compiler_rc_map.item_map_in(Result)
      end

   cpp_compiler_list: ARRAY[STRING] is
      once
         create Result.make(1, 0)
         cpp_compiler_rc_map.item_map_in(Result)
         Result.add_first(fz_none)
      end

invariant

   not echo.verbose

end
