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
class CLASS_NAME
   --
   -- To store the base class name of a class.
   --

inherit
   NAME
      redefine
         is_equal
      end
   HASHABLE
      redefine
         is_equal
      end

creation make, unknown_position

feature {CLASS_NAME_VISITOR}

   accept(visitor: CLASS_NAME_VISITOR) is
      do
         visitor.visit_class_name(Current)
      end

feature

   start_position: POSITION
	 -- Of the first character.

   to_string: STRING
	 -- The name itself.

   hash_code: INTEGER
	 -- A memory cache for `to_string.hash_code'.

   is_subclass_of(other: CLASS_NAME): BOOLEAN is
      require
         to_string /= other.to_string
      local
	 other_base_class: BASE_CLASS
      do
         if as_none = to_string then
            Result := True
         elseif as_any = other.to_string then
            Result := True
         elseif as_none = other.to_string then
         else
	    other_base_class := other.base_class_memory
	    if other_base_class = Void then
	       other_base_class := smart_eiffel.loaded_base_class(other)
	       if other_base_class /= Void then
		  other.set_base_class_memory(other_base_class)
	       end
	    end
	    if other_base_class /= Void then
	       Result := base_class.is_subclass_of(other_base_class)
	    end
         end
      end

   predefined: BOOLEAN is
         -- All following classes are handled in a special way
         -- by the TYPE_* corresponding class.
      do
         Result := (as_any = to_string or else
                    as_array = to_string or else
                    as_boolean = to_string or else
                    as_character = to_string or else
                    as_double = to_string or else
                    as_integer_8 = to_string or else
                    as_integer_16 = to_string or else
                    as_integer_32 = to_string or else
                    as_integer = to_string or else
                    as_integer_64 = to_string or else
                    as_none = to_string or else
                    as_pointer = to_string or else
                    as_real = to_string or else
                    as_real_32 = to_string or else
                    as_real_64 = to_string or else
                    as_string = to_string)
      end

   base_class: BASE_CLASS is
	 -- The corresponding one unique instance. 
      do
	 if base_class_memory = Void then
	    base_class_memory := smart_eiffel.base_class(Current)
	 end
	 Result := base_class_memory
      end

   is_a(other: like Current): BOOLEAN is
      require
         other /= Void
         error_handler.is_empty
      local
         to_string2: STRING; bc1, bc2: like base_class
      do
         to_string2 := other.to_string
         if as_any = to_string2 then
            Result := True
         elseif to_string = to_string2 then
            Result := True
         elseif as_none = to_string2 then
         else
            bc1 := base_class
            bc2 := other.base_class
            if bc1 = Void then
               error_handler.append("Unable to load ")
               error_handler.append(to_string)
               error(start_position,fz_dot_blank)
            elseif bc2 = Void then
               error_handler.append("Unable to load ")
               error_handler.append(to_string2)
               error(start_position,fz_dot_blank)
            else
               Result := bc1.is_subclass_of(bc2)
            end
         end
      end

   pretty_print is
      do
         pretty_printer.put_string(to_string)
      end

   is_equal(other: like Current): BOOLEAN is
      do
	 Result := to_string = other.to_string
      end

feature {EIFFEL_PARSER}

   set_accurate_position(sp: like start_position) is
      do
         start_position := sp
      ensure
         start_position = sp
      end

feature {CLASS_NAME}

   base_class_memory: BASE_CLASS
	 -- To cache `base_class' function Result.

   set_base_class_memory(bcm: like base_class_memory) is
      require
	 bcm /= Void; base_class_memory = Void
      do
	 base_class_memory := bcm
      ensure
	 base_class_memory = bcm
      end

feature

   make(n: STRING; sp: like start_position) is
      require
         n = string_aliaser.item(n)
      do
         to_string := n
	 hash_code := to_string.hash_code
         start_position := sp
      ensure
         start_position = sp
         to_string = n
      end

   unknown_position(n: STRING) is
      require
         n = string_aliaser.item(n)
      do
         to_string := n
	 hash_code := to_string.hash_code
      ensure
         to_string = n
      end

invariant

   to_string = string_aliaser.item(to_string)

   hash_code = to_string.hash_code

   eiffel_parser.case_insensitive
      implies
         to_string.is_equal(to_string.as_upper)
   
end -- CLASS_NAME
