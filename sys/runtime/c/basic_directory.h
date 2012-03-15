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
  This file (SmartEiffel/sys/runtime/basic_directory.h) is automatically
  included when some external "SmartEiffel" feature of class BASIC_DIRECTORY
  is live.
*/

#ifndef WIN32
#  include <dirent.h>
#endif
#ifndef WIN32
#  include <unistd.h>
#endif

EIF_POINTER basic_directory_open(EIF_POINTER path);
EIF_POINTER basic_directory_read_entry(EIF_POINTER dirstream);
EIF_POINTER basic_directory_get_entry_name(EIF_POINTER entry);
EIF_BOOLEAN basic_directory_close(EIF_POINTER dirstream);
#define basic_directory_current_working_directory (basic_directory_cwd())
EIF_POINTER basic_directory_cwd(void);
EIF_BOOLEAN basic_directory_chdir(EIF_POINTER destination);
EIF_BOOLEAN basic_directory_mkdir(EIF_POINTER directory_path);
EIF_BOOLEAN basic_directory_rmdir(EIF_POINTER directory_path);
