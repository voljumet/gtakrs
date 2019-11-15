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

        void npcInit(sf::Texture &texture); // loading the texture instead *1
        void move(Block _Block[109][115]);

        /// Variables
        int NextPosX,NextPosY;
        int CurrentPosX, CurrentPosY;
        int walkSpeed = 4;
        int walkUp, walkDown, walkRight, walkLeft;
        int NextNpcTile;
        bool crashCurb;
        int UpdatedPosX, UpdatedPosY;

        sf::Sprite &getNpcBot();
        enum direction{UP, DOWN, LEFT, RIGHT} dir;
        int curb[6]={1,2,3,4,11,12};

        direction RandomDir;
    private:
        /// Player Speed
        GameDataRef _data;
        sf::Sprite npcBot;
    };
}