#include <algorithm>
#include <iterator>
#include "Npc.h"

namespace GTA {
    Npc::Npc() = default;
    Npc::~Npc() = default;


    // Using a reference of texture works
    void Npc::npcInit(sf::Texture &texture, Block _Block[WORLD_HEIGHT][WORLD_WIDTH]) { // dependency injection method is the trick. *2
        dir = RandomDir;
        movementSpeed = 5;

        /// Walk speed
//        (rand() % (4 + 5));

//        randomColor = (rand() % 5, rand() % 5);
//        switch (randomColor){
//            case 1 :
                npcBot.setTexture(texture);
//            break;
//            case 2 : this->npcBot.setTexture(texture2); break;
//            case 3 : this->npcBot.setTexture(texture3); break;
//            case 4 : this->npcBot.setTexture(texture4); break;
//            case 5 : this->npcBot.setTexture(texture5); break;
//        }


        /// Spawn random
        while(!CheckWalkable){
            randomPosX = (rand() % WORLD_WIDTH, rand() % WORLD_WIDTH);
            randomPosY = (rand() % WORLD_HEIGHT, rand() % WORLD_HEIGHT);

            RandNpcTile = _Block[randomPosY][randomPosX].tileTextureNumber;

            /// IF True, break loop (true means that the tile is ok to spawn in)
            CheckWalkable = std::find(std::begin(Npc_Can_SpawnHere), std::end(Npc_Can_SpawnHere), RandNpcTile) != std::end(Npc_Can_SpawnHere);
        }

        this->npcBot.setPosition(randomPosX * TILE_SIZE, randomPosY * TILE_SIZE);
        this->npcBot.setTextureRect(sf::IntRect(0, 0,100, 100));
        this->npcBot.setScale(sf::Vector2f(1.0f, 1.0f));
        this->npcBot.setOrigin(50.f, 67.f);
        CheckWalkable = false;
        health = 50;
    }

    sf::Sprite &Npc::getNpcBot() { return npcBot; }

    void Npc::move(Block _Block[WORLD_HEIGHT][WORLD_WIDTH], std::vector<Npc*> &npcVec) {
        CurrentPosX = npcBot.getPosition().x;
        CurrentPosY = npcBot.getPosition().y;

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
                NextPosY = (moveDown+31) / TILE_SIZE;
                UpdatedPosX = CurrentPosX;
                UpdatedPosY = moveDown;
                break;
            }
        }

        NextTile = _Block[NextPosY][NextPosX].tileTextureNumber;

        for(int i = 0; i < npcVec.size(); ++i) {
            /// change dir if colliding with other npc
            if(PixelPerfectTest(npcVec[i]->getNpcBot(), getNpcBot()) && npcVec[i]->Number != Number){
                dir = RandomDir;
            }
            /// change dir if colliding with any npv
//            if(PixelPerfectTest(npcVec[i]->getNpcBot(), getNpcBot()) && npcVec[i]->Number != Number){
//                    dir = RandomDir;
//                }
        }

        /// check if  "NextNpcPos" crashes with any of the variables in "curb"
        crashCurb = std::find(std::begin(NpcCan_Not_MoveHere),
                std::end(NpcCan_Not_MoveHere), NextTile) != std::end(NpcCan_Not_MoveHere);

        /// if "crashCurb" is false, keep moving
        if(crashCurb){
            dir = RandomDir; /// set random Direction
        } else {
            npcBot.setPosition(UpdatedPosX, UpdatedPosY);
        }

        StepCounter++;
        if(StepCounter == 100){
            dir = RandomDir;
            StepCounter=0;
        }

        /// Sets the rotation of the NPC
        if(dir == RIGHT){npcBot.setRotation(90);}
        else if (dir == LEFT){npcBot.setRotation(270);}
        else if (dir == UP){npcBot.setRotation(0);}
        else if (dir == DOWN){npcBot.setRotation(180);}


        /// NPC movement Animation
        npcBot.setTextureRect(sf::IntRect(0, walkAnimation * 110,
                100, 110));

        SpriteSpeed++;
        if (SpriteSpeed == 4) {
            walkAnimation++;
            SpriteSpeed = 0;
        }

        if (walkAnimation == 5)
            walkAnimation = 1;

    }

    void Npc::setNpcBot(sf::Texture &textura) {
        this->npcBot.setTexture(textura);
        npcBot.setTextureRect(sf::IntRect(0, 0, 100, 110));

    }

    void NpcController::NpcSpawn(sf::Texture &texture, Block _Block[WORLD_HEIGHT][WORLD_WIDTH]) {
//        this->_data->assets.LoadTexture("Player2", PLAYER2);
//        this->_data->assets.LoadTexture("Player3", PLAYER3);
//        this->_data->assets.LoadTexture("Player4", PLAYER4);
//        this->_data->assets.LoadTexture("Player5", PLAYER5);
//
//        player1 = this->_data->assets.GetTexture("Player");
//        player2 = this->_data->assets.GetTexture("Player2");
//        player3 = this->_data->assets.GetTexture("Player3");
//        player4 = this->_data->assets.GetTexture("Player4");
//        player5 = this->_data->assets.GetTexture("Player5");
        for (int i = 0; i < 200; ++i) {
            npcVec.push_back(new Npc);
            npcVec[i]->Number=i;
            npcVec[i]->npcInit(texture, _Block);

        }
    }

    void NpcController::NpcMoveAndSpawn(sf::Texture &texture, Block _Block[WORLD_HEIGHT][WORLD_WIDTH]) {

        RandomDir = static_cast<direction >(rand() % 4);

        for(auto n : npcVec) {
            if(!n->dead){
                n->move(_Block, npcVec);
            } else {
                n->RespawnTime -= 1;
                if (n->RespawnTime == 0){
                    n->npcInit(texture, _Block);
                    n->dead = false;
                    n->RespawnTime = 600;
                }
            }
        }
    }

    void NpcController::NpcDraw(GameDataRef &inn_data, bool &Driving, float &MovementSpeed,
            sf::Sprite &_car, sf::Sprite &_player, sf::Sound &cardeath) {
        _data = inn_data;
        for (auto &i : npcVec) {
            this->_data->window.draw(i->getNpcBot());

            /// Npc collision with car
            if(!i->dead){
                if(Driving){
                    if(MovementSpeed <= 800){
                        collisionDetaction.Check_Collision(_car,i->getNpcBot(),true);
                    } else {
                        if(PixelPerfectTest(i->getNpcBot(),_car)){
                            i->dead = true;
                            this->_data->assets.PlaySound(cardeath);
                            ///legg til cardeath
                            i->setNpcBot(this->_data->assets.GetTexture("Dead"));
                        }
                    }
                } else {
                    collisionDetaction.Check_Collision(_player,i->getNpcBot(),true);
                }
            }
        }
    }
}