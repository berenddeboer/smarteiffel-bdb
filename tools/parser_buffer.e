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
class PARSER_BUFFER
   --
   -- Parsers are working in a buffered area (the file to parse is entirely
   -- loaded into this buffer during parsing). This solution make it easy
   -- line/column counting as well as backward moves.
   --
inherit
   GLOBALS
   VISITABLE

creation make

feature {PARSER_BUFFER_VISITOR}

   accept(visitor: PARSER_BUFFER_VISITOR) is
      do
         visitor.visit_parser_buffer(Current)
      end

feature

   path: STRING
         -- When `is_ready', gives the `path' of the corresponding buffered file.

   cluster: CLUSTER
	 -- The corresponding one when the buffered file is an Eiffel source
	 -- file.

   count: INTEGER
         -- Number of lines in the source file.

   is_ready: BOOLEAN is
      do
         Result := path /= Void
      end

feature {SMART_EIFFEL,PARSER,CLUSTER,SYSTEM_TOOLS,INSTALL,PARSER_BUFFER_VISITOR}

   load_file(a_path: STRING) is
         -- Try to load `a_path' and set `is_ready' when corresponding
         -- file has been loaded.
      require
	 not is_ready
      local
         i: INTEGER
      do
         tmp_file_read.connect_to(a_path)
         if tmp_file_read.is_connected then
            path := string_aliaser.item(a_path)
            from
               if empty_line_at(0) /= Void then
                  -- unused line.
               end
               i := 1
               tmp_file_read.read_line_in(empty_line_at(i))
            until
               tmp_file_read.end_of_input
            loop
               i := i + 1
               tmp_file_read.read_line_in(empty_line_at(i))
            end
            if text.item(i).is_empty then
               count := i - 1
            else
               count := i
            end
            tmp_file_read.disconnect
	    if count <= 0 then
	       error_handler.append("File %"")
	       error_handler.append(path)
	       error_handler.append("%" seems to be empty.")
	       error_handler.print_as_fatal_error
	    end
         else
            path := Void
         end
      end

   load_string(a_string: STRING) is
      -- Initialize the buffer with the contents of the string
      require
         not is_ready
      local
         i: INTEGER; l: STRING; c: CHARACTER
      do
         from
            count := 1
            l := empty_line_at(1)
            i := a_string.lower
         until
            i > a_string.upper
         loop
            c := a_string.item(i)
            if c = '%N' then
               count := count + 1
               l := empty_line_at(count)
            else
               l.extend(c)
            end
            i := i + 1
         end
         path := once "*** STRING ***"
      end

feature {SMART_EIFFEL,PARSER,CLUSTER}

   release is
	 -- To be called at the end of parsing to release the `parser_buffer'.
      require
	 is_ready
      do
         path := Void
	 cluster := Void
      ensure
	 not is_ready
      end

feature {PARSER}

   item(line: INTEGER): STRING is
      require
         is_ready
         1 <= line
         line <= count
      do
         Result := text.item(line)
      ensure
         Result /= Void
      end

feature {CLUSTER}

   set_cluster(c: like cluster) is
      require
         c /= Void
      do
         cluster := c
      ensure
         cluster = c
      end

feature {NONE}

   make is
      do
         create text.with_capacity(6000)
      end

   text: FAST_ARRAY[STRING]
         -- To store the complete file to parse. Each line
         -- is one STRING without the '%N' end-of-line mark.

   empty_line_at(i: INTEGER): STRING is
      require
         i >= 0
      do
         if i <= text.upper then
            Result := text.item(i)
            Result.clear_count
         else
            !!Result.make(medium_line_size)
            text.add_last(Result)
         end
      ensure
         Result.is_empty
         Result.capacity >= medium_line_size
         text.item(i) = Result
      end

   medium_line_size: INTEGER is 128

   singleton_memory: PARSER_BUFFER is
      once
         Result := Current
      end

invariant

   is_real_singleton: Current = singleton_memory

end -- PARSER_BUFFER

