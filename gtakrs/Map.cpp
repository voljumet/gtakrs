#include <iostream>
#include "Map.h"

namespace GTA{

    Map::Map() = default;

    void Map::MapLoad() {
        file.open(MAP_FILE);
        for (int &i : mapArray) { file >> i; }
        file.close();

        if (!_map.load(MAP_TILE_FILEPATH, sf::Vector2u(TILE_SIZE, TILE_SIZE), mapArray, WORLD_WIDTH, WORLD_HEIGHT)){
            std::cout << "Error in Map loading!" << std::endl;
        }
    }

//    void Map::MapLocation() {
//        file.open(MAP_FILE);
//        for(int y = 0; y < WORLD_HEIGHT; y++) {
//            for (int x = 0; x < WORLD_WIDTH; x++) {
//                file >> mapLocationArray[y][x];
//            }
//        }
//        file.close();
//        std::cout << "MapLocation Made!" << std::endl;
//    }

    void Map::MapLocationPrint() {
        for(int y = 0; y < WORLD_HEIGHT; y++) {
            for (int x = 0; x < WORLD_WIDTH; x++) {
                std::cout << "|"<< mapLocationArray[y][x] ;
            }
            std::cout << "|"<< std::endl;
        }
        std::cout << "MapLocation printed!";
    }

    Map::~Map() = default;


}