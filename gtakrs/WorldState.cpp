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

        this->_data->assets.LoadTexture("Player_up", PLAYER_1);
        this->_data->assets.LoadTexture("Player_down", PLAYER_2);
        this->_data->assets.LoadTexture("Player_left", PLAYER_3);   /// Load Texture
        this->_data->assets.LoadTexture("Player_right", PLAYER_4);

        _player.setTexture(this->_data->assets.GetTexture("Player_left"));      /// Set Texture
        this->_player.setPosition((SCREEN_HEIGHT/2),(SCREEN_WIDTH/2));

    }


    void WorldState::HandleInput() {
        sf::Event event{};


        while(this->_data->window.pollEvent(event)) {
            if (sf::Event::Closed == event.type) { this->_data->window.close(); }     /// Handle if window is exited

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                _player.setTexture(this->_data->assets.GetTexture("Player_right"));
                this->_background.setPosition(x-=10,y);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
                _player.setTexture(this->_data->assets.GetTexture("Player_left"));
                this->_background.setPosition(x+=10,y);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                _player.setTexture(this->_data->assets.GetTexture("Player_up"));
                this->_background.setPosition(x,y+=10);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                _player.setTexture(this->_data->assets.GetTexture("Player_down"));
                this->_background.setPosition(x,y-=10);
            }



        }
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