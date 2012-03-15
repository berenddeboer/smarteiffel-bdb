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
class BINARY_FILE_READ
   -- This class allow to read a file on the disk as a binary file 
   -- (ie. file containing bytes). If you need to read a file which 
   -- contain text, then consider using TEXT_FILE_READ.

inherit FILE

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
	 -- Open binary file for reading. The stream is positioned at the
	 -- beginning of the file.
      do
         input_stream := basic_io_binary_file_read_open(new_path.to_external)
         if input_stream.is_not_null then
            path := new_path
	    end_of_input := False
	    if capacity = 0 then
	       buffer := buffer.calloc(4096)
	       capacity := 4096
	    end
	    buffer_position := 0
	    buffer_size := 0
         end
      end

   disconnect is
      do
         basic_io_fclose(input_stream)
         path := Void
      end

   read_byte is
         -- Read a byte and assign it to `last_byte'.
      require
         is_connected
         not end_of_input
      do
	 if buffer_position >= buffer_size then
	    fill_buffer
	 end 
	 last_byte := buffer.item(buffer_position).code
	 buffer_position := buffer_position + 1
      end

   last_byte: INTEGER
         -- Last byte read with `read_byte'.

   read_integer_16_native_endian is
	 -- Read in the same order as the machine running this code. If a 
	 -- 16-bits value is available, it's assigned to `last_integer_16'.
	 -- The result is machine dependant.
      require
	 is_connected
         not end_of_input
      local
	 c1, c2: CHARACTER
      do
	 if buffer_position >= buffer_size then
	    fill_buffer
	 end
	 c1 := buffer.item(buffer_position)
	 buffer_position := buffer_position + 1

	 if buffer_position >= buffer_size and then not end_of_input then
	    fill_buffer
	 end
	 c2 := buffer.item(buffer_position)
	 buffer_position := buffer_position + 1

	 last_integer_16 := as_16_ne(c1, c2)
      end

   read_integer_16_big_endian is
	 -- Read a big endian value is the file. If a 16-bits value
	 -- is available, it's assigned to `last_integer_16'.
      require
	 is_connected
         not end_of_input
      do
	 if buffer_position >= buffer_size then
	    fill_buffer
	 end
	 last_integer_16 := buffer.item(buffer_position).code |<< 8
	 buffer_position := buffer_position + 1

	 if buffer_position >= buffer_size and then not end_of_input then
	    fill_buffer
	 end
	 last_integer_16 := last_integer_16 | buffer.item(buffer_position).code
	 buffer_position := buffer_position + 1
      end

   read_integer_16_little_endian is
	 -- Read a little endian value is the file. If a 16-bits value
	 -- is available, it's assigned to `last_integer_16'.
      require
	 is_connected
         not end_of_input
      do
	 if buffer_position >= buffer_size then
	    fill_buffer
	 end
	 last_integer_16 := buffer.item(buffer_position).code
	 buffer_position := buffer_position + 1

	 if buffer_position >= buffer_size and then not end_of_input then
	    fill_buffer
	 end
	 last_integer_16 := last_integer_16 | 
				  (buffer.item(buffer_position).code |<< 8)
	 buffer_position := buffer_position + 1
      end

   last_integer_16: INTEGER
         -- Last byte read with `read_integer_16_*'.

   end_of_input: BOOLEAN
         -- Has end-of-input been reached ?
         -- True when the last character has been read.

feature {NONE}
   buffer: NATIVE_ARRAY[CHARACTER]
   buffer_position, buffer_size: INTEGER
   capacity: INTEGER

   input_stream: POINTER

   fill_buffer is
      do 
         buffer_size := basic_io_fread(buffer, capacity, input_stream)

         buffer_position := 0
	 if buffer_size <= 0 then
	    end_of_input := True
	    --if buffer_size = -1 => exception ?
	    buffer_size := 1
	    buffer_position := 1
	 end
      end

   make is
	 -- The new created object is not connected. (See also `connect_to'.)
      do
      ensure
	 not is_connected
      end

   basic_io_binary_file_read_open(path_pointer: POINTER): POINTER is
      external "SmartEiffel"
      end

   basic_io_fread(buf: NATIVE_ARRAY[CHARACTER]; size: INTEGER; stream_pointer: POINTER): INTEGER is
      -- return size read or 0 if end of input (-1 on error => exception ?)
      external "SmartEiffel"
      end

   basic_io_fclose(stream_pointer : POINTER) is
      external "SmartEiffel"
      end

   as_16_ne(c1, c2: CHARACTER): INTEGER_16 is
      external "SmartEiffel"
      end

end -- BINARY_FILE_READ

