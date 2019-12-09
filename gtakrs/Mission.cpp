#include <utility>
#include <iostream>
#include "DEFINITIONS.h"
#include "MainMenuState.h"
#include "Mission.h"
#include "SpriteFactory.h"
#include <vector>
#include "WorldState.h"

namespace GTA{
    Mission::Mission(GTA::GameDataRef data): _data(std::move(data)) { }

    void Mission::Init() {

        this->view.setSize(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
        this->view.setCenter(sf::Vector2f(SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f));

        this->posX = SCREEN_WIDTH/2;
        this->posY = SCREEN_HEIGHT/2;
        this->movementspeed = 30.f;        ///Determins the movement speed of the scope
        this->spriteposX = posX +350.f;
        this->spriteposY = posY +700.f;
        this->steps = 0;
        dir = Right;                        ///Dir is an enum for direction, used for moving the sprite.

        ///Load texture for background.
        this->_data->assets.LoadTexture("Building", MISSION_1_BUILDING);
        _background.setTexture(this->_data->assets.GetTexture("Building"));
        this->_background.setPosition(posX, posY);

        ///Load texture for sprite.
        this->_data->assets.LoadTexture("Sprite", MISSION_1_SPRITE);
        _sprite.setTexture(this->_data->assets.GetTexture("Sprite"));
        this->_sprite.setPosition(posX + spriteposX, posY + spriteposY);

        ///Load texture for scope.
        this->_data->assets.LoadTexture("Scope", MISSION_1_SCOPE);
        _scope.setTexture(this->_data->assets.GetTexture("Scope"));

        ///Set position for scope and framerate limit for state.
        this->_data->window.setFramerateLimit(60);
        this->_scope.setPosition(0, 0);

    }

    ///Function to handle all input from player during state.
    void Mission::HandleInput() {

        ////////////////////////
//        Factory* factory = new SpriteFactory;
//        if(spritelist.size() <= 10){
//        spritelist.push_back(factory->CreateNPC());
//        for(auto s : spritelist) {
//            s->setPosition(rand() % 1000, rand() % 1000);
//            s->setTexture(this->_data->assets.GetTexture("Sprite"));
//            }
//        }
        ////////////////////////

        sf::Event event{};
        counter += 1;
        while (this->_data->window.pollEvent(event)) {
            _scope.setPosition(0,0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            posX -= movementspeed;
            spriteposX -= movementspeed;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            posX += movementspeed;
            spriteposX += movementspeed;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            posY += movementspeed;
            spriteposY += movementspeed;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            posY -= movementspeed;
            spriteposY -= movementspeed;
        }

        _background.setPosition(posX, posY);
        _sprite.setPosition(spriteposX, spriteposY);

        ///shape and spriteshape is circles enclosing the sprite and the middle of the screen.
        /// These are used to detect intersection between scope and target
        auto shape = new sf::CircleShape(2.f);
        auto spriteshape = new sf::CircleShape(185.f);

        shape->setPosition(SCREEN_WIDTH / 2 , SCREEN_HEIGHT / 2 );
        spriteshape->setPosition(spriteposX+145, spriteposY+100);


        ///if statement for shooting.
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {

            _scope.setPosition(0, -80);

            ///If statement checks if the target is in the crosshair.
            if(shape->getGlobalBounds().intersects(spriteshape->getGlobalBounds())) {
                ///Load texture for dead sprite.
                this->_data->assets.LoadTexture("Dead Sprite", MISSION_1_DEADSPRITE);
                _sprite.setTexture(this->_data->assets.GetTexture("Dead Sprite"));
                _scope.setPosition(0, -80);
                spriteisdead = true;
            }
        }


/// Handles movement of sprite
        if (!spriteisdead) {
            if (counter >= 10) {
                if (steps == 0) {
                    dir = Right;
                    counter = 0;
                }
                if (steps == 80) {
                    dir = Left;
                    counter = 0;
                }
            }

            switch (dir) {
                case Right :
                    spriteposX += 30;
                    steps += 1;
                    break;
                case Left :
                    spriteposX -= 30;
                    steps -= 1;
                    break;
            }
        }
    }


    ///Updates the
    void Mission::Update(float dt) {
        if(spriteisdead){
            std::cout << "rompa juice" << std::endl;
//            this->_data->machine.AddState(StateRef(new WorldState(_data)),
//                    true);
            this->_data->machine.RemoveState();
            this->_data->machine.GetActiveState()->Resume();
        }
    }

    ///Function used to draw elements in mission state
    void Mission::Draw(float dt) {
        this->_data->window.setView(this->view);
        this->_data->window.clear(sf::Color::White);
        this->_data->window.draw(this->_sprite);
        this->_data->window.draw(this->_background);
        this->_data->window.draw(this->_scope);
        for(auto &s: spritelist){
            this->_data->window.draw(*s);
        }
        this->_data->window.display();
    }
}
