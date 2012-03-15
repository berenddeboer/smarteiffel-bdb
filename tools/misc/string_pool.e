-- This file is part of SmartEiffel The GNU Eiffel Compiler Tools and Libraries
--
-- SmartEiffel is  free software;  you can redistribute it and/or  modify it
-- under  the terms of the  GNU General Public License, as published by  the
-- Free Software Foundation; either version 2, or (at your option) any later
-- version.
-- SmartEiffel is distributed in the hope that it will be useful but WITHOUT 
-- ANY WARRANTY;  without  even the implied warranty  of MERCHANTABILITY  or
-- FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
-- more details.  You should have received a copy of  the GNU General Public
-- License along with SmartEiffel;  see the file COPYING.  If not,  write to
-- the Free Software Foundation,  Inc., 59 Temple Place - Suite 330,  Boston, 
-- MA 02111-1307, USA.
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
deferred class STRING_POOL
   --
   -- The STRING_POOL is a collection of strings. It is initialized from
   -- another collection. The strings are not kept "as-is"; that way, you
   -- can reuse your initial collection, or the strings in it; the
   -- string_pool won't be changed.
   --
   -- Be aware that using a STRING_POOL is not always interesting, because
   -- it is very memory-consuming. It's advantage, though, is to be able to
   -- find if a string is in the pool or not (and find its index), very
   -- quickly.
   --
inherit
   GLOBALS
   VISITABLE

feature {STRING_POOL_VISITOR}

   accept(visitor: STRING_POOL_VISITOR) is
      deferred
      end

feature {ANY} -- Interface:

   has_empty: BOOLEAN
         -- The headers list has an empty string

   has(a_string: STRING): BOOLEAN is
      require
         string_not_void:  a_string /= Void
         --string_not_empty: a_string.count > 0
      do
         compute_final_state(a_string, 1, a_string.count)
         Result := last_match /= unknown_state
      end

   has_substring(a_string: STRING; first, last: INTEGER): BOOLEAN is
      require
         string_not_void:   a_string /= Void
         --string_not_empty:  a_string.count > 0
         first_in_string:   first > 0
         last_in_string:    last <= a_string.count
         first_before_last: last >= first
      do
         compute_final_state(a_string, first, last)
         Result := last_match /= unknown_state
      end

   index_of(a_string: STRING): INTEGER is
      require
         string_not_void:  a_string /= Void
         --string_not_empty: a_string.count > 0
         has_string:       has(a_string)
      do
         compute_final_state(a_string, 1, a_string.count)
         Result := last_external_match
      end

   index_of_substring(a_string: STRING; first, last: INTEGER): INTEGER is
      require
         string_not_void:   a_string /= Void
         --string_not_empty:  a_string.count > 0
         first_in_string:   first > 0
         last_in_string:    last <= a_string.count
         first_before_last: last >= first
         has_substring:     has_substring(a_string, first, last)
      do
         compute_final_state(a_string, first, last)
         Result := last_external_match
      end

