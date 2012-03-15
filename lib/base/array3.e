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
class ARRAY3[E]
   --
   -- General prurpose, resizable, three dimensional array.
   --

inherit COLLECTION3[E]

creation
   make, copy, from_collection3, from_collection, from_model

feature

   lower1, lower2, lower3, upper1, upper2, upper3: INTEGER

   count1, count2, count3, count: INTEGER

feature {ARRAY3}

   storage: NATIVE_ARRAY[E]
	 -- To store elements line by line.

   capacity: INTEGER
	 -- Number of elements in `storage'.

feature -- Creation / modification:

   make(line_min, line_max, column_min, column_max, depth_min, depth_max: INTEGER) is
         -- Reset all bounds `line_minimum' / `line_maximum' / `column_minimum'
         -- `column_maximum' / `depth_min' and `depth_max' using arguments as
         -- new values. All elements are set to the default value of type E.
      require
	 line_min <= line_max
         column_min <= column_max
         depth_min <= depth_max
      do
	 lower1 := line_min
	 upper1 := line_max
	 lower2 := column_min
	 upper2 := column_max
         lower3 := depth_min
         upper3 := depth_max
	 count1 := upper1 - lower1 + 1
	 count2 := upper2 - lower2 + 1
	 count3 := upper3 - lower3 + 1
	 count := count1 * count2 * count3
	 if capacity >= count then
	    storage.clear_all(count - 1)
	 else
	    capacity := count
	    storage := storage.calloc(count)
	 end
      ensure
	 line_minimum = line_min
	 line_maximum = line_max
	 column_minimum = column_min
	 column_maximum = column_max
         depth_minimum = depth_min
         depth_maximum = depth_max
      end

   from_collection3(model: COLLECTION3[like item]) is
      local
         i, j, k: INTEGER
      do
	 make(model.line_minimum,
	      model.line_maximum,
	      model.column_minimum,
              model.column_maximum,
              model.depth_minimum,
              model.depth_maximum)
	 from
	    i := line_minimum
	 until
	    i > line_maximum
	 loop
	    from
	       j := column_minimum
	    until
	       j > column_maximum
	    loop
               from
                  k := depth_minimum
               until
                  k > depth_maximum
               loop
                  put(model.item(i,j,k),i,j,k)
                  k := k + 1
               end
   	       j := j + 1
	    end
	    i := i + 1
	 end
      ensure then
	 lower1 = model.lower1
         lower2 = model.lower2
         lower3 = model.lower3
      end

   from_collection(contents: COLLECTION[E]
        line_min, line_max, column_min, column_max, depth_min, depth_max: INTEGER) is
	 --  Reset all bounds using `line_min', `line_max', `column_min',
         --  `column_max', `depth_min', and `depth_max'.
	 --  Copy all elements of `contents', line by line into Current.
      require
	 line_min <= line_max
	 column_min <= column_max
         depth_min <= depth_max
         contents.count = (line_max - line_min + 1) * (column_max - column_min + 1) * (depth_max - depth_min + 1)
      local
	 i: INTEGER
      do
         make(line_min,line_max,column_min,column_max,depth_min,depth_max)
	 from
	    i := 0
	 until
	    i >= count
	 loop
	    storage.put(contents.item(contents.lower + i),i)
	    i := i + 1
	 end
      ensure
	 line_minimum = line_min
	 line_maximum = line_max
	 column_minimum = column_min
	 column_maximum = column_max
         depth_minimum = depth_min
         depth_maximum = depth_max
         count = contents.count
      end

   from_model(model: COLLECTION[COLLECTION[COLLECTION[E]]]) is
         -- The `model' is used to fill line by line the COLLECTION3.
         -- Assume all sub-collections of have the same indexing.
      local
         line, column, depth: INTEGER
      do
	 make(model.lower,
	      model.upper,
	      model.first.lower,
              model.first.upper,
              model.first.first.lower,
              model.first.first.upper)
	 from
	    line := model.lower
	 until
	    line > model.upper
	 loop
	    from
	       column := model.first.lower
	    until
	       column > model.first.upper
	    loop
               from
                  depth := model.first.first.lower
               until
                  depth > model.first.first.upper
               loop
                  put(model.item(line).item(column).item(depth),line,column,depth)
                  depth := depth + 1
               end
	       column := column + 1
	    end
	    line := line + 1
	 end
      ensure then
	 line_minimum = model.lower
	 line_maximum = model.upper
	 column_minimum = model.first.lower
         column_maximum = model.first.upper
         depth_minimum = model.first.first.lower
         depth_maximum = model.first.first.upper
      end

feature -- Resizing:

   resize(line_min, line_max, column_min, column_max, depth_min, depth_max: INTEGER) is
	 -- Resize bounds of the Current array
      require
	 line_max >= line_min
	 column_max >= column_min
         depth_max >= depth_min
      local
	 tmp: like Current
         l, c, d: INTEGER
      do
         !!tmp.make(line_min, line_max, column_min, column_max, depth_min, depth_max)
         -- It may be possible to avoid this creation when :
	 --    new `capacity' <= old `capacity'
	 from
	    l := lower1
	 until
	    l > line_maximum
	 loop
	    from
	       c := lower2
	    until
	       c > column_maximum
	    loop
               from
                  d := lower3
               until
                  d > depth_maximum
               loop
                  if tmp.valid_index(l,c,d) then
                     tmp.put(item(l,c,d),l,c,d)
                  end
                  d := d + 1
               end
	       c := c + 1
	    end
	    l := l + 1
	 end
	 standard_copy(tmp)
      ensure
	 line_minimum = line_min
	 line_maximum = line_max
	 column_minimum = column_min
	 column_maximum = column_max
         depth_minimum = depth_min
         depth_maximum = depth_max
      end

