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

        typedef std::shared_ptr<GTA::GameData> GameDataRef;
    public:

        missionPlacement();
        virtual ~missionPlacement();

        void missionStart(GameDataRef data_inn, Player &player, int &missionNumber, sf::Sprite &playerPos, bool boat);
        void InfoBox(sf::Sprite &player, sf::Vector2f boatPos, int &missionNumber, bool &boat);
        void infoBoxBoat(sf::Sprite &player, bool &boat, sf::Vector2f boatPos);
        void BoatCircle(bool &boat);

        sf::Sprite getMissionCircle();
        sf::Sprite getBoatCircle();
        sf::Sprite getBoatCircleIsland();
        sf::Sprite getMissionCircleMini();
        sf::RectangleShape getBox();
        sf::Text getText();
    };
}


