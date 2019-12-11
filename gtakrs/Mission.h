#pragma once
#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"
#include "DEFINITIONS.h"

namespace GTA {
class Mission : public State {
public:
    explicit Mission(GameDataRef data);

    enum Direction{Left, Right} dir;

    bool spriteisdead = false;
    bool missionDone = false;

    float posX = 5000, posY= 5000, spriteposX = 0, spriteposY =0, movementspeed=0;
    float clouds1X = 0, clouds2X = 2500;


    int counter{}, steps{};

    void Init() override;
    void HandleInput() override;
    void Update(float dt) override;
    void Draw(float dt) override;
    void UpdateView(const float &dt);

private:

    float scaleFactor = 2.4;
    GameDataRef _data;
    sf::View view;
    sf::Sprite _background;
    sf::Sprite cars;
    sf::Sprite clouds;
    sf::Sprite clouds2;
    sf::Sprite trees;
    sf::Sprite ground;
    sf::Sprite frame;
    sf::Sprite houses;
    sf::Sprite skyskrapers;
    sf::Sprite _sprite;
    sf::Sprite _scope;

    };
}
