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
class CECIL_POOL
   --
   -- Unique global object in charge of CECIL calls.
   --

inherit GLOBALS; VISITABLE

feature {ACE, COMMAND_LINE_TOOLS}

   add_file(path: STRING) is
	 -- Add `path' as a new -cecil file to be considered.
      require
	 path /= Void
      do
	 if cecil_files = Void then
	    create cecil_files.make
	    cecil_files.add(create {CECIL_FILE}.make(path), path)
	 elseif not cecil_files.has(path) then
	    cecil_files.add(create {CECIL_FILE}.make(path), path)
	 end
      end

feature {SMART_EIFFEL}

   fill_up is
      local
	 i: INTEGER
      do
	 if cecil_files /= Void then
	    from
	       i := cecil_files.lower
	    until
	       i > cecil_files.upper
	    loop
	       cecil_files.item(i).parse
	       i := i + 1
	    end
	 end
      end

   afd_check is
      local
	 i: INTEGER
      do
	 if cecil_files /= Void then
	    from
	       i := cecil_files.lower
	    until
	       i > cecil_files.upper
	    loop
	       cecil_files.item(i).afd_check
	       i := i + 1
	    end
	 end
      end

feature {C_PRETTY_PRINTER}

   c_define_users is
      local
	 i: INTEGER
      do
	 if cecil_files /= Void then
	    from
	       i := cecil_files.lower
	    until
	       i > cecil_files.upper
	    loop
	       cecil_files.item(i).c_define_users
	       i := i + 1
	    end
	 end
      end

feature {RUN_FEATURE}

   define_body_of(rf: RUN_FEATURE) is
      local
         rfct, rfrt: E_TYPE; fake_target: FAKE_TARGET
	 eal: EFFECTIVE_ARG_LIST; run_time_set: RUN_TIME_SET
      do
         rfct := rf.current_type
         rfrt := rf.result_type
         run_time_set := rfct.run_class.run_time_set
         if run_time_set.count = 0 then
            error_handler.add_type(rfct,
                                   once " not created (type is not alive).")
            error_handler.append(once " Empty Cecil/Wrapper function ")
            error_handler.append(rfct.run_time_mark)
            error_handler.extend('.')
            error_handler.append(rf.name.to_key)
            error_handler.extend('.')
            error_handler.print_as_warning
	    if ace.no_check then
	       cpp.put_string(once "[
               error0("Deferred feature call (Void target).", NULL);

                                ]")					    
	    end
	 else
            if ace.no_check then
               cpp.put_string(once "[
                  se_dump_stack ds={NULL,NULL,0,NULL,NULL,NULL};
                  ds.caller=se_dst;
                  ds.exception_origin=NULL;
                  ds.locals=NULL;

                  ]")
	       rf.c_set_dump_stack_top(once "&ds", fz_link);
            end
	    if rfrt /= Void then
               buffer.clear
               buffer.extend('{')
               rfrt.c_type_for_external_in(buffer)
               buffer.append(once " R=")
               cpp.put_string(buffer)
            end
            create fake_target.make(rf.current_type)
            if rf.arguments /= Void then
               eal := effective_arg_list(rf)
            end
            if rfct.is_expanded then
               cpp.push_direct(rf,fake_target,eal)
               rf.mapping_c
               cpp.pop
            else
               cpp.push_cpc(rf,run_time_set,fake_target,eal)
            end
            if rfrt /= Void then
               cpp.put_string(fz_00)
            end
            if ace.no_check then
               rf.c_set_dump_stack_top(once "ds.caller", fz_unlink);
            end
            if rfrt /= Void then
               cpp.put_string(once "return R;%N}%N")
            end
         end
         cpp.put_string(fz_12)
      end

feature {CECIL_FILE}

   echo_for(rf: RUN_FEATURE) is
      do
	 if echo.verbose then
	    echo.put_character('%T')
	    echo.put_string(rf.current_type.run_time_mark)
	    echo.put_character('.')
	    echo.put_string(rf.name.to_string)
	    echo.put_character('%N')
	 end
      end

   c_define_for(c_name: STRING; rf: RUN_FEATURE) is
      require
         not c_name.is_empty
         rf /= Void
      local
         rfct, rfrt: E_TYPE; rfargs: FORMAL_ARG_LIST
      do
         rfct := rf.current_type
         rfrt := rf.result_type
         rfargs := rf.arguments
	 echo_for(rf)
         -- (1) ------------------------- Define Cecil heading :
         buffer.clear
         if rfrt /= Void then
            rfrt.c_type_for_external_in(buffer)
         else
            buffer.append(fz_void)
         end
         buffer.extend(' ')
         buffer.append(c_name)
         buffer.extend('(')
         rfct.c_type_for_external_in(buffer)
         buffer.extend(' ')
         buffer.extend('C')
         if rfargs /= Void then
            buffer.extend(',')
            rfargs.external_prototype_in(buffer)
         end
         buffer.extend(')')
         cpp.put_c_heading(buffer)
         cpp.swap_on_c
         define_body_of(rf)
      end

feature {CECIL_POOL_VISITOR}

   accept(visitor: CECIL_POOL_VISITOR) is
      do
         visitor.visit_cecil_pool(Current)
      end

feature {NONE}

   effective_arg_list(rf: RUN_FEATURE): EFFECTIVE_ARG_LIST is
      local
	 first: FAKE_ARGUMENT; remainder: FIXED_ARRAY[EXPRESSION]
	 fake_argument: FAKE_ARGUMENT; fal: FORMAL_ARG_LIST
	 i: INTEGER
      do
	 fal := rf.arguments
	 create first.make(fal.type(1),1)
	 if fal.count > 1 then
	    from
	       create remainder.with_capacity(fal.count - 1)
	       i := 2
	    until
	       i > fal.count
	    loop
	       create fake_argument.make(fal.type(i),i)
	       remainder.add_last(fake_argument)
	       i := i + 1
	    end
	    create Result.make_n(first,remainder)
	 else
	    create Result.make_1(first)
	 end
      end

   cecil_files: DICTIONARY[CECIL_FILE, STRING]
	 -- Non Void if some -cecil option is used.

   buffer: STRING is
	 -- To prepare C code.
      once
         create Result.make(256)
      end

   singleton_memory: CECIL_POOL is
      once
	 Result := Current
      end

invariant

   is_real_singleton: Current = singleton_memory

end -- CECIL_POOL

