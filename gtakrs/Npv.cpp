#include <algorithm>
#include <iterator>
#include "Npv.h"


namespace GTA {
    Npv::Npv() = default;
    Npv::~Npv() = default;

//    void Npc::loader(){
//        M3_Blue = this->_data->assets.GetTexture("M3_BLUE");
//        M3_Red = this->_data->assets.GetTexture("M3_RED");
//        M3_Black = this->_data->assets.GetTexture("M3_BLACK");
//        M3_Silver = this->_data->assets.GetTexture("M3_SILVER");
//        M3_White = this->_data->assets.GetTexture("M3_WHITE");
//    }

    // Using a reference of texture works
    void Npv::CarInit(sf::Texture &M3W, Block _Block[WORLD_HEIGHT][WORLD_WIDTH]) { // dependency injection method is the trick. *2

        dir = RandomDir;
        movementSpeed = 8;
        spriteHeight = 208;
        spriteWidth = 91;

        /// Spawn random
        while(!CheckWalkable){
            randomPosX = (rand() % WORLD_WIDTH, rand() % WORLD_WIDTH);
            randomPosY = (rand() % WORLD_HEIGHT, rand() % WORLD_HEIGHT);

            //RandNpcTile = _Block[randomPosY][randomPosX].tileTextureNumber;

            /// IF True, break loop (true means that the tile is ok to spawn in)
            CheckWalkable = std::find(std::begin(Npv_Can_SpawnHere), std::end(Npv_Can_SpawnHere), RandNpcTile) != std::end(Npv_Can_SpawnHere);
        }

//        randomColor = (rand() % 5, rand() % 5);
//        switch (randomColor){
//            case 1 :
                this->npvBot.setTexture(M3W);
//            break;
//            case 2 : this->npvBot.setTexture(M3K); break;
//            case 3 : this->npvBot.setTexture(M3R); break;
//            case 4 : this->npvBot.setTexture(M3S); break;
//            case 5 : this->npvBot.setTexture(M3B); break;
//        }

        this->npvBot.setPosition(randomPosX * TILE_SIZE, randomPosY * TILE_SIZE);
        this->npvBot.setTextureRect(sf::IntRect(0, 0, spriteWidth, spriteHeight));
        this->npvBot.setScale(sf::Vector2f(1.2f, 1.2f));
        this->npvBot.setOrigin(50.f, 67.f);
        health = 100;
    }

    sf::Sprite &Npv::getNpvBot() { return npvBot; }

