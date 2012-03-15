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
   This file (SmartEiffel/sys/runtime/gc_lib.c) is automatically included
   when the Garbage Collector is used (default, unless option -no_gc has been
   selected).
*/
/*
   The `mark_stack_and_registers' C function is called by the Garbage
   Collector (GC) of SmartEiffel. It has to be customized for some systems,
   but also for some C compilers. This file provides some definitions in the
   end and has to be completed for systems which need specific work.

   On some architectures, addresses increase as the stack grows; or,
   conversely, addresses decrease as the stack grows. A C compiler may be
   clever enough to hide some root object inside registers. Unfortunately all
   registers are not always accessible via the C `setjmp' function!

   Thus, in order to be able to use the GC on your architecture/C-compiler,
   you have to provide the correct `mark_stack_and_registers' function.

   What is the `mark_stack_and_registers' function supposed to do?  The
   `mark_stack_and_registers' function is supposed to notify the GC with all
   the possible roots one can find in the C stack and registers by calling the
   `gc_mark' function. A root is an object which must not be collected.  The
   SmartEiffel GC already knows about some root objects like once function
   results or manifest strings. The `mark_stack_and_registers' function has to
   notify the other possible roots. Obviously, one can find in the C stack any
   kind of adresses, but the `gc_mark' function is clever enough to determine
   if the passed pointer is an Eiffel object or not.  When the passed pointer
   reaches some Eiffel object, this object as well as its descendant(s) are
   automatically marked as un-collectable.

   In order to provide the most appropriate `mark_stack_and_registers'
   function, the very first question is to know about the way the C stack is
   managed (addresses of the stack may increase or decrease as the C stack
   grows). The DEFAULT BEHAVIOUR FOR UNKNOWN SYSTEMS is to consider ADDRESSES
   DECREASE AS THE STACK GROWS, as it's the most common case.  The global C
   variable `stack_bottom' is set with some pointer which is supposed to be
   the bottom of the stack (this variable is automatically initialized in the
   C main function).  Note: using the current stack pointer inside
   `mark_stack_and_registers', it is quite obvious to determine if addresses
   increase or not as the C stack grows.  Note2: on some systems, the stack is
   not in contiguous addresses. In such case, `mark_stack_and_registers' has
   to go through all the stack fragments.

   Some roots may be stored only in registers and not in the C stack.  In
   order to reach the registers as well, the first attempt is to use setjmp,
   in the hope that setjmp will save registers in the stack!  Note: this
   technique do not work on processors using windows registers (such as sparc
   processors).

*/


int se_gc_strategy = SE_GC_DEFAULT_MEMORY_STRATEGY;

int collector_counter = 0;

static void gcna_align_mark(rsoc*c,void*o);
static rsoc*rsocfl=NULL; /* ReSizable Object Chunk Free List. */

void**stack_bottom=NULL;
mch**gcmt=NULL; /* Garbage Collector Main Table. */
int gcmt_max=2048;
int gcmt_used=0;
fsoc*fsocfl=NULL; /* Fixed Size Object Chunk Free List. */
int gc_is_off=1;
unsigned int fsoc_count=0;
unsigned int rsoc_count=0;
void*gcmt_tail_addr=NULL;

static int chunk_rounded(int size) {
  int rounded_size = size;
  int diff = rounded_size%RSOC_SIZE;

  if (diff != 0) rounded_size += (RSOC_SIZE-diff);
  return rounded_size;
}

static void free_and_remove_from_gcmt(mch* c) {
  /* Remove and free the chunk `c' from the
   * gcmt (Garbage Collector Main Table).
   */
  mch**p=(gcmt+gcmt_used-1);
  mch*save=*p;
  mch*save2;
  p--;
  while(save != c) {
    save2 = save;
    save = *p;
    *p = save2;
    p--;
  }
  free(c);
  gcmt_used--;
}

