#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

namespace GTA{
    class Bullet{
        sf::Sprite bullet;
        sf::Vector2f bulletVec;
        sf::Texture texture;
        float bulletspeed;

    public:
        sf::Sprite &getBullet()  { return bullet; }
        sf::Vector2f &getBulletVec()  { return bulletVec; }

        void setBullet( sf::Sprite &bullet) { Bullet::bullet = bullet; }
        void setBulletVec(sf::Vector2<float> bulletVec) { Bullet::bulletVec = bulletVec; }
        void setBulletspeed(float bulletspeed) { Bullet::bulletspeed = bulletspeed; }

        float getBulletspeed()  { return bulletspeed; }

    };
}
