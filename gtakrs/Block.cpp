
#include "Block.h"
#include "Values.h"

namespace GTA{
    Block::Block() {}

    void Block::Init() {
        this->_data->assets.LoadTexture("TileMap", MAP_TILE_FILEPATH);
        for (int y = 0; y < WORLD_HEIGHT; ++y) {
            for (int x = 0; x < WORLD_WIDTH; ++x) {

                block[y][x].setTexture(this->_data->assets.GetTexture("TileMap"));
                setTextures(x, y);
                block[y][x].setPosition(sf::Vector2f(x * TILE_SIZE , x * TILE_SIZE));
                block[y][x].setScale(sf::Vector2f(1,1));

            }
        }
    }

    void Block::setTextures(int x, int y) {
//        int NUM = block[y][x].getPosition();
//        if(block[x] == 5){}
//        switch (NUM)
        this->_road1->setTextureRect(sf::IntRect(0, 70*road1, 70,70));
        this->_road2->setTextureRect(sf::IntRect(0, 70*road2, 70,70));
        this->_road3->setTextureRect(sf::IntRect(0, 70*road3, 70,70));
        this->_road4->setTextureRect(sf::IntRect(0, 70*road4, 70,70));
        this->_road5->setTextureRect(sf::IntRect(0, 70*road5, 70,70));

        this->_curb1->setTextureRect(sf::IntRect(0, 70*curb1, 70,70));
        this->_curb2->setTextureRect(sf::IntRect(0, 70*curb2, 70,70));
        this->_curb3->setTextureRect(sf::IntRect(0, 70*curb3, 70,70));
        this->_curb4->setTextureRect(sf::IntRect(0, 70*curb4, 70,70));

        this->_water->setTextureRect(sf::IntRect(0, 70*water, 70,70));

        this->_grass->setTextureRect(sf::IntRect(0, 70*grass, 70,70));
        this->_bush->setTextureRect(sf::IntRect(0, 70*bush1, 70,70));

        this->_roof1->setTextureRect(sf::IntRect(0, 70*roof1, 70,70));
        this->_roof2->setTextureRect(sf::IntRect(0, 70*roof2, 70,70));


    }

    void Block::Draw() {
        this->_data->window.clear(sf::Color::Black);
//        this->_data->window.draw(this->block);


    }

}

