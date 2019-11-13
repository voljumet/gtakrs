#include <utility>
#include <algorithm>

#include "WorldState.h"
#include "DEFINITIONS.h"
#include "MainMenuState.h"
#include "Movement.h"
#include "colliderTest.h"

/// Denne klassen er for WORLD

namespace GTA {

    WorldState::WorldState(GTA::GameDataRef data) : _data(std::move(data)) {}

    void WorldState::Init() {
        this->view.setSize(sf::Vector2f(SCREEN_WIDTH,SCREEN_HEIGHT));
        this->minimap.setSize(sf::Vector2f(SCREEN_WIDTH*2,SCREEN_HEIGHT*2));
        this->view.setCenter(sf::Vector2f(SCREEN_WIDTH /2.f,SCREEN_HEIGHT/2.f));
        this->minimap.setCenter(sf::Vector2f(SCREEN_WIDTH /2.f,SCREEN_HEIGHT/2.f));
        this->minimap.setViewport(sf::FloatRect(0.79f,0.01f , 0.2f, 0.2f));

        this->_data->assets.LoadTexture("tiles", MAP_TILE_FILEPATH);    // dependency injected directly *3
        map.Array(this->_data->assets.GetTexture("tiles"));

        /// loads all the ogg files for the sound effects into soundbuffers that can be used when something happens
//        audio.loadall();

        /// Player Texture / Settings
        this->_data->assets.LoadTexture("Player", PLAYER);                            /// Load Texture for player
        this->_player.setTexture(this->_data->assets.GetTexture("Player"));         /// Set Texture for player
        this->_data->assets.GetTexture("Player").setSmooth(true);
        this->_player.setPosition((SCREEN_WIDTH), (SCREEN_HEIGHT));                /// Place player
        this->_player.setTextureRect(sf::IntRect(0, 0, 100,110));      /// Player rectangle load pictures from (0,0), size of rectangle (100x110)px
        this->_player.setScale(sf::Vector2f(1.0f, 1.0f));                     /// player scale factor
        this->_player.setOrigin(50.f, 67.f);                                          /// Origin player position

        /// Player car Texture / Settings
        this->_data->assets.LoadTexture("car1", CAR_WHITE);   /// Load Texture
        this->_car.setTexture(this->_data->assets.GetTexture("car1"));      /// Set Texture
        this->_data->assets.GetTexture("car1").setSmooth(true);
        this->_car.setPosition(_player.getPosition().x, _player.getPosition().y);
        this->_car.setTextureRect(sf::IntRect(0, 0, 100, 180));
        this->_car.setScale(sf::Vector2f(1.0f, 1.0f)); /// absolute scale factor

        this->_car.setOrigin(35.f, 50.f);
        this->_car.setColor(sf::Color(10,50,50));
        GTA::CreateTextureAndBitmask(this->_data->assets.GetTexture("car1"), CAR_WHITE);

        ////Car 2 Texture / Settings
        this->_data->assets.LoadTexture("car", CAR_BLUE);   /// Load Texture
        this->_car2.setTexture(this->_data->assets.GetTexture("car"));      /// Set Texture
        this->_car2.setPosition(TILE_SIZE * 30, TILE_SIZE * 7);
        this->_car2.setTextureRect(sf::IntRect(0, 0, 100, 180));
        this->_car2.setRotation(90);
        this->_car2.setScale(sf::Vector2f(1.0f, 1.0f)); /// absolute scale factor
        this->_car2.setOrigin(50.f, 90.f);
        GTA::CreateTextureAndBitmask(this->_data->assets.GetTexture("car"), CAR_BLUE);

        //// Car 3 Texture / Settings
        this->_car3.setTexture(this->_data->assets.GetTexture("car"));      /// Set Texture
        this->_data->assets.GetTexture("car").setSmooth(true);
        this->_car3.setPosition(1400, 500);
        this->_car3.setTextureRect(sf::IntRect(0, 0, 100, 180));
        this->_car3.setRotation(90);
        this->_car3.setScale(sf::Vector2f(1.0f, 1.0f)); /// absolute scale factor
        this->_car3.setOrigin(50.f, 90.f);
        this->_car3.setColor(sf::Color::Red);

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
                    event.type == sf::Event::KeyReleased)){
                map.~Map();     /// Destructer
                this->_data->window.close();
            }
        }

        /// Change between person and car
        switch (event.type) {
            case sf::Event::KeyReleased: {
                switch (event.key.code){
                    case sf::Keyboard::Space:{
                        if (!Driving) {
                            this->_car.setPosition(this->_player.getPosition());
                            Driving = true;
                            audio.playcardoor();
                        } else if (Driving) {
                            this->_player.setPosition(this->_car.getPosition());
                            Driving = false;
                            audio.playcardoor();
                            audio.playsong();
                        }
                    }
                }
            }
        }

        /// Activate DEBUG-MODE
        switch (event.type) {
            case sf::Event::KeyReleased:{
                switch (event.key.code){
                    case sf::Keyboard::G:{
                        if (!debug) {
                            debug = true;
                        } else if (debug) {
                            debug = false;

                        }
                    }
                }
            }
        }

        UpdateMovement(this->_player, this->_car);

        if (this->GetCollider_car().Check_Collision(this->GetCollider_car_2(), 1.0f));
        if (this->GetCollider_car().Check_Collision(this->GetCollider_car3(), 0.0f));
        if (this->GetCollider_player().Check_Collision(this->GetCollider_car_2(), 0.0f));
    }

    void WorldState::Update(float dt) {         /// New state to replace this state
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            this->_data->machine.GetActiveState()->Pause();
            this->_data->machine.AddState(StateRef(new MainMenuState(_data)), false);
        }
    }

    void WorldState::Draw(float dt) {

        this->UpdateView(dt);
        this->_data->window.setView(this->view);
        this->_data->window.clear(sf::Color::Black);        /// Clear window with a color

        /// Draw map as tiles
        MapRendering();

        if (!Driving) { this->_data->window.draw(this->_player); }    /// Draw Player
        if (Driving) { this->_data->window.draw(this->_car); }          /// Draw Car

        /////DRAW EVERY SPRITE IN THE LIST
        for (auto &i : spriteListy) { this->_data->window.draw(*i); }

        ///////// Minimap
        this->_data->window.setView(this->minimap);
        Minimap = true;
        MapRendering();

        if (!Driving) { this->_data->window.draw(this->_player); }    /// Draw Player
        if (Driving) { this->_data->window.draw(this->_car); }          /// Draw Car

        /////DRAW EVERY SPRITE IN THE LIST
        for (auto &i : spriteListy) {
            this->_data->window.draw(*i);
        }

        this->_data->window.display();
    }

    /// husk å bruke view
    void WorldState::UpdateView(const float &dt){
        if(Driving){this->view.setCenter(this->_car.getPosition());}
        else if (!Driving){this->view.setCenter(this->_player.getPosition());}

        if(Driving){this->minimap.setCenter(this->_car.getPosition());}
        else if (!Driving){this->minimap.setCenter(this->_player.getPosition());}

    }

    void WorldState::UpdateMovement(sf::Sprite &walker, sf::Sprite &driver) {
        if (Driving) {
            driver.move(movement.movementVec * movement.currentSpeed * movement.dt);

        } else if (!Driving) {
            walker.move(movement.movementVec * movement.currentSpeed * movement.dt);
        }
        if (!Driving) {
            movement.Walk(this->_player);
        } else {

            movement.Drive(this->_car);
        }
    }

    void WorldState::MapRendering() {
        if(Driving){
            posX = _car.getPosition().x / TILE_SIZE;
            posY = _car.getPosition().y / TILE_SIZE;
        } else {
            posX = _player.getPosition().x / TILE_SIZE;
            posY = _player.getPosition().y / TILE_SIZE;
        }
        if(!Minimap){
            fromX = posX - mapReach;
            toX = posX + mapReach;
            fromY = posY - mapReach;
            toY = posY + mapReach;
        } else {
            fromX = posX - miniMapReach;
            toX = posX + miniMapReach;
            fromY = posY - miniMapReach;
            toY = posY + miniMapReach;
            Minimap = false;
        }

        if(fromX < 0){ fromX = 0; } else if (fromX >= WORLD_WIDTH){ fromX = WORLD_WIDTH -1; }
        if(fromY < 0){ fromY = 0; } else if (fromY >= WORLD_HEIGHT){ fromY = WORLD_HEIGHT -1; }
        if(toX < 0){ toX = 0; } else if (toX >= WORLD_WIDTH){ toX = WORLD_WIDTH -1; }
        if(toY < 0){ toY = 0; } else if (toY >= WORLD_HEIGHT){ toY = WORLD_HEIGHT -1; }

        for(int Y = fromY; Y < toY; Y++) {
            for (int X = fromX; X < toX; X++) {
                /// Draw tiles
                this->_data->window.draw(this->map._Block[Y][X].tileSprite);

                if(debug){
                    this->_data->window.draw(this->map._Block[Y][X].getRekt);
                    this->_data->window.draw(this->map._Block[Y][X].text);
                }
            }
        }
    }


}

