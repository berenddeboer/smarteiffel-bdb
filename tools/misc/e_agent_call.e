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
class E_AGENT_CALL
   --
   -- Fake call used during E_AGENT mapping of the actual called routine.
   --

inherit
   CALL_PROC_CALL

creation {E_AGENT} make

feature {E_AGENT_CALL_VISITOR}

   accept(visitor: E_AGENT_CALL_VISITOR) is
      do
         visitor.visit_e_agent_call(Current)
      end

feature

   arguments: EFFECTIVE_ARG_LIST

feature {NONE}

   creator: E_AGENT
	 -- The `creator' of `Current'.

   make(c: like creator; rf: like run_feature) is
      require
	 c /= Void
      local
	 fal: FORMAL_ARG_LIST; argc, i: INTEGER
      do
	 creator := c
	 run_feature := rf
	 create {FAKE_TARGET} target.make(rf.current_type)
	 feature_name := rf.name
	 fal := rf.arguments
	 if fal /= Void then
	    argc := fal.count
	    from
	       create arguments.make_1(fake_argument(fal,1))
	       i := 2
	    until
	       i > argc
	    loop
	       arguments.add_last(fake_argument(fal,i))
	       i := i + 1
	    end
	 end
      ensure
	 creator = c
      end

   fake_argument(fal: FORMAL_ARG_LIST; idx: INTEGER): FAKE_ARGUMENT is
      require
	 idx.in_range(1,fal.count)
      local
	 rt: E_TYPE
      do
	 rt := fal.type(idx).run_type
	 create {FAKE_ARGUMENT} Result.make(rt,idx)
      ensure
	 Result /= Void
      end

invariant

   creator /= Void

end -- E_AGENT_CALL
