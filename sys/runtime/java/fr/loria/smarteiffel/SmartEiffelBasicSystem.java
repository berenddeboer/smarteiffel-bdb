/*
  -- This file is  free  software, which  comes  along  with  SmartEiffel. This
  -- software  is  distributed  in the hope that it will be useful, but WITHOUT
  -- ANY  WARRANTY;  without  even  the  implied warranty of MERCHANTABILITY or
  -- FITNESS  FOR A PARTICULAR PURPOSE. You can modify it as you want, provided
  -- this header is kept unaltered, and a notification of the changes is added.
  -- You  are  allowed  to  redistribute  it and sell it, alone or as a part of
  -- another product.
  --          Copyright (C) 1994-98 LORIA - UHP - CRIN - INRIA - FRANCE
  --            Dominique COLNET and Suzanne COLLIN - colnet@loria.fr
  --                       http://SmartEiffel.loria.fr
  --
*/

package fr.loria.smarteiffel;

import java.io.*;
import java.util.*;
import java.lang.*;

public class SmartEiffelBasicSystem {

    public static int basic_system_execute_command (Object system_command_line) {
	String scl = SmartEiffelRuntime.NullTerminatedBytesToString(system_command_line);
	Process process;
	try {
	    process = Runtime.getRuntime().exec(scl);
	    process.waitFor();
	}
	catch (Exception e) {
	    System.err.print("SmartEiffelRuntime: basic_system_execute_command(\"");
	    System.err.print(scl);
	    System.err.println("\") failed.");
	    SmartEiffelRuntime.print_run_time_stack();
	    System.err.println("Try to continue execution.");
	}
	return 0;
    }
}
