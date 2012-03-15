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
  This file (SmartEiffel/sys/runtime/scoop.c) is automatically included
  when separate objects are created.
*/

/**@name Synchronization and Communication for Object-Oriented Programming (SCOOP)
 *
 * Implementation of common parts to all types of subsystems
 *
 * @author Philippe Ribet, Cyril Adrian
 */
//@{

/// The VFTs
static se_subsystem_vft_t** vft = NULL;

/// The number of known VFTs; i.e., the number of known subsystem types
static int vft_count = 0;



/**
 * Register a new type of subsystem. Must be done before the runtime starts
 * (no locking).
 *
 * {\em Advice:} Call this function for each type in decreasing order, to
 * avoid multiple instanciations of the #vft# array.
 */
void se_register_vft(int type, se_subsystem_vft_t* a_vft) {
  se_subsystem_vft_t** new_vft;
  int new_count;
  int i;
  if (vft_count <= type) {
    new_count = type+1;
    new_vft = (se_subsystem_vft_t**)malloc(new_count * sizeof(se_subsystem_vft_t*));
    if (new_vft == NULL) {
      fprintf(stderr, "SCOOP internals: could not alloc VFT table\n");
      exit(1);
    }
    for (i = new_count; i --> vft_count; ) new_vft[i] = NULL;
    if (vft_count != 0) {
      memcpy(new_vft, vft, vft_count * sizeof(se_subsystem_vft_t*));
    }
    if (vft != NULL) free(vft);
    vft = new_vft;
    vft_count = new_count;
  }
  vft[type] = a_vft;
}



/**
 * Create a new subsystem. The type must exist.
 */
se_subsystem_t* se_new_subsystem(int type, char* name) {
  se_subsystem_t* result = NULL;
  static int counter = 0;
  scoop_check(type < vft_count && type >= 0);
  result = vft[type]->new(name);
  result->vft = *vft[type];
  result->num = ++counter;
  return result;
}



#ifndef SE_BOOST
/**
 * Print the stack traces of all threads. Not available in boost mode.
 */
void se_print_all_stack_traces() {
  int i;
  for (i = vft_count; i --> 0; ) {
    vft[i]->print_all_stack_traces();
  }
}
#endif



/**
 * Create a new subsystem mapping the current thread. Used only for root
 * thread (init). The type must exist.
 */
se_subsystem_t* se_init_separate_root(int type, char* name) {
  se_subsystem_t* result = NULL;
  static int initialized=0;
  scoop_check(!initialized);
  scoop_check(type < vft_count && type >= 0);
  result = vft[type]->from_root(name);
  result->vft = *vft[type];
  result->num = 0;
  initialized = 1;
  return result;
}



/**
 * Used by se_join_subsystem (below)
 */
static void se_join(void* data, int length, void* result) {
  scoop_check(result != NULL);
  *((int*)result) = 1;
  return;
}



/**
 * Wait for the given subsystem to be ready (sends it a dummy query)
 *
 * @pre subsystem != NULL
 */
void se_join_subsystem(se_subsystem_t* subsystem) {
  volatile int join = 0;
  scoop_check(subsystem != NULL);
  subsystem->vft.query(subsystem, &se_join, NULL, 0, (void*)(&join));
  scoop_check(join);
}



/**
 * Returns the local object
 *
 * @post object != NULL || result == NULL
 * @post object == NULL || is_local(result)
 */
T0* as_local(T0* object) {
  if (object == NULL) return NULL;
  if (is_local(object)) return object;
  return ((sT0*)object)->ref;
}



/**
 * Returns true if the objects are identical (Eiffel's #=#, {\em not}
 * #is_equal#), modulo the subsystem object.
 */
int scoop_cmp(T0* o1, T0* o2) {
    int result = (o1 == o2);
    if (!result && o1 != NULL && o2 != NULL) {
	result = (as_local(o1) == as_local(o2));
    }
    return result;
}



void scoop_atexit() {
  int i;
  for (i = vft_count; i --> 0; ) {
    vft[i]->atexit();
  }
}


//@}
