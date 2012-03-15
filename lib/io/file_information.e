expanded class FILE_INFORMATION

feature -- Access

	exists: BOOLEAN
			-- Existing file?

	device: INTEGER_32 is
			-- Device identifier for device containing file
		require
			exists
		do
			Result := internal_device
		end

	inode: INTEGER_64 is
			-- identification for physical file
		require
			exists
		do
			Result := internal_inode
		end

	mode: INTEGER_32 is
			-- Bit encoded access rights and file type
		require
			exists
		do
			Result := internal_mode
		end

	links: INTEGER_32 is
			-- Number of references to the file (physical, not symbolic)
		require
			exists
		do
			Result := internal_links
		ensure
			Result >= 0
		end

	user_id: INTEGER_32 is
			-- Numeric id of file owner
		require
			exists
		do
			Result := internal_user_id
		end

	group_id: INTEGER_32 is
			-- Numeric id of file group
		require
			exists
		do
			Result := internal_group_id
		end

	size: INTEGER_64 is
			-- File size in bytes
		require
			exists
		do
			Result := internal_size
		ensure
			Result >= 0
		end

	access_time: INTEGER is
			-- Time of last file access
		require
			exists
		do
			Result := internal_atime
		end

	modification_time: INTEGER is
			-- Time of last file modification
		require
			exists
		do
			Result := internal_mtime
		end

	metadata_modification_time: INTEGER is
			-- Time of last modification to file metadata
		require
			exists
		do
			Result := internal_ctime
		end

feature -- Operations

	update (path: STRING) is
			-- Update with information from file named `path'
	do
		exists := basic_fstat_st_all (path.to_external,
		$internal_device,
		$internal_inode,
		$internal_mode,
		$internal_links,
		$internal_user_id,
		$internal_group_id,
		$internal_size,
		$internal_atime,
		$internal_ctime,
		$internal_mtime)
	end

feature {NONE} -- Representation

	internal_device: INTEGER_32
	internal_inode: INTEGER_64
	internal_mode: INTEGER_32
	internal_links: INTEGER_32
	internal_user_id: INTEGER_32
	internal_group_id: INTEGER_32
	internal_size: INTEGER_64
	internal_atime, internal_ctime, internal_mtime: INTEGER

feature {NONE} -- External

	basic_fstat_st_all (path, dev, ino, mod, nlink, uid, gid, sz, atim, mtim, ctim: POINTER): BOOLEAN is
		external "SmartEiffel"
		end

end -- class FILE_INFORMATION