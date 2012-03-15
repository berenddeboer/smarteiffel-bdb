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
deferred class LOCAL_ARGUMENT
   --
   -- Common root to handle local variables (LOCAL_NAME) or formal
   -- argument names (ARGUMENT_NAME).
   --

inherit NAME; EXPRESSION redefine to_runnable end

feature

   start_position: POSITION
         -- Of the first character of the name.

   is_void: BOOLEAN is False

   is_manifest_string: BOOLEAN is False

   is_current: BOOLEAN is False

   is_result: BOOLEAN is False

   side_effect_free: BOOLEAN is True

   is_static: BOOLEAN is False

   use_current: BOOLEAN is False

   frozen simplify_1_, frozen simplify_2: like Current is
      do
	 Result := Current
      end
   
   to_string: STRING is
      deferred
      end

   to_runnable(ct: E_TYPE): like Current is
      deferred
      end

   rank: INTEGER is
         -- in the corresponding flat list.
      deferred
      ensure
         Result >= 1
      end

   frozen to_integer_or_error: INTEGER is
      do
	 to_integer_error
      end

   frozen stupid_switch(run_time_set: RUN_TIME_SET): BOOLEAN is
      do
         if smart_eiffel.stupid_switch(result_type,run_time_set) then
            Result := True
         end
      end

   frozen start_lookup_class: BASE_CLASS is
      do
         Result := result_type.start_lookup_class
      end

   frozen afd_check is do end

   frozen safety_check is do end

   frozen to_key: STRING is
      do
         Result := to_string
      end

   frozen collect_c_tmp is
      do
      end

   frozen c_frame_descriptor(format, locals: STRING) is
      do
      end

   frozen compile_target_to_jvm is
      do
         standard_compile_target_to_jvm
      end

   frozen precedence: INTEGER is
      do
         Result := atomic_precedence
      end

   frozen print_as_target is
      do
         pretty_printer.put_string(to_string)
         pretty_printer.put_character('.')
      end

   frozen short is
      local
         i: INTEGER
         c: CHARACTER
      do
         short_print.hook("Ban")
         from
            i := 1
         until
            i > to_string.count
         loop
            c := to_string.item(i)
            if c = '_' then
               short_print.hook_or("Uan","_")
            else
               short_print.a_character(c)
            end
            i := i + 1
         end
         short_print.hook("Aan")
      end

   frozen short_target is
      do
         short
         short_print.a_dot
      end

feature {DECLARATION_LIST}

   c_scoop_struct_in(buf: STRING) is
      local
         t: E_TYPE
      do
         t := result_type.run_type
         t.c_type_for_result_in(buf)
         buf.extend(' ')
         buf.extend('_')
         buf.append(to_string)
         buf.extend(';')
      end

feature {LOCAL_ARGUMENT_VISITOR}

   accept(visitor: LOCAL_ARGUMENT_VISITOR) is
      deferred
      end

invariant

   not start_position.is_unknown

end -- LOCAL_ARGUMENT

