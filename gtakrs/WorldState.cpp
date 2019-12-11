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

        loadAllTexture();
        this->getRektMap.setSize(sf::Vector2f(380, 340));
        this->getRektMap.setFillColor(sf::Color(0, 0, 0, 200));

        map.Array(this->_data->assets.GetTexture("Tiles"), this->_data->assets.GetFont("Arial"));


        /// Loads audio
        sound.loadall();
        sound.song.play();

        /// loads all the ogg files for the sound effects into soundbuffers that can be used when something happens
        // calls initcoin function from missionPlacement
        missionPlacement.hackMissionSettings();

        player1 = this->_data->assets.GetTexture("Player");
        M3_White = this->_data->assets.GetTexture("M3_WHITE");

        /// calls initcoin function from missionPlacement
        missionPlacement.hackMissionSettings();

        /// SET STARTING POSITION
        playerStartPosX = TILE_SIZE * 49;
        playerStartPosY = TILE_SIZE * 22;

        ///TESTING//////////////////////////////////////////////////////////////////////////////////////////////////
        weapon.Gun_init();
        weapon.setGunPosX(TILE_SIZE * 51) ;
        weapon.setGunPosY(TILE_SIZE * 23);
        weapon.getGun().setPosition(weapon.getGunPosX(), weapon.getGunPosY());

        weapon.setShotgunPosX(TILE_SIZE * 53) ;
        weapon.setShotgunPosY(TILE_SIZE * 23) ;
        weapon.getShotgun().setPosition(weapon.getShotgunPosX(), weapon.getShotgunPosY());

        objectSpawn.spawnPc();
        objectSpawn.getPc().setPosition(objectSpawn.getPcPox(), objectSpawn.getPcPoy());
        objectSpawn.spawnBurger();
        objectSpawn.getPc().setPosition(objectSpawn.getBurgerPox(), objectSpawn.getBurgerPoy());
        objectSpawn.spawnSniper();
        objectSpawn.getPc().setPosition(objectSpawn.getSniperPox(), objectSpawn.getSniperPoy());


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
///BOAT !!!!!!!!
        this->Boat.setTexture(this->_data->assets.GetTexture("boat"));
        this->Boat.setPosition(127*TILE_SIZE, 118*TILE_SIZE);
        this->Boat.setScale(1.2, 1.2);
        this->Boat.setRotation(90);

        /// Create NPVehicles
        npvController.NpvSpawn(M3_White, map._Block);

        /// Create NPCaracters
        npcController.NpcSpawn(player1, map._Block);

    }
    void WorldState::HandleInput() {
        sf::Event event{};

        /// Close window
        while (this->_data->window.pollEvent(event)) {
            if (event.type == sf::Event::Closed
                || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape &&
                    event.type == sf::Event::KeyReleased)) {
                map.~Map();
                this->_data->window.close();
            }
        }
////////////////////////////////////
    if (event.key.code == sf::Keyboard::E && !Driving) {
        if(weapon.isHasweapon()){
            _player.loseBullet();
            if(weapon.getGunammo()>0) {
                shooting.CreateBullet(_player.playerGetSprite());
                sound.PlaySound(sound.gunshot);
                weapon.setGunammo(weapon.getGunammo()-1);
                std::cout<<weapon.getGunammo()<<std::endl;
            }
            else{
                sound.PlaySound(sound.empty);
            }


        }
        if(weapon.isHasshotgun()){
            _player.loseBullet();
            if(weapon.getShotammo()>0) {
                shooting.CreateShotgunBullet(_player.playerGetSprite());
                sound.PlaySound(sound.spas);
                weapon.setShotammo(weapon.getShotammo()-1);
            }

            else{
                std::cout << "No bullets left" << std::endl;
                sound.PlaySound(sound.empty);
            }
        }
    }
    /// Change between person and car
