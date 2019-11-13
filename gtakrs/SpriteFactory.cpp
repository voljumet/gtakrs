//
// Created by Ole Gunvaldsen on 10/11/2019.
//

#include "SpriteFactory.h"
#include "DEFINITIONS.h"

namespace GTA{
    SpriteFactory::SpriteFactory() {
        this->_data->assets.LoadTexture("bluecar", CAR_BLUE);

    }
    sf::Sprite SpriteFactory::CreateSprite() {
        int type = Randomtype();
        switch (type){
            case 1:
                sprite.setTexture(this->_data->assets.GetTexture("bluecar"));
                sprite.setPosition(rand() % 100, rand() % 100);
        }
        return sprite;
    }

    int SpriteFactory::Randomtype() {
        int type = rand() % 4;
        return type;
    }
}