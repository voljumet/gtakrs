//
// Created by Peshang Alo on 01/11/2019.
//

#ifndef GTAKRS_MOVEMENT_H
#define GTAKRS_MOVEMENT_H


#include <SFML/Audio.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Movement {
public:
    Movement();
    friend class WorldState;
    float dt = 0.01f;
    /// Speed / Movement Controller
    float WalkSpeed = 1.f;
    float rotateAmount = 150.f;
    float currentSpeed = 0.f;
    int WalkCounterForward = 0, SpriteSpeed = 0, SpriteSpeedBa = 0;
    int WalkCounterBackward = 5;


    ///Car variables /  Driving variables

    bool Enter = false;
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


#endif //GTAKRS_MOVEMENT_H
