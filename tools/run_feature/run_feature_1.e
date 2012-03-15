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
class RUN_FEATURE_1

inherit RUN_FEATURE redefine base_feature end

creation make

feature

   base_feature: CST_ATT

   value: EXPRESSION

   value_i: INTEGER

   result_type: E_TYPE

   is_deferred: BOOLEAN is False

   once_pre_computable: BOOLEAN is False

   side_effect_free: BOOLEAN is True

   is_once_procedure: BOOLEAN is False

   is_once_function: BOOLEAN is False

   arguments: FORMAL_ARG_LIST is
      do
      end

   require_assertion: RUN_REQUIRE is
      do
      end

   local_vars: LOCAL_VAR_LIST is
      do
      end

   routine_body: COMPOUND is
      do
      end

   ensure_assertion: E_ENSURE is
      do
      end

   rescue_compound: COMPOUND is
      do
      end

   afd_check is
      do
      end

   simplify_2 is
      do
      end

   collect_c_tmp is
      do
      end

   mapping_c is
      local
         real_constant: REAL_CONSTANT; scoop: BOOLEAN
      do
	 scoop := smart_eiffel.scoop and then current_type.is_separate
	 if scoop then
	    cpp.put_string(once "(se_join_subsystem(self),")
	 end
         if result_type.is_double then
            real_constant ?= value
            check
               real_constant /= Void
            end
            cpp.put_string(real_constant.to_string)
         else
            value.compile_to_c
         end
	 if scoop then
	    cpp.put_character(')')
	 end
      end

   c_define is do end

feature {ADDRESS_OF_POOL}

   address_of_c_define(caller: ADDRESS_OF) is
      do
         error_handler.add_position(caller.start_position)
         error_handler.add_position(start_position)
         error_handler.append("Cannot access address of a constant (VZAA).")
	 error_handler.print_as_fatal_error
      end

feature {ADDRESS_OF}

   address_of_c_mapping is
      do
      end

feature {RUN_FEATURE}

   compute_use_current is
      do
         use_current_state := False_state
      end

   jvm_field_or_method is
      do
      end

feature

   mapping_jvm is
      local
         space: INTEGER
      do
         jvm.drop_target
         space := value.compile_to_jvm_into(result_type)
      end

feature {JVM}

   jvm_define is
      do
      end

feature {RUN_FEATURE_1_VISITOR}

   accept(visitor: RUN_FEATURE_1_VISITOR) is
      do
         visitor.visit_run_feature_1(Current)
      end

feature {NONE}

   initialize is
      local
         i: INTEGER; bc: BASE_CLASS; original_name: FEATURE_NAME
      do
         result_type := base_feature.result_type
         result_type := result_type.to_runnable(current_type)
         bc := current_type.base_class
         original_name := bc.original_name(base_feature.base_class,name)
         i := base_feature.names.index_of(original_name)
         value_i := i
         check i > 0 end
         value := base_feature.value(i)
         value := value.to_runnable(current_type)
      end

   compute_stupid_switch(run_time_set: RUN_TIME_SET) is
      do
         stupid_switch_state := True_state
      end

   update_tmp_jvm_descriptor is
      do
      end

   c_define_body is
      do
	 check False end
      end

   stupid_switch_comment: STRING is "SSCARF1"

end -- RUN_FEATURE_1
