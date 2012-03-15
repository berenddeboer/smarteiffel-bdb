class EXAMPLE6
--
-- Using BASIC_TIME with the FILE_TOOLS class.
--

creation make

feature {NONE}

   make is
      local
	 time: TIME;
	 time_in_english: TIME_IN_ENGLISH;
	 f: FILE_TOOLS
      do
	 io.put_string("Last modification of file %"example6.e%":%N");
	 time := f.last_change_of("example6.e");
	 time_in_english.set_time(time);
	 io.put_string(time_in_english.to_string);
	 io.put_string("%N");
      end;

end
