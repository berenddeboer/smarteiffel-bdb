-- This file is part of SmartEiffel The GNU Eiffel Compiler Tools and Libraries
--
-- SmartEiffel is  free software;  you can redistribute it and/or  modify it
-- under  the terms of the  GNU General Public License, as published by  the
-- Free Software Foundation; either version 2, or (at your option) any later
-- version.
-- SmartEiffel is distributed in the hope that it will be useful but WITHOUT 
-- ANY WARRANTY;  without  even the implied warranty  of MERCHANTABILITY  or
-- FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
-- more details.  You should have received a copy of  the GNU General Public
-- License along with SmartEiffel;  see the file COPYING.  If not,  write to
-- the Free Software Foundation,  Inc., 59 Temple Place - Suite 330,  Boston, 
-- MA 02111-1307, USA.
--
-- Copyright(C) 1994-2002: INRIA - LORIA (INRIA Lorraine) - ESIAL U.H.P.
--			   - University of Nancy 1 - FRANCE
-- Copyright(C) 2003:      INRIA - LORIA (INRIA Lorraine) - I.U.T. Charlemagne
--			   - University of Nancy 2 - FRANCE
--
--		 Dominique COLNET, Suzanne COLLIN, Olivier ZENDRA,
--			   Philippe RIBET, Cyril ADRIAN
--
-- http://SmartEiffel.loria.fr - SmartEiffel@loria.fr
--
class FEATURE_CLAUSE
   --
   -- The contents of a feature clause.
   --
   -- Note : for a `pretty' pretty_printing, it is necessary to store exactly
   --        the original contents (in the source file) of a feature clause.
   --

inherit
   GLOBALS
   VISITABLE

creation make

feature

   clients: CLIENT_LIST
         -- The `clients' allowed to use these features.

   comment: COMMENT
         -- The heading comment comming with the clause.

   pretty_print is
      local
         i: INTEGER
      do
         pretty_printer.set_indent_level(0)
         if not pretty_printer.zen_mode then
            pretty_printer.skip_one_line
         else
            pretty_printer.indent
         end
         pretty_printer.keyword(fz_feature)
         clients.pretty_print
         pretty_printer.set_indent_level(0)
         if comment /= Void then
            if pretty_printer.zen_mode then
            elseif pretty_printer.column > 15 then
               pretty_printer.set_indent_level(1)
               pretty_printer.indent
               pretty_printer.set_indent_level(0)
            end
            comment.pretty_print
            if not pretty_printer.zen_mode then
               pretty_printer.skip_one_line
            end
         end
         if list /= Void then
            from
               i := 0
            until
               i > list.upper
            loop
               pretty_printer.set_indent_level(1)
               pretty_printer.indent
               if not pretty_printer.zen_mode then
                  pretty_printer.skip_one_line
               end
               list.item(i).pretty_print
               i := i + 1
            end
         end
         pretty_printer.set_indent_level(0)
         if not pretty_printer.zen_mode then
            pretty_printer.skip_one_line
         end
      end

   start_position: POSITION is
      do
	 if clients /= Void then
	    Result := clients.start_position
	 end
      end

feature {FEATURE_CLAUSE_LIST}

   for_short(bcn: CLASS_NAME; sort: BOOLEAN; short_list: SHORT_LIST
	     rc: RUN_CLASS; client: CLASS_NAME) is
      local
         i: INTEGER; f: E_FEATURE; heading_done: BOOLEAN
      do
         if list /= Void then
	    if clients.gives_permission_to(client) then
               from
                  i := list.lower
               until
                  i > list.upper
               loop
                  f := list.item(i)
                  heading_done := f.names.for_short(Current, heading_done, bcn,
						    sort, short_list, rc, client)
                  i := i + 1
               end
            else
               error_handler.cancel
            end
         end
      end

feature {FEATURE_NAME_LIST}

   do_heading_for_short(bcn: CLASS_NAME) is
      do
         if comment = Void then
            short_print.hook_or("hook202","feature(s) from ")
            short_print.a_class_name(bcn)
            short_print.hook_or("hook203","%N")
         else
            short_print.hook_or("hook204","feature(s) from ")
            short_print.a_class_name(bcn)
            short_print.hook_or("hook205","%N")
            comment.short("hook206","   --","hook207","%N")
            short_print.hook_or("hook208","")
         end
      end

feature {FEATURE_CLAUSE_LIST}

   add_into(fd: HASHED_DICTIONARY[E_FEATURE,FEATURE_NAME]) is
      local
         i: INTEGER; f: E_FEATURE
      do
         if list /= Void then
            from
               i := 0
            until
               i > list.upper
            loop
               f := list.item(i)
               f.set_clients(clients)
               f.add_into(fd)
               i := i + 1
            end
         end
      end

feature {FEATURE_CLAUSE_VISITOR}

   accept(visitor: FEATURE_CLAUSE_VISITOR) is
      do
         visitor.visit_feature_clause(Current)
      end

   list: FAST_ARRAY[E_FEATURE]
         -- Only the features of the current clause. (Actually, this is useful 
         -- only for `pretty' because all features of a class are grouped in a 
         -- single HASHED_DICTIONARY (see BASE_CLASS).

feature {NONE}

   make(c: like clients; cm: COMMENT; l: like list) is
      require
         c /= Void
         l /= Void implies not l.is_empty
      do
         clients := c
         comment := cm
         list := l
      ensure
         clients = c
         comment = cm
         list = l
      end

invariant

   clients /= Void

   list /= Void implies not list.is_empty

end -- FEATURE_CLAUSE

