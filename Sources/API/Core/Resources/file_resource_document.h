/*
**  ClanLib SDK
**  Copyright (c) 1997-2016 The ClanLib Team
**
**  This software is provided 'as-is', without any express or implied
**  warranty.  In no event will the authors be held liable for any damages
**  arising from the use of this software.
**
**  Permission is granted to anyone to use this software for any purpose,
**  including commercial applications, and to alter it and redistribute it
**  freely, subject to the following restrictions:
**
**  1. The origin of this software must not be misrepresented; you must not
**     claim that you wrote the original software. If you use this software
**     in a product, an acknowledgment in the product documentation would be
**     appreciated but is not required.
**  2. Altered source versions must be plainly marked as such, and must not be
**     misrepresented as being the original software.
**  3. This notice may not be removed or altered from any source distribution.
**
**  Note: Some of the libraries ClanLib may link to may have additional
**  requirements or restrictions.
**
**  File Author(s):
**
**    Magnus Norddahl
**    Mark Page
*/

#pragma once

#include "../IOData/file_system.h"
#include <vector>
#include <memory>

namespace clan
{
	/// \addtogroup clanCore_Resources clanCore Resources
	/// \{

	class IODevice;
	class FileSystem;
	class FileResourceDocument_Impl;

	/// \brief File Resource Document.
	class FileResourceDocument
	{
	public:
		/// \brief Construct a FileResourceDocument.
		FileResourceDocument();

		/// \brief Constructs a FileResourceDocument
		///
		/// \param fs = File system
		FileResourceDocument(const FileSystem &fs);

		~FileResourceDocument();

		// \brief Get the file system
		FileSystem get_file_system() const;

	private:
		std::shared_ptr<FileResourceDocument_Impl> impl;
	};

	/// \}
}
