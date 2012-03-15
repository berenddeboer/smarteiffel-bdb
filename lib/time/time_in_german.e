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
expanded class TIME_IN_GERMAN
--
-- The German format class for class TIME.
--

inherit TIME_IN_SOME_LANGUAGE

feature

   day_in(buffer: STRING) is
      local
         s: STRING
      do
         if short_mode then
            inspect
               time.week_day
            when 0 then
               s := once "So"
            when 1 then
               s := once "Mo"
            when 2 then
               s := once "Di"
            when 3 then
               s := once "Mi"
            when 4 then
               s := once "Do"
            when 5 then
               s := once "Fr"
            when 6 then
               s := once "Sa"
            end
         else
            inspect
               time.week_day
            when 0 then
               s := once "Sonntag"
            when 1 then
               s := once "Montag"
            when 2 then
               s := once "Dienstag"
            when 3 then
               s := once "Mittwoch"
            when 4 then
               s := once "Donnerstag"
            when 5 then
               s := once "Freitag"
            when 6 then
               s := once "Samstag"
            end
         end
         buffer.append(s)
      end

   month_in(buffer: STRING) is
      local
         s: STRING
      do
         if short_mode then
            inspect
               time.month
            when 1 then
               s := once "Jan"
            when 2 then
               s := once "Feb"
            when 3 then
               s := once "M�r"
            when 4 then
               s := once "Apr"
            when 5 then
               s := once "Mai"
            when 6 then
               s := once "Jun"
            when 7 then
               s := once "Jul"
            when 8 then
               s := once "Aug"
            when 9 then
               s := once "Sep"
            when 10 then
               s := once "Okt"
            when 11 then
               s := once "Nov"
            when 12 then
               s := once "Dez"
            end
         else
            inspect
               time.month
            when 1 then
               s := once "Januar"
            when 2 then
               s := once "Februar"
            when 3 then
               s := once "M�rz"
            when 4 then
               s := once "April"
            when 5 then
               s := once "Mai"
            when 6 then
               s := once "Juni"
            when 7 then
               s := once "Juli"
            when 8 then
               s := once "August"
            when 9 then
               s := once "September"
            when 10 then
               s := once "Oktober"
            when 11 then
               s := once "November"
            when 12 then
               s := once "Dezember"
            end
         end
         buffer.append(s)
      end

   append_in(buffer: STRING) is
      local
         tmp: STRING
      do
         day_in(buffer)
         buffer.extend(',')
         buffer.extend(' ')
         tmp := time.day.to_string
         if 2 > tmp.count then
            tmp.insert_character('0',1)
         end
         buffer.append_string(tmp)
         buffer.append_character('.')
         buffer.append_character(' ')
         month_in(buffer)
         buffer.append_character(' ')
         if short_mode then
            tmp := (time.year \\ 100).to_string
            if 2 > tmp.count then
               tmp.insert_character('0',1)
            end
            buffer.append_string(tmp)
         else
            time.year.append_in(buffer)
         end
         buffer.extend(' ')
         tmp := time.hour.to_string
         if 2 > tmp.count then
            tmp.insert_character('0',1)
         end
         buffer.append_string(tmp)
         buffer.append_character(':')
         tmp := time.minute.to_string
         if 2 > tmp.count then
            tmp.insert_character('0',1)
         end
         buffer.append_string(tmp)
         buffer.append_character(':')
         if not short_mode then
            tmp := time.second.to_string
            if 2 > tmp.count then
               tmp.insert_character('0',1)
            end
            buffer.append_string(tmp)
         end
      end

end
