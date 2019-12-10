#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
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

        int NextPosX = 0,NextPosY= 0;
        int CurrentPosX= 0, CurrentPosY= 0;
        double movementSpeed= 0;
        int moveUp= 0, moveDown= 0, moveRight= 0, moveLeft= 0;
        int spriteHeight= 0, spriteWidth= 0;
        int NextTile= 0, currentTile= 0;
        int UpdatedPosX= 0, UpdatedPosY= 0;
        int randomColor= 0;
        int StepCounter = 0;
        int RespawnTime = 600;
        int randomPosX= 0, randomPosY= 0, RandNpcTile= 0;
        int health= 0;
        bool crashCurb = true, CheckWalkable = false, dead = false;

        int Number = 0;
        int CrashCounter = 0;


        int Npc_Can_SpawnHere[10]={15, 16, 17, 18, 19, 20, 21};
        int Npv_Can_SpawnHere[9]={7, 8, 14, 15, 16};

        int NpcCan_Not_MoveHere[14]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 13, 14};
        int NpvCan_Not_MoveHere[18]={1, 2, 3, 4, 0, 5, 6, 9, 10, 11, 12, 17, 18, 19, 20, 21, 22};

        enum direction{UP, DOWN, LEFT, RIGHT} dir;

        direction RandomDir = UP;
        Collision_Detection collisionDetaction;

        std::clock_t Timer;
        int timer2=0;
        double Rando;
        double vec;

    };
}