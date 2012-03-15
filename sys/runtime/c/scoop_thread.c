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
  This file (SmartEiffel/sys/runtime/scoop_thread.c) is automatically included
  when separate objects are created.
*/

/**
 * @author Philippe Ribet
 * @author Cyril Adrian
 */

//@{

#define SCOOP_TYPE_THREAD 0



/* --[SCOOP variables]--------------------------------------------------- */

//@{

/**
 * All threads
 */
se_subsystem_thread_t* se_thread_system = NULL;



/**
 * Last accessed thread structure (used to speed up
 * #se_current_subsystem_thread()#)
 */
se_subsystem_thread_t* se_thread_memory = NULL;



/**
 * Number of active threads
 */
int se_thread_count = 0;



/**
 * Mutex protecting the above resources
 */
pthread_mutex_t se_thread_mutex = PTHREAD_MUTEX_INITIALIZER;

//@}



#ifndef SE_BOOST
/**
 * Becomes true as soon as one thread_command() was performed (it allows the
 * message posted by the main function to pass unhindered by my paranoid
 * tests.
 */
static int se_system_init_done = 0;
#endif



/**
 * The Threads VFT.
 */
static se_subsystem_vft_t* thread_vft;



#ifndef SE_BOOST
FILE* scoop_debug_file = NULL;
pthread_mutex_t scoop_debug_file_mutex = PTHREAD_MUTEX_INITIALIZER;
#endif



/* --[Forward declarations]---------------------------------------------- */



// VFT functions:



static se_subsystem_t*  thread_new(char* name);
static se_subsystem_t*  thread_from_root(char* name);
static void             thread_run(se_subsystem_t* root);
#ifdef SE_GC_LIB
static void             thread_gc_sweep(T0* a);
#endif
static void             thread_delete(se_subsystem_t* subsystem);
static void             thread_command(se_subsystem_t* subsystem, se_command_t command, void* data, int length);
static void             thread_query(se_subsystem_t* subsystem, se_command_t command, void* data, int length, void* result);
#ifndef SE_BOOST
static void             thread_print_run_time_stack(se_subsystem_t* subsystem);
static void             thread_print_all_stack_traces();
static void*            thread_get_dst_and_lock(se_subsystem_t* subsystem);
static void             thread_set_dst_and_unlock(se_subsystem_t* subsystem, void* dst);
#endif
static void             thread_atexit();
static int              thread_inc_count(se_subsystem_t* subsystem);
static int              thread_dec_count(se_subsystem_t* subsystem);
static void             thread_set_once(se_subsystem_t* subsystem, char* key, void* once);
static int              thread_is_set_once(se_subsystem_t* subsystem, char* key);
static void*            thread_get_once(se_subsystem_t* subsystem, char* key);
static int              thread_must_wait_for_providers(se_subsystem_t* subsystem, se_subsystem_t** providers, int count);
static void             thread_wait_for_providers(se_subsystem_t* subsystem, se_subsystem_t** providers, int count);
static void             thread_unqueue_providers(se_subsystem_t* subsystem, se_subsystem_t** providers, int count);
static void             thread_set_origin(se_subsystem_t* subsystem, se_origin_t* origin);
static se_origin_t*     thread_get_origin(se_subsystem_t* subsystem);
static void             thread_signal(se_subsystem_t* subsystem, se_subsystem_t* provider);
static void             thread_wait_commit(se_subsystem_t* subsystem, se_subsystem_t* provider);
static void             thread_unqueue_waiter_commit(se_subsystem_t* subsystem, se_subsystem_t* provider);



// Some other internal functions:



static int                    se_execute_message(se_subsystem_thread_t* subsystem, se_message_t* message, se_message_t* previous);
static void                   se_loop_thread(se_subsystem_thread_t* subsystem);
static void                   scoop_delete_subsystem(se_subsystem_thread_t* subsystem);
static void*                  se_run_thread(void* a);
static se_subsystem_thread_t* scoop_create_subsystem(char* name);



/* --[Interface from scoop.h]-------------------------------------------- */



void init_scoop_thread() {
  static se_subsystem_vft_t static_thread_vft = {
#ifndef SE_BOOST
    .id                      = SCOOP_TYPE_THREAD,
#endif
    .new                     = thread_new,
    .from_root               = thread_from_root,
    .run                     = thread_run,
#ifdef SE_GC_LIB
    .gc_sweep                = thread_gc_sweep,
#endif
    .delete                  = thread_delete,
    .command                 = thread_command,
    .query                   = thread_query,
#ifndef SE_BOOST
    .print_run_time_stack    = thread_print_run_time_stack,
    .print_all_stack_traces  = thread_print_all_stack_traces,
    .get_dst_and_lock        = thread_get_dst_and_lock,
    .set_dst_and_unlock      = thread_set_dst_and_unlock,
#endif
    .atexit                  = thread_atexit,
    .inc_count               = thread_inc_count,
    .dec_count               = thread_dec_count,
    .set_once                = thread_set_once,
    .is_set_once             = thread_is_set_once,
    .get_once                = thread_get_once,
    .must_wait_for_providers = thread_must_wait_for_providers,
    .wait_for_providers      = thread_wait_for_providers,
    .unqueue_providers       = thread_unqueue_providers,
    .set_origin              = thread_set_origin,
    .get_origin              = thread_get_origin,
    .signal                  = thread_signal,
    .wait_commit             = thread_wait_commit,
    .unqueue_waiter_commit   = thread_unqueue_waiter_commit,
  };

#ifndef SE_BOOST
  {
    char* path = getenv("SCOOP_THREAD_DEBUG");
    if (path != NULL) {
      if (strcmp(path, "SE_ERR")==0) {
        scoop_debug_file = SE_ERR;
      }
      else {
        scoop_debug_file = fopen(path, "w");
      }
    }
    else {
      fprintf(SE_ERR, "SCOOP_THREAD_DEBUG not set\n");
    }
  }
#endif

  thread_vft = &static_thread_vft;
  se_register_vft(SCOOP_TYPE_THREAD, thread_vft);
}



/* --[Memory management]------------------------------------------------- */



static se_message_t* free_messages;
static pthread_mutex_t se_messages_mutex = PTHREAD_MUTEX_INITIALIZER;



static se_origin_t* free_origins;
long long se_origin_counter = 0;
static pthread_mutex_t se_origins_mutex = PTHREAD_MUTEX_INITIALIZER;



