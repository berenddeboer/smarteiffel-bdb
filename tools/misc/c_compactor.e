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
class C_COMPACTOR
   --
   -- Outputs really compact C code
   --
   -- C_COMPACTOR is a very low-level interface between C_PRETTY_PRINTER and
   -- the real file; it understands the notions of C strings, characters and
   -- comments; it also knows about symbols, and symbols that should keep
   -- their proper name. Any other symbol is, hem... shortened... :o)
   --
   -- Note that this class is only based on mere heuristics, it's by no means
   -- a true C parser!
   --
   -- Also note that this option considerably slowers the compilation. Double
   -- times have been seen.
   --
   -- See `reserved_words' for the list of non-changed symbols.
   --
inherit
   GLOBALS
   VISITABLE
   TEXT_FILE_WRITE
      undefine
         tmp_file_read
      redefine
         connect_to, disconnect, is_connected, flush, put_character, make
      end

creation {C_PRETTY_PRINTER}
   make

feature {C_COMPACTOR_VISITOR}

   accept(visitor: C_COMPACTOR_VISITOR) is
      do
         visitor.visit_c_compactor(Current)
      end

feature {NONE}

   max_columns: INTEGER is 132

feature

   unstripped_count: COUNTER is
      once
         create Result
      end

   stripped_count: COUNTER is
      once
         create Result
      end

   put_character(c: CHARACTER) is
      do
         unstripped_count.increment
         next_state(c)
      end

   is_connected: BOOLEAN is
      do
         Result := output.is_connected
      end

   flush is
      do
         output.flush
      end

   disconnect is
      do
         out_buffers(wstate = 0)
         output.put_new_line
         output.disconnect
      end

   connect_to(a_path: STRING) is
      do
         output.connect_to(a_path)
      end

   show_gain is
      local
         gain: INTEGER
      do
         gain := (unstripped_count.value - stripped_count.value) * 100 // unstripped_count.value
         echo.put_string(once "Compact gain: ")
         echo.put_integer(gain)
         echo.put_string(once "%%%N")
      end

   write_symbols(tfw: TEXT_FILE_WRITE) is
      local
         i, j: INTEGER
         k, v: STRING
      do
         from
            i := symbols.lower
         until
            i > symbols.upper
         loop
            k := symbols.key(i)
            v := symbols.item(i)
            if not k.is_equal(v) then
               tfw.put_string(once "#define ")
               tfw.put_string(v)
               tfw.put_character(' ')
               tfw.put_string(k)
               tfw.put_new_line
               from
                  j := 9 + k.count + v.count
               until
                  j = 0
               loop
                  stripped_count.increment
                  j := j - 1
               end
            end
            i := i + 1
         end
      end

   register_symbol(s: STRING) is
      local
         dummy: STRING
      do
         dummy := compact_symbol(s)
      end

feature {NONE}

   next_state(cc: CHARACTER) is
      do
	 inspect
	    state
	 when 0 then -- Initial normal state.
	    inspect
	       cc
	    when '/' then
	       new_state(1, False, ' ')
	    when '%"' then
	       new_state(4, True, cc)
	    when '%'' then
	       new_state(6, True, cc)
	    when '\' then
	       new_state(8, True, cc)
            when '%T', ' ' then
               new_state(10, False, ' ')
            when '%N' then
               if column > max_columns then
                  new_state(9, True, '%N')
               else
                  new_state(9, in_macro, '%N')
               end
               in_macro := False
	    else
	       new_state(state, True, cc)
	    end
	 when 1 then -- After / with this / delayed.
	    inspect
	       cc
	    when '*' then
	       new_state(2, False, ' ')
	    when '/' then
	       new_state(12, False, ' ')
	    when '\' then
               write('/')
	       new_state(8, True, cc)
            when '%T', ' ' then
               write('/')
               new_state(10, False, ' ')
            when '%N' then
               write('/')
               if column > max_columns then
                  new_state(9, True, '%N')
               else
                  new_state(9, in_macro, '%N')
               end
               in_macro := False
	    else
	       write('/')
	       new_state(0, True, cc)
	    end
	 when 2 then -- Inside C comment.
	    inspect
	       cc
	    when '*' then
	       new_state(3, False, ' ')
	    else
	       new_state(state, False, ' ')
	    end
	 when 3 then -- Inside C comment after closing *
	    inspect
	       cc
	    when '/' then
	       new_state(10, False, ' ')
            when '*' then
               new_state(state, False, ' ')
	    else
	       new_state(2, False, ' ')
	    end
	 when 4 then -- Inside C string.
	    inspect
	       cc
	    when '%"' then
	       new_state(0, True, cc)
	    when '\' then
	       new_state(5, True, cc)
	    else
	       new_state(state, True, cc)
	    end
	 when 5 then -- Inside C string, after \
	    new_state(4, True, cc)
	 when 6 then -- Inside C character (after the first ' ).
	    inspect
	       cc
	    when '\' then
	       new_state(7, True, cc)
	    when '%'' then
	       new_state(0, True, cc)
	    else
	       new_state(6, True, cc)
	    end
	 when 7 then -- Inside C character (after '\ )
	    new_state(6, True, cc)
         when 8 then -- After a \
	    inspect
	       cc
            when '%T', ' ' then
               new_state(10, False, ' ')
            else
               new_state(0, True, cc)
            end
         when 9 then -- First character of a line (not in string nor comment nor character)
            check
               not in_macro
            end
	    inspect
	       cc
            when '#' then
               if column > 0 then
                  write('%N')
               end
               new_state(0, True, cc)
               in_macro := True
	    when '/' then
	       new_state(1, False, ' ')
	    when '%"' then
	       new_state(4, True, cc)
	    when '%'' then
	       new_state(6, True, cc)
	    when '\' then
	       new_state(8, True, cc)
            when '%N' then
               new_state(state, False, ' ')
            when '%T', ' ' then
               new_state(10, False, ' ')
	    else
	       new_state(0, True, cc)
	    end
         when 10 then -- Reading useless extra spaces
	    inspect
	       cc
	    when '/' then
	       new_state(1, False, ' ')
	    when '%"' then
               if in_define then
                  write(' ')
               end
	       new_state(4, True, cc)
	    when '%'' then
               if in_define then
                  write(' ')
               end
	       new_state(6, True, cc)
	    when '\' then
               write(' ')
	       new_state(8, True, cc)
            when '%N' then
               if column > max_columns then
                  new_state(11, True, '%N')
               else
                  new_state(11, in_macro, '%N')
               end
               in_macro := False
            when '%T', ' ' then
               new_state(state, False, ' ')
	    else
               if column > 0
                  and then (last_written.is_letter_or_digit or else last_written = '_')
                  and then (cc.is_letter_or_digit or else cc = '_')
                  and then not in_macro
                then
                  if column > max_columns then
                     write('%N')
                  else
                     write(' ')
                  end
               elseif in_macro and then column > 1 then
                  if column > max_columns then
                     write('%N')
                  else
                     write(' ')
                  end
               end
	       new_state(0, True, cc)
	    end
         when 11 then -- First character in a line, in extra-spaces mode
            check
               not in_macro
            end
	    inspect
	       cc
            when '#' then
               if column > 0 then
                  write('%N')
               end
               new_state(0, True, cc)
               in_macro := True
	    when '/' then
	       new_state(1, False, ' ')
	    when '%"' then
	       new_state(4, True, cc)
	    when '%'' then
	       new_state(6, True, cc)
	    when '\' then
	       new_state(8, True, cc)
            when '%N' then
               new_state(state, False, ' ')
               in_macro := False
            when '%T', ' ' then
               new_state(10, False, ' ')
	    else
               if column > 0
                  and then (last_written.is_letter_or_digit or else last_written = '_')
                  and then (cc.is_letter_or_digit or else cc = '_')
                  and then not in_macro
                then
                  if column > max_columns then
                     write('%N')
                  else
                     write(' ')
                  end
               elseif in_macro and then column > 1 then
                  if column > max_columns then
                     write('%N')
                  else
                     write(' ')
                  end
               end
	       new_state(0, True, cc)
	    end
         when 12 then -- Inside a once-line comment
            inspect
               cc
            when '%N' then
               new_state(11, in_macro, '%N')
               in_macro := False
            else
               new_state(state, False, ' ')
            end
	 end
      end

   new_state(s: INTEGER; call_write: BOOLEAN; c: CHARACTER) is
      do
	 debug
	    previous_previous_state := previous_state
	    previous_state := state
	 end
         if state /= s then
            out_buffers(wstate = 0)
            wstate := 2
         end
	 state := s
	 if call_write then
            write(c)
	 end
      end

   write(c: CHARACTER) is
      do
	 check
	    c /= '%U'
	 end
         if state /= 0 then
            out_character(c)
         else
            inspect
               wstate
            when 0 then -- reading an identifier
               inspect c
               when '0'..'9', 'A'..'Z', 'a'..'z', '_' then
                  wbuffer.extend(c)
               else
                  out_buffers(True)
                  wstate := 2
                  out_character(c)
               end
            when 1 then -- reading a number
               inspect c
               when '0'..'9' then
                  wbuffer.extend(c)
               when 'x' then 
                  check wbuffer.last = '0' end
                  wbuffer.extend(c)
                  hex_number := True;
               when 'A'..'F', 'a'..'f' then
                  if not hex_number then
                    out_buffers(False)
                    wstate := 0
                  end
                  wbuffer.extend(c)
               when 'G'..'Z', 'g'..'w', 'y', 'z', '_' then
                  out_buffers(False)
                  wstate := 0
                  wbuffer.extend(c)
               else
                  out_buffers(False)
                  wstate := 2
                  out_character(c)
               end
            when 2 then -- reading anything else
               inspect c
               when '0'..'9' then
                  out_buffers(False)
                  wbuffer.extend(c)
                  wstate := 1
               when 'A'..'Z', 'a'..'z', '_' then
                  out_buffers(False)
                  wbuffer.extend(c)
                  wstate := 0
               else
                  out_character(c)
               end
            end
         end
      end

   compact_symbol(s: STRING): STRING is
      require
         s /= Void
      local
         symb: STRING
      do
         Result := once ""
         if in_include or else in_ifdef or else in_define
            or else (in_macro and then reserved_cpp_words.has(s))
            or else reserved_words.has(s) then
            Result.copy(s)
         elseif symbols.has(s) then
            Result.copy(symbols.at(s))
         elseif s.count <= 3 then
            Result.copy(s)
            symb := Result.twin
            symbols.put(symb, s.twin)
         else
            counter.next
            Result.copy(once "Z")
            counter.append_in(Result)
            symb := Result.twin
            symbols.put(symb, s.twin)
         end
         if in_macro then
            if not in_include then
               in_include := (once "include").is_equal(s)
            end
            if not in_define then
               in_define := (once "define").is_equal(s)
            end
            in_ifdef := define_words.has(s)
         else
            in_include := False
            in_ifdef := False
            in_define := False
         end
      ensure
         Result /= Void
      end

   out_buffers(do_compact: BOOLEAN) is
      do
         if not wbuffer.is_empty then
            if do_compact then
               obuffer.prepend(compact_symbol(wbuffer))
            else
               obuffer.prepend(wbuffer)
            end
            wbuffer.clear
         end
         out_string(obuffer)
         obuffer.clear
      end

   out_string(s: STRING) is
      local
         i, n: INTEGER
      do
         n := s.count
         from
            i := 1
         until
            i > n
         loop
            out_character(s.item(i))
            i := i + 1
         end
      end

   out_character(c: CHARACTER) is
      do
         if wbuffer.is_empty then
            output.put_character(c)
            stripped_count.increment
         else
            obuffer.extend(c)
         end
         if c = '%N' then
            column := 0
         else
            column := column + 1
         end
         last_written := c
      end

feature {NONE}

   state:     INTEGER
         -- State machine

   in_macro:   BOOLEAN
         -- Are we inside a macro definition

   in_include: BOOLEAN
         -- Are we inside a #include

   in_ifdef:   BOOLEAN
         -- Are we inside a #ifdef

   in_define:  BOOLEAN
         -- Are we inside a #define

   hex_number: BOOLEAN
         -- Are we parsing a hexadecimal integer

   previous_previous_state, previous_state: INTEGER
   last_written: CHARACTER

   wstate: INTEGER
   wbuffer: STRING is ""
   obuffer: STRING is ""

   column: INTEGER
   output: TEXT_FILE_WRITE

   symbols: DICTIONARY[STRING, STRING] is
      once
         create Result.with_capacity(4096)
      end

   make is
      do
         create output.make
         state := 9
         wstate := 2
      end

   counter: COUNTER63 is
      once
         create Result.make
      end

   reserved_words: ARRAY[STRING] is
      once
         Result := <<
                     "auto"     "break"    "case"     "char"
                     "const"    "continue" "default"  "do"
                     "double"   "else"     "enum"     "extern"
                     "float"    "for"      "goto"     "if"
                     "int"      "long"     "main"     "register"
                     "return"   "short"    "signed"   "sizeof"
                     "static"   "struct"   "switch"   "typedef"
                     "union"    "unsigned" "void"     "volatile"
                     "while"
                     "main"
                   >>
      end

   reserved_cpp_words: ARRAY[STRING] is
      once
         Result := <<
                     "include" "ifdef" "ifndef" "define"
                     "if" "elif" "endif" "defined"
                     "error" "pragma"
                   >>
      end

   define_words: ARRAY[STRING] is
      once
         Result := <<
                     "ifdef" "ifndef" "defined"
                   >>
      end

invariant

   output /= Void

end
