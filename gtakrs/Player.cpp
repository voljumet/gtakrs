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


    }

    void Player::playerMoves() {
        playerSprite.move(movement.movementVec * movement.currentSpeed * movement.dt);

    }
}