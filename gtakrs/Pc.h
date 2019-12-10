#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "DEFINITIONS.h"

class Pc {
public:

    void spawnPc();

private:
    sf::Sprite pc;
    sf::Texture pcTexture;
public:
    sf::Sprite &getPc();

private:

    float pcPox = TILE_SIZE * 114.f;
    float pcPoy = TILE_SIZE * 117.f;
public:
    float getPcPox() const;

    float getPcPoy() const;

    bool hasPc = false;
};