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
class SHORT_PRINT
   --
   -- Driver for the `short' command.
   --

inherit GLOBALS; VISITABLE

creation make

feature

   out_stream: OUTPUT_STREAM

   set_out_stream(a_out_stream: like out_stream) is
      require
         a_out_stream /= Void
      do
         out_stream := a_out_stream
      end

   hook_or(h, str: STRING) is
      do
         if hook_exists(h) then
            from
               tmp_hook.read_character
            until
               tmp_hook.end_of_input
            loop
               out_stream.put_character(tmp_hook.last_character)
               tmp_hook.read_character
            end
            tmp_hook.disconnect
         else
            out_stream.put_string(str)
         end
      end

   hook_and_lower(h, name: STRING) is
         -- When hook `h' exists, the corresponding `name' is printed
         -- one more time (using lower case letters) just before the
         -- contents of `h' hook file.
      do
         if hook_exists(h) then
            tmp_string.copy(name)
            tmp_string.to_lower
            out_stream.put_string(tmp_string)
            from
               tmp_hook.read_character
            until
               tmp_hook.end_of_input
            loop
               out_stream.put_character(tmp_hook.last_character)
               tmp_hook.read_character
            end
            tmp_hook.disconnect
         end
      end

   hook_and(h, name: STRING) is
         -- When hook `h' exists, the corresponding `name' is printed
         -- just before the contents of `h' hook file.
      do
         if hook_exists(h) then
            out_stream.put_string(name)
            from
               tmp_hook.read_character
            until
               tmp_hook.end_of_input
            loop
               out_stream.put_character(tmp_hook.last_character)
               tmp_hook.read_character
            end
            tmp_hook.disconnect
         end
      end

   hook(h: STRING) is
      do
         if hook_exists(h) then
            from
               tmp_hook.read_character
            until
               tmp_hook.end_of_input
            loop
               out_stream.put_character(tmp_hook.last_character)
               tmp_hook.read_character
            end
            tmp_hook.disconnect
         end
      end

   a_class_name(name: CLASS_NAME) is
      local
         i: INTEGER; c: CHARACTER; str: STRING
      do
         hook(once "Bcn")
         hook_and_lower(once "Mcn",name.to_string)
         from
            str := name.to_string
            i := 1
         until
            i > str.count
         loop
            c := str.item(i)
            if c = '_' then
               hook_or(once "Ucn","_")
            else
               out_stream.put_character(c)
            end
            i := i + 1
         end
         hook(once "Acn")
      end

   a_integer(value: INTEGER_64) is
      local
         s: STRING; c: CHARACTER; i: INTEGER
      do
         s := once ""
         s.clear
         value.append_in(s)
         from
            i := 1
         until
            i > s.count
         loop
            c := s.item(i)
            out_stream.put_character(c)
            i := i + 1
         end
      end

   a_character(c: CHARACTER) is
      do
         out_stream.put_character(c)
      end

   a_dot is
      do
         hook_or(once "dot", once ".")
      end

feature {FEATURE_NAME_LIST}

   a_feature(fn: FEATURE_NAME) is
         -- Where `fn' is really the final name to print.
      local
         rf: RUN_FEATURE
      do
         rf := run_class.get_feature(fn)
	 if rf = Void then
	    error_handler.add_position(fn.start_position)
	    error_handler.append("Feature not found (error while running %
				 %short).")
	    error_handler.print_as_fatal_error
	 end
	 a_run_feature(rf)
      end

feature {SHORT_LIST}

   a_run_feature(rf: RUN_FEATURE) is
      require
	 rf /= Void
      local
         args: FORMAL_ARG_LIST; rt: E_TYPE; hc: COMMENT
         rr: RUN_REQUIRE; ea: E_ENSURE
      do
         hook_or(once "hook300", once"   ")
         rf.name.short
         args := rf.arguments
         if args = Void then
            hook_or(once "hook301", once "")
         else
            args.short
         end
         rt := rf.result_type
         if rt = Void then
            hook_or(once "hook307", once "%N")
         else
            hook_or(once "hook308", once ": ")
            rt.short
            hook_or(once "hook309", once "%N")
         end
         hc := rf.base_feature.header_comment
         if hc /= Void then
            hook(once "hook310")
            hc.short(once "hook311", once "      --", once "hook312", once "%N")
            hook(once "hook313")
         else
            hook(once "hook314")
         end
         rr := rf.require_assertion
         if rr = Void then
            hook(once "hook400")
         else
            rr.short
         end
         ea := rf.ensure_assertion
         if ea = Void then
            hook_or(once "hook500", once "")
         else
            ea.short
         end
         hook_or(once "hook599", once "")
      end

