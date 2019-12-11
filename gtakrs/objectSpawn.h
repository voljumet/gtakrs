#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "DEFINITIONS.h"

class objectSpawn {

    sf::Sprite pc;
    sf::Texture pcTexture;
    sf::Sprite burger;
    sf::Texture burgerTexture;
    sf::Sprite sniper;
    sf::Texture sniperTexture;

    bool hasPc = false;
    bool hasBurger = false;
    bool hasSniper = false;

    float burgerPox = TILE_SIZE * 125.f;
    float burgerPoy = TILE_SIZE * 285.f;

    float sniperPox = TILE_SIZE * 46.30f;
    float sniperPoy = TILE_SIZE * 65.30f;

    float pcPoy = TILE_SIZE * 117.f;
    float pcPox = TILE_SIZE * 114.f;

public:

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