static se_origin_thread_t* se_new_origin(se_subsystem_t* subsystem) {

  se_origin_thread_t* result = NULL;

  scoop_check_call(pthread_mutex_lock(&se_origins_mutex));
  {
    result = (se_origin_thread_t*)free_origins;
    if (result != NULL) {
#ifndef SE_BOOST
      scoop_check(result->super.is_free);
#endif
      free_origins = result->super.next;
    }
    else {
      result = (se_origin_thread_t*)malloc(sizeof(se_origin_thread_t));

      if (result == NULL) {
        se_scoop_trace("Internal error in scoop.c: could not malloc origin");
        se_print_run_time_stack();
        exit(1);
      }
    }
    result->super.next = NULL;
#ifndef SE_BOOST
    result->super.is_free = 0;
#endif
    result->super.ref_count = 0;
    result->super.subsystem = subsystem;
    result->super.id = ++se_origin_counter;

    scoop_check_call(pthread_mutex_init(&result->modify, NULL));

#ifndef SE_BOOST
    se_scoop_debug("new origin #%lli for processor %s\n", result->super.id, subsystem->name);
#endif
  }
  scoop_check_call(pthread_mutex_unlock(&se_origins_mutex));

  return result;
}



static void se_free_origin(se_origin_thread_t* origin) {

  scoop_check(origin != NULL);
#ifndef SE_BOOST
  scoop_check(!origin->super.is_free);
#endif

  scoop_check_call(pthread_mutex_lock(&se_origins_mutex));
  {
    origin->super.next = free_origins;
    free_origins = &(origin->super);
#ifndef SE_BOOST
    origin->super.is_free=1;
#endif
    scoop_check_call(pthread_mutex_destroy(&origin->modify));
  }
  scoop_check_call(pthread_mutex_unlock(&se_origins_mutex));
}



static se_message_t* se_new_message() {

  se_message_t* result = NULL;

  scoop_check_call(pthread_mutex_lock(&se_messages_mutex));
  {
    result = free_messages;
    if (result != NULL) {
#ifndef SE_BOOST
      scoop_check(result->is_free);
#endif
      free_messages = result->next;
    }
    else {
      result = (se_message_t*)malloc(sizeof(se_message_t));

      if (result == NULL) {
        se_scoop_trace("Internal error in scoop.c: could not malloc message");
        se_print_run_time_stack();
        exit(1);
      }
    }
    result->next = NULL;
#ifndef SE_BOOST
    result->is_free = 0;
#endif
  }
  scoop_check_call(pthread_mutex_unlock(&se_messages_mutex));

  return result;
}



static void se_free_message(se_message_t* message) {

  se_origin_thread_t* origin;

  scoop_check(message != NULL);
#ifndef SE_BOOST
  scoop_check(!message->is_free);
#endif

  origin = (se_origin_thread_t*)(message->origin);
  if (origin != NULL) {
    int destroy=0;
    scoop_check_call(pthread_mutex_lock(&(origin->modify)));
    {
      origin->super.ref_count--;
      destroy=(origin->super.ref_count==0);
    }
    scoop_check_call(pthread_mutex_unlock(&(origin->modify)));
    scoop_check(!destroy);
    if (destroy) se_free_origin(origin);
  }

  scoop_check_call(pthread_mutex_lock(&se_messages_mutex));
  {
    message->next = free_messages;
    free_messages = message;
#ifndef SE_BOOST
    message->is_free=1;
#endif
  }
  scoop_check_call(pthread_mutex_unlock(&se_messages_mutex));
}



/* --[Implementation]---------------------------------------------------- */



/**
 * Inter-subsystem locking.
 *
 * POSIX semantics demand mutexes to be locked and unlocked by the same
 * thread. The hanshakes between Processors are implemented as PV/VP and need
 * inter-Processors mutexes.
 */
//@{



/// Reserve
#define P(m) do { \
  pthread_mutex_lock(&((m).mutex)); \
  if (((m).count) > 0) { \
    ((m).count)--; \
  } \
  else { \
    do { \
      pthread_cond_wait(&((m).cond),&((m).mutex)); \
    } while (((m).count) <= 0); \
    scoop_check(((m).count) > 0); \
    ((m).count)--; \
  } \
  pthread_mutex_unlock(&((m).mutex)); \
} while(0)



/// Surrender
#define V(m) do { \
  pthread_mutex_lock(&((m).mutex)); \
  ((m).count)++; \
  pthread_cond_signal(&((m).cond)); \
  pthread_mutex_unlock(&((m).mutex)); \
} while(0)



//@}



static void
thread_atexit() {
#ifndef SE_BOOST
  if (scoop_debug_file != NULL) {
    scoop_check_call(pthread_mutex_lock(&scoop_debug_file_mutex));
    {
      fflush(scoop_debug_file);
    }
    scoop_check_call(pthread_mutex_unlock(&scoop_debug_file_mutex));
  }
#endif
}



/// Atomically increment the number of instances of a subsystem.
static int
thread_inc_count(se_subsystem_t* subsystem) {

  se_subsystem_thread_t* s=(se_subsystem_thread_t*)subsystem;
  int result = 0;

#ifndef SE_BOOST
  if (s->super.id != SCOOP_TYPE_THREAD) {
    se_scoop_trace("SCOOP internals: bad subsystem type.");
    se_print_run_time_stack();
    exit(1);
  }
#endif

  pthread_mutex_lock(&(s->modify_count));
  {
    result = ++(s->super.count);
  }
  pthread_mutex_unlock(&(s->modify_count));

#ifndef SE_BOOST
    se_scoop_debug("increment count for processor %s, now %d\n", subsystem->name, result);
#endif

  return result;
}



/// Atomically decrement the number of instances of a subsystem.
static int
thread_dec_count(se_subsystem_t* subsystem) {
  se_subsystem_thread_t* s=(se_subsystem_thread_t*)subsystem;
  int result;

#ifndef SE_BOOST
  if (s->super.id != SCOOP_TYPE_THREAD) {
    se_scoop_trace("SCOOP internals: bad subsystem type.");
    se_print_run_time_stack();
    exit(1);
  }
#endif

  pthread_mutex_lock(&(s->modify_count));
  {
    result = --(s->super.count);
  }
  pthread_mutex_unlock(&(s->modify_count));

#ifndef SE_BOOST
    se_scoop_debug("decrement count for processor %s, now %d\n", subsystem->name, result);
#endif

  return result;
}



