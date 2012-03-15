class FOREMAN

   create {EXAMPLE4} make

feature {NONE}

   worker: separate WORKER

   make(sw: separate WORKER) is
      do
         worker := sw
      end


feature {EXAMPLE4}

   give_big_work is
      do
         real_give_big_work(worker)
      end

   give_small_work is
      do
         real_give_small_work(worker)
      end


   real_give_small_work(sw: separate WORKER) is
         -- `sw' being a separate argument, when 
         -- `real_give_small_work' is called, the object referred by `sw' 
         -- is reserved and thus may not be used as target by other 
         -- routines. `real_give_small_work' corresponds to a critical section.
      local
         j: INTEGER
      do
         io.put_string("Give small work%N")
         sw.do_work
         j := sw.work_done
         io.put_string("Small work done%N")
      end

   real_give_big_work(sw: separate WORKER) is
         -- `sw' being a separate argument, when 
         -- `real_give_big_work' is called, the object referred by `sw' 
         -- is reserved and thus may not be used as target by other 
         -- routines. `real_give_big_work' corresponds to a critical section.
      local
         i, j: INTEGER
      do
         -- here, in the critical section, the loop is executed 
         -- sequentially and uninterrupted: no other query or command 
         -- may be executed by `sw' for someone else
         from
            i := 1
            io.put_string("In big work%N")
         until
            i > 5
         loop
            io.put_string("Give one step of the big work%N")
            sw.do_work
            j := sw.work_done
            io.put_string("One step of the big work done%N")
            i := i + 1
         end
         io.put_string("Big work done%N")
      end


end

