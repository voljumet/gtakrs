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

        this->missionCircle.setTextureRect(sf::IntRect(0,0,
                100, 100));
        this->missionCircle.setScale(2.f, 2.f);
//        this->missionCircle.setColor(sf::Color::Transparent); /// unvisible if uncommented
        this->missionCircle.setOrigin(50.f, 67.f);
    }

    void missionPlacement::missionSnipe(GameDataRef data_inn, Player player) {
        _data = std::move(data_inn);

        this->missionCircle.setPosition(TILE_SIZE * 33.30f, TILE_SIZE * 43.30f);
        initCoin();
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

    void missionPlacement::missionHack(GameDataRef data_inn, Player player) {
        _data = std::move(data_inn);
        this->missionCircle.setPosition(TILE_SIZE * 113.30f, TILE_SIZE * 71.30f);
        initCoin();
        if (PixelPerfectTest(getMissionCircle(), player.playerGetSprite())) {
            std::cout << "true" << std::endl;
            this->_data->machine.GetActiveState()->Pause();
            this->_data->machine.AddState(StateRef(new Mission(_data)),
                                          false);
        }
    }


    }