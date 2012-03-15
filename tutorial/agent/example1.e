class EXAMPLE1
--
-- To start with agents, just read this first example.
--

creation make

feature

   make is
      local
         my_array: ARRAY[STRING]
      do
	 my_array := <<"Benedicte","Lucien","Marie">>

	 my_array.do_all(agent print_item(?))
      end

feature {NONE}

   print_item(item: STRING) is
      do
	 number := number + 1
	 std_output.put_character('#')
	 std_output.put_integer(number)
	 std_output.put_character(' ')
	 std_output.put_string(item)
	 std_output.put_character('%N')
      end

   number: INTEGER

end -- EXAMPLE1

