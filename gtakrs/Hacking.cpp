#include <utility>
#include <iostream>
#include "DEFINITIONS.h"
#include "MainMenuState.h"
#include "Hacking.h"


namespace GTA{
    Hacking::Hacking(GTA::GameDataRef data): _data(std::move(data)) { }
    void Hacking::Init() {
        this->view.setSize(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
        this->view.setCenter(sf::Vector2f(SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f));

        hackaudio.loadall();
        hackaudio.playcomputer();

        this->posX = 0;
        this->posY = 0;
        this->correctpassword = false;
        int layer = 0;

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

                hackaudio.PlaySound(hackaudio.button);

                //std::remove_if(sounds.begin(), sounds.end(), [](sf::Sound&) {!sound.isPlaying()});
                ///get this working brutha


                if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
                    playerinput.clear();
                    this->_data->window.draw(playertext);
                }

                this->_data->window.draw(playertext);
            }


            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){

                //------------------------------------------------------------------------------------

                if((playerinput.compare("cd files"))==0){ /// CD FILES
                    layer = 1;
                    text.setString("cd files");
                }



                else if((playerinput.compare("cat confidential_files.txt"))==0){ /// CONFIDENTIAL FILES
                    layer = 11;
                    text.setString("$ area 51 alien list [LOCKED]\n"
                                   "$ the integer between 1 and 2 [LOCKED]\n"
                                   "$ obamas real name [LOCKED]");
                }


                else if((playerinput.compare("cd illuminati client list"))==0){ /// ILLUMINATI CLIENT LIST
                    layer = 12;
                    text.setString("cd illuminati client list");
                }



                else if((playerinput.compare("cd security"))==0){  /// CD SECURITY
                    layer = 13;
                    text.setString("cd security");
                }


                else if((playerinput.compare("cd camera recordings"))==0){ /// CD CAMERA RECORDINGS
                    layer = 132;
                    text.setString("cd camera recordings");
                }


                else if((playerinput.compare("cat passwords.txt"))==0){ /// CD PASSWORDS
                    layer = 131;
                    text.setString("$ gun depot password: gunny123\n"
                                   "$ gate password: epstein251\n"
                                   "$ P O T U S phone password: 11111111");
                }

                else if((playerinput.compare("cd locations"))==0){ /// CD PASSWORDS
                    layer = 130;
                    text.setString("Around 1st block north of the city \n");
                }


                else if((playerinput.compare("enter password"))==0){ /// ENTER PASSWORD
                    text.setString("please enter gate password: \n");
                }


                else if((playerinput.compare("epstein251"))==0){ /// IF THE USER ENTERS THE CORRECT PASSWORD
                    text.setString("password entered, gate opening \n"
                                   "have a nice day!\n");
                    correctpassword = true;
                    ///Exit the minigame after this perhaps?
                }


                //------------------------------------------------------------------------------------

                if (event.type == sf::Event::Closed
                    || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape &&
                        event.type == sf::Event::KeyReleased)) {

                    this->_data->window.close();
                }

                //------------------------------------------------------------------------------------
                if((playerinput.compare("ls"))==0) { /// list kommando

                    if(layer==1) { ///FILES
                        text.setString("$ confidential_files.txt\n"
                                       "$ illuminati client list\n"
                                       "$ security");
                    }

                    if(layer==11) { ///CONFIDENTIAL FILES
                        text.setString("$ area 51 alien list [LOCKED]\n"
                                       "$ the integer between 1 and 2 [LOCKED]\n"
                                       "$ obamas real name [LOCKED]");
                    }

                    if(layer==12) { ///ILLUMINATI LIST
                        text.setString("$ bill gates [locked]\n"
                                       "$ beyonce [locked]\n"
                                       "$ aron h haugen [locked]");
                    }

                    if(layer==13) { ///SECURITY
                        text.setString("$ passwords.txt\n"
                                       "$ camera recordings\n"
                                       "$ locations");
                    }

                    if(layer==132) { ///CAMERA RECORDINGS
                        text.setString("$ epic_fortnite-noscope.mp4[locked]\n"
                                       "$ 20-11-2019.mp4[locked]");
                    }

                    if(layer==131) { ///PASSWORDS
                        text.setString("$ gun depot password: gunny123\n"
                                       "$ gate password: epstein251\n"
                                       "$ P O T U S phone password: 11111111");
                    }


                }

                //------------------------------------------------------------------------------------

                if((playerinput.compare("cd .."))==0) { /// CD .. aka gå tilbake et steg

                    if(layer==1) {
                        layer = 1;
                        text.setString("files");
                    }

                    if(layer==11) {
                        layer = 1;
                        text.setString("files");}


                    if(layer==12) {
                        layer = 1;
                        text.setString("files");
                    }

                    if(layer==13) {
                        layer = 1;
                        text.setString("files");
                    }

                    if(layer==132) {
                        layer = 13;
                        text.setString("security");
                    }

                    if(layer==131) {
                        layer = 13;
                        text.setString("security");
                    }
                }
                playerinput.clear();
            }
        }
    }

    void Hacking::Update(float dt) {
        if(correctpassword || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            this->_data->machine.RemoveState();
            this->_data->machine.GetActiveState()->Resume();
            correctpassword = false;
            std::cout << "correct password " << std::endl;
            hackaudio.computersounds.stop();
        }
    }

    void Hacking::Draw(float dt) {
        this->_data->window.setView(this->view);
        this->_data->window.clear(sf::Color::Black);
        this->_data->window.draw(this->_background);
        this->_data->window.draw(text);
        this->_data->window.draw(playertext);
        this->_data->window.display();
    }
}