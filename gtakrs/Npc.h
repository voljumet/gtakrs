# pragma once

#include "NPC_NPV.h"

namespace GTA {

    class Npc : public NPC_NPV{
    public:
        typedef std::shared_ptr<GTA::GameData> GameDataRef;

        explicit Npc();
        virtual ~Npc();
        void setNpcBot(sf::Texture &texture);
        void npcInit(sf::Texture &texture, Block _Block[WORLD_HEIGHT][WORLD_WIDTH]); // loading the texture instead *1
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

        void NpcSpawn(sf::Texture &texture, Block _Block[WORLD_HEIGHT][WORLD_WIDTH]);

        void NpcMoveAndSpawn(sf::Texture &texture, Block _Block[WORLD_HEIGHT][WORLD_WIDTH]);
        void NpcDraw(GameDataRef &inn_data, bool &Driving, float &MovementSpeed, sf::Sprite &_car, sf::Sprite &_player, sf::Sound &cardeath);


        std::vector<Npc*> npcVec;
    private:
        GameDataRef _data;
        Collision_Detection collisionDetaction;

        sf::Texture player1;
        sf::Texture player2;
        sf::Texture player3;
        sf::Texture player4;
        sf::Texture player5;

    };
}