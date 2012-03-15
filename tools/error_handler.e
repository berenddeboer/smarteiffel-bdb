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
class ERROR_HANDLER
   --
   -- The unique `error_handler' object for Warning, Error and Fatal Error
   -- handling.
   -- This handler use an assynchronous strategy.
   --

inherit
   GLOBALS
   VISITABLE

feature

   error_counter, warning_counter: INTEGER
         -- Global counters.

   no_warning: BOOLEAN
	 -- To avoid warning messages.

   is_empty: BOOLEAN is
         -- True when nothing stored in `explanation' and `positions'.
      do
         Result := explanation.is_empty and then positions.is_empty
      end

   set_no_warning is
      do
         no_warning := True
      end

   append(s: STRING) is
	 -- Append text `s' to the current `explanation'.
      require
         not s.is_empty
      do
         explanation.append(s)
      ensure
         not is_empty
      end

   append_integer(i: INTEGER) is
	 -- Append integer `i' to the current `explanation'.
      do
         i.append_in(explanation)
      ensure
         not is_empty
      end

   extend(c: CHARACTER) is
	 -- Append `c' to the current `explanation'.
      do
         explanation.extend(c)
      ensure
         not is_empty
      end

   add_position(p: POSITION) is
	 -- If necessary, add `p' to the already known `positions'.
      do
         if p.is_unknown then
         else
            positions.add_last(p)
         end
      end

   add_type(t: E_TYPE; tail: STRING) is
      require
         t /= Void
      do
         append(once "Type ")
         if t.is_run_type then
            append(t.run_time_mark)
         else
            append(t.written_mark)
         end
         append(tail)
         add_position(t.start_position)
      end

   feature_not_found(fn: FEATURE_NAME) is
      require
         fn /= Void
      do
         add_position(fn.start_position)
         append(fz_09)
         append(fn.to_string)
         append(fz_not_found)
      end

   add_feature_name(fn: FEATURE_NAME) is
      require
         fn /= Void
      local
	 flag: BOOLEAN
      do
         add_position(fn.start_position)
	 if fn.is_infix_name then
	    append(fz_infix)
	    flag := True
	 elseif fn.is_prefix_name then
	    append(fz_prefix)
	    flag := True
	 end
	 if flag then append(" %"") end
	 append(fn.to_string)
	 if flag then extend('%"') end
      end

   add_context_info(ct: E_TYPE) is
      require
         ct.run_type = ct
      do
	 append(once " (The validation context is ")
	 append(ct.run_time_mark)
	 append(once " . The validation context is used to compute all %
		     %anchored type marks.)")
      end

   type_error(t1, t2: E_TYPE) is
      require
	 t1 /= Void; t2 /= Void
      do
	 add_type(t1,once " is not a kind of ")
	 add_type(t2,fz_dot_blank)
      ensure
	 not is_empty
      end

   print_as_warning is
         -- Print `explanation' as a Warning report.
         -- After printing, `explanation' and `positions' are reset.
      require
         not is_empty
      do
         if no_warning then
            cancel
         else
            do_print(once "Warning")
         end
         warning_counter := warning_counter + 1
      ensure
	 warning_counter = old warning_counter + 1
      end

   print_as_error is
         -- Print `explanation' as an Error report.
         -- After printing, `explanation' and `positions' are reset.
      require
         not is_empty
      do
         do_print(once "Error")
         error_counter := error_counter + 1
         if error_counter >= 6 then
            echo.w_put_string(fz_error_stars)
            echo.w_put_string(once "Too many errors.%N")
            die_with_code(exit_failure_code)
         end
      ensure
         error_counter = old error_counter + 1
      end

   print_as_fatal_error is
         -- Print `explanation' as a Fatal Error.
         -- Execution is stopped after this call.
      do
         do_print(once "Fatal Error")
         die_with_code(exit_failure_code)
      end

   cancel is
      -- Cancel a prepared report without printing it.
      do
         explanation.clear
         positions.clear
      ensure
         is_empty
      end

feature {ERROR_HANDLER_VISITOR}

   accept(visitor: ERROR_HANDLER_VISITOR) is
      do
         visitor.visit_error_handler(Current)
      end

feature {NONE}

   explanation: STRING is
         -- Current `explanation' text to be print with next Warning,
         -- the next Error or the next Fatal Error.
      once
         !!Result.make(1024)
      end

   positions: FIXED_ARRAY[POSITION] is
         -- The list of `positions' to be shown with next Warning,
         -- the next Error or the next Fatal Error.
      once
         create Result.with_capacity(16)
      end

   do_print(heading: STRING) is
      local
         i, cpt: INTEGER; cc, previous_cc: CHARACTER; p: POSITION
	 stop: BOOLEAN; class_name: STRING
	 -- TO_DO: we should be clever enought to be able to print 
	 -- each line only once when there are more than one position
	 -- on the very same line (by using more ^ on the same line).
      do
         echo.w_put_string(fz_error_stars)
         echo.w_put_string(heading)
         echo.w_put_character(':')
         echo.w_put_character(' ')
	 -- Removing extra space in explanation first (actually, they 
	 -- should not be there at all :-(
	 from
	    i := 1
	 until
	    i = 0
	 loop
	    i := explanation.substring_index(once "  ", 1)
	    if i /= 0 then
	       explanation.remove(i)
	    end
	 end
	 --
         from
            i := 1
            cpt := 9 + heading.count
         until
            i > explanation.count
         loop
            previous_cc := cc
            cc := explanation.item(i)
            i := i + 1
            if cpt > 60 then
               if cc = ' ' or else cc = '%N' then
                  echo.w_put_character('%N')
                  cpt := 0
               else
                  echo.w_put_character(cc)
                  cpt := cpt + 1
               end
            else
               echo.w_put_character(cc)
               inspect
                  cc
               when '%N' then
                  cpt := 0
               else
                  cpt := cpt + 1
               end
            end
         end
         echo.w_put_character('%N')
         from
         until
            positions.is_empty
         loop
            p := positions.first
	    positions.remove_first
	    if p.base_class_name = Void then
	       p.show
	    else
	       class_name := p.base_class_name.to_string
	       if not smart_eiffel.no_file_for(class_name) then
		  p.show
	       end
	    end
	    -- Removing the already printed one:
	    from
	       stop := False
	    until
	       stop
	    loop
	       i := positions.fast_index_of(p)
	       if positions.valid_index(i) then
		  positions.remove(i)
	       else
		  stop := True
	       end
            end
         end
         cancel
         echo.w_put_string(once "------%N")

         sedb_breakpoint
      ensure
         is_empty
      end

   singleton_memory: ERROR_HANDLER is
      once
	 Result := Current
      end

invariant

   is_real_singleton: Current = singleton_memory

end -- ERROR_HANDLER
