#pragma once


#include <SFML/Audio.hpp>

namespace GTA {


    class aiController {
    public:
        sf::Vector2f npcMovement;
        void npcPath();
        void npcRandomMove();
    };
}

