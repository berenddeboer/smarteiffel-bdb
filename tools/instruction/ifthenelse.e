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
class IFTHENELSE
   --
   -- The conditionnal instruction :
   --              "if ... then ... elseif ... else ... end".
   --

inherit INSTRUCTION; IF_GLOBALS

creation make

feature

   side_effect_free: BOOLEAN is False
      
   once_pre_computable: BOOLEAN is False

   end_mark_comment: BOOLEAN is True

   start_position: POSITION
	 -- Of keyword "if".

   ifthenlist: IFTHENLIST

   else_compound: COMPOUND
	 -- Not Void if any.

   use_current: BOOLEAN is
      do
	 if ifthenlist.use_current then
	    Result := True
	 elseif else_compound /= Void then
	    Result := else_compound.use_current
	 end
      end

   stupid_switch(run_time_set: RUN_TIME_SET): BOOLEAN is
      do
	 Result := ifthenlist.stupid_switch(run_time_set) 
	    and then
	    (else_compound = Void 
	     or else 
	     else_compound.stupid_switch(run_time_set))
      end

   afd_check is
      do
	 ifthenlist.afd_check
	 if else_compound /= Void then
	    else_compound.afd_check
	 end
      end

   safety_check is
      do
	 ifthenlist.safety_check
	 if else_compound /= Void then
	    else_compound.safety_check
	 end
      end

   collect_c_tmp is
      do
	 ifthenlist.collect_c_tmp
      end

   compile_to_c is
      local
	 static_value: INTEGER
      do
	 check
	    ifthenlist.count > 0
	 end
	 cpp.put_string(once "/*[IF*/%N")
	 static_value := ifthenlist.compile_to_c
	 inspect
	    static_value
	 when Always_false then
	    cpp.put_string(once "/*AE*/%N")
	    if else_compound /= Void then
	       else_compound.compile_to_c
	    end
	 when Always_true then
	 when Always_here then
	    if else_compound /= Void then
	       cpp.put_string(fz_else)
	       cpp.put_string(fz_11)
	       else_compound.compile_to_c
	       cpp.put_string(fz_12)
	    end
	 end
	 cpp.put_string(once "/*FI]*/%N")
      end

   compile_to_jvm is
      local
	 static_value: INTEGER
      do
	 check
	    ifthenlist.count > 0
	 end
	 static_value := ifthenlist.compile_to_jvm
	 inspect
	    static_value
	 when Always_false then
	    -- Always else :
	    if else_compound /= Void then
	       else_compound.compile_to_jvm
	    end
	 when Always_true then
	    -- Never else :
	    ifthenlist.compile_to_jvm_resolve_branch
	 when Always_here then
	    -- Else is possible :
	    if else_compound /= Void then
	       else_compound.compile_to_jvm
	    end
	    ifthenlist.compile_to_jvm_resolve_branch
	 end
      end

   to_runnable(ct: E_TYPE): like Current is
      local
	 ne: INTEGER; itl: like ifthenlist; ec: like else_compound
      do
	 ne := nb_errors
	 if current_type = Void then
	    current_type := ct
	    itl := ifthenlist.to_runnable(ct)
	    if itl = Void then
	       check
		  nb_errors - ne > 0
	       end
	    else
	       ifthenlist := itl
	    end
	    if nb_errors - ne = 0 and then else_compound /= Void then
	       ec := else_compound.to_runnable(ct)
	       if ec = Void then
		  check
		     nb_errors - ne > 0
		  end
	       else
		  else_compound := ec
	       end
	    end
	    if itl /= Void then
	       Result := Current
	    end
	 else
	    Result := twin
	    Result.clear_current_type
	    Result := Result.to_runnable(ct)
	 end
      end

   simplify_2(container: COMPOUND; index: INTEGER) is
      do
	 ifthenlist.simplify_2(Current)
	 if else_compound /= Void then
	    else_compound := else_compound.simplify_2
	 end
	 if ifthenlist.count = 0 then
	    container.remove(index)
	    if else_compound /= Void then
	       container.insert_compound(else_compound, index)
	    end
	 end
      end
   
   pretty_print is
      do
	 check
	    ifthenlist.count > 0
	 end
	 pretty_printer.keyword(fz_if)
	 ifthenlist.pretty_print
	 if else_compound /= Void then
	    pretty_printer.indent
	    pretty_printer.keyword(fz_else)
	    else_compound.pretty_print
	 end
	 pretty_printer.indent
	 pretty_printer.keyword(fz_end)
	 if pretty_printer.print_end_of_statement then
	    pretty_printer.put_end_of(fz_if)
	 end
      end
   
feature {COMPOUND,INSTRUCTION_WITH_COMMENT}

   verify_scoop(allowed: FORMAL_ARG_LIST) is
      do
         ifthenlist.verify_scoop(allowed)
         if else_compound /= Void then
            else_compound.verify_scoop(allowed)
         end
      end

feature {IFTHENELSE}

   clear_current_type is
      do
	 current_type := Void
      ensure
	 current_type = Void
      end

feature {EIFFEL_PARSER, IFTHENLIST}

   set_else_compound(ec: like else_compound) is
      do
	 else_compound := ec
      ensure
	 else_compound = ec
      end

feature {EIFFEL_PARSER}

   add_if_then(expression: EXPRESSION; then_compound: COMPOUND) is
      require
	 expression /= void
      local
	 ifthen: IFTHEN
      do
	 !!ifthen.make(expression,then_compound)
	 if ifthenlist = Void then
	    !!ifthenlist.make(ifthen)
	 else
	    ifthenlist.add_last(ifthen)
	 end
      end

feature {IFTHENELSE_VISITOR}

   accept(visitor: IFTHENELSE_VISITOR) is
      do
         visitor.visit_ifthenelse(Current)
      end

feature {NONE}

   current_type: E_TYPE

   make(sp: like start_position) is
      do
	 start_position := sp
      end

end -- IFTHENELSE
