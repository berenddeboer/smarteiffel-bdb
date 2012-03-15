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
class BASE_CLASS
   --
   -- Internal representation of an Eiffel source base class.
   --

inherit
   HASHABLE redefine is_equal end
   GLOBALS
   ASSERTION_LEVEL_NUMBERING
   VISITABLE

creation
   {EIFFEL_PARSER} make

creation
   {TYPE_TUPLE, SMART_EIFFEL} face_class

feature

   id: INTEGER_16
	 -- To produce compact C code.

   path: STRING
	 -- Access to the corresponding file (full file path).

   cluster: CLUSTER
	 -- The `cluster' used to load the class (also gives acces to
	 -- the directory path).

   index_list: INDEX_LIST
	 -- For the indexing of the class.

   heading_comment1: COMMENT
	 -- Comment before keyword `class'.

   is_deferred: BOOLEAN
	 -- True if class itself is deferred or if at least one
	 -- feature is deferred

   is_expanded: BOOLEAN
	 -- True if class itself is expanded.

   is_separate: BOOLEAN
         -- True if the class itself is separate. See scoop.html

   maybe_separate: BOOLEAN
         -- True if some entity uses that class as separate (i.e. some
         -- TYPE_SEPARATE object exists.) See scoop.html

   name: CLASS_NAME
	 -- The short name of the class (no `cluster' name included).

   formal_generic_list: FORMAL_GENERIC_LIST
	 -- Formal generic args if any.

   heading_comment2: COMMENT
	 -- Comment after class name.

   obsolete_type_string: MANIFEST_STRING
	 -- To warn user if any.

   parent_list: PARENT_LIST
	 -- The contents of the inherit clause if any.

   creation_clause_list: CREATION_CLAUSE_LIST
	 -- Constructor list.

   feature_clause_list: FEATURE_CLAUSE_LIST
	 -- Features.

   class_invariant: CLASS_INVARIANT
	 -- If any, the class invariant.

   end_comment: COMMENT
	 -- Comment after end of class.

   assertion_level: INTEGER
	 -- The one `Current' (mangled using ASSERTION_LEVEL_NUMBERING).

   sedb_trace: BOOLEAN
	 -- Is the -sedb run-time trace mechanism activated for the
	 -- `Current' class?

   no_check: BOOLEAN is
	 -- Is `Current' in -no_check mode ?
      do
	 if assertion_level = level_unknown then
	    assertion_level := ace.assertion_level_of(Current)
	 end
	 Result := assertion_level >= level_no
      end

   require_check: BOOLEAN is
	 -- Is `Current' in -require_check mode ?
      do
	 if assertion_level = level_unknown then
	    assertion_level := ace.assertion_level_of(Current)
	 end
	 Result := assertion_level >= level_require
      end

   ensure_check: BOOLEAN is
	 -- Is `Current' in -ensure_check mode ?
      do
	 if assertion_level = level_unknown then
	    assertion_level := ace.assertion_level_of(Current)
	 end
	 Result := assertion_level >= level_ensure
      end

   invariant_check: BOOLEAN is
	 -- Is `Current' in -invariant_check mode ?
      do
	 if assertion_level = level_unknown then
	    assertion_level := ace.assertion_level_of(Current)
	 end
	 Result := assertion_level >= level_invariant
      end

   loop_check: BOOLEAN is
	 -- Is `Current' in -loop_check mode ?
      do
	 if assertion_level = level_unknown then
	    assertion_level := ace.assertion_level_of(Current)
	 end
	 Result := assertion_level >= level_loop
      end

   all_check: BOOLEAN is
	 -- Is `Current' in -all_check mode ?
      do
	 if assertion_level = level_unknown then
	    assertion_level := ace.assertion_level_of(Current)
	 end
	 Result := assertion_level >= level_all
      end

   a_default_create(type: E_TYPE): RUN_FEATURE_3 is
	 -- When the corresponding `base_class' has a `default_create' or
	 -- to get the creation procedure of and expanded class.
      require
	 type.base_class = Current
      do
	 if creation_clause_list /= Void then
	    Result := creation_clause_list.a_default_create(type)
	 end
      end

   new_name_of(top: BASE_CLASS; top_fn: FEATURE_NAME): FEATURE_NAME is
	 -- Assume, `top_fn' is a valid notation to denote a feature
	 -- of `top'. It computes the corresponding name (taking in account
	 -- possible rename/select) to use this feature down in class
	 -- hierarchy (in the Current base_class).
      require
	 Current = top or else Current.is_subclass_of(top)
	 top_fn /= Void
      do
	 if Current = top then
	    Result := top_fn
	 else
	    Result := top.up_to_original(Current,top_fn)
	    if Result = Void then
	       error_handler.add_position(top_fn.start_position)
	       error_handler.append(fz_09)
	       error_handler.append(top_fn.to_string)
	       error_handler.append("%" from %"")
	       error_handler.append(top.name.to_string)
	       error_handler.append("%" not found in %"")
	       error_handler.append(name.to_string)
	       error_handler.append("%".")
	       error_handler.print_as_fatal_error
	    end
	 end
      ensure
	 Result /= Void
      end

   get_copy: E_FEATURE is
      do
	 fn_buffer.unknown_position(as_copy)
	 Result := feature_dictionary.at(fn_buffer)
      ensure
	 Result /= Void
      end

   clients_for(fn: FEATURE_NAME): CLIENT_LIST is
	 -- Looking up for the clients list when calling feature `fn' with
	 -- some object from current class. Assume `fn' exists.
      local
	 f: E_FEATURE
      do
	 f := feature_dictionary.reference_at(fn)
	 if f /= Void then
	    Result := f.clients
	 elseif is_general then
	 elseif parent_list = Void then
	    Result := class_any.clients_for(fn)
	 else
	    check
	       parent_list.count >= 1
	    end
	    Result := parent_list.clients_for(fn)
	 end
      ensure
	 -- *** ??? Result /= Void
      end

   has_creation_clause: BOOLEAN is
      do
	 Result := creation_clause_list /= Void
      end

   has_creation(proc_name: FEATURE_NAME): BOOLEAN is
	 -- Is `proc_name' the name of a creation procedure? Also check that
	 -- `proc_name' is written in an allowed base class for creation.
      require
	 proc_name.origin_base_class /= Void
      local
	 cc: CREATION_CLAUSE; bc: BASE_CLASS; cn: CLASS_NAME; cl: CLIENT_LIST
      do
	 if creation_clause_list = Void then
	    error_handler.append(name.to_string)
	    error_handler.append(once " has no creation clause. This %
				      %creation call is thus not allowed.")
	    error_handler.add_position(proc_name.start_position)
	    error_handler.print_as_error
	 else
	    cc := creation_clause_list.get_clause(proc_name)
	    if cc = Void then
	       error_handler.append(fz_09)
	       error_handler.append(proc_name.to_string)
	       error_handler.append(once "%" does not belong to a creation %
					   %clause of ")
	       error_handler.append(name.to_string)
	       error_handler.add_position(proc_name.start_position)
	       error_handler.append(". This creation call is thus not %
				    %allowed.")
	       error_handler.print_as_error
	    else
	       Result := True
	       bc := proc_name.origin_base_class
	       if bc /= Void then
		  cn := bc.name
		  cl := cc.clients
		  Result := cl.gives_permission_to(cn)
		  if not Result then
		     error_handler.add_position(proc_name.start_position)
		     error_handler.append("Forbidden creation call (i.e. exportation %
			       %rules violated). Creation is only allowed %
			       %from ")
		     error_handler.append(cl.eiffel_view)
		     cl.locate_in_error_handler
		     error_handler.extend('.')
		     error_handler.print_as_error
		  end
	       end
	    end
	 end
      end

   is_generic: BOOLEAN is
	 -- When class is defined with generic arguments.
      do
	 Result := formal_generic_list /= Void
      end

   proper_has(fn: FEATURE_NAME): BOOLEAN is
	 -- True when `fn' is really written in current class.
      do
	 Result := feature_dictionary.has(fn)
      end

   is_subclass_of(other: BASE_CLASS): BOOLEAN is
	 -- Is Current a subclass of `other' ?
      require
	 other /= Current
      local
	 other_name: STRING
      do
	 if is_subclass_of_memory.has(other) then
	    Result := is_subclass_of_memory.at(other)
	 else
	    other_name := other.name.to_string
	    if other_name = as_any then
	       Result := True
	    elseif other_name = as_platform then
	       Result := True
	    elseif parent_list /= Void then
	       Result := parent_list.has_parent(other)
	    elseif other_name = as_general then
	       Result := True
	    elseif other_name = as_none then
	    elseif is_none then
	       Result := True
	    end
	    is_subclass_of_memory.add(Result,other)
	 end
      end

   is_any: BOOLEAN is
	 -- Is it the ANY class ?
      do
	 Result := name.to_string = as_any
      end

   is_general: BOOLEAN is
	 -- Is it the GENERAL class ?
      do
	 Result := name.to_string = as_general
      end

   is_platform: BOOLEAN is
	 -- Is it the PLATFORM class ?
      do
	 Result := name.to_string = as_platform
      end

   is_none: BOOLEAN is
	 -- Is it the NONE class ?
      do
	 Result := name.to_string = as_none
      end

   has_redefine(fn: FEATURE_NAME): BOOLEAN is
      require
	 fn /= Void
      do
	 if parent_list /= Void then
	    Result := parent_list.has_redefine(fn)
	 end
      end

   e_feature(fn: FEATURE_NAME): E_FEATURE is
	 -- Simple (and fast) look_up to see if `fn' exists here.
      do
	 Result := feature_dictionary.reference_at(fn)
	 if Result = Void then
	    Result := super_e_feature(fn)
	 end
      end

   has(fn: FEATURE_NAME): BOOLEAN is
	 -- Simple (and fast) look_up to see if `fn' exists here.
      require
	 fn /= Void
      do
	 Result := e_feature(fn) /= Void
      end

   hash_code: INTEGER
	 -- Actually, in order to speed up the compiler, this is a cache
	 -- for value `name.to_string.hash_code'.

   is_equal(other: like Current): BOOLEAN is
      do
	 Result := Current = other
      end

   pretty_print is
      do
	 pretty_printer.set_indent_level(0)
	 if index_list /= Void then
	    index_list.pretty_print
	    pretty_printer.indent
	 end
	 if heading_comment1 /= Void then
	    heading_comment1.pretty_print
	    pretty_printer.indent
	 end
	 if is_deferred then
	    pretty_printer.keyword(once "deferred")
	 elseif is_expanded then
	    pretty_printer.keyword(fz_expanded)
	    end
	    pretty_printer.keyword(once "class")
	    name.pretty_print
	    if is_generic then
	       formal_generic_list.pretty_print
	    end
	    pretty_printer.indent
	    if obsolete_type_string /= Void then
	       pretty_printer.keyword(once "obsolete")
	       obsolete_type_string.pretty_print
	    end
	    pretty_printer.indent
	    if heading_comment2 /= Void then
	       pretty_printer.set_indent_level(1)
	       pretty_printer.indent
	       heading_comment2.pretty_print
	    end
	    if parent_list /= Void then
	       parent_list.pretty_print
	    end
	    if creation_clause_list /= Void then
	       creation_clause_list.pretty_print
	    end
	    if feature_clause_list /= Void then
	       feature_clause_list.pretty_print
	    end
	    if class_invariant /= Void then
	       class_invariant.pretty_print
	    end
	    pretty_printer.set_indent_level(0)
	    pretty_printer.indent
	    if not pretty_printer.zen_mode then
	       pretty_printer.skip_one_line
	    end
	    pretty_printer.keyword(fz_end)
	    if end_comment /= Void
	       and then not end_comment.is_dummy_base_class_end(Current)
	     then
	       end_comment.pretty_print
	    elseif not pretty_printer.zen_mode then
	       pretty_printer.put_string(once "-- class ")
	       pretty_printer.put_string(name.to_string)
	    end
	    if pretty_printer.column /= 1 then
	       pretty_printer.put_character('%N')
	    end
	 end

feature {TYPE_SEPARATE}

   set_maybe_separate is
      do
         if is_expanded then
            error(name.start_position,
                  once "An expanded class cannot be separate.")
         end
         maybe_separate := True
      end

feature {TYPE_CLASS}

   smallest_ancestor(type, other: E_TYPE): E_TYPE is
	 -- To help implementation of E_TYPE.smallest_ancestor while one
	 -- have to consider parents. Note that `type' is directly related
	 -- to `Current'.
      require
	 type.is_run_type
	 other.is_run_type
	 type.base_class = Current
	 not other.is_any
	 not other.is_none
	 other.base_class /= Void
      local
	 c1, c2: INTEGER; bc2: BASE_CLASS; pl1, pl2: like parent_list
      do
	 if is_any then
	    Result := type
	 elseif type.run_time_mark = other.run_time_mark then
	    Result := type
	 else
	    pl1 := parent_list
	    if pl1 = Void then
	       Result := type_any
	    else
	       bc2 := other.base_class
	       pl2 := bc2.parent_list
	       if pl2 = Void then
		  Result := type_any
	       else
		  c1 := pl1.count
		  c2 := pl2.count
		  if c1 < c2 then
		     Result := pl1.smallest_ancestor(type,other)
		  else
		     Result := pl2.smallest_ancestor(other,type)
		  end
	       end
	    end
	 end
      ensure
	 Result /= Void
      end

feature {CLASS_CHECKER, EIFFEL_PARSER}

   set_heading_comment2(hc: like heading_comment2) is
      do
	 heading_comment2 := hc
      end

feature {CLASS_CHECKER, PARENT_LIST}

   up_to_any_in(pl: FIXED_ARRAY[BASE_CLASS]) is
      do
	 if not is_general then
	    if not pl.fast_has(Current) then
	       pl.add_last(Current)
	    end
	    if parent_list = Void then
	       if not pl.fast_has(class_any) then
		  pl.add_last(class_any)
	       end
	    else
	       parent_list.up_to_any_in(pl)
	    end
	 end
      end

feature {RUN_CLASS}

   get_default_rescue(rc: RUN_CLASS; n: FEATURE_NAME): RUN_FEATURE_3 is
      local
	 general: BASE_CLASS; p: E_PROCEDURE; fn1, fn2: FEATURE_NAME
      do
	 general := class_general
	 if Current /= general then
	    p := general.general_default_rescue
	    if p /= Void then
	       fn1 := p.first_name
	       fn2 := new_name_of(general,fn1)
	       if fn2.to_string /= n.to_string then
		  p ?= look_up_for(rc,fn2)
		  if p /= Void then
		     Result := p.a_default_rescue(rc,fn2)
		  end
	       end
	    end
	 end
      end

   check_expanded_with(type: E_TYPE) is
      require
	 type.is_expanded
	 type.base_class = Current
      local
	 rf: RUN_FEATURE
      do
	 if is_deferred then
	    error_handler.add_type(type,fz_is_invalid)
	    error_handler.append(
               " A deferred class must not be expanded (VTEC.1).")
	    error_handler.print_as_fatal_error
	 end
	 if creation_clause_list /= Void then
	    creation_clause_list.check_expanded_with(type)
	 end
	 rf := a_default_create(type)
      end

feature {ONCE_ROUTINE_POOL}

   once_flag(mark: STRING): BOOLEAN is
	 -- Flag used to avoid double C definition of globals C variables for 
	 -- once routines.
      require
	 mark = string_aliaser.item(mark)
	 smart_eiffel.is_ready
      do
	 if once_mark_list = Void then
	    create once_mark_list.with_capacity(4)
	    once_mark_list.add_last(mark)
	 elseif once_mark_list.fast_has(mark) then
	    Result := True
	 else
	    once_mark_list.add_last(mark)
	 end
      ensure
	 once_flag(mark)
      end

feature {TYPE_FORMAL_GENERIC}

   first_parent_for(other: like Current): PARENT is
	 -- Assume `other' is a parent of Current, gives
	 -- the closest PARENT of Current going to `other'.
      require
	 is_subclass_of(other)
	 parent_list /= Void
      do
	 Result := parent_list.first_parent_for(other)
      ensure
	 Result /= Void
      end

   next_parent_for(other: like Current; previous: PARENT): like previous is
	 -- Gives the next one or Void.
      require
	 is_subclass_of(other)
	 parent_list /= Void
      do
	 Result := parent_list.next_parent_for(other,previous)
      end

feature {BASE_CLASS,PARENT}

   up_to_original(bottom: BASE_CLASS; top_fn: FEATURE_NAME): FEATURE_NAME is
	 -- Assume `top_fn' is a valid name in `bottom'. Try to go up in the
	 -- hierarchy to retrieve the original name of the feature.
      require
	 top_fn /= Void
	 Current = bottom or else bottom.is_subclass_of(Current)
      local
	 dico: DICTIONARY[FEATURE_NAME,BASE_CLASS]
      do
	 if ace.high_memory_compiler then
	    dico := up_to_original_memory.reference_at(top_fn)
	    if dico = Void then
	       create dico.make
	       up_to_original_memory.add(dico,top_fn)
	    end
	    Result := dico.reference_at(bottom)
	    if Result = Void then
	       Result := up_to_original_(bottom,top_fn)
	       dico.put(Result,bottom)
	    end
	 else
	    Result := up_to_original_(bottom,top_fn)
	 end
      end

feature {NONE}

   up_to_original_memory:
      DICTIONARY[DICTIONARY[FEATURE_NAME,BASE_CLASS],FEATURE_NAME]

   up_to_original_(bottom: BASE_CLASS; top_fn: FEATURE_NAME): FEATURE_NAME is
      require
	 top_fn /= Void
	 Current = bottom or else bottom.is_subclass_of(Current)
      do
	 if proper_has(top_fn) then
	    if parent_list = Void then
	       Result := bottom.new_name_of_original(Current,top_fn)
	    else
	       Result := parent_list.up_to_original(bottom,top_fn)
	       if Result = Void then
		  Result := bottom.new_name_of_original(Current,top_fn)
	       end
	    end
	 elseif parent_list /= Void then
	    Result := parent_list.up_to_original(bottom,top_fn)
	 elseif is_general then
	 else
	    Result := class_any.up_to_original(bottom,top_fn)
	 end
      end

feature {RUN_FEATURE_1,PARENT,BASE_CLASS}

   original_name(top: BASE_CLASS; bottom_fn: FEATURE_NAME): FEATURE_NAME is
	 -- Assume that `bottom_fn' is a valid name in `Current'. Compute the
	 -- original definition name going up in the hierarchy to `top'.
      require
	 bottom_fn /= Void
	 Current = top or else Current.is_subclass_of(top)
      do
	 if Current = top then
	    check
	       name.to_string /= as_tuple implies proper_has(bottom_fn)
	    end
	    Result := bottom_fn
	 elseif parent_list /= Void then
	    Result := parent_list.original_name(top,bottom_fn)
	 else
	    Result := top.original_name(top,bottom_fn)
	    if Result = Void then
	       Result := bottom_fn
	       error_handler.add_position(bottom_fn.start_position)
	       error_handler.append(top.name.to_string)
	       error_handler.append(once "<---")
	       error_handler.append(name.to_string)
	       error_handler.append(once ". BASE_CLASS.original_name, Not Yet Implemented.")
	       error_handler.print_as_warning
	    end
	 end
      ensure
	 Result /= Void
      end

feature {BASE_CLASS}

   new_name_of_original(top: BASE_CLASS; top_fn: FEATURE_NAME): FEATURE_NAME is
	 -- Compute rename/select to go down in class hierarchy. In the very
	 -- first call, `top_fn' is the name used in `top'.
      require
	 top_fn /= Void
	 top.proper_has(top_fn)
	 Current = top or else Current.is_subclass_of(top)
      do
	 if Current = top then
	    Result := top_fn
	 else
	    check not is_general end
	    if parent_list = Void then
	       Result := class_any.new_name_of(top,top_fn)
	    else
	       going_up_trace.clear
	       Result := parent_list.going_up(going_up_trace,top,top_fn)
	    end
	 end
      ensure
	 Result /= Void
      end

   general_default_rescue: E_PROCEDURE is
      do
	 fn_buffer.unknown_position(as_default_rescue)
	 if feature_dictionary.has(fn_buffer) then
	    Result ?= feature_dictionary.at(fn_buffer)
	 end
      end

feature {BASE_CLASS,PARENT_LIST,PARENT}

   going_up(trace: FIXED_ARRAY[PARENT]; top: BASE_CLASS
	    top_fn: FEATURE_NAME;): FEATURE_NAME is
      require
	 Current /= top
      do
	 if parent_list = Void then
	    Result := class_any.going_up(trace,top,top_fn)
	 else
	    Result := parent_list.going_up(trace,top,top_fn)
	 end
      end

feature

   mapping_c_in(str: STRING) is
      do
	 str.extend('B')
	 str.extend('C')
	 id.append_in(str)
      end

   mapping_c is
      local
	 s: STRING
      do
	 s := once "        "
	 s.clear
	 mapping_c_in(s)
	 cpp.put_string(s)
      end

feature {EIFFEL_PARSER}

   add_index_clause(index_clause: INDEX_CLAUSE) is
      require
	 index_clause /= Void
      do
	 if index_list = Void then
	    !!index_list.make(index_clause)
	 else
	    index_list.add_last(index_clause)
	 end
      end

   add_creation_clause(cc: CREATION_CLAUSE) is
      require
	 cc /= Void
      do
	 if creation_clause_list = Void then
	    !!creation_clause_list.make(cc)
	 else
	    creation_clause_list.add_last(cc)
	 end
      end

   add_feature_clause(fc: FEATURE_CLAUSE) is
      require
	 fc /= Void
      do
	 if feature_clause_list = Void then
	    !!feature_clause_list.make(fc)
	 else
	    feature_clause_list.add_last(fc)
	 end
      end

   set_is_deferred is
      do
	 if is_expanded then
	    error_vtec1
         elseif is_separate then
            error(name.start_position,
                  once "A class cannot be separate and deferred.")
	 end
	 is_deferred := True
      end

   set_is_expanded is
      do
	 if is_deferred then
	    error_vtec1
         elseif is_separate then
            error(name.start_position,
                  once "A class cannot be separate and expanded.")
	 end
	 is_expanded := True
      end

   set_is_separate is
      do
         if is_expanded then
            error(name.start_position,
                  once "A class cannot be separate and expanded.")
         elseif is_deferred then
            error(name.start_position,
                  once "A class cannot be separate and deferred.")
         end
         is_separate := True
         set_maybe_separate
      end

   set_formal_generic_list(fgl: like formal_generic_list) is
      do
	 formal_generic_list := fgl
      end

   set_heading_comment1(hc: like heading_comment1) is
      do
	 heading_comment1 := hc
      end

   set_parent_list(sp: POSITION; c: COMMENT; l: FIXED_ARRAY[PARENT]) is
      require
	 not sp.is_unknown
	 c /= Void or else l /= Void
	 l /= Void implies not l.is_empty
      do
	 !!parent_list.make(Current,sp,c,l)
      end

   set_end_comment(ec: like end_comment) is
      do
	 end_comment := ec
      end

   set_obsolete_type_string(ots: like obsolete_type_string) is
      do
	 obsolete_type_string := ots
      end

   set_invariant(sp: POSITION; hc: COMMENT; al: FIXED_ARRAY[ASSERTION]) is
      do
	 if hc /= Void or else al /= Void then
	    create class_invariant.make(sp,hc,al)
	 end
      end

   get_started is
	 -- Called just after parsing to initialize and start checking.
      do
	 if feature_clause_list /= Void then
	    feature_clause_list.get_started(feature_dictionary)
	 end
	 if parent_list /= Void then
	    if not smart_eiffel.pretty_flag then
	       parent_list.get_started_step_1
	       -- Checking for inheritance cycle:
	       visited.clear
	       visited.add_last(Current)
	       parent_list.inherit_cycle_check
	       -- 
	       parent_list.get_started_step_2
	    end
	 end
	 if end_comment /= Void then
	    end_comment.good_end(name)
	 end
	 if is_deferred and then creation_clause_list /= Void then
	    error_handler.add_position(name.start_position)
	    warning(creation_clause_list.start_position,
		    once "Deferred class should not have %
		    %creation clause (VGCP.1).")
	 end
	 sedb_trace := ace.trace_of(Current)
      end

feature {ACE}

   default_root_procedure_name: STRING is
	 -- Return the default creation procedure name to be used as the root
	 -- procedure (the execution entry point of the system).
      do
	 fatal_error_when_no_creation_clause
	 Result := creation_clause_list.default_root
      ensure
	 Result /= Void
      end

feature {SMART_EIFFEL}

   root_creation_search(a_name: STRING): FEATURE_NAME is
	 -- Check that `a_name' is actually member of some creation clause.
      require
	 not a_name.is_empty
      do
	 fatal_error_when_no_creation_clause
	 Result := creation_clause_list.root_creation_search(a_name)
	 if Result = Void then
	    error_handler.add_position(name.start_position)
	    error_handler.append("Bad root procedure name (%"")
	    error_handler.append(a_name)
	    error_handler.append(
               "%" is not a creation procedure of this class).")
	    error_handler.print_as_fatal_error
	 end
      ensure
	 Result.is_simple_feature_name
      end

   root_procedure_check(procedure_name: FEATURE_NAME): E_PROCEDURE is
	 -- Look for the root procedure to start execution here.
	 -- Do some checking on the root class (not deferred, not generic,
	 -- really has `procedure_name' as a creation procedure etc.).
	 -- Return Void and print errors if needed.
      require
	 procedure_name = root_creation_search(procedure_name.to_string)
      local
	 rc: RUN_CLASS; f: E_FEATURE
      do
	 if is_generic then
	    error_handler.append(name.to_string)
	    error_handler.append(
               " cannot be a root class since it is a generic class.")
	    error_handler.print_as_fatal_error
	 end
	 if is_deferred then
	    error_handler.append(name.to_string)
	    error_handler.append(
               " cannot be a root class since it is a deferred class.")
	    error_handler.print_as_warning
	 end
	 rc := smart_eiffel.run_class_for(name)
	 rc.set_at_run_time
	 f := look_up_for(rc,procedure_name)
	 if f = Void then
	    error_handler.add_position(procedure_name.start_position)
	    error_handler.append("Root procedure not found.")
	    error_handler.print_as_fatal_error
	 end
	 Result ?= f
	 if Result = Void then
	    error_handler.add_position(f.start_position)
	    error_handler.append(
               "Invalid Root. Only procedure are allowed (VGCC.6).")
	    error_handler.print_as_fatal_error
	 end
      ensure
	 Result /= Void
      end

   check_generic_formal_arguments is
      do
	 if formal_generic_list /= Void then
	    formal_generic_list.check_generic_formal_arguments
	 end
      end

   id_extra_information(tfw: TEXT_FILE_WRITE) is
      do
	 tfw.put_string(once "class-name: ")
	 tfw.put_string(name.to_string)
	 tfw.put_string(once "%Nparent-count: ")
	 if parent_list /= Void then
	    parent_list.id_extra_information(tfw)
	 else
	    tfw.put_character('0')
	 end
	 tfw.put_character('%N')
      end

   obsolete_warning(client_name: CLASS_NAME) is
      require
	 client_name.to_string = name.to_string
      do
   	 if obsolete_type_string /= Void then
	    if smart_eiffel.short_flag then
	    elseif smart_eiffel.pretty_flag then
	    else
	       error_handler.add_position(client_name.start_position)
	       error_handler.append(once "Class ")
	       error_handler.append(name.to_string)
	       error_handler.append(once " is obsolete :%N")
	       error_handler.append(obsolete_type_string.to_string)
	       error_handler.add_position(name.start_position)
	       error_handler.print_as_warning
	    end
	 end
      end

feature {PARENT_LIST,BASE_CLASS}

   inherit_cycle_check is
      local
	 i: INTEGER
      do
	 visited.add_last(Current)
	 if visited.first = Current then
	    error_handler.append("Cyclic inheritance graph: ")
	    from
	       i := 0
	    until
	       i > visited.upper
	    loop
	       error_handler.append(visited.item(i).name.to_string)
	       if i < visited.upper then
		  error_handler.append(", ")
	       end
	       i := i + 1
	    end
	    error_handler.append(", ...")
	    error_handler.print_as_fatal_error
	 elseif parent_list /= Void then
	    parent_list.inherit_cycle_check
	 end
      end

feature {CALL_PROC_CALL, E_AGENT}

   run_feature_for(rc: RUN_CLASS; target: EXPRESSION
		   fn: FEATURE_NAME; ct: E_TYPE): RUN_FEATURE is
	 -- Fetch the corresponding one in `rc' when the context is `ct'
	 -- (the context is the type of Current). Exporting rules are
	 -- automatically checked and possible rename are also done. No
	 -- return when an error occurs because `fatal_error' is called.
      require
	 -- *** target.result_type.base_class = Current
	 -- This should be True ....
	 ---
	 target.result_type.run_class = rc
         rc.base_class = Current
	 not fn.start_position.is_unknown
      local
	 top_bc, bc: BASE_CLASS; lfn, nfn: FEATURE_NAME; bcn: CLASS_NAME
	 target_type: E_TYPE; lf: E_FEATURE; tlf: TYPE_LIKE_FEATURE
	 cl: CLIENT_LIST
      do
	 check
	    fn.to_string /= as_eq
	    fn.to_string /= as_neq
	 end
	 -- Compute possible rename first:
	 nfn := fn
	 target_type := target.result_type
	 if target_type.is_like_current and then
	    target_type.run_time_mark = ct.run_time_mark
	  then
	    top_bc := target.start_position.base_class
	    check
	       ct.base_class = Current
	    end
	    nfn := new_name_of(top_bc,fn)
	 elseif target_type.is_like_feature then
	    tlf ?= target_type
	    lfn := tlf.like_what
	    bc := lfn.start_position.base_class
	    lf := bc.e_feature(lfn)
	    top_bc := lf.result_type.start_lookup_class
	    if top_bc /= Void then
	       bc := target.result_type.base_class
	       if bc = top_bc or else bc.is_subclass_of(top_bc) then
		  if top_bc.has(fn) then
		     nfn := bc.new_name_of(top_bc,fn)
		  end
	       end
	    end
	 else
	    top_bc := target.start_lookup_class
	    if top_bc /= Void then
	       if Current = top_bc or else Current.is_subclass_of(top_bc) then
		  if top_bc.has(fn) then
		     nfn := Current.new_name_of(top_bc,fn)
		  end
	       end
	    end
	 end
	 check nfn /= Void end
	 -- Search for the feature:
	 Result := rc.get_feature(nfn)
	 if Result = Void then
	    error_handler.feature_not_found(fn)
	    error_handler.print_as_fatal_error
	 end
	 -- Check export rules:
	 if not target.is_current then
	    bcn := ct.base_class.name
	    cl := Result.clients
	    if not cl.gives_permission_to(bcn) then
	       error_handler.add_position(fn.start_position)
	       error_handler.append(
                  "Forbidden call (i.e. exportation rules violated) %
		  %when the type of Current is ")
	       error_handler.append(ct.run_time_mark)
	       error_handler.append(
                  ". (See the next error report for details.)")
	       error_handler.print_as_error
	       error_handler.add_position(Result.start_position)
	       error_handler.append("This feature is only exported to ")
	       error_handler.append(cl.eiffel_view)
	       cl.locate_in_error_handler
	       error_handler.extend('.')
	       error_handler.print_as_fatal_error
	    end
	 end
	 -- Finally, check for obsolete usage:
	 Result.base_feature.check_obsolete(fn.start_position)
      ensure
	 Result.run_class = rc
      end


feature {LOCAL_ARGUMENT,RUN_CLASS}

   has_simple_feature_name(sfn: STRING): BOOLEAN is
	 -- Simple (and fast) look_up to see if one feature of name
	 -- `n' exists here.
      require
	 sfn = string_aliaser.item(sfn)
      do
	 fn_buffer.unknown_position(sfn)
	 Result := has(fn_buffer)
      end

feature {BASE_CLASS, PARENT, RUN_CLASS}

   look_up_for(rc: RUN_CLASS; fn: FEATURE_NAME): E_FEATURE is
	 -- Gives Void or the good one to compute the runnable
	 -- version of `fn' in `rc'.
	 -- All inheritance rules are checked.
      local
	 super: E_FEATURE; cst_att: CST_ATT; fnl: FEATURE_NAME_LIST
	 super_fn: like fn; i: INTEGER
	 writable_attribute: WRITABLE_ATTRIBUTE
      do
	 Result := feature_dictionary.reference_at(fn)
	 if Result /= Void then
	    super :=  super_look_up_for(rc,fn)
	    if super /= Void then
	       vdrd6(rc,super,Result)
	       cst_att ?= super
	       if cst_att /= Void then
		  error_handler.add_position(super.start_position)
		  error_handler.add_position(Result.start_position)
		  error_handler.append(
                     "Constant feature cannot be redefined.")
		  error_handler.print_as_fatal_error
	       end
	       from
		  fnl := super.names
		  i := fnl.count
	       until
		  i < 1
	       loop
		  super_fn := fnl.item(i)
		  if super_fn.is_frozen then
		     if super_fn.to_key = fn.to_key then
			error_handler.add_position(super_fn.start_position)
			error_handler.add_position(Result.start_position)
			error_handler.append(
                           "Cannot redefine a frozen feature.")
			error_handler.print_as_fatal_error
		     end
		  end
		  i := i - 1
	       end
	       if not Result.can_hide(super,rc) then
		  writable_attribute ?= Result
		  if writable_attribute /= Void and then
		     writable_attribute.is_item_of_integer
		   then
		     -- The rule is relaxed for INTEGER_*.item definition.
		  else
		     error_handler.add_position(super.start_position)
		     error_handler.add_position(Result.start_position)
		     error_handler.append(
		        "Incompatible headings for redefinition.")
		     error_handler.add_context_info(rc.current_type)
		     error_handler.print_as_fatal_error
		  end
	       end
	       if super.is_deferred then
	       elseif has_redefine(fn) then
	       else
		  error_handler.add_position(Result.start_position)
		  error_handler.add_position(super.start_position)
		  error_handler.append("Invalid redefinition in ")
		  error_handler.append(name.to_string)
		  error_handler.append(". Missing redefine ?")
		  error_handler.print_as_error
	       end
	    end
	 else
	    Result := super_look_up_for(rc,fn)
	 end
      end

feature {RUN_CLASS, PARENT_LIST}

   collect_invariant(rc: RUN_CLASS) is
      require
	 rc /= Void
      do
	 if parent_list /= Void then
	    parent_list.collect_invariant(rc)
	 end
	 if class_invariant /= Void then
	    assertion_collector.invariant_add_last(class_invariant)
	 end
      end

feature {CLASS_INVARIANT,PARENT_LIST}

   header_comment_for(ci: CLASS_INVARIANT) is
      local
	 ia: like class_invariant
      do
	 ia := class_invariant
	 if ia /= Void and then ia.header_comment /= Void then
	    ci.set_header_comment(ia.header_comment)
	 elseif parent_list /= Void then
	    parent_list.header_comment_for(ci)
	 end
      end

feature {RUN_FEATURE}

   run_require(rf: RUN_FEATURE): RUN_REQUIRE is
	 -- Collect all (inherited) require assertions for `rf'.
      require
	 rf.current_type.base_class = Current
      local
	 ct: E_TYPE
      do
	 assertion_collector.require_start
	 ct := rf.current_type
	 collect_assertion(rf.name)
	 Result := assertion_collector.require_end(rf,ct)
      end

   run_ensure(rf: RUN_FEATURE): E_ENSURE is
	 -- Collect all (inherited) ensure assertions for `rf'.
      require
	 rf.current_type.base_class = Current
      local
	 ct: E_TYPE
      do
	 assertion_collector.ensure_start
	 ct := rf.current_type
	 collect_assertion(rf.name)
	 Result := assertion_collector.ensure_end(rf,ct)
      end

feature {BASE_CLASS, PARENT_LIST}

   collect_assertion(fn: FEATURE_NAME) is
      require
	 fn /= Void
      local
	 ef: E_FEATURE
      do
	 ef := feature_dictionary.reference_at(fn)
	 if ef /= Void then
	    assertion_collector.assertion_add_last(ef)
	 end
	 if parent_list = Void then
	    if not is_general then
	       class_any.collect_assertion(fn)
	    end
	 else
	    parent_list.collect_assertion(fn)
	 end
      end

feature {BASE_CLASS}

   super_e_feature(fn: FEATURE_NAME): E_FEATURE is

      do
	 if parent_list = Void then
	    if not is_general then
	       Result := class_any.e_feature(fn)
	    end
	 else
	    Result := parent_list.e_feature(fn)
	 end
      end

feature {FEATURE_NAME,E_FEATURE}

   fatal_undefine(fn: FEATURE_NAME) is
      do
	 error_handler.append("Problem with undefine of %"")
	 error_handler.append(fn.to_string)
	 error_handler.append("%" in %"")
	 error_handler.append(name.to_string)
	 error_handler.append("%".")
	 error_handler.print_as_fatal_error
      end

feature {E_TYPE, PARENT}

   is_a_vncg(t1, t2: E_TYPE): BOOLEAN is
	 -- Direct conformance of generic classes VNCG.
      require
	 t1.is_run_type
	 t2.is_run_type
	 t1.base_class = Current
	 t2.base_class /= Current
	 t2.generic_list /= Void
	 error_handler.is_empty
      do
	 if parent_list /= Void then
	    Result := parent_list.is_a_vncg(t1.run_type,t2.run_type)
	 end
      ensure
	 error_handler.is_empty
      end

feature {RUN_TIME_SET, PARENT}

   graph_node_vncg_update(site: POSITION; t1, t2: E_TYPE): BOOLEAN is
	 -- To update the assignment graph node for generic arguments.
      require
	 t1.run_type.is_a(t2.run_type)
	 t1.base_class = Current
	 t2.base_class /= Current
	 t2.generic_list /= Void
      do
	 check
	    parent_list /= Void
	    t1.run_type = t1
	    t2.run_type = t2
	 end
	 Result := parent_list.graph_node_vncg_update(site,t1,t2)
      end

feature {TYPE_FUNCTION}

   load_feature_item(toa: TYPE_OF_AGENT; rt: E_TYPE) is
      require
	 toa.run_type = toa
	 toa.base_class = Current
	 rt.run_type = rt
      local
	 sp: POSITION; at: TYPE_TUPLE; er: EXTERNAL_FUNCTION
	 n: FEATURE_NAME; arg: ARGUMENT_NAME1
	 fal: FORMAL_ARG_LIST; rf: RUN_FEATURE; rc: RUN_CLASS
      do
	 rc := toa.run_class
	 fn_buffer.unknown_position(as_item)
	 rf := rc.at(fn_buffer)
	 if rf = Void then
	    -- Creation of the `call' feature:
	    sp.set_in(Current)
	    create arg.make(sp, as_a1)
	    create at.make(sp, Void)
	    create fal.make(<<create {DECLARATION_1}.make(arg, at)>>)
	    create n.simple_feature_name(as_item, sp)
	    create er.make(create {FEATURE_NAME_LIST}.make_1(n),
			   fal, rt, Void, Void, Void,
			   create {NATIVE_SMART_EIFFEL}.default_create,
			   Void)
	    rf := er.to_run_feature(toa, n)
	    rf.set_clients_with_any
	 end
	 check
	    rc.at(fn_buffer) /= Void
	 end
      end

feature {TYPE_OF_AGENT}

   load_feature_call(toa: TYPE_OF_AGENT) is
      require
	 toa.run_type = toa
	 toa.written_mark = toa.run_time_mark
	 toa.base_class = Current
      local
	 sp: POSITION; at: TYPE_TUPLE; er: EXTERNAL_PROCEDURE
	 n: FEATURE_NAME; arg: ARGUMENT_NAME1
	 fal: FORMAL_ARG_LIST; rf: RUN_FEATURE; rc: RUN_CLASS
      do
	 rc := toa.run_class
	 fn_buffer.unknown_position(as_call)
	 rf := rc.at(fn_buffer)
	 if rf = Void then
	    -- Creation of the `call' feature:
	    sp.set_in(Current)
	    create arg.make(sp, as_a1)
	    create at.make(sp, Void)
	    create fal.make(<<create {DECLARATION_1}.make(arg,at)>>)
	    create n.simple_feature_name(as_call, sp)
	    create er.make(create {FEATURE_NAME_LIST}.make_1(n),
			   fal,Void,Void,Void,
			   create {NATIVE_SMART_EIFFEL}.default_create,
			   Void)
	    rf := er.to_run_feature(toa, n)
	    rf.set_clients_with_any
	 end
	 debug
	    fn_buffer.unknown_position(as_call)
	    check
	       rc.at(fn_buffer) /= Void
	    end
	 end
      end

feature {BASE_CLASS_VISITOR}

   accept(visitor: BASE_CLASS_VISITOR) is
      do
         visitor.visit_base_class(Current)
      end

feature {NONE}

   basic_create is
	 -- Common part to finish all create procedure.
      do
	 hash_code := name.hash_code
	 smart_eiffel.add_base_class(Current)
	 create feature_dictionary.make
	 create is_subclass_of_memory.with_capacity(256)
	 if ace.high_memory_compiler then
	    create up_to_original_memory.with_capacity(1024)
	 end
      end

   add_feature(f: E_FEATURE) is
	 -- To add pseudo features.
      require
	 f.names.count = 1
      do
	 f.set_clients(omitted_client_list)
	 f.add_into(feature_dictionary)
      end

   once_mark_list: FIXED_ARRAY[STRING]
	 -- When the tag is in the list, the corresponding routine
	 -- does not use Current and C code is already written.

   going_up_trace: FIXED_ARRAY[PARENT] is
      once
	 !!Result.with_capacity(8)
      end

   super_look_up_for(rc: RUN_CLASS; fn: FEATURE_NAME): E_FEATURE is
	 -- Same work as `look_up_for' but do not look in current
	 -- base class.
      require
	 rc /= Void
	 fn /= Void
      do
	 if parent_list = Void then
	    if not is_general then
	       Result := class_any.look_up_for(rc,fn)
	    end
	 else
	    Result := parent_list.look_up_for(rc,fn)
	 end
      end

   fn_buffer: FEATURE_NAME is
	 -- Dummy once name to avoid memory leaks.
      once
	 create Result.unknown_position(as_storage)
      end

   error_vtec1 is
      do
	 error(name.start_position,
	       once "A class cannot be expanded and deferred (VTEC.1).")
      end

   feature_dictionary: DICTIONARY[E_FEATURE,FEATURE_NAME]
	 -- All features really defined in the current class. Thus, it is
	 -- the same features contained in `feature_clause_list' (this
	 -- dictionary speed up feature look up).

   is_subclass_of_memory: DICTIONARY[BOOLEAN,BASE_CLASS]
	 -- This is a memory cache to avoid many recomputation of
	 -- `is_subclass_of'. This is also why the `hash_code' is cached too.

   make(p: like path;  my_name: STRING; c: like cluster; i: like id) is
      require
	 p = string_aliaser.item(p)
	 my_name = string_aliaser.item(my_name)
	 not smart_eiffel.no_file_for(my_name)
	 c /= Void
	 i > 0
      do
	 id := i
	 path := p
	 cluster := c
	 create name.unknown_position(my_name)
	 basic_create
      ensure
	 path = p
	 name.to_string = my_name
	 cluster = c
	 id = i
      end

   face_class(n: STRING) is
	 -- To create some face classes: TUPLE, ROUTINE, PROCEDURE,
	 -- FUNCTION, and PREDICATE.
      require
	 smart_eiffel.no_file_for(n)
      do
	 path := n
	 create name.unknown_position(n)
	 id := id_provider.item(n)
	 basic_create
      ensure
	 name.to_string = n
      end

   visited: FIXED_ARRAY[BASE_CLASS] is
	 -- List of all visited classes for the `inherit_cycle_check'.
      once
	 !!Result.with_capacity(32)
      end

   fatal_error_when_no_creation_clause is
      do
	 if creation_clause_list = Void then
	    error_handler.add_position(name.start_position)
	    error_handler.append(
               "Bad root class (this class has no creation clause).")
	    error_handler.print_as_fatal_error
	 end
      end


   vdrd6(rc: RUN_CLASS; super, redef: E_FEATURE) is
      require
	 super /= Void
	 redef /= Void
	 super /= redef
      local
	 writable_attribute: WRITABLE_ATTRIBUTE
	 ct, rt1, rt2: E_TYPE
      do
	 writable_attribute ?= super
	 if writable_attribute /= Void then
	    writable_attribute ?= redef
	    if writable_attribute = Void then
	       fatal_error_vdrd6(super,redef,
	       "An attribute must be redefined as an attribute %
	       %only (VDRD.6).")
	    else
	       ct := rc.current_type
	       rt1 := super.result_type.to_runnable(ct)
	       rt2 := redef.result_type.to_runnable(ct)
	       if rt1.is_reference then
		  if rt2.is_reference then
		  elseif writable_attribute.is_item_of_integer then
		     -- The rule is relaxed for INTEGER_*.item definition.
		  else
		     fatal_error_vdrd6(super,redef,vdrd6_types)
		  end
	       elseif rt2.is_reference then
		  fatal_error_vdrd6(super,redef,vdrd6_types)
	       end
	    end
	 end
      end

   vdrd6_types: STRING is "Result types must be both expanded or %
   %both non-expanded (VDRD.6)."

   fatal_error_vdrd6(super, redef: E_FEATURE; msg: STRING) is
      do
	 error_handler.add_position(super.start_position)
	 error_handler.add_position(redef.start_position)
	 error_handler.append("Bad redefinition. ")
	 error_handler.append(msg)
	 error_handler.print_as_fatal_error
      end

   default_rescue_sfn: FEATURE_NAME is
      once
	 !!Result.unknown_position(as_default_rescue)
      end

   copy_sfn: FEATURE_NAME is
      once
	 !!Result.unknown_position(as_copy)
      end

invariant

   name /= Void

   hash_code = name.to_string.hash_code

end -- BASE_CLASS
