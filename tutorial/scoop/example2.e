class EXAMPLE2
-- Example to show that when using queries on separate objects, 
-- concurrency makes them synchronous. That means that the caller 
-- waits for the result.
-- This can be used to synchronize concurrent objects for a 
-- rendez-vous. 

   create make

feature {NONE}

   make is
      local
         worker: separate WORKER
      do
         -- create one new concurrent processor:
         create worker.make(1)

         give_work(worker)

         io.put_string("Work has been given to the worker, waiting till it has finished%N")         
         print_work_done(worker)
      end

   give_work(sw: separate WORKER) is
      local
         i: INTEGER
      do
         from
            i := 1
         until
            i > 5
         loop
            sw.do_work
            i := i + 1
         end
      end

   print_work_done(sw: separate WORKER) is
      do
         io.put_integer(sw.work_done)
         -- `work_done' being a query on a separate object, 
         -- it is a synchronization point: we wait till it returns 
         -- its result
         io.put_string(" has been done.%N")
      end

end
