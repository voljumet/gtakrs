#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "DEFINITIONS.h"
#include "State.h"
#include "Game.h"
#include "Map.h"
#include "colliderTest.h"
#include "Movement.h"
#include "Npc.h"
#include "Collision_Detaction.h"
#include "Player.h"


namespace GTA {
    class WorldState : public State {
    public:

        Map map;
        Movement movement;
       ///TODO: PUT IN AUDIO FROM ASSETMANAGER
        Npc nonpc;
        Player player;


        const float dt = 0.01f;
        float WalkSpeed = 1.f;
        bool Driving = false;
        bool Debug = false;
        bool Minimap = false;


        explicit WorldState(GameDataRef data);
        void Init() override;
        void HandleInput() override;
        void Update(float dt) override;
        void Draw(float dt) override;
        void UpdateView(const float &dt);
        void UpdateMovement(sf::Sprite &, sf::Sprite &);


        friend class Map;

    private:
        /// Create a new sprite
        Collision_Detaction collisionDetaction;
        std::vector<sf::Sprite *> spriteListy;
        GameDataRef _data;
        sf::View view;
        sf::View minimap;
        sf::Vector2f viewCenter;

//        sf::Sprite _player;
        sf::Sprite _car;
        sf::Sprite _car2;
        sf::Sprite _car3;

    };
}