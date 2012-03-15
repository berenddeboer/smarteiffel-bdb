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
  This file (SmartEiffel/sys/runtime/basic_time.c) is automatically
  included when some external "SmartEiffel" basic_time_* feature is
  used (i.e. in live code).
*/

EIF_DOUBLE basic_time_difftime(time_t t2, time_t t1) {
  return difftime((time_t)t2, (time_t)t1);
}

EIF_INTEGER basic_time_getyear(time_t t, EIF_INTEGER m) {
  if (m == 1) {
    return (gmtime((time_t *)(&t)))->tm_year + 1900;
  }
  else {
    return (localtime((time_t *)(&t)))->tm_year + 1900;
  }
}

EIF_INTEGER basic_time_getmonth(time_t t, EIF_INTEGER m) {
  if (m == 1) {
    return (gmtime((time_t *)(&t)))->tm_mon + 1;
  }
  else {
    return (localtime((time_t *)(&t)))->tm_mon + 1;
  }
}

EIF_INTEGER basic_time_getday(time_t t, EIF_INTEGER m) {
  if (m == 1) {
    return (gmtime((time_t *)(&t)))->tm_mday;
  }
  else {
    return (localtime((time_t *)(&t)))->tm_mday;
  }
}

EIF_INTEGER basic_time_gethour(time_t t, EIF_INTEGER m) {
  if (m == 1) {
    return (gmtime((time_t *)(&t)))->tm_hour;
  }
  else {
    return (localtime((time_t *)(&t)))->tm_hour;
  }
}

EIF_INTEGER basic_time_getminute(time_t t, EIF_INTEGER m) {
  if (m == 1) {
    return (gmtime((time_t *)(&t)))->tm_min;
  }
  else {
    return (localtime((time_t *)(&t)))->tm_min;
  }
}

EIF_INTEGER basic_time_getsecond(time_t t, EIF_INTEGER m) {
  if (m == 1) {
    return (gmtime((time_t *)(&t)))->tm_sec;
  }
  else {
    return (localtime((time_t *)(&t)))->tm_sec;
  }
}

EIF_INTEGER basic_time_getwday(time_t t, EIF_INTEGER m) {
  if (m == 1) {
    return (gmtime((time_t *)(&t)))->tm_wday;
  }
  else {
    return (localtime((time_t *)(&t)))->tm_wday;
  }
}

EIF_INTEGER basic_time_getyday(time_t t, EIF_INTEGER m) {
  if (m == 1) {
    return (gmtime((time_t *)(&t)))->tm_yday;
  }
  else {
    return (localtime((time_t *)(&t)))->tm_yday;
  }
}

EIF_BOOLEAN basic_time_is_summer_time_used(time_t t) {
  return (EIF_BOOLEAN)(((localtime((time_t *)(&t)))->tm_isdst) != 0);
}

EIF_INTEGER_64 basic_time_mktime(EIF_INTEGER year,
			     EIF_INTEGER mon,
			     EIF_INTEGER mday,
			     EIF_INTEGER hour,
			     EIF_INTEGER min,
			     EIF_INTEGER sec) {
  struct tm tm_buf;

  tm_buf.tm_year  = (year - 1900);
  tm_buf.tm_mon   = (mon - 1);
  tm_buf.tm_mday  = mday;
  tm_buf.tm_hour  = hour;
  tm_buf.tm_min   = min;
  tm_buf.tm_sec   = sec;
  tm_buf.tm_isdst = -1;

  return (EIF_INTEGER_64)mktime(&tm_buf);
}

void basic_time_add_second(EIF_INTEGER_64 *t, EIF_INTEGER s) {
  *t += s;
}
