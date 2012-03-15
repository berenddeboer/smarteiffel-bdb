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
class CALL_INFIX_FREEOP
   --
   --   Infix free operator : "@...", "#...", "|...", "&..."
   --

inherit CALL_INFIX1

creation {EIFFEL_PARSER} make

creation {CALL_INFIX} with

feature

   precedence: INTEGER is 10

   left_brackets: BOOLEAN is False

   isa_dca_inline_argument: INTEGER is 0

   operator: STRING is
      do
         Result := feature_name.to_string
      end

   dca_inline_argument(formal_arg_type: E_TYPE) is
      do
      end

   simplify_1_: EXPRESSION is
      do
	 -- *** TODO: shift operation on INTEGERs. ***
	 Result := Current
      end

   compile_to_c is
      do
         call_proc_call_c2c
      end

   compile_to_jvm is
      do
         call_proc_call_c2jvm
      end

   jvm_branch_if_false: INTEGER is
      do
         Result := jvm_standard_branch_if_false
      end

   jvm_branch_if_true: INTEGER is
      do
         Result := jvm_standard_branch_if_true
      end

feature {CALL_INFIX_FREEOP_VISITOR}

   accept(visitor: CALL_INFIX_FREEOP_VISITOR) is
      do
         visitor.visit_call_infix_freeop(Current)
      end

feature {NONE}

   make(lp: like target; in: like feature_name; rp: like arg1) is
      require
         lp /= Void
         in.is_free_operator
         rp /= Void
      do
         target := lp
         feature_name := in
         create arguments.make_1(rp)
      ensure
         target = lp
         feature_name = in
         arguments.first = rp
      end

invariant

   feature_name.is_free_operator

end -- CALL_INFIX_FREEOP

