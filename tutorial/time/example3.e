class EXAMPLE3
--
-- Using the TIME_IN_ENGLISH class.
--

creation make

feature {NONE}

   make is
      local
         time: TIME;
         format: TIME_IN_ENGLISH;
      do
         time.update;
         format.set_time(time);
         io.put_string("The complete format :%N");
         format.set_short_mode(false);
         format.print_on(io);
         io.put_new_line;
         io.put_string("The short format :%N");
         format.set_short_mode(true);
         format.print_on(io);
         io.put_new_line;
      end;

end
