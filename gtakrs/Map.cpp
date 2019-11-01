#include <iostream>
#include "Map.h"

namespace GTA{

    Map::Map() { }

    void Map::MapLoad() {
        file.open(MAP_FILE);
        for (int &i : mapArray) { file >> i; }
        file.close();

        if (!_map.load(MAP_TILE_FILEPATH, sf::Vector2u(TILE_SIZE, TILE_SIZE),mapArray, WORLD_SIZE_WIDTH, WORLD_SIZE_HEIGHT)){
            std::cout << "Error in Map loading!" << std::endl;
        }
    }

    void Map::MapLocation() {
           file.open(MAP_FILE);
        for(int i=0; i < WORLD_SIZE_HEIGHT; i++) {
            for (int j = 0; j < WORLD_SIZE_WIDTH; j++) {
                file >> mapLocationArray[i][j];
            }
        }

        for(int i=0; i < WORLD_SIZE_HEIGHT; i++) {
            for (int j = 0; j < WORLD_SIZE_WIDTH; j++) {
                std::cout << mapLocationArray[i][j];
            }
            std::cout << std::endl;
        }
//            std::cout << "its alive!";
    }
}