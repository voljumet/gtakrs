#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include "Movement.h"

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
    void HealthBar(sf::RenderWindow &renderWindow);
    float getRotaion();
    void setRotaion(float rotation);
private:
    friend class missionPlacement;
    sf::Sprite playerSprite;
    sf::RectangleShape healthBar;
    sf::Text text;
    sf::Font font;

};
}



