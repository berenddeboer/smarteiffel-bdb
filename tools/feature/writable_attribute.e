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
class WRITABLE_ATTRIBUTE
   --
   -- For instance variables (ordinary attribute).
   --

inherit ATTRIBUTE

creation make, implicit

feature {WRITABLE_ATTRIBUTE_VISITOR}

   accept(visitor: WRITABLE_ATTRIBUTE_VISITOR) is
      do
         visitor.visit_writable_attribute(Current)
      end

feature

   to_run_feature(t: E_TYPE; fn: FEATURE_NAME): RUN_FEATURE_2 is
      do
         !!Result.make(t,fn,Current)
      end

feature {BASE_CLASS}

   is_item_of_integer: BOOLEAN is
	 -- To skip VDRD6 for INTEGER_*.item ...
      local
	 fn: FEATURE_NAME; cn: STRING
      do
	 fn := names.first
	 if fn.to_string = as_item then
	    cn := base_class.name.to_string
	    Result := (cn = as_integer_general
		       or else 
		       cn = as_integer_8
		       or else
		       cn = as_integer_16
		       or else
		       cn = as_integer_32
		       or else
		       cn = as_integer
		       or else
		       cn = as_integer_64)
	 end
      end

feature {NONE}

   make(n: like names; t: like result_type) is
      require
         n /= Void; t /= Void
      do
         make_e_feature(n)
         result_type := t
      ensure
         names = n
         result_type = t
      end

   implicit(bc: like base_class;  attribute_name: FEATURE_NAME
	    attribute_type: E_TYPE) is
	 -- Allow the creation of an implicit writable attribute
	 -- written in class `bc'. As an example, this routine is
	 -- used to create `first', `second', ... TUPLE implicit attributes.
      local
	 fnl: like names
      do
	 base_class := bc
	 !!fnl.make_1(attribute_name)
	 make(fnl,attribute_type)
	 clients := omitted_client_list
      end

   pretty_constant_value is do end

end -- WRITABLE_ATTRIBUTE
