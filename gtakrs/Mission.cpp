#include <utility>
#include "DEFINITIONS.h"
#include "MainMenuState.h"
#include "Mission.h"
#include <vector>
#include "WorldState.h"

namespace GTA{
    Mission::Mission(GTA::GameDataRef data): _data(std::move(data)) { }

    void Mission::Init() {
        this->view.setSize(sf::Vector2f(SCREEN_WIDTH,SCREEN_HEIGHT));


        this->movementspeed = 15.f;        ///Determins the movement speed of the scope
        this->spriteposX = 3600;
        this->spriteposY = 5100;

        this->steps = 0;
        dir = Right;                        ///Dir is an enum for direction, used for moving the sprite.

        ///Load texture for background.
        this->_data->assets.LoadTexture("Ground", MISSION_1_BACKGROUND_HQ);
        _background.setTexture(this->_data->assets.GetTexture("Ground"));
        this->_background.setPosition(SCREEN_HEIGHT/2.f, SCREEN_WIDTH/2.f);
        _background.setScale(scaleFactor, scaleFactor);
        _background.setOrigin(0,0);

        ///Load texture for sprite.
        this->_data->assets.LoadTexture("Sprite", MISSION_1_SPRITE);
        _sprite.setTexture(this->_data->assets.GetTexture("Sprite"));
        _sprite.setScale(0.2, 0.2);
        this->_sprite.setPosition(spriteposX, spriteposY);

        ///Load texture for scope.
        this->_data->assets.LoadTexture("Scope", MISSION_1_SCOPE);
        _scope.setTexture(this->_data->assets.GetTexture("Scope"));
        _scope.setPosition(SCREEN_WIDTH/3.f,SCREEN_HEIGHT/3.f);

        this->_data->assets.LoadTexture("Houses", MISSION_1_HOUSES_HQ);
        houses.setTexture(this->_data->assets.GetTexture("Houses"));
        houses.setScale(scaleFactor,scaleFactor);
        houses.setPosition(830, 900);

        this->_data->assets.LoadTexture("skyscrapers", MISSION_1_SKYSCRAPERS_HQ);
        skyskrapers.setTexture(this->_data->assets.GetTexture("skyscrapers"));
        skyskrapers.setScale(scaleFactor, scaleFactor);
        skyskrapers.setPosition(830,900);

        this->_data->assets.LoadTexture("Clouds", MISSION_1_CLOUDS_HQ);
        clouds.setTexture(this->_data->assets.GetTexture("Clouds"));
        clouds.setScale(scaleFactor,scaleFactor);
        clouds.setPosition(clouds1X, 400);

        clouds2.setTexture(this->_data->assets.GetTexture("Clouds"));
        clouds2.setScale(scaleFactor,scaleFactor);
        clouds2.setPosition(clouds2X, 200);


        this->_data->assets.LoadTexture("Trees", MISSION_1_TREES_HQ);
        trees.setTexture(this->_data->assets.GetTexture("Trees"));
        trees.setScale(scaleFactor,scaleFactor);
        trees.setPosition(900, 900);

        this->_data->assets.LoadTexture("Frame", MISSION_1_Frame_HQ);
        trees.setTexture(this->_data->assets.GetTexture("Frame"));
        trees.setScale(scaleFactor,scaleFactor);
        trees.setPosition(800, 900);


        ///Set position for scope and framerate limit for state.
        this->_data->window.setFramerateLimit(60);
        this->_scope.setPosition(this->view.getCenter().x - SCREEN_WIDTH/3, this->view.getCenter().y - SCREEN_HEIGHT/3);

    }

    ///Function to handle all input from player during state.
    void Mission::HandleInput() {

        sf::Event event{};
        counter += 1;
        while (this->_data->window.pollEvent(event)) {}
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                if(posX > 7800 ) { posX = 7800; }
                posX += movementspeed;

            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                if (posX < 1735) { posX = 1735; }
                posX -= movementspeed;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                if (posY < 1735) { posY = 1735; }
                posY -= movementspeed;

            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                if (posY > 6000) { posY = 6000; }
                posY += movementspeed;
            }


        _sprite.setPosition(spriteposX, spriteposY);
        clouds.setPosition(clouds1X, 400);
        clouds2.setPosition(clouds2X, 200);


        this->_scope.setPosition(this->view.getCenter().x - SCREEN_WIDTH/2, this->view.getCenter().y - SCREEN_HEIGHT/2);

        ///shape and spriteshape is circles enclosing the sprite and the middle of the screen.
        /// These are used to detect intersection between scope and target
        auto shape = new sf::CircleShape(2.f);
        shape->setPosition(this->view.getCenter());

        ///if statement for shooting.
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {


            ///If statement checks if the target is in the corsairs.
            if(shape->getGlobalBounds().intersects(this->_sprite.getGlobalBounds())) {

                ///Load texture for dead sprite.
                this->_data->assets.LoadTexture("Dead Sprite", MISSION_1_DEADSPRITE);
                _sprite.setTexture(this->_data->assets.GetTexture("Dead Sprite"));
                _scope.setPosition(0, -80);
                spriteisdead = true;
            }
        }


/// Handles movement of sprite
        if (!spriteisdead) {
            if (counter >= 3) {
                if (steps == 0) {
                    dir = Right;
                    counter = 0;
                }
                if (steps == 40) {
                    dir = Left;
                    counter = 0;
                }
            }

            switch (dir) {
                case Right :
                    spriteposX += 3;
                    steps += 1;
                    break;
                case Left :
                    spriteposX -= 3;
                    steps -= 1;
                    break;
            }

            clouds1X+=1;
            clouds2X+=3;

            if(clouds1X > 8000){
                clouds1X = -5000;
            }
            if(clouds2X > 8000){
                clouds2X = -5000;
            }
        }
    }


    ///Updates the
    void Mission::Update(float dt) {
        if(spriteisdead || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            this->_data->machine.RemoveState();
            this->_data->machine.GetActiveState()->Resume();
        }
    }

    ///Function used to draw elements in mission state
    void Mission::Draw(float dt) {
        this->_data->window.setView(this->view);
        this->UpdateView(dt);

        this->_data->window.clear(sf::Color(93,93,93));

        this->_data->window.draw(this->_background);
        this->_data->window.draw(this->skyskrapers);
        this->_data->window.draw(this->houses);
        this->_data->window.draw(this->clouds);
        this->_data->window.draw(this->clouds2);

        this->_data->window.draw(this->trees);
        this->_data->window.draw(this->_sprite);
        this->_data->window.draw(this->_scope);
        this->_data->window.draw(this->frame);


        this->_data->window.display();
    }

    void Mission::UpdateView(const float &dt) {

       this->view.setCenter( posX , posY );
    }
}
