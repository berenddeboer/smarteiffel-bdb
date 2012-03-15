class EXAMPLE3

-- Compilation: 
--    compile_to_jvm example3

-- Execution:
--    java example3

-- This example demonstrates how to use Java arrays from Eiffel.

creation
   make

feature 

   make is
      do
         boolean_array
         byte_array
         char_array
         short_array
         int_array
         long_array
         float_array
         double_array
         java_lang_String_array
      end
      
feature

   boolean_array is
      local
         a: POINTER
         i: INTEGER
         length: INTEGER
         z: BOOLEAN
      do
         
-- create an array of booleans         
         
         a := new_aZ( 5 )

-- fill the array

         length := arraylength_aZ( checkcast_aZ(a) )
         
         from
            i := 0
         until
            i >= length
         loop
            put_aZ( checkcast_aZ(a), i, i.even )
            i := i + 1
         end
         
-- read the array

         length := arraylength_aZ( checkcast_aZ(a) )
         
         print( "array of booleans: " )
         from
            i := 0
         until
            i >= length
         loop
            z := item_aZ( checkcast_aZ(a), i )
            print( z.out )
            print( " " )
            i := i + 1
         end
         print( "%N" )

      end
   
   byte_array is
      local
         a: POINTER
         i: INTEGER
         length: INTEGER
         b: INTEGER_8
      do
         
-- create an array of bytes
         
         a := new_aB( 5 )

-- fill the array

         length := arraylength_aB( checkcast_aB(a) )
         
         from
            i := 0
         until
            i >= length
         loop
            put_aB( checkcast_aB(a), i, i.to_integer_8 )
            i := i + 1
         end
         
-- read the array

         length := arraylength_aB( checkcast_aB(a) )
         
         print( "array of bytes: " )
         from
            i := 0
         until
            i >= length
         loop
            b := item_aB( checkcast_aB(a), i )
            print( b.out )
            print( " " )
            i := i + 1
         end
         print( "%N" )

      end
            
   char_array is
         -- note that Java characters are 16 bits long and are
         -- not equivalent to Eiffel characters
         -- Eiffel integers are used to hold Java characters
      local
         a: POINTER
         i: INTEGER
         length: INTEGER
         c: INTEGER
         s: STRING
         javaString: POINTER
      do
         
-- create an array of chars
         
         a := new_aC( 5 )

-- fill the array

         s := "Meyer" 
         javaString := new_java_lang_String( checkcast_aB( s.to_external ), 0, s.count )

         length := arraylength_aC( checkcast_aC(a) )
         
         from
            i := 0
         until
            i >= length
         loop
            c := charAt( checkcast_java_lang_String(javaString), i )
            put_aC( checkcast_aC(a), i, c )
            i := i + 1
         end
         
-- read the array

         length := arraylength_aC( checkcast_aC(a) )
         
         print( "array of chars: " )
         from
            i := 0
         until
            i >= length
         loop
            c := item_aC( checkcast_aC(a), i )
            print( c.out )
            print( " " )
            i := i + 1
         end
         print( "%N" )

      end
            
   short_array is
      local
         a: POINTER
         i: INTEGER
         length: INTEGER
         s: INTEGER_16
      do
         
-- create an array of shorts
         
         a := new_aS( 5 )

-- fill the array

         length := arraylength_aS( checkcast_aS(a) )
         
         from
            i := 0
         until
            i >= length
         loop
            put_aS( checkcast_aS(a), i, i.to_integer_16 )
            i := i + 1
         end
         
-- read the array

         length := arraylength_aS( checkcast_aS(a) )
         
         print( "array of shorts: " )
         from
            i := 0
         until
            i >= length
         loop
            s := item_aS( checkcast_aS(a), i )
            print( s.out )
            print( " " )
            i := i + 1
         end
         print( "%N" )

      end
            
   int_array is
      local
         a: POINTER
         i: INTEGER
         length: INTEGER
         i1: INTEGER
      do
         
-- create an array of ints
         
         a := new_aI( 5 )

-- fill the array

         length := arraylength_aI( checkcast_aI(a) )
         
         from
            i := 0
         until
            i >= length
         loop
            put_aI( checkcast_aI(a), i, i )
            i := i + 1
         end
         
-- read the array

         length := arraylength_aI( checkcast_aI(a) )
         
         print( "array of ints: " )
         from
            i := 0
         until
            i >= length
         loop
            i1 := item_aI( checkcast_aI(a), i )
            print( i1.out )
            print( " " )
            i := i + 1
         end
         print( "%N" )

      end
            
   long_array is
      local
         a: POINTER
         i: INTEGER
         length: INTEGER
         j: INTEGER_64
      do
         
-- create an array of longs
         
         a := new_aJ( 5 )

