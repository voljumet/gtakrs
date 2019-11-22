#pragma once

#include "missionPlacement.h"

#include <utility>
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

    void missionPlacement::activate(GameDataRef data_inn, Player player) {
        _data = std::move(data_inn);
        if (PixelPerfectTest(getMissionCircle(), player.playerGetSprite())) {
                std::cout << "true" << std::endl;
            this->_data->machine.GetActiveState()->Pause();
            this->_data->machine.AddState(StateRef(new Mission(_data)),
                    false);

        }


    }


    sf::Sprite missionPlacement::getMissionCircle(){
        return missionCircle;
    }

    void missionPlacement::updateView() {

    }


}