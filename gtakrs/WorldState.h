#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "DEFINITIONS.h"
#include "State.h"
#include "Game.h"
#include "Audio.h"
#include "Map.h"
#include "collisionTest.h"
#include "colliderTest.h"
#include "Movement.h"


namespace GTA {
    class WorldState : public State {
    public:

        Map map;
        Movement movement;
        Audio audio; ///this creates the audio object so that sounds can be used in worldstate.cpp

        const float dt = 0.01f;
        float WalkSpeed = 1.f;
        bool Driving = true;
        bool debug = false;

        int fromX = 0, toX = 0;
        int fromY = 0, toY = 0;
        int posX, posY;

        explicit WorldState(GameDataRef data);
        void Init() override;
        void HandleInput() override;
        void Update(float dt) override;
        void Draw(float dt) override;
        void UpdateView(const float &dt);
        void UpdateMovement(sf::Sprite &, sf::Sprite &);
        void MapRendering();

        Collider GetCollider_car_2() { return Collider(_car2); }
        Collider GetCollider_car() { return Collider(_car); }
        Collider GetCollider_car3() { return Collider(_car3); }
        Collider GetCollider_player() { return Collider(_player); }

    private:
        /// Create a new sprite
        std::vector<sf::Sprite *> spriteListy;
        GameDataRef _data;
        sf::View view;
        sf::View minimap;

        sf::Sprite _player;
        sf::Sprite _car;
        sf::Sprite _car2;
        sf::Sprite _car3;
    };
}