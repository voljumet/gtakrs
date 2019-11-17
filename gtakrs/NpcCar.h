# pragma once

#include <iostream>

#include "Game.h"
#include "Movement.h"
#include "DEFINITIONS.h"
#include "Map.h"
#include "Npc.h"


namespace GTA {

    class NpcCar : public Movement{
    public:
        typedef std::shared_ptr<GTA::GameData> GameDataRef;

        NpcCar();
        virtual ~NpcCar();

        void npcCarInit(sf::Texture &texture, Block _Block[WORLD_HEIGHT][WORLD_WIDTH]); // loading the texture instead *1
        void moveCar(Block _Block[WORLD_HEIGHT][WORLD_WIDTH]);

        /// Variables
        int NextPosX,NextPosY;
        int CurrentPosX, CurrentPosY;
        int walkSpeed = 4;
        int walkUp, walkDown, walkRight, walkLeft;
        int NextNpcTile;
        int UpdatedPosX, UpdatedPosY;
        int npcStepsCounter = 0;
        int randomPosX, randomPosY, RandNpcTile;
        int randomColor;
        bool crashCurb, npcCheckWalkable = false;

        int npcCarCanSpawnHere[9]={7, 8, 14, 15, 16};
        int npcCarCanNotDriveHere[18]={1,2,3,4,0, 5, 6, 9, 10, 11, 12,17,18,19,20,21,22};

        enum direction{UP, DOWN, LEFT, RIGHT} dir;
        sf::Sprite &getNpcCarBot();

        direction RandomDir;
    private:
        /// Player Speed
        GameDataRef _data;
        sf::Sprite npcCarBot;
    };
}