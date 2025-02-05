#include <iostream>
#include "Map.h"

namespace GTA{
    /// Create the Matrix with numbers and sprites for tile-map
    void Map::Array(sf::Texture & texture, sf::Font & font){

        file.open(MAP_FILE);
        for(int Y = 0; Y < WORLD_HEIGHT; Y++) {
            for (int X = 0; X < WORLD_WIDTH; X++) {
                file >> _Block[Y][X].tileTextureNumber;
                _Block[Y][X].tileTextureNumber -=1;

                tileNumer = std::to_string(_Block[Y][X].tileTextureNumber);

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
        file.close();
    }
    /// Draw map ONLY inside the view
    void Map::Render(bool Driving, bool Minimap, bool Debug, int carPosX, int carPosY, int playerPosX,
        int playerPosY, GameDataRef inn_data, bool NoDrivingOrWalkingBool) {
        if(Driving){
            mPosX = carPosX / TILE_SIZE;
            mPosY = carPosY / TILE_SIZE;
        } else {
            mPosX = playerPosX / TILE_SIZE;
            mPosY = playerPosY / TILE_SIZE;
        }

        if(!Minimap){
            fromX = mPosX - mapReach;
            toX = mPosX + mapReach;
            fromY = mPosY - mapReach;
            toY = mPosY + mapReach;
        } else {
            fromX = mPosX - miniMapReach;
            toX = mPosX + miniMapReach;
            fromY = mPosY - miniMapReach;
            toY = mPosY + miniMapReach;
        }
         _data = inn_data;
        if(fromX < 0){ fromX = 0; } else if (fromX >= WORLD_WIDTH){ fromX = WORLD_WIDTH -1; }
        if(fromY < 0){ fromY = 0; } else if (fromY >= WORLD_HEIGHT){ fromY = WORLD_HEIGHT -1; }
        if(toX < 0){ toX = 0; } else if (toX >= WORLD_WIDTH){ toX = WORLD_WIDTH -1; }
        if(toY < 0){ toY = 0; } else if (toY >= WORLD_HEIGHT){ toY = WORLD_HEIGHT -1; }

        for(int Y = fromY; Y < toY; Y++) {
            for (int X = fromX; X < toX; X++) {
                /// Draw tiles
                 this->_data->window.draw(this->_Block[Y][X].tileSprite);
                if(Debug){
                    this->_data->window.draw(this->_Block[Y][X].text);
                }
            }
        }
    }
}