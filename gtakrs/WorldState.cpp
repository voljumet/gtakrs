#include <utility>
#include <algorithm>
#include "WorldState.h"
#include "DEFINITIONS.h"
#include "MainMenuState.h"
#include "Movement.h"
#include "colliderTest.h"

/// Denne klassen er for WORLD
class check_collision;

namespace GTA {

    WorldState::WorldState(GTA::GameDataRef data) : _data(std::move(data)) {}

    void WorldState::Init() {
        this->view.setSize(sf::Vector2f(SCREEN_WIDTH,SCREEN_HEIGHT));
        this->minimap.setSize(sf::Vector2f(SCREEN_WIDTH*2,SCREEN_HEIGHT*2));
        this->view.setCenter(sf::Vector2f(SCREEN_WIDTH /2.f,SCREEN_HEIGHT/2.f));
        this->minimap.setCenter(sf::Vector2f(SCREEN_WIDTH /2.f,SCREEN_HEIGHT/2.f));
        this->minimap.setViewport(sf::FloatRect(0.79f,0.01f , 0.2f, 0.2f));

        this->_data->assets.LoadTexture("Tiles", TILEMAP_PNG_FILEPATH);    // dependency injected directly *3
        this->_data->assets.LoadFont("Arial", FONT_ARIAL);
        map.Array(this->_data->assets.GetTexture("Tiles"), this->_data->assets.GetFont("Arial"));

        /// loads all the ogg files for the sound effects into soundbuffers that can be used when something happens
//        audio.loadAll();
//        this->_data->assets.LoadSound()

        ///Load Textures
        this->_data->assets.LoadTexture("Player", PLAYER);
        this->_data->assets.LoadTexture("Dead", DEAD_PLAYER);
        this->_data->assets.LoadTexture("car1", CAR_WHITE);
        this->_data->assets.LoadTexture("car", CAR_BLUE);

        playerStartPosX = TILE_SIZE * 49;
        playerStartPosY = TILE_SIZE * 22;

        /// Player Texture / Settings
        this->_player.setTexture(this->_data->assets.GetTexture("Player"));         /// Set Texture for player
        this->_data->assets.GetTexture("Player").setSmooth(true);
        this->_player.setPosition(playerStartPosX, playerStartPosY);                /// Place player
        this->_player.setTextureRect(sf::IntRect(0, 0, 100,110));      /// Player rectangle load pictures from (0,0), size of rectangle (100x110)px
        this->_player.setScale(sf::Vector2f(1.0f, 1.0f));                     /// player scale factor
        this->_player.setOrigin(50.f, 67.f);                                          /// Origin player position

        /// Player car Texture / Settings
        this->_car.setTexture(this->_data->assets.GetTexture("car1"));      /// Set Texture
        this->_data->assets.GetTexture("car1").setSmooth(true);

        this->_car.setPosition(playerStartPosX, playerStartPosY);
        this->_car.setTextureRect(sf::IntRect(0, 0, 100, 180));
        this->_car.setScale(sf::Vector2f(1.0f, 1.0f)); /// absolute scale factor
        this->_car.setOrigin(35.f, 50.f);
        this->_car.setColor(sf::Color(10,50,50));
//        this->_car.setRotation(180);
        GTA::CreateTextureAndBitmask(this->_data->assets.GetTexture("car1"), CAR_WHITE);

        ////NPC-Car 2 Texture / Settings
        this->_car2.setTexture(this->_data->assets.GetTexture("car"));      /// Set Texture
        this->_car2.setPosition(TILE_SIZE * 46, TILE_SIZE * 24);
        this->_car2.setTextureRect(sf::IntRect(0, 0, 100, 180));
        this->_car2.setRotation(90);
        this->_car2.setScale(sf::Vector2f(1.0f, 1.0f)); /// absolute scale factor
        this->_car2.setOrigin(50.f, 90.f);
        GTA::CreateTextureAndBitmask(this->_data->assets.GetTexture("car"), CAR_BLUE);

        ////NPC-Car 3 Texture / Settings
        this->_car3.setTexture(this->_data->assets.GetTexture("car"));      /// Set Texture
        this->_data->assets.GetTexture("car").setSmooth(true);
        this->_car3.setPosition(TILE_SIZE * 56, TILE_SIZE * 21);
        this->_car3.setTextureRect(sf::IntRect(0, 0, 100, 180));
        this->_car3.setRotation(-90);
        this->_car3.setScale(sf::Vector2f(1.0f, 1.0f)); /// absolute scale factor
        this->_car3.setOrigin(50.f, 90.f);
        this->_car3.setColor(sf::Color::Red);

        /// BUILDING COLLISION TEST
//        this->_buildings.set
//        this->_buildings.setPosition( TILE_SIZE * 54, TILE_SIZE * 26);
//        this->_buildings.setColor(sf::Color::Red);


        ////Add Sprites in to Sprite List
        spriteListy.push_back(&this->_car2);
        spriteListy.push_back(&this->_car3);

        /// Create NPCars
        for (int k = 0; k < 10; ++k) {
            npcCarVec.push_back(new NpcCar);
            npcCarVec[k]->npcCarInit(this->_data->assets.GetTexture("car1"), map._Block);
        }

        /// Create NPCaracters
        for (int i = 0; i < 55; ++i) {
            npcVec.push_back(new Npc);
            npcVec[i]->npcInit(this->_data->assets.GetTexture("Player"), map._Block);
        }


    }

