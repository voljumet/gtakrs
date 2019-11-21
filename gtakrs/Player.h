#pragma once

#include "Movement.h"

namespace GTA{
class Player : Movement{
public:
    Player();
    ~Player();


    void playerInit(sf::Texture &texture); // loading texture
    void playerMoves();

private:
    sf::Sprite playerSprite;
    Movement movement;


};
}



