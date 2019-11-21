#include <algorithm>
#include <iterator>
#include "Npc.h"
#include "colliderTest.h"


namespace GTA {
    Npc::Npc() = default;
    Npc::~Npc() = default;

    // Using a reference of texture works
    void Npc::npcInit(sf::Texture & texture, Block _Block[WORLD_HEIGHT][WORLD_WIDTH]) { // dependency injection method is the trick. *2
        dir = RandomDir;
        this->npcBot.setTexture(texture);

        /// Spawn random
        while(!CheckWalkable){
            randomPosX = (rand() % WORLD_WIDTH, rand() % WORLD_WIDTH);
            randomPosY = (rand() % WORLD_HEIGHT, rand() % WORLD_HEIGHT);

            RandNpcTile = _Block[randomPosY][randomPosX].tileTextureNumber;

            /// IF True, break loop (true means that the tile is ok to spawn in)
            CheckWalkable = std::find(std::begin(npcCanSpawnHere), std::end(npcCanSpawnHere), RandNpcTile) != std::end(npcCanSpawnHere);
        }

        this->npcBot.setPosition(randomPosX * TILE_SIZE, randomPosY * TILE_SIZE);
        this->npcBot.setTextureRect(sf::IntRect(0, 0,100, 100));
        this->npcBot.setScale(sf::Vector2f(1.0f, 1.0f));
        this->npcBot.setOrigin(50.f, 67.f);
        CheckWalkable = false;

    }

    sf::Sprite &Npc::getNpcBot() { return npcBot; }

    void Npc::move(Block _Block[WORLD_HEIGHT][WORLD_WIDTH]) {
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

        /// check if  "NextNpcPos" crashes with any of the variables in "curb"
        crashCurb = std::find(std::begin(npcCanNOTwalkHere), std::end(npcCanNOTwalkHere), NextTile) != std::end(npcCanNOTwalkHere);

        /// if "crashCurb" is false, keep moving
        if(!crashCurb){
            npcBot.setPosition(UpdatedPosX, UpdatedPosY);
        } else {
            dir = RandomDir; /// set random Direction
        }
        StepCounter++;
        if(StepCounter == 500){
            dir = RandomDir;
            StepCounter=0;
        }

        /// Sets the rotation of the NPC
        if(dir == RIGHT){npcBot.setRotation(90);}
        else if (dir == LEFT){npcBot.setRotation(270);}
        else if (dir == UP){npcBot.setRotation(0);}
        else if (dir == DOWN){npcBot.setRotation(180);}

        /// NPC movement Animation
        npcBot.setTextureRect(sf::IntRect(0, walkAnimation * 110, 100, 110));

        SpriteSpeed++;
        if (SpriteSpeed == 18) {
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

//    void Npc::setNpcBot(sf::Vector2f vector2F) {
//
//        npcBot.move(vector2F);
//    }

    void NpcController::NpcSpawn(sf::Texture &texture, Block _Block[WORLD_HEIGHT][WORLD_WIDTH]) {

        for (int i = 0; i < 55; ++i) {
            npcVec.push_back(new Npc);
            npcVec[i]->npcInit(texture, _Block);
        }
    }

    void NpcController::NpcMoveAndSpawn(sf::Texture &texture, Block _Block[WORLD_HEIGHT][WORLD_WIDTH]) {

        for(auto n : npcVec) {
            if(!n->dead){
                n->move(_Block);
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

    void NpcController::NpcDraw(GameDataRef inn_data, bool Driving, float MovementSpeed, sf::Sprite _car, sf::Sprite _player) {
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
                            i->setNpcBot(this->_data->assets.GetTexture("Dead"));
                        }
                    }
                } else {
                    collisionDetaction.Check_Collision(_player,i->getNpcBot(),true);
                }
            }


            /// Kommer til å intersecte med seg selv?!?!?!? -----
//            for(auto &j : npcVec){
//                for(auto &k : npcVec){
//                    if(PixelPerfectTest(j->getNpcBot(),k->getNpcBot())){
////                    collisionDetaction.Check_Collision(j->getNpcBot(),k->getNpcBot(),true);
//                        j->dir = j->RandomDir;
//                    }
//                }
//            }
        }
    }


}