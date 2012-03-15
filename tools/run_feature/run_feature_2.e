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
class RUN_FEATURE_2

inherit RUN_FEATURE redefine base_feature, verify_scoop_expanded end

creation make

feature

   base_feature: WRITABLE_ATTRIBUTE

   result_type: E_TYPE

   is_deferred: BOOLEAN is False

   side_effect_free: BOOLEAN is True

   once_pre_computable: BOOLEAN is False

   is_once_procedure: BOOLEAN is False

   is_once_function: BOOLEAN is False

   order: INTEGER
         -- Used for special sorting of RUN_CLASS.writable_attributes

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

   rescue_compound: COMPOUND is
      do
      end

   ensure_assertion: E_ENSURE is
      do
      end

   afd_check is
      local
         rc: RUN_CLASS
      do
         rc := result_type.run_type.run_class
      end

   simplify_2 is
      do
      end

   put_c_field_name is
	 --  Emit using `cpp' the corresponding field name with an extra C
	 --  comment which include the offset of the corresponding C field.
	 --  This extra C comment is mandatory to force C recompilation,
	 --  because the field may move from one compilation to another.
      do
	 cpp.put_character('_')
	 cpp.put_string(name.to_string)
         cpp.put_recompilation_comment(run_class.offset_of(Current))
      end

   put_c_field_name_in(buffer: STRING) is
	 --  Emit using `cpp' the corresponding field name with an extra C
	 --  comment which include the offset of the corresponding C field.
	 --  This extra C comment is mandatory to force C recompilation,
	 --  because the field may move from one compilation to another.
      do
	 buffer.extend('_')
	 buffer.append(name.to_string)
         cpp.put_recompilation_comment_in(buffer, run_class.offset_of(Current))
      end

   collect_c_tmp is
      do
      end

   mapping_c is
      local
         ct: E_TYPE
      do
         cpp.put_string(once "(/*RF2*/")
         ct := current_type
         if ct.is_basic_eiffel_expanded then
            check
               as_item = name.to_string
            end
            cpp.put_target_as_value
         elseif ct.is_separate then
	    cpp.put_character('(')
	    cpp.put_target_as_target
	    cpp.put_string(once ")->ref->")
	    put_c_field_name
         elseif ct.is_reference then
	    cpp.put_character('(')
	    cpp.put_target_as_target
	    cpp.put_string(fz_72)
	    put_c_field_name
         else
            check
               ct.is_user_expanded
            end
            cpp.put_character('(')
            cpp.put_target_as_value
            cpp.put_string(once ").")
            put_c_field_name
         end
         cpp.put_character(')')
      end

   c_define is
      do
      end

feature {RUN_CLASS}

   set_order(o: like order) is
      require
         o >= 0
      do
         order := o
      ensure
         order = o
      end

feature {ADDRESS_OF_POOL}

   address_of_c_define(caller: ADDRESS_OF) is
      do
      end

feature {ADDRESS_OF}

   address_of_c_mapping is
      do
         cpp.put_string(once "&(")
         cpp.print_current
         cpp.put_string(once "->_")
         cpp.put_string(name.to_string)
         cpp.put_character(')')
      end

feature {NONE}

   initialize is
      do
         result_type := base_feature.result_type
         result_type := result_type.to_runnable(current_type)
      end

   compute_use_current is
      do
         use_current_state := True_state
      end

   compute_stupid_switch(run_time_set: RUN_TIME_SET) is
      do
         smart_eiffel.push(Current)
         if cpp.attribute_read_removal(Current,run_time_set) then
            stupid_switch_state := True_state
         else
            stupid_switch_state := False_state
         end
         smart_eiffel.pop
      end

feature {RUN_CLASS}

   jvm_field_or_method is
      do
         jvm.add_field(Current)
      end

   verify_scoop_expanded(p: POSITION) is
      do
         default_verify_scoop_expanded(p)
      end

feature

   mapping_jvm is
      local
         idx: INTEGER
         stack_level: INTEGER
      do
         jvm.push_target_as_target
         if current_type.is_basic_eiffel_expanded then
            check
               as_item = name.to_string
            end
         else
            stack_level := result_type.jvm_stack_space - 1
            idx := constant_pool.idx_fieldref(Current)
            code_attribute.opcode_getfield(idx,stack_level)
         end
      end

feature {RUN_CLASS}

   prepare_introspection is
      require
         cpp.on_c
         ace.no_check
      do
         cpp.push_introspect(Current)
         cpp.put_string(once "if (!strcmp(attr,%"")
	 cpp.put_string(name.to_string)
         cpp.put_string(once "%")) {%N")
         result_type.run_class.c_return_introspect(Current)
         cpp.put_string(fz_12)
         cpp.pop
      end

feature {JVM}

   jvm_define is
      local
         name_idx, descriptor: INTEGER
         cp: like constant_pool
         access_flags: INTEGER
      do
         cp := constant_pool
         name_idx := cp.idx_utf8(name.to_string)
         descriptor := cp.idx_utf8(jvm_descriptor)
         access_flags := field_info.field_modifier( name_idx )
         field_info.add(access_flags, name_idx, descriptor)
      end

feature {RUN_FEATURE_2_VISITOR}

   accept(visitor: RUN_FEATURE_2_VISITOR) is
      do
         visitor.visit_run_feature_2(Current)
      end

feature {NONE}

   update_tmp_jvm_descriptor is
      local
         rt: E_TYPE
      do
         rt := result_type.run_type
         if rt.is_reference then
            tmp_jvm_descriptor.append(jvm_root_descriptor)
         else
            rt.jvm_descriptor_in(tmp_jvm_descriptor)
         end
      end

   c_define_body is
      do
	 check False end
      end

   stupid_switch_comment: STRING is "SSWARF2"

invariant

   order >= 0

end -- RUN_FEATURE_2
