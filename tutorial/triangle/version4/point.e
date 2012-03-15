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
   
   display_on(stream: OUTPUT_STREAM) is
	 -- Display `Current' on the `stream'.
      require
	 stream.is_connected
      do
	 stream.put_string("POINT[")
	 stream.put_double(x)
	 stream.put_character(',')
	 stream.put_double(y)
	 stream.put_string("]%N")
      ensure
	 stream.is_connected
      end
   
feature {NONE}
   
   make(vx, vy: DOUBLE) is
	 -- To create a new POINT.
      do
	 x := vx
	 y := vy
      end
   
end
