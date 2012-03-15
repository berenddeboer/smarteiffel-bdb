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
class CREATION_CLAUSE
   --
   -- The store the contents of one creation clause.
   --   example 1
   --                creation {ANY} make
   --   example 2
   --                creation make, foo
   --   example 3
   --                creation {NONE,ANY} make, foo
   --   example 4
   --                creation
   --
   -- Note : The original text of the source file can be stored
   --        for pretty pretty_printing to be fine.
   --

inherit
   GLOBALS
   VISITABLE

creation make

feature

   start_position: POSITION
         -- Of the corresponding keyword.

   clients: CLIENT_LIST

   comment: COMMENT

feature {NONE}

   make(sp: like start_position; c: like clients
        cm: like comment; pl: like procedure_list) is
      require
         not sp.is_unknown
         c /= Void
      do
         start_position := sp
         clients := c
         comment := cm
         procedure_list := pl
      ensure
         clients = c
         comment = cm
         procedure_list = pl
      end

feature

   pretty_print is
      do
         pretty_printer.set_indent_level(0)
         if not pretty_printer.zen_mode then
            pretty_printer.skip_one_line
         else
            pretty_printer.indent
         end
         pretty_printer.keyword(once "creation")
         pretty_printer.set_indent_level(1)
         if clients /= Void then
            clients.pretty_print
         end
         if comment /= void then
            comment.pretty_print
         end
         pretty_printer.set_indent_level(1)
         if not pretty_printer.zen_mode then
            pretty_printer.indent
         end
         if procedure_list /= Void then
            procedure_list.pretty_print
         end
      end

   short(heading_done: BOOLEAN; client: CLASS_NAME): BOOLEAN is
         -- True when at least one creation list is printed.
      do
         if clients.gives_permission_to(client) then
            if not heading_done then
               short_print.hook_or("hook100","creation%N")
            end
            if procedure_list /= Void then
               procedure_list.short_for_creation
            end
            short_print.hook_or("hook101","")
            Result := true
         else
            error_handler.cancel
         end
      end

   has(fn: FEATURE_NAME): BOOLEAN is
      require
         fn /= Void
      do
         if procedure_list /= Void then
            Result := procedure_list.has(fn)
         end
      end

feature {CREATION_CLAUSE_VISITOR}

   procedure_list: FEATURE_NAME_LIST

   accept(visitor: CREATION_CLAUSE_VISITOR) is
      do
         visitor.visit_creation_clause(Current)
      end

feature {CREATION_CLAUSE_LIST}

   default_root: STRING is
	 -- Return the default creation procedure name to be used as the root
	 -- procedure (the execution entry point of the system).
      do
         if procedure_list /= Void then
	    if procedure_list.has_make then
	       Result := as_make
	    else
	       Result := procedure_list.first.to_string
	    end
	 end
      end

   root_creation_search(a_name: STRING): FEATURE_NAME is
      do
         if procedure_list /= Void then
            Result := procedure_list.root_creation_search(a_name)
         end
      end

   check_expanded_with(t: E_TYPE) is
      require
         t.is_expanded
      local
         rf: RUN_FEATURE; rf3: RUN_FEATURE_3; rc: RUN_CLASS
      do
         if procedure_list = Void then
            error_handler.add_position(start_position)
            error_handler.append(
               "Cannot create a class with an empty creation list.")
	    error_handler.print_as_fatal_error
         end
         if procedure_list.count > 1 then
            error_handler.add_type(t,fz_cbe)
            error_handler.add_position(start_position)
            fatal_error_vtec_2
         end
         rc := t.run_class
         rf := rc.get_feature(procedure_list.first)
         if rf = Void then
            error_handler.add_position(start_position)
            error_handler.append("Creation procedure for ")
            error_handler.add_type(t," not found.")
            error_handler.print_as_fatal_error
         end
         rf3 ?= rf
         if rf3 = Void then
            error_handler.add_position(start_position)
            error_handler.add_position(rf.start_position)
            error_handler.append("Feature found is not a procedure.")
	    error_handler.print_as_fatal_error
         end
         if rf3.arguments /= Void then
            error_handler.add_type(t,fz_cbe)
            error_handler.add_position(start_position)
            error_handler.add_position(rf3.start_position)
            error_handler.append("Procedure found has arguments. ")
            fatal_error_vtec_2
         end
      end

   a_default_create(type: E_TYPE): RUN_FEATURE_3 is
      require
         type /= Void
      local
	 i: INTEGER; fn, rfn: FEATURE_NAME
	 rc: RUN_CLASS; rf: RUN_FEATURE
      do
         if procedure_list /= Void then
	    rc := type.run_class
	    from
	       i := procedure_list.count
	    until
	       rf /= Void or else i <= 0
	    loop
	       fn := procedure_list.item(i)
	       if fn.to_string = as_default_create then
		  rf := rc.get_feature(fn)
		  rfn := fn
	       end
	       i := i - 1
	    end
	    if rf = Void and then type.is_expanded then
	       from
		  i := procedure_list.count
	       until
		  rf /= Void or else i <= 0
	       loop
		  fn := procedure_list.item(i)
		  rf := rc.get_feature(fn)
		  rfn := fn
		  if rf /= Void then
		     if rf.arguments /= Void then
			rf := Void
		     end
		  end
		  i := i - 1
	       end
	    end
	    if rf /= Void then
	       Result ?= rf
	       if Result = Void then
		  error_handler.add_position(rf.start_position)
		  error_handler.add_position(rfn.start_position)
		  error_handler.append(fz_ffinap)
		  error_handler.print_as_fatal_error
	       end
	    end
         end
      end

invariant

   clients /= Void

end -- CREATION_CLAUSE

