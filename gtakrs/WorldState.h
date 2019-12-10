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
#include "Shooting.h"
#include "Weapon.h"
#include "AssetManager.h"


namespace GTA {
    class WorldState : public State {
    public:

        Npv npv;
        Map map;
        Movement movement;
        NpcController npcController;
        CarController carController;
        Shooting shooting;
        Weapon weapon;
        AssetManager sound;

       ///TODO: PUT IN AUDIO FROM ASSETMANAGER

        Player _player;
        missionPlacement msp;
        missionPlacement missionPlacement;

        const float dt = 0.01f;
        float WalkSpeed = 1.f;
        bool Driving = false;
        bool Debug = false;
        bool Minimap = false;
        bool mission = false;
        bool NULLER = false;
        bool NoDrivingOrWalkingBool = false;
        bool nocruising = false;

        bool boatbool = false;

        int missionNumber = 1;


        int BOATCan_Not_MoveHere[24]={0, 1, 2, 3, 4, 6, 7, 8, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24};

        int NoDrivingOrWalkingArray[4]={0, 9, 11, 12};

        int NoDrivWalkInt;
        int collisionReach = 5;
        int fromX = 0, toX = 0;
        int fromY = 0, toY = 0;
        int mPosX, mPosY;
        int drawtimerNPC;
        int drawtimerNPV;

        int playerStartPosX;
        int playerStartPosY;
        int  X, Y;

        explicit WorldState(GTA::GameDataRef data);
        void Init() override;
        void HandleInput() override;
        void Update(float dt) override;
        void Draw(float dt) override;
        void UpdateView(const float &dt);
        void UpdateMovement(sf::Sprite &, sf::Sprite &);
        void playerCrashTEMP();
        void PrintTimer();

        friend class Map;

    private:
        /// Create a new sprite

        std::clock_t Timer;
        int timer=0;
        double NPCMoveDura;
        double NPVMoveDura;
        double PlayDura;
        double MapDura;
        double MmapDura;
        double NPCDura;
        double NPVDura;
        double NullDura;

        Collision_Detection collisionDetaction;
        std::vector<sf::Sprite *> spriteListy;
        GameDataRef _data;
        sf::View view;
        sf::View minimap;
        sf::RectangleShape getRektMap;
        sf::Vector2f viewCenter;

        sf::Texture M3_White;

        sf::Texture player1;
        sf::Sprite Boat;
        sf::Sprite _car;
        sf::Sprite _car2;
        sf::Sprite _car3;

    };
}