#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"
#include "DEFINITIONS.h"

namespace GTA {
    class Mission : public State {
        enum Direction { Left, Right } dir;
        bool spriteisdead = false;
        int counter{}, steps{};
        float posX = 5000, posY = 5000, spriteposX = 0, spriteposY = 0, movementspeed = 0;
        float clouds1X = 0, clouds2X = 2500;
        float scaleFactor = 2.4;
        GameDataRef _data;
        sf::View view;
        sf::Sprite _background;
        sf::Sprite clouds;
        sf::Sprite clouds2;
        sf::Sprite trees;
        sf::Sprite frame;
        sf::Sprite houses;
        sf::Sprite skyskrapers;
        sf::Sprite _sprite;
        sf::Sprite _scope;

    public:
        void Init() override;
        void HandleInput() override;
        void Update(float dt) override;
        void Draw(float dt) override;
        void UpdateView(const float &dt);
        explicit Mission(GameDataRef data);
    };
}
