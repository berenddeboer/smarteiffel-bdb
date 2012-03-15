class EXAMPLE1
--
-- To start with TUPLE, just compile an run it :
--
--            compile -o example1 -boost example1
--

creation make

feature

   make is
      local
         my_tuple: TUPLE[INTEGER,STRING,REAL]
      do
	 -- Creation of a new TUPLE:
         my_tuple := [2,"Lucien",6.5]

	 -- Accessing:
	 io.put_string("my_tuple.count = ")
         io.put_integer(my_tuple.count)
         io.put_string("%Nmy_tuple.first = ")
         io.put_integer(my_tuple.first)
         io.put_string("%Nmy_tuple.second = ")
         io.put_string(my_tuple.second)
         io.put_string("%Nmy_tuple.third = ")
         io.put_real(my_tuple.third)

	 -- Writing:
	 my_tuple.set_first(3)
	 my_tuple.set_second("Marie")
	 my_tuple.set_third(4.5)

	 -- Accessing:
         io.put_string("%Nmy_tuple.first = ")
         io.put_integer(my_tuple.first)
         io.put_string("%Nmy_tuple.second = ")
         io.put_string(my_tuple.second)
         io.put_string("%Nmy_tuple.third = ")
         io.put_real(my_tuple.third)

         io.put_string("[
			To know more about very long TUPLEs,
			have a look at example #2.

			]")
      end

end -- EXAMPLE1

