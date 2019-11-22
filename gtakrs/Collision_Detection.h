#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include "Movement.h"

namespace GTA {
    class Collision_Detection {
    public:

        void Check_Collision(sf::Sprite&, sf::Sprite&, bool move);
    private:
        float dx = 0;
        float dy = 0;
    };
}