/*
-- This file is  free  software, which  comes  along  with  SmartEiffel. This
-- software  is  distributed  in the hope that it will be useful, but WITHOUT
-- ANY  WARRANTY;  without  even  the  implied warranty of MERCHANTABILITY or
-- FITNESS  FOR A PARTICULAR PURPOSE. You can modify it as you want, provided
-- this header is kept unaltered, and a notification of the changes is added.
-- You  are  allowed  to  redistribute  it and sell it, alone or as a part of
-- another product.
--       Copyright (C) 1994-2002 LORIA - INRIA - U.H.P. Nancy 1 - FRANCE
--          Dominique COLNET and Suzanne COLLIN - SmartEiffel@loria.fr
--                       http://SmartEiffel.loria.fr
--
*/
/*
  This file (SmartEiffel/sys/runtime/basic_microsecond.h) is automatically
  included when some external "SmartEiffel" basic_microsecond_* feature is
  used (i.e. in live code).
*/

#ifndef WIN32
#  include <sys/time.h>
#endif

extern EIF_INTEGER basic_microsecond_microsecond;
extern EIF_INTEGER_64 basic_microsecond_time;
#define basic_microsecond_update (_basic_microsecond_update())
void _basic_microsecond_update(void);
