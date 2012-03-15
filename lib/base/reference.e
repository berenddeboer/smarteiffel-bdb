-- See the Copyright notice at the end of this file.
--
class REFERENCE[E]
	--
	-- This class is useful to share a common volatile expanded value between different objects or as the 
	-- result of a once function.
	-- So in most cases the E type is expanded and the reference to the REFERENCE[E] container object is 
	-- shared.
	--

-- In SE 2.x, this class has two creation routines, default_create and set_item.
-- Given the lack of support for default_create, I preferred leave this having
-- no creation procedure (similar effect to having just default_create)
-- I could also had used clear and set_item as creation routines, but then
-- code like "create ref.clear" would not compile in SE2

feature {ANY}
	item: E

	set_item (i: like item) is
		do
			item := i
		ensure
			item = i
		end

	clear is
			-- Reset `item' with the default value.
		local
			default_item: like item
		do
			item := default_item
		end

end -- class REFERENCE
--
-- ------------------------------------------------------------------------------------------------------------------------------
-- Copyright notice below. Please read.
--
-- This file is free software, which comes along with SmartEiffel. This software is distributed in the hope that it will be
-- useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
-- You can modify it as you want, provided this footer is kept unaltered, and a notification of the changes is added.
-- You are allowed to redistribute it and sell it, alone or as a part of another product.
--
-- Copyright(C) 1994-2002: INRIA - LORIA (INRIA Lorraine) - ESIAL U.H.P.       - University of Nancy 1 - FRANCE
-- Copyright(C) 2003-2004: INRIA - LORIA (INRIA Lorraine) - I.U.T. Charlemagne - University of Nancy 2 - FRANCE
--
-- Authors: Dominique COLNET, Philippe RIBET, Cyril ADRIAN, Vincent CROIZIER, Frederic MERIZEN
--
-- http://SmartEiffel.loria.fr - SmartEiffel@loria.fr
-- ------------------------------------------------------------------------------------------------------------------------------
