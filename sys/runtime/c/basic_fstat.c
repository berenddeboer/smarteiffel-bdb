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
  This file (SmartEiffel/sys/runtime/basic_fstat.c) is automatically
  included when some external "SmartEiffel" basic_fstat_* feature is used.
*/

EIF_INTEGER basic_fstat_st_size(EIF_POINTER path) {
  struct stat buf;

  stat(path,&buf);
  return buf.st_size;
}

EIF_INTEGER_64 basic_fstat_st_mtime(EIF_POINTER path) {
  struct stat buf;

  stat(path,&buf);
  return buf.st_mtime;
}

EIF_BOOLEAN basic_fstat_st_all (EIF_POINTER path,
                         EIF_INTEGER_32 *dev,
                         EIF_INTEGER_64 *inode,
                         EIF_INTEGER_32 *mode,
                         EIF_INTEGER_32 *nlink,
                         EIF_INTEGER_32 *uid,
                         EIF_INTEGER_32 *gid,
                         EIF_INTEGER_64 *size,
                         EIF_INTEGER *atime,
                         EIF_INTEGER *ctime,
                         EIF_INTEGER *mtime
                          ) {

  EIF_BOOLEAN result;
#ifdef __USE_LARGEFILE64
  struct stat64 buf;
  result = stat64(path,&buf) == 0;
#else
  struct stat buf;
  result = stat(path,&buf) == 0;
#endif
  *dev = buf.st_dev;
  *inode = buf.st_ino;
  *mode = buf.st_mode;
  *nlink = buf.st_nlink;
  *uid = buf.st_uid;
  *gid = buf.st_gid;
  *size = buf.st_size;
  *atime = buf.st_atime;
  *ctime = buf.st_ctime;
  *mtime = buf.st_mtime;
  return result;
}
