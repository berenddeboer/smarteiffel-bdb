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
class NATIVE_C_PLUS_PLUS

inherit NATIVE

creation make

feature {NATIVE_C_PLUS_PLUS_VISITOR}

   accept(visitor: NATIVE_C_PLUS_PLUS_VISITOR) is
      do
         visitor.visit_native_c_plus_plus(Current)
      end

feature

   use_current(er: EXTERNAL_ROUTINE): BOOLEAN is do end

   stupid_switch_function(run_time_set: RUN_TIME_SET; name: STRING)
      : BOOLEAN is
      do
         Result := true
      end

   stupid_switch_procedure(run_time_set: RUN_TIME_SET; name: STRING)
      : BOOLEAN is
      do
         Result := true
      end

   notify_external_assignments(args: FORMAL_ARG_LIST; rt: E_TYPE) is
      do
	 assignment_handler.from_external(start_position, args, rt)
      end
   
   c_define_function(rf8: RUN_FEATURE_8; bcn, name: STRING) is
      do
         standard_c_define_function(rf8, bcn, name)
         cpp.c_plus_plus_register(Current)
         rf8_memory := rf8
      end
   
   c_mapping_function(rf8: RUN_FEATURE_8; bcn, name: STRING) is
      do
         if ace.boost then
            c_mapping_external(rf8.base_feature,rf8.arg_count)
         else
            rf8.default_mapping_function
         end
      end

   c_define_procedure(rf7: RUN_FEATURE_7; bcn, name: STRING) is
      do
         standard_c_define_procedure(rf7, bcn, name)
         cpp.c_plus_plus_register(Current)
         rf7_memory := rf7
      end

   c_mapping_procedure(rf7: RUN_FEATURE_7; bcn, name: STRING) is
      do
         if ace.boost then
            c_mapping_external(rf7.base_feature,rf7.arg_count)
            cpp.put_string(fz_00)
         else
            rf7.default_mapping_procedure
         end
      end

   jvm_add_method_for_function(rf8: RUN_FEATURE_8; bcn, name: STRING) is
      do
      end

   jvm_define_function(rf8: RUN_FEATURE_8; bcn, name: STRING) is
      do
         fe_c2jvm(rf8)
      end

   jvm_mapping_function(rf8: RUN_FEATURE_8; bcn, name: STRING) is
      do
         fe_c2jvm(rf8)
      end

   jvm_add_method_for_procedure(rf7: RUN_FEATURE_7; bcn, name: STRING) is
      do
      end

   jvm_define_procedure(rf7: RUN_FEATURE_7; bcn, name: STRING) is
      do
         fe_c2jvm(rf7)
      end

   jvm_mapping_procedure(rf7: RUN_FEATURE_7; bcn, name: STRING) is
      do
         fe_c2jvm(rf7)
      end

feature {C_PRETTY_PRINTER}

   c_plus_plus_definition is
      do
         if rf8_memory /= Void then
            c_plus_plus_function_definition(rf8_memory)
         else
            c_plus_plus_procedure_definition(rf7_memory)
         end
      end

