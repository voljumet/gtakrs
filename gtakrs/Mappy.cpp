#include <iostream>
#include "Mappy.h"
#include "WorldState.h"


namespace GTA{

    Mappy::Mappy() {
        this->_data->assets.LoadTexture("tiles", MAP_TILE_FILEPATH);

    }

    void Mappy::DrawMap() {
        file.open(MAP_FILE);
        for(int y = 0; y < WORLD_HEIGHT; y++) {
            for (int x = 0; x < WORLD_WIDTH; x++) {
                file >> mapLocationArray[y][x];
            }
        }
        file.close();
        std::cout << "MapLocation Made!" << std::endl;
        this->_data->assets.LoadTexture("tiles", MAP_TILE_FILEPATH);
        int type = 0;

        for (int row = 0; row < 20; ++row) {
            for (int column = 0; column < 25; ++column) {
                type = mapLocationArray[row][column];
                std::cout << mapLocationArray[row][column]<< " added to new array.." << std::endl;

                switch (type){
                    case 0 : {
                        this->_black->setTextureRect(sf::IntRect(0, 70 * black, 70, 70));
                        this->mapLocationArray[row][column];
                    }
                    case 14 : {
                        this->_road1->setTextureRect(sf::IntRect(0, 70 * road1, 70, 70));
                    }
                    case 5 : this->_road2->setTextureRect(sf::IntRect(0, 70*road2, 70,70));
                    case 6 : this->_road3->setTextureRect(sf::IntRect(0, 70*road3, 70,70));
                    case 7 : this->_road4->setTextureRect(sf::IntRect(0, 70*road4, 70,70));
                    case 8 : this->_road5->setTextureRect(sf::IntRect(0, 70*road5, 70,70));

                    case 1 : this->_curb1->setTextureRect(sf::IntRect(0, 70*curb1, 70,70));
                    case 2 : this->_curb2->setTextureRect(sf::IntRect(0, 70*curb2, 70,70));
                    case 3 : this->_curb3->setTextureRect(sf::IntRect(0, 70*curb3, 70,70));
                    case 4 : this->_curb4->setTextureRect(sf::IntRect(0, 70*curb4, 70,70));

                    case 9 : this->_water->setTextureRect(sf::IntRect(0, 70*water, 70,70));

                    case 10 : this->_grass->setTextureRect(sf::IntRect(0, 70*grass, 70,70));
                    case 13 : this->_bush->setTextureRect(sf::IntRect(0, 70*bush1, 70,70));

                    case 11 : this->_roof1->setTextureRect(sf::IntRect(0, 70*roof1, 70,70));
                    case 12 : this->_roof2->setTextureRect(sf::IntRect(0, 70*roof2, 70,70));

                    default:
                        break;

                }
            }
        }
    }



//    void Mappy::Init() {
//
//    }

}

