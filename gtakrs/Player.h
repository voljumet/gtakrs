#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include "Movement.h"
#include <sstream>

namespace GTA{

class Player : Movement{
public:
    friend class missionPlacement;
    Player();
    ~Player();

    void playerInit(sf::Texture &texture); // loading texture
    void playerMoves(Movement& movement);
    sf::Vector2f setplayerViewCenter(sf::Vector2f);
    void Draw(sf::RenderWindow & renderWindow);
    sf::Vector2f player_Getposition();
    void player_SetPosition(sf::Vector2f);
    sf::Sprite &playerGetSprite();
    float playerVec( Movement &movement);
    void HealthBar(sf::RenderWindow &renderWindow,sf::Texture &healthbar,
            sf::Texture &healthbar1,sf::Vector2f pos, bool Deiving);
    float getRotaion();
    void setRotaion(float rotation);

    int getDamage();
    int getCoin();
    int getBullet();
    int loseBullet();
    int ammo;
//    void checkCollision(bool Debug, bool Driving, );

    int intHealth = 100;
private:
    friend class missionPlacement;
    sf::Sprite playerSprite;
    sf::RectangleShape healthBarRect;
    sf::RectangleShape bulletBarRect;
    sf::Font font;
    sf::Text text;
    int coin = 10;
    int bullet = 1;
    sf::Sprite healthbarSprite, healthbarSprite1;

};
}