#pragma once

#include "missionPlacement.h"
#include "DEFINITIONS.h"

namespace GTA{

    missionPlacement::missionPlacement() = default;
    missionPlacement::~missionPlacement() = default;

    void missionPlacement::initCoin() {

        sf::CircleShape circle;
        this->missionCircle.setRadius(50);
        this->missionCircle.setFillColor(sf::Color::Transparent);
        this->missionCircle.setOutlineColor(sf::Color::Yellow);
        this->missionCircle.setOutlineThickness(5);
        this->missionCircle.setPosition(TILE_SIZE * 33, TILE_SIZE * 43);
        this->missionCircle.setOrigin(missionCircle.getRadius(), missionCircle.getRadius());

    }


    void missionPlacement::activate() {


    }

    const sf::CircleShape &missionPlacement::getMissionCircle() const {
        return missionCircle;
    }


}