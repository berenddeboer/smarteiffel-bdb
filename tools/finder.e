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
class FINDER
   --
   -- The `finder' command.
   --

inherit
   COMMAND_LINE_TOOLS

creation make

feature {FINDER_VISITOR}

   accept(visitor: FINDER_VISITOR) is
      do
         visitor.visit_finder(Current)
      end

feature

   command_name: STRING is "finder"

   command_line_help_summary: STRING is "[
      Usage: finder [options] <ClassName>
         or: finder [options] <ACEfileName>.ace <ClassName>

      The finder command tells you where the class <ClassName> is by
      printing the complete path of the corresponding file.
      Hint: to see the search path used, just run finder with
      some non-existent class name.%

      This command may also be useful in shell scripts to check if the
      source file exists. (Use the exit status.)

      Option summary:

      Information:
        -help               Display this help information
        -version            Display SmartEiffel version information
        -verbose            Display detailed information about what the
                             program is doing

      Class lookup:
        -loadpath <file>    Specify an extra loadpath file to read

      ]"

feature {NONE}

   make is
      local
         argi, argc: INTEGER
         arg, search_key, file_path: STRING
	 ace_mode: BOOLEAN
      do
         argc := argument_count
	 if argc = 0 then
	    system_tools.bad_use_exit(Current)
	 end
         search_for_verbose_flag
	 ace_mode := ace_file_mode
	 from
	    argi := 1
	 until
	    argi > argc
	 loop
	    arg := argument(argi)
	    if ace.file_path = arg then
	    elseif is_some_flag(arg) then
	       if is_valid_argument_for_ace_mode(arg) then
	       end
	    elseif search_key /= Void then
	       system_tools.bad_use_exit(Current)
            elseif flag_match(fz_loadpath,arg) then
               if argi < argc then
                  system_tools.add_loadpath_file(argument(argi + 1))
                  argi := argi + 2
               else
                  echo.w_put_string(command_name)
                  echo.w_put_string(once ": missing loadpath file path after -loadpath flag.%N")
                  die_with_code(exit_failure_code)
               end
	    else
	       search_key := arg
	       ace.set_root_class_name_using(arg)
	    end
	    argi := argi + 1
	 end
	 if ace.file_path = Void then
	    ace.command_line_parsed(command_name)
	 end
	 if search_key = Void then
	    system_tools.bad_use_exit(Current)
	 end
	 file_path := smart_eiffel.find_path_for(ace.root_class_name)
	 if file_path = Void then
	    std_error.put_string("No file found for %"")
	    std_error.put_string(search_key)
	    std_error.put_string("%".%N")
	    die_with_code(exit_failure_code)
	 else
	    std_output.put_string(file_path)
	    std_output.put_character('%N')
	 end
      end

   is_valid_argument_for_ace_mode(arg: STRING): BOOLEAN is
      do
	 if is_some_flag(arg) then
	    if (is_version_flag(arg)
		or else
		is_verbose_flag(arg)
		or else
		is_help_flag(arg))
	     then
	       Result := True
	    end
	 else
	    Result := True
	 end
      end

   valid_argument_for_ace_mode: STRING is
      "Only the -verbose, -version, and -help flags are allowed in ACE %
      %file mode.%N"

end -- FINDER
