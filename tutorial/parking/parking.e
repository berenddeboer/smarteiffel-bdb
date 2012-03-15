class PARKING

creation make

feature

   lower_level: INTEGER is
      do
         Result := level_list.lower
      end
   
   upper_level: INTEGER is
      do
         Result := level_list.upper
      end
   
   hour_price: REAL
   
   default_hour_price: REAL is 1.50
   
   count: INTEGER is
      local
         i: INTEGER
      do
         from
            i := lower_level
         until
            i > upper_level
         loop
            Result := Result + level_count(i)
            i := i + 1
         end
      end
   
   clock: DATE
   
   level_count(number: INTEGER): INTEGER is
      require
         number <= upper_level
         lower_level <= number
      do
         Result := level_list.item(number).count
      ensure
         Result >= 0
      end

feature -- Modifications:

   make(ll: like level_list) is
      require
         ll /= Void
      do
         !!clock.make(0,360)
         hour_price := default_hour_price
         level_list := ll
         last_car := 0
      ensure
         hour_price = default_hour_price
         level_list = ll
         last_car = 0
      end
   
   arrival: INTEGER is
	 -- Gives 0 when no more place.
      local
         i: INTEGER
      do
         from
            i := lower_level
         until
            (i > upper_level) or else
            (not level_list.item(i).full)
         loop
            i := i + 1
         end
         if (i > upper_level) or else
            (level_list.item(i).full)
         then
            Result := 0
         else
            last_car := last_car + 1
            level_list.item(i).arrival(last_car,clock.twin)
            Result := last_car
         end
      ensure
         Result >= 0
      end
   
   departure(car: INTEGER): REAL is
         -- Gives the price to pay or -1 when car has already leaved.
      require
         car > 0
      local
         i: INTEGER; stop: BOOLEAN; c: like clock
      do
         from
            i := lower_level
            stop := level_list.count <= 0
            Result := -1
            c := clock.twin
         until
            stop
         loop
            Result := level_list.item(i).departure(car,c,hour_price)
            i := i + 1
            stop := (Result >= 0) or (i > upper_level)
         end
      end
   
   add_time(incr: INTEGER) is
      do
         clock.add_time(incr)
      end
   
   set_hour_price(hp: REAL) is
      require
         hp >= 0
      do
         hour_price := hp
      ensure
         hour_price = hp
      end
   
feature {NONE}
   
   level_list: ARRAY[LEVEL]
   
   last_car: INTEGER
   
invariant
   
   valid_price: hour_price >= 0
   
   clock /= Void
   
   last_car >= 0
   
   level_list /= Void
   
end -- PARKING
