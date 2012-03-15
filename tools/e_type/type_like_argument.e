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
class TYPE_LIKE_ARGUMENT
   --
   -- For an anchored declaration type mark using a formal argument.
   --
   -- See also TYPE_LIKE and TYPE_LIKE_CURRENT.
   --

inherit TYPE_ANCHORED

creation make, with

feature {TYPE_LIKE_ARGUMENT_VISITOR}

   accept(visitor: TYPE_LIKE_ARGUMENT_VISITOR) is
      do
         visitor.visit_type_like_argument(Current)
      end

feature

   is_like_current: BOOLEAN is false

   is_like_argument: BOOLEAN is true

   is_like_feature: BOOLEAN is false

   like_what: ARGUMENT_NAME2

   written_mark: STRING

   start_lookup_name: CLASS_NAME is
      local
         bc: BASE_CLASS
      do
	 -- I am not really convinced by this way of computing
	 -- the lookup class name. (Why isn't the `run_type' used?)
         bc := like_what.start_lookup_class
         if bc /= Void then
            Result := bc.name
         end
      end

   is_run_type: BOOLEAN is
      do
         if run_feature /= Void then
            Result := run_type.is_run_type
         end
      end

   run_type: E_TYPE is
      local
         fal: FORMAL_ARG_LIST
      do
         fal := run_feature.arguments
         Result := fal.type(rank)
         if Result.is_run_type then
            Result := Result.run_type
         end
      end

   to_runnable(ct: E_TYPE): like Current is
      local
         rf: RUN_FEATURE; rt: E_TYPE
      do
         anchor_cycle_start
         rf := smart_eiffel.top_rf
         if rf.arguments = Void then
            error_handler.add_position(start_position)
            error_handler.add_position(rf.start_position)
            fatal_error(fz_bad_anchor)
         end
         if run_feature = Void then
            run_feature := rf
            Result := Current
         elseif run_feature = rf then
            Result := Current
         else
            !!Result.with(Current,rf)
         end
         rt := Result.run_type
         if rt.is_anchored then
            rt := rt.to_runnable(ct)
         end
         anchor_cycle_end
      end

   stupid_switch(run_time_set: RUN_TIME_SET): BOOLEAN is
      do
	 Result := standard_stupid_switch(run_time_set)
      end

   rank: INTEGER is
      do
         Result := like_what.rank
      end

   is_a(other: E_TYPE): BOOLEAN is
      do
         Result := run_type.is_a(other)
      end

feature {E_TYPE}

   short_hook is
      do
         short_print.hook_or("like","like ")
         like_what.short
      end

feature {NONE}

   run_feature: RUN_FEATURE

   make(sp: like start_position; lw: like like_what) is
      require
         not sp.is_unknown
         lw /= Void
      do
         start_position := sp
         like_what := lw
         written_mark_buffer.copy(fz_like)
         written_mark_buffer.extend(' ')
         written_mark_buffer.append(like_what.to_string)
         written_mark := string_aliaser.item(written_mark_buffer)
      ensure
         start_position = sp
         like_what = lw
      end

   with(model: like Current; rf: RUN_FEATURE) is
      require
         model /= Void
         rf /= Void
      do
         start_position := model.start_position
         like_what := model.like_what
         written_mark := model.written_mark
         run_feature := rf
      ensure
         start_position = model.start_position
         like_what = model.like_what
         written_mark = model.written_mark
         run_feature = rf
      end

invariant

   as_current /= like_what.to_string

end -- TYPE_LIKE_ARGUMENT

