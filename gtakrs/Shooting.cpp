

#include <iostream>
#include "Shooting.h"
#include "Game.h"
#include "colliderTest.h"

namespace GTA {
    void Shooting::CreateBullet(sf::Sprite &Player)
    {
        Bullet* bullet = new Bullet;
        bullet->bulletspeed = 4000.f;
        sf::Transform t;
        t.rotate(Player.getRotation());
        bullet->bulletVec = t.transformPoint(movement.forwardVec());
        bullet->bullet.setRotation(Player.getRotation());
        bullet->bullet.setPosition(Player.getPosition().x, Player.getPosition().y);
        bullet->bullet.setTexture(this->_data->assets.GetTexture("Bullet"));
        bullet->bullet.rotate(270);
        bullet->bullet.setScale(0.03, 0.03);
        bulletlist.push_back(bullet);

    }
    void Shooting::CreateShotgunBullet(sf::Sprite &Player){
        for(int i = 0; i < 5; i++){
            Bullet* bullet = new Bullet;
            sf::Transform t;
            t.rotate(Player.getRotation());
            if(i == 0){
            bullet->bulletVec = t.transformPoint(movement.forwardVec().x -0.2, movement.forwardVec().y);
                bullet->bulletspeed = 3000.f;
            }
            if(i == 1){
                bullet->bulletVec = t.transformPoint(movement.forwardVec().x -0.1, movement.forwardVec().y);
                bullet->bulletspeed = 3500.f;
            }
            if(i == 2){
                bullet->bulletVec = t.transformPoint(movement.forwardVec());
                bullet->bulletspeed = 4000.f;
            }
            if(i == 3){
                bullet->bulletVec = t.transformPoint(movement.forwardVec().x +0.1, movement.forwardVec().y);
                bullet->bulletspeed = 3500.f;
            }
            if(i == 4){
                bullet->bulletVec = t.transformPoint(movement.forwardVec().x +0.2, movement.forwardVec().y);
                bullet->bulletspeed = 3000.f;
            }
            bullet->bullet.setRotation(Player.getRotation());
            bullet->bullet.setPosition(Player.getPosition().x, Player.getPosition().y);
            bullet->bullet.setTexture(this->_data->assets.GetTexture("Bullet"));
            bullet->bullet.rotate(270);
            bullet->bullet.setScale(0.03, 0.03);
            bulletlist.push_back(bullet);
        }
    }

    void Shooting::MoveBullet(){
        for(auto &b: bulletlist){
            b->bullet.move(b->bulletVec*b->bulletspeed*movement.dt);
            if(b->bullet.getPosition().x >= WORLD_WIDTH*70 || b->bullet.getPosition().y >= WORLD_HEIGHT*70){
                bulletlist.erase(std::remove(bulletlist.begin(), bulletlist.end(), b), bulletlist.end());
            }else if(b->bullet.getPosition().x <= 0 || b->bullet.getPosition().y <= 0){
                bulletlist.erase(std::remove(bulletlist.begin(), bulletlist.end(), b), bulletlist.end());
            }
        }
    }
    void Shooting::DrawBullet(GameDataRef &inn_data) {
        _data = inn_data;
        for(auto b: bulletlist){
            this->_data->window.draw(b->bullet);
        }
    }
    void Shooting::Collision(GameDataRef &inn_data, std::vector<Npc *> &npclist, std::vector<Npv*> &npvlist, std::vector<Bullet *> &bulletlist) {
        _data = inn_data;
        for(auto &npc: npclist){
            if(!npc->dead){
                for(auto &bullet : bulletlist){
                   if(bullet->bullet.getGlobalBounds().intersects(npc->getNpcBot().getGlobalBounds())) {
                       bulletlist.erase(std::remove(bulletlist.begin(), bulletlist.end(), bullet), bulletlist.end());
                       npc->health -= 2;
                       npc->movementSpeed = 4;
                       if(npc->health == 0) {
                           npc->dead = true;
                           npc->movementSpeed = 1;
                           npc->health = 50;
                           npc->setNpcBot(this->_data->assets.GetTexture("Dead"));
                       }
                   }
                }
            }
        }
        for(auto &npv : npvlist){
            for(auto &bullet: bulletlist){
                if(bullet->bullet.getGlobalBounds().intersects(npv->getNpvBot().getGlobalBounds())){
                    npv->health -= 2;
                    npv->movementSpeed = 5;
                    if(npv->health == 0){
                        npv->getNpvBot().setColor(sf::Color::Black);
                        npv->dead = true;
                        npv->health = 300;
                    }
                }
            }
        }
    }
}

