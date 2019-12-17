#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include "Movement.h"
#include <sstream>
#include "Collision_Detection.h"

namespace GTA{
    class Player : Movement{
    public:
        friend class missionPlacement;
        Player();
        ~Player();

        void playerInit(sf::Texture &texture);
        void playerMoves(Movement& movement, sf::Sound &footstep);
        void Draw(sf::RenderWindow & renderWindow);
        void player_SetPosition(sf::Vector2f);
        void HealthBar(sf::RenderWindow &renderWindow,sf::Texture &healthbar, sf::Texture &healthbar1,sf::Vector2f pos, bool Driving);
        void setRotaion(float rotation);
        void setDamage();
        void Damage(int damage);

        sf::Sprite &playerGetSprite();
        sf::Vector2f player_Getposition();

        float playerVec( Movement &movement);
        float getRotaion();

        int setHealth();
        int setCoin();
        int setBullet();
        int loseBullet();

        bool playerIsDead = false;
    private:
        friend class missionPlacement;
        sf::Sprite playerSprite;
        sf::RectangleShape healthBarRect;
        sf::RectangleShape bulletBarRect;
        sf::Sprite healthbarSprite, healthbarSprite1;
        sf::Font font;
        sf::Text text;
        int coin = 0;
        int bullet = 0;
        int healthSize = 227;
        int counter = 0;

        GameDataRef  _data;
    };
}