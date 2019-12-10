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

    void setDamage();
    int setHealth();
    int setCoin();
    int setBullet();
    int loseBullet();
//    void checkCollision(bool Debug, bool Driving, );

    int intHealth = 100;
        bool playerIsDead = false;
private:
    friend class missionPlacement;
    sf::Sprite playerSprite;
    sf::RectangleShape healthBarRect;
    sf::RectangleShape bulletBarRect;
    sf::Font font;
    sf::Text text;
    sf::Text ammotext;
    int coin = 10;
    int bullet = 0;
    int healthSize = 227;

    sf::Sprite healthbarSprite, healthbarSprite1;
        int counter = 0;

    Collision_Detection collisionDetection;

};
}