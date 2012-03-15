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

public class SmartEiffelBasicMicrosecond {

    public static long last_millis;

    public static void basic_microsecond_update() {
	last_millis = System.currentTimeMillis();
	return;
    }

    public static double basic_microsecond_time() {
	return Double.longBitsToDouble( last_millis );
    }

    public static int basic_microsecond_microsecond() {
	return (int) ( last_millis % 1000 )*1000;
    }
}
