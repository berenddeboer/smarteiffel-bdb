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
expanded class TIME_IN_ITALIAN
--
-- The Italian format class for class TIME.
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
               s := once "Dom"
            when 1 then
               s := once "Lun"
            when 2 then
               s := once "Mar"
            when 3 then
               s := once "Mer"
            when 4 then
               s := once "Gio"
            when 5 then
               s := once "Ven"
            when 6 then
               s := once "Sab"
            end
         else
            inspect
               time.week_day
            when 0 then
               s := once "Domenica"
            when 1 then
               s := once "Lunedi"
            when 2 then
               s := once "Martedi"
            when 3 then
               s := once "Mercoledi"
            when 4 then
               s := once "Giovedi"
            when 5 then
               s := once "Venerdi"
            when 6 then
               s := once "Sabato"
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
               s := once "Gen"
            when 2 then
               s := once "Feb"
            when 3 then
               s := once "Mar"
            when 4 then
               s := once "Apr"
            when 5 then
               s := once "Mag"
            when 6 then
               s := once "Giu"
            when 7 then
               s := once "Lug"
            when 8 then
               s := once "Ago"
            when 9 then
               s := once "Set"
            when 10 then
               s := once "Ott"
            when 11 then
               s := once "Nov"
            when 12 then
               s := once "Dic"
            end
         else
            inspect
               time.month
            when 1 then
               s := once "Gennaio"
            when 2 then
               s := once "Febbraio"
            when 3 then
               s := once "Marzo"
            when 4 then
               s := once "Aprile"
            when 5 then
               s := once "Maggio"
            when 6 then
               s := once "Giugno"
            when 7 then
               s := once "Luglio"
            when 8 then
               s := once "Agosto"
            when 9 then
               s := once "Settembre"
            when 10 then
               s := once "Ottobre"
            when 11 then
               s := once "Novembre"
            when 12 then
               s := once "Dicembre"
            end
         end
         buffer.append(s)
      end

   append_in(buffer: STRING) is
      do
         day_in(buffer)
         buffer.extend(' ')
         time.day.append_in(buffer)
         buffer.extend(' ')
         month_in(buffer)
         buffer.extend(' ')
         time.year.append_in(buffer)
         buffer.extend(' ')
         time.hour.append_in(buffer)
         buffer.extend(':')
         time.minute.append_in(buffer)
         if not short_mode then
            buffer.extend(':')
            time.second.append_in(buffer)
         end
      end

end
