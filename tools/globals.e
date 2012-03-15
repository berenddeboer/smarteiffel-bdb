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
deferred class GLOBALS
   --
   -- Global Tools for the SmartEiffel system.
   --

inherit
   ALIASED_STRING_LIST
   FROZEN_STRING_LIST

feature

   frozen smart_eiffel: SMART_EIFFEL is
      once
         create Result
      end

   frozen eiffel_parser : EIFFEL_PARSER is
      once
         create Result
      end

   frozen ace: ACE is
      once
         create Result
      end

   frozen ini_parser: INI_PARSER is
      once
         create Result
      end

   frozen error_handler: ERROR_HANDLER is
      once
         create Result
      end

   frozen string_aliaser: STRING_ALIASER is
      once
         create Result.make
      end

   frozen cpp: C_PRETTY_PRINTER is
      once
         create Result
      end

   frozen pretty_printer: PRETTY_PRINTER is
      once
         create Result.make
      end

   frozen jvm: JVM is
      once
         create Result.make
      end

   frozen constant_pool: CONSTANT_POOL is
      once
         create Result
      end

   frozen mini_buffer: MINI_BUFFER is
      once
         create Result
      end

   nb_errors: INTEGER is
      do
         Result := error_handler.error_counter
      ensure
         Result >= 0
      end

   frozen gc_handler: GC_HANDLER is
      once
         create Result.make
      end

   separate_tools: SEPARATE_TOOLS is
      once
         create Result.make
      end

   frozen system_tools: SYSTEM_TOOLS is
      once
         create Result.make
      end

feature {SMART_EIFFEL,SYSTEM_TOOLS,INSTALL,VISITOR}

   frozen parser_buffer: PARSER_BUFFER is
      once
         create Result.make
      end

feature {NATIVE_JAVA}

   frozen interface_info: INTERFACE_INFO is
      once
         create Result
      end

