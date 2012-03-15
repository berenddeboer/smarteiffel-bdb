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
class COMPILE
   --
   -- The `compile' command.
   --

inherit
   COMMAND_LINE_TOOLS

creation make

feature {COMPILE_VISITOR}

   accept(visitor: COMPILE_VISITOR) is
      do
         visitor.visit_compile(Current)
      end

feature

   command_name: STRING is "compile"

   command_line_help_summary: STRING is "[
      Usage: compile [options] <RootClass> <RootProcedure> ...
         or: compile [options] <ACEfileName>.ace
      For information about and examples of ACE files, have a look
      in the SmartEiffel/tutorial/ace directory.

      Most of the following options are not available when using
      an ACE file.

      Option summary:

      Information:
        -help               Display this help information
        -version            Display SmartEiffel version information
        -verbose            Display detailed information about what the
                             compiler is doing

      Warning levels:
        -case_insensitive   Make class and feature names case-insensitive
        -no_style_warning   Don't print warnings about style violations
        -no_warning         Don't print any warnings (implies -no_style_warning)

      Optimization and debugging levels (specify at most one; default is -all_check):
        -boost              Enable all optimizations,
                             but disable all run-time checks
        -no_check           Enable Void target and system-level checking
        -require_check      Enable precondition checking (implies -no_check)
        -ensure_check       Enable postcondition checking (implies -require_check)
        -invariant_check    Enable class invariant checking (implies -ensure_check)
        -loop_check         Enable loop variant and invariant checking
                             (implies -invariant_check)
        -all_check          Enable 'check' blocks (implies -loop_check)
        -debug_check        Enable 'debug' blocks (implies -all_check)

      C compilation and run-time system:
        -cc <command>       Specify the C compiler to use
        -c_mode <C mode>    Specify a C mode to use. This option is incompatible
                             with -cc
        -cecil <file>       Take CECIL information from <file>
                             (may be used more than once)
        -o <file>           Put the executable program into <file>
        -no_main            Don't include a main() in the generated executable
        -no_gc              Disable garbage collection
        -gc_info            Enable status messages from the garbage collector
        -no_strip           Don't run 'strip' on the generated executable
        -no_split           Generate only one C file
        -sedb               Enable sedb, the SmartEiffel debugger
        -manifest_string_trace
                            Enable the trace support to track non-once
                            manifest string creation
        -wedit              Include support for the Wedit debugger
        -clean              Run the 'clean' command at the end
        -loadpath <file>    Specify an extra loadpath file to read
        -compact            Make the generated code much more compact than the
                            normally rather verbose C code

      Miscellaneous:
        -high_memory_compiler
                            Allow the compile_to_c to use more memory; if you
                            have enough physical memory, compilation should
                            be faster (note: generated C code is not affected)

   ]"

feature {NONE}

   make is
      local
         argc, argi: INTEGER
         arg, make_script_name: STRING
      do
         argc := argument_count
         if argc < 1 then
            system_tools.bad_use_exit(Current)
         end
         search_for_verbose_flag
         search_for_cc_flag(argc)
         if ini_parser.section_has(fz_conf_general, once "c2c") then
            command.copy(ini_parser.section_item(fz_conf_general, once "c2c"))
         else
            system_tools.command_path_in(command,once "compile_to_c")
         end
	 if ace_file_mode then
	    from
	       argi := 1
	    until
	       argi > argc
	    loop
	       arg := argument(argi)
	       if is_clean_flag(arg) then
	       elseif is_help_flag(arg) then
	       elseif is_version_flag(arg) then
	       else
		  compile_to_c_pass_argument(arg)
	       end
	       argi := argi + 1
	    end
	 else
            parse_command_line(1)
            ace.set_default_level
            system_tools.add_smarteiffel_c_mode_options
            parse_command_line(2)
	    ace.command_line_parsed(command_name)
	 end
         make_script_name := system_tools.new_make_script
         echo.system_call(command)
         system_tools.cygnus_bug(make_file,make_script_name)
         if not make_file.is_connected then
            echo.w_put_string(fz_01)
            echo.w_put_string(make_script_name)
            echo.w_put_string("%" not found. %
                                %Error(s) during `compile_to_c'.%N")
            die_with_code(exit_failure_code)
         end
         echo.put_string(once "C compiling using %"")
         echo.put_string(make_script_name)
         echo.put_string(once "%" command file.%N")
         from
            make_file.read_line
         until
            make_file.last_string.count = 0
         loop
            command.copy(make_file.last_string)
            echo.system_call(command)
            make_file.read_line
         end
         make_file.disconnect
	 system_tools.remove_make_script_and_other_extra_files
         if ace.clean then
            command.clear
            system_tools.command_path_in(command,once "clean")
	    if echo.verbose then
	       command.append(once " -verbose")
	    end
            command.extend(' ')
            command.append(make_script_name)
            echo.system_call(command)
         else
            echo.put_string(once "C code not removed.%N")
         end
         echo.put_string(fz_02)
      end

   parse_command_line(pass: INTEGER) is
      local
         arg, next_arg: STRING
         argc, argi: INTEGER
      do
         from
            argc := argument_count
            argi := 1
         until
            argi > argc
         loop
            arg := argument(argi)
            if is_help_flag(arg) then
               argi := argi + 1
            elseif is_version_flag(arg) then
               argi := argi + 1
            elseif is_clean_flag(arg) then
               argi := argi + 1
            elseif one_arg_flag(arg) then
               compile_to_c_pass_argument(arg)
               argi := argi + 1
               if argi <= argc then
                  arg := argument(argi)
                  compile_to_c_pass_argument(arg)
                  argi := argi + 1
               end
            elseif flag_match(once "c2c", arg) then
               if argi = argc then
                  echo.w_put_string(once "Argument awaited for -c2c.%N")
                  die_with_code(exit_failure_code)
               else
                  command.copy(argument(argi+1))
                  argi := argi + 2
               end
            elseif argi < argc then
               if pass = 2 then
                  compile_to_c_pass_argument(arg)
                  next_arg := argument(argi + 1)
                  argi := system_tools.extra_arg(arg,argi,next_arg)
                  if argument(argi - 1) = next_arg then
                     compile_to_c_pass_argument(next_arg)
                  end
               else
                  argi := argi + 1
               end
            else
               if pass = 2 then
                  compile_to_c_pass_argument(arg)
                  argi := system_tools.extra_arg(arg,argi,Void)
               else
                  argi := argi + 1
               end
            end
         end
      end

   compile_to_c_pass_argument(arg: STRING) is
      do
         command.extend(' ')
         command.append(arg)
      end

   make_file: TEXT_FILE_READ is
      once
         !!Result.make
      end

   command: STRING is
      once
         !!Result.make(256)
      end

   one_arg_flag(flag: STRING): BOOLEAN is
      do
	 if (fz_o.is_equal(flag)
	     or else
	     flag_match(fz_cc,flag)
	     or else
	     flag_match(fz_cecil,flag)
             or else
             flag_match(fz_loadpath,flag)
             or else
             flag_match(fz_c_mode,flag))
	  then
	    Result := True
	 end
      end

   is_valid_argument_for_ace_mode(arg: STRING): BOOLEAN is
      do
	 if (is_version_flag(arg)
	     or else
	     is_no_style_warning_flag(arg)
	     or else
	     is_no_warning_flag(arg)
	     or else
	     is_verbose_flag(arg)
	     or else
	     is_clean_flag(arg))
	  then
	    Result := true
	 end
      end

   valid_argument_for_ace_mode: STRING is
      "Only the -verbose, -version, -clean, and -help flags are allowed%N%
      %in ACE file mode.%N"

end -- COMPILE

