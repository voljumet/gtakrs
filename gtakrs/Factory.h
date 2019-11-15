//
// Created by Ole Gunvaldsen on 13/11/2019.
//

#ifndef GTAKRS_FACTORY_H
#define GTAKRS_FACTORY_H

#include <SFML/Graphics/Sprite.hpp>
#include "Game.h"

namespace GTA{
    class Factory{
    public:
        virtual sf::Sprite* CreateNPC() = 0;
        virtual sf::Sprite* CreateCAR() = 0;

    };
}
#endif //GTAKRS_FACTORY_H


