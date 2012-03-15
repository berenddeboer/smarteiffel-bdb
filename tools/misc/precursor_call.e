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
deferred class PRECURSOR_CALL
   --
   -- Handling of the `Precursor' construct. Common ancestor of
   -- PRECURSOR_CALL_EXPRESSION (when `Precursor' is inside a function call) and
   -- PRECURSOR_CALL_INSTRUCTION (when `Precursor' is inside a procedure call).
   --

inherit
   GLOBALS
   VISITABLE

feature {PRECURSOR_CALL_VISITOR}

   accept(visitor: PRECURSOR_CALL_VISITOR) is
      deferred
      end

feature

   use_current: BOOLEAN is True

   start_position: POSITION


   parent: CLASS_NAME
         -- {<CLASS_NAME>} to remove the ambiguity if any.

   frozen afd_check is
      do
         if arguments /= Void then
            arguments.afd_check
         end
      end

   frozen safety_check is
      do
         if arguments /= Void then
            arguments.safety_check
         end
      end

   frozen compile_to_c is
      do
         cpp.push_precursor(run_feature,arguments)
         run_feature.mapping_c
         cpp.pop
      end

   frozen pretty_print is
      do
         if parent /= Void then
            pretty_printer.put_character('{')
            parent.pretty_print
            pretty_printer.put_character('}')
         end
         pretty_printer.put_string(as_precursor)
         if arguments /= Void then
            pretty_printer.indent_level_increment
            arguments.pretty_print
            pretty_printer.indent_level_decrement
         end
         put_semi_colon
      end

   frozen compile_to_jvm is
      do
         jvm.push_precursor(run_feature,arguments)
         run_feature.mapping_jvm
         jvm.pop
      end

feature {NONE}

   current_type: E_TYPE

   arguments: EFFECTIVE_ARG_LIST

   run_feature: RUN_FEATURE
         -- Corresponding super feature.

   make(sp: like start_position; pc: like parent; pal: like arguments) is
      require
         not sp.is_unknown
      do
         start_position := sp
         parent := pc
         arguments := pal
      ensure
         start_position = sp
         parent = pc
         arguments = pal
      end

   super_feature(wrf: RUN_FEATURE): EFFECTIVE_ROUTINE is
         -- Gives the one to be called where `wrf' is the
         -- written runable feature which contains Current.
      require
         wrf /= Void
      local
         e_feature: E_FEATURE
         wbc: BASE_CLASS
         pl: PARENT_LIST
      do
         e_feature := wrf.base_feature
         wbc := e_feature.base_class
         pl := wbc.parent_list
         if pl = Void then
            error_handler.add_position(start_position)
            fatal_error("Precursor call is allowed only when the %
                        %enclosing routine is redefined.")
         else
            Result := pl.precursor_for(Current,wrf)
         end
      ensure
         Result /= Void
      end

   prepare_arguments(ct: E_TYPE) is
         -- Called after `super_feature' in order to prepare runnable `arguments'.
      require
         run_feature /= Void
      local
         a: like arguments
      do
         if arguments /= Void then
            a := arguments.to_runnable(ct)
            if a = Void then
	       error_handler.add_position(arguments.start_position)
	       error_handler.append(fz_bad_arguments)
	       error_handler.print_as_fatal_error
            else
               arguments := a
            end
	 end
	 smart_eiffel.argument_passing_check(start_position,
					     arguments,run_feature)
      end

   precursor_name(wfn: FEATURE_NAME; super: E_FEATURE): FEATURE_NAME is
      require
         wfn /= Void; super /= Void
      do
         create Result.precursor_name(super.base_class.id,wfn)
      ensure
	 Result.is_precursor_name
      end

   put_semi_colon is
      deferred
      end

end -- PRECURSOR_CALL
