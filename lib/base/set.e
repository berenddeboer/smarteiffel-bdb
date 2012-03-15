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
class SET[E->HASHABLE]
   --
   -- Definition of a mathematical set of hashable objects. All common
   -- operations on mathematical sets are available.
   --

inherit ANY redefine is_equal, copy end

creation make, with_capacity, from_collection

feature

   Default_size: INTEGER is 53
	 -- Minimum size for storage in number of items.

feature {SET}

   buckets: NATIVE_ARRAY[SET_NODE[E]]
	 -- The `buckets' storage area is the primary hash table of `capacity'
	 -- elements. To search some element, the first access is done in
	 -- `buckets' using the remainder of the division of the key `hash_code' 
	 -- by `capacity'. In order to try to avoid clashes, `capacity' is 
	 -- always a prime number (selected using HASH_TABLE_SIZE).

feature {SET} -- Internal cache handling:

   cache_user: INTEGER
         -- The last user's external index in range [1 .. `count'] (see `item'
         -- and `valid_index' for example) may be saved in `cache_user' otherwise
         -- -1 to indicate that the cache is not active. When the cache is
         -- active, the corresponding index in `buckets' is save in
         -- `cache_buckets' and the corresponding node in `cache_node'.

   cache_node: SET_NODE[E]
	 -- Meaningful only when `cache_user' is not -1.

   cache_buckets: INTEGER
	 -- Meaningful only when `cache_user' is not -1.

feature {NONE}

   make is
	 -- Create an empty set. Internal storage `capacity' of the set is
	 -- initialized using the `Default_size' value. Then, tuning of needed
	 -- storage size is done automatically according to usage. If you
	 -- are really sure that your set is always really bigger than
	 -- `Default_size', you may use `with_capacity' to save some execution 
	 -- time.
      do
	 with_capacity(Default_size)
      ensure
	 is_empty
	 capacity = Default_size
      end

   with_capacity(medium_size: INTEGER) is
	 -- Create an empty set using `medium_size' as an appropriate value
	 -- to help initialization of `capacity'. Thus, this feature may be
	 -- used in place of `make' to save some execution time if one is
	 -- sure that storage size will rapidly become really bigger than
	 -- `Default_size' (if not sure, simply use `make'). Anyway, the
	 -- initial `medium_size' value is just an indication and never a
	 -- limit for the possible `capacity'. Keep in mind that the
	 -- `capacity' tuning is done automatically according to usage.
      require
	 medium_size > 0
      local
	 new_capacity: INTEGER; hts: HASH_TABLE_SIZE
      do
	 new_capacity := hts.prime_number_ceiling(medium_size)
	 buckets := buckets.calloc(new_capacity)
	 capacity := new_capacity
	 cache_user := -1
	 count := 0
      ensure
	 is_empty
	 capacity >= medium_size
      end

feature -- Counting:

   count: INTEGER
	 -- Cardinality of the set (i.e. actual `count' of stored elements).

   capacity: INTEGER
	 -- Of the `buckets' storage area.

   is_empty: BOOLEAN is
	 -- Is the set empty?
      do
	 Result := (count = 0)
      ensure
	 Result = (count = 0)
      end

feature -- Adding and removing:

   add(e: like item) is
	 -- Add a new item to the set: the mathematical definition of
	 -- adding in a set is followed.
      require
	 e /= Void
      local
	 h, idx: INTEGER
	 node: like cache_node
      do
	 cache_user := -1
	 from
	    h := e.hash_code
	    idx := h \\ capacity
	    node := buckets.item(idx)
	 until
	    node = Void or else node.item.is_equal(e)
	 loop
	    node := node.next
	 end
	 if node = Void then
	    if capacity = count then
	       increase_capacity
	       idx := h \\ capacity
	    end
	    !!node.make(e,buckets.item(idx))
	    buckets.put(node,idx)
	    count := count + 1
	 end
      ensure
	 added: has(e)
	 not_in_then_added: not(old has(e)) implies (count = old count + 1)
	 in_then_not_added: (old has(e)) implies (count = old count)
      end

   remove(e: like item) is
	 -- Remove item `e' from the set: the mathematical definition of
	 -- removing from a set is followed.
      require
	 e /= Void
      local
         h, idx: INTEGER
         node, previous_node: like cache_node
      do
	 cache_user := -1
	 h := e.hash_code
	 idx := h \\ capacity
	 node := buckets.item(idx)
	 if node /= Void then
	    if node.item.is_equal(e) then
	       count := count - 1
	       node := node.next
	       buckets.put(node,idx)
	    else
	       from
		  previous_node := node
		  node := node.next
	       until
		  node = Void or else node.item.is_equal(e)
	       loop
		  previous_node := node
		  node := node.next
	       end
	       if node /= Void then
		  count := count - 1
		  previous_node.set_next(node.next)
	       end
	    end
	 end
      ensure
	 removed: not has(e)
	 not_in_not_removed: not(old has(e)) implies count = old count
	 in_then_removed: old has(e) implies count = old count - 1
      end

   clear is
	 -- Empty the current set.
      do
         buckets.set_all_with(Void,capacity - 1)
         cache_user := -1
         count := 0
      ensure
	 is_empty
      end

