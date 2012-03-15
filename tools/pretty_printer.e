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
class PRETTY_PRINTER
   --
   -- Singleton in charge of handling Eiffel code pretty printing (this is used 
   -- to implement the well knowned "pretty" command). 
   -- This singleton is shared via the GLOBALS.`pretty_printer' once function.
   --
   -- The `pretty_printer' singleton takes care of Eiffel source code output 
   -- in a given file. The indent level, the current column number as well as 
   -- already skipped lines is automatically updated. The `pretty_printer' 
   -- singleton is also in charge of replacing sequence of blank characters with 
   -- tabulation in the output.
   -- In order to make this object easy to use, the output is automatically 
   -- buffered so that indentation level can be change without any trouble.
   --
inherit
   GLOBALS
   VISITABLE

creation make

feature

   indent_level: INTEGER
         -- The current `indent_level'. As an example, this is 0 before the 
         -- "inherit" keyword or 0 before the "feature" keyword, this is 1 
         -- before a feature name declaration and 2 for the "do" keyword. 
   
   set_indent_level(il: INTEGER) is
      require
         il >= 0
      do
         indent_level := il
      ensure
         indent_level = il
      end

   indent_level_increment is
      do
         indent_level := indent_level + 1
      ensure
	 indent_level = 1 + old indent_level
      end

   indent_level_decrement is
      require
         indent_level > 0
      do
         indent_level := indent_level - 1
      ensure
         indent_level = (old indent_level) - 1
      end

   indent is
         -- Go if needed to the `column' according to the current 
         -- `indent_level'. Ensure that the last printed character is ' ' 
         -- or '%N'.
      local
         goal: INTEGER; stop: BOOLEAN
      do
         goal := 1 + indent_level * indent_increment
	 from until stop
	 loop
	    if line_buffer.is_empty then
	       stop := True
	    elseif line_buffer.last = ' ' then
	       line_buffer.remove_last(1)
	    else
	       stop := True
	       line_buffer.extend(' ')
	    end
	 end
         if column > goal then
            put_character('%N')
         end
         from
         until
            goal = column
         loop
            put_character(' ')
         end
         inspect
            last_character
         when ' ', '%N' then
         else
            put_character('%N')
            indent
         end
      ensure
         column = indent_level * indent_increment + 1
         last_character = ' ' or last_character = '%N'
      end

   zen_mode: BOOLEAN is
	 -- Are we in the "-zen" mode?
      do
         Result := mode = C_zen
      end

   default_mode: BOOLEAN is
	 -- Are we in the "-default" mode?
      do
         Result := mode = C_default
      end

   end_mode: BOOLEAN is
	 -- Are we in the "-end" mode?
      do
         Result := mode = C_end
      end

   parano_mode: BOOLEAN is
	 -- Are we in the "-parano" mode?
      do
         Result := mode = C_parano
      end

   print_end_of_statement: BOOLEAN is
	 -- Do we have to print the end of a statement according to 
	 -- the current `mode'?
      do
         inspect
            mode
         when C_zen, C_default, C_end then
         when C_parano then
            Result := True
         end
      end

   print_end_of_feature: BOOLEAN is
	 -- Do we have to print the end of a feature according to 
	 -- the current `mode'?
      do
         inspect
            mode
         when C_zen, C_default then
         when C_end, C_parano then
            Result := True
         end
      end

   put_end_of(what: STRING) is
	 -- Short-hand to tag the end of `what'.
      do
         put_string(once "-- ")
         put_string(what)
         put_character('%N')
      end

   keyword(k: STRING) is
         -- Print keyword `k'. If needed, a space is added before `k' and 
         -- always add a ' ' after `k'.
      require
         not k.has('%N')
	 not k.has('%T')
	 not k.has(';')
      do
         inspect
            last_character
         when ' ','%N','%U' then
         else
            put_character(' ')
         end
         put_string(k)
	 if k.is_equal(fz_end) then
	    if parano_mode then
	       put_character(';')
	    end
	 end
         if last_character /= ' ' then
            put_character(' ')
         end
      ensure
         last_character = ' '
      end

   semi_colon_flag: BOOLEAN
         -- When the current instruction may add a following semi_colon (i.e. 
         -- when this is not the last one of some compound).

   set_semi_colon_flag(v: like semi_colon_flag) is
      do
	 if v then
	    if parano_mode then
	       semi_colon_flag := v
	    end
	 else
	    semi_colon_flag := v
	 end
      end

   put_character(c: CHARACTER) is
      do
	 if c = '%N' then
	    line_buffer_flush
	 else
	    line_buffer.extend(c)
	 end
      end

   put_string(s: STRING) is
      require
         s /= Void
      local
         i: INTEGER
      do
         from
            i := 1
         until
            i > s.count
         loop
            put_character(s.item(i))
            i := i + 1
         end
      end
   
   skip_one_line is
	 -- Add an empty line in the output only if it is necessary (i.e. if 
	 -- there is no empty line already skipped). Hence, calling the 
	 -- `skip_one_line' feature is not equivalent to call `put_character' 
	 -- using '%N' as an argument. In other words, two immediately 
	 -- successive calls to this `skip_one_line' actually skip only one line!
	 -- (See also `skip_two_lines'.)
      do
	 from
	 until
	    line_buffer.is_empty or else line_buffer.last /= ' '
	 loop
	    line_buffer.remove_last(1)
	 end
	 if line_buffer.is_empty then
	    if flushed_memory_1.is_empty then
	       -- Do nothing because one line is already skipped.
	    else
	       put_character('%N')
	    end
	 else
	    put_character('%N')
	    put_character('%N')
	 end
      end

   skip_two_lines is
	 -- Add two empty lines in the ouput only if it is necessary.
	 -- (See also `skip_one_line'.)
      do
	 skip_one_line
	 check
	    line_buffer.is_empty
	 end
	 if flushed_memory_1.is_empty then
	    if flushed_memory_2.is_empty then
	       -- Do nothing because two lines are already skipped.
	    else
	       put_character('%N')
	    end
	 else
	    put_character('%N')
	    put_character('%N')
	 end
      end

feature {COMPOUND, MANIFEST_STRING}

   last_non_blank_character_is(c: CHARACTER): BOOLEAN is
	 -- Is the last non blank character equal to `c'? 
      require
	 (once ";,()").has(c)
      local
	 i: INTEGER; c2: CHARACTER
      do
	 from
	    i := line_buffer.count
	 until
	    i <= 0 or else Result
	 loop
	    c2 := line_buffer.item(i)
	    if c2 = c then
	       Result := True
	    elseif c2 /= ' ' then
	       i := -1
	    else
	       i := i - 1
	    end
	 end
	 if not Result then
	    if i = 0 then
	       if not flushed_memory_1.is_empty then
		  Result := flushed_memory_1.last = c
	       elseif not flushed_memory_2.is_empty then
		  Result := flushed_memory_2.last = c
	       end
	    end
	 end
      end

feature {LOCAL_VAR_LIST, FORMAL_ARG_LIST}
   
   wrap_limit: INTEGER is 80
   
feature {BASE_CLASS, COMMENT, FEATURE_CLAUSE, INDEX_CLAUSE, LOCAL_VAR_LIST, ANY}

   column: INTEGER is
         -- The current column in the output file (`text_file_write'). 
	 -- Note: the left-most column number is 1.
      do
	 Result := line_buffer.count + 1
      end
      
   last_character: CHARACTER is
         -- The last printed one.
      do
	 if line_buffer.is_empty then
	    Result := '%N'
	 else
	    Result := line_buffer.last
	 end
      end
   
feature {PRETTY}

   set_zen is
         -- (See pretty.html for more info.)
      do
         mode := C_zen
      end

   set_default is
         -- (See pretty.html for more info.)
      do
         mode := C_default
      end

   set_end is
         -- (See pretty.html for more info.)
      do
         mode := C_end
      end

   set_parano is
         -- (See pretty.html for more info.)
      do
         mode := C_parano
      end

feature {PRETTY}

   connect_to(path: STRING) is
	 -- Note: because the output is buffered, the caller must not 
	 -- forget to call `disconnect' at the end.
      require
         not path.is_empty
      do
	 if text_file_write = Void then
	    create text_file_write.make
	 end
	 echo.tfw_connect(text_file_write, path)
      ensure
         text_file_write.is_connected
      end

   disconnect is
	 -- Flush the output and close the correspnding file (see `connect_to').
      do
	 from
	 until
	    line_buffer.is_empty or else line_buffer.last /= ' '
	 loop
	    line_buffer.remove_last(1)
	 end
	 if not line_buffer.is_empty then
	    line_buffer_flush
	 end
	 text_file_write.disconnect
      end
   
feature {PRETTY_PRINTER_VISITOR}

   accept(visitor: PRETTY_PRINTER_VISITOR) is
      do
         visitor.visit_pretty_printer(Current)
      end

feature {MANIFEST_STRING}

   set_no_blanks_to_tab_flag(value: BOOLEAN) is
      do
	 no_blanks_to_tab_flag := value
      end
   
feature {NONE}

   line_buffer: STRING
	 -- The current line buffer (not yet flushed on the `text_file_write').

   flushed_memory_1: STRING
	 -- The last flushed line.

   flushed_memory_2: STRING
	 -- The previous `flushed_memory_1'.
   
   text_file_write: TEXT_FILE_WRITE
         -- Where printing is done.

   mode: INTEGER
         -- Internal code to memorize the selected mode : "-zen", "-default", 
         -- "-end" or "-parano".

   C_zen, C_default, C_end, C_parano: INTEGER is unique

   indent_increment: INTEGER is 3
         -- Basic standard increment.
      
   make is
      do
	 mode := C_default
	 create line_buffer.make(256)
	 flushed_memory_1 := line_buffer.twin
	 flushed_memory_2 := line_buffer.twin
      end

   valid_mode(m: like mode): BOOLEAN is
         -- Is the mode previously obtained using `mode'?
      do
         inspect
            m
         when C_zen, C_default, C_end, C_parano then
            Result := True
         else
         end
      end

   blanks_to_tab: STRING is "        "
	 -- When this sequence of ' ' appears at the beginning of a 
	 -- line, if is automatically replaced by one '%T' character.
   
   no_blanks_to_tab_flag: BOOLEAN
   
   line_buffer_flush is
	 -- Flush the `line_buffer' on `text_file_write'.
      local
	 stop: BOOLEAN; i: INTEGER
      do
	 -- Remove extra trailing ' ' or '%T' first:
	 from
	 until
	    stop
	 loop
	    if line_buffer.is_empty then
	       stop := True
	    else
	       inspect
		  line_buffer.last
	       when ' ', '%T' then
		  line_buffer.remove_last(1)
	       else
		  stop := True
	       end
	    end
	 end
	 if not line_buffer.is_empty then
	    if not no_blanks_to_tab_flag then
	       -- Replace starting sequences of ' ' with '%T':
	       from
		  i := 1
	       until
		  line_buffer.substring_index(blanks_to_tab, i) /= i
	       loop
		  line_buffer.remove_substring(i, i + blanks_to_tab.count - 1)
		  line_buffer.insert_character('%T', i)
		  i := i + 1
	       end
	    end
	    text_file_write.put_string(line_buffer)
	 end
	 text_file_write.put_character('%N')
	 flushed_memory_2.copy(flushed_memory_1)
	 flushed_memory_1.copy(line_buffer)
	 line_buffer.clear_count
      end
      
   singleton_memory: PRETTY_PRINTER is
      once
	 Result := Current
      end

invariant

   is_real_singleton: Current = singleton_memory

   indent_level >= 0

   valid_mode(mode)

   not line_buffer.has('%N')

end -- PRETTY_PRINTER


