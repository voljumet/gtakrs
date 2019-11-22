#include <iostream>
#include "Player.h"
#include "DEFINITIONS.h"

namespace GTA{


    Player::Player()= default;

    Player::~Player()= default;

    void Player::playerInit(sf::Texture &texture) {
        this->playerSprite.setTexture(texture);         /// Set Texture for player
//        this->_data->assets.GetTexture("Player").setSmooth(true);
        this->playerSprite.setPosition((SCREEN_WIDTH), (SCREEN_HEIGHT));                /// Place player
        this->playerSprite.setTextureRect(sf::IntRect(0, 0, 100,
                                                 110));      /// Player rectangle load pictures from (0,0), size of rectangle (100x110)px
        this->playerSprite.setScale(sf::Vector2f(1.0f, 1.0f));                     /// player scale factor
        this->playerSprite.setOrigin(50.f, 67.f);
        font.loadFromFile(FONT_ARIAL);

    }



    void Player::playerMoves(Movement &movement) {
        playerSprite.move(movement.movementVec * movement.currentSpeed *movement.dt);
        movement.Walk(playerSprite);
    }

    sf::Vector2f Player::setplayerViewCenter(sf::Vector2f vector2F) {
        return  vector2F = sf::Vector2f(playerSprite.getPosition().x, playerSprite.getPosition().y);

    }

    void Player::Draw(sf::RenderWindow &renderWindow) {
        renderWindow.draw(playerSprite);


    }

    sf::Vector2f Player::player_Getposition() {
        return playerSprite.getPosition();
    }

    void Player::player_SetPosition(sf::Vector2f vf) {
        playerSprite.setPosition(vf);

    }

    sf::Sprite &Player::playerGetSprite() {
        return playerSprite ;
    }

    float Player::playerVec(Movement &movement) {
        return playerSprite.getRotation();
    }

    void Player::HealthBar(sf::RenderWindow &renderWindow) {
        healthBar.setFillColor(sf::Color::Red);
        healthBar.setSize(sf::Vector2f(200,20));
        healthBar.setPosition(playerSprite.getPosition().x -850,playerSprite.getPosition().y-750);
        renderWindow.draw(healthBar);
        healthBar.setOutlineColor(sf::Color::Black);
        healthBar.setOutlineThickness(6.f);

        text.setString("HEALTH");
        text.setScale(2,2);
        text.setFillColor(sf::Color::Black);
        text.setFont(font);
        text.setCharacterSize(15);
        text.setPosition(playerSprite.getPosition().x-850,playerSprite.getPosition().y-800);
        renderWindow.draw(text);
    }

    float Player::getRotaion() {
        return playerSprite.getRotation();

    }

    void Player::setRotaion(float rotation) {
        playerSprite.setRotation(rotation);

    }


}