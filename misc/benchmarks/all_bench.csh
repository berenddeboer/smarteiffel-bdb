#!/bin/csh -f
#
# Run this file for all the benchmarks
#
foreach bench (`find . -name "bench.csh" -print`)
   set dir =  $bench:h
   echo "Running benchmarks in $dir."
   pushd $dir >& /dev/null
   /bin/csh -f bench.csh
   popd >& /dev/null
end
