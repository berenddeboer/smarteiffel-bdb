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
  This file (SmartEiffel/sys/runtime/base.c) is included for _all_ modes of
  compilation (-boost, -no_check, ... -all_check, -debug_check).
*/

/*
  Byte swapping function
*/
void copy_swap_16(const uint16_t *src, uint16_t *dest, int count){
  while (count--) {
    *dest++ = (*src << 8) | (*src >> 8);
    src++;
  }
}


/*
  The wrapper for `malloc' (generated C code is supposed to use
  only `se_malloc' instead of direct `malloc').
*/
void* se_malloc(size_t size) {
  void *result = malloc(size);
  if (result == NULL) {
#ifdef SE_EXCEPTIONS
    internal_exception_handler(No_more_memory);
#elif !defined(SE_BOOST)
    error0("No more memory.", NULL);
#else
  fprintf(SE_ERR,"No more memory.\n");
  se_print_run_time_stack();
  exit(EXIT_FAILURE);
#endif
  }
  return result;
}

/*
  The wrapper for `calloc' (generated C code is supposed to use
  only `se_calloc' instead of direct `calloc').
*/
void* se_calloc(size_t nmemb, size_t size) {
  void *result = calloc(nmemb,size);
  if (result == NULL) {
#ifdef SE_EXCEPTIONS
    internal_exception_handler(No_more_memory);
#elif !defined(SE_BOOST)
    error0("No more memory.", NULL);
#else
  fprintf(SE_ERR,"No more memory.\n");
  se_print_run_time_stack();
  exit(EXIT_FAILURE);
#endif
  }
  return result;
}

/*
  The wrapper for `realloc' (generated C code is supposed to use
  only `se_realloc' instead of direct `realloc').
*/
void* se_realloc(void* src, size_t size) {
  void *result = realloc(src, size);
  if (result == NULL) {
#ifdef SE_EXCEPTIONS
    internal_exception_handler(No_more_memory);
#elif !defined(SE_BOOST)
    error0("No more memory.", NULL);
#else
  fprintf(SE_ERR,"No more memory.\n");
  se_print_run_time_stack();
  exit(EXIT_FAILURE);
#endif
  }
  return result;
}
