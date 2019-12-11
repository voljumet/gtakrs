#include <string>
#include <SFML/Window/Keyboard.hpp>
#include "Player.h"
#include "DEFINITIONS.h"
#include "colliderTest.h"


namespace GTA {


    Player::Player() = default;

    Player::~Player() = default;

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
        playerSprite.move(movement.movementVec * movement.currentSpeed * movement.dt);
        movement.Walk(playerSprite);
    }

    sf::Vector2f Player::setplayerViewCenter(sf::Vector2f vector2F) {
        return vector2F = sf::Vector2f(playerSprite.getPosition().x, playerSprite.getPosition().y);

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
        return playerSprite;
    }

    float Player::playerVec(Movement &movement) {
        return playerSprite.getRotation();
    }

    void
    Player::HealthBar(sf::RenderWindow &renderWindow, sf::Texture &healthbar, sf::Texture &healthbar1, sf::Vector2f pos,
                      bool Driving) {
        if (!Driving) {
            healthbarSprite1.setTexture(healthbar1);
            healthbarSprite1.setPosition(playerSprite.getPosition().x - 845, playerSprite.getPosition().y - 750);
            healthbarSprite1.setTextureRect(sf::IntRect(0, 0, 300, 250));
            renderWindow.draw(healthbarSprite1);
            ///// Red Bar
            healthBarRect.setFillColor(sf::Color::Red);
            healthBarRect.setSize(sf::Vector2f(healthSize, 25));
            healthBarRect.setPosition(playerSprite.getPosition().x - 775, playerSprite.getPosition().y - 723);
            renderWindow.draw(healthBarRect);
            /////////// bullet bar
            bulletBarRect.setFillColor(sf::Color::Black);
            bulletBarRect.setSize(sf::Vector2f(bullet, 25));
            bulletBarRect.setPosition(playerSprite.getPosition().x - 775, playerSprite.getPosition().y - 663);
            renderWindow.draw(bulletBarRect);

//            ammotext.setString(std::to_string(ammo));
//            ammotext.setScale(2, 2);
//            ammotext.setFillColor(sf::Color::White);
//            ammotext.setFont(font);
//            ammotext.setOutlineThickness(1);
//            ammotext.setCharacterSize(12);
//            ammotext.setPosition(playerSprite.getPosition().x - 770, playerSprite.getPosition().y - 663);
//            renderWindow.draw(ammotext);

            //////Coins
            text.setString(std::to_string(coin));
            text.setScale(2, 2);
            text.setFillColor(sf::Color::White);
            text.setFont(font);
            text.setOutlineThickness(1);
            text.setCharacterSize(12);
            text.setPosition(playerSprite.getPosition().x - 770, playerSprite.getPosition().y - 605);
            renderWindow.draw(text);


            healthbarSprite.setTexture(healthbar);
            healthbarSprite.setPosition(playerSprite.getPosition().x - 845, playerSprite.getPosition().y - 750);
            healthbarSprite.setTextureRect(sf::IntRect(0, 0, 300, 250));
            renderWindow.draw(healthbarSprite);
        } else {
            healthbarSprite1.setTexture(healthbar1);
            healthbarSprite1.setPosition(pos.x - 845, pos.y - 750);
            healthbarSprite1.setTextureRect(sf::IntRect(0, 0, 300, 250));
            renderWindow.draw(healthbarSprite1);
            ///// Red Bar
            healthBarRect.setFillColor(sf::Color::Red);
            healthBarRect.setSize(sf::Vector2f(healthSize , 25));
            healthBarRect.setPosition(pos.x - 775, pos.y - 723);
            renderWindow.draw(healthBarRect);
            /////////// bullet bar
            bulletBarRect.setFillColor(sf::Color::Black);
            bulletBarRect.setSize(sf::Vector2f(bullet, 25));
            bulletBarRect.setPosition(pos.x - 775, pos.y - 663);
            renderWindow.draw(bulletBarRect);

            //////Coins
            text.setString(std::to_string(coin));
            text.setScale(2, 2);
            text.setFillColor(sf::Color::White);
            text.setFont(font);
            text.setOutlineThickness(1);
            text.setCharacterSize(12);
            text.setPosition(pos.x - 770, pos.y - 605);
            renderWindow.draw(text);

            healthbarSprite.setTexture(healthbar);
            healthbarSprite.setPosition(pos.x - 845, pos.y - 750);
            healthbarSprite.setTextureRect(sf::IntRect(0, 0, 300, 250));
            renderWindow.draw(healthbarSprite);

        }
    }

    float Player::getRotaion() {
        return playerSprite.getRotation();

    }

    void Player::setRotaion(float rotation) {
        playerSprite.setRotation(rotation);

    }

    void Player::setDamage() {
        counter ++;
        if(counter == 10)
        {
            if(healthSize < 0){ healthSize = 0,playerIsDead = true; }
            else{
                healthSize -= 10;
                counter = 0;
            }
        }
    }

    int Player::setCoin() {
        return coin++;
    }

    int Player::setBullet() {
        if (bullet < 226){return bullet += 10;}
    }

    int Player::loseBullet(){
        if(bullet < 0){ bullet = 0; }
        else{bullet -= 10;}
    }

    int Player::setHealth()
    {
        counter++;
        if (counter == 100)
        {
        if (healthSize < 226){return healthSize += 10;}
        }

    }

    void Player::Damage(int damage) {
        healthSize -= damage;


    }


}