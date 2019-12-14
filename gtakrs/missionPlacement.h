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
        void missionStart(GameDataRef data_inn, Player &player, int &missionNumber, sf::Sprite &playerPos, bool boat);
        void infoBox(sf::Sprite &player, int &missionNumber, bool boat);
        void InfoBoxText(sf::Sprite &player, int &missionNumber, bool &boat);
        void Boat(bool boat);


    private:
        GameDataRef _data;
        sf::Sprite missionCircle;
        sf::Sprite missionCircleMini;
        sf::Sprite boatCircleIsland;
        sf::Sprite boatCircle;

        sf::Texture texture;
        sf::Texture textureMini;

        sf::RectangleShape rectangleShape;
        sf::Text text;
        sf::Font font;

    public:
       sf::Sprite getMissionCircle();
        sf::Sprite getMissionCircleMini();
        sf::RectangleShape getBox();
       sf::Text getText();
    };
}


