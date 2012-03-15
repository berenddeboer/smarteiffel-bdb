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
class CLASS_CHECK
   --
   -- The `class_check' command.
   --
   -- "class_check my_class"
   --          <=>
   -- "short -client NONE my_class > /dev/null"
   --

inherit CLASS_CHECKER

creation
   make

feature

   command_name: STRING is "class_check"

   command_line_help_summary: STRING is "[
      Usage: class_check [options] <ClassName>

      Option summary:

      Information:
        -help               Display this help information
        -version            Display SmartEiffel version information
        -verbose            Display detailed information about what the
                             program is doing

      Warning levels:
        -case_insensitive   Make class and feature names case-insensitive
        -no_style_warning   Don't print warnings about style violations
        -no_warning         Don't print any warnings (implies -no_style_warning)

      Class lookup:
        -loadpath <file>    Specify an extra loadpath file to read

      ]"

feature {CLASS_CHECK_VISITOR}

   accept(visitor: CLASS_CHECK_VISITOR) is
      do
         visitor.visit_class_check(Current)
      end

   make is
      do
         create {NULL_OUTPUT} output
         start
      end

   parse_arguments is
      local
         i: INTEGER; arg: STRING
      do
	 -- A `short' command is running:
         -- yes, `class_check' is really a "short > /dev/null" command
         smart_eiffel.set_short_flag
         if argument_count = 0 then fatal_bad_usage end
	 if ace_file_mode then
         else
	    from
	       i := 1
	    until
	       i > argument_count
	    loop
               arg := argument(i)
               if flag_match(fz_loadpath,arg) then
                  if i = argument_count then
                     fatal_bad_usage
                  else
                     system_tools.add_loadpath_file(argument(i + 1))
                     i := i + 1
                  end
	       elseif is_valid_argument_for_ace_mode(arg) then
               else
                  fatal_bad_usage
               end
	       i := i + 1
	    end
	    ace.command_line_parsed(command_name)
	 end
	 if help_flag then
	    die_with_code(exit_success_code)
	 end
	 if version_flag then
	    die_with_code(exit_success_code)
	 end
	 root_class_names.append_collection(ace.root_class_names)
	 if root_class_names.is_empty then
	    fatal_bad_usage
	 end
         set_client(as_none)
         set_format(once "plain")
      end

   is_valid_argument_for_ace_mode(arg: STRING): BOOLEAN is
	 -- Because of style options, this function always returns True.
	 -- Futhermore, this function is used for non ACE mode too.
      do
	 Result := True
         if is_version_flag(arg) then
         elseif is_verbose_flag(arg) then
	 elseif is_help_flag(arg) then
	 elseif is_case_insensitive_flag(arg) then
	 elseif is_no_warning_flag(arg) then
	 elseif is_no_style_warning_flag(arg) then
	 elseif arg.item(1) = '-' then
            Result := False
	 else
	    if arg.has_suffix(eiffel_suffix) then
	       arg.remove_suffix(eiffel_suffix)
	    end
	    ace.set_root_class_name_using(arg)
	 end
      end

   valid_argument_for_ace_mode: STRING is
      "Only the -version, -help, -no_warning, and -no_style_warning are%N%
      %allowed in ACE file mode.%N"

end -- CLASS_CHECK
