#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "DEFINITIONS.h"
#include "State.h"
#include "Game.h"
#include "Map.h"
#include "colliderTest.h"
#include "Movement.h"
#include "Npv.h"
#include "Npc.h"
#include "Collision_Detection.h"
#include "Player.h"
#include "missionPlacement.h"

namespace GTA {
    class WorldState : public State {
    public:

        Map map;
        Movement movement;
        NpcController npcController;
        CarController carController;

       ///TODO: PUT IN AUDIO FROM ASSETMANAGER

        Player _player;
        missionPlacement msp;

        const float dt = 0.01f;
        float WalkSpeed = 1.f;
        bool Driving = false;
        bool Debug = false;
        bool Minimap = false;
        bool mission = false;
        bool NoDrivingOrWalkingBool = false;

        int NoDrivingOrWalkingArray[4]={0, 9, 11, 12};
        int NoDrivWalkInt;
        int collisionReach = 5;
        int fromX = 0, toX = 0;
        int fromY = 0, toY = 0;
        int mPosX, mPosY;

        int playerStartPosX;
        int playerStartPosY;
        int  X, Y;

        explicit WorldState(GameDataRef data);
        void Init() override;
        void HandleInput() override;
        void Update(float dt) override;
        void Draw(float dt) override;
        void UpdateView(const float &dt);
        void UpdateMovement(sf::Sprite &, sf::Sprite &);
        void playerCrashTEMP();

        friend class Map;

    private:
        /// Create a new sprite
        Collision_Detection collisionDetaction;
        std::vector<sf::Sprite *> spriteListy;
        GameDataRef _data;
        sf::View view;
        sf::View minimap;
        sf::RectangleShape getRektMap;
        sf::Vector2f viewCenter;

        sf::Sprite _car;
        sf::Sprite _car2;
        sf::Sprite _car3;

    };
}