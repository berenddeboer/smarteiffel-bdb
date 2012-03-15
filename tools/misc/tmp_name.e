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
expanded class TMP_NAME
   --
   -- Singleton object used by `eiffel_parser' and `ace' to have a temporary
   -- storage of some unknown name during syntax analysis.
   --

inherit
   GLOBALS
   VISITABLE

feature {TMP_NAME_VISITOR}

   accept(visitor: TMP_NAME_VISITOR) is
      do
         visitor.visit_tmp_name(Current)
      end

feature {PARSER, CREATE_TOOLS} 
   -- Hack: we need to create a fake name at creation sites,
   -- to build HASHED_DICTIONARYs instead of DICTIONARYs

   to_class_name: CLASS_NAME is
      do
         !!Result.make(aliased_string,start_position)
      end

   reset(sp: like start_position) is
      do
         start_position := sp
         buffer.clear_count
         aliased_string_memory := Void
      end

   append(s: STRING) is
      do
         buffer.append(s)
      end

feature {PARSER}

   buffer: STRING is "                                                 "

   start_position: POSITION

   line: INTEGER is
      do
         Result := start_position.line
      end

   column: INTEGER is
      do
         Result := start_position.column
      end

   extend(ch: CHARACTER) is
      do
         buffer.extend(ch)
      end

   is_current: BOOLEAN is
      do
         if buffer.count = 7 then
            Result := as_current.same_as(buffer)
         end
      end

   is_result: BOOLEAN is
      do
         if buffer.count = 6 then
            Result := as_result.same_as(buffer)
         end
      end

   is_void: BOOLEAN is
      do
         if buffer.count = 4 then
            Result := as_void.same_as(buffer)
         end
      end

   aliased_string: STRING is
      do
         if aliased_string_memory = Void then
            aliased_string_memory := string_aliaser.item(buffer)
         end
         Result := aliased_string_memory
      end

   isa_keyword: BOOLEAN is
      local
         c: CHARACTER
      do
         c := buffer.first.to_lower
         inspect
            c
         when 'a' then
            if fz_alias.same_as(buffer) then
               Result := True
            elseif fz_all.same_as(buffer) then
               Result := True
            elseif as_and.same_as(buffer) then
               Result := True
            elseif as_agent.same_as(buffer) then
	       new_keyword_warning
               Result := True
            else
               Result := fz_as.same_as(buffer)
            end
         when 'c' then
            if fz_check.same_as(buffer) then
               Result := True
            elseif fz_class.same_as(buffer) then
               Result := True
	    elseif fz_create.same_as(buffer) then
               Result := True
            else
               Result := fz_creation.same_as(buffer)
            end
         when 'd' then
            if fz_debug.same_as(buffer) then
               Result := True
            elseif fz_deferred.same_as(buffer) then
               Result := True
            else
               Result := fz_do.same_as(buffer)
            end
         when 'e' then
            if fz_else.same_as(buffer) then
               Result := True
            elseif fz_elseif.same_as(buffer) then
               Result := True
            elseif fz_end.same_as(buffer) then
               Result := True
            elseif fz_ensure.same_as(buffer) then
               Result := True
            elseif fz_expanded.same_as(buffer) then
               Result := True
            elseif fz_export.same_as(buffer) then
               Result := True
            else
               Result := fz_external.same_as(buffer)
            end
         when 'f' then
            if fz_false.same_as(buffer) then
               Result := True
            elseif fz_feature.same_as(buffer) then
               Result := True
            elseif fz_from.same_as(buffer) then
               Result := True
            else
               Result := fz_frozen.same_as(buffer)
            end
         when 'i' then
            if fz_if.same_as(buffer) then
               Result := True
            elseif as_implies.same_as(buffer) then
               Result := True
            elseif fz_indexing.same_as(buffer) then
               Result := True
            elseif fz_infix.same_as(buffer) then
               Result := True
            elseif fz_inherit.same_as(buffer) then
               Result := True
            elseif fz_inspect.same_as(buffer) then
               Result := True
            elseif fz_invariant.same_as(buffer) then
               Result := True
            else
               Result := fz_is.same_as(buffer)
            end
         when 'l' then
            if fz_like.same_as(buffer) then
               Result := True
            elseif fz_local.same_as(buffer) then
               Result := True
            else
               Result := fz_loop.same_as(buffer)
            end
         when 'o' then
            if fz_obsolete.same_as(buffer) then
               Result := True
            elseif fz_old.same_as(buffer) then
               Result := True
            elseif fz_once.same_as(buffer) then
               Result := True
            else
               Result := as_or.same_as(buffer)
            end
         when 'p' then
            if as_precursor.same_as(buffer) then
               Result := True
            else
               Result := fz_prefix.same_as(buffer)
            end
         when 'r' then
            if fz_redefine.same_as(buffer) then
               Result := True
            elseif fz_rename.same_as(buffer) then
               Result := True
            elseif fz_require.same_as(buffer) then
               Result := True
            elseif fz_rescue.same_as(buffer) then
               Result := True
            else
               Result := fz_retry.same_as(buffer)
            end
         when 's' then
            if fz_select.same_as(buffer) then
               Result := True
            elseif fz_separate.same_as(buffer) then
               Result := True
            else
               Result := fz_strip.same_as(buffer)
            end
         when 't' then
            if fz_then.same_as(buffer) then
               Result := True
            else
               Result := fz_true.same_as(buffer)
            end
         when 'u' then
            if fz_undefine.same_as(buffer) then
               Result := True
            elseif fz_unique.same_as(buffer) then
               Result := True
            else
               Result := fz_until.same_as(buffer)
            end
         when 'v' then
            Result := fz_variant.same_as(buffer)
         when 'w' then
            Result := fz_when.same_as(buffer)
         when 'x' then
            Result := as_xor.same_as(buffer)
         else
         end
      end

   to_argument_name1: ARGUMENT_NAME1 is
      do
         !!Result.make(start_position,aliased_string)
      end

   to_argument_name2(fal: FORMAL_ARG_LIST; rank: INTEGER): ARGUMENT_NAME2 is
      do
         !!Result.refer_to(start_position,fal,rank)
      end

   to_e_void: E_VOID is
      require
         is_void
      do
         !!Result.make(start_position)
      end

   to_simple_feature_name: FEATURE_NAME is
      do
         create Result.simple_feature_name(aliased_string,start_position)
      end

   to_local_name1: LOCAL_NAME1 is
      do
         !!Result.make(start_position,aliased_string)
      end

   to_local_name2(lvl: LOCAL_VAR_LIST; rank: INTEGER): LOCAL_NAME2 is
      do
         !!Result.refer_to(start_position,lvl,rank)
      end

   to_tag_name: TAG_NAME is
      do
         !!Result.make(aliased_string,start_position)
      end

feature {INI_PARSER}

   case_sensitive_aliased_string: STRING is
      do
         if aliased_string_memory = Void then
            aliased_string_memory := string_aliaser.item(buffer)
         end
         Result := aliased_string_memory
      end

feature {NONE}

   new_keyword_warning is
      do
	 error_handler.extend('%"')
	 error_handler.append(buffer)
	 error_handler.append("%" is now a keyword in the new Eiffel definition. %
		    %You must use another name (sorry).")
	 error_handler.add_position(start_position)
	 error_handler.print_as_warning
      end

   aliased_string_memory: STRING

end -- TMP_NAME
