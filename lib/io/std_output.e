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
class STD_OUTPUT
--
-- To use the standard output file. As for UNIX, the default standard
-- output is the screen.
--
-- Notes: - the predefined `std_output' should be use to have only one instance
--        of the class STD_OUTPUT,
--        - to do reading or writing at the same time on the screen,
--        see STD_INPUT_OUTPUT,
--

inherit OUTPUT_STREAM

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

   put_character(c: CHARACTER) is
      do
         if buffer_position >= 4096 then
            write_buffer
         end 
	 buffer.put(c, buffer_position)
         buffer_position := buffer_position + 1 
	 if c = '%N' then
	    write_buffer
	 end
      end

   flush is
      do
	 if buffer_position > 0 then
	    write_buffer
	 end
	 basic_io_flush(basic_io_stdout)
      end


feature {STD_INPUT}
   buffer_position: INTEGER

feature {NONE}
   buffer: NATIVE_ARRAY[CHARACTER]
   capacity: INTEGER

   write_buffer is
      do
	 if buffer_position > 0 then
	    basic_io_fwrite(buffer, buffer_position, basic_io_stdout)
	    buffer_position := 0
	 end
      end
   
   basic_io_stdout: POINTER is
      external "SmartEiffel"
      end

end -- STD_OUTPUT

