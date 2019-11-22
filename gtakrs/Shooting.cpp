

#include <iostream>
#include "Shooting.h"
#include "Game.h"

namespace GTA {
    void Shooting::CreateBullet(sf::Sprite Player, sf::Texture texture)
    {
        Bullet* bullet = new Bullet;
        bullet->bulletspeed = 2000.f;
        sf::Transform t;
        t.rotate(Player.getRotation());
        bullet->bulletVec = t.transformPoint(movement.forwardVec());
        bullet->bullet.setRotation(Player.getRotation());
        bullet->bullet.setPosition(Player.getPosition().x, Player.getPosition().y);
        bullet->bullet.setTexture(texture);
        bullet->bullet.setScale(0.2, 0.2);
        bulletlist.push_back(bullet);
    }
    void Shooting::MoveBullet(){
        for(auto &b: bulletlist){
            b->bullet.move(b->bulletVec*b->bulletspeed*movement.dt);
        }
    }
    void Shooting::DrawBullet(GameDataRef inn_data) {
        _data = inn_data;
        for(auto b: bulletlist){
            this->_data->window.draw(b->bullet);
        }
    }
    void Shooting::Collision(std::vector<Npc *> npclist, std::vector<Bullet *> bulletlist) {
        for(auto npc: npclist){

        }
    }
}

