#pragma once

#include <SFML/Graphics.hpp>
#include <mach/machine.h>
#include "State.h"
#include "Game.h"
#include "DEFINITIONS.h"

namespace GTA {
    class Weapon {
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


    public:
        sf::Sprite &getGun();

        void setGun(const sf::Sprite &gun);

        float getGunPosX() const;

        void setGunPosX(float gunPosX);

        float getGunPosY() const;

        void setGunPosY(float gunPosY);

        void Gun_init();


        void Gun_randompos();

        sf::Sprite &getShotgun();

        void setShotgun(const sf::Sprite &shotgun);

        float getShotgunPosX() const;

        void setShotgunPosX(float shotgunPosX);

        float getShotgunPosY() const;

        void setShotgunPosY(float shotgunPosY);

        bool isHasweapon() const;

        void setHasweapon(bool hasweapon);

        int getShotammo() const;

        void setShotammo(int shotammo);

        int getGunammo() const;

        void setGunammo(int gunammo);

        bool isHasshotgun() const;

        void setHasshotgun(bool hasshotgun);


    };

}
