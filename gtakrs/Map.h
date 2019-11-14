#pragma once

#include <SFML/Graphics.hpp>
#include <fstream>
#include "Game.h"
#include "DEFINITIONS.h"

namespace GTA {

    class Block : public sf::RectangleShape{
    public:
        sf::RectangleShape getRekt;
        sf::Sprite tileSprite;
        sf::Text text;
        int tileTextureNumber;

    };

    class Map{

    public:
        std::string tileNumer;
        std::string strX;
        std::string strY;
        std::ifstream file;

        int mapReach = 15;
        int miniMapReach = 27;
        int fromX = 0, toX = 0;
        int fromY = 0, toY = 0;
        int mPosX, mPosY;

        Block _Block[WORLD_HEIGHT][WORLD_WIDTH];

        void Array(sf::Texture & texture, sf::Font & font);
        void Render(bool Driving, bool Minimap, bool Debug, int carPosX, int carPosY, int playerPosX,
                int playerPosY, Block pBlock[WORLD_HEIGHT][WORLD_WIDTH], GameDataRef _data);

    private:
        GameDataRef _data;
    };


}

