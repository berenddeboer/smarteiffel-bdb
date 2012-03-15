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
deferred class PARSER
   --
   -- To share some features amongs parsers (actually the
   -- EIFFEL_PARSER and the ACE parser).
   --
inherit
   GLOBALS
   VISITABLE

feature {PARSER_VISITOR}

   accept(visitor: PARSER_VISITOR) is
      deferred
      end

feature {NONE}

   line, column: INTEGER
	 -- Current `line' number and current `column' number.

   current_line: STRING
	 -- Current line string of `text'.

   cc: CHARACTER
	 -- Current character in the `current_line'.

   pos(l, c: INTEGER): POSITION is
	 -- Initialize a new one at line `l' and column `c'.
      require
	 l >= 1; c >= 1
      deferred
      end

   end_of_text: CHARACTER is '%/0/'; -- Flag of the end of the `text'.

   last_comment: COMMENT
	 -- Void or waiting comment.

   drop_comments: BOOLEAN
	 -- When objects COMMENT are not necessary.

   skip_comments is
	 -- Skip separators and comments if any. Unless `drop_comments',
	 -- comments are stored in `last_comment'.
      local
	 sp: POSITION; stop: BOOLEAN
      do
	 from
	 until
	    stop
	 loop
	    inspect
	       cc
	    when ' ','%T','%N' then
	       next_char
	    when '-' then
	       next_char
	       if cc = '-' then
		  if drop_comments then
		     if line = parser_buffer.count then
			cc := end_of_text
			stop := True
		     else
			line := line + 1
			column := 1
			current_line := parser_buffer.item(line)
			if current_line.count = 0 then
			   cc := '%N'
			else
			   cc := current_line.first
			end
		     end
		  else
		     from
			sp := pos(line,column - 1)
			next_char
			lcs.clear_count
		     until
			cc = '%N'
		     loop
			lcs.extend(cc)
			next_char
		     end
		     if last_comment = Void then
			!!last_comment.make(sp,lcs.twin)
		     else
			last_comment.add_last(lcs.twin)
		     end
		  end
	       else
		  cc := '-'
		  column := column - 1
		  stop := True
	       end
	    else
	       stop := True
	    end
	 end
      end

   next_char is
      do
	 if column < current_line.count then
	    column := column + 1
	    cc := current_line.item(column)
	 elseif column = current_line.count then
	    column := column + 1
	    cc := '%N'
	 elseif line = parser_buffer.count then
	    cc := end_of_text
	 else
	    line := line + 1
	    column := 1
	    current_line := parser_buffer.item(line)
	    if current_line.count = 0 then
	       cc := '%N'
	    else
	       cc := current_line.first
	    end
	 end
      end

   start_line, start_column: INTEGER
	 -- To store beginning position of : `a_keyword', `a_integer',
	 -- `a_real', `skip1', `skip2' and `skip1unless2'.

   a_keyword(keyword: STRING): BOOLEAN is
	 -- Look for a `keyword' beginning strictly at current position, then,
	 -- `skip_comment' is automatically called. A keyword is never followed
	 -- by a character of this set: {'A'..'Z','a'..'z','0'..'9','_'}.
      require
	 keyword.count >= 1
	 not keyword.has('%N')
      local
	 c, i, j: INTEGER
	 bad_case: BOOLEAN
      do
	 i := column
	 c := keyword.count
	 if current_line.count - i + 1 >= c then
	    from
	       start_line := line
	       start_column := i
	       j := 1
	    until
	       c <= 0
	    loop
	       if current_line.item(i) = keyword.item(j) then
		  i := i + 1
		  j := j + 1
		  c := c - 1
	       elseif current_line.item(i).same_as (keyword.item(j)) then
		  i := i + 1
		  j := j + 1
		  c := c - 1
		  bad_case := True
	       else
		  c := -1
	       end
	    end
	 end
	 if c = 0 then
	    if i > current_line.count then
	       Result := True
	       cc := '%N'
	       column := i
	       skip_comments
	    else
	       inspect
		  current_line.item(i)
	       when ' ','%T','-' then
		  Result := True
		  cc := current_line.item(i)
		  column := i
		  skip_comments
	       when 'a'..'z','A'..'Z','0'..'9','_' then
	       else
		  Result := True
		  cc := current_line.item(i)
		  column := i
	       end
	    end
	 end
         if Result and bad_case and keyword /= fz_reference then
            error_handler.add_position (pos (start_line, start_column))
            error_handler.append (
               once "Wrong case for keyword, this will not work in SE 2.2. %
               %You should capitalize: '")
            error_handler.append(keyword)
            error_handler.append("'")
            error_handler.print_as_warning
         end
      end

   skip1(char: CHARACTER): BOOLEAN is
      do
	 if char = cc then
	    start_line := line
	    start_column := column
	    Result := True
	    next_char
	    skip_comments
	 end
      end

   fcp(msg: STRING) is
	 -- Fatal error at current position.
      do
	 error_handler.add_position(current_position)
	 error_handler.append(msg)
	 error_handler.print_as_fatal_error
      end

   wcp(msg: STRING) is
	 -- Warning at current position.
      do
	 warning(current_position,msg)
      end

   current_position: POSITION is
      do
	 Result := pos(line,column)
      end

   lcs: STRING is
	 -- Last Comment String.
      once
	 !!Result.make(80)
      end

   tmp_name: TMP_NAME
	 -- The temporary buffer for some name.

   em1 : STRING is "Underscore in fractionnal part must group 3 digits."
   em2 : STRING is "Feature name expected."
   em3 : STRING is "Index value expected (%"indexing ...%")."
   em4 : STRING is "Error in inspect."
   em5 : STRING is "Added %",%"."
   em6 : STRING is "Added %";%"."
   em7 : STRING is "Unexpected comma (deleted)."
   em8 : STRING is "Unexpected new line in manifest string."
   em9 : STRING is "Underscore in number must group 3 digits."
   em10: STRING is "Bad character constant."
   em11: STRING is "Bad clients list."
   em12: STRING is "Deleted extra coma."
   em13: STRING is "Deleted extra separator."
   em14: STRING is "Class name should use only uppercase letters."
   em15: STRING is "Name of the current class expected."
   em16: STRING is "Type mark expected."
   em17: STRING is "Unexpected character."
   em18: STRING is "Useless keyword deleted."

   em21: STRING is "A formal argument is not a writable variable."
   em22: STRING is "Bad creation/create (writable expected)."
   em23: STRING is "Bad creation/create (procedure name expected)."
   em24: STRING is "Deleted extra semi-colon."
   em25: STRING is "Identifier should use only lowercase letters."
   em26: STRING is "Same identifier appears twice (local/formal)."
   em27: STRING is "Added %"(%"."
   em28: STRING is "Added %")%"."
   em29: STRING is "Added %":%"."
   em30: STRING is "Expected %"[%" (to start generic argument list)."
   em31: STRING is "Expected %"]%" (to finish generic argument list)."
   em32: STRING is "Type mark expected."
   em34: STRING is "Bad agent (call expected)."
   em35: STRING is "Empty generic list (deleted)."
   em36: STRING is "Closing %"}%" expected."
   em37: STRING is "Unknown special character."
   em38: STRING is "Unexpected character in decimal ascii code."
   em39: STRING is "Bad (empty?) ascii code."
   em40: STRING is "Decimal CHARACTER code out of range."
   em41: STRING is "Error inside multi-line manifest string."
   em42: STRING is "Extra blank or tab character removed in multi-line %
                   %manifest string."
   em43: STRING is "Invalid free operator (the last character must be %
		   %a member of this +-*/\=<>@#|& character list.)."
   em44: STRING is "Invalid free operator. (This character cannot be used.)"
   em45: STRING is "Unexpected character in hexadecimal ascii code."
   em46: STRING is "Unexpected character in hexadecimal unicode."
      
end -- PARSER