feature {NONE}

   frozen id_provider: ID_PROVIDER is
      once
         create Result.make
      end

   frozen manifest_string_pool: MANIFEST_STRING_POOL is
      once
         create Result
      end

   frozen manifest_array_pool: MANIFEST_ARRAY_POOL is
      once
         create Result
      end

   frozen once_routine_pool: ONCE_ROUTINE_POOL is
      once
         create Result
      end

   frozen agent_pool: AGENT_POOL is
      once
         create Result
      end

   frozen cecil_pool: CECIL_POOL is
      once
         create Result
      end

   frozen address_of_pool: ADDRESS_OF_POOL is
      once
         create Result
      end

   frozen short_print: SHORT_PRINT is
      once
         create Result.make
      end

   frozen echo: ECHO is
      once
         create Result.make
      end

   frozen assignment_handler: ASSIGNMENT_HANDLER is
      once
         create Result
      end

   frozen switch_collection: SWITCH_COLLECTION is
      once
      end

   frozen assertion_collector: ASSERTION_COLLECTOR is
      once
         create Result.make
      end

   frozen exceptions_handler: EXCEPTIONS_HANDLER is
      once
         create Result.make
      end

   frozen classfile_attribute: CLASSFILE_ATTRIBUTE is
      once
         create Result.make
      end

   frozen line_number_table: LINE_NUMBER_TABLE is
       once
          create Result.make
       end

   frozen field_info: FIELD_INFO is
      once
         create Result
      end

   frozen code_attribute: CODE_ATTRIBUTE is
      once
         create Result
      end

   frozen method_info: METHOD_INFO is
      once
         create Result
      end

   nb_warnings: INTEGER is
      do
         Result := error_handler.warning_counter
      ensure
         Result >= 0
      end

   warning(p: POSITION; msg: STRING) is
         -- Warning `msg' at position `p'.
      require
         not msg.is_empty
      do
         error_handler.add_position(p)
         error_handler.append(msg)
         error_handler.print_as_warning
      ensure
         nb_warnings = old nb_warnings + 1
      end

   error(p: POSITION; msg: STRING) is
         -- When error `msg' occurs at position `p'.
      require
         not msg.is_empty
      do
         error_handler.add_position(p)
         error_handler.append(msg)
         error_handler.print_as_error
      ensure
         nb_errors = old nb_errors + 1
      end

   fatal_error(msg: STRING) is
         -- Should not append but it is better to know :-)
      require
         not msg.is_empty
      do
         error_handler.append(msg)
         error_handler.print_as_fatal_error
      end

   tmp_path: STRING is
      once
         create Result.make(512)
      end

   tmp_file_read: TEXT_FILE_READ is
      once
         create Result.make
      end

   class_any: BASE_CLASS is
      local
	 cn: CLASS_NAME
      once
	 create cn.unknown_position(as_any)
         Result := smart_eiffel.base_class(cn)
      end

   class_general: BASE_CLASS is
      local
	 cn: CLASS_NAME
      once
	 create cn.unknown_position(as_general)
         Result := smart_eiffel.base_class(cn)
      end

   type_boolean: TYPE_BOOLEAN is
      local
         unknown_position: POSITION
      once
         create Result.make(unknown_position)
      end

   type_string: TYPE_STRING is
      local
         unknown_position: POSITION
      once
         create Result.make(unknown_position)
      end

   type_any: TYPE_ANY is
      local
         unknown_position: POSITION
      once
         create Result.make(unknown_position)
      end

   type_pointer: TYPE_POINTER is
      local
         unknown_position: POSITION
      once
         create Result.make(unknown_position)
      end

   frozen omitted_client_list: CLIENT_LIST is
	 -- (To avoid multiple creation(s).)
      once
	 create Result.omitted
      end

   no_errors: BOOLEAN is
      do
         Result := nb_errors = 0
      end

   character_coding(c: CHARACTER; str: STRING) is
         -- Append in `str' the Eiffel coding of the character (Table
         -- in chapter 25 of ETL, page 423). -- When the % letter notation
         -- exists, it is returned in priority: '%N' gives "%N", '%T' gives
         -- "%T", etc.
	 -- When % letter notation does not exists (not in the ETL table),
         -- numbered coding is used ("%/1/", "%/2/" etc).
      local
         special: CHARACTER
      do
         inspect
            c
         when '%A' then special := 'A'
         when '%B' then special := 'B'
         when '%C' then special := 'C'
         when '%D' then special := 'D'
         when '%F' then special := 'F'
         when '%H' then special := 'H'
         when '%L' then special := 'L'
         when '%N' then special := 'N'
         when '%Q' then special := 'Q'
         when '%R' then special := 'R'
         when '%S' then special := 'S'
         when '%T' then special := 'T'
         when '%U' then special := 'U'
         when '%V' then special := 'V'
         when '%%' then special := '%%'
         when '%'' then special := '%''
         when '%"' then special := '"'
         when '%(' then special := '('
         when '%)' then special := ')'
         when '%<' then special := '<'
         when '%>' then special := '>'
         else
         end
         str.extend('%%')
         if special = '%U' then
            str.extend('/')
            c.code.append_in(str)
            str.extend('/')
         else
            str.extend(special)
         end
      end

   fatal_error_vtec_2 is
      do
         error_handler.append(
            "Expanded class must have no creation procedure, or only %
            %one creation procedure with no arguments (VTEC.2).")
	 error_handler.print_as_fatal_error
      end

   eiffel_suffix: STRING is ".e"
         -- Eiffel Source file suffix.

   c_suffix: STRING is ".c"
         -- C files suffix.

   h_suffix: STRING is ".h"
         -- Heading C files suffix.

   c_plus_plus_suffix: STRING is ".cpp"
         -- C++ files suffix.

   backup_suffix: STRING is ".bak"
         -- Backup suffix for command `pretty'.

   class_suffix: STRING is ".class"

   dot_precedence: INTEGER is 12
         -- The highest precedence value according to ETL.

   atomic_precedence: INTEGER is 13
         -- Used for atomic elements.

   jvm_root_class: STRING is
         -- Fully qualified name for the jvm SmartEiffel object's
         -- added root : "<Package>/<fz_jvm_root>".
      once
         create Result.make(12)
         Result.copy(ace.executable_name)
         Result.extend('/')
         Result.append(fz_jvm_root)
      end

   jvm_root_descriptor: STRING is
         -- Descriptor for `jvm_root_class': "L<jvm_root_class>;"
      once
         create Result.make(12)
         Result.extend('L')
         Result.append(jvm_root_class)
         Result.extend(';')
      end

   append_u1(str: STRING; u1: INTEGER) is
      require
         u1.in_range(0, 255)
      do
         str.extend(u1.to_character)
      end

   append_u2(str: STRING; u2: INTEGER) is
      require
         u2.in_range(0, 65535)
      do
         append_u1(str,u2 // 256)
         append_u1(str,u2 \\ 256)
      end

   append_u4(str: STRING; u4: INTEGER) is
      require
	 u4.in_range(0, Maximum_integer)
      do
         append_u2(str,u4 // 65536)
         append_u2(str,u4 \\ 65536)
      end

   is_install: REFERENCE [BOOLEAN] is
      once
         create Result
      end

end -- GLOBALS
