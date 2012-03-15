class EXAMPLE2
--
-- This example shows how to know about time variation using
-- class TIME.
--

creation make

feature {NONE}

   make is
      local
         time1, time2: TIME; clock: CLOCK;
	 clock_value1, clock_value2, periods: INTEGER;
	 seconds: DOUBLE;
      do
	 if clock.value >= 0 then
	    clock_value1 := clock.value;
	 end;
         time1.update;
         from
            time2.update;
         until
            time2 > time1
         loop
            time2.update;
         end;
	 clock_value2 := clock.value;

         io.put_string("Elapsed time: ");
         io.put_integer(time1.elapsed_seconds(time2).floor);
         io.put_string(" seconds%N");

	 if clock_value1 >= 0 then
	    io.put_string("Elapsed time in number of clock periods: ");
	    periods := clock_value2 - clock_value1;
	    io.put_integer(periods);
	    io.put_string(" (sec: ");
	    seconds := periods / clock.periods_per_second;
	    io.put_double(seconds);
	    io.put_string(")%N");
	 end;
      end;

end
