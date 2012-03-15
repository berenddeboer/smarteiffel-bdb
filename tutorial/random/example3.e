class EXAMPLE3

creation make

feature

   make is
      local
         rand: GEN_RAND;
         seed, count: INTEGER;
      do
         if argument_count < 2 then
            io.put_string("Usage: ");
	    io.put_string(argument(0));
	    io.put_string(" <seed> <count> [min_stand|std_rand]%N");
	    die_with_code(exit_failure_code);
         end;
         seed := argument(1).to_integer;
         count := argument(2).to_integer;
         if argument_count > 2 then
            if argument(3).same_as("MIN_STAND") then
               !MIN_STAND!rand.with_seed(seed);
               io.put_string("Using MIN_STAND.%N");
            else
               !STD_RAND!rand.with_seed(seed);
               io.put_string("Using STD_RAND.%N");
            end;
         else
            !STD_RAND!rand.with_seed(seed);
            io.put_string("Using default STD_RAND.%N");
         end;
         from
         until
            count = 0
         loop
            rand.next;
            io.put_double(rand.last_double);
            count := count - 1;
            io.put_string("%N");
         end;
      end;

end -- EXAMPLE3

