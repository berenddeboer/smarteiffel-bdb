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
class NULL_INPUT
   --
   -- This "null" stream provides an unbroken sequence of '%U'
   -- (like /dev/zero does on Unix)
   --
inherit
   INPUT_STREAM

feature

   is_connected: BOOLEAN is True

   end_of_input: BOOLEAN is False

   read_character is
      do
         push_back_flag := False
      end

   last_character: CHARACTER is '%U'

   push_back_flag: BOOLEAN

   unread_character is
      do
         push_back_flag := True
      end

   read_line_in(buffer: STRING) is
      do
         buffer.fill_with('%U')
      end

end -- NULL_INPUT
