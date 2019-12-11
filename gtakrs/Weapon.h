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

        sf::Sprite shotgun;
        sf::Texture shotgunTexture;

        float shotgun_posX = SCREEN_WIDTH / 2;
        float shotgun_posY = SCREEN_HEIGHT / 2;


        float gun_posX = SCREEN_WIDTH / 2;
        float gun_posY = SCREEN_HEIGHT / 2;

        bool hasweapon;
        bool hasshotgun;

        int shotammo = 0;
        int gunammo = 0;

        void Gun_init();

        void Gun_randompos();


    };

}
