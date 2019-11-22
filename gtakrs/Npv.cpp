#include <algorithm>
#include <iterator>
#include "Npv.h"


namespace GTA {
    Npv::Npv() = default;
    Npv::~Npv() = default;

    // Using a reference of texture works
    void Npv::CarInit(sf::Texture & texture, Block _Block[WORLD_HEIGHT][WORLD_WIDTH]) { // dependency injection method is the trick. *2
        dir = RandomDir;
        this->npvBot.setTexture(texture);
        movementSpeed = 4;

        /// Spawn random
        while(!CheckWalkable){
            randomPosX = (rand() % WORLD_WIDTH, rand() % WORLD_WIDTH);
            randomPosY = (rand() % WORLD_HEIGHT, rand() % WORLD_HEIGHT);

            RandNpcTile = _Block[randomPosY][randomPosX].tileTextureNumber;

            /// IF True, break loop (true means that the tile is ok to spawn in)
            CheckWalkable = std::find(std::begin(npcCarCanSpawnHere), std::end(npcCarCanSpawnHere), RandNpcTile) != std::end(npcCarCanSpawnHere);
        }

        randomColor = (rand() % 5, rand() % 5);
        switch (randomColor){
            case 1 : this->npvBot.setColor(sf::Color::Red); break;
            case 2 : this->npvBot.setColor(sf::Color::Green); break;
            case 3 : this->npvBot.setColor(sf::Color::Magenta); break;
            case 4 : this->npvBot.setColor(sf::Color::White); break;
            case 5 : this->npvBot.setColor(sf::Color::Cyan); break;
        }

        this->npvBot.setPosition(randomPosX * TILE_SIZE, randomPosY * TILE_SIZE);
        this->npvBot.setTextureRect(sf::IntRect(0, 0, 100, 100));
        this->npvBot.setScale(sf::Vector2f(1.0f, 1.0f));
        this->npvBot.setOrigin(50.f, 67.f);
        health = 100;
    }

    sf::Sprite &Npv::getNpvBot() { return npvBot; }

    void Npv::moveCar(Block Car_Block[WORLD_HEIGHT][WORLD_WIDTH]) {
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
        crashCurb = std::find(std::begin(npcCarCanNotDriveHere), std::end(npcCarCanNotDriveHere), NextTile) != std::end(npcCarCanNotDriveHere);

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
        npvBot.setTextureRect(sf::IntRect(0, 0, 100, 180));

    }

    void Npv::setNvcBot(sf::Texture &textura) {

        this->npvBot.setTexture(textura);
        npvBot.setTextureRect(sf::IntRect(0, 0, 100, 110));

    }

    void Npv::setNpvBot(sf::Vector2f vector2F) {

        npvBot.move(vector2F);
    }

    void CarController::NpvSpawn(sf::Texture &texture, Block _Block[WORLD_HEIGHT][WORLD_WIDTH]) {
        for (int k = 0; k < 10; ++k) {
            npvVec.push_back(new Npv);
            npvVec[k]->CarInit(texture, _Block);
        }
    }

    void CarController::NpvMoveAndSpawn(sf::Texture &texture, Block _Block[WORLD_HEIGHT][WORLD_WIDTH]) {
        for(auto nop : npvVec) {
            if(!nop->dead){
            nop->moveCar(_Block);
            }else{
                nop->RespawnTime -= 1;
                if(nop->RespawnTime == 0){
                    nop->CarInit(texture, _Block);
                    nop->dead = false;
                    nop->RespawnTime = 600;
                    nop->getNpvBot().setColor(sf::Color::Red);
                }
            }
        }
    }

    void CarController::NpvDraw(GameDataRef inn_data, bool Driving, float MovementSpeed, sf::Sprite _car,sf::Sprite _player) {
        _data = inn_data;
        for (auto &i : npvVec) {
            this->_data->window.draw(i->getNpvBot());

            if(i->dead){
//                i->setNvcBot(this->_data->assets.GetTexture("Dead"));
                i->movementSpeed = 0;
            }

            /// Npc collision with car
            if(Driving){
//                if(movement.currentSpeed <= 800){
                collisionDetaction.Check_Collision(_car, i->getNpvBot(), true);
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