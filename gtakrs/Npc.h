# pragma once

#include "NPC_NPV.h"

namespace GTA {

    class Npc : public NPC_NPV{
    public:
        typedef std::shared_ptr<GTA::GameData> GameDataRef;

        explicit Npc();
        virtual ~Npc();
        void setNpcBot(sf::Texture &texture);
        void npcInit(Block _Block[WORLD_HEIGHT][WORLD_WIDTH]); // loading the texture instead *1
        void move(Block _Block[WORLD_HEIGHT][WORLD_WIDTH], std::vector<Npc*> &npcVec);

        sf::Sprite &getNpcBot();

    private:
        GameDataRef _data;
        sf::Sprite npcBot;

        sf::Texture player1;
        sf::Texture player2;
        sf::Texture player3;
        sf::Texture player4;
        sf::Texture player5;
    };

    class NpcController : public NPC_NPV{
    public:
        typedef std::shared_ptr<GTA::GameData> GameDataRef;

        void NpcSpawn(Block _Block[WORLD_HEIGHT][WORLD_WIDTH]);
        void NpcMoveAndSpawn(Block _Block[WORLD_HEIGHT][WORLD_WIDTH]);
        void NpcDraw(GameDataRef &inn_data, bool &Driving, float &MovementSpeed, sf::Sprite &_car, sf::Sprite &_player);

    private:
        GameDataRef _data;
        std::vector<Npc*> npcVec;

        sf::Texture player1;
        sf::Texture player2;
        sf::Texture player3;
        sf::Texture player4;
        sf::Texture player5;

    };
}