/// Used by #thread_set_once()#, #thread_is_set_once()#, and #thread_get_once()#
static se_thread_once_t*
se_find_once(se_subsystem_t* subsystem, char* key) {
  se_thread_once_t* result = NULL;
  se_subsystem_thread_t* s = (se_subsystem_thread_t*)subsystem;
  if (s->once_memory != NULL) {
    if (!strcmp(s->once_memory->key, key)) {
      result = s->once_memory;
    }
  }
  if (result == NULL) {
    // The memory was not the good object. Let's try and find it...
    se_thread_once_t* current = s->once_head;
    while (result == NULL && current != NULL) {
      if (!strcmp(current->key, key)) {
        result = s->once_memory = current;
      }
      else {
        current = current->next;
      }
    }
  }

#ifndef SE_BOOST
    se_scoop_debug("looking once object for processor %s and key %s,\n  found %p\n", subsystem->name, key, result == NULL ? NULL : result->once);
#endif

  return result;
}



static void
thread_set_once(se_subsystem_t* subsystem, char* key, void* once) {
  se_subsystem_thread_t* s = (se_subsystem_thread_t*)subsystem;
  se_thread_once_t* t_once = se_find_once(subsystem, key);
#ifndef SE_BOOST
  se_scoop_debug("setting once object %p for processor %s and key %s\n", once, subsystem->name, key);
#endif
  scoop_check(t_once == NULL);
  t_once = (se_thread_once_t*)malloc(sizeof(se_thread_once_t));
  t_once->next = s->once_head;
  t_once->key = key;
  t_once->once = once;
  s->once_head = s->once_memory = t_once;
}



static int
thread_is_set_once(se_subsystem_t* subsystem, char* key) {
  int result = se_find_once(subsystem, key) != NULL;
  return result;
}



static void*
thread_get_once(se_subsystem_t* subsystem, char* key) {
  void* result = NULL;
  se_thread_once_t* once = se_find_once(subsystem, key);
  if (once != NULL) result = once->once;
  return result;
}



static se_subsystem_t*
thread_new(char* name) {
  se_subsystem_thread_t* new = scoop_create_subsystem(name);
  scoop_check_call(pthread_create(&(new->thread), NULL, se_run_thread, new));

#ifndef SE_BOOST
    se_scoop_debug("new processor %s\n", name);
#endif

  return (se_subsystem_t*)new;
}



static se_subsystem_t*
thread_from_root(char* name) {
  se_subsystem_thread_t* new = scoop_create_subsystem(name);
  new->thread = pthread_self();

#ifndef SE_BOOST
    se_scoop_debug("new root processor %s\n", name);
#endif

  return (se_subsystem_t*)new;
}



static void
thread_run(se_subsystem_t* subsystem) {

#ifndef SE_BOOST
    se_scoop_debug("starting processor %s\n", subsystem->name);
#endif

  se_run_thread(subsystem);
}



static void
thread_delete(se_subsystem_t* subsystem) {

#ifndef SE_BOOST
    se_scoop_debug("deleting processor %s\n", subsystem->name);
#endif

  scoop_delete_subsystem((se_subsystem_thread_t*)subsystem);
}



static void
thread_command(se_subsystem_t* subsystem, se_command_t command, void* data, int length) {

  se_message_t*          message;
  se_subsystem_thread_t* s = (se_subsystem_thread_t*)subsystem;
  se_origin_thread_t*    origin;

  scoop_check(!s->stop_processor);

#ifndef SE_BOOST
  if (se_system_init_done) if (pthread_equal(s->thread, pthread_self())) {
    se_scoop_trace("SCOOP internals: error in scoop.c: thread_command() called by the same thread");
    se_print_run_time_stack();
    exit(1);
  }

  /* Afterwards the threads will be checked. The first is not, since it is the
   * initialization performed by the main thread...
   */
  se_system_init_done = 1;

  se_scoop_debug("new command for processor %s\n", subsystem->name);
#endif

  message = se_new_message();

  message->agent            = command;
  message->caller           = pthread_self();
  message->data             = data;
  message->length           = length;
  message->result           = NULL;
  message->next             = NULL;
  message->result_available = 1;
  message->client           = NULL; // the client is useless for a command

  // Pass the origin, if set
  origin = (se_origin_thread_t*)thread_get_origin(se_current_subsystem_thread());
  if (origin == NULL) {
    message->origin = NULL;
  }
  else {
    message->origin = &(origin->super);
    scoop_check_call(pthread_mutex_lock(&(origin->modify)));
    {
      origin->super.ref_count++;
    }
    scoop_check_call(pthread_mutex_unlock(&(origin->modify)));
  }

  // Now enqueue the message
  scoop_check_call(pthread_mutex_lock(&(s->message_queue_mutex.mutex)));
  {
    if (s->message_queue_mutex.count == 0) {
      s->queue_head = message;
    }
    else {
      s->queue_tail->next = message;
    }

    s->queue_tail = message;
    s->message_queue_mutex.count++;

    /**
     * Increase the number of active subsystems
     */
    scoop_check_call(pthread_mutex_lock(&se_thread_mutex));
    {
      se_thread_count++;
    }
    scoop_check_call(pthread_mutex_unlock(&se_thread_mutex));

    /* Tell the thread that a command has been posted */
    scoop_check_call(pthread_cond_signal(&(s->message_queue_mutex.cond)));
  }
  scoop_check_call(pthread_mutex_unlock(&(s->message_queue_mutex.mutex)));
}