static void may_free_rsocfl(void) {
  /* May free all chunks of `rsocfl' (ReSizable Object Chunk Free List)
     in some circumstances.
  */
  rsoc* next, *current;
  unsigned int count = rsocfl_count();
  if ((count > 50) && (count > (rsoc_count >> 1))) { 
    current=rsocfl;
    rsocfl=NULL;
    while (current != NULL) {
      next=current->next;
      if (current->isize == current->header.size) {
	free_and_remove_from_gcmt(((mch*)current)); 
	rsoc_count--;
      }
      else {
	current->next=rsocfl;
	rsocfl=current;
      }
      current = next;
    }
  }
}

int gc_memory_used(void) {
  int i;
  int result = 0;
  mch* mch;
  for (i = gcmt_used; i --> 0; ) {
    mch = gcmt[i];
    switch(mch->state_type) {
    case RSO_USED_CHUNK:
    case FSO_USED_CHUNK:
    case FSO_STORE_CHUNK:
      result += mch->size;
      break;
    default:
      break;
    }
  }
  return result;
}

void gc_sweep(void) {
  mch** p2 = gcmt;
  mch** p1 = gcmt+1;
  mch**eogcmt=gcmt+gcmt_used;
  if (FREE_CHUNK((*p2)->state_type)) {
    if (RSO_FREE_CHUNK == ((*p2)->state_type)) {
      ((rsoc*)(*p2))->next=NULL;
      rsocfl=((rsoc*)(*p2));
    }
    else {
      rsocfl=NULL;
    }
  }
  else {
    ((*gcmt)->swfp)(*p2);
    if (RSO_FREE_CHUNK==((*p2)->state_type)) {
      ((rsoc*)(*p2))->next=NULL;
      rsocfl=((rsoc*)(*p2));
    }
    else {
      rsocfl=NULL;
    }
  }
  while (p1 < eogcmt) {
    if (FREE_CHUNK((*p1)->state_type)) {
      if (RSO_FREE_CHUNK == ((*p1)->state_type)) {
	if (RSO_FREE_CHUNK == ((*p2)->state_type)) {
	  if (((char*)(*p2))+(*p2)->size == ((char*)(*p1))) {
	    ((*p2)->size)+=((*p1)->size);
	    p1++;
	  }
	  else {
	    ((rsoc*)(*p1))->next=rsocfl;
	    rsocfl=((rsoc*)(*p1));
	    *(p2+1)=*p1; p2++; p1++;
	  }
	}
	else {
	  ((rsoc*)(*p1))->next=rsocfl;
	  rsocfl=((rsoc*)(*p1));
	  *(p2+1)=*p1; p2++; p1++;
	}
      }
      else {
	*(p2+1)=*p1; p2++; p1++;
      }
    }
    else {
      ((*p1)->swfp)(*p1);
      if (RSO_FREE_CHUNK == ((*p1)->state_type)) {
	if (RSO_FREE_CHUNK == ((*p2)->state_type)) {
	  if (((char*)(*p2))+(*p2)->size == ((char*)(*p1))) {
	    ((*p2)->size)+=((*p1)->size);
	    p1++;
	  }
	  else {
	    ((rsoc*)(*p1))->next=rsocfl;
	    rsocfl=((rsoc*)(*p1));
	    *(p2+1)=*p1; p2++; p1++;
	  }
	}
	else {
	  ((rsoc*)(*p1))->next=rsocfl;
	  rsocfl=((rsoc*)(*p1));
	  *(p2+1)=*p1; p2++; p1++;
	}
      }
      else {
	*(p2+1)=*p1; p2++; p1++;
      }
    }
  }
  gcmt_used=(p2-gcmt)+1;
  may_free_rsocfl();
}

/* return the mch containing p or NULL if p is not 
 * a valid address or was externally allocated 
 */
mch * gc_find_chunk(void * p){
  if ((p>((void*)*gcmt))&&(p<=gcmt_tail_addr)) {
    int i1=0;
    int i2=gcmt_used-1;
    int m=i2>>1;
    mch*c;
    for (;i2>i1;m=((i1+i2)>>1)) {
      if (p<=((void*)gcmt[m+1])) {
	i2=m;
      }
      else {
	i1=m+1;
      }
    }
    c=gcmt[i2];
    if((char*)p<(char*)c+c->size)   /* check for upper bound */
      if (!(FREE_CHUNK(c->state_type)))
	return c;
  }
  return NULL;
}

