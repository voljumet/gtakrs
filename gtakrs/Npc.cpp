#pragma once
#include <random>
#include <algorithm>
#include <iterator>
#include "Npc.h"


namespace GTA {
    Npc::Npc() = default;
    Npc::~Npc() = default;

    // Using a reference of texture works
    void Npc::npcInit(sf::Texture & texture) { // dependency injection method is the trick. *2
        dir = RIGHT;
        this->npcBot.setTexture(texture);
        this->npcBot.setPosition(TILE_SIZE * 49, TILE_SIZE * 25);
        this->npcBot.setTextureRect(sf::IntRect(0, 0,
                100, 100));
        this->npcBot.setScale(sf::Vector2f(1.0f, 1.0f));
        this->npcBot.setOrigin(50.f, 67.f);

    }

    sf::Sprite &Npc::getNpcBot() { return npcBot; }

    void Npc::move(Block _Block[109][115]) {
        CurrentPosX = npcBot.getPosition().x;
        CurrentPosY = npcBot.getPosition().y;

        walkRight = CurrentPosX + walkSpeed;
        walkLeft = CurrentPosX - walkSpeed;
        walkUp = CurrentPosY - walkSpeed;
        walkDown = CurrentPosY + walkSpeed;


        /// Generates random direction
        RANDIR = static_cast<direction >(rand() % 4);


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
        crashCurb = std::find(std::begin(curb), std::end(curb), NextNpcTile) != std::end(curb);

        /// if "crashCurb" is false, keep moving
        if(!crashCurb){
            npcBot.setPosition(UpdatedPosX, UpdatedPosY);
        } else {
            dir = RANDIR; /// set random Direction
        }

        /// Sets the rotation of the NPC
        if(dir == RIGHT){npcBot.setRotation(90);}
        else if (dir == LEFT){npcBot.setRotation(270);}
        else if (dir == UP){npcBot.setRotation(0);}
        else if (dir == DOWN){npcBot.setRotation(180);}

        /// NPC movement Animation
        npcBot.setTextureRect(sf::IntRect(0, WalkCounterForward * 110, 100, 110));

        SpriteSpeed++;
        if (SpriteSpeed == 8) {
            WalkCounterForward++;
            SpriteSpeed = 0;
        }

        if (WalkCounterForward == 5)
            WalkCounterForward = 1;

    }

}