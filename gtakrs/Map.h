#pragma once

#include "TileMap.h"
#include "DEFINITIONS.h"

namespace GTA {
    class Map {

    public:
        std::ifstream file;
        TileMap _map;

        Map();
        void MapLocation();
        void MapLocationPrint();
        void MapLoad();
        ~Map();

    private:
        int mapLocationArray[WORLD_HEIGHT][WORLD_WIDTH]={0};        /// Makes an array Matrix that holds the numbers of all the tiles

        int mapArray[WORLD_HEIGHT * WORLD_WIDTH]={0};     /// Makes an array that contains the size of the total Tiles that is loaded
    };

}

