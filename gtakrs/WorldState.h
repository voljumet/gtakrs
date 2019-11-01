#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"
#include "DEFINITIONS.h"
#include "Audio.h"

#include <vector>

#include "TileMap.h"
#include "collisionTest.h"
#include "colliderTest.h"
#include "Movement.h"
class check_collision;


namespace GTA{
    class WorldState : public  State{
    public:

        Audio audio; //i create the object here so that i can use sounds in worldstate.cpp
        Movement movement;


        bool Driving = true;

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


        bool check_collision(const sf::Sprite & other, float push);


        Collider GetCollider_car_2() { return Collider(_car2);}
        Collider GetCollider_car() { return Collider(_car);}
        Collider GetCollider_car3() { return Collider(_car3);}
        Collider GetCollider_player() { return Collider(_player);}








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