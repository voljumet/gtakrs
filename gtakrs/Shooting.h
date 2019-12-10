#pragma once

#include "Bullet.h"
#include "Movement.h"
#include "Game.h"
#include <SFML/Graphics/Texture.hpp>
#include "Npc.h"
#include "Npv.h"

namespace GTA {
    class Shooting {
    public:
        Movement movement;
        bool shotgun = false;
        std::vector<Bullet*> bulletlist;
        void CreateBullet(sf::Sprite &Player);
        void CreateShotgunBullet(sf::Sprite &Player);
        void MoveBullet();
        void DrawBullet(GameDataRef &inn_data);
        void Collision(GameDataRef &inn_data, std::vector<Npc*> &npclist,std::vector<Npv*> &npvlist, std::vector<Bullet*> &bulletlist);

    private:
        GameDataRef _data;
    };
}

