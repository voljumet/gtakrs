#include <utility>
#include <algorithm>
#include "WorldState.h"
#include "DEFINITIONS.h"
#include "MainMenuState.h"
#include "Movement.h"
#include "colliderTest.h"
#include "WastedState.h"

/// Denne klassen er for WORLD

namespace GTA {

    WorldState::WorldState(GTA::GameDataRef data) : _data(std::move(data)) {}

    void WorldState::Init() {
        this->view.setSize(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
        this->view.setCenter(sf::Vector2f(SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f));

        this->minimap.setSize(sf::Vector2f(SCREEN_WIDTH * 2, SCREEN_HEIGHT * 2));
        this->minimap.setCenter(sf::Vector2f(SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f));
        this->minimap.setViewport(sf::FloatRect(0.79f,
                0.01f, 0.2f, 0.2f));

        this->getRektMap.setSize(sf::Vector2f(380, 340));
        this->getRektMap.setFillColor(sf::Color(0, 0, 0, 200));

        this->_data->assets.LoadTexture("Tiles", TILEMAP_PNG_FILEPATH);    // dependency injected directly *3
        this->_data->assets.LoadFont("Arial", FONT_ARIAL);
        map.Array(this->_data->assets.GetTexture("Tiles"), this->_data->assets.GetFont("Arial"));


        /// Loads audio
        sound.loadall();


        /// loads all the ogg files for the sound effects into soundbuffers that can be used when something happens

        ///Load Textures
        this->_data->assets.LoadTexture("Player", PLAYER);
        this->_data->assets.LoadTexture("Player2", PLAYER2);
        this->_data->assets.LoadTexture("Player3", PLAYER3);
        this->_data->assets.LoadTexture("Player4", PLAYER4);
        this->_data->assets.LoadTexture("Player5", PLAYER5);

        this->_data->assets.LoadTexture("Dead", DEAD_PLAYER);
        this->_data->assets.LoadTexture("car1", CAR_WHITE);
        this->_data->assets.LoadTexture("car", CAR_BLUE);
        this->_data->assets.LoadTexture("mission Circle", MISSION_CIRCLE_SPRITE);

        /// calls initcoin function from missionPlacement
        missionPlacement.hackMissionSettings();
//        missionPlacement.getText();


        this->_data->assets.LoadTexture("Bullet", BULLET_SPRITE);

        this->_data->assets.LoadTexture("HB", HEALTH_BAR);
        this->_data->assets.LoadTexture("HB1", HEALTH_BAR_1);

        this->_data->assets.LoadTexture("boat", BOAT);

        this->_data->assets.LoadTexture("M3_BLUE", M3_BLUE);
        this->_data->assets.LoadTexture("M3_RED", M3_RED);
        this->_data->assets.LoadTexture("M3_BLACK", M3_BLACK);
        this->_data->assets.LoadTexture("M3_SILVER", M3_SILVER);
        this->_data->assets.LoadTexture("M3_WHITE", M3_WHITE);


        player1 = this->_data->assets.GetTexture("Player");
        M3_White = this->_data->assets.GetTexture("M3_WHITE");
        M3_Black = this->_data->assets.GetTexture("M3_BLACK");
        M3_blue = this->_data->assets.GetTexture("M3_BLUE");
        M3_red = this->_data->assets.GetTexture("M3_RED");

        /// SET STARTING POSITION
        playerStartPosX = TILE_SIZE * 49;
        playerStartPosY = TILE_SIZE * 22;

        ///TESTING//////////////////////////////////////////////////////////////////////////////////////////////////

        weapon.Gun_init();

        weapon.gun_posX = TILE_SIZE * 51;
        weapon.gun_posY = TILE_SIZE * 23;
        weapon.gun.setPosition(weapon.gun_posX, weapon.gun_posY);

        ///TESTING////////////////////////////////////////////////////////////////////////////////////////////////

        /// Player Texture / Settings

        _player.playerInit(this->_data->assets.GetTexture("Player"));

        /// Player car Texture / Settings
        this->_car.setTexture(M3_White);      /// Set Texture
        this->_data->assets.GetTexture("M3_WHITE").setSmooth(true);

        this->_car.setPosition(playerStartPosX, playerStartPosY);
        this->_car.setTextureRect(sf::IntRect(0, 0, 91, 208));
        this->_car.setScale(sf::Vector2f(1.2f, 1.2f)); /// absolute scale factor
        this->_car.setOrigin(35.f, 50.f);
        this->_car.setRotation(180);

        /// Create NPCars
        carController.NpvSpawn(M3_White, map._Block);
//        carController.NpvSpawn(M3_Black, map._Block);
//        carController.NpvSpawn(M3_red, map._Block);
//        carController.NpvSpawn(M3_blue, map._Block);


//        carController.NpvSpawn(M3_White, M3_Black, M3_Silver, M3_Blue, M3_Red, map._Block);

        /// Create NPCaracters
        npcController.NpcSpawn(player1, map._Block);

//        npcController.NpcSpawn(player1,player2,player3,player4, player5, map._Block);

    }
    void WorldState::HandleInput() {

        /// npc Respawn and Move
        Timer = std::clock();
        drawtimerNPC +=1;
        if(drawtimerNPC == 5){
            npcController.NpcMoveAndSpawn(player1, map._Block);
            drawtimerNPC = 0;


        }
        NPCMoveDura += (std::clock() - Timer ) / (double) CLOCKS_PER_SEC;

        /// mission trigger
        if(PixelPerfectTest(missionPlacement.getMissionCircle(), _player.playerGetSprite())){
            mission = true;
            missionPlacement.infoBox(_player.playerGetSprite(), missionNumber);

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space )) {
                missionPlacement.missionStart(_data, _player, missionNumber, _player.playerGetSprite());
                std::cout << "Mission: " << missionNumber << std::endl;
            }
        }else {
            mission = false;
        }

