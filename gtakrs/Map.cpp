#include <iostream>
#include "Map.h"

namespace GTA{

    Map::Map() = default;

    void Map::Array(sf::Texture & texture){

        if (!font.loadFromFile(FONT_ARIAL)){ std::cout << "Error no font!"; }
        file.open(MAP_FILE);
        for(int Y = 0; Y < WORLD_HEIGHT; Y++) {
            for (int X = 0; X < WORLD_WIDTH; X++) {
                file >> _Block[Y][X].tileTextureNumber;

                tileNumer = std::to_string(_Block[Y][X].tileTextureNumber);

                this->_Block[Y][X].getRekt.setSize(sf::Vector2f(TILE_SIZE, TILE_SIZE));
                this->_Block[Y][X].getRekt.setOutlineColor(sf::Color::Red);
                this->_Block[Y][X].getRekt.setOutlineThickness(0.5);
                this->_Block[Y][X].getRekt.setPosition((TILE_SIZE * X), (TILE_SIZE * Y));
                this->_Block[Y][X].getRekt.setFillColor(sf::Color(0, 0, 0, 0));

                this->_Block[Y][X].tileSprite.setTexture(texture);         /// Set Texture for tile
                this->_Block[Y][X].tileSprite.setPosition((TILE_SIZE * X), (TILE_SIZE * Y));                /// Place player
                this->_Block[Y][X].tileSprite.setTextureRect(sf::IntRect(0, (_Block[Y][X].tileTextureNumber) * TILE_SIZE, 70,70));      /// Player rectangle load pictures from (0,0), size of rectangle (100x110)px
                this->_Block[Y][X].tileSprite.setScale(sf::Vector2f(1.0f, 1.0f));                     /// player scale factor
                this->_Block[Y][X].tileSprite.setOrigin(0.f, 0.f);                                          /// Origin player position

                strX = std::to_string(X);
                strY = std::to_string(Y);

                this->_Block[Y][X].text.setFont(font);
                this->_Block[Y][X].text.setCharacterSize(15);

                if(_Block[Y][X].tileTextureNumber <= 9){
                    this->_Block[Y][X].text.setString("  tile: 0"+tileNumer+"\n  X: "+strX+"\n  Y: "+strY);
                } else {
                    this->_Block[Y][X].text.setString("  tile: "+tileNumer+"\n  X: "+strX+"\n  Y: "+strY);
                }
                this->_Block[Y][X].text.setFillColor(sf::Color::Blue);
                this->_Block[Y][X].text.setPosition((TILE_SIZE * X), (TILE_SIZE * Y)+9);
            }
        }
        std::cout << _Block[5][5].tileTextureNumber << std::endl;
        file.close();
    }

    Map::~Map() = default;
}