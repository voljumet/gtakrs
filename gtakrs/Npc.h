# pragma once

#include "Game.h"
#include "Movement.h"
#include "iostream"
#include "DEFINITIONS.h"
#include "Map.h"


namespace GTA {

    class Npc : public Movement{
    public:
        explicit Npc(GameDataRef data);
        typedef std::shared_ptr<GTA::GameData> GameDataRef;


        Npc();
        virtual ~Npc();

        void npcInit(sf::Texture &texture); // loading the texture instead *1
//        void npcDirectUpdate();
        void move();
        void NpcPos(Block pBlock[109][115]);
        void npcRotation();
        bool stop = false;

        // variables
        int posX,posY;
        int nyPosX, nyPosY;
        int walkSpeed = 1;

        sf::Sprite &getNpcBot();
        enum direction{UP, DOWN, LEFT, RIGHT} dir;

    private:
        //Player Speed
        GameDataRef _data;
        sf::Sprite npcBot;
    };
}