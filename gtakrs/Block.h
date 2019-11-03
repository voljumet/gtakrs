//#pragma once
//
//#include "TileMap.h"
//#include "SFML/Graphics.hpp"
//#include "DEFINITIONS.h"
//#include "State.h"
//#include "Game.h"
//
//namespace GTA {
//class Block{
//
//    public:
//        int towerSquareSize = 130;
//        int groundID;
//        int airID;
//
//        Block();
//        sf::Sprite block[WORLD_HEIGHT][WORLD_WIDTH];
//
//        void Draw();
//
//        void setTextures(int x, int y);
//
//        void Init();
//
//
//    private:
//    GameDataRef _data;
//
//    sf::Sprite *_road1, *_road2, *_road3, *_road4, *_road5;
//    sf::Sprite *_curb1, *_curb2, *_curb3, *_curb4;
//    sf::Sprite *_water;
//    sf::Sprite *_grass, *_bush;
//    sf::Sprite *_roof1, *_roof2;
//
//
////        int mapLocationArray[WORLD_HEIGHT][WORLD_WIDTH]={0};        /// Makes an array Matrix that holds the numbers of all the tiles
////        int mapArray[WORLD_HEIGHT * WORLD_WIDTH]={0};     /// Makes an array that contains the size of the total Tiles that is loaded
//    };
//
//}