static void
thread_query(se_subsystem_t* subsystem, se_command_t command, void* data, int length, void* result) {

  se_message_t*          message;
  se_subsystem_thread_t* s         = (se_subsystem_thread_t*)subsystem;
  se_origin_thread_t*    origin;
  int                    is_origin = 0;
  se_subsystem_t*        self      = se_current_subsystem_thread();

  scoop_check(!s->stop_processor);

#ifndef SE_BOOST
  if (se_system_init_done) if (pthread_equal(s->thread, pthread_self())) {
    se_scoop_trace("SCOOP internals: error in scoop.c: thread_query() called by the same thread");
    se_print_run_time_stack();
    exit(1);
  }

  /* Afterwards the threads will be checked. The first is not, since it is the
   * initialization performed by the main thread
   */
  se_system_init_done = 1;

    se_scoop_debug("new query for processor %s\n", subsystem->name);
#endif

  message = se_new_message();

  message->agent            = command;
  message->caller           = pthread_self();
  message->data             = data;
  message->length           = length;
  message->result           = result;
  message->next             = NULL;
  message->result_available = 0;
  message->client           = (se_subsystem_thread_t*)self;

  // Pass the origin, if set
  origin = (se_origin_thread_t*)thread_get_origin(self);
  if (origin == NULL) {
    origin = se_new_origin(self);
    self->vft.set_origin(self, &(origin->super));
    origin->super.ref_count++;
    is_origin = 1;
  }
  else {
    message->origin = &(origin->super);
    scoop_check_call(pthread_mutex_lock(&(origin->modify)));
    {
      origin->super.ref_count++;
    }
    scoop_check_call(pthread_mutex_unlock(&(origin->modify)));
  }

  // Enqueue the message
  scoop_check_call(pthread_mutex_lock(&(s->message_queue_mutex.mutex)));
  {
    if (s->message_queue_mutex.count == 0) {
      s->queue_head = message;
    }
    else {
      scoop_check(s->queue_head != NULL);
      s->queue_tail->next = message;
    }

    s->queue_tail = message;
    s->message_queue_mutex.count++;

    /**
     * Increase the number of active subsystems
     */
    scoop_check_call(pthread_mutex_lock(&se_thread_mutex));
    {
      se_thread_count++;
    }
    scoop_check_call(pthread_mutex_unlock(&se_thread_mutex));

    /* Tell the thread that a command has been posted */
    scoop_check_call(pthread_cond_signal(&(s->message_queue_mutex.cond)));
  }
  scoop_check_call(pthread_mutex_unlock(&(s->message_queue_mutex.mutex)));

  // We wait for the result to be available
  {
    se_subsystem_thread_t* myself      = (se_subsystem_thread_t*)self;
    int                    execute_msg = 0;
    int                    must_wait   = 1;
    se_message_t*          cur_msg     = message;
    se_message_t*          msg;
    do {
      must_wait = (!(message->result_available));
      if (must_wait) {
        scoop_check_call(pthread_mutex_lock(&(myself->message_queue_mutex.mutex)));
        {
          must_wait = (!(message->result_available));
          if (must_wait) {
            scoop_check_call(pthread_cond_wait(&(myself->message_queue_mutex.cond), &(myself->message_queue_mutex.mutex)));
            must_wait = (!(message->result_available));
            if (must_wait) {
              msg = cur_msg->next;
              if (msg != NULL) {
                scoop_check((msg->next != NULL) || (msg == myself->queue_tail));
                while (msg->next != NULL && msg->origin->id != origin->super.id) {
                  cur_msg = msg;
                  msg = msg->next;
                  scoop_check((msg->next != NULL) || (msg == myself->queue_tail));
                }
                if (msg->origin != NULL) {
                  execute_msg = (msg->origin->id == origin->super.id);
                }
              }
            }
          }
        }
        scoop_check_call(pthread_mutex_unlock(&(myself->message_queue_mutex.mutex)));
        if (execute_msg) {
          // A message with the same origin is in the wait queue: let's call it.
          int term;
          scoop_check(must_wait);
#ifndef SE_BOOST
          se_scoop_debug("processor %s directly calls a message while waiting for a query to complete\n", subsystem->name);
#endif
          term = se_execute_message(myself, msg, cur_msg);
          scoop_check(!term);
          execute_msg = 0;
        }
      }
    } while (must_wait);
  }

  scoop_check(message->result_available);

#ifndef SE_BOOST
  se_scoop_debug("processor %s has obtained the result\n", subsystem->name);
#endif

  se_free_message(message);

  if (is_origin) {
    int destroy = 0;
    self->vft.set_origin(self, NULL);
    scoop_check_call(pthread_mutex_lock(&(origin->modify)));
    {
      origin->super.ref_count--;
      destroy=(origin->super.ref_count==0);
    }
    scoop_check_call(pthread_mutex_unlock(&(origin->modify)));
    scoop_check(destroy);
    if (destroy) se_free_origin(origin);
  }
}



#ifdef SE_GC_LIB
static void
thread_gc_sweep(T0* a) {
  se_subsystem_thread_t* subsystem = (se_subsystem_thread_t*)(get_subsystem(a, NULL));
  if (subsystem != NULL) {
    scoop_check_call(pthread_mutex_lock(&(subsystem->modify_count)));
    {
      subsystem->stop_processor = (--(subsystem->count) == 0);
    }
    scoop_check_call(pthread_mutex_unlock(&(subsystem->modify_count)));
  }
}
#endif



#ifndef SE_BOOST
static void*
thread_get_dst_and_lock(se_subsystem_t* subsystem) {
  se_subsystem_thread_t* s = (se_subsystem_thread_t*)subsystem;
  scoop_check_call(pthread_mutex_lock(&(s->modify_ds)));
  return s->dst;
}



static void
thread_set_dst_and_unlock(se_subsystem_t* subsystem, void* dst) {
  se_subsystem_thread_t* s = (se_subsystem_thread_t*)subsystem;
  s->dst = dst;

#ifndef SE_BOOST
    se_scoop_debug("set dst %p for processor %s\n", dst, subsystem->name);
    if (scoop_debug_file != NULL) {
      scoop_check_call(pthread_mutex_lock(&scoop_debug_file_mutex));
      {
        if (dst == NULL) {
          fprintf(scoop_debug_file, "NULL\n");
        }
        else {
          fprintf(scoop_debug_file, "=====================================================================\n");
          se_print_one_frame_in(scoop_debug_file, dst);
          fprintf(scoop_debug_file, "=====================================================================\n");
        }
        fflush(scoop_debug_file);
      }
      scoop_check_call(pthread_mutex_unlock(&scoop_debug_file_mutex));
    }
#endif

  scoop_check_call(pthread_mutex_unlock(&(s->modify_ds)));
}



