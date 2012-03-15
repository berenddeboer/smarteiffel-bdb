class PRINT_ARGUMENTS
   --
   -- How to print arguments of the command line.
   --

creation make

feature

   make is
      local
         i: INTEGER;
      do
         from
            i := 1;
         until
            i > argument_count
         loop
            std_output.put_string(argument(i));
            std_output.put_character(' ');
            i := i + 1;
         end;
         std_output.put_character('%N');
      end;

end -- PRINT_ARGUMENTS
