class EXAMPLE1

creation make

feature

   make is
      local
         count, range, column: INTEGER;
      do
         io.put_string("Using the MIN_STAND random number generator.%N%
                       %How many numbers ? ");
         io.read_integer;
         count := io.last_integer;
         io.put_string("Range ( > 1)     ? ");
         io.read_integer;
         range := io.last_integer;
         from
         until
            count = 0
         loop
            random_generator.next;
            io.put_integer(random_generator.last_integer(range));
            count := count - 1;
            if column = 6 then
               io.put_string("%N");
               column := 0;
            else
               column := column + 1;
               io.put_string("%T");
            end;
         end;
         io.put_string("%N");
      end;

feature {NONE}

   random_generator: MIN_STAND is
      once
         !!Result.make;
      end;

end -- EXAMPLE1

