class EXAMPLE2
--
-- Here is a little cookbook for people using very large computers.
-- We suppose here that the goal is to minimize execution time (i.e.
-- we suppose now that you have a _lot_ of available memory).
--
-- Note: it is usually interesting to compare the execution time of this
-- example with/without the SmartEiffel garbage collector:
--    compile -boost        example2
--    compile -boost -no_gc example2
--
-- Hint: when the -no_gc flag is used, there is one C malloc for 
-- each object.
--

inherit MEMORY;

creation my_main

feature

   my_main is
      local
	 long_loop: INTEGER; foo: STRING;
      do
	 -- At the beginning of the execution of your main procedure, 
	 -- just select the `high_memory_strategy':
	 -- Here, we suppose that you have a _LOT_ of memory and our 
	 -- prediction is to push ceils at the maximum:
	 set_default_memory_strategy;
	 from
	    long_loop := 50_000;
	    -- Please uncomment the following line to have more time 
	    -- to check memory consumption:
	    -- long_loop := 10_000_000;
	 until
	    long_loop <= 0
	 loop
	    foo := ("bar").twin;
	    long_loop := long_loop - 1;
	 end;
	 io.put_string("Collector counter: ");
	 io.put_integer(collector_counter);
	 io.put_new_line;
	 io.put_string("Allocated bytes of memory: ");
	 io.put_integer(allocated_bytes);
	 io.put_new_line;
      end;

end
