class TRIANGLE
-- Description of TRIANGLEs objects.
   
creation make
   
feature
   
   p1: POINT
	 -- First point.
   p2: POINT
	 -- Second point.
   p3: POINT
	 -- Third point.
   
   translate(dx, dy: DOUBLE) is
	 -- To translate `Current' using `dx' and `dy'.
      do
	 p1.translate(dx,dy)
	 p2.translate(dx,dy)
	 p3.translate(dx,dy)
      end
   
   display_on(stream: OUTPUT_STREAM) is
      -- To display `Current' on the `stream'.
      require
	 stream.is_connected
      do
	 stream.put_string("TRIANGLE[%N%T")
	 p1.display
	 stream.put_string("%N%T")
	 p2.display
	 stream.put_string("%N%T")
	 p3.display
	 stream.put_string("%T]%N")
      end
      
feature {NONE}   
   
   make(a, b, c: POINT) is
	 -- To create a new TRIANGLE.
      require
	 a /= Void
	 b /= Void
	 c /= Void
      do
	 p1 := a
	 p2 := b
	 p3 := c
      ensure
	 p1 = a
	 p2 = b
	 p3 = c
      end
   
invariant
   
   p1 /= Void
   
   p2 /= Void

   p3 /= Void
   
end
