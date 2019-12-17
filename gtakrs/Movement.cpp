#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Transform.hpp>
#include <iostream>

#include "Movement.h"
#include "Game.h"

namespace GTA{
    Movement::Movement(){}

    sf::Vector2f Movement::forwardVec() {
        return sf::Vector2f(0.f, -WalkSpeed);
    }

    void Movement::Drive(sf::Sprite& driver, sf::Sound &tesla) {
        if (up) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { driver.rotate(-rotateAmountCar * dt); }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { driver.rotate(rotateAmountCar * dt); }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            up = true;
            currentSpeed -= deceleration * 2;
            if (currentSpeed < maxSpeed / 10)
                currentSpeed = -maxSpeed / 5;
            sf::Transform t;
            t.rotate(driver.getRotation());
            movementVec = t.transformPoint( Movement::forwardVec());



        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            up = true;
            currentSpeed += acceleration;

            if (currentSpeed >= maxSpeed) {
                currentSpeed = maxSpeed;
            }
            if (CanDriveForward) {
                sf::Transform t;
                t.rotate(driver.getRotation());
                movementVec = t.transformPoint(Movement::forwardVec());
            } else { currentSpeed = 0; }

        } else {
            currentSpeed -= deceleration;
            if (currentSpeed < 10.f) {
                currentSpeed = 0.f;
                up = false;

            }
        }
    }

    void Movement::Walk(GameDataRef &inn_data , sf::Sprite& walker, sf::Sound &footstep) {
        _data = inn_data;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            walker.rotate(-rotateAmountWalk * dt);

        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            walker.rotate(rotateAmountWalk * dt);

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            walker.setTextureRect(sf::IntRect(0, walkAnimation * 110, 100, 110));
            if (currentSpeed < maxSpeed) {
                currentSpeed = 100;
            }
            sf::Transform t;
            t.rotate(walker.getRotation());
            movementVec = t.transformPoint(-Movement::forwardVec());
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {

            walker.setTextureRect(sf::IntRect(0, walkAnimation * 110, 100, 110));
            if (currentSpeed < maxSpeed) {
                currentSpeed = 300;
            }
            sf::Transform t;
            t.rotate(walker.getRotation());
            movementVec = t.transformPoint(Movement::forwardVec());

        } else {
            currentSpeed = 0.f;
            walker.setTextureRect(sf::IntRect(0, 0, 100, 110));
        }

        SpriteSpeed++;
        if (SpriteSpeed == 8) {
            walkAnimation++;
            SpriteSpeed = 0;

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)  ) {
                soundCounter++;
                if(soundCounter==5){
                    sound.PlaySound(footstep);
                    soundCounter = 0;
                }
            }
        }

        if (walkAnimation == 5){
            walkAnimation = 1;
        }
    }
}
