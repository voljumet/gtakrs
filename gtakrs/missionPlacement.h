
#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "map"
#include "State.h"
#include "Game.h"

namespace GTA{
    class missionPlacement{

    public:
//        explicit missionPlacement(GameDataRef data);
        typedef std::shared_ptr<GTA::GameData> GameDataRef;

        missionPlacement();


        void initCoin();
        void activate();

        virtual ~missionPlacement();


    private:
        GameDataRef _data;
        sf::CircleShape missionCircle;
    public:
        const sf::CircleShape &getMissionCircle() const;

    };
}


