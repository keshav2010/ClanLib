/*
**  ClanLib SDK
**  Copyright (c) 1997-2015 The ClanLib Team
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

#include "API/Display/TargetProviders/display_window_provider.h"
#include "API/Display/Render/graphic_context.h"
#include "API/Display/Window/input_context.h"
#include <memory>
#include "API/GL/opengl_window_description.h"
#include "API/GL/opengl_wrap.h"

namespace clan
{

class OpenGLWindowDescription;

class OpenGLWindowProvider : public DisplayWindowProvider
{
/// \name Construction
/// \{

public:
	OpenGLWindowProvider(OpenGLWindowDescription &opengl_desc);
	~OpenGLWindowProvider();


/// \}
/// \name Attributes
/// \{

public:
	Rect get_geometry() const override;
	Rect get_viewport() const override;
	bool is_fullscreen() const override;
	bool has_focus() const override;
	bool is_minimized() const override;
	bool is_maximized() const override;
	bool is_visible() const override;
	std::string get_title() const override;
	Size get_minimum_size(bool client_area) const;
	Size get_maximum_size(bool client_area) const;
	DisplayWindowHandle get_handle() const override { return DisplayWindowHandle(); }
	GraphicContext& get_gc() override { return gc; }
	InputContext get_ic() override { return InputContext(); }
	bool is_clipboard_text_available() const override;
	bool is_clipboard_image_available() const override;
	std::string get_clipboard_text() const override;
	PixelBuffer get_clipboard_image() const override;
	float get_pixel_ratio() const override;

/// \}
/// \name Operations
/// \{

public:
	Point client_to_screen(const Point &client) override;
	Point screen_to_client(const Point &screen) override;
	void create(DisplayWindowSite *site, const DisplayWindowDescription &description) override;

	void show_system_cursor() override;
	CursorProvider *create_cursor(const CursorDescription &cursor_description) override;
	void set_cursor(CursorProvider *cursor) override;
	void set_cursor(StandardCursor type) override;
	void hide_system_cursor() override;
	void set_title(const std::string &new_title) override;
	void set_position(const Rect &pos, bool client_area) override;
	void set_size(int width, int height, bool client_area) override;
	void set_minimum_size(int width, int height, bool client_area) override;
	void set_maximum_size( int width, int height, bool client_area) override;
	void set_enabled(bool enable) override;
	void minimize() override;
	void restore() override;
	void maximize() override;
	void show(bool activate) override;
	void hide() override;
	void bring_to_front() override;

	/// \brief Flip OpenGL buffers.
	void flip(int interval) override;

	/// \brief Copy a region of the back buffer to the front buffer.
	void update(const Rect &rect) override;

	/// \brief Capture/Release the mouse.
	void capture_mouse(bool capture) override;

	/// \brief Stores text in the clipboard.
	void set_clipboard_text(const std::string &text) override;

	void set_clipboard_image(const PixelBuffer &buf) override;

	/// \brief Invalidates a region of a screen, causing a repaint.
	void request_repaint(const Rect &rect) override;

	void set_large_icon(const PixelBuffer &image) override;
	void set_small_icon(const PixelBuffer &image) override;

	void enable_alpha_channel(const Rect &blur_rect) override;
	void extend_frame_into_client_area(int left, int top, int right, int bottom) override;

	void set_pixel_ratio(float ratio) override;

/// \}
/// \name Implementation
/// \{

private:
	GraphicContext gc;
/// \}
};

}