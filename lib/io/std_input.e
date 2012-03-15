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
class STD_INPUT
--
-- To use the standard input file. As for UNIX, the default standard
-- input is the keyboard.
--
-- Notes : - the predefined `std_input' should be use to have only
--         one instance of the class STD_INPUT.
--         - to do reading or writing at the same time on the screen,
--         see STD_INPUT_OUTPUT,
--         - to handle cursor of the screen, see CURSES.
--

inherit INPUT_STREAM

creation make

feature
   is_connected: BOOLEAN is True

feature
   make is
      do
	 buffer := buffer.calloc(4096)
	 capacity := 4096
      end

feature
   push_back_flag: BOOLEAN

   read_character is 
      do 
         if std_output.buffer_position > 0 then
            std_output.flush
         end
	 push_back_flag := False; 
	 if buffer_position >= buffer_size then 
	    fill_buffer
	 end 
	 last_character := buffer.item(buffer_position); 
	 buffer_position := buffer_position + 1 
	 end_of_input := end_reached
      end; 

   unread_character is
      do
         push_back_flag := True
	 end_of_input := False
	 buffer_position := buffer_position - 1
      end

   last_character: CHARACTER 

   end_of_input: BOOLEAN

   read_line_in(str: STRING) is
      local
         i: INTEGER
	 stop: BOOLEAN
	 old_count, new_count: INTEGER
	 initial_count: INTEGER      
      do
	 if std_output.buffer_position > 0 then
	    std_output.flush
	 end
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
	 push_back_flag := False; 
	 end_of_input := end_reached
      end


feature {NONE} 
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
         buffer_size := basic_io_read_stdin(buffer, 4096)
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
   basic_io_read_stdin(buf: NATIVE_ARRAY[CHARACTER]; size: INTEGER): INTEGER is
      -- return size read or 0 if end of input (-1 on error => exception ?)
      external "SmartEiffel"
      end

   basic_io_stdin: POINTER is
      external "SmartEiffel"
      end

end -- STD_INPUT
