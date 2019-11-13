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
        int roads[5]={14,5,6,7,8};
        int curbs[4]={1,2,3,4};
        int roof[2]={11,12};
        int grass[2]={10,13};
        int water = 9;

        friend class Npc;

    private:
        int mapArray[WORLD_HEIGHT * WORLD_WIDTH]={0};     /// Makes an array that contains the size of the total Tiles that is loaded
    };



}

