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
class PRECURSOR_EXPRESSION
   --
   -- Handling of the `Precursor' function call.
   --

inherit PRECURSOR_CALL; EXPRESSION

creation make

feature

   is_current: BOOLEAN is False

   is_manifest_string: BOOLEAN is False

   is_result: BOOLEAN is False

   is_void: BOOLEAN is False

   once_pre_computable: BOOLEAN is False

   is_static: BOOLEAN is False

   is_writable: BOOLEAN is False

   extra_bracket_flag: BOOLEAN is False
   
   side_effect_free: BOOLEAN is False

   isa_dca_inline_argument: INTEGER is 0

   start_lookup_class: BASE_CLASS is
      local
         e_feature: E_FEATURE
         rt: E_TYPE
      do
         if run_feature /= Void then
            e_feature := run_feature.base_feature
            rt := e_feature.result_type
            Result := rt.start_lookup_class
         end
      end

   result_type: E_TYPE is
      do
         Result := run_feature.result_type
      end

   collect_c_tmp is
      do
         if run_feature /= Void then
            run_feature.collect_c_tmp
         end
         if arguments /= Void then
            arguments.collect_c_tmp
         end
      end


   to_runnable(ct: E_TYPE): like Current is
      local
         wrf: RUN_FEATURE; super: EFFECTIVE_ROUTINE; pn: FEATURE_NAME
      do
         if current_type = Void then
            current_type := ct
            Result := Current
            wrf := smart_eiffel.top_rf
            if wrf.result_type = Void then
               error_handler.add_position(start_position)
               fatal_error("Inside a procedure, a Precursor call must %
                           %be a procedure call (not a function call).")
            end
            super := super_feature(wrf)
            pn := precursor_name(wrf.name,super)
	    run_feature := ct.run_class.at(pn)
	    if run_feature = Void then
	       !RUN_FEATURE_11!run_feature.make(ct,pn,super)
	    end
            prepare_arguments(ct)
         else
            !!Result.make(start_position,parent,arguments)
            Result := Result.to_runnable(ct)
         end
      end

   simplify_1_, simplify_2: like Current is
      do
	 Result := Current
      end
   
   stupid_switch(run_time_set: RUN_TIME_SET): BOOLEAN is do end

   to_integer_or_error: INTEGER is
      do
	 to_integer_error
      end

   dca_inline_argument(formal_arg_type: E_TYPE) is do end

   assertion_check(tag: CHARACTER) is do end

   precedence: INTEGER is
      do
         Result := dot_precedence
      end

   mapping_c_target(formal_type: E_TYPE) is
      do
         compile_to_c
      end

   mapping_c_arg(formal_arg_type: E_TYPE) is
      do
         compile_to_c
      end

   c_frame_descriptor(format, locals: STRING) is
      do
         if arguments /= Void then
            arguments.c_frame_descriptor(format,locals)
         end
      end

   compile_target_to_jvm is
      do
         standard_compile_target_to_jvm
      end

   compile_to_jvm_into(dest: E_TYPE): INTEGER is
      do
         Result := standard_compile_to_jvm_into(dest)
      end

   jvm_branch_if_false: INTEGER is
      do
         compile_to_jvm
         Result := code_attribute.opcode_ifeq
      end

   jvm_branch_if_true: INTEGER is
      do
         compile_to_jvm
         Result := code_attribute.opcode_ifne
      end

   jvm_assign_creation, jvm_assign is
      do
      end

   bracketed_pretty_print is
      do
         pretty_print
      end

   print_as_target is
      do
         pretty_print
         pretty_printer.put_character('.')
      end

   short is
      do
	 if parent /= Void then
	    short_print.hook_or("open_curly_bracket","{")
	    short_print.a_class_name(parent)
	    short_print.hook_or("close_curly_bracket","}")
	 end
         short_print.hook_or(as_precursor, as_precursor)	 
	 if arguments /= Void then
	    arguments.short
	 end
      end

   short_target is
      do
         short
         short_print.a_dot
      end

feature {PRECURSOR_EXPRESSION_VISITOR}

   accept(visitor: PRECURSOR_EXPRESSION_VISITOR) is
      do
         visitor.visit_precursor_expression(Current)
      end

feature {NONE}

   put_semi_colon is
      do
      end

end -- PRECURSOR_EXPRESSION
