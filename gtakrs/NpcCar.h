//# pragma once
//
//#include <iostream>
//
//#include "Game.h"
//#include "Movement.h"
//#include "DEFINITIONS.h"
//#include "Map.h"
//
//
//namespace GTA {
//
//    class NpcCar : public Movement{
//    public:
//        typedef std::shared_ptr<GTA::GameData> GameDataRef;
//
//        NpcCar();
//        virtual ~NpcCar();
//
//        void npcCarInit(sf::Texture &texture, Block _Block[WORLD_HEIGHT][WORLD_WIDTH]); // loading the texture instead *1
//        void moveCar(Block _Block[109][115]);
//
//        /// Variables
//        int NextPosX,NextPosY;
//        int CurrentPosX, CurrentPosY;
//        int walkSpeed = 4;
//        int walkUp, walkDown, walkRight, walkLeft;
//        int NextNpcTile;
//        int UpdatedPosX, UpdatedPosY;
//        int npcStepsCounter = 0;
//        int randomPosX, randomPosY, RandNpcTile;
//        bool crashCurb, npcCheckWalkable = false;
//
//        int npcCarCanStartHere[9]={1,2,3,4,7,8,14,15,16};
//        int npcCarCanNotDriveHere[7]={0, 5, 6, 9, 11, 12,17};
//
//        enum direction{UP, DOWN, LEFT, RIGHT} dir;
//        sf::Sprite &getNpcCarBot();
//
//        direction RandomDir;
//    private:
//        /// Player Speed
//        GameDataRef _data;
//        sf::Sprite npcCarBot;
//    };
//}