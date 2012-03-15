class CONSUMER

   create make

feature {NONE}

   make is
      do
      end

feature {ANY}

   use(nb: INTEGER; sw: separate WORKER) is
      require

         nb > 0
         -- `nb' is not a separate object, thus this precondition is 
         -- a classical one (immediately true of false, when require 
         -- are checked)

         sw /= Void
         -- `sw' is a separate object, but no query is performed on 
         -- it. This precondition is thus also a classical one. 
         -- Indeed, `sw' may never change, so waiting would be 
         -- pointless. 

         sw.work_done >= nb
         -- `sw' being a separate object and the target of the 
         -- `work_done' query, this precondition is a guard: this 
         -- processor waits till the condition becomes true (even 
         -- when require are not checked)
         
      do
         io.put_string("Worker reached ")
         io.put_integer(sw.work_done)
         io.put_new_line
      end


end
