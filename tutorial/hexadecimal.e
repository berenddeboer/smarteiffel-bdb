class HEXADECIMAL
--
-- Here is an example of the hexadecimal notation to denote INTEGER_8, 
-- INTEGER_16, INTEGER_32, and INTEGER_64.
-- A similar hexadecimal notation is also possible to denote CHARACTER
-- and content of STRINGs.
--

   
creation hexadecimal_documentation
   --
   -- Actually, the notation is similar to the one used in C or in
   -- Java for example.
   --
   -- Just follow step-by-step the execution of this class. Compile 
   -- with:
   --          compile -sedb hexadecimal
   --
   
feature

   hexadecimal_documentation is
      local
	 int8: INTEGER_8; int16: INTEGER_16
	 int32: INTEGER_32; int64: INTEGER_64
      do
	 -- A 2 hexadecimal digit denote an INTEGER_8.
	 -- Setting all bits of an INTEGER_8 is achieved with:
	 int8 := 0xFF

	 -- A 4 hexadecimal digit denote an INTEGER_16.
	 -- As an example, the greater positive value for an
	 -- INTEGER_16 is:
	 int16 := 0x7FFF
	 check
	    int16 = 32767
	 end
	 
	 -- A 8 hexadecimal digit denote an INTEGER_32.
	 -- As an example, the smallest negative value for an
	 -- INTEGER_32 is:
	 int32 := 0x80000000
	 check
	    int32 = -2147483648
	 end

	 -- A 16 hexadecimal digit denote an INTEGER_64.
	 -- The `Maximum_integer_64':
	 int64 := 0x7FFFFFFFFFFFFFFF
	 check
	    int64 = 9223372036854775807
	 end
	 -- The `Minimum_integer_64':
	 int64 := 0x8000000000000000
	 check
	    int64 = -9223372036854775808
	 end

	 -- Hexadecimal notation can also be applied to denote
	 -- CHARACTERs:
	 character := '%/0x41/'
	 check
	    character = 'A'
	 end
	 -- The good old decimal notation is still accepted:
	 character := '%/65/'
	 check
	    character = 'A'
	 end


	 -- Hexadecimal can also be used inside STRINGs as well:
	 string := "One %/0x43414645/ pl%/0x65/ase"
	 sedb_breakpoint -- Use the -sedb option to view the string !
      end

   character: CHARACTER

   string: STRING
   
end

