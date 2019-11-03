#pragma once

#include <SFML/Graphics.hpp>

#include "DEFINITIONS.h"
#include "Game.h"
#include "State.h"
#include "Values.h"
#include "Map.h"
#include "Array.h"
#include <fstream>


namespace GTA{
    class Mappy : public State{
    public:
        Map map;
        std::ifstream file;
        Values values;

        explicit Mappy(GTA::GameDataRef data);
//        ~Mappy();

        void Init();
        void Draw(float dt) override;
        void HandleInput() override;
        void Update(float dt) override;
        void UpdateView(const float& dt);

    private:
//        Array array;
        Array MappyArray[4][4];
        int mapLocationArray[WORLD_HEIGHT][WORLD_WIDTH];
        GameDataRef _data;

        sf::Sprite _black;
        sf::Sprite _road1, _road2, _road3, _road4, _road5;
        sf::Sprite _curb1, _curb2, _curb3, _curb4;
        sf::Sprite _water;
        sf::Sprite _grass, _bush;
        sf::Sprite _roof1, _roof2;

    };

}
