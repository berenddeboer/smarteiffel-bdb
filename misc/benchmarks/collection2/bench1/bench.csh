#!/bin/csh -f
#
# Run this file to have a comparison 
#
set os=`uname -s | cut -c1-6`
if ("x$os" == "xCYGWIN") then
  set ext = "exe"
else
  set ext = "out"
endif
foreach b (*_bench.e)
   set cmd="compile -clean $b make -no_split -boost -O3"
   $cmd 
   echo "$b : "
   time ./a.$ext 
   /bin/rm -f a.$ext
end
