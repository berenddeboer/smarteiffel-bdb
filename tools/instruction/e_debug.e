-- This file is part of SmartEiffel The GNU Eiffel Compiler Tools and Libraries
--
-- SmartEiffel is  free software;  you can redistribute it and/or  modify it
-- under  the terms of the  GNU General Public License, as published by  the
-- Free Software Foundation; either version 2, or (at your option) any later
-- version.
-- SmartEiffel is distributed in the hope that it will be useful but WITHOUT 
-- ANY WARRANTY;  without  even the implied warranty  of MERCHANTABILITY  or
-- FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
-- more details.  You should have received a copy of  the GNU General Public
-- License along with SmartEiffel;  see the file COPYING.  If not,  write to
-- the Free Software Foundation,  Inc., 59 Temple Place - Suite 330,  Boston, 
-- MA 02111-1307, USA.
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
class E_DEBUG
   --
   -- The instruction "debug ... end".
   --

inherit INSTRUCTION

creation make

feature

   start_position: POSITION

   end_mark_comment: BOOLEAN is True

   once_pre_computable: BOOLEAN is
      do
	 Result := ace.boost
      end

   side_effect_free: BOOLEAN is
      do
	 Result := ace.boost
      end
      
   to_runnable(ct: E_TYPE): like Current is
      do
         if current_type = Void then
            current_type := ct
	    if compound /= Void then
	       compound := compound.to_runnable(ct)
	    end
            Result := Current
         else
            !!Result.make(start_position,list,compound)
            Result := Result.to_runnable(ct)
         end
      end

   stupid_switch(run_time_set: RUN_TIME_SET): BOOLEAN is
      do
         Result := True
      end

   afd_check is
      do
         if compound /= Void then
	    compound.afd_check
         end
      end

   safety_check is
      do
         check False end
      end

   simplify_2(container: COMPOUND; index: INTEGER) is
      do
	 if ace.boost then
	    container.remove(index)
	 end
      end

   collect_c_tmp is
      do
      end

   compile_to_c is
      do
         if compound /= Void then
	    compound.compile_to_c
         end
      end

   compile_to_jvm is
      do
         if compound /= Void then
	    compound.compile_to_jvm
         end
      end

   use_current: BOOLEAN is
      do
         if compound /= Void then
	    Result := compound.use_current
         end
      end

   pretty_print is
      local
         i: INTEGER
      do
         pretty_printer.keyword(fz_debug)
         pretty_printer.indent_level_increment
         if list /= Void then
            pretty_printer.put_character('(')
            from
               i := list.lower
            until
               i > list.upper
            loop
               list.item(i).pretty_print
               i := i + 1
               if i <= list.upper then
                  pretty_printer.put_character(',')
               end
            end
            pretty_printer.put_character(')')
         end
         pretty_printer.indent_level_decrement
         if compound /= Void then
            compound.pretty_print
         end
         pretty_printer.indent
         pretty_printer.keyword(fz_end)
         if pretty_printer.print_end_of_statement then
            pretty_printer.put_end_of(fz_debug)
         end
      end

feature {COMPOUND,INSTRUCTION_WITH_COMMENT}

   verify_scoop(allowed: FORMAL_ARG_LIST) is
      do
         if compound /= Void then
            compound.verify_scoop(allowed)
         end
      end

feature {ACE, CLUSTER}

   match_debug_key(key: STRING): BOOLEAN is
      require
	 (not key.is_equal("yes")) and (not key.is_equal("no"))
      local
	 i: INTEGER
      do
	 if list /= Void then
	    from
	       i := list.upper
	    until
	       Result or else i < list.lower
	    loop
	       Result := list.item(i).to_string.is_equal(key)
	       i := i - 1
	    end
	 end
      end

feature {E_DEBUG_VISITOR}

   accept(visitor: E_DEBUG_VISITOR) is
      do
         visitor.visit_e_debug(Current)
      end

feature {NONE}

   current_type: E_TYPE

   list: FIXED_ARRAY[MANIFEST_STRING]

   compound: COMPOUND

   make(sp: like start_position; l: like list; c: like compound) is
      require
         not sp.is_unknown
      do
         start_position := sp
         list := l
         compound := c
      ensure
         start_position = sp
         list = l
         compound = c
      end

invariant

   not start_position.is_unknown

end -- E_DEBUG