void gc_mark(void*p) {
  mch * c = gc_find_chunk(p);
  if(NULL != c) 
    (c->amfp)(c,p);
}

int gc_stack_size(void) {
  void*stack_top[2]={NULL,NULL};
  if (stack_top > stack_bottom) {
    return ((void**)stack_top)-((void**)stack_bottom);
  }
  else {
    return ((void**)stack_bottom)-((void**)stack_top);
  }
}

/*
  To delay Garbage Collection when the stack is too large.
  To allow fast increase of ceils.
*/
#define FSOC_LIMIT (10240/((FSOC_SIZE)>>10))
#define RSOC_LIMIT (10240/((RSOC_SIZE)>>10))

/*
  When stack is too large, collection may be delayed.
*/
#define GCLARGESTACK 50000

int garbage_delayed(void) {
  /*
    To delay the first GC call.
  */
  if (gc_stack_size() > GCLARGESTACK) {
    if (fsoc_count_ceil <= fsoc_count) {
      if (rsoc_count_ceil <= rsoc_count) {
	if ((fsoc_count<FSOC_LIMIT)&&(rsoc_count<RSOC_LIMIT)) {
	  fsoc_count_ceil++;
	  rsoc_count_ceil++;
	  return 1;
	}
	else return 0;
      }
      else {
	if (fsoc_count<FSOC_LIMIT) {
	  fsoc_count_ceil++;
	  return 1;
	}
	else return 0;
      }
    }
    else {
      if (rsoc_count_ceil <= rsoc_count) {
	if (rsoc_count<RSOC_LIMIT) {
	  rsoc_count_ceil++;
	  return 1;
	}
	else return 0;
      }
      else return 0;
    }
  }
  else {
    return 0;
  }
}

void gc_update_ceils(void) {
  /* This function is automatically called after each collection
     cycle.
  */
  if (se_gc_strategy == SE_GC_LOW_MEMORY_STRATEGY) {
    fsoc_count_ceil = fsoc_count;
    rsoc_count_ceil = rsoc_count;
    /* Todo: we should also consider to free unused chunks here. */
    return;
  }
  if (se_gc_strategy == SE_GC_HIGH_MEMORY_STRATEGY) {
    fsoc_count_ceil = (256 + fsoc_count) << 2;
    rsoc_count_ceil = (256 + rsoc_count) << 2;
    return;
  }
  /* The SE_GC_DEFAULT_MEMORY_STRATEGY. */
  /* Compute fsoc_count_ceil: */
  if (fsocfl == NULL) {
    if (fsoc_count >= fsoc_count_ceil) {
      if (fsoc_count_ceil < FSOC_LIMIT) {
	fsoc_count_ceil <<= 1;
      }
      else {
	unsigned int c = fsoc_count + (fsoc_count/3);
	if (fsoc_count_ceil < c)
	  fsoc_count_ceil = c;
      }
    }
  }
  else {
    if (fsoc_count_ceil < fsoc_count) {
      fsoc_count_ceil = fsoc_count;
    }
  }
  /* Compute rsoc_count_ceil: */
  if (rsocfl == NULL) {
    if (rsoc_count >= rsoc_count_ceil) {
      if (rsoc_count_ceil < RSOC_LIMIT) {
	rsoc_count_ceil <<= 1;
      }
      else {
	unsigned int c = rsoc_count + (rsoc_count / 3);
	if (rsoc_count_ceil < c) {
	  rsoc_count_ceil = c;
	}
      }
    }
  }
  else {
    if (rsoc_count_ceil < rsoc_count) {
      rsoc_count_ceil = rsoc_count;
    }
  }
}

