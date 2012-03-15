class EXAMPLE1
--
-- For more information about unicode see first:
--     http://www.unicode.org
--

creation make

feature

   make is
      local
	 unicode_string: UNICODE_STRING
      do
	 unicode_string := U"The EURO sign is %/Ux20AC/!%N"

	 -- If you are running this example on a UTF-8 compatible 
	 -- terminal, you should now see the EURO sign:
	 io.put_string(unicode_string.to_utf8)

	 -- Actually, to make it easier, we have also added a new 
	 -- feature in the OUTPUT_STREAM class to get the same output:
	 io.put_unicode_string(unicode_string)

	 -- For those who like that, you may as well do:
	 print(unicode_string)
	 
      end

end
   
