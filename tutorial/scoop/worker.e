class WORKER

   create make

feature {NONE}

   make(id: INTEGER) is
      do
         number := id
      end

feature {ANY}

   work_done: INTEGER -- count the "amount" of work done

   do_work is
      local
         current_time, end_time: MICROSECOND_TIME
      do
         -- to simulate some work that takes time, we loop 
         -- to "work" some time varying from 1 to 2 seconds
         from
            current_time.update
            random.next
            end_time := current_time + random.last_double + 1.0
         until
            current_time > end_time
         loop
            current_time.update
         end
         work_done := work_done + 1
         print_status
      end

   print_status is
      do
         io.put_string("Worker number ")
         io.put_integer(number) 
         io.put_string(" just finished job ")
         io.put_integer(work_done)
         io.put_string(".%N")
      end

feature {NONE}

   number: INTEGER -- worker identifier

   random: MIN_STAND is
      once
         !!Result.make;
      end;

end
