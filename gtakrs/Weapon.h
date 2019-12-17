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
        sf::Sprite &getShotgun();

        void setGun(const sf::Sprite &gun);
        void setGunPosX(float gunPosX);
        void setGunPosY(float gunPosY);
        void Gun_init();
        void setShotgun(const sf::Sprite &shotgun);
        void setShotgunPosX(float shotgunPosX);
        void setShotgunPosY(float shotgunPosY);
        void setHasweapon(bool hasweapon);
        void setShotammo(int shotammo);
        void setHasshotgun(bool hasshotgun);
        void setGunammo(int gunammo);

        int getShotammo() const;
        int getGunammo() const;

        float getShotgunPosX() const;
        float getGunPosY() const;
        float getShotgunPosY() const;
        float getGunPosX() const;

        bool isHasweapon() const;
        bool isHasshotgun() const;
    };
}
