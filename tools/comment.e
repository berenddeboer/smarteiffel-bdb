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
class COMMENT
   --
   -- To store a comment (of one or more lines).
   --
   -- Note : for pretty printing, the original text source is stored.
   --

inherit GLOBALS; VISITABLE

creation make

creation {CLASS_CHECKER} fake_comment

feature

   start_position: POSITION

   short(h1, r1, h2, r2: STRING) is
      local
         i, j: INTEGER
         l: STRING
         c: CHARACTER
         open_quote: BOOLEAN
      do
         from
            i := list.lower
         until
            i > list.upper
         loop
            short_print.hook_or(h1,r1)
            short_print.hook("BECL")
            l := list.item(i)
            from
               j := 1
            until
               j > l.count
            loop
               c := l.item(j)
               inspect
                  c
               when '_' then
                  short_print.hook_or("Ucomment","_")
               when '`' then
                  open_quote := True
                  short_print.hook_or("op_quote","`")
               when '%'' then
                  if open_quote then
                     open_quote := False
                     short_print.hook_or("cl_quote","'")
                  else
                     short_print.a_character(c)
                  end
               else
                  short_print.a_character(c)
               end
               j := j + 1
            end
            short_print.hook("AECL")
            short_print.hook_or(h2,r2)
            i := i + 1
         end
      end

   pretty_print is
	 -- Print the comment, and finish with '%N' output.
      local
         i, column: INTEGER
      do
         if pretty_printer.column > 1
	    and then pretty_printer.last_character /= ' '
	  then
            pretty_printer.put_character(' ')
         end
         from
            column := pretty_printer.column
            i := list.lower
         until
            i > list.upper
         loop
            pretty_printer.put_string(once "--")
            pretty_printer.put_string(list.item(i))
            i := i + 1
            if i <= list.upper then
               from
                  pretty_printer.put_character('%N')
               until
                  pretty_printer.column = column
               loop
                  pretty_printer.put_character(' ')
               end
            end
         end
         pretty_printer.put_character('%N')
      ensure
         pretty_printer.indent_level = old pretty_printer.indent_level
      end

   count: INTEGER is
         -- Number of lines of the comment.
      do
         Result := list.count
      end

feature {INSTRUCTION_WITH_COMMENT}

   is_dummy_end_of_statement: BOOLEAN is
         -- Is this comment a dummy comment, i.e. a generated comment to end
         -- some statement.
      local
         first_line: STRING; c: INTEGER
      do
	 first_line := list.first
	 c := first_line.count
	 if first_line.first_substring_index(fz_if).in_range(1, 3) then
	    Result := c < 7
	 elseif first_line.first_substring_index(fz_inspect).in_range(1, 3) then
	    Result := c < 12
	 elseif first_line.first_substring_index(fz_loop).in_range(1, 3) then
	    Result := c < 9
	 elseif first_line.first_substring_index(fz_check).in_range(1, 3) then
	    Result := c < 10
	 elseif first_line.first_substring_index(fz_debug).in_range(1, 3) then
	    Result := c < 10
         end
	 if Result and then list.count > 1 then
	    -- Remove the dummy first line only:
	    list.remove(list.lower)
	    Result := False
	 end
      end

feature {E_FEATURE}

   is_dummy_feature_end(e_feature: E_FEATURE): BOOLEAN is
	 -- Is this comment a dummy en comment of the `e_feature'?
      local
	 first_line, name: STRING
      do
	 name := e_feature.first_name.to_string
	 first_line := list.first
	 if first_line.first_substring_index(name).in_range(1, 3) then
	    Result := first_line.count < (name.count + 5)
	 end
	 if Result and then count > 1 then
	    list.remove(list.lower)
	    Result := False
	 end
      end

feature {BASE_CLASS}

   is_dummy_base_class_end(base_class: BASE_CLASS): BOOLEAN is
	 -- Is this comment a dummy en comment of the `base_class'?
      local
	 first_line, name: STRING
      do
	 name := base_class.name.to_string
	 first_line := list.first
	 if first_line.first_substring_index(name).in_range(1, 9) then
	    Result := True
	 end
	 if Result and then count > 1 then
	    list.remove(list.lower)
	    Result := False
	 end
      end

   good_end(name: CLASS_NAME) is
      do
         if not list.item(1).has_substring(name.to_string) then
            error_handler.add_position(name.start_position)
            warning(start_position,"Bad comment to end a class.")
         end
      end

feature {COMMENT, COMMENT_VISITOR}

   list: ARRAY[STRING]
         -- The contents of the comment.

feature {PARSER}

   add_last(l: STRING) is
      require
         l /= Void
      do
         list.add_last(l)
      ensure
         count = 1 + old count
      end

feature {PARSER}

   append(other: like Current) is
      require
         other /= Void
      local
         i: INTEGER
      do
         from
            i := 1
         until
            i > other.list.upper
         loop
            add_last(other.list.item(i))
            i := i + 1
         end
      end

feature {COMMENT_VISITOR}

   accept(visitor: COMMENT_VISITOR) is
      do
         visitor.visit_comment(Current)
      end

feature {NONE}

   make(sp: like start_position; first: STRING) is
      require
         not sp.is_unknown
         first /= Void
      do
         start_position := sp
	 create list.with_capacity(4, 1)
         list.add_last(first)
      ensure
         start_position = sp
         list.first = first
      end

   fake_comment(bc: BASE_CLASS; multi_line: STRING) is
	 -- To create a multi-line comment for `bc' in a single step.
      require
	 multi_line.has('%N')
      local
	 one_line: STRING; i1, i2: INTEGER
      do
	 start_position.set_in(bc)
	 create list.with_capacity(1 + multi_line.occurrences('%N'), 1)
	 from
	    i1 := 1; i2 := 1
	 until
	    i2 = 0
	 loop
	    i2 := multi_line.index_of('%N', i1)
	    if i2 = 0 then
	       -- The very last line:
	       one_line := multi_line.substring(i1, multi_line.count)
	    else
	       one_line := multi_line.substring(i1, i2 - 1)
	       i1 := i2 + 1
	    end
	    one_line.add_first(' ')
	    list.add_last(one_line)
	 end
      end

invariant

   not start_position.is_unknown

   not list.is_empty

   list.lower = 1

end -- COMMENT
