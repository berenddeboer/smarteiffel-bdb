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
class C_MODE
      --
      -- Used by the new-generation installer.
      --
inherit
   INSTALL_GLOBALS
   VISITABLE

creation
   {INSTALL} make

feature {C_MODE_VISITOR}

   accept(visitor: C_MODE_VISITOR) is
      do
         visitor.visit_c_mode(Current)
      end

feature {INSTALL}

   c_file:               INI_PARSER
   cpp_file:             INI_PARSER
   name:                 STRING
   c_compiler_type:      STRING
   c_compiler_path:      STRING
   c_compiler_options:   STRING
   c_linker_path:        STRING
   c_linker_options:     STRING
   cpp_compiler_type:    STRING
   cpp_compiler_path:    STRING
   cpp_compiler_options: STRING
   cpp_linker_path:      STRING
   cpp_linker_options:   STRING
   smarteiffel_options:  STRING

   could_read_template:  BOOLEAN
         -- True if a template was used by the last `set_c_compiler_type'
         -- call.

   reset(a_name: like name;
         a_c_file: like ini_parser; a_c_compiler_type: like c_compiler_type
         a_cpp_file: like ini_parser; a_cpp_compiler_type: like cpp_compiler_type) is
      require
         name_not_void:      a_name /= Void

         compiler_exists:    a_c_compiler_type /= Void

         good_c_file:        a_c_file /= Void
                             implies a_c_compiler_type.is_equal(a_c_file.item(fz_conf_compiler_type))

         good_cpp_file:      a_cpp_file /= Void
                             implies (a_cpp_compiler_type /= Void
                                      and then a_cpp_compiler_type.is_equal(a_cpp_file.item(fz_conf_cpp_compiler_type)))

         known_c_compiler:   a_c_compiler_type /= fz_conf_undefined
                             implies system_tools.compiler_list.has(a_c_compiler_type)

         known_cpp_compiler: a_cpp_compiler_type /= fz_conf_undefined
                             implies system_tools.c_plus_plus_compiler_list.has(a_cpp_compiler_type)
      do
         name.copy(a_name)
         c_file := a_c_file
         if a_c_compiler_type /= fz_conf_undefined then
            c_compiler_type := system_tools.compiler_list.item(system_tools.compiler_list.index_of(a_c_compiler_type))
         end
         cpp_file := a_cpp_file
         if a_cpp_compiler_type /= fz_conf_undefined then
            cpp_compiler_type := system_tools.c_plus_plus_compiler_list.item(system_tools.c_plus_plus_compiler_list.index_of(a_cpp_compiler_type))
         end
         read_template
      end

   set_c_compiler_path(ccp: STRING) is
      do
         if ccp = Void then
            c_compiler_path := Void
         else
            buf_c_compiler_path.copy(ccp)
            c_compiler_path := buf_c_compiler_path
         end
      ensure
         ccp = Void implies c_compiler_path = Void
         ccp /= Void implies c_compiler_path.is_equal(ccp)
      end

   set_c_compiler_options(cco: STRING) is
      do
         if cco = Void then
            c_compiler_options := Void
         else
            buf_c_compiler_options.copy(cco)
            c_compiler_options := buf_c_compiler_options
         end
         if c_same then
            if cco = Void then
               c_linker_options := Void
            else
               buf_c_linker_options.copy(cco)
               c_linker_options := buf_c_linker_options
            end
         end
      ensure
         cco = Void implies c_compiler_options = Void
         cco /= Void implies c_compiler_options.is_equal(cco)
      end

   set_c_linker_path(clp: STRING) is
      do
         if clp = Void then
            c_linker_path := Void
         else
            buf_c_linker_path.copy(clp)
            c_linker_path := buf_c_linker_path
         end
      ensure
         clp = Void implies c_linker_path = Void
         clp /= Void implies c_linker_path.is_equal(clp)
      end

   set_c_linker_options(clo: STRING) is
      do
         if clo = Void then
            c_linker_options := Void
         else
            buf_c_linker_options.copy(clo)
            c_linker_options := buf_c_linker_options
         end
         c_same := False
      ensure
         clo = Void implies c_linker_options = Void
         clo /= Void implies c_linker_options.is_equal(clo)
      end

   set_cpp_compiler_path(ccp: STRING) is
      do
         if ccp = Void then
            cpp_compiler_path := Void
         else
            buf_cpp_compiler_path.copy(ccp)
            cpp_compiler_path := buf_cpp_compiler_path
         end
      ensure
         ccp = Void implies cpp_compiler_path = Void
         ccp /= Void implies cpp_compiler_path.is_equal(ccp)
      end

   set_cpp_compiler_options(cco: STRING) is
      do
         if cco = Void then
            cpp_compiler_options := Void
         else
            buf_cpp_compiler_options.copy(cco)
            cpp_compiler_options := buf_cpp_compiler_options
         end
         if cpp_same then
            if cco = Void then
               cpp_linker_options := Void
            else
               buf_cpp_linker_options.copy(cco)
               cpp_linker_options := buf_cpp_linker_options
            end
         end
      ensure
         cco = Void implies cpp_compiler_options = Void
         cco /= Void implies cpp_compiler_options.is_equal(cco)
      end

   set_cpp_linker_path(clp: STRING) is
      do
         if clp = Void then
            cpp_linker_path := Void
         else
            buf_cpp_linker_path.copy(clp)
            cpp_linker_path := buf_cpp_linker_path
         end
      ensure
         clp = Void implies cpp_linker_path = Void
         clp /= Void implies cpp_linker_path.is_equal(clp)
      end

   set_cpp_linker_options(clo: STRING) is
      do
         if clo = Void then
            cpp_linker_options := Void
         else
            buf_cpp_linker_options.copy(clo)
            cpp_linker_options := buf_cpp_linker_options
         end
         cpp_same := False
      ensure
         clo = Void implies cpp_linker_options = Void
         clo /= Void implies cpp_linker_options.is_equal(clo)
      end

   set_smarteiffel_options(so: STRING) is
      do
         if so = Void then
            smarteiffel_options := Void
         else
            buf_smarteiffel_options.copy(so)
            smarteiffel_options := buf_smarteiffel_options
         end
      ensure
         so = Void implies smarteiffel_options = Void
         so /= Void implies smarteiffel_options.is_equal(so)
      end

feature {NONE}

   make(a_name: like name;
        a_c_file: like c_file; a_c_compiler_type: like c_compiler_type
        a_cpp_file: like cpp_file; a_cpp_compiler_type: like cpp_compiler_type) is
      require
         name_not_void:      a_name /= Void

         compiler_exists:    a_c_compiler_type /= Void

         good_c_file:        a_c_file /= Void
                             implies a_c_compiler_type.is_equal(a_c_file.item(fz_conf_compiler_type))

         good_cpp_file:      a_cpp_file /= Void
                             implies (a_cpp_compiler_type /= Void
                                      and then a_cpp_compiler_type.is_equal(a_cpp_file.item(fz_conf_cpp_compiler_type)))

         known_c_compiler:   a_c_compiler_type /= fz_conf_undefined
                             implies system_tools.compiler_list.has(a_c_compiler_type)

         known_cpp_compiler: a_cpp_compiler_type /= fz_conf_undefined
                             implies system_tools.c_plus_plus_compiler_list.has(a_cpp_compiler_type)
      do
         -- Create buffers:
         create name.make(8)
         create buf_c_compiler_path.make(16)
         create buf_c_compiler_options.make(16)
         create buf_c_linker_path.make(16)
         create buf_c_linker_options.make(16)
         create buf_cpp_compiler_path.make(16)
         create buf_cpp_compiler_options.make(16)
         create buf_cpp_linker_path.make(16)
         create buf_cpp_linker_options.make(16)
         create buf_smarteiffel_options.make(16)

         reset(a_name, a_c_file, a_c_compiler_type, a_cpp_file, a_cpp_compiler_type)
      end

   read_template is
         -- Reads the template into the keys of this C mode.
      local
         tmp: STRING
         rc: INI_PARSER
      do
         set_c_compiler_path(Void)
         set_c_compiler_options(Void)
         set_c_linker_path(Void)
         set_c_linker_options(Void)
         set_cpp_compiler_path(Void)
         set_cpp_compiler_options(Void)
         set_cpp_linker_path(Void)
         set_cpp_linker_options(Void)
         set_smarteiffel_options(Void)
         c_same := False
         cpp_same := False

         could_read_template := False
         rc := c_file
         if rc /= Void then
            could_read_template := rc.has(fz_conf_compiler_type)
               and then rc.item(fz_conf_compiler_type).is_equal(c_compiler_type)
            if could_read_template then

               if rc.section_has(name, fz_conf_compiler_path) then
                  tmp := rc.section_item(name, fz_conf_compiler_path)
                  set_c_compiler_path(tmp)
               end
               if rc.section_has(name, fz_conf_compiler_options) then
                  tmp := rc.section_item(name, fz_conf_compiler_options)
                  set_c_compiler_options(tmp)
               end
               if rc.section_has(name, fz_conf_linker_path) then
                  tmp := rc.section_item(name, fz_conf_linker_path)
                  set_c_linker_path(tmp)
               end
               if rc.section_has(name, fz_conf_linker_options) then
                  tmp := rc.section_item(name, fz_conf_linker_options)
                  set_c_linker_options(tmp)
               end
               if rc.section_has(name, fz_conf_smarteiffel_options) then
                  tmp := rc.section_item(name, fz_conf_smarteiffel_options)
                  set_smarteiffel_options(tmp)
               end

               c_same := c_compiler_options = c_linker_options
               if not c_same and then c_compiler_options /= Void and then c_linker_options /= Void then
                  c_same := c_compiler_options.is_equal(c_linker_options)
               end
            end
         end

         rc := cpp_file
         if rc /= Void then
            could_read_template := could_read_template
               and then rc.has(fz_conf_cpp_compiler_type)
               and then (rc.item(fz_conf_cpp_compiler_type).is_equal(cpp_compiler_type)
                         or else rc.item(fz_conf_compiler_type).is_equal(cpp_compiler_type))
            if could_read_template then
               cpp_compiler_type := system_tools.c_plus_plus_compiler_list.item(system_tools.c_plus_plus_compiler_list.index_of(rc.item(fz_conf_cpp_compiler_type)));

               if rc.section_has(name, fz_conf_cpp_compiler_path) then
                  tmp := rc.section_item(name, fz_conf_cpp_compiler_path)
                  set_cpp_compiler_path(tmp)
               end
               if rc.section_has(name, fz_conf_cpp_compiler_options) then
                  tmp := rc.section_item(name, fz_conf_cpp_compiler_options)
                  set_cpp_compiler_options(tmp)
               end
               if rc.section_has(name, fz_conf_cpp_linker_path) then
                  tmp := rc.section_item(name, fz_conf_cpp_linker_path)
                  set_cpp_linker_path(tmp)
               end
               if rc.section_has(name, fz_conf_cpp_linker_options) then
                  tmp := rc.section_item(name, fz_conf_cpp_linker_options)
                  set_cpp_linker_options(tmp)
               end

               cpp_same := cpp_compiler_options = cpp_linker_options
               if not cpp_same and then cpp_compiler_options /= Void and then cpp_linker_options /= Void then
                  cpp_same := cpp_compiler_options.is_equal(cpp_linker_options)
               end
            end
         end
      end

   buf_c_compiler_path: STRING
   buf_c_compiler_options: STRING
   buf_c_linker_path: STRING
   buf_c_linker_options: STRING
   buf_cpp_compiler_path: STRING
   buf_cpp_compiler_options: STRING
   buf_cpp_linker_path: STRING
   buf_cpp_linker_options: STRING
   buf_smarteiffel_options: STRING

   c_same: BOOLEAN
   cpp_same: BOOLEAN

invariant

   name /= Void
   c_compiler_type /= Void
   cpp_file /= Void implies cpp_compiler_type /= Void

end
