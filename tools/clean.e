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
class CLEAN
   --
   -- The `clean' command.
   --

inherit
   COMMAND_LINE_TOOLS

creation make

feature {CLEAN_VISITOR}

   accept(visitor: CLEAN_VISITOR) is
      do
         visitor.visit_clean(Current)
      end

feature

   command_name: STRING is "clean"

   command_line_help_summary: STRING is
      "Usage: clean <Root-Class> ...%N%
      %%N%
      %Option summary:%N%
      %%N%
      %Information:%N%
      %  -help               Display this help information%N%
      %  -version            Display SmartEiffel version information%N%
      %  -verbose            Display detailed information about what the%N%
      %                       program is doing%N"

feature {NONE}

   make is
      local
         argc: INTEGER
      do
         argc := argument_count
         if argc < 1 then
            system_tools.bad_use_exit(Current)
         end
         search_for_verbose_flag
         search_for_cc_flag(argc)
         parse_command_line(1)
         ace.set_default_level
         system_tools.add_smarteiffel_c_mode_options
         parse_command_line(2)
      end

   parse_command_line(pass: INTEGER) is
      local
         argc, argi: INTEGER
         arg, make_suffix, symb_suffix: STRING
      do
         from
            argc := argument_count
            if pass = 2 then
               make_suffix := system_tools.make_suffix
               symb_suffix := system_tools.symb_suffix
            end
            argi := 1
         until
            argi > argc
         loop
            arg := argument(argi)
            if flag_match(fz_c_mode,arg) then
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
	    elseif is_some_flag(arg) then
	       if (is_verbose_flag(arg)
		   or else
		   is_version_flag(arg)
		   or else
		   is_help_flag(arg))
		then
		  argi := argi + 1
	       else
		  unknown_flag_exit(arg)
	       end
            else
               if pass = 2 then
                  if arg.has_suffix(eiffel_suffix) then
                     arg.remove_suffix(eiffel_suffix)
                  elseif arg.has_suffix(make_suffix) then
                     arg.remove_suffix(make_suffix)
                  elseif arg.has_suffix(symb_suffix) then
                     arg.remove_suffix(symb_suffix)
                  end
                  ace.set_root_class_name_using(arg)
                  try_to_remove(arg)
                  arg.to_upper
                  try_to_remove(arg)
                  arg.to_lower
                  try_to_remove(arg)
                  arg := system_tools.new_make_script
                  arg := ace.root_class_name.twin
                  try_to_remove(arg)
                  arg.to_lower
                  try_to_remove(arg)
               end
               argi := argi + 1
            end
         end
      end

   try_to_remove(prefix_name: STRING) is
      require
         prefix_name.count > 0
      local
         i: INTEGER
      do
         from
            i := 1
         until
            i = 0
         loop
            tmp_path.copy(prefix_name)
            i.append_in(tmp_path)
            tmp_path.extend('.')
            tmp_path.extend('c')
            if file_exists(tmp_path) then
               echo.file_removing(tmp_path)
               tmp_path.put('d',tmp_path.count)
               echo.file_removing(tmp_path)
               tmp_path.remove_last(2)
               tmp_path.append(system_tools.object_suffix)
               echo.file_removing(tmp_path)
               i := i + 1
            else
               i := 0
            end
         end
	 --
         tmp_path.copy(prefix_name)
         tmp_path.append(".h")
         echo.file_removing(tmp_path)
	 --
         tmp_path.copy(prefix_name)
         tmp_path.append(".c")
         echo.file_removing(tmp_path)
	 --
         tmp_path.copy(prefix_name)
         tmp_path.append(".d")
         echo.file_removing(tmp_path)
	 --
         tmp_path.copy(prefix_name)
         tmp_path.append(".id")
         echo.file_removing(tmp_path)
	 --
         tmp_path.copy(prefix_name)
         tmp_path.append("_external_cpp.h")
         echo.file_removing(tmp_path)
	 --
         tmp_path.copy(prefix_name)
         tmp_path.append("_external_cpp.cpp")
         echo.file_removing(tmp_path)
	 --
         tmp_path.copy(prefix_name)
         tmp_path.append("_external_cpp")
         tmp_path.append(system_tools.object_suffix)
         echo.file_removing(tmp_path)
	 --
	 tmp_path.copy(prefix_name)
         tmp_path.append(system_tools.object_suffix)
         echo.file_removing(tmp_path)
	 --
         tmp_path.copy(prefix_name)
         tmp_path.append(system_tools.symb_suffix)
         echo.file_removing(tmp_path)
      end

end -- CLEAN
