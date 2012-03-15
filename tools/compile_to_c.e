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
class COMPILE_TO_C
   --
   -- The `compile_to_c' command.
   --

inherit
   COMMAND_LINE_TOOLS

creation make

feature {COMPILE_TO_C_VISITOR}

   accept(visitor: COMPILE_TO_C_VISITOR) is
      do
         visitor.visit_compile_to_c(Current)
      end

feature

   command_name: STRING is "compile_to_c"

   command_line_help_summary: STRING is "[
      Usage: compile_to_c [options] <RootClass> <RootProcedure> ...
         or: compile_to_c [options] <ACEfileName>.ace

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

      Class lookup:
        -loadpath <file>    Specify an extra loadpath file to read

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
         -- Command line parsing has two passes:
         -- 1, options are parsed;
         -- 2, the extra options are added
      local
         argc: INTEGER
         string_command_line: STRING_COMMAND_LINE
      do
         eiffel_parser.set_drop_comments
         string_command_line.set_command_name(command_name)
         argc := argument_count
         if argc < 1 then
            system_tools.bad_use_exit(Current)
         end
         search_for_verbose_flag
	 search_for_cc_flag(argc)
	 if ace_file_mode then
            system_tools.add_smarteiffel_c_mode_options
         else
            -- First pass:
            parse_command_line(1)

            -- Before the second pass, we set the C mode; it is used later on
            -- to correctly recognize the "extra arguments". Options are
            -- parsed again: that is not very efficient (to say the least),
            -- but it works.
            ace.set_default_level
            system_tools.add_smarteiffel_c_mode_options

            -- Second pass:
            parse_command_line(2)

            -- Now finish the work.
	    ace.command_line_parsed(command_name)
	 end
         smart_eiffel.compile_to_c
         id_provider.disk_save
         string_aliaser.echo_information
      end

   parse_command_line(pass: INTEGER) is
      local
         argc, argi: INTEGER; arg: STRING
      do
         argc := argument_count
	 from
	    argi := 1
	 until
	    argi > argc
	 loop
	    arg := argument(argi)
	    if is_help_flag(arg) then
	       argi := argi + 1
	    elseif is_case_insensitive_flag(arg) then
	       argi := argi + 1
	    elseif is_no_style_warning_flag(arg) then
	       argi := argi + 1
	    elseif is_no_warning_flag(arg) then
	       argi := argi + 1
	    elseif is_version_flag(arg) then
	       argi := argi + 1
	    elseif is_verbose_flag(arg) then
	       argi := argi + 1
	    elseif is_a_compilation_level_flag(arg) then
	       argi := argi + 1
	    elseif is_cecil_flag(arg,argi,argc) then
	       argi := argi + 2
	    elseif is_o_flag(arg,argi,argc) then
	       argi := argi + 2
	    elseif flag_match(fz_no_main,arg) then
	       ace.set_no_main
	       argi := argi + 1
	    elseif flag_match(once "no_gc",arg) then
	       gc_handler.no_gc
	       argi := argi + 1
	    elseif flag_match(fz_gc_info,arg) then
	       gc_handler.set_info_flag
	       argi := argi + 1
	    elseif is_safety_check_flag(arg) then
	       argi := argi + 1
	    elseif is_manifest_string_trace_flag(arg) then
	       argi := argi + 1
	    elseif flag_match(fz_no_strip,arg) then
	       system_tools.set_no_strip
	       argi := argi + 1
	    elseif flag_match(fz_no_split,arg) then
	       ace.set_no_split(true)
	       argi := argi + 1
	    elseif is_trace_flag(arg) then
	       argi := argi + 1
	    elseif flag_match(fz_wedit,arg) then
	       ace.set_wedit(true)
	       argi := argi + 1
	    elseif is_high_memory_compiler(arg) then
	       argi := argi + 1
            elseif flag_match(fz_compact,arg) then
               cpp.set_compact(True)
               argi := argi + 1
            elseif flag_match(fz_loadpath,arg) then
               if pass = 1 then
                  -- C compiler choice is only parsed in pass 1
                  if argi < argc then
                     system_tools.add_loadpath_file(argument(argi + 1))
                     argi := argi + 2
                  else
                     echo.w_put_string(command_name)
                     echo.w_put_string(once ": missing loadpath file path after -loadpath flag.%N")
                     die_with_code(exit_failure_code)
                  end
               else
                  argi := argi + 2
               end
            elseif flag_match(fz_c_mode,arg) then
               if pass = 1 then
                  -- c_mode is only parsed in pass 1
	          if argi < argc then
                     system_tools.set_alternate_c_mode(argument(argi + 1))
                     argi := argi + 2
                  else
                     echo.w_put_string(command_name)
                     echo.w_put_string(once ": missing C mode name after -c_mode flag.%N")
                     die_with_code(exit_failure_code)
                  end
               else
                  argi := argi + 2
               end
	    elseif flag_match(fz_cc,arg) then
	       if argi < argc or else pass /= 1 then
	          argi := argi + 2
	       else
	          echo.w_put_string(command_name)
	          echo.w_put_string(
	             ": missing compiler name after -cc flag.%N")
	          die_with_code(exit_failure_code)
	       end
            elseif pass = 2 then
               -- extra args are only parsed in pass 2
               if argi < argc then
                  argi := system_tools.extra_arg(arg,argi,argument(argi + 1))
               else
                  argi := system_tools.extra_arg(arg,argi,Void)
               end
            else
               argi := argi + 1
            end
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
	     is_verbose_flag(arg))
	  then
	    Result := true
	 end
      end

   valid_argument_for_ace_mode: STRING is
      "Only the flags -verbose, -version, and -help are allowed in ACE%N%
      %file mode.%
      %%N"

end -- COMPILE_TO_C
