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

        void initCoin();
        void missionSnipe(GameDataRef data_inn, Player player);
        void missionHack(GameDataRef data_inn, Player player);


    private:
        GameDataRef _data;
        sf::Sprite missionCircle;
        sf::Texture texture;

    public:
       sf::Sprite getMissionCircle();

    };
}


