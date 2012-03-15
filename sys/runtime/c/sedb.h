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
  This file (SmartEiffel/sys/runtime/sedb.h) is automatically included when
  `run_control.no_check' is true (ie. all modes except -boost).
  This file comes after no_check.[hc] to implements the -sedb flag.
*/
#define SE_SEDB 1

/* 
   List of possible values for the `sedb_status' variable:

   SEDB_RUNNING_STATUS: we are in running mode.
   SEDB_STEP_BY_STEP: we are in step-by-step mode.
   SEDB_START_STATUS: to start with on-line-help.
   SEDB_WAITING_KBD: waiting for keyboard input.
   SEDB_EXIT_MODE: to be sure to exit (atexit may be called).
   SEDB_TRACE_FILE: when profiling on the "trace.se" file.
   SEDB_FINISH_CMD: waiting the end of the routine ('f' command).
   SEDB_NEXT_CMD: single step at the same level ('n' command).

 */
enum sedb_status_values {
  SEDB_RUNNING_STATUS= 1,
  SEDB_RUNNING_IGNORE_BREAKPOINTS,
  SEDB_STEP_BY_STEP,
  SEDB_START_STATUS,
  SEDB_WAITING_KBD,
  SEDB_EXIT_MODE,
  SEDB_TRACE_FILE,
  SEDB_FINISH_CMD,
  SEDB_NEXT_CMD
};

extern enum sedb_status_values sedb_status;

void sedb(se_dump_stack*ds,se_position position);
void sedb_breakpoint(se_dump_stack*ds,se_position position);
void sedb_break(se_dump_stack*ds,se_position position);
void sedb_signal_handler(int sig);
