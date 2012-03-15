
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
  This file (SmartEiffel/sys/runtime/basic_time.h) is automatically
  included when some external "SmartEiffel" basic_time_* feature is
  used (i.e. in live code).
*/
#include <time.h>

#define basic_time_time ((EIF_INTEGER_64)time(NULL))
EIF_DOUBLE basic_time_difftime(time_t t2, time_t t1);
EIF_INTEGER basic_time_getyear(time_t t, EIF_INTEGER m);
EIF_INTEGER basic_time_getmonth(time_t t, EIF_INTEGER m);
EIF_INTEGER basic_time_getday(time_t t, EIF_INTEGER m);
EIF_INTEGER basic_time_gethour(time_t t, EIF_INTEGER m);
EIF_INTEGER basic_time_getminute(time_t t, EIF_INTEGER m);
EIF_INTEGER basic_time_getsecond(time_t t, EIF_INTEGER m);
EIF_INTEGER basic_time_getyday(time_t t, EIF_INTEGER m);
EIF_INTEGER basic_time_getwday(time_t t, EIF_INTEGER m);
EIF_BOOLEAN basic_time_is_summer_time_used(time_t t);
EIF_INTEGER_64 basic_time_mktime(EIF_INTEGER year, EIF_INTEGER mon,
			     EIF_INTEGER mday, EIF_INTEGER hour,
			     EIF_INTEGER min,  EIF_INTEGER sec);
void basic_time_add_second(EIF_INTEGER_64 *t, EIF_INTEGER s);
