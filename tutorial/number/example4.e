class EXAMPLE4
   --
   -- Other examples to view NUMBERs.
   --

inherit
    ARGUMENTS

creation make

feature

   make is
      local
         n: NUMBER
      do
	 n := (1).to_number / (5).to_number

	 io.put_string("(" + n.to_string + ").to_decimal(5,true) -> ")
	 io.put_string(n.to_decimal(5,True) + "%N")

	 io.put_string("(" + n.to_string + ").to_decimal(5,false) -> ")
	 io.put_string(n.to_decimal(5,False) + "%N")

	 n := (1).to_number / (3).to_number

	 io.put_string("(" + n.to_string + ").to_decimal(10,true) -> ")
	 io.put_string(n.to_decimal(10,True) + "%N")

	 io.put_string("(" + n.to_string + ").to_decimal(10,false) -> ")
	 io.put_string(n.to_decimal(10,False) + "%N")
      end

end -- EXAMPLE4


