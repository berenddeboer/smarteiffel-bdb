class POINT
-- Description of POINTs objects.
   
creation make
   
feature
   
   x: DOUBLE
	 -- The `x' coordinate.
   
   y: DOUBLE
	 -- The `y' coordinate.
   
   rho: DOUBLE is
      do
	 Result := x.sin
      end
   
   make(vx, vy: DOUBLE) is
      do
	 x := vx
	 y := vy
      end
   
   translate(dx, dy: DOUBLE) is
	 -- To translate the `Current' POINT.
      do
	 x := x + dx
	 y := y + dy
      end
   
end
