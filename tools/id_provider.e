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
class ID_PROVIDER
   --
   -- Unique object in charge of some id providing.
   --

inherit
   GLOBALS
   VISITABLE

creation make

feature {ID_PROVIDER_VISITOR}

   accept(visitor: ID_PROVIDER_VISITOR) is
      do
         visitor.visit_id_provider(Current)
      end

feature {SMART_EIFFEL}

   max_id: INTEGER_16
	 -- Last already assigned `id'. Maximum 15 bits (see POSITION), so
	 -- INTEGER_16 is ok (bit#16 is the sign)

feature {COMPILE_TO_C}

   disk_save is
      local
         i, id: INTEGER_16; tfw: TEXT_FILE_WRITE; str: STRING
      do
         create tfw.make
         echo.tfw_connect(tfw,system_tools.id_file_path)
         from
            i := 1
         until
            i > id_memory.count
         loop
            str := id_memory.key(i)
            id := id_memory.item(i)
            tfw.put_integer(id)
            tfw.put_character(' ')
            tfw.put_character('%"')
            tfw.put_string(str)
            tfw.put_character('%"')
            tfw.put_character(' ')
            smart_eiffel.id_extra_information(tfw,str)
            tfw.put_character('#')
            tfw.put_character('%N')
            i := i + 1
         end
         tfw.disconnect
      end

feature {PARSER, BASE_CLASS, RUN_CLASS, C_PRETTY_PRINTER}

   item(str: STRING): INTEGER_16 is
      require
         str = string_aliaser.item(str)
      local
         p: POSITION
      do
	 if id_memory.has(str) then
	    Result := id_memory.at(str)
         elseif max_id = p.maximum_free_id then
            error_handler.append(once "Too many live types (the maximum is ")
            error_handler.append_integer(p.maximum_free_id)
            error_handler.append(once "). Cannot go on: please send a mail at smarteiffel@loria.fr")
            error_handler.print_as_fatal_error
	 else
	    max_id := max_id + 1
	    Result := max_id
	    id_memory.add(Result,str)
	 end
      end

feature {POSITION}

   alias_of(id: INTEGER_16): STRING is
      do
         Result := id_memory.fast_key_at(id)
      end

feature {NONE}

   id_memory: HASHED_DICTIONARY[INTEGER_16,STRING] is
      once
         create Result.with_capacity(2048)
      end

   make is
      do
         id_memory.put(0,as_none)
         id_memory.put(1,as_integer_8)
         id_memory.put(2,as_integer)
         id_memory.put(2,as_integer_32)
         id_memory.put(3,as_character)
         id_memory.put(4,as_real)
         id_memory.put(4,as_real_32) -- Alias
         id_memory.put(5,as_double)
         id_memory.put(5,as_real_64) -- Alias
         id_memory.put(6,as_boolean)
         id_memory.put(7,as_string)
         id_memory.put(8,as_pointer)
         id_memory.put(9,as_native_array_character)
         id_memory.put(10,as_integer_16)
         id_memory.put(11,as_integer_64)
         max_id := 11
         if not smart_eiffel.no_id then
            disk_restore
         end
      end

   disk_restore is
      local
	 cc: CHARACTER; type_name: STRING; id, item_count: INTEGER_16
         tfr: TEXT_FILE_READ; state: INTEGER_8
	 predefined_ids: INTEGER
      do
	 predefined_ids := max_id
         !!tfr.make
         echo.tfr_connect(tfr,system_tools.id_file_path)
         if tfr.is_connected then
            from
	       if tfr.end_of_input then
		  state := 6
	       end
            until
	       state > 4
            loop
	       tfr.read_character
	       if tfr.end_of_input then
		  state := 5
	       else
		  cc := tfr.last_character
	       end
	       inspect
		  state
	       when 0 then -- Waiting first digit of `id'.
		  inspect
		     cc
		  when ' ', '%R', '%N', '%T' then
		  when '0' .. '9' then
		     id := cc.decimal_value
		     state := 1
		  else
		     state := 6
		  end
	       when 1 then -- Inside `id'.
		  inspect
		     cc
		  when '0' ..'9' then
		     id := id * 10 + cc.decimal_value
		  when '%"' then
		     type_name := temporary_type_name
		     type_name.clear_count
		     state := 3
		  when ' ', '%T' then
		     state := 2
		  else
		     state := 6
		  end
	       when 2 then -- Waiting opening ".
		  inspect
		     cc
		  when '%"' then
		     type_name := temporary_type_name
		     type_name.clear_count
		     state := 3
		  when ' ', '%T', '%N', '%R' then
		  else
		     state := 6
		  end
	       when 3 then -- Inside `type_name'.
		  inspect
		     cc
		  when '%"' then
		     item_count := item_count + 1
		     if id > predefined_ids then
			type_name := string_aliaser.item(type_name)
			id_memory.put(id, type_name)
			max_id := max_id.max(id)
		     end
		     state := 4
		  when '%N', '%R', '%T' then
		     state := 6
		  else
		     type_name.extend(cc)
		  end
	       when 4 then -- Waiting end of type ('#').
		  inspect
		     cc
		  when '#' then
		     state := 0
		  else
		  end
	       else
	       end
            end
            tfr.disconnect
	    if state = 6 then -- Error final state.
	       echo.put_string("Corrupted *.id file (after ")
	       echo.put_integer(item_count)
	       echo.put_string(" correct items).%N")
	    else
	       check
		  state = 5
	       end
	       -- Final success state.
	    end
            echo.put_string(once "Previous IDs reloaded (max_id = ")
            echo.put_integer(max_id)
            echo.put_string(once ").%N")
         end
      end

   temporary_type_name: STRING is
      once
	 create Result.make(128)
      end

end -- ID_PROVIDER
