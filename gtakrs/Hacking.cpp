#include <utility>
#include <iostream>
#include <string>
#include "DEFINITIONS.h"
#include "MainMenuState.h"
#include "Hacking.h"



namespace GTA{
    Hacking::Hacking(GTA::GameDataRef data): _data(std::move(data)) { }
    void Hacking::Init() {



        this->posX = 0;
        this->posY = 0;
        this->correctpassword = false;


        this->_data->assets.LoadTexture("CRT", CRT_SCREEN); ///Loading background image of CRT
        _background.setTexture(this->_data->assets.GetTexture("CRT"));
        this->_background.setPosition(posX, posY);
        this->_background.setScale(2.093f, 2.0f);


        ///Loading font to use for the text in the terminal
        ///The font is uppercase only, so make sure to take that into consideration when you test for file navigation
        if (!font.loadFromFile(RETRO))
        {
            std::cout << "Cant load font from resources!" << std::endl;
        }
        text.setFont(font);
        playertext.setFont(font);

        text.setPosition(200,200);
        playertext.setPosition(200,500);
        text.setFillColor(sf::Color::Red);
        playertext.setFillColor(sf::Color::Green);
        text.setString("$ Enter command: \n"
                             "$ eg. ´cd files´ ");

        this->_data->window.setFramerateLimit(60);
    }

    void Hacking::HandleInput() {
        sf::Event event{};
        while(this->_data->window.pollEvent(event)) {

            if (event.type == sf::Event::TextEntered) {
                playerinput += event.text.unicode;
                playertext.setString(playerinput);

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
                    playerinput.clear();
                    this->_data->window.draw(playertext);
                }

                    this->_data->window.draw(playertext);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){

                if((playerinput.compare("cd files"))==0){ /// CD FILES
                    text.setString("$ confidential files\n"
                                   "$ illuminati client list\n"
                                   "$ security");
                }

                else if((playerinput.compare("cd confidential files"))==0){ /// CONFIDENTIAL FILES
                    text.setString("$ area 51 alien list [LOCKED]\n"
                                   "$ the integer between 1 and 2 [LOCKED]\n"
                                   "$ obamas real name [LOCKED]");
                }

               else if((playerinput.compare("cd illuminati client list"))==0){ /// ILLUMINATI CLIENT LIST
                    text.setString("$ bill gates\n"
                                   "$ beyonce\n"
                                   "$ aron h haugen");
                }

               else if((playerinput.compare("cd security"))==0){  /// CD SECURITY
                    text.setString("$ passwords\n"
                                   "$ camera recordings");
                }

               else if((playerinput.compare("cd camera recordings"))==0){ /// CD CAMERA RECORDINGS
                    text.setString("$ epic_fortnite-noscope.mp4\n"
                                   "$ 20-11-2019.mp4");
                }

               else if((playerinput.compare("cd passwords"))==0){ /// CD PASSWORDS
                    text.setString("$ gun depot password: gunny123\n"
                                   "$ gate password: epstein251\n"
                                   "$ P O T U S phone password: 11111111");
                }

               else if((playerinput.compare("enter password"))==0){ /// CD ENTER PASSWORD
                    text.setString("$ please enter gate password: \n");
                }

               else if((playerinput.compare("epstein251"))==0){ /// IF THE USER ENTERS THE CORRECT PASSWORD
                    text.setString("$ password entered, gate opening \n"
                                          "$ have a nice day!\n");
                    correctpassword = true;
                    ///Exit the minigame after this perhaps?
                }


                playerinput.clear();
            }




//            if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
//                this->_data->window.close();
//            }
        }
    }




    void Hacking::Update(float dt) {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);

        }
    }



    void Hacking::Draw(float dt) {
        this->_data->window.clear(sf::Color::Black);
        this->_data->window.draw(this->_background);
        this->_data->window.draw(text);
        this->_data->window.draw(playertext);
        this->_data->window.display();
    }




}