feature -- Looking and searching:

   has(e: like item): BOOLEAN is
	 -- Is element `e' in the set?
      require
	 e /= Void
      local
	 idx: INTEGER; node: like cache_node
      do
	 from
	    idx := e.hash_code \\ capacity
	    node := buckets.item(idx)
	 until
	    node = Void or else node.item.is_equal(e)
	 loop
	    node := node.next
	 end
	 Result := node /= Void
      ensure
	 Result implies (not is_empty)
      end

   reference_at(e: like item): like item is
	 -- When Is element `e' in the set?
      require
	 e /= Void
	 not e.is_expanded_type
      local
	 idx: INTEGER; node: like cache_node
      do
	 from
	    idx := e.hash_code \\ capacity
	    node := buckets.item(idx)
	 until
	    node = Void or else node.item.is_equal(e)
	 loop
	    node := node.next
	 end
	 if node /= Void then
	    Result := node.item
	 end
      ensure
	 has(e) implies Result /= Void
      end

feature -- To provide iterating facilities:

   lower: INTEGER is 1

   upper: INTEGER is
      do
         Result := count
      ensure
         Result = count
      end

   valid_index(index: INTEGER): BOOLEAN is
      do
         Result := (1 <= index) and then (index <= count)
      ensure
         Result =  index.in_range(lower,upper)
      end

   item(index: INTEGER): E is
	 -- Return the item indexed by `index'.
      require
	 valid_index(index)
      do
         set_cache_user(index)
         Result := cache_node.item
      ensure
	 has(Result)
      end

   get_new_iterator: ITERATOR[E] is
      do
	 !ITERATOR_ON_SET[E]!Result.make(Current)
      end

feature -- Mathematical operations:

   union(other: like Current) is
	 -- Make the union of the `Current' set with `other'.
      require
	 other /= Void
      local
	 i: INTEGER; e: like item
      do
	 from
	    i := 1
	 until
	    i > other.count
	 loop
	    e := other.item(i)
	    if not has(e) then
	       add(e)
	    end
	    i := i + 1
	 end
      ensure
	 count <= old count + other.count
      end

   infix "+" (other: like Current): like Current is
	 -- Return the union of the `Current' set with `other'.
      require
	 other /= Void
      do
	 Result := twin
	 Result.union(other)
      ensure
	 Result.count <= count + other.count
	 Current.is_subset_of(Result) and then
	 other.is_subset_of(Result)
      end

   intersection(other: like Current) is
	 -- Make the intersection of the `Current' set with `other'.
      require
	 other /= Void
      local
	 i, c: INTEGER node1, node2: like cache_node
      do
	 cache_user := -1
	 from
	    i := capacity - 1
	    c := count
	 until
	    c = 0
	 loop
	    from
	       node1 := buckets.item(i)
	    until
	       node1 = Void or else other.has(node1.item)
	    loop
	       node1 := node1.next
	       c := c - 1
	       buckets.put(node1,i)
	       count := count - 1
	    end
	    if node1 /= Void then
	       from
		  node2 := node1.next
		  c := c - 1
	       until
		  node2 = Void
	       loop
		  if not other.has(node2.item) then
		     node1.set_next(node2.next)
		     count := count - 1
		  else
		     node1 := node2
		  end
		  node2 := node2.next
		  c := c - 1
	       end
	    end
	    i := i - 1
	 end
      ensure
	 count <= other.count.min(old count)
      end

   infix "^" (other: like Current): like Current is
	 -- Return the intersection of the `Current' set with `other'.
      require
	 other /= Void
      do
	 Result := twin
	 Result.intersection(other)
      ensure
	 Result.count <= other.count.min(count)
	 Result.is_subset_of(Current) and then
	 Result.is_subset_of(other)
      end

   minus(other: like Current) is
	 -- Make the set `Current' - `other'.
      require
	 other /= Void
      local
	 i: INTEGER
      do
	 if other = Current then
	    clear
	 else
	    from
	       i := 1
	    until
	       i > other.count
	    loop
	       remove(other.item(i))
	       i := i + 1
	    end
	 end
      ensure
	 count <= old count
      end

   infix "-" (other: like Current): like Current is
	 -- Return  the set `Current' - `other'.
      require
	 other /= Void
      do
	 Result := twin
	 Result.minus(other)
      ensure
	 Result.count <= count
	 Result.is_subset_of(Current)
      end

