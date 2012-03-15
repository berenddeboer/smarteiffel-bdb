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
  This file (SmartEiffel/sys/runtime/no_check.h) is automatically included
  when `run_control.no_check' is true (ie. all modes except mode -boost).
*/

void se_prinT0(FILE* file,T0** o);
void se_prinT1(FILE* file,EIF_INTEGER_8* o);
void se_prinT2(FILE* file,EIF_INTEGER* o);
void se_prinT3(FILE* file,EIF_CHARACTER* o);
void se_prinT4(FILE* file,EIF_REAL* o);
void se_prinT5(FILE* file,EIF_DOUBLE* o);
void se_prinT6(FILE* file,EIF_BOOLEAN* o);
void se_prinT7(FILE* file,EIF_STRING* o);
void se_prinT8(FILE* file,EIF_POINTER* o);
void se_prinT10(FILE* file,EIF_INTEGER_16* o);
void se_prinT11(FILE* file,EIF_INTEGER_64* o);

/*
   This type is used to store a position in some Eiffel source file.
   It must be compatible with the implementation of class POSITION.
*/
typedef unsigned int se_position;

#define se_position2line(position) (((position) & 1) \
  ? ((EIF_INTEGER)(((position) >> 1) & 0x7FFF)) \
  : ((EIF_INTEGER)(((position) >> 8) & 0x1FFF)))

#define se_position2column(position) (((position) & 1) \
  ? 0 \
  : ((EIF_INTEGER)(((position) >> 1) & 0x7F)))

#define se_position2path_id(position) (((position) & 1) \
  ? ((position) >> 17) \
  : ((position) >> 21))

/*
  To be able to print a stack frame in a human readable format :
*/
typedef struct _se_frame_descriptor se_frame_descriptor;
struct _se_frame_descriptor {
  char* name; /* Eiffel name of the routine. */
  int use_current; /* Flag is 1 when this routine use Current. */
  int local_count; /* Number of C variables to print. */
  char* local_format; /* Format/type information. */
  int assertion_flag; /* 1 when assertions can be checked. */
};

/*
  To keep the track of execution in order to be able to print a
  dump when things goes wrong :
*/
typedef struct _se_dump_stack se_dump_stack;
struct _se_dump_stack {
  se_frame_descriptor* fd;
  void** current; /* NULL when not used. */
  se_position p; /* The current position. */
  se_dump_stack* caller; /* Back to the caller. */
  se_dump_stack* exception_origin; /* The exception origin if we are handling an exception. That object was malloc'ed */
  void*** locals;
};
extern se_dump_stack* se_dst;
int se_stack_size(se_dump_stack* ds);
void se_print_run_time_stack(void);
int se_print_one_frame(se_dump_stack*ds);
int se_print_one_frame_in(FILE* file, se_dump_stack*ds);

extern int se_rspf;
extern int se_require_uppermost_flag;
extern int se_require_last_result;
int se_rci(se_dump_stack*caller,void*C);
void error0(char*m,char*vv);
void error1(char*m,se_position position);
void error2(T0* o,se_position position);
T0* vc(T0* o, se_position position);
T0* ci(int id, T0* o, se_position position);
void ac_req(int v, char* vv);
void ac_ens(int v, char* vv);
void ac_inv(int v, char* vv);
void ac_liv(int v, char* vv);
void ac_insp(int v);
int ac_lvc(int lc,int lv1,int lv2);
void ac_civ(int v,char*vv);
T0* se_evobt(T0* o,se_position position);
void se_signal_handler(int sig);
void se_gc_check_id(void*o,int id);

/* The two following instructions are used by the exceptions system to keep
   the stack trace when jumping back to the retry clause */
se_dump_stack* se_new_dump_stack(se_dump_stack* copy);
void se_delete_dump_stack(se_dump_stack* ds);

#ifdef SE_SCOOP
#define set_dump_stack_top(subsystem, ds) \
  do { \
    se_subsystem_t* rst_self=(subsystem); \
    (void)(rst_self->vft.get_dst_and_lock(rst_self)); \
    rst_self->vft.set_dst_and_unlock(rst_self,(ds)); \
  } while(0)
#else
#define set_dump_stack_top(ds) se_dst=(ds)
#endif