static void gc_add_into_gcmt(mch*c) {
  /* Update the `gcmt' (Garbage Collector Main Table) by adding the
     new `mch' (Memory Chunk Header).
  */
  mch** p;
  if (gcmt_used == gcmt_max) {
    gcmt_max <<= 1;
    gcmt = ((mch**)(se_realloc(gcmt,(gcmt_max+1)*sizeof(void*))));
  }
  for (p=gcmt+(gcmt_used++ -1) ; (p>=gcmt)&&(*p>c) ; p--) {
    *(p+1) = *p;
  }
  *(p+1) = c;
}

static char*rso_from_store(na_env*nae,unsigned int size) {
  rsoh*r=(nae->store);
  nae->store_left-=size;
  if ((nae->store_left) > sizeof(rsoh)) {
    r->header.size=size;
    nae->store=((rsoh*)(((char*)(nae->store))+size));
  }
  else {
    r->header.size=size+nae->store_left;
    nae->store_left=0;
  }
  (r->header.magic_flag)=RSOH_UNMARKED;
  ((void)memset((r+1),0,r->header.size-sizeof(rsoh)));
  return (char*)(r+1);
}

static void rsoc_sweep(rsoc*c) {
  na_env*nae=c->nae;
  rsoh*gp=(rsoh*)&(c->first_header);
  rsoh*pp;
  rsoh*eoc=((rsoh*)(((char*)c)+c->header.size));
  c->free_list_of_large=NULL;
  if (c->header.size > RSOC_SIZE) {
    if (gp->header.magic_flag == RSOH_MARKED) {
      gp->header.magic_flag=RSOH_UNMARKED;
      c->next=nae->chunk_list;
      nae->chunk_list=c;
    }
    else {
      c->header.state_type=RSO_FREE_CHUNK;
    }
    return;
  }
  while (gp<eoc) {
    while (gp->header.magic_flag == RSOH_MARKED) {
      gp->header.magic_flag=RSOH_UNMARKED;
      gp=((rsoh*)(((char*)gp)+gp->header.size));
      if(gp>=eoc) {
	c->next=nae->chunk_list;
	nae->chunk_list=c;
	return;
      }
    }
    gp->header.magic_flag=RSOH_FREE;
    pp=(rsoh*)(((char*)gp)+gp->header.size);
    while ((pp<eoc)&&(pp->header.magic_flag != RSOH_MARKED)) {
      pp->header.magic_flag=RSOH_FREE;
      gp->header.size+=pp->header.size;
      pp=((rsoh*)(((char*)pp)+pp->header.size));
    }
    if (gp->header.size >= RSOC_MIN_STORE) {
      if (nae->store_left==0) {
	nae->store_left=gp->header.size;
	nae->store=gp;
	nae->store_chunk=c;
      }
      else if (nae->store->header.size < gp->header.size) {
	((fll_rsoh*)nae->store)->nextflol=nae->store_chunk->free_list_of_large;
	nae->store_chunk->free_list_of_large=((fll_rsoh*)nae->store);
	nae->store_left=gp->header.size;
	nae->store=gp;
	nae->store_chunk=c;
      }
      else {
	((fll_rsoh*)gp)->nextflol=c->free_list_of_large;
	c->free_list_of_large=((fll_rsoh*)gp);
      }
    }
    gp=pp;
  }
  if (((rsoh*)(&c->first_header))->header.size >=
      (c->header.size-sizeof(rsoc)+sizeof(rsoh))){
    c->header.state_type=RSO_FREE_CHUNK;
    nae->store_chunk=NULL;
    nae->store_left=0;
  }
  else{
    c->next=nae->chunk_list;
    nae->chunk_list=c;
  }
}

static const rsoc MRSOC = {
    {
	RSOC_SIZE,
	RSO_USED_CHUNK,
	((void(*)(mch*,void*))gcna_align_mark),
	((void(*)(mch*))rsoc_sweep)
    },
    0,
    NULL,
    NULL,
    NULL,
    {
      {
	0,
	RSOH_MARKED
      }
    }
};

