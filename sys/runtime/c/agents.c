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
  This file (SmartEiffel/sys/runtime/agents.c) is automatically included
  when agent support is used in the live code.
*/

#ifdef SE_GC_LIB
gc_agent *store_agent = NULL;
gc_agent *gc_free_agent = NULL;
int       store_left_agent = 0;
int       count_agent=0;
int       gc_info_nb_agent = 0;
fsoc     *store_chunk_agent = NULL;
fsoc H_agent =
{
  {
    FSOC_SIZE, FSO_STORE_CHUNK,
    (void (*)(mch *, void *)) gc_align_mark_agent,
    (void (*)(mch *)) gc_sweep_agent
  },
  NULL,
  (((FSOC_SIZE - sizeof (fsoc) + sizeof (double)) / sizeof (gc_agent)) - 1)
};
#endif

se_agent* new_agent(Tid id) {
#ifdef SE_GC_LIB
  int i;
  gc_agent *agent;
  fsoc *c;
  if (store_left_agent > 1)
    {
      store_left_agent--;
      agent = store_agent++;
    }
  else if (gc_free_agent != NULL)
    {
      agent = gc_free_agent;
      gc_free_agent = agent->header.next;
    }
  else if (store_left_agent == 1)
    {
      store_left_agent = 0;
      store_chunk_agent->header.state_type = FSO_USED_CHUNK;
      agent = store_agent++;
    }
  else
    {
      c = gc_fsoc_get1 ();
      if (gc_free_agent != NULL)
	{
	  agent = gc_free_agent;
	  gc_free_agent = agent->header.next;
	}
      else
	{
	  if (c == NULL)
	    c = gc_fsoc_get2 ();
	  store_chunk_agent = c;
	  *store_chunk_agent = H_agent;
	  store_agent = ((gc_agent *) (&(store_chunk_agent->first_object)));
	  store_left_agent = H_agent.count_minus_one;
	  agent = store_agent++;
	}
    }
  agent->header.flag = FSOH_UNMARKED;
  for(i=0;i<(sizeof(se_agent)/4);i++)
    ((int*) (agent))[i] = 0;

#else /* SE_GC_LIB */
  se_agent* agent = se_calloc(1,sizeof(se_agent));

#endif /* SE_GC_LIB */

  ((se_agent*) agent)->u0.id = id;

#ifdef SE_GC_LIB
  gc_info_nb_agent++;
#endif /* SE_GC_LIB */
  return (se_agent *) agent;
}


#ifdef SE_GC_LIB
void gc_sweep_agent (fsoc * c) {
  gc_agent *a1, *a2, *flt, flh;
  a1 = ((gc_agent *) (&(c->first_object)));
  if (c->header.state_type == FSO_STORE_CHUNK) {
    for (; a1 < store_agent; a1++) {
      if ((a1->header.flag) == FSOH_MARKED) {
	a1->header.flag = FSOH_UNMARKED;
      }
      else if ((a1->header.flag) == FSOH_UNMARKED) {
	a1->header.next = gc_free_agent;
	gc_free_agent = a1;
      }
    }
  }
  else {
    int dead = 1;
    flh.header.next = NULL;
    flt = &flh;
    a2 = a1 + c->count_minus_one;
    for (; a1 <= a2; a2--) {
      if ((a2->header.flag) == FSOH_MARKED) {
	a2->header.flag = FSOH_UNMARKED;
	dead = 0;
      }
      else if ((a2->header.flag) == FSOH_UNMARKED) {
	flt->header.next = a2;
	flt = a2;
      }
    }
    if (dead) {
      c->next = fsocfl;
      fsocfl = c;
      c->header.state_type = FSO_FREE_CHUNK;
    }
    else if (flh.header.next != NULL) {
      flt->header.next = gc_free_agent;
      gc_free_agent = flh.header.next;
    }
  }
}

static void agent_recur_gc_mark(void *p) {
  int i;

  for(i=0;i<(sizeof(se_agent)/4+1);i++)
    gc_mark(((char*) p) + i);
}

void gc_mark_agent (/*agent*/T0* o) {
  if (((gc_agent *) o)->header.flag == FSOH_UNMARKED)
    {

      ((gc_agent *) o)->header.flag = FSOH_MARKED;
      agent_recur_gc_mark( o);
    }
}

void gc_align_mark_agent (fsoc * c, gc_agent * p) {
  gc_agent *b = ((gc_agent *) (&(c->first_object)));
  if ((c->header.state_type == FSO_STORE_CHUNK)
      && (((char *) p) >= ((char *) store_agent)))
    return;

  if (((char *) p) > ((char *) (b + (c->count_minus_one))))
    return;

  if (((char *) p) < ((char *) b))
    return;
  if (((((char *) p) - ((char *) b)) % sizeof (*p)) == 0)
    {
      if (p->header.flag == FSOH_UNMARKED)
	{
	  se_agent *ta = (&(p->object));
	  ((gc_agent *) ta)->header.flag = FSOH_MARKED;
	  agent_recur_gc_mark( ta);
	}
    }
}

#endif /* SE_GC_LIB */
