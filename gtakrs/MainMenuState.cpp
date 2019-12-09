#include <sstream>
#include "MainMenuState.h"
#include "DEFINITIONS.h"
#include "WorldState.h"
#include "ControlsState.h"

#include "Hacking.h"

#include "Mission.h"

/// Denne klassen er MainMenu
namespace GTA{
    MainMenuState::MainMenuState(GameDataRef data) : _data(std::move(data)){ }

    void MainMenuState::Init() {
        this->view.setSize(sf::Vector2f(SCREEN_WIDTH,SCREEN_HEIGHT));
        this->view.setCenter(sf::Vector2f(SCREEN_WIDTH /2.f,SCREEN_HEIGHT/2.f));

        this->_data->assets.LoadTexture("Game Logo", MAIN_MENU_LOGO_PATH);    /// Load Texture
        this->_data->assets.LoadTexture("Play button", MAIN_MENU_PLAY_BUTTON);  /// Load Texture
        this->_data->assets.LoadTexture("Resume Button", MAIN_MENU_LOAD_BUTTON);  /// Load Texture
        this->_data->assets.LoadTexture("Exit Button", MAIN_MENU_EXIT_BUTTON);  /// Load Texture
        this->_data->assets.LoadTexture("Controls", MAIN_MENU_CONTROLS_BUTTON);    /// Load Texture

        this->_logo.setTexture(this->_data->assets.GetTexture("Game Logo"));         /// Set Texture
        this->_playButton.setTexture(this->_data->assets.GetTexture("Play button"));   /// Set Texture
        this->_resumeButton.setTexture(this->_data->assets.GetTexture("Resume Button"));   /// Set Texture
        this->_exitButton.setTexture(this->_data->assets.GetTexture("Exit Button"));   /// Set Texture
        this->_controlsButton.setTexture(this->_data->assets.GetTexture("Controls"));   /// Set Texture

        this->_logo.setPosition((SCREEN_WIDTH / 2) - (this->_logo.getGlobalBounds().width / 2), this->_logo.getGlobalBounds().height * 0.1);     /// Set Position to title/logo
        this->_playButton.setPosition((SCREEN_WIDTH/2)-(this->_playButton.getGlobalBounds().width/2),(SCREEN_HEIGHT/2)-(this->_playButton.getGlobalBounds().height/2));   /// Set Position to buttons
        this->_resumeButton.setPosition((SCREEN_WIDTH / 2) - (this->_resumeButton.getGlobalBounds().width / 2), _playButton.getPosition().y + _playButton.getGlobalBounds().height);   /// Set Position to buttons
        this->_controlsButton.setPosition((SCREEN_WIDTH/2)-(this->_controlsButton.getGlobalBounds().width/2), _resumeButton.getPosition().y + _resumeButton.getGlobalBounds().height);   /// Set Position to buttons
        this->_exitButton.setPosition((SCREEN_WIDTH/2)-(this->_exitButton.getGlobalBounds().width/2), _controlsButton.getPosition().y + _controlsButton.getGlobalBounds().height);   /// Set Position to buttons

    }

    void MainMenuState::HandleInput() {
        sf::Event event{};

        while (this->_data->window.pollEvent(event)){
            if(sf::Event::Closed == event.type){ this->_data->window.close(); }      /// Handle if window is exited

            if(this->_data->input.IsSpriteClicked(this->_playButton, sf::Mouse::Left, this->_data->window) || sf::Keyboard::isKeyPressed(sf::Keyboard::P)){
                this->_data->machine.AddState(StateRef(new WorldState(_data)), true);        /// New state to replace the running state
            }

            if(this->_data->input.IsSpriteClicked(this->_resumeButton, sf::Mouse::Left, this->_data->window)|| sf::Keyboard::isKeyPressed(sf::Keyboard::R)){
                this->_data->machine.GetActiveState()->Resume();
                this->_data->machine.RemoveState();
            }

            if(this->_data->input.IsSpriteClicked(this->_controlsButton, sf::Mouse::Left, this->_data->window)|| sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
                this->_data->machine.AddState(StateRef(new ControlsState(_data)), false);
                this->_data->machine.RemoveState();
            }

            if(this->_data->input.IsSpriteClicked(this->_exitButton, sf::Mouse::Left, this->_data->window)|| sf::Keyboard::isKeyPressed(sf::Keyboard::X)){             /// Handle if button is pressed
                this->_data->window.close();
            }

///////////////////////////////////////////////////////////////////////////////////

            if(event.key.code == sf::Keyboard::M){
                this->_data->machine.AddState(StateRef(new Hacking(_data)), true);        /// New state to replace the running state
            }

            if(event.key.code == sf::Keyboard::N){
                this->_data->machine.AddState(StateRef(new Mission(_data)), true);        /// New state to replace the running state
            }

///////////////////////////////////////////////////////////////////////////////////

        }
    }

    void MainMenuState::Update(float dt) {

    }

    void MainMenuState::Draw(float dt) {
        this->UpdateView(dt);
        this->_data->window.setView(this->view);
        this->_data->window.clear();      /// Clear all

        this->_data->window.draw(this->_logo);        /// Draw Button
        this->_data->window.draw(this->_playButton);   /// Draw Button
        this->_data->window.draw(this->_resumeButton);   /// Draw Button
        this->_data->window.draw(this->_controlsButton);   /// Draw Button
        this->_data->window.draw(this->_exitButton);   /// Draw Button

        this->_data->window.display();      /// Display all

    }

    void MainMenuState::UpdateView(const float &dt) {
        this->view.setCenter( (SCREEN_WIDTH/2) , (SCREEN_HEIGHT/2) );
    }
}