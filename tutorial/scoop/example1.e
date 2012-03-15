class EXAMPLE1
-- Example to show that when using commands on separate objects, 
-- concurrency makes them asynchronous. That means that the execution of 
-- commands on two different SCOOP processors may be interleaved, and 
-- that the client sending a command continues its execution without 
-- waiting for the command to complete.

   create make

feature {NONE}

   make is
      local
         worker1, worker2: separate WORKER
      do
         -- create two new concurrent processors:
         create worker1.make(1)
         create worker2.make(2)

         -- give each of them works, to be done concurrently:
         give_work(worker1)
         give_work(worker2)

         -- `make' finishes, but both workers may still be working.
         -- The program will end when they are finished.
      end

   give_work(s: separate WORKER) is
      local
         i: INTEGER
      do
         from
            i := 1
         until
            i > 5
         loop
            s.do_work
            i := i + 1
         end
      end

end
