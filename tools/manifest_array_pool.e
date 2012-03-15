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
class MANIFEST_ARRAY_POOL
   --
   -- Unique global object in charge of MANIFEST_ARRAY used.
   --

inherit
   GLOBALS
   VISITABLE

feature {MANIFEST_ARRAY_POOL_VISITOR}

   accept(visitor: MANIFEST_ARRAY_POOL_VISITOR) is
      do
         visitor.visit_manifest_array_pool(Current)
      end

feature {NONE}

   manifest_array_types: DICTIONARY[E_TYPE,INTEGER] is
         -- Gives the type for all kind of used MANIFEST_ARRAY.
      once
         !!Result.make
      end

   as_se_ma: STRING is "se_ma"

feature {MANIFEST_ARRAY,E_STRIP}

   register(ma_type: E_TYPE) is
      require
         ma_type /= Void
      local
         id: INTEGER
      do
         id := ma_type.id
         if not manifest_array_types.has(id) then
            manifest_array_types.put(ma_type,id)
         end
      end

   c_call(ma_type: E_TYPE) is
      require
         smart_eiffel.is_ready
      local
         id: INTEGER
      do
         id := ma_type.id
         cpp.put_string(as_se_ma)
         cpp.put_integer(id)
      end

feature {SMART_EIFFEL}

   c_define is
      require
         smart_eiffel.is_ready
      local
         i: INTEGER
      do
         from
            i := 1
         until
            i > manifest_array_types.count
         loop
            c_define_for(manifest_array_types.item(i))
            i := i + 1
         end
      end

feature {NONE}

   c_define_for(ma_type: E_TYPE) is
      local
         ma_id, elt_id: INTEGER
         elt_type: E_TYPE
         rf: RUN_FEATURE
	 type_bit: TYPE_BIT
      do
         ma_id := ma_type.id
         elt_type := ma_type.generic_list.item(1).run_type
         elt_id := elt_type.id
         -- Prepare header :
         header.copy(fz_void)
         header.extend('*')
         header.append(as_se_ma)
         ma_id.append_in(header)
         header.append(once "(int argc,...)")
         -- Prepare body :
         body.clear
         body.extend('T')
         ma_id.append_in(body)
         body.append(once "*m;%N%
                     %va_list pa;%N")
         if elt_type.is_reference then
            body.append(fz_t0_star)
         else
            body.extend('T')
            elt_id.append_in(body)
         end
         body.append(once "*s;%N%
                     %m=")
         if gc_handler.is_off then
            body.append(
               once "se_malloc(sizeof(*m));%N%
               %*m=M")
            ma_id.append_in(body)
            body.append(
               once ";%N%
               %if(argc){%N%
               %s=se_malloc(argc*sizeof(*s));%N")
         else
            body.append(fz_new)
            ma_id.append_in(body)
            body.append(
               once "();%N%
               %if(argc){%N%
               %s=((void*)new")
            rf := ma_type.run_class.get_feature_with(as_storage)
            rf.result_type.id.append_in(body)
            body.append(once "(argc));%N")
         end
         body.append(
           once "m->_storage=s;%N%
           %m->_capacity=argc;%N%
           %m->_lower=1;%N%
           %m->_upper=argc;%N%
           %va_start(pa,argc);%N%
           %while(argc--){%N")

	 type_bit ?= elt_type
	 body.append(once "*(s++)=")
	 if elt_type.is_user_expanded then
	    body.extend('*')
	 end
	 body.append(once "va_arg(pa,")
	 if elt_type.is_reference then
	    body.append(fz_t0_star)
	 elseif elt_type.is_real then --C va_list use size of double for float.
	    body.append(once "double")
	 elseif elt_type.id = 1 or else elt_type.id = 10  -- INTEGER_8 & 16
	    or else elt_type.is_boolean or else elt_type.is_character
	    or else (type_bit /= Void and then type_bit.nb <= Character_bits)
	  then
	    -- C promotes small types to int.
	    body.append(once "int")
	 else
	    body.extend('T')
	    elt_id.append_in(body)
	    if elt_type.is_user_expanded then
	       body.extend('*')
	    end
	 end
	 body.append(once ");%N")

         body.append(once "}%N%
                     %va_end(pa);%N}%N%
                     %else{%N%
                     %m->_storage=NULL;%N%
                     %m->_capacity=0;%N%
                     %m->_lower=1;%N%
                     %m->_upper=0;%N%
                     %}%N%
                     %return m;%N")
         --
         cpp.put_c_function(header,body)
      end

feature {NONE}

   header: STRING is
      once
         !!Result.make(64)
      end

   body: STRING is
      once
         !!Result.make(1024)
      end

end -- MANIFEST_ARRAY_POOL

