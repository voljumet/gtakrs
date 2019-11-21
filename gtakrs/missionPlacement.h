#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics.hpp>
#include "MainMenuState.h"
#include "iostream"
#include "Npc.h"


namespace GTA{
    class missionPlacement{

    public:
       // explicit missionPlacement(GameDataRef data);
        typedef std::shared_ptr<GTA::GameData> GameDataRef;

        missionPlacement();
        virtual ~missionPlacement();

        bool mission = false;

        void initCoin();
        void activate(Npc npc);


    private:
        GameDataRef _data;
        sf::CircleShape missionCircle;

    public:
        const sf::CircleShape &getMissionCircle() const;

    };
}


