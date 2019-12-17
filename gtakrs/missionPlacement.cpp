#pragma once

#include "missionPlacement.h"
#include <utility>

namespace GTA{

    missionPlacement::~missionPlacement() = default;

    missionPlacement::missionPlacement(){
        this->texture.loadFromFile( MISSION_CIRCLE_SPRITE);
        this->missionCircle.setTexture(texture);
        this->missionCircle.setPosition(TILE_SIZE * 20, TILE_SIZE * 21);
        this->missionCircle.setTextureRect(sf::IntRect(0,0,100, 100));
        this->missionCircle.setScale(2.f, 2.f);
        this->missionCircle.setOrigin(50.f, 67.f);

        this->textureMini.loadFromFile( MISSION_CIRCLE_SPRITE2);
        this->missionCircleMini.setTexture(textureMini);
        this->missionCircleMini.setPosition(TILE_SIZE * 20, TILE_SIZE * 21);
        this->missionCircleMini.setTextureRect(sf::IntRect(0,0,100, 100));
        this->missionCircleMini.setScale(2.f, 2.f);
        this->missionCircleMini.setOrigin(50.f, 67.f);

        this->boatCircleIsland.setTexture(texture);
        this->boatCircleIsland.setPosition(TILE_SIZE * 182, TILE_SIZE * 65);
        this->boatCircleIsland.setTextureRect(sf::IntRect(0,0,100, 100));
        this->boatCircleIsland.setScale(2.f, 2.f);
        this->boatCircleIsland.setOrigin(50.f, 67.f);

        this->boatCircle.setTexture(texture);
        this->boatCircle.setPosition(TILE_SIZE * 120, TILE_SIZE * 117);
        this->boatCircle.setTextureRect(sf::IntRect(0,0,100, 100));
        this->boatCircle.setScale(2.f, 2.f);
        this->boatCircle.setOrigin(50.f, 67.f);

        if (!font.loadFromFile(RETRO)){ std::cout << "Cant load font from resources!" << std::endl; }
    }

    void missionPlacement::missionStart(GameDataRef data_inn, Player &player,
            int &missionNumber, sf::Sprite &playerPos, bool boat) {
        _data = std::move(data_inn);

        switch (missionNumber){
            case 1:
                missionNumber++;
                player.setCoin();
                this->missionCircle.setPosition(TILE_SIZE * 24.f, TILE_SIZE * 376.f);
                break;

            case 2:
                missionNumber++;
                player.setCoin();
                this->missionCircle.setPosition(TILE_SIZE * 111.f, TILE_SIZE * 21.f);
                break;
            case 3:
                player.Damage(100);
                missionNumber++;
                player.setCoin();
                this->missionCircle.setPosition(TILE_SIZE * 148.f, TILE_SIZE * 366.f);
                break;
            case 4:
                missionNumber++;
                player.setCoin();
                this->missionCircle.setPosition(TILE_SIZE * 121.f, TILE_SIZE * 286.f);
                break;
            case 5:
                missionNumber++;
                player.setCoin();
                this->missionCircle.setPosition(TILE_SIZE * 20.f, TILE_SIZE * 248.f);
                this->_data->machine.GetActiveState()->Pause();
                this->_data->machine.AddState(StateRef(new Hacking(_data)),false);
                break;
            case 6:
                missionNumber++;
                player.setCoin();
                this->missionCircle.setPosition(TILE_SIZE * 49.30f, TILE_SIZE * 66.30f);
                break;
            case 7:
                missionNumber++;
                player.setCoin();
                this->missionCircle.setPosition(TILE_SIZE * 88.30f, TILE_SIZE * 216.30f);
                this->_data->machine.GetActiveState()->Pause();
                this->_data->machine.AddState(StateRef(new Mission(_data)),false);
                break;
            case 8:
                missionNumber++;
                player.setCoin();
                this->missionCircle.setPosition(TILE_SIZE * 116.f, TILE_SIZE * 117.f);
                break;
            case 9:
                missionNumber++;
                player.setCoin();
                this->missionCircle.setPosition(TILE_SIZE * 116.f, TILE_SIZE * 117.f);
                break;
            case 10:
                missionNumber++;
                player.setCoin();
                this->missionCircle.setPosition(TILE_SIZE * 172.f, TILE_SIZE * 42.f);
                break;
            case 11:
                missionNumber++;
                player.setCoin();
                break;
            default:
                break;
        }
        this->missionCircleMini.setPosition(missionCircle.getPosition());
    }

