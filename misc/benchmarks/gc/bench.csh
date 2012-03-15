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
foreach dir ([A-Z]*)
   cd $dir
   if (-f bench.e) then
      set cmd="compile -clean bench.e make -no_split -boost -O3"
      $cmd 
      echo "$dir/bench.e : "
      time ./a.$ext 
      /bin/rm -f a.$ext
   endif
   cd ..
end
