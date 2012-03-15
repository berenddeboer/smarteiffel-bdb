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
deferred class FILE
   --
   -- Common parent class to all the FILE-type streams. Provides a common
   -- connection interface to the "real" files of the operating system.
   --
feature

   is_connected: BOOLEAN is
         -- Is this file connected to some file of the operating system?
      deferred
      end

   connect_to(new_path: STRING) is
         -- Try to connect to an existing file of the operating system.
      require
         not is_connected
         not new_path.is_empty
      deferred
      end

   disconnect is
         -- Disconnect from any file.
      require
         is_connected
      deferred
      ensure
         not is_connected
      end

end
