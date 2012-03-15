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
expanded class STRING_COMMAND_LINE
--
-- Emulate a command line using a string
--
inherit
   COMMAND_LINE_TOOLS
       undefine
           ace_file_mode,
           unknown_flag_exit
       end -- Avoid conformance problems with Current

feature {STRING_COMMAND_LINE_VISITOR}

   accept(visitor: STRING_COMMAND_LINE_VISITOR) is
      do
         visitor.visit_string_command_line(Current)
      end

feature

   set_command_name(c: STRING) is
      do
         command_name.copy(c)
      end

   parse(command_line: STRING) is
         -- Only a very small subset of SmartEiffel options are supported
         -- here:
         --    -no_gc
         --    -no_strip
         --    -no_split
         --    -sedb
         --    -wedit
         --    -compact
      local
         arg: STRING
      do
         from
            command_line_buffer.copy(command_line)
         until
            command_line_buffer.is_empty
         loop
            next_option
            arg := option_buffer
            if flag_match(once "no_gc", arg) then
               gc_handler.no_gc
            elseif flag_match(fz_no_strip,arg) then
               system_tools.set_no_strip
            elseif flag_match(fz_no_split,arg) then
               ace.set_no_split(True)
            elseif is_trace_flag(arg) then
            elseif flag_match(fz_wedit,arg) then
               ace.set_wedit(True)
            elseif flag_match(fz_compact,arg) then
               cpp.set_compact(True)
            else
               echo.w_put_string(command_name)
               echo.w_put_string(": unsupported option %"")
               echo.w_put_string(arg)
               echo.w_put_string("%".%N")
            end
         end
      end

feature {NONE}

   next_option is
         -- Finds the next option after having skipped the separators
      local
         low, up, i: INTEGER
      do
         from
            low := 1
         until
            low > command_line_buffer.count or else not command_line_buffer.item(low).is_separator
         loop
            low := low + 1
         end
         from
            up := low
         until
            up > command_line_buffer.count or else command_line_buffer.item(up).is_separator
         loop
            up := up + 1
         end
         option_buffer.clear_count
         if up > command_line_buffer.count then
            from
               i := low
            until
               i > command_line_buffer.count
            loop
               option_buffer.extend(command_line_buffer.item(i))
               i := i + 1
            end
            command_line_buffer.clear_count
         else
            from
               i := low
            until
               i = up
            loop
               option_buffer.extend(command_line_buffer.item(i))
               i := i + 1
            end
            command_line_buffer.shrink(up, command_line_buffer.count)
         end
      end

   command_line_buffer: STRING is
      once
         create Result.make(16)
      end

   option_buffer: STRING is
      once
         create Result.make(16)
      end

   command_name: STRING is
      once
         Result := "string_command_line" -- must be changed by the tools which use the STRING_COMMAND_LINE
      end

   valid_argument_for_ace_mode: STRING is ""

   command_line_help_summary: STRING is ""
   
   is_valid_argument_for_ace_mode (arg: STRING): BOOLEAN is
   do
       Result := True
   end

end
