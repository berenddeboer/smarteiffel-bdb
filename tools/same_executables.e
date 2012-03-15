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
class SAME_EXECUTABLES
--
-- Check if two files given as arguments are (quite) the same
-- executables files.
-- Terminate execution with the corresponding exit status code.
--
inherit
   GLOBALS
   VISITABLE

creation make

feature {SAME_EXECUTABLES_VISITOR}

   accept(visitor: SAME_EXECUTABLES_VISITOR) is
      do
         visitor.visit_same_executables(Current)
      end

feature {NONE}

   msg1, msg2: TEXT_FILE_READ

feature

   make is
      local
         path1, path2: STRING
      do
         if argument_count < 2 then
            io.put_string("usage: same_files <path1> <path2>%N")
            die_with_code(exit_failure_code)
         end
         path1 := argument(1)
         path2 := argument(2)
         exists(path1)
         exists(path2)
         if same_executables(path1,path2) then
            io.put_string(once "Sames files.%N")
         else
            io.put_string("Files differ.%N")
            die_with_code(exit_failure_code)
         end
      end

feature {NONE}

   same_executables(path1,path2: STRING): BOOLEAN is
      local
         f1, f2: TEXT_FILE_READ
         diff_count: INTEGER
         stop: BOOLEAN
      do
         from
            !!f1.connect_to(path1)
            if f1.is_connected then
               if not f1.end_of_input then
                  f1.read_character
               end
            end
            !!f2.connect_to(path2)
            if f2.is_connected then
               if not f2.end_of_input then
                  f2.read_character
               end
            end
            diff_count := 4
         until
            stop
         loop
            if f1.end_of_input then
               if f2.end_of_input then
                  stop := true
                  Result := true
               else
                  stop := true
                  Result := false
               end
            elseif f2.end_of_input then
               stop := true
               Result := false
            else
               if f1.last_character /= f2.last_character then
                  diff_count := diff_count - 1
                  if diff_count = 0 then
                     stop := true
                     Result := false
                  end
               end
               f1.read_character
               f2.read_character
            end
         end
         f1.disconnect
         f2.disconnect
      end

   exists(path: STRING) is
      do
         if not file_exists(path) then
            io.put_string("File : %"")
            io.put_string(path)
            io.put_string("%" not found.%N")
            die_with_code(exit_failure_code)
         end
      end

end -- SAME_EXECUTABLES

