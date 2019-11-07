#include <sstream>
#include "MainMenuState.h"
#include "DEFINITIONS.h"
#include "WorldState.h"
#include "Mission.h"



#include <iostream>

/// Denne klassen er MainMenu

namespace GTA{
    MainMenuState::MainMenuState(GameDataRef data) : _data(std::move(data)){ }

    void MainMenuState::Init() {
        this->view.setSize(sf::Vector2f(SCREEN_WIDTH,SCREEN_HEIGHT));
        this->view.setCenter(sf::Vector2f(SCREEN_WIDTH /2.f,SCREEN_HEIGHT/2.f));


        this->_data->assets.LoadTexture("Play button", MAIN_MENU_PLAY_BUTTON);  /// Load Texture
        this->_data->assets.LoadTexture("Resume Button", MAIN_MENU_LOAD_BUTTON);  /// Load Texture
        this->_data->assets.LoadTexture("Exit Button", MAIN_MENU_EXIT_BUTTON);  /// Load Texture
        this->_data->assets.LoadTexture("Game Title", MAIN_MENU_TITLE_PATH);    /// Load Texture

        this->_playButton.setTexture(this->_data->assets.GetTexture("Play button"));   /// Set Texture
        this->_resumeButton.setTexture(this->_data->assets.GetTexture("Resume Button"));   /// Set Texture
        this->_exitButton.setTexture(this->_data->assets.GetTexture("Exit Button"));   /// Set Texture
        this->_title.setTexture(this->_data->assets.GetTexture("Game Title"));         /// Set Texture

        this->_title.setPosition((SCREEN_WIDTH/2)-(this->_title.getGlobalBounds().width/2),this->_title.getGlobalBounds().height*0.1);     /// Set Position to title/logo

        this->_playButton.setPosition((SCREEN_WIDTH/2)-(this->_playButton.getGlobalBounds().width/2),(SCREEN_HEIGHT/2)-(this->_playButton.getGlobalBounds().height/2));   /// Set Position to buttons
        this->_resumeButton.setPosition((SCREEN_WIDTH / 2) - (this->_resumeButton.getGlobalBounds().width / 2), _playButton.getPosition().y + _playButton.getGlobalBounds().height);   /// Set Position to buttons
        this->_exitButton.setPosition((SCREEN_WIDTH/2)-(this->_exitButton.getGlobalBounds().width/2), _resumeButton.getPosition().y + _resumeButton.getGlobalBounds().height);   /// Set Position to buttons

    }

    void MainMenuState::HandleInput() {
        sf::Event event{};


        while (this->_data->window.pollEvent(event)){
            if(sf::Event::Closed == event.type){ this->_data->window.close(); }      /// Handle if window is exited

            if(this->_data->input.IsSpriteClicked(this->_playButton, sf::Mouse::Left, this->_data->window)){             /// Handle if button is pressed
                std::cout << "Play Game" << std::endl;

            }

            if(this->_data->input.IsSpriteClicked(this->_resumeButton, sf::Mouse::Left, this->_data->window)){             /// Handle if button is pressed
                std::cout << "Resume Game" << std::endl;
            }

            if(this->_data->input.IsSpriteClicked(this->_exitButton, sf::Mouse::Left, this->_data->window)){             /// Handle if button is pressed
                std::cout << "Exit Game" << std::endl;
                this->_data->window.close();
            }
        }
    }

    void MainMenuState::Update(float dt) {
        if(this->_data->input.IsSpriteClicked(this->_playButton, sf::Mouse::Left, this->_data->window) || sf::Keyboard::isKeyPressed(sf::Keyboard::P)){
            this->_data->machine.AddState(StateRef(new WorldState(_data)), true);        /// New state to replace the running state
        }

        if(this->_data->input.IsSpriteClicked(this->_resumeButton, sf::Mouse::Left, this->_data->window)){
            
            this->_data->machine.AddState(StateRef(new Mission(_data)), false);          ///Resume the last running game state
        }
    }

    void MainMenuState::Draw(float dt) {
        this->UpdateView(dt);
        this->_data->window.setView(this->view);
        this->_data->window.clear();      /// Clear all

        this->_data->window.draw(this->_title);        /// Draw Button
        this->_data->window.draw(this->_playButton);   /// Draw Button
        this->_data->window.draw(this->_resumeButton);   /// Draw Button
        this->_data->window.draw(this->_exitButton);   /// Draw Button

        this->_data->window.display();      /// Display all


    }

    void MainMenuState::UpdateView(const float &dt) {
        this->view.setCenter((SCREEN_WIDTH/2) , (SCREEN_HEIGHT/2));
    }

}