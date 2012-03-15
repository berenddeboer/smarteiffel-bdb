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
   This file (SmartEiffel/sys/runtime/gc_lib.h) is automatically included
   when the Garbage Collector is used (default, unless option -no_gc has
   been selected).
*/

#define SE_GC_LIB 1

#define SE_GC_LOW_MEMORY_STRATEGY 0
#define SE_GC_HIGH_MEMORY_STRATEGY 1
#define SE_GC_DEFAULT_MEMORY_STRATEGY 2
extern int se_gc_strategy;


#define RSOH_UNMARKED 15253
#define RSOH_FREE 1
#define RSOH_MARKED 2


#define FSOH_UNMARKED ((void *) 1)
#define FSOH_MARKED   ((void *) 2)

/* To codify the state and the type of some Memory Chunk, we are
   using the following definitions :
*/
#define FSO_FREE_CHUNK  (-2)
#define RSO_FREE_CHUNK  (-1)
#define RSO_USED_CHUNK  ( 0)
#define FSO_STORE_CHUNK ( 1)
#define FSO_USED_CHUNK  ( 2)
#define FREE_CHUNK(x) ((x)<0)

/* Minimum size for a store area in a ReSizable Objects Chunk :
 */
#define RSOC_MIN_STORE 512

/* The default channel used to print -gc_info flag information :
*/
#define SE_GCINFO SE_ERR

extern int collector_counter; /* MEMORY.collector_counter */

typedef struct s_mch mch; /* Memory Chunk Header. */
typedef struct s_fsoc fsoc; /* Fixed Size Objects Chunk. */
typedef union u_rsoh rsoh; /* ReSizable Object Header. */
typedef struct s_fll_rsoh fll_rsoh;
typedef struct s_rsoc rsoc; /* ReSizable Objects Chunk. */
typedef struct s_na_env na_env; /* Native Array ENVironment. */


struct s_mch{
  unsigned int size; /* In number of bytes (actual argument of malloc).*/
  int state_type; /* One value in : RSO_USED_CHUNK,
                     FREE_CHUNK, FSO_STORE_CHUNK, FSO_USED_CHUNK */
  void(*amfp)(mch*,void*); /* Align Mark Function Pointer. */
  void(*swfp)(mch*); /* SWeep Function Pointer. */
};

struct s_fsoc{
  mch header; /* Common header for fsoc and rsoc. */
  fsoc* next; /* The next one when in free list (fsocfl). */
  int count_minus_one;
  double first_object;
};

typedef struct _rso_header rso_header;

struct _rso_header{
    unsigned int size;
    int magic_flag;     /* RSOH_MARKED when used,
			   RSOH_FREE when free,
			   else RSOH_UNMARKED */
};

union u_rsoh{
  rso_header header;
  double padding;
  };

struct s_fll_rsoh {
  rso_header rsoh_field;
  fll_rsoh* nextflol;
};

struct s_rsoc{
  mch header; /* Common header for fsoc and rsoc. */
  unsigned int isize; /* Initial size (at malloc time) to detect split chunks. */
  rsoc* next; /* The next one when in free list (rsocfl). */
  fll_rsoh*free_list_of_large; /* Intra. free list. */
  na_env*nae;
  rsoh first_header;
};

struct s_na_env{
  unsigned int store_left;
  rsoh* store;
  rsoc*store_chunk;
  rsoc*chunk_list;
  void (*gc_mark)(T0*);
};

extern void**stack_bottom;
extern mch**gcmt;
extern int gcmt_max;
extern int gcmt_used;
extern int gc_is_off;
extern fsoc* fsocfl;
extern unsigned int fsoc_count;
extern unsigned int rsoc_count;
extern void*gcmt_tail_addr;

void gc_sweep(void);
void gc_mark(void* p);
mch* gc_find_chunk(void* p);
int gc_stack_size(void);
int garbage_delayed(void);
void gc_update_ceils(void);
char*new_na(na_env*nae,unsigned int size);
unsigned int fsocfl_count(void);
unsigned int rsocfl_count(void);
void gc_dispose_before_exit(void);
void mark_stack_and_registers (void);
fsoc* gc_fsoc_get1(void);
fsoc* gc_fsoc_get2(void);

int gc_memory_used(void);
