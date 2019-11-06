#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Movement {
public:
    Movement();
    float dt = 0.01f;
    /// Speed / Movement Controller
    float WalkSpeed = 1.f;
    float rotateAmount = 150.f;
    float currentSpeed = 0.f;
    int WalkCounterForward = 0, SpriteSpeed = 0;


    ///Car variables /  Driving variables

    bool up = false;
    bool CanDriveForward = true;
    float acceleration = 25.f;
    const float deceleration = 25.f;
    const float maxSpeed = 1500.f;

     sf::Vector2f movementVec; ///normal vector based on current direction
     sf::Vector2f forwardVec(); //normal vec pointing forward

    void Walk(sf::Sprite&);
    void Drive(sf::Sprite&);


};
