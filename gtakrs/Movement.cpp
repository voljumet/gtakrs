#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Transform.hpp>

#include "Movement.h"

namespace GTA{
    Movement::Movement(){}

    sf::Vector2f Movement::forwardVec() {
        return sf::Vector2f(0.f, -WalkSpeed);
    }

    void Movement::Drive(sf::Sprite& driver) {
        if (up) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) { driver.rotate(-rotateAmount * dt); }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { driver.rotate(rotateAmount * dt); }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            up = true;
            currentSpeed -= deceleration * 2;
            if (currentSpeed < maxSpeed / 10)
                currentSpeed = -maxSpeed / 5;
            sf::Transform t;
            t.rotate(driver.getRotation());
            movementVec = t.transformPoint( Movement::forwardVec());


        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
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

    void Movement::Walk(sf::Sprite& walker) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            walker.rotate(-rotateAmount * dt);

        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            walker.rotate(rotateAmount * dt);

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            walker.setTextureRect(sf::IntRect(0, WalkCounterForward * 110, 100, 110));
            if (currentSpeed < maxSpeed) {
                currentSpeed = 100;
            }
            sf::Transform t;
            t.rotate(walker.getRotation());
            movementVec = t.transformPoint(-Movement::forwardVec());
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {

            walker.setTextureRect(sf::IntRect(0, WalkCounterForward * 110, 100, 110));
            if (currentSpeed < maxSpeed) {
                currentSpeed = 300;
            }
            sf::Transform t;
            t.rotate(walker.getRotation());
            movementVec = t.transformPoint(Movement::forwardVec());

        } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)){
            walker.setTextureRect(sf::IntRect(0, WalkCounterForward * 150, 100, 110));
            if(currentSpeed == maxSpeed){
                currentSpeed = 600;
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
            WalkCounterForward++;
            SpriteSpeed = 0;
        }

        if (WalkCounterForward == 5)
            WalkCounterForward = 1;
    }
}
