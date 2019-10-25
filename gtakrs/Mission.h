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

    float posX, posY, spriteposX, spriteposY, movementspeed;

    int counter, steps;

    void Init();
    void HandleInput();
    void Update(float dt);
    void Draw(float dt);

private:

    GameDataRef _data;
    sf::Sprite _background;
    sf::Sprite _sprite;
    sf::Sprite _scope;
    };
}
