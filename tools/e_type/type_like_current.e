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
class TYPE_LIKE_CURRENT

inherit TYPE_ANCHORED

creation make, with

feature

   run_type: E_TYPE

   is_like_current: BOOLEAN is True

   is_like_argument, is_like_feature: BOOLEAN is False

   start_lookup_name: CLASS_NAME is
      do
         Result := start_position.base_class_name
      end

   is_run_type: BOOLEAN is
      do
         Result := run_type /= Void
      end

   to_runnable(ct: E_TYPE): like Current is
      do
         if run_type = Void then
            run_type := ct
            Result := Current
         elseif run_type = ct then
            Result := Current
         else
            create Result.with(Current, ct)
         end
      end

   stupid_switch(run_time_set: RUN_TIME_SET): BOOLEAN is do end

   written_mark: STRING is
      do
         Result := as_like_current
      end

   is_a(other: E_TYPE): BOOLEAN is
      do
	 Result := run_type.is_a(other)
	 if not Result then
	    error_handler.add_position(start_position)
	 end
      end

feature {E_TYPE}

   short_hook is
      do
         short_print.hook_or("like","like ")
         short_print.hook_or(as_current,as_current)
      end

feature {TYPE_LIKE_CURRENT_VISITOR}

   accept(visitor: TYPE_LIKE_CURRENT_VISITOR) is
      do
         visitor.visit_type_like_current(Current)
      end

feature {NONE}

   make(sp: like start_position) is
      require
         not sp.is_unknown
      do
         start_position := sp
      ensure
         start_position = sp
      end

   with(model: like Current; rt: E_TYPE) is
      require
         model /= Void
         rt /= Void
      do
         start_position := model.start_position
         run_type := rt
      ensure
         start_position = model.start_position
         run_type = rt
      end

end -- TYPE_LIKE_CURRENT
