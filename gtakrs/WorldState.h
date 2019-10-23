#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"
#include "DEFINITIONS.h"

namespace GTA{
    class WorldState : public  State{
    public:

        ///Movement
        int WalkCounterForward = 0, WalkCounterBackward = 5, SpriteSpeed = 0;

        /// Speed Controller
        const  float WalkSpeed = 1.f;
        const float rotateAmount = 300.f;
        float currentSpeed = 0.f;

        ///consts are units per second as each value is multiplied by frame time
        const float acceleration = 100.f;
        const float deceleration = 1000.f;
        const float maxSpeed = 800.f;
        const float  run = 0.f;

        ///some movement values
        sf::Vector2f movementVec; ///normal vector based on current direction


        explicit WorldState(GameDataRef data);

        void Init() override;

        void HandleInput() override;
        void Update(float dt) override;
        void Draw( float dt) override;
        void Running();

    private:
        GameDataRef _data;

        sf::Sprite _background;
        sf::Sprite _player;
    };
}