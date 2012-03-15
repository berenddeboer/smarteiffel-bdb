class EXAMPLE5
   --
   -- Using the NUMBER_TOOLS parser.
   --

creation make

feature {NONE}

   parser_buffer: MINI_PARSER_BUFFER

   make is
      local
	  stop: BOOLEAN; formula: STRING; number_tools: NUMBER_TOOLS
      do
	 parser_buffer := number_tools.parser_buffer
	 from until stop
	 loop
	    io.put_string(once "[
                Type Q to quit or ...
                Enter your NUMBER formula on a single line:

		                ]")
	    io.read_line
	    formula := io.last_string.twin
	    if formula.is_empty then
	       stop := True
	    else
	       if formula.count = 1 then
		  inspect
		     formula.first
		  when 'Q', 'q' then
		     stop := True
		  else
		  end
	       end
	       if not stop then
		  parsing_of(formula)
	       end
	    end
	 end
	 io.put_string("Bye.%N")
      end
   
   parsing_of(formula: STRING) is
      local
	 number_tools: NUMBER_TOOLS; number: NUMBER; i: INTEGER
      do
	 if number_tools.is_number(formula) then
	    number := number_tools.from_string(formula)
	    if number /= Void then
	       io.put_string(once "=%N")
	       io.put_number(number)
	       io.put_character('%N')
	    else
	       io.put_string(once "Error: ")
	       io.put_string(parser_buffer.last_error)
	       io.put_character('%N')
	    end
	 else
	    io.put_string(once "Syntax error: ")
	    io.put_string(parser_buffer.last_error)
	    io.put_character('%N')
	    io.put_string(formula)
	    io.put_character('%N')
	    from
	       i := 1
	    until
	       i = parser_buffer.current_index
	    loop
	       io.put_character(' ')
	       i := i + 1
	    end
	    io.put_string(once "^%N")
	 end
      end
   
end -- EXAMPLE5


