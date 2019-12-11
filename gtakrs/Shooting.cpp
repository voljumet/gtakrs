

#include <iostream>
#include "Shooting.h"
#include "Game.h"
#include "colliderTest.h"

namespace GTA {
    void Shooting::CreateBullet(sf::Sprite &Player)
    {
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
            if(i == 0){
            bullet->setBulletVec( t.transformPoint(movement.forwardVec().x -0.2, movement.forwardVec().y));
                bullet->setBulletspeed(3000.f) ;
            }
            if(i == 1){
                bullet->setBulletVec( t.transformPoint(movement.forwardVec().x -0.1, movement.forwardVec().y));
                bullet->setBulletspeed(3500.f) ;
            }
            if(i == 2){
                bullet->setBulletVec(t.transformPoint(movement.forwardVec()))  ;
                bullet->setBulletspeed(4000.f);
            }
            if(i == 3){
                bullet->setBulletVec(t.transformPoint(movement.forwardVec().x +0.1, movement.forwardVec().y)) ;
                bullet->setBulletspeed(3500.f) ;
            }
            if(i == 4){
                bullet->setBulletVec(t.transformPoint(movement.forwardVec().x +0.2, movement.forwardVec().y));
                bullet->setBulletspeed(3000.f) ;
            }
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
            if(b->getBullet().getPosition().x >= WORLD_WIDTH*70 || b->getBullet().getPosition().y >= WORLD_HEIGHT*70){
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
        for(auto &npc: npclist){
            if(!npc->dead){
                for(auto &bullet : bulletlist){
                   if(bullet->getBullet().getGlobalBounds().intersects(npc->getNpcBot().getGlobalBounds())) {
                       bulletlist.erase(std::remove(bulletlist.begin(), bulletlist.end(), bullet), bulletlist.end());
                       npc->health -= 10;
                       npc->movementSpeed = 16;
                       if(npc->health == 0) {
                           npc->dead = true;
                           npc->movementSpeed = 4;
                           npc->health = 50;
                           npc->setNpcBot(this->_data->assets.GetTexture("Dead"));

                       }
                   }
                }
            }
        }

        for(auto &npv : npvlist){
            for(auto &bullet: bulletlist){
                if(bullet->getBullet().getGlobalBounds().intersects(npv->getNpvBot().getGlobalBounds())){
                    bulletlist.erase(std::remove(bulletlist.begin(), bulletlist.end(), bullet), bulletlist.end());
                    npv->health -= 2;
                    npv->movementSpeed = 16;
                    if(npv->health == 0){
                        npv->getNpvBot().setColor(sf::Color::Black);
                        npv->dead = true;
                        npv->health = 300;
                        npv->movementSpeed = 8;
                    }
                }
            }
        }
    }

     std::vector<Bullet *> &Shooting::getBulletlist()  {
        return bulletlist;
    }


}