static void
thread_print_run_time_stack(se_subsystem_t* subsystem) {
  se_subsystem_thread_t* s=(se_subsystem_thread_t*)subsystem;

  scoop_check_call(pthread_mutex_lock(&(s->modify_ds)));
  {
    se_dump_stack* dst = s->dst;
    se_dump_stack* ds  = NULL;
    se_dump_stack* ds2;
    int frame_count = 1;

    if (s->print_dst) {
      se_scoop_trace("SCOOP internals: loop while printing stack trace!!!");
      exit(1);
    }

    s->print_dst = 1;

    ds = dst;
    fprintf(SE_ERR,"Run Time Stack for processor \"%s\".\n", subsystem->name);
    if (ds == NULL) {
      fprintf(SE_ERR,"Empty stack.\n");
    }
    else {
      while (ds->caller != NULL) {
        ds = ds->caller;
        frame_count++;
      }
      fprintf(SE_ERR,"%d frames in current stack.\n",frame_count);
      fprintf(SE_ERR,"=====  Bottom of run-time stack  =====\n");
      while (ds != NULL) {
        se_print_one_frame(ds);
        /* Next frame : */
        if (ds == dst) {
          ds = NULL;
        }
        else {
          ds2 = dst;
          while (ds2->caller != ds) {
            ds2 = ds2->caller;
          }
          ds = ds2;
        }
        if (--frame_count) {
          fprintf(SE_ERR,"======================================\n");
        }
      }
      fprintf(SE_ERR,"=====   Top of run-time stack    =====\n");
    }

    s->print_dst = 0;
  }
  scoop_check_call(pthread_mutex_unlock(&(s->modify_ds)));
}



static void
thread_print_all_stack_traces() {
  scoop_check_call(pthread_mutex_lock(&se_thread_mutex));
  {
    se_subsystem_t* current = &(se_thread_system->super);
    while (current != NULL) {
      thread_print_run_time_stack(current);
      current = current->next;
    }
  }
  scoop_check_call(pthread_mutex_unlock(&se_thread_mutex));
}
#endif /* SE_SCOOP */



static void
thread_wait_commit(se_subsystem_t* subsystem, se_subsystem_t* provider) {

  se_subsystem_thread_t* s = (se_subsystem_thread_t*)subsystem;

#ifndef SE_BOOST
    se_scoop_debug("processor %s waits commit from provider %s\n", subsystem->name, provider->name);
#endif

  scoop_check_call(pthread_mutex_lock(&(s->modify_lock_count)));
  {
    s->lock_count++;
  }
  scoop_check_call(pthread_mutex_unlock(&(s->modify_lock_count)));
}



static void
thread_unqueue_waiter_commit(se_subsystem_t* subsystem, se_subsystem_t* provider) {

  se_subsystem_thread_t* s = (se_subsystem_thread_t*)subsystem;

#ifndef SE_BOOST
    se_scoop_debug("processor %s commits \"unqueue waiter\" from provider %s\n", subsystem->name, provider->name);
#endif

  scoop_check_call(pthread_mutex_lock(&(s->modify_lock_count)));
  {
    s->ready_lock_count++;
  }
  scoop_check_call(pthread_mutex_unlock(&(s->modify_lock_count)));
}



static void
thread_wait(se_subsystem_t* subsystem, se_subsystem_t* client) {

  se_subsystem_thread_t* s=(se_subsystem_thread_t*)subsystem;
  se_queue_wait_t* waiter;

#ifndef SE_BOOST
    se_scoop_debug("processor %s waits for client %s\n", subsystem->name, client->name);
#endif

  scoop_check(subsystem != client);
  scoop_check_call(pthread_mutex_lock(&(s->modify_locker)));
  {
    waiter = (se_queue_wait_t*)malloc(sizeof(se_queue_wait_t));
    if (waiter == NULL) {
      se_scoop_trace("SCOOP internals: could not allocate waiter.");
      se_print_run_time_stack();
      exit(1);
    }

    waiter->subsystem = client;
    waiter->next = NULL;
    if (s->lock_waiters_count == 0) {
      s->lock_waiters_head = waiter;
      client->vft.unqueue_waiter_commit(client, subsystem);
    }
    else {
      s->lock_waiters_tail->next = waiter;
    }
    s->lock_waiters_tail = waiter;

    client->vft.wait_commit(client, subsystem);
    s->lock_waiters_count++;
  }
  scoop_check_call(pthread_mutex_unlock(&(s->modify_locker)));
}



static void
thread_signal(se_subsystem_t* subsystem, se_subsystem_t* provider) {

  se_subsystem_thread_t* s = (se_subsystem_thread_t*)subsystem;

#ifndef SE_BOOST
    se_scoop_debug("processor %s signals provider %p\n", subsystem->name, provider->name);
#endif

  scoop_check_call(pthread_mutex_lock(&(s->lock_signal_mutex)));
  {
    pthread_cond_signal(&(s->lock_signal_cond));
  }
  scoop_check_call(pthread_mutex_unlock(&(s->lock_signal_mutex)));
}



static void
thread_set_origin(se_subsystem_t* subsystem, se_origin_t* origin) {

  se_subsystem_thread_t* s = (se_subsystem_thread_t*)subsystem;

#ifndef SE_BOOST
    se_scoop_debug("processor %s sets origin to %lli\n", subsystem->name, origin == NULL ? 0 : origin->id);
#endif

  scoop_check_call(pthread_mutex_lock(&(s->modify_origin)));
  {
    s->origin = origin;
  }
  scoop_check_call(pthread_mutex_unlock(&(s->modify_origin)));
}



static se_origin_t*
thread_get_origin(se_subsystem_t* subsystem) {

  se_subsystem_thread_t* s = (se_subsystem_thread_t*)subsystem;
  se_origin_t*           result;
  scoop_check_call(pthread_mutex_lock(&(s->modify_origin)));
  {
    result = s->origin;
  }
  scoop_check_call(pthread_mutex_unlock(&(s->modify_origin)));
  return result;
}



static int
thread_must_wait_for_this_provider(se_subsystem_t* subsystem, se_subsystem_t* provider) {

  int result = 1;
  if (provider == subsystem) {
    result = 0;
  }
  else if (provider == NULL) {
    result = 0;
  }
  else {
    se_origin_t* sorigin = subsystem->vft.get_origin(subsystem);
    se_origin_t* porigin = provider->vft.get_origin(provider);
    if (sorigin != NULL && porigin != NULL) {
      if (sorigin->id == porigin->id) {
        result = 0;
      }
    }
  }

#ifndef SE_BOOST
    se_scoop_debug("processor %s must%s wait for provider %s\n", subsystem->name, result ? "" : " not", provider == NULL ? NULL : provider->name);
#endif

  return result;
}



