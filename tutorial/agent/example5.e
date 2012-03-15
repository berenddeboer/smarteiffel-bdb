class EXAMPLE5
--
-- There is also a `for_all' routine in COLLECTION (i.e. ARRAY,
-- FIXED_ARRAY, LINKED_LIST, TWO_WAY_LINKED_LIST).
-- You can watch the result using sedb, the SmartEiffel DeBugger.
--

creation make

feature

   make is
      local
         my_array: ARRAY[INTEGER]; bool: BOOLEAN
      do
	 my_array := <<2,3,4>>

	 bool := my_array.for_all(agent greater_than(?, 1))
	 sedb_breakpoint

	 bool := my_array.for_all(agent greater_than(1, ?))
	 sedb_breakpoint

	 bool := my_array.exists(agent greater_than(4, ?))
	 sedb_breakpoint

	 bool := my_array.exists(agent greater_than(?, 4))
	 sedb_breakpoint
      end

feature {NONE}

   greater_than(item, value: INTEGER): BOOLEAN is
      do
	 Result := item > value
      end

end -- EXAMPLE5

