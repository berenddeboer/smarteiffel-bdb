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
expanded class MICROSECOND_TIME
--
-- Date and time facilities (like TIME) plus an extra microsecond information.
--

inherit
   TIME --year, month, day, hour and seconds access.
      export {NONE}to_microsecond_time
      redefine update, is_equal, infix "<", elapsed_seconds
      end
feature
   microsecond: INTEGER
         -- Extra information in number of microseconds in range 0 .. 999999.
	 -- Note that the accuracy is system dependant.

   to_time: TIME is
      do
	 Result.set_time_memory(time_memory)
      ensure
	 Result.year = year
	 Result.month = month
	 Result.day = day
	 Result.hour = hour
	 Result.minute = minute
	 Result.second = second
      end

feature -- Setting:

   update is
         -- Update `Current' with the current system clock.
      do
         basic_microsecond_update
         time_memory := basic_microsecond_time
	 microsecond := basic_microsecond_microsecond
      end

   set_microsecond(microsec: INTEGER) is
         -- To set `microsecond' in range 0 .. 999 999.
      require
	 microsec.in_range(0, 999_999)
      do
	 microsecond := microsec
      ensure
	 microsecond = microsec
      end

   infix "+" (s: DOUBLE): like Current is
	 -- Add `s' seconds (2.476 is 2 seconds and 476 milliseconds)
      require
	 s >= 0.0
      local
	 a, b: INTEGER
      do
	 a := s.truncated_to_integer
	 b := ((s - a) * 1_000_000).truncated_to_integer
	 Result := Current
	 Result.add_second(a)
	 Result.add_microsecond(b)
      end

   add_millisecond(millisecond: INTEGER) is
	 -- Add `millisecond' milliseconds.
      require
	 millisecond.in_range(0, 999)
      do
	 add_microsecond(millisecond * 1000)
      ensure
	 Current >= old Current
      end

   add_microsecond(microsec: INTEGER) is
	 -- Add `microsec' microseconds
      require
	 microsec.in_range(0, 999_999)
      local
	 a: INTEGER
      do
	 a := microsec + microsecond
	 if a >= 1_000_000 then
	    add_second(1)
	    a := a - 1_000_000
	 end
	 microsecond := a
      ensure
	 Current >= old Current
      end

feature

   elapsed_seconds(other: like Current): DOUBLE is
         -- Elapsed time in seconds from `Current' to `other' with sub-second
	 -- precision.
      do
         Result := basic_time_difftime(other.time_memory, time_memory)
	 Result := Result + ((other.microsecond - microsecond) / 1_000_000)
      end

   is_equal(other: like Current): BOOLEAN is
      do
	 if microsecond = other.microsecond then
	    Result := time_memory = other.time_memory
	 end
      end

   infix "<" (other: like Current): BOOLEAN is
      local
	 sec: INTEGER
      do
         sec := basic_time_difftime(other.time_memory, time_memory).floor
	 Result := sec > 0 or else 
			(sec = 0 and then microsecond < other.microsecond)
      ensure then
	 Result implies (elapsed_seconds(other) > 0)
      end

feature {NONE}

   basic_microsecond_time: INTEGER_64 is
      external "SmartEiffel"
      end

   basic_microsecond_microsecond: INTEGER is
      external "SmartEiffel"
      end

   basic_microsecond_update is
      external "SmartEiffel"
      end

invariant

   microsecond.in_range(0,999999)

end -- MICROSECOND_TIME
