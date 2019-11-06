#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"
#include "DEFINITIONS.h"
#include "Audio.h"
#include "Map.h"
#include <vector>
#include "TileMap.h"
#include "collisionTest.h"
#include "colliderTest.h"
#include "Movement.h"

namespace GTA {
    class WorldState : public State {
    public:


        Map map;
        Audio audio; //i create the object here so that i can use sounds in worldstate.cpp
        Movement movement;
        bool Driving = true;
        explicit WorldState(GameDataRef data);

        void Init() override;

        void HandleInput() override;

        void Update(float dt) override;

        void Draw(float dt) override;

        void UpdateView(const float &dt);

        void UpdateMovement(sf::Sprite &, sf::Sprite &);

        Collider GetCollider_car_2() { return Collider(_car2); }

        Collider GetCollider_car() { return Collider(_car); }

        Collider GetCollider_car3() { return Collider(_car3); }

        Collider GetCollider_player() { return Collider(_player); }


    private:

        /// Create a new sprite
        std::vector<sf::Sprite *> spriteListy;
        GameDataRef _data;
        sf::View view;
        int MapArray[MAP_SIZE_HEIGHT * MAP_SIZE_WIDTH];

        TileMap _map;

        sf::Sprite _player;
        sf::Sprite _car;
        sf::Sprite _car2;
        sf::Sprite _car3;

    };
}