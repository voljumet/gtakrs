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

    void missionPlacement::activate(Npc npc) {

        int npcPosY, npcPosX;
        sf::Vector2f npcPos = npc.getNpcBot().getPosition();
        sf::Vector2f missionCircle = getMissionCircle().getPosition();


        if(mission){
            if(npcPos == missionCircle){
                std::cout << "Player on place" << std::endl;
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::M)){
                    this->_data->machine.GetActiveState();
                    this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
                }
            }
        }

    }

    const sf::CircleShape &missionPlacement::getMissionCircle() const {
        return missionCircle;
    }


}