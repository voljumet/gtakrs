//
// Created by Ole Gunvaldsen on 10/11/2019.
//

#ifndef GTAKRS_SPRITEFACTORY_H
#define GTAKRS_SPRITEFACTORY_H



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


#endif //GTAKRS_SPRITEFACTORY_H
