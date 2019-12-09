#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include "Game.h"

namespace GTA{
    class Factory{
    public:
        virtual sf::Sprite* CreateNPC() = 0;
        virtual sf::Sprite* CreateCAR() = 0;

    };
}


