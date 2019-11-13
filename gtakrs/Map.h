#pragma once

#include <SFML/Graphics.hpp>
#include <fstream>
#include "Game.h"
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
        std::string tileNumer;
        std::string strX;
        std::string strY;
        std::ifstream file;

//        bool debug = false;
//        bool Minimap = false;

        int mapReach = 15;
        int miniMapReach = 27;
        int fromX = 0, toX = 0;
        int fromY = 0, toY = 0;
//        int mposX, posY;

        Block _Block[WORLD_HEIGHT][WORLD_WIDTH];

        Map();
        void Array(sf::Texture & texture, sf::Font & font);
        void Numbers(int,int,bool);
        ~Map();

    };
}

