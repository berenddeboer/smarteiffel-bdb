class EXAMPLE2

creation main
   
feature
   
   main is
      local
	 t: TRIANGLE
      do
	 create t.make(
		       create {POINT}.make(1.0 , 2.0),
		       create {POINT}.make(3.0 , 4.0),
		       create {POINT}.make(5.0 , 6.0)
		       )
	 t.display_on(io)
	 io.put_string("[
			
	    Also have a look at the OUTPUT_STREAM interface.
	    Type:
	            short OUTPUT_STREAM

                       ]")
      end
  
end
   
