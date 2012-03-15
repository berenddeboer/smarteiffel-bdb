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
expanded class POSITION
   --
   -- A position in some source file. Actually the source file can be
   -- some Eiffel source file, some -cecil file or the ACE file.
   --

inherit
   GLOBALS
   VISITABLE

feature

   base_class: BASE_CLASS
         -- The corresponding one which may be Void for example when
         -- `is_unknown' or when parsing a -cecil file or the ACE file.

   line: INTEGER is
         -- The corresponding `line' number in the source file or 0
         -- when `is_unknown'.
      do
         if mangling.bit_test(0) then
            Result := mangling |>> 1
            Result := Result & 0x0000ffff
            check Result.fit_integer_16 end
         else
            Result := mangling |>> 8
            Result := Result & 0x00001fff
         end
      ensure
         not is_unknown implies Result >= 0
      end

   column: INTEGER is
         -- The `column' number in the source file or 0 when `is_unknown' or
         -- when there is not enough space in `mangling' for the `column'.
      do
         if mangling.bit_test(0) then
            -- Result is 0 because `column' is not memorized.
         else
            Result := mangling |>> 1
            Result := Result & 0x0000007f
         end
      ensure
         Result >= 0
      end

   base_class_name: CLASS_NAME is
         -- The corresponding one when already loaded by the `eiffel_parser'.
      local
         bc: BASE_CLASS
      do
         bc := base_class
         if bc /= Void then
            Result := bc.name
         end
      end

   path: STRING is
         -- The corresponding file `path' or Void when `is_unknown'.
      local
         bc: BASE_CLASS
         id_value: INTEGER_16
      do
         bc := base_class
         if bc /= Void then
            Result := bc.path
         else
            -- Looking for the path of the -cecil file or for the
            -- path of some ACE or INI file.
            id_value := id
            inspect
               id_value
            when id_ace_file then
               Result := ace.file_path
            when id_ini_file then
               Result := ini_parser.file_path
            else
               check id_value > 0 end
               Result := id_provider.alias_of(id_value)
	    end
         end
      ensure
         Result /= Void implies string_aliaser.item(Result) = Result
      end

   is_unknown: BOOLEAN is
         -- True when the `eiffel_parser' as called `set'.
      do
         Result := mangling = 0
      end

   before(other: like Current): BOOLEAN is
         -- Is `Current' position strictly before `other' (which is in the
         -- same source text file).
      require
         path = other.path
      local
         li, other_li: INTEGER
      do
         li := line
         other_li := other.line
         if li < other_li then
            Result := True
         elseif li = other_li then
            Result := column < other.column
         end
      end

   sedb_trace: BOOLEAN is
	 -- Is the run-time trace mechanism activated for this position?
      local
	 bc: BASE_CLASS
      do
	 bc := base_class
	 if bc /= Void then
	    Result := bc.sedb_trace
	 end
      end

   show is
      require
	 base_class_name = Void or else not smart_eiffel.no_file_for(base_class_name.to_string)
      local
         li, co, nb: INTEGER; bc: BASE_CLASS; bcn: CLASS_NAME
         name, file_path, the_line: STRING
         id_value: INTEGER_16
      do
         li := line
         co := column
         bc := base_class
         if bc /= Void then
            check id = bc.id end
            bcn := base_class_name
         end
         if bcn /= Void then
            name := bcn.to_string
            file_path := bc.path
         end
	 if file_path = Void then
            id_value := id
            inspect
               id_value
            when id_ace_file then
	       file_path := ace.file_path
            when id_ini_file then
               file_path := ini_parser.file_path
            when id_other_file then
               file_path := file
            else
               file_path := id_provider.alias_of(id_value)
            end
	 end
         echo.w_put_string("Line ")
         echo.w_put_integer(li)
         if co > 0 then
            echo.w_put_string(" column ")
            echo.w_put_integer(co)
         end
         echo.w_put_string(" in ")
         if name /= Void then
            echo.w_put_string(name)
         end
         if file_path /= Void then
            echo.w_put_string(" (")
            echo.w_put_string(file_path)
            echo.w_put_character(')')
         end
         echo.w_put_string(" :%N")
         if file_path /= Void then
            the_line := get_line(file_path,li)
            if li > 0 and then the_line /= Void then
               echo.w_put_string(the_line)
               echo.w_put_character('%N')
               if co > 0 then
                  from
                     nb := 1
                  until
                     nb >= co
                  loop
                     if the_line.item(nb) = '%T' then
                        echo.w_put_character('%T')
                     else
                        echo.w_put_character(' ')
                     end
                     nb := nb + 1
                  end
                  echo.w_put_string("^%N")
               end
            end
         end
      end

   append_in(buffer: STRING) is
      require
         buffer /= Void
      local
         li, co: INTEGER; bc: BASE_CLASS; bcn: CLASS_NAME; place: STRING
      do
         li := line
         co := column
         buffer.append("Line ")
         li.append_in(buffer)
         if co > 0 then
            buffer.append(" column ")
            co.append_in(buffer)
         end
         bc := base_class
         if bc /= Void then
            place := bc.path
            if place = Void then
               bcn := bc.name
               if bcn /= Void then
                  place := bcn.to_string
               end
            end
            if place /= Void then
               buffer.append(" in %"")
               buffer.append(place)
               buffer.append(fz_03)
            end
         end
      end

   set_in(bc: like base_class) is
	 -- Assign `Current' in `bc'. This routine is used to create implicit
	 -- Eiffel code. As an example, this is used to define pseudo
	 -- code of class TUPLE which is not truly written.
      require
	 smart_eiffel.no_file_for(bc.name.to_string)
      do
	 eiffel_file(1,1,bc.id,bc)
      end

feature {EIFFEL_PARSER}

   eiffel_file(li, co: INTEGER; class_id: INTEGER_16; bc: like base_class) is
	 -- The position is in some Eiffel file.
      require
         li >= 1
         co >= 1
         bc /= Void implies class_id = bc.id
      do
         base_class := bc
         check Integer_bits >= 32 end
         if class_id <= 2047 and then li <= 8191 and then co <= 127 then
            mangling := (class_id |<< 21)       -- 11 bits for `id'
            mangling := mangling | (li |<< 8)   -- 13 bits for `line'
            mangling := mangling | (co |<< 1)   -- 7  bits for `column'
         else
            -- The `column' is not memorized.
            mangling := (class_id |<< 17);       -- 15 bits for `id'
            mangling := mangling | (li |<< 1)    -- 16 bits for `line'
            mangling := mangling | 1             -- forget `column'.
         end
      ensure
         line = li
         id = class_id
         column = 0 or else column = co
      end

feature {ACE}

   ace_file(li, co: INTEGER) is
	 -- The position is in the ACE file.
      require
         li >= 1; co >= 1
      do
         eiffel_file(li,co,id_ace_file,Void)
      ensure
         line = li
         id = id_ace_file
         column = 0 or else column = co
      end

feature {INI_PARSER}

   ini_file(li, co: INTEGER) is
	 -- The position is in the configuration file.
      require
         li >= 1; co >= 1
      do
         eiffel_file(li,co,id_ini_file,Void)
      ensure
         line = li
         id = id_ini_file
         column = 0 or else column = co
      end

feature

   other_file(li, co: INTEGER; f: STRING) is
      require
         li >= 1; co >= 1
      do
         eiffel_file(li, co, id_other_file, Void)
         file := f
      ensure
         line = li
         id = id_other_file
         column = 0 or else column = co
         file = f
      end

   file: STRING

feature {C_PRETTY_PRINTER,E_AGENT}

   mangling: INTEGER_32
         -- In order to save memory (there are a lot of objects like `Current'),
         -- the `id' of the class, the `line' and the `column' are saved in this
         -- BIT sequence. Two mangling are used, and the `column' may be
         -- dropped (not memorized, see `set'). This implementation assume
         -- that `Integer_bits' is greater or equal to 32.
         -- The two manglings are:
         --  ---------------------------------------------------------------
         -- |      id (11)        |    line (13)            | col (7)     |0|
         --  ---------------------------------------------------------------
         -- |         id (15)             |       line (16)               |1|
         --  ---------------------------------------------------------------

feature {NONE}

   id: INTEGER_16 is
      do
         if mangling.bit_test(0) then
            Result := (mangling |>>> 17).low_16
         else
            Result := (mangling |>>> 21).low_16
         end
      ensure
         Result >= 0
            or else Result = id_ace_file
            or else Result = id_ini_file
      end

   get_line(file_path: STRING; li: INTEGER): STRING is
      require
         not file_path.is_empty
         li > 0
      local
         i: INTEGER
      do
         echo.tfr_connect(tmp_file_read,file_path)
         if tmp_file_read.is_connected then
            from until tmp_file_read.end_of_input or else i = li
            loop
               tmp_file_read.read_line
               i := i + 1
            end
            if not tmp_file_read.end_of_input then
               Result := tmp_file_read.last_string
            end
            tmp_file_read.disconnect
         end
      end

feature {POSITION_VISITOR}

   accept(visitor: POSITION_VISITOR) is
      do
         visitor.visit_position(Current)
      end

feature {ID_PROVIDER}

   id_ace_file:   INTEGER_16 is 32767
   id_ini_file:   INTEGER_16 is 32766
   id_other_file: INTEGER_16 is 32765

   maximum_free_id: INTEGER_16 is 32764

end -- POSITION
