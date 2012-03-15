class EXAMPLE1
   --
   -- Yes it is easy to sort any COLLECTION:
   -- 
   --            compile -o example1 -boost example1
   --

creation make

feature

   make is
      local
         c: COLLECTION[INTEGER]; sorter: COLLECTION_SORTER[INTEGER]
      do
         c := <<10, 3, 5, 11, 1>>
         io.put_string("My collection not sorted : ")
         print_collection(c)
         io.put_string("My sorted collection     : ")
         sorter.sort(c)
         print_collection(c)
         io.put_string("To know more about sorting, have a look %
		       %at example #2.%N")
      end

feature {NONE}

   print_collection(c: COLLECTION[INTEGER]) is
      local
         i: INTEGER
      do
         from
            i := c.lower
         until
            i > c.upper
         loop
            io.put_integer(c.item(i))
            io.put_character(' ')
            i := i + 1
         end
         io.put_character('%N')
      end

end -- EXAMPLE1

