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
--                           - University of Nancy 1 - FRANCE
-- Copyright(C) 2003:      INRIA - LORIA (INRIA Lorraine) - I.U.T. Charlemagne
--                           - University of Nancy 2 - FRANCE
--
--                 Dominique COLNET, Suzanne COLLIN, Olivier ZENDRA,
--                           Philippe RIBET, Cyril ADRIAN
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

   is_infinity: BOOLEAN is
      do
         Result := to_string.has_substring (once "inf") or else
                   to_string.has_substring (once "INF")
         -- ISO C99 compilers generate "inf" or "infinity", optionally preceded
         -- by a minus sign. Visual C++ 7.1 generates something else, but
         -- this should catch it, see ticket:42
      end

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
         if not is_infinity then
             cpp.put_string(to_string)
         elseif to_string.first = '-' then
             cpp.put_string(once "NEGATIVE_INFINITY")
         else
             cpp.put_string(once "POSITIVE_INFINITY")
         end
         -- The constants generated are defined in base.h
      end

   compile_target_to_jvm, compile_to_jvm is
      do
         if result_type.is_double then
            code_attribute.opcode_push_as_double(normalized_view)
         else
            code_attribute.opcode_push_as_float(normalized_view)
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
            code_attribute.opcode_push_as_float(normalized_view)
            Result := 1
         elseif dest.is_double then
            code_attribute.opcode_push_as_double(normalized_view)
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
   
	normalized_view: STRING is
			-- Return our internal normalized notation:
			--    0.0      --> 0e0
			--    1.0      --> 1e0
		   --    0.5      --> 5e-1
		   --   -3.5      --> -35e-1
		   --   -3.56     --> -356e-2
		local
			buffer: STRING; state, i, mantissa_count, exponent, user_exponent: INTEGER; cc: CHARACTER
			negative_user_exponent_flag: BOOLEAN
		do
			if normalized_memory = Void and not is_infinity then
				from
					-- This automaton assume that the `to_string' is correct.
					buffer := once "..........................................................."
					buffer.clear_count
					i := 1
				until
					i > to_string.count
				loop
					cc := to_string.item(i)
					inspect
						state
					when 0 then	-- Still waiting fot the first non zero digit of the mantissa.
						inspect
							cc
						when '{' then
							state := 1
						when '-' then
							buffer.extend('-')
						when '1' .. '9' then
							state := 2
							buffer.extend(cc); mantissa_count := 1
						when '0', '+' then
						when '.' then
							state := 3
						when 'e', 'E' then
							state := 4
						end
					when 1 then	-- Inside the type mark.
						if cc = ' ' then
							state := 0
						end
					when 2 then	-- Inside mantissa.
						inspect
							cc
						when '0' .. '9' then
							buffer.extend(cc); mantissa_count := mantissa_count + 1
						when '.' then
							state := 3
						when 'e', 'E' then
							state := 4
						end
					when 3 then	-- Inside frational part.
						inspect
							cc
						when '0' then
							if mantissa_count > 0 then
								buffer.extend(cc); mantissa_count := mantissa_count + 1
							end
							exponent := exponent - 1
						when '1' .. '9' then
							buffer.extend(cc); mantissa_count := mantissa_count + 1
							exponent := exponent - 1
						when '}' then
						when 'e', 'E' then
							state := 4
						end
					when 4 then	-- Inside exponent part.
						inspect
							cc
						when '+' then
						when '-' then
							negative_user_exponent_flag := True
						when '0' .. '9' then
							user_exponent := (user_exponent * 10) + cc.decimal_value 
						when '}' then
						end
					end
					i := i + 1
				end
				if negative_user_exponent_flag then
					user_exponent := - user_exponent
				end
				exponent := exponent + user_exponent
				inspect
					mantissa_count
				when 0 then
					if user_exponent /= 0 then
						error_handler.add_position(start_position)
						error_handler.append("Invalid notation for 0.0.")
						error_handler.print_as_error
					end
					buffer.copy(once "0e0")
				else
					-- Remove trailing '0'.
					from 
					until
						buffer.last /= '0'
					loop
						buffer.remove_last (1)
						mantissa_count := mantissa_count - 1
						exponent := exponent + 1
					end
					buffer.extend('e')
					exponent.append_in(buffer)
				end
				normalized_memory := buffer.twin
			end
			Result := normalized_memory
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

   normalized_memory: STRING

   make (sp: like start_position; ts: like to_string) is
      require
         not sp.is_unknown
         ts.is_double
         string_aliaser.item(ts) /= ts
      do
         start_position := sp
         to_string := ts
         -- Setting the `result_type':
         create {TYPE_REAL} result_type.make(start_position, as_real)
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
