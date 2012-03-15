#!/bin/csh -f
#
# To INSTALL SmartEiffel on UNIX like platforms (including LINUX).
#
# If you have the gcc compiler, simply run this script.
#
if (!($?SmartEiffel)) then
   echo Please set the environment Variable 'SmartEiffel' with
   echo the absolute path of file SmartEiffel/sys/system.se
   exit 1
endif
if (-d $SmartEiffel) then
   echo Since release -0.79 the value of the environment
   echo variable SmartEiffel should be the absolute path of
   echo file SmartEiffel/sys/system.se
   echo Trying to fix this automatically.
   set SmartEiffel=${SmartEiffel}/sys/system.se
endif
if (! -f ${SmartEiffel}) then
   echo File ${SmartEiffel} not found.
   echo Please check the value of the environment Variable
   echo 'SmartEiffel' wich must be the absolute path of 
   echo the file SmartEiffel/sys/system.se
   exit 1
endif
if (`basename $SmartEiffel` != "system.se") then
   echo Please check the value of the environment Variable
   echo 'SmartEiffel' wich must be the absolute path of 
   echo the file SmartEiffel/sys/system.se
   exit 1
endif
set SE=`dirname $SmartEiffel`
set SE=`dirname $SE`
if (! -d ${SE}) then
   echo SmartEiffel home directory ${SE} not found.
   echo Please check the value of the environment Variable
   echo 'SmartEiffel' wich must be the absolute path of 
   echo the file SmartEiffel/sys/system.se
   exit 1
endif
echo "Running the new installation procedure :"
echo "    " cd ${SE}
echo "    " make
echo "    "
cd ${SE}
make
echo Done.
