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
  This file (SmartEiffel/sys/runtime/basic_io.c) is automatically
  included when some external "SmartEiffel" basic_io_* feature is used.
*/

#if defined __USE_POSIX || defined __unix__ || defined _POSIX_C_SOURCE
/* macro read is used of basic_io_read_stdin */
#else
int basic_io_read_stdin(char *buffer, int size) {
  int c;
  c = getc(stdin);
  if (c==EOF)
    return 0;
  *buffer = (char)c;
  return 1;
}
#endif

