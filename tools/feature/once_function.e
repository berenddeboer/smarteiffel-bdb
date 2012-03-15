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
class ONCE_FUNCTION

inherit ONCE_ROUTINE

creation make

feature

   result_type: E_TYPE

   to_run_feature(t: E_TYPE; fn: FEATURE_NAME): RUN_FEATURE_6 is
      do
         create Result.make(t, fn, Current)
      end

   once_pre_computable: BOOLEAN is
	 -- Purely static computation (only really simple once functions are 
	 -- actually pre-computable).
      local
	 bc: like base_class
      do
	 inspect
	    once_pre_computable_memory
	 when 0 then
	    once_pre_computable_memory := 1
	    bc := base_class
	    if ((not bc.require_check) or else require_assertion = Void)
	       and then
	       ((not bc.ensure_check) or else ensure_assertion = Void)
	       and then
	       (rescue_compound = Void)
	     then
	       if routine_body = Void then
		  Result := True
	       else
		  Result := routine_body.once_pre_computable
	       end
	    end
	    if Result then
	       once_pre_computable_memory := 3
	    else
	       once_pre_computable_memory := 2
	    end
	 when 1 then
	    once_pre_computable_memory := 2
	 when 2 then
	 when 3 then
	    Result := True
	 end
      end
   
feature {ONCE_FUNCTION_VISITOR}

   accept(visitor: ONCE_FUNCTION_VISITOR) is
      do
         visitor.visit_once_function(Current)
      end

feature {NONE}

   make(n: like names
        fa: like arguments
        t: like result_type
        om: like obsolete_mark
        hc: like header_comment
        ra: like require_assertion
        lv: like local_vars
        rb: like routine_body) is
      require
         t /= Void
      do
         make_effective_routine(n, fa, om, hc, ra, lv ,rb)
         result_type := t
      end

   once_pre_computable_memory: INTEGER

   try_to_undefine_aux(fn: FEATURE_NAME; bc: BASE_CLASS): DEFERRED_ROUTINE is
      do
         create {DEFERRED_FUNCTION}
	    Result.from_effective(fn, arguments,
				  result_type,
				  require_assertion,
				  ensure_assertion,
				  bc)
      end

end -- ONCE_FUNCTION

