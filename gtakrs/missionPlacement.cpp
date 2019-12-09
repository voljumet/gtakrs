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

    void missionPlacement::missionStart(GameDataRef data_inn, Player &player, int &missionNumber, sf::Sprite &playerPos) {
        _data = std::move(data_inn);
        std::cout << "mission " << std::endl;

        switch (missionNumber){

            case 1:
                std::cout << "1" << std::endl;
                missionNumber++;
//                this->missionCircle.setPosition(TILE_SIZE * 33.30f, TILE_SIZE * 43.30f);
                this->missionCircle.setPosition(TILE_SIZE * 24.f, TILE_SIZE * 376.f);
                break;

            case 2:
                std::cout << "2" << std::endl;
                missionNumber++;
                this->missionCircle.setPosition(TILE_SIZE * 114.f, TILE_SIZE * 117.f);

                break;
            case 3:
                std::cout << "3" << std::endl;
                missionNumber++;
                this->missionCircle.setPosition(TILE_SIZE * 147.f, TILE_SIZE * 366.f);

                break;
            case 4:
                std::cout << "4" << std::endl;
                missionNumber++;
                this->missionCircle.setPosition(TILE_SIZE * 122.f, TILE_SIZE * 284.f);

                break;
            case 5:
                std::cout << "5" << std::endl;
                missionNumber++;
                this->missionCircle.setPosition(TILE_SIZE * 20.f, TILE_SIZE * 248.f);
                this->_data->machine.GetActiveState()->Pause();
                this->_data->machine.AddState(StateRef(new Hacking(_data)),false);
                break;
            case 6:
                std::cout << "6" << std::endl;
                missionNumber++;
                this->missionCircle.setPosition(TILE_SIZE * 49.f, TILE_SIZE * 65.f);
                break;
            case 7:
                std::cout << "7" << std::endl;
                missionNumber++;
                this->missionCircle.setPosition(TILE_SIZE * 33.30f, TILE_SIZE * 43.30f);
                break;
            case 8:
                std::cout << "8" << std::endl;
                missionNumber++;
                this->missionCircle.setPosition(TILE_SIZE * 33.30f, TILE_SIZE * 43.30f);
                this->_data->machine.GetActiveState()->Pause();
                this->_data->machine.AddState(StateRef(new Hacking(_data)),false);
                break;

            case 9:
                std::cout << "9" << std::endl;
                missionNumber++;
                this->missionCircle.setPosition(TILE_SIZE * 115.f, TILE_SIZE * 17.f);
                break;

            default:
                break;
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

    void missionPlacement::InfoBoxText(sf::Sprite &player, int &missionNumber) {

        text.setFont(font);

        switch(missionNumber){
            case 1:
                rectangleShape.setSize(sf::Vector2f(800, 320));
                text.setString(" \n"
                        "  The world is running out of Juice\n\n"
                               "  * Please save the Juice.\n\n"
                               "  * Press space to activate mission.\n\n"
                               "  * Steal a car and drive south.\n\n"
                               "  * Find Tony Montana!\n\n");
                break;
            case 2:
                rectangleShape.setSize(sf::Vector2f(800, 240));
                text.setString(" \n"
                               "  * Press 'space 'to activate mission. \n\n"
                               "  * Nice, You found the Tony! \n\n"
                               "  * Get the location of next mission.\n\n"
                               "  * Tony says: drive 'East', find a pc and steal.\n\n");
                break;
            case 3:
                rectangleShape.setSize(sf::Vector2f(800, 100));
                text.setString(" \n"
                               "  * Cross the bridge. \n\n"
                               "  * You seem to be hungry, find a burger \n\n"
                               "  * Eat \n\n");
                break;
            case 4:
                rectangleShape.setSize(sf::Vector2f(800, 50));
                text.setString(" \n"

                               "  * Find hacking mission. \n\n");
                break;
            case 5:
                rectangleShape.setSize(sf::Vector2f(800, 250));
                text.setString(" \n"
                               "  * Locate his hotel.\n\n"
                               "  * Hack Abradolf Lincler's hotel room door password.\n\n");
                break;
            case 6:
                rectangleShape.setSize(sf::Vector2f(800, 250));
                text.setString(" \n"
                               "  * Great! \n\n"
                               "  * Meet Tony again. \n\n"
                               "  * He know's where to find a sniper. \n\n");
                break;
            case 7:
                rectangleShape.setSize(sf::Vector2f(800, 80));
                text.setString(" \n"
                               "  * Find next mission \n\n");
                    break;
            case 8:
                rectangleShape.setSize(sf::Vector2f(800, 400));
                text.setString(" \n"
                               "  * Locate Abradolf's hotel \n\n"
                               "  * Be patience, and wait for him \n\n"
                               "  * Kill that bitch silently! \n\n"
                               "  * Flee the scene \n\n"
                               "  * Meet Tony again");
                break;
            case 9:
                rectangleShape.setSize(sf::Vector2f(800, 250));
                text.setString(" \n"
                               "  * Tony will get you out of the city \n\n"
                               "  * Congratulations 'you saved the Juice' \n\n");
                break;
            default:
                break;
        }

        text.setCharacterSize(22);
        text.setFillColor(sf::Color::Black);
        text.setPosition(player.getPosition().x - 400, player.getPosition().y + 400);
    }



}