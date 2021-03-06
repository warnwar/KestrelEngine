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

#if !defined(KESTREL_TEXT_HPP)
#define KESTREL_TEXT_HPP

#include <memory>
#include "math/point.hpp"
#include "math/vector.hpp"
#include "math/size.hpp"
#include "core/graphics/common/entity.hpp"
#include "util/hint.hpp"
#include "scripting/state.hpp"
#include "core/graphics/common/font.hpp"
#include "core/graphics/common/color.hpp"

namespace graphics
{

    class text: public std::enable_shared_from_this<graphics::text>, public scripting::lua::object
    {
    public:
        typedef luabridge::RefCountedPtr<graphics::text> lua_reference;
        static auto enroll_object_api_in_state(const std::shared_ptr<scripting::lua::state>& lua) -> void;

    private:
        std::string m_text;
        int m_font_size;
        std::string m_font_face;
        graphics::color m_color { graphics::color::white_color() };

    public:
        lua_api text(std::string text, std::string font, int size, const graphics::color::lua_reference& color);

        lua_api auto spawn_entity(const math::vector& position) -> graphics::entity::lua_reference;

        lua_api auto get_value() const -> std::string;
        lua_api auto get_font_size() const -> int;
        lua_api auto get_font() const -> std::string;
        lua_api auto get_color() const -> graphics::color::lua_reference;
    };

}

#endif //KESTREL_TEXT_HPP
