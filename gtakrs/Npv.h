# pragma once

#include "NPC_NPV.h"
#include "Player.h"

namespace GTA {

    class Npv : public NPC_NPV{
    public:
        typedef std::shared_ptr<GTA::GameData> GameDataRef;

        Npv();
        virtual ~Npv();
        void CarInit(sf::Texture &M3W, Block _Block[WORLD_HEIGHT][WORLD_WIDTH]); // loading the texture instead *1
        void moveCar(Block _Block[WORLD_HEIGHT][WORLD_WIDTH], std::vector<Npv*> &npcVec);

        sf::Sprite &getNpvBot();
        bool carInteract = false;
        bool boatInteract = false;


    private:
        /// Player Speed
        GameDataRef _data;
        sf::Sprite npvBot;

    };

    class NpvController: public NPC_NPV{
    public:
        typedef std::shared_ptr<GTA::GameData> GameDataRef;

        void NpvSpawn(sf::Texture &M3W,  Block _Block[WORLD_HEIGHT][WORLD_WIDTH]);
        void NpvMoveAndSpawn(sf::Texture &_car, Block _Block[WORLD_HEIGHT][WORLD_WIDTH]);
        void NpvDraw(GameDataRef &inn_data, bool &Driving, float &MovementSpeed, sf::Sprite &_car, sf::Sprite &_player, sf::Sound &carcrashdone,sf::Texture &_cartex, Block _Block[WORLD_HEIGHT][WORLD_WIDTH], Player &player,bool &boat, sf::Sound &tesla);
        int random = 0;
        int numberOfNpv = 51;
        sf::Color color;
        sf::Color Loader();
        std::vector<Npv*> npvVec;

    private:
        GameDataRef _data;
        AssetManager sound;
    };
}