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
class DICTIONARY[V, K->HASHABLE]
   --
   -- Associative memory.
   -- Values of type `V' are stored using Keys of type `K'.
   --

inherit SAFE_EQUAL[V] redefine is_equal, copy end

creation make, with_capacity

feature {DICTIONARY}

   buckets: NATIVE_ARRAY[like cache_node]
	 -- The `buckets' storage area is the primary hash table of 
	 -- `capacity' elements. To search some key, the first access is 
	 -- done in `buckets' using the remainder of the division of the 
	 -- key `hash_code' by `capacity'. In order to try to avoid clashes, 
	 -- `capacity' is always a prime number (selected using 
	 -- HASH_TABLE_SIZE).

feature

   Default_size: INTEGER is 193
         -- Default size for the storage area in muber of items.

feature -- Counting:

   capacity: INTEGER
	 -- Of the `buckets' storage area.

   count: INTEGER
         -- Actual `count' of stored elements.

   is_empty: BOOLEAN is
	 -- Is it empty ?
      do
         Result := count = 0
      ensure
         Result = (count = 0)
      end

feature -- Basic access:

   has(k: K): BOOLEAN is
         -- Is there a value currently associated with key `k'?
      require
	 k /= Void
      local
	 idx: INTEGER; node: like cache_node
      do
	 from
	    idx := k.hash_code \\ capacity
	    node := buckets.item(idx)
	 until
	    node = Void or else node.key.is_equal(k)
	 loop
	    node := node.next
	 end
	 Result := node /= Void
      end

   at, infix "@" (k: K): V is
         -- Return the value associated to key `k'.
	 -- (See also `reference_at' if V is a reference type.)
      require
         has(k)
      local
	 idx: INTEGER; node: like cache_node
      do
	 from
	    idx := k.hash_code \\ capacity
	    node := buckets.item(idx)
	 until
	    node.key.is_equal(k)
	 loop
	    node := node.next
	 end
	 Result := node.item
      end

   reference_at(k: K): V is
         -- Return Void or the value associated with key `k'. Actually, this 
         -- feature is useful when the type of values (the type V) is a 
         -- reference type, to avoid using `has' just followed by `at' to get 
         -- the corresponding value.
      require
	 k /= Void
	 not Result.is_expanded_type
      local
	 idx: INTEGER; node: like cache_node
      do
	 from
	    idx := k.hash_code \\ capacity
	    node := buckets.item(idx)
	 until
	    node = Void or else node.key.is_equal(k)
	 loop
	    node := node.next
	 end
	 if node /= Void then
	    Result := node.item
	 end
      ensure
	 has(k) implies Result = at(k)
      end

feature

   put(v: V; k: K) is
	 -- Change some existing entry or `add' the new one. If there is
	 -- as yet no key `k' in the dictionary, enter it with item `v'.
	 -- Otherwise overwrite the item associated with key `k'.
      require
	 k /= Void
      local
	 h, idx: INTEGER; node: like cache_node
      do
	 from
	    h := k.hash_code
	    idx := h \\ capacity
	    node := buckets.item(idx)
	 until
	    node = Void or else node.key.is_equal(k)
	 loop
	    node := node.next
	 end
	 if node = Void then
	    if capacity = count then
	       increase_capacity
	       idx := h \\ capacity
	    end
	    create node.make(v,k,buckets.item(idx))
	    buckets.put(node,idx)
	    count := count + 1
            cache_user := -1
	 else
	    node.set_item(v)
	 end
      ensure
         v = at(k)
      end

   add(v: V; k: K) is
         -- To add a new entry `k' with its associated value `v'. Actually, 
         -- this is equivalent to call `put', but may run a little bit 
         -- faster.
      require
	 not has(k)
      local
	 idx: INTEGER; node: like cache_node
      do
	 cache_user := -1
	 if capacity = count then
	    increase_capacity
	 end
	 idx := k.hash_code \\ capacity
	 create node.make(v,k,buckets.item(idx))
	 buckets.put(node,idx)
	 count := count + 1
      ensure
	 count = 1 + old count
         v = at(k)
      end

feature -- Looking and searching some value:

   occurrences(v: V): INTEGER is
         -- Number of occurrences using `equal'.
	 -- See also `fast_occurrences' to chose the apropriate one.
      local
         i: INTEGER
      do
         from
            i := 1
         until
            i > count
         loop
            if safe_equal(v,item(i)) then
               Result := Result + 1
            end
            i := i + 1
         end
      ensure
         Result >= 0
      end

   fast_occurrences(v: V): INTEGER is
         -- Number of occurrences using `='.
	 -- See also `occurrences' to chose the apropriate one.
      local
         i: INTEGER
      do
         from
            i := 1
         until
            i > count
         loop
            if v = item(i) then
               Result := Result + 1
            end
            i := i + 1
         end
      ensure
         Result >= 0
      end

   key_at(v: V): K is
         -- Retrieve the key used for value `v' using `equal' for comparison.
      require
         occurrences(v) = 1
      local
         i: INTEGER
      do
         from
            i := 1
         until
            safe_equal(v,item(i))
         loop
            i := i + 1
         end
         Result := cache_node.key
      ensure
         safe_equal(at(Result),v)
      end

   fast_key_at(v: V): K is
         -- Retrieve the key used for value `v' using `=' for comparison.
      require
         fast_occurrences(v) = 1
      local
         i: INTEGER
      do
         from
            i := 1
         until
            v = item(i)
         loop
            i := i + 1
         end
         Result := cache_node.key
      ensure
         at(Result) = v
      end

