#include <utility>
#include <iostream>
#include "WorldState.h"
#include "DEFINITIONS.h"
#include "MainMenuState.h"

/// Denne klassen er for WORLD

namespace GTA{
    WorldState::WorldState(GTA::GameDataRef data ): _data(std::move( data )) { }

    void WorldState::Init() {
        this->_data->assets.LoadTexture("Map Background", MAP_BACKGROUND_FILEPATH);   /// Load Texture for background
        _background.setTexture(this->_data->assets.GetTexture("Map Background"));      /// Set Texture for background
        this->_background.setPosition(-(SCREEN_WIDTH/2),-(SCREEN_HEIGHT/2));      /// Place background


        this->_data->assets.LoadTexture("Player", PLAYER);   /// Load Texture for player
        _player.setTexture(this->_data->assets.GetTexture("Player"));      /// Set Texture for player
        this->_player.setPosition((SCREEN_WIDTH/2),(SCREEN_HEIGHT/2));          /// Place player
        this->_player.setTextureRect(sf::IntRect(0, 0, 100, 110));
        this->_player.setScale(sf::Vector2f(1.0f, 1.0f));         /// player scale factor
        this->_player.setOrigin(50.f, 67.f);        /// Origin player position
    }

    void WorldState::HandleInput() {
        Running();
    }

    void WorldState::Update(float dt) {         /// New state to replace this state
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            this->_data->machine.AddState(StateRef(new MainMenuState(_data)), false);
        }
    }

    void WorldState::Draw(float dt){
        this->_data->window.clear(sf::Color::White);        /// Draw Color

        this->_data->window.draw(this->_background);        /// Draw background
        this->_data->window.draw(this->_player);            /// Draw player

        this->_data->window.display();                      /// Display all
    }

    void WorldState::Running() {
        sf::Event event{};

        float dt = 0.01f;
        const sf::Vector2f forwardVec(0.f, -WalkSpeed);                 /// Normal vec pointing forward
        while (this->_data->window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
                this->_data->window.close();                                             /// Close window if one of the conditions above is true
        }

        /// set speed and direction from keyboard input
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) { this->_player.rotate(-rotateAmount * dt); }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { this->_player.rotate(rotateAmount * dt); }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            this->_player.setTextureRect(sf::IntRect(0, WalkCounterBackward * 110, 100, 110));
            if (currentSpeed < maxSpeed) {
                currentSpeed = 100;
            }

            sf::Transform t;
            t.rotate(this->_player.getRotation());
            movementVec = t.transformPoint(forwardVec);

            SpriteSpeed++;
            if (SpriteSpeed == 6) {     /// movement (higher number is slower)
                WalkCounterBackward--;
                SpriteSpeed = 0;
            }


        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {

            this->_player.setTextureRect(sf::IntRect(0, WalkCounterForward * 110, 100, 110));
            if (currentSpeed < maxSpeed) {
                currentSpeed = 300;
            }

            sf::Transform t;
            t.rotate(this->_player.getRotation());
            movementVec = t.transformPoint(-forwardVec);

            SpriteSpeed++;
            if (SpriteSpeed == 6) {     /// movement (higher number is slower)
                WalkCounterForward++;
                SpriteSpeed = 0;
            }

        } else {
            currentSpeed = 0.f;
            this->_player.setTextureRect(sf::IntRect(0, 0, 100, 110));

            /// Car deceleration
            //currentSpeed -= deceleration * dt;
            //if(currentSpeed < 0.f) currentSpeed = 0.f;
        }



        if (WalkCounterForward == 5 /*<--- number that decides how many pictures in walk animation*/) WalkCounterForward = 1;
        if (WalkCounterBackward == 1 /*<--- number that decides how many pictures in walk animation*/) WalkCounterBackward = 5;

        this->_background.move(movementVec * currentSpeed * dt);    /// Move background when walking
    }
}