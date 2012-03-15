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
	 -- To translate the `Current' TRIANGLE.
      do
	 p1.translate(dx,dy)
	 p2.translate(dx,dy)
	 p3.translate(dx,dy)
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