feature -- Removing:

   remove(k: K) is
         -- Remove entry `k' (which may exist or not before this call).
      require
	 k /= Void
      local
         h, idx: INTEGER; node, previous_node: like cache_node
      do
	 cache_user := -1
	 h := k.hash_code
	 idx := h \\ capacity
	 node := buckets.item(idx)
	 if node /= Void then
	    if node.key.is_equal(k) then
	       count := count - 1
	       node := node.next
	       buckets.put(node,idx)
	    else
	       from
		  previous_node := node
		  node := node.next
	       until
		  node = Void or else node.key.is_equal(k)
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
         not has(k)
      end

   clear is
         -- Discard all items.
      do
         buckets.set_all_with(Void,capacity - 1)
         cache_user := -1
         count := 0
      ensure
         is_empty
	 capacity = old capacity
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

   item(index: INTEGER): V is
      require
         valid_index(index)
      do
         set_cache_user(index)
         Result := cache_node.item
      ensure
         Result = at(key(index))
      end

   key(index: INTEGER): K is
      require
         valid_index(index)
      do
         set_cache_user(index)
         Result := cache_node.key
      ensure
         at(Result) = item(index)
      end

   get_new_iterator_on_items: ITERATOR[V] is
      do
         !ITERATOR_ON_DICTIONARY_ITEMS[V]!Result.make(Current)
      end

   get_new_iterator_on_keys: ITERATOR[K] is
      do
         !ITERATOR_ON_DICTIONARY_KEYS[K]!Result.make(Current)
      end

   key_map_in(buffer: COLLECTION[K]) is
	 -- Append in `buffer', all available keys (this may be useful to
	 -- speed up the traversal).
      require
	 buffer /= Void
      local
	 node: like cache_node; i, idx: INTEGER
      do
	 from
	    i := count
	    node := buckets.item(idx)
	 until
	    i <= 0
	 loop
	    from
	    until
	       node /= Void
	    loop
	       idx := idx + 1
	       check idx < capacity end
	       node := buckets.item(idx)
	    end
	    buffer.add_last(node.key)
	    node := node.next
	    i := i - 1
	 end
      ensure
	 buffer.count = count + old buffer.count
      end

   item_map_in(buffer: COLLECTION[V]) is
	 -- Append in `buffer', all available items (this may be useful to
	 -- speed up the traversal).
      require
	 buffer /= Void
      local
	 node: like cache_node; i, idx: INTEGER
      do
	 from
	    i := count
	    node := buckets.item(idx)
	 until
	    i <= 0
	 loop
	    from
	    until
	       node /= Void
	    loop
	       idx := idx + 1
	       check idx < capacity end
	       node := buckets.item(idx)
	    end
	    buffer.add_last(node.item)
	    node := node.next
	    i := i - 1
	 end
      ensure
	 buffer.count = count + old buffer.count
      end

feature

   is_equal(other: like current): BOOLEAN is
	 -- Do both dictionaries have the same set of associations?
	 -- Keys are compared with `is_equal' and values are comnpared
	 -- with the basic = operator. See also `is_equal_map'.
      local
	 i: INTEGER
      do
         if Current = other then
            Result := True
         elseif count = other.count then
	    from
	       Result := True
	       i := 1
	    until
	       not Result or else i > count
	    loop
	       if other.has(key(i)) then
		  if other.at(key(i)) /= item(i) then
		     Result := False
		  else
		     i := i + 1
		  end
	       else
		  Result := False
	       end
	    end
         end
      ensure then
	 Result implies count = other.count
      end

   is_equal_map(other: like current): BOOLEAN is
	 -- Do both dictionaries have the same set of associations?
	 -- Both keys and values are compared with `is_equal'. See also `is_equal'.
      local
	 i: INTEGER
         k: K
      do
         if Current = other then
            Result := True
         elseif count = other.count then
	    from
	       Result := True
	       i := 1
	    until
	       not Result or else i > count
	    loop
	       k := key(i)
	       if other.has(k) then
		  if not safe_equal(other.at(k),item(i)) then
		     Result := False
		  else
		     i := i + 1
		  end
	       else
		  Result := False
	       end
	    end
         end
      end

   copy(other: like current) is
	 -- Reinitialize by copying all associations of `other'.
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
	    put(other.item(i),other.key(i))
	    i := i + 1
	 end
      end

feature -- Agents based features:

   do_all(action: ROUTINE[ANY,TUPLE[V,K]]) is
	 -- Apply `action' to every [V,K] associations of `Current'.
      local
	 i: INTEGER; v: V; k: K
      do
	 from i := lower until i > upper
	 loop
	    v := item(i)
	    k := cache_node.key
	    action.call([v,k])
	    i := i + 1
	 end
      end

   for_all(test: PREDICATE[ANY,TUPLE[V,K]]): BOOLEAN is
	 -- Do all [V,K] associations satisfy `test'?
      local
	 i: INTEGER; v: V; k: K
      do
	 from
	    Result := True
	    i := lower
	 until
	    not Result or else i > upper
	 loop
	    v := item(i)
	    k := cache_node.key
	    Result := test.item([v,k])
	    i := i + 1
	 end
      end

   exists(test: PREDICATE[ANY,TUPLE[V,K]]): BOOLEAN is
	 -- Does at least one [V,K] association satisfy `test'?
      local
	 i: INTEGER; v: V; k: K
      do
	 from
	    i := lower
	 until
	    Result or else i > upper
	 loop
	    v := item(i)
	    k := cache_node.key
	    Result := test.item([v,k])
	    i := i + 1
	 end
      end

