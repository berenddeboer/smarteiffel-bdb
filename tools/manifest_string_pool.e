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
class MANIFEST_STRING_POOL
   --
   -- Unique global object in charge of once manifest string used (i.e. once
   -- manifest string in live code).
   --

inherit
   GLOBALS
   VISITABLE
   STRING_HANDLER
   UNICODE_STRING_HANDLER

feature {MANIFEST_STRING_POOL_VISITOR}

   accept(visitor: MANIFEST_STRING_POOL_VISITOR) is
      do
         visitor.visit_manifest_string_pool(Current)
      end

feature {MANIFEST_STRING}

   once_register(ms: MANIFEST_STRING): STRING is
         -- To register a runnable once one. The selected "ms_XXX" global 
         -- name is returned to be memorized by the caller.
      require
         not smart_eiffel.is_ready
         ms.once_flag
      do
         from
	    header.copy(once "ms")
	    header.append(ms.alias_global)
         until
            not once_variables.has(header)
         loop
            header.extend('a')
         end
         Result := header.twin
         once_variables.add(ms, Result)
      end

   register(ms: MANIFEST_STRING) is
         -- Registration of `ms' and computation of possible `alias_link'. 
         -- The returned value is an id which can be used to mangle 
         -- generated code.
      require
         not smart_eiffel.is_ready
      local
         mangling: STRING; ms2: MANIFEST_STRING
      do
	 if ms.alias_global = Void then
	    ms2 := storage_alias.reference_at(ms)
	    check ms2 /= ms end
	    if ms2 = Void then
	       header.clear
	       ms.start_position.base_class.id.append_in(header)
	       header.extend('_')
	       ms.hash_code.append_in(header)
	       from until
		  not storage_mangling.has(header)
	       loop
		  header.extend('a')
	       end
	       mangling := header.twin
	       ms.set_alias_global(mangling)
	       storage_mangling.add(mangling)
	       storage_alias.put(ms, ms)
	    else
	       ms.storage_alias_of(ms2)
	    end
	 end
      end

   set_se_ums(rf: like se_ums) is
      require
	 rf /= Void
      do
	 se_ums := rf
      ensure
	 se_ums = rf
      end

   se_ms_c_call_in(buffer: STRING; ms: MANIFEST_STRING) is
      require
	 not ms.unicode_flag
      local
	 trace: BOOLEAN
      do
	 trace := manifest_string_trace(ms, buffer)
	 buffer.append(once "se_ms(")
	 ms.count.append_in(buffer)
	 buffer.extend(',')
	 if ms.alias_link = Void then
	    string_to_c_code(ms.to_string, buffer)
	 else
	    buffer.extend('s')
	    buffer.append(ms.alias_global)
	 end
	 buffer.extend(')')
	 if trace then buffer.extend(')') end
      end

   se_ums_c_call_in(buffer: STRING; ms: MANIFEST_STRING) is
      require
	 ms.unicode_flag
      local
	 trace: BOOLEAN; us: UNICODE_STRING; c: INTEGER
      do
	 trace := manifest_string_trace(ms, buffer)
	 us := ms.unicode_string
	 buffer.append(once "se_ums(")
	 if ace.no_check then
	    buffer.append(once "&ds,")
	 end
	 c := us.count
	 c.append_in(buffer)
	 buffer.extend(',')
	 if c = 0 then
	    buffer.append(fz_null)
	 else
	    buffer.extend('s')
	    buffer.append(ms.alias_global)
	 end
	 buffer.extend(',')
	 if us.low_surrogate_values = Void then
	    c := 0
	 else
	    c := us.low_surrogate_values.count
	 end
	 c.append_in(buffer)
	 buffer.extend(',')
	 if c /= 0 then
	    buffer.append(once "lsv")
	    buffer.append(ms.alias_global)
	    buffer.append(once ",lsi")
	    buffer.append(ms.alias_global)
	 else
	    buffer.append(once "NULL, NULL")
	 end
	 buffer.extend(')')
	 if trace then buffer.extend(')') end
      end

