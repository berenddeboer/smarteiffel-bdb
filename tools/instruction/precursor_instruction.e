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
class PRECURSOR_INSTRUCTION
   --
   -- Handling of the `Precursor' procedure call.
   --

inherit PRECURSOR_CALL; INSTRUCTION

creation make

feature

   end_mark_comment: BOOLEAN is False

   side_effect_free: BOOLEAN is False
      
   once_pre_computable: BOOLEAN is False

   simplify_2(container: COMPOUND; index: INTEGER) is
      do
      end
   
   collect_c_tmp is
      do
         if arguments /= Void then
            arguments.collect_c_tmp
         end
      end

   to_runnable(ct: E_TYPE): like Current is
      local
         wrf: RUN_FEATURE; super: EFFECTIVE_ROUTINE; pn: FEATURE_NAME
      do
         if current_type = Void then
            current_type := ct
            Result := Current
            wrf := smart_eiffel.top_rf
            if wrf.result_type /= Void then
               error_handler.add_position(start_position)
               fatal_error("Inside a function, a Precursor call must %
                           %be a function call (not a procedure call).")
            end
            super := super_feature(wrf)
            pn := precursor_name(wrf.name,super)
	    run_feature := ct.run_class.at(pn)
	    if run_feature = Void then
	       !RUN_FEATURE_10!run_feature.make(ct,pn,super)
	    end
            prepare_arguments(ct)
         else
            !!Result.make(start_position,parent,arguments)
            Result := Result.to_runnable(ct)
         end
      end

   stupid_switch(run_time_set: RUN_TIME_SET): BOOLEAN is
      do
         Result := True
      end

feature {COMPOUND,INSTRUCTION_WITH_COMMENT}

   verify_scoop(allowed: FORMAL_ARG_LIST) is
      do
      end

feature {PRECURSOR_INSTRUCTION_VISITOR}

   accept(visitor: PRECURSOR_INSTRUCTION_VISITOR) is
      do
         visitor.visit_precursor_instruction(Current)
      end

feature {NONE}

   put_semi_colon is
      do
         if pretty_printer.semi_colon_flag then
            pretty_printer.put_character(';')
         end
      end

end -- PRECURSOR_INSTRUCTION
