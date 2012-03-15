class RUN_PARKING
   --
   -- Main loop to run the PARKING example.
   --
creation make

feature {NONE}

   make is
      local
         p: PARKING; level1, level2, level3: LEVEL
         command: COMMAND; price: REAL; i, value: INTEGER
      do
         from
            !!level1.make(14)
            !!level2.make(18)
            !!level3.make(25)
            !!p.make(<<level1,level2,level3>>)
            !!command.make
            io.put_string("Parking simulation.%N%N")
            command.print_help_on(io)
            command.get_command(io)
         until
            command.quit
         loop
            if command.arrival then
               value := p.arrival
               if value > 0 then
                  io.put_integer(value)
                  io.put_new_line
               else
                  io.put_string("Error: No more places to park.%N")
               end
            elseif command.level_count then
               i := command.arg_integer
               if  i < p.lower_level then
                  io.put_string("Error: Level too small.%N")
               elseif i > p.upper_level then
                  io.put_string("Error: Level too big.%N")
               else
                  io.put_integer(p.level_count(i))
                  io.put_new_line
               end
            elseif command.add_time then
               i := command.arg_integer
               if i <= 0 then
                  io.put_string("Error: Time too small.%N")
               else
                  p.add_time(i)
               end
            elseif command.hour_price then
               price := command.arg_real
               if price <= 0 then
                  io.put_string("Error: It is not Enought.%N")
               else
                  p.set_hour_price(price)
               end
            elseif command.departure then
               i := command.arg_integer
               if i <= 0 then
                  io.put_string("Error: Too Small car #.%N")
               else
                  price := p.departure(i)
                  if price < 0 then
                     io.put_string("Error: this car is already outside.%N")
                  else
                     io.put_real(price)
                     io.put_new_line
                  end
               end
            elseif command.clock then
               p.clock.display_on(io)
               io.put_new_line
            elseif command.count then
               io.put_integer(p.count)
               io.put_new_line
            elseif command.help then
               command.print_help_on(io)
            else
               io.put_string("Error: Unknown Command.%N")
            end
            command.get_command(io)
         end
         io.put_string("Quit%N")
      end

end -- RUN_PARKING
