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
expanded class CHARACTER_CONSTANTS
   --
   -- Platform-independent, universal, character constants.
   -- Intended to be used as ancestor for classes that need these constants.
   --
inherit
   ANY
      redefine Ctrl_a, Ctrl_b, Ctrl_c, Ctrl_d, Ctrl_e, Ctrl_f, Ctrl_g,
	 Ch_bs, Ch_tab, Ctrl_j, Ctrl_k, Ctrl_l, Ctrl_m, Ctrl_n,
	 Ctrl_o, Ctrl_p, Ctrl_q, Ctrl_r, Ctrl_s, Ctrl_t, Ctrl_u, Ctrl_v,
	 Ctrl_w, Ctrl_x, Ctrl_y, Ctrl_z, Ch_del
      end
	
feature -- Character names:

   Ctrl_a: CHARACTER is '%/1/'
   Ctrl_b: CHARACTER is '%/2/'
   Ctrl_c: CHARACTER is '%/3/'
   Ctrl_d: CHARACTER is '%/4/'
   Ctrl_e: CHARACTER is '%/5/'
   Ctrl_f: CHARACTER is '%/6/'
   Ctrl_g: CHARACTER is '%/7/'
   Ch_bs : CHARACTER is '%/8/'
   Ch_tab: CHARACTER is '%/9/'
   Ctrl_j: CHARACTER is '%/10/'
   Ctrl_k: CHARACTER is '%/11/'
   Ctrl_l: CHARACTER is '%/12/'
   Ctrl_m: CHARACTER is '%/13/'
   Ctrl_n: CHARACTER is '%/14/'
   Ctrl_o: CHARACTER is '%/15/'
   Ctrl_p: CHARACTER is '%/16/'
   Ctrl_q: CHARACTER is '%/17/'
   Ctrl_r: CHARACTER is '%/18/'
   Ctrl_s: CHARACTER is '%/19/'
   Ctrl_t: CHARACTER is '%/20/'
   Ctrl_u: CHARACTER is '%/21/'
   Ctrl_v: CHARACTER is '%/22/'
   Ctrl_w: CHARACTER is '%/23/'
   Ctrl_x: CHARACTER is '%/24/'
   Ctrl_y: CHARACTER is '%/25/'
   Ctrl_z: CHARACTER is '%/26/'
   Ch_del: CHARACTER is '%/63/'

	
end -- CHARACTER_CONSTANTS

