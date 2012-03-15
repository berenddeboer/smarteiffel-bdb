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
expanded class SYSTEM
--
-- This expanded class allow to execute system command
-- and to get/set environment variables.
--

inherit ANY redefine get_environment_variable end

feature

   get_environment_variable(variable: STRING): STRING is
         -- Try to get the value of the system environment `variable' or some
         -- `variable' in the system registry. Gives Void when no information
         -- about the `variable' is available. Under UNIX like system, this 
         -- is in fact the good way to know about some system environment 
         -- variable.
	 -- Under Windows, this function also look in the system registery.
      require
         variable /= Void
      local
         p, null: POINTER
      do
         p := variable.to_external
	 p := basic_getenv(p)
	 if p /= null then
	    !!Result.from_external_copy(p)
	 end
      end

   set_environment_variable(variable, value: STRING) is
         -- Try to assign the system environment `variable' with `value'.
      require
         variable /= Void
	 value /= Void
      do
	 basic_putenv(variable.to_external,value.to_external)
      end

   execute_command(system_command_line: STRING): INTEGER is
         -- To execute a `system_command_line' as for example, "ls -l" on UNIX.
         -- The `Result' depends of the actual operating system. As an exemple,
         -- this `execute' feature is under UNIX the equivalent of a `system' call.
      require
	 system_command_line /= Void
      local
         p: POINTER
      do
         p := system_command_line.to_external
         Result := basic_system_execute_command(p)
      end

   execute_command_line(system_command_line: STRING) is
	 -- The equivalent of `execute_command' without `Result'.
      do
	 if execute_command(system_command_line) = 0 then end
      end

feature {NONE}

   basic_getenv(environment_variable: POINTER): POINTER is
         -- To implement `get_environment_variable'.
      external "SmartEiffel"
      end

   basic_putenv(variable, value: POINTER) is
         -- To implement `set_environment_variable'.
      external "SmartEiffel"
      end

   basic_system_execute_command(system_command_line: POINTER): INTEGER is
      external "SmartEiffel"
      end

end -- SYSTEM
