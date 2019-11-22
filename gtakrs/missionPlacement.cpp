#pragma once

#include "missionPlacement.h"
#include "WorldState.h"


namespace GTA{


    missionPlacement::missionPlacement() = default;
    missionPlacement::~missionPlacement() = default;

    void missionPlacement::initCoin() {

        this->texture.loadFromFile( MISSION_CIRCLE_SPRITE);
        this->missionCircle.setTexture(texture);
        this->missionCircle.setPosition(TILE_SIZE * 33, TILE_SIZE * 43);
        this->missionCircle.setTextureRect(sf::IntRect(0,0,
                100, 100));
        this->missionCircle.setScale(2.f, 2.f);
//        this->missionCircle.setColor(sf::Color::Transparent);
        this->missionCircle.setOrigin(50.f, 67.f);
    }

    void missionPlacement::activate(bool mission, Player player) {

        if (PixelPerfectTest(getMissionCircle(), player.playerGetSprite())) {
            mission = true;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)) {
                std::cout << "true" << std::endl;
//                    this->_data->machine.GetActiveState();
                this->_data->machine.AddState(StateRef(new Mission(_data)), true);
            }
        }
    }

    sf::Sprite missionPlacement::getMissionCircle(){
        return missionCircle;
    }


}