-- This  file  is  free software,  which comes along with SmartEiffel.  This
-- software is distributed in the hope that it will be useful,  but  WITHOUT
-- ANY  WARRANTY;  without  even the  implied warranty of MERCHANTABILITY or
-- FITNESS FOR A PARTICULAR PURPOSE. You can modify it as you want, provided
-- this header is kept unaltered, and a notification of the changes is added.
-- You  are  allowed  to  redistribute it and sell it, alone or as a part of
-- another product.
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
class TEXT_FILE_READ
   --
   -- Basic input facilities to read a named file on the disc.
   --
   -- Note: most features are common with STD_INPUT so you can test your
   --       program on the screen first and then, just changing of
   --       instance (STD_INPUT/TEXT_FILE_READ), doing the same in a file.
   --

inherit INPUT_STREAM; FILE

creation make, connect_to

feature

   path: STRING
         -- Not Void when connected to the corresponding file on the disk.

   is_connected: BOOLEAN is
      do
         Result := path /= Void
      ensure
	 definition: Result = (path /= Void)
      end

   connect_to(new_path: STRING) is
	 --  Open text file for reading. The stream is positioned at the
	 --  beginning of the file.
      local
         p: POINTER
      do
         p := new_path.to_external
         input_stream := basic_io_text_file_read_open(p)
         if input_stream.is_not_null then
            push_back_flag := false
	    end_of_input := False
            path := new_path
	    if capacity = 0 then
	       buffer := buffer.calloc(4096)
	       capacity := 4096
	    end
	    end_reached := False
	    buffer_position := 0
	    buffer_size := 0
         end
      end

   disconnect is
      do
         basic_io_fclose(input_stream)
         path := Void
      end

   read_character is 
      do 
	 push_back_flag := False
	 if buffer_position >= buffer_size then 
	    fill_buffer
	 end 
	 last_character := buffer.item(buffer_position)
	 buffer_position := buffer_position + 1 
	 end_of_input := end_reached
      end

   unread_character is
      do
         push_back_flag := True
	 end_of_input := False
	 buffer_position := buffer_position - 1
      end

   last_character: CHARACTER 

   end_of_input: BOOLEAN

   push_back_flag: BOOLEAN

   read_line_in(str: STRING) is
      local
         i: INTEGER
	 stop: BOOLEAN
	 old_count, new_count: INTEGER
	 initial_count: INTEGER      
      do
	 from
	    initial_count := str.count
	 until
	    stop
	 loop
	    -- search %N in buffer
	    from
	       i := buffer_position
	    until
	       i >= buffer_size or else buffer.item(i) = '%N'
	    loop
	       i := i + 1
	    end

	    -- block copy (but copy_slice copies char by char...)
	    if i > buffer_position then
	       old_count := str.count
	       new_count := old_count + i - buffer_position
	       if str.capacity < new_count then
		  str.resize((old_count*2).max(new_count))
	       end
	       str.storage.copy_slice(old_count, buffer, buffer_position, i-1)
	       str.set_count(new_count)
	    end

	    -- next buffer if needed
	    if i < buffer_size and then buffer.item(i) = '%N' then
	       stop := True
	       buffer_position := i + 1
	       if str.count > initial_count and then str.last = '%R' then
		  str.remove_last(1)
		  -- UNIX uses the Linefeed character (ASCII character 10) to 
		  -- denote the end of a line. DOS uses the Carriage Return 
		  -- followed by the Linefeed character (ASCII character 13 
		  -- & ASCII character 10) to denote a new line.
	       end
	    else
	       if not end_reached then
		  fill_buffer
	       end
	       stop := end_reached
	    end
	 end
	 push_back_flag := False
	 end_of_input := end_reached
      end

feature {FILE_TOOLS}

   same_as(other: like Current): BOOLEAN is
      require
         is_connected
         other.is_connected
      local
	 b1, b2: NATIVE_ARRAY[CHARACTER]
	 i: INTEGER
      do
         from
	    fill_buffer
	    b1 := buffer
	    other.fill_buffer
	    b2 := other.buffer
	    Result := True
         until
	    not Result or else
	    end_reached or else other.end_reached
         loop
	    if buffer_size = other.buffer_size then
	       if b1.item(0) /= b2.item(0) then
		  Result := False
	       else
		  -- make first character different for loop end
		  b1.put('%R', 0)
		  b2.put('%N', 0)
		  from
		     i := buffer_size - 1
		  variant
		     i
		  until
		     b1.item(i) /= b2.item(i)
		  loop
		     i := i - 1
		  end
		  Result := i = 0
	       end
	       if Result then
		  fill_buffer
		  other.fill_buffer
	       end
	    else
	       from
		  read_character
		  other.read_character
	       until
		  not Result or else
		  end_of_input or else other.end_of_input
	       loop
		  Result := last_character = other.last_character
		  read_character
		  other.read_character
	       end
	    end
	 end
	 Result := Result and then end_reached
	    and then other.end_reached
         disconnect
         other.disconnect
      ensure
         not is_connected
         not other.is_connected
      end

feature {INPUT_STREAM}

   input_stream: POINTER

feature {TEXT_FILE_READ} 
   buffer: NATIVE_ARRAY[CHARACTER]
   end_reached: BOOLEAN
   buffer_position, buffer_size: INTEGER
   capacity: INTEGER

   fill_buffer is
      local
	 last: CHARACTER
      do 
	 if buffer_size > 0 then
	    last := buffer.item(buffer_size - 1)
	 end
         buffer_size := basic_io_fread(buffer, capacity, input_stream)

         buffer_position := 0
	 if buffer_size <= 0 then
	    end_reached := True
	    buffer.put(last, 0) -- needed for unread_character service
	    --if buffer_size = -1 => exception ?
	    buffer_size := 1
	    buffer_position := 1
	 end
      end
  
feature {NONE}

   make is
	 -- The new created object is not connected. (See also `connect_to'.)
      do
      ensure
	 not is_connected
      end

   basic_io_text_file_read_open(path_pointer: POINTER): POINTER is
      external "SmartEiffel"
      end

   basic_io_fclose(stream_pointer : POINTER) is
      external "SmartEiffel"
      end

end -- TEXT_FILE_READ

