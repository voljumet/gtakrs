# pragma once

#include "NPC_NPV.h"


namespace GTA {

    class Npc : public NPC_NPV{
    public:
        typedef std::shared_ptr<GTA::GameData> GameDataRef;

        Npc();
        virtual ~Npc();
        void setNpcBot(sf::Texture &texture);

        void npcInit(sf::Texture &texture, Block _Block[WORLD_HEIGHT][WORLD_WIDTH]); // loading the texture instead *1
        void move(Block _Block[WORLD_HEIGHT][WORLD_WIDTH], sf::Texture texture);

        sf::Sprite &getNpcBot();

    private:
        GameDataRef _data;
        sf::Sprite npcBot;
    };

    class NpcController : public NPC_NPV{
    public:
        typedef std::shared_ptr<GTA::GameData> GameDataRef;

        void NpcSpawn(sf::Texture &texture, Block _Block[WORLD_HEIGHT][WORLD_WIDTH]);
        void NpcMoveAndSpawn(sf::Texture &texture, Block _Block[WORLD_HEIGHT][WORLD_WIDTH], sf::Texture texture1);
        void NpcDraw(GameDataRef inn_data, bool Driving, float MovementSpeed, sf::Sprite _car, sf::Sprite _player);
        std::vector<Npc*> npcVec;

    private:
        GameDataRef _data;
    };
}