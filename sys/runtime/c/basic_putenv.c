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
  This file (SmartEiffel/sys/runtime/basic_putenv.c) is automatically
  included when the basic_putenv feature is used (ie. in live code).
*/

void basic_putenv(EIF_POINTER variable, EIF_POINTER value) {
  size_t variable_len = strlen((char*)variable);
  size_t value_len = strlen((char*)value);
  char* v;
  v = se_malloc(variable_len + value_len + 2);
  strncpy(v,((char*)variable),variable_len);
  v[variable_len] = '=';
  strncpy(v + variable_len + 1,((char*)value),value_len);
  v[variable_len + 1 + value_len] = '\0';
  putenv(v);
}
