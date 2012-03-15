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
  This file (SmartEiffel/sys/runtime/scoop.h) is automatically included
  when separate objects are created.
*/

/**@name Synchronization and Communication for Object-Oriented Programming (SCOOP)
 *
 * The intended semantics of this file is to provide SCOOP facilities as defined by Bertrand Meyer
 * (see http://www.eiffel.com/doc/manuals/technology/concurrency/CONCURRENCY.html)
 *
 * @author Philippe Ribet, Cyril Adrian
 */
//@{
#define SE_SCOOP 1



#define SCOOP_PROCESSOR_STARTING        0 /* The processor is being created */
#define SCOOP_PROCESSOR_WAITING_REQUEST 1 /* The processor is waiting for something to do */
#define SCOOP_PROCESSOR_RUNNING         2 /* The processor is processing a request */
#define SCOOP_PROCESSOR_BLOCKED         3 /* The processor is blocked on a guard */
#define SCOOP_PROCESSOR_WAITING_RESULT  4 /* The processor is waiting for a result to be available */
#define SCOOP_PROCESSOR_STOPPING        5 /* The processor is stopping */



/**
 * The SUBSYSTEM data structure
 */
typedef struct se_subsystem     se_subsystem_t;

/**
 * The SUBSYSTEM methods structure
 */
typedef struct se_subsystem_vft se_subsystem_vft_t;

/**
 * The ORIGIN data structure
 */
typedef struct se_origin        se_origin_t;

/**
 * A GUARD function returns FALSE (zero) when passing, TRUE (non-zero) when
 * blocking.
 */
typedef int (*se_guard_t)(void* data, int data_length);

/**
 * A COMMAND is a proxy function that calls back the SmartEiffel runtime in
 * the "good" processor.
 */
typedef void (*se_command_t)(void* data, int data_length, void* result);



/**
 * Remote object definition: it is just a proxy access to an Eiffel object; it
 * also has an attached subsystem it belongs to. Such an object has its own id
 * (managed by the SmartEiffel compiler). Conversions to and from the local
 * object are handled by SmartEiffel (see #get_subsystem()# and
 * #as_separate()#).
 */
//@{
typedef struct sS0 {
  /// Identifier of the object: its value is attributed by SmartEiffel
  int id;
  /// Reference to the subsystem the referenced object belongs to
  se_subsystem_t* subsystem;
  /// Reference to the local Eiffel object
  T0* ref;
} sT0;
//@}



/**
 * The interface of each subsystem
 */
//@{
struct se_subsystem_vft {

#ifndef SE_BOOST
  /**
   * The id: "type" of subsystem. Not present in boost mode.
   */
  int id;
#endif

  /**
   * Creates and returns a new subsystem.
   */
  se_subsystem_t* (*new)(char* name);

  /**
   * Creates a subsystem mapping the current processor. Used only for root
   * processor (init).
   *
   * It can be done at most once.
   */
  se_subsystem_t* (*from_root)(char* name);

  /**
   * Starts the subsystem event loop.
   */
  void (*run)(se_subsystem_t* current);

#ifdef SE_GC_LIB
  /**
   * GC sweep.
   *
   * Called by the GC when an instance in this subsystem is to be collected.
   *
   * @pre is_separate(a)
   */
  void (*gc_sweep)(T0* a);
#endif

  /**
   * Destroys the resources associated with the subsystem.
   */
  void (*delete)(se_subsystem_t* current);

  /**
   * Puts a command in the queue of the subsystem.
   */
  void (*command)(se_subsystem_t* current,
                  se_command_t command,
                  void* data,
                  int data_length);

  /**
   * Puts a query in the queue of the subsystem, and {\em wait} for the result
   * to be available.
   */
  void (*query)(se_subsystem_t* current,
                se_command_t command,
                void* data,
                int data_length,
                void* result);

#ifndef SE_BOOST
  /** Dump Stack management */
  //@{

  /**
   * Prints the runstack of the subsystem.
   */
  void (*print_run_time_stack)(se_subsystem_t* current);

  /**
   * Prints all the runstacks of the subsystem of the same processor type.
   */
  void (*print_all_stack_traces)();

  /**
   * Gets the Dump Stack, and lock for operations on it.
   */
  void* (*get_dst_and_lock)(se_subsystem_t* current);

  /**
   * Sets the Dump Stack, and unlock; no further operations should be
   * performed on it.
   */
  void (*set_dst_and_unlock)(se_subsystem_t* current, void* dst);

  //@}
#endif

  /**
   * Called when the runtime is about to finish.
   */
  void (*atexit)();

  /**
   * Increments the number of instances in the subsystem
   *
   * @return the number of instances in the subsystem
   */
  int (*inc_count)(se_subsystem_t* current);

  /**
   * Decrements the number of instances in the subsystem
   *
   * @return the number of instances in the subsystem
   */
  int (*dec_count)(se_subsystem_t* current);

  /**
   * Sets a new thread-once Eiffel object.
   * `once' is a T0**
   */
  void (*set_once)(se_subsystem_t* current, char* key, void* once);

  /**
   * Returns non-0 if the thread-once Eiffel object was set.
   */
  int (*is_set_once)(se_subsystem_t* current, char* key);

  /**
   * Gets a thread-once Eiffel object.
   * @return a T0**
   */
  void* (*get_once)(se_subsystem_t* current, char* key);

  /** Lock Manager */
  //@{

