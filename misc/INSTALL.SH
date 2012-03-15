#!/bin/sh
#
# To INSTALL SmartEiffel on UNIX like platforms (including LINUX).
#
# If you have the gcc compiler, simply run this script.
#
sed=${SmartEiffel:=1}
if [ ${sed} = 1 ];  then 
   echo Please set the environment Variable \'SmartEiffel\' with
   echo the absolute path of file SmartEiffel/sys/system.se
   exit 1
fi
if [ -d ${SmartEiffel} ]; then 
   echo Since release -0.79 the value of the environment
   echo variable SmartEiffel should be the absolute path of
   echo file SmartEiffel/sys/system.se
   echo Trying to fix this automatically.
   SmartEiffel=${SmartEiffel}/sys/system.se
fi
if [ ! -f ${SmartEiffel} ]; then
   echo File ${SmartEiffel} not found.
   echo Please check the value of the environment Variable
   echo \'SmartEiffel\' wich must be the absolute path of 
   echo the file SmartEiffel/sys/system.se
   exit 1
fi
SE=`dirname $SmartEiffel`
SE=`dirname $SE`
if [ -f ${SE} ]; then
   echo ${SE} "not found."
   exit 1
fi
echo "Running the new installation procedure :"
echo "    " cd ${SE}
echo "    " make
echo "    "
cd ${SE}
make
echo Done.
