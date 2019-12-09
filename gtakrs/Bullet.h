#pragma once


#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

namespace GTA{
    class Bullet{
    public:
            sf::Sprite bullet;
            sf::Vector2f bulletVec;
            sf::Texture texture;
            float bulletspeed;
    };
}
