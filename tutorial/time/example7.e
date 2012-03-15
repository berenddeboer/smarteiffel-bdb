class EXAMPLE7
--
-- Using MICROSECOND_TIME to get more accuracy.
--

creation make

feature {NONE}

   make is
      local
	 mt1, mt2: MICROSECOND_TIME;
	 string: STRING;
      do
	 print("Time to create a new small STRING:%N");
	 mt1.update;
	 create string.make(12);
	 mt2.update;
	 print_microsecond_time(mt1);
	 print_microsecond_time(mt2);
      end;

   print_microsecond_time(mt: MICROSECOND_TIME) is
      local
	 time_in_english: TIME_IN_ENGLISH;
      do
	 time_in_english.set_short_mode(true);
	 time_in_english.set_time(mt.to_time);
	 print(time_in_english.to_string  + " " + mt.second.to_string +
	       " seconds and " + mt.microsecond.to_string + " microseconds%N");
      end;

end
