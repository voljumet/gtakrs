#include <utility>
#include <iostream>
#include "Map.h"

namespace GTA{

    Map::Map() {

    }

    void Map::MapLoad() {

            file.open(MAP_FILE);
            for (int &i : MapArray) { file >> i; }
            file.close();

            /// Load Tileset---- if not loaded, load...
            if (!_map.load(MAP_TILE_FILEPATH, sf::Vector2u(
                    70, 70),              /// Tile Size
                           MapArray,              /// Tile Array
                           90,                   /// MAP SIZE WIDTH (number of blocks) 90 is standard
                           1000))               /// MAP SIZE HEIGHT (number of blocks) 1000 is standard
                std::cout << "Error in Map loading!" << std::endl;

    }
}