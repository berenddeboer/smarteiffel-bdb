class COMMAND
   --
   -- To separate Handling of Keyboard Input.
   --

creation make

feature 

   arrival: BOOLEAN is
      do
         Result := (code = c_arrival)
      end

   departure: BOOLEAN is
      do
         Result := (code = c_departure)
      end
   
   level_count: BOOLEAN is
      do
         Result := (code = c_level_count)
      end
   
   hour_price: BOOLEAN is
      do
         Result := (code = c_hour_price)
      end
   
   add_time: BOOLEAN is
      do
         Result := (code = c_add_time)
      end
   
   clock: BOOLEAN is
      do
         Result := (code = c_clock)
      end
   
   quit: BOOLEAN is
      do
         Result := (code = c_quit)
      end
   
   help: BOOLEAN is
      do
         Result := (code = c_help)
      end
   
   arg_real: REAL is
      do
	 if cmd.is_real then
	    Result := cmd.to_real
	 else
	    io.put_string("Real expected: %"" + cmd + "%"%N")
	 end
      end
   
   arg_integer: INTEGER is
      do
	 if cmd.is_integer then
	    Result := cmd.to_integer
	 else
	    io.put_string("Integer expected: %"" + cmd + "%"%N")
	 end
      end
   
   count: BOOLEAN is
      do
         Result := (code = c_count)
      end
   
feature -- Modifications:

   make is
      do
      end
   
   get_command(sio: STD_INPUT_OUTPUT) is
      require
         sio /= Void
      local
         stop: BOOLEAN
      do
         sio.read_line
         cmd := sio.last_string
         from
            code := ' '
            stop := (cmd.count < 1)
         until
            stop
         loop
            code := cmd @ 1
            cmd.remove(1)
            stop := ((code /= ' ') and (code /= '%T')) or (cmd.count < 1)
         end
      end

   print_help_on(sio: STD_INPUT_OUTPUT) is
      require
         sio /= Void
      do
         sio.put_string("[
            Commands:
            -------------------
            q        Quit
            a        Arrival of a car
            d <i>    Departure of car number <i>
            l <i>    number of car at Level <i>
            h <x>    set Hour price with <x>
            c        total Count of cars
            t <i>    add Time <i> minutes
            T        current Time
            ?        help

                         ]")
      end
   
feature {COMMAND}
   
   c_arrival : CHARACTER is 'a'
   c_departure : CHARACTER is 'd'
   c_level_count : CHARACTER is 'l'
   c_hour_price : CHARACTER is 'h'
   c_add_time : CHARACTER is 't'
   c_clock : CHARACTER is 'T'
   c_quit : CHARACTER is 'q'
   c_count : CHARACTER is 'c'
   c_help : CHARACTER is '?'
   
   code : CHARACTER
   
feature {NONE}
   
   cmd: STRING
   
end -- COMMAND
