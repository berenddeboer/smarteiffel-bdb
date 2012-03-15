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
deferred class ASSERTION_LIST
   --
   -- To store a list of assertions (see ASSERTION).
   --
   -- See also : CLASS_INVARIANT, E_REQUIRE, E_ENSURE,
   --            LOOP_INVARIANT and CHECK_INVARIANT.
   --

inherit
   GLOBALS
   VISITABLE

feature

   is_require: BOOLEAN is
      deferred
      end

   name: STRING is
         -- "require", "ensure" or "invariant".
      deferred
      end

   start_position: POSITION
         -- If any, the position of the first letter of `name'.

   header_comment: COMMENT

feature {ASSERTION_LIST, E_CHECK, E_FEATURE}

   list: FAST_ARRAY[ASSERTION]

feature

   verify_scoop(allowed: FORMAL_ARG_LIST) is
      local
         i: INTEGER
      do
         from
            i := list.upper
         until
            i < list.lower
         loop
            list.item(i).verify_scoop(allowed)
            i := i - 1
         end
      end

feature

   current_type: E_TYPE
         -- Not Void when checked in.

feature {NONE}

   run_feature: RUN_FEATURE
         -- Corresponding one (if any) when runnable.
         -- Note: class invariant are not inside a RUN_FEATURE.

feature

   set_current_type(ct: like current_type) is
      do
         current_type := ct
      end

   afd_check is
      local
         i: INTEGER
      do
         if list /= Void then
            from
               i := list.upper
            until
               i < list.lower
            loop
               list.item(i).afd_check
               i := i - 1
            end
         end
      end

feature {NONE}

   is_always_true: BOOLEAN is
      local
         i: INTEGER; assertion: ASSERTION
      do
         from
            i := list.upper
            Result := True
         until
            not Result or else i < list.lower
         loop
            assertion := list.item(i)
            Result := assertion.is_always_true
            i := i - 1
         end
      end

feature

   compile_to_c is
      local
         i: INTEGER; assertion: ASSERTION
      do
         if not is_always_true then
            c_set_flag
            from
               i := list.lower
            until
               i > list.upper
            loop
               assertion := list.item(i)
               if not is_require or else not smart_eiffel.scoop or else
		  not assertion.is_guard
		then
                  c_compile_assertion(assertion)
               end
               i := i + 1
            end
            c_clear_flag
         end
      end

   c_scoop is
         -- Make some C code if the assertion is a guard
      require
         smart_eiffel.scoop
         is_require
      local
         i: INTEGER; assertion: ASSERTION; flag_set: BOOLEAN
      do
         if not is_always_true then
            from
               i := list.lower
            until
               i > list.upper
            loop
               assertion := list.item(i)
               if assertion.is_guard then
                  if not flag_set then
                     c_set_flag
                     flag_set := True
                  end
                  c_compile_assertion(assertion)
               end
               i := i + 1
            end
            if flag_set then
               c_clear_flag
            end
         end
      end

   frozen compile_to_jvm(last_chance: BOOLEAN) is
         -- If `last_chance' is true, an error message is printed at
         -- run-time.
         -- The final result is always left a top of stack.
      local
         point_true, i: INTEGER; ca: like code_attribute
      do
         ca := code_attribute
         ca.check_opening
         from
            failure.clear
            i := list.lower
         until
            i > list.upper
         loop
            list.item(i).compile_to_jvm(last_chance)
            failure.add_last(ca.opcode_ifeq)
            i := i + 1
         end
         ca.opcode_iconst_1
         point_true := ca.opcode_goto
         ca.resolve_with(failure)
         ca.opcode_iconst_0
         ca.resolve_u2_branch(point_true)
         ca.check_closing
      end

   use_current: BOOLEAN is
      local
         i: INTEGER
      do
         if list /= Void then
            from
               i := list.upper
            until
               Result or else i < list.lower
            loop
               Result := list.item(i).use_current
               i := i - 1
            end
         end
      end

feature {NONE}

   make(sp: like start_position; hc: like header_comment; l: like list) is
      require
         l /= Void implies not l.is_empty
         hc /= Void or else l /= Void
      do
         start_position := sp
         header_comment := hc
         list := l
      ensure
         start_position = sp
         header_comment = hc
         list = l
      end

