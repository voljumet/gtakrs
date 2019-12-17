#include <sstream>
#include <utility>
#include "WastedState.h"
#include "DEFINITIONS.h"
#include "MainMenuState.h"

/// This class is only to show the WASTED screen if the player dies, and return to MainMenu
namespace GTA{
    WastedState::WastedState(GTA::GameDataRef data ): _data(std::move( data )) { }

    void WastedState::Init() {
        this->view.setSize(sf::Vector2f(SCREEN_WIDTH,SCREEN_HEIGHT));
        this->view.setCenter(sf::Vector2f(SCREEN_WIDTH /2.f,SCREEN_HEIGHT/2.f));

        this->_data->assets.LoadTexture("Wasted", WASTED_FILEPATH);   /// Load Texture
        _background.setTexture(this->_data->assets.GetTexture("Wasted"));      /// Set Texture

    }

    void WastedState::HandleInput() {
        sf::Event event{};

        while(this->_data->window.pollEvent(event)){
            if (sf::Event::Closed == event.type){ this->_data->window.close(); }      /// Handle if window is exited
        }
    }

    void WastedState::Update(float dt) {
        if(this->_clock.getElapsedTime().asSeconds() > WASTED_STATE_SHOW_TIME){
            this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);        /// New state to replace this state
        }
    }

    void WastedState::Draw(float dt){
        this->UpdateView(dt);
        this->_data->window.setView(this->view);
        this->_data->window.draw(this->_background);        /// Draw Texture
        this->_data->window.display();      /// Display all
    }

    void WastedState::UpdateView(const float &dt) {
        this->view.setCenter( (SCREEN_WIDTH/2) , (SCREEN_HEIGHT/2) );
    }

}