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
class STD_INPUT_OUTPUT
   --
   -- To have the useful `io' of class ANY.
   --

inherit
   INPUT_STREAM
   OUTPUT_STREAM

creation make

feature
   is_connected: BOOLEAN is True

   make is
      do
      end

   read_character is
      do
	 std_input.read_character
      end

   unread_character is
      do
	 std_input.unread_character
      end

   push_back_flag: BOOLEAN is
      do
	 Result := std_input.push_back_flag
      end

   last_character: CHARACTER is
      do
	 Result := std_input.last_character
      end

   put_character(c: CHARACTER) is
      do
	 std_output.put_character(c)
      end

   end_of_input: BOOLEAN is
      do
	 Result := std_input.end_of_input
      end

   read_line_in(str: STRING) is
      do
	 std_input.read_line_in(str)
      end

   flush is
      do
	 std_output.flush
      end

end -- STD_INPUT_OUTPUT


