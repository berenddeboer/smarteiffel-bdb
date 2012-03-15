class POINT
-- Description of POINTs objects.
   
creation make
   
feature
   
   x: DOUBLE
	 -- The `x' coordinate.
   
   y: DOUBLE
	 -- The `y' coordinate.
   
   translate(dx, dy: DOUBLE) is
	 -- To translate `Current' using `dx' and `dy'.
      do
	 x := x + dx
	 y := y + dy
      ensure 
	 x = dx + old x
	 y = dy + old y 
      end
   
   display is
	 -- Display `Current' on `io'.
      do
	 io.put_string("POINT[")
	 io.put_double(x)
	 io.put_character(',')
	 io.put_double(y)
	 io.put_string("]%N")
      end
   
feature {NONE}
   
   make(vx, vy: DOUBLE) is
	 -- To create a new POINT.
      do
	 x := vx
	 y := vy
      end
   
end
