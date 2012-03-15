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
expanded class NATIVE_ARRAY[E]
--
-- This class gives access to the lowest level for arrays both for the C
-- language and for the Java language.
--
-- Warning: GURUS ONLY!! Using this class makes your Eiffel code non portable
-- on other Eiffel systems. This class may also be modified in further release
-- for a better interoperability between Java and C low level arrays.
--
-- Each class using some attribute of NATIVE_ARRAY type need an attribute
-- named `capacity' with value set to the size of the NATIVE_ARRAY. Value
-- has to be ajusted after each calloc/realloc/create_from.
--
inherit SAFE_EQUAL[E]

feature -- Basic features:

   element_sizeof: INTEGER is
         -- The size in number of bytes for type `E'.
      external "SmartEiffel"
      end

   calloc(nb_elements: INTEGER): like Current is
         -- Allocate a new array of `nb_elements' of type `E'.
         -- The new array is initialized with default values.
      require
         nb_elements > 0
      external "SmartEiffel"
      ensure
	 Result.all_default(nb_elements - 1)
      end

   item(index: INTEGER): E is
         -- To read an `item'.
         -- Assume that `calloc' is already done and that `index'
         -- is the range [0 .. nb_elements-1].
      external "SmartEiffel"
      end

   put(element: E; index: INTEGER) is
         -- To write an item.
         -- Assume that `calloc' is already done and that `index'
         -- is the range [0 .. nb_elements-1].
      external "SmartEiffel"
      end

