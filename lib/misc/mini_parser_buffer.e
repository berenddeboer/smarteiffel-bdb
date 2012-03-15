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
class MINI_PARSER_BUFFER
   --
   -- Useful and efficient mini parsing buffer.
   -- From the user point of view, an object of this class can be considered 
   -- as the combination of a STRING to be parsed with an extra INTEGER 
   -- index to memorize the current position in this STRING. 
   -- Beside the fact that this object provides the current position 
   -- memorization inside the STRING to be parsed, the implementation is 
   -- also more efficient than the one you may get by using the traditional 
   -- STRING interface.
   --
   
inherit STRING_HANDLER
   
feature

   initialize_with(string: STRING) is
	 -- Initialize the `Current' buffer using the content of the 
	 -- `string'.
      require
	 string /= Void
      do
	 internal_index := 0
	 upper := string.count - 1
	 capacity := string.capacity
	 storage := string.storage
	 last_error := Void
      ensure
	 count = string.count
	 last_error = Void
      end

   count: INTEGER is
         -- The length of the `Current' buffer which is also the maximum 
         -- valid index.
      do
	 Result := upper + 1
      end

   current_index: INTEGER is
	 -- Index of the current character.
      do
	 Result := internal_index + 1
      end
   
   current_character: CHARACTER is
	 -- The current character (the one at `current_index').
      require
	 current_index.in_range(1, count)
      do
	 Result := storage.item(internal_index)
      end

   end_reached: BOOLEAN is
	 -- Is the end of the buffer reached?
      do
	 Result := internal_index > upper
      ensure
	 Result = (current_index > count)
      end

   next is
	 -- Move the `current_index' forward by one.
      require
	 not end_reached
      do
	 internal_index := internal_index + 1
      ensure
	 current_index = 1 + old current_index
      end
   
   skip_separators is
         -- Skip all separators by using `is_separator' of class CHARACTER.
      local
	 stop:  BOOLEAN
      do
	 from until stop
	 loop
	    if internal_index > upper then
	       stop := True
	    elseif storage.item(internal_index).is_separator then
	       internal_index := internal_index + 1
	    else
	       stop := True
	    end
	 end
      end

   last_error: STRING
	 -- Can be used to memorize an error message.

   set_last_error(error_msg: like last_error) is
      do
	 last_error := error_msg
      ensure
	 last_error = error_msg
      end
   
feature {NONE}

   storage: NATIVE_ARRAY[CHARACTER]
	 -- The `storage' area to be parsed.
   
   capacity: INTEGER
	 -- Of `storage'.
   
   upper: INTEGER
	 -- Maximum valid index in storage.
   
   internal_index: INTEGER
	 -- Of the current character in `storage'.
   
end -- MINI_PARSER_BUFFER

