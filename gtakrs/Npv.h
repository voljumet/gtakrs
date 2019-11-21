# pragma once

#include "NPC_NPV.h"


namespace GTA {

    class Npv : public NPC_NPV{
    public:
        typedef std::shared_ptr<GTA::GameData> GameDataRef;

        Npv();
        virtual ~Npv();

        void setNpcCarBot(sf::Texture &texture);
        void setNpcCarBot(sf::Vector2f vector2F);

        void CarInit(sf::Texture &texture, Block _Block[WORLD_HEIGHT][WORLD_WIDTH]); // loading the texture instead *1
        void moveCar(Block _Block[WORLD_HEIGHT][WORLD_WIDTH]);

        sf::Sprite &getNpcCarBot();

    private:
        /// Player Speed
        GameDataRef _data;
        sf::Sprite npcCarBot;
    };

    class CarController{
    public:
        typedef std::shared_ptr<GTA::GameData> GameDataRef;

        void CarSpawn(sf::Texture &texture, Block _Block[WORLD_HEIGHT][WORLD_WIDTH]);
        void CarMoveAndSpawn(sf::Texture &texture, Block _Block[WORLD_HEIGHT][WORLD_WIDTH]);
        void CarDraw(GameDataRef inn_data, bool Driving, float MovementSpeed, sf::Sprite _car, sf::Sprite _player);
        std::vector<Npv*> CarVec;

    private:
        GameDataRef _data;
        Collision_Detection collisionDetaction;
    };
}