feature {FORMAL_GENERIC_ARG, E_TYPE}

   a_magic_class_name(name: CLASS_NAME) is
	 -- Used when the class `name' has no corresponding source file.
      local
         i: INTEGER; c: CHARACTER; str: STRING
      do
         hook(once "Bfga")
         hook_and_lower(once "Mfga",name.to_string)
         from
            str := name.to_string
            i := 1
         until
            i > str.count
         loop
            c := str.item(i)
            if c = '_' then
               hook_or(once "Ufga", once "_")
            else
               out_stream.put_character(c)
            end
            i := i + 1
         end
         hook(once "Afga")
      end

feature {CLASS_CHECKER}

   start(format: STRING; bc: BASE_CLASS; rc: RUN_CLASS) is
      local
         hc2: COMMENT; fgl: FORMAL_GENERIC_LIST
      do
         base_class := bc
         run_class := rc
         format_directory := system_tools.format_directory(format)
         -- Start output :
         hook(once "hook000")
         hook_and(once "hook002",bc.name.to_string)
         if bc.is_expanded then
            hook_or(once "hook010", once "expanded class interface ")
         elseif bc.is_deferred then
            hook_or(once "hook011", once "deferred class interface ")
         else
            hook_or(once "hook012", once "class interface ")
         end
         hook(once "hook013")
         a_class_name(bc.name)
         fgl := bc.formal_generic_list
         if fgl /= Void then
            fgl.short
         end
         hook_or(once "hook014", once "%N")
         hc2 := bc.heading_comment2
         if hc2 /= Void then
            hook(once "hook015")
            hc2.short(once "hook016", once "   --", once "hook017", once "%N")
            hook(once "hook018")
         else
            hook(once "hook019")
         end
      end

   finish(obsolete_flag: BOOLEAN) is
      -- The `obsolete_flag' indicates that the class to short itself
      -- is obsolete.
      local
         fgl: FORMAL_GENERIC_LIST; ci: CLASS_INVARIANT
      do
	 if not obsolete_flag then
	    ci := run_class.class_invariant
	 end
         if ci = Void then
            hook(once "hook800")
         else
            ci.short(base_class)
         end
         hook(once "hook900")
         if base_class.is_expanded then
            hook_or(once "hook901", once "end of expanded ")
         elseif base_class.is_deferred then
            hook_or(once "hook902", once "end of deferred ")
         else
            hook_or(once "hook903", once "end of ")
         end
         hook(once "hook904")
         a_class_name(base_class.name)
         fgl := base_class.formal_generic_list
         if fgl /= Void then
            fgl.short
         end
         hook_or(once "hook905", once "%N")
         hook(once "hook999")
      end

feature {CALL_PREFIX}

   a_prefix_name(pn: FEATURE_NAME) is
         -- Used in an expression.
      require
	 pn.is_prefix_name
      local
         i: INTEGER; c: CHARACTER; str: STRING
      do
         from
            str := pn.to_string
            i := 1
         until
            i > str.count
         loop
            c := str.item(i)
            if c = '_' then
               hook_or(once "Usfn", once "_")
            else
               out_stream.put_character(c)
            end
            i := i + 1
         end
         a_character(' ')
      end

feature {CALL_INFIX,FEATURE_NAME}

   a_infix_name(h1,r1,h2,r2: STRING; in: FEATURE_NAME) is
      require
	 in.is_infix_name
      local
         i: INTEGER; str: STRING
      do
         hook_or(h1,r1)
         str := in.to_string
         if as_backslash_backslash = str then
            hook_or(once "rem",as_backslash_backslash)
         else
            from
               i := 1
            until
               i > str.count
            loop
               out_stream.put_character(str.item(i))
               i := i + 1
            end
         end
         hook_or(h2,r2)
      end

feature {BASE_TYPE_CONSTANT}

   a_base_type_constant(str: STRING) is
      local
         i: INTEGER; c: CHARACTER
      do
         from
            i := 1
         until
            i > str.count
         loop
            c := str.item(i)
            if c = '.' then
               hook_or(once "dot", once ".")
            else
               out_stream.put_character(c)
            end
            i := i + 1
         end
      end

feature {SHORT_PRINT_VISITOR}

   accept(visitor: SHORT_PRINT_VISITOR) is
      do
         visitor.visit_short_print(Current)
      end

feature {NONE}

   format_directory: STRING
         -- For the output style.

   base_class: BASE_CLASS
         -- The one printed.

   run_class: RUN_CLASS
         -- The one printed.

   make is
      do
      end

   hook_exists(h: STRING): BOOLEAN is
      do
         tmp_hook_path.copy(format_directory)
         tmp_hook_path.append(h)
         tmp_hook.connect_to(tmp_hook_path)
         Result := tmp_hook.is_connected
      end

   tmp_hook: TEXT_FILE_READ is
      once
         !!Result.make
      end

   tmp_hook_path: STRING is
      once
         !!Result.make(80)
      end

   tmp_string: STRING is
      once
         !!Result.make(16)
      end

end -- SHORT_PRINT

