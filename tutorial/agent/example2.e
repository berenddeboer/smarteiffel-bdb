class EXAMPLE2
--
-- Actually, agents are available for all kinds of COLLECTION (i.e. ARRAY,
-- FIXED_ARRAY, LINKED_LIST, TWO_WAY_LINKED_LIST), but also for class SET
-- as well as for class DICTIONARY.
--

creation make

feature

   make is
      local
	 my_collection: COLLECTION[STRING]
         my_list: LINKED_LIST[STRING]; my_set: SET[STRING]
      do
	 my_collection := <<"Benedicte","Lucien","Marie">>

	 create my_list.make
	 -- Using an agent to fill `my_list' using `my_collection':
	 my_collection.do_all(agent my_list.add_last(?))

	 create my_set.make
	 -- Using an agent to fill `my_set' with `my_list':
	 my_list.do_all(agent my_set.add(?))

	 -- Using an agent to print `my_set':
	 my_set.do_all(agent print_item(?))
      end

feature {NONE}

   print_item(item: STRING) is
      do
	 std_output.put_string(item)
	 std_output.put_character('%N')
      end

end -- EXAMPLE2

