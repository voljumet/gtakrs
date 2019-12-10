#pragma once

#include "missionPlacement.h"
#include <utility>


namespace GTA{


    missionPlacement::missionPlacement() = default;
    missionPlacement::~missionPlacement() = default;

    void missionPlacement::hackMissionSettings(){

        this->texture.loadFromFile( MISSION_CIRCLE_SPRITE);
        this->missionCircle.setTexture(texture);
        this->missionCircle.setPosition(TILE_SIZE * 20, TILE_SIZE * 21);
        this->missionCircle.setTextureRect(sf::IntRect(0,0,100, 100));
        this->missionCircle.setScale(2.f, 2.f);
        this->missionCircle.setOrigin(50.f, 67.f);
        if (!font.loadFromFile(RETRO)){
            std::cout << "Cant load font from resources!" << std::endl;
        }
    }

    void missionPlacement::snipeMissionSettings() {

        this->missionCircle.setPosition(TILE_SIZE * 33.30f, TILE_SIZE * 43.30f);
    }

    void missionPlacement::missionStart(GameDataRef data_inn, Player &player, int &missionNumber, sf::Sprite &playerPos) {
        _data = std::move(data_inn);

        if (missionNumber == 1) {
            missionNumber++;
            snipeMissionSettings();
            this->_data->machine.GetActiveState()->Pause();
            this->_data->machine.AddState(StateRef(new Hacking(_data)),false);
        }

        else if(missionNumber == 2) {
            missionNumber++;
            this->_data->machine.GetActiveState()->Pause();
            this->_data->machine.AddState(StateRef(new Mission(_data)),false);
        }
    }

    sf::Sprite missionPlacement::getMissionCircle(){
        return missionCircle;
    }
    sf::RectangleShape missionPlacement::getBox() {
        return rectangleShape;
    }

    sf::Text missionPlacement::getText() {
        return text;
    }

    void missionPlacement::infoBox(sf::Sprite &player, int &missionNumber) {

        rectangleShape.setSize(sf::Vector2f(800, 250));
        rectangleShape.setOutlineColor(sf::Color::Red);
        rectangleShape.setOutlineThickness(5);
        rectangleShape.setPosition(player.getPosition().x - 400, player.getPosition().y + 400);
        InfoBoxText(player, missionNumber);
    }

    void missionPlacement::InfoBoxText(sf::Sprite &player, int &MN) {

        text.setFont(font);
        if(MN == 1){
            text.setString("  Mission criticle information: \n\n"
                           "  * Click space to activate mission.\n\n"
                           "  * Find gate password.\n\n"
                           "  * Find location of AbraDolf Lincler.\n\n");
        }
        else if(MN == 2){
            text.setString("  Mission criticle information: \n\n"
                           "  * Click space to activate mission.\n\n"
                           "  * Find Abradolf Lincler before he escapes.\n\n"
                           "  * Kill him.\n\n");
        }

        text.setCharacterSize(24);
        text.setFillColor(sf::Color::Black);
        text.setPosition(player.getPosition().x - 400, player.getPosition().y + 400);
    }
}