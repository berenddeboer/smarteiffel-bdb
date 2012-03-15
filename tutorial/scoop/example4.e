class EXAMPLE4
-- This examples aims at showing that a feature with separate 
-- arguments corresponds to a critical section for these separate 
-- arguments. 
-- BEWARE: it is very easy to have critical sections larger than you 
-- think. Watch closely your usage of features using separate 
-- arguments. 

   create {ANY} make

feature {NONE}

   make is
      local
         foreman1, foreman2: separate FOREMAN
         worker: separate WORKER
      do
         -- three new processors: two foremen and only one worker 
         -- (poor guy!)
         create worker.make(1)
         create foreman1.make(worker)
         create foreman2.make(worker)

         start_work_day(foreman1, foreman2)
      end

   start_work_day(sf1, sf2: separate FOREMAN) is
      local
         i: INTEGER
      do
         from
            i := 1
         until
            i > 20
         loop
            sf1.give_big_work    -- tough guy...
            sf2.give_small_work  -- nice guy !
            -- `give_XXX_work' are both commands, so the loop goes on 
            -- and terminates without any waiting
            i := i + 1
         end
      end

end
