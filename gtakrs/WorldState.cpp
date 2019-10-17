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

        /// Load Textures --------------------------------------------

        this->_data->assets.LoadTexture("Player_up", PLAYER_UP_1);
        this->_data->assets.LoadTexture("Player_up_1", PLAYER_UP_2);
        this->_data->assets.LoadTexture("Player_up_2", PLAYER_UP_3);

        this->_data->assets.LoadTexture("Player_down", PLAYER_DOWN_1);
        this->_data->assets.LoadTexture("Player_down_1", PLAYER_DOWN_2);
        this->_data->assets.LoadTexture("Player_down_2", PLAYER_DOWN_3);

        this->_data->assets.LoadTexture("Player_left", PLAYER_LEFT_1);
        this->_data->assets.LoadTexture("Player_left_1", PLAYER_LEFT_2);
        this->_data->assets.LoadTexture("Player_left_2", PLAYER_LEFT_3);

        this->_data->assets.LoadTexture("Player_right", PLAYER_RIGHT_1);
        this->_data->assets.LoadTexture("Player_right_1", PLAYER_RIGHT_2);
        this->_data->assets.LoadTexture("Player_right_2", PLAYER_RIGHT_3);


        _player.setTexture(this->_data->assets.GetTexture("Player_left"));      /// Set Texture
        this->_player.setPosition((SCREEN_WIDTH/2),(SCREEN_HEIGHT/2));

    }


    void WorldState::HandleInput() {
        sf::Event event{};


        while(this->_data->window.pollEvent(event)) {
            if (sf::Event::Closed == event.type) { this->_data->window.close(); }     /// Handle if window is exited


            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                oldy = 0; /// reset y-dir walking animation

                if(oldx == 0){
                    _player.setTexture(this->_data->assets.GetTexture("Player_right"));
                } else if(oldx < 4 && oldx > 0){
                    _player.setTexture(this->_data->assets.GetTexture("Player_right_1"));
                } else if(oldx > 4) {
                    _player.setTexture(this->_data->assets.GetTexture("Player_right_2"));
                } if(oldx >= 8){oldx = 0;}

                oldx++;
                this->_background.setPosition(x-=10,y);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
                oldy = 0;   /// reset y-dir walking animation
                if(oldx == 0){
                    _player.setTexture(this->_data->assets.GetTexture("Player_left"));
                } else if(oldx < 4 && oldx > 0){
                    _player.setTexture(this->_data->assets.GetTexture("Player_left_1"));
                } else if(oldx > 4) {
                    _player.setTexture(this->_data->assets.GetTexture("Player_left_2"));
                } if(oldx >= 8){oldx = 0;}

                oldx++;
                this->_background.setPosition(x+=10,y);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                oldx = 0;   /// reset x-dir walking animation
                if(oldy == 0){
                    _player.setTexture(this->_data->assets.GetTexture("Player_up"));
                } else if(oldy < 4 && oldy > 0){
                    _player.setTexture(this->_data->assets.GetTexture("Player_up_1"));
                } else if(oldy > 4) {
                    _player.setTexture(this->_data->assets.GetTexture("Player_up_2"));
                } if(oldy >= 8){oldy = 0;}

                oldy++;
                this->_background.setPosition(x,y+=10);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                oldx = 0;   /// reset x-dir walking animation
                if(oldy == 0){
                    _player.setTexture(this->_data->assets.GetTexture("Player_down"));
                } else if(oldy < 4 && oldy > 0){
                    _player.setTexture(this->_data->assets.GetTexture("Player_down_1"));
                } else if(oldy > 4) {
                    _player.setTexture(this->_data->assets.GetTexture("Player_down_2"));
                } if(oldy >= 8){oldy = 0;}

                oldy++;
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