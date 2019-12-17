#pragma once

#include <SFML/Audio.hpp>
#include "Game.h"
#include <SFML/Graphics/Sprite.hpp>
#include "Collision_Detection.h"

namespace GTA{
    class Movement {
        GameDataRef _data;
        AssetManager sound;

    public:
        Movement();
        float dt = 0.01f;

        /// Speed / Movement Controller
        float WalkSpeed = 1.f;
        float rotateAmountWalk = 250.f;
        float rotateAmountCar = 150.f;

        float currentSpeed = 0.f;
        int walkAnimation = 0, SpriteSpeed = 0;

        ///Car variables /  Driving variables
        bool up = false;
        bool CanDriveForward = true;
        float acceleration = 25.f;
        const float deceleration = 25.f;
        const float maxSpeed = 1500.f;
        int soundCounter = 0;

        sf::Vector2f movementVec; ///normal vector based on current direction
        sf::Vector2f forwardVec(); ///normal vec pointing forward

        void Walk(GameDataRef &inn_data, sf::Sprite&, sf::Sound &footstep);
        void Drive(sf::Sprite&, sf::Sound &teslasound);
    };
}