feature -- Comparison:

   is_subset_of(other: like Current): BOOLEAN is
	 -- Is the `Current' set a subset of `other'?
      require
	 other /= Void
      local
	 i: INTEGER
      do
	 if Current = other then
	    Result := true
	 elseif count <= other.count then
	    from
	       Result := true
	       i := 1
	    until
	       not Result or else i > count
	    loop
	       Result := other.has(item(i))
	       i := i + 1
	    end
	 end
      ensure
	 Result implies count <= other.count
      end

   is_disjoint_from(other: like Current): BOOLEAN is
	 -- Is the `Current' set disjoint from `other' ?
      require
	 other /= Void
      local
	 i: INTEGER
      do
	 if Current /= other then
	    Result := true
	    i := 1
	    if count <= other.count then
	       from until
		  not Result or else i > count
	       loop
		  Result := not other.has(item(i))
		  i := i + 1
	       end
	    else
	       from until not Result or else i > other.count
	       loop
		  Result := not has(other.item(i))
		  i := i + 1
	       end
	    end
	 end
      ensure
	 Result = (Current ^ other).is_empty
      end

   is_equal(other: like Current): BOOLEAN is
	 -- Is the `Current' set equal to `other'?
      local
	 i: INTEGER
      do
	 if Current = other then
	    Result := true
	 elseif count = other.count then
	    from
	       Result := true
	       i := 1
	    until
	       not Result or else i > count
	    loop
	       Result := other.has(item(i))
	       i := i + 1
	    end
	 end
      ensure then
	 double_inclusion: Result = (is_subset_of(other) and
				     other.is_subset_of(Current))
      end

feature

   copy(other: like Current) is
	 -- Copy 'other' into the current set
      local
	 i: INTEGER
      do
	 -- Note: this is a naive implementation because we should
	 -- recycle already allocated nodes of `Current'.
	 from
	    if capacity = 0 then
	       with_capacity(other.count + 1)
	    else
	       clear
	    end
	    i := 1
	 until
	    i > other.count
	 loop
	    add(other.item(i))
	    i := i + 1
	 end
      end

   from_collection(model: COLLECTION[like item]) is
      local
         i, up: INTEGER
      do
         from
            with_capacity(model.count.max(1))
            up := model.upper
            i := model.lower
         until
            i > up
         loop
            add(model.item(i))
            i := i + 1
         end
      end

feature -- Agents based features:

   do_all(action: ROUTINE[ANY,TUPLE[E]]) is
	 -- Apply `action' to every item of `Current'.
      local
	 i: INTEGER
      do
	 from i := lower until i > upper
	 loop
	    action.call([item(i)])
	    i := i + 1
	 end
      end

   for_all(test: PREDICATE[ANY,TUPLE[E]]): BOOLEAN is
	 -- Do all items satisfy `test'?
      local
	 i: INTEGER
      do
	 from
	    Result := true
	    i := lower
	 until
	    not Result or else i > upper
	 loop
	    Result := test.item([item(i)])
	    i := i + 1
	 end
      end

   exists(test: PREDICATE[ANY,TUPLE[E]]): BOOLEAN is
	 -- Does at least one item satisfy `test'?
      local
	 i: INTEGER
      do
	 from
	    i := lower
	 until
	    Result or else i > upper
	 loop
	    Result := test.item([item(i)])
	    i := i + 1
	 end
      end

feature {NONE}

   increase_capacity is
         -- There is no more free slots: the set must grow.
      require
	 capacity = count
      local
	 i, idx, new_capacity: INTEGER; old_buckets: like buckets
	 node1, node2: like cache_node; hts: HASH_TABLE_SIZE
      do
	 from
	    new_capacity := hts.prime_number_ceiling(capacity + 1)
	    old_buckets := buckets
	    buckets := buckets.calloc(new_capacity)
	    i := capacity - 1
	    capacity := new_capacity
	 until
	    i < 0
	 loop
	    from
	       node1 := old_buckets.item(i)
	    until
	       node1 = Void
	    loop
	       node2 := node1.next
	       idx := node1.item.hash_code \\ capacity
	       node1.set_next(buckets.item(idx))
	       buckets.put(node1,idx)
	       node1 := node2
	    end
	    i := i - 1
	 end
	 cache_user := -1
      ensure
	 capacity > old capacity
	 count = old count
      end

   set_cache_user(index: INTEGER) is
      require
	 valid_index(index)
      do
         if index = cache_user + 1 then
	    from
	       cache_user := index
	       cache_node := cache_node.next
	    until
	       cache_node /= Void
	    loop
	       cache_buckets := cache_buckets + 1
	       cache_node := buckets.item(cache_buckets)
	    end
         elseif index = cache_user then
	 elseif index = 1 then
	    from
	       cache_user := 1
	       cache_buckets := 0
	       cache_node := buckets.item(cache_buckets)
	    until
	       cache_node /= Void
	    loop
	       cache_buckets := cache_buckets + 1
	       cache_node := buckets.item(cache_buckets)
	    end
	 else
	    from
	       set_cache_user(1)
	    until
	       cache_user = index
	    loop
	       set_cache_user(cache_user + 1)
	    end
         end
      ensure
         cache_user = index
         cache_buckets.in_range(0,capacity - 1)
         cache_node /= Void
      end

invariant

   capacity > 0

   capacity >= count

   cache_user.in_range(-1,count)

   cache_user > 0 implies cache_node /= Void

   cache_user > 0 implies cache_buckets.in_range(0,capacity - 1)

end -- SET[E->HASHABLE]
