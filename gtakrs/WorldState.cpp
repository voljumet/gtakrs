#include <utility>
#include <iostream>
#include "WorldState.h"
#include "DEFINITIONS.h"
#include "MainMenuState.h"

/// Denne klassen er bare for splashstate i starten av spillet

namespace GTA{
    WorldState::WorldState(GTA::GameDataRef data ): _data(std::move( data )) { }

    void WorldState::Init() {
        this->_data->assets.LoadTexture("Map Background", MAP_BACKGROUND_FILEPATH);   /// Load Texture
        _background.setTexture(this->_data->assets.GetTexture("Map Background"));      /// Set Texture
        this->_background.setPosition((SCREEN_WIDTH/2),(SCREEN_HEIGHT/2));

        this->_data->assets.LoadTexture("Player", PLAYER);   /// Load Texture
        _player.setTexture(this->_data->assets.GetTexture("Player"));      /// Set Texture

        /// Load Textures --------------------------------------------
    this->_data->window.setFramerateLimit(60);
        this->_player .setPosition(this->_data->window.getSize().x / 2, this->_data->window.getSize().y / 2);
        this->_player.setTextureRect(sf::IntRect(0, 0, 110, 110));
        this->_player.setScale(sf::Vector2f(1.0f, 1.0f)); // absolute scale factor
        this->_player.setOrigin(50.f, 50.f);
    }


    void WorldState::HandleInput() {
        sf::Event event{};

        //////////////////////////////////
        const sf::Vector2f forwardVec(0.f, -WalkCounter); //normal vec pointing forward
            while (this->_data->window.pollEvent(event)) {
                if (event.type == sf::Event::Closed
                    || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
                    this->_data->window.close();
            }

            //------------------------
           // float dt = Game::_clock.restart().asSeconds();
           float  dt = 0.01f;
        this->_data->window.clear();
            //set speed and direction from keyboard input
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                this->_player.rotate(-rotateAmount * dt);


            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                this->_player.rotate(rotateAmount * dt);

            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {

                this->_player.setTextureRect(sf::IntRect(0, WalkCounter * 120, 110, 110));
                if (currentSpeed < maxSpeed) {
                    currentSpeed = 300;
                }

                sf::Transform t;
                t.rotate(this->_player.getRotation());
                movementVec = t.transformPoint(-forwardVec);
                //this->_background.setPosition(x,y+=10);
            } else {
                currentSpeed = 0.f;
                this->_player.setTextureRect(sf::IntRect(0, 0, 110, 110));

                //CAR deceleration
                //currentSpeed -= deceleration * dt;
                //if(currentSpeed < 0.f) currentSpeed = 0.f;
            }
            SpriteSpeed++;
            if (SpriteSpeed == 5) {
                WalkCounter++;
                SpriteSpeed = 0;
            }

            if (WalkCounter == 6)
                WalkCounter = 0;



            //finally, move car
        //this->_player.move(movementVec * currentSpeed * dt);
        this->_background.move(movementVec*currentSpeed*dt);


            //-------draw-------------
          //  Game::_clock.restart();


       // this->_data->window.clear(sf::Color::White);
        this->_data->window.draw(this->_player); //Right
       //this->_data->window.display();



    }

    void WorldState::Update(float dt) {         /// New state to replace this state
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            this->_data->machine.AddState(StateRef(new MainMenuState(_data)), false);
        }
    }

    void WorldState::Draw(float dt){
        this->_data->window.clear(sf::Color::White);        /// Draw Color


        this->_data->window.draw(this->_background);        /// Draw Texture
        this->_data->window.draw(this->_player);

        this->_data->window.display();      /// Display all
    }
}