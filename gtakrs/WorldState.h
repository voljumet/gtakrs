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
#include "objectSpawn.h"


namespace GTA {
    class WorldState : public State {
    public:
        Map map;
        Movement movement;
        NpcController npcController;
        NpvController npvController;
        Shooting shooting;
        Weapon weapon;
        objectSpawn objectSpawn;
        AssetManager sound;


        Player _player;
        missionPlacement missionPlacement;

        const float dt = 0.01f;
        bool Driving = false;
        bool Debug = false;
        bool Minimap = false;
        bool mission = false;

        /// IKKE SLETT !!!! ------------
        bool NULLER = false;
        /// _____________________________
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
        void UpdateMovement(GameDataRef  &inn_data, sf::Sprite &, sf::Sprite &);
        void playerCrashTEMP();
        void PrintTimer();
        void loadAllTexture();

        friend class Map;

    private:
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

        Collision_Detection collisionDetection;
        GameDataRef _data;
        sf::View view;
        sf::View minimap;
        sf::RectangleShape getRektMap;

        sf::Texture M3_White;

        sf::Texture player1;
        sf::Sprite Boat;
        sf::Sprite _car;
    };
}