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
class REAL_CONSTANT
   --
   -- For Manifest Constant REAL as well as DOUBLE.
   --

inherit BASE_TYPE_CONSTANT

creation make, from_double

feature

   is_static: BOOLEAN is False

   to_string: STRING
         -- Cleanly written view of the constant (ANSI C compatible).

   to_integer_or_error: INTEGER is
      do
	 to_integer_error
      end

   value: DOUBLE is
      do
	 Result := to_string.to_double
      end

   compile_to_c is
      do
         cpp.put_string(to_string)
      end

   compile_target_to_jvm, compile_to_jvm is
      do
	 if result_type.is_double then
	    code_attribute.opcode_push_as_double(to_string)
	 else
	    code_attribute.opcode_push_as_float(to_string)
	 end
      end
	 
   jvm_branch_if_false: INTEGER is
      do
      end

   jvm_branch_if_true: INTEGER is
      do
      end

   compile_to_jvm_into(dest: E_TYPE): INTEGER is
      do
         if dest.is_real then
            code_attribute.opcode_push_as_float(to_string)
            Result := 1
         elseif dest.is_double then
            code_attribute.opcode_push_as_double(to_string)
            Result := 2
         else
            Result := standard_compile_to_jvm_into(dest)
         end
      end

   to_runnable(ct: E_TYPE): like Current is
      do
         Result := Current
      end

   simplify_1_, simplify_2: like Current is
      do
	 Result := Current
      end
   
feature {IMPLICIT_CAST, TMP_FEATURE}

   set_result_type(rt: E_TYPE) is
      require
	 rt.is_double or else rt.is_real
      do
	 result_type := rt
      ensure
	 result_type = rt
      end

feature {REAL_CONSTANT_VISITOR}

   accept(visitor: REAL_CONSTANT_VISITOR) is
      do
         visitor.visit_real_constant(Current)
      end

feature {NONE}

   make(sp: like start_position; ts: like to_string) is
      require
         not sp.is_unknown
         ts.is_double
	 string_aliaser.item(ts) /= ts
      local
	 stop: BOOLEAN
      do
         start_position := sp
         to_string := ts
	 if smart_eiffel.pretty_flag then
	 elseif smart_eiffel.short_flag then
	 else
	    -- Kind of normalisation to allow easy comparison.
	    -- Normalize the righ-most part:
	    from until stop
	    loop
	       if to_string.count = 1 then
		  stop := True
	       elseif to_string.last /= '0' then
		  stop := True
	       else
		  to_string.remove_last(1)
	       end
	    end
	    if not to_string.has('.') then
	       to_string.extend('.')
	    end
	    if to_string.last = '.' then
	       to_string.extend('0')
	    end
	    -- Normalize the left-most part:
	    from
	       stop := False
	    until stop
	    loop
	       if to_string.first /= '0' then
		  stop := True
	       else
		  to_string.remove_first(1)
	       end
	    end
	    if to_string.first = '.' then
	       to_string.precede('0')
	    end
	 end
	 -- Setting the `result_type':
	 create {TYPE_REAL} result_type.make(start_position)
      ensure
         start_position = sp
         to_string = ts
      end

   from_double(sp: like start_position; double: DOUBLE; rt: like result_type) is
      require
	 rt.is_double or else rt.is_real
      do
	 make(sp, double.to_string_format(10))
	 --                               **
	 -- We need to redesign REAL/DOUBLE notation... :-(
	 result_type := rt
      end
   
end -- REAL_CONSTANT