-- fill the array

         length := arraylength_aJ( checkcast_aJ(a) )
         
         from
            i := 0
         until
            i >= length
         loop
            put_aJ( checkcast_aJ(a), i, i.to_integer_64 )
            i := i + 1
         end
         
-- read the array

         length := arraylength_aJ( checkcast_aJ(a) )
         
         print( "array of longs: " )
         from
            i := 0
         until
            i >= length
         loop
            j := item_aJ( checkcast_aJ(a), i )
            print( j.out )
            print( " " )
            i := i + 1
         end
         print( "%N" )

      end
            
   float_array is
      local
         a: POINTER
         i: INTEGER
         length: INTEGER
         f: REAL
      do
         
-- create an array of floats
         
         a := new_aF( 5 )

-- fill the array

         length := arraylength_aF( checkcast_aF(a) )
         
         from
            i := 0
         until
            i >= length
         loop
            put_aF( checkcast_aF(a), i, i*1.0 )
            i := i + 1
         end
         
-- read the array

         length := arraylength_aF( checkcast_aF(a) )
         
         print( "array of floats: " )
         from
            i := 0
         until
            i >= length
         loop
            f := item_aF( checkcast_aF(a), i )
            print( f.out )
            print( " " )
            i := i + 1
         end
         print( "%N" )

      end
            
   double_array is
      local
         a: POINTER
         i: INTEGER
         length: INTEGER
         d: DOUBLE
      do
         
-- create an array of doubles
         
         a := new_aD( 5 )

-- fill the array

         length := arraylength_aD( checkcast_aD(a) )
         
         from
            i := 0
         until
            i >= length
         loop
            put_aD( checkcast_aD(a), i, i*1.0 )
            i := i + 1
         end
         
-- read the array

         length := arraylength_aD( checkcast_aD(a) )
         
         print( "array of doubles: " )
         from
            i := 0
         until
            i >= length
         loop
            d := item_aD( checkcast_aD(a), i )
            print( d.out )
            print( " " )
            i := i + 1
         end
         print( "%N" )

      end
            
   java_lang_String_array is
      local
         a: POINTER
         i: INTEGER
         length: INTEGER
         s: STRING
         javaString: POINTER
         javaStringBytes: POINTER
         string_length: INTEGER
      do
         
-- create an array of java.lang.Strings
         
         a := new_a_java_lang_String( 5 )

-- fill the array


         length := arraylength_a_java_lang_String( checkcast_a_java_lang_String(a) )
         
         from
            i := 0
         until
            i >= length
         loop
            create s.make( 3 )
            s.append( "<" )
            s.append( i.out )
            s.append( ">" )
            javaString := new_java_lang_String( checkcast_aB( s.to_external ), 0, s.count )
            put_a_java_lang_String( checkcast_a_java_lang_String(a), i, checkcast_java_lang_String(javaString) )
            i := i + 1
         end
         
-- read the array

         length := arraylength_a_java_lang_String( checkcast_a_java_lang_String(a) )
         
         print( "array of strings: " )
         from
            i := 0
         until
            i >= length
         loop
            javaString := item_a_java_lang_String( checkcast_a_java_lang_String(a), i )
            string_length := length_java_lang_String( checkcast_java_lang_String( javaString ) )
            create s.make_filled( '%U', string_length )
            javaStringBytes := getBytes( checkcast_java_lang_String( javaString ) )
            arraycopy( javaStringBytes, 0, s.to_external, 0, string_length )
            print( s.out )
            print( " " )
            i := i + 1
         end
         print( "%N" )

      end
            
feature -- externals

-- boolean

	new_aZ( a_length: INTEGER ): POINTER is
		external "Java array boolean new"
		end

	checkcast_aZ( p: POINTER ): POINTER is
		external "Java class boolean[] checkcast"
		end

	arraylength_aZ( p: POINTER ): INTEGER is
		external "Java array boolean length"
		end

	put_aZ( p: POINTER; i: INTEGER; a: BOOLEAN ) is
		external "Java array boolean set"
		end

	item_aZ( p: POINTER; i: INTEGER ): BOOLEAN is
		external "Java array boolean get"
		end

-- byte

	new_aB( a_length: INTEGER ): POINTER is
		external "Java array byte new"
		end

	checkcast_aB( p: POINTER ): POINTER is
		external "Java class byte[] checkcast"
		end

	arraylength_aB( p: POINTER ): INTEGER is
		external "Java array byte length"
		end

	put_aB( p: POINTER; i: INTEGER; a: INTEGER_8 ) is
		external "Java array byte set"
		end

	item_aB( p: POINTER; i: INTEGER ): INTEGER_8 is
		external "Java array byte get"
		end

