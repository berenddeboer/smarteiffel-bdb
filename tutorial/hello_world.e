class HELLO_WORLD
--
-- The "Hi World program" for SmartEiffel :-)
--
-- To compile type command : compile hello_world
-- Run with command : a.out
--
-- To compile an optimized version type : compile hello_world -boost -O2
--
-- To produce Java bytecode : compile_to_jvm -o hello hello_world
-- To run the Java bytecode : java hello
--
create make

feature

   make is
      do
         io.put_string("Hello World.%N")
      end

end -- HELLO_WORLD
