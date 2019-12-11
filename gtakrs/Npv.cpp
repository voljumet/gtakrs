#include <algorithm>
#include <iterator>
#include "Npv.h"
#include "Player.h"


namespace GTA {
    Npv::Npv() = default;
    Npv::~Npv() = default;

    void Npv::CarInit(sf::Texture &M3W, Block _Block[WORLD_HEIGHT][WORLD_WIDTH]) {
//        RandomDir = static_cast<direction >(rand() % 4);

        dir = RandomDir;
        movementSpeed = 8;
        spriteHeight = 208;
        spriteWidth = 91;

        /// Spawn random
        while (!CheckWalkable) {
            randomPosX = (rand() % WORLD_WIDTH, rand() % WORLD_WIDTH);
            randomPosY = (rand() % WORLD_HEIGHT, rand() % WORLD_HEIGHT);

            RandNpcTile = _Block[randomPosY][randomPosX].tileTextureNumber;

            /// IF True, break loop (true means that the tile is ok to spawn in)
            CheckWalkable = std::find(std::begin(Npv_Can_SpawnHere), std::end(Npv_Can_SpawnHere), RandNpcTile) !=
                            std::end(Npv_Can_SpawnHere);
        }

        this->npvBot.setTexture(M3W);

        this->npvBot.setPosition(randomPosX * TILE_SIZE, randomPosY * TILE_SIZE);
        this->npvBot.setTextureRect(sf::IntRect(0, 0, spriteWidth, spriteHeight));
        this->npvBot.setScale(sf::Vector2f(1.2f, 1.2f));
        this->npvBot.setOrigin(50.f, 67.f);
        health = 200;
    }

    sf::Sprite &Npv::getNpvBot() { return npvBot; }

    void Npv::moveCar(Block _Block[WORLD_HEIGHT][WORLD_WIDTH], std::vector<Npv *> &npvVec) {

        CurrentPosX = npvBot.getPosition().x;
        CurrentPosY = npvBot.getPosition().y;

        moveRight = CurrentPosX + movementSpeed;
        moveLeft = CurrentPosX - movementSpeed;
        moveUp = CurrentPosY - movementSpeed;
        moveDown = CurrentPosY + movementSpeed;

        /// Generates random direction
        RandomDir = static_cast<direction >(rand() % 4);

        /// FUNKER -------------------
        switch (dir) {
            case RIGHT : {
                NextPosX = (moveRight + 31) / TILE_SIZE;
                NextPosY = CurrentPosY / TILE_SIZE;
                UpdatedPosX = moveRight;
                UpdatedPosY = CurrentPosY;
                break;
            }
            case LEFT : {
                NextPosX = (moveLeft - 31) / TILE_SIZE;
                NextPosY = CurrentPosY / TILE_SIZE;
                UpdatedPosX = moveLeft;
                UpdatedPosY = CurrentPosY;
                break;
            }
            case UP : {
                NextPosX = CurrentPosX / TILE_SIZE;
                NextPosY = (moveUp - 31) / TILE_SIZE;
                UpdatedPosX = CurrentPosX;
                UpdatedPosY = moveUp;
                break;
            }
            case DOWN : {
                NextPosX = CurrentPosX / TILE_SIZE;
                NextPosY = (moveDown + 31) / TILE_SIZE;
                UpdatedPosX = CurrentPosX;
                UpdatedPosY = moveDown;
                break;
            }
        }

        /// Checks if tiles around NPV are movable
        NextTile = _Block[NextPosY][NextPosX].tileTextureNumber;

        NextTile_RIGHT = _Block[CurrentPosY / TILE_SIZE][(moveRight + 31) / TILE_SIZE].tileTextureNumber;
        NextTile_LEFT = _Block[CurrentPosY / TILE_SIZE][(moveLeft - 31) / TILE_SIZE].tileTextureNumber;
        NextTile_UP = _Block[(moveUp - 31) / TILE_SIZE][CurrentPosX / TILE_SIZE].tileTextureNumber;
        NextTile_DOWN = _Block[(moveUp + 31) / TILE_SIZE][CurrentPosX / TILE_SIZE].tileTextureNumber;

        /// If out of reach !!!!!!!!!!!!!!!!!!!
        if (dir < 0 || dir > 3) { dir = UP; }

        /// check if  "NextNpcPos" crashes with any of the variables in "curb"
        crashCurb_RIGHT = std::find(std::begin(NpvCan_Not_MoveHere), std::end(NpvCan_Not_MoveHere),NextTile_RIGHT) != std::end(NpvCan_Not_MoveHere);
        crashCurb_LEFT = std::find(std::begin(NpvCan_Not_MoveHere), std::end(NpvCan_Not_MoveHere),NextTile_LEFT) != std::end(NpvCan_Not_MoveHere);
        crashCurb_UP = std::find(std::begin(NpvCan_Not_MoveHere), std::end(NpvCan_Not_MoveHere),NextTile_UP) != std::end(NpvCan_Not_MoveHere);
        crashCurb_DOWN = std::find(std::begin(NpvCan_Not_MoveHere), std::end(NpvCan_Not_MoveHere),NextTile_DOWN) != std::end(NpvCan_Not_MoveHere);

        crashCurb = std::find(std::begin(NpvCan_Not_MoveHere), std::end(NpvCan_Not_MoveHere),NextTile) != std::end(NpvCan_Not_MoveHere);

        /// Check if tile in front of npv is ok
        if (crashCurb) {
            /// If all tiles around npv are non-movable, stand still
            if (crashCurb_RIGHT && crashCurb_LEFT && crashCurb_DOWN && crashCurb_UP){
                movementSpeed = 0;
                /// else change dir
            } else { dir = RandomDir;

            }
            /// If the tile in front of npc is ok, move
        } else  {
            npvBot.setPosition(UpdatedPosX, UpdatedPosY);
            StepCounter++;
        }

        /// change dir if colliding with other npv
        for(int i = 0; i < npvVec.size(); ++i) {
            if (npvVec[i]->NextPosX == NextPosX && npvVec[i]->NextPosY == NextPosY && npvVec[i]->Number != Number) {
                dir = RandomDir;
            }

            if(PixelPerfectTest(npvVec[i]->getNpvBot(), getNpvBot()) && npvVec[i]->Number != Number){
                dir = RandomDir;
                collisionDetaction.Check_Collision(npvVec[i]->getNpvBot(), getNpvBot(), true);
            }
        }

        /// How long should NPV move in one signle direction before turning around
        if (StepCounter == 500){ dir = RandomDir; StepCounter = 0; }

        /// Sets the rotation of the NPC
        if (dir == RIGHT) { npvBot.setRotation(90); }
        else if (dir == LEFT) { npvBot.setRotation(270); }
        else if (dir == UP) { npvBot.setRotation(0); }
        else if (dir == DOWN) { npvBot.setRotation(180); }

    }

