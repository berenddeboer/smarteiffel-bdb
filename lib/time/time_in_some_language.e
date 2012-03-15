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
deferred class TIME_IN_SOME_LANGUAGE
   --
   -- The polymophic format class for BASIC_TIME.
   --

inherit ANY redefine out_in_tagged_out_memory end

feature

   time: TIME
	 -- The corresponding information to display.

   set_time(t: TIME) is
      do
         time := t
      ensure
         time = t
      end

   set_basic_time(bt: BASIC_TIME) is
      obsolete "Since release -0.74, you have to use `set_time' instead."
      do
	 time.set_time_memory(bt.time_memory)
      end

   short_mode: BOOLEAN
         -- Is the formatting mode set to the short (abbreviated)
         -- mode ?

   set_short_mode(value: BOOLEAN) is
      do
         short_mode := value
      ensure
         short_mode = value
      end

   day_in(buffer: STRING) is
         -- According to the current `short_mode', append in the `buffer'
         -- the name of the day.
      deferred
      end

   month_in(buffer: STRING) is
         -- According to the current `short_mode', append in the `buffer'
         -- the name of the month.
      deferred
      end

   frozen to_string: STRING is
      do
         to_string_buffer.clear_count
         append_in(to_string_buffer)
         Result := to_string_buffer.twin
      end

   append_in(buffer: STRING) is
      deferred
      end

   frozen out_in_tagged_out_memory is
      do
         append_in(tagged_out_memory)
      end

feature {NONE}

   to_string_buffer: STRING is
      once
	 !!Result.make(128)
      end

end