static int
thread_must_wait_for_providers(se_subsystem_t* subsystem, se_subsystem_t** providers, int count) {

  int result = count;
  int i = count;
  while (i --> 0) {
    if (!thread_must_wait_for_this_provider(subsystem, providers[i])) result--;
  }
  return result;
}



static void
thread_wait_for_providers(se_subsystem_t* subsystem, se_subsystem_t** providers, int count) {

  se_subsystem_thread_t* s = (se_subsystem_thread_t*)subsystem;
  int real_count = count;

  scoop_check_call(pthread_mutex_lock(&(s->modify_lock_count)));
  {
    //scoop_check(s->lock_count == 0);
    //scoop_check(s->ready_lock_count == 0);
    s->lock_count = 0;
    s->ready_lock_count = 0;
  }
  scoop_check_call(pthread_mutex_unlock(&(s->modify_lock_count)));

  switch(count) {

  case 0:
    break;

  case 1:
    {
      if (thread_must_wait_for_this_provider(subsystem, providers[0])) {
        thread_wait(providers[0], subsystem);
      }
      else {
        real_count = 0;
      }
      break;
    }

  case 2:
    {
      if (!thread_must_wait_for_this_provider(subsystem, providers[1])) {
        if (thread_must_wait_for_this_provider(subsystem, providers[0])) {
          real_count = 1;
          thread_wait(providers[0], subsystem);
        }
        else {
          real_count = 0;
        }
      }
      else if (!thread_must_wait_for_this_provider(subsystem, providers[0])) {
        real_count = 1;
        thread_wait(providers[1], subsystem);
      }
      else if (providers[0] == providers[1]) {
        real_count = 1;
        thread_wait(providers[0], subsystem);
      }
      else {
        if (providers[0]->num < providers[1]->num) {
          thread_wait(providers[0], subsystem);
          thread_wait(providers[1], subsystem);
        }
        else {
          thread_wait(providers[1], subsystem);
          thread_wait(providers[0], subsystem);
        }
      }
      break;
    }

  default:
    {
      // Bubble search: TO BE OPTIMIZED
      int n = 0;
      int cur = 0;
      se_subsystem_t* next = NULL;
      do {
        int i;
        next = NULL;
        for (i = count; i --> 0; ) {
          if (providers[i] != subsystem) {
            if (providers[i]->num > cur) {
              if (next == NULL) next = providers[i];
              else if (providers[i]->num < next->num) next = providers[i];
            }
          }
        }
        if (next != NULL) {
          if (thread_must_wait_for_this_provider(subsystem, next)) {
            n++;
            thread_wait(next, subsystem);
          }
          cur = next->num;
        }
      } while (next != NULL);
      scoop_check(n <= count);
      real_count = n;
    }
  }

#ifndef SE_BOOST
  scoop_check_call(pthread_mutex_lock(&(s->modify_lock_count)));
  {
    scoop_check(s->lock_count == real_count);
  }
  scoop_check_call(pthread_mutex_unlock(&(s->modify_lock_count)));
#endif

  if (real_count > 0) {
    int ready_count;
    scoop_check_call(pthread_mutex_lock(&(s->modify_lock_count)));
    {
      ready_count = s->ready_lock_count;
    }
    scoop_check_call(pthread_mutex_unlock(&(s->modify_lock_count)));
    while (ready_count < real_count) {

      scoop_check_call(pthread_mutex_lock(&(s->lock_signal_mutex)));
      {
        pthread_cond_wait(&(s->lock_signal_cond), &(s->lock_signal_mutex));
      }
      scoop_check_call(pthread_mutex_unlock(&(s->lock_signal_mutex)));
      scoop_check_call(pthread_mutex_lock(&(s->modify_lock_count)));
      {
        ready_count = s->ready_lock_count;
      }
      scoop_check_call(pthread_mutex_unlock(&(s->modify_lock_count)));
    }
  }
}



static void
thread_unqueue_waiter(se_subsystem_t* subsystem, se_subsystem_t* client) {
  se_subsystem_thread_t* s = (se_subsystem_thread_t*)subsystem;
  se_queue_wait_t* waiter;
  se_subsystem_t* next_client;

#ifndef SE_BOOST
    se_scoop_debug("processor %s unqueues waiter %p\n", subsystem->name, client->name);
#endif

  scoop_check_call(pthread_mutex_lock(&(s->modify_locker)));
  {
    waiter = s->lock_waiters_head;
    scoop_check(waiter->subsystem == client);
    s->lock_waiters_head = waiter->next;
    s->lock_waiters_count--;
    if (s->lock_waiters_count <= 1) {
      s->lock_waiters_tail = s->lock_waiters_head;
    }

    if (s->lock_waiters_head != NULL) {
      // need to signal the next client it may grab the lock on that subsystem
      next_client = s->lock_waiters_head->subsystem;
      next_client->vft.unqueue_waiter_commit(next_client, subsystem);
      next_client->vft.signal(next_client, subsystem);
    }

    free(waiter);
  }
  scoop_check_call(pthread_mutex_unlock(&(s->modify_locker)));
}



static void
thread_unqueue_providers(se_subsystem_t* subsystem, se_subsystem_t** providers, int count) {

  switch(count) {

  case 0:
    break;

  case 1:
    {
      if (providers[0] != subsystem) {
        if (providers[0] != NULL) thread_unqueue_waiter(providers[0], subsystem);
      }
      break;
    }

  case 2:
    {
      if (providers[1] == subsystem) {
        if (providers[0] != subsystem) {
          if (providers[0] != NULL) thread_unqueue_waiter(providers[0], subsystem);
        }
      }
      else if (providers[0] == subsystem) {
        if (providers[1] != NULL) thread_unqueue_waiter(providers[1], subsystem);
      }
      else if (providers[0] == providers[1]) {
        if (providers[0] != NULL) thread_unqueue_waiter(providers[0], subsystem);
      }
      else {
        if (providers[0]->num > providers[1]->num) {
          if (providers[0] != NULL) thread_unqueue_waiter(providers[0], subsystem);
          if (providers[1] != NULL) thread_unqueue_waiter(providers[1], subsystem);
        }
        else {
          if (providers[1] != NULL) thread_unqueue_waiter(providers[1], subsystem);
          if (providers[0] != NULL) thread_unqueue_waiter(providers[0], subsystem);
        }
      }
      break;
    }

  default:
    {
      // Bubble search: TO BE OPTIMIZED
      // The unlock order is exactly opposite to the lock order
      int cur = 65535; // max. 65536 threads... NOT TESTED IN THE CODE!!
      se_subsystem_t* next = NULL;
      do {
        int i;
        next = NULL;
        for (i = count; i --> 0; ) {
          if (providers[i] != subsystem) {
            if (providers[i]->num < cur) {
              if (next == NULL) next = providers[i];
              else if (providers[i]->num > next->num) next = providers[i];
            }
          }
        }
        if (next != NULL) {
          thread_unqueue_waiter(next, subsystem);
          cur = next->num;
        }
      } while (next != NULL);
    }
  }
}