feature -- Other features:

   internal_key(k: K): K is
	 -- Retrieve the internal key object which correspond to the existing
	 -- entry `k' (the one memorized into the `Current' dictionary).
      require
	 has(k)
      local
	 node: like cache_node
      do
	 from
	    node := buckets.item(k.hash_code \\ capacity)
	    Result := node.key
	 until
	    Result.is_equal(k)
	 loop
	    node := node.next
	    Result := node.key
	 end
      ensure
	 Result.is_equal(k)
      end

feature {NONE}

   increase_capacity is
         -- There is no more free slots: the dictionary must grow.
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
	       idx := node1.key.hash_code \\ capacity
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
	 -- Set the internal memory cache (`cache_user', `cache_node' and
	 -- `cache_buckets') to the appropriate valid value.
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

   cache_user: INTEGER
         -- The last user's external index in range [1 .. `count'] (see `item'
         -- and `valid_index' for example) may be saved in `cache_user' otherwise
         -- -1 to indicate that the cache is not active. When the cache is
         -- active, the corresponding index in `buckets' is save in
         -- `cache_buckets' and the corresponding node in `cache_node'.

   cache_node: DICTIONARY_NODE[V,K]
	 -- Meaningful only when `cache_user' is not -1.

   cache_buckets: INTEGER
	 -- Meaningful only when `cache_user' is not -1.

   make is
         -- Create an empty dictionary. Internal storage `capacity' of the
         -- dictionary is initialized using the `Default_size' value. Then,
         -- tuning of needed storage `capacity' is performed automatically
         -- according to usage. If you are really sure that your dictionary
         -- is always really bigger than `Default_size', you may consider to use
         -- `with_capacity' to save some execution time.
      do
         with_capacity(Default_size)
      ensure
         is_empty
         capacity = Default_size
      end

   with_capacity(medium_size: INTEGER) is
         -- May be used to save some execution time if one is sure that
         -- storage size will rapidly become really bigger than `Default_size'.
         -- When first `remove' occurs, storage size may naturally become
         -- smaller than `medium_size'. Afterall, tuning of storage size is
         -- done automatically according to usage.
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

invariant

   capacity > 0

   capacity >= count

   cache_user.in_range(-1,count)

   cache_user > 0 implies cache_node /= Void

   cache_user > 0 implies cache_buckets.in_range(0,capacity - 1)

end -- DICTIONARY[V,K->HASHABLE]

