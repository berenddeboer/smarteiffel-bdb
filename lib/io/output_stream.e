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
deferred class OUTPUT_STREAM
   --
   -- This abstract class is the superclass of all classes representing
   -- an output stream of bytes.
   --

feature -- State of the stream:

   is_connected: BOOLEAN is
      deferred
      end

feature -- To write one character at a time:

   put_character(c: CHARACTER) is
      require
         is_connected
      deferred
      end

feature

   put_string(s: STRING) is
         -- Output `s' to current output device.
      require
         is_connected
         s /= Void
      local
         i, count: INTEGER
      do
         from
            i := 1
	    count := s.count
         until
            i > count
         loop
            put_character(s.item(i))
            i := i + 1
         end
      end

   put_unicode_string(unicode_string: UNICODE_STRING) is
         -- Output the UTF-8 encoding of the `unicode_string'.
      require
         unicode_string /= Void
      do
         tmp_string.clear_count
         unicode_string.utf8_encode_in(tmp_string)
         put_string(tmp_string)
      end

feature -- To write a number:

   frozen put_integer(i: INTEGER_64) is
         -- Output `i' to current output device.
      require
         is_connected
      do
         tmp_string.clear_count
         i.append_in(tmp_string)
         put_string(tmp_string)
      end

   frozen put_integer_format(i: INTEGER_64; s: INTEGER) is
         -- Output `i' to current output device using at most `s' character.
      require
         is_connected
      do
         tmp_string.clear_count
         i.append_in_format(tmp_string,s)
         put_string(tmp_string)
      end

   put_real(r: REAL) is
         -- Output `r' to current output device.
      require
         is_connected
      do
         tmp_string.clear_count
         r.append_in(tmp_string)
         put_string(tmp_string)
      end

   put_real_format(r: REAL; f: INTEGER) is
         -- Output `r' with only `f' digit for the fractionnal part.
         -- Examples:
         --    put_real(3.519,2) print "3.51".
      require
         is_connected
         f >= 0
      do
         tmp_string.clear_count
         r.append_in_format(tmp_string,f)
         put_string(tmp_string)
      end

   put_double(d: DOUBLE) is
         -- Output `d' to current output device.
      require
         is_connected
      do
         tmp_string.clear_count
         d.append_in(tmp_string)
         put_string(tmp_string)
      end

   put_double_format(d: DOUBLE; f: INTEGER) is
         -- Output `d' with only `f' digit for the fractionnal part.
         -- Examples:
         --    put_double(3.519,2) print "3.51".
      require
         is_connected
         f >= 0
      do
         tmp_string.clear_count
         d.append_in_format(tmp_string,f)
         put_string(tmp_string)
      end

   put_number(number: NUMBER) is
         -- Output the `number'.
      require
         number /= Void
      do
         tmp_string.clear_count
         number.append_in(tmp_string)
         put_string(tmp_string)
      end

feature -- Other features:

   put_boolean(b: BOOLEAN) is
         -- Output `b' to current output device according
         -- to the Eiffel format.
      require
         is_connected
      do
         tmp_string.clear_count
         b.append_in(tmp_string)
         put_string(tmp_string)
      end

   put_pointer(p: POINTER) is
         -- Output a viewable version of `p'.
      require
         is_connected
      do
         tmp_string.clear_count
         p.append_in(tmp_string)
         put_string(tmp_string)
      end

   put_new_line is
         -- Output a newline character.
      require
         is_connected
      do
         put_character('%N')
      end

   put_spaces(nb: INTEGER) is
      -- Output `nb' spaces character.
      require
         nb >= 0
      local
         count : INTEGER
      do
         from
         until
            count >= nb
         loop
            put_character(' ')
            count := count + 1
         end
      end

   append_file(file_name: STRING) is
      require
         is_connected
         ftools.is_readable(file_name)
      local
         c: CHARACTER
      do
         tmp_file_read.connect_to(file_name)
         from
            tmp_file_read.read_character
         until
            tmp_file_read.end_of_input
         loop
            c := tmp_file_read.last_character
            put_character(c)
            tmp_file_read.read_character
         end
         tmp_file_read.disconnect
      end

   flush is
	 -- forces a write of unwritten character (write my have been 
	 -- delayed, flush writes buffered characters)
      deferred
      end

   ftools: FILE_TOOLS

feature {NONE}

   basic_io_putc(byte: CHARACTER; stream: POINTER) is
      external "SmartEiffel"
      end

   basic_io_fwrite(buf: NATIVE_ARRAY[CHARACTER]; size: INTEGER; stream: POINTER) is
      external "SmartEiffel"
      end

   basic_io_flush(stream_pointer: POINTER) is
      external "SmartEiffel"
      end

   tmp_file_read: TEXT_FILE_READ is
      once
         !!Result.make
      end

   tmp_string: STRING is
      once
         !!Result.make(512)
      end

   
end -- OUTPUT_STREAM

