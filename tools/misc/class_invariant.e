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
class CLASS_INVARIANT
   --
   -- To store a `class invariant'.
   --

inherit
   ASSERTION_LIST
      redefine
         pretty_print
      end

creation make, make_runnable

feature

   is_require: BOOLEAN is False

   name: STRING is
      do
         Result := fz_invariant
      end

   pretty_print is
      local
         i: INTEGER
      do
         if not pretty_printer.zen_mode then
            pretty_printer.skip_one_line
         end
	 pretty_printer.set_indent_level(0)
	 pretty_printer.indent
         pretty_printer.keyword(name)
         if header_comment /= Void then
	    pretty_printer.set_indent_level(1)
	    pretty_printer.indent
            header_comment.pretty_print
         end
         if list /= Void then
            from
               i := list.lower
            until
               i > list.upper
            loop
               if not pretty_printer.zen_mode then
                  pretty_printer.skip_one_line
               end
               pretty_printer.set_semi_colon_flag(True)
               pretty_printer.set_indent_level(1)
               pretty_printer.indent
               list.item(i).pretty_print
               i := i + 1
            end
         end
	 pretty_printer.set_indent_level(0)
	 pretty_printer.indent
      end

   short(bc: BASE_CLASS) is
      local
         i: INTEGER
      do
         bc.header_comment_for(Current)
         short_print.hook_or(once "hook811",once "invariant%N")
         if header_comment = Void then
            short_print.hook_or(once "hook812",once "")
         else
            short_print.hook_or(once "hook813",once "")
            header_comment.short(once "hook814",once "   --",once "hook815",once "%N")
            short_print.hook_or(once "hook816",once "")
         end
         if list = Void then
            short_print.hook_or(once "hook817",once "")
         else
            short_print.hook_or(once "hook818",once "")
            from
               i := 0
            until
               i = list.upper
            loop
               list.item(i).short(once "hook819",once "   ", -- before each assertion
                                  once "hook820",once "", -- no tag
                                  once "hook821",once "", -- before tag
                                  once "hook822",once ": ", -- after tag
                                  once "hook823",once "", -- no expression
                                  once "hook824",once "", -- before expression
                                  once "hook825",once ";", -- after expression except last
                                  once "hook826",once "%N", -- no comment
                                  once "hook827",once "", -- before comment
                                  once "hook828",once " --", -- comment begin line
                                  once "hook829",once "%N", -- comment end of line
                                  once "hook830",once "", -- after comment
                                  once "hook831",once ""); -- end of each assertion

               i := i + 1
            end
            list.item(i).short(once "hook819",once "   ", -- before each assertion
                               once "hook820",once "", -- no tag
                               once "hook821",once "", -- before tag
                               once "hook822",once ": ", -- after tag
                               once "hook823",once "", -- no expression
                               once "hook824",once "", -- before expression
                               once "hook832",once ";", -- after last expression
                               once "hook826",once "%N", -- no comment
                               once "hook827",once "", -- before comment
                               once "hook828",once " --", -- comment begin line
                               once "hook829",once "%N", -- comment end of line
                               once "hook830",once "", -- after comment
                               once "hook831",once "")
            short_print.hook_or(once "hook833",once "")
         end
         short_print.hook_or(once "hook834",once "")
      end

feature {NONE}

   check_assertion_mode: STRING is
      do
         Result := once "inv"
      end

feature {RUN_CLASS}

   c_define is
         -- Define C function to check invariant.
      require
         current_type /= Void
         run_class.at_run_time
         smart_eiffel.is_ready
         cpp.on_c
      local
         id: INTEGER
      do
         id := current_type.id
         -- The invariant frame descriptor :
         c_code.copy(once "se_frame_descriptor se_ifd")
         id.append_in(c_code)
         cpp.put_extern7(c_code)
         c_code.copy(once "{%"invariant ")
         c_code.append(current_type.run_time_mark)
         c_code.append(once "%",1,0,%"")
         current_type.c_frame_descriptor_in(c_code)
         c_code.append(once "%",1};%N")
         cpp.put_string(c_code)
         -- The function :
         c_code.clear_count
         c_code.extend('T')
         id.append_in(c_code)
         c_code.extend('*')
         c_code.append(fz_se_i)
         id.append_in(c_code)
         c_code.append(once "(se_dump_stack*caller,T")
         id.append_in(c_code)
         c_code.append(once "*C)")
         cpp.put_c_heading(c_code)
         cpp.swap_on_c
         c_code.copy(once "se_dump_stack ds;%N")
         if smart_eiffel.scoop then
            cpp.put_string(once "se_subsystem_t* self=se_current_subsystem_thread();%N")
         end
         c_code.append(once "ds.fd=&se_ifd")
         id.append_in(c_code)
         c_code.append(once ";%Nds.current=((void**)&C);%N")
         cpp.put_string(c_code)
         cpp.put_position_in_ds(start_position)
         cpp.put_string(once "ds.caller=caller;%Nds.exception_origin=NULL;%Nds.locals=NULL;%N")
         if smart_eiffel.scoop then
            cpp.put_string(once "(void)(self->vft.get_dst_and_lock(self));%N%
                                %self->vft.set_dst_and_unlock(self,&ds);/*link*/%N")
         else
            cpp.put_string(once "se_dst=&ds;/*link*/%N")
         end
         compile_to_c
         if smart_eiffel.scoop then
            cpp.put_string(once "(void)(self->vft.get_dst_and_lock(self));%N%
                                %self->vft.set_dst_and_unlock(self,caller);/*unlink*/%N")
         else
            cpp.put_string(once "se_dst=caller;/*unlink*/%N")
         end
         cpp.put_string(once "return C;%N}%N")
      ensure
         cpp.on_c
      end

feature {CLASS_INVARIANT_VISITOR}

   accept(visitor: CLASS_INVARIANT_VISITOR) is
      do
         visitor.visit_class_invariant(Current)
      end

feature {NONE}

   c_code: STRING is
      once
         !!Result.make(128)
      end

end -- CLASS_INVARIANT

