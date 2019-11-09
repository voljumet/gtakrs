#pragma once

#include <SFML/Graphics.hpp>
#include <fstream>

#include "DEFINITIONS.h"

namespace GTA {

    class Block : public sf::RectangleShape{
    public:
        sf::RectangleShape getRekt;
        sf::Sprite tileSprite;
        sf::Text text;
        int tileTextureNumber;

    };

    class Map{

    public:
        sf::Font font;

        std::string tileNumer;
        std::string strX;
        std::string strY;
        std::ifstream file;

        Block _Block[WORLD_HEIGHT][WORLD_WIDTH];

        Map();
        void Array(sf::Texture & texture);
        ~Map();

    };
}

