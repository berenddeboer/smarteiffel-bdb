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

public class SmartEiffelBasicPutenv {

    public static void basic_putenv (Object name, Object value) {
	String name_string = SmartEiffelRuntime.NullTerminatedBytesToString(name);
	String value_string = SmartEiffelRuntime.NullTerminatedBytesToString(value);
	Properties props = System.getProperties();
	props.put(name_string,value_string);
	System.setProperties(props);
	return;
    }
}