static void rsoc_malloc(na_env*nae) {
  rsoc* r = ((rsoc*)(se_malloc(RSOC_SIZE)));
  rsoc_count++;
  *r=MRSOC;
  r->nae=nae;
  r->isize=RSOC_SIZE;
  nae->store=(&(r->first_header));
  nae->store_left=RSOC_SIZE-sizeof(rsoc)+sizeof(rsoh);
  nae->store_chunk=r;
  r->next=nae->chunk_list;
  nae->chunk_list=r;
  gc_add_into_gcmt((mch*)r);
}

static rsoc* rsocfl_best_fit(unsigned int size) {
  unsigned int best_size = 0;
  rsoc *pc,*best_pc,*best_c, *c;
  if (rsocfl==NULL)
    return NULL;
  pc=NULL;
  best_pc=NULL;
  best_c=NULL;
  c=rsocfl;
  while ((NULL!=c)&&(NULL==best_c)){
    if (c->header.size>=size){
      best_c=c;
      best_pc=pc;
      best_size=c->header.size;
    }
    pc=c;
    c=c->next;
  }
  if (NULL==c){
    if (best_pc != NULL)
      best_pc->next=best_c->next;
    else if (best_c==rsocfl)
      rsocfl=best_c->next;
    return best_c;
  }
  do {
    if ((c->header.size >= size) && (c->header.size < best_size)) {
      best_c = c;
      best_pc = pc;
      best_size = c->header.size;
    }
    pc=c;
    c=c->next;
  }
  while(c!=NULL);
  if (NULL==best_pc) {
    rsocfl = best_c->next;
  }
  else {
    best_pc->next=best_c->next;
  }
  return best_c;
}

static int get_store_in(rsoc*c,unsigned int size) {
  na_env*nae=c->nae;
  fll_rsoh*pf=NULL;
  fll_rsoh*f=c->free_list_of_large;
  while (f != NULL) {
    if (f->rsoh_field.size >= size) {
      nae->store_left=f->rsoh_field.size;
      nae->store=(rsoh*)f;
      nae->store_chunk=c;
      if (pf == NULL) {
	c->free_list_of_large=f->nextflol;
      }
      else {
	pf->nextflol=f->nextflol;
      }
      return 1;
    }
    pf = f;
    f = f->nextflol;
  }
  return 0;
}

char*new_na_from_chunk_list(na_env*nae,unsigned int size) {
  rsoc*c=nae->chunk_list;
  unsigned int csize;
  while (c != NULL) {
    if (get_store_in(c,size)) {
      return rso_from_store(nae,size);
    }
    c = c->next;
  }
  csize=size+(sizeof(rsoc)-sizeof(rsoh));
  c=rsocfl_best_fit(csize);
  if (c != NULL){
    if ((c->header.size > RSOC_SIZE)
	&&
	(c->header.size-csize > RSOC_MIN_STORE*4)) {
      int csize_left=c->header.size-csize;
      if ((csize_left%sizeof(double))!=0) {
	csize_left-=(csize_left%sizeof(double));
	csize=c->header.size-csize_left;
      }
      c->header.size=csize_left;
      c->next=rsocfl;
      rsocfl=c;
      c=(rsoc*)(((char*)c)+csize_left);
      gc_add_into_gcmt((mch*)c);
      c->header.amfp=(void(*)(mch*,void*))gcna_align_mark;
      c->header.swfp=(void(*)(mch*))rsoc_sweep;
    }
    else {
      csize=c->header.size;
    }
    c->header.size=csize;
    c->header.state_type=RSO_USED_CHUNK;
    c->free_list_of_large=NULL;
    c->nae=nae;
    nae->store=(&(c->first_header));
    nae->store_left=csize-sizeof(rsoc)+sizeof(rsoh);
    nae->store_chunk=c;
    c->next=nae->chunk_list;
    nae->chunk_list=c;
    return rso_from_store(nae,size);
  }
  return NULL;
}

