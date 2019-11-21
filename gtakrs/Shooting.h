#pragma once

#include "Bullet.h"
#include "Movement.h"
#include <SFML/Graphics/Texture.hpp>

namespace GTA {
    class Shooting {
    public:
        Movement movement;
        Bullet bullet;
        std::vector<Bullet*> bulletlist;
        void CreateBullet(sf::Sprite Player);
        void MoveBullet();
    };
}

