#include <algorithm>
#include <iterator>
#include "NpcCar.h"


namespace GTA {
    NpcCar::NpcCar() = default;
    NpcCar::~NpcCar() = default;

    // Using a reference of texture works
    void NpcCar::CarInit(sf::Texture & texture, Block _Block[WORLD_HEIGHT][WORLD_WIDTH]) { // dependency injection method is the trick. *2
        dir = RandomDir;
        this->npcCarBot.setTexture(texture);

        /// Spawn random
        while(!npcCheckWalkable){
            randomPosX = (rand() % WORLD_WIDTH, rand() % WORLD_WIDTH);
            randomPosY = (rand() % WORLD_HEIGHT, rand() % WORLD_HEIGHT);

            RandNpcTile = _Block[randomPosY][randomPosX].tileTextureNumber;

            /// IF True, break loop (true means that the tile is ok to spawn in)
            npcCheckWalkable = std::find(std::begin(npcCarCanSpawnHere), std::end(npcCarCanSpawnHere), RandNpcTile) != std::end(npcCarCanSpawnHere);
        }

        randomColor = (rand() % 6, rand() % 6);
        switch (randomColor){
            case 1 : this->npcCarBot.setColor(sf::Color::Red); break;
            case 2 : this->npcCarBot.setColor(sf::Color::Green); break;
            case 3 : this->npcCarBot.setColor(sf::Color::Magenta); break;
            case 4 : this->npcCarBot.setColor(sf::Color::Black); break;
            case 5 : this->npcCarBot.setColor(sf::Color::White); break;
            case 6 : this->npcCarBot.setColor(sf::Color::Cyan); break;
        }

        this->npcCarBot.setPosition(randomPosX * TILE_SIZE, randomPosY * TILE_SIZE);
        this->npcCarBot.setTextureRect(sf::IntRect(0, 0, 100, 100));
        this->npcCarBot.setScale(sf::Vector2f(1.0f, 1.0f));
        this->npcCarBot.setOrigin(50.f, 67.f);
    }

    sf::Sprite &NpcCar::getNpcCarBot() { return npcCarBot; }

    void NpcCar::moveCar(Block Car_Block[WORLD_HEIGHT][WORLD_WIDTH]) {
        CurrentPosX = npcCarBot.getPosition().x;
        CurrentPosY = npcCarBot.getPosition().y;

        walkRight = CurrentPosX + walkSpeed;
        walkLeft = CurrentPosX - walkSpeed;
        walkUp = CurrentPosY - walkSpeed;
        walkDown = CurrentPosY + walkSpeed;

        /// Generates random direction
        RandomDir = static_cast<direction >(rand() % 4);

        /// FUNKER -------------------
        switch (dir){
            case RIGHT : {
                NextPosX = (walkRight+31) / TILE_SIZE;
                NextPosY = CurrentPosY / TILE_SIZE;
                UpdatedPosX = walkRight;
                UpdatedPosY = CurrentPosY;
                break;
            }
            case LEFT : {
                NextPosX = (walkLeft-31) / TILE_SIZE;
                NextPosY = CurrentPosY / TILE_SIZE;
                UpdatedPosX = walkLeft;
                UpdatedPosY = CurrentPosY;
                break;
            }
            case UP : {
                NextPosX = CurrentPosX / TILE_SIZE;
                NextPosY = (walkUp-31) / TILE_SIZE;
                UpdatedPosX = CurrentPosX;
                UpdatedPosY = walkUp;
                break;
            }
            case DOWN : {
                NextPosX = CurrentPosX / TILE_SIZE;
                NextPosY = (walkDown+31) / TILE_SIZE;
                UpdatedPosX = CurrentPosX;
                UpdatedPosY = walkDown;
                break;
            }
        }

        NextNpcTile = Car_Block[NextPosY][NextPosX].tileTextureNumber;

        /// check if  "NextNpcPos" crashes with any of the variables in "curb"
        crashCurb = std::find(std::begin(npcCarCanNotDriveHere), std::end(npcCarCanNotDriveHere), NextNpcTile) != std::end(npcCarCanNotDriveHere);

        /// if "crashCurb" is false, keep moving, else set random Direction
        if(!crashCurb){ npcCarBot.setPosition(UpdatedPosX, UpdatedPosY); }
        else { dir = RandomDir; }

        npcStepsCounter +=1;
        if(npcStepsCounter == 500){
            dir = RandomDir;
            npcStepsCounter=0;
        }

        /// Sets the rotation of the NPC
        if(dir == RIGHT){npcCarBot.setRotation(90);}
        else if (dir == LEFT){npcCarBot.setRotation(270);}
        else if (dir == UP){npcCarBot.setRotation(0);}
        else if (dir == DOWN){npcCarBot.setRotation(180);}

        /// NPC movement Animation
        npcCarBot.setTextureRect(sf::IntRect(0, 0, 100, 180));

    }

    void NpcCar::setNpcCarBot(sf::Texture &textura) {
        std::cout << "Destroyed!"<< std::endl;

        this->npcCarBot.setTexture(textura);
        npcCarBot.setTextureRect(sf::IntRect(0, 0, 100, 110));

    }

    void NpcCar::setNpcCarBot(sf::Vector2f vector2F) {

        npcCarBot.move(vector2F);
    }

    void CarController::CarSpawn(sf::Texture &texture, Block _Block[WORLD_HEIGHT][WORLD_WIDTH] ) {
        for (int k = 0; k < 10; ++k) {
            CarVec.push_back(new NpcCar);
            CarVec[k]->CarInit(texture, _Block);
        }
    }

    void CarController::CarMoveAndSpawn(sf::Texture &texture, Block _Block[WORLD_HEIGHT][WORLD_WIDTH]) {
        for(auto nop : CarVec) {
            nop->moveCar(_Block);
        }
    }

    void CarController::CarDraw(GameDataRef inn_data, bool Driving, float MovementSpeed, sf::Sprite _car,sf::Sprite _player) {
        _data = inn_data;
        for (auto &i : CarVec) {
            this->_data->window.draw(i->getNpcCarBot());

            /// Npc collision with car
            if(Driving){
//                if(movement.currentSpeed <= 800){
                collisionDetaction.Check_Collision(_car,i->getNpcCarBot(),true);
//                } else {
//                    i->dead = true;
//                    i->setNpcCarBot(this->_data->assets.GetTexture("Dead"));
//                }
            } else {
//                    i->dir = i->RandomDir;
                collisionDetaction.Check_Collision(_player,i->getNpcCarBot(),false);
            }

        }
    }
}