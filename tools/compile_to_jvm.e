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
class COMPILE_TO_JVM
   --
   -- The `compile_to_jvm' command.
   --

inherit
   COMMAND_LINE_TOOLS

creation make

feature {COMPILE_TO_JVM_VISITOR}

   accept(visitor: COMPILE_TO_JVM_VISITOR) is
      do
         visitor.visit_compile_to_jvm(Current)
      end

feature

   command_name: STRING is "compile_to_jvm"

   command_line_help_summary: STRING is "[
      Usage: compile_to_jvm [options] <Root-Class> <Root-Procedure>
         or: compile_to_jvm [options] <ACEfileName>.ace

      For information about and examples of ACE files, have a look
      in the SmartEiffel/tutorial/ace directory.

      Most of the following options are not available when using
      an ACE file.

      Option summary:

      Information:
        -help               Display this help information
        -version            Display SmartEiffel version information
        -verbose            Display detailed information about what the


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
        -all_check          Enable "check" blocks (implies -loop_check)
        -debug_check        Enable "debug" blocks (implies -all_check)

      Class lookup:
        -loadpath <file>    Specify an extra loadpath file to read

      Compilation and run-time system:
        -cecil <file>       Take CECIL information from <file>
                             (may be used more than once)
        -o <file>           Use <file> as the name of the output directory and the
                             name of the generated root class
        -sedb              Enable the internal debugger

      ]"

feature {NONE}

   make is
      local
         argc, argi: INTEGER; arg, executable_name: STRING
         string_command_line: STRING_COMMAND_LINE
      do
         eiffel_parser.set_drop_comments
         string_command_line.set_command_name(command_name)
         argc := argument_count
         if argc < 1 then
            system_tools.bad_use_exit(Current)
         end
         search_for_verbose_flag
	 if not ace_file_mode then
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
	       elseif is_safety_check_flag(arg) then
		  argi := argi + 1
	       elseif is_trace_flag(arg) then
		  argi := argi + 1
	       elseif is_cecil_flag(arg,argi,argc) then
		  argi := argi + 2
	       elseif is_o_flag(arg,argi,argc) then
		  argi := argi + 2
               elseif flag_match(fz_loadpath,arg) then
		  if argi < argc then
                     system_tools.add_loadpath_file(argument(argi + 1))
		     argi := argi + 2
		  else
		     echo.w_put_string(command_name)
		     echo.w_put_string(
		        ": missing loadpath file path after -loadpath flag.%N")
		     die_with_code(exit_failure_code)
		  end
	       elseif arg.item(1) /= '-' then
		  ace.set_root_class_name_using(arg)
		  argi := argi + 1
		  if argi <= argc then
		     arg := argument(argi)
		     if arg.item(1) /= '-' then
			ace.set_root_procedure_name(arg)
			argi := argi + 1
		     end
		  end
	       else
		  unknown_flag_exit(arg)
	       end
	    end
	    ace.command_line_parsed(command_name)
	 end
	 if ace.executable_name = Void then
	    executable_name := ace.root_class_name.twin
	    executable_name.to_lower
	    ace.set_executable_name(executable_name)
	 end
         smart_eiffel.compile_to_jvm
         string_aliaser.echo_information
      end

   is_valid_argument_for_ace_mode(arg: STRING): BOOLEAN is
      do
	 if (is_version_flag(arg)
	     or else
	     is_help_flag(arg)
	     or else
	     is_no_style_warning_flag(arg)
	     or else
	     is_no_warning_flag(arg)
	     or else
	     is_verbose_flag(arg))
	  then
	    Result := True
	 end
      end

   valid_argument_for_ace_mode: STRING is
      "Only the flags -verbose, -version, and -help are allowed in ACE%N%
      %file mode.%
      %%N"

end -- COMPILE_TO_JVM
