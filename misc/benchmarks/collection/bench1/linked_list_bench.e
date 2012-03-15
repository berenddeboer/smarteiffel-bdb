--          This file is part of SmartEiffel The GNU Eiffel Compiler.
--          Copyright (C) 1994-98 LORIA - UHP - CRIN - INRIA - FRANCE
--            Dominique COLNET and Suzanne COLLIN - colnet@loria.fr
--                       http://SmartEiffel.loria.fr
-- SmartEiffel is  free  software;  you can  redistribute it and/or modify it
-- under the terms of the GNU General Public License as published by the Free
-- Software  Foundation;  either  version  2, or (at your option)  any  later
-- version. SmartEiffel is distributed in the hope that it will be useful,but
-- WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
-- or  FITNESS FOR A PARTICULAR PURPOSE.   See the GNU General Public License
-- for  more  details.  You  should  have  received a copy of the GNU General
-- Public  License  along  with  SmartEiffel;  see the file COPYING.  If not,
-- write to the  Free Software Foundation, Inc., 59 Temple Place - Suite 330,
-- Boston, MA 02111-1307, USA.
--
class LINKED_LIST_BENCH

inherit BENCH;

creation make

feature

   make is
      local
         link_list: LINKED_LIST[INTEGER];
         i: INTEGER;
      do
         from
            !!link_list.make;
            i := count;
         until
            i = 0
         loop
            link_list.add_first(0);
            i := i - 1;
         end;
         bench(link_list);
      end;

end -- LINKED_LIST_BENCH
