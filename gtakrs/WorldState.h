#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "DEFINITIONS.h"
#include "State.h"
#include "Game.h"
#include "Audio.h"
#include "Map.h"
#include "TileMap.h"
#include "collisionTest.h"
#include "colliderTest.h"

namespace GTA{
    class WorldState : public  State{
    public:
        Map map;

        Audio audio; ///this creates the audio object so that sounds can be used in worldstate.cpp

        const float dt = 0.01f;
        int WalkCounterForward = 0, SpriteSpeed = 0;

        /// Speed / Movement Controller
        float WalkSpeed = 1.f;
        const float rotateAmount = 150.f;
        float currentSpeed = 0.f;

        ///Car variables /  Driving variables
        bool Driving = true;
        bool up = false;
        float acceleration = 25.f;
        const float deceleration = 25.f;
        const float maxSpeed = 1500.f;

        bool debug = false;

        sf::Vector2f movementVec; ///normal vector based on current direction

        explicit WorldState(GameDataRef data);
        void Init() override;
        void HandleInput() override;
        void Update(float dt) override;
        void Draw( float dt) override;
        void UpdateView(const float& dt);

        bool CanDriveForward = true;

        Collider GetCollider_car_2() { return Collider(_car2);}
        Collider GetCollider_car() { return Collider(_car);}
        Collider GetCollider_car3() { return Collider(_car3);}
        Collider GetCollider_player() { return Collider(_player);}

    private:

        /// Create a new sprite
        std::vector<sf::Sprite*> spriteListy;

        GameDataRef _data;
        sf::View view;

        sf::Sprite _player;
        sf::Sprite _car;
        sf::Sprite _car2;
        sf::Sprite _car3;

    };
}