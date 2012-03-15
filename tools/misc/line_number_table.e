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
class LINE_NUMBER_TABLE
   --
   -- Unique Global Object in charge of the line number table and
   -- the local variable table attributes of
   -- a method_info as described in the JVM specification.
   -- Obviously, the same object is recycled.
   --
inherit
   GLOBALS
   VISITABLE

creation {GLOBALS} make

feature {LINE_NUMBER_TABLE_VISITOR}

   accept(visitor: LINE_NUMBER_TABLE_VISITOR) is
      do
         visitor.visit_line_number_table(Current)
      end

feature {NONE}

   start_pc: FIXED_ARRAY[INTEGER] is
      once
         !!Result.with_capacity(4)
      end

   line_number: FIXED_ARRAY[INTEGER] is
      once
         !!Result.with_capacity(4)
      end

feature {NONE}

   make is
      do
         create filename.make(128)
         create descriptor.make(128)
      end

   idx_sourcefile: INTEGER
   idx_localattribute_length: INTEGER

   idx_line_number_table: INTEGER
   
   idx_filename: INTEGER
   filename: STRING
   descriptor: STRING
   
feature {CODE_ATTRIBUTE}

   count: INTEGER is
      do
         Result := start_pc.count
      end

   length: INTEGER is
      local
         arguments_count: INTEGER
         local_vars_count: INTEGER
      do
         if count = 0 or ace.boost = True then
            Result := 0
         else
            if jvm.current_frame.arguments /= Void then
               arguments_count := jvm.current_frame.arguments.count
            end
            
            if jvm.current_frame.local_vars /= Void then
               local_vars_count := jvm.current_frame.local_vars.count
            end

            Result := 2 + 8 + ( 6 + 4*count ) + ( 6 + 2 + 10*( arguments_count + local_vars_count ) )
         end
      
      end
   
feature {CODE_ATTRIBUTE,COMPOUND}

   clear is
      do
         start_pc.clear
         line_number.clear
         idx_line_number_table := -1
         idx_filename := -1
         filename.clear
      end

   add( a_start_pc: INTEGER; a_position: POSITION) is
      do
         start_pc.add_last(a_start_pc)
         line_number.add_last(a_position.line)
         idx_line_number_table := constant_pool.idx_utf8( "LineNumberTable" )
         filename.clear
         filename.append( a_position.base_class_name.to_string )
         filename.append( ".e" )
         idx_filename := constant_pool.idx_utf8( filename )
      end

   store_in(storage: STRING) is
      local
         i: INTEGER
         idx: INTEGER
         offset: INTEGER
         arguments_count: INTEGER
         local_vars_count: INTEGER
      do
         if count = 0 or ace.boost = True then
            append_u2( storage, 0 )
         else
            append_u2(storage, 3)

-- source file 

            idx_sourcefile := constant_pool.idx_utf8( "SourceFile" )
            append_u2( storage, idx_sourcefile )
            append_u2( storage, 0 )
            append_u2( storage, 2 )
            append_u2( storage, idx_filename )

-- line numbers

            append_u2(storage, idx_line_number_table)
            append_u4( storage, 2 + 4*count )
            append_u2( storage, count )
            from
               i := 0
            until
               i >= start_pc.count
            loop
               append_u2(storage,start_pc.item(i))
               append_u2(storage,line_number.item(i))
               i := i + 1
            end

            if jvm.current_frame.arguments /= Void then
               arguments_count := jvm.current_frame.arguments.count
            end
            
            if jvm.current_frame.local_vars /= Void then
               local_vars_count := jvm.current_frame.local_vars.count
            end
            
            idx_localattribute_length := constant_pool.idx_utf8( "LocalVariableTable" )
            append_u2( storage, idx_localattribute_length )
            append_u4( storage, 2 + 10*( arguments_count + local_vars_count ) )
            append_u2( storage, arguments_count + local_vars_count )

-- argument and local variable names and descriptors
           
            from
               i := 1
            until
               i > arguments_count
            loop
               append_u2(storage, 0)
               append_u2(storage, code_attribute.program_counter)
               idx := constant_pool.idx_utf8( jvm.current_frame.arguments.name(i).to_string )
               append_u2(storage, idx)
               descriptor.clear
               if jvm.current_frame.arguments.name(i).result_type.is_basic_eiffel_expanded or
                     jvm.current_frame.arguments.name(i).result_type.base_class.is_deferred then
                  jvm.current_frame.arguments.name(i).result_type.jvm_descriptor_in( descriptor )
               else
                  descriptor.append_character( 'L' )
                  descriptor.append( jvm.current_frame.arguments.name(i).result_type.run_class.fully_qualified_name )
                  descriptor.append_character( ';' )
               end
               idx := constant_pool.idx_utf8( descriptor )
               append_u2(storage, idx)
               offset := jvm.argument_offset_of( jvm.current_frame.arguments.name(i) )
               append_u2(storage, offset)
               i := i + 1
            end

            from
               i := 1
            until
               i > local_vars_count
            loop
               append_u2(storage, 0)
               append_u2(storage, code_attribute.program_counter)
               idx := constant_pool.idx_utf8( jvm.current_frame.local_vars.name(i).to_string )
               append_u2(storage, idx)
               descriptor.clear
               if jvm.current_frame.local_vars.name(i).result_type.is_basic_eiffel_expanded or
                     jvm.current_frame.local_vars.name(i).result_type.base_class.is_deferred then
                  jvm.current_frame.local_vars.name(i).result_type.jvm_descriptor_in( descriptor )
               else
                  descriptor.append_character( 'L' )
                  descriptor.append( jvm.current_frame.local_vars.name(i).result_type.run_class.fully_qualified_name )
                  descriptor.append_character( ';' )
               end
               idx := constant_pool.idx_utf8( descriptor )
               append_u2(storage, idx)
               offset := jvm.local_offset_of( jvm.current_frame.local_vars.name(i) )
               append_u2(storage, offset)
               i := i + 1
            end

         end
      end

end -- LINE_NUMBER_TABLE

