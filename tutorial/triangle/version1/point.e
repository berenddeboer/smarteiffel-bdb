class POINT
-- Description of POINTs objects.
   
feature
   
   x: DOUBLE
	 -- The `x' coordinate.
   
   y: DOUBLE
	 -- The `y' coordinate.
   
   translate(dx, dy: DOUBLE) is
	 -- To translate the `Current' POINT.
      do
	 -- Modification of the `Current' POINT.
	 x := x + dx
	 y := y + dy
      end
   
end
