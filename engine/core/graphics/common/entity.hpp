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

#if !defined(KESTREL_ENTITY_HPP)
#define KESTREL_ENTITY_HPP

#include <memory>
#include "math/point.hpp"
#include "math/vector.hpp"
#include "math/size.hpp"
#include "core/graphics/common/spritesheet.hpp"
#include "core/graphics/common/scene.hpp"

namespace graphics
{

    class entity: public std::enable_shared_from_this<graphics::entity>
    {
    public:
        math::vector position;
        math::size size;
        int sprite_index { 0 };

    private:
        std::shared_ptr<graphics::spritesheet> m_spritesheet;
        std::weak_ptr<graphics::scene> m_scene;

    public:
        explicit entity(const math::size& size);
        entity(const math::vector& position, const math::size& size);

        auto move_to_scene(std::weak_ptr<graphics::scene> scene);
        auto scene() const -> std::weak_ptr<graphics::scene>;

        auto set_spritesheet(std::shared_ptr<graphics::spritesheet> sheet, const int& sprite_index = 0) -> void;
        auto sritesheet() const -> std::shared_ptr<graphics::spritesheet>;
        auto texture() const -> std::shared_ptr<graphics::texture>;

        auto draw() const -> void;
    };

};

#endif //KESTREL_ENTITY_HPP