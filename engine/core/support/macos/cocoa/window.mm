// Copyright (c) 2020 Tom Hancocks
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include "core/support/macos/cocoa/window.h"
#include "core/support/macos/cocoa/cocoa_utils.h"

// MARK: - Construction

cocoa::window::window()
{
    NSWindow *window = [[NSWindow alloc] initWithContentRect:NSMakeRect(0, 0, 200, 200)
                                                   styleMask:NSWindowStyleMaskTitled
                                                     backing:NSBackingStoreBuffered
                                                       defer:NO];
    [window cascadeTopLeftFromPoint:NSMakePoint(20,20)];
    [window makeKeyAndOrderFront:nil];
    m_handle = window;
}

// MARK: - Accessors

auto cocoa::window::set_title(const std::string &title) -> void
{
    NSWindow *wnd = (__bridge NSWindow *)m_handle;
    [wnd setTitle:cocoa::string::to(title)];
}

auto cocoa::window::title() const -> std::string
{
    NSWindow *wnd = (__bridge NSWindow *)m_handle;
    return cocoa::string::from([wnd title]);
}

auto cocoa::window::set_size(const int& width, const int& height) -> void
{
    NSWindow *wnd = (__bridge NSWindow *)m_handle;
    [wnd setFrame:NSMakeRect(0, 0, width, height) display:YES];
    [wnd center];
}
