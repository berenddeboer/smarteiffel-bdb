class LEVEL

creation make

feature

   count: INTEGER
         -- Total count of occupied places.
   
   free_count: INTEGER is
      do
         Result := park.count - count
      end
   
   capacity : INTEGER is
      do
         Result := count + free_count
      end
   
   full: BOOLEAN is
      do
         Result := count = capacity
      end
   
feature -- Modifications:

   make(max_cars: INTEGER) is
      require
         max_cars > 0
      do
         !!park.make(1,max_cars)
         !!tickets.make(park.lower,park.upper)
         count := 0
      ensure
         count = 0
      end

   arrival(car: INTEGER; arrival_time: DATE) is
      require
         not full
         car > 0
      local
         i: INTEGER; stop: BOOLEAN; ticket: TICKET
      do
         from
            i := park.lower
            stop := false
         until
            stop
         loop
            if park.item(i) <= 0 then
               stop := true
               park.put(car,i)
               !!ticket.make(arrival_time)
               tickets.put(ticket,i)
               count := count + 1
            end
            i := i + 1
         end
      ensure
         count >= old count + 1
      end

   departure(car: INTEGER; departure_time: DATE; hour_price: REAL): REAL is
         -- Gives price to pay or -1 when car is not at this level.
      require
         car > 0
      local
         i: INTEGER
      do
         i := park.index_of(car)
         if i > park.upper then
            Result := -1
         else
            Result := tickets.item(i).price(departure_time,hour_price)
            tickets.put(Void,i)
            park.put(0,i)
            count := count - 1
         end
      end

feature {NONE}

   park: ARRAY[INTEGER]

   tickets: ARRAY[TICKET]

invariant

   count >= 0

   free_count >= 0
   
   capacity = count + free_count
   
   capacity >= 1
   
   tickets.count = park.count
   
end -- LEVEL
