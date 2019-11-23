#pragma once

#include <iostream>

#include "Movement.h"
#include "Game.h"
#include "Map.h"
#include "DEFINITIONS.h"
#include "Movement.h"
#include "Collision_Detection.h"
#include "colliderTest.h"

namespace GTA{
    class NPC_NPV : public Movement{
    public:
        int NextPosX,NextPosY;
        int CurrentPosX, CurrentPosY;
        int movementSpeed;
        int moveUp, moveDown, moveRight, moveLeft;
        int NextTile, currentTile;
        int UpdatedPosX, UpdatedPosY;
        int randomColor;
        int StepCounter = 0;
        int RespawnTime = 600;
        int randomPosX, randomPosY, RandNpcTile;
        bool crashCurb, CheckWalkable = false, dead = false;

        int Npc_Can_SpawnHere[10]={15, 16, 17, 18, 19, 20, 21};
        int Npv_Can_SpawnHere[9]={7, 8, 14, 15, 16};

        int NpcCan_Not_MoveHere[14]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 13, 14};
        int NpvCan_Not_MoveHere[18]={1, 2, 3, 4, 0, 5, 6, 9, 10, 11, 12, 17, 18, 19, 20, 21, 22};

        enum direction{UP, DOWN, LEFT, RIGHT} dir;

        direction RandomDir;
        Collision_Detection collisionDetaction;
    };
}