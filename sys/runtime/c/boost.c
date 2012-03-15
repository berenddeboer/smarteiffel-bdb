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
  This file (SmartEiffel/sys/runtime/boost.c) is automatically included when
  `run_control.boost' is true (ie. only for mode -boost).
*/

void se_print_run_time_stack (void) {
  fprintf(SE_ERR,"Eiffel program crash at run time.\n");
  fprintf(SE_ERR,"No trace when using option \"-boost\"\n");
}

void se_signal_handler(int sig) {
  printf("Received signal %d.\n",sig);
  se_print_run_time_stack();
  exit(EXIT_FAILURE);
}
