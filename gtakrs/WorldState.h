#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "DEFINITIONS.h"
#include "State.h"
#include "Game.h"
#include "Map.h"
#include "colliderTest.h"
#include "Movement.h"
#include "NpcCar.h"
#include "Npc.h"
#include "Weapon.h"
#include "Collision_Detaction.h"


namespace GTA {
    class WorldState : public State {
    public:

        Map map;
        Movement movement;
        Weapon weapon;

        std::vector<NpcCar*> npcCarVec;
        std::vector<Npc*> npcVec;

        const float dt = 0.01f;
        float WalkSpeed = 1.f;
        bool Driving = false;
        bool Debug = false;
        bool Minimap = false;
        bool NoDrivingOrWalkingBool = false;

        int NoDrivingOrWalkingArray[4]={0, 9, 11, 12};
        int NoDrivWalkInt;

        int playerStartPosX;
        int playerStartPosY;


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

        sf::Sprite _player;
        sf::Sprite _car;
        sf::Sprite _car2;
        sf::Sprite _car3;
    };
}