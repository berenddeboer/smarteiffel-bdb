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

public class SmartEiffelBasicSprintf {

    public static void basic_sprintf_double (byte buffer[], int f, double d) {
	String s = Double.toString(d);
	int ib = 0; int is = 0;	int iE;	int idot; int exp; int i;

	if (s.charAt(is) == '-') {
	    buffer[ib++] = '-';
	    s = s.substring(1,s.length());
	}
	iE = s.indexOf('E');
	idot = s.indexOf('.');
	if (iE < 0) {
	    /* ddd.ddd notation. */
	    for (; is < idot ; is++) {
		buffer[ib++] = ((byte)(s.charAt(is)));
	    }
	    if (f > 0) {
		buffer[ib++] = '.';
		is++;
	    }
	    for (; ((f > 0) && (is < s.length())) ; f--) {
		buffer[ib++] = ((byte)(s.charAt(is++)));
	    }
	    for (; f > 0 ; f--) {
		buffer[ib++] = '0';
	    }
	    buffer[ib] = 0;
	}
	else {
	    /* m.ddddE-xx notation. */
	    exp = Integer.parseInt(s.substring(iE+1,s.length()));
	    if (exp >= 0) {
		for (; is < idot ; is++) {
		    buffer[ib++] = ((byte)(s.charAt(is)));
		}
		is++;
		for (; exp > 0 ; exp--) {
		    if (is < iE) {
			buffer[ib++] = ((byte)(s.charAt(is++)));
		    }
		    else {
			buffer[ib++] = '0';
		    }
		}
		if (f > 0) {
		    buffer[ib++] = '.';
		}
		for (; f > 0 ; f--) {
		    if (is < iE) {
			buffer[ib++] = ((byte)(s.charAt(is++)));
		    }
		    else {
			buffer[ib++] = '0';
		    }
		}
		buffer[ib] = 0;
	    }
	    else {
		i = idot + exp;
		if (i <= 0) {
		    buffer[ib++] = '0';
		}
		else {
		    for (; is < i ; is++) {
			buffer[ib++] = ((byte)(s.charAt(is++)));
		    }
		}
		if (f > 0) {
		    buffer[ib++] = '.';
		}
		for (; f > 0 ; f--) {
		    if (i < 0) {
			buffer[ib++] = '0';
			i++;
		    }
		    else if (is < iE) {
			if (is == idot) is++;
			buffer[ib++] = ((byte)(s.charAt(is++)));
		    }
		    else {
			buffer[ib++] = '0';
		    }
		}
		buffer[ib] = 0;
	    }
	}
    }
}
