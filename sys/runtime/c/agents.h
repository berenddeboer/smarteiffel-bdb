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
  This file (SmartEiffel/sys/runtime/agents.h) is automatically included
  when agent support is used in the live code.
*/

#define SE_AGENTS 1
#define EIF_AGENT se_agent*

se_agent* new_agent(Tid id);

#ifdef SE_GC_LIB

  typedef struct B_agent gc_agent;

  struct B_agent {
    se_agent object;
    union {
      void *flag;
      gc_agent *next;
    } header;
  };

  extern gc_agent *store_agent;
  extern gc_agent *gc_free_agent;
  extern int       store_left_agent;
  extern fsoc     *store_chunk_agent;
  extern fsoc      H_agent;
  extern int       gc_info_nb_agent;

  void gc_mark_agent (/*agent*/T0* o);
  void gc_align_mark_agent(fsoc *c, gc_agent* a);
  void gc_sweep_agent(fsoc *c);

#endif
