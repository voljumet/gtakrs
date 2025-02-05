#pragma once

#include <SFML/Graphics.hpp>
#include <fstream>
#include "Game.h"
#include "DEFINITIONS.h"
#include "Collision_Detection.h"

namespace GTA {

    class Block : public sf::RectangleShape{
    public:
        sf::Sprite tileSprite;
        sf::Text text;
        int tileTextureNumber;
    };

    class Map{
        GameDataRef _data;

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

        friend class Npv;
        friend class Npc;

        void Array(sf::Texture & texture, sf::Font & font);
        void Render(bool Driving, bool Minimap, bool Debug, int carPosX, int carPosY, int playerPosX, int playerPosY, GameDataRef _data, bool NoDrivingOrWalkingBool);
    };
}

