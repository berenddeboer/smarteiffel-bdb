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
class PRETTY
   --
   -- The `pretty' command.
   --

inherit
   COMMAND_LINE_TOOLS

creation make

feature

   command_name: STRING is "pretty"

   command_line_help_summary: STRING is
      "Usage: pretty [options] <ClassNames> ...%N%
      %%N%
      %Option summary:%N%
      %%N%
      %Information:%N%
      %  -help               Display this help information%N%
      %  -version            Display SmartEiffel version information%N%
      %  -verbose            Display detailed information about what the%N%
      %                       program is doing%N%
      %%N%
      %Style (default is -default):%N%
      %  -zen                Print as little as possible (%"Current%" only when necessary,%N%
      %                       no end comments, compact printing)%N%
      %  -default            Print using the default style options%N%
      %  -end                Include end comments (implies -default)%N%
      %  -parano             Print as much as possible (implies -end)%N"

feature {PRETTY_VISITOR}

   accept(visitor: PRETTY_VISITOR) is
      do
         visitor.visit_pretty(Current)
      end

feature {NONE}

   make is
      local
         i: INTEGER; arg: STRING
      do
	 smart_eiffel.set_pretty_flag
         if argument_count < 1 then
            system_tools.bad_use_exit(Current)
	 end
         from
            i := 1
         until
            i > argument_count or else state > 0
         loop
            arg := argument(i)
	    if is_some_flag(arg) then
	       if is_no_style_warning_flag(arg) then
	       elseif is_no_warning_flag(arg) then
	       elseif is_version_flag(arg) then
	       elseif is_help_flag(arg) then
	       elseif (once "-default").is_equal(arg) then
		  if style /= Void then
		     error_style(arg)
		  else
		     pretty_printer.set_default
		     style := arg
		  end
	       elseif (once "-zen").is_equal(arg) then
		  if style /= Void then
		     error_style(arg)
		  else
		     pretty_printer.set_zen
		     style := arg
		  end
	       elseif (once "-end").is_equal(arg) then
		  if style /= Void then
		     error_style(arg)
		  else
		     pretty_printer.set_end
		     style := arg
		  end
	       elseif (once "-parano").is_equal(arg) then
		  if style /= Void then
		     error_style(arg)
		  else
		     pretty_printer.set_parano
		     style := arg
		  end
	       else
		  echo.w_put_string("Unknown flag: ")
		  echo.w_put_string(arg)
		  echo.w_put_character('%N')
		  state := 2
	       end
	    else
               class_names.add_last(arg)
            end
	    i := i + 1
         end
         if nb_errors > 0 then
            error_handler.append("No pretty printing done.")
            error_handler.print_as_error
         else
            if class_names.is_empty then
               error_handler.append("No class to pretty print.")
               error_handler.print_as_error
            else
	       ace.start_pretty_mode
	       from
		  i := class_names.lower
	       until
		  i > class_names.upper
	       loop
		  pretty_for(class_names.item(i))
		  i := i + 1
	       end
            end
         end
      end

   state: INTEGER
	 -- Of the automata in charge of argument parsing.
         -- 0: nothing done.
         -- 1: end.
         -- 2: error.

   style: STRING
	 -- The selected one among: -default -zen -end -parano

   class_names: FIXED_ARRAY[STRING] is
      once
         create Result.with_capacity(12)
      end


   error_style(style2: STRING) is
      do
         state := 2
         error_handler.append("pretty: format style is already set to ")
         error_handler.append(style)
         error_handler.append(". Bad flag ")
         error_handler.append(style2)
         error_handler.append(fz_dot_blank)
         error_handler.print_as_error
      end

   pretty_for(name: STRING) is
      require
         name /= Void
      local
         root_class: STRING; bc: BASE_CLASS; cn: CLASS_NAME
      do
         ace.set_root_class_name_using(name)
         root_class := ace.root_class_name
	 create cn.unknown_position(root_class)
         bc := smart_eiffel.base_class(cn)
         if bc = Void then
            error_handler.append("No pretty printing done for %"")
            error_handler.append(name)
            fatal_error("%".")
         else
            path.copy(bc.path)
            backup.copy(path)
            backup.remove_suffix(eiffel_suffix)
            backup.append(backup_suffix)
            if file_exists(backup) then
               error_handler.append("Security backup file %"")
               error_handler.append(backup)
               fatal_error("%" already exists. Remove this file first and %
			     %then run pretty again.")
            end
            rename_file(path, backup)
            if not file_exists(backup) then
               error_handler.append("Cannot rename %"")
               error_handler.append(path)
               fatal_error("%".")
            end
            pretty_printer.connect_to(path)
            bc.pretty_print
            pretty_printer.disconnect
            if not smart_eiffel.re_load_class(bc) then
               error_handler.append("Error during `pretty' printing.%N%
                         %Cannot parse output of pretty.%N%
                         %Backup file %"")
               error_handler.append(backup)
               fatal_error("%" not removed.")
            end
         end
      end

   path: STRING is
      once
         create Result.make(256)
      end

   backup: STRING is
      once
         create Result.make(256)
      end

end -- PRETTY
