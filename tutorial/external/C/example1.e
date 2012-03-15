class EXAMPLE1
--
-- How to use external "C" features (i.e. calling C from Eiffel).
--
-- To compile this file:
--
--       compile example1 c_glue1.c
--
-- You may also prefer:
--
--       gcc -c c_glue1.c
--       compile example1 c_glue1.o
--
creation make

feature

   make is
      local
	 i: INTEGER; c: CHARACTER
      do
	 -- To send an INTEGER to the C world:
         integer2c(6)
	 -- To send a CHARACTER to the C world:
         character2c('a')
	 -- To send a BOOLEAN to the C world:
         boolean2c(true)
	 -- To send a REAL to the C world:
         real2c(3.5)
	 -- To send a DOUBLE to the C world:
         double2c((3.5).to_double)
         double2c(3.5)
	 -- To send the internal storage of a STRING to the C world:
         string_storage2c(("Hi C World %N").to_external)
	 -- To send `Current' address to the C world:
         any2c(Current)
	 -- To send a STRING to the C world:
         any2c("Hi")
	 -- To get an INTEGER from the C world:
	 i := c_int2eiffel
         io.put_integer(i)
	 -- To get an CHARACTER from the C world:
	 c := c_char2eiffel
         io.put_character(c)
         -- To pass the address on an INTEGER attribute:
         set_integer_attribute($integer_attribute)
         std_output.put_integer(integer_attribute)
         std_output.put_new_line
	 -- Calling the hello C function:
         if hello then
	    std_output.put_string(" C man !%N")
	 end
      end

feature {NONE}

   integer2c(i: INTEGER) is
         -- Call the C `integer2c' function with `i' as argument (see c_glue1.c).
      external "C"
      end

   character2c(c: CHARACTER) is
         -- Call the C `character2c' function with `c' as argument (see c_glue1.c).
      external "C"
      end

   boolean2c(b: BOOLEAN) is
         -- Call the C `boolean2c' function with `b' as argument (see c_glue1.c).
      external "C"
      end

   real2c(r: REAL) is
         -- Call the C `real2c' function with `r' as argument (see c_glue1.c).
      external "C"
      end

   double2c(d: DOUBLE) is
         -- Call the C `double2c' function with `d' as argument (see c_glue1.c).
      external "C"
      end

   string_storage2c(s: POINTER) is
         -- Call the C `string_storage2c' function with `s' as argument (see 
         -- c_glue1.c).
      external "C"
      end

   any2c(a: ANY) is
         -- Call the C `any2c' function with `a' as argument (see c_glue1.c).
      external "C"
      end

   c_int2eiffel: INTEGER is
         -- Call the C `c_int2eiffel' function (see c_glue1.c).
      external "C"
      end

   c_char2eiffel: CHARACTER is
         -- Call the C `c_char2eiffel' function (see c_glue1.c).
      external "C"
      end

   integer_attribute: INTEGER
	 
   set_integer_attribute(integer_pointer: POINTER) is
         -- Call the C `set_integer_attribute' function with the address of an 
         -- INTEGER attribute (see c_glue1.c).
      external "C"
      end

   hello: BOOLEAN is
      external "C"
      end

end -- EXAMPLE1