/* exported */ se_subsystem_t*
se_current_subsystem_thread() {

  se_subsystem_thread_t* result = NULL;
  se_subsystem_thread_t* current;
  pthread_t              self   = pthread_self();

  scoop_check_call(pthread_mutex_lock(&(se_thread_mutex)));
  {
    if (se_thread_memory != NULL) {
      if (pthread_equal(se_thread_memory->thread, self)) result = se_thread_memory;
    }
    if (result == NULL) {
      for (current = se_thread_system;
           (result == NULL) && (current != NULL);
           current = (se_subsystem_thread_t*)(current->super.next)) {
        if (pthread_equal(current->thread, self)) {
          result = current;
        }
      }
      se_thread_memory = result;
    }
  }
  scoop_check_call(pthread_mutex_unlock(&(se_thread_mutex)));

  if (result == NULL) {
    se_scoop_trace("Current thread not found!");
    exit(1);
  }
  return (se_subsystem_t*)result;
}



/* --[Internals]--------------------------------------------------------- */

/*
 * This implementation is really naive, leaving a lot of place to
 * optimisation.
 */



/**
 * The "main function" of a thread.
 */
static void*
se_run_thread(void* a) {

  se_subsystem_thread_t* subsystem = (se_subsystem_thread_t*)a;
  /*
   * The main loop.
   */
  while (!(subsystem->stop_processor && subsystem->queue_head == NULL)) {
    se_loop_thread(subsystem);
  }
  scoop_delete_subsystem(subsystem);
  return NULL;
}



/**
 * One step of the main loop of a thread.
 */
static void
se_loop_thread(se_subsystem_thread_t* subsystem) {

  se_message_t* message;
  int termination_case;

  /*
   * First of all, let's wait for a command to have been posted by
   * thread_command() or thread_query()
   */
  scoop_check_call(pthread_mutex_lock(&(subsystem->message_queue_mutex.mutex)));
  {
    if (subsystem->message_queue_mutex.count == 0) {
#ifndef SE_BOOST
      se_scoop_debug("processor %s waits for a message\n", subsystem->super.name);
#endif
      scoop_check_call(pthread_cond_wait(&(subsystem->message_queue_mutex.cond), &(subsystem->message_queue_mutex.mutex)));
    }
    /*
     * Get the message from the queue.
     */
    message = subsystem->queue_head;
#ifndef SE_BOOST
      se_scoop_debug("processor %s got a message\n", subsystem->super.name);
#endif
  }
  scoop_check_call(pthread_mutex_unlock(&(subsystem->message_queue_mutex.mutex)));

  /*
   * Termination case, see below. It is the only case when the message queue
   * will be empty.
   */
  if (subsystem->stop_processor) {
    scoop_check(message == NULL);
#ifndef SE_BOOST
    se_scoop_debug("processor %s must stop\n", subsystem->super.name);
#endif
  }
  else {
    termination_case = se_execute_message(subsystem, message, NULL);

    if (termination_case) {
#ifndef SE_BOOST
      se_scoop_debug("processor %s detects a termination case\n", subsystem->super.name);
#endif
      scoop_check_call(pthread_mutex_lock(&(se_thread_mutex)));
      {
        /*
         * No more threads waiting for work: we must now stop the application
         * (termination case) by telling every processor to stop.
         *
         * Hence we have a graceful termination. Each processor releases its own
         * resources, and the program stops by itself.
         */
        se_subsystem_thread_t* s    = se_thread_system;
        pthread_t              self = pthread_self();
        while (s != NULL) {
          /*
           * We ask the processor to stop. See above the test of this variable.
           */
          s->stop_processor = 1;
          if (!pthread_equal(self, s->thread)) {
            /*
             * Then we signal the thread to stop itself by signaling its queue lock.
             */
#ifndef SE_BOOST
            se_scoop_debug("processor %s signals %s to stop\n", subsystem->super.name, s->super.name);
#endif
            scoop_check_call(pthread_cond_signal(&(s->message_queue_mutex.cond)));
          }
          s = (se_subsystem_thread_t*)(s->super.next);
        }
        scoop_check(subsystem->stop_processor);
      }
      scoop_check_call(pthread_mutex_unlock(&(se_thread_mutex)));
    }
  }
}



/**
 * Executes the message and unlinks it. `previous' must be either NULL or the
 * previous message
 *
 * @pre previous == NULL || previous->next == message
 * @return non-zero if the termination case is reached.
 */
