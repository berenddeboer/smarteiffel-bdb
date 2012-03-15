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
  This file (SmartEiffel/sys/runtime/basic_microsecond.c) is automatically
  included when some external "SmartEiffel" basic_microsecond_* feature is
  used (i.e. in live code).
*/

EIF_INTEGER basic_microsecond_microsecond = 0;
EIF_INTEGER_64 basic_microsecond_time = 0;

void _basic_microsecond_update(void) {
#ifndef WIN32
  struct timeval t;

  gettimeofday (&t, NULL);
  basic_microsecond_time = t.tv_sec;
  basic_microsecond_microsecond = t.tv_usec;
#else
  static DWORD ref_uptime = -1; /* max value as ref_uptime is unsigned */
  static time_t ref_time;
  DWORD uptime;

  /*  uptime = timeGetTime();*/
  uptime = GetTickCount();

  if (uptime < ref_uptime) {
    /* !!! this test manages first call AND 50th day ;-)  */
    ref_uptime = uptime;
    time(&ref_time);
  }

  basic_microsecond_time = ref_time + (uptime - ref_uptime)/1000;
  basic_microsecond_microsecond = ((uptime - ref_uptime) % 1000) * 1000;
#endif
}
