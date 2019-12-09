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


    float posX = 5000, posY= 5000, spriteposX, spriteposY, movementspeed;


    int counter{}, steps{};

    void Init() override;
    void HandleInput() override;
    void Update(float dt) override;
    void Draw(float dt) override;
    void UpdateView(const float &dt);

private:

    GameDataRef _data;
    sf::View view;
    sf::Sprite _background;
    sf::Sprite cars;
    sf::Sprite clouds;
    sf::Sprite trees;
    sf::Sprite ground;
    sf::Sprite houses;
    sf::Sprite skyskrapers;
    sf::Sprite _sprite;
    sf::Sprite _scope;

    };
}
