#include <utility>
#include "DEFINITIONS.h"
#include "MainMenuState.h"
#include "Mission.h"
#include <vector>


namespace GTA{
    Mission::Mission(GTA::GameDataRef data): _data(std::move(data)) { }

    void Mission::Init() {
        this->view.setSize(sf::Vector2f(SCREEN_WIDTH,SCREEN_HEIGHT));


        this->posX = 900;
        this->posY = 900;
        this->movementspeed = 15.f;        ///Determins the movement speed of the scope
        this->spriteposX = 5200;
        this->spriteposY = 2200;
        this->steps = 0;
        dir = Right;                        ///Dir is an enum for direction, used for moving the sprite.

        ///Load texture for background.
        this->_data->assets.LoadTexture("Ground", MISSION_1_BACKGROUND);
        this->_data->assets.LoadTexture("Clouds", MISSION_1_CLOUDS);
        this->_data->assets.LoadTexture("Skyscrapers", MISSION_1_SKYSCRAPERS);
        this->_data->assets.LoadTexture("Houses", MISSION_1_HOUSES);
        this->_data->assets.LoadTexture("Trees", MISSION_1_TREES);

        _background.setTexture(this->_data->assets.GetTexture("Ground"));
        this->_background.setPosition(posX, posY);
        _background.setScale(10, 10);
        _background.setOrigin(0,0);

        ///Load texture for sprite.
        this->_data->assets.LoadTexture("Sprite", MISSION_1_SPRITE);
        _sprite.setTexture(this->_data->assets.GetTexture("Sprite"));
        _sprite.setScale(0.1, 0.1);
        this->_sprite.setPosition(spriteposX, spriteposY);

        ///Load texture for scope.
        this->_data->assets.LoadTexture("Scope", MISSION_1_SCOPE);
        _scope.setTexture(this->_data->assets.GetTexture("Scope"));

        this->_data->assets.LoadTexture("Houses", MISSION_1_HOUSES);
        houses.setTexture(this->_data->assets.GetTexture("Houses"));
        houses.setScale(10,10);
        houses.setPosition(900, 780);

        this->_data->assets.LoadTexture("skyscrapers", MISSION_1_SKYSCRAPERS);
        skyskrapers.setTexture(this->_data->assets.GetTexture("skyscrapers"));
        skyskrapers.setScale(10, 10);
        skyskrapers.setPosition(900,780);

        this->_data->assets.LoadTexture("Clouds", MISSION_1_CLOUDS);
        clouds.setTexture(this->_data->assets.GetTexture("Clouds"));
        clouds.setScale(10,10);
        clouds.setPosition(600, 400);

        this->_data->assets.LoadTexture("Trees", MISSION_1_TREES);
        trees.setTexture(this->_data->assets.GetTexture("Trees"));
        trees.setScale(10,10);
        trees.setPosition(900, 800);


        ///Set position for scope and framerate limit for state.
        this->_data->window.setFramerateLimit(60);
        this->_scope.setPosition(this->view.getCenter().x - SCREEN_WIDTH/2, this->view.getCenter().y - SCREEN_HEIGHT/2);

    }

    ///Function to handle all input from player during state.
    void Mission::HandleInput() {

        sf::Event event{};
        counter += 1;
        while (this->_data->window.pollEvent(event)) {
            _scope.setPosition(0,0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            posX += movementspeed;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            posX -= movementspeed;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            posY -= movementspeed;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            posY += movementspeed;
        }

//        _background.setPosition(posX, posY);
        _sprite.setPosition(spriteposX, spriteposY);
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
        }
        this->_scope.setPosition(this->view.getCenter().x - SCREEN_WIDTH/2, this->view.getCenter().y - SCREEN_HEIGHT/2);
    }



    ///Updates the
    void Mission::Update(float dt) {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
        }
    }

    ///Function used to draw elements in mission state
    void Mission::Draw(float dt) {
        this->UpdateView(dt);
        this->_data->window.setView(this->view);
        this->_data->window.clear(sf::Color::Transparent);

        this->_data->window.draw(this->_background);
        this->_data->window.draw(this->skyskrapers);
        this->_data->window.draw(this->houses);
////        this->_data->window.draw(this->cars);
        this->_data->window.draw(this->clouds);
        this->_data->window.draw(this->trees);
        this->_data->window.draw(this->_sprite);
        this->_data->window.draw(this->_scope);

        this->_data->window.display();
    }

    void Mission::UpdateView(const float &dt) {
        this->view.setCenter( (posX) , (posY) );
    }
}
