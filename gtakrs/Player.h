#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include "Movement.h"

namespace GTA{

class Player : Movement{
public:
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
    void HealthBar(sf::RenderWindow &renderWindow);
    float getRotaion();
    void setRotaion(float rotation);
//    void checkCollision(bool Debug, bool Driving, );
    int health = 100;
    bool dead = false;
private:

    sf::Sprite playerSprite;
    sf::RectangleShape healthBar;
    sf::Text text;
    sf::Font font;

};
}