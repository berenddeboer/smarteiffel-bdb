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
class CALL_PREFIX_FREEOP
   --
   --   Prefix free operator : "@...", "#...", "|...", "&..."
   --

inherit CALL_PREFIX

creation {EIFFEL_PARSER} make

creation {CALL_PREFIX} with

feature

   precedence: INTEGER is 11

   side_effect_free: BOOLEAN is False

   operator: STRING is
      do
         Result := feature_name.to_string
      end

   isa_dca_inline_argument: INTEGER is
      do
      end

   dca_inline_argument(formal_arg_type: E_TYPE) is
      do
      end

   simplify_1_: EXPRESSION is
      do
	 Result := Current
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

feature {CALL_PREFIX_FREEOP_VISITOR}

   accept(visitor: CALL_PREFIX_FREEOP_VISITOR) is
      do
         visitor.visit_call_prefix_freeop(Current)
      end

feature {NONE}

   make(t: like target; pn: like feature_name) is
      require
         t /= Void
         pn.is_free_operator
      do
         target := t
         feature_name := pn
      end

invariant

   feature_name.is_free_operator
   
end -- CALL_PREFIX_FREEOP