    void missionPlacement::InfoBox(sf::Sprite &player, sf::Vector2f boatPos, int &missionNumber, bool &boat) {
        rectangleShape.setSize(sf::Vector2f(800, 250));
        rectangleShape.setOutlineColor(sf::Color::Red);
        rectangleShape.setOutlineThickness(5);
        text.setCharacterSize(22);
        text.setFillColor(sf::Color::Black);
        text.setFont(font);

        if(boat){ text.setPosition(boatPos.x - 400, boatPos.y + 400);
            rectangleShape.setPosition(boatPos.x - 400, boatPos.y + 400);
        } else { text.setPosition(player.getPosition().x - 400, player.getPosition().y + 400);
            rectangleShape.setPosition(player.getPosition().x - 400, player.getPosition().y + 400);
        }

        switch (missionNumber) {
            case 1:
                rectangleShape.setSize(sf::Vector2f(700, 260));
                text.setString(" \n"
                               "  - This is your first mission,\n"
                               "    you will be able to accept and complete \n"
                               "    missions in the red cicles!\n\n"

                               "  - Steal a car and drive south-west over\n"
                               "    the bridge to find Mony Banana.\n\n"

                               "  -Press 'space' to accept and start missions-\n");

                break;
            case 2:
                rectangleShape.setSize(sf::Vector2f(820, 380));
                text.setString(" \n"
                               "  - Abradolf Linkler is trying to bomb\n"
                               "    our city, we need to take him down\n"
                               "    before he manages to do so! \n\n"

                               "  - Hack and retrive his password, \n"
                               "    then find his location. \n"
                               "  - But first you need to find a pc,\n"
                               "    drive north-east over the bridge to find it \n");
                break;
            case 3:
                rectangleShape.setSize(sf::Vector2f(800, 180));
                text.setString(" \n"
                               "  - Find a pc in the city\n"
                               "    then cross the bridge again and drive \n"
                               "    south-east to find the right place to use it.\n");
                break;
            case 4:
                rectangleShape.setSize(sf::Vector2f(800, 200));
                text.setString(" \n"
                               "  - Missions are exhausting, and your health \n"
                               "    seems to be low, find a burger to eat. \n"
                               "  - Next objective is two blocks north from here\n");
                break;
            case 5:
                rectangleShape.setSize(sf::Vector2f(800, 200));
                text.setString(" \n"
                               "  - Hack Abradolf's computer\n"
                               "    and find his location\n"
                               "    Meet Mony west of the city after.\n");
                break;
            case 6:
                rectangleShape.setSize(sf::Vector2f(800, 280));
                text.setString(" \n"
                               "  - You're a Genius! \n"
                               "    and we're close to getting him now.\n"
                               "  - Find a tall building so you \n"
                               "    can take him down with a sniper,\n"
                               "    look north-west after a good place, \n"
                               "    remember to grab a sniper on the way.\n"
                               "  - It can be found around here!\n\n");
                break;
            case 7:
                rectangleShape.setSize(sf::Vector2f(800, 260));
                text.setString(" \n"
                               "  - Find him in one of the buildings\n"
                               "    and take him down!\n"
                               "  - Meet Tony afterwards\n"
                               "    he's at south-side of the first block\n"
                               "    after crossing the bridge.\n\n");
                break;
            case 8:
                rectangleShape.setSize(sf::Vector2f(800, 220));
                text.setString(" \n"
                               "  - Grab the boat key from Tony\n"
                               "    and hurry to the dock, \n"
                               "    cross the bridge to the north\n"
                               "    and find the boat around east");
                break;
            case 9:
                rectangleShape.setSize(sf::Vector2f(800, 120));
                text.setString(" \n"
                               "  - Take the boat and get to the island  \n"
                               "    north-west of here! \n\n");
                break;

            case 10:
                rectangleShape.setSize(sf::Vector2f(800, 60));
                text.setString(" \n"
                               "  - Time for vacation after saving the city! \n"
                               "    And thanks's for playing! \n\n");
                break;
            case 11:
                break;
            default:
                break;
        }
    }


    sf::Text missionPlacement::getText() { return text; }
    sf::RectangleShape missionPlacement::getBox() { return rectangleShape; }
    sf::Sprite missionPlacement::getMissionCircle(){ return missionCircle; }
    sf::Sprite missionPlacement::getMissionCircleMini() { return missionCircleMini; }
    sf::Sprite missionPlacement::getBoatCircle() { return boatCircle; }
    sf::Sprite missionPlacement::getBoatCircleIsland() { return boatCircleIsland; }

    void missionPlacement::infoBoxBoat(sf::Sprite &player, bool &boat, sf::Vector2f boatPos) {
        rectangleShape.setSize(sf::Vector2f(800, 250));
        rectangleShape.setOutlineColor(sf::Color::Red);
        rectangleShape.setOutlineThickness(5);

        text.setFont(font);
        if(boat){
            rectangleShape.setPosition(boatPos.x - 400, boatPos.y + 400);
            text.setPosition(boatPos.x - 400, boatPos.y + 400);
            rectangleShape.setSize(sf::Vector2f(800, 60));
            text.setString("\n  Press space to leave boat \n");
        } else {
            rectangleShape.setPosition(player.getPosition().x - 400, player.getPosition().y + 400);
            text.setPosition(player.getPosition().x - 400, player.getPosition().y + 400);
            rectangleShape.setSize(sf::Vector2f(800, 60));
            text.setString("\n  Press space to enter boat \n");
        }
        text.setCharacterSize(22);
        text.setFillColor(sf::Color::Black);
    }

    void missionPlacement::BoatCircle(bool &boat) {
        if (boat){
            this->boatCircle.setPosition(TILE_SIZE * 125.f, TILE_SIZE * 121.f);
            this->boatCircleIsland.setPosition(TILE_SIZE * 185.f, TILE_SIZE * 65.f);
        } else {
            this->boatCircle.setPosition(TILE_SIZE * 120, TILE_SIZE * 117);
            this->boatCircleIsland.setPosition(TILE_SIZE * 182, TILE_SIZE * 65);
        }
    }

}