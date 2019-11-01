#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>

#include "State.h"
#include "Game.h"
#include "DEFINITIONS.h"

namespace GTA{
    class WorldMap : public  State{
    public:
        WorldMap(GameDataRef data);

        ~WorldMap();

        void DrawMap();
        void LoadMap();

        /// Loads file for Map
        std::ifstream file;

    private:
        GameDataRef _data;
        GameDataRef _water;
        GameDataRef _grass;
        GameDataRef _dirt;

//        sf::Texture* tmpSurface.LoadT MAP_TILE_FILEPATH

        sf::Texture* dirt;
        sf::Texture* grass;
        sf::Texture* water;
        int map[20][25]{};

    };
}