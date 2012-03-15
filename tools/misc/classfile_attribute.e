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
class CLASSFILE_ATTRIBUTE
   --
   -- Unique Global Object in charge of the classfile attribute of
   -- a class as described in the JVM specification.
   -- Obviously, the same object is recycled.
   --
inherit
   GLOBALS
   VISITABLE

creation make

feature {CLASSFILE_ATTRIBUTE_VISITOR}

   accept(visitor: CLASSFILE_ATTRIBUTE_VISITOR) is
      do
         visitor.visit_classfile_attribute(Current)
      end

feature {JVM}

   idx_sourcefile: INTEGER
   idx_classfile: INTEGER

   is_set: BOOLEAN
   
   clear is
      do
         is_set := False
         idx_sourcefile := -1
         idx_classfile := -1
      end

   set(name: STRING) is
      local
         i: INTEGER; s: STRING
      do
         idx_sourcefile := constant_pool.idx_utf8(once "SourceFile")
         create s.make(64)
         from
            i := name.lower
         until
            i > name.upper or else name.item(i) = '['
         loop
            s.extend(name.item(i))
            i := i + 1
         end
         s.append(once ".e ")
         idx_classfile := constant_pool.idx_utf8(s)
         is_set := True
      end

   write_bytes is
      do
         if is_set = False or ace.boost = True then
            jvm.b_put_u2( 0 )
         else
            jvm.b_put_u2( 1 )
            jvm.b_put_u2( idx_sourcefile )
            jvm.b_put_u2( 0 )
            jvm.b_put_u2( 2 )
            jvm.b_put_u2( idx_classfile )
         end
      end

feature {NONE}

   make is
      do
      end

end -- CLASSFILE_ATTRIBUTE

