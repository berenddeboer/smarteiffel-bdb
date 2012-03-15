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
  This file (SmartEiffel/sys/runtime/basic_io.h) is automatically
  included when some external "SmartEiffel" basic_io_* feature is used.
*/

#define basic_io_stdin (stdin)
#define basic_io_stdout (stdout)
#define basic_io_stderr (stderr)
#define basic_io_eof (EOF)
#define basic_io_text_file_read_open(p) (fopen(((char*)(p)),"r"))
#define basic_io_text_file_write_open(p) (fopen(((char*)(p)),"w"))
#define basic_io_text_file_write_append(p) (fopen(((char*)(p)),"a"))
#define basic_io_text_file_read_write_open(p) (fopen(((char*)(p)),"r+"))
#define basic_io_text_file_read_write_append(p) (fopen(((char*)(p)),"a+"))
#define basic_io_binary_file_read_open(p) (fopen(((char*)(p)),"rb"))
#define basic_io_binary_file_write_open(p) (fopen(((char*)(p)),"wb"))
#define basic_io_binary_file_write_append(p) (fopen(((char*)(p)),"ab"))
#define basic_io_fclose(p) (fclose((FILE*)(p)))
#define basic_io_flush(p) (fflush((FILE*)(p)))
#define basic_io_getc(f) (getc(((FILE*)(f))))
#define basic_io_putc(b, f) (putc((b),((FILE*)(f))))
#define basic_io_fread(b, n, f) (fread((void *)(b),(size_t)(1), (size_t)(n),(FILE*)(f)))
#define basic_io_fwrite(b, n, f) (fwrite((void *)(b),(size_t)(1), (size_t)(n),(FILE*)(f)))
#define basic_io_feof(f) (feof(((FILE*)(f))))
#define basic_io_rename(o, n) (rename(((char*)(o)),((char*)(n))))
#define basic_io_remove(f) (remove(((char*)(f))))

#if defined __USE_POSIX || defined __unix__ || defined _POSIX_C_SOURCE
#  define basic_io_read_stdin(b, s) (read(STDIN_FILENO, b, s))
#else
  extern int basic_io_read_stdin(char *buffer, int size);
#endif

