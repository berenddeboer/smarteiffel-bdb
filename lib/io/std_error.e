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
class STD_ERROR
--
-- To write on the standard error output. As for UNIX, the default
-- standard error file is the screen.
--
-- Note: only one instance of this class should be necessary (have a look
-- in the root classes to search for the good name to use).
--

inherit OUTPUT_STREAM

creation make

feature

   is_connected: BOOLEAN is True

feature

   make is
      do
      end

feature

   put_character(c: CHARACTER) is
      do
         basic_io_putc(c,basic_io_stderr)
      end

   flush is
      do
         basic_io_flush(basic_io_stderr)
      end

feature {NONE}

   basic_io_stderr: POINTER is
      external "SmartEiffel"
      end

end -- STD_ERROR

