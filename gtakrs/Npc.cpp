#include <algorithm>
#include <iterator>
#include "Npc.h"

namespace GTA {
    Npc::Npc() = default;

    Npc::~Npc() = default;

    void Npc::npcInit(sf::Texture &texture, Block _Block[WORLD_HEIGHT][WORLD_WIDTH]) {
        dir = RandomDir;
        movementSpeed = 5;
        npcBot.setTexture(texture);

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

        /// Loads tile numbers around NPV
        NextTile = _Block[NextPosY][NextPosX].tileTextureNumber;

        NextTile_RIGHT = _Block[CurrentPosY / TILE_SIZE][(moveRight + 31) / TILE_SIZE].tileTextureNumber;
        NextTile_LEFT = _Block[CurrentPosY / TILE_SIZE][(moveLeft - 31) / TILE_SIZE].tileTextureNumber;
        NextTile_UP = _Block[(moveUp - 31) / TILE_SIZE][CurrentPosX / TILE_SIZE].tileTextureNumber;
        NextTile_DOWN = _Block[(moveUp + 31) / TILE_SIZE][CurrentPosX / TILE_SIZE].tileTextureNumber;

        /// Check if  tiles around NPV crashes with any of the variables in "NpcCan_Not_MoveHere"
        crashCurb_RIGHT = std::find(std::begin(NpcCan_Not_MoveHere), std::end(NpcCan_Not_MoveHere),NextTile_RIGHT) != std::end(NpcCan_Not_MoveHere);
        crashCurb_LEFT = std::find(std::begin(NpcCan_Not_MoveHere), std::end(NpcCan_Not_MoveHere),NextTile_LEFT) != std::end(NpcCan_Not_MoveHere);
        crashCurb_UP = std::find(std::begin(NpcCan_Not_MoveHere), std::end(NpcCan_Not_MoveHere),NextTile_UP) != std::end(NpcCan_Not_MoveHere);
        crashCurb_DOWN = std::find(std::begin(NpcCan_Not_MoveHere), std::end(NpcCan_Not_MoveHere),NextTile_DOWN) != std::end(NpcCan_Not_MoveHere);

        crashCurb = std::find(std::begin(NpcCan_Not_MoveHere),std::end(NpcCan_Not_MoveHere),NextTile) != std::end(NpcCan_Not_MoveHere);

        /// Check if tile in front of npc is ok
        if (crashCurb) {
            /// If all tiles around npc are non-movable, stand still
            if (crashCurb_RIGHT && crashCurb_LEFT && crashCurb_DOWN && crashCurb_UP){
                movementSpeed = 0;
                walkAnimation = 0;
            /// else change dir
            } else { dir = RandomDir; }
        /// If the tile in front of npc is ok, move
        } else  {
            npcBot.setPosition(UpdatedPosX, UpdatedPosY);
            StepCounter++;
            SpriteSpeed++;
        }

        /// change dir if colliding with other npc
        for(int i = 0; i < npcVec.size(); ++i) {
            if(PixelPerfectTest(npcVec[i]->getNpcBot(), getNpcBot()) && npcVec[i]->Number != Number){
                dir = RandomDir;
            }
        }

        /// Sets the rotation of the NPC
        if(dir == RIGHT){npcBot.setRotation(90);}
        else if (dir == LEFT){npcBot.setRotation(270);}
        else if (dir == UP){npcBot.setRotation(0);}
        else if (dir == DOWN){npcBot.setRotation(180);}

        if (StepCounter == 100){ dir = RandomDir; StepCounter = 0; }
        if (SpriteSpeed == 4) { walkAnimation++; SpriteSpeed = 0; }
        if (walkAnimation == 5) { walkAnimation = 1; }

        /// NPC movement Animation
        npcBot.setTextureRect(sf::IntRect(0, walkAnimation * 110,100, 110));

    }

    void Npc::setNpcBot(sf::Texture &textura) {
        this->npcBot.setTexture(textura);
        npcBot.setTextureRect(sf::IntRect(0, 0, 100, 110));

    }

    void NpcController::NpcSpawn(sf::Texture &texture, Block _Block[WORLD_HEIGHT][WORLD_WIDTH]) {

        for (int i = 0; i < 200; ++i) {
            npcVec.push_back(new Npc);
            npcVec[i]->Number=i;
            npcVec[i]->npcInit(texture, _Block);
        }
    }

    void NpcController::NpcMoveAndSpawn(sf::Texture &texture, Block _Block[WORLD_HEIGHT][WORLD_WIDTH]) {
        RandomDir = static_cast<direction >(rand() % 4);

        for(auto n : npcVec) {
            /// If npc has been standing still for some time time, it respawns
            if (n->movementSpeed == 0){
                if(n->respawnCounter == n->coolDown){
                    n->respawnCounter = 0;
                    int tempNum = n->Number;
                    delete(n);
                    npcVec.push_back(new Npc);
                    n->Number = tempNum;
                    n->npcInit(texture, _Block);
//                    i->getNpvBot().setColor(NpvController::Loader());

                }
                n->respawnCounter++;
            }
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



            /// Npc collision with player in car
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

     std::vector<Npc *> &NpcController::getNpcVec()  {
        return npcVec;
    }
}