    void NpvController::NpvSpawn(sf::Texture &M3W, Block _Block[WORLD_HEIGHT][WORLD_WIDTH]) {

        /// MUST BE 101 CARS FOR THE CODE TO WORK!!!
        for (int k = 0; k < 101; ++k) {

            npvVec.push_back(new Npv);
            npvVec[k]->Number = k;
            npvVec[k]->CarInit(M3W, _Block);
            npvVec[k]->getNpvBot().setColor(NpvController::Loader());
        }
    }

    void NpvController::NpvMoveAndSpawn(sf::Texture &_car, Block _Block[WORLD_HEIGHT][WORLD_WIDTH]) {
        for (auto nop : npvVec) {
            if (!nop->dead) {
                nop->moveCar(_Block, npvVec);
            } else {

                nop->RespawnTime -= 1;
                if (nop->RespawnTime == 0) {
                    nop->CarInit(_car, _Block);
                    nop->dead = false;
                    nop->RespawnTime = 600;
                    nop->getNpvBot().setColor(sf::Color::Red);
                }
            }
        }
    }

    sf::Color NpvController::Loader() {
        random = rand() % 6 + 1;
        switch (random) {
            case 1:
                color = sf::Color::Red;
                break;
            case 2:
                color = sf::Color::White;
                break;
            case 3:
                color = sf::Color::Blue;
                break;
            case 4:
                color = sf::Color::Cyan;
                break;
            case 5:
                color = sf::Color::Yellow;
                break;
            case 6:
                color = sf::Color::Green;
                break;
        }
        return color;
    }

    void NpvController::NpvDraw(GameDataRef &inn_data, bool &Driving, float &MovementSpeed, sf::Sprite &_car,
                                sf::Sprite &_player, sf::Sound &carcrashdone, sf::Texture &cartex,
                                Block _Block[WORLD_HEIGHT][WORLD_WIDTH], Player &player1, bool &boat) {

        _data = inn_data;
        for (auto i : npvVec) {
            this->_data->window.draw(i->getNpvBot());
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W )&& !boat) {
                if (!Driving && GTA::PixelPerfectTest(_player, i->getNpvBot())) {
                    _car.setPosition(i->getNpvBot().getPosition());
                    _car.setRotation(i->getNpvBot().getRotation());
                    _car.setColor(i->getNpvBot().getColor());
                    npvVec.erase(std::remove(npvVec.begin(), npvVec.end(), i), npvVec.end());
                    Driving = true;
                }
            }

            if (i->dead) {
//                i->setNvcBot(this->_data->assets.GetTexture("Dead"));
                i->movementSpeed = 0;
            }

            /// Npc collision with car
            if (Driving) {
//                if(movement.currentSpeed <= 800){
                collisionDetaction.Check_Collision(_car, i->getNpvBot(), true);

                //this->_data->assets.PlaySound(carcrashdone);
                /// denne lyden må spilles når en bil "dør", ellers så spilles lyden hver gang spilleren dytter bilen
//                } else {
//                    i->dead = true;
//                    i->setNvcBot(this->_data->assets.GetTexture("Dead"));
//                }
            } else {
//
                if (GTA::PixelPerfectTest(_player, i->getNpvBot())) {
                    if(i->movementSpeed != 0){
                    player1.setDamage();
                    }
                    collisionDetaction.Check_Collision(_player, i->getNpvBot(), false);
                }
            }

            if (Driving && sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
                for (int k = 99; k < 100; ++k) {
                    npvVec.push_back(new Npv);
                    npvVec[k]->Number = k;
                    npvVec[k]->CarInit(cartex, _Block);
                    npvVec[k]->getNpvBot().setOrigin(_car.getOrigin());
                    npvVec[k]->getNpvBot().setColor(_car.getColor());
                    npvVec[k]->getNpvBot().setPosition(_car.getPosition());
                    npvVec[k]->getNpvBot().setRotation(_car.getRotation());
                    npvVec[k]->movementSpeed = 0;
//                npvVec[k]
//                npvVec[k]->dir = UP;
                }

                _player.setPosition(_car.getPosition().x + 50, _car.getPosition().y + 50);
                _player.setRotation(_car.getRotation());

                Driving = false;
//            std::cout << npvVec.size() << std::endl;
            }
        }
    }
}