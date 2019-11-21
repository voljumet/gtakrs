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
        this->view.setSize(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
        this->minimap.setSize(sf::Vector2f(SCREEN_WIDTH * 2, SCREEN_HEIGHT * 2));
        this->view.setCenter(sf::Vector2f(SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f));
        this->minimap.setCenter(sf::Vector2f(SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f));
        this->minimap.setViewport(sf::FloatRect(0.79f, 0.01f, 0.2f, 0.2f));

        this->_data->assets.LoadTexture("Tiles", TILEMAP_PNG_FILEPATH);    // dependency injected directly *3
        this->_data->assets.LoadFont("Arial", FONT_ARIAL);
        map.Array(this->_data->assets.GetTexture("Tiles"), this->_data->assets.GetFont("Arial"));



        /// loads all the ogg files for the sound effects into soundbuffers that can be used when something happens

        ///Load Textures
        this->_data->assets.LoadTexture("Player", PLAYER);
        this->_data->assets.LoadTexture("Dead", DEAD_PLAYER);
        this->_data->assets.LoadTexture("car1", CAR_WHITE);
        this->_data->assets.LoadTexture("car", CAR_BLUE);

        /// SET STARTING POSITION
        playerStartPosX = TILE_SIZE * 49;
        playerStartPosY = TILE_SIZE * 22;

        /// Player Texture / Settings

        player.playerInit(this->_data->assets.GetTexture("Player"));

        /// Player car Texture / Settings
        this->_car.setTexture(this->_data->assets.GetTexture("car1"));      /// Set Texture
        this->_data->assets.GetTexture("car1").setSmooth(true);

        this->_car.setPosition(playerStartPosX, playerStartPosY);
        this->_car.setTextureRect(sf::IntRect(0, 0, 100, 180));
        this->_car.setScale(sf::Vector2f(1.0f, 1.0f)); /// absolute scale factor
        this->_car.setOrigin(35.f, 50.f);
        this->_car.setColor(sf::Color(10,50,50));
        CreateTextureAndBitmask(this->_data->assets.GetTexture("car1"), CAR_WHITE);
        this->_car.setRotation(180);

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
            } else {
                n->RespawnTime -= 1;
                if (n->RespawnTime == 0){
                    n->npcInit(this->_data->assets.GetTexture("Player"), map._Block);
                    n->dead = false;
                    n->RespawnTime = 600;
                }
            }
        }

        for(auto nop : npcCarVec) { nop->moveCar(map._Block); }


        sf::Event event{};

        while (this->_data->window.pollEvent(event)) {
            if (event.type == sf::Event::Closed
                || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape &&
                    event.type == sf::Event::KeyReleased)) {
                map.~Map();     /// Destructer
                this->_data->window.close();
            }
        }

        /// Change between person and car
        switch (event.type) {
            case sf::Event::KeyReleased: {
                switch (event.key.code) {
                    case sf::Keyboard::Space: {
                        if (!Driving) {
                            this->_car.setPosition(player.player_Getposition());
                            this->_car.setRotation(this->player.getRotaion());
                            Driving = true;
//                            audio.playcardoor();
                        } else {
                            player.player_SetPosition(this->_car.getPosition());
                            this->player.setRotaion(this->_car.getRotation());
                            Driving = false;
                        }
                    }
                }
            }
        }

        /// Activate DEBUG-MODE
        switch (event.type) {
            case sf::Event::KeyReleased: {
                switch (event.key.code) {
                    case sf::Keyboard::G: {
                        if (!Debug) {
                            Debug = true;
                        } else {
                            Debug = false;

                        }
                    }
                }
            }
        }

        UpdateMovement(player.playerGetSprite(), this->_car);
        player.playerVec(movement);


        /// Collision with buildings and static elements
        for(int Y = 0; Y < WORLD_HEIGHT; Y++) {
            for (int X = 0; X < WORLD_WIDTH; X++) {
                NoDrivWalkInt = map._Block[Y][X].tileTextureNumber;
                NoDrivingOrWalkingBool = std::find(std::begin(NoDrivingOrWalkingArray), std::end(NoDrivingOrWalkingArray), NoDrivWalkInt) != std::end(NoDrivingOrWalkingArray);
                if(NoDrivingOrWalkingBool){
                    if(Driving){
                        collisionDetaction.Check_Collision(_car,map._Block[Y][X].tileSprite,false);

//                        if (PixelPerfectTest(this->_car,map._Block[Y][X].tileSprite)){
//                            this->_car.move(movement.movementVec * movement.currentSpeed * movement.dt);
//                        }
                    } else {
                        collisionDetaction.Check_Collision(player.playerGetSprite(),map._Block[Y][X].tileSprite,false);

//                        if (PixelPerfectTest(this->_player,map._Block[Y][X].tileSprite)){
//                            this->_player.move(sf::Vector2f(0,0));
//                        }
                    }
                }
            }
        }

            collisionDetaction.Check_Collision(_car,_car2,true);
            collisionDetaction.Check_Collision(_car,_car3,true);
            collisionDetaction.Check_Collision(player.playerGetSprite(),_car2,false);
            
        // npc