    void Npv::moveCar(Block Car_Block[WORLD_HEIGHT][WORLD_WIDTH], std::vector<Npv*> &npvVec) {
        CurrentPosX = npvBot.getPosition().x;
        CurrentPosY = npvBot.getPosition().y;

        moveRight = CurrentPosX + movementSpeed;
        moveLeft = CurrentPosX - movementSpeed;
        moveUp = CurrentPosY - movementSpeed;
        moveDown = CurrentPosY + movementSpeed;

        /// Generates random direction
        RandomDir = static_cast<direction >(rand() % 4);

        /// FUNKER -------------------
        switch (dir){
            case RIGHT : {
                NextPosX = (moveRight + 31) / TILE_SIZE;
                NextPosY = CurrentPosY / TILE_SIZE;
                UpdatedPosX = moveRight;
                UpdatedPosY = CurrentPosY;
                break;
            }
            case LEFT : {
                NextPosX = (moveLeft - 31) / TILE_SIZE;
                NextPosY = CurrentPosY / TILE_SIZE;
                UpdatedPosX = moveLeft;
                UpdatedPosY = CurrentPosY;
                break;
            }
            case UP : {
                NextPosX = CurrentPosX / TILE_SIZE;
                NextPosY = (moveUp - 31) / TILE_SIZE;
                UpdatedPosX = CurrentPosX;
                UpdatedPosY = moveUp;
                break;
            }
            case DOWN : {
                NextPosX = CurrentPosX / TILE_SIZE;
                NextPosY = (moveDown + 31) / TILE_SIZE;
                UpdatedPosX = CurrentPosX;
                UpdatedPosY = moveDown;
                break;
            }
        }

        NextTile = Car_Block[NextPosY][NextPosX].tileTextureNumber;

        /// check if  "NextNpcPos" crashes with any of the variables in "curb"
        crashCurb = std::find(std::begin(NpvCan_Not_MoveHere), std::end(NpvCan_Not_MoveHere), NextTile) != std::end(NpvCan_Not_MoveHere);

        for(int i = 0; i < npvVec.size(); ++i) {
            if(npvVec[i]->NextPosX == NextPosX && npvVec[i]->NextPosY == NextPosY && npvVec[i]->Number != Number){
                dir = RandomDir;
            }
        }

//        for(int i = 0; i < npvVec.size(); ++i) {
//            if(PixelPerfectTest(npvVec[i]->getNpvBot(), getNpvBot()) && npvVec[i]->Number != Number){
//                dir = RandomDir;
//            }
//            if (npvVec[i]->NextPosX == NextPosX && npvVec[i]->NextPosY == NextPosY && npvVec[i]->Number != Number) {
//                dir = RandomDir;
//            }
//        }

        /// if "crashCurb" is false, keep moving, else set random Direction
        if(!crashCurb){ npvBot.setPosition(UpdatedPosX, UpdatedPosY); }
        else { dir = RandomDir; }

        StepCounter +=1;
        if(StepCounter == 500){
            dir = RandomDir;
            StepCounter=0;
        }

        /// Sets the rotation of the NPC
        if(dir == RIGHT){npvBot.setRotation(90);}
        else if (dir == LEFT){npvBot.setRotation(270);}
        else if (dir == UP){npvBot.setRotation(0);}
        else if (dir == DOWN){npvBot.setRotation(180);}

        /// NPC movement Animation
//        npvBot.setTextureRect(sf::IntRect(0, 0, 100, 180));

    }

    void Npv::setNvcBot(sf::Texture &textura) {

        this->npvBot.setTexture(textura);
        npvBot.setTextureRect(sf::IntRect(0, 0, spriteWidth, spriteHeight));

    }

    void Npv::setNpvBot(sf::Vector2f vector2F) {

        npvBot.move(vector2F);
    }

    void CarController::NpvSpawn(sf::Texture &M3W,  Block _Block[WORLD_HEIGHT][WORLD_WIDTH]) {
        for (int k = 0; k < 5; ++k) {
            npvVec.push_back(new Npv);
            npvVec[k]->Number = k;
            npvVec[k]->CarInit(M3W, _Block);
        }
    }

    void CarController::NpvMoveAndSpawn(sf::Texture &_car, Block _Block[WORLD_HEIGHT][WORLD_WIDTH]) {
        for(auto nop : npvVec) {
            if(!nop->dead){
            nop->moveCar(_Block,npvVec);
            }else{
                nop->RespawnTime -= 1;
                if(nop->RespawnTime == 0){
                    nop->CarInit(_car, _Block);
                    nop->dead = false;
                    nop->RespawnTime = 600;
                    nop->getNpvBot().setColor(sf::Color::Red);
                }
            }
        }
    }

//            nop->moveCar(_Block, npvVec);

    void CarController::NpvDraw(GameDataRef &inn_data, bool &Driving, float &MovementSpeed, sf::Sprite &_car,sf::Sprite &_player, sf::Sound &carcrashdone) {
        _data = inn_data;
        for (auto i : npvVec) {
            this->_data->window.draw(i->getNpvBot());

            if(i->dead){
//                i->setNvcBot(this->_data->assets.GetTexture("Dead"));
                i->movementSpeed = 0;
            }

            /// Npc collision with car
            if(Driving){
//                if(movement.currentSpeed <= 800){
                collisionDetaction.Check_Collision(_car, i->getNpvBot(), true);
                //this->_data->assets.PlaySound(carcrashdone);
                /// denne lyden må spilles når en bil "dør", ellers så spilles lyden hver gang spilleren dytter bilen
//                } else {
//                    i->dead = true;
//                    i->setNvcBot(this->_data->assets.GetTexture("Dead"));
//                }
            } else {
//                    i->dir = i->RandomDir;
                collisionDetaction.Check_Collision(_player, i->getNpvBot(), false);
            }

        }
    }
}