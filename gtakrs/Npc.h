# pragma once

#include <iostream>

#include "Game.h"
#include "Movement.h"
#include "DEFINITIONS.h"
#include "Map.h"


namespace GTA {

    class Npc : public Movement{
    public:
        typedef std::shared_ptr<GTA::GameData> GameDataRef;

        Npc();
        virtual ~Npc();

        void setNpcBot(sf::Texture &texture);

        void npcInit(sf::Texture &texture, Block _Block[WORLD_HEIGHT][WORLD_WIDTH]); // loading the texture instead *1
        void move(Block _Block[109][115]);

        /// Variables
        int NextPosX,NextPosY;
        int CurrentPosX, CurrentPosY;
        int walkSpeed = 1;
        int walkUp, walkDown, walkRight, walkLeft;
        int NextNpcTile;
        int UpdatedPosX, UpdatedPosY;
        int npcStepsCounter = 0;
        int randomPosX, randomPosY, RandNpcTile;
        bool crashCurb, npcCheckWalkable = false, dead = false;

        int npcCanStartHere[4]={10, 15, 16, 17};
        int npcCanNOTwalkHere[14]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 13, 14};

        enum direction{UP, DOWN, LEFT, RIGHT} dir;
        sf::Sprite &getNpcBot();

        direction RandomDir;
    private:
        /// Player Speed
        GameDataRef _data;
        sf::Sprite npcBot;
    };
}