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

public class SmartEiffelBasicTime {

    public static double basic_time_time() {
	return Double.longBitsToDouble( System.currentTimeMillis() );
    }

    public static int basic_time_difftime( double t2, double t1 ) {
	return (int) ( ( Double.doubleToLongBits( t2 ) - Double.doubleToLongBits( t1) )/1000 );
    }

    public static int basic_time_getyear( double t, int mode ) {
	java.util.Date aDate = new java.util.Date( Double.doubleToLongBits( t ) );
	java.util.Calendar aCalendar = java.util.Calendar.getInstance();
	aCalendar.setTime( aDate );
	if ( mode == 1 ) {
	    java.util.TimeZone zone = java.util.TimeZone.getTimeZone( "GMT" );
	    aCalendar.setTimeZone( zone );
	}
	return aCalendar.get( java.util.Calendar.YEAR );
    }

    public static int basic_time_getmonth( double t, int mode ) {
	java.util.Date aDate = new java.util.Date( Double.doubleToLongBits( t ) );
	java.util.Calendar aCalendar = java.util.Calendar.getInstance();
	aCalendar.setTime( aDate );
	if ( mode == 1 ) {
	    java.util.TimeZone zone = java.util.TimeZone.getTimeZone( "GMT" );
	    aCalendar.setTimeZone( zone );
	}
	return ( aCalendar.get( java.util.Calendar.MONTH ) + 1 );
    }

    public static int basic_time_getday( double t, int mode ) {
	java.util.Date aDate = new java.util.Date( Double.doubleToLongBits( t ) );
	java.util.Calendar aCalendar = java.util.Calendar.getInstance();
	aCalendar.setTime( aDate );
	if ( mode == 1 ) {
	    java.util.TimeZone zone = java.util.TimeZone.getTimeZone( "GMT" );
	    aCalendar.setTimeZone( zone );
	}
	return aCalendar.get( java.util.Calendar.DAY_OF_MONTH );
    }

    public static int basic_time_gethour( double t, int mode ) {
	java.util.Date aDate = new java.util.Date( Double.doubleToLongBits( t ) );
	java.util.Calendar aCalendar = java.util.Calendar.getInstance();
	aCalendar.setTime( aDate );
	if ( mode == 1 ) {
	    java.util.TimeZone zone = java.util.TimeZone.getTimeZone( "GMT" );
	    aCalendar.setTimeZone( zone );
	}
	return aCalendar.get( java.util.Calendar.HOUR );
    }

    public static int basic_time_getminute( double t, int mode ) {
	java.util.Date aDate = new java.util.Date( Double.doubleToLongBits( t ) );
	java.util.Calendar aCalendar = java.util.Calendar.getInstance();
	aCalendar.setTime( aDate );
	if ( mode == 1 ) {
	    java.util.TimeZone zone = java.util.TimeZone.getTimeZone( "GMT" );
	    aCalendar.setTimeZone( zone );
	}
	return aCalendar.get( java.util.Calendar.MINUTE );
    }

    public static int basic_time_getsecond( double t, int mode ) {
	java.util.Date aDate = new java.util.Date( Double.doubleToLongBits( t ) );
	java.util.Calendar aCalendar = java.util.Calendar.getInstance();
	aCalendar.setTime( aDate );
	if ( mode == 1 ) {
	    java.util.TimeZone zone = java.util.TimeZone.getTimeZone( "GMT" );
	    aCalendar.setTimeZone( zone );
	}
	return aCalendar.get( java.util.Calendar.SECOND );
    }

    public static boolean basic_time_is_summer_time_used( double t ) {
	java.util.Date aDate = new java.util.Date( Double.doubleToLongBits( t ) );
	java.util.TimeZone zone = java.util.TimeZone.getDefault();
	return zone.inDaylightTime( aDate );
    }

    public static int basic_time_getyday( double t, int mode ) {
	java.util.Date aDate = new java.util.Date( Double.doubleToLongBits( t ) );
	java.util.Calendar aCalendar = java.util.Calendar.getInstance();
	aCalendar.setTime( aDate );
	if ( mode == 1 ) {
	    java.util.TimeZone zone = java.util.TimeZone.getTimeZone( "GMT" );
	    aCalendar.setTimeZone( zone );
	}
	return aCalendar.get( java.util.Calendar.DAY_OF_YEAR );
    }

    public static int basic_time_getwday( double t, int mode ) {
	java.util.Date aDate = new java.util.Date( Double.doubleToLongBits( t ) );
	java.util.Calendar aCalendar = java.util.Calendar.getInstance();
	aCalendar.setTime( aDate );
	if ( mode == 1 ) {
	    java.util.TimeZone zone = java.util.TimeZone.getTimeZone( "GMT" );
	    aCalendar.setTimeZone( zone );
	}
      return ( aCalendar.get( java.util.Calendar.DAY_OF_WEEK ) - 1 );
    }

    public static double basic_time_mktime( int a_year, int a_mon, int a_day,
					    int a_hour, int a_min, int a_sec ) {
	java.util.Calendar aCalendar = java.util.Calendar.getInstance();
	aCalendar.set( a_year, (a_mon - 1), a_day, a_hour, a_min, a_sec );
	return Double.longBitsToDouble( aCalendar.getTime().getTime() );
    }

    public static double basic_time_add_second( double t2, double t1 ) {
      return Double.longBitsToDouble( Double.doubleToLongBits( t2 ) - Double.doubleToLongBits( t1) );
    }
}
