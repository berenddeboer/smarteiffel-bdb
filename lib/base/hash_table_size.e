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
expanded class HASH_TABLE_SIZE
--
-- Some useful features to deal with prime INTEGER values in order to
-- select an appropriate size for some hash table (used for example
-- by the DICTIONARY class as well as by the SET class).
--

feature

   prime_number_ceiling(integer: INTEGER): INTEGER is
         -- A good prime number, large enough, and no smaller than `integer'.
      do
	 if integer <= 53 then
	    -- This seems to be a good minimum value to start hashing with.
	    Result := 53
	 elseif integer <= 97 then
	    Result := 97
	 elseif integer <= 193 then
	    Result := 193
	 elseif integer <= 389 then
	    Result := 389
	 elseif integer <= 769 then
	    Result := 769
	 elseif integer <= 1543 then
	    Result := 1543
	 elseif integer <= 3079 then
	    Result := 3079
	 elseif integer <= 6151 then
	    Result := 6151
	 elseif integer <= 12289 then
	    Result := 12289
	 elseif integer <= 24593 then
	    Result := 24593
	 elseif integer <= 49157 then
	    Result := 49157
	 elseif integer <= 98317 then
	    Result := 98317
	 elseif integer <= 196613 then
	    Result := 196613
	 elseif integer <= 393241 then
	    Result := 393241
	 elseif integer <= 786433 then
	    Result := 786433
	 elseif integer <= 1572869 then
	    Result := 1572869
	 elseif integer <= 3145739 then
	    Result := 3145739
	 elseif integer <= 6291469 then
	    Result := 6291469
	 elseif integer <= 12582917 then
	    Result := 12582917
	 elseif integer <= 25165843 then
	    Result := 25165843
	 elseif integer <= 50331653 then
	    Result := 50331653
	 elseif integer <= 100663319 then
	    Result := 100663319
	 elseif integer <= 201326611 then
	    Result := 201326611
	 elseif integer <= 402653189 then
	    Result := 402653189
	 elseif integer <= 805306457 then
	    Result := 805306457
	 else
	    Result := 1610612741
	    -- This should be enough !
	 end
      ensure
	 Result >= integer
      end

end
