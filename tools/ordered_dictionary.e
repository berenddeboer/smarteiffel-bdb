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
class ORDERED_DICTIONARY[V, K->HASHABLE]
   --
   -- Used by INI_PARSER to be sure that the key iterator wanders through the
   -- key set in the order in which they were added.
   --
inherit
   HASHED_DICTIONARY[V, K]
      redefine
         put, add,
         get_new_iterator_on_keys,
         with_capacity
      end
   VISITABLE
      undefine
         is_equal, copy
      end

creation
   make, with_capacity

feature {ORDERED_DICTIONARY_VISITOR}

   accept(visitor: ORDERED_DICTIONARY_VISITOR[V, K]) is
      do
         visitor.visit_ordered_dictionary(Current)
      end

feature {ANY}

   put(v: V; k: K) is
      obsolete "Don't use this feature! Use `add' instead."
      do
         crash
      end

   add(v: V; k: K) is
      do
         Precursor(v, k)
         ordered_keys.add_last(k)
      end

   get_new_iterator_on_keys: ITERATOR[K] is
      do
         Result := ordered_keys.get_new_iterator
      end

feature {NONE}

   with_capacity(medium_size: INTEGER) is
      do
         Precursor(medium_size)
         create ordered_keys.with_capacity(medium_size)
      end

   ordered_keys: FAST_ARRAY[K]

invariant

   count = ordered_keys.count

end
