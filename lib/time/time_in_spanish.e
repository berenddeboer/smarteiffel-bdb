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
expanded class TIME_IN_SPANISH
--
-- The Spanish format class for class TIME.
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
               s := once "Mie"
            when 4 then
               s := once "Jue"
            when 5 then
               s := once "Vie"
            when 6 then
               s := once "Sab"
            end
         else
            inspect
               time.week_day
            when 0 then
               s := once "Domingo"
            when 1 then
               s := once "Lunes"
            when 2 then
               s := once "Martes"
            when 3 then
               s := once "Miercoles"
            when 4 then
               s := once "Jueves"
            when 5 then
               s := once "Viernes"
            when 6 then
               s := once "Sabado"
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
               s := once "Ene"
            when 2 then
               s := once "Feb"
            when 3 then
               s := once "Mar"
            when 4 then
               s := once "Abr"
            when 5 then
               s := once "May"
            when 6 then
               s := once "Jun"
            when 7 then
               s := once "Jul"
            when 8 then
               s := once "Ago"
            when 9 then
               s := once "Sep"
            when 10 then
               s := once "Oct"
            when 11 then
               s := once "Nov"
            when 12 then
               s := once "Dic"
            end
         else
            inspect
               time.month
            when 1 then
               s := once "Enero"
            when 2 then
               s := once "Febrero"
            when 3 then
               s := once "Marzo"
            when 4 then
               s := once "Abril"
            when 5 then
               s := once "Mayo"
            when 6 then
               s := once "Junio"
            when 7 then
               s := once "Julio"
            when 8 then
               s := once "Agosto"
            when 9 then
               s := once "Septiembre"
            when 10 then
               s := once "Octubre"
            when 11 then
               s := once "Noviembre"
            when 12 then
               s := once "Diciembre"
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