        /// Car Respawn and Move
        Timer = std::clock();
        drawtimerNPV +=1;
        if(drawtimerNPV == 2){
            carController.NpvMoveAndSpawn(this->_data->assets.GetTexture("car"), map._Block);
            drawtimerNPV = 0;
        }
        NPVMoveDura += (std::clock() - Timer ) / (double) CLOCKS_PER_SEC;

        sf::Event event{};

        while (this->_data->window.pollEvent(event)) {
            if (event.type == sf::Event::Closed
                || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape &&
                    event.type == sf::Event::KeyReleased)) {
                map.~Map();     /// Destructer
                this->_data->window.close();
            }
        }
////////////////////////////////////

    if (event.key.code == sf::Keyboard::E && !Driving) { shooting.CreateBullet(_player.playerGetSprite()); }

////////////////////////////////////




        /// Change between person and car
        switch (event.type) {
            case sf::Event::KeyReleased: {
                switch (event.key.code) {
                    case sf::Keyboard::Space: {
                        if (!Driving) {
                            this->_car.setPosition(_player.player_Getposition());
                            this->_car.setRotation(this->_player.getRotaion());
                            Driving = true;
                           sound.PlaySound(sound.cardoor);
                        } else {
                            _player.player_SetPosition(this->_car.getPosition());
                            this->_player.setRotaion(this->_car.getRotation());
                            Driving = false;
                            sound.PlaySound(sound.cardoor);
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

        switch (event.type) {
            case sf::Event::KeyReleased: {
                switch (event.key.code) {
                    case sf::Keyboard::H: {
                        this->_player.intHealth-=50;

                    }
                }
            }
        }



        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {

            this->_data->machine.GetActiveState()->Pause();
            this->_data->machine.AddState(StateRef(new MainMenuState(_data)), false);
        }
        if(this->_player.intHealth == 0){
            this->_player.intHealth = 100;
            this->_data->machine.AddState(StateRef(new WastedState(_data)), true);

        }
    }

    void WorldState::Update(float dt) {         /// New state to replace this state
        UpdateMovement(_player.playerGetSprite(), this->_car);
        _player.playerVec(movement);

        /// Collision with buildings and static elements
//        _player.checkCollision();

        Timer = std::clock();

        playerCrashTEMP();
        PlayDura += (std::clock() - Timer ) / (double) CLOCKS_PER_SEC;

        collisionDetaction.Check_Collision(_car,_car2,true);
        collisionDetaction.Check_Collision(_car,_car3,true);
        collisionDetaction.Check_Collision(_player.playerGetSprite(),_car2,false);
        shooting.Collision(_data, npcController.npcVec, carController.npvVec ,shooting.bulletlist);
        shooting.MoveBullet();

        if(PixelPerfectTest(_player.playerGetSprite(), weapon.gun)){                             ///Dersom player plukker opp pistolen

            weapon.hasweapon=true;
            std::cout << "weapon is now ready" << std::endl;

            weapon.gun_posX = TILE_SIZE * 60;
            weapon.gun_posY = TILE_SIZE * 23;
            weapon.gun.setPosition(weapon.gun_posX, weapon.gun_posY);
            std::cout << "posx is " << weapon.gun_posX << std::endl;
            std::cout << "posy is " << weapon.gun_posY << std::endl;

        }
    }

    void WorldState::Draw(float dt) {

        this->UpdateView(dt);
        this->_data->window.setView(this->view);
        this->_data->window.clear(sf::Color::Black);        /// Clear window with a color

        /// Draw map as tiles
        Timer = std::clock();
        map.Render(Driving, Minimap, Debug, _car.getPosition().x,
                   _car.getPosition().y, _player.playerGetSprite().getPosition().x,
                   _player.playerGetSprite().getPosition().y, _data, NoDrivingOrWalkingBool);

        MapDura += (std::clock() - Timer ) / (double) CLOCKS_PER_SEC;

        this->_data->window.draw(missionPlacement.getMissionCircle());

        shooting.DrawBullet(_data);

        /// Draw NPCharacters
        Timer = std::clock();
        npcController.NpcDraw(_data, Driving,movement.currentSpeed, _car, _player.playerGetSprite(), sound.cardeath);

        NPCDura += (std::clock() - Timer ) / (double) CLOCKS_PER_SEC;

        /// Draw NPVehicles
        Timer = std::clock();
        carController.NpvDraw(_data, Driving,movement.currentSpeed, _car, _player.playerGetSprite(), sound.cardeath);


        NPVDura += (std::clock() - Timer ) / (double) CLOCKS_PER_SEC;

        /// NULL
        Timer = std::clock();
        for (int j = 0; j < 1; ++j) { NULLER = false; }
        NullDura += (std::clock() - Timer ) / (double) CLOCKS_PER_SEC;


        /// Draw Player or Vehicle
        if (!Driving) {_player.Draw(this->_data->window); } /// Draw Player
        else { this->_data->window.draw(this->_car); }  /// Draw Vehicle
        _player.HealthBar( this->_data->window,this->_data->assets.GetTexture("HB"),
                          this->_data->assets.GetTexture("HB1"),_car.getPosition(),Driving);


        this->_data->window.draw(weapon.gun);
        /////DRAW EVERY SPRITE IN THE LIST
        for (auto &i : spriteListy) { this->_data->window.draw(*i); }

        /// if mission equals to true, and player is out of circle the rectangle box disappears
        if(mission) {
            this->_data->window.draw(missionPlacement.getBox());
            this->_data->window.draw(missionPlacement.getText());

        }

        /////////Draw Minimap
        Timer = std::clock();
        if(!Debug){
            this->_data->window.draw(this->getRektMap);
            this->_data->window.setView(this->minimap);
            Minimap = true;
            map.Render(Driving, Minimap, Debug, _car.getPosition().x,
                       _car.getPosition().y, _player.playerGetSprite().getPosition().x,
                       _player.playerGetSprite().getPosition().y, _data, NoDrivingOrWalkingBool);
        }
        MmapDura += (std::clock() - Timer ) / (double) CLOCKS_PER_SEC;

        /// Draw Player or Car
        if (!Driving) { _player.Draw(this->_data->window); }
        else { this->_data->window.draw(this->_car); }

        this->_data->window.display();
        if(Debug){ PrintTimer(); }

    }

    /// husk å bruke view
    void WorldState::UpdateView(const float &dt){
        if(Driving){
            X = this->_car.getPosition().x;
            Y = this->_car.getPosition().y;
        } else {
            X = this->_player.player_Getposition().x;
            Y = this->_player.player_Getposition().y;
        }
        this->view.setCenter(X,Y);
        this->minimap.setCenter(X,Y);
        this->getRektMap.setPosition(X+=512,Y-=794);

    }

    void WorldState::UpdateMovement(sf::Sprite &walker, sf::Sprite &driver) {
        if (Driving) {
            driver.move(movement.movementVec * movement.currentSpeed * movement.dt);
            movement.Drive(this->_car);
        } else {
           _player.playerMoves(movement);
        }
    }

    void WorldState::playerCrashTEMP() {
        if(!Debug){
            if(Driving){
                mPosX = _car.getPosition().x / TILE_SIZE;
                mPosY = _car.getPosition().y / TILE_SIZE;
            } else {
                mPosX = _player.player_Getposition().x / TILE_SIZE;
                mPosY = _player.player_Getposition().y / TILE_SIZE;
            }

            fromX = mPosX - collisionReach;
            toX = mPosX + collisionReach;
            fromY = mPosY - collisionReach;
            toY = mPosY + collisionReach;

            if(fromX < 0){ fromX = 0; } else if (fromX >= WORLD_WIDTH){ fromX = WORLD_WIDTH -1; }
            if(fromY < 0){ fromY = 0; } else if (fromY >= WORLD_HEIGHT){ fromY = WORLD_HEIGHT -1; }
            if(toX < 0){ toX = 0; } else if (toX >= WORLD_WIDTH){ toX = WORLD_WIDTH -1; }
            if(toY < 0){ toY = 0; } else if (toY >= WORLD_HEIGHT){ toY = WORLD_HEIGHT -1; }

            for(int Y = fromY; Y < toY; Y++) {
                for (int X = fromX; X < toX; X++) {
                    NoDrivWalkInt = map._Block[Y][X].tileTextureNumber;
                    NoDrivingOrWalkingBool = std::find(std::begin(NoDrivingOrWalkingArray), std::end(NoDrivingOrWalkingArray), NoDrivWalkInt) != std::end(NoDrivingOrWalkingArray);
                    if(NoDrivingOrWalkingBool){
                        if(Driving){
                            collisionDetaction.Check_Collision(_car,map._Block[Y][X].tileSprite,false);
                        } else {
                            collisionDetaction.Check_Collision(_player.playerGetSprite(), map._Block[Y][X].tileSprite, false);
                        }
                    }
                }
            }
        }
    }

    void WorldState::PrintTimer() {
        timer +=1;
        if (timer == 60){
            std::cout << "Timer NPC Move: " << NPCMoveDura/60 << std::endl;
            std::cout << "Timer NPV Move: " << NPVMoveDura/60 << std::endl;
            std::cout << "Timer Draw Map: " << MapDura/60 << std::endl;
            std::cout << "Timer Draw miniMap: " << MmapDura/60 << std::endl;
            std::cout << "Timer Draw NPC: " << NPCDura/60 << std::endl;
            std::cout << "Timer Draw NPV: " << NPVDura/60 << std::endl;
            std::cout << "Timer PlayerCollision: " << PlayDura/60 << std::endl;
            std::cout << "Timer Controll: " << NullDura/60 << std::endl;

            std::cout << "--------------------- " << std::endl;
            MapDura = 0;
            MmapDura = 0;
            PlayDura = 0;
            NPCDura = 0;
            NPVDura = 0;
            NullDura = 0;
            NPVMoveDura = 0;
            NPCMoveDura = 0;

            timer = 0;
        }
    }
}

