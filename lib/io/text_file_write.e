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
class TEXT_FILE_WRITE
   --
   -- Basic output facilities to write a named file on the disk.
   --
   -- Note: most features are common with STD_OUTPUT so you can test your
   --       program first on the screen and then, changing of instance
   --       (STD_OUTPUT/TEXT_FILE_WRITE), doing the same on a file.
   --

inherit
   OUTPUT_STREAM
   MEMORY redefine dispose end
   FILE

creation make, connect_to, connect_for_appending_to

feature

   path: STRING
         -- Not Void when connected to the corresponding file
         -- on the disk.

   is_connected: BOOLEAN is
      do
         Result := path /= Void
      end

   connect_to(new_path: STRING) is
	 -- Truncate file to zero length or create text file for writing.
	 -- The stream is positioned at the beginning of the file.
      local
         p: POINTER
      do
         p := new_path.to_external
         output_stream := basic_io_text_file_write_open(p)
         if output_stream.is_not_null then
            path := new_path
	    if capacity =0 then
	       buffer := buffer.calloc(4096)
	       capacity := 4096
	    end
         end
      end

   connect_for_appending_to(new_path: STRING) is
	 -- Open for writing. The file is created if it does not exist.
	 -- The stream is positioned at the end of the file.
      require
         not is_connected
         not new_path.is_empty
      local
         p: POINTER
      do
         p := new_path.to_external
         output_stream := basic_io_text_file_write_append(p)
         if output_stream.is_not_null then
            path := new_path
	    if capacity = 0 then
	       buffer := buffer.calloc(4096)
	       capacity := 4096
	    end
         end
      end

   disconnect is
      do
	 if buffer_position > 0 then
	    write_buffer
	 end
         basic_io_fclose(output_stream)
         path := Void
      end

   flush is
      do
	 if buffer_position > 0 then
	    write_buffer
	 end
         basic_io_flush(output_stream)
      end

   put_character(c: CHARACTER) is
      do
         if buffer_position >= 4096 then
            write_buffer
         end 
	 buffer.put(c, buffer_position)
         buffer_position := buffer_position + 1
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
   
   basic_io_text_file_write_open(path_pointer: POINTER): POINTER is
      external "SmartEiffel"
      end

   basic_io_text_file_write_append(path_pointer: POINTER): POINTER is
      external "SmartEiffel"
      end

   basic_io_fclose(stream_pointer : POINTER) is
      external "SmartEiffel"
      end

end -- TEXT_FILE_WRITE
