#pragma once


#include <SFML/Graphics/Sprite.hpp>
#include "Factory.h"



namespace GTA {
    class SpriteFactory : public Factory{

    public:
        sf::Sprite* CreateNPC(){
            return  new sf::Sprite;
        }
        sf::Sprite* CreateCAR(){
            return new sf::Sprite;
        }
    };
}

