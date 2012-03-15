class EXAMPLE2
--
-- To start with TUPLE, just compile an run it :
--
--            compile -o example2 -boost example2
--

creation make

feature

   make is
      local
         my_very_long_tuple: TUPLE[INTEGER,STRING,INTEGER,
				   INTEGER,STRING,INTEGER,
				   INTEGER,STRING,INTEGER]
      do
	 -- Creation of a new TUPLE:
         my_very_long_tuple := [1,"Benedicte",1993,
				2,"Lucien",1995,
				3,"Marie",1997]

	 -- Accessing:
	 io.put_string("my_very_long_tuple.count = ")
         io.put_integer(my_very_long_tuple.count)
         io.put_string("%Nmy_very_long_tuple.first = ")
         io.put_integer(my_very_long_tuple.first)
         io.put_string("%Nmy_very_long_tuple.second = ")
         io.put_string(my_very_long_tuple.second)
         io.put_string("%Nmy_very_long_tuple.third = ")
         io.put_integer(my_very_long_tuple.third)
         io.put_string("%Nmy_very_long_tuple.fourth = ")
         io.put_integer(my_very_long_tuple.fourth)
         io.put_string("%Nmy_very_long_tuple.fifth = ")
         io.put_string(my_very_long_tuple.fifth)
         io.put_string("%Nmy_very_long_tuple.item_6 = ")
         io.put_integer(my_very_long_tuple.item_6)
         io.put_string("%Nmy_very_long_tuple.item_7 = ")
         io.put_integer(my_very_long_tuple.item_7)
         io.put_string("%Nmy_very_long_tuple.item_8 = ")
         io.put_string(my_very_long_tuple.item_8)
         io.put_string("%Nmy_very_long_tuple.item_9 = ")
         io.put_integer(my_very_long_tuple.item_9)
	 io.put_character('%N')

	 -- Writing:
	 my_very_long_tuple.set_first(0)
	 my_very_long_tuple.set_second(Void)
	 my_very_long_tuple.set_third(0)
	 my_very_long_tuple.set_fourth(0)
	 my_very_long_tuple.set_fifth(Void)
	 my_very_long_tuple.set_item_6(0)
	 my_very_long_tuple.set_item_7(0)
	 my_very_long_tuple.set_item_8(Void)
	 my_very_long_tuple.set_item_9(0)
      end

end -- EXAMPLE2

