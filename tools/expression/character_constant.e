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
class CHARACTER_CONSTANT
   --
   -- For Manifest Constant CHARACTER.
   --

inherit BASE_TYPE_CONSTANT

creation {EIFFEL_PARSER} make

creation with

feature

   is_static: BOOLEAN is True

   value: CHARACTER

   pretty_print_mode: INTEGER

   std_pretty_print: INTEGER is 0

   percent_pretty_print: INTEGER is 1

   ascii_pretty_print: INTEGER is 2

   to_integer_or_error: INTEGER is
      do
         Result := value.code
      end

   compile_to_c is
      do
         cpp.put_string(once "((T3)%'")
         if value.is_letter or else value.is_digit then
            cpp.put_character(value)
         elseif value = '%N' then
            cpp.put_character('\')
            cpp.put_character('n')
         else
            cpp.put_character('\')
	    tmp_string.clear_count
	    value.code.low_8.to_octal_in(tmp_string)
            cpp.put_string(tmp_string)
         end
         cpp.put_string(once "%')")
      end

   compile_to_jvm, compile_target_to_jvm is
      do
         code_attribute.opcode_push_integer(value.code)
      end

   jvm_branch_if_false: INTEGER is
      do
      end

   jvm_branch_if_true: INTEGER is
      do
      end

   compile_to_jvm_into(dest: E_TYPE): INTEGER is
      do
         Result := standard_compile_to_jvm_into(dest)
      end

   set_pretty_print_mode(pm: like pretty_print_mode) is
      require
         pm = std_pretty_print or else
         pm = percent_pretty_print or else
         pm = ascii_pretty_print
      do
         pretty_print_mode := pm
      ensure
         pretty_print_mode = pm
      end

   to_string: STRING is
      do
         create Result.make(4)
         Result.extend('%'')
         inspect
            pretty_print_mode
         when std_pretty_print then
            Result.extend(value)
         when percent_pretty_print then
            character_coding(value,Result)
         when ascii_pretty_print then
            Result.extend('%%')
            Result.extend('/')
            value.code.append_in(Result)
            Result.extend('/')
         end
         Result.extend('%'')
      end

   to_runnable(ct: E_TYPE): like Current is
      do
         Result := Current
	 if result_type = Void then
	    set_result_type
	 end
      end

   simplify_1_, simplify_2: like Current is
      do
	 Result := Current
      end
   
feature {CHARACTER_CONSTANT_VISITOR}

   accept(visitor: CHARACTER_CONSTANT_VISITOR) is
      do
         visitor.visit_character_constant(Current)
      end

feature {NONE}

   set_result_type is
      require
	 result_type = Void
      do
	 create {TYPE_CHARACTER} result_type.make(start_position)
      end
   
   tmp_string: STRING is
      once
         create Result.make(22)
      end

   make(sp: like start_position; v: like value
        pm: like pretty_print_mode) is
      require
         not sp.is_unknown
      do
         start_position := sp
         value := v
         set_pretty_print_mode(pm)
      ensure
         start_position = sp
         value = v
         pretty_print_mode = pm
      end

   with(sp: like start_position; v: like value) is
      require
         not sp.is_unknown
      do
	 make(sp, v, std_pretty_print)
	 set_result_type
      end
   
end -- CHARACTER_CONSTANT

