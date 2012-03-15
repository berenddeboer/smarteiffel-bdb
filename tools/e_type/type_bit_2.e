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
class TYPE_BIT_2
   --
   -- Handling for example of "BIT Foo" type mark 
   --

inherit TYPE_BIT

creation make

feature

   n: FEATURE_NAME
         -- Which is supposed to gives the number of bits.

   run_type: TYPE_BIT
         -- When runnable, the corresponding one.

   nb: INTEGER is
      do
         Result := run_type.nb
      end

   run_time_mark: STRING is
      do
         Result := run_type.written_mark
      end

   is_run_type: BOOLEAN is
      do
         Result := run_type /= Void
      end

   to_runnable(ct: E_TYPE): like Current is
      local
         rf: RUN_FEATURE; rf1: RUN_FEATURE_1; rf8: RUN_FEATURE_8
         ic: INTEGER_CONSTANT; nb_value: INTEGER
      do
         if run_type = Void then
            rf := n.run_feature(ct)
            if rf = Void then
               error_handler.feature_not_found(n)
               error_handler.print_as_fatal_error
            else
               rf1 ?= rf
               rf8 ?= rf
               if rf1 /= Void then
                  ic ?= rf1.base_feature.value(1)
                  if ic = Void then
                     error_handler.add_position(n.start_position)
                     error_handler.add_position(rf1.start_position)
                     fatal_error(fz_iinaiv)
                  end
                  nb_value := ic.value_memory.to_integer
                  if nb_value < 0 then
                     error_handler.add_position(n.start_position)
                     error_handler.add_position(rf1.start_position)
                     fatal_error("Must be a positive INTEGER.")
                  end
                  create {TYPE_BIT_1}
		     run_type.make(start_position,ic)
               elseif rf8 /= Void then
                  nb_value := rf8.integer_value(n.start_position)
                  create ic.make(nb_value, n.start_position)
                  create {TYPE_BIT_1}
		     run_type.make(start_position,ic)
               else
                  error_handler.add_position(n.start_position)
                  error_handler.add_position(rf.start_position)
                  fatal_error(fz_iinaiv)
               end
               Result := Current
               to_runnable_1_2
            end
         else
            create Result.make(start_position,n)
            Result := Result.to_runnable(ct)
         end
      end

feature {E_TYPE}

   short_hook is
      do
         short_print.a_class_name(base_class_name)
         short_print.hook_or("tm_blank"," ")
         n.short
      end

feature {TYPE_BIT_2_VISITOR}

   accept(visitor: TYPE_BIT_2_VISITOR) is
      do
         visitor.visit_type_bit_2(Current)
      end

feature {NONE}

   make(sp: like start_position; name: like n) is
      require
         not sp.is_unknown
         name /= Void
      do
         tmp_string.copy(as_bit)
         tmp_string.extend(' ')
         tmp_string.append(name.to_string)
         written_mark := string_aliaser.item(tmp_string)
         start_position := sp
         n := name
      end

invariant

   n /= Void

end -- TYPE_BIT_2

