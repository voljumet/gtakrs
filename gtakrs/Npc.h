# pragma once

#include "Game.h"
#include "aiController.h"


namespace GTA {
    class Npc {
    public:

        typedef std::shared_ptr<GTA::GameData> GameDataRef;

        Npc();
        virtual ~Npc();

        void spawnNpc(sf::Texture & texture); // loading the texture instead *1
        void npcWalkStart();

        // variables
        sf::Sprite npcBot;
        sf::Sprite npcBot1;

        int tileSize= 70;
    private:
        GameDataRef _data;
    };
}