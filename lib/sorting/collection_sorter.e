-- This  file  is  free software,  which comes along with SmartEiffel.  This
-- software is distributed in the hope that it will be useful,  but  WITHOUT
-- ANY  WARRANTY;  without  even the  implied warranty of MERCHANTABILITY or
-- FITNESS FOR A PARTICULAR PURPOSE. You can modify it as you want, provided
-- this header is kept unaltered, and a notification of the changes is added.
-- You  are  allowed  to  redistribute it and sell it, alone or as a part of
-- another product.
--
-- Copyright(C) 1994-2002: INRIA - LORIA (INRIA Lorraine) - ESIAL U.H.P.
--			   - University of Nancy 1 - FRANCE
-- Copyright(C) 2003:      INRIA - LORIA (INRIA Lorraine) - I.U.T. Charlemagne
--			   - University of Nancy 2 - FRANCE
--
--		 Dominique COLNET, Suzanne COLLIN, Olivier ZENDRA,
--			   Philippe RIBET, Cyril ADRIAN
--
-- http://SmartEiffel.loria.fr - SmartEiffel@loria.fr
--
expanded class COLLECTION_SORTER[X -> COMPARABLE]
--
-- Some algorithms to sort any COLLECTION[COMPARABLE].
--
-- Elements are sorted using increasing order: small elements
-- at the beginning of the collection, large at the end (decreasing
-- order is implemented by class REVERSE_COLLECTION_SORTER).
--
--
-- How to use this expanded class :
--
--          local
--             sorter: COLLECTION_SORTER[INTEGER]
--             array: ARRAY[INTEGER]
--          do
--             array := <<1,3,2>>
--             sorter.sort(array)
--             check
--                sorter.is_sorted(array)
--             end
--             ...
--

