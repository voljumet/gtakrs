#pragma once

#include <SFML/Graphics.hpp>

#include "DEFINITIONS.h"
#include "Game.h"
#include "State.h"
#include "Values.h"
#include "Map.h"
#include "Block.h"
//#include "Array.h"



namespace GTA{
    class Mappy{
    public:
//        Map map;
        std::ifstream file;
        Values values;

        explicit Mappy();
//        ~Mappy();

        void Init();
        void Draw(float dt);
//        void HandleInput();
//        void Update(float dt) ;
//        void UpdateView(const float& dt);

        Block Block[WORLD_HEIGHT][WORLD_WIDTH];
    private:
//        Array array;
//        int mapLocationArray[WORLD_HEIGHT][WORLD_WIDTH];
        GameDataRef _data;

        sf::Sprite _black;
        sf::Sprite _road1, _road2, _road3, _road4, _road5;
        sf::Sprite _curb1, _curb2, _curb3, _curb4;
        sf::Sprite _water;
        sf::Sprite _grass, _bush;
        sf::Sprite _roof1, _roof2;

    };

}
