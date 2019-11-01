#pragma once

#include "TileMap.h"
#include "DEFINITIONS.h"

namespace GTA {
    class Map {

    public:
        /// Loads file for Map
        std::ifstream file;
        Map();
        TileMap _map;

        void MapLoad();


    private:

        int MapArray[MAP_SIZE_HEIGHT*MAP_SIZE_WIDTH];
    };

}

