#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"
#include "DEFINITIONS.h"

#include <vector>

#include "TileMap.h"


namespace GTA{
    class WorldState : public  State{
    public:

        const float dt = 0.01f;
        int WalkCounterForward = 0, SpriteSpeed = 0, SpriteSpeedBa = 0;
        int WalkCounterBackward = 5;

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

        /// Loads file for Map
        std::ifstream file;

        explicit WorldState(GameDataRef data);
        void Init() override;
        void HandleInput() override;
        void Update(float dt) override;
        void Draw( float dt) override;
        void Running();
        void Map();
        void UpdateView(const float& dt);








    private:
        /// Create a new sprite
        std::vector<sf::Sprite*> spriteListy;
        GameDataRef _data;
        sf::Sprite _background;
        sf::View view;
        int MapArray[MAP_SIZE_HEIGHT*MAP_SIZE_WIDTH];

        TileMap _map;

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