feature

   realloc(old_nb_elts, new_nb_elts: INTEGER): like Current is
         -- Assume Current is a valid NATIVE_ARRAY in range
         -- [0 .. `old_nb_elts'-1]. Allocate a bigger new array in
         -- range [0 .. `new_nb_elts'-1].
         -- Old range is copied in the new allocated array.
         -- New items are initialized with default values.
      require
         is_not_null
         old_nb_elts > 0
         old_nb_elts < new_nb_elts
      do
         Result := calloc(new_nb_elts)
         Result.copy_from(Current,old_nb_elts - 1)
      ensure
         Result.is_not_null
      end

feature -- Comparison:

   memcmp(other: like Current; capacity: INTEGER): BOOLEAN is
         -- True if all elements in range [0..capacity-1] are
         -- identical using `equal'. Assume Current and `other'
         -- are big enough.
         -- See also `fast_memcmp'.
      require
         capacity > 0 implies other.is_not_null
      local
         i: INTEGER
      do
         from
            i := capacity - 1
         until
            i < 0 or else not safe_equal(item(i),other.item(i))
         loop
            i := i - 1
         end
         Result := i < 0
      end

   fast_memcmp(other: like Current; capacity: INTEGER): BOOLEAN is
         -- Same jobs as `memcmp' but uses infix "=" instead `equal'.
      require
         capacity > 0 implies other.is_not_null
      local
         i: INTEGER
      do
         from
            i := capacity - 1
         until
            i < 0 or else item(i) /= other.item(i)
         loop
            i := i - 1
         end
         Result := i < 0
      end

   deep_memcmp(other: like Current; capacity: INTEGER): BOOLEAN is
         -- Same jobs as `memcmp' but uses `is_deep_equal' instead `equal'.
      local
         i: INTEGER
	 e1, e2: like item
      do
         from
            i := capacity - 1
	    Result := True
         until
            not Result or else i < 0
         loop
	    e1 := item(i)
	    e2 := other.item(i)
	    if e1 = e2 then
	    elseif e1 /= Void then
	       if e2 /= Void then
		  Result := e1.is_deep_equal(e2)
	       else
		  Result := False
	       end
	    else
	       Result := False
	    end
            i := i - 1
         end
      end

feature -- Searching:

   index_of(element: like item; upper: INTEGER): INTEGER is
         -- Give the index of the first occurrence of `element' using
         -- `is_equal' for comparison.
         -- Answer `upper + 1' when `element' is not inside.
      require
         upper >= -1
      do
         from
         until
            Result > upper or else safe_equal(element,item(Result))
         loop
            Result := Result + 1
         end
      end

   fast_index_of(element: like item; upper: INTEGER): INTEGER is
         -- Same as `index_of' but use basic `=' for comparison.
      require
         upper >= -1
      do
         from
         until
            Result > upper or else element = item(Result)
         loop
            Result := Result + 1
         end
      end

   has(element: like item; upper: INTEGER): BOOLEAN is
         -- Look for `element' using `is_equal' for comparison.
         -- Also consider `has' to choose the most appropriate.
      require
         upper >= -1
      local
         i: INTEGER
      do
         from
            i := upper
         until
            Result or else i < 0
         loop
            Result := safe_equal(element,item(i))
            i := i - 1
         end
      end

   fast_has(element: like item; upper: INTEGER): BOOLEAN is
         -- Look for `element' using basic `=' for comparison.
         -- Also consider `has' to choose the most appropriate.
      require
         upper >= -1
      local
         i: INTEGER
      do
         from
            i := upper
         until
            i < 0 or else element = item(i)
         loop
            i := i - 1
         end
         Result := i >= 0
      end

feature -- Removing:

   remove_first(upper: INTEGER) is
         -- Assume `upper' is a valid index.
         -- Move range [1 .. `upper'] by 1 position left.
      require
         upper >= 0
      local
         i: INTEGER
      do
         from until i = upper
         loop
            put(item(i + 1),i)
            i := i + 1
         end
      end

   remove(index, upper: INTEGER) is
         -- Assume `upper' is a valid index.
         -- Move range [`index' + 1 .. `upper'] by 1 position left.
      require
         index >= 0
         index <= upper
      local
         i: INTEGER
      do
         from i := index until i = upper
         loop
            put(item(i + 1),i)
            i := i + 1
         end
      end

feature -- Replacing:

   replace_all(old_value, new_value: like item; upper: INTEGER) is
         -- Replace all occurrences of the element `old_value' by `new_value'
         -- using `is_equal' for comparison.
         -- See also `fast_replace_all' to choose the apropriate one.
      require
         upper >= -1
      local
         i: INTEGER
      do
         from i := upper until i < 0
         loop
            if safe_equal(old_value,item(i)) then
               put(new_value,i)
            end
            i := i - 1
         end
      end

   fast_replace_all(old_value, new_value: like item; upper: INTEGER) is
         -- Replace all occurrences of the element `old_value' by `new_value'
         -- using basic `=' for comparison.
         -- See also `replace_all' to choose the apropriate one.
      require
         upper >= -1
      local
         i: INTEGER
      do
         from i := upper until i < 0
         loop
            if old_value = item(i) then
               put(new_value,i)
            end
            i := i - 1
         end
      end

feature -- Adding:

   copy_at(at: INTEGER; src: like Current; src_capacity: INTEGER) is
         -- Copy range [0 .. `src_capacity - 1'] of `src' to range
	 -- [`at' .. `at + src_capacity - 1'] of `Current'.
	 -- No subscript checking.
      require
         at >= 0; src_capacity >= 0
      local
         at_idx, src_idx: INTEGER
      do
         from
            src_idx := src_capacity - 1
            at_idx := at + src_idx
         until
            src_idx < 0
         loop
            put(src.item(src_idx),at_idx)
            src_idx := src_idx - 1
            at_idx := at_idx - 1
         end
      end

   copy_slice(at: INTEGER; src: like Current; src_min, src_max: INTEGER) is
         -- Copy range [`src_min' .. `src_max'] of `src' to range
         -- [`at' .. `at + src_max - src_min - 1'] of `Current'.
	 -- No subscript checking.
      require
         at >= 0
         src_min <= src_max + 1
      local
         i1, i2: INTEGER
      do
         from
            i1 := at
	    i2 := src_min
         until
            i2 > src_max
         loop
            put(src.item(i2),i1)
            i2 := i2 + 1
            i1 := i1 + 1
         end
      end

feature -- Other:

   set_all_with(v: like item; upper: INTEGER) is
         -- Set all elements in range [0 .. upper] with
         -- value `v'.
      require
	 upper >= -1
      local
         i: INTEGER
      do
         from i := upper until i < 0
         loop
            put(v,i)
            i := i - 1
         end
      end

   clear_all(upper: INTEGER) is
         -- Set all elements in range [0 .. `upper'] with
         -- the default value.
      require
	 upper >= -1
      local
         v: E; i: INTEGER
      do
         from i := upper until i < 0
         loop
            put(v,i)
            i := i - 1
         end
      ensure
	 all_default(upper)
      end

   clear(lower, upper: INTEGER) is
         -- Set all elements in range [`lower' .. `upper'] with
         -- the default value
      require
         lower >= 0
         upper >= lower - 1
      local
         v: E; i: INTEGER
      do
         from i := lower until i > upper
         loop
            put(v, i)
            i := i + 1
         end
      end

   copy_from(model: like Current; upper: INTEGER) is
         -- Assume `upper' is a valid index both in Current and `model'.
      require
	 upper >= -1
      local
         i: INTEGER
      do
         from i := upper until i < 0
         loop
            put(model.item(i),i)
            i := i - 1
         end
      end

   deep_twin_from(capacity: INTEGER): like Current is
	 -- To implement `deep_twin'. Allocate a new array of `capacity' 
	 -- initialized  with `deep_twin'. Assume `capacity' is valid both in 
	 -- `Current' and `model'.
      require
	 capacity >= 0
      local
         i: INTEGER
	 element: like item
      do
	 if capacity > 0 then
	    from
	       Result := calloc(capacity)
	       i := capacity - 1
	    until
	       i < 0
	    loop
	       element := item(i)
	       if element /= Void then
		  element := element.deep_twin
	       end
	       Result.put(element,i)
	       i := i - 1
	    end
	 end
      end

   move(lower, upper, offset: INTEGER) is
         -- Move range [`lower' .. `upper'] by `offset' positions.
         -- Freed positions are not initialized to default values.
      require
         lower >= 0
         upper >= lower
         lower + offset >= 0
      local
         i: INTEGER
      do
         if offset = 0 then
         elseif offset < 0 then
            from i := lower until i > upper
            loop
               put(item(i), i + offset)
               i := i + 1
            end
         else
            from i := upper until i < lower
            loop
               put(item(i), i + offset)
               i := i - 1
            end
         end
      end

   occurrences(element: like item; upper: INTEGER): INTEGER is
         -- Number of occurrences of `element' in range [0..upper]
         -- using `equal' for comparison.
         -- See also `fast_occurrences' to chose the apropriate one.
      require
	 upper >= -1
      local
         i: INTEGER
      do
         from i := upper until i < 0
         loop
            if safe_equal(element,item(i)) then
               Result := Result + 1
            end
            i := i - 1
         end
      end

   fast_occurrences(element: like item; upper: INTEGER): INTEGER is
         -- Number of occurrences of `element' in range [0..upper]
         -- using basic "=" for comparison.
         -- See also `fast_occurrences' to chose the apropriate one.
      require
	 upper >= -1
      local
         i: INTEGER
      do
         from i := upper until i < 0
         loop
            if element = item(i) then
               Result := Result + 1
            end
            i := i - 1
         end
      end

   all_default(upper: INTEGER): BOOLEAN is
         -- Do all items in range [0 .. `upper'] have their type's
	 -- default value?
	 -- Note: for non Void items, the test is performed with the 
	 -- `is_default' predicate.
      require
         upper >= -1
      local
         i: INTEGER; v: like item
      do
         from
            Result := True
            i := upper
         until
            i < 0 or else not Result
         loop
	    v := item(i)
	    if v /= Void then
	       Result := v.is_default
	    end
            i := i - 1
         end
      end

feature -- Interfacing with C:

   to_external: POINTER is
         -- Gives access to the C pointer on the area of storage.
      do
         Result := to_pointer
      end

   from_pointer(pointer: POINTER): like Current is
         -- Convert `pointer' into Current type.
      external "SmartEiffel"
      end

   is_not_null: BOOLEAN is
      do
         Result := to_pointer.is_not_null
      end

   is_null: BOOLEAN is
      do
         Result := to_pointer.is_null
      end

end -- NATIVE_ARRAY[E]
