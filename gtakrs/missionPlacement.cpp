#pragma once

#include "missionPlacement.h"
#include <utility>


namespace GTA{


    missionPlacement::missionPlacement() = default;
    missionPlacement::~missionPlacement() = default;

    void missionPlacement::hackMissionSettings(){

        this->texture.loadFromFile( MISSION_CIRCLE_SPRITE);
        this->missionCircle.setTexture(texture);
        this->missionCircle.setPosition(TILE_SIZE * 113.30f, TILE_SIZE * 71.30f);
        this->missionCircle.setTextureRect(sf::IntRect(0,0,100, 100));
        this->missionCircle.setScale(2.f, 2.f);
        this->missionCircle.setOrigin(50.f, 67.f);
    }

    void missionPlacement::snipeMissionSettings() {
        this->missionCircle.setPosition(TILE_SIZE * 33.30f, TILE_SIZE * 43.30f);
    }

    void missionPlacement::missionStart(GameDataRef data_inn, Player &player, int &missionNumber, sf::Sprite &playerPos) {
        _data = std::move(data_inn);
        std::cout << "mission " << std::endl;

        if (missionNumber == 1) {
            std::cout << "1" << std::endl;
            missionNumber++;
            snipeMissionSettings();
            this->_data->machine.GetActiveState()->Pause();
            this->_data->machine.AddState(StateRef(new Hacking(_data)),false);
        }  else if(missionNumber == 2) {
            std::cout << "2" << std::endl;
            missionNumber++;
            this->_data->machine.GetActiveState()->Pause();
            this->_data->machine.AddState(StateRef(new Mission(_data)),false);
        }
    }

    sf::Sprite missionPlacement::getMissionCircle(){
        return missionCircle;
    }

    void missionPlacement::missionText(int &missionNumber) {
        if (missionNumber == 1){

        } else if (missionNumber == 2){

        }
    }

    void missionPlacement::infoBox(sf::Sprite &player) {

        sf::RectangleShape rectangleShape;
        rectangleShape.setSize(sf::Vector2f(200, 100));
        rectangleShape.setOutlineColor(sf::Color::Red);
        rectangleShape.setOutlineThickness(5);
        rectangleShape.setPosition(player.getPosition().x, player.getPosition().y + 600);
    }
}