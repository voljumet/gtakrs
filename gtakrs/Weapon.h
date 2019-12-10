#pragma once
#include <SFML/Graphics.hpp>
#include <mach/machine.h>
#include "State.h"
#include "Game.h"
#include "DEFINITIONS.h"



namespace GTA {
    class Weapon {

    public:

        sf::Sprite gun;
        sf::Texture gunTexture;

        bool hasweapon;

        float gun_posX = SCREEN_WIDTH / 2;
        float gun_posY = SCREEN_HEIGHT / 2;

        void Gun_init();
    };

}
