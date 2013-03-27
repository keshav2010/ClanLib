/*
**  ClanLib SDK
**  Copyright (c) 1997-2011 The ClanLib Team
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
*/

#include "SWRender/precomp.h"
#include "API/Core/System/mutex.h"
#include "API/SWRender/setup_swrender.h"
#include "API/SWRender/swr_target.h"

namespace clan
{

/////////////////////////////////////////////////////////////////////////////
// SetupSWRender Construction:

static Mutex cl_gdi_mutex;

static int cl_gdi_refcount = 0;

static SWRenderTarget *cl_gdi_target = 0;

SetupSWRender::SetupSWRender()
{
	if (!System::detect_cpu_extension(System::sse2))
	{
		throw Exception("Sorry, clanSWRender requires a processor capable of SSE2 instructions. (Update your CPU)");
	}

	MutexSection mutex_lock(&cl_gdi_mutex);
	if (cl_gdi_refcount == 0)
		cl_gdi_target = new SWRenderTarget();
	cl_gdi_refcount++;
}

SetupSWRender::~SetupSWRender()
{
	MutexSection mutex_lock(&cl_gdi_mutex);
	cl_gdi_refcount--;
	if (cl_gdi_refcount == 0)
		delete cl_gdi_target;
}

void SetupSWRender::set_current()
{
	MutexSection mutex_lock(&cl_gdi_mutex);
	cl_gdi_target->set_current();
}

}