char*new_na(na_env*nae,unsigned int size) {
  if (nae->store_left>0) {
    nae->store->header.size=nae->store_left;
    nae->store->header.magic_flag=RSOH_FREE;
    if (nae->store_left >= RSOC_MIN_STORE) {
      ((fll_rsoh*)(nae->store))->nextflol=nae->store_chunk->free_list_of_large;
      nae->store_chunk->free_list_of_large=((fll_rsoh*)nae->store);
    }
    nae->store_left=0;
  }
  if ((nae->store_chunk!=NULL)&&(get_store_in(nae->store_chunk,size))) {
    return rso_from_store(nae,size);
  }
  {
    char*r=new_na_from_chunk_list(nae,size);
    if (r!=NULL)
      return r;
  }
  if (rsoc_count<rsoc_count_ceil) {
    if((size+sizeof(rsoc)-sizeof(rsoh))>RSOC_SIZE){
      rsoc*c;
      rsoh*r;
      unsigned int rounded_size= chunk_rounded(size+sizeof(rsoc)-sizeof(rsoh));
      c=((rsoc*)(se_malloc(rounded_size)));
      r=(&(c->first_header));
      rsoc_count++;
      *c=MRSOC;
      c->isize = rounded_size;
      c->header.size=rounded_size;
      c->nae=nae;
      c->next=nae->chunk_list;
      nae->chunk_list=c;
      gc_add_into_gcmt((mch*)c);
      r->header.size=size;
      (r->header.magic_flag)=RSOH_UNMARKED;
      ((void)memset((r+1),0,size-sizeof(rsoh)));
      return (char*)(r+1);
    }
    else {
      rsoc_malloc(nae);
      return rso_from_store(nae,size);
    }
  }
  gc_start();
  if (size<=(nae->store_left)) {
    return rso_from_store(nae,size);
  }
  {
    char*r=new_na_from_chunk_list(nae,size);
    if (r!=NULL) {
      return r;
    }
  }
  if((size+sizeof(rsoc)-sizeof(rsoh))>RSOC_SIZE){
    rsoc*c;
    rsoh*r;
    unsigned int rounded_size = chunk_rounded(size+sizeof(rsoc)-sizeof(rsoh));
    c=((rsoc*)(se_malloc(rounded_size)));
    r=(&(c->first_header));
    rsoc_count++;
    *c=MRSOC;
    c->isize = rounded_size;
    c->header.size=rounded_size;
    c->nae=nae;
    c->next=nae->chunk_list;
    nae->chunk_list=c;
    gc_add_into_gcmt((mch*)c);
    r->header.size=size;
    (r->header.magic_flag)=RSOH_UNMARKED;
    ((void)memset((r+1),0,size-sizeof(rsoh)));
    gc_update_ceils();
    return (char*)(r+1);
  }
  else {
    rsoc_malloc(nae);
    gc_update_ceils();
    return rso_from_store(nae,size);
  }
}

static void gcna_align_mark(rsoc*c,void*o) {
  na_env* nae = c->nae;
  fll_rsoh* f;
  fll_rsoh* pf;
  char* b = (char*)&(c->first_header);

  /* properly aligned ? */
  if (((((char*)o)-((char*)c))%sizeof(int)) != 0) {
      return;
  }
  /* already marked ? */
  if ((((rsoh*)o)-1)->header.magic_flag != RSOH_UNMARKED) {
      return;
  }
  if (((char*)o) < ((char*)(c+1))) {
      return;
  }
  /* a large chunck ? */
  if (c->header.size > RSOC_SIZE) {
      if (o == (c+1)) {
	nae->gc_mark((T0*)o);
      }
      return;
  }
  pf=NULL;
  f=c->free_list_of_large;
  while ((f != NULL) && (f < ((fll_rsoh*)o))) {
      pf=f;
      f=f->nextflol;
  }
  if (pf == NULL) {
      pf=(fll_rsoh*)b;
  }
  while ((((rsoh*)pf)+1) < (rsoh*)o) {
      pf = ((fll_rsoh*)(((char*)pf)+pf->rsoh_field.size));
  }
  if (o == (((rsoh*)pf)+1)) {
    nae->gc_mark((T0*)o);
  }
}

