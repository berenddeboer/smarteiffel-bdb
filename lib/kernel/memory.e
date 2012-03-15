-- This  file  is  free software,  which comes along with SmartEiffel.  This
-- software is distributed in the hope that it will be useful,  but  WITHOUT
-- ANY  WARRANTY;  without  even the  implied warranty of MERCHANTABILITY or
-- FITNESS FOR A PARTICULAR PURPOSE. You can modify it as you want, provided
-- this header is kept unaltered, and a notification of the changes is added.
-- You  are  allowed  to  redistribute it and sell it, alone or as a part of
-- another product.
--
-- Copyright(C) 1994-2002: INRIA - LORIA (INRIA Lorraine) - ESIAL U.H.P.
--			   - University of Nancy 1 - FRANCE
-- Copyright(C) 2003:      INRIA - LORIA (INRIA Lorraine) - I.U.T. Charlemagne
--			   - University of Nancy 2 - FRANCE
--
--		 Dominique COLNET, Suzanne COLLIN, Olivier ZENDRA,
--			   Philippe RIBET, Cyril ADRIAN
--
-- http://SmartEiffel.loria.fr - SmartEiffel@loria.fr
--
expanded class MEMORY
--
-- Facilities for tuning up the garbage collection, and
-- everything about memory control.
--

feature

   dispose is
         -- Action to be executed just before garbage collection reclaims an
         -- object. (The default action is to do nothing at all.) If you want
         -- to change the default action, your class is supposed to
         -- inherit MEMORY and to redefine this `dispose' feature.
      do
      end

feature -- Garbage collector information and tuning:

   frozen collecting: BOOLEAN is
         -- Is garbage collection enabled?
      external "SmartEiffel"
      end

   frozen collection_off is
         -- Disable garbage collection.
      external "SmartEiffel"
      end

   frozen collection_on is
         -- Enable garbage collection.
      external "SmartEiffel"
      end

   frozen full_collect is
         -- Force a full collection cycle if garbage collection is
         -- enabled (i.e. `collecting' is true); do nothing otherwise.
      external "SmartEiffel"
      end

   frozen collector_counter: INTEGER is
	 -- The number of collections actually performed or -1 when the
	 -- system is not using the SmartEiffel garbage collector (i.e. when
	 -- the system is compiled using the -no_gc flag).
      external "SmartEiffel"
      ensure
	 Result >= -1
      end

feature -- SmartEiffel Garbage collector information and tuning:

   frozen small_eiffel_collector: BOOLEAN is
	 -- Is the SmartEiffel garbage collector really used?
      do
	 Result := collector_counter >= 0
      ensure
	 Result = (collector_counter >= 0)
      end

   frozen low_memory_strategy: BOOLEAN is
	 -- Is the low memory strategy in use? When this strategy is used,
	 -- the garbage collector try to use as few memory as possible.
      require
	 small_eiffel_collector
      do
	 c_inline_c("#ifdef SE_GC_LIB%N")
	 c_inline_c("R=(se_gc_strategy==SE_GC_LOW_MEMORY_STRATEGY);%N")
	 c_inline_c("#endif%N")
      end

   frozen set_low_memory_strategy is
      require
	 small_eiffel_collector
      do
	 c_inline_c("#ifdef SE_GC_LIB%N")
	 c_inline_c("se_gc_strategy=SE_GC_LOW_MEMORY_STRATEGY;%N%
		    %gc_update_ceils();%N")
	 c_inline_c("#endif%N")
      ensure
	 low_memory_strategy
      end

   frozen high_memory_strategy: BOOLEAN is
	 -- Is the high memory strategy in use? When this strategy is used,
	 -- the garbage collector assume that more memory can be allocated
	 -- if necessary.
      require
	 small_eiffel_collector
      do
	 c_inline_c("#ifdef SE_GC_LIB%N")
	 c_inline_c("R=(se_gc_strategy==SE_GC_HIGH_MEMORY_STRATEGY);%N")
	 c_inline_c("#endif%N")
      end

   frozen set_high_memory_strategy is
      require
	 small_eiffel_collector
      do
	 c_inline_c("#ifdef SE_GC_LIB%N")
	 c_inline_c("se_gc_strategy=SE_GC_HIGH_MEMORY_STRATEGY;%N%
		    %gc_update_ceils();%N")
	 c_inline_c("#endif%N")
      ensure
	 high_memory_strategy
      end

   frozen default_memory_strategy: BOOLEAN is
	 -- Is the default memory strategy in use? This is the default initial
	 -- mode for the garbage collector (somewhere between `low_memory_strategy'
	 -- and `high_memory_strategy').
      require
	 small_eiffel_collector
      do
	 c_inline_c("#ifdef SE_GC_LIB%N")
	 c_inline_c("R=(se_gc_strategy==SE_GC_DEFAULT_MEMORY_STRATEGY);%N")
	 c_inline_c("#endif%N")
      end

   frozen set_default_memory_strategy is
      require
	 small_eiffel_collector
      do
	 c_inline_c("#ifdef SE_GC_LIB%N")
	 c_inline_c("se_gc_strategy=SE_GC_DEFAULT_MEMORY_STRATEGY;%N%
		    %gc_update_ceils();%N")
	 c_inline_c("#endif%N")
      ensure
	 default_memory_strategy
      end

   frozen allocated_bytes: INTEGER is
	 -- Total number of allocated bytes of memory in the heap.
      require
	 collector_counter >= 0
      do
	 c_inline_c("#ifdef SE_GC_LIB%N")
         c_inline_c("R=gc_memory_used();%N");
	 c_inline_c("#endif%N")
      end

feature -- Other features:

   pointer_size: INTEGER is
         -- The size in number of bytes for a pointer.
      external "SmartEiffel"
      end

end -- MEMORY
