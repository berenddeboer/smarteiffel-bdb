class EXAMPLE3
-- Example to show the behaviors of preconditions with or without 
-- separate objects. Preconditions involving queries on separate 
-- objects are guards, others are normal assertions.

   create make

feature {NONE}

   worker: separate WORKER
   consumer: separate CONSUMER

   make is
      do
         create consumer.make
         create worker.make(1)

         call_use(consumer)
         -- `consumer' is blocked till `worker' has produced enough
         give_work(worker)

         io.put_string("Exemple finished, but some work may remain!%N")
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

   call_use(sc: separate CONSUMER) is
      do
         sc.use(3, worker)
      end

end