unsigned int rsocfl_count(void) {
  /* Returns the number of items in the ReSizable Object Free List.
  */
  unsigned int r=0;
  rsoc*p=rsocfl;
  while (p!=NULL) {
    r++;
    p=p->next;
  }
  return r;
}

unsigned int fsocfl_count(void) {
  unsigned int r=0;
  fsoc*p=fsocfl;
  while (p!=NULL) {
    r++;
    p=p->next;
  }
  return r;
}

void gc_dispose_before_exit(void) {
  mch** p = gcmt;
  mch**eogcmt=gcmt+gcmt_used;

  while (p < eogcmt) {
    if (((*p)->state_type == FSO_STORE_CHUNK) ||
	((*p)->state_type == FSO_USED_CHUNK)) {
      ((*p)->swfp)(*p);
    }
    p++;
  }
}

fsoc* gc_fsoc_get1(void) {
  /* Get a `fsoc' (Fixed Size Object Chunk) from the free fsoc list or
     allocate a new one (using `se_malloc') only when the ceil is not
     yet reached. Otherwise, call the `gc_start()' function and
     return NULL.
  */
  fsoc* result;
  if (fsocfl != NULL) {
    result = fsocfl;
    fsocfl = fsocfl->next;
    return result;
  }
  else if (fsoc_count_ceil > fsoc_count) {
    result = ((fsoc*)se_malloc(FSOC_SIZE));
    fsoc_count++;
    gc_add_into_gcmt((mch*)result);
    return result;
  }
  else {
    gc_start();
    return NULL;
  }
}

fsoc* gc_fsoc_get2(void) {
  /* Get a `fsoc' (Fixed Size Object Chunk) or force the allocation of a
     new `fsoc' (using the `se_malloc' function). Update various ceils
     accordingly.
  */
  fsoc* result;
  if (fsocfl != NULL) {
    result = fsocfl;
    fsocfl=fsocfl->next;
    return result;
  }
  else {
    result = ((fsoc*)(se_malloc(FSOC_SIZE)));
    fsoc_count++;
    gc_update_ceils();
    gc_add_into_gcmt((mch*)result);
    return result;
  }
}

#if defined(__sparc__) || defined(sparc) || defined(__sparc)
/* For SPARC architecture.
   As this part contains assembly code (asm), you must not use
   the flag -ansi of gcc compiler.
*/

void mark_loop(void) {
  void** max = stack_bottom;
  void** stack_pointer;
  void* stack_top[2]={NULL,NULL};
  stack_pointer = stack_top;
  /* Addresses decrease as the stack grows. */
  while (stack_pointer <= max) {
    gc_mark(*(stack_pointer++));
  }
}

void mark_stack_and_registers(void) {
#  if defined(__sparcv9)
  asm(" flushw");
#  else
  asm(" ta      0x3   ! ST_FLUSH_WINDOWS");
#  endif
  mark_loop();
}

#elif defined(__ELATE__) || defined(ELATE)
/* GNU Eiffel's VP (Virtual Processor) garbage collector for Elate.
   (c) 2000 Rudi Chiarito <rudi@amiga.com>

   Thanks to Andy Stout and Kevin Croombs at Tao Group for their
   precious help!

   ChangeLog:
   - 2000-06-12 Rudi Chiarito <rudi@amiga.com>
     * Version 1.0
   - 2001-01-01 Joseph Kiniry <kiniry@acm.org>
     * Integrated with new SE 0.75b
   - 2001-08-10 Rudi Chiarito <rudi@amiga.com>
     * Inlined and optimised range marking
     * Added some more comments
     * Added conditional breakpoint in mark_stack_and_registers
   - 2002-09-21 Rudi Chiarito <rudi@amiga.com>
     * Removed redundant 'ret'
*/

