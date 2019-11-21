#pragma once
#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"
#include "DEFINITIONS.h"




class Weapon {

public:

    sf::Sprite gun;
    sf::Texture gunTexture;

    float gun_posX = SCREEN_WIDTH/2;
    float gun_posY = SCREEN_HEIGHT/2;


    void Gun_init();

    void Gun_randompos();


};


