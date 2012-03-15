class EXAMPLE3
   --
   -- To add a loop variant for any kind of ITERATOR (for loop variant
   -- fans only ;-).
   --

creation make

feature {NONE}

   iterator: ITERATOR_WITH_VARIANT[INTEGER];
   
   make is
      local
	 simple_iterator: ITERATOR[INTEGER];
      do
	 !ITERATOR_ON_RANDOM_GENERATOR!simple_iterator.make(10);
	 !!iterator.make(simple_iterator);
	 io.put_string("First traversal :%N");
	 traverse;
	 io.put_string("Second traversal :%N");
	 traverse;
      end;

   traverse is
      do
	 from
	    iterator.start;
	 variant
	    iterator.variant_value
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
