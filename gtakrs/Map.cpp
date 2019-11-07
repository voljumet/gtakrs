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

    void Map::Array() {

        if (!font.loadFromFile(FONT_ARIAL)){ std::cout << "Error no font!"; }
        file.open(MAP_FILE);
        for(int Y = 0; Y < WORLD_HEIGHT; Y++) {
            for (int X = 0; X < WORLD_WIDTH; X++) {
                file >> _Block[Y][X].tileTextureNumber;

                this->_Block[Y][X].getRekt.setSize(sf::Vector2f(TILE_SIZE, TILE_SIZE));
                this->_Block[Y][X].getRekt.setOutlineColor(sf::Color::Red);
                this->_Block[Y][X].getRekt.setOutlineThickness(0.5);
                this->_Block[Y][X].getRekt.setPosition((TILE_SIZE * X), (TILE_SIZE * Y));
                this->_Block[Y][X].getRekt.setFillColor(sf::Color(0, 0, 0, 0));

                tileNumer = std::to_string(_Block[Y][X].tileTextureNumber);
                strX = std::to_string(X);
                strY = std::to_string(Y);

                this->_Block[Y][X].text.setFont(font);
                this->_Block[Y][X].text.setCharacterSize(15);
                this->_Block[Y][X].text.setString("  tile: "+tileNumer+"\nX: "+strX+", Y: "+strY);
                this->_Block[Y][X].text.setFillColor(sf::Color::Blue);
                this->_Block[Y][X].text.setPosition((TILE_SIZE * X), (TILE_SIZE * Y)+10);
            }
        }
        std::cout << _Block[5][5].tileTextureNumber << std::endl;
        file.close();
    }

    Map::~Map() = default;
}