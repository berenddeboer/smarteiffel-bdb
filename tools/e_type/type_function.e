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
class TYPE_FUNCTION
   --
   -- For agents of type FUNCTION as well as agents of type PREDICATE.
   --

inherit TYPE_OF_AGENT

creation make

creation {TYPE_FUNCTION} set

feature

   is_type_predicate: BOOLEAN is
      do
	 Result := res.is_boolean
      end

   to_runnable_(ct: E_TYPE): like Current is
      local
	 b: like base; so: like static_open; r:like res
      do
	 b := base.to_runnable(ct)
	 so := static_open.to_runnable(ct)
	 r := res.to_runnable(ct)
	 if b = base and then so = static_open and then r = res then
	    if run_type = Void then
	       create run_type.make(start_position,
				    b.run_type, so.run_type, r.run_type)
	       check run_type.written_runnable_flag end
	       set_open_using(so)
	       Result := Current
	    else
	       Result := Current
	    end
	 elseif run_type = Void then
	    create run_type.make(start_position, 
				 b.run_type, so.run_type, r.run_type)
	    check run_type.written_runnable_flag end
	    base := b
	    static_open := so
	    res := r
	    set_open_using(so)
	    Result := Current
	 else
	    create Result.make(start_position,
			       b.run_type, so.run_type, r.run_type)
	    check Result.written_runnable_flag end
	    if Result.written_mark = run_type.written_mark then
	       Result := Current
	    else
	       create Result.set(Current, so, Result)
	    end
	 end
      end

   written_mark: STRING is
      local
	 base_wm, static_open_wm, res_wm: STRING; predicate: BOOLEAN
      do
	 Result := written_mark_memory
	 if Result = Void then
	    predicate := is_type_predicate
	    -- To force computation of components first:
	    base_wm := base.written_mark
	    static_open_wm := static_open.written_mark
	    if not predicate then
	       res_wm := res.written_mark
	    end
	    -- Then compute the `Result':
	    Result := once "...This is a local once buffer..."
	    if predicate then
	       Result.copy(as_predicate)
	    else
	       Result.copy(as_function)
	    end
	    Result.extend('[')
	    Result.append(base_wm)
	    Result.extend(',')
	    Result.append(static_open_wm)
	    if not predicate then
	       Result.extend(',')
	       Result.append(res_wm)
	    end
	    Result.extend(']')
	    Result := string_aliaser.item(Result)
	    written_mark_memory := Result
	 end
      end

feature {E_TYPE}

   short_hook is
      local
	 predicate : BOOLEAN; bcn: like base_class_name
      do
	 predicate := is_type_predicate
	 bcn := base_class_name
	 if predicate then
	    create bcn.make(as_predicate,bcn.start_position)
	 end
	 short_print.a_magic_class_name(bcn)
         short_print.hook_or("open_sb","[")
	 base.short_hook
	 short_print.hook_or("tm_sep",",")
	 open.short_hook
	 if not predicate then
	    short_print.hook_or("tm_sep",",")
	    res.short_hook
	 end
         short_print.hook_or("close_sb","]")
      end

feature {E_AGENT, RUN_CLASS, TYPE_OF_AGENT}

   load_builtin_features is
      do
	 base_class.load_feature_call(run_type)
	 base_class.load_feature_item(run_type, res.run_type)
      end
   
feature {TYPE_FUNCTION_VISITOR}

   accept(visitor: TYPE_FUNCTION_VISITOR) is
      do
         visitor.visit_type_function(Current)
      end

feature {NONE}

   make(sp: like start_position; b: like base; so: like static_open;
	r: like res) is
      require
	 not sp.is_unknown
	 b /= Void
	 so /= Void
      do
	 start_position := sp
	 base := b
	 static_open := so
	 open ?= so
	 if r /= Void then
	    res := r
	 else
	    create {TYPE_BOOLEAN} res.make(sp)
	 end
	 create base_class_name.make(as_function, sp)
	 -- Compute `written_runnable_flag':
	 if b.is_run_type and then b.run_type = b then
	    if res.is_run_type and then res.run_type = res then
	       if so.is_run_type and then so.run_type = so then
		  written_runnable_flag := True
		  run_type := Current
	       end
	    end
	 end
      ensure
	 start_position = sp
	 base = b
	 static_open = so
	 res = r or else res.is_boolean
      end

   set(model: like Current; so: like static_open; rt: like run_type) is
      require
	 not model.written_runnable_flag
	 model.run_type /= Void
	 rt.written_runnable_flag
      do
	 start_position := model.start_position
	 base := model.base
	 static_open := so
	 res := model.res
	 base_class_name := model.base_class_name
	 run_type := rt
	 set_open_using(so)
      ensure
	 start_position = model.start_position
	 base = model.base
	 static_open = so
	 open = so.run_type
	 res = model.res
	 base_class_name = model.base_class_name
	 run_type = rt
      end
   
   is_a_(other: TYPE_OF_AGENT): BOOLEAN is
      do
	 if base.is_a(other.base) then
	    if other.open.is_a(open) then
	       if other.res /= Void then
		  Result := res.is_a(other.res)
	       else
		  Result := True
	       end
	    end
	 end
      end

invariant

   res /= Void

end -- TYPE_FUNCTION
