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

    void missionPlacement::missionStart(GameDataRef data_inn, Player &player,
            int &missionNumber, sf::Sprite &playerPos) {
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
                this->missionCircle.setPosition(TILE_SIZE * 111.f, TILE_SIZE * 21.f);

                break;
            case 3:
                std::cout << "3" << std::endl;
                missionNumber++;
                this->missionCircle.setPosition(TILE_SIZE * 147.f, TILE_SIZE * 366.f);

                break;
            case 4:
                std::cout << "4" << std::endl;
                missionNumber++;
                this->missionCircle.setPosition(TILE_SIZE * 121.f, TILE_SIZE * 285.f);

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
                rectangleShape.setSize(sf::Vector2f(700, 260));
                text.setString(" \n"
                               "  Mission: \n\n"
                               "  * Find Tony Montana!\n"
                               "  * Steal a car and drive south.\n"
                               "  * Cross bridge, and continue South-West\n\n"
                               "  * Press space to activate mission.\n\n");


                break;
            case 2:
                rectangleShape.setSize(sf::Vector2f(820, 400));
                text.setString(" \n"
                               "  Tony 'Hello Trevor!' \n\n"
                               "    The world is running out of Juice. \n"
                               "    We need to save it,  \n"
                               "    before Abradolf drinks it empty.\n"
                               "  * Your objective is to: \n\n"
                               "  * Hack Abradolf Lincler's password, \n"
                               "  * to find his location. \n"
                               "  * But first you need to find a Pc\n"
                               "  * Cross the bridge north \n"
                               "  * Drive 'North-East'\n\n");
                break;
            case 3:
                rectangleShape.setSize(sf::Vector2f(800, 180));
                text.setString(" \n"
                               "  * Find a pc \n"
                               "  * You can find one around the dock\n"
                               "  * Cross the bridge again \n"
                               "  * Next mission should be around South-East\n");
                break;
            case 4:
                rectangleShape.setSize(sf::Vector2f(800, 200));
                text.setString(" \n"
                               "  * Your health seems to be low!\n"
                               "  * Find a burger to eat. \n"
                               "  * Should be some burgers to eat around here. \n"
                               "  * Next objective is two blocks north!\n");
                break;
            case 5:
                rectangleShape.setSize(sf::Vector2f(800, 200));
                text.setString(" \n"
                               "  Hack Abradolf's \n"
                               "  * Cell phone.\n"
                               "  * Find his location\n"
                               "  * Meet Tony west of the city\n");
                break;
            case 6:
                rectangleShape.setSize(sf::Vector2f(800, 250));
                text.setString(" \n"
                               "  * You're a Genius! \n"
                               "  * We 're close to get him \n"
                               "  * Find next mission around north-west\n"
                               "  * Find a sniper before you go\n"
                               "  * A sniper can be found around here!\n");
                break;

            case 7:
                rectangleShape.setSize(sf::Vector2f(800, 200));
                text.setString(" \n"
                               "  * Locate his hotel \n"
                               "  * Wait for him to show up!\n"
                               "  * Snipe him\n"
                               "  * Meet Tony afterwards\n"
                               "  * Tony can be found by crossing the bridge\n"
                               "  * and continuing south-west\n\n");
                    break;
            case 8:
                rectangleShape.setSize(sf::Vector2f(800, 400));
                text.setString(" \n"
                               "  * Tony's got the boat keys\n"
                               "  * Hurry to the docks \n"
                               "  * Locate the boat\n"
                               "  * Flee to the island\n");
                break;
            case 9:
                rectangleShape.setSize(sf::Vector2f(800, 250));
                text.setString(" \n"
                               "  * Congratulations 'you saved the Juice' \n"
                               "  * Thanks's for playing!");
                break;
            default:
                break;
        }

        text.setCharacterSize(22);

        text.setFillColor(sf::Color::Black);
        text.setPosition(player.getPosition().x - 400, player.getPosition().y + 400);
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


}