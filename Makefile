#          This file is part of SmartEiffel The GNU Eiffel Compiler.
#       Copyright (C) 1994-2002 LORIA - INRIA - U.H.P. Nancy 1 - FRANCE
#          Dominique COLNET and Suzanne COLLIN - SmartEiffel@loria.fr
#                       http://SmartEiffel.loria.fr
# SmartEiffel is  free  software;  you can  redistribute it and/or modify it
# under the terms of the GNU General Public License as published by the Free
# Software  Foundation;  either  version  2, or (at your option)  any  later
# version. SmartEiffel is distributed in the hope that it will be useful,but
# WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
# or  FITNESS FOR A PARTICULAR PURPOSE.   See the GNU General Public License
# for  more  details.  You  should  have  received a copy of the GNU General
# Public  License  along  with  SmartEiffel;  see the file COPYING.  If not,
# write to the  Free Software Foundation, Inc., 59 Temple Place - Suite 330,
# Boston, MA 02111-1307, USA.
#
#
# Available targets:
#
#  - all         Starts the installer in automatic mode--use it if you know the
#                installer is smart enough to compute default values, and those
#                values suit your needs. The default values are known to be
#                correctly computed on Windows and Linux.
#
#  - interactive Starts the installer in interactive mode: use the menu to
#                install SmartEiffel
#
#  - elate       Starts the installer for ELATE systems
#
#  - openvms     Starts the installer for OpenVMS systems
#
#  - clean       Cleans the installation.

.SILENT:

all: ./install/germ/compile_to_c.h install.c
	gcc -o se_install install.c
	(echo ''; echo '4'; echo '5'; echo ''; echo '6') | ./se_install
	\rm -f ./se_install

interactive: ./install/germ/compile_to_c.h install.c
	gcc -o se_install install.c
	./se_install
	\rm -f ./se_install

clean:
	echo "Removing all executable tools..."
	\rm -f bin/*

elate: ./install/germ/compile_to_c.h install.c
	vpcc -o se_install install.c
	./se_install
	\rm -f ./se_install.00

openvms: [.install.germ]compile_to_c.h install.c
	cc/warning=disable=(embedcomment,longextern) install
	link/exe=se_install.exe install.obj
	mcr se_install
	delete se_install;
