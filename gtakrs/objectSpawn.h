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
    bool hasSniper = false;    float pcPoy = TILE_SIZE * 117.f;

    float burgerPox = TILE_SIZE * 112.f;
    float burgerPoy = TILE_SIZE * 115.f;

    float sniperPox = TILE_SIZE * 112.f;
    float sniperPoy = TILE_SIZE * 114.f;

    float pcPox = TILE_SIZE * 114.f;
public:


    bool isHasPc() const;
    bool isHasBurger() const;
    bool isHasSniper() const;

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