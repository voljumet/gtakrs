#include <sstream>
#include "MainMenuState.h"
#include "DEFINITIONS.h"
#include <iostream>

/// Denne klassen er MainMenu

namespace GTA{
    MainMenuState::MainMenuState(GameDataRef data) : _data(data){ }

    void MainMenuState::Init() {

        this->_data->assets.LoadTexture("Background", MAIN_MENU_BACKGROUND_FILEPATH);
        this->_data->assets.LoadTexture("Play button", MAIN_MENU_PLAY_BUTTON);
        this->_data->assets.LoadTexture("Load Button", MAIN_MENU_LOAD_BUTTON);
        this->_data->assets.LoadTexture("Exit Button", MAIN_MENU_EXIT_BUTTON);
        this->_data->assets.LoadTexture("Game Title", MAIN_MENU_TITLE_PATH);

        this->_background.setTexture(this->_data->assets.GetTexture("Background"));
        this->_playButton.setTexture(this->_data->assets.GetTexture("Play button"));
        this->_loadButton.setTexture(this->_data->assets.GetTexture("Load Button"));
        this->_exitButton.setTexture(this->_data->assets.GetTexture("Exit Button"));
        this->_title.setTexture(this->_data->assets.GetTexture("Game Title"));

        this->_playButton.setPosition((SCREEN_WIDTH/2)-(this->_playButton.getGlobalBounds().width/2),(SCREEN_HEIGHT/2)-(this->_playButton.getGlobalBounds().height/2));
        this->_loadButton.setPosition((SCREEN_WIDTH/2)-(this->_loadButton.getGlobalBounds().width/2),_playButton.getPosition().y+_playButton.getGlobalBounds().height);
        this->_exitButton.setPosition((SCREEN_WIDTH/2)-(this->_exitButton.getGlobalBounds().width/2),_loadButton.getPosition().y+_loadButton.getGlobalBounds().height);

        this->_title.setPosition((SCREEN_WIDTH/2)-(this->_title.getGlobalBounds().width/2),this->_title.getGlobalBounds().height*0.1);
    }

    void MainMenuState::HandleInput() {
        sf::Event event;

        while (this->_data->window.pollEvent(event)){
            if(sf::Event::Closed == event.type){
                this->_data->window.close();
            }

            if(this->_data->input.IsSpriteClicked(this->_playButton, sf::Mouse::Left, this->_data->window)){
                std::cout << "Play Game" << std::endl;
            }

            if(this->_data->input.IsSpriteClicked(this->_loadButton, sf::Mouse::Left, this->_data->window)){
                std::cout << "Load Game" << std::endl;
            }

            if(this->_data->input.IsSpriteClicked(this->_exitButton, sf::Mouse::Left, this->_data->window)){
                std::cout << "Exit Game" << std::endl;
                this->_data->window.close();
            }
        }
    }

    void MainMenuState::Update(float dt) { }

    void MainMenuState::Draw(float dt) {
        this->_data->window.clear();

        this->_data->window.draw(this->_playButton);

        this->_data->window.draw(this->_loadButton);
        this->_data->window.draw(this->_exitButton);
        this->_data->window.draw(this->_title);

        this->_data->window.display();

    }
}