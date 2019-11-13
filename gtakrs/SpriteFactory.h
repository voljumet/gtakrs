//
// Created by Ole Gunvaldsen on 10/11/2019.
//

#ifndef GTAKRS_SPRITEFACTORY_H
#define GTAKRS_SPRITEFACTORY_H



#include <SFML/Graphics/Sprite.hpp>
#include "Game.h"

namespace GTA {
    class SpriteFactory {
    public:
        sf::Sprite sprite;
        SpriteFactory();


        sf::Sprite CreateSprite();
        int Randomtype();

    private:
        GameDataRef _data;
    };
}


#endif //GTAKRS_SPRITEFACTORY_H
