class EXAMPLE3
--
-- How to use C macro from Eiffel.
--
-- To compile this file:
--
--       compile example3
-- 
creation make

feature

   make is
      local
         v: INTEGER; output_ptr: POINTER
      do
         -- Calling the C `sum' macro from Eiffel:
	 v := sum(1,2)
	 io.put_string("sum(1,2)=" + v.to_string + "%N")

         -- Calling standard C `stdin' macro from Eiffel:
	 output_ptr := stdout
       end

feature {NONE}

   sum(a, b: INTEGER): INTEGER is
	 -- (Corresponding C function defined in c_glue2.c)
      external "[
                 C macro use "c_glue3.h"
               ]"
      end

   stdout: POINTER is
      external "C macro use <stdio.h>"
      end

end -- EXAMPLE3