    void WorldState::HandleInput() {

        /// npc
        for(auto n : npcVec) {
            if(!n->dead){
                n->move(map._Block);
            }
        }

        for(auto nop : npcCarVec) { nop->moveCar(map._Block); }


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
                            this->_car.setRotation(this->_player.getRotation());
                            Driving = true;
                            audio.playcardoor();
                        } else {
                            this->_player.setPosition(this->_car.getPosition());
                            this->_player.setRotation(this->_car.getRotation());
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
                        if (!Debug) {
                            Debug = true;
                        } else {
                            Debug = false;

                        }
                    }
                }
            }
        }

        UpdateMovement(this->_player, this->_car);


        if (this->GetCollider_car().Check_Collision(this->GetCollider_car_2(), 1.0f));
        if (this->GetCollider_player().Check_Collision(this->GetCollider_car_2(), 0.0f));


        for(int Y = 0; Y < WORLD_HEIGHT; Y++) {
            for (int X = 0; X < WORLD_WIDTH; X++) {
                NoDrivWalkInt = map._Block[Y][X].tileTextureNumber;
                NoDrivingOrWalkingBool = std::find(std::begin(NoDrivingOrWalkingArray), std::end(NoDrivingOrWalkingArray), NoDrivWalkInt) != std::end(NoDrivingOrWalkingArray);
                if(NoDrivingOrWalkingBool){
                    if(Driving){
                        if (this->GetCollider_car().Check_Collision(map._Block[Y][X].tileSprite, 0.0f));
                    } else {
                        if (this->GetCollider_player().Check_Collision(map._Block[Y][X].tileSprite, 0.0f));

                    }
                }
            }
        }


        if (this->GetCollider_car().Check_Collision(this->GetCollider_car3(), 0.0f));

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
        map.Render(Driving, Minimap, Debug, _car.getPosition().x, _car.getPosition().y,
                _player.getPosition().x, _player.getPosition().y, map._Block, _data);

        this->_data->window.draw(this->_buildings);


        /// Draw NPCharacters
        for (auto &i : npcVec) {
            this->_data->window.draw(i->getNpcBot());

            /// Npc collision with car
            if(!i->dead){
                if(this->_car.getGlobalBounds().intersects(i->getNpcBot().getGlobalBounds())){
                    i->dead = true;
                    i->setNpcBot(this->_data->assets.GetTexture("Dead"));
//                i->dir = i->RandomDir;
                }
            }

            /// Kommer til å intersecte med seg selv?!?!?!? -----
//            for(auto &j : npcVec){
//                if(j->getNpcBot().getGlobalBounds().intersects(i->getNpcBot().getGlobalBounds())){
//                    j->dir = j->RandomDir;
//                }
//            }
        }

        /// Draw NPCars
        for (auto &i : npcCarVec) {
            this->_data->window.draw(i->getNpcCarBot());
        }

        /// Draw Player or Car
        if (!Driving) { this->_data->window.draw(this->_player); }
        else { this->_data->window.draw(this->_car); }

        /////DRAW EVERY SPRITE IN THE LIST
        for (auto &i : spriteListy) { this->_data->window.draw(*i); }

        /////////Draw Minimap
        if(!Debug){
            this->_data->window.setView(this->minimap);
            Minimap = true;
            map.Render(Driving, Minimap, Debug, _car.getPosition().x, _car.getPosition().y,
                       _player.getPosition().x, _player.getPosition().y, map._Block, _data);

        }

        /// Draw Player or Car
        if (!Driving) { this->_data->window.draw(this->_player); }
        else { this->_data->window.draw(this->_car); }

        /////DRAW EVERY SPRITE IN THE LIST
        for (auto &i : spriteListy) { this->_data->window.draw(*i); }


        this->_data->window.display();
    }

    /// husk å bruke view
    void WorldState::UpdateView(const float &dt){
        if(Driving){
            this->view.setCenter(this->_car.getPosition());
            this->minimap.setCenter(this->_car.getPosition());
        } else {
            this->view.setCenter(this->_player.getPosition());
            this->minimap.setCenter(this->_player.getPosition());
        }

    }

    void WorldState::UpdateMovement(sf::Sprite &walker, sf::Sprite &driver) {
        if (Driving) {
            driver.move(movement.movementVec * movement.currentSpeed * movement.dt);
            movement.Drive(this->_car);
        } else {
            walker.move(movement.movementVec * movement.currentSpeed * movement.dt);
            movement.Walk(this->_player);
        }

    }
}

