#pragma once
#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"
#include "DEFINITIONS.h"

namespace GTA{
class Hacking : public State {
public:
    explicit Hacking(GameDataRef data);

    float posX, posY, size;
    bool correctpassword;

    void Init();
    void HandleInput();
    void Update(float dt);
    void Draw(float dt);




private:

    GameDataRef _data;

    sf::Sprite _background;
    sf::Text text, playertext;
    std::string playerinput;
    sf::Font font;
};
}



