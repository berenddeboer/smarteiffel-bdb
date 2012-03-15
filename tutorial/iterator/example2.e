class EXAMPLE2
   --
   -- Using an ITERATOR traverse some random collection of INTEGER.
   --

creation make

feature {NONE}

   iterator: ITERATOR_ON_RANDOM_GENERATOR;
   
   make is
      do
	 !!iterator.make(10);
	 io.put_string("First traversal :%N");
	 traverse;
	 io.put_string("Second traversal :%N");
	 traverse;
      end;

   traverse is
      do
	 from
	    iterator.start;
	 until
	    iterator.is_off
	 loop
	    io.put_integer(iterator.item);
            io.put_character(' ');
	    iterator.next;
	 end;
         io.put_new_line;
      end;

end
