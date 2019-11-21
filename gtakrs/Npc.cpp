#include <algorithm>
#include <iterator>
#include "Npc.h"


namespace GTA {
    Npc::Npc() = default;
    Npc::~Npc() = default;

    // Using a reference of texture works
    void Npc::npcInit(sf::Texture & texture, Block _Block[WORLD_HEIGHT][WORLD_WIDTH]) { // dependency injection method is the trick. *2
        dir = RandomDir;
        this->npcBot.setTexture(texture);

        /// Spawn random
        while(!npcCheckWalkable){
            randomPosX = (rand() % WORLD_WIDTH, rand() % WORLD_WIDTH);
            randomPosY = (rand() % WORLD_HEIGHT, rand() % WORLD_HEIGHT);

            RandNpcTile = _Block[randomPosY][randomPosX].tileTextureNumber;

            /// IF True, break loop (true means that the tile is ok to spawn in)
            npcCheckWalkable = std::find(std::begin(npcCanSpawnHere), std::end(npcCanSpawnHere), RandNpcTile) != std::end(npcCanSpawnHere);
        }

        this->npcBot.setPosition(randomPosX * TILE_SIZE, randomPosY * TILE_SIZE);
        this->npcBot.setTextureRect(sf::IntRect(0, 0,100, 100));
        this->npcBot.setScale(sf::Vector2f(1.0f, 1.0f));
        this->npcBot.setOrigin(50.f, 67.f);
        npcCheckWalkable = false;
    }

    sf::Sprite &Npc::getNpcBot() { return npcBot; }

    void Npc::move(Block _Block[WORLD_HEIGHT][WORLD_WIDTH]) {
        CurrentPosX = npcBot.getPosition().x;
        CurrentPosY = npcBot.getPosition().y;

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

        NextNpcTile = _Block[NextPosY][NextPosX].tileTextureNumber;

        /// check if  "NextNpcPos" crashes with any of the variables in "curb"
        crashCurb = std::find(std::begin(npcCanNOTwalkHere), std::end(npcCanNOTwalkHere), NextNpcTile) != std::end(npcCanNOTwalkHere);

        /// if "crashCurb" is false, keep moving
        if(!crashCurb){
            npcBot.setPosition(UpdatedPosX, UpdatedPosY);
        } else {
            dir = RandomDir; /// set random Direction
        }
        npcStepsCounter++;
        if(npcStepsCounter == 500){
            dir = RandomDir;
            npcStepsCounter=0;
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
        std::cout << "dead!"<< std::endl;

        this->npcBot.setTexture(textura);
        npcBot.setTextureRect(sf::IntRect(0, 0, 100, 110));

    }

    void Npc::setNpcBot(sf::Vector2f vector2F) {

        npcBot.move(vector2F);
    }

}