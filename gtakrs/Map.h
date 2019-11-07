#pragma once

#include "TileMap.h"
#include "DEFINITIONS.h"

namespace GTA {

    class Block : public sf::RectangleShape{
    public:
        sf::RectangleShape getRekt;
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
        TileMap _map;

        Map();
        void MapLoad();
        void Array();
        ~Map();
        Block _Block[WORLD_HEIGHT][WORLD_WIDTH];

    private:
        int mapArray[WORLD_HEIGHT * WORLD_WIDTH]={0};     /// Makes an array that contains the size of the total Tiles that is loaded
    };



}

