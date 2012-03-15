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
expanded class TIME_IN_ENGLISH
--
-- The English format class for class TIME.
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
               s := once "Su"
            when 1 then
               s := once "Mo"
            when 2 then
               s := once "Tu"
            when 3 then
               s := once "We"
            when 4 then
               s := once "Th"
            when 5 then
               s := once "Fr"
            when 6 then
               s := once "Sa"
            end
         else
            inspect
               time.week_day
            when 0 then
               s := once "Sunday"
            when 1 then
               s := once "Monday"
            when 2 then
               s := once "Tuesday"
            when 3 then
               s := once "Wednesday"
            when 4 then
               s := once "Thursday"
            when 5 then
               s := once "Friday"
            when 6 then
               s := once "Saturday"
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
               s := once "Mar"
            when 4 then
               s := once "Apr"
            when 5 then
               s := once "May"
            when 6 then
               s := once "Jun"
            when 7 then
               s := once "Jul"
            when 8 then
               s := once "Aug"
            when 9 then
               s := once "Sep"
            when 10 then
               s := once "Oct"
            when 11 then
               s := once "Nov"
            when 12 then
               s := once "Dec"
            end
         else
            inspect
               time.month
            when 1 then
               s := once "January"
            when 2 then
               s := once "February"
            when 3 then
               s := once "March"
            when 4 then
               s := once "April"
            when 5 then
               s := once "May"
            when 6 then
               s := once "June"
            when 7 then
               s := once "July"
            when 8 then
               s := once "August"
            when 9 then
               s := once "September"
            when 10 then
               s := once "October"
            when 11 then
               s := once "November"
            when 12 then
               s := once "December"
            end
         end
         buffer.append(s)
      end

   append_in(buffer: STRING) is
      do
         day_in(buffer)
         buffer.extend(' ')
         month_in(buffer)
         buffer.extend(' ')
         time.day.append_in(buffer)
         buffer.extend(' ')
         time.hour.append_in(buffer)
         buffer.extend(':')
         time.minute.append_in(buffer)
         if not short_mode then
            buffer.extend(':')
            time.second.append_in(buffer)
         end
         buffer.extend(' ')
         time.year.append_in(buffer)
      end

end