feature -- Implementation of others feature from COLLECTION3:

   item(line, column, depth: INTEGER): E is
      do
         Result := storage.item((line - lower1) * count2 * count3 + (column - lower2) * count3 + depth - lower3)
      end

   put(element: like item; line, column, depth: INTEGER) is
      do
         storage.put(element,(line - lower1) * count2 * count3 + (column - lower2) * count3 + depth - lower3)
      end

   force(x: like item; line, column, depth: INTEGER) is
      require else
	 True
      do
         if not valid_index(line,column,depth) then
	    resize(line.min(lower1),
		   line.max(upper1),
		   column.min(lower2),
                   column.max(upper2),
                   depth.min(lower3),
                   depth.max(upper3))
	 end
         put(x,line,column,depth)
      end

   set_all_with(element: E) is
      do
	 storage.set_all_with(element,count - 1)
      end

   replace_all(old_value, new_value: like item) is
      do
	 storage.replace_all(old_value,new_value,count - 1)
      end

   fast_replace_all(old_value, new_value: like item) is
      do
	 storage.fast_replace_all(old_value,new_value,count - 1)
      end

   sub_collection3(line_min, line_max, column_min, column_max,
                   depth_min, depth_max: INTEGER): like Current is
      local
         i, j, k, n: INTEGER
      do
         !!Result.make(line_min,line_max,column_min,column_max,
                       depth_min,depth_max)
	 from
	    i := line_min
	    k := 0
	 until
	    i > line_max
	 loop
	    from
	       j := column_min
	    until
	       j > column_max
	    loop
               from
                  k := depth_min
               until
                  k > depth_max
               loop
                  Result.storage.put(item(i,j,k),n)
                  n := n + 1
                  k := k + 1
               end
               j := j + 1
	    end
	    i := i + 1
	 end
      ensure then
	 Result.lower1 = line_min
	 Result.lower2 = column_min
         Result.lower3 = depth_min
	 Result.upper1 = line_max
	 Result.upper2 = column_max
         Result.upper3 = depth_max
      end

feature --  Looking and comparison:

   occurrences(elt: E): INTEGER is
      do
	 Result := storage.occurrences(elt,count - 1)
      end

   fast_occurrences(elt: E): INTEGER is
      do
	 Result := storage.fast_occurrences(elt,count - 1)
      end

   has(x: like item): BOOLEAN is
	 -- Search if a element x is in the array using `equal'.
         -- See also `fast_has' to choose the apropriate one.
      do
	 Result := storage.index_of(x,count - 1) <= count - 1
      end

   fast_has(x: like item): BOOLEAN is
	 --  Search if a element x is in the array using `='.
      do
	 Result := storage.fast_index_of(x,count - 1) <= count -1
      end

   all_default: BOOLEAN is
      do
	 result := storage.all_default(count - 1)
      end

   swap(line1, column1, depth1, line2, column2, depth2 : INTEGER) is
      local
	 tmp: like item
         index1, index2: INTEGER
      do
         index1 := (line1 - lower1) * count2 * count3 + (column1 - lower2) * count3 + depth1 - lower3
         index2 := (line2 - lower1) * count2 * count3 + (column2 - lower2) * count3 + depth2 - lower3
	 tmp := storage.item(index1)
	 storage.put(storage.item(index2),index1)
	 storage.put(tmp,index2)
      end

   copy(other: like Current) is
      do
	 lower1 := other.lower1
	 upper1 := other.upper1
	 lower2 := other.lower2
	 upper2 := other.upper2
         lower3 := other.lower3
         upper3 := other.upper3
	 count := other.count
	 count1 := other.count1
	 count2 := other.count2
	 count3 := other.count3
	 if capacity < count then
	    capacity := count
	    storage := storage.calloc(count)
	 end
	 storage.copy_from(other.storage, count - 1)
      end

   is_equal(other: like Current): BOOLEAN is
      do
	 if other = Current then
	    Result := True
	 elseif lower1 /= other.lower1 then
	 elseif lower2 /= other.lower2 then
         elseif lower3 /= other.lower3 then
         elseif upper1 /= other.upper1 then
         elseif upper2 /= other.upper2 then
         elseif upper3 /= other.upper3 then
	 else
	    Result := storage.memcmp(other.storage,count)
	 end
      end

   same_as(other: COLLECTION3[E]): BOOLEAN is
      do
         Result := other.same_as_array3(Current)
      end

feature {COLLECTION3}

   same_as_array3(other: ARRAY3[E]): BOOLEAN is
      do
	 Result := standard_same_as(other)
      end

   same_as_fixed_array3(other: FIXED_ARRAY3[E]): BOOLEAN is
      do
	 Result := standard_same_as(other)
      end

invariant

   count1 = upper1 - lower1 + 1
   count2 = upper2 - lower2 + 1
   count3 = upper3 - lower3 + 1

   capacity >= count

end -- ARRAY3[E]
