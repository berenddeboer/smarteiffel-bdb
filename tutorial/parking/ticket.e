class TICKET

creation make

feature

   arrival_time: DATE

   price(departure_time: DATE; hour_price: REAL): REAL is
      require
         departure_time >= arrival_time
      local
         nb_min: TUPLE[INTEGER,INTEGER]
      do
         nb_min := arrival_time.day_night_to(departure_time)
         io.put_integer(nb_min.second)
         Result := (((hour_price / 4) * nb_min.second)
                    + (hour_price * nb_min.first)) / 60
      end

   make(arrival: DATE) is
      do
         arrival_time := arrival
      ensure
         arrival_time = arrival
      end

end -- TICKET
