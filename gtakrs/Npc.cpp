#include "Npc.h"
#include "WorldState.h"


namespace GTA {
    Npc::Npc() = default;
    Npc::~Npc() = default;

    Npc::Npc(GTA::GameDataRef data): _data(std::move(data)) { }

    // Using a reference of texture works
    void Npc::npcInit(sf::Texture & texture) { // dependency injection method is the trick. *2

        posX = TILE_SIZE * 31;
        posY = TILE_SIZE * 19;

        dir = RIGHT;
        std::cout << "stash 1" << std::endl;
        this->npcBot.setTexture(texture);
        this->npcBot.setPosition(posX, posY);
        this->npcBot.setTextureRect(sf::IntRect(0, 0,
                100, 100));
        sf::Vector2i getSource(1, RIGHT); //Default Sprite Sheet Crop
        this->npcBot.setScale(sf::Vector2f(1.0f, 1.0f));
        this->npcBot.setOrigin(50.f, 67.f);
        npcRotation();

        //PLAYER / ANIMATION SPEED
    }

    sf::Sprite &Npc::getNpcBot() {
        return npcBot;
    }

    void Npc::npcRotation() {
        npcBot.rotate(90.f);
    }

    void Npc::NpcPos(Block _Block[WORLD_HEIGHT][WORLD_WIDTH]) {

        posX = npcBot.getPosition().x /TILE_SIZE;
        posY = npcBot.getPosition().y/TILE_SIZE;

        if(_Block[posY][posX].tileTextureNumber == 1){
            npcRotation();
            dir = UP;
            stop = true;
        }

        if(_Block[posY][posX].tileTextureNumber == 2){
            npcRotation();
            dir = DOWN;
            stop = true;
        }

        if(_Block[posY][posX].tileTextureNumber == 3){

            getNpcBot().setPosition(getNpcBot().getPosition().x,
                                          getNpcBot().getPosition().y+1);

            npcRotation();
            dir = RIGHT;
            stop = true;
        }

        if(_Block[posY][posX].tileTextureNumber == 4){
            npcRotation();
            dir = LEFT;
        }

    }

    void Npc::move() {
        nyPosX = npcBot.getPosition().x;
        nyPosY = npcBot.getPosition().y;
        switch (dir){
            case LEFT:
                std::cout << "enum LEFT"<<std::endl;
                if(!stop){
                    npcBot.setPosition(nyPosX - walkSpeed,nyPosY);
                }
                break;
            case RIGHT:
                std::cout << "enum RIGHT"<<std::endl;
                if(!stop){
                    npcBot.setPosition(nyPosX + walkSpeed,nyPosY);
                }
                break;
            case UP:
                std::cout << "enum UP"<<std::endl;
                if(!stop){
                    npcBot.setPosition(nyPosX,nyPosY - walkSpeed);
                }
                break;
            case DOWN:
                std::cout << "enum DOWN"<<std::endl;
                if(!stop){
                    npcBot.setPosition(nyPosX,nyPosY + walkSpeed);
                }

        }
        // player movement
        npcBot.setTextureRect(sf::IntRect(0, WalkCounterForward * 110, 100, 110));

        SpriteSpeed++;
        if (SpriteSpeed == 10) {
            WalkCounterForward++;
            SpriteSpeed = 0;
        }

        if (WalkCounterForward == 5)
            WalkCounterForward = 1;

    }

}














/*    void Npc::npcWalkStart() {
        if (direction(UP)){
            std::cout << "turning stuff" << std::endl;
            npcBot.rotate(rotateAmount * dt);
            npcBot.setTextureRect(sf::IntRect(0, WalkCounterForward * 110,
                                              100, 110));
            if (currentSpeed < maxSpeed){
                currentSpeed = 300;
            }
            sf::Transform t;
            t.rotate(npcBot.getRotation());
            movementVec = t.transformPoint(-Movement::forwardVec());
        }
        else if(direction(DOWN)){
            std::cout << "turning south" << std::endl;
            npcBot.rotate(rotateAmount * dt);
            npcBot.setTextureRect(sf::IntRect(0, WalkCounterForward * 110,
                                              100, 110));
            if (currentSpeed < maxSpeed){
                currentSpeed = 300;
            }
            sf::Transform t;
            t.rotate(npcBot.getRotation());
            movementVec = t.transformPoint(-Movement::forwardVec());
        }
        else if(direction(LEFT)){
            std::cout << "turning south" << std::endl;
            npcBot.rotate(rotateAmount * dt);
            npcBot.setTextureRect(sf::IntRect(0, WalkCounterForward * 110,
                                              100, 110));
            if (currentSpeed < maxSpeed){
                currentSpeed = 300;
            }
            sf::Transform t;
            t.rotate(npcBot.getRotation());
            movementVec = t.transformPoint(-Movement::forwardVec());
        }

        else if(direction(RIGHT)){
            std::cout << "turning south" << std::endl;
            npcBot.rotate(rotateAmount * dt);
            npcBot.setTextureRect(sf::IntRect(0, WalkCounterForward * 110,
                                              100, 110));
            if (currentSpeed < maxSpeed){
                currentSpeed = 300;
            }
            sf::Transform t;
            t.rotate(npcBot.getRotation());
            movementVec = t.transformPoint(-Movement::forwardVec());
        }

        SpriteSpeed++;
        if (SpriteSpeed == 8) {
            WalkCounterForward++;
            SpriteSpeed = 0;
        }

        if (WalkCounterForward == 5)
            WalkCounterForward = 0;
    }*/