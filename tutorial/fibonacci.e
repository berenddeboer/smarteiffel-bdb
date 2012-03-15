class FIBONACCI

creation make

feature

   make is
      do
         if argument_count /= 1 or else
            not argument(1).is_integer
          then
            io.put_string("Usage: ");
            io.put_string(argument(0));
            io.put_string(" <Integer_value>%N");
            die_with_code(exit_failure_code);
         end;
         io.put_integer(fibonacci(argument(1).to_integer));
         io.put_new_line;
      end;

   fibonacci(i: INTEGER): INTEGER is
      require
         i >= 0
      do
         if i = 0 then
            Result := 1;
         elseif i = 1 then
            Result := 1;
         else
            Result := fibonacci(i - 1) + fibonacci(i - 2) ;
         end;
      end;

end

