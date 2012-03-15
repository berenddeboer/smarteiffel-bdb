
class EXAMPLE5
--
-- Using different languages: TIME_IN_FRENCH, TIME_IN_ENGLISH,
-- TIME_IN_ITALIAN, TIME_IN_GERMAN, ...
--

creation make

feature {NONE}

   make is
      local
         time: TIME;
         french: TIME_IN_FRENCH;
         english: TIME_IN_ENGLISH;
         italian: TIME_IN_ITALIAN;
	 german: TIME_IN_GERMAN;
	 spanish : TIME_IN_SPANISH
      do
         time.update;

         io.put_string("The French format :%N");
         french.set_time(time);
         show_time(french);

         io.put_string("The English format :%N");
         english.set_time(time);
         show_time(english);

         io.put_string("The Italian format :%N");
         italian.set_time(time);
         show_time(italian);

         io.put_string("The German format :%N");
         german.set_time(time);
         show_time(german);

         io.put_string("The Spanish format :%N");
         spanish.set_time(time);
         show_time(spanish);
      end;

   show_time(format: TIME_IN_SOME_LANGUAGE) is
      do
         format.set_short_mode(false);
         io.put_string("        ");
         io.put_string(format.to_string);
         io.put_string("%N        ");
         format.set_short_mode(true);
         io.put_string(format.to_string);
         io.put_new_line;
      end;

end
