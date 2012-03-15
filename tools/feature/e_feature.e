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
deferred class E_FEATURE
   --
   -- For all possible Features : procedure, function, attribute,
   -- constants, once procedure, once function, ...
   --

inherit GLOBALS

feature

   clients: CLIENT_LIST
         -- Authorized clients list of the corresponding feature
         -- clause in the base definition class.

   base_class: BASE_CLASS
         -- The class where the feature is really written if any.
	 -- Because of the undefine option for example, `base_class' may be
	 -- Void.

   names: FEATURE_NAME_LIST
         -- All the names of the feature.

   sedb_trace_before_exit: POSITION;
	 -- This is used for some feature only, to add an extra `sedb' call 
	 -- in the C code in order to be sure to trace the end of the 
	 -- execution of this feature under sedb.
   
   arguments: FORMAL_ARG_LIST is
         -- Arguments if any.
      deferred
      end

   result_type: E_TYPE is
         -- Result type if any.
      deferred
      end

   header_comment: COMMENT
         -- Header comment for a routine or following comment for
         -- an attribute.

   obsolete_mark: MANIFEST_STRING is
         -- The `obsolete' mark if any.
      deferred
      end

   require_assertion: E_REQUIRE is
         -- Not Void if any.
      deferred
      end

   ensure_assertion: E_ENSURE is
         -- Not Void if any.
      deferred
      end

   is_deferred: BOOLEAN is
         -- Is it a deferred feature ?
      deferred
      end

   frozen base_class_name: CLASS_NAME is
         -- Name of the class where the feature is really written.
      do
         Result := base_class.name
      end

   frozen first_name: FEATURE_NAME is
      do
         Result := names.first
      ensure
         Result /= void
      end

   frozen start_position: POSITION is
      do
         Result := first_name.start_position
      end

   to_run_feature(ct: E_TYPE; fn: FEATURE_NAME): RUN_FEATURE is
         -- If possible, gives the checked runnable feature for `ct'
         -- using `fn' as the final name.
      require
	 ct.is_static
         ct.run_class.at(fn) = Void
      deferred
      ensure
         Result /= Void implies ct.run_class.at(fn) = Result
         Result = Void implies nb_errors > 0
      end

   can_hide(other: E_FEATURE; rc: RUN_CLASS): BOOLEAN is
         -- True when header of `Current' can hide the header of `other' in 
         -- `rc'.
      require
         Current /= other
      do
         if result_type /= other.result_type then
            if result_type = Void or else other.result_type = Void then
               error_handler.add_position(other.start_position)
               error(start_position,em_ohrbnto)
            end
         end
         if arguments /= other.arguments then
            if arguments = Void or else other.arguments = Void then
               error_handler.add_position(other.start_position)
               error(start_position,em_ohabnto)
            elseif arguments.count /= other.arguments.count then
               error_handler.add_position(other.start_position)
               error(start_position,em_ina)
            end
         end
         if nb_errors = 0 then
            if result_type /= Void then
               if not assignment_handler.redefinition(other.result_type,
						      result_type,
						      rc,
						      False)
		then
                  error_handler.append(em_chtfi)
                  error_handler.append(rc.current_type.run_time_mark)
                  error_handler.append(fz_dot_blank)
                  error_handler.print_as_error
               end
            end
         end
         if nb_errors = 0 then
            if arguments /= Void then
               if not arguments.is_a_in(other.arguments,rc) then
                  error_handler.add_position(other.start_position)
                  error_handler.add_position(start_position)
                  error_handler.append(em_chtfi)
                  error_handler.append(rc.current_type.run_time_mark)
                  error_handler.append(fz_dot_blank)
                  error_handler.print_as_error
               end
            end
         end
         Result := nb_errors = 0
         if Result then
            merge_header_comments(other)
         end
      end

   frozen check_obsolete(caller: POSITION) is
      require
         not caller.is_unknown
      do
         if obsolete_mark /= Void then
            if not smart_eiffel.short_flag then
               error_handler.add_position(caller)
               error_handler.append("This feature is obsolete :%N")
               error_handler.append(obsolete_mark.to_string)
               error_handler.add_position(start_position)
               error_handler.print_as_warning
            end
         end
      end

   set_header_comment(hc: like header_comment) is
      do
         header_comment := hc
      end

   pretty_print is
      require
         pretty_printer.indent_level = 1
      deferred
      ensure
         pretty_printer.indent_level = 1
      end

   frozen pretty_print_profile is
      require
	 pretty_printer.indent_level = 1
      do
	 pretty_printer.indent
         pretty_print_names
         pretty_printer.set_indent_level(2)
         pretty_print_arguments
         pretty_printer.set_indent_level(3)
         if result_type /= Void then
            pretty_printer.put_string(once ": ")
            result_type.pretty_print
         end
      end

feature {PARENT_LIST}

   frozen is_not_mergeable_with(other: E_FEATURE): BOOLEAN is
         -- True when `Current' and `other' are clearly not mergeable
         -- because of a different number of arguments or result.
      require
         Current /= other
         error_handler.is_empty
      do
         if result_type = Void then
            Result := other.result_type /= Void
         else
            Result := other.result_type = Void
         end
         if Result then
            error_handler.append(em_ohrbnto)
         else
            if arguments = Void then
               Result := other.arguments /= Void
            else
               Result := other.arguments = Void
            end
            if Result then
               error_handler.append(em_ohabnto)
            elseif arguments = Void then
            elseif arguments.count /= other.arguments.count then
               error_handler.append(em_ina)
               Result := True
            end
         end
         merge_header_comments(other)
      ensure
         Result = not error_handler.is_empty
      end

