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

public class SmartEiffelBasicDirectory {

    static class DirectoryStream {
	/* To simulate a BASIC_DIRECTORY stream. */
	File directory;
	String[] list;
	int index;

	public DirectoryStream read_entry() {
	    if (++index < list.length) {
		return this;
	    }
	    else {
		return null;
	    }
	}

	public Object get_entry_name() {
	    String entry;
	    if (index == -2) {
		entry = ".";
	    }
	    else if (index == -1) {
		entry = "..";
	    }
	    else {
		entry = list[index];
	    }
	    return SmartEiffelRuntime.StringToNullTerminatedBytes(entry);
	}
    }

    public static Object basic_directory_open(Object path_pointer) {
	String path = new String((byte[])path_pointer);
	File directory = new File(path);
	if (directory.isDirectory()) {
	    DirectoryStream dirstream = new DirectoryStream();
	    dirstream.directory = directory;
	    dirstream.list = directory.list();
	    dirstream.index = -3;
	    return dirstream;
	}
	else {
	    return null;
	}
    }

    public static Object basic_directory_read_entry(Object dirstream_pointer) {
	DirectoryStream dirstream = ((DirectoryStream)dirstream_pointer);
	return dirstream.read_entry();
    }

    public static Object basic_directory_get_entry_name(Object dirstream_pointer) {
	DirectoryStream dirstream = ((DirectoryStream)dirstream_pointer);
	return dirstream.get_entry_name();
    }

    public static boolean basic_directory_close(Object stream) {
	return true;
    }

    public static Object basic_directory_current_working_directory() {
	String cwd = System.getProperty("user.dir");
	return SmartEiffelRuntime.StringToNullTerminatedBytes(cwd);
    }

    public static boolean basic_directory_chdir(Object dirpath_pointer) {
	String path = new String((byte[])dirpath_pointer);
	File directory = new File(path);
	if (directory.isDirectory()) {
	    Properties p = System.getProperties();
	    p.put("user.dir",path);
	    return true;
	}
	else {
	    return false;
	}
    }

    public static boolean basic_directory_mkdir(Object dirpath_pointer) {
	String name = SmartEiffelRuntime.NullTerminatedBytesToString(dirpath_pointer);
	File directory = new File(name);
	directory.mkdir();
	return true;
    }

    public static boolean basic_directory_rmdir(Object dirpath_pointer) {
	String name = SmartEiffelRuntime.NullTerminatedBytesToString(dirpath_pointer);
	File directory = new File(name);
	directory.delete();
	return true;
    }
}
