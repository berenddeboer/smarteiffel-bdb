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
  This file (SmartEiffel/sys/runtime/scoop_thread.h) is automatically included
  when separate objects are created.
*/

/**
 * @name Thread processors
 *
 * Only the POSIX semantics is supported as for now (February 4th 2003). It
 * will have to be expanded in the future, to support at least Windows
 * threads.
 *
 * @author Cyril Adrian
 */
//@{
#include <pthread.h>
#include <stdarg.h>

#define SE_SCOOP_THREAD 1

#define SE_SCOOP_THREAD_TYPE 0



typedef struct se_message          se_message_t;
typedef struct se_queue_wait       se_queue_wait_t;
typedef struct se_thread_mutex     se_thread_mutex_t;
typedef struct se_thread           se_thread_t;
typedef struct se_thread_once      se_thread_once_t;
typedef struct se_subsystem_thread se_subsystem_thread_t;
typedef struct se_origin_thread    se_origin_thread_t;



/**
 * The message queue of a processor
 */
struct se_message {

  /// Next message in queue, #NULL# if none.
  se_message_t* next;

  /// The client processor
  pthread_t caller;

  /// The message function ({\em agent})
  void (* agent)(void*,int,void*);

  /// Some data passed to the guard and the message
  void* data;

  /// Length of the data
  int length;

  /// The result location. #NULL# when the message is a command.
  void* result;

  /// Is the result available: non zero when true
  volatile int result_available;

  /// The subsystem originator of a query. #NULL# when no query was started.
  se_origin_t* origin;

#ifndef SE_BOOST
  /// Used to detect bad memory management
  int is_free;
#endif

  se_subsystem_thread_t* client;
};



/**
 * The subsystem monitor queue
 */
struct se_queue_wait {

  /// Next entry in queue
  se_queue_wait_t* next;

  /// The waiting processor
  se_subsystem_t*  subsystem;
};



/**
 * A mutex used to correctly define P() and V() with POSIX-compliant code.
 */
struct se_thread_mutex {

  /// A counter
  int count;

  /// The true mutex. POSIX requires the same thread to do the lock() and
  /// unlock()
  pthread_mutex_t mutex;

  /// A condition to synchronize the threads
  pthread_cond_t cond;
};



/**
 * An Eiffel once object shell: an access key, and the Eiffel object
 */
struct se_thread_once {
  // The key to access the object
  char* key;
  // The Eiffel "once" object
  void* once;
  // Next key
  se_thread_once_t* next;
};



/**
 * Extension of se_origin
 */
struct se_origin_thread {

  /// The "parent" structure
  se_origin_t super;

  /// A mutex
  pthread_mutex_t modify;
};



/**
 * Extension of se_subsystem
 */
struct se_subsystem_thread {

  /// The "parent" structure
  se_subsystem_t super;

  /// The processor
  pthread_t thread;

  /** Lock Manager */
  //@{

  /**
   * This counter is used when the subsystem is a client of a call. It counts
   * how many objects still have to be awaited for before we can dream of any
   * locking.
   */
  int lock_count;

  /**
   * This counter is used to count the number of providers that are ready to
   * serve the current subsystem. The subsystem will enter the critical
   * section when ready_lock_count == lock_count.
   */
  int ready_lock_count;

  /**
   * A locker to protect lock_count and ready_lock_count
   */
  pthread_mutex_t modify_lock_count;

  /**
   * This queue is used when the subsystem is a supplier. It holds all the
   * clients which wait to lock this subsystem. If #NULL#, no one waits for
   * this subsystem.
   */
  int lock_waiters_count;
  se_queue_wait_t* lock_waiters_head;
  se_queue_wait_t* lock_waiters_tail;

  /**
   * The current locker
   */
  se_subsystem_t* locker;

  /**
   * A mutex to protect the lock_waiters modification
   */
  pthread_mutex_t modify_locker;

  pthread_mutex_t lock_signal_mutex;
  pthread_cond_t  lock_signal_cond;

  /**
   * Origin of a query
   */
  se_origin_t* origin;
  pthread_mutex_t modify_origin;

