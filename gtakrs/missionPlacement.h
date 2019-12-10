#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics.hpp>
#include "MainMenuState.h"
#include "iostream"
#include "Player.h"
#include "DEFINITIONS.h"
#include "colliderTest.h"
#include "Mission.h"
#include "Hacking.h"

namespace GTA{
    class missionPlacement{

    public:
        typedef std::shared_ptr<GTA::GameData> GameDataRef;

        missionPlacement();
        virtual ~missionPlacement();

        void hackMissionSettings();
        void missionStart(GameDataRef data_inn, Player &player, int &missionNumber, sf::Sprite &playerPos);
        void infoBox(sf::Sprite &player, int &missionNumber);
        void InfoBoxText(sf::Sprite &player, int &missionNumber);


    private:
        GameDataRef _data;
        sf::Sprite missionCircle;
        sf::Texture texture;
        sf::RectangleShape rectangleShape;
        sf::Text text;
        sf::Font font;

    public:
       sf::Sprite getMissionCircle();
       sf::RectangleShape getBox();
       sf::Text getText();
    };
}


