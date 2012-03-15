class EXAMPLE1
-- This example demonstrates how to call Java class and instance 
-- methods from Eiffel code.
-- To try this example:
--
--                       compile_to_jvm example1
--                       java example1

creation make

feature

   make is
      local
         i: INTEGER; s: STRING; b: BOOLEAN
         java_string, java_string_bytes, hash_map, obj: POINTER
      do
	 -- get and print this object's Java hash code
         i := hashCode( Current.to_pointer )
         print( "hash code is: " )
         print( i.out )
         print( "%N" )
         
-- get and print this object's Java string value
         
         java_string := toString( Current.to_pointer )
         i := length( checkcast_java_lang_String( java_string ) )
         create s.make_filled( '%U', i )
         java_string_bytes := getBytes( checkcast_java_lang_String( java_string ) )
         arraycopy( java_string_bytes, 0, s.to_external, 0, i )
         print( "string value is: " )
         print( s )
         print( "%N" )

-- create hash map

         hash_map := new_java_util_HashMap
         
-- fill hash map with entries using a java.lang.String as key and Eiffel string as value

         s := "A" 
         java_string := new_java_lang_String( checkcast_aB( s.to_external ), 0, s.count )
         s := "Number_1"
         obj := put( checkcast_java_util_HashMap( hash_map ), java_string, s.to_pointer )
         
         s := "B" 
         java_string := new_java_lang_String( checkcast_aB( s.to_external ), 0, s.count )
         s := "Number_2"
         obj := put( checkcast_java_util_HashMap( hash_map ), java_string, s.to_pointer )
         
         s := "C" 
         java_string := new_java_lang_String( checkcast_aB( s.to_external ), 0, s.count )
         s := "Number_3"
         obj := put( checkcast_java_util_HashMap( hash_map ), java_string, s.to_pointer )

-- get size of hash map
         
         i := size( checkcast_java_util_HashMap( hash_map ) )
         print( "hashMap size is: " )
         print( i.out )
         print( "%N" )

-- retrieve hash map entry

         s := "B" 
         java_string := new_java_lang_String( checkcast_aB( s.to_external ), 0, s.count )
         b := containsKey( checkcast_java_util_HashMap( hash_map ), java_string )
         print( "is key " )
         print( s )
         print( " present in hashMap: " )
         print( b.out )
         print( "%N" )
         
         obj := get( checkcast_java_util_HashMap( hash_map ), java_string )
         s := checkcast_example1_string( obj )
         print( "string associated with key is: " )
         print( s )
         print( "%N" )

-- retrieve hash map entry using java.util.Map interface

         s := "C" 
         java_string := new_java_lang_String( checkcast_aB( s.to_external ), 0, s.count )
         obj := checkcast_java_util_Map( hash_map )
         b := containsKey_interface( checkcast_java_util_Map( hash_map ), java_string )
         print( "is key " )
         print( s )
         print( " present in hashMap: " )
         print( b.out )
         print( "%N" )
         
         obj := get_interface( checkcast_java_util_Map( hash_map ), java_string )
         s := checkcast_example1_string( obj )
         print( "string associated with key is: " )
         print( s )
         print( "%N" )

		end
         
feature -- externals

   hashCode( p: POINTER ): INTEGER is
		external "Java class java.lang.Object method int hashCode()"
		end

	toString( p: POINTER ): POINTER is
		external "Java class java.lang.Object method java.lang.String toString()"
		end

	length( p: POINTER ): INTEGER is
		external "Java class java.lang.String method int length()"
		end

	checkcast_java_lang_String( p: POINTER ): POINTER is
		external "Java class java.lang.String checkcast"
		end

	getBytes( p: POINTER ): POINTER is
		external "Java class java.lang.String method byte[] getBytes()"
		end

	arraycopy( a1: POINTER; a2: INTEGER; a3: POINTER; a4: INTEGER; a5: INTEGER ) is
		external "Java class java.lang.System method static void arraycopy(java.lang.Object,int,java.lang.Object,int,int)"
   	end

	new_java_lang_String( a1: POINTER; a2: INTEGER; a3: INTEGER ): POINTER is
		external "Java class java.lang.String new (byte[],int,int)"
		end

	new_java_util_HashMap: POINTER is
		external "Java class java.util.HashMap new ()"
		end

	checkcast_aB( p: POINTER ): POINTER is
		external "Java class byte[] checkcast"
		end

	put( p: POINTER; a1: POINTER; a2: POINTER ): POINTER is
		external "Java class java.util.HashMap method java.lang.Object put(java.lang.Object,java.lang.Object)"
		end

	checkcast_java_util_HashMap( p: POINTER ): POINTER is
		external "Java class java.util.HashMap checkcast"
		end

	size( p: POINTER ): INTEGER is
		external "Java class java.util.HashMap method int size()"
		end

	containsKey( p: POINTER; a1: POINTER ): BOOLEAN is
		external "Java class java.util.HashMap method boolean containsKey(java.lang.Object)"
		end

	get( p: POINTER; a1: POINTER ): POINTER is
		external "Java class java.util.HashMap method java.lang.Object get(java.lang.Object)"
		end

	checkcast_example1_string( p: POINTER ): STRING is
		external "Java class example1.string checkcast"
		end

	containsKey_interface( p: POINTER; a1: POINTER ): BOOLEAN is
		external "Java interface java.util.Map method boolean containsKey(java.lang.Object)"
		end

	get_interface( p: POINTER; a1: POINTER ): POINTER is
		external "Java interface java.util.Map method java.lang.Object get(java.lang.Object)"
		end

	checkcast_java_util_Map( p: POINTER ): POINTER is
		external "Java class java.util.Map checkcast"
		end

end -- class EXAMPLE1