static int
se_execute_message(se_subsystem_thread_t* subsystem, se_message_t* message, se_message_t* previous) {

  int result = 0;
  se_message_t* next;
  se_origin_thread_t* origin;
  se_origin_t* save_origin;
  int is_query;

  scoop_check(message != NULL);
#ifndef SE_BOOST
  scoop_check(!message->is_free);
#endif
  scoop_check(message == ((previous == NULL) ? subsystem->queue_head : previous->next));

#ifndef SE_BOOST
  se_scoop_debug("processor %s executes a message\n", subsystem->super.name);
#endif

  save_origin = thread_get_origin(&(subsystem->super));
  origin = (se_origin_thread_t*)message->origin;
  if (origin != NULL) {
    thread_set_origin(&(subsystem->super), &(origin->super));
    scoop_check_call(pthread_mutex_lock(&(origin->modify)));
    {
      origin->super.ref_count++;
    }
    scoop_check_call(pthread_mutex_unlock(&(origin->modify)));
  }

  next = message->next;

  /*
   * Now we may call the wrapped Eiffel method.
   */
  if (message->result == NULL) {
    // COMMAND:
#ifndef SE_BOOST
  se_scoop_debug("processor %s executes a command\n", subsystem->super.name);
#endif
    is_query = 0;
    message->agent(message->data, message->length, NULL);
    se_free_message(message);
  }
  else {
    // QUERY:
    is_query = 1;
#ifndef SE_BOOST
  se_scoop_debug("processor %s executes a query\n", subsystem->super.name);
#endif
    message->agent(message->data, message->length, message->result);
    // The message is not freed now; it will eventually be by the
    // thread_query() function when its result_available flag (set below) is
    // read.
  }

  thread_set_origin(&(subsystem->super), save_origin);
  if (origin != NULL) {
    int destroy=0;
    scoop_check_call(pthread_mutex_lock(&(origin->modify)));
    {
      origin->super.ref_count--;
      destroy=(origin->super.ref_count==0);
    }
    scoop_check_call(pthread_mutex_unlock(&(origin->modify)));
    scoop_check(!destroy);
    if (destroy) se_free_origin(origin);
  }

  /*
   * Unqueue the message structure.
   */
  scoop_check_call(pthread_mutex_lock(&(subsystem->message_queue_mutex.mutex)));
  {
    if (previous == NULL) {
      subsystem->queue_head = next;
    }
    else {
      previous->next = next;
    }
    subsystem->message_queue_mutex.count--;
    if (subsystem->message_queue_mutex.count <= 1) {
      subsystem->queue_tail = subsystem->queue_head;
    }

    scoop_check(subsystem->message_queue_mutex.count >= 0);
    scoop_check((subsystem->message_queue_mutex.count > 0) || (subsystem->queue_head == NULL));
    scoop_check((subsystem->message_queue_mutex.count == 0) || (subsystem->queue_head != NULL));

    /*
     * Decrease the number of active subsystems. If this number reaches zero,
     * and the current queue is empty (see above), then the program must
     * terminate.
     */
    scoop_check_call(pthread_mutex_lock(&(se_thread_mutex)));
    {
      result = (--se_thread_count == 0);
    }
    scoop_check_call(pthread_mutex_unlock(&(se_thread_mutex)));
  }
  scoop_check_call(pthread_mutex_unlock(&(subsystem->message_queue_mutex.mutex)));

  if (is_query) {
#ifndef SE_BOOST
    se_scoop_debug("processor %s makes the result available\n", subsystem->super.name);
#endif
    /* Tell the thread that the result is available */
    message->result_available = 1;
    scoop_check(message->client != NULL);
    scoop_check_call(pthread_mutex_lock(&(message->client->message_queue_mutex.mutex)));
    {
      scoop_check_call(pthread_cond_signal(&(message->client->message_queue_mutex.cond)));
    }
    scoop_check_call(pthread_mutex_unlock(&(message->client->message_queue_mutex.mutex)));
  }

  return result;
}



// ----------------------------------------------------------------------



static se_subsystem_thread_t*
scoop_create_subsystem(char* name) {
  se_subsystem_thread_t* new = (se_subsystem_thread_t*)malloc(sizeof(se_subsystem_thread_t));

  if (new == NULL) {
    se_scoop_trace("Internal error in scoop.c: could not malloc scoop context");
    se_print_run_time_stack();
    exit(1);
  }

#ifndef SE_BOOST
  new->super.id = SCOOP_TYPE_THREAD;
#endif

  scoop_check_call(pthread_mutex_init(&new->message_queue_mutex.mutex, NULL));
  scoop_check_call(pthread_cond_init(&new->message_queue_mutex.cond, NULL));
  new->message_queue_mutex.count = 0;

  scoop_check_call(pthread_mutex_init(&new->modify_count, NULL));
#ifndef SE_BOOST
  scoop_check_call(pthread_mutex_init(&new->modify_ds, NULL));
#endif

  scoop_check_call(pthread_mutex_init(&new->modify_origin, NULL));

  new->count          = 0; /* SmartEiffel manages this counter, therefore it is initialized to zero */
  new->queue_head     = NULL;
  new->queue_tail     = NULL;
  new->stop_processor = 0;
  new->super.name     = name;
  new->lock_count     = 0;
  new->locker         = NULL;
#ifndef SE_BOOST
  new->print_dst      = 0;
#endif
  new->once_head      = NULL;
  new->once_memory    = NULL;

  new->lock_waiters_head  = NULL;
  new->lock_waiters_tail  = NULL;
  new->lock_waiters_count = 0;

  new->origin             = NULL;

  scoop_check_call(pthread_mutex_lock(&(se_thread_mutex)));
  {
    /*
     * This check (below) means that either the system is not yet initialized
     * (and will be whenever a message is sent) either the number of working
     * threads is not null. Obviously if no thread is working, no new thread
     * should be created and the system should halt.
     */
    scoop_check((!se_system_init_done) || (se_thread_count > 0));

    new->super.next = &(se_thread_system->super);
    se_thread_system = new;
  }
  scoop_check_call(pthread_mutex_unlock(&(se_thread_mutex)));

  return new;
}



static void
scoop_delete_subsystem(se_subsystem_thread_t* subsystem) {

  /*
   * First we remove the subsystem from the system.
   */
  scoop_check_call(pthread_mutex_lock(&(se_thread_mutex)));
  {
    se_subsystem_t* s;

    if (subsystem == se_thread_system) {
      se_thread_system = (se_subsystem_thread_t*)subsystem->super.next;
    }
    else {
      s = &(se_thread_system->super);
      while (s->next != &(subsystem->super)) {
        s = s->next;
      }
      s->next = subsystem->super.next;
    }
  }
  scoop_check_call(pthread_mutex_unlock(&(se_thread_mutex)));

  /*
   * Now we destroy the resources associated to the subsystem.
   */
  scoop_check_call(pthread_mutex_destroy(&subsystem->message_queue_mutex.mutex));
  scoop_check_call(pthread_cond_destroy(&subsystem->message_queue_mutex.cond));

  scoop_check_call(pthread_mutex_destroy(&subsystem->modify_count));
#ifndef SE_BOOST
  scoop_check_call(pthread_mutex_destroy(&subsystem->modify_ds));
#endif

  /*
   * Now we destroy its local once objects.
   */
  {
    se_thread_once_t* once = subsystem->once_head;
    while (once != NULL) {
      se_thread_once_t* next = once->next;
#ifdef GC_LIB
      // HOW DO I CALL THE DESTRUCTION ROUTINE OF THE GC?
      // (to free once->once)
#endif
      free(once);
      once=next;
    }
  }

  /*
   * And at last we free the subsystem structure. End of story.
   */
  free(subsystem);
}

//@}
