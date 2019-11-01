#include <utility>
#include <iostream>


#include "WorldState.h"
#include "DEFINITIONS.h"
#include "MainMenuState.h"
#include <algorithm>
#include "collisionTest.h"


/// Denne klassen er for WORLD


namespace GTA {
    WorldState::WorldState(GTA::GameDataRef data) : _data(std::move(data)) {

    }

    void WorldState::Init() {
        this->view.setSize(sf::Vector2f(SCREEN_WIDTH,SCREEN_HEIGHT));
        this->view.setCenter(sf::Vector2f(SCREEN_WIDTH /2.f,SCREEN_HEIGHT/2.f));


        Map(); /// Load Map


        /// Player Texture / Sittings
        this->_data->assets.LoadTexture("Player", PLAYER);                            /// Load Texture for player
        this->_player.setTexture(this->_data->assets.GetTexture("Player"));         /// Set Texture for player
        this->_player.setPosition((SCREEN_WIDTH / 2), (SCREEN_HEIGHT / 2));                /// Place player
        this->_player.setTextureRect(sf::IntRect(0, 0, 100,
                                                 110));      /// Player rectangle load pictures from (0,0), size of rectangle (100x110)px
        this->_player.setScale(sf::Vector2f(1.0f, 1.0f));                     /// player scale factor
        this->_player.setOrigin(50.f, 67.f);                                          /// Origin player position


        /// CAR Texture / Sittings
        this->_data->assets.LoadTexture("car", CAR);   /// Load Texture
        _car.setTexture(this->_data->assets.GetTexture("car"));      /// Set Texture
        this->_car.setPosition(this->_data->window.getSize().x / 2, this->_data->window.getSize().y / 2);
        this->_car.setTextureRect(sf::IntRect(0, 0, 100, 180));
        this->_car.setScale(sf::Vector2f(1.0f, 1.0f)); // absolute scale factor
        this->_car.setOrigin(35.f, 50.f);


        ////Car 2 Texture / Sittings

        this->_data->assets.LoadTexture("car", CAR);   /// Load Texture
        _car2.setTexture(this->_data->assets.GetTexture("car"));      /// Set Texture
        this->_car2.setPosition(600, 600);
        this->_car2.setTextureRect(sf::IntRect(0, 0, 100, 180));
        this->_car2.setScale(sf::Vector2f(1.0f, 1.0f)); // absolute scale factor
        this->_car2.setOrigin(35.f, 50.f);

        //// Car 3 Texture / Sittings

        this->_data->assets.LoadTexture("car", CAR);   /// Load Texture
        _car3.setTexture(this->_data->assets.GetTexture("car"));      /// Set Texture
        this->_car3.setPosition(1400, 300);
        this->_car3.setTextureRect(sf::IntRect(0, 0, 100, 180));
        this->_car3.setScale(sf::Vector2f(1.0f, 1.0f)); // absolute scale factor
        this->_car3.setOrigin(35.f, 50.f);



        ////Add Sprites in to Sprite List
        spriteListy.push_back(&this->_car2);
        spriteListy.push_back(&this->_car3);

    }


    void WorldState::HandleInput() {
        sf::Event event{};
        const sf::Vector2f forwardVec(0.f, -WalkSpeed); //normal vec pointing forward
        while (this->_data->window.pollEvent(event)) {
            if (event.type == sf::Event::Closed
                || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape &&
                    event.type == sf::Event::KeyReleased))
                this->_data->window.close();
        }

        switch (event.type) {
            case sf::Event::KeyPressed:

                switch (event.key.code)
                    case sf::Keyboard::Space:
                        if (!Driving) {
                            this->_car.setPosition(this->_player.getPosition());
                            Driving = true; }
                        else if (Driving) {
                            this->_player.setPosition(this->_car.getPosition());
                            Driving = false; }

                break;

            case sf::Event::KeyReleased:
                switch (event.key.code)
                    case sf::Keyboard::Space:
                        if (!Driving) {
                            this->_car.setPosition(this->_player.getPosition());
                            Driving = true; }
                        else if (Driving) {
                            this->_player.setPosition(this->_car.getPosition());
                            Driving = false; }

        }



//        for (auto &i : spriteListy) {
//
//            if (!Driving) {
//                if (Collision::PixelPerfectTest(this->_player, *i) && Enter) {
//                    Driving = true;
//                    this->_car.setPosition(i->getPosition());
//                    i->setColor(sf::Color::Transparent);
//                }
//            }
//
//        }
        // if (Collision::PixelPerfectTest(this->_car, this->_car2))
        //   currentSpeed = 0;



///////////////////////////////////////////////////////////////////////
//////////////////WALKING Control//////////////////////////////////////