feature {ANY} -- Initialization:

   from_collection(a_headers: COLLECTION[STRING]) is
         -- Initializes the automaton. The given strings will be the ones
         -- that can be matched. In that case, `match' will return the index
         -- of the matched string in that collection.
         --
         -- Be aware that the procesing time is quite heavy during the
         -- initialization. It's the pay-off to make it really lighter
         -- matches. Don't use the string_pool for a one-time test, it's only
         -- useful in the long run.
         --
         -- After initialization, you can safely discard or modify the
         -- collection; it will not change the automaton.
      require
         headers_not_void:  a_headers /= Void
         headers_not_empty: a_headers.count > 0
         unique_headers:    -- each string contains a different word
         --headers_not_empty: -- each string is non-empty
      local
         cs: COLLECTION_SORTER[STRING]
      do
         counter.increment
         id := counter.value

         create headers.from_collection(a_headers)
         cs.sort(headers)
         count_states

         make_transitions_array
         compile_headers
         externalize_tags(a_headers)
         report(a_headers)
      end

feature {NONE} -- At initialization time:

   report(a_headers: COLLECTION[STRING]) is
      local
         i, j, n, st: INTEGER
         s: STRING
      do
         echo.put_string(once "STRING_POOL#")
         echo.put_integer(id)
         echo.put_string(once ": ")
         echo.put_integer(maxstate+1)
         echo.put_string(once " transition(s)%N")
         from
            i := a_headers.lower
         until
            i > a_headers.upper
         loop
            s := a_headers.item(i)
            echo.put_string("%T%"")
            echo.put_string(s)
            echo.put_string(once "%": ")
            if s.is_empty then
               st := empty_idx
            else
               from
                  st := unknown_state
                  n := s.count
                  j := 1
               until
                  j > n
               loop
                  if j > 1 then
                     echo.put_character(',')
                  end
                  st := state(st, s.item(j))
                  echo.put_integer(st)
                  j := j + 1
               end
            end
            echo.put_string(once " -> ")
            io.flush
            echo.put_integer(tag_state.at(st))
            echo.put_new_line
            i := i + 1
         end
      end

   count_states is
      local
         c, k: CHARACTER
         i, j: INTEGER
         again, next_c: BOOLEAN
         s: STRING
         defstate, oldstate, newstate: INTEGER
      do
         transition_memory.make(headers.count)
         transition_memory.set_all_with(unknown_state)
         from
            maxstate := 0
            newstate := unknown_state
            defstate := headers.upper
            again := true
            i := 1
         until
            not again
         loop
            again := false
            from
               next_c := true
               j := headers.lower
            until
               j > headers.upper
            loop
               s := headers.item(j)
               if not has_empty and then s.is_empty then
                  has_empty := True
                  empty_idx := j
               end
               debug
                  io.put_string(s)
                  io.put_string(once "%T[")
                  io.put_integer(i)
                  io.put_string(once "]%N")
               end
               if oldstate /= transition_memory.item(j) then
                  oldstate := transition_memory.item(j)
                  next_c := true
               end
               if i > s.count then
                  next_c := true
               else
                  check
                     transition_memory.item(j) /= j
                  end
                  again := true
                  k := s.item(i)
                  if i = s.count then
                     check
                        next_c or else c /= k
                     end
                     newstate := j
                     c := k
                  elseif next_c or else c /= k then
                     defstate := defstate + 1
                     newstate := defstate
                     c := k
                  end
                  next_c := false
                  check
                     newstate /= unknown_state
                  end
                  transition_memory.put(newstate, j)
               end
               j := j + 1
            end
            i := i + 1
         end

         maxstate := defstate

         debug
            io.put_string(once "maxstate = ")
            io.put_integer(maxstate)
            io.put_new_line
         end
      end

   compile_headers is
         -- Create the automaton.
      local
         c, k: CHARACTER
         i, j: INTEGER
         again, next_c: BOOLEAN
         s: STRING
         defstate, oldstate, newstate: INTEGER
      do
         transition_memory.make(headers.count)
         transition_memory.set_all_with(unknown_state)

         newstate := unknown_state
         defstate := headers.upper

         from
            again := true
            i := 1
         until
            not again
         loop
            again := false
            from
               next_c := true
               j := headers.lower
            until
               j > headers.upper
            loop
               s := headers.item(j)
               debug
                  io.put_string(s)
                  io.put_string(once "%T[")
                  io.put_integer(i)
                  io.put_string(once "]%N")
               end
               if oldstate /= transition_memory.item(j) then
                  oldstate := transition_memory.item(j)
                  next_c := true
               end
               if i > s.count then
                  next_c := true
               else
                  check
                     transition_memory.item(j) /= j
                  end
                  again := true
                  k := s.item(i)
                  if i = s.count then
                     check
                        next_c or else c /= k
                     end
                     newstate := j
                     c := k
                     set_state(newstate, oldstate, k)
                  elseif next_c or else c /= k then
                     defstate := defstate + 1
                     newstate := defstate
                     c := k
                     set_state(newstate, oldstate, k)
                  end
                  next_c := false
                  check
                     newstate /= unknown_state
                  end
                  transition_memory.put(newstate, j)
               end
               j := j + 1
            end
            i := i + 1
         end
      end

   externalize_tags(a_headers: COLLECTION[STRING]) is
         -- Create tag_state
      local
         intern, extern: INTEGER; s: STRING
      do
         if tag_state = Void then
            create tag_state.with_capacity(headers.count)
         else
            tag_state.clear
         end

         from
            extern := a_headers.lower
         until
            extern > a_headers.upper
         loop
            s := a_headers.item(extern)
            intern := the_final_state(s, 1, s.count)
            debug
               echo.put_integer(intern)
               echo.put_string(once " [int] <-> ")
               echo.put_integer(extern)
               echo.put_string(once " [ext]%N")
            end
            tag_state.put(extern, intern)
            extern := extern + 1
         end
      end

feature {NONE} -- State management:

   make_transitions_array is
      deferred
      end

   set_state(new_state, previous_state: INTEGER; character: CHARACTER) is
      require
         previous_state.in_range(unknown_state, maxstate)
         new_state.in_range(0, maxstate)
      deferred
      ensure
         state(previous_state, character) = new_state
      end

   state(previous_state: INTEGER; character: CHARACTER): INTEGER is
      require
         previous_state.in_range(unknown_state, maxstate)
      deferred
      end

feature {NONE} -- Finding a string:

   compute_final_state(a_string: STRING; first, last: INTEGER) is
      do
         last_match := the_final_state(a_string, first, last)
         if last_match > headers.count then
            last_match := unknown_state
         elseif last_match /= unknown_state then
            check
               headers.item(last_match).is_equal(a_string.substring(first, last))
            end
            -- now externalize
            last_external_match := tag_state.at(last_match)
         end
      end

   the_final_state(a_string: STRING; first, last: INTEGER): INTEGER is
      local
         i: INTEGER
      do
         if a_string.is_empty then
            Result := empty_idx
         else
            from
               Result := state(unknown_state, a_string.item(first))
               i := first + 1
            until
               i > last or else Result = unknown_state
            loop
               Result := state(Result, a_string.item(i))
               i := i + 1
            end
         end
      end

feature {NONE}

   maxstate: INTEGER
   id: INTEGER

   empty_idx: INTEGER

   last_match: INTEGER
   last_external_match: INTEGER

   tag_state: DICTIONARY[INTEGER, INTEGER] -- internal => external states

feature {NONE}

   unknown_state: INTEGER is -1

   headers: FIXED_ARRAY[STRING]

   transition_memory: FIXED_ARRAY[INTEGER] is
      once
         create Result.with_capacity(4)
      end

   counter: COUNTER is
      once
         create Result
      end

end -- STRING_POOL