feature {NONE}

   make_runnable(sp: like start_position; l: like list
                 ct: like current_type; rf: like run_feature) is
      require
         not l.is_empty
         ct /= Void
      do
         start_position := sp
         list := l
         current_type := ct
         run_feature := rf
      ensure
         start_position = sp
         list = l
         current_type = ct
         run_feature = rf
      end

feature

   is_empty: BOOLEAN is
      do
         Result := list = Void
      end

   run_class: RUN_CLASS is
      do
         Result := current_type.run_class
      end

   frozen to_runnable(ct: E_TYPE): like Current is
      require
         ct.run_type = ct
      do
         if current_type = Void then
            current_type := ct
            run_feature := smart_eiffel.top_rf
            if list /= Void then
               list := assertion_collector.runnable(list,ct,run_feature, '_')
            end
            if nb_errors = 0 then
               Result := Current
            end
         else
            Result := twin
            Result.set_current_type(Void)
            Result := Result.to_runnable(ct)
         end
      ensure
         nb_errors = 0 implies Result /= Void
      end

   pretty_print is
      local
         i: INTEGER
      do
         pretty_printer.indent
         pretty_printer.keyword(name)
         pretty_printer.indent_level_increment
         if header_comment /= Void then
            header_comment.pretty_print
         else
            pretty_printer.indent
         end
         if list /= Void then
            from
               i := list.lower
            until
               i > list.upper
            loop
               if pretty_printer.zen_mode and i = list.upper then
                  pretty_printer.set_semi_colon_flag(False)
               else
                  pretty_printer.set_semi_colon_flag(True)
               end
               pretty_printer.indent
               list.item(i).pretty_print
               i := i + 1
            end
         end
         pretty_printer.indent_level_decrement
         pretty_printer.indent
      ensure
         pretty_printer.indent_level = old pretty_printer.indent_level
      end

   set_header_comment(hc: like header_comment) is
      do
         header_comment := hc
      end

feature {E_FEATURE, RUN_CLASS, ASSERTION_COLLECTOR}

   add_into(collector: FAST_ARRAY[ASSERTION]) is
      local
         i: INTEGER; a: ASSERTION
      do
         if list /= Void then
            from
               i := list.lower
            until
               i > list.upper
            loop
               a := list.item(i)
               if not collector.fast_has(a) then
                  collector.add_last(a)
               end
               i := i + 1
            end
         end
      end

feature {NONE}

   failure: FAST_ARRAY[INTEGER] is
      once
         !!Result.with_capacity(12)
      end

   check_assertion_mode: STRING is
      deferred
      end

feature {ONCE_ROUTINE_POOL, RUN_REQUIRE}

   clear_run_feature is
      do
         run_feature := Void
      end

feature {ASSERTION_LIST_VISITOR}

   accept(visitor: ASSERTION_LIST_VISITOR) is
      deferred
      end

feature {NONE}

   c_compile_assertion(assertion: ASSERTION) is
      local
         need_se_tmp: BOOLEAN
      do
         if assertion.is_always_true then
         else
            assertion.collect_c_tmp
            need_se_tmp := cpp.se_tmp_open_declaration
            cpp.set_check_assertion_mode(check_assertion_mode)
            assertion.compile_to_c
            if need_se_tmp then
               cpp.se_tmp_close_declaration
            end
         end
      end

   c_set_flag is
      do
	 -- Remove the `assertion_flag' stuff in boost'ed SCOOP guards
	 if ace.no_check then
	    if run_feature = Void then
	       cpp.put_string
	       (once "if(ds.fd->assertion_flag){%Nds.fd->assertion_flag=0;%N")
	    else
	       cpp.put_string
	       (once "if(fd.assertion_flag){%Nfd.assertion_flag=0;%N")
	    end
	 end
      end

   c_clear_flag is
      do
	 -- Remove the `assertion_flag' stuff in boost'ed SCOOP guards
	 if ace.no_check then
	    if run_feature = Void then
	       cpp.put_string(once "ds.fd->assertion_flag=1;%N}%N")
	    else
	       cpp.put_string(once "fd.assertion_flag=1;%N}%N")
	    end
	 end
      end

invariant

   list /= Void implies (not list.is_empty)

end -- ASSERTION_LIST
