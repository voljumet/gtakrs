#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "DEFINITIONS.h"

namespace GTA{
    class objectSpawn {

        float sniperPoy = TILE_SIZE * 365.30f;
        float burgerPox = TILE_SIZE * 18.30f;
        float burgerPoy = TILE_SIZE * 154.30f;
        float pcPoy = TILE_SIZE * 117.f;
        float pcPox = TILE_SIZE * 114.f;

        sf::Sprite pc;
        sf::Texture pcTexture;
        sf::Sprite burger;
        sf::Texture burgerTexture;
        sf::Sprite sniper;
        sf::Texture sniperTexture;

        bool hasPc = false;
        bool hasBurger = false;
        bool hasSniper = false;

        float sniperPox = TILE_SIZE * 159.30f;
    public:
        void setSniperPox(float sniperPox);
        void setSniperPoy(float sniperPoy);
        void setBurgerPox(float burgerPox);
        void setBurgerPoy(float burgerPoy);
        void setPcPoy(float pcPoy);
        void setPcPox(float pcPox);
        void setHasBurger(bool hasBurger);
        void setHasSniper(bool hasSniper);
        void setHasPc(bool hasPc);
        void spawnPc();
        void spawnBurger();
        void spawnSniper();

        sf::Sprite &getPc();
        sf::Sprite &getBurger();
        sf::Sprite &getSniper();

        float getBurgerPox();
        float getBurgerPoy();
        float getSniperPox();
        float getSniperPoy();
        float getPcPox();
        float getPcPoy();
    };
}
