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
class ASSERTION_COLLECTOR
   --
   -- Singleton object in charge of assertion lookup.
   -- This singleton is shared via the GLOBALS.`assertion_collector' once 
   -- function.
   --

inherit
   GLOBALS
   VISITABLE

creation make

feature {ASSERTION_COLLECTOR_VISITOR}

   accept(visitor: ASSERTION_COLLECTOR_VISITOR) is
      do
         visitor.visit_assertion_collector(Current)
      end

feature {NONE}

   processing_require: BOOLEAN
         -- When processing require collection only.

   header_comment: COMMENT

   make is
      do
      end

feature {RUN_CLASS}

   invariant_start is
         -- Called to start the collection of a class invariant.
      do
         collector.clear
         header_comment := Void
      end

   invariant_end(ct: E_TYPE): CLASS_INVARIANT is
         -- Called to finish the collection of `ct' class invariant.
      require
         ct /= Void
      local
         r: FAST_ARRAY[ASSERTION]; position: POSITION
      do
         r := runnable(collector, ct, Void, '_')
         if r /= Void then
            smart_eiffel.magic_count_increment
            position := ct.base_class.name.start_position
            create Result.make_runnable(position, r, ct, Void)
            Result.set_header_comment(header_comment)
         end
      end

feature {BASE_CLASS}

   invariant_add_last(ci: CLASS_INVARIANT) is
      require
         ci /= Void
      local
         hc2: COMMENT; bc, bc2: BASE_CLASS
      do
         ci.add_into(collector)
         hc2 := ci.header_comment
         if header_comment = Void then
            header_comment := hc2
         elseif hc2 = Void then
         else
            bc := header_comment.start_position.base_class
            bc2 := hc2.start_position.base_class
            if bc2 = bc or else bc2.is_subclass_of(bc) then
               header_comment := hc2
            end
         end
      end

   require_start is
         -- Called to start the collection of require assertions.
      do
         collector.clear
	 require_collector.clear
         header_comment := Void
         processing_require := True
      end

   require_end(rf: RUN_FEATURE; ct: E_TYPE): RUN_REQUIRE is
         -- Called to finish the collection of `ct' require assertion.
      require
         ct = rf.current_type
      local
         i, c: INTEGER; sp: POSITION; bc, bc1, bc2: BASE_CLASS; a: ASSERTION
	 r, r2: FAST_ARRAY[ASSERTION]; er, er1, er2: E_REQUIRE
      do
	 -- Checking require/require else:
	 c := require_collector.count
	 if c > 1 then
	    from
	       c := require_collector.upper
	       er2 := require_collector.item(c)
	       bc2 := er2.start_position.base_class
	    until
	       c = 0
	    loop
	       er1 := er2
	       bc1 := bc2
	       c := c - 1
	       er2 := require_collector.item(c)
	       bc2 := er2.start_position.base_class
	       if bc1 = bc2 then
	       elseif bc2.name.to_string = as_general then
	       elseif bc2.is_subclass_of(bc1) then
		  if not er2.is_require_else then
		     error_handler.append(once
	          "Keyword %"require%" replaced with %"require else%" %
		  %because there is an inherited require assertion. %
		  %(See next warning.)")
		     error_handler.add_position(er2.start_position)
		     error_handler.print_as_warning
		     error_handler.append(once
		  "This is the inherited require assertion. %
		  %(The one that can be weakened.)")
		     error_handler.add_position(er1.start_position)
		     error_handler.print_as_warning
		  end
	       end
	    end
	 end
	 --
	 processing_require := False
         r := runnable(collector, ct, rf, 'R')
         if r /= Void then
            from
               create r2.with_capacity(r.count)
               a := r.first
               r2.add_last(a)
               sp := a.start_position
               bc := sp.base_class
               i := 1
            until
               i > r.upper or else r.item(i).start_position.base_class /= bc
            loop
               r2.add_last(r.item(i))
               i := i + 1
            end
            !!er.make_runnable(sp, r2, ct, rf)
            !!Result.make(er)
            from
            until
               i > r.upper
            loop
               from
                  create r2.with_capacity(r.count)
                  a := r.item(i)
                  r2.add_last(a)
                  sp := a.start_position
                  bc := sp.base_class
                  i := i + 1
               until
                  i > r.upper or else
		  r.item(i).start_position.base_class /= bc
               loop
                  r2.add_last(r.item(i))
                  i := i + 1
               end
               create er.make_runnable(sp, r2, ct, rf)
               Result.add(er)
            end
         end
      end

   ensure_start is
         -- Called to start the collection of ensure assertions.
      do
         collector.clear
         ensure_collector.clear
         header_comment := Void
      end

   ensure_end(rf: RUN_FEATURE; ct: E_TYPE): E_ENSURE is
         -- Called to finish the collection of `ct' ensure assertion.
      require
         ct = rf.current_type
      local
         r: FAST_ARRAY[ASSERTION]; position: POSITION
	 c: INTEGER; ee1, ee2: E_ENSURE; bc1, bc2: BASE_CLASS
      do
	 -- Checking ensure/ensure then:
	 c := ensure_collector.count
	 if c > 1 then
	    from
	       c := ensure_collector.upper
	       ee2 := ensure_collector.item(c)
	       bc2 := ee2.start_position.base_class
	    until
	       c = 0
	    loop
	       ee1 := ee2
	       bc1 := bc2
	       c := c - 1
	       ee2 := ensure_collector.item(c)
	       bc2 := ee2.start_position.base_class
	       if bc1 = bc2 then
	       elseif bc2.name.to_string = as_general then
	       elseif bc2.is_subclass_of(bc1) then
		  if not ee2.is_ensure_then then
		     error_handler.append(once
	          "Keyword %"ensure%" replaced with %"ensure then%" %
		  %because there is an inherited ensure assertion. %
		  %(See next warning.)")
		     error_handler.add_position(ee2.start_position)
		     error_handler.print_as_warning
		     error_handler.append(once
		  "This is the inherited ensure assertion. %
		  %(The one that can be strengthened.)")
		     error_handler.add_position(ee1.start_position)
		     error_handler.print_as_warning
		  end
	       end
	    end
	 end
	 --
         r := runnable(collector, ct, rf, 'E')
         if r /= Void then
            position := ct.base_class.name.start_position
            create Result.make_runnable(position, r, ct, rf)
            Result.set_header_comment(header_comment)
         end
      end

   assertion_add_last(f: E_FEATURE) is
         -- To add some require/ensure assertion.
      local
         er: E_REQUIRE; ee: E_ENSURE
      do
         if processing_require then
            er := f.require_assertion
            if er /= Void then
               if header_comment = Void then
                  header_comment := er.header_comment
               end
               er.add_into(collector)
	       require_collector.add_last(er)
            end
         else
            ee := f.ensure_assertion
            if ee /= Void then
               if header_comment = Void then
                  header_comment := ee.header_comment
               end
               ee.add_into(collector)
	       ensure_collector.add_last(ee)
            end
         end
      end

feature {ASSERTION_LIST}

   runnable(collected: FAST_ARRAY[ASSERTION]; ct: E_TYPE; for: RUN_FEATURE
            assertion_check_tag: CHARACTER): FAST_ARRAY[ASSERTION] is
         -- Produce a runnable `collected'.
      require
         for /= Void implies ct = for.current_type
      local
         i: INTEGER; a: ASSERTION
      do
         if not collected.is_empty then
            from
               Result := collected.twin
               i := Result.upper
            until
               i < Result.lower
            loop
               smart_eiffel.push(for)
               a := Result.item(i).to_runnable(ct,assertion_check_tag)
               if a = Void then
                  error(Result.item(i).start_position,fz_bad_assertion)
               else
                  Result.put(a,i)
               end
               smart_eiffel.pop
               i := i - 1
            end
         end
      end

feature {NONE}
   
   collector: FAST_ARRAY[ASSERTION] is
      once
         create Result.with_capacity(12)
      end

   require_collector: FAST_ARRAY[E_REQUIRE] is
      once
         create Result.with_capacity(12)
      end

   ensure_collector: FAST_ARRAY[E_ENSURE] is
      once
         create Result.with_capacity(12)
      end

   singleton_memory: ASSERTION_COLLECTOR is
      once
         Result := Current
      end

invariant

   is_real_singleton: Current = singleton_memory

end -- ASSERTION_COLLECTOR
