#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"
#include "DEFINITIONS.h"
#include "Collider.h"
#include <vector>
#include "CollitsionTest.h"


namespace GTA{
    class WorldState : public  State{
    public:

        const float dt = 0.01f;
        int WalkCounter = 0, SpriteSpeed = 0;

        /// Speed / Movement Controller
          float WalkSpeed = 1.f;
        const float rotateAmount = 150.f;
        float currentSpeed = 0.f;


        ///Car variables /  Driving variables
        bool Driving = true;
        bool Enter = false;
        bool up = false;
        float acceleration = 25.f;
        const float deceleration = 25.f;
        const float maxSpeed = 1500.f;



        sf::Vector2f movementVec; ///normal vector based on current direction





        double oldx = 0, x = (SCREEN_WIDTH/2);
        double oldy = 0, y = (SCREEN_HEIGHT/2);

        explicit WorldState(GameDataRef data);
        void Init() override;
        void HandleInput() override;
        void Update(float dt) override;
        void Draw( float dt) override;







    private:
        /// Create a new sprite
        std::vector<sf::Sprite*> spriteListy;
        GameDataRef _data;
        sf::Sprite _background;
        sf::Sprite _player;
        sf::Sprite _car;
        sf::Sprite _car2;
        sf::Sprite _car3;
        sf::RectangleShape _car4;
        /*
        Collider GetCollider_car() { return Collider(_car);}
        Collider GetCollider_player() { return Collider(_player);}
        Collider GetCollider_background() { return Collider(_background);}
         */

    };
}