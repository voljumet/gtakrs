#ifndef GTAKRS_SPRITE_H
#define GTAKRS_SPRITE_H
#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"
#include "DEFINITIONS.h"
#include "Audio.h"


class Sprite {

    int posx;
    int posy;
    int scale;
    sf::Texture playertexture;
    sf::Sprite sprite;



    int getposition(int posx, int posy);
    void setposition();
    void loadtexture();






};


#endif //GTAKRS_SPRITE_H

