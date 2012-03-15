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
class OPEN_OPERAND
   --
   -- An open operand `?' in some agent definition.
   --

inherit EXPRESSION

creation make, with

feature

   is_current: BOOLEAN is False

   is_manifest_string: BOOLEAN is False

   is_void: BOOLEAN is False

   side_effect_free: BOOLEAN is False

   is_result: BOOLEAN is False

   is_writable: BOOLEAN is False

   once_pre_computable: BOOLEAN is False

   is_static: BOOLEAN is False

   extra_bracket_flag: BOOLEAN is False
   
   isa_dca_inline_argument: INTEGER is 0

   dca_inline_argument(formal_arg_type: E_TYPE) is
      do
	 check False end
      end

   start_position: POSITION
         -- Of the `?' character.


   bracketed_pretty_print, pretty_print is
      do
	 if type = Void then
	    pretty_printer.put_character('?')
	 else
	    pretty_printer.put_character('{')
	    type.pretty_print
	    pretty_printer.put_character('}')
	 end
      end

   print_as_target is
      do
         check False end
      end

   short, short_target is
      do
	 not_yet_implemented
      end

   precedence: INTEGER is
      do
         Result := atomic_precedence
      end

   to_runnable(ct: E_TYPE): like Current is
      local
	 t: E_TYPE
      do
	 if run_feature = Void then
	    error_handler.add_position(start_position)
	    error_handler.append("Open operand out of agent scope. %
		      %(Missing %"agent%" keyword?)")
	    error_handler.print_as_fatal_error
	 elseif type /= Void then
	    t := type.to_runnable(ct)
	    if t = Void then
	       error_handler.add_position(type.start_position)
	       error_handler.append(em)
	       error_handler.print_as_fatal_error
	    end
	    type := t
	    t := run_feature.arguments.type(rank)
	    if not type.is_a(t) then
	       error_handler.add_position(type.start_position)
	       error_handler.add_position(t.start_position)
	       error_handler.append(em)
	       error_handler.print_as_fatal_error
	    end
	 end
	 Result := Current
      end

   simplify_1_, simplify_2: like Current is
      do
	 Result := Current
      end
   
   afd_check is do end

   safety_check is do end

   collect_c_tmp is do end

   stupid_switch(run_time_set: RUN_TIME_SET): BOOLEAN is do end

   c_frame_descriptor(format, locals: STRING) is
      do
	 not_yet_implemented
      end

   assertion_check(tag: CHARACTER) is
      do
	 not_yet_implemented
      end

   start_lookup_class: BASE_CLASS is
      do
	 not_yet_implemented
      end

   compile_to_c is
      do
	 cpp.put_character('a')
	 cpp.put_integer(rank)
      end

   mapping_c_target(formal_type: E_TYPE) is
      do
	 check False end
      end

   mapping_c_arg(formal_arg_type: E_TYPE) is
      do
	 compile_to_c
      end

   result_type: E_TYPE is
      do
	 if type = Void then
	    Result := run_feature.arguments.type(rank)
	 else
	    Result := type
	 end
	 Result := Result.run_type
      ensure then
	 Result.run_type = Result
      end

   use_current: BOOLEAN is False

   to_integer_or_error: INTEGER is
      do
	 to_integer_error
      end

   jvm_assign_creation, jvm_assign is
      do
	 check False end
      end

   compile_to_jvm_into(dest: E_TYPE): INTEGER is
      do
	 not_yet_implemented
      end

   compile_target_to_jvm, compile_to_jvm is
      do
	 not_yet_implemented
      end

   jvm_branch_if_false: INTEGER is
      do
	 not_yet_implemented
      end

   jvm_branch_if_true: INTEGER is
      do
	 not_yet_implemented
      end

feature {EFFECTIVE_ARG_LIST,OPEN_OPERAND}

   notify(e_agent: E_AGENT; rf: RUN_FEATURE; r: like rank): like Current is
      require
	 r.in_range(1,rf.arguments.count)
      do
	 if run_feature = Void then
	    run_feature := rf
	    rank := r
	    e_agent.register(Current)
	    Result := Current
	 else
	    create Result.with(start_position,type)
	    Result := Result.notify(e_agent,rf,r)
	 end
      ensure
	 run_feature = rf
	 rank = r
      end

feature {E_AGENT}

   rank: INTEGER
	 -- The `rank' of the corresponding open argument in run_feature.

feature {OPEN_OPERAND_VISITOR}

   accept(visitor: OPEN_OPERAND_VISITOR) is
      do
         visitor.visit_open_operand(Current)
      end

feature {NONE}

   type: E_TYPE
	 -- The one used between {} when the ? notation is not used.

   run_feature: RUN_FEATURE
	 -- When checked, the corresponding one.

   make(sp: like start_position) is
      require
	 not sp.is_unknown
      do
	 start_position := sp
      ensure
	 start_position = sp
      end

   with(sp: like start_position; t: like type) is
      require
	 not sp.is_unknown
      do
	 start_position := sp
	 type := t
      ensure
	 start_position = sp
	 type = t
      end

   em: STRING is "Bad open operand type."

end -- OPEN_OPERAND
