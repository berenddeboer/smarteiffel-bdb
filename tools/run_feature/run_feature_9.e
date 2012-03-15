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
class RUN_FEATURE_9

inherit RUN_FEATURE redefine base_feature end

creation make

feature

   base_feature: DEFERRED_ROUTINE

   arguments: FORMAL_ARG_LIST

   result_type: E_TYPE

   require_assertion: RUN_REQUIRE

   ensure_assertion: E_ENSURE

   is_deferred: BOOLEAN is True

   once_pre_computable: BOOLEAN is False

   side_effect_free: BOOLEAN is False

   is_once_procedure: BOOLEAN is False

   is_once_function: BOOLEAN is False

   routine_body: COMPOUND is
      do
      end

   rescue_compound: COMPOUND is
      do
      end

   afd_check is
      do
         routine_afd_check
         smart_eiffel.afd_check_deferred(Current)
      end

   simplify_2 is
      do
      end

   collect_c_tmp is
      local
         rt: E_TYPE
      do
         rt := result_type
         if rt /= Void and then rt.is_user_expanded then
            if rt.is_dummy_expanded then
            else
               cpp.se_tmp_register(result_type)
            end
         end
      end

   mapping_c is
      do
         if ace.no_check then
            if result_type = Void then
               default_mapping_procedure
            else
               default_mapping_function
            end
         elseif result_type /= Void then
            result_type.c_initialize
         end
      end

   c_define is
      do
	 define_prototype
	 c_define_body
	 cpp.put_string(fz_12)
      end

   local_vars: LOCAL_VAR_LIST is do end

feature {ADDRESS_OF_POOL}

   address_of_c_define(caller: ADDRESS_OF) is
      do
         error_handler.add_position(caller.start_position)
         error_handler.add_position(start_position)
         fatal_error("Cannot access address of a deferred routine.")
      end

feature {ADDRESS_OF}

   address_of_c_mapping is
      do
      end

feature {NONE}

   initialize is
      local
	 base_class: BASE_CLASS
      do
	 base_class := current_type.base_class
         result_type := base_feature.result_type
         arguments := base_feature.arguments
         if result_type /= Void then
            if result_type.is_like_argument then
               if not arguments.is_runnable(current_type) then
                  !!arguments.with(arguments,current_type)
               end
               result_type := result_type.to_runnable(current_type)
            else
               result_type := result_type.to_runnable(current_type)
               if arguments /= Void then
                  if not arguments.is_runnable(current_type) then
                     !!arguments.with(arguments,current_type)
                  end
               end
            end
         elseif arguments /= Void then
            if not arguments.is_runnable(current_type) then
               !!arguments.with(arguments,current_type)
            end
         end
         if smart_eiffel.short_flag then
            require_assertion := base_class.run_require(Current)
            ensure_assertion := base_class.run_ensure(Current)
         end
      end

   compute_use_current is
      do
         use_current_state := True_state
      end

feature {RUN_CLASS}

   jvm_field_or_method is
      do
      end

feature

   mapping_jvm is
      do
      end

feature {JVM}

   jvm_define is
      do
      end

feature {RUN_FEATURE_9_VISITOR}

   accept(visitor: RUN_FEATURE_9_VISITOR) is
      do
         visitor.visit_run_feature_9(Current)
      end

feature {NONE}

   c_define_body is
      do
	 c_define_opening
	 cpp.put_error0("Deferred routine called.")
	 c_define_closing
      end

   compute_stupid_switch(run_time_set: RUN_TIME_SET) is
      do
         stupid_switch_state := False_state
      end

   update_tmp_jvm_descriptor is
      do
         routine_update_tmp_jvm_descriptor
      end

   stupid_switch_comment: STRING is "SSDRRF9"

end -- RUN_FEATURE_9
