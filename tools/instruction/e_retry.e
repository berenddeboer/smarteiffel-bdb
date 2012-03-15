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
class E_RETRY
   --
   -- To store instruction "retry" for exception handling.
   --

inherit INSTRUCTION

creation make

feature

   start_position: POSITION

   side_effect_free: BOOLEAN is False
      
   end_mark_comment: BOOLEAN is False

   once_pre_computable: BOOLEAN is False

   use_current: BOOLEAN is False

   afd_check is
      do
      end

   safety_check is
      do
      end

   simplify_2(container: COMPOUND; index: INTEGER) is
      do
      end

   collect_c_tmp is
      do
      end

   compile_to_c is
      do
         if ace.no_check then
            cpp.put_string(once "fd.assertion_flag=1;%Nfree_exception_frames();%N")
         end
         cpp.put_string(once "goto retry_tag;%N")
      end

   compile_to_jvm is
      do
         code_attribute.opcode_goto_backward( jvm.current_frame.jvm_try_begin )
      end

   to_runnable(ct: E_TYPE): like Current is
      local
         rf: RUN_FEATURE
      do
         rf := smart_eiffel.top_rf
         if run_feature = Void then
            run_feature := rf
            Result := Current
         elseif run_feature = rf then
            Result := Current
         else
            !!Result.make(start_position)
            Result := Result.to_runnable(ct)
         end
      end

   stupid_switch(run_time_set: RUN_TIME_SET): BOOLEAN is
      do
         Result := True
      end

   pretty_print is
      do
         pretty_printer.put_string(once "retry")
         if pretty_printer.semi_colon_flag then
            pretty_printer.put_character(';')
         end
      end

feature {COMPOUND,INSTRUCTION_WITH_COMMENT}

   verify_scoop(allowed: FORMAL_ARG_LIST) is
      do
      end

feature {E_RETRY_VISITOR}

   accept(visitor: E_RETRY_VISITOR) is
      do
         visitor.visit_e_retry(Current)
      end

feature {NONE}

   run_feature: RUN_FEATURE
         -- Corresponding one when runnable.

   make(sp: like start_position) is
      do
         start_position := sp
      end

end -- E_RETRY

