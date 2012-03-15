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
class CLIENT_LIST
   --
   -- To store a list of clients class like : {FOO,BAR}
   --

inherit
   GLOBALS
   VISITABLE

creation make, omitted, merge

feature

   start_position: POSITION
         -- Of the the opening bracket when list is really written.

   is_omitted: BOOLEAN is
      do
         Result := start_position.is_unknown
      end

   pretty_print is
      do
         if is_omitted then
            if pretty_printer.parano_mode then
               pretty_printer.put_string(once "{ANY} ")
            end
         else
            if list = Void then
               if pretty_printer.zen_mode then
                  pretty_printer.put_string(once "{} ")
               else
                  pretty_printer.put_string(once "{NONE} ")
               end
            else
               pretty_printer.put_character('{')
               pretty_printer.set_indent_level(2)
               list.pretty_print
               pretty_printer.put_character('}')
               pretty_printer.put_character(' ')
            end
         end
      end

   gives_permission_to(cn: CLASS_NAME): BOOLEAN is
         -- Check whether the `cn' class is a member (or a subclass as
         -- well) of the `Current' client list. (No error report done here
         -- in `error_handler').
      require
         cn /= Void
	 error_handler.is_empty
      do
         if is_omitted then
            -- It is equivalent to {ANY}:
            Result := True
         elseif list = Void then
            -- Because it is equivalent to {NONE}.
         else
            Result := list.gives_permission_to(cn)
         end
      ensure
	 error_handler.is_empty
      end

   gives_permission_to_any: BOOLEAN is
         -- Check whether the `Current' client list gives permission to all
         -- classes. (No error report done here in `error_handler').
      require
	 error_handler.is_empty
      do
         if is_omitted then
            Result := True
            -- Because it is as : {ANY}.
         elseif list = Void then
            -- Because it is as : {NONE}.
         else
            Result := list.gives_permission_to_any
         end
      ensure
	 error_handler.is_empty
      end

feature {BASE_CLASS, CLIENT_LIST}

   eiffel_view: STRING is
	 -- The Eiffel view of the allowed classe(s) list. (Because of
	 -- clients list merging, the `Current' clients list may be located
	 -- on many Eiffel source files. This function is also useful to
	 -- remind default abbreviated notation as omited list or empty
	 -- list.)
      local
	 i: INTEGER
      do
	 if eiffel_view_memory = Void then
	    if is_omitted then
	       eiffel_view_memory := once "{ANY}"
	    elseif list = Void then
	       eiffel_view_memory := once "{NONE}"
	    else
	       create eiffel_view_memory.make(64)
	       eiffel_view_memory.extend('{')
	       from
		  i := 1
	       until
		  i > list.count
	       loop
		  eiffel_view_memory.append(list.item(i).to_string)
		  i := i + 1
		  if i <= list.count then
		     eiffel_view_memory.extend(',')
		     eiffel_view_memory.extend(' ')
		  end
	       end
	       eiffel_view_memory.extend('}')
	    end
	 end
	 Result := eiffel_view_memory
      ensure
	 Result /= Void
      end

   locate_in_error_handler is
	 -- Add one or more related positions in the `error_handler'.
      do
	 if list = Void then
	    error_handler.add_position(start_position)
	 else
	    list.locate_in_error_handler
	 end
      end

feature {EXPORT_LIST}

   merge_with(other: like Current): like current is
      require
         other /= Void
      local
         sp: POSITION
      do
         if gives_permission_to_any then
            Result := Current
         elseif other.gives_permission_to_any then
            Result := other
         else
            sp := start_position
            if sp.is_unknown then
               sp := other.start_position
            end
            create Result.merge(sp,list,other.list)
         end
      end

feature {PARENT_LIST}

   append(other: like Current): like Current is
      require
         other /= Void
      do
         if Current = other or else is_omitted then
            Result := Current
         elseif gives_permission_to_any then
	    Result := Current
	 elseif other.is_omitted then
	    Result := other
	 elseif other.gives_permission_to_any then
	    Result := other
	 else
	    create Result.merge(start_position,list,other.list)
	 end
	 debug
	    eiffel_view_memory := Void
	    if eiffel_view /= Void then end
	 end
      end

feature {RUN_FEATURE}

   vape_check(enclosing: RUN_FEATURE; call_site: POSITION;
	      other: like Current) is
         -- To enforce the VAPE rule. The `Current' client list is the one of
         -- the `enclosing' feature and the `other' is the one of the
	 -- `call_site' which is inside the require assertion.
      require
         other /= Void
      local
         vape: BOOLEAN; i: INTEGER; cn: CLASS_NAME
      do
         if is_omitted then
            -- It is as {ANY}:
            vape := other.gives_permission_to_any
         elseif list = Void then
            -- It is {NONE}:
            vape := True
         else
            from
               vape := True
               i := list.count
            until
               not vape or else i = 0
            loop
               cn := list.item(i)
               vape := other.gives_permission_to(cn)
               i := i - 1
            end
         end
         if not vape then
            error_handler.append("(VAPE): The content of a require assertion must %
		      %also be visible by the caller of the routine (i.e. %
		      %the client must be able to check the require %
		      %assertion before calling the routine). See next %
		      %two following reports for details.")
            error_handler.print_as_error
	    --
            error_handler.add_position(call_site)
            error_handler.append("This call which is inside the require assertion is %
		       %exported to ")
	    error_handler.append(other.eiffel_view)
	    other.locate_in_error_handler
	    error_handler.extend('.')
            error_handler.print_as_error
	    --
            error_handler.add_position(enclosing.start_position)
            error_handler.append("This routine, is exported to ")
	    error_handler.append(Current.eiffel_view)
	    Current.locate_in_error_handler
            error_handler.append(" (when the type of Current is ")
            error_handler.append(enclosing.current_type.run_time_mark)
            error_handler.append(" ).")
            if cn /= Void then
	       error_handler.append(" (Class ")
	       error_handler.append(cn.to_string)
	       error_handler.append(" is not allowed to use the code inside the %
			 %require assertion.)")
            end
            error_handler.print_as_fatal_error
         end
      end

feature {CLIENT_LIST_VISITOR}

   accept(visitor: CLIENT_LIST_VISITOR) is
      do
         visitor.visit_client_list(Current)
      end

feature {CLIENT_LIST, CLIENT_LIST_VISITOR}

   list: CLASS_NAME_LIST

feature {NONE}

   make(sp: like start_position; l: like list) is
         -- When the client list is really written.
         --
         -- Note : {NONE} has the same meaning as {}.
      require
         not sp.is_unknown
      do
         start_position := sp
         list := l
	 debug
	    if eiffel_view /= Void then end
	 end
      ensure
         start_position = sp
         list = l
      end

   omitted is
         -- When the client list is omitted. (Remind that when the
         -- client list is omitted, it is like {ANY}.)
      do
      end

   merge(sp: like start_position; l1, l2: like list) is
      require
         not sp.is_unknown
      do
         start_position := sp
         create list.merge(l1,l2)
	 debug
	    eiffel_view_memory := Void
	    if eiffel_view /= Void then end
	 end
      end

   eiffel_view_memory: STRING
	 -- To cache the Result of `eiffel_view'.

end -- CLIENT_LIST
