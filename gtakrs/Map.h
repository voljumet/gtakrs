#pragma once

#include "TileMap.h"
#include "DEFINITIONS.h"

namespace GTA {
    class Map {

    public:
        std::ifstream file;
        TileMap _map;     ///Makes instance of TileMap class.

        Map();
        void MapLocation();
        void MapLocationPrint();
        void MapLoad();
        ~Map();

    private:
        int mapLocationArray[WORLD_SIZE_HEIGHT][WORLD_SIZE_WIDTH]={0};        /// Makes an array Matrix that holds the numbers of all the tiles

        int mapArray[WORLD_SIZE_WIDTH * WORLD_SIZE_HEIGHT]={0};     /// Makes an array that contains the size of the total Tiles that is loaded
    };

}

