

#include "Npc.h"
#include "iostream"

GTA::Npc::Npc() = default;
GTA::Npc::~Npc() = default;

namespace GTA {

    // Using a reference of texture works
    void Npc::spawnNpc(sf::Texture & texture) { // dependency injection method is the trick. *2
        std::cout << "stash 1" << std::endl;

        this->npcBot.setTexture(texture);
        this->npcBot.setPosition((tileSize  * 39) + tileSize/2, (tileSize * 9)+ tileSize/2);
        this->npcBot.setTextureRect(sf::IntRect(0, 0,
                100, 100));
        this->npcBot.setScale(sf::Vector2f(1.0f, 1.0f));
        this->npcBot.setOrigin(50.f, 67.f);

        npcWalkStart();
    }

    void Npc::npcWalkStart() {
        //GTA::aiController::npcPth();

    }
}


