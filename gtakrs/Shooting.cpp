

#include <iostream>
#include "Shooting.h"
namespace GTA {
    void Shooting::CreateBullet(sf::Sprite Player)
    {
        Bullet* bullet = new Bullet;
        bullet->bulletspeed = 2000.f;
        sf::Transform t;
        t.rotate(Player.getRotation());
        bullet->bulletVec = t.transformPoint(movement.forwardVec());
        bullet->bullet.setRotation(Player.getRotation());
        bullet->bullet.setPosition(Player.getPosition().x, Player.getPosition().y);
        bulletlist.push_back(bullet);
    }
    void Shooting::MoveBullet(){
        for(auto &b: bulletlist){
            b->bullet.move(b->bulletVec*b->bulletspeed*movement.dt);
        }
    }
}

