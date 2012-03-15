class EXAMPLE4
--
-- The target itself can be an open operand:
--

creation make

feature

   make is
      local
         my_array: ARRAY[FRUIT]
      do
	 my_array := <<create {PEACH}, create {APPLE}>>

	 my_array.do_all(agent {FRUIT}.display)

      end

end -- EXAMPLE4