feature

   is_sorted(c: COLLECTION[X]): BOOLEAN is
         -- Is `c' already sorted ?
         -- Uses infix "<=" for comparison.
      require
         c /= Void
      local
         i, c_upper: INTEGER
         elt1, elt2: X
      do
         i := c.lower
         c_upper := c.upper
         Result := True
         if c_upper > i then
            from
               elt1 := c.item(i)
            invariant
               c.valid_index(i)
            until
               not Result or else i >= c_upper
            loop
               i := i + 1
               elt2 := c.item(i)
               Result := elt1 <= elt2
               elt1 := elt2
            end
         end
      ensure
         c.is_equal(old c.twin)
      end

   has(c: COLLECTION[X]; element: X): BOOLEAN is
      require
	 c /= Void
	 is_sorted(c)
      local
	 idx: INTEGER
      do
	 idx := index_of(c, element)
	 Result := c.valid_index(idx) and then c.item(idx).is_equal(element)
      ensure
	 Result = c.has(element)
      end

   index_of(c: COLLECTION[X]; element: X): INTEGER is
      require
	 c /= Void
	 is_sorted(c)
      local
	 min, max: INTEGER; stop: BOOLEAN
      do
	 if c.is_empty then
	    Result := c.lower
	 else
	    from
	       min := c.lower
	       max := c.upper
	    variant
	       max - min
	    until
	       stop
	    loop
	       if min = max then
		  stop := True
		  if c.item(min) < element then
		     Result := min + 1
		  else
		     Result := min
		  end
	       else
		  check min < max end
		  Result := (min + max) // 2
		  if c.item(Result) < element then
		     min := Result + 1
		  else
		     max := Result
		  end
	       end
	    end
         end
      ensure
         c.has(element) implies c.item(Result).is_equal(element)
         c.valid_index(Result - 1) implies (not (element < c.item(Result - 1)))
         (not c.has(element) and c.valid_index(Result)) implies element < c.item(Result)
      end

   add(c: COLLECTION[X]; element: X) is
	 -- Add `element' in collection `c' keeping the sorted property.
      require
	 c /= Void
	 is_sorted(c)
      do
	 c.add(element, index_of(c, element))
      ensure
	 c.count = old c.count + 1
	 is_sorted(c)
      end

   sort(c: COLLECTION[X]) is
         -- Sort `c' using the default most efficient sorting algorithm
         -- already implemented.
      require
         c /= Void
      do
         if not is_sorted(c) then
            quick_sort(c)
         end
      ensure
         c.count = old c.count
         is_sorted(c)
      end

   quick_sort(c: COLLECTION[X]) is
         -- Sort `c' using the quick sort algorithm.
      require
         c /= Void
      do
        quick_sort_region(c,c.lower,c.upper)
      ensure
         c.count = old c.count
         is_sorted(c)
      end

   von_neuman_sort(c: COLLECTION[X]) is
         -- Sort `c' using the Von Neuman algorithm.
         -- This algorithm needs to create a second collection.
         -- Uses infix "<=" for comparison.
      require
         c /= Void
      local
         src, dest, tmp: COLLECTION[X]
         nb, count, d_count, c_count, lower, imax: INTEGER
      do
         c_count := c.count
         if c_count > 1 then
            lower := c.lower
            imax := c.upper + 1
            from
               count := 1
            until
               count >= c_count
            loop
               count := count * 2
               nb := nb + 1
            end
            if nb.odd then
               src := c
               dest := c.twin
            else
               dest := c
               src := c.twin
            end
            from
               count := 1
            variant
               c_count * 2 - count
            until
               count >= c_count
            loop
               d_count := count * 2
               tmp := dest
               dest := src
               src := tmp
               von_neuman_line(src,dest,count,d_count,lower,imax)
               count := d_count
            end
         end
      ensure
         c.count = old c.count
         is_sorted(c)
      end


   heap_sort(c: COLLECTION[X]) is
         -- Sort `c' using the heap sort algorithm.
      require
         c /= Void
      local
         i, c_lower, c_upper: INTEGER
      do
         c_lower := c.lower
         c_upper := c.upper
         if c_upper > c_lower then
            from
               -- Build the very first heap first :
               from
                  i := c_lower + c.count // 2 + 1
               until
                  i < c_lower
               loop
                  heap_repair(c,c_lower,i,c_upper)
                  i := i - 1
               end
               --
               i := c_upper
            until
               i < c_lower + 1
            loop
               c.swap(c_lower,i)
               heap_repair(c,c_lower,c_lower,i - 1)
               i := i - 1
            end
         end
      ensure
         c.count = old c.count
         is_sorted(c)
      end

   bubble_sort(c: COLLECTION[X]) is
         -- Sort `c' using the bubble sort algorithm.
         -- Uses infix "<" for comparison.
      require
         c /= Void
      local
         i, imax, imin: INTEGER
         modified: BOOLEAN
      do
         from
            imax := c.upper
            imin := c.lower
            modified := True
         until
            not modified or else imin >= imax
         loop
            from
               modified := false
               i := imax
               imin := imin + 1
            until
               i < imin
            loop
               if c.item(i) < c.item(i - 1) then
                  c.swap(i ,i - 1)
                  modified := True
               end
               i := i - 1
            end
            if modified then
               from
                  modified := false
                  i := imin
                  imax := imax - 1
               until
                  i > imax
               loop
                  if c.item(i + 1) < c.item(i) then
                     c.swap(i ,i + 1)
                     modified := True
                  end
                  i := i + 1
               end
            end
         end
      ensure
         c.count = old c.count
         is_sorted(c)
      end

feature {NONE}

   von_neuman_line(src, dest: COLLECTION[X]; count, d_count, lower, imax: INTEGER) is
      require
         src /= dest
         src.lower = dest.lower
         src.upper = dest.upper
         count >= 1
         d_count = count * 2
         lower = src.lower
         imax = src.upper + 1
      local
         sg1: INTEGER
      do
         from
            sg1 := lower
         until
            sg1 >= imax
         loop
            von_neuman_inner_sort(src,dest,sg1,count,imax)
            sg1 := sg1 + d_count
         end
      ensure
         d_count >= dest.count implies is_sorted(dest)
      end

   von_neuman_inner_sort(src, dest: COLLECTION[X]; sg1, count, imax: INTEGER) is
      require
         src.valid_index(sg1)
      local
         i1, i2, i, i1max, i2max: INTEGER
      do
         from
            i1 := sg1
            i2 := sg1 + count
            i1max := i2.min(imax)
            i2max := (i2 + count).min(imax)
            i := i1
         until
            i1 >= i1max or else i2 >= i2max
         loop
            if src.item(i1) <= src.item(i2) then
               dest.put(src.item(i1),i)
               i1 := i1 + 1
            else
               dest.put(src.item(i2),i)
               i2 := i2 + 1
            end
            i := i + 1
         end
         if i1 >= i1max then
            from until i2 >= i2max
            loop
               dest.put(src.item(i2),i)
               i2 := i2 + 1; i := i + 1
            end
         else
            from until i1 >= i1max
            loop
               dest.put(src.item(i1),i)
               i1 := i1 + 1; i := i + 1
            end
         end
      end

   heap_repair(c: COLLECTION[X]; c_lower, first, last: INTEGER) is
         -- Repair the heap from the node number `first'
         -- It considers that the last item of c is number `last'
         -- It supposes that children are heaps.
      require
         c /= Void
         c.lower = c_lower
         c_lower <= first
         last <= c.upper
      local
         left_idx, right_idx: INTEGER
      do
         left_idx := 1 - c_lower + 2 * first
         if left_idx <= last then -- not a leaf :
            right_idx := 2 - c_lower + 2 * first
            if left_idx = last then
               if c.item(first) < c.item(left_idx) then
                  c.swap(first,left_idx)
               end
            elseif c.item(first) > c.item(left_idx) then
               if c.item(first) < c.item(right_idx) then
                  c.swap(first,right_idx)
                  heap_repair(c,c_lower,right_idx,last)
               end
            elseif c.item(left_idx) > c.item(right_idx) then
               c.swap(first,left_idx)
               heap_repair(c,c_lower,left_idx,last)
            else
               c.swap(first,right_idx)
               heap_repair(c,c_lower,right_idx,last)
            end
         end
      end

   quick_sort_region(c: COLLECTION[X]; left, right:INTEGER) is
      local
         middle: INTEGER; i: INTEGER
      do
         if left < right then
            i := left + (right - left) // 2 + 1
            c.swap(left,i)
            middle := left
            from
               i := left +1
            until
               i > right
            loop
               if c.item(i) < c.item(left) then
                  middle := middle + 1
                  c.swap(middle,i)
               end
               i := i + 1
            end
            c.swap(left,middle)
            quick_sort_region(c , left , middle - 1)
            quick_sort_region(c , middle + 1 , right)
         end
      end

end -- COLLECTION_SORTER