//        nonpc.move(map._Block);
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
                player.playerGetSprite().getPosition().x, player.playerGetSprite().getPosition().y, _data);

        /// Draw NPCharacters
        for (auto &i : npcVec) {
            this->_data->window.draw(i->getNpcBot());


            /// Npc collision with car
            if(!i->dead){
                if(Driving){
                    if(movement.currentSpeed <= 800){
                        collisionDetaction.Check_Collision(_car,i->getNpcBot(),true);
                    } else {
                        if(PixelPerfectTest(i->getNpcBot(),_car)){
                            i->dead = true;
                            i->setNpcBot(this->_data->assets.GetTexture("Dead"));
                        }
                    }
                } else {
//                        i->dir = i->RandomDir;
                    collisionDetaction.Check_Collision(player.playerGetSprite(),i->getNpcBot(),true);
                }
            }


            /// Kommer til å intersecte med seg selv?!?!?!? -----
//            for(auto &j : npcVec){
//                for(auto &k : npcVec){
//                    if(PixelPerfectTest(j->getNpcBot(),k->getNpcBot())){
////                    collisionDetaction.Check_Collision(j->getNpcBot(),k->getNpcBot(),true);
//                        j->dir = j->RandomDir;
//                    }
//                }
//            }
        }

        /// Draw NPCars
        for (auto &i : npcCarVec) {
            this->_data->window.draw(i->getNpcCarBot());

            /// Npc collision with car
            if(Driving){
//                if(movement.currentSpeed <= 800){
                    collisionDetaction.Check_Collision(_car,i->getNpcCarBot(),true);
//                } else {
//                    i->dead = true;
//                    i->setNpcCarBot(this->_data->assets.GetTexture("Dead"));
//                }
            } else {
//                    i->dir = i->RandomDir;
                collisionDetaction.Check_Collision(player.playerGetSprite(),i->getNpcCarBot(),false);
            }

        }

        /// Draw Player or Car
        if (!Driving) {player.Draw(this->_data->window); } /// Draw Player
        else { this->_data->window.draw(this->_car); }  /// Draw Car

        /////DRAW EVERY SPRITE IN THE LIST
        for (auto &i : spriteListy) { this->_data->window.draw(*i); }
        player.HealthBar( this->_data->window);

        /////////Draw Minimap
        if(!Debug){
            this->_data->window.setView(this->minimap);
            Minimap = true;
            map.Render(Driving, Minimap, Debug, _car.getPosition().x, _car.getPosition().y,
                       player.playerGetSprite().getPosition().x, player.playerGetSprite().getPosition().y, _data);

        }

        /// Draw Player or Car
        if (!Driving) { player.Draw(this->_data->window); }
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
            this->view.setCenter(this->player.player_Getposition());
            this->minimap.setCenter(this->player.player_Getposition());
        }

    }

    void WorldState::UpdateMovement(sf::Sprite &walker, sf::Sprite &driver) {
        if (Driving) {
            driver.move(movement.movementVec * movement.currentSpeed * movement.dt);
            movement.Drive(this->_car);

        } else {
           player.playerMoves(movement);
        }


    }
}