//        if(Debug){
//            switch (event.type) {
//                case sf::Event::KeyReleased: {
//                    switch (event.key.code) {
//                        case sf::Keyboard::Space: {
//                            if (!Driving) {
//                                this->_car.setPosition(_player.player_Getposition());
//                                this->_car.setRotation(this->_player.getRotaion());
//                                Driving = true;
//                                sound.PlaySound(sound.cardoor);
//                            } else {
//                                _player.player_SetPosition(this->_car.getPosition());
//                                this->_player.setRotaion(this->_car.getRotation());
//                                Driving = false;
//                                sound.PlaySound(sound.cardoor);
//                            }
//                        }
//                    }
//                }
//            }
//        }

//        switch (event.type) {
//            case sf::Event::KeyReleased: {
//                switch (event.key.code) {
//                    case sf::Keyboard::Space: {
//                        if (!Driving && !boatbool) {
//
//                            this->_car.setPosition(_player.player_Getposition());
//                            this->_car.setRotation(this->_player.getRotaion());
//                            Driving = true;
//                            sound.PlaySound(sound.cardoor);
//
//                        } else if (!Driving && boatbool) {
//
//                            _player.player_SetPosition(this->_car.getPosition());
//                            this->_player.setRotaion(this->_car.getRotation());
//                            Driving = false;
//                            sound.PlaySound(sound.cardoor);
//                        }
//                    }
//                }
//            }
//        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::E) && GTA::PixelPerfectTest(_player.playerGetSprite(), Boat)){
            _car.setPosition(Boat.getPosition());
            _car.setRotation(Boat.getRotation());
            _car.setTexture(this->_data->assets.GetTexture("boat"));
            _car.setColor(sf::Color::White);
            _car.setTextureRect(sf::IntRect(0,0,400,430));
            _car.setOrigin(150, 100);
            Boat.setColor(sf::Color::Transparent);
            Driving = true;
            boatbool = true;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::R) && boatbool){
            _player.playerGetSprite().setPosition(182*TILE_SIZE,64*TILE_SIZE);
            _player.playerGetSprite().setRotation(_car.getRotation());
            _car.setTexture(this->_data->assets.GetTexture("M3_WHITE"));
            _car.setTextureRect(sf::IntRect(0,0,91, 208));
            _car.setOrigin(35.f, 50.f);
            Boat.setPosition(_car.getPosition());
            Boat.setTexture(this->_data->assets.GetTexture("boat"));
            Boat.setRotation(_car.getRotation());
            Boat.setColor(sf::Color::White);
            Driving = false;
            boatbool = false;
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

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            sound.song.stop();
            this->_data->machine.GetActiveState()->Pause();
            this->_data->machine.AddState(StateRef(new MainMenuState(_data)), false);
        }
    }

    void WorldState::Update(float dt) {         /// New state to replace this state

        /// If player dies
        if(_player.playerIsDead){ this->_data->machine.AddState(StateRef(new WastedState(_data)), true); }

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
            }
        }else {
            mission = false;
        }

        /// Car Respawn and Move
        Timer = std::clock();
        drawtimerNPV +=1;
        if(drawtimerNPV == 2){ npvController.NpvMoveAndSpawn(this->_data->assets.GetTexture("car"), map._Block);
            drawtimerNPV = 0;
        }
        NPVMoveDura += (std::clock() - Timer ) / (double) CLOCKS_PER_SEC;

        /// Timer control samle (stores a time that should be close to 0, if high, all numbers are off!)
        Timer = std::clock();
        for (int j = 0; j < 1; ++j) { NULLER = false; }
        NullDura += (std::clock() - Timer ) / (double) CLOCKS_PER_SEC;

        /// Update player movement
        UpdateMovement(_data, _player.playerGetSprite(), this->_car);
        _player.playerVec(movement);

        /// Player collision
        Timer = std::clock();
        playerCrashTEMP();
        PlayDura += (std::clock() - Timer ) / (double) CLOCKS_PER_SEC;

        /// Shooting
        shooting.Collision(_data, npcController.getNpcVec(), npvController.npvVec , shooting.getBulletlist());
        shooting.MoveBullet();

        /// Player picks up weapon
        if(PixelPerfectTest(_player.playerGetSprite(), weapon.getGun())){
            weapon.setHasweapon(1);
            weapon.setHasshotgun(0);
            _player.setBullet();
            weapon.setGunammo(30);

            weapon.setGunPosX((rand() % WORLD_WIDTH, rand() % WORLD_WIDTH)) ;
            weapon.setGunPosX((rand() % WORLD_HEIGHT, rand() % WORLD_HEIGHT)) ;
            weapon.getGun().setPosition(weapon.getGunPosX(), weapon.getGunPosY());

        }

        if(PixelPerfectTest(_player.playerGetSprite(), weapon.getShotgun())){
            weapon.setHasweapon(0);
            weapon.setHasshotgun(1);
            _player.setBullet();
            weapon.setShotammo(30);

            weapon.setShotgunPosX((rand() % WORLD_WIDTH, rand() % WORLD_WIDTH));
            weapon.setShotgunPosY( (rand() % WORLD_HEIGHT, rand() % WORLD_HEIGHT));
            weapon.getShotgun().setPosition(weapon.getShotgunPosX(), weapon.getShotgunPosY());

        }

        if(PixelPerfectTest(_player.playerGetSprite(), objectSpawn.getPc())){
            objectSpawn.setHasPc(1);

            objectSpawn.getPc().setPosition(objectSpawn.getPcPox(), objectSpawn.getPcPoy());
        }

        if(PixelPerfectTest(_player.playerGetSprite(), objectSpawn.getBurger())){
            objectSpawn.setHasBurger(1);
            objectSpawn.getBurger().setPosition(objectSpawn.getBurgerPox(), objectSpawn.getBurgerPoy());
        }

        if(PixelPerfectTest(_player.playerGetSprite(), objectSpawn.getSniper())){
            objectSpawn.setHasSniper(1);
            objectSpawn.getSniper().setPosition(objectSpawn.getSniperPox(), objectSpawn.getSniperPoy());
        }
    }

    void WorldState::Draw(float dt) {

        this->UpdateView(dt);
        this->_data->window.setView(this->view);
        this->_data->window.clear(sf::Color(62,137,201));        /// Clear window with a color

        /// Draw map as tiles
        Timer = std::clock();
        map.Render(Driving, Minimap, Debug, _car.getPosition().x,
                   _car.getPosition().y, _player.playerGetSprite().getPosition().x,
                   _player.playerGetSprite().getPosition().y, _data, NoDrivingOrWalkingBool);

        MapDura += (std::clock() - Timer ) / (double) CLOCKS_PER_SEC;

        /// Draw mission circle
        this->_data->window.draw(missionPlacement.getMissionCircle());

        /// Draw Bullets
        shooting.DrawBullet(_data);

        /// Draw NPCharacters
        Timer = std::clock();
        npcController.NpcDraw(_data, Driving,movement.currentSpeed, _car, _player.playerGetSprite(), sound.cardeath);
        NPCDura += (std::clock() - Timer ) / (double) CLOCKS_PER_SEC;

        /// Draw NPVehicles
        Timer = std::clock();

        npvController.NpvDraw(_data, Driving,movement.currentSpeed, _car, _player.playerGetSprite(), sound.cardeath,M3_White, map._Block, _player, boatbool,sound.tesla  );

        NPVDura += (std::clock() - Timer ) / (double) CLOCKS_PER_SEC;

        /// Draw Player or Vehicle
        if (!Driving) {_player.Draw(this->_data->window); } /// Draw Player
        else { this->_data->window.draw(this->_car); }  /// Draw Vehicle

        /// Draw Player healthbar and stats
        _player.HealthBar( this->_data->window,this->_data->assets.GetTexture("HB"),
                          this->_data->assets.GetTexture("HB1"),_car.getPosition(),Driving);

        /// Draw weapons
        this->_data->window.draw(weapon.getGun());
        this->_data->window.draw(weapon.getShotgun());

        /// Draw stuff

        this->_data->window.draw(objectSpawn.getPc());
        this->_data->window.draw(objectSpawn.getBurger());
        this->_data->window.draw(objectSpawn.getSniper());

        /// if mission equals true and player intesects circle, the rectangle box appears
        if(mission) { this->_data->window.draw(missionPlacement.getBox());
            this->_data->window.draw(missionPlacement.getText()); }

        ///Draw Boat.
        this->_data->window.draw(Boat);

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

        /// Draw mission circle
        this->_data->window.draw(missionPlacement.getMissionCircleMini());

        /// Draw Player or Car
        if (!Driving) { _player.Draw(this->_data->window); }
        else { this->_data->window.draw(this->_car); }

        this->_data->window.display();

        /// Print dtimer debug to console
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

    void WorldState::UpdateMovement(GameDataRef &inn_data, sf::Sprite &walker, sf::Sprite &driver) {
        if (Driving) {
            driver.move(movement.movementVec * movement.currentSpeed * movement.dt);
            movement.Drive(this->_car, sound.tesla);
        } else {
           _player.playerMoves(movement, sound.footstep);
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
//                    if(PixelPerfectTest(Boat,map._Block[Y][X].tileSprite))
//                    {
//
//                    }
                    NoDrivWalkInt = map._Block[Y][X].tileTextureNumber;
                    if(NoDrivWalkInt == 11 || NoDrivWalkInt == 12){
                        for (int j = 0; j < npcController.getNpcVec().size(); ++j) {
                            collisionDetection.Check_Collision( npcController.getNpcVec()[j]->getNpcBot(),map._Block[Y][X].tileSprite, false);

                            if(j < npvController.npvVec.size() ){
                                collisionDetection.Check_Collision( npvController.npvVec[j]->getNpvBot(),map._Block[Y][X].tileSprite, false);
                            }
                        }
                    }


                    if(boatbool) {
                        nocruising = std::find(std::begin(BOATCan_Not_MoveHere), std::end(BOATCan_Not_MoveHere),
                                               NoDrivWalkInt) != std::end(BOATCan_Not_MoveHere);
                        if (nocruising) {
                            if (Driving) {
                                collisionDetection.Check_Collision(_car, map._Block[Y][X].tileSprite, false);
                            } else {
                                collisionDetection.Check_Collision(_player.playerGetSprite(),
                                                                   map._Block[Y][X].tileSprite, false);
                            }
                        }
                    }else {
                        NoDrivingOrWalkingBool =
                                std::find(std::begin(NoDrivingOrWalkingArray), std::end(NoDrivingOrWalkingArray),
                                          NoDrivWalkInt) != std::end(NoDrivingOrWalkingArray);
                        if (NoDrivingOrWalkingBool) {
                            if (Driving) {
                                collisionDetection.Check_Collision(_car, map._Block[Y][X].tileSprite, false);
                            } else {
                                collisionDetection.Check_Collision(_player.playerGetSprite(),
                                                                   map._Block[Y][X].tileSprite, false);
                            }
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


    void WorldState::loadAllTexture() {

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


        this->_data->assets.LoadTexture("Bullet", BULLET_SPRITE);

        this->_data->assets.LoadTexture("HB", HEALTH_BAR);
        this->_data->assets.LoadTexture("HB1", HEALTH_BAR_1);

        this->_data->assets.LoadTexture("boat", BOAT);

        this->_data->assets.LoadTexture("M3_BLUE", M3_BLUE);
        this->_data->assets.LoadTexture("M3_RED", M3_RED);
        this->_data->assets.LoadTexture("M3_BLACK", M3_BLACK);
        this->_data->assets.LoadTexture("M3_SILVER", M3_SILVER);
        this->_data->assets.LoadTexture("M3_WHITE", M3_WHITE);

        this->_data->assets.LoadTexture("Tiles", TILEMAP_PNG_FILEPATH);    // dependency injected directly *3
        this->_data->assets.LoadFont("Arial", FONT_ARIAL);


    }

}


