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
class SHORT
   --
   -- The `short' command.
   --

inherit CLASS_CHECKER

creation
   make

creation {SHORT_VISITOR}
   make_for_visitor

feature

   command_name: STRING is "short"

   command_line_help_summary: STRING is "[
      Usage: short [format] [options] <ClassName>
         or: short [format] [options] <ACEfileName>.ace <ClassName>

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

        -sort               Sort features alphabetically
        -short              Don't include inherited features

      Formatting (specify at most one; default is -plain):
        -plain, -pretty, -tex1, -tex2, -tex3, -html1, -html2
                            Specify the style of formatting (see short.txt)

      Point of view:
        -client <class>     Specify the class whom the point of view is taken of

      Class lookup:
        -loadpath <file>    Specify an extra loadpath file to read

      ]"

feature {SHORT_VISITOR}

   accept(visitor: SHORT_VISITOR) is
      do
         visitor.visit_short(Current)
      end

   make is
      do
         output := std_output
         start
      end

   parse_arguments is
      local
         i: INTEGER; arg: STRING; found: BOOLEAN
         root_class_name: STRING
      do
         if argument_count = 0 then fatal_bad_usage end
	 if ace_file_mode then
            from
	       i := 1
	    until
	       found or else i > argument_count
	    loop
               arg := argument(i)
               if is_client_flag(arg) then
                  if i = argument_count then
                     fatal_bad_usage
                  else
                     arg := argument(i+1)
                     arg.to_upper
                     set_client(string_aliaser.item(arg))
                     found := True
                  end
               else
                  i := i + 1
               end
	    end
         else
	    from
	       i := 1
	    until
	       i > argument_count
	    loop
               arg := argument(i)
               if is_client_flag(arg) then
                  if i = argument_count then
                     fatal_bad_usage
                  else
                     i := i + 1
                     arg := argument(i)
                     arg.to_upper
                     set_client(string_aliaser.item(arg))
                     found := True
                  end
               elseif flag_match(fz_loadpath,arg) then
                  if i = argument_count then
                     fatal_bad_usage
                  else
                     system_tools.add_loadpath_file(argument(i + 1))
                     i := i + 1
                  end
	       elseif is_valid_argument_for_ace_mode(arg) then
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
	 root_class_name := ace.root_class_name
	 if root_class_name = Void or else root_class_name.is_empty then
	    fatal_bad_usage
	 end
         root_class_names.add_last(root_class_name)
         if not found then
            set_client(as_any)
         end
         if format = Void then
	    set_format(once "plain")
         end
      end

   is_sort_flag(flag: STRING): BOOLEAN is
      do
	 if flag_match(once "sort",flag) then
	    Result := True
	    sort := True
	 end
      end

   is_short_flag(flag: STRING): BOOLEAN is
      do
	 if flag_match(once "short",flag) then
	    Result := True
	    short := True
	 end
      end

   is_client_flag(flag: STRING): BOOLEAN is
      do
	 if flag_match(once "client",flag) then
	    Result := True
	 end
      end

   is_valid_argument_for_ace_mode(arg: STRING): BOOLEAN is
	 -- Because of style options, this function always returns True.
	 -- Futhermore, this function is used for non ACE mode too.
      do
	 Result := True
         if is_client_flag(arg) then
	 elseif is_version_flag(arg) then
         elseif is_verbose_flag(arg) then
	 elseif is_help_flag(arg) then
	 elseif is_sort_flag(arg) then
	 elseif is_short_flag(arg) then
	 elseif is_case_insensitive_flag(arg) then
	 elseif is_no_warning_flag(arg) then
	 elseif is_no_style_warning_flag(arg) then
	 elseif arg.item(1) = '-' then
	    arg.remove_first(1)
	    set_format(arg)
	 else
	    if arg.has_suffix(eiffel_suffix) then
	       arg.remove_suffix(eiffel_suffix)
	    end
	    ace.set_root_class_name_using(arg)
	 end
      end

   valid_argument_for_ace_mode: STRING is
      "Only the -client, -version, -help, -no_warning, and -no_style_warning are%N%
      %allowed in ACE file mode.%N"

end -- SHORT
