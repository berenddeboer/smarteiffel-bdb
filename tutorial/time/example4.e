class EXAMPLE4
--
-- Using the TIME_IN_FRENCH class.
--

creation make

feature {NONE}

   make is
      local
         time: TIME;
         format: TIME_IN_FRENCH;
      do
         time.update;
         format.set_time(time);
         io.put_string("Le grand format :%N");
         format.set_short_mode(false);
         format.print_on(io);
         io.put_new_line;
         io.put_string("Le petit format :%N");
         format.set_short_mode(true);
         format.print_on(io);
         io.put_new_line;
      end;

end
