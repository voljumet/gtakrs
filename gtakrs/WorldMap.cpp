#include "WorldMap.h"

namespace GTA{
    WorldMap::WorldMap(GTA::GameDataRef data) : _data(std::move(data)){

    }

    void WorldMap::LoadMap(){
        this->_data->assets.LoadTexture("Player", PLAYER);
//        this->_dirt.setTexture(this->_data->assets.GetTexture("Player"))
    }

    void WorldMap::DrawMap() {

    }

    WorldMap::~WorldMap() = default;


}