__inline__ void mark_stack_and_registers(void)
{

  void *pointer_to_gc_mark = &gc_mark;

  __asm__ __volatile__
  (
    /*
      WARNING: funky code ahead!
      \t and \n are needed to make the final output easier to read
      while debugging. Hopefully you'll never have to bother with all
      of this.

      Registers:
        p0  pointer to stack block
        p1  pointer to gc_mark()
        p2  scratch pointer
        i0  length of current stack block
        i1  scratch register
    */

#  ifdef __ELATE_SE_DEBUG_GC
   "\tqcall sys/cii/breakpt,(-:-)\n"
#  endif

   "\tsync\n"                          /* spill all the registers */
   "\tsyncreg\n"                       /* to the stack */

   "\tcpy.p %0,p1\n"                   /* pointer to gc_mark() */

   /* pointer to the current stack block */
   "\tcpy.p [gp+PROC_STACK],p0\n"

   /* point to last location in the block, before the descriptor */
   "\tcpy.p p0 + ([(p0 - STK_SIZE) + STK_LENGTH] - STK_SIZE - 4),p2\n"

   /* mark the contents of the current stack block */
   "\twhile p2>=sp\n"
      "\t\tgos p1,(p2 : -)\n"
      "\t\tsub.p 4,p2\n"
   "\tendwhile\n"

   /* now scan other blocks (if any) */

   "\tloop\n"
      "\t\tcpy.p [p0 - STK_SIZE + STK_LINK],p0\n" /* get next block */
      "\t\tbreakif p0=NULL\n"

      /* point to last location in the block, before the descriptor */
      "\t\tcpy.p p0 + ([(p0 - STK_SIZE) + STK_LENGTH] - STK_SIZE - 4),p2\n"

      /* mark this block */
      "\t\twhile p2>=p0\n"

         "\t\t\tgos p1,(p2 : -)\n"
         "\t\t\tsub.p 4,p2\n"
      "\t\tendwhile\n"
   "\tendloop\n"

   : /* no output */
   : "p" (pointer_to_gc_mark)
   : "p0", "p1", "p2", "i0" 
   );
}

#elif defined(__hppa__) || defined(__hppa) || defined(__hp9000) || \
      defined(__hp9000s300) || defined(hp9000s300) || \
      defined(__hp9000s700) || defined(hp9000s700) || \
      defined(__hp9000s800) || defined(hp9000s800) || defined(hp9000s820)

/****************************************************************************
 * Generic code for architectures where addresses increase as the stack grows.
 ****************************************************************************/

void mark_stack_and_registers(void){
  void** max = stack_bottom;
  JMP_BUF registers;   /* The jmp_buf buffer is in the C stack. */
  void**stack_pointer; /* Used to traverse the stack and registers assuming
			  that `setjmp' will save registers in the C stack.
		       */

  (void)SETJMP(registers);  /* To fill the C stack with registers. */
  stack_pointer = (void**)(&registers) + ((sizeof(JMP_BUF)/sizeof(void*))-1);
  /* stack_pointer will traverse the JMP_BUF as well (jmp_buf size is added, 
     otherwise stack_pointer would be below the registers structure). */

#  if !defined(SE_BOOST)
  if (stack_pointer < max) {
    fprintf(stderr, "Wrong stack direction: your stack decrease as the stack grows (or complex stack management). Please drop an e-mail to SmartEiffel@loria.fr\n");
    exit(1); }
#  endif

  while (stack_pointer >= max) {
    gc_mark(*(stack_pointer--));
  }
}
#else

/****************************************************************************
 * Generic code for architectures where addresses decrease as the stack grows.
 ****************************************************************************/

void mark_stack_and_registers(void){
  void** max = stack_bottom;
  JMP_BUF registers;   /* The jmp_buf buffer is in the C stack. */
  void**stack_pointer; /* Used to traverse the stack and registers assuming
			  that `setjmp' will save registers in the C stack.
		       */

  (void)SETJMP(registers);  /* To fill the C stack with registers. */
  stack_pointer = (void**)(&registers);

#  if !defined(SE_BOOST)
  if (stack_pointer > max) {
    fprintf(stderr, "Wrong stack direction: the stack addresses increase as the stack grows (or complex stack management). Please drop an e-mail to SmartEiffel@loria.fr\n");
    exit(1); }
#  endif

  while (stack_pointer <= max) {
    gc_mark(*(stack_pointer++));
  }
}
#endif

