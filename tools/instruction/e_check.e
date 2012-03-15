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
class E_CHECK
   --
   -- Instruction "check ... end;".
   --

inherit INSTRUCTION

creation make

feature

   end_mark_comment: BOOLEAN is True

   side_effect_free: BOOLEAN is
      do
	 Result := ace.boost
      end
      
   start_position: POSITION is
         -- Of keyword "check".
      do
         if check_invariant /= Void then
            Result := check_invariant.start_position
         end
      end

   to_runnable(ct: E_TYPE): like Current is
      do
	 if current_type = Void then
	    current_type := ct
	    if ct.base_class.all_check then
	       all_check := True
	       if check_invariant /= Void then
		  check_invariant := check_invariant.to_runnable(ct)
	       end
	    end
	    Result := Current
	 else
	    !!Result.make(start_position,Void,check_invariant.list)
	    Result := Result.to_runnable(ct)
	 end
      end

   stupid_switch(run_time_set: RUN_TIME_SET): BOOLEAN is
      do
         Result := True
      end

   afd_check is
      do
         if all_check and then check_invariant /= Void then
            check_invariant.afd_check
         end
      end

   safety_check is
      do
         check False end
      end

   simplify_2(container: COMPOUND; index: INTEGER) is
      do
	 if ace.boost then
	    container.remove(index)
	 end
      end

   collect_c_tmp is
      do
      end

   compile_to_c is
      do
         if all_check and then check_invariant /= Void then
            check_invariant.compile_to_c
         end
      end

   compile_to_jvm is
      do
         if all_check and then check_invariant /= Void then
            check_invariant.compile_to_jvm(True)
            code_attribute.opcode_pop
         end
      end

   once_pre_computable: BOOLEAN is
      do
	 Result := ace.boost
      end

   use_current: BOOLEAN is
      do
         if all_check and then check_invariant /= Void then
            Result := check_invariant.use_current
         end
      end

   pretty_print is
      do
         if check_invariant /= Void then
            check_invariant.pretty_print
            pretty_printer.keyword(fz_end)
            if pretty_printer.print_end_of_statement then
               pretty_printer.put_end_of(fz_check)
            end
         end
      end

feature {COMPOUND,INSTRUCTION_WITH_COMMENT}

   verify_scoop(allowed: FORMAL_ARG_LIST) is
      do
         if check_invariant /= Void then
            check_invariant.verify_scoop(allowed)
         end
      end

feature {E_CHECK_VISITOR}

   accept(visitor: E_CHECK_VISITOR) is
      do
         visitor.visit_e_check(Current)
      end

feature {NONE}

   check_invariant: CHECK_INVARIANT

   current_type: E_TYPE

   all_check: BOOLEAN

   make(sp: like start_position; hc: COMMENT; l: FAST_ARRAY[ASSERTION]) is
      require
         not sp.is_unknown
      do
         if hc /= Void or else l /= Void then
            create check_invariant.make(sp, hc, l)
         end
      end

end -- E_CHECK
