#pragma once

#include <iostream>

#include "DEFINITIONS.h"

namespace GTA {
    class Map {
        int MapArray[MAP_SIZE_HEIGHT][MAP_SIZE_WIDTH];
    public:

        Map();
        void Init();

    };

}

