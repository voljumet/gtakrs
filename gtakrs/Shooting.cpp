

#include <iostream>
#include "Shooting.h"
#include "Game.h"
#include "colliderTest.h"

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
            if(b->bullet.getPosition().x >= WORLD_WIDTH*70 || b->bullet.getPosition().y >= WORLD_HEIGHT*70){
                bulletlist.erase(std::remove(bulletlist.begin(), bulletlist.end(), b), bulletlist.end());
            }else if(b->bullet.getPosition().x <= 0 || b->bullet.getPosition().y <= 0){
                bulletlist.erase(std::remove(bulletlist.begin(), bulletlist.end(), b), bulletlist.end());
            }
                std::cout << bulletlist.size() << std::endl;
        }
    }
    void Shooting::DrawBullet(GameDataRef inn_data) {
        _data = inn_data;
        for(auto b: bulletlist){
            this->_data->window.draw(b->bullet);
        }
    }
    void Shooting::Collision(GameDataRef inn_data, std::vector<Npc *> npclist, std::vector<Bullet *> bulletlist) {
        _data = inn_data;
        for(auto &npc: npclist){
            if(!npc->dead){
                for(auto &bullet : bulletlist){
                   if(bullet->bullet.getGlobalBounds().intersects(npc->getNpcBot().getGlobalBounds())) {
                       npc->health -= 2;
                       npc->movementSpeed = 4;
                       if(npc->health == 0) {
                           npc->dead = true;
                           npc->movementSpeed = 1;
                           npc->health = 100;
                           npc->setNpcBot(this->_data->assets.GetTexture("Dead"));
                       }
                   }
                }
            }
        }
    }
}