  //@}

  /** Message queue handling */
  //@{

  /**
   * A mutex used when adding or removing elements in the message queue. The
   * counter is used to count the number of messages in the queue. The
   * condition is used to signal the presence of a new message in the queue.
   */
  se_thread_mutex_t message_queue_mutex;

  /**
   * The head of the message queue; #NULL# when empty.
   */
  se_message_t* queue_head;

  /**
   * The tail of the message queue
   */
  se_message_t* queue_tail;

  //@}

  /** Global subsystem maintenance */
  //@{

  /**
   * Non-zero when the processor must terminate
   */
  int stop_processor;

  /**
   * The number of objects in this subsystem.
   */
  int count;

  /**
   * A mutex used when reading/writing the number of objects in this
   * subsystem.
   */
  pthread_mutex_t modify_count;

#ifndef SE_BOOST
  /**
   * A mutex used when modifying the Dump Stack.
   */
  pthread_mutex_t modify_ds;

  /**
   * One Dump Stack per thread! Declared #void*# because se_dump_stack is
   * declared later on...
   */
  void* dst;

  /**
   * Non-0 when printing the Dump Stack
   */
  int print_dst;
#endif

  //@}

  /**
   * Thread-once handling. There is no need for any lock since only the
   * current processor can access those objects.
   */
  //@{

  /** The head of the once objects */
  se_thread_once_t* once_head;
  /** The once object last accessed */
  se_thread_once_t* once_memory;

  //@}
};

//@}



/**
 * This function is called by SmartEiffel if some thread-type processors are
 * created. (That is, always...)
 */
extern void init_scoop_thread();



/**
 * Returns the current running processor.
 */
se_subsystem_t* se_current_subsystem_thread();



extern int se_thread_count;
extern pthread_mutex_t se_thread_mutex;



#define state(thread_subsystem) (thread_subsystem)->super.state
#define state_wait_request(thread_subsystem) do { state(thread_subsystem) = SCOOP_PROCESSOR_WAITING_REQUEST; } while(0)
#define state_run(thread_subsystem) do { state(thread_subsystem) = SCOOP_PROCESSOR_RUNNING; } while(0)
#define state_block(thread_subsystem) do { state(thread_subsystem) = SCOOP_PROCESSOR_BLOCKED; } while(0)
#define state_wait_result(thread_subsystem) do { state(thread_subsystem) = SCOOP_PROCESSOR_WAITING_RESULT; } while(0)



#ifndef SE_BOOST

/**
 * Debug file, set to the value of the SCOOP_DEBUG environment variable.
 */
extern FILE* scoop_debug_file;
extern pthread_mutex_t scoop_debug_file_mutex;

void se_scoop_debug(char* format, ...) {
  va_list args;
  va_start(args, format);
  if (scoop_debug_file != NULL) {
    scoop_check_call(pthread_mutex_lock(&scoop_debug_file_mutex));
    {
      vfprintf(scoop_debug_file, format, args);
      fflush(scoop_debug_file);
    }
    scoop_check_call(pthread_mutex_unlock(&scoop_debug_file_mutex));
  }
  va_end(args);
}

#define se_scoop_trace(trace) do { \
    se_scoop_debug("%s:%d\t%s\n", __FILE__, __LINE__, trace); \
    if (scoop_debug_file != NULL) { \
      scoop_check_call(pthread_mutex_lock(&scoop_debug_file_mutex)); \
      { \
        fprintf(scoop_debug_file, "%s:%d\t%s\n", __FILE__, __LINE__, trace); \
        fflush(scoop_debug_file); \
      } \
      scoop_check_call(pthread_mutex_unlock(&scoop_debug_file_mutex)); \
    } \
    else { \
      fprintf(SE_ERR, "%s:%d\t%s\n", __FILE__, __LINE__, trace); \
    } \
  } while(0)

#else

void se_scoop_debug(char* dummy, ...) {} // I hope C compilers optimize this away!

#define se_scoop_trace(trace) fprintf(SE_ERR, "%s:%d\t%s\n", __FILE__, __LINE__, trace)

#endif
