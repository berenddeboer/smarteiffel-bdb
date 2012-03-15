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
class MINI_BUFFER
   --
   -- This mini buffer is used to parse information inside MANIFEST_STRING 
   -- objects (used for example to parse external feature definition). This 
   -- singleton object is shared via the GLOBALS.`mini_buffer' once function.

inherit
   GLOBALS
   VISITABLE

feature {MINI_BUFFER_VISITOR}

   accept(visitor: MINI_BUFFER_VISITOR) is
      do
         visitor.visit_mini_buffer(Current)
      end

feature -- A simple ITERATOR like interface:

   start_with(ms: MANIFEST_STRING) is
	 -- Getting started with `ms', the `item' is set with the 
	 -- first non-blank character.
      require
	 ms /= Void
      do
	 manifest_string := ms
	 to_string := manifest_string.to_string
	 count := to_string.count
	 idx := 1
	 skip_separators
      ensure
	 manifest_string = ms
	 not is_off implies not item.is_separator
      end

   item: CHARACTER is
	 -- The one at current position.
      require
	 not is_off
      do
	 Result := to_string.item(idx)
      end

   is_off: BOOLEAN is
      do
	 Result := idx > count
      end

   next is
      require
	 not is_off
      do
	 idx := idx + 1
      end

feature

   skip_separators is
	 -- (Use `is_separator' of class CHARACTER.)
      do
	 from 
	 until
	    idx > count or else not to_string.item(idx).is_separator
	 loop
	    idx := idx + 1
	 end
      ensure
	 not is_off implies not item.is_separator
      end

   a_keyword(keyword: STRING): BOOLEAN is
	 -- Look for a `keyword' beginning strictly at current position, then,
	 -- `skip_separators' is automatically called. A keyword is never followed 
	 -- by a character of this set: {'A'..'Z','a'..'z','0'..'9','_'}.
      require
	 not item.is_separator
      local
	 idx_memory, i: INTEGER; stop: BOOLEAN
      do
	 idx_memory := idx
	 from
	    i := 1
	 until
	    stop
	 loop
	    if i > keyword.count then
	       stop := True
	    elseif idx > count then
	       stop := True
	    elseif to_string.item(idx) = keyword.item(i) then
	       i := i + 1
	       idx := idx + 1
	    else
	       stop := True
	    end
	 end
	 if i > keyword.count then
	    skip_separators
	    Result := True
	 else
	    idx := idx_memory
	 end
      ensure
	 is_off or else not item.is_separator
      end
   
   a_word(keyword: STRING): BOOLEAN is
	 -- Is it a single stand-alone `keyword'?
      require
	 not item.is_separator
      local
	 idx_memory: INTEGER
      do
	 idx_memory := idx
	 if a_keyword(keyword) then
	    if idx > count then
	       Result := True
	    else
	       idx := idx_memory
	    end
	 end
      ensure
	 Result implies is_off
      end

   a_include: STRING is
	 -- Always return some file name wich may looks like a file 
	 -- to include: "....foo.h" or <...foo.h>. When the file name 
	 -- is not properly brace with "..." or <...>, the standard 
	 -- "..." are automatically added.
      require
	 not item.is_separator
      local
	 stop: BOOLEAN
      do
	 from
	    Result := once ".... local unique buffer ...."
	    Result.clear_count
	    Result.extend(item)
	    next
	 until
	    stop
	 loop
	    if is_off then
	       stop := True
	    elseif item.is_separator then
	       stop := True
	    elseif item = ',' then
	       stop := True
	    else
	       Result.extend(item)
	       next
	    end
	 end
	 inspect
	    Result.first
	 when '%"', '<' then
	 else
	    Result.add_first('%"')
	    Result.add_last('%"')
	 end
	 Result := Result.twin
      ensure
	 is_off or else not item.is_separator
      end

   a_field_or_variable_name: STRING is
      do
	 Result := a_type_cast
      ensure
	 is_off or else not item.is_separator
      end

   a_type_cast: STRING is
	 -- Read an expected C cast.
      require
	 not item.is_separator      
      local
	 stop: BOOLEAN
      do
	 from
	    Result := once ".... local unique buffer ...."
	    Result.clear_count
	    Result.extend(item)
	    next
	 until
	    stop
	 loop
	    if is_off then
	       stop := True
	    elseif item = ',' then
	       stop := True
	    elseif item.is_separator then
	       stop := True;	       
	    else
	       Result.extend(item)
	       next
	       if Result.last = ')' then
		  if Result.occurrences('(') < Result.occurrences(')') then
		     idx := idx - 1
		     Result.remove_last(1)
		     stop := True
		  end
	       end
	    end
	 end
	 Result := Result.twin
	 skip_separators
      ensure
	 is_off or else not item.is_separator
      end

   a_signature: FAST_ARRAY[STRING] is
	 -- Read the expected external signature.
      require
	 not item.is_separator      
      local
	 stop: BOOLEAN; external_cast: STRING
      do
	 if item /= '(' then
	    error_handler.append("Bad external signature (missing opening %"(%" %
		      %delimiter.")
	    error_handler.print_as_fatal_error
	 end
	 from
	    next; skip_separators
	    create Result.with_capacity(8)
	    Result.add_last(Void)
	 until
	    stop
	 loop
	    if is_off then
	       error_handler.append("Bad external signature (missing %")%" %
                         %delimiter.")
	       error_handler.print_as_fatal_error
	    elseif item = ',' then
	       next; skip_separators
	    elseif item = ')' then
	       stop := True
	       next; skip_separators
	    else
	       external_cast := a_type_cast
	       Result.add_last(external_cast)
	    end
	 end
      ensure
         Result.count > 1
	 is_off or else not item.is_separator
      end

feature {NONE}

   manifest_string: MANIFEST_STRING
	 -- The one currently parsed.

   to_string: STRING
	 -- To cache `manifest_string.to_string'.

   count: INTEGER
	 -- To cache `to_string.count'.

   idx: INTEGER
	 -- The current position in `to_string'.

   singleton_memory: MINI_BUFFER is
      once
	 Result := Current
      end

invariant

   is_real_singleton: Current = singleton_memory

end -- MINI_BUFFER
