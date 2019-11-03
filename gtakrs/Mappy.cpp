#include <iostream>
#include "Mappy.h"

namespace GTA{

    Mappy::Mappy(GTA::GameDataRef data) : _data(std::move(data)) {}

    void Mappy::Init() {
        map.MapLoad();
        file.open(MAP_FILE_TEST);
        for(int y = 0; y < WORLD_HEIGHT; y++) {
            for (int x = 0; x < WORLD_WIDTH; x++) {
                file >> mapLocationArray[y][x];
            }
        }
        file.close();
        
        std::cout << "MapLocations added!" << std::endl;
        _data->assets.LoadTexture("tiles", MAP_TILE_FILEPATH);
//        assetManager.LoadTexture("tiles", MAP_TILE_FILEPATH);

        int type = 0;

        for (int Y = 0; Y < WORLD_HEIGHT; ++Y) {
            for (int X = 0; X < WORLD_WIDTH; ++X) {
                type = mapLocationArray[Y][X];
                std::cout << mapLocationArray[Y][X] << " added to new array.." << std::endl;

                switch (type){
                    case 0 : {
                        this->_black.setTextureRect(sf::IntRect(0, TILE_SIZE * values.black, TILE_SIZE, TILE_SIZE));
                    }
                    case 14 : {
                        mapLocationArray[Y][X];
                        _road1.setTexture(this->_data->assets.GetTexture("tiles"));
                        _road1.setPosition(TILE_SIZE*X, TILE_SIZE*Y);
                        _road1.setTextureRect(sf::IntRect(0, TILE_SIZE * values.road1, TILE_SIZE, TILE_SIZE));
                        break;
                    }
                    case 5 : {
                        _road2.setTexture(this->_data->assets.GetTexture("tiles"));
                        _road2.setPosition(TILE_SIZE*X, TILE_SIZE*Y);
                        this->_road2.setTextureRect(sf::IntRect(0, TILE_SIZE * values.road2, TILE_SIZE, TILE_SIZE));
                        break;
                    }
                    case 6 : {
                        _road3.setTexture(this->_data->assets.GetTexture("tiles"));
                        _road3.setPosition(TILE_SIZE*X, TILE_SIZE*Y);
                        this->_road3.setTextureRect(sf::IntRect(0, TILE_SIZE * values.road3, TILE_SIZE, TILE_SIZE));
                        break;
                    }
                    case 7 : {
                        _road4.setTexture(this->_data->assets.GetTexture("tiles"));
                        _road4.setPosition(TILE_SIZE*X, TILE_SIZE*Y);
                        this->_road4.setTextureRect(sf::IntRect(0, TILE_SIZE * values.road4, TILE_SIZE, TILE_SIZE));
                        break;
                    }
                    case 8 : {
                        _road5.setTexture(this->_data->assets.GetTexture("tiles"));
                        _road5.setPosition(TILE_SIZE*X, TILE_SIZE*Y);
                        this->_road5.setTextureRect(sf::IntRect(0, TILE_SIZE * values.road5, TILE_SIZE, TILE_SIZE));
                        break;
                    }
                    case 1 :{
                        _curb1.setTexture(this->_data->assets.GetTexture("tiles"));
                        _curb1.setPosition(TILE_SIZE*X, TILE_SIZE*Y);
                        this->_curb1.setTextureRect(sf::IntRect(0, TILE_SIZE * values.curb1, TILE_SIZE, TILE_SIZE));
                        break;
                    }
                    case 2 : {
                        _curb2.setTexture(this->_data->assets.GetTexture("tiles"));
                        _curb2.setPosition(TILE_SIZE*X, TILE_SIZE*Y);
                        this->_curb2.setTextureRect(sf::IntRect(0, TILE_SIZE * values.curb1, TILE_SIZE, TILE_SIZE));
                        break;
                    }
                    case 10 :{
                        _grass.setTexture(this->_data->assets.GetTexture("tiles"));
                        _grass.setPosition(TILE_SIZE*X, TILE_SIZE*Y);
                        this->_grass.setTextureRect(sf::IntRect(0, TILE_SIZE * values.curb1, TILE_SIZE, TILE_SIZE));
                        break;
                    }
                    case 13 : {
                        _bush.setTexture(this->_data->assets.GetTexture("tiles"));
                        _bush.setPosition(TILE_SIZE*X, TILE_SIZE*Y);
                        this->_bush.setTextureRect(sf::IntRect(0, TILE_SIZE * values.curb1, TILE_SIZE, TILE_SIZE));
                        break;
                    }
                    case 3 : {
                        _curb3.setTexture(this->_data->assets.GetTexture("tiles"));
                        _curb3.setPosition(TILE_SIZE*X, TILE_SIZE*Y);
                        this->_curb3.setTextureRect(sf::IntRect(0, TILE_SIZE * values.curb1, TILE_SIZE, TILE_SIZE));
                        break;
                    }
                    case 4 : {
                        _curb4.setTexture(this->_data->assets.GetTexture("tiles"));
                        _curb4.setPosition(TILE_SIZE*X, TILE_SIZE*Y);
                        this->_curb4.setTextureRect(sf::IntRect(0, TILE_SIZE * values.curb1, TILE_SIZE, TILE_SIZE));
                        break;
                    }
                    case 9 : {
                        _water.setTexture(this->_data->assets.GetTexture("tiles"));
                        _water.setPosition(TILE_SIZE*X, TILE_SIZE*Y);
                        this->_water.setTextureRect(sf::IntRect(0, TILE_SIZE * values.curb1, TILE_SIZE, TILE_SIZE));
                        break;
                    }
                    case 11 :{
                        _roof1.setTexture(this->_data->assets.GetTexture("tiles"));
                        _roof1.setPosition(TILE_SIZE*X, TILE_SIZE*Y);
                        this->_roof1.setTextureRect(sf::IntRect(0, TILE_SIZE * values.curb1, TILE_SIZE, TILE_SIZE));
                        break;
                    }
                    case 12 :{
                        _roof2.setTexture(this->_data->assets.GetTexture("tiles"));
                        _roof2.setPosition(TILE_SIZE*X, TILE_SIZE*Y);
                        this->_roof2.setTextureRect(sf::IntRect(0, TILE_SIZE * values.curb1, TILE_SIZE, TILE_SIZE));
                        break;
                    }

                    default:
                        break;

                }
            }
        }
    }



    void Mappy::Draw(float dt) {
        this->_data->window.clear(sf::Color::Black);
        this->_data->window.draw(_black);
        this->_data->window.draw(_road1);
        this->_data->window.draw(_road2);
        this->_data->window.draw(_road3);
        this->_data->window.draw(_road4);
        this->_data->window.draw(_road5);

        this->_data->window.draw(_curb1);
        this->_data->window.draw(_curb2);
        this->_data->window.draw(_curb3);
        this->_data->window.draw(_curb4);

        this->_data->window.draw(_roof1);
        this->_data->window.draw(_roof2);



        this->_data->window.display();
    }

    void Mappy::Update(float dt) {

    }

    void Mappy::HandleInput() {

    }

    void Mappy::UpdateView(const float &dt) {

    }

}

