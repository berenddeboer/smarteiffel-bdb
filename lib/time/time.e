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
expanded class TIME
--
-- Time and date facilities: year, month, day, hour and seconds.
--

inherit
   HASHABLE redefine is_equal end
   COMPARABLE  redefine is_equal end

feature

   is_local_time: BOOLEAN is
         -- Is the local time in use? This information applies to all objects
         -- of class TIME and MICROSECOND_TIME.
      do
         Result := (time_mode = 0)
      ensure
         Result implies not is_universal_time
      end

   is_universal_time: BOOLEAN is
         -- Is Universal Time in use?  This information applies to all objects
         -- of class TIME and MICROSECOND_TIME.
      do
         Result := (time_mode /= 0)
      ensure
         Result implies not is_local_time
      end

   year: INTEGER is
         -- Number of the year.
      do
         Result := basic_time_getyear(time_memory, time_mode)
      end

   month: INTEGER is
         -- Number of the month (1 for January, 2 for February, ...
         -- 12 for December).
      do
         Result := basic_time_getmonth(time_memory, time_mode)
      ensure
         Result.in_range(1,12)
      end

   day: INTEGER is
         -- Day of the `month' in range 1 .. 31.
      do
         Result := basic_time_getday(time_memory, time_mode)
      ensure
         Result.in_range(1,31)
      end

   hour: INTEGER is
         -- Hour in range 0..23.
      do
         Result := basic_time_gethour(time_memory, time_mode)
      ensure
         Result.in_range(0,23)
      end

   minute: INTEGER is
         -- Minute in range 0 .. 59.
      do
         Result := basic_time_getminute(time_memory, time_mode)
      ensure
         Result.in_range(0,59)
      end

   second: INTEGER is
         -- Second in range 0 .. 59.
      do
         Result := basic_time_getsecond(time_memory, time_mode)
      ensure
         Result.in_range(0,59)
      end

   week_day: INTEGER is
         -- Number of the day in the week (Sunday is 0, Monday is 1, etc.).
      do
         Result := basic_time_getwday(time_memory, time_mode)
      ensure
         Result.in_range(0,6)
      end

   year_day: INTEGER is
         -- Number of the day in the year in range 0 .. 365.
      do
         Result := basic_time_getyday(time_memory, time_mode)
      end

   is_summer_time_used: BOOLEAN is
         -- Is summer time in effect?
      do
         Result := basic_time_is_summer_time_used(time_memory)
      end

   to_microsecond_time: MICROSECOND_TIME is
      do
	 Result.set_time_memory(time_memory)
      ensure
	 Result.to_time = Current
	 Result.microsecond = 0
      end

feature -- Setting:

   update is
         -- Update `Current' with the current system clock.
      do
         time_memory := basic_time_time
      end

   set(a_year, a_month, a_day, a_hour, a_min, sec: INTEGER): BOOLEAN is
         -- Try to set `Current' using the given information. If this input
         -- is not a valid date, the `Result' is false and `Current' is not updated.
      require
	 valid_month: a_month.in_range(1,12)
	 valid_day: a_day.in_range(1,31)
	 valid_hour: a_hour.in_range(0,23)
	 valid_minute: a_min.in_range(0,59)
	 valid_second: sec.in_range(0,59)
      local
         tm: like time_memory
      do
         tm := basic_time_mktime(a_year, a_month, a_day, a_hour, a_min, sec)
         if tm /= -1 then
            time_memory := tm
            Result := true
         end
      end

   add_second(s: INTEGER) is
	 -- Add `s' seconds to `Current'.
      require
	 --*** s >= 0
      do
	 basic_time_add_second($time_memory, s)
      ensure
	 Current >= old Current
      end

feature

   elapsed_seconds(other: like Current): DOUBLE is
         -- Elapsed time in seconds from `Current' to `other'.
      require
         Current <= other
      do
         Result := basic_time_difftime(other.time_memory, time_memory)
      ensure
         Result >= 0
      end

   is_equal(other: like Current): BOOLEAN is
      do
         Result := other.time_memory = time_memory
      end

   infix "<" (other: like Current): BOOLEAN is
      do
         Result := basic_time_difftime(other.time_memory, time_memory) > 0
      end

feature -- Setting common time mode (local or universal):

   set_universal_time is
      do
         time_mode_memo.set_item(1)
      ensure
         is_universal_time
      end

   set_local_time is
      do
         time_mode_memo.set_item(0)
      ensure
         is_local_time
      end

feature

   clock_periods: INTEGER is
         -- CPU clock value if available (-1 if not).
      obsolete "Since release -0.74, use feature `value' of class CLOCK."
      local
	 clock: CLOCK
      do
         Result := clock.value
      end

feature -- Hashing:

   hash_code: INTEGER is
      do
         Result := time_memory.hash_code
      end

feature {TIME, FILE_TOOLS, TIME_IN_SOME_LANGUAGE}

   set_time_memory(tm: like time_memory) is
      do
	 time_memory := tm
      ensure
	 time_memory = tm
      end

feature {TIME, TIME_IN_SOME_LANGUAGE}

   time_memory: INTEGER_64
         -- The current time value of `Current'. As far as I know, this
         -- kind of information should always fit into a integer_64.

feature {NONE}

   time_mode_memo: MEMO[INTEGER] is
         -- The global default `time_mode' memory.
      once
         !!Result
      end

   time_mode: INTEGER is
      do
         Result := time_mode_memo.item
      ensure
         Result = 0 or Result = 1
      end

   basic_time_time: INTEGER_64 is
      external "SmartEiffel"
      end

   basic_time_difftime(time2, time1: INTEGER_64): DOUBLE is
      external "SmartEiffel"
      end

   basic_time_getyear(tm: INTEGER_64; mode: INTEGER): INTEGER is
      external "SmartEiffel"
      end

   basic_time_getmonth(tm: INTEGER_64; mode: INTEGER): INTEGER is
      external "SmartEiffel"
      end

   basic_time_getday(tm: INTEGER_64; mode: INTEGER): INTEGER is
      external "SmartEiffel"
      end

   basic_time_gethour(tm: INTEGER_64; mode: INTEGER): INTEGER is
      external "SmartEiffel"
      end

   basic_time_getminute(tm: INTEGER_64; mode: INTEGER): INTEGER is
      external "SmartEiffel"
      end

   basic_time_getsecond(tm: INTEGER_64; mode: INTEGER): INTEGER is
      external "SmartEiffel"
      end

   basic_time_is_summer_time_used(tm: INTEGER_64): BOOLEAN is
      external "SmartEiffel"
      end

   basic_time_getyday(tm: INTEGER_64; mode: INTEGER): INTEGER is
      external "SmartEiffel"
      end

   basic_time_getwday(tm: INTEGER_64; mode: INTEGER): INTEGER is
      external "SmartEiffel"
      end

   basic_time_mktime(a_year, a_mon, a_day,
                     a_hour, a_min, a_sec: INTEGER): INTEGER_64 is
      external "SmartEiffel"
      end

   basic_time_add_second(time: POINTER; s: INTEGER) is
      external "SmartEiffel"
      end

end -- TIME
