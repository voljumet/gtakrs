#pragma once


#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

namespace GTA{
    class Bullet{
            sf::Sprite bullet;
            sf::Vector2f bulletVec;
    public:
         sf::Sprite &getBullet()  {
            return bullet;
        }

        void setBullet( sf::Sprite &bullet) {
            Bullet::bullet = bullet;
        }

         sf::Vector2f &getBulletVec()  {
            return bulletVec;
        }

        void setBulletVec(sf::Vector2<float> bulletVec) {
            Bullet::bulletVec = bulletVec;
        }

        float getBulletspeed()  {
            return bulletspeed;
        }

        void setBulletspeed(float bulletspeed) {
            Bullet::bulletspeed = bulletspeed;
        }

    private:
        float bulletspeed;
            sf::Texture texture;


    };
}
