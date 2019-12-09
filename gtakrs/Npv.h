# pragma once

#include "NPC_NPV.h"

namespace GTA {

    class Npv : public NPC_NPV{
    public:
        typedef std::shared_ptr<GTA::GameData> GameDataRef;

        Npv();
        virtual ~Npv();

        void setNvcBot(sf::Texture &textura);
        void setNpvBot(sf::Vector2f vector2F);
        void setNpv_spBot(sf::Sprite sprite);

        void CarInit(sf::Texture &M3W, Block _Block[WORLD_HEIGHT][WORLD_WIDTH]); // loading the texture instead *1
        void moveCar(Block _Block[WORLD_HEIGHT][WORLD_WIDTH], std::vector<Npv*> &npcVec);

        sf::Sprite &getNpvBot();

    private:
        /// Player Speed
        GameDataRef _data;
        sf::Sprite npvBot;

        sf::Texture M3_Black;
        sf::Texture M3_Blue;
        sf::Texture M3_Red;
        sf::Texture M3_Silver;
    };

    class CarController: public NPC_NPV{
    public:
        typedef std::shared_ptr<GTA::GameData> GameDataRef;

        void NpvSpawn(sf::Texture &M3W,  Block _Block[WORLD_HEIGHT][WORLD_WIDTH]);
        void NpvMoveAndSpawn(sf::Texture &_car, Block _Block[WORLD_HEIGHT][WORLD_WIDTH]);

        void NpvDraw(GameDataRef &inn_data, bool &Driving, float &MovementSpeed, sf::Sprite &_car, sf::Sprite &_player, sf::Sound &carcrashdone,sf::Texture &_cartex, Block _Block[WORLD_HEIGHT][WORLD_WIDTH]);
        std::vector<Npv*> npvVec;

        void setNpvVec(const std::vector<Npv *> &npvVec);


    private:
        GameDataRef _data;
    };
}