#pragma once

#include "Bullet.h"
#include "Movement.h"
#include "Game.h"
#include "Collision_Detection.h"
#include <SFML/Graphics/Texture.hpp>
#include "Npc.h"

namespace GTA {
    class Shooting {
    public:
        Movement movement;
        std::vector<Bullet*> bulletlist;
        void CreateBullet(sf::Sprite Player, sf::Texture texture);
        void MoveBullet();
        void DrawBullet(GameDataRef inn_data);
        void Collision(std::vector<Npc*> npclist, std::vector<Bullet*> bulletlist);

    private:
        GameDataRef _data;
        Collision_Detection collisionDetaction;
    };
}

