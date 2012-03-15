class DATE
   --
   -- Special DATE class to fit with the PARKING example.
   --
creation make

feature 

   display_on(file: OUTPUT_STREAM) is
	 -- To display `Current' on `file'.
      do
	 if day > 0 then
	    file.put_string("day")
	    if day > 1 then
	       file.put_character('s')
	    end
	    file.put_string(": ")
	    file.put_integer(day)
	 end
         file.put_string(" minute")
	 if min > 1 then
	    file.put_character('s')
	 end
	 file.put_string(": ")
         file.put_integer(min)
	 if day_time then
	    file.put_string(" (day time)")
	 else
	    file.put_string(" (night time)")
	 end
      end
   
   minutes_to(after: DATE): INTEGER is
         -- Count of minutes to go to `after'.
      require
         after >= Current
      do
         Result := ((after.day - day) * 24 * 60 + (after.min - min))
      ensure
         Result >= 0
      end

   day_night_to(d2: DATE): TUPLE[INTEGER,INTEGER] is
         --The `Result' is a couple of INTEGER where:
	 --    Result.first: Night time.
         --    Result.second: Day time.
      require
         d2 >= Current
      local
         min_jour, min_nuit, save_day, save_min: INTEGER
      do
	 save_day := day
	 save_min := min
         from until
            Current.is_equal(d2)
         loop
            if day_time then
               min_jour := min_jour + 1
            else
               min_nuit := min_nuit + 1
            end
            add_time(1)
         end
         day := save_day
         min := save_min
         Result := [min_jour,min_nuit]
      ensure
         Result.first + Result.second = minutes_to(d2)
      end

   infix ">=" (d2: like Current): BOOLEAN is
      require
         d2 /= Void
      do
	 if day > d2.day then
	    Result := true
	 elseif day = d2.day then 
	    Result := min >= d2.min
	 end
      end

   day_time: BOOLEAN is
         -- Is it Sunny ?
      do
         Result := (min >= 6 * 60) and (min <= 22 * 60)
      end

   nigth_time: BOOLEAN is
         -- Is it the night ?
      do
         Result := not day_time
      end
   
feature -- Modifications:

   make(vday, vmin: INTEGER) is
      do
         day := vday
         min := vmin
      ensure
         day = vday
         min = vmin
      end

   add_time(nb_min: INTEGER) is
      do
         min := min + nb_min
         if min >= (24 * 60) then
            day := day + (min // (24 * 60))
            min := min \\ (24 * 60)
         end
      end

feature {DATE}

   day, min: INTEGER

invariant

   day >= 0

   min.in_range(0, (24 * 60) - 1)

end -- DATE
