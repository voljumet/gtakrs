#pragma once

#include <SFML/Graphics.hpp>

#include "DEFINITIONS.h"
#include "Game.h"
#include "State.h"
#include "Values.h"
#include "Map.h"
#include <fstream>


namespace GTA{
    class Mappy : public State{
    public:
        std::ifstream file;

        Mappy();
        ~Mappy();

        void LoadMap();
        void DrawMap();

    private:
        int mapLocationArray[WORLD_HEIGHT][WORLD_WIDTH];
        GameDataRef _data;

        sf::RectangleShape src, dest;

//        sf::Texture* _road1;
//        sf::Texture* _grass;
//        sf::Texture* _water;

    sf::Sprite *_black;
    sf::Sprite *_road1, *_road2, *_road3, *_road4, *_road5;
    sf::Sprite *_curb1, *_curb2, *_curb3, *_curb4;
    sf::Sprite *_water;
    sf::Sprite *_grass, *_bush;
    sf::Sprite *_roof1, *_roof2;

    };

}
