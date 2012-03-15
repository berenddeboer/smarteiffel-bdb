-- This  file  is  free software,  which comes along with SmartEiffel.  This
-- software is distributed in the hope that it will be useful,  but  WITHOUT
-- ANY  WARRANTY;  without  even the  implied warranty of MERCHANTABILITY or
-- FITNESS FOR A PARTICULAR PURPOSE. You can modify it as you want, provided
-- this header is kept unaltered, and a notification of the changes is added.
-- You  are  allowed  to  redistribute it and sell it, alone or as a part of
-- another product.
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
expanded class POINTER
--
-- References to objects meant to be exchanged with non-Eiffel software.
--
-- Note : An Eiffel POINTER is mapped as C type "void *" or as
-- Java "java.lang.Object" type.
--

inherit
   HASHABLE
      export {NONE} copy
      redefine
         out_in_tagged_out_memory, fill_tagged_out_memory
      end
   STRING_HANDLER
      export {NONE} copy
      end
   
feature

   is_null: BOOLEAN is
         -- Is the external POINTER a NULL pointer ?
      do
         Result := not is_not_null
      end

   is_not_null: BOOLEAN is
         -- Is the external POINTER a non-NULL pointer ?
      external "SmartEiffel"
      end

   to_string: STRING is
      do
	 string_buffer.clear
	 Current.append_in(string_buffer)
	 Result := string_buffer.twin
      end

   append_in(buffer: STRING) is
         -- Append on `str' a viewable version of `Current'.
      local
	 storage: NATIVE_ARRAY[CHARACTER]; i: INTEGER
      do
         from
	    storage := string_buffer.storage
	    basic_sprintf_pointer(storage, Current)
            i := 0
         until
            storage.item(i) = '%U'
         loop
            buffer.extend(storage.item(i))
            i := i + 1
         end
      end

   out_in_tagged_out_memory, fill_tagged_out_memory is
      do
         Current.append_in(tagged_out_memory)
      end

   hash_code: INTEGER is
      do
	 Result := basic_pointer_hash_code(Current)
      end

   infix "+" (offset: INTEGER): POINTER is
	 -- `Current' moved by an offset of `offset' bytes.
      do
	 Result := basic_pointer_plus(Current,offset)
      end

   to_any: ANY is
         -- Dangerous forced conversion. This function assume that `Current' 
         -- is really a reference to some Eiffel allocated object.
      do
         Result := basic_pointer_to_any(Current)
      end

feature -- For compatibility with the obsolete INTEGER_REF style:
   
   item: POINTER
   
   set_item(value: like item) is
      do
	 item := value
      ensure
	 item = value
      end

feature {NONE}

   basic_sprintf_pointer(native_array: NATIVE_ARRAY[CHARACTER];p: POINTER) is
      external "SmartEiffel"
      end

   basic_pointer_hash_code(p: POINTER): INTEGER is
      external "SmartEiffel"
      end

   basic_pointer_to_any(p: POINTER): ANY is
         -- Dangerous forced conversion. This function assume that `p' is
         -- really a reference to some Eiffel allocated object.
      external "SmartEiffel"
      end

   basic_pointer_plus(p: POINTER; offset: INTEGER): POINTER is
	 -- Pointer `p' moved by an offset of `offset' bytes.
      external "SmartEiffel"
      end
   
   string_buffer: STRING is
      once
	 create Result.make(64)
      end

end -- POINTER