  /**
   * Returns non-zero if waiting is useful (it's useless if the providers are
   * all already locked by the client).
   */
  int (*must_wait_for_providers)(se_subsystem_t* current, se_subsystem_t** providers, int count);

  /**
   * The wait loop: waits for all providers to signal the subsystem. Returns
   * only when the providers can safely be locked.
   */
  void (*wait_for_providers)(se_subsystem_t* current, se_subsystem_t** providers, int count);

  /**
   * Unqueues the client from the subsystem. It must be the first waiter.
   */
  void (*unqueue_providers)(se_subsystem_t* current, se_subsystem_t** providers, int count);

  // ----------------------------------------------------------------------
  // "Private" functions:

  /**
   * USED INTERNALLY to set the current query originator.
   */
  void (*set_origin)(se_subsystem_t* current, se_origin_t* origin);

  /**
   * USED INTERNALLY to get the current query originator.
   */
  se_origin_t* (*get_origin)(se_subsystem_t* current);

  /**
   * USED INTERNALLY for inter-subsystem communication: tell the subsystem it
   * is ready to enter the provider. It means that the subsystem is at the top
   * of the provider's lock queue.
   */
  void (*signal)(se_subsystem_t* current, se_subsystem_t* provider);

  /**
   * USED INTERNALLY for inter-subsystem communication: tell the subsystem it
   * was enqueued.
   */
  void (*wait_commit)(se_subsystem_t* current, se_subsystem_t* provider);

  /**
   * USED INTERNALLY for inter-subsystem communication: tell the subsystem it
   * was dequeued.
   */
  void (*unqueue_waiter_commit)(se_subsystem_t* current, se_subsystem_t* provider);

  //@}
};
//@}



/**
 * Used to represent the origin of a query cycle
 */
struct se_origin {
  /**
   * A unique identifier
   */
  long long id;
  /**
   * The processor that initiated the cycle
   */
  se_subsystem_t* subsystem;
  /**
   * A reference counter
   */
  int ref_count;

#ifndef SE_BOOST
  /// Used to detect bad memory management
  int is_free;
#endif

  /// Used by memory management
  se_origin_t* next;
};



/**
 * The most important structure: there is one such per processor.
 */
struct se_subsystem {

#ifndef SE_BOOST
  /**
   * The id: "type" of subsystem. Not present in boost mode.
   */
  int id;
#endif

  /**
   * The subsystems are chained between them.
   *
   * @see se_system
   */
  se_subsystem_t* next;

  /// The unique identifier used e.g. for lock sorting
  int num;

  /// Number of instances in this subsystem
  int count;

  /// Name of the subsystem
  char* name;

  /// State of the processor
  int state;

  /**
   * The subsystems contain their own functions a la unix
   */
  se_subsystem_vft_t vft;
};



// ======================================================================



/**
 * Interface used by the SmallEiffel generated runtime
 */
//@{

/**
 * Creates a new subsystem. The type must exist.
 */
extern se_subsystem_t* se_new_subsystem(int type, char* name);



/**
 * Creates a new subsystem mapping the current thread. Used only for root
 * thread (init). The type must exist.
 */
extern se_subsystem_t* se_init_separate_root(int type, char* name);



#ifndef SE_BOOST
/**
 * Prints the stack traces of all threads
 */
extern void se_print_all_stack_traces();
#endif



/**
 * Waits for the current thread to be ready (sends it a dummy query)
 */
extern void se_join_subsystem(se_subsystem_t* subsystem);

//@}



// ======================================================================



/**
 * Interface used by the SCOOP internals (the subsystems
 * implementations). Those functions are defined in scoop.c
 */
//@{

/**
 * Registers a new type of subsystem.
 */
extern void se_register_vft(int type, se_subsystem_vft_t* vft);



#ifdef SE_BOOST

/// In boost mode
//@{
/// Ignored check; simply calls #x#
#define scoop_check_call(x) (x)

/// Ignored check
#define scoop_check(x) ((void)0)
//@}



#else
void se_print_run_time_stack(void);

/// In non-boost mode
//@{
/// Executes x; if it returns non-zero, exits.
#define scoop_check_call(x) \
  do { \
    if (x) { \
      fprintf(stderr, "SCOOP internals: error while calling \"%s\" (line %d in %s)\n", #x, __LINE__, __FILE__); se_print_run_time_stack(); exit(1); \
    } \
  } while (0)

/// If x is false, exits.
#define scoop_check(x) \
  do { \
    if (!(x)) { \
      fprintf(stderr, "SCOOP internals: check \"%s\" failed (line %d in %s)\n", #x, __LINE__, __FILE__); se_print_run_time_stack(); exit(1); \
    } \
  } while (0)

#endif
//@}

//@}



// get_subsystem() is generated by SmartEiffel: it knows which types are
// separate, based on their ids.



/**
 * Returns non-zero if the object is not a separate object
 */
#define is_local(object) (get_subsystem(object, NULL) == NULL)



/**
 * Returns non-zero if the object is a separate object
 */
#define is_separate(object) (get_subsystem(object, NULL) != NULL)



/**
 * Returns the local version of the given object (be it separate or not)
 *
 * @post is_local(return)
 */
T0* as_local(T0* object);



/**
 * Compares (using '==') the local version of the given objects.
 *
 * @post result == (as_local(o1) == as_local(o2))
 */
int scoop_cmp(T0* o1, T0* o2);



/**
 * Called by SmartEiffel at process exit
 */
void scoop_atexit();

//@}
