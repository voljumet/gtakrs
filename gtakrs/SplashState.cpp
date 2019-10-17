#include <sstream>
#include <utility>
#include "SplashState.h"
#include "DEFINITIONS.h"
#include "MainMenuState.h"

/// Denne klassen er bare for splashstate i starten av spillet

namespace GTA{
    SplashState::SplashState(GTA::GameDataRef data ): _data(std::move( data )) { }

    void SplashState::Init() {
        this->_data->assets.LoadTexture("Splash State Background", SPLASH_SCENE_BACKGROUND_FILEPATH);   /// Load Texture
        _background.setTexture(this->_data->assets.GetTexture("Splash State Background"));      /// Set Texture

    }

    void SplashState::HandleInput() {
        sf::Event event{};

        while(this->_data->window.pollEvent(event)){
            if (sf::Event::Closed == event.type){ this->_data->window.close(); }      /// Handle if window is exited

        }
    }

    void SplashState::Update(float dt) {
        if(this->_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME){
            this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);        /// New state to replace this state
        }
    }

    void SplashState::Draw(float dt){
        this->_data->window.clear(sf::Color::Black);        /// Draw Color

        this->_data->window.draw(this->_background);        /// Draw Texture

        this->_data->window.display();      /// Display all
    }
}