feature {PARENT}

   frozen try_to_undefine(fn: FEATURE_NAME; bc: BASE_CLASS):
      DEFERRED_ROUTINE is
         -- Compute the corresponding deferred feature for `Current'.
         -- This occurs for example when `bc' has an undefine clause
         -- for `fn' which refer to `Current'.
         -- The Result is never Void because `fatal_error' may be called.
         -- Also check VDUS.
      require
         fn /= Void
         bc.name.is_subclass_of(base_class_name)
      local
         fn2: FEATURE_NAME
      do
         -- For (VDUS) :
         error_handler.add_position(fn.start_position)
         fn2 :=  names.feature_name(fn.to_key)
         if fn2 /= Void then
            fn2.undefine_in(bc)
         end
         error_handler.cancel
         --
         Result := try_to_undefine_aux(fn,bc)
         if Result /= Void then
            Result.set_clients(clients)
            merge_header_comments(Result)
         else
            bc.fatal_undefine(fn)
         end
      ensure
         Result /= Void
      end

feature {FEATURE_CLAUSE,E_FEATURE,BASE_CLASS}

   set_clients(c: like clients) is
      require
         c /= Void
      do
         clients := c
      ensure
         clients = c
      end

feature {FEATURE_CLAUSE,BASE_CLASS}

   frozen add_into(fd: HASHED_DICTIONARY[E_FEATURE,FEATURE_NAME]) is
         -- Also check for multiple definitions.
      local
         i: INTEGER; fn: FEATURE_NAME; f: E_FEATURE
      do
         base_class := names.item(1).start_position.base_class
         from
            i := 1
         until
            i > names.count
         loop
            fn := names.item(i)
	    f := fd.reference_at(fn)
            if f /= Void then
               fn := f.first_name
               error_handler.add_position(fn.start_position)
               error_handler.add_position(names.item(i).start_position)
               error_handler.append("Double definition of feature ")
               error_handler.append(fn.to_string)
               error_handler.append(fz_dot_blank)
               error_handler.print_as_error
            else
               fd.add(Current,fn)
            end
            i := i + 1
         end
      end

feature {E_FEATURE_VISITOR}

   accept(visitor: E_FEATURE_VISITOR) is
      deferred
      end

feature {NONE}

   frozen pretty_print_names is
         -- Print only the names of the feature.
      local
         i: INTEGER; fn: FEATURE_NAME
      do
         from
            i := 1
            fn := names.item(i)
	    fn.declaration_pretty_print
            i := i + 1
         until
            i > names.count
         loop
            pretty_printer.put_string(once ", ")
            fn := names.item(i)
	    fn.declaration_pretty_print
            i := i + 1
         end
	 if fn.is_infix_name or else fn.is_prefix_name then
            pretty_printer.put_character(' ')
	 end
      end

   pretty_print_arguments is
      deferred
      end

   make_e_feature(n: like names) is
      require
         n.count >= 1
      do
         names := n
      ensure
         names = n
      end

   try_to_undefine_aux(fn: FEATURE_NAME
                       bc: BASE_CLASS): DEFERRED_ROUTINE is
      require
         fn /= Void
         bc /= Void
      deferred
      end

   frozen merge_header_comments(other: E_FEATURE) is
         -- Falling down of the `header_comment' for command short.
      do
         if smart_eiffel.short_flag then
            if header_comment = Void then
               header_comment := other.header_comment
            elseif other.header_comment = Void then
               other.set_header_comment(header_comment)
            end
         end
      end

   em_chtfi: STRING is " Cannot inherit these features in "

   em_ohrbnto: STRING is "One has Result but not the other."

   em_ohabnto: STRING is "One has argument(s) but not the other."

   em_ina: STRING is "Incompatible number of arguments."

invariant

   names /= Void

end -- E_FEATURE

