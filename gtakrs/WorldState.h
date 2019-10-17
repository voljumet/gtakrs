#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"
#include "DEFINITIONS.h"

namespace GTA{
    class WorldState : public  State{
    public:

        //Movement
        int WalkCounter = 0, SpriteSpeed = 0;
        // Speed Controller
        const  float WalkSpeed = 1.f;
        const float rotateAmount = 150.f;
        float currentSpeed = 0.f;

        //consts are units per second as each value is multiplied by frame time
        const float acceleration = 100.f;
        const float deceleration = 1000.f;
        const float maxSpeed = 800.f;
        const float  run = 0.f;

        //sf::Clock deltaClock, frameClock;

        //some movement values
        sf::Vector2f movementVec; //normal vector based on current direction





        double oldx = 0, x = (SCREEN_WIDTH/2);
        double oldy = 0, y = (SCREEN_HEIGHT/2);

        explicit WorldState(GameDataRef data);

        void Init() override;

        void HandleInput() override;
        void Update(float dt) override;
        void Draw( float dt) override;

    private:
        GameDataRef _data;

        sf::Sprite _background;

        sf::Sprite _player;
    };
}