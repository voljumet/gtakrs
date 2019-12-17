#pragma once

#include <iostream>
#include "Shooting.h"
#include "Game.h"
#include "colliderTest.h"

namespace GTA {

    std::vector<Bullet *> &Shooting::getBulletlist() { return bulletlist; }

    void Shooting::CreateBullet(sf::Sprite &Player){
        Bullet* bullet = new Bullet;
        bullet->setBulletspeed(4000.f);
        sf::Transform t;
        t.rotate(Player.getRotation());
        bullet->setBulletVec(t.transformPoint(movement.forwardVec()));
        bullet->getBullet().setRotation(Player.getRotation());
        bullet->getBullet().setPosition(Player.getPosition().x, Player.getPosition().y);
        bullet->getBullet().setTexture(this->_data->assets.GetTexture("Bullet"));
        bullet->getBullet().rotate(270);
        bullet->getBullet().setScale(0.03, 0.03);
        bulletlist.push_back(bullet);

    }

    void Shooting::CreateShotgunBullet(sf::Sprite &Player){
        for(int i = 0; i < 5; i++){
            Bullet* bullet = new Bullet;
            sf::Transform t;
            t.rotate(Player.getRotation());
            if(i == 0){ bullet->setBulletspeed(3000.f);
                bullet->setBulletVec( t.transformPoint(movement.forwardVec().x -0.2, movement.forwardVec().y));}
            if(i == 1){ bullet->setBulletspeed(3500.f);
                bullet->setBulletVec( t.transformPoint(movement.forwardVec().x -0.1, movement.forwardVec().y));}
            if(i == 2){ bullet->setBulletspeed(4000.f);
                bullet->setBulletVec(t.transformPoint(movement.forwardVec())); }
            if(i == 3){ bullet->setBulletspeed(3500.f);
                bullet->setBulletVec(t.transformPoint(movement.forwardVec().x +0.1, movement.forwardVec().y)); }
            if(i == 4){ bullet->setBulletspeed(3000.f);
                bullet->setBulletVec(t.transformPoint(movement.forwardVec().x +0.2, movement.forwardVec().y));}
            bullet->getBullet().setRotation(Player.getRotation());
            bullet->getBullet().setPosition(Player.getPosition().x, Player.getPosition().y);
            bullet->getBullet().setTexture(this->_data->assets.GetTexture("Bullet"));
            bullet->getBullet().rotate(270);
            bullet->getBullet().setScale(0.03, 0.03);
            bulletlist.push_back(bullet);
        }
    }

    void Shooting::MoveBullet(){
        for(auto &b: bulletlist){
            b->getBullet().move(b->getBulletVec()*b->getBulletspeed()*movement.dt);
            if(b->getBullet().getPosition().x >= WORLD_WIDTH*TILE_SIZE || b->getBullet().getPosition().y >= WORLD_HEIGHT*TILE_SIZE){
                bulletlist.erase(std::remove(bulletlist.begin(), bulletlist.end(), b), bulletlist.end());
            }else if(b->getBullet().getPosition().x <= 0 || b->getBullet().getPosition().y <= 0){
                bulletlist.erase(std::remove(bulletlist.begin(), bulletlist.end(), b), bulletlist.end());
            }
        }
    }

    void Shooting::DrawBullet(GameDataRef &inn_data) {
        _data = inn_data;
        for(auto b: bulletlist){
            this->_data->window.draw(b->getBullet());
        }
    }

    void Shooting::Collision(GameDataRef &inn_data, std::vector<Npc *> &npclist, std::vector<Npv*> &npvlist, std::vector<Bullet *> &bulletlist) {
        _data = inn_data;

        /// Check bullet against NPC and NPV
        for (int i = 0; i < npclist.size(); ++i) {
            if(!npclist[i]->dead){
                for(auto &bullet : bulletlist){
                    if(bullet->getBullet().getGlobalBounds().intersects(npclist[i]->getNpcBot().getGlobalBounds())) {
                        bulletlist.erase(std::remove(bulletlist.begin(), bulletlist.end(), bullet), bulletlist.end());
                        npclist[i]->health -= 10;
                        npclist[i]->movementSpeed = 16;
                        if(npclist[i]->health == 0) {
                            npclist[i]->dead = true;
                            npclist[i]->movementSpeed = 4;
                            npclist[i]->health = 50;
                            npclist[i]->setNpcBot(this->_data->assets.GetTexture("Dead"));
                        }
                    }
                }
            }

            if(i < npvlist.size()){
                for(auto &bullet: bulletlist){
                    if(bullet->getBullet().getGlobalBounds().intersects(npvlist[i]->getNpvBot().getGlobalBounds())){
                        bulletlist.erase(std::remove(bulletlist.begin(), bulletlist.end(), bullet), bulletlist.end());
                        npvlist[i]->health -= 2;
                        npvlist[i]->movementSpeed = 16;
                        if(npvlist[i]->health == 0){
                            npvlist[i]->getNpvBot().setColor(sf::Color::Black);
                            npvlist[i]->dead = true;
                            npvlist[i]->health = 300;
                            npvlist[i]->movementSpeed = 8;
                        }
                    }
                }
            }
        }
    }
}