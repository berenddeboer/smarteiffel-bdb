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
class BINARY_FILE_WRITE
   -- This class allow to write a file on the disk as a binary file 
   -- (ie. file containing bytes). If you need to write text in a file,
   -- then consider using TEXT_FILE_WRITE.

inherit
   MEMORY redefine dispose end
   FILE

creation make, connect_to, connect_for_appending_to

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
	 -- Truncate file to zero length or create binary file for writing.
	 -- The stream is positioned at the beginning of the file.
      local
	 p: POINTER
      do
	 p := new_path.to_external
         output_stream := basic_io_binary_file_write_open(p)
         if output_stream.is_not_null then
            path := new_path
	    if capacity =0 then
	       buffer := buffer.calloc(4096)
	       capacity := 4096
	    end
         end
      end

   connect_for_appending_to(new_path: STRING) is
	 -- Truncate file to zero length or create binary file for writing.
	 -- The stream is positioned at the beginning of the file.
      require
         not is_connected
         not new_path.is_empty
      local
	 p: POINTER
      do
	 p := new_path.to_external
         output_stream := basic_io_binary_file_write_append(p)
         if output_stream.is_not_null then
            path := new_path
	    if capacity =0 then
	       buffer := buffer.calloc(4096)
	       capacity := 4096
	    end
         end
      end

   flush is
	 -- forces a write of unwritten character (write my have been 
	 -- delayed, flush writes buffered characters)
      do
	 if buffer_position > 0 then
	    write_buffer
	 end
         basic_io_flush(output_stream)
      end

   disconnect is
      do
	 if buffer_position > 0 then
	    write_buffer
	 end
         basic_io_fclose(output_stream)
         path := Void
      end

   put_byte(byte: INTEGER) is
      require
         is_connected
      do
         if buffer_position >= 4096 then
            write_buffer
         end 
	 buffer.put(byte.to_character, buffer_position)
         buffer_position := buffer_position + 1
      end

   put_integer_16_native_endian(i: INTEGER_16) is
	 -- Write in the same order as the machine running this code.
	 -- The result is machine dependant.
      require
	 is_connected
      do
         if buffer_position >= 4095 or else buffer_position.odd then
            write_buffer
         end 
	 put_16_ne(buffer, i, buffer_position)
         buffer_position := buffer_position + 2
      end

   put_integer_16_big_endian(i: INTEGER_16) is
	 -- Write `i' in big endian mode.
	 -- The result is machine independant.
      require
	 is_connected
      do
         if buffer_position >= 4095 or else buffer_position.odd then
            write_buffer
         end
	 put_16_be(buffer, i, buffer_position)
         buffer_position := buffer_position + 2
      end

   put_integer_16_little_endian(i: INTEGER_16) is
	 -- Write `i' in little endian mode.
	 -- The result is machine independant.
      require
	 is_connected
      do
         if buffer_position >= 4095 or else buffer_position.odd then
            write_buffer
         end 
	 put_16_le(buffer, i, buffer_position)
         buffer_position := buffer_position + 2
      end

feature {NONE}
   buffer: NATIVE_ARRAY[CHARACTER]
   buffer_position: INTEGER
   capacity: INTEGER
   output_stream: POINTER

   make is
	 -- The new created object is not connected. (See also `connect_to' and
	 -- `connect_for_appending_to'.)
      do
	 buffer := buffer.calloc(4096)
	 capacity := 4096
      ensure
	 not is_connected
      end

   dispose is
      require
	 disconnect_file_after_use: not is_connected
      do
      end

   write_buffer is
      do
	 if buffer_position > 0 then
	    basic_io_fwrite(buffer, buffer_position, output_stream)
	    buffer_position := 0
	 end
      end
   
   put_16_ne(buf: NATIVE_ARRAY[CHARACTER]; i: INTEGER_16; ch_pos: INTEGER) is
      external "SmartEiffel"
      end

   put_16_le(buf: NATIVE_ARRAY[CHARACTER]; i: INTEGER_16; ch_pos: INTEGER) is
      external "SmartEiffel"
      end

   put_16_be(buf: NATIVE_ARRAY[CHARACTER]; i: INTEGER_16; ch_pos: INTEGER) is
      external "SmartEiffel"
      end

   basic_io_binary_file_write_open(path_pointer: POINTER): POINTER is
      external "SmartEiffel"
      end

   basic_io_binary_file_write_append(path_pointer: POINTER): POINTER is
      external "SmartEiffel"
      end

   basic_io_putc(byte: CHARACTER; stream: POINTER) is
      external "SmartEiffel"
      end

   basic_io_fwrite(buf: NATIVE_ARRAY[CHARACTER]; size: INTEGER; stream: POINTER) is
      external "SmartEiffel"
      end

   basic_io_flush(stream_pointer: POINTER) is
      external "SmartEiffel"
      end

   basic_io_fclose(stream_pointer : POINTER) is
      external "SmartEiffel"
      end

end -- BINARY_FILE_WRITE
