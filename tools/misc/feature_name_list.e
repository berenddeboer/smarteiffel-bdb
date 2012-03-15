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
class FEATURE_NAME_LIST
   --
   -- A list of FEATURE_NAME (simple feature names as well as infix or 
   -- prefix names).
   --

inherit
   GLOBALS
   VISITABLE

creation make_1, make_n

feature {FEATURE_NAME_LIST_VISITOR}

   accept(visitor: FEATURE_NAME_LIST_VISITOR) is
      do
         visitor.visit_feature_name_list(Current)
      end

feature

   first: FEATURE_NAME

   item(i: INTEGER): FEATURE_NAME is
      require
         i.in_range(1,count)
      do
         if i = 1 then
            Result := first
         else
            Result := remainder.item(i - 2)
         end
      ensure
         Result /= Void
      end

   count: INTEGER is
      do
         if remainder = Void then
            Result := 1
         else
            Result := remainder.upper + 2
         end
      end

   has(fn: FEATURE_NAME): BOOLEAN is
      require
         fn /= Void
      do
         Result := index_of(fn) > 0 
      end

   feature_name(fn_key: STRING): FEATURE_NAME is
      require
         fn_key = string_aliaser.item(fn_key)
      local
         i: INTEGER
      do
         if first.to_key = fn_key then
            Result := first
         elseif remainder = Void then
         else
            from
               i := remainder.upper
            until
               i < 0 or else fn_key = remainder.item(i).to_key
            loop
               i := i - 1
            end
            if i >= 0 then
               Result := remainder.item(i)
            end
         end
      end

   pretty_print is
      local
         i, icount: INTEGER
      do
         from i := 1 until i > count
         loop
            pretty_printer.set_indent_level(3)
            item(i).declaration_pretty_print
            i := i + 1
            icount := icount + 1
            if i <= count then
               pretty_printer.put_string(once ", ")
               if icount > 4 then
                  pretty_printer.set_indent_level(3)
                  pretty_printer.indent
                  icount := 0
               end
            end
         end
      end

   short is
      local
         i: INTEGER
      do
         from i := 1 until i > count
         loop
            item(i).short
            i := i + 1
            if i <= count then
               short_print.hook_or("fnl_sep",", ")
            end
         end
      end

feature {EIFFEL_PARSER}

   add_last(fn: FEATURE_NAME) is
      require
         fn /= Void
      local
         fn2: FEATURE_NAME
      do
         fn2 := feature_name(fn.to_key)
         if fn2 /= Void then
            fe_multiple(fn2,fn)
         end
         if remainder = Void then
            !!remainder.with_capacity(4)
         end
         remainder.add_last(fn)
      ensure
         count = 1 + old count
         item(count) = fn
      end

feature {FEATURE_CLAUSE}

   for_short(fc: FEATURE_CLAUSE; heading_done: BOOLEAN; bcn: CLASS_NAME
	     sort: BOOLEAN; short_list: SHORT_LIST; rc: RUN_CLASS
	     cn: CLASS_NAME): BOOLEAN is
      local
         i: INTEGER; fn: FEATURE_NAME; rf: RUN_FEATURE; f: E_FEATURE
      do
         Result := heading_done
         from
            i := 1
         until
            i > count
         loop
            fn := item(i)
            rf := rc.get_rf_with(fn)
            f := rf.base_feature
	    if f.obsolete_mark = Void then
	       if rf.clients.gives_permission_to(cn) then
		  if not short_list.has(rf) then
		     short_list.add_last(rf)
		     if not sort then
			if not Result then
			   Result := True
			   fc.do_heading_for_short(bcn)
			end
			short_list.do_print_of(rf)
		     end
		  end
               end
            end
            i := i + 1
         end
      end

feature {RUN_FEATURE_1}

   index_of(fn: FEATURE_NAME): INTEGER is
      require
         fn /= Void
      local
         fn_key: STRING
      do
         fn_key := fn.to_key
         if first.to_key = fn_key then
            Result := 1
         elseif remainder = Void then
         else
            from
               Result := remainder.upper
            until
               Result < 0 or else fn_key = remainder.item(Result).to_key
            loop
               Result := Result - 1
            end
            if Result < 0 then
               Result := 0
            else
               Result := Result + 2
            end
         end
      ensure
         Result.in_range(0,count)
         Result > 0 implies fn.to_key = item(Result).to_key
      end

feature {CREATION_CLAUSE}

   has_make: BOOLEAN is
	 -- Is the "make" name member of this list ?
      local
         i: INTEGER
      do
         from
            i := count
         until
            Result or else i = 0
         loop
            if item(i).to_string = as_make then
	       Result := True
	    end
	    i := i - 1
         end
      end

   root_creation_search(a_name: STRING): FEATURE_NAME is
      local
         i: INTEGER; fn: FEATURE_NAME
      do
         from
            i := count
         until
            i = 0 or else Result /= Void
         loop
            fn := item(i)
            if fn.to_string.is_equal(a_name) then
               Result := fn
            end
            i := i - 1
         end
      end

   short_for_creation is
      local
         i: INTEGER
      do
         from
            i := 1
         until
            i > count
         loop
            short_print.a_feature(item(i))
            i := i + 1
         end
      end

feature {NONE}

   remainder: FAST_ARRAY[FEATURE_NAME]
         -- Non Void when the list has more than one element.

   make_1(fn: FEATURE_NAME) is
      require
         fn /= Void
      do
         first := fn
      ensure
         count = 1
         item(1) = fn
      end

   make_n(list: FAST_ARRAY[FEATURE_NAME]) is
         -- Note: also check for multiple occurrences.
      require
         not list.is_empty
      local
         i, j: INTEGER
      do
         from
            i := list.upper
         until
            i < 0
         loop
            from
               j := i - 1
            until
               j < 0
            loop
               if list.item(i).to_key = list.item(j).to_key then
                  fe_multiple(list.item(i),list.item(j))
               end
               j := j - 1
            end
            i := i - 1
         end
         first := list.item(0)
         i := list.upper
         if i > 0 then
            from
               !!remainder.make(i)
               j := 0
            until
               i = 0
            loop
               remainder.put(list.item(j + 1),j)
               j := j + 1
               i := i - 1
            end
         end
      ensure
         count = list.count
      end

   fe_multiple(fn1, fn2: FEATURE_NAME) is
      do
         error_handler.add_position(fn1.start_position)
         error_handler.add_position(fn2.start_position)
         error_handler.append("Same feature name appears twice.")
	 error_handler.print_as_fatal_error
      end

invariant

   first /= Void

   remainder /= Void implies count = 1 + remainder.count

end -- FEATURE_NAME_LIST