-- char

	new_aC( a_length: INTEGER ): POINTER is
		external "Java array char new"
		end

	checkcast_aC( p: POINTER ): POINTER is
		external "Java class char[] checkcast"
		end

	arraylength_aC( p: POINTER ): INTEGER is
		external "Java array char length"
		end

	put_aC( p: POINTER; i: INTEGER; a: INTEGER ) is
		external "Java array char set"
		end

	item_aC( p: POINTER; i: INTEGER ): INTEGER is
		external "Java array char get"
		end

	new_java_lang_String( a1: POINTER; a2: INTEGER; a3: INTEGER ): POINTER is
		external "Java class java.lang.String new (byte[],int,int)"
		end

	checkcast_java_lang_String( p: POINTER ): POINTER is
		external "Java class java.lang.String checkcast"
		end

	charAt( p: POINTER; a1: INTEGER ): INTEGER is
		external "Java class java.lang.String method char charAt(int)"
		end

-- short

	new_aS( a_length: INTEGER ): POINTER is
		external "Java array short new"
		end

	checkcast_aS( p: POINTER ): POINTER is
		external "Java class short[] checkcast"
		end

	arraylength_aS( p: POINTER ): INTEGER is
		external "Java array short length"
		end

	put_aS( p: POINTER; i: INTEGER; a: INTEGER_16 ) is
		external "Java array short set"
		end

	item_aS( p: POINTER; i: INTEGER ): INTEGER_16 is
		external "Java array short get"
		end

-- int

	new_aI( a_length: INTEGER ): POINTER is
		external "Java array int new"
		end

	checkcast_aI( p: POINTER ): POINTER is
		external "Java class int[] checkcast"
		end

	arraylength_aI( p: POINTER ): INTEGER is
		external "Java array int length"
		end

	put_aI( p: POINTER; i: INTEGER; a: INTEGER ) is
		external "Java array int set"
		end

	item_aI( p: POINTER; i: INTEGER ): INTEGER is
		external "Java array int get"
		end

-- long

	new_aJ( a_length: INTEGER ): POINTER is
		external "Java array long new"
		end

	checkcast_aJ( p: POINTER ): POINTER is
		external "Java class long[] checkcast"
		end

	arraylength_aJ( p: POINTER ): INTEGER is
		external "Java array long length"
		end

	put_aJ( p: POINTER; i: INTEGER; a: INTEGER_64 ) is
		external "Java array long set"
		end

	item_aJ( p: POINTER; i: INTEGER ): INTEGER_64 is
		external "Java array long get"
		end

-- float 

	new_aF( a_length: INTEGER ): POINTER is
		external "Java array float new"
		end

	checkcast_aF( p: POINTER ): POINTER is
		external "Java class float[] checkcast"
		end

	arraylength_aF( p: POINTER ): INTEGER is
		external "Java array float length"
		end

	put_aF( p: POINTER; i: INTEGER; a: REAL ) is
		external "Java array float set"
		end

	item_aF( p: POINTER; i: INTEGER ): REAL is
		external "Java array float get"
		end

-- double

	new_aD( a_length: INTEGER ): POINTER is
		external "Java array double new"
		end

	checkcast_aD( p: POINTER ): POINTER is
		external "Java class double[] checkcast"
		end

	arraylength_aD( p: POINTER ): INTEGER is
		external "Java array double length"
		end

	put_aD( p: POINTER; i: INTEGER; a: DOUBLE ) is
		external "Java array double set"
		end

	item_aD( p: POINTER; i: INTEGER ): DOUBLE is
		external "Java array double get"
		end

-- java.lang.String

	length_java_lang_String( p: POINTER ): INTEGER is
		external "Java class java.lang.String method int length()"
		end

	new_a_java_lang_String( a_length: INTEGER ): POINTER is
		external "Java array java.lang.String new"
		end

	checkcast_a_java_lang_String( p: POINTER ): POINTER is
		external "Java class java.lang.String[] checkcast"
		end

	arraylength_a_java_lang_String( p: POINTER ): INTEGER is
		external "Java array java.lang.String length"
		end

	put_a_java_lang_String( p: POINTER; i: INTEGER; a: POINTER ) is
		external "Java array java.lang.String set"
		end

	item_a_java_lang_String( p: POINTER; i: INTEGER ): POINTER is
		external "Java array java.lang.String get"
		end

	getBytes( p: POINTER ): POINTER is
		external "Java class java.lang.String method byte[] getBytes()"
		end

	arraycopy( a1: POINTER; a2: INTEGER; a3: POINTER; a4: INTEGER; a5: INTEGER ) is
		external "Java class java.lang.System method static void arraycopy(java.lang.Object,int,java.lang.Object,int,int)"
   	end

end -- class EXAMPLE3
