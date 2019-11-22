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


namespace GTA{
    class missionPlacement{

    public:
        typedef std::shared_ptr<GTA::GameData> GameDataRef;

        missionPlacement();
        virtual ~missionPlacement();

//        bool mission = false;

        void initCoin();
        void activate(bool mission, Player player);


    private:
        GameDataRef _data;
        sf::Sprite missionCircle;
        sf::Vector2f PlayerPos;
        sf::Vector2f misnCircle;
        sf::Texture texture;

    public:
       sf::Sprite getMissionCircle();

    };
}


