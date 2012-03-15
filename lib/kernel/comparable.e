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
deferred class COMPARABLE
   --
   -- All classes handling COMPARABLE objects with a total order relation
   -- should inherit from this class.
   --

inherit ANY redefine is_equal end

feature

   is_equal(other: like Current): BOOLEAN is
      do
	 Result := (not (Current < other) and then not (other < Current))
      ensure then
	 trichotomy: Result = (not (Current < other) and not (other < Current))
      end

   infix "<" (other: like Current): BOOLEAN is
         -- Is `Current' strictly less than `other'?
      require
         other_exists: other /= Void
      deferred
      ensure
         asymmetric: Result implies not (other < Current)
      end

   infix "<=" (other: like Current): BOOLEAN is
         -- Is `Current' less than or equal `other'?
      require
         other_exists: other /= Void
      do
         Result := not (other < Current)
      ensure
         definition: Result = ((Current < other) or is_equal(other))
      end

   infix ">" (other: like Current): BOOLEAN is
         -- Is `Current' strictly greater than `other'?
      require
         other_exists: other /= Void
      do
         Result := (other < Current)
      ensure
         definition: Result = (other < Current)
      end

   infix ">=" (other: like Current): BOOLEAN is
         -- Is `Current' greater than or equal than `other'?
      require
         other_exists: other /= Void
      do
         Result := not (Current < other)
      ensure
         definition: Result = (other <= Current)
      end

   in_range(lower, upper: like Current): BOOLEAN is
         -- Return true if `Current' is in range [`lower'..`upper']
      do
         Result := (Current >= lower) and then (Current <= upper)
      ensure
         Result = (Current >= lower and Current <= upper)
      end

   compare, three_way_comparison(other: like Current): INTEGER is
 	 -- If current object equal to `other', 0
 	 -- if smaller,  -1; if greater, 1.
      require
         other_exists: other /= Void
      do
         if Current < other then
            Result := -1
         elseif other < Current then
            Result := 1
         end
      ensure
         equal_zero      : (Result =  0) = is_equal(other)
         smaller_negative: (Result = -1) = (Current < other)
         greater_positive: (Result =  1) = (Current > other)
      end

   min(other: like Current): like Current is
         -- Minimum of `Current' and `other'.
      require
         other /= Void
      do
         if Current <= other then
            Result := Current
         else
            Result := other
         end
      ensure
         Result <= Current and then Result <= other
         compare(Result) = 0 or else other.compare(Result) = 0
      end

   max(other: like Current): like Current is
         -- Maximum of `Current' and `other'.
      require
         other /= Void
      do
         if Current >= other then
            Result := Current
         else
            Result := other
         end
      ensure
         Result >= Current and then Result >= other
         compare(Result) = 0 or else other.compare(Result) = 0
      end

end -- COMPARABLE