feature {NONE}

   rf7_memory: RUN_FEATURE_7

   rf8_memory: RUN_FEATURE_8

   standard_c_define_function(rf8: RUN_FEATURE_8; bcn, name: STRING) is
      do
	 rf8.external_c_prototype_from(external_tag.start_position)
         if ace.no_check then
            body.clear
            body.extend('R')
            body.extend('=')
            wrapped_external_call(rf8.base_feature,rf8.arg_count)
            rf8.c_define_with_body(body)
         end
      end

   standard_c_define_procedure(rf7: RUN_FEATURE_7; bcn, name: STRING) is
      do
	 rf7.external_c_prototype_from(external_tag.start_position)
         if ace.no_check then
            body.clear
            wrapped_external_call(rf7.base_feature,rf7.arg_count)
            rf7.c_define_with_body(body)
         end
      end

   c_mapping_external(er: EXTERNAL_ROUTINE; arg_count: INTEGER) is
      local
         eruc, tcbd: BOOLEAN
      do
         eruc := use_current(er)
         if not eruc then
            tcbd := cpp.target_cannot_be_dropped
            if tcbd then
               cpp.put_character(',')
            end
         end
         cpp.put_string(er.external_name)
         cpp.put_character('(')
         if eruc then
            cpp.put_target_as_value
         end
         if arg_count > 0 then
            if eruc then
               cpp.put_character(',')
            end
            cpp.put_arguments
         end
         cpp.put_character(')')
         if not eruc and then tcbd then
            cpp.put_character(')')
         end
      end

   wrapped_external_call(er: EXTERNAL_ROUTINE; arg_count: INTEGER) is
      local
         i: INTEGER
      do
         body.append(er.external_name)
         body.extend('(')
         if use_current(er) then
            body.extend('C')
            if arg_count > 0 then
               body.extend(',')
            end
         end
         from
            i := 1
         until
            i > arg_count
         loop
            body.extend('a')
            i.append_in(body)
            i := i + 1
            if i <= arg_count then
               body.extend(',')
            end
         end
         body.append(fz_14)
      end

   c_plus_plus_function_definition(rf8: RUN_FEATURE_8) is
      require
         cpp.on_c
      local
         er: EXTERNAL_ROUTINE
	 args_count: INTEGER
      do
         er := rf8.base_feature
	 if not external_routine_memory.fast_has(er) then
	    external_routine_memory.add_last(er)
	    rf8.c_plus_plus_prototype(er)
	    body.clear
	    body.append(once "return ((")
	    rf8.result_type.c_type_for_external_in(body)
	    body.extend(')')
	    if rf8.arguments /= Void then
	       args_count := rf8.arguments.count
	    end
	    parse_external(args_count,external_tag.to_string,er)
	    body.append(once ");%N}%N")
	    cpp.put_string(body)
	 end
      end

   c_plus_plus_procedure_definition(rf7: RUN_FEATURE_7) is
      require
         cpp.on_c
      local
         er: EXTERNAL_ROUTINE
	 args_count: INTEGER
      do
         er := rf7.base_feature
	 if not external_routine_memory.fast_has(er) then
	    external_routine_memory.add_last(er)
	    rf7.c_plus_plus_prototype(er)
	    body.clear
	    if rf7.arguments /= Void then
	       args_count := rf7.arguments.count
	    end
	    parse_external(args_count,external_tag.to_string,er)
	    body.append(once ";%N}%N")
	    cpp.put_string(body)
	 end
      end

   parse_external(args_count: INTEGER; tag: STRING; er: EXTERNAL_ROUTINE) is
	 -- Lazy parsing (hope the tag is correct) of this syntax :
	 --
	 -- External -> "%"C++" [ "[" C++_feature "]" ]
	 --                     [ "(" {Type "," ...} ")" [ ":" Type ] ]
	 --                     [ "|" {include "," ...} ]
         --             "%""
	 -- C++_feature -> "static" C++_Class |
         --                "new" C++_Class |
	 --                "delete" C++_Class |
         --                "data_member" C++_Class |
	 --                C++_Class
	 -- include -> "%"" Manifest string "%"" |
	 --            "<" Manifest_string ">"
	 -- C++_Class -> Identifier include
      local
         i, state, args, parenthesis: INTEGER
         c: CHARACTER
      do
         from
	    check
	       tag.has_prefix(once "C++")
	    end
            i := 4
         until
            i > tag.count
         loop
            c := tag.item(i)
            inspect
               state
            when 0 then
	       -- Looks like : "C++"
               inspect
                  c
               when ' ', '%T', '%N' then
                  i := i + 1
               when '[' then
                  i := i + 1
                  state := 1
               else
                  i := error_at(i,tag,state)
               end
            when 1 then
	       -- Looks like : "C++ [" :
               if c = ' ' or else c = '%T' or else c = '%N' then
                  i := i + 1
               elseif i = tag.substring_index(once "static ",i) then
		  i := i + 7
		  i := parse_cpp_class(i,tag)
		  body.append(once "::")
		  body.append(er.c_plus_plus_name)
		  state := 2
               elseif i = tag.substring_index(once "new ",i) then
                  i := i + 4
		  body.append(once "new ")
		  i := parse_cpp_class(i,tag)
                  state := 3
               elseif i = tag.substring_index(once "delete ",i) then
                  i := i + 7
		  body.append(once "delete((")
		  i := parse_cpp_class(i,tag)
                  body.append(once "*)a1)")
		  if args /= 0 or else args_count /= 1 then
		     i := error_at(i,tag,state)
		  else
		     state := 4
		  end
               elseif i = tag.substring_index(once "data_member ",i) then
		  i := error_at(i,tag,state); -- really necessary ?
               else
		  args := args + 1
		  body.append(once "((")
		  i := parse_cpp_class(i,tag)
		  body.append(once "*)a1)->")
                  body.append(er.c_plus_plus_name)
                  state := 5
               end
            when 2 then
	       -- Looks like : "C++ [ static C++_Class " :
               inspect
                  c
               when ' ', '%T', '%N' then
                  i := i + 1
               when ']' then
                  i := i + 1
                  state := 8
	       else
		  i := error_at(i,tag,state)
	       end
            when 3 then
	       -- Looks like : "C++ [ new C++_Class" :
               inspect
                  c
               when ' ', '%T', '%N' then
                  i := i + 1
               when ']' then
                  i := i + 1
                  state := 6
	       else
		  i := error_at(i,tag,state)
	       end
            when 4 then
	       -- Looks like : "C++ [ delete C++_Class " :
               inspect
                  c
               when ' ', '%T', '%N' then
                  i := i + 1
               when ']' then
                  i := i + 1
                  state := 10
	       else
		  i := error_at(i,tag,state)
	       end
	    when 5 then
	       -- Looks like : "C++ [C++_Class" :
               inspect
                  c
               when ' ', '%T', '%N' then
                  i := i + 1
               when ']' then
                  i := i + 1
                  state := 7
	       else
		  i := error_at(i,tag,state)
	       end
            when 6 then
	       -- Looks like : "C++ [ new C++_CLASS ]" :
               inspect
                  c
               when ' ', '%T', '%N' then
                  i := i + 1
               when '(' then
		  i := parse_args(i,tag,args,args_count)
                  state := 13
	       else
		  i := error_at(i,tag,state)
	       end
            when 7 then
	       -- Looks like : "C++ [ C++_Class ] :
               inspect
                  c
               when ' ', '%T', '%N' then
                  i := i + 1
               when '(' then
		  i := parse_args(i,tag,args,args_count)
                  state := 11
	       else
		  i := error_at(i,tag,state)
	       end
            when 8 then
	       -- Looks like : "C++ [ static C++_Class ]" :
               inspect
                  c
               when ' ', '%T', '%N' then
                  i := i + 1
               when '(' then
		  i := parse_args(i,tag,args,args_count)
                  state := 9
	       else
		  i := error_at(i,tag,state)
	       end
            when 9 then
	       -- Looks like : "C++ [ static C++_Class ] ({type, ...})" :
	       i := i + 1
            when 10 then
	       -- Looks like : "C++ [ delete C++_Class ]" :
               inspect
                  c
               when ' ', '%T', '%N' then
                  i := i + 1
               when '(' then
		  parenthesis := parenthesis + 1
		  i := i + 1
               when ')' then
		  if parenthesis > 1 then
		     i := error_at(i,tag,state)
		  else
		     i := i + 1
		  end
	       else
		  i := error_at(i,tag,state)
	       end
            when 11 then
	       -- Looks like : "C++ * ( { type , ... } )" :
               inspect
                  c
               when ':' then
		  state := 12
               when '|' then
		  state := 13
	       else
	       end
	       i := i + 1
            when 12 then
	       -- Looks like : "C++ * ( { type , ... } ) : " :
               inspect
                  c
               when '|' then
		  state := 13
	       else
	       end
	       i := i + 1
            when 13 then
	       -- Looks like : "C++ * |" :
	       inspect
		  c
	       when ' ', '%T', '%N' then
		  i := i + 1
	       when '<', '%"' then
		  i := parse_include(i,tag)
	       when ',' then
		  i := i + 1
	       else
		  i := error_at(i,tag,state)
	       end
            end
         end
      end

   parse_args(s: INTEGER; tag: STRING; args, args_count: INTEGER): INTEGER is
      require
	 tag.item(s) = '('
      local
	 i, parenthesis, a, state: INTEGER
	 c: CHARACTER
      do
	 from
	    a := args
	    state := 40
	    body.extend('(')
	    i := s + 1
	 until
	    i > tag.count or else Result > i
	 loop
	    c := tag.item(i)
	    inspect
	       state
	    when 40 then
	       -- Before arg type :
               inspect
                  c
               when ' ', '%T', '%N' then
                  i := i + 1
	       when ')' then
	          Result := i + 1
	       else
		  body.extend('(')
		  state := 41
	       end
	    when 41 then
	       -- Inside some type :
               inspect
                  c
               when ',' then
		  i := i + 1
		  body.extend(')')
		  a := a + 1
		  body.extend('a')
		  a.append_in(body)
		  if a < args_count then
		     body.extend(',')
		  end
		  state := 40
               when '(' then
		  body.extend(c)
		  parenthesis := parenthesis + 1
		  i := i + 1
               when ')' then
		  if parenthesis = 0 then
		     body.extend(')')
		     a := a + 1
		     body.extend('a')
		     a.append_in(body)
		     Result := i + 1
		  else
		     body.extend(c)
		     parenthesis := parenthesis - 1
		     i := i + 1
		  end
	       else
		  body.extend(c)
		  i := i + 1
	       end
	    end
	 end
	 body.extend(')')
	 if Result = 0 or else a /= args_count then
	    Result := error_at(i,tag,state)
	 end
      end

   parse_include(s: INTEGER; tag: STRING): INTEGER is
      require
	 (once "%"<").has(tag.item(s))
      local
         include: STRING
	 i: INTEGER; c: CHARACTER
      do
	 from
	    buffer.clear
	    buffer.extend(tag.item(s))
	    i := s + 1
	 until
	    i > tag.count or else Result > i
	 loop
	    c := tag.item(i)
	    inspect
	       c
	    when '%"', '>' then
	       buffer.extend(c)
	       include := buffer.twin
	       if not include_memory.has(include) then
		  include_memory.add_last(include)
		  cpp.add_include(include)
	       end
	       Result := i + 1
	    else
	       buffer.extend(c)
	       i := i + 1
	    end
	 end
	 if Result = 0 then
	    Result := error_at(i,tag,20)
	 end
      end

   parse_cpp_class(s: INTEGER; tag: STRING): INTEGER is
      local
	 i, state: INTEGER
	 c: CHARACTER
      do
	 from
	    state := 30
	    i := s
	 until
	    i > tag.count or else state > 32
	 loop
	    c := tag.item(i)
	    inspect
	       state
	    when 30 then
	       -- Nothing :
	       inspect
		  c
	       when ' ', '%T', '%N' then
		  i := i + 1
	       when '<', '>', '%"', '(', ')' then
		  i := error_at(i,tag,state)
	       else
		  state := 31
	       end
	    when 31 then
	       -- Inside Identifier :
	       inspect
		  c
	       when ' ', '%T', '%N' then
		  state := 32
	       when '<', '%"' then
		  i := parse_include(i,tag)
		  state := 33
	       else
		  body.extend(c)
		  i := i + 1
	       end
	    when 32 then
	       -- After Identifier :
	       inspect
		  c
	       when ' ', '%T', '%N' then
		  i := i + 1
	       when '<', '%"' then
		  i := parse_include(i,tag)
		  state := 33
	       else
		  i := error_at(i,tag,state)
	       end
	    end
	 end
	 Result := i
      end

   error_at(error_index: INTEGER; tag: STRING; state: INTEGER): INTEGER is
      do
         if rf7_memory /= Void then
            error_handler.add_position(rf7_memory.base_feature.start_position)
         else
            error_handler.add_position(rf8_memory.base_feature.start_position)
         end
         error_handler.append("Bad external %"C++%" definition.%Nexternal %"")
         error_handler.append(tag)
         error_handler.append("%"%N_________")
         from
            Result := 1
         until
            Result > error_index
         loop
            error_handler.extend('_')
            Result := Result + 1
         end
         error_handler.extend('^')
         error_handler.append("%NSee SmartEiffel/tutorial/external/C++ directory %
		   %for more information.%N (Internal state = ")
         error_handler.append(state.to_string)
         error_handler.extend(')')
         error_handler.print_as_error
         Result := tag.count + 1
      end

   include_memory: FIXED_ARRAY[STRING] is
      once
         !!Result.with_capacity(4)
      end

   external_routine_memory: FIXED_ARRAY[EXTERNAL_ROUTINE] is
      once
         !!Result.with_capacity(4)
      end

end -- NATIVE_C_PLUS_PLUS
