#include <sstream>
#include "ControlsState.h"
#include "DEFINITIONS.h"
#include "MainMenuState.h"

/// Denne klassen er MainMenu
namespace GTA{
    ControlsState::ControlsState(GameDataRef data) : _data(std::move(data)){ }

    void ControlsState::Init() {
        this->view.setSize(sf::Vector2f(SCREEN_WIDTH,SCREEN_HEIGHT));
        this->view.setCenter(sf::Vector2f(SCREEN_WIDTH /2.f,SCREEN_HEIGHT/2.f));

        this->_data->assets.LoadTexture("Background", CONTROLS_FILEPATH);    /// Load Texture
        this->_data->assets.LoadTexture("Game Logo", MAIN_MENU_LOGO_PATH);    /// Load Texture
        this->_data->assets.LoadTexture("Back Button", MAIN_MENU_BACK_BUTTON);  /// Load Texture

        this->_background.setTexture(this->_data->assets.GetTexture("Background"));
        this->_logo.setTexture(this->_data->assets.GetTexture("Game Logo"));         /// Set Texture
        this->_logo.setScale(0.5,0.5);
        this->_backButton.setTexture(this->_data->assets.GetTexture("Back Button"));   /// Set Texture

        this->_background.setPosition(0,0);
        this->_logo.setPosition((SCREEN_WIDTH / 2) - (this->_logo.getGlobalBounds().width / 2), this->_logo.getGlobalBounds().height * 0.1);     /// Set Position to title/logo
        this->_backButton.setPosition(SCREEN_WIDTH-(this->_backButton.getGlobalBounds().width*1.5),SCREEN_HEIGHT-(this->_backButton.getGlobalBounds().height*2));   /// Set Position to buttons

    }

    void ControlsState::HandleInput() {
        sf::Event event{};

        while (this->_data->window.pollEvent(event)){
            if(sf::Event::Closed == event.type){ this->_data->window.close(); }      /// Handle if window is exited

            if(this->_data->input.IsSpriteClicked(this->_backButton, sf::Mouse::Left, this->_data->window) || sf::Keyboard::isKeyPressed(sf::Keyboard::B)){             /// Handle if button is pressed
                this->_data->machine.AddState(StateRef(new MainMenuState(_data)), false);
            }
        }
    }

    void ControlsState::Update(float dt) {
        if(this->_data->input.IsSpriteClicked(this->_backButton, sf::Mouse::Left, this->_data->window)|| sf::Keyboard::isKeyPressed(sf::Keyboard::B)){
            this->_data->machine.GetActiveState()->Resume();
            this->_data->machine.RemoveState();
        }

    }

    void ControlsState::Draw(float dt) {
        this->UpdateView(dt);
        this->_data->window.setView(this->view);
        this->_data->window.clear();      /// Clear all

        this->_data->window.draw(this->_background);        /// Draw Button
        this->_data->window.draw(this->_logo);        /// Draw Button
        this->_data->window.draw(this->_backButton);   /// Draw Button

        this->_data->window.display();      /// Display all
    }

    void ControlsState::UpdateView(const float &dt) {
        this->view.setCenter( (SCREEN_WIDTH/2) , (SCREEN_HEIGHT/2) );
    }
}