        if (!Driving) {

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                this->_player.rotate(-rotateAmount * dt);


            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                this->_player.rotate(rotateAmount * dt);

            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                this->_player.setTextureRect(sf::IntRect(0, WalkCounterForward * 110, 100, 110));
                if (currentSpeed < maxSpeed) {
                    currentSpeed = 300;
                }
                sf::Transform t;
                t.rotate(this->_player.getRotation());
                movementVec = t.transformPoint(-forwardVec);
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {

                this->_player.setTextureRect(sf::IntRect(0, WalkCounterForward * 110, 100, 110));
                if (currentSpeed < maxSpeed) {
                    currentSpeed = 300;
                }
                sf::Transform t;
                t.rotate(this->_player.getRotation());
                movementVec = t.transformPoint(forwardVec);
            } else {
                currentSpeed = 0.f;
                this->_player.setTextureRect(sf::IntRect(0, 0, 100, 110));

            }
            SpriteSpeed++;
            if (SpriteSpeed == 8) {
                WalkCounterForward++;
                SpriteSpeed = 0;
            }

            if (WalkCounterForward == 5)
                WalkCounterForward = 0;
        }

            /////////////////////////////////////////////////////////////////////////
            //////////////// DRIVING /////////////////////////
        else if (Driving) {



            if (up) {

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                    this->_car.rotate(-rotateAmount * dt);

                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                    this->_car.rotate(rotateAmount * dt);
                }

            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                up = true;
                currentSpeed -= deceleration * 2;
                if (currentSpeed < maxSpeed / 10)
                    currentSpeed = -maxSpeed / 5;
                sf::Transform t;
                t.rotate(this->_car.getRotation());
                movementVec = t.transformPoint(forwardVec);


            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                up = true;
                currentSpeed += acceleration;
                if (currentSpeed >= maxSpeed) {
                    currentSpeed = maxSpeed;
                }
                sf::Transform t;
                t.rotate(this->_car.getRotation());
                movementVec = t.transformPoint(forwardVec);

            } else {
                currentSpeed -= deceleration;
                if (currentSpeed < 10.f) {
                    currentSpeed = 0.f;
                    up = false;

                }

            }
        }

        ////////////////////////////////////
        ///////// Sprite Movement//////////

        if(Driving)
        {
            this->_car.move(movementVec * currentSpeed * dt);

        } else if (!Driving)
        {

            this->_player.move(movementVec * currentSpeed * dt);
        }


        //////////////////////////////////
        ///////// Collision ////////////

        if(this->_car.getGlobalBounds().intersects(this->_car2.getGlobalBounds()) )
        {
            std::cout<<"Collision"<<std::endl;
        }

    }


    void WorldState::Update(float dt) {         /// New state to replace this state
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            this->_data->machine.AddState(StateRef(new MainMenuState(_data)), false);
        }


    }

    void WorldState::Draw(float dt) {

        this->UpdateView(dt);
        this->_data->window.setView(this->view);
        this->_data->window.clear(sf::Color::Black);        /// Clear window with white color
        this->_data->window.draw(this->_map);      /// Draw map/ ground
        if (!Driving) { this->_data->window.draw(this->_player); }    /// Draw Player
        if (Driving) { this->_data->window.draw(this->_car); }          /// Draw Car
        /////DRAW EVERY SPRITE IN THE LIST

        for (auto &i : spriteListy) {
            this->_data->window.draw(*i);
        }

        this->_data->window.display();

    }


    void WorldState::Map() {

        file.open(MAP_FILE);
        for (int &i : MapArray) { file >> i; }
        file.close();

        /// Load Tileset---- if not loaded, load...
        if (!_map.load(MAP_TILE_FILEPATH, sf::Vector2u(
                70, 70),              /// Tile Size
                       MapArray,              /// Tile Array
                       90,                   /// MAP SIZE WIDTH (number of blocks) 90 is standard
                       1000))               /// MAP SIZE HEIGHT (number of blocks) 1000 is standard
            std::cout << "Error in Map loading!" << std::endl;

    }

    void WorldState::UpdateView(const float &dt)
    {
        if(Driving){this->view.setCenter(this->_car.getPosition());}
        else if (!Driving){this->view.setCenter(this->_player.getPosition());}
    }
}