feature {SMART_EIFFEL}

   c_define1(string_at_run_time: BOOLEAN) is
      require
	 cpp.on_h
      local
	 i, j, upper: INTEGER; ms: MANIFEST_STRING; us: UNICODE_STRING
	 storage: NATIVE_ARRAY[INTEGER_16]
	 lsv: FIXED_ARRAY[INTEGER_16]; lsi: FIXED_ARRAY[INTEGER];
      do
         if not string_at_run_time then
            cpp.put_string(
               once "typedef struct S7 T7;%N%
               %struct S7{T9 _storage;T2 _count;T2 _capacity;};%N")
         end
	 cpp.swap_on_c
	 from
	    cpp.put_string(
            once "/*Aliased storage area or unicode storage.*/%N")
	    i := 1
	 until
	    i > storage_alias.count
	 loop
	    ms := storage_alias.item(i)
	    if ms.unicode_flag then
	       us := ms.unicode_string
	       upper := us.count
	       if upper > 0 then
		  header.copy(once "uint16_t s")
		  header.append(ms.alias_global)
		  cpp.put_extern3(header, upper)
		  upper := upper - 1		  
		  from
		     storage := us.storage
		     j := 0
		  until
		     j > upper
		  loop
		     cpp.put_integer(storage.item(j))
		     j := j + 1
		     if j <= upper then cpp.put_character(',') end
		  end
		  cpp.put_string(fz_a1)
	       end
	       lsv := us.low_surrogate_values
	       if lsv /= Void and then lsv.count > 0 then
		  from
		     header.copy(once "uint16_t lsv")
		     header.append(ms.alias_global)
		     cpp.put_extern3(header, upper)
		     j := 0
		  until
		     j > lsv.upper
		  loop
		     cpp.put_integer(lsv.item(j))
		     j := j + 1
		     if j <= lsv.upper then cpp.put_character(',') end
		  end
		  cpp.put_string(fz_a1)
	       end
	       lsi := us.low_surrogate_indexes
	       if lsi /= Void and then lsi.count > 0 then
		  from
		     header.copy(once "uint32_t lsi")
		     header.append(ms.alias_global)
		     cpp.put_extern3(header, upper)
		     j := 0
		  until
		     j > lsi.upper
		  loop
		     cpp.put_integer(lsi.item(j))
		     j := j + 1
		     if j <= lsi.upper then cpp.put_character(',') end
		  end
		  cpp.put_string(fz_a1)
	       end
	    elseif ms.alias_link /= Void then
	       header.copy(once "char*s")
	       header.append(ms.alias_global)
	       body.clear
	       string_to_c_code(ms.to_string, body)
	       cpp.put_extern5(header, body)
	    end
	    i := i + 1
	 end
	 cpp.swap_on_h
      ensure
	 cpp.on_h
      end

   c_define2(string_at_run_time: BOOLEAN) is
      require
         cpp.on_c
      local
         i, j, function_count, mdc, id: INTEGER; ms: MANIFEST_STRING
	 no_check: BOOLEAN; rc: RUN_CLASS
      do
	 no_check := ace.no_check
	 if not smart_eiffel.scoop then
	    mdc := once_variables.count
	    echo.print_count(once "Manifest String",mdc)
	    if mdc > 0 then
	       from -- For the *.h file:
		  i := 1
	       until
		  i > mdc
	       loop
		  ms := once_variables.item(i)
		  header.copy(once "T0*")
		  header.append(ms.once_variable)
		  cpp.put_extern1(header)
		  i := i + 1
	       end
	    end
	 end
	 --
         define_se_ms(string_at_run_time)
         --
	 if smart_eiffel.scoop then
	    cpp.put_c_function(once "void se_msi1()",
			       once "")
	 elseif mdc > 0 then
	    from -- For the *.c file:
	       i := 1
	       function_count := 1
	    until
	       function_count > 1 and then i > mdc
	    loop
	       header.copy(fz_void)
	       header.extend(' ')
	       header.append(fz_se_msi)
	       function_count.append_in(header)
	       header.append(fz_c_void_args)
	       from
		  body.clear
		  if no_check and then se_ums /= Void then
		     body.append(
	          "[
                   se_frame_descriptor fd={"<global-once>",0,0,"",1};
                   se_dump_stack ds;
                   ds.fd=&fd;
                   ds.p=0;
                   ds.caller=NULL;
                   ds.exception_origin=NULL;
                   ds.locals=NULL;

                   ]")
		  end
		  j := nb_ms_per_function
	       until
		  j = 0 or else i > mdc
	       loop
		  ms := once_variables.item(i)
		  body.append(ms.once_variable)
		  body.extend('=')
		  if ms.unicode_flag then
		     se_ums_c_call_in(body, ms)
		  else
		     se_ms_c_call_in(body, ms)
		  end
		  body.extend(';')
		  body.extend('%N')
		  j := j - 1
		  i := i + 1
	       end
	       function_count := function_count + 1
	       if i <= mdc then
		  body.append(fz_se_msi)
		  function_count.append_in(body)
		  body.append(fz_c_no_args_procedure)
	       end
	       cpp.next_bunch_size(3)
	       cpp.put_c_function(header,body)
	    end
   	 end
	 if se_ums /= Void then
	    rc := se_ums.current_type.run_class
	    id := rc.id
	    header.copy("T0*se_ums(")
	    if no_check then
	       header.append("se_dump_stack*caller,")
	    end
	    header.append("int32_t c,uint16_t*s,int32_t sc,int16_t*lsv,%
			  %int32_t*lsi)")
	    body.clear
	    body.extend('T')
	    id.append_in(body)
	    body.append("*us;%N")
	    if no_check then
	       body.append(
	       "[
                se_frame_descriptor fd={"<unicode-initialization>",0,0,"",1};
                se_dump_stack ds;
                ds.fd=&fd;
                ds.p=0;
                ds.caller=caller;

                ]")
	    end
	    gc_handler.allocation_in(once "us", body, rc)
	    body.extend('r')
	    id.append_in(body)
	    body.append("manifest_initialize(")
	    if no_check then
	       body.append("&ds,")
	    end
	    body.append("us,c,s,sc,lsv,lsi);return (T0*)us;%N")
	    cpp.put_c_function(header, body)
	 end
      ensure
         cpp.on_c
      end

feature {C_PRETTY_PRINTER, MANIFEST_STRING}

   string_to_c_code(s: STRING; c_code: STRING) is
      do
	 native_array_to_c_code(s.count, s.storage, c_code)
      end
   
feature {C_PRETTY_PRINTER}

   character_to_c_code(c: CHARACTER; c_code: STRING) is
      do
         if c = '%N' then
            c_code.extend('\')
            c_code.extend('n')
         elseif c = '\' then
            c_code.extend('\')
            c_code.extend('\')
         elseif c = '?' then
            c_code.extend('\')
            c_code.extend('?')
         elseif c = '%"' then
            c_code.extend('\')
            c_code.extend('%"')
         elseif c = '%'' then
            c_code.extend('\')
            c_code.extend('%'')
         elseif c.code < 32 or else 122 < c.code then
            c_code.extend('\')
            c.code.low_8.to_octal_in(c_code)
            c_code.append(once "%"%"")
	 else
            c_code.extend(c)
         end
      end

   c_call_initialize is
      require
         cpp.on_c
      do
         if once_variables.count > 0 then
            cpp.put_string(fz_se_msi)
            cpp.put_character('1')
            cpp.put_string(fz_c_no_args_procedure)
         end
      ensure
         cpp.on_c
      end

feature {GC_HANDLER}

   define_manifest_string_mark is
      local
         i, mdc, ms_count, function_count, id, us_id: INTEGER
	 ms: MANIFEST_STRING
      do
         mdc := once_variables.count
         function_count := 1
         define_manifest_string_mark_header(function_count)
         from
            i := 1
	    if se_ums /= void then
	       us_id := se_ums.current_type.run_class.id
	    end
         until
            i > mdc
         loop
            if ms_count > 300 then
               ms_count := 0
               function_count := function_count + 1
               cpp.put_string(fz_manifest_string_mark)
               cpp.put_integer(function_count)
               cpp.put_string(fz_c_no_args_procedure)
               cpp.put_string(fz_12)
               define_manifest_string_mark_header(function_count)
            end
            ms := once_variables.item(i)
	    cpp.put_string(fz_gc_mark)
	    if ms.unicode_flag then
	       id := us_id
	    else
	       id := 7
	    end
	    cpp.put_integer(id)
	    cpp.put_string(once "((T")
	    cpp.put_integer(id)
	    cpp.put_string(once "*)")
	    cpp.put_string(ms.once_variable)
	    cpp.put_string(fz_14)
	    ms_count := ms_count + 1
            i := i + 1
         end
         cpp.put_string(fz_12)
      end

feature {JVM}

   jvm_define_fields is
      local
         cp: like constant_pool; ms: MANIFEST_STRING
         name_idx, string_idx, i, mdc: INTEGER
      do
         mdc := once_variables.count
         if mdc > 0 then
            cp := constant_pool
            string_idx := cp.idx_eiffel_string_descriptor
            from
               i := 1
            until
               i > mdc
            loop
               ms := once_variables.item(i)
               name_idx := cp.idx_utf8(ms.once_variable)
               field_info.add(9,name_idx,string_idx)
               i := i + 1
            end
         end
      end

   jvm_initialize_fields is
      local
         cp: like constant_pool; ca: like code_attribute
         ms: MANIFEST_STRING; i, mdc: INTEGER
      do
         mdc := once_variables.count
         if mdc > 0 then
            cp := constant_pool
            ca := code_attribute
            from
               i := 1
            until
               i > mdc
            loop
               ms := once_variables.item(i)
               ca.opcode_push_manifest_string(ms.to_string)
               ca.opcode_putstatic(ms.fieldref_idx,-1)
               i := i + 1
            end
         end
      end

feature {NONE}

   once_variables: DICTIONARY[MANIFEST_STRING, STRING] is
	 -- To allocate different global variables names for each 
	 -- "once" manifest string.
      once
         create Result.with_capacity(4096)
      end

   storage_alias: DICTIONARY[MANIFEST_STRING, MANIFEST_STRING] is
	 -- For storage aliasing.
      once
         create Result.with_capacity(4096)
      end

   storage_mangling: SET[STRING] is
	 -- For storage mangling.
      once
         create Result.with_capacity(4096)
      end

   header: STRING is
	 -- Buffer for headers or temporary name computation.
      once
         create Result.make(64)
      end

   body: STRING is
	 -- Buffer for body of functions.
      once
         create Result.make(2048)
      end

   native_array_to_c_code(capacity: INTEGER
			  storage: NATIVE_ARRAY[CHARACTER]
			  c_code: STRING) is
      local
         break, i: INTEGER
      do
         c_code.extend('%"')
         from until
            i >= capacity
         loop
            character_to_c_code(storage.item(i),c_code)
            i := i + 1
	    break := break + 1
	    if break > 1024 then
	       -- Because of a limitation of the Visual C/C++
	       -- compiler which do not like too long lines:
	       c_code.append(once "%"%N%"")
	       break := 0
	    end
         end
         c_code.extend('%"')
      end

   define_se_ms(string_at_run_time: BOOLEAN) is
      do
         header.copy(once "T0*se_ms(int c,char*e)")
         body.copy(once "/* Allocate a Manifest STRING.*/%NT7*")
	 common_body_for_se_string_and_se_ms(string_at_run_time)
         --
         header.copy(once "T0*se_string(char*e)")
         body.copy(
            once "/* Allocate an Eiffel STRING by copying C char*e */%N%
		 %int c=strlen(e);%N%
		 %T7*")
	 common_body_for_se_string_and_se_ms(string_at_run_time)
	 --
	 if smart_eiffel.scoop then
	    cpp.put_c_function(once
    "T0* scoop_once_manifest_string(char* key, int count, char* value)",
			       once "{
    se_subsystem_t* self = se_current_subsystem_thread();
    T0* result = NULL;
    if (self->vft.is_set_once(self, key)) {
	result = self->vft.get_once(self, key);
    }
    else {
	result = se_ms(count, value);
	self->vft.set_once(self, key, result);
    }
    return result;

				     }")
         end
      end

   common_body_for_se_string_and_se_ms(string_at_run_time: BOOLEAN) is
      do
         gc_handler.new_manifest_string_in(body,string_at_run_time)
         body.append(once "s->_count=c;%N%
		     %s->_capacity=c+1;%N%
		     %s->_storage=((T9)")
         gc_handler.new_native9_in(body,string_at_run_time)
         body.append(once "(c+1));%N%
		     %memcpy(s->_storage,e,c+1);%N%
		     %return((T0*)s);")
         cpp.put_c_function(header,body)
      end

   define_manifest_string_mark_header(number: INTEGER) is
      do
         header.copy(fz_void)
         header.extend(' ')
         header.append(fz_manifest_string_mark)
         number.append_in(header)
         header.append(fz_c_void_args)
         cpp.put_c_heading(header)
      end

   fz_manifest_string_mark: STRING is "manifest_string_mark"

   fz_se_msi: STRING is "se_msi"

   nb_ms_per_function: INTEGER is 50

   manifest_string_trace(ms: MANIFEST_STRING; buffer: STRING): BOOLEAN is
      local
	 position: POSITION
      do
	 if ms.once_flag then
	 elseif ace.manifest_string_trace then
	    Result := True;
	    position := ms.start_position
	    buffer.append(once "%N(fprintf(SE_ERR,%"%%s\n%",")
	    string_to_c_code(ms.to_string, buffer)
	    buffer.append(
	       once "),%Nfprintf(SE_ERR,%"-manifest_string_trace: line ")
	    position.line.append_in(buffer)
	    buffer.append(once " column ")
	    position.column.append_in(buffer)
	    buffer.extend(' ')
	    buffer.append(position.path)
	    buffer.append(once "\n%"),%N")
	 end
      end

   se_ums: RUN_FEATURE
	 -- Non Void when `{UNICODE_STRING}.se_ums' is used.

end -- MANIFEST_STRING_POOL
