-- This  file  is  free software,  which comes along with SmartEiffel.  This
-- software is distributed in the hope that it will be useful,  but  WITHOUT
-- ANY  WARRANTY;  without  even the  implied warranty of MERCHANTABILITY or
-- FITNESS FOR A PARTICULAR PURPOSE. You can modify it as you want, provided
-- this header is kept unaltered, and a notification of the changes is added.
-- You  are  allowed  to  redistribute it and sell it, alone or as a part of
-- another product.
--
-- Copyright(C) 2005: Daniel F. MOISSET
--
-- http://opensvn.csie.org/traccgi/smarteiffel12 - smarteiffel@except.com.ar
--
class HASHED_SET [E -> HASHABLE]

inherit
    SET [E]

create
    make, with_capacity, from_collection

end -- class HASHED_SET
