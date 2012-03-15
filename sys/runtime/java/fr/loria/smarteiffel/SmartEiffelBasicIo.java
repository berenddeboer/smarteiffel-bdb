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

public class SmartEiffelBasicIo {

    public static Object basic_io_stdin() {
	return System.in;
    }

    public static Object basic_io_stdout() {
	return System.out;
    }

    public static Object basic_io_stderr() {
	return System.err;
    }

    public static int basic_io_eof() {
	return -1;
    }

    public static Object basic_io_binary_file_read_open (Object bytes) {
	String name = SmartEiffelRuntime.NullTerminatedBytesToString(bytes);
	File file = new File(name);
	try {
	    return new FileInputStream (file);
	} catch (FileNotFoundException e) {
	    return null;
	}
    }

    public static Object basic_io_binary_file_write_open (Object bytes) {
	String name = SmartEiffelRuntime.NullTerminatedBytesToString(bytes);
	File file = new File(name);
	try {
	    return new FileOutputStream (file);
	} catch (IOException e) {
	    return null;
	}
    }

    public static Object basic_io_binary_file_write_append (Object bytes) {
	String name = SmartEiffelRuntime.NullTerminatedBytesToString(bytes);
	try {
	    return new FileOutputStream (name, true);
	} catch (IOException e) {
	    return null;
	}
    }

    public static Object basic_io_text_file_read_open (Object bytes) {
	String name = SmartEiffelRuntime.NullTerminatedBytesToString(bytes);
	File file = new File(name);
	try {
	    return new FileInputStream (file);
	} catch (FileNotFoundException e) {
	    return null;
	}
    }

    public static Object basic_io_text_file_write_open (Object bytes) {
	String name = SmartEiffelRuntime.NullTerminatedBytesToString(bytes);
	File file = new File(name);
	try {
	    return new FileOutputStream (file);
	} catch (IOException e) {
	    return null;
	}
    }

    public static Object basic_io_text_file_write_append (Object bytes) {
	String name = SmartEiffelRuntime.NullTerminatedBytesToString(bytes);
	try {
	    return new FileOutputStream (name, true);
	} catch (IOException e) {
	    return null;
	}
    }

    public static Object basic_io_text_file_read_write_open (Object bytes) {
	String name = SmartEiffelRuntime.NullTerminatedBytesToString(bytes);
	RandomAccessFile rfile;
        try {
            rfile = new RandomAccessFile(name, "rw");
        } catch (IOException e) {
            return null;
        }
	return rfile;
    }

    public static Object basic_io_text_file_read_write_append (Object bytes) {
	String name = SmartEiffelRuntime.NullTerminatedBytesToString(bytes);
	RandomAccessFile rfile;
	try {
            rfile = new RandomAccessFile(name, "rw");
	} catch (IOException e) {
	    return null;
	}
	try {
	    long len = rfile.length();
	    rfile.seek( len );
	} catch (IOException e) {
	}
	return rfile;
    }

    public static boolean basic_io_feof (Object stream) {
	boolean result;
	result = false;
	try {
	    long fpointer = ((RandomAccessFile)stream).getFilePointer();
	    long len =  ((RandomAccessFile)stream).length();
	    if ( fpointer == len ) {
		result = true;
	    }
	} catch (IOException e) {
	}
	return result;
    }

    public static void basic_io_rename (Object old_path, Object new_path) {
	String oldPath = SmartEiffelRuntime.NullTerminatedBytesToString(old_path);
	String newPath = SmartEiffelRuntime.NullTerminatedBytesToString(new_path);
	File oldFile = new File(oldPath);
	File newFile = new File(newPath);
	oldFile.renameTo(newFile);
    }

    public static void basic_io_remove (Object path) {
	String name = SmartEiffelRuntime.NullTerminatedBytesToString(path);
	File file = new File(name);
	file.delete();
    }

    public static void basic_io_fclose (Object stream) {
	try { ((InputStream)stream).close(); return ; }
	catch (Exception e) {
	    try {((OutputStream)stream).close(); return ; }
	    catch (Exception f) {
	    }
	}
    }

    public static int basic_io_getc (Object stream) {
	try {
	    return ((InputStream)stream).read();
	} catch (IOException e) {
	    return -1;
	} catch (ClassCastException cce) {
	    try {
		return ((RandomAccessFile)stream).read();
	    } catch (IOException e) {
		return -1;
	    }
	}
    }

    public static void basic_io_putc (byte b, Object stream) {
	try {
	    ((OutputStream)stream).write(b);
	} catch (IOException e) {
	} catch (ClassCastException cce) {
	    try {
		((RandomAccessFile)stream).write(b);
	    } catch (IOException e) {
	    }
	}
    }

    public static void basic_io_flush(Object dirstream_pointer) {
	try {
	    ((PrintStream)dirstream_pointer).flush();
	} catch (ClassCastException cce) {
	}
    }

    public static int basic_io_read_stdin (byte[] bytes, int max_count) {
	try {
	    return (System.in).read(bytes,0,max_count);
	} catch (IOException e) {
	    return -1;
	}
    }

    public static int basic_io_fread (byte[] bytes, int max_count, Object stream) {
	try {
	    return ((InputStream)stream).read(bytes, 0, max_count);
	} catch (IOException e) {
	    return -1;
	} catch (ClassCastException cce) {
	    try {
		return ((RandomAccessFile)stream).read(bytes, 0, max_count);
	    } catch (IOException e) {
		return -1;
	    }
	}
    }

    public static void basic_io_fwrite (byte[] bytes, int count, Object stream) {
	try {
	    ((OutputStream)stream).write(bytes,0,count);
	} catch (IOException e) {
	} catch (ClassCastException cce) {
	    try {
		((RandomAccessFile)stream).write(bytes,0,count);
	    } catch (IOException e) {
	    